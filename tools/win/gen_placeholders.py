#!/usr/bin/env python3
r"""Emit, per TU, the function addresses `pe_extract.py` will NOT carve from the base
-- as extra target symbols (`pe_extract.py --extra`) -- for the Pikmin Windows (VC6/PE)
decomp.

`pe_extract.py`'s primary carve is BASE-DRIVEN: it takes the decorated names the
compiled base object *defines* (`base_defined_functions`) and looks each up in the map.
A DLL function whose source we have not written yet therefore has NO target symbol at
all -- nothing to diff against, nothing to map onto, and (worse) nothing in objdiff's
denominator, so a TU with no source scores a fake 100%. This tool closes that gap by
listing every one of a TU's DLL functions that the base carve will miss, grouped by
their byte-faithful TU (`<mod>_text_ranges.csv`, the decoded `.text` contributions):

  * map row HAS a decorated `name_mangled` -> emit it under that decorated name. It
    shows in objdiff as an unmatched target function and counts toward the metric; the
    moment our source defines it, the base carve claims the same VA and `--extra`
    stands down (pe_extract skips any extra colliding with an already-carved body), so
    the two pair by name with no further bookkeeping.
  * map row is UNLABELLED (no mangled name, label empty or a disassembler placeholder)
    -> emit a `FUN_<addr>` placeholder, the manual-mapping target for an unmatched base
    function whose address we have not identified yet.

A row with a real label but NO decorated name is deliberately SKIPPED: pe_extract owns
those, either via the demangled-name bridge or -- for a file-static (`_Print`, `_Error`,
`quickABS`, per-TU-labelled) -- via its call-site/relocation pinning, which carves the
body under the BASE's decorated name so it pairs. Emitting such a row here would put its
VA in pe_extract's `resolved_vas` and shadow that pinning (see pe_extract.py:875,911).

It is deliberately MAP-ONLY (no objdiff report, no base object): that avoids the
report<->target build cycle and matches review_labels.py's notion of "unlabelled".
Being map-only, it cannot know whether the base actually defines a named row -- it does
not need to, because the VA-collision guard makes emitting one harmless either way.

Writes `build/win/placeholders/<mod>/<tu>.csv` (va,size,name), lowercase TU stem (so
it matches `<source-stem>.lower()`), plus a `<mod>.stamp` marker.

Usage:
    python tools/win/gen_placeholders.py plugPiki --out build/win/placeholders/plugPiki
"""
from __future__ import annotations

import argparse
import bisect
import csv
import re
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
PLACEHOLDER = re.compile(r"^(FUN_|sub_|loc_|j_|unk_|thunk_FUN_)")


def load_tu_index(mod: str):
    """(sorted [(lo,hi,stem)], [lo...]) from the tracked <mod>_text_ranges.csv.

    That table is the byte-faithful object->.text-range map exported from the .ilk by
    `ilk_layout.py --ranges-csv`. Reading the committed CSV instead of the .ilk keeps
    the routine build reproducible on a clean checkout (see tools/win/README.md);
    `ilk_layout`/`ilk_functions` stay authoring-only tools.
    """
    p = ROOT / f"config/GPIE01_01/win/{mod}_text_ranges.csv"
    if not p.exists():
        raise SystemExit(f"{p} missing -- regenerate with "
                         f"`python tools/win/authoring/ilk_layout.py {mod} --ranges-csv {p}`")
    ivs = [(int(r["lo_rva"], 16), int(r["hi_rva"], 16), r["stem"])
           for r in csv.DictReader(p.open(newline=""))]
    ivs.sort()
    return ivs, [i[0] for i in ivs]


def tu_at(rva: int, ivs, starts) -> str | None:
    i = bisect.bisect_right(starts, rva) - 1
    if 0 <= i < len(ivs) and ivs[i][0] <= rva < ivs[i][1]:
        return ivs[i][2]
    return None


def run(mod: str, out: Path) -> None:
    ivs, starts = load_tu_index(mod)

    by_tu: dict[str, list] = defaultdict(list)
    n_named = n_ph = 0
    mp = ROOT / f"config/GPIE01_01/win/{mod}_map.csv"
    for row in csv.DictReader(mp.open(newline="")):
        if row["kind"] != "function":
            continue
        size = int(row.get("size") or 0)
        if size <= 0:
            continue
        decorated = (row.get("name_mangled") or "").strip()
        label = (row.get("name") or "").strip()
        if not decorated and label and not PLACEHOLDER.match(label):
            continue          # pe_extract owns it: demangled bridge, or file-static pinning
        rva = int(row["rva"], 16)
        tu = tu_at(rva, ivs, starts)
        if not tu:
            continue
        va = int(row["va"], 16)
        # A decorated name is the name our source WILL define, so the target symbol
        # pairs by name the moment it does (until then it is an honest unmatched
        # target function). An unlabelled row gets the FUN_ manual-mapping placeholder.
        by_tu[tu].append((va, size, decorated or label or f"FUN_{va:x}"))
        if decorated:
            n_named += 1
        else:
            n_ph += 1

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
    (out.parent / f"{mod}.stamp").write_text(
        f"{len(by_tu)} tus {total} extras ({n_named} named, {n_ph} placeholder)\n")
    print(f"=== {mod}: {total} extra targets across {len(by_tu)} TUs "
          f"({n_named} named, {n_ph} FUN_ placeholder) -> {out}/ ===")


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
