#!/usr/bin/env python3
"""Reconcile a module's `.ilk` ground-truth symbol names against what our decomp
actually emits, and produce a per-bucket laundry list of what to fix or pair up.

For the Pikmin Windows (VC6/PE) decomp. The shipped incremental-link file
(`<module>.ilk`) is the ground truth for symbol *names*: it carries every
decorated MSVC name the original linker knew, and it preserves the objects'
contribution order, so the names cluster by translation unit. This tool extracts
that list (validating each candidate by demangling it), then diffs it against:

  * what our source *emits*   -- the base function symbols in the objdiff
                                 `report.json` (i.e. every function VC6 compiled);
  * what the map *holds*      -- `config/GPIE01_01/win/<module>_map.csv`.

It writes four files into `build/win/reconcile_<module>/`:

  A_wrong_names.txt     names our source emits that the .ilk never had -- typos,
                        signature drift, and (dominantly) struct-vs-class key
                        mismatches (MSVC mangles `class` as V, `struct` as U).
  A_classkey_types.txt  the distinct types we still declare `struct` but the .ilk
                        mangles `class`, with the number of our functions each
                        affects. This is the actionable "flip these" list.
  B_missing_by_tu.txt   .ilk functions our source does NOT emit (unimplemented or
                        mis-named), bucketed by probable translation unit. TU is
                        inferred, in order of confidence, from: a source path
                        embedded in a file-local static's symbol (certain); the
                        owning class's home TU agreeing with the .ilk-order
                        neighbours; .ilk-order neighbour consensus alone; or the
                        class-home vote alone. A small "hard" residue (whole
                        un-started TUs, e.g. an entire state-machine block) is left
                        for a human.
  C_map_placeholders.txt map function rows still sitting on FUN_/sub_/DAT_ labels.

Ground truth caveat: some modules' `.ilk` store the name table differently and
only a fraction of names are recoverable as plain strings (sysCore yields ~1660
vs plugPiki's ~11800). Those modules are export-covered elsewhere, so the partial
run is low-impact -- but treat a surprisingly low ground-truth count with
suspicion.

Usage:
    python tools/win/authoring/ilk_reconcile.py plugPiki
    python tools/win/authoring/ilk_reconcile.py sysCore --report build/win/report.json

Needs pydemumble (a reccmp dependency) for name validation/demangling.
"""
from __future__ import annotations

import argparse
import csv
import json
import re
from collections import Counter, defaultdict
from pathlib import Path

import pydemumble

import _bootstrap  # noqa: E402,F401  (authoring/_bootstrap.py: sys.path + ROOT)
ROOT = _bootstrap.ROOT

# embedded source path in a file-local static:  ?%c:\...\foo.cpp12345::
PATHRE = re.compile(r'[\\/]([A-Za-z0-9_]+)\.cpp\d*::')

_dm: dict[str, str | None] = {}


def demangle(dec: str) -> str | None:
    if dec in _dm:
        return _dm[dec]
    try:
        d = pydemumble.demangle(dec)
        d = d if d and d != dec else None
    except Exception:
        d = None
    _dm[dec] = d
    return d


def canon(dem: str | None) -> str | None:
    """Demangled form with the class-key words + whitespace stripped, so that
    names differing only in struct/union/enum-vs-class collapse together."""
    if dem is None:
        return None
    s = re.sub(r'\b(class|struct|union|enum)\b', '', dem)
    return re.sub(r'\s+', '', s)


def is_synth(dec: str) -> bool:
    """Compiler-generated names we never hand-author (not "wrong")."""
    return dec.startswith(('??_G', '??_E', '??_H', '??_I', '??_R', '??_C'))


def owner_class(dem: str | None) -> str | None:
    """The owning class of a member function -- or, if the owner is a template,
    the template's first type argument (so State<Foo> attributes to Foo)."""
    if dem is None:
        return None
    m = re.search(r'(?:__thiscall|__cdecl|__stdcall|__fastcall)\s+.*?([\w<> ,:*&]+?)::', dem)
    if not m:
        return None
    top = re.split(r'::', m.group(1).strip())[0]
    tm = re.search(r'<\s*(?:class |struct )?([A-Za-z_]\w*)', top)
    return (tm.group(1) if tm else re.sub(r'<.*', '', top)).strip()


