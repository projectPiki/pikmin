#!/usr/bin/env python3
"""Generate the Windows objdiff progress report - both the full per-unit report
and the deduplicated honest metric - and print a side-by-side summary.

For the Pikmin Windows (VC6/PE) decomp. Under `/Od` every referenced inline
member is emitted as a COMDAT-select-ANY external in every TU that uses it (and
`SYSCORE_EXPORTS` widens that to every TU that includes the header), so a single
inline function is counted in dozens of units. That inflates the raw report
(sysCore: ~87% of the function entries are redundant duplicate inline copies).
objdiff-cli's `--deduplicate` collapses those weak/global symbols to one, giving
the honest number.

We keep BOTH:
  * `report.json`        - full, un-deduplicated. This is the tooling artifact:
                           `ilk_reconcile.py`/`inline_owner.py` and anything that
                           needs the true per-unit symbol emission reads this one.
  * `report_dedup.json`  - deduplicated. The honest progress metric.

Both are generated from the RAW obj/target tree via the `build/win/full`
objdiff config (NOT the root objdiff.json, which points at the deduped GUI tree
where each inline already appears once -- inline_owner needs to see every emitter).

Run after `ninja -f build/win/build.ninja target` re-carves the target objects.

Usage:
    python tools/win/win_report.py
"""
from __future__ import annotations

import json
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
CLI = ROOT / 'build/tools/objdiff-cli.exe'
FULL = ROOT / 'build/win/report.json'
DEDUP = ROOT / 'build/win/report_dedup.json'
# The raw (un-deduplicated) objdiff project, emitted by configure_win.py; the root
# objdiff.json points at the deduped GUI tree and would hide the per-unit emitters.
FULL_PROJ = ROOT / 'build/win/full'


def _newest(d: Path) -> float:
    """Newest mtime of any *.obj under d, or 0.0 if none/absent."""
    return max((p.stat().st_mtime for p in d.rglob('*.obj')), default=0.0)


def warn_if_gui_stale() -> None:
    """Tripwire for the raw/deduped two-tree split: the objdiff GUI reads the
    deduped tree, but this report (and inline_owner/ilk_reconcile) read the raw one.
    Re-carving only `target` leaves the GUI stale -- warn if target_dedup is older
    than target so a fixed pairing isn't silently invisible in the GUI."""
    raw = ROOT / 'build/win/target'
    dedup = ROOT / 'build/win/target_dedup'
    if dedup.exists() and _newest(dedup) + 1 < _newest(raw):
        print("\n!! objdiff GUI tree (build/win/target_dedup) is OLDER than the raw "
              "tree.\n   Run `ninja -f build/win/build.ninja objdiff` to resync both "
              "(or `dedup`).", file=sys.stderr)


def gen(out: Path, dedup: bool) -> None:
    cmd = [str(CLI), 'report', 'generate', '-p', str(FULL_PROJ), '-o', str(out)]
    if dedup:
        cmd.append('--deduplicate')
    subprocess.run(cmd, cwd=ROOT, check=True)


def summarise(path: Path):
    r = json.loads(path.read_text())
    per = {}
    for u in r['units']:
        mod = u['name'].split('/')[0]
        m = u.get('measures') or {}
        d = per.setdefault(mod, [0, 0])
        d[0] += m.get('matched_functions', 0)
        d[1] += m.get('total_functions', 0)
    tot = r['measures']
    return per, (tot.get('matched_functions', 0), tot.get('total_functions', 0),
                 round(tot.get('fuzzy_match_percent', 0.0), 2))


def main() -> int:
    if not CLI.exists():
        print(f'objdiff-cli not found at {CLI}', file=sys.stderr)
        return 1
    gen(FULL, dedup=False)
    gen(DEDUP, dedup=True)
    fper, ftot = summarise(FULL)
    dper, dtot = summarise(DEDUP)
    print('\n=== Windows objdiff progress (matched/total functions) ===')
    print(f'{"module":12s} {"full":>18s}   {"deduplicated":>18s}')
    for mod in sorted(fper):
        fm, ftl = fper[mod]
        dm, dtl = dper.get(mod, (0, 0))
        print(f'{mod:12s} {fm:8d}/{ftl:<8d}   {dm:8d}/{dtl:<8d}')
    print(f'{"TOTAL":12s} {ftot[0]:8d}/{ftot[1]:<8d}   {dtot[0]:8d}/{dtot[1]:<8d}'
          f'   fuzzy {dtot[2]}%')
    print('\nreport.json = full (per-unit tooling); report_dedup.json = honest metric')
    warn_if_gui_stale()
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
