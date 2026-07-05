#!/usr/bin/env python3
"""Carve a per-TU objdiff *target* object out of an original Windows DLL.

Part of the Pikmin Windows (VC6/PE32) decomp. objdiff diffs two relocatable
object files per translation unit: a *base* (our VC6 compile, already i386 COFF
in build/win/obj/) and a *target* (the "expected" answer). The original ships
only as a linked `sysCore.dll`, so this tool synthesizes the target object:

  * it reads the *base* obj's COFF symbol table to learn which functions that TU
    defines (VC6 emits one COMDAT section per function, so each is its own
    symbol),
  * joins those decorated names to the master symbol map
    (config/GPIE01_01/win/<mod>_map.csv) to get each function's real body address
    and size in the original,
  * copies those bytes verbatim out of the DLL into a fresh COFF `.text`, giving
    each function a symbol with the *same* decorated name as the base so objdiff
    pairs them,
  * and reconstructs relocations with capstone: REL32 for call/jmp targets and
    DIR32 for absolute data/global references, each pointing at the map symbol it
    lands on. The field is rewritten to the addend (offset-from-symbol, normally
    0), exactly mirroring what a genuine MSVC object stores -- so the target's
    relocations are byte-for-byte comparable to the base's.

The base is a real MSVC object and the target mirrors MSVC conventions, so
matched functions diff cleanly and reccmp's known-exact functions come out ~100%.

Usage (typically driven by configure_win.py -> build.ninja):
    python tools/win/pe_extract.py \
        --dll  orig/GPIE01_01/files/sysCore.dll \
        --map  config/GPIE01_01/win/sysCore_map.csv \
        --base build/win/obj/ayuStack.obj \
        --out  build/win/target/ayuStack.obj
"""
from __future__ import annotations

import argparse
import bisect
import csv
import re
import struct
import sys
from dataclasses import dataclass, field
from pathlib import Path

# Reuse the dependency-free PE reader that already backs pe_symbols.py.
sys.path.insert(0, str(Path(__file__).resolve().parent))
from pe_symbols import PEFile, demangle  # noqa: E402

import capstone  # noqa: E402
from capstone import x86 as cs_x86  # noqa: E402

# --- COFF / relocation constants --------------------------------------------
IMAGE_FILE_MACHINE_I386 = 0x014C
IMAGE_SCN_CNT_CODE = 0x00000020
IMAGE_SCN_MEM_EXECUTE = 0x20000000
IMAGE_SCN_MEM_READ = 0x40000000
IMAGE_SCN_ALIGN_16BYTES = 0x00500000
IMAGE_SCN_LNK_NRELOC_OVFL = 0x01000000
IMAGE_REL_I386_DIR32 = 0x0006
IMAGE_REL_I386_REL32 = 0x0014
IMAGE_SYM_CLASS_EXTERNAL = 2
IMAGE_SYM_CLASS_STATIC = 3
IMAGE_SYM_DTYPE_FUNCTION = 0x20  # (DTYPE FUNCTION << 4) | (BTYPE NULL)

TEXT_ALIGN = 16


# Compiler-inserted CRT helpers that the disassembler labelled with a single
# leading underscore, but which MSVC references by its cdecl-decorated (double
# underscore) name. /GZ emits the __chkesp stack check in almost every function,
# so aliasing it here keeps that ubiquitous call pairing with the base instead of
# showing as a spurious relocation mismatch in nearly every diff.
NAME_ALIASES = {"_chkesp": "__chkesp", "_ftol": "__ftol"}


def _printable(s: str) -> bool:
    return bool(s) and all(0x20 <= ord(c) < 0x7F for c in s)


# --- Demangled-name bridge --------------------------------------------------
# plugPiki's symbol map (from Ghidra) carries only *demangled* labels
# (`BTeki::spawnCorpseParts`) with an empty name_mangled for internals, while an
# objdiff base object names everything by its decorated MSVC symbol. To pair them
# we demangle each base symbol, normalize it to a `Class::method`(+argc) key, and
# match that against the map's label column. sysCore keeps pairing by decorated
# name directly (its exports supply name_mangled); the bridge only fills the gap.
_CALLCONV = re.compile(r"\b__(?:thiscall|cdecl|stdcall|fastcall|clrcall)\b")
_PLACEHOLDER = re.compile(
    r"^(?:sub|loc|locret|unk|nullsub|j|off|byte|word|dword|qword|FUN|DAT|LAB|thunk)_")
