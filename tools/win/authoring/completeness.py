#!/usr/bin/env python3
"""Report a module's true completeness -- the honest "% of the real binary" -- for
the Pikmin Windows (VC6/PE) decomp.

The number objdiff reports (matched / emitted) answers "of the functions our source
*emits*, how many match?" -- but our source emits only a fraction of the functions
the shipped module actually contains, so that ratio flatters us. This tool fixes the
denominator to the **shipped ground truth**: every function the original linker knew,
read from the module's `.ilk` symbol table via `ilk_map.ground_truth_functions`
(the complete, address-anchored, COFF-typed set). Against that fixed denominator it reports:

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
    python tools/win/authoring/completeness.py plugPiki sysCore
    python tools/win/authoring/completeness.py plugPiki --report build/win/report.json --canon
    python tools/win/authoring/completeness.py plugPiki -o build/win/completeness.json
"""
from __future__ import annotations

import argparse
import json
from collections import defaultdict
from pathlib import Path

from ilk_reconcile import ROOT, _find_ilk, canon, load_have
from ilk_map import ground_truth_data as ilk_data_symbols, ground_truth_functions
from pe_extract import (base_symbol_bridge, data_verdict, load_map, parse_base_coff)
from pe_symbols import PEFile

DLLS = {'sysCore': 'orig/GPIE01_01/files/sysCore.dll',
        'plugPiki': 'orig/GPIE01_01/files/plugins/plugPiki.dll'}


def data_measure(module: str, ilk: Path) -> dict:
    """The honest data dimension: "% of the real binary's DATA bytes we reproduce".

    Not read from the objdiff report, for two reasons. Its `total_data` is the data our
    source *emits* -- the same flattering denominator this tool exists to replace -- and
    under `/Od` every COMDAT string, fp-constant and vftable is emitted in each TU that
    uses one, so the report counts the same bytes dozens of times over. So:

      denominator -- every DATA symbol the shipped `.ilk` knows, sized by the gap to the
        next symbol in its PE section. This is the exact counterpart of the function
        denominator above (which is every `.ilk` FUNCTION), and it inherits the same
        blind spot: a file-local static has no `.ilk` record, so its bytes are silently
        attributed to the external in front of it. Deliberately NOT the section-
        contribution table, which would be more direct but whose module records the
        format notes are stale/incomplete after an incremental relink (sysCore's walk
        finds a few hundred of its contributions, not all of them).
      numerator   -- our base objects' data symbols, DEDUPED BY DECORATED NAME (which is
        what makes the COMDAT copies collapse to one), each judged byte-for-byte against
        the original at the address the `.ilk` gives its name (pe_extract.data_verdict --
        the very test the carved target is scored on).

    Uninitialised data is split out of both and NOT byte-counted: it is zeros on either
    side, so comparing it is vacuously perfect. (MSVC puts anything zero-initialised in
    `.bss`, which is why an all-zero image symbol is the test for it.) What is real there
    is whether each uninitialised global exists in the original at all -- i.e. whether
    the `.ilk` has its exact decorated name -- so that is what gets reported."""
    pe = PEFile((ROOT / DLLS[module]).read_bytes())
    mapping = load_map(ROOT / f'config/GPIE01_01/win/{module}_map.csv')

    gt = defaultdict(int)
    for s in ilk_data_symbols(ilk):
        sec = pe.section_for_rva(s['rva'])
        if sec is None or sec.name not in ('.rdata', '.data'):
            continue
        size = s['size'] or 0
        img = pe.image_bytes(s['rva'], size)
        zero = img is not None and not any(img)
        gt['.bss' if zero else sec.name] += size

    seen: dict[str, tuple] = {}   # decorated -> (BaseData, located, exact)
    for obj in sorted((ROOT / 'build/win/obj' / module).glob('*.obj')):
        raw = obj.read_bytes()
        _funcs, data = parse_base_coff(raw)
        bridge = base_symbol_bridge(raw)
        for name, info in data.items():
            if name in seen:
                continue
            row = mapping.data_row(name)
            if row is None:
                seen[name] = (info, False, False)
            else:
                seen[name] = (info, True, info.bss or
                              data_verdict(pe, mapping, bridge, info, row.va))

    res = {'ground_truth_bytes': gt['.rdata'] + gt['.data'],
           'bss_ground_truth_bytes': gt['.bss'], 'sections': dict(gt),
           'covered_bytes': 0, 'exact_bytes': 0,
           'stray_external_bytes': 0, 'static_bytes': 0,
           'bss_total': 0, 'bss_located': 0, 'unmatched_external': []}
    for name, (info, located, exact) in seen.items():
        if info.bss:
            res['bss_total'] += 1
            res['bss_located'] += located
        elif located:
            res['covered_bytes'] += info.size
            if exact:
                res['exact_bytes'] += info.size
        elif info.external:
            # An EXTERNAL data symbol the `.ilk` has no name for is a real finding, not
            # a tooling gap: the linker recorded every external, so a miss means our
            # declaration disagrees with the original's -- a wrong type, a stray const, a
            # global the original never had.
            res['stray_external_bytes'] += info.size
        else:
            # A file-local static, on the other hand, is simply invisible to the `.ilk`
            # (the documented hard limit), so it can never be name-matched and says
            # nothing either way. It is neither credited nor held against us here; the
            # carve still reaches many of them by relocation discovery, and objdiff
            # shows those.
            res['static_bytes'] += info.size
        if not located and info.external:
            res['unmatched_external'].append((name, info.sec, info.size))
    res['unmatched_external'].sort(key=lambda t: -t[2])
    return res


