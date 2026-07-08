#!/usr/bin/env python3
r"""Generate a TU-by-TU worklist of unlabelled functions for MANUAL name
assignment, and ingest the filled-in names back into the map. For the Pikmin
Windows (VC6/PE) decomp.

Automatic labelling reaches vtable virtuals ([[vtable_labels.py]]) and callees of
compiled functions ([[backfill_map_names.py]]); what is left -- strong (non-virtual)
bodies our source does not emit -- has no reliable programmatic labeller without the
absent PDB (the `.ilk` carries no symbol->address map; see win-decomp-vtable-labels).
So those are assigned by hand, and this tool makes that tractable by giving each
unlabelled slot the context a human needs to recognise it:

  * its byte-faithful TU (the original object it lives in) and address/size,
  * inline-vs-strong kind (COMDAT selection, from ilk_functions),
  * the nearest NAMED functions before/after it in that TU (orientation),
  * its direct callees that are already named (a `call rel32` scan of the original
    bytes -- a strong fingerprint of what the function does).

The candidate NAME pool for a TU is the .ilk's un-emitted names for it: see
`build/win/reconcile_<mod>/B_missing_by_tu.txt` (from ilk_reconcile.py) alongside.

Workflow:
  1. python tools/win/authoring/review_labels.py plugPiki --emit         # writes review CSV
  2. edit build/win/review/<mod>.csv, filling the `assign` column with either a
     decorated name (`?foo@Bar@@...`) or a demangled label (`Bar::foo`).
  3. python tools/win/authoring/review_labels.py plugPiki --ingest       # dry-run: preview
     python tools/win/authoring/review_labels.py plugPiki --ingest --apply   # write to map

Only rows whose `assign` is non-empty are touched; the map is backed up first.
"""
from __future__ import annotations

import argparse
import csv
import struct
import sys
from pathlib import Path

import _bootstrap  # noqa: E402,F401  (authoring/_bootstrap.py: sys.path + ROOT)
from mapbak import backup  # noqa: E402
from ilk_functions import (find_ilk, inventory, load_map, tu_at, tu_index,  # noqa: E402
                           load_report, emitted_status, label_state)
import pydemumble  # noqa: E402

ROOT = _bootstrap.ROOT


def find_dll(mod: str) -> Path:
    for c in (ROOT / f'orig/GPIE01_01/files/{mod}.dll',
              ROOT / f'orig/GPIE01_01/files/plugins/{mod}.dll'):
        if c.exists():
            return c
    raise SystemExit(f'no dll for {mod}')


def call_targets(dll: bytes, pe_off, base, rva, size, fnset) -> list[int]:
    """RVAs of `call rel32` (E8) targets inside [rva, rva+size) that land on a
    known function start -- a cheap, false-positive-resistant callee scan."""
    off = pe_off(rva)
    if off is None:
        return []
    out = []
    k = 0
    while k < size - 4:
        if dll[off + k] == 0xE8:
            rel = struct.unpack_from('<i', dll, off + k + 1)[0]
            t = rva + k + 5 + rel
            if t in fnset:
                out.append(t)
        k += 1
    return out


