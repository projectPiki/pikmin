#!/usr/bin/env python3
"""Report a module's true completeness -- the honest "% of the real binary" -- for
the Pikmin Windows (VC6/PE) decomp.

The number objdiff reports (matched / emitted) answers "of the functions our source
*emits*, how many match?" -- but our source emits only a fraction of the functions
the shipped module actually contains, so that ratio flatters us. This tool fixes the
denominator to the **shipped ground truth**: every function the original linker knew,
read from the module's `.ilk` (the same list `ilk_reconcile.py` extracts and
validates by demangling). Against that fixed denominator it reports:

  coverage      -- ground-truth functions we emit at all (name-matched)
  byte-exact    -- ground-truth functions we reproduce byte-for-byte (fuzzy == 100)
  >=90% fuzzy   -- ground-truth functions that are close
  mean fuzzy    -- average best-fuzzy over ALL ground-truth functions
                   (unemitted counted as 0) -- a single soft progress scalar

"% of real binary" = byte-exact / ground-truth. That is the headline the 2026-07-05
gameplan check-in flagged as missing.

Matching is by decorated MSVC name (apples-to-apples with `ilk_reconcile`). A
`--canon` pass additionally credits a ground-truth function whose only difference
from an emitted byte-exact function is the struct-vs-class mangling key (V/U) -- an
upper bound that discounts the residual key cosmetics rather than the code.

Keying by name inherently deduplicates the inline-COMDAT copies objdiff shows in
every TU (each name's best fuzzy is taken across all emitting units), so no
`--deduplicate` report is needed here.

Usage:
    python tools/win/completeness.py plugPiki sysCore
    python tools/win/completeness.py plugPiki --report build/win/report.json --canon
    python tools/win/completeness.py plugPiki -o build/win/completeness.json
"""
from __future__ import annotations

import argparse
import json
from collections import defaultdict
from pathlib import Path

from ilk_reconcile import ROOT, _find_ilk, canon, extract_ilk, load_have


def data_bytes(report: Path, module: str) -> tuple[int, int]:
    """(matched, total) initialised-data bytes objdiff measured for a module -- the
    W-DATA dimension, carved into the target objects' `.rdata`/`.data` by
    pe_extract. total is the data our source emits (the carve denominator)."""
    rep = json.loads(report.read_text())
    matched = total = 0
    for u in rep['units']:
        if not u['name'].startswith(module + '/'):
            continue
        m = u.get('measures') or {}
        matched += int(m.get('matched_data', 0))
        total += int(m.get('total_data', 0))
    return matched, total


def measure(module: str, ilk: Path, report: Path, want_canon: bool) -> dict:
    gt_order = extract_ilk(ilk)
    gt_dem = dict(gt_order)
    gt_fns = [d for d, m in gt_order if '(' in m]        # ground-truth functions
    gt_set = set(gt_fns)

    have, _ = load_have(report, module)                  # decorated -> {best, dem, units}

    # best fuzzy for each ground-truth function under exact-name matching
    best_exact = {d: have[d]['best'] for d in gt_set if d in have}

    # optional canon (class-key-insensitive) augmentation: an emitted byte-exact
    # function whose canon key equals a ground-truth fn's, when the exact name missed.
    best_canon = dict(best_exact)
    if want_canon:
        canon_have: dict[str, float] = defaultdict(float)
        for d, info in have.items():
            canon_have[canon(info['dem'] or gt_dem.get(d) or d)] = max(
                canon_have[canon(info['dem'] or gt_dem.get(d) or d)], info['best'])
        for d in gt_set:
            if d not in best_canon:
                c = canon(gt_dem[d])
                if c in canon_have:
                    best_canon[d] = canon_have[c]

    def tally(best: dict[str, float]) -> dict:
        total = len(gt_set)
        cov = len(best)
        exact = sum(1 for v in best.values() if v >= 100.0)
        near = sum(1 for v in best.values() if 90.0 <= v < 100.0)
        mean = sum(best.values()) / total if total else 0.0   # unemitted == 0
        return {'ground_truth': total, 'covered': cov, 'byte_exact': exact,
                'near90': near, 'mean_fuzzy': mean}

    res = {'module': module, 'ilk': str(ilk), 'exact': tally(best_exact),
           'data': data_bytes(report, module)}
    if want_canon:
        res['canon'] = tally(best_canon)
    return res


