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

It also carves **data** (W-DATA): strings, fp-constant pools and vftables the TU
defines. Their names (`??_C@...`, `??_7X@@6B@`) aren't in the map, so their DLL
addresses are discovered from base relocations - a base reloc names the referenced
symbol and the aligned carved DLL bytes give its address. Discovery seeds from code
(functions carved byte-identical modulo relocations) and BFS's through data->data
pointers; carved bytes land in `.rdata`/`.data`, with code/vftable-slot relocations
named after the base's target so objdiff pairs them. `--no-data` disables this.

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


def _aligned(dll_bytes: bytes, base: bytes, relocs: dict) -> bool:
    """True when carved DLL bytes reproduce a base section modulo relocations.

    Reloc-covered fields (4 bytes each) are wildcards -- they legitimately differ
    (the DLL holds a linked address where the base holds an addend), so a match on
    every *other* byte means the base's reloc offsets line up with the DLL operands
    and can be trusted to name what each site references."""
    if len(dll_bytes) != len(base):
        return False
    covered = set()
    for o in relocs:
        covered.update(range(o, o + 4))
    return all(j in covered or dll_bytes[j] == base[j] for j in range(len(base)))


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


# --- Base COFF: the data a TU defines, and who references it (W-DATA) --------
def _data_kind(name: str) -> str:
    if name.startswith("??_7"):
        return "vftable"
    if name.startswith("??_C"):
        return "string"
    if name.startswith(("__real@", "__xmm@")):
        return "fpconst"
    if name.startswith("??_R"):
        return "rtti"
    return "other"


def _iter_symbols_indexed(obj: bytes):
    """As _iter_symbols but also yielding the symbol's table index and aux count."""
    (num_sections, sym_ptr, num_syms) = struct.unpack_from("<HxxxxII", obj, 2)
    strtab = sym_ptr + num_syms * 18
    i = 0
    while i < num_syms:
        off = sym_ptr + i * 18
        raw = obj[off:off + 8]
        value, secnum, typ, sclass, naux = struct.unpack_from("<IhHBB", obj, off + 8)
        if raw[:4] == b"\x00\x00\x00\x00":
            so = strtab + struct.unpack_from("<I", raw, 4)[0]
            name = obj[so:obj.index(b"\x00", so)].decode("latin1")
        else:
            name = raw.rstrip(b"\x00").decode("latin1")
        yield i, name, value, secnum, typ, sclass, naux
        i += 1 + naux


@dataclass
class BaseData:
    kind: str
    size: int
    bytes: bytes
    sec: str                          # base section basename (.rdata/.data/...)
    relocs: dict[int, tuple[str, int]]  # intra-offset -> (target decorated name, type)


def parse_base_coff(obj: bytes):
    """Parse a base object into its defined functions and data symbols.

    Returns ``(func_relocs, data)`` where ``func_relocs[name]`` = (section bytes,
    {intra-offset: (target name, reltype)}) for each defined function, and
    ``data[name]`` = a :class:`BaseData`. VC6 emits one COMDAT section per symbol,
    so a section with exactly one defined non-section symbol is owned by it; the
    section's raw bytes and relocations belong to that symbol. Relocation targets
    are resolved to their symbol names so the carved target can reference the same
    decorated names the base does (that is what makes objdiff pair them)."""
    num_sections, sym_ptr, num_syms = struct.unpack_from("<HxxxxII", obj, 2)
    secs = []
    for k in range(num_sections):
        s = 20 + k * 40
        name = obj[s:s + 8].rstrip(b"\x00").decode("latin1")
        (vsz, vad, rawsz, rawptr, relptr, lnptr,
         nrel, nln, ch) = struct.unpack_from("<IIIIIIHHI", obj, s + 8)
        secs.append({"name": name, "rawsz": rawsz, "rawptr": rawptr,
                     "relptr": relptr, "nrel": nrel})

    idx_name: dict[int, str] = {}
    members: dict[int, list] = {}
    for idx, name, value, secnum, typ, sclass, naux in _iter_symbols_indexed(obj):
        idx_name[idx] = name
        if (secnum > 0 and sclass in (IMAGE_SYM_CLASS_EXTERNAL, IMAGE_SYM_CLASS_STATIC)
                and name and not name.startswith(".")):
            members.setdefault(secnum, []).append((name, value, typ))

    func_relocs: dict[str, tuple[bytes, dict]] = {}
    data: dict[str, BaseData] = {}
    for secnum, mem in members.items():
        if len(mem) != 1:
            continue  # not a clean 1:1 COMDAT; functions still carve by name
        sec = secs[secnum - 1]
        base = sec["name"].split("$")[0]
        if base in (".debug", ".drectve", ".text"):
            # .text funcs are carved via the map by name; we only need their relocs
            if base != ".text":
                continue
        raw = obj[sec["rawptr"]:sec["rawptr"] + sec["rawsz"]] if sec["rawptr"] else b""
        relocs: dict[int, tuple[str, int]] = {}
        for r in range(sec["nrel"]):
            vaddr, symidx, rtype = struct.unpack_from("<IIH", obj, sec["relptr"] + r * 10)
            tn = idx_name.get(symidx)
            if tn:
                relocs[vaddr] = (tn, rtype)
        name, value, typ = mem[0]
        if (typ >> 4) == 0x2:
            func_relocs[name] = (raw, relocs)
        elif base not in (".text", ".bss") and sec["rawptr"]:
            # .bss/uninitialised data has no bytes to carve (increment 1 skips it).
            data[name] = BaseData(_data_kind(name), sec["rawsz"], raw, base, relocs)
    return func_relocs, data