def emit(mod: str, report: Path) -> None:
    ilk = find_ilk(mod)
    raw = ilk.read_bytes()
    inv = inventory(raw)
    ivs, starts = tu_index(raw)
    map_by_rva, base = load_map(ROOT / f'config/GPIE01_01/win/{mod}_map.csv')
    by_dec, by_qual = load_report(report, mod)

    # PE offset resolver + function-start set for the callee scan
    dllp = find_dll(mod)
    dll = dllp.read_bytes()
    pe = struct.unpack_from('<I', dll, 0x3c)[0]
    nsec = struct.unpack_from('<H', dll, pe + 6)[0]
    opt = pe + 0x18
    secs = []
    so = opt + struct.unpack_from('<H', dll, pe + 0x14)[0]
    for i in range(nsec):
        b = so + i * 0x28
        va, rsz, rp = (struct.unpack_from('<I', dll, b + 12)[0],
                       struct.unpack_from('<I', dll, b + 16)[0],
                       struct.unpack_from('<I', dll, b + 20)[0])
        secs.append((va, rsz, rp))

    def pe_off(r):
        for va, rsz, rp in secs:
            if va <= r < va + rsz:
                return rp + (r - va)
        return None

    fnset = set(inv)

    # named function per rva (for neighbour + callee naming)
    def label_of(r):
        m = map_by_rva.get(r)
        if not m:
            return ''
        return m['name_mangled'] or (m['name'] if label_state(m) == 'named' else '')

    ordered = sorted(inv)
    pos = {rva: i for i, rva in enumerate(ordered)}
    tu_cache = {rva: (tu_at(rva, ivs, starts) or '?') for rva in ordered}
    lab_cache = {rva: label_of(rva) for rva in ordered}
    rows = []
    for rva in ordered:
        m = map_by_rva.get(rva)
        status, _ = emitted_status(m, by_dec, by_qual)
        lab = label_state(m)
        # target: not emitted, not already named, and a real function (not a
        # thunk / not the unmapped '?' bucket -- neither is a manual-label target)
        if status != 'unassigned' or lab == 'named' or inv[rva]['kind'] == 'thunk':
            continue
        tu = tu_cache[rva]
        if tu == '?':
            continue
        # nearest named neighbours in the same TU
        prev = nxt = ''
        i = pos[rva]
        j = i - 1
        while j >= 0 and tu_cache[ordered[j]] == tu:
            if lab_cache[ordered[j]]:
                prev = lab_cache[ordered[j]]
                break
            j -= 1
        j = i + 1
        while j < len(ordered) and tu_cache[ordered[j]] == tu:
            if lab_cache[ordered[j]]:
                nxt = lab_cache[ordered[j]]
                break
            j += 1
        calls = call_targets(dll, pe_off, base, rva, inv[rva]['size'], fnset)
        callnames = [lab_cache[t] for t in calls if lab_cache.get(t)]
        # demangle for readability
        pcs = pydemumble.demangle(prev) or prev
        ncs = pydemumble.demangle(nxt) or nxt
        cs = '; '.join(dict.fromkeys(pydemumble.demangle(c) or c for c in callnames))
        rows.append({
            'tu': tu, 'va': f'{rva + base:#x}', 'size': inv[rva]['size'],
            'kind': inv[rva]['kind'], 'current': (m['name'] if m else ''),
            'prev_named': pcs, 'next_named': ncs, 'calls': cs, 'assign': '',
        })

    out = ROOT / f'build/win/review/{mod}.csv'
    out.parent.mkdir(parents=True, exist_ok=True)
    # order by TU (most-unlabelled first) then address
    from collections import Counter
    tucount = Counter(r['tu'] for r in rows)
    rows.sort(key=lambda r: (-tucount[r['tu']], r['tu'], int(r['va'], 16)))
    with out.open('w', newline='') as fh:
        w = csv.DictWriter(fh, fieldnames=['tu', 'va', 'size', 'kind', 'current',
                           'prev_named', 'next_named', 'calls', 'assign'])
        w.writeheader()
        w.writerows(rows)
    print(f'=== {mod}: {len(rows)} unlabelled functions across {len(tucount)} TUs ===')
    print(f'   top TUs: {dict(tucount.most_common(8))}')
    print(f'   wrote -> {out}')
    print(f'   candidate .ilk names per TU: build/win/reconcile_{mod}/B_missing_by_tu.txt')


def ingest(mod: str, apply: bool) -> None:
    review = ROOT / f'build/win/review/{mod}.csv'
    if not review.exists():
        raise SystemExit(f'no review file {review}; run --emit first')
    ilk = find_ilk(mod)
    # .ilk decorated<->demangled, so a demangled `assign` can be re-decorated
    from ilk_reconcile import extract_ilk
    dem2dec = {}
    for dec, dem in extract_ilk(ilk):
        dem2dec.setdefault(dem, dec)
        # also key by the bare "Class::method(args)" without the leading access/ret
        dem2dec.setdefault(dem.split('__thiscall ')[-1].split('__cdecl ')[-1], dec)

    mp = ROOT / f'config/GPIE01_01/win/{mod}_map.csv'
    rows = list(csv.DictReader(mp.open(newline='')))
    by_va = {int(r['va'], 16): r for r in rows if r['kind'] == 'function'}

    todo = []
    for r in csv.DictReader(review.open(newline='')):
        a = (r.get('assign') or '').strip()
        if not a:
            continue
        va = int(r['va'], 16)
        row = by_va.get(va)
        if not row:
            print(f'   !! va {r["va"]} not a map function row -- skipped')
            continue
        if a.startswith('?'):                       # decorated given directly
            dec, name = a, pydemumble.demangle(a) or ''
        elif a in dem2dec:                          # demangled -> re-decorate via .ilk
            dec, name = dem2dec[a], a
        else:                                       # plain label, no decoration known
            dec, name = '', a
        todo.append((va, row, dec, name))

    print(f'=== {mod} ingest: {len(todo)} assignments ===')
    for va, row, dec, name in todo[:40]:
        print(f'   {va:#x}  {dec or "(label)"}  {name or row.get("name")}')
    if len(todo) > 40:
        print(f'   ... (+{len(todo) - 40} more)')

    if apply and todo:
        bak = backup(mp)
        for va, row, dec, name in todo:
            if dec:
                row['name_mangled'] = dec
            if name:
                row['name'] = name
        with mp.open('w', newline='') as fh:
            w = csv.DictWriter(fh, fieldnames=rows[0].keys())
            w.writeheader()
            w.writerows(rows)
        print(f'   applied {len(todo)} assignments to {mp}  (backup {bak.name})')
    elif todo:
        print('   (dry-run; pass --apply to write)')


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('module')
    ap.add_argument('--report', type=Path, default=ROOT / 'build/win/report.json')
    ap.add_argument('--emit', action='store_true', help='write the review worklist CSV')
    ap.add_argument('--ingest', action='store_true', help='read assignments back')
    ap.add_argument('--apply', action='store_true', help='(with --ingest) write to the map')
    args = ap.parse_args(argv)
    if args.emit:
        emit(args.module, args.report)
    if args.ingest:
        ingest(args.module, args.apply)
    if not (args.emit or args.ingest):
        ap.error('pass --emit or --ingest')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
