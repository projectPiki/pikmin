#!/usr/bin/env python3
"""Merge the authoritative PE export table with disassembler labels into the
master RVA-keyed symbol map for one Windows-decomp module.

For the Pikmin Windows (VC6/PE) decomp. Three streams of truth about a module's
symbols get folded here, one row per address:

  * exports  - `pe_symbols.py` CSV (ground truth for exported names + thunk bodies,
               straight from the shipped PE).
  * ghidra   - `ghidra/export_symbols.py` CSV (rich internal labels, e.g. plugPiki).
  * ida      - `ida/export_symbols.py` CSV (rich internal labels, e.g. sysCore).

The master map is the crown jewel of the effort: reccmp `// FUNCTION:`/`// GLOBAL:`
seeding and the objdiff extractor are only as good as it. So the merge is
conservative about names:

  * Provenance precedence for the label: manual > ida/ghidra > export. A human
    relabel supersedes the raw export name and is never clobbered by a re-export.
  * BUT disassembler placeholder names (`sub_`, `FUN_`, `loc_`, `dword_`, ...)
    never outrank a real name. They still contribute the address + size (valuable
    for boundaries/extraction) while leaving the export's true name intact.
  * The decorated/mangled name is preserved from whichever source kept it, since
    objdiff names data/global/vtable relocations by decorated symbol.

Output CSV: rva,va,kind,size,name_mangled,name,source
  rva/va  - image-base-relative and absolute (va = image_base + rva).
  kind    - function|thunk|data|string|vtable|forwarder.
  size    - bytes (0 if unknown; disassembler sizes preferred over export's 0).
  source  - all contributing streams, e.g. "export+ida".

Usage:
    python tools/win/authoring/merge_symbols.py --target sysCore \
        --exports config/GPIE01_01/win/sysCore_symbols.csv \
        --labels  sysCore_ida.csv \
        -o config/GPIE01_01/win/sysCore_map.csv
"""
from __future__ import annotations

import argparse
import csv
import re
import sys
from dataclasses import dataclass, field

# Auto-generated names from IDA/Ghidra that carry no human meaning. They provide
# address + size but must never overwrite a real (export or hand-labelled) name.
_PLACEHOLDER = re.compile(
    r"^(?:sub|loc|locret|unk|byte|word|dword|qword|xmmword|off|flt|dbl|stru|"
    r"asc|a[A-Z0-9]|jpt|def|nullsub|thunk|thunk_FUN|j|unknown|FUN|DAT|LAB|SUB|UNK|PTR|s|u)_",
)

# Precedence for the human *label* (`name`): a hand refinement supersedes a raw export.
_SRC_PRIORITY = {"manual": 3, "ida": 2, "ghidra": 2, "export": 1}


def _mangled_priority(sources: set) -> int:
    """Precedence for the *decorated* name — inverted from the label: the PE export
    table is the authoritative decoration, so it outranks a disassembler's."""
    if "export" in sources:
        return 3
    if "manual" in sources:
        return 2
    return 1


def is_placeholder(name: str) -> bool:
    return not name or bool(_PLACEHOLDER.match(name))


def export_kind(demangled: str, mangled: str, forwarder: str) -> str:
    """Classify a PE export — the export table alone can't tell code from data.

    A trustworthy demangling is decisive: MSVC data symbols (`?x@@3HA`, static
    members, globals) demangle *without* a parameter list; string constants
    demangle to a quoted literal; anything with a `(...)` arg list is a function.
    When demangling FAILED (`pydemumble` leaves ~77 sysCore names decorated, so
    `demangled == mangled`), fall back to the decoration shape: a decorated MSVC
    *function* name ends in `Z` (the argument-list terminator); data does not.
    Undecorated C exports (`NewObject`) default to function."""
    if forwarder:
        return "forwarder"
    if demangled[:1] in ('"', "`"):
        return "string"
    if demangled and demangled != mangled:  # trustworthy demangling
        return "function" if "(" in demangled else "data"
    if mangled.startswith("?"):  # decorated but un-demangled: use the shape
        return "function" if mangled.endswith("Z") else "data"
    return "function"  # undecorated C export


