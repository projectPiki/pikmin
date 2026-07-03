#!/usr/bin/env python3
"""Parse the export table of a Windows PE (DLL/EXE) into a symbol CSV.

Pure-Python PE reader (no pefile/pfunction dependency) so it runs on a stock
CPython. For the Pikmin Windows (VC6/PE) decomp: the shipped GPIE01_01
`sysCore.dll` exports 1478 mangled C++ symbols, which give us original
address <-> name pairs for free (no Ghidra needed for exported functions).

CSV columns: target,ordinal,rva,va,real_rva,real_va,forwarder,mangled,demangled

  target     - logical module name (e.g. "sysCore"), passed via --target
  ordinal    - export ordinal (OrdinalBase + name-ordinal index)
  rva        - relative virtual address of the export, 0x-hex
  va         - virtual address of the export (ImageBase + rva), 0x-hex
  real_rva   - rva of the actual function body.  The GPIE01_01 modules were linked
               `/INCREMENTAL:YES`, so an export usually points at a 5-byte `jmp rel32`
               thunk in the incremental-link table rather than the real function.  This
               column follows that jump to the body; for non-thunk exports it equals rva.
  real_va    - ImageBase + real_rva.  THIS is the address reccmp
               `// FUNCTION: <target> 0x...` annotations must use (annotating the thunk
               address makes reccmp diff the real body against a run of jmp stubs -> 0%).
  forwarder  - forward target string if this export forwards, else empty
  mangled    - raw export name as stored in the PE
  demangled  - MSVC-demangled signature (via pydemumble) incl. calling
               convention, or the raw name if it does not demangle

Usage:
    python tools/win/pe_symbols.py <pe-file> --target sysCore [-o out.csv]
    python tools/win/pe_symbols.py <pe-file> --target sysCore   # -> stdout
"""
from __future__ import annotations

import argparse
import csv
import struct
import sys
from dataclasses import dataclass


@dataclass
class Section:
    name: str
    vaddr: int
    vsize: int
    raw_ptr: int
    raw_size: int


@dataclass
class Export:
    ordinal: int
    rva: int
    va: int
    real_rva: int
    real_va: int
    forwarder: str
    mangled: str
    demangled: str


class PEError(Exception):
    pass


def _u16(b: bytes, off: int) -> int:
    return struct.unpack_from("<H", b, off)[0]


def _u32(b: bytes, off: int) -> int:
    return struct.unpack_from("<I", b, off)[0]


def _cstr(b: bytes, off: int) -> str:
    end = b.find(b"\x00", off)
    if end < 0:
        end = len(b)
    return b[off:end].decode("ascii", errors="replace")


