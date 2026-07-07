#!/usr/bin/env python3
r"""Generate the link fillers a non-`/FORCE` DLL link needs -- workstream (b1).

To link a module without `/FORCE`, every symbol that must resolve has to be
defined. Two axes force a definition:

  1. REFERENCED-but-undefined -- a symbol our compiled objects call/use but no TU
     defines (`undef_survey.py`'s stub-*/carve-* buckets: Dolphin SDK, not-yet-
     written code, ...).
  2. EXPORTED-but-undefined -- a symbol the module's `.def` exports (the full
     original export surface, ordinals pinned) that no TU defines. `/FORCE` hid
     these; a clean link errors `LNK2001` on the `.exp` for each. This is the bulk
     of the gap (the undecompiled half of the export table).

This tool unions both and emits a single SYNTHETIC COFF object defining every such
name by its exact decorated name: vftable/rtti/data-decorated names get a zero word
in `.data`, everything else a one-byte `ret` in `.text`. The linker resolves purely
by decorated name, so no C++ source / header reproduction is needed and the object
is plainly non-matched (never carved, never in objdiff). Each undecompiled symbol is
swapped stub->real as its source lands (the "stitched DLL" model, workstream b2).

NOT emitted: `crt`/`import` buckets (resolved from MSVCRTD/kernel32/opengl32/... on
the link line) and the EH-vector iterators / C-decorated CRT helpers the map happens
to have an address for (defining them collides, LNK2005).

Usage:
    python tools/win/gen_link_fillers.py sysCore \
        --undef build/win/undef_sysCore.csv \
        --def config/GPIE01_01/win/sysCore.def \
        --objs-dir build/win/obj/sysCore \
        --stub-obj build/win/stubs/sysCore_stubs.obj \
        --carve-names build/win/stubs/sysCore_carve.txt
"""
from __future__ import annotations

import argparse
import csv
import glob
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from pe_extract import (  # noqa: E402
    CoffBuilder, IMAGE_SYM_DTYPE_FUNCTION,
)

ROOT = Path(__file__).resolve().parents[2]

STUB_BUCKETS = ("stub-sdk", "stub-code")
CARVE_BUCKETS = ("carve-fn", "carve-data")
RET = b"\xc3"  # a bare cdecl `ret`: caller cleans the stack, esp unchanged

# Compiler/CRT helpers the map happens to have an address for but that MSVCRTD
# already provides (defining them too -> LNK2005 "already defined"). Leave to the
# CRT: ??_M/??_L are the EH vector ctor/dtor iterators (ehvecctr/ehvecdtr.obj).
LIB_HELPER_PREFIXES = ("??_M", "??_L")

_DATA_RE = re.compile(r"\?[^?].*@@3")  # a C++ data variable: ...@@3<type><cvq>


def is_data_symbol(name: str) -> bool:
    """True for a decorated name that names DATA rather than a function: a vftable
    (``??_7``), RTTI (``??_R``), or a data variable (``?x@@3...``). Such a stub goes
    in .data (a word) instead of .text so a `mov r, offset X` reference is valid."""
    return name.startswith(("??_7", "??_R")) or bool(_DATA_RE.match(name))


def build_stub_obj(stub_funcs: list[str], stub_data: list[str]) -> bytes:
    """A COFF object defining each name: functions -> a `ret` in .text, data ->
    a zero word in .data. Packed tightly; every symbol external so the linker can
    satisfy a reference to it from any other object."""
    b = CoffBuilder()
    for name in stub_funcs:
        off = len(b.text)
        b.text += RET
        b.add_symbol(name, off, 1, IMAGE_SYM_DTYPE_FUNCTION)
    data_sec = 0
    for name in stub_data:
        if not data_sec:
            data_sec = b.add_data_section(".data", writable=True)
        s = b.section(data_sec)
        off = len(s.data)
        s.data += b"\x00\x00\x00\x00"       # a single pointer/word slot
        b.add_symbol(name, off, data_sec, 0)
    b.add_section_symbol(".text", 1, len(b.text), 0)
    if data_sec:
        b.add_section_symbol(".data", data_sec, len(b.section(data_sec).data), 0)
    return b.build()


def defined_symbols(objs: list[str]) -> set[str]:
    """External symbols DEFINED (Section>0, or COMMON) across a set of COFF objs."""
    d: set[str] = set()
    for op in objs:
        raw = Path(op).read_bytes()
        if raw[:2] == b"MZ":
            continue
        nsym = struct.unpack_from("<I", raw, 12)[0]
        symptr = struct.unpack_from("<I", raw, 8)[0]
        strtab = symptr + nsym * 18
        i = 0
        while i < nsym:
            o = symptr + i * 18
            if struct.unpack_from("<I", raw, o)[0] == 0:
                off = struct.unpack_from("<I", raw, o + 4)[0]
                name = raw[strtab + off:raw.find(b"\0", strtab + off)].decode("latin1")
            else:
                name = raw[o:o + 8].rstrip(b"\0").decode("latin1")
            val = struct.unpack_from("<I", raw, o + 8)[0]
            sec = struct.unpack_from("<h", raw, o + 12)[0]
            sclass, naux = raw[o + 16], raw[o + 17]
            if sclass == 2 and (sec > 0 or (sec == 0 and val > 0)):
                d.add(name)
            i += 1 + naux
    return d