def _pct(n: int, d: int) -> str:
    return f'{100.0 * n / d:5.1f}%' if d else '  n/a'


def _print(res: dict, want_canon: bool) -> None:
    e = res['exact']
    d = e['ground_truth']
    print(f"\n=== {res['module']} completeness (% of real binary) ===")
    print(f"  ground-truth functions (.ilk) : {d:6d}")
    print(f"  emitted (name-matched)        : {e['covered']:6d}  ({_pct(e['covered'], d)} coverage)")
    print(f"  BYTE-EXACT (100%)             : {e['byte_exact']:6d}  ({_pct(e['byte_exact'], d)} of real binary)  <==")
    print(f"  >=90% fuzzy                   : {e['near90']:6d}  ({_pct(e['near90'], d)})")
    print(f"  mean fuzzy over all GT fns    : {e['mean_fuzzy']:5.1f}%   (unemitted counted as 0)")
    print(f"  not yet emitted               : {d - e['covered']:6d}")
    if want_canon and 'canon' in res:
        c = res['canon']
        print("  -- canon (class-key-insensitive upper bound) --")
        print(f"     covered {c['covered']:6d} ({_pct(c['covered'], d)})   "
              f"byte-exact {c['byte_exact']:6d} ({_pct(c['byte_exact'], d)})")
    if 'data' in res:
        dm, dt = res['data']
        print(f"  data bytes byte-exact         : {dm:6d} / {dt:<6d} "
              f"({_pct(dm, dt)} of carved data)   [W-DATA]")


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('modules', nargs='+', help='module stems, e.g. plugPiki sysCore')
    ap.add_argument('--report', type=Path, default=ROOT / 'build/win/report.json',
                    help='objdiff report.json (what our source emits)')
    ap.add_argument('--ilk', type=Path, help='override .ilk path (single module only)')
    ap.add_argument('--canon', action='store_true',
                    help='also credit struct/class-key-only differences (upper bound)')
    ap.add_argument('-o', '--out', type=Path, help='write JSON summary here')
    args = ap.parse_args(argv)

    if args.ilk and len(args.modules) != 1:
        ap.error('--ilk applies to a single module')

    results = []
    agg = {'ground_truth': 0, 'covered': 0, 'byte_exact': 0, 'near90': 0,
           'mean_sum': 0.0, 'data_matched': 0, 'data_total': 0}
    for mod in args.modules:
        ilk = args.ilk or _find_ilk(mod)
        res = measure(mod, ilk, args.report, args.canon)
        results.append(res)
        _print(res, args.canon)
        e = res['exact']
        agg['ground_truth'] += e['ground_truth']
        agg['covered'] += e['covered']
        agg['byte_exact'] += e['byte_exact']
        agg['near90'] += e['near90']
        agg['mean_sum'] += e['mean_fuzzy'] * e['ground_truth']
        agg['data_matched'] += res['data'][0]
        agg['data_total'] += res['data'][1]

    if len(results) > 1:
        d = agg['ground_truth']
        print(f"\n=== TOTAL (all {len(results)} modules) ===")
        print(f"  ground-truth functions        : {d:6d}")
        print(f"  emitted (name-matched)        : {agg['covered']:6d}  ({_pct(agg['covered'], d)} coverage)")
        print(f"  BYTE-EXACT (100%)             : {agg['byte_exact']:6d}  ({_pct(agg['byte_exact'], d)} of real binary)  <==")
        print(f"  >=90% fuzzy                   : {agg['near90']:6d}  ({_pct(agg['near90'], d)})")
        print(f"  mean fuzzy over all GT fns    : {agg['mean_sum'] / d:5.1f}%")
        print(f"  data bytes byte-exact         : {agg['data_matched']:6d} / "
              f"{agg['data_total']:<6d} ({_pct(agg['data_matched'], agg['data_total'])} "
              f"of carved data)   [W-DATA]")

    if args.out:
        args.out.write_text(json.dumps({'modules': results, 'total': agg}, indent=2))
        print(f'\nwrote -> {args.out}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