def measure(module: str, ilk: Path, report: Path, want_canon: bool) -> dict:
    # Complete, address-anchored, COFF-typed ground truth from the .ilk symbol table
    # (ilk_map) — supersedes the earlier partial regex scan, so no module is a proxy.
    gt_order = ground_truth_functions(ilk)
    gt_dem = dict(gt_order)
    gt_fns = [d for d, _ in gt_order]                    # all are functions (COFF type 0x20)
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
           'data': data_measure(module, ilk)}
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
    _print_data(res['data'])


def _print_data(d: dict) -> None:
    gt = d['ground_truth_bytes']
    ue = d['unmatched_external']
    print("  -- DATA: initialised .rdata/.data (% of real binary) --")
    print(f"     ground-truth bytes (.ilk)  : {gt:7d}")
    print(f"     located (name in .ilk)     : {d['covered_bytes']:7d}  "
          f"({_pct(d['covered_bytes'], gt)} coverage)")
    print(f"     BYTE-EXACT                 : {d['exact_bytes']:7d}  "
          f"({_pct(d['exact_bytes'], gt)} of real binary)  <==")
    print(f"     ours, absent from original : {d['stray_external_bytes']:7d}  "
          f"in {len(ue)} external symbols  <- the data worklist")
    print(f"     file-local statics (n/a)   : {d['static_bytes']:7d}  "
          f"(no .ilk record: unmatchable by name, neither credited nor charged)")
    print("  -- .bss: uninitialised (zeros both sides -- existence, not bytes) --")
    print(f"     globals found in original  : {d['bss_located']:7d} / "
          f"{d['bss_total']:<6d} ({d['bss_ground_truth_bytes']} GT bytes)")
    for name, sec, size in ue[:5]:
        print(f"       absent: {sec:6s} {size:6d}B  {name[:60]}")


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
    ap.add_argument('--data-worklist', type=Path,
                    help='write the EXTERNAL-data-with-no-.ilk-name list here (the '
                         'real data mismatches: wrong types, stray consts, ...)')
    args = ap.parse_args(argv)

    if args.ilk and len(args.modules) != 1:
        ap.error('--ilk applies to a single module')

    results = []
    agg = {'ground_truth': 0, 'covered': 0, 'byte_exact': 0, 'near90': 0,
           'mean_sum': 0.0}
    dagg: dict = defaultdict(int)
    dagg['unmatched_external'] = []
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
        for k, v in res['data'].items():
            if isinstance(v, int):
                dagg[k] += v
        dagg['unmatched_external'] += res['data']['unmatched_external']

    if len(results) > 1:
        d = agg['ground_truth']
        print(f"\n=== TOTAL (all {len(results)} modules) ===")
        print(f"  ground-truth functions        : {d:6d}")
        print(f"  emitted (name-matched)        : {agg['covered']:6d}  ({_pct(agg['covered'], d)} coverage)")
        print(f"  BYTE-EXACT (100%)             : {agg['byte_exact']:6d}  ({_pct(agg['byte_exact'], d)} of real binary)  <==")
        print(f"  >=90% fuzzy                   : {agg['near90']:6d}  ({_pct(agg['near90'], d)})")
        print(f"  mean fuzzy over all GT fns    : {agg['mean_sum'] / d:5.1f}%")
        _print_data(dagg)

    if args.out:
        args.out.write_text(json.dumps(
            {'modules': results, 'total': agg, 'data_total': dagg}, indent=2))
        print(f'\nwrote -> {args.out}')
    if args.data_worklist:
        with open(args.data_worklist, 'w') as f:
            f.write('# EXTERNAL data symbols our objects define that the shipped .ilk\n'
                    '# has no name for. The linker recorded every external symbol, so a\n'
                    '# miss here is a REAL disagreement with the original -- a wrong type,\n'
                    '# a stray const, a global the original never had -- not a tooling gap.\n'
                    '# section,bytes,decorated\n')
            for name, sec, size in dagg['unmatched_external']:
                f.write(f'{sec},{size},{name}\n')
        print(f"wrote {len(dagg['unmatched_external'])} rows -> {args.data_worklist}")
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