# --- Target COFF builder ----------------------------------------------------
IMAGE_SCN_CNT_INITIALIZED_DATA = 0x00000040
IMAGE_SCN_MEM_WRITE = 0x80000000
IMAGE_SCN_ALIGN_4BYTES = 0x00300000


@dataclass
class Reloc:
    vaddr: int   # offset within the owning section of the field to fix up
    symidx: int  # index into the symbol table
    type: int    # IMAGE_REL_I386_*


@dataclass
class Section:
    name: str
    chars: int
    data: bytearray = field(default_factory=bytearray)
    relocs: list[Reloc] = field(default_factory=list)


class CoffBuilder:
    """Builds a multi-section i386 COFF. Section 1 is always `.text`; data
    sections (`.rdata`/`.data`) are added on demand. `text`/`relocs` alias
    section 1 so the (proven) function-carving code needs no changes."""

    def __init__(self):
        tchars = (IMAGE_SCN_CNT_CODE | IMAGE_SCN_MEM_EXECUTE
                  | IMAGE_SCN_MEM_READ | IMAGE_SCN_ALIGN_16BYTES)
        self.text = bytearray()
        self.relocs: list[Reloc] = []
        self._sections = [Section(".text", tchars, self.text, self.relocs)]
        self._records: list[bytes] = []
        self._strtab = bytearray()
        self._index_of: dict[str, int] = {}

    def add_data_section(self, name: str, writable: bool = False) -> int:
        """Append an initialised-data section; return its 1-based section number."""
        chars = (IMAGE_SCN_CNT_INITIALIZED_DATA | IMAGE_SCN_MEM_READ
                 | IMAGE_SCN_ALIGN_4BYTES)
        if writable:
            chars |= IMAGE_SCN_MEM_WRITE
        self._sections.append(Section(name, chars, bytearray(), []))
        return len(self._sections)

    def section(self, secnum: int) -> Section:
        return self._sections[secnum - 1]

    def _name_field(self, name: str) -> bytes:
        # COFF symbol names must be valid UTF-8 (objdiff's loader rejects otherwise);
        # a stray high byte (0x80-0xFF) in a map label -> '?' so the object still
        # loads. No-op for the ASCII decorated names the normal carve emits.
        b = name.encode("latin1", "replace")
        b = bytes(c if c < 0x80 else 0x3F for c in b)
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

    def has_symbol(self, name: str) -> bool:
        return name in self._index_of

    def symbol_index(self, name: str, is_func: bool) -> int:
        """Index of ``name`` -- a defined symbol if this TU has one, else an
        undefined external created on first use."""
        idx = self._index_of.get(name)
        if idx is not None:
            return idx
        return self.add_symbol(name, 0, 0,
                               IMAGE_SYM_DTYPE_FUNCTION if is_func else 0)

    def build(self) -> bytes:
        nsec = len(self._sections)
        num_syms = len(self._records)
        # Layout: header, section headers, then each section's raw data, then each
        # section's relocations, then symbols, then the string table.
        cursor = 20 + nsec * 40
        raw_ptr = []
        for s in self._sections:
            raw_ptr.append(cursor if s.data else 0)
            cursor += len(s.data)
        rel_ptr, stored_nrel, overflow = [], [], []
        for s in self._sections:
            n = len(s.relocs)
            of = n > 0xFFFF  # COFF u16 reloc count; overflow -> flag + synthetic reloc
            overflow.append(of)
            stored_nrel.append(0xFFFF if of else n)
            rel_ptr.append(cursor if n else 0)
            cursor += (n + (1 if of else 0)) * 10
        sym_ptr = cursor

        out = bytearray()
        out += struct.pack("<HHIIIHH", IMAGE_FILE_MACHINE_I386, nsec, 0,
                           sym_ptr, num_syms, 0, 0)
        for i, s in enumerate(self._sections):
            chars = s.chars | (IMAGE_SCN_LNK_NRELOC_OVFL if overflow[i] else 0)
            out += (s.name.encode("latin1").ljust(8, b"\x00")
                    + struct.pack("<IIIIIIHHI", 0, 0, len(s.data), raw_ptr[i],
                                  rel_ptr[i], 0, stored_nrel[i], 0, chars))
        for s in self._sections:
            out += s.data
        for i, s in enumerate(self._sections):
            if overflow[i]:
                out += struct.pack("<IIH", len(s.relocs) + 1, 0, 0)
            for r in s.relocs:
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
            module: str, carve_data: bool = True,
            explicit_names: list[str] | None = None,
            extra: list[tuple[str, int, int]] | None = None) -> dict:
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

    if explicit_names is not None:
        # Filler mode (workstream b): carve a given list of decorated names into a
        # standalone object with NO base .obj -- used to supply the functions a
        # non-/FORCE link needs but no TU defines (undef_survey.py's carve-fn
        # bucket). There is no base to pair against, so no bridge / no file-static
        # discovery / no data BFS; reloc targets are named straight from the map.
        base_bytes = b""
        names = list(explicit_names)
        bridge = {}
        carve_data = False
    else:
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

    # Extra target symbols carved by ADDRESS (workstream (c)/objdiff mapping): the
    # unlabelled DLL functions of this TU, added under their placeholder labels so
    # objdiff has target symbols the human can manually map an unmatched base
    # function onto. Not name-resolved (placeholders don't join the base) -- carved
    # straight from (rva, size). Skip any that collide with an already-carved body.
    if extra:
        have_va = {s.va for _n, s in funcs}
        for pname, pva, psize in extra:            # (name, VA, size)
            if pva in have_va or psize <= 0:
                continue
            pname = pname or f"FUN_{pva:x}"        # never an empty COFF symbol name
            funcs.append((pname, MapSym(rva=pva - pe.image_base, va=pva,
                                        kind="function", size=psize,
                                        name_mangled=pname, name=pname)))

    # Base COFF relocations/data, parsed once: used both for file-static discovery
    # (just below) and the W-DATA carving (further down). Cheap and pure.
    func_base, data_base = parse_base_coff(base_bytes) if base_bytes else ({}, {})

    # --- Discover this TU's file-static functions -------------------------------
    # A file-static (DEFINE_PRINT's `_Print`, DEFINE_ERROR's `_Error`, a leaf
    # `quickABS`, a `makeObject*` factory, ...) has internal linkage: every TU emits
    # the *same* decorated name at a *different* address, so the shared map
    # disambiguates them with per-TU labels (`aiBridge_Print`) or -- when Ghidra
    # never guessed one -- a bare `FUN_<addr>` that doesn't join to the base name.
    # We pin THIS TU's copy two ways, always carving the target VA under the base's
    # decorated name so it pairs by construction:
    #
    #   1. base-relocation alignment (primary, label-independent): every carved
    #      function that reproduces its base bytes modulo relocations lets us trust
    #      the base's own relocations -- each names a static it references and the
    #      aligned DLL bytes at that offset give the referenced address. Catches E8
    #      calls AND address-of (DIR32) uses, e.g. a `makeObjectTeki` only ever
    #      stored into a factory table, regardless of the map label.
    #   2. call-site + label endswith (fallback): a direct E8 to a still-unpaired
    #      map row whose label ends with the static's demangled name -- covers a
    #      static whose only caller did not carve byte-aligned.
    static_name_by_va: dict[int, str] = {}
    resolved_vas = {sym.va for _n, sym in funcs}
    want_dec: dict[str, str] = {}  # base decorated name -> demangled simple ("_Print")
    for sname in (base_defined_statics(base_bytes) if base_bytes else []):
        if mapping.carve_row(sname) is not None:
            continue  # a non-colliding static that already joined by name
        key = demangled_key(sname)
        if key is not None:
            want_dec[sname] = key[0]

    def _pin_static(row_va: int, decorated: str) -> None:
        res = mapping.resolve(row_va)
        if res is None or res[1] != 0:
            return  # not an exact function-start -> not the static body
        row = res[0]
        if row.name_mangled or row.va in resolved_vas or row.va in static_name_by_va:
            return  # already named / already carved / already pinned
        static_name_by_va[row.va] = decorated
        funcs.append((decorated, row))

    if want_dec:
        # (1) base-relocation alignment
        for name, sym in list(funcs):
            fb = func_base.get(name)
            if fb is None:
                continue
            foff = pe.rva_to_off(sym.rva)
            dll_bytes = pe.data[foff : foff + sym.size]
            if not _aligned(dll_bytes, fb[0], fb[1]):
                continue
            for off, (tn, rt) in fb[1].items():
                if tn not in want_dec or off + 4 > len(dll_bytes):
                    continue
                if rt == IMAGE_REL_I386_REL32:
                    rel = struct.unpack_from("<i", dll_bytes, off)[0]
                    tgt_va = (sym.va + off + 4 + rel) & 0xFFFFFFFF
                elif rt == IMAGE_REL_I386_DIR32:
                    tgt_va = struct.unpack_from("<I", dll_bytes, off)[0]
                else:
                    continue
                _pin_static(tgt_va, tn)
        # (2) call-site + label endswith fallback
        for _n, sym in list(funcs):
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
                for dec, simple in want_dec.items():
                    if (row.name or "").endswith(simple):
                        _pin_static(row.va, dec)
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

    # --- Discover and carve this TU's data (W-DATA) -----------------------------
    # A base relocation names every symbol a function or vftable references; the
    # carved DLL bytes at the aligned offset give that symbol's address. So we seed
    # from code -- only functions that carved byte-identical *modulo relocations*,
    # so the base reloc offsets line up with the DLL operands -- then BFS through
    # data->data pointers (pointer arrays, vftable slots) to reach data that code
    # never names directly. b.text still holds the raw DLL bytes here (the reloc
    # pass below rewrites the fields), so the operand VAs are readable.
    # (func_base/data_base were parsed once, above the static discovery.)
    data_va: dict[str, int] = {}  # discovered data symbol name -> start VA

    def _want(name: str, va: int) -> None:
        if name not in data_va and name in data_base:
            data_va[name] = va

    if carve_data:
        for name, sym in funcs:
            fb = func_base.get(name)
            if fb is None:
                continue
            dll_bytes = bytes(b.text[text_off[name]:text_off[name] + sym.size])
            if not _aligned(dll_bytes, fb[0], fb[1]):
                continue
            for off, (tn, _rt) in fb[1].items():
                if tn in data_base and off + 4 <= len(dll_bytes):
                    v = struct.unpack_from("<I", dll_bytes, off)[0]
                    if lo <= v < hi:
                        _want(tn, v)
        queue = list(data_va.items())
        while queue:
            dname, dva = queue.pop()
            info = data_base[dname]
            if not info.relocs:
                continue
            doff = pe.rva_to_off(dva - pe.image_base)
            if doff is None:
                continue
            dbytes = pe.data[doff:doff + info.size]
            for off, (tn, _rt) in info.relocs.items():
                if tn in data_base and tn not in data_va and off + 4 <= len(dbytes):
                    v = struct.unpack_from("<I", dbytes, off)[0]
                    if lo <= v < hi:
                        _want(tn, v)
                        queue.append((tn, v))

    rdata_sec = data_sec = 0
    data_off: dict[str, int] = {}  # data name -> (secnum, offset in that section)
    for name, va in list(data_va.items()):
        info = data_base[name]
        off = pe.rva_to_off(va - pe.image_base)
        if off is None:
            del data_va[name]  # not raw-backed (e.g. straddles .bss); cannot carve
            continue
        dbytes = pe.data[off:off + info.size]
        if info.sec == ".data":
            data_sec = data_sec or b.add_data_section(".data", writable=True)
            secnum = data_sec
        else:
            rdata_sec = rdata_sec or b.add_data_section(".rdata")
            secnum = rdata_sec
        s = b.section(secnum)
        data_off[name] = (secnum, len(s.data))
        s.data += dbytes
        b.add_symbol(name, data_off[name][1], secnum, 0)
    data_name_by_va = {va: n for n, va in data_va.items()}

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
                dn = data_name_by_va.get(val)
                if dn is not None:  # a data symbol we carved -> name the ref after it
                    fld = insn_off + fld_off
                    struct.pack_into("<i", b.text, fld, 0)
                    b.relocs.append(Reloc(fld, b.symbol_index(dn, False),
                                          IMAGE_REL_I386_DIR32))
                    n_dir32 += 1
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

    # --- Data relocations: name each pointer slot after the base's target -------
    # A vftable slot / pointer-array element is an absolute pointer; the base's data
    # reloc names it (a function or nested data symbol) and the DLL dword gives its
    # value. Emit a DIR32 under that name so it pairs; only where the DLL dword is a
    # real in-image pointer (else it is a mismatch -- leave the bytes, don't fake a
    # relocation the original never had).
    n_data_rel = 0
    for name, va in data_va.items():
        info = data_base[name]
        if not info.relocs:
            continue
        secnum, base_o = data_off[name]
        s = b.section(secnum)
        doff = pe.rva_to_off(va - pe.image_base)
        for off, (tn, _rt) in info.relocs.items():
            if off + 4 > info.size:
                continue
            v = struct.unpack_from("<I", pe.data, doff + off)[0]
            if not (lo <= v < hi):
                continue
            res = mapping.resolve(v)
            addend = res[1] if res else 0
            struct.pack_into("<i", s.data, base_o + off, addend)
            s.relocs.append(Reloc(base_o + off,
                                  b.symbol_index(tn, tn not in data_base),
                                  IMAGE_REL_I386_DIR32))
            n_data_rel += 1

    # .text section symbol + aux, then the data section symbols, all with true
    # sizes/reloc counts now that every reference has been emitted.
    b.add_section_symbol(".text", 1, len(b.text), len(b.relocs))
    for secnum, sname in ((rdata_sec, ".rdata"), (data_sec, ".data")):
        if secnum:
            sec = b.section(secnum)
            b.add_section_symbol(sname, secnum, len(sec.data), len(sec.relocs))

    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_bytes(b.build())
    return {
        "funcs": len(funcs), "candidates": len(names),
        "rel32": n_rel32, "dir32": n_dir32, "iat": n_iat,
        "unresolved_calls": n_unresolved, "bytes": len(b.text),
        "data_syms": len(data_va), "data_rel": n_data_rel,
    }


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description="Carve an objdiff target object from a PE.")
    ap.add_argument("--dll", required=True, type=Path, help="original module (e.g. sysCore.dll)")
    ap.add_argument("--map", required=True, type=Path, help="master symbol map CSV")
    ap.add_argument("--base", type=Path, help="compiled base .obj for this TU")
    ap.add_argument("--names", type=Path,
                    help="filler mode: carve this list of decorated names (one per "
                         "line) into a standalone object, with no base .obj")
    ap.add_argument("--extra", type=Path,
                    help="CSV (va,size,name) of extra functions to carve by ADDRESS "
                         "as placeholder target symbols for objdiff manual mapping")
    ap.add_argument("--out", required=True, type=Path, help="target .obj to write")
    ap.add_argument("--module", default="SYSCORE", help="module id (informational)")
    ap.add_argument("--no-data", action="store_true",
                    help="carve only .text (skip the W-DATA data-section carving)")
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args(argv)
    if not args.base and not args.names:
        ap.error("one of --base or --names is required")

    mapping = load_map(args.map)
    explicit = None
    if args.names:
        explicit = [ln.strip() for ln in args.names.read_text().splitlines()
                    if ln.strip() and not ln.startswith("#")]
    extra = None
    if args.extra and args.extra.exists():             # absent = this TU has no placeholders
        extra = [(r["name"], int(r["va"], 16), int(r["size"]))
                 for r in csv.DictReader(args.extra.open(newline=""))]
    stats = extract(args.dll, mapping, args.base, args.out, args.module,
                    carve_data=not args.no_data, explicit_names=explicit, extra=extra)
    if args.verbose:
        print(f"{args.out.name}: {stats['funcs']}/{stats['candidates']} funcs, "
              f"{stats['bytes']} .text bytes, {stats['rel32']} REL32, "
              f"{stats['dir32']} DIR32, {stats['iat']} IAT, "
              f"{stats['unresolved_calls']} unresolved calls, "
              f"{stats['data_syms']} data syms ({stats['data_rel']} data relocs)",
              file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