_QUAL_RE = re.compile(r"^[A-Za-z_]\w*(?:::~?[A-Za-z_]\w*)*$")
_TRAILERS = re.compile(r"\s*(?:const|volatile|throw\s*\([^)]*\))\s*$")


def _count_args(argstr: str) -> int:
    """Top-level comma count of a parameter list (copied from seed_annotations)."""
    s = argstr.strip()
    if s in ("", "void"):
        return 0
    depth, n = 0, 1
    for ch in s:
        if ch in "(<[":
            depth += 1
        elif ch in ")>]":
            depth -= 1
        elif ch == "," and depth == 0:
            n += 1
    return n


def _split_params(text: str):
    """Split trailing balanced `(...)`; return (before, argstr) or None."""
    text = _TRAILERS.sub("", text.rstrip())
    if not text.endswith(")"):
        return None
    depth, i = 0, len(text) - 1
    while i >= 0:
        if text[i] == ")":
            depth += 1
        elif text[i] == "(":
            depth -= 1
            if depth == 0:
                break
        i -= 1
    if i < 0:
        return None
    return text[:i], text[i + 1:len(text) - 1]


def demangled_key(decorated: str):
    """A decorated MSVC symbol -> (qualified 'Class::method', argc), or None.

    The function's calling-convention token (`__thiscall`/...) always immediately
    precedes its qualified name in MSVC's demangled form, so the name is whatever
    follows the last such token up to the parameter list."""
    dem = demangle(decorated)
    if not dem or dem == decorated:
        return None  # did not demangle (extern "C" / unknown) -> no reliable key
    sp = _split_params(dem)
    if sp is None:
        return None
    before, argstr = sp
    ms = list(_CALLCONV.finditer(before))
    if ms:
        qual = before[ms[-1].end():].strip()
    else:
        toks = before.strip().split()
        qual = toks[-1] if toks else ""
    if not _QUAL_RE.match(qual):
        return None  # operator new, `vector ctor iterator', etc. -> skip
    return qual, _count_args(argstr)


_CLASSKEY_RE = re.compile(r"\b(?:struct|class|union|enum)\s+")


def canon_sig(decorated: str):
    """A decorated MSVC symbol -> its demangled signature with the aggregate
    class-key (struct/class/union) neutralised and whitespace stripped.

    MSVC mangles `class X` as `V` and `struct X` as `U`, so the SAME function
    gets two decorated names depending on how each TU declared X. After the
    codebase-wide struct->class flip our base emits `V`, but the backfilled map
    `name_mangled` still carry the original's key (often `U`) -- an exact
    `by_name` match then misses. Canonicalising both sides to a key-insensitive
    full signature recovers the pairing without the arg-count ambiguity of the
    bare label bridge (the full parameter types disambiguate overloads)."""
    dem = demangle(decorated)
    if not dem or dem == decorated:
        return None
    return re.sub(r"\s+", "", _CLASSKEY_RE.sub("", dem))


def map_label_key(name: str):
    """A map `name` label -> its qualified key, or None for placeholders/junk.

    Ghidra labels are arg-less (`Class::method`); tolerate an accidental param
    list by stripping it."""
    name = (name or "").strip()
    if not name or _PLACEHOLDER.match(name):
        return None
    sp = _split_params(name)
    if sp is not None:
        name = sp[0]
    name = re.sub(r"\s+", "", name)
    return name if _QUAL_RE.match(name) else None


# --- Symbol map -------------------------------------------------------------
@dataclass
class MapSym:
    rva: int
    va: int
    kind: str
    size: int
    name_mangled: str
    name: str = ""

    def emit_name(self) -> str | None:
        """The symbol name to place in the target object: the decorated MSVC
        name when we have one (so it pairs with the base), else the disassembler
        label, else None (no usable name -> leave the reference un-relocated)."""
        for cand in (self.name_mangled, self.name):
            if _printable(cand):
                return NAME_ALIASES.get(cand, cand)
        return None