@dataclass
class Sym:
    rva: int
    kind: str = "function"
    size: int = 0
    name_mangled: str = ""
    name: str = ""
    sources: set = field(default_factory=set)

    def merge_in(self, other: "Sym") -> None:
        self_only = self.sources - other.sources  # before we fold other in
        self.sources |= other.sources
        op = max((_SRC_PRIORITY.get(s, 0) for s in other.sources), default=0)
        sp = max((_SRC_PRIORITY.get(s, 0) for s in self_only), default=0)

        # name (human label): human/disassembler refinement wins; placeholders never clobber.
        if not is_placeholder(other.name):
            if is_placeholder(self.name) or op > sp or (op == sp and len(other.name) > len(self.name)):
                self.name = other.name
        # name_mangled (decorated symbol): the PE export table is ground truth, so the
        # export's clean name beats a disassembler's (e.g. IDA's `_0` dedup suffix);
        # disassemblers only fill in internal symbols the export table never had.
        if other.name_mangled:
            om, sm = _mangled_priority(other.sources), _mangled_priority(self_only)
            if not self.name_mangled or om > sm or (om == sm and len(other.name_mangled) > len(self.name_mangled)):
                self.name_mangled = other.name_mangled
        # kind: disassembler (higher priority) is authoritative; else prefer specific over "function".
        if other.kind and other.kind != "function":
            if self.kind == "function" or op >= sp:
                self.kind = other.kind
        # size: prefer a known (non-zero) size, disassembler over export.
        if other.size and (not self.size or op >= sp):
            self.size = other.size


def read_exports(path: str, image_base_out: list) -> list[Sym]:
    """Project a pe_symbols.py CSV into master rows: a body row at real_rva, plus a
    thunk row at rva when the export routes through an incremental-link stub."""
    out: list[Sym] = []
    with open(path, newline="") as f:
        for r in csv.DictReader(f):
            rva = int(r["rva"], 16)
            real_rva = int(r["real_rva"], 16)
            va = int(r["va"], 16)
            image_base_out.append(va - rva)
            demangled = r.get("demangled") or r["mangled"]
            kind = export_kind(demangled, r["mangled"], r.get("forwarder", ""))
            out.append(Sym(rva=real_rva, kind=kind, name_mangled=r["mangled"],
                           name=demangled, sources={"export"}))
            # Only code exports route through incremental-link jmp thunks.
            if real_rva != rva and kind == "function":
                out.append(Sym(rva=rva, kind="thunk", name_mangled=r["mangled"],
                               name=(r.get("demangled") or r["mangled"]), sources={"export"}))
    return out


def read_labels(path: str) -> list[Sym]:
    out: list[Sym] = []
    with open(path, newline="") as f:
        for r in csv.DictReader(f):
            out.append(Sym(
                rva=int(r["rva"], 16),
                kind=r.get("kind") or "function",
                size=int(r["size"]) if r.get("size") else 0,
                name_mangled=r.get("name_mangled", ""),
                name=r.get("name", ""),
                sources={(r.get("source") or "manual").strip()},
            ))
    return out


def merge(streams: list[list[Sym]]) -> dict[int, Sym]:
    table: dict[int, Sym] = {}
    for stream in streams:
        for sym in stream:
            if sym.rva in table:
                table[sym.rva].merge_in(sym)
            else:
                table[sym.rva] = sym
    return table


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--target", required=True, help="logical module name (e.g. sysCore)")
    ap.add_argument("--exports", help="pe_symbols.py CSV for this module (authoritative export names)")
    ap.add_argument("--labels", action="append", default=[], help="disassembler CSV(s); repeatable")
    ap.add_argument("--image-base", type=lambda s: int(s, 0), help="PE image base if no --exports (default 0x10000000)")
    ap.add_argument("-o", "--out", help="output CSV (default: stdout)")
    args = ap.parse_args(argv)

    bases: list[int] = []
    streams: list[list[Sym]] = []
    if args.exports:
        streams.append(read_exports(args.exports, bases))
    for lab in args.labels:
        streams.append(read_labels(lab))
    if not streams:
        ap.error("need --exports and/or --labels")

    image_base = bases[0] if bases else (args.image_base if args.image_base is not None else 0x10000000)
    table = merge(streams)
    syms = sorted(table.values(), key=lambda s: s.rva)

    def emit(f):
        w = csv.writer(f, lineterminator="\n")
        w.writerow(["rva", "va", "kind", "size", "name_mangled", "name", "source"])
        for s in syms:
            w.writerow(["0x%08x" % s.rva, "0x%08x" % (image_base + s.rva), s.kind,
                        s.size, s.name_mangled, s.name, "+".join(sorted(s.sources))])

    if args.out:
        with open(args.out, "w", newline="") as f:
            emit(f)
        labelled = sum(1 for s in syms if not is_placeholder(s.name))
        print(f"{args.target}: {len(syms)} symbols ({labelled} named, image_base=0x{image_base:08x}) -> {args.out}",
              file=sys.stderr)
    else:
        emit(sys.stdout)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
