#!/usr/bin/env python3
r"""Emit, per TU, the module's UNLABELLED function addresses as placeholder target
symbols for objdiff manual mapping -- for the Pikmin Windows (VC6/PE) decomp.

`pe_extract.py` carves a target containing only the functions the map can NAME, so an
unmatched base function (one our source compiles but whose original address is still a
`FUN_`/`sub_` placeholder in the map) has nothing in the target to be mapped onto in
objdiff. This tool lists those unlabelled addresses -- grouped by their byte-faithful
TU (`ilk_functions.tu_at`, the decoded `.text` contributions) -- so the target carve
can add each as a `FUN_<addr>` placeholder (`pe_extract.py --extra`).

It is deliberately MAP-ONLY (no objdiff report): a function needs a placeholder iff
the map has no decorated `name_mangled` for it and its label is a disassembler
placeholder (or empty). That avoids the report<->target build cycle and matches
review_labels.py's notion of "unlabelled".

Writes `build/win/placeholders/<mod>/<tu>.csv` (va,size,name), lowercase TU stem (so
it matches `<source-stem>.lower()`), plus a `<mod>.stamp` marker.

Usage:
    python tools/win/gen_placeholders.py plugPiki --out build/win/placeholders/plugPiki
"""
from __future__ import annotations

import argparse
import csv
import re
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from ilk_functions import find_ilk, tu_at, tu_index  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
PLACEHOLDER = re.compile(r"^(FUN_|sub_|loc_|j_|unk_|thunk_FUN_)")


def run(mod: str, out: Path) -> None:
    ivs, starts = tu_index(find_ilk(mod).read_bytes())

    by_tu: dict[str, list] = defaultdict(list)
    mp = ROOT / f"config/GPIE01_01/win/{mod}_map.csv"
    for row in csv.DictReader(mp.open(newline="")):
        if row["kind"] != "function":
            continue
        if (row.get("name_mangled") or "").strip():
            continue                                   # named -> carved by name
        label = (row.get("name") or "").strip()
        if label and not PLACEHOLDER.match(label):
            continue                                   # a real Ghidra label -> bridge-carved
        size = int(row.get("size") or 0)
        if size <= 0:
            continue
        rva = int(row["rva"], 16)
        tu = tu_at(rva, ivs, starts)
        if not tu:
            continue
        by_tu[tu].append((int(row["va"], 16), size, label or f"FUN_{int(row['va'], 16):x}"))

    out.mkdir(parents=True, exist_ok=True)
    for f in out.glob("*.csv"):
        f.unlink()
    total = 0
    for tu, rows in by_tu.items():
        with (out / f"{tu}.csv").open("w", newline="") as fh:
            w = csv.writer(fh)
            w.writerow(["va", "size", "name"])
            for va, size, name in sorted(rows):
                w.writerow([f"{va:#x}", size, name])
        total += len(rows)
    (out.parent / f"{mod}.stamp").write_text(f"{len(by_tu)} tus {total} placeholders\n")
    print(f"=== {mod}: {total} placeholder targets across {len(by_tu)} TUs -> {out}/ ===")


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("module")
    ap.add_argument("--out", type=Path, required=True)
    args = ap.parse_args(argv)
    run(args.module, args.out)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