class SymbolMap:
    """The RVA-keyed master map, indexed for the two lookups the extractor needs.

    * ``by_name`` -- decorated name -> the *function-body* row (for deciding what
      to carve). Function rows win over thunk rows so we copy the real body.
    * address resolution -- exact-start hit first (thunks, function/data entries),
      then interval containment (references into the middle of a symbol).
    """

    def __init__(self, rows: list[MapSym]):
        self.by_name: dict[str, MapSym] = {}
        # label key ("Class::method") -> the carveable function rows sharing it.
        # Populated for the demangled-name bridge; overloaded keys stay a list so
        # the caller can decide (a lone entry pairs unambiguously).
        self.by_demangled: dict[str, list[MapSym]] = {}
        # class-key-insensitive full-signature -> carveable rows (U<->V bridge)
        self.by_canon: dict[str, list[MapSym]] = {}
        self._exact: dict[int, MapSym] = {}
        starts: list[tuple[int, int, MapSym]] = []  # (start_va, end_va, sym)
        for r in rows:
            # Prefer a real body row for name->carve; thunks only fill gaps.
            cur = self.by_name.get(r.name_mangled)
            if cur is None or (cur.kind == "thunk" and r.kind == "function"):
                self.by_name[r.name_mangled] = r
            if r.kind == "function" and r.size > 0:
                key = map_label_key(r.name)
                if key:
                    self.by_demangled.setdefault(key, []).append(r)
                if r.name_mangled:
                    ck = canon_sig(r.name_mangled)
                    if ck:
                        self.by_canon.setdefault(ck, []).append(r)
            self._exact.setdefault(r.va, r)
            if r.size > 0:
                starts.append((r.va, r.va + r.size, r))
        starts.sort()
        self._starts = [s[0] for s in starts]
        self._spans = starts

    def carve_row(self, decorated: str):
        """The function-body row to carve for a base's decorated symbol name.

        Tries the exact decorated match first (sysCore exports), then the
        demangled-name bridge (plugPiki internals). Returns None if unresolved or
        the key is ambiguous (several map rows, indistinguishable overloads)."""
        sym = self.by_name.get(decorated)
        if sym is not None and sym.kind == "function" and sym.size > 0:
            return sym
        # class-key-insensitive exact-signature match (U<->V after the flip):
        # unambiguous because the full parameter types are preserved.
        ck = canon_sig(decorated)
        if ck:
            cands = self.by_canon.get(ck)
            if cands:
                vas = {c.va for c in cands}
                if len(vas) == 1:
                    return cands[0]
        key = demangled_key(decorated)
        if key is None:
            return None
        cands = self.by_demangled.get(key[0])
        if not cands:
            return None
        if len(cands) == 1:
            return cands[0]
        # Overloaded label: Ghidra labels are arg-less so we cannot pick by argc;
        # if every row is the same body (dup label) take it, else leave unmatched.
        vas = {c.va for c in cands}
        return cands[0] if len(vas) == 1 else None

    def resolve(self, va: int) -> tuple[MapSym, int] | None:
        """Return (symbol, addend) for a VA, or None if it hits no known symbol."""
        hit = self._exact.get(va)
        if hit is not None:
            return hit, 0
        i = bisect.bisect_right(self._starts, va) - 1
        if 0 <= i < len(self._spans):
            start, end, sym = self._spans[i]
            if start <= va < end:
                return sym, va - start
        return None


def load_map(path: Path) -> SymbolMap:
    rows: list[MapSym] = []
    with path.open(encoding="utf-8", newline="") as f:
        for r in csv.DictReader(f):
            rows.append(
                MapSym(
                    rva=int(r["rva"], 16),
                    va=int(r["va"], 16),
                    kind=r["kind"],
                    size=int(r["size"] or 0),
                    name_mangled=r["name_mangled"],
                    name=r.get("name", ""),
                )
            )
    return SymbolMap(rows)


