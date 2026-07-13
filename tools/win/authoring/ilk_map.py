#!/usr/bin/env python3
"""Project a module's shipped `.ilk` into the master-map interchange schema, and
expose the complete ground-truth function set for `completeness.py`.

For the Pikmin Windows (VC6/PE) decomp. The `.ilk` (decoded by the dependency-free
`ilk.py`) is the linker's own record of every EXTERNAL symbol: its exact decorated
name, real body RVA, incremental thunk, COFF type, and owning object. That is a
strictly better name->address stream than the disassembler heuristics the map was
built from, so this feeds `merge_symbols.py` as the `ilk` source:

  * a **body row** at the real function/data RVA, and
  * a **thunk row** at the incremental-link thunk RVA when the symbol is thunked
    (mirrors `read_exports`, so pe_extract resolves thunked call sites),
  * `name_mangled` = the linker's exact decoration (ground truth -- top precedence),
  * `name` = its demangling, `kind` from the COFF type (function vs data/vtable/string),
  * `size` = the RVA-sort estimate (the `.ilk` has no size field; disassembler sizes,
    where present, still win in the merge).

Blind spot (documented): file-local statics have no `.ilk` record, so they are absent
here -- the disassembler streams remain the only source for those.

Usage:
    python tools/win/authoring/ilk_map.py sysCore -o config/GPIE01_01/win/sysCore_ilk.csv
    python tools/win/authoring/ilk_map.py plugPiki           # prints counts only
"""
from __future__ import annotations

import argparse
import csv
import sys
from pathlib import Path

import _bootstrap  # noqa: F401  (authoring/_bootstrap.py: sys.path + ROOT)
from ilk import Ilk, add_size_by_sort
from ilk_reconcile import ROOT, _find_ilk, demangle

# a symbol whose COFF section is UNDEF (0) or ABSOLUTE (0xFFFF) has no body in this
# image (imports, linker absolutes) -- not a map row.
_NO_BODY = {0, 0xFFFF}


def _kind(sym: dict) -> str:
    n = sym["name"]
    if n.startswith("??_7") or n.startswith("??_8"):
        return "vtable"
    if n.startswith("??_C"):
        return "string"
    if sym["coff_type"] == 0x20:
        return "function"
    return "data"


def load(ilk_path: Path):
    ik = Ilk(str(ilk_path))
    syms = ik.symbols()
    add_size_by_sort(syms)
    return ik, syms


def map_rows(ilk_path: Path) -> list[dict]:
    """Interchange rows (body + thunk) for merge_symbols.read_labels."""
    _ik, syms = load(ilk_path)
    rows: list[dict] = []
    for s in syms:
        if s["rva"] is None or s["section"] in _NO_BODY:
            continue
        kind = _kind(s)
        dem = demangle(s["name"]) or s["name"]
        size = s.get("size_by_sort") or 0
        rows.append(dict(rva="0x%08x" % s["rva"], kind=kind,
                         size=(size if kind == "function" else 0),
                         name_mangled=s["name"], name=dem, source="ilk"))
        if s["thunk_off"]:
            rows.append(dict(rva="0x%08x" % s["thunk_rva"], kind="thunk", size=0,
                             name_mangled=s["name"], name=dem, source="ilk"))
    return rows


def ground_truth_data(ilk_path: Path) -> list[dict]:
    """The data counterpart of ground_truth_functions: every non-FUNCTION symbol with a
    body in the image, deduped by decorated name, with an RVA-sort `size`.

    The `.ilk` carries no size field, so `size` is the gap to the next symbol in the
    same PE section -- exact except where a file-local static (which the `.ilk` never
    records) sits in the gap and gets charged to the external in front of it. The last
    symbol in a section has no successor and is dropped rather than guessed at."""
    _ik, syms = load(ilk_path)
    out: dict[str, dict] = {}
    for s in syms:
        if s["coff_type"] == 0x20 or s["section"] in _NO_BODY or s["rva"] is None:
            continue
        if s["name"] not in out and s.get("size_by_sort"):
            out[s["name"]] = {"name": s["name"], "rva": s["rva"],
                              "size": s["size_by_sort"]}
    return list(out.values())


def ground_truth_functions(ilk_path: Path) -> list[tuple[str, str]]:
    """Complete completeness denominator: (decorated, demangled) for every FUNCTION
    (COFF type 0x20) defined in the image, deduped by decorated name, address-ordered.
    Supersedes ilk_reconcile.extract_ilk's partial regex scan."""
    _ik, syms = load(ilk_path)
    seen: dict[str, str] = {}
    for s in sorted(syms, key=lambda s: (s["rva"] if s["rva"] is not None else 0)):
        if s["coff_type"] != 0x20 or s["section"] in _NO_BODY:
            continue
        dec = s["name"]
        if dec not in seen:
            seen[dec] = demangle(dec) or dec
    return list(seen.items())


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("module", help="module stem, e.g. sysCore")
    ap.add_argument("--ilk", type=Path, help="override .ilk path")
    ap.add_argument("-o", "--out", type=Path, help="write interchange CSV here")
    args = ap.parse_args(argv)

    ilk = args.ilk or _find_ilk(args.module)
    rows = map_rows(ilk)
    gt = ground_truth_functions(ilk)
    nbody = sum(1 for r in rows if r["kind"] != "thunk")
    nthunk = sum(1 for r in rows if r["kind"] == "thunk")
    print(f"{args.module}: {len(gt)} distinct ground-truth functions; "
          f"{nbody} body rows + {nthunk} thunk rows  <- {ilk}", file=sys.stderr)

    if args.out:
        with open(args.out, "w", newline="") as f:
            w = csv.DictWriter(f, fieldnames=["rva", "kind", "size", "name_mangled",
                                              "name", "source"], lineterminator="\n")
            w.writeheader()
            w.writerows(rows)
        print(f"wrote -> {args.out}", file=sys.stderr)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