def extract_ilk(path: Path) -> list[tuple[str, str]]:
    """Validated (decorated, demangled) names from a .ilk, in file order,
    deduplicated. A candidate must start with '?', contain '@@', and demangle to
    something that looks like a real symbol."""
    raw = path.read_bytes()
    out: list[tuple[str, str]] = []
    seen: set[str] = set()
    for m in re.finditer(rb'[\x20-\x7e]{4,}', raw):
        r = m.group().decode('latin1')
        if not (r.startswith('?') and '@@' in r) or r in seen:
            continue
        dem = demangle(r)
        if dem and re.search(r'[A-Za-z]{3}', dem) and ('::' in dem or ' ' in dem or '`' in dem):
            seen.add(r)
            out.append((r, dem))
    return out


def load_have(report: Path, module: str):
    """From the objdiff report: decorated name -> {best fuzzy %, units emitting it}."""
    rep = json.loads(report.read_text())
    have: dict[str, dict] = {}
    units_present = []
    for u in rep['units']:
        if not u['name'].startswith(module + '/'):
            continue
        unit = u['name'][len(module) + 1:]
        units_present.append(unit)
        for f in u.get('functions') or []:
            d = have.setdefault(f['name'], {
                'dem': (f.get('metadata') or {}).get('demangled_name'),
                'best': 0.0, 'units': Counter()})
            d['best'] = max(d['best'], f.get('fuzzy_match_percent', 0.0))
            d['units'][unit] += 1
    return have, units_present


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('module', help='module stem, e.g. plugPiki or sysCore')
    ap.add_argument('--ilk', type=Path, help='override .ilk path')
    ap.add_argument('--map', type=Path, help='override <module>_map.csv path')
    ap.add_argument('--report', type=Path, default=ROOT / 'build/win/report.json',
                    help='objdiff report.json (what our source emits)')
    ap.add_argument('--out', type=Path, help='output dir (default build/win/reconcile_<module>)')
    args = ap.parse_args(argv)

    mod = args.module
    ilk = args.ilk or _find_ilk(mod)
    mp = args.map or ROOT / f'config/GPIE01_01/win/{mod}_map.csv'
    out = args.out or ROOT / f'build/win/reconcile_{mod}'
    out.mkdir(parents=True, exist_ok=True)

    gt_order = extract_ilk(ilk)
    gt_idx = {d: i for i, (d, _) in enumerate(gt_order)}
    gt_dem = dict(gt_order)
    gt_fns = {d for d, m in gt_order if '(' in m}

    have, _ = load_have(args.report, mod)
    have_fns = set(have)

    cls_units: dict[str, Counter] = defaultdict(Counter)
    for dec, info in have.items():
        c = owner_class(info['dem'] or demangle(dec))
        if c:
            for un, n in info['units'].items():
                cls_units[c][un] += n
    # unit stems for path-encoded statics
    stem_unit = {}
    for un in {u for info in have.values() for u in info['units']}:
        stem_unit[un.split('/')[-1].lower()] = un

    idx_unit = {gt_idx[d]: have[d]['units'].most_common(1)[0][0]
                for d in gt_fns & have_fns}

    def neighbour_tu(i, win=30):
        votes: Counter = Counter()
        for off in range(1, win + 1):
            for j in (i - off, i + off):
                if j in idx_unit:
                    votes[idx_unit[j]] += (win - off + 1)
        if not votes:
            return None, 0.0
        tu, w = votes.most_common(1)[0]
        return tu, w / sum(votes.values())

    # bucket A: names we emit that the .ilk lacks
    canon_gt: dict[str, list[str]] = defaultdict(list)
    for d in gt_fns:
        canon_gt[canon(gt_dem[d])].append(d)
    wrong = []
    classkey_types: Counter = Counter()
    synth = 0
    for dec in sorted(have_fns - gt_fns):
        if is_synth(dec):
            synth += 1
            continue
        dem = have[dec]['dem'] or demangle(dec) or dec
        twin = None
        for g in canon_gt.get(canon(dem), []):
            if g != dec:
                twin = g
                break
        reason = 'class-key(struct->class)' if twin else 'drift/folded'
        if twin:
            for a, b in zip(re.finditer(r'\b(class|struct) ([\w:]+)', dem),
                            re.finditer(r'\b(class|struct) ([\w:]+)', gt_dem[twin])):
                if a.group(1) == 'struct' and b.group(1) == 'class' and a.group(2) == b.group(2):
                    classkey_types[b.group(2)] += 1
        wrong.append((have[dec]['best'], dec, dem, reason, twin))

    # bucket B: .ilk functions we don't emit
    missing = []
    for dec in gt_fns - have_fns:
        dem = gt_dem[dec]
        i = gt_idx[dec]
        tu = conf = None
        pm = PATHRE.search(dem)
        if pm and pm.group(1).lower() in stem_unit:
            tu, conf = stem_unit[pm.group(1).lower()], 'path'
        if tu is None:
            c = owner_class(dem)
            ntu, nfrac = neighbour_tu(i)
            ctu = cls_units[c].most_common(1)[0][0] if c and cls_units.get(c) else None
            if ctu and ntu and ctu == ntu:
                tu, conf = ctu, 'high'
            elif ntu and nfrac >= 0.6:
                tu, conf = ntu, 'ilk-order'
            elif ctu:
                tu, conf = ctu, 'class-vote'
            elif ntu:
                tu, conf = ntu, 'ilk-order-weak'
            else:
                tu, conf = '???', 'hard'
        missing.append((i, dec, dem, tu, conf))
    missing.sort()

    # bucket C: map placeholders
    ph = re.compile(r'^(FUN_|sub_|loc_|DAT_|dword_|thunk_FUN_|unk_|j_|byte_|off_)')
    map_ph = []
    if mp.exists():
        for row in csv.DictReader(mp.open(newline='')):
            if row['kind'] != 'function':
                continue
            nmg = (row.get('name_mangled') or '').strip()
            nm = (row.get('name') or '').strip()
            if not nmg and (not nm or ph.match(nm)):
                map_ph.append((row['va'], row['size'], nm))

    def dump(name, lines, hdr):
        (out / name).write_text(hdr + '\n' + '\n'.join(lines) + '\n', encoding='utf-8')

    byreason = Counter(w[3] for w in wrong)
    print(f'=== {mod} reconciliation ===')
    print(f'.ilk ground truth : {len(gt_order)} symbols ({len(gt_fns)} functions)  <- {ilk}')
    print(f'our source emits   : {len(have_fns)} distinct fn symbols; matched-by-name {len(gt_fns & have_fns)}')
    print(f'A) wrong-name      : {len(wrong)} (+{synth} synth ignored)  {dict(byreason)}')
    print(f'   class-key types : {len(classkey_types)} distinct types to flip struct->class')
    print(f'B) missing         : {len(missing)}  {dict(Counter(m[4] for m in missing))}')
    print(f'C) map placeholders: {len(map_ph)}')

    dump('A_wrong_names.txt',
         [f'{b:5.1f}%  {d}\n         our : {dm}' +
          (f'\n         ilk : {t} = {gt_dem[t]}' if t else
           '  [no .ilk counterpart -> folded/inlined or genuine drift]')
          for b, d, dm, r, t in sorted(wrong, key=lambda x: (x[3], -x[0]))],
         f'# A) names our source emits that {mod}.ilk lacks. Sorted by reason then match%.')
    dump('A_classkey_types.txt',
         [f'{n:5d}  {t}' for t, n in classkey_types.most_common()],
         f'# A) types we still declare `struct` but {mod}.ilk mangles `class` (V). '
         f'#fns affected. FLIP THESE.')
    bytu: dict[str, list] = defaultdict(list)
    for i, d, dm, tu, conf in missing:
        bytu[tu].append((i, dm, conf))
    lines = []
    for tu in sorted(bytu, key=lambda t: (t == '???', -len(bytu[t]))):
        lines.append(f'\n## {tu}   ({len(bytu[tu])})')
        for i, dm, conf in sorted(bytu[tu]):
            lines.append(f'  [ilk#{i:5d} {conf:14s}] {dm}')
    dump('B_missing_by_tu.txt', lines,
         f'# B) {mod}.ilk functions our source does NOT emit, by probable TU.\n'
         f'# confidence: path=source path in symbol (certain) | high=class-vote==ilk-order '
         f'| ilk-order=.ilk neighbours agree | class-vote | *-weak | hard')
    dump('C_map_placeholders.txt',
         [f'{v}  size={s:>5}  {n}' for v, s, n in map_ph],
         f'# C) {mod}_map.csv function rows still on placeholder labels')
    print(f'\nwrote -> {out}/')
    return 0


def _find_ilk(mod: str) -> Path:
    for cand in (ROOT / f'orig/GPIE01_01/files/{mod}.ilk',
                 ROOT / f'orig/GPIE01_01/files/plugins/{mod}.ilk'):
        if cand.exists():
            return cand
    raise SystemExit(f'no .ilk found for {mod}')


if __name__ == '__main__':
    raise SystemExit(main())