# --- Base COFF: which functions does this TU define? ------------------------
def _iter_symbols(obj: bytes):
    """Yield (name, value, secnum, typ, sclass) for each COFF symbol table entry."""
    (num_sections, sym_ptr, num_syms) = struct.unpack_from("<HxxxxII", obj, 2)
    strtab = sym_ptr + num_syms * 18
    i = 0
    while i < num_syms:
        off = sym_ptr + i * 18
        raw = obj[off : off + 8]
        value, secnum, typ, sclass, naux = struct.unpack_from("<IhHBB", obj, off + 8)
        if raw[:4] == b"\x00\x00\x00\x00":
            so = strtab + struct.unpack_from("<I", raw, 4)[0]
            name = obj[so : obj.index(b"\x00", so)].decode("latin1")
        else:
            name = raw.rstrip(b"\x00").decode("latin1")
        yield name, value, secnum, typ, sclass
        i += 1 + naux


def base_defined_functions(obj: bytes) -> list[str]:
    """Decorated names of the functions *defined* in a base COFF object.

    VC6 puts each COMDAT function in its own section, so a defined function is a
    symbol bound to a section (secnum > 0), of derived type FUNCTION, external or
    static. Section symbols (type 0) and undefined externals (secnum 0) are
    excluded."""
    return [name for name, _v, secnum, typ, sclass in _iter_symbols(obj)
            if secnum > 0 and (typ >> 4) == 0x2
            and sclass in (IMAGE_SYM_CLASS_EXTERNAL, IMAGE_SYM_CLASS_STATIC)]


def base_defined_statics(obj: bytes) -> list[str]:
    """Decorated names of the *file-static* (internal-linkage) functions a base
    object defines -- e.g. DEFINE_PRINT's `?_Print@@YAXPADZZ`. Every TU emits the
    same decorated name for its own copy, so these cannot be joined to the shared
    map by name; they are discovered per-TU via their call sites instead."""
    return [name for name, _v, secnum, typ, sclass in _iter_symbols(obj)
            if secnum > 0 and (typ >> 4) == 0x2 and sclass == IMAGE_SYM_CLASS_STATIC]


def base_symbol_bridge(obj: bytes) -> dict:
    """label key ("Class::method") -> a decorated name the base uses for it.

    Collects every external/static symbol the base defines or references (both the
    functions it defines and the undefined externals it calls), demangling each to
    its qualified key. Lets a carved *target*'s relocations be emitted under the
    same decorated name the *base*'s relocations use, so objdiff pairs them even
    though the map only knows the demangled label. First decorated name wins for a
    key; overloads sharing a key are inherently ambiguous here."""
    bridge: dict[str, str] = {}
    for name, _v, _s, _t, sclass in _iter_symbols(obj):
        if sclass not in (IMAGE_SYM_CLASS_EXTERNAL, IMAGE_SYM_CLASS_STATIC):
            continue
        if not name or name.startswith("."):
            continue
        key = demangled_key(name)
        if key is not None:
            bridge.setdefault(key[0], name)
    return bridge


# --- Target COFF builder ----------------------------------------------------
@dataclass
class Reloc:
    vaddr: int   # offset in .text of the field to fix up
    symidx: int  # index into the symbol table
    type: int    # IMAGE_REL_I386_*


