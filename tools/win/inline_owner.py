#!/usr/bin/env python3
"""Decide, for each inline function duplicated across many objdiff units, the ONE
unit that should own it -- deterministically, the way the original linker did.

For the Pikmin Windows (VC6/PE) decomp. Under `/Od` every referenced inline
member is emitted as a COMDAT-select-ANY external in every TU that uses it, so a
single inline (e.g. `Stream::Stream`) shows up in dozens of objdiff units; sysCore
is ~87% redundant duplicate copies. MSVC's incremental linker keeps exactly one
copy: the one from the FIRST object in link order that emits the COMDAT. So the
faithful owner is:

    owner(F) = the emitter of F whose object is earliest in link order.

Link order is read straight out of the `.ilk`'s object-contribution table (the
linker's own record). We validate the choice against the map: the surviving
copy's address must fall in the owner's address span (bracketed by the owner's
uniquely-owned "anchor" functions) - and empirically it does (all the hot
Stream/RamStream/Vector3f inlines land in graphics.obj, which is link-order #1).

The original built 50 objects; 26 map 1:1 to our objdiff units by name, ~8 are CRT
/ compiler-support objects (chkstk, llmul, crtdll ...) that aren't our source, and
the rest are Win32/renamed (ogl* -> our dgxGraphics, ui*/wSocket/tcpStream, age).
`OBJ_ALIAS` handles the renames; unmapped objects get an infinite rank so they are
never chosen as owner unless they are the sole emitter.

CAVEAT (measured): the link-order rule concentrates shared inlines in graphics
(link #1 -- it owns ~94% of the duplicates), which is enough to DECLUTTER the GUI
deterministically. But the anchor-address validation is only ~50% consistent: the
incremental linker interleaves each object's contributions rather than laying them
out contiguously, so a kept copy's address often sits next to some other emitter's
anchor. That is partly validator noise and partly genuine -- for byte-FAITHFUL
per-unit attribution (each inline shown in the exact unit the original placed it),
Phase 3 should assign ownership from the `.ilk` object-contribution table's exact
address ranges rather than this link-order approximation. For decluttering alone,
the approximation suffices.

Output: `build/win/inline_owner_<module>.csv` (decorated,owner_unit,n_emitters) for
every function emitted by >1 unit. This drives the COMDAT-dedup build pass (Task 2
Phase 3): strip each shared inline's COMDAT from every base object except its owner
so objdiff shows it once, in the unit the original linker put it.

Usage:
    python tools/win/inline_owner.py sysCore
"""
from __future__ import annotations

import argparse
import bisect
import csv
import json
import os
import re
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

# our objdiff-unit stem -> original .ilk object stem, where they differ in name.
OBJ_ALIAS = {
    'dgxGraphics': 'oglGraphics',   # Windows graphics backend (GX name in our tree)
}


def link_order(ilk: Path) -> dict[str, int]:
    """original object stem (lowercased) -> link-order rank, from the .ilk."""
    raw = ilk.read_bytes()
    order: list[str] = []
    for m in re.finditer(rb'[\x20-\x7e]{4,}', raw):
        r = m.group().decode('latin1')
        if r.lower().endswith('.obj'):
            stem = os.path.basename(r.replace('\\', '/'))[:-4].lower()
            if stem not in order:
                order.append(stem)
    return {stem: i for i, stem in enumerate(order)}


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('module', help='sysCore (the module with the inline problem)')
    ap.add_argument('--ilk', type=Path)
    ap.add_argument('--report', type=Path, default=ROOT / 'build/win/report.json')
    ap.add_argument('--map', type=Path)
    ap.add_argument('--out', type=Path)
    args = ap.parse_args(argv)
    mod = args.module
    ilk = args.ilk or (ROOT / f'orig/GPIE01_01/files/{mod}.ilk')
    mp = args.map or (ROOT / f'config/GPIE01_01/win/{mod}_map.csv')
    out = args.out or (ROOT / f'build/win/inline_owner_{mod}.csv')

    rank = link_order(ilk)
    INF = 10 ** 9

    # emitter units per decorated name
    rep = json.loads(args.report.read_text())
    name_units: dict[str, set] = defaultdict(set)
    for u in rep['units']:
        if not u['name'].startswith(mod + '/'):
            continue
        unit = u['name'].split('/')[-1]
        for f in u.get('functions') or []:
            name_units[f['name']].add(unit)

    def unit_rank(unit: str) -> int:
        stem = OBJ_ALIAS.get(unit, unit).lower()
        return rank.get(stem, INF)

    unmapped = sorted({u for us in name_units.values() for u in us
                       if unit_rank(u) == INF})

    # owner = earliest-link-order emitter
    owner = {n: min(us, key=lambda u: (unit_rank(u), u))
             for n, us in name_units.items()}
    dup = {n: us for n, us in name_units.items() if len(us) > 1}

    # validate against map addresses: owner's anchor span should bracket addr(n)
    anchor_unit = {n: next(iter(us)) for n, us in name_units.items() if len(us) == 1}
    addr = {}
    if mp.exists():
        for row in csv.DictReader(mp.open(newline='')):
            if row['kind'] == 'function' and row.get('name_mangled'):
                addr[row['name_mangled']] = int(row['va'], 16)
    apts = sorted((addr[n], anchor_unit[n]) for n in anchor_unit if n in addr)
    aaddr = [a for a, _ in apts]

    def bracket_unit(x):
        i = bisect.bisect_left(aaddr, x)
        cands = set()
        if i > 0:
            cands.add(apts[i - 1][1])
        if i < len(apts):
            cands.add(apts[i][1])
        return cands

    agree = disagree = novalid = 0
    for n in dup:
        if n not in addr:
            novalid += 1
            continue
        if owner[n] in bracket_unit(addr[n]):
            agree += 1
        else:
            disagree += 1

    out.parent.mkdir(parents=True, exist_ok=True)
    with out.open('w', newline='') as fh:
        w = csv.writer(fh)
        w.writerow(['decorated', 'owner_unit', 'n_emitters'])
        for n in sorted(dup):
            w.writerow([n, owner[n], len(dup[n])])

    tot_entries = sum(len(us) for us in name_units.values())
    print(f'=== {mod} inline owner map ===')
    print(f'link order: {len(rank)} objects; first = '
          f'{sorted(rank, key=rank.get)[0]}')
    print(f'distinct fn names        : {len(name_units)}')
    print(f'total (unit,fn) entries  : {tot_entries}')
    print(f'duplicated (>1 unit)     : {len(dup)}  '
          f'({tot_entries - len(name_units)} redundant copies to strip)')
    print(f'address validation       : agree {agree}, disagree {disagree}, '
          f'no-addr {novalid}')
    if unmapped:
        print(f'units with no link rank ({len(unmapped)}): {unmapped}')
    top = Counter(owner[n] for n in dup)
    print('owner distribution (top):', dict(top.most_common(8)))
    print(f'wrote -> {out}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
