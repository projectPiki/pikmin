#!/usr/bin/env python3
r"""Round-trip objdiff MANUAL SYMBOL MAPPINGS into the master map, for the Pikmin
Windows (VC6/PE) decomp -- the interactive complement to autodraft_labels.py.

objdiff's GUI lets a human pick, for an unmatched BASE function (our compiled
`?foo@Bar@@...`), the TARGET symbol it should be compared against -- guided by the
live byte diff. It persists that choice in the unit's `symbol_mappings` map in
`objdiff.json`. For those choices to exist, the carved target must contain the
unlabelled DLL functions as symbols: carve with
`pe_extract.py --extra <va,size,name csv>` (placeholder `FUN_<addr>` targets; the
`build/win/pairing/<mod>/<tu>.csv` ADDR rows are exactly that list).

This tool reads `objdiff.json`, and for every mapping pairing a decorated base name
with a `FUN_<hex>`/`sub_<hex>` placeholder (either key or value -- direction is not
assumed), assigns that decorated name to the map row at the placeholder's address
(the hex suffix, cross-checked against the map's label). Dry-run by default; backs
the map up to `build/win/mapbak/` on --apply. Re-carve + win_report to confirm
(a correct mapping carves byte-identical, exactly like the other passes).

Usage:
    python tools/win/objdiff_mappings.py plugPiki                 # preview
    python tools/win/objdiff_mappings.py plugPiki --apply
"""
from __future__ import annotations

import argparse
import csv
import json
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import pydemumble  # noqa: E402
from mapbak import backup  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
PLACEHOLDER = re.compile(r"^(?:FUN_|sub_|loc_)([0-9a-fA-F]+)$")


def classify(a: str, b: str):
    """(placeholder, decorated) -> (address_va, decorated_name), or None. Tries both
    orders so the mapping's key/value direction need not be known."""
    for ph, other in ((a, b), (b, a)):
        m = PLACEHOLDER.match(ph)
        if m and other.startswith("?"):
            return int(m.group(1), 16), other, ph
    return None


def collect(objdiff_json: Path, module: str):
    cfg = json.loads(objdiff_json.read_text())
    out = []
    for u in cfg.get("units", []):
        name = u.get("name", "")
        if module and not name.startswith(module + "/"):
            continue
        sm = u.get("symbol_mappings") or {}
        for k, v in sm.items():
            c = classify(k, v)
            if c:
                out.append((name, *c))            # (unit, va, decorated, placeholder)
    return out


def run(module: str, objdiff_json: Path, apply: bool) -> None:
    pairs = collect(objdiff_json, module)
    mp = ROOT / f"config/GPIE01_01/win/{module}_map.csv"
    rows = list(csv.DictReader(mp.open(newline="")))
    by_va = {int(r["va"], 16): r for r in rows if r["kind"] == "function"}

    todo, warn = [], []
    for unit, va, dec, ph in pairs:
        row = by_va.get(va)
        if row is None:
            warn.append(f"{ph}: va {va:#x} is not a map function row")
            continue
        # cross-check: the placeholder should be this row's current label
        cur = (row.get("name") or "")
        if cur and cur != ph and PLACEHOLDER.match(cur):
            warn.append(f"{ph}: map label at {va:#x} is {cur} (mismatch)")
        todo.append((va, row, dec, pydemumble.demangle(dec) or ""))

    print(f"=== {module}: {len(pairs)} objdiff mappings -> {len(todo)} map assignments ===")
    for va, _row, dec, dm in todo[:40]:
        print(f"   {va:#x}  {dec}  ({dm})")
    if len(todo) > 40:
        print(f"   ... (+{len(todo) - 40} more)")
    for w in warn[:10]:
        print(f"   !! {w}")

    if apply and todo:
        bak = backup(mp)
        for va, row, dec, dm in todo:
            row["name_mangled"] = dec
            if dm:
                row["name"] = dm
        with mp.open("w", newline="") as fh:
            w = csv.DictWriter(fh, fieldnames=rows[0].keys())
            w.writeheader()
            w.writerows(rows)
        print(f"   applied {len(todo)} to {mp}  (backup {bak.name}) -- re-carve to confirm")
    elif todo:
        print("   (dry-run; pass --apply to write)")


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("module")
    ap.add_argument("--objdiff", type=Path, default=ROOT / "objdiff.json",
                    help="objdiff.json holding the GUI's symbol_mappings")
    ap.add_argument("--apply", action="store_true")
    args = ap.parse_args(argv)
    run(args.module, args.objdiff, args.apply)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