@dataclass
class CoffBuilder:
    text: bytearray = field(default_factory=bytearray)
    relocs: list[Reloc] = field(default_factory=list)
    # symbol records, each already packed to 18 bytes (main + any aux)
    _records: list[bytes] = field(default_factory=list)
    _strtab: bytearray = field(default_factory=bytearray)
    _index_of: dict[str, int] = field(default_factory=dict)

    def _name_field(self, name: str) -> bytes:
        b = name.encode("latin1")
        if len(b) <= 8:
            return b.ljust(8, b"\x00")
        off = 4 + len(self._strtab)
        self._strtab += b + b"\x00"
        return struct.pack("<II", 0, off)

    def _add_record(self, rec: bytes) -> int:
        idx = len(self._records)
        self._records.append(rec)
        return idx

    def add_symbol(self, name: str, value: int, secnum: int, typ: int,
                   sclass: int = IMAGE_SYM_CLASS_EXTERNAL) -> int:
        idx = self._add_record(
            self._name_field(name)
            + struct.pack("<IhHBB", value, secnum, typ, sclass, 0)
        )
        self._index_of[name] = idx
        return idx

    def add_section_symbol(self, name: str, secnum: int, length: int, nreloc: int) -> None:
        """A section symbol plus its aux record (occupies two symbol slots)."""
        self._add_record(
            self._name_field(name)
            + struct.pack("<IhHBB", 0, secnum, 0, IMAGE_SYM_CLASS_STATIC, 1)
        )
        self._add_record(
            struct.pack("<IHHIHBxxx", length, min(nreloc, 0xFFFF), 0, 0, 0, 0)
        )

    def symbol_index(self, name: str, is_func: bool) -> int:
        """Index of ``name`` -- a defined symbol if this TU has one, else an
        undefined external created on first use."""
        idx = self._index_of.get(name)
        if idx is not None:
            return idx
        return self.add_symbol(name, 0, 0,
                               IMAGE_SYM_DTYPE_FUNCTION if is_func else 0)

    def build(self) -> bytes:
        nsec = 1
        num_syms = len(self._records)
        text_ptr = 20 + nsec * 40
        reloc_ptr = text_ptr + len(self.text)
        nreloc = len(self.relocs)
        # COFF stores the reloc count in a u16; overflow is signalled by a flag
        # and a synthetic first reloc holding the real count (rare per-TU).
        overflow = nreloc > 0xFFFF
        stored_nreloc = 0xFFFF if overflow else nreloc
        reloc_bytes = nreloc + (1 if overflow else 0)
        sym_ptr = reloc_ptr + reloc_bytes * 10

        characteristics = (IMAGE_SCN_CNT_CODE | IMAGE_SCN_MEM_EXECUTE
                           | IMAGE_SCN_MEM_READ | IMAGE_SCN_ALIGN_16BYTES)
        if overflow:
            characteristics |= IMAGE_SCN_LNK_NRELOC_OVFL

        out = bytearray()
        out += struct.pack("<HHIIIHH", IMAGE_FILE_MACHINE_I386, nsec, 0,
                           sym_ptr, num_syms, 0, 0)
        out += (b".text\x00\x00\x00"
                + struct.pack("<IIIIIIHHI", 0, 0, len(self.text), text_ptr,
                              reloc_ptr if nreloc else 0, 0,
                              stored_nreloc, 0, characteristics))
        out += self.text
        if overflow:
            out += struct.pack("<IIH", nreloc + 1, 0, 0)  # count in VirtualAddress
        for r in self.relocs:
            out += struct.pack("<IIH", r.vaddr, r.symidx, r.type)
        for rec in self._records:
            out += rec
        out += struct.pack("<I", len(self._strtab) + 4) + self._strtab
        return bytes(out)


# --- Extraction -------------------------------------------------------------
def _image_hi(pe: PEFile) -> int:
    hi = 0
    for s in pe.sections:
        hi = max(hi, s.vaddr + max(s.vsize, s.raw_size))
    return pe.image_base + hi