def def_exports(def_path: Path) -> list[str]:
    """Decorated export names listed in a module .def's EXPORTS section."""
    out = []
    for ln in def_path.read_text().splitlines():
        m = re.match(r"\s+(\S+)\s+@\d+", ln)
        if m:
            out.append(m.group(1))
    return out


def load_provided(paths: list[Path]) -> set[str]:
    """Decorated names supplied by an import library on the link line (e.g. a
    dependency DLL's exports): these resolve at link and must NOT be stubbed, or
    the stub collides with the import (LNK2005). Reads a pe_symbols CSV (`mangled`
    column) or a plain one-name-per-line list."""
    provided: set[str] = set()
    for p in paths:
        text = p.read_text()
        if text.lstrip().startswith(("target,", "target ,")) or "mangled" in text.splitlines()[0]:
            for r in csv.DictReader(p.open(newline="")):
                if r.get("mangled"):
                    provided.add(r["mangled"])
        else:
            provided.update(ln.strip() for ln in text.splitlines()
                            if ln.strip() and not ln.startswith("#"))
    return provided


def run(mod: str, undef: Path, def_path: Path, objs_dir: Path,
        stub_obj: Path, carve_names: Path, provided: set[str]) -> None:
    stub: dict[str, bool] = {}   # name -> is_data (dedup; a name stubbed once)
    carve: list[str] = []        # b2 byte-carve worklist
    skipped_lib: list[str] = []

    def add_stub(name: str) -> None:
        if name.startswith(LIB_HELPER_PREFIXES) or name in provided:
            skipped_lib.append(name)
            return
        stub.setdefault(name, is_data_symbol(name))

    # Axis 1: referenced-but-undefined (undef_survey buckets).
    for r in csv.DictReader(undef.open(newline="")):
        name, bucket = r["name_mangled"], r["bucket"]
        if bucket in STUB_BUCKETS:
            add_stub(name)
        elif bucket in CARVE_BUCKETS:
            if (not name.startswith("?") or name.startswith(LIB_HELPER_PREFIXES)
                    or name in provided):
                skipped_lib.append(name)   # C-name/_atexit, EH iterator, or lib export
            else:
                if bucket == "carve-fn":
                    carve.append(name)     # a b2 byte-carve candidate; stubbed for b1
                add_stub(name)

    # Axis 2: exported-but-undefined (the .def surface minus what our objects define).
    defined = defined_symbols(sorted(glob.glob(str(objs_dir / "*.obj"))))
    exported_undef = [e for e in def_exports(def_path) if e not in defined]
    for name in exported_undef:
        add_stub(name)

    stub_funcs = [n for n, d in stub.items() if not d]
    stub_data = [n for n, d in stub.items() if d]
    stub_obj.parent.mkdir(parents=True, exist_ok=True)
    stub_obj.write_bytes(build_stub_obj(stub_funcs, stub_data))
    carve_names.parent.mkdir(parents=True, exist_ok=True)
    carve_names.write_text(
        f"# {mod}: b2 byte-carve worklist (pe_extract.py --names); stubbed for b1\n"
        + "".join(n + "\n" for n in carve))
    print(f"=== {mod} link fillers ===")
    print(f"   axis 1 referenced-undefined : {sum(1 for r in csv.DictReader(undef.open(newline='')) if r['bucket'] in STUB_BUCKETS+CARVE_BUCKETS)} rows")
    print(f"   axis 2 exported-undefined   : {len(exported_undef)} (of {len(def_exports(def_path))} exports)")
    print(f"   => stub obj  : {len(stub_funcs)} fn + {len(stub_data)} data -> {stub_obj}")
    print(f"      b2 carve list: {len(carve)} fn -> {carve_names}")
    if skipped_lib:
        print(f"      lib-resolved (left to CRT/import libs): {len(skipped_lib)} "
              f"({', '.join(sorted(set(skipped_lib))[:4])}...)")


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("module")
    ap.add_argument("--undef", type=Path, required=True)
    ap.add_argument("--def", dest="def_path", type=Path, required=True)
    ap.add_argument("--objs-dir", type=Path, required=True)
    ap.add_argument("--stub-obj", type=Path, required=True)
    ap.add_argument("--carve-names", type=Path, required=True)
    ap.add_argument("--provided", type=Path, action="append", default=[],
                    metavar="CSV", help="symbols an import lib supplies (do not "
                    "stub); a pe_symbols CSV or name list. Repeatable "
                    "(e.g. a plugin's --provided sysCore_symbols.csv).")
    args = ap.parse_args(argv)
    run(args.module, args.undef, args.def_path, args.objs_dir,
        args.stub_obj, args.carve_names, load_provided(args.provided))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