class PEFile:
    def __init__(self, data: bytes):
        self.data = data
        if data[:2] != b"MZ":
            raise PEError("not an MZ/PE image")
        e_lfanew = _u32(data, 0x3C)
        if data[e_lfanew : e_lfanew + 4] != b"PE\x00\x00":
            raise PEError("bad PE signature")
        coff = e_lfanew + 4
        self.machine = _u16(data, coff + 0)
        num_sections = _u16(data, coff + 2)
        size_opt = _u16(data, coff + 16)
        opt = coff + 20
        magic = _u16(data, opt + 0)
        if magic == 0x10B:  # PE32
            self.image_base = _u32(data, opt + 28)
            dd_off = opt + 96
            num_dd = _u32(data, opt + 92)
        elif magic == 0x20B:  # PE32+
            self.image_base = struct.unpack_from("<Q", data, opt + 24)[0]
            dd_off = opt + 112
            num_dd = _u32(data, opt + 108)
        else:
            raise PEError(f"unknown optional-header magic 0x{magic:x}")

        self.export_rva = self.export_size = 0
        if num_dd >= 1:
            self.export_rva = _u32(data, dd_off + 0)
            self.export_size = _u32(data, dd_off + 4)

        sec_off = opt + size_opt
        self.sections: list[Section] = []
        for i in range(num_sections):
            s = sec_off + i * 40
            self.sections.append(
                Section(
                    name=_cstr(data[s : s + 8], 0),
                    vaddr=_u32(data, s + 12),
                    vsize=_u32(data, s + 8),
                    raw_ptr=_u32(data, s + 20),
                    raw_size=_u32(data, s + 16),
                )
            )

    def rva_to_off(self, rva: int) -> int | None:
        for s in self.sections:
            span = max(s.vsize, s.raw_size)
            if s.vaddr <= rva < s.vaddr + span:
                off = s.raw_ptr + (rva - s.vaddr)
                if off < len(self.data):
                    return off
        return None

    def resolve_thunk(self, rva: int) -> int:
        """Follow an incremental-link `jmp rel32` thunk to the real body rva.

        `/INCREMENTAL:YES` routes calls/exports through 5-byte `E9 rel32` stubs.  A single
        hop is all VC6 emits; if the target is itself a thunk we would loop, so we follow at
        most a few hops defensively.  Non-thunk rvas are returned unchanged.
        """
        for _ in range(8):
            off = self.rva_to_off(rva)
            if off is None or off >= len(self.data) or self.data[off] != 0xE9:
                return rva
            rel = struct.unpack_from("<i", self.data, off + 1)[0]
            target = rva + 5 + rel
            if target == rva:
                return rva
            rva = target
        return rva

    def exports(self) -> list[Export]:
        if not self.export_rva:
            return []
        d = self.data
        base = self.rva_to_off(self.export_rva)
        if base is None:
            raise PEError("export directory RVA not in any section")
        ordinal_base = _u32(d, base + 16)
        num_funcs = _u32(d, base + 20)
        num_names = _u32(d, base + 24)
        eat_off = self.rva_to_off(_u32(d, base + 28))
        names_off = self.rva_to_off(_u32(d, base + 32))
        ords_off = self.rva_to_off(_u32(d, base + 36))

        # EAT index -> mangled name (only for named exports)
        name_by_index: dict[int, str] = {}
        if num_names and names_off is not None and ords_off is not None:
            for i in range(num_names):
                name_rva = _u32(d, names_off + i * 4)
                idx = _u16(d, ords_off + i * 2)
                noff = self.rva_to_off(name_rva)
                name_by_index[idx] = _cstr(d, noff) if noff is not None else ""

        lo, hi = self.export_rva, self.export_rva + self.export_size
        out: list[Export] = []
        for idx in range(num_funcs):
            fn_rva = _u32(d, eat_off + idx * 4)
            if fn_rva == 0:
                continue  # unused ordinal slot
            forwarder = ""
            if lo <= fn_rva < hi:  # RVA inside export dir => forwarder string
                foff = self.rva_to_off(fn_rva)
                forwarder = _cstr(d, foff) if foff is not None else ""
            mangled = name_by_index.get(idx, "")
            # Forwarder RVAs point into the export directory (a string), not code; don't chase them.
            real_rva = fn_rva if forwarder else self.resolve_thunk(fn_rva)
            out.append(
                Export(
                    ordinal=ordinal_base + idx,
                    rva=fn_rva,
                    va=self.image_base + fn_rva,
                    real_rva=real_rva,
                    real_va=self.image_base + real_rva,
                    forwarder=forwarder,
                    mangled=mangled,
                    demangled=demangle(mangled) if mangled else "",
                )
            )
        out.sort(key=lambda e: e.rva)
        return out


_demangle_fn = None


def demangle(name: str) -> str:
    """Best-effort MSVC demangle; returns the input unchanged on failure."""
    global _demangle_fn
    if _demangle_fn is None:
        try:
            import pydemumble

            _demangle_fn = pydemumble.demangle
        except Exception:
            _demangle_fn = lambda s: s  # noqa: E731
    try:
        res = _demangle_fn(name)
    except Exception:
        return name
    return res or name


def parse_exports(path: str) -> tuple[PEFile, list[Export]]:
    with open(path, "rb") as f:
        pe = PEFile(f.read())
    return pe, pe.exports()


def write_csv(exports: list[Export], target: str, out) -> None:
    w = csv.writer(out, lineterminator="\n")
    w.writerow(
        ["target", "ordinal", "rva", "va", "real_rva", "real_va", "forwarder", "mangled", "demangled"]
    )
    for e in exports:
        w.writerow(
            [
                target,
                e.ordinal,
                f"0x{e.rva:08x}",
                f"0x{e.va:08x}",
                f"0x{e.real_rva:08x}",
                f"0x{e.real_va:08x}",
                e.forwarder,
                e.mangled,
                e.demangled,
            ]
        )


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description="PE export table -> symbol CSV")
    ap.add_argument("pe", help="path to the .dll/.exe")
    ap.add_argument("--target", required=True, help="logical module name (e.g. sysCore)")
    ap.add_argument("-o", "--out", help="output CSV path (default: stdout)")
    args = ap.parse_args(argv)

    pe, exports = parse_exports(args.pe)
    named = sum(1 for e in exports if e.mangled)
    fwd = sum(1 for e in exports if e.forwarder)
    if args.out:
        with open(args.out, "w", newline="") as f:
            write_csv(exports, args.target, f)
        print(
            f"{args.pe}: image_base=0x{pe.image_base:08x} "
            f"exports={len(exports)} named={named} forwarders={fwd} -> {args.out}",
            file=sys.stderr,
        )
    else:
        write_csv(exports, args.target, sys.stdout)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