def extract(dll: Path, mapping: SymbolMap, base_obj: Path, out: Path,
            module: str) -> dict:
    pe = PEFile(dll.read_bytes())
    lo, hi = pe.image_base, _image_hi(pe)
    # This module's own import table: IAT-slot VA -> the imported symbol. The
    # shipped DLL references every cross-DLL (e.g. sysCore) symbol indirectly
    # through its IAT -- `call dword ptr [iat_va]` / `mov r,[iat_va]` -- so a carved
    # target must emit those as DIR32 relocations against the `__imp_<decorated>`
    # symbol, exactly the symbol an importer compiled with __declspec(dllimport)
    # (SYSCORE_API) emits on the base side. Without this the absolute IAT VA sits in
    # the target bytes as an unnamed constant and every cross-DLL site mismatches.
    iat = {im.iat_va: im for im in pe.imports()}
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    md.detail = True

    base_bytes = base_obj.read_bytes()
    names = base_defined_functions(base_bytes)
    # Reverse bridge: label key -> a decorated name the base uses, so a carved
    # target's relocations can be emitted under the same name the base references.
    bridge = base_symbol_bridge(base_bytes)

    def resolve_name(tsym: MapSym) -> str | None:
        """Name to emit for a relocation target: the decorated name when we have
        one (map export, or a match the base references via the bridge), else the
        demangled label so the reference is at least named."""
        if _printable(tsym.name_mangled):
            return NAME_ALIASES.get(tsym.name_mangled, tsym.name_mangled)
        key = map_label_key(tsym.name)
        if key is not None and key in bridge:
            return bridge[key]
        return tsym.emit_name()

    # Resolve each defined name to a carveable body; keep source order stable.
    funcs: list[tuple[str, MapSym]] = []
    for n in names:
        sym = mapping.carve_row(n)
        if sym is not None:
            funcs.append((n, sym))

    # --- Discover this TU's file-static functions via their call sites ----------
    # A file-static (DEFINE_PRINT's `_Print`, DEFINE_ERROR's `_Error`, ...) has
    # internal linkage: every TU emits the *same* decorated name at a *different*
    # address, so the shared map disambiguates them with per-TU labels
    # (`aiBridge_Print`) that don't join to the base name. But internal linkage also
    # means a static is only ever called from within its own TU -- so we pin THIS
    # TU's copy by disassembling the functions we already resolved and finding the
    # call whose target is a still-unpaired static-labelled map row (label ends with
    # the base static's demangled name, e.g. `_Print`). That target *is* this TU's
    # static; we carve it under the base's decorated name so it pairs by construction.
    static_name_by_va: dict[int, str] = {}
    want: dict[str, str] = {}  # demangled simple name ("_Print") -> base decorated name
    for sname in base_defined_statics(base_bytes):
        if mapping.carve_row(sname) is not None:
            continue  # a non-colliding static that already joined by name
        key = demangled_key(sname)
        if key is not None:
            want[key[0]] = sname
    if want:
        resolved_vas = {sym.va for _n, sym in funcs}
        for _n, sym in funcs:
            foff = pe.rva_to_off(sym.rva)
            for insn in md.disasm(pe.data[foff : foff + sym.size], sym.va):
                if not insn.bytes or insn.bytes[0] != 0xE8 or insn.encoding.imm_size != 4:
                    continue  # only direct near calls (E8) reach a static
                res = mapping.resolve(insn.operands[-1].imm & 0xFFFFFFFF)
                if res is None or res[1] != 0:
                    continue
                row = res[0]
                if row.name_mangled or row.va in resolved_vas or row.va in static_name_by_va:
                    continue
                for simple, sname in want.items():
                    if (row.name or "").endswith(simple):
                        static_name_by_va[row.va] = sname
                        funcs.append((sname, row))
                        break
    b = CoffBuilder()
    # Defined function symbols come first (indices 0..n-1); undefined externals
    # for call/data targets are appended during the reloc pass, and the .text
    # section symbol is added last (nothing references it) with true size/count.
    # Pack tightly (no inter-function padding): objdiff infers a function's size
    # from the offset of the next symbol, so any alignment padding would be
    # attributed to the preceding function and inflate it past the base's size.
    text_off: dict[str, int] = {}
    for name, sym in funcs:
        off = len(b.text)
        text_off[name] = off
        foff = pe.rva_to_off(sym.rva)
        b.text += pe.data[foff : foff + sym.size]
        b.add_symbol(name, off, 1, IMAGE_SYM_DTYPE_FUNCTION)

    n_rel32 = n_dir32 = n_iat = n_unresolved = 0
    for name, sym in funcs:
        base_off = text_off[name]
        code = bytes(b.text[base_off : base_off + sym.size])
        for insn in md.disasm(code, sym.va):
            enc = insn.encoding
            insn_off = base_off + (insn.address - sym.va)
            op0 = insn.bytes[0]
            is_branch = op0 in (0xE8, 0xE9) or (
                op0 == 0x0F and len(insn.bytes) > 1 and 0x80 <= insn.bytes[1] <= 0x8F)
            if is_branch and enc.imm_size == 4:
                target = insn.operands[-1].imm & 0xFFFFFFFF
                res = mapping.resolve(target)
                if res is not None and res[0].va == sym.va and res[1] != 0:
                    continue  # branch to a label *inside* the function being carved:
                    # the copied rel32 is already self-relative and MSVC emits no
                    # relocation for it, so emitting one here is a spurious
                    # "self-reloc" the real base object never has. (Keyed off
                    # resolve()'s interval, so a call to the next function is unaffected
                    # even when this function's map size overruns it.)
                if res is None:
                    # plugPiki's map has few thunk rows; an incremental-link
                    # `jmp rel32` call target may miss it. Follow the stub to the
                    # real body (which the map does know) and retry.
                    hopped = pe.resolve_thunk(target - pe.image_base) + pe.image_base
                    res = mapping.resolve(hopped) if hopped != target else None
                    if res is None:
                        n_unresolved += 1
                        continue
                tsym, addend = res
                tname = (static_name_by_va.get(tsym.va) if addend == 0 else None) \
                    or resolve_name(tsym)
                if tname is None:
                    n_unresolved += 1
                    continue
                fld = insn_off + enc.imm_offset
                struct.pack_into("<i", b.text, fld, addend)
                symidx = b.symbol_index(tname, True)
                b.relocs.append(Reloc(fld, symidx, IMAGE_REL_I386_REL32))
                n_rel32 += 1
                continue
            if is_branch:
                continue
            for op in insn.operands:
                if op.type == cs_x86.X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0:
                    val = op.mem.disp & 0xFFFFFFFF
                    fld_off = enc.disp_offset
                elif op.type == cs_x86.X86_OP_IMM and enc.imm_size == 4:
                    val = op.imm & 0xFFFFFFFF
                    fld_off = enc.imm_offset
                else:
                    continue
                if not (lo <= val < hi):
                    continue
                imp = iat.get(val)
                if imp is not None:  # reference through our own IAT -> __imp_ symbol
                    fld = insn_off + fld_off
                    struct.pack_into("<i", b.text, fld, 0)
                    symidx = b.symbol_index(imp.imp_symbol, False)
                    b.relocs.append(Reloc(fld, symidx, IMAGE_REL_I386_DIR32))
                    n_iat += 1
                    continue
                res = mapping.resolve(val)
                if res is None:
                    continue  # in-image constant with no known symbol; leave as-is
                tsym, addend = res
                tname = (static_name_by_va.get(tsym.va) if addend == 0 else None) \
                    or resolve_name(tsym)
                if tname is None:
                    continue  # in-image ref with no usable symbol name; leave as-is
                fld = insn_off + fld_off
                struct.pack_into("<i", b.text, fld, addend)
                is_func = tsym.kind in ("function", "thunk")
                symidx = b.symbol_index(tname, is_func)
                b.relocs.append(Reloc(fld, symidx, IMAGE_REL_I386_DIR32))
                n_dir32 += 1

    # .text section symbol + aux, last, with the now-known size and reloc count.
    b.add_section_symbol(".text", 1, len(b.text), len(b.relocs))

    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_bytes(b.build())
    return {
        "funcs": len(funcs), "candidates": len(names),
        "rel32": n_rel32, "dir32": n_dir32, "iat": n_iat,
        "unresolved_calls": n_unresolved, "bytes": len(b.text),
    }


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description="Carve an objdiff target object from a PE.")
    ap.add_argument("--dll", required=True, type=Path, help="original module (e.g. sysCore.dll)")
    ap.add_argument("--map", required=True, type=Path, help="master symbol map CSV")
    ap.add_argument("--base", required=True, type=Path, help="compiled base .obj for this TU")
    ap.add_argument("--out", required=True, type=Path, help="target .obj to write")
    ap.add_argument("--module", default="SYSCORE", help="module id (informational)")
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args(argv)

    mapping = load_map(args.map)
    stats = extract(args.dll, mapping, args.base, args.out, args.module)
    if args.verbose:
        print(f"{args.out.name}: {stats['funcs']}/{stats['candidates']} funcs, "
              f"{stats['bytes']} .text bytes, {stats['rel32']} REL32, "
              f"{stats['dir32']} DIR32, {stats['iat']} IAT, "
              f"{stats['unresolved_calls']} unresolved calls",
              file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
