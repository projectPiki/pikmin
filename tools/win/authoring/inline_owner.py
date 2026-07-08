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
    python tools/win/authoring/inline_owner.py sysCore
"""
from __future__ import annotations

import argparse
import bisect
import csv
import json
import os
import re
import sys
from collections import Counter, defaultdict
from pathlib import Path

import _bootstrap  # noqa: E402,F401  (authoring/_bootstrap.py: sys.path + ROOT)
from ilk_layout import object_text_ranges  # noqa: E402
from pe_extract import base_defined_statics  # noqa: E402

ROOT = _bootstrap.ROOT

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

    # Internal-linkage (file-static) functions -- `?_Print@@`, `?_Error@@`,
    # `?printMatrix@@`, ... -- share a decorated name across TUs but are DISTINCT
    # functions at DISTINCT DLL addresses (the linker keeps every copy). From the
    # report alone they look identical to a duplicated inline (one name, N units),
    # so exclude them here by their COFF storage class: a select-any inline COMDAT
    # is EXTERNAL, a file-static is STATIC. Deduping a static would strip its base
    # definition and break pe_extract's per-TU static discovery (see the
    # win-decomp-inline-dedup memory / dedup_comdats.py's matching guard).
    obj_dir = ROOT / f'build/win/obj/{mod}'
    statics: set[str] = set()
    for o in sorted(obj_dir.glob('*.obj')):
        statics.update(base_defined_statics(o.read_bytes()))

    # emitter units per decorated name (from the objdiff report)
    rep = json.loads(args.report.read_text())
    name_units: dict[str, set] = defaultdict(set)
    for u in rep['units']:
        if not u['name'].startswith(mod + '/'):
            continue
        unit = u['name'].split('/')[-1]
        for f in u.get('functions') or []:
            if f['name'] in statics:
                continue  # internal-linkage static: never a dedup-able duplicate
            name_units[f['name']].add(unit)

    # objdiff unit <-> lowercased .ilk object stem (report units carry real case;
    # OBJ_ALIAS bridges the few renamed backends).
    stem_of_unit = {u: OBJ_ALIAS.get(u, u).lower()
                    for us in name_units.values() for u in us}
    unit_of_stem = {st: u for u, st in stem_of_unit.items()}

    def unit_rank(unit: str) -> int:
        return rank.get(stem_of_unit.get(unit, unit.lower()), INF)

    unmapped = sorted({u for us in name_units.values() for u in us
                       if unit_rank(u) == INF})

    # --- byte-faithful ownership from the .ilk section-contribution table -------
    # owner(F) = the object whose kept .text contribution actually contains F's
    # address (the copy the linker kept), mapped back to its objdiff unit. This
    # replaces the link-order approximation (whose anchor validation was ~50%).
    ranges = object_text_ranges(ilk.read_bytes())   # stem(lower) -> (lo, hi) RVA
    ivs = sorted((lo, hi, st) for st, (lo, hi) in ranges.items())
    istarts = [i[0] for i in ivs]

    def object_at(rva: int):
        i = bisect.bisect_right(istarts, rva) - 1
        if 0 <= i < len(ivs) and ivs[i][0] <= rva < ivs[i][1]:
            return ivs[i][2]
        return None

    rva_of: dict[str, int] = {}
    if mp.exists():
        for row in csv.DictReader(mp.open(newline='')):
            if row['kind'] == 'function' and row.get('name_mangled'):
                rva_of[row['name_mangled']] = int(row['rva'], 16)

    dup = {n: us for n, us in name_units.items() if len(us) > 1}

    owner: dict[str, str] = {}
    method: dict[str, str] = {}
    faithful = fallback = orphan = 0
    for n, us in name_units.items():
        st = object_at(rva_of[n]) if n in rva_of else None
        ow = unit_of_stem.get(st) if st is not None else None
        # The address-owner is authoritative ONLY when that unit actually emits +
        # carves n here (ow in us): the surviving copy must be one objdiff can pair.
        # If the byte-faithful owner has no matchable copy in our build (its object
        # includes the header but didn't emit/carve n -- the ~13 graphics cases), or
        # the address maps to no unit-bearing object at all, fall back to the
        # earliest real emitter so the dedup strip never leaves n with ZERO copies.
        if ow is not None and ow in us:
            owner[n], method[n] = ow, 'ilk-range'
            if len(us) > 1:
                faithful += 1
        else:
            if ow is not None and len(us) > 1:
                orphan += 1  # address-owner exists but isn't a matchable emitter
            owner[n], method[n] = min(us, key=lambda u: (unit_rank(u), u)), 'link-order'
            if len(us) > 1:
                fallback += 1

    out.parent.mkdir(parents=True, exist_ok=True)
    with out.open('w', newline='') as fh:
        w = csv.writer(fh)
        w.writerow(['decorated', 'owner_unit', 'n_emitters', 'method'])
        for n in sorted(dup):
            w.writerow([n, owner[n], len(dup[n]), method[n]])

    tot_entries = sum(len(us) for us in name_units.values())
    print(f'=== {mod} inline owner map (byte-faithful, .ilk .text ranges) ===')
    print(f'link order: {len(rank)} objects; .ilk .text ranges: {len(ranges)} objects')
    print(f'distinct fn names        : {len(name_units)}')
    print(f'internal-linkage statics : {len(statics)} names excluded (never deduped)')
    print(f'total (unit,fn) entries  : {tot_entries}')
    print(f'duplicated (>1 unit)     : {len(dup)}  '
          f'({tot_entries - len(name_units)} redundant copies to strip)')
    print(f'dup ownership            : ilk-range {faithful} '
          f'(byte-faithful, owner is a matchable emitter), '
          f'link-order fallback {fallback} '
          f'({orphan} of them address-owned by a non-emitting object)')
    if unmapped:
        print(f'units with no link rank ({len(unmapped)}): {unmapped}')
    top = Counter(owner[n] for n in dup)
    print('owner distribution (top):', dict(top.most_common(8)))
    print(f'wrote -> {out}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
