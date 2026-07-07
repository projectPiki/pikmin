#!/usr/bin/env python3
r"""Label virtual methods deterministically by transferring vtable slot names from
our compiled base objects onto the original binary, for the Pikmin Windows decomp.

Why this is reliable (unlike order/alignment heuristics, which the `.ilk` blob order
fails at ~0% local precision, and unlike the `.ilk` which carries NO readable
symbol->address map without the absent PDB):

  * Our VC6 base objects emit, for every class we DECLARE, its vtable COMDAT
    `??_7Class@@6B...@` whose slots are the *decorated names* of the overriding
    virtual methods, in declaration order (inherited base virtuals first) -- and
    they do so even when a method BODY is an undefined external, so this reaches
    virtuals we have not decompiled yet.
  * A vtable's slot order is fixed by the class declaration, identical on both
    sides. So if we line a base vtable up against a run of code-pointers in the
    original `.rdata`/`.data` and the slots whose address we ALREADY know agree
    (>=2 agreements, ZERO disagreements), the class is identified with certainty,
    and every remaining slot's original RVA gets the base slot's name.

The match is self-validating (a wrong alignment produces disagreements and is
rejected), so the output is high-confidence; coverage is whatever the vtables reach
(measured: ~1588 of plugPiki's 2713 unlabeled function RVAs sit in a vtable slot).

Writes `build/win/vtable_labels_<mod>.csv` (rva, decorated, demangled, via_vtable,
agreements). With `--apply`, fills `name_mangled` on the matching map function rows
(placeholder / empty only; never overwrites a real name) after backing the map up.

Usage:
    python tools/win/vtable_labels.py plugPiki                 # dry-run report
    python tools/win/vtable_labels.py plugPiki --apply         # write into the map
"""
from __future__ import annotations

import argparse
import csv
import glob
import struct
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from pe_symbols import PEFile  # noqa: E402
from pe_extract import demangled_key, map_label_key  # noqa: E402
from mapbak import backup  # noqa: E402
import pydemumble  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
PLACEHOLDER = ('FUN_', 'sub_', 'loc_', 'DAT_', 'dword_', 'thunk_FUN_', 'unk_',
               'j_', 'byte_', 'off_', 'thunk_')


# --- base-object vtables ----------------------------------------------------
def coff_vtables(raw: bytes) -> list[tuple[str, list[str]]]:
    """(vtable decorated name, [slot decorated name...]) for every `??_7` COMDAT
    in a base COFF object, slots ordered by their in-section offset."""
    if raw[:2] == b'MZ':
        return []
    nsec = struct.unpack_from('<H', raw, 2)[0]
    symptr = struct.unpack_from('<I', raw, 8)[0]
    nsym = struct.unpack_from('<I', raw, 12)[0]
    strtab = symptr + nsym * 18

    def symname(o: int) -> str:
        if struct.unpack_from('<I', raw, o)[0] == 0:
            off = struct.unpack_from('<I', raw, o + 4)[0]
            e = raw.find(b'\0', strtab + off)
            return raw[strtab + off:e].decode('latin1')
        return raw[o:o + 8].rstrip(b'\0').decode('latin1')

    syms = {}
    i = 0
    while i < nsym:
        o = symptr + i * 18
        syms[i] = (symname(o), struct.unpack_from('<h', raw, o + 12)[0])
        i += 1 + raw[o + 17]  # skip aux records

    secs = []
    for i in range(nsec):
        b = 20 + i * 40
        relptr = struct.unpack_from('<I', raw, b + 24)[0]
        nrel = struct.unpack_from('<H', raw, b + 32)[0]
        secs.append((relptr, nrel))

    out = []
    for i, (nm, sec) in syms.items():
        if not nm.startswith('??_7') or not (1 <= sec <= len(secs)):
            continue
        relptr, nrel = secs[sec - 1]
        slots = []
        for k in range(nrel):
            ro = relptr + k * 10
            va = struct.unpack_from('<I', raw, ro)[0]
            sidx = struct.unpack_from('<I', raw, ro + 4)[0]
            slots.append((va, syms.get(sidx, ('?', 0))[0]))
        slots.sort()
        out.append((nm, [s for _, s in slots]))
    return out


def load_base_vtables(mod: str) -> dict[str, list[str]]:
    vts: dict[str, list[str]] = {}
    for op in glob.glob(str(ROOT / f'build/win/obj/{mod}/*.obj')):
        raw = Path(op).read_bytes()
        try:
            for nm, slots in coff_vtables(raw):
                if len(slots) > len(vts.get(nm, [])):
                    vts[nm] = slots      # keep the most complete copy
        except Exception:
            continue
    return vts


# --- original binary vtables (runs of code pointers) ------------------------
def original_runs(pe: PEFile) -> list[list[int]]:
    """Maximal runs of consecutive dwords that point (via thunk) into `.text`,
    scanned across `.rdata`/`.data`. Each run is a list of body RVAs."""
    text = next((s for s in pe.sections if s.name == '.text'), None)
    tlo, thi = text.vaddr, text.vaddr + max(text.vsize, text.raw_size)
    runs = []
    for s in pe.sections:
        if s.name not in ('.rdata', '.data'):
            continue
        run: list[int] = []
        for k in range((s.raw_size // 4)):
            v = struct.unpack_from('<I', pe.data, s.raw_ptr + 4 * k)[0]
            rva = v - pe.image_base
            if 0 <= rva:
                body = pe.resolve_thunk(rva)
                if tlo <= body < thi:
                    run.append(body)
                    continue
            if len(run) >= 3:
                runs.append(run)
            run = []
        if len(run) >= 3:
            runs.append(run)
    return runs


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('module')
    ap.add_argument('--dll', type=Path)
    ap.add_argument('--map', type=Path)
    ap.add_argument('--apply', action='store_true', help='write into the map (backs up first)')
    ap.add_argument('--include-isolated', action='store_true',
                    help='also apply the exposed `isolated` tier (default: cross+bracket only)')
    args = ap.parse_args(argv)
    mod = args.module
    dll = args.dll or next(p for p in (ROOT / f'orig/GPIE01_01/files/{mod}.dll',
                                       ROOT / f'orig/GPIE01_01/files/plugins/{mod}.dll') if p.exists())
    mp = args.map or ROOT / f'config/GPIE01_01/win/{mod}_map.csv'

    base_vt = load_base_vtables(mod)
    pe = PEFile(dll.read_bytes())
    runs = original_runs(pe)

    # map lookups
    rows = list(csv.DictReader(mp.open(newline='')))
    fn_rows = {int(r['rva'], 16): r for r in rows if r['kind'] == 'function'}
    rva_of_name: dict[str, int] = {}
    by_qual: dict[str, int] = {}
    for r in rows:
        if r['kind'] != 'function':
            continue
        rva = int(r['rva'], 16)
        if r.get('name_mangled'):
            rva_of_name[r['name_mangled']] = rva
        k = map_label_key(r.get('name') or '')
        if k:
            by_qual.setdefault(k, rva)

    def name_rva(dec: str):
        if dec in rva_of_name:
            return rva_of_name[dec]
        k = demangled_key(dec)
        return by_qual.get(k[0]) if k else None

    def is_labeled(rva: int) -> bool:
        r = fn_rows.get(rva)
        if not r:
            return False
        return bool(r.get('name_mangled')) or (
            r.get('name') and not r['name'].startswith(PLACEHOLDER))

    # a name may itself be a known anchor (at a definite rva); used to reject a
    # transfer that would contradict it (the vtable-reordering guard, see below).
    anchor_name_rva = dict(rva_of_name)

    # original slot index: rva -> list of (run_id, pos)
    where: dict[int, list[tuple[int, int]]] = defaultdict(list)
    for ri, run in enumerate(runs):
        for pos, rva in enumerate(run):
            where[rva].append((ri, pos))

    # --- match every base vtable to an original run offset ------------------
    # A vtable's slot order is class-declaration order on BOTH sides, so the match
    # (>=2 known slots agree, ZERO disagree) identifies the class with certainty.
    # BUT a transferred (unknown) slot only inherits the right name if OUR base
    # object's slot order equals the DLL's there -- and those can differ (our
    # source's virtual order may have been tuned to the DOL; DLL vtable order
    # occasionally diverges from the DOL). A reordering among UNKNOWN slots that
    # avoids every anchor slips the match check. So we grade each proposal by how
    # exposed it is to that:
    #   cross    -- the same rva->name is produced independently by >=2 matched
    #               vtables (a reorder would have to repeat identically in both) -> immune
    #   bracket  -- agreeing anchors on BOTH sides in its vtable (a reorder is
    #               confined between them) -> low risk
    #   isolated -- one-sided / edge anchors only -> exposed; report, don't auto-apply
    # Plus a hard reject: a proposed name already anchored at a DIFFERENT rva.
    votes: dict[int, list[tuple[str, bool, str]]] = defaultdict(list)  # rva->(name,bracket,vt)
    holdout_ok = holdout_bad = matched_vt = 0

    for vtname, slots in base_vt.items():
        known = [(p, name_rva(s)) for p, s in enumerate(slots)]
        known = [(p, rv) for p, rv in known if rv is not None]
        if len(known) < 2:
            continue
        cand: dict[tuple[int, int], None] = {}
        for p, rv in known:
            for ri, pos in where.get(rv, ()):
                cand[(ri, pos - p)] = None
        best = None
        for (ri, start) in cand:
            run = runs[ri]
            if start < 0 or start + len(slots) > len(run):
                continue
            agree = disagree = 0
            for p, rv in known:
                if run[start + p] == rv:
                    agree += 1
                else:
                    disagree += 1
            if disagree == 0 and agree >= 2 and (best is None or agree > best[2]):
                best = (ri, start, agree)
        if best is None:
            continue
        matched_vt += 1
        ri, start, _ = best
        run = runs[ri]
        anchpos = [p for p, _ in known]
        amin, amax = min(anchpos), max(anchpos)
        for p, s in enumerate(slots):
            rva = run[start + p]
            kr = name_rva(s)
            if kr is not None:                       # a known slot -> holdout check
                holdout_ok += (kr == rva)
                holdout_bad += (kr != rva)
                continue
            if is_labeled(rva):
                continue
            votes[rva].append((s, amin < p < amax, vtname))

    # resolve votes -> tiered proposals
    proposals: dict[int, tuple[str, str]] = {}   # rva -> (decorated, confidence)
    name_conflict = anchor_conflict = 0
    tier_n = defaultdict(int)
    for rva, vs in votes.items():
        names = {v[0] for v in vs}
        if len(names) > 1:
            name_conflict += 1
            continue
        name = vs[0][0]
        if name in anchor_name_rva and anchor_name_rva[name] != rva:
            anchor_conflict += 1
            continue
        if len({v[2] for v in vs}) >= 2:
            conf = 'cross'
        elif any(v[1] for v in vs):
            conf = 'bracket'
        else:
            conf = 'isolated'
        proposals[rva] = (name, conf)
        tier_n[conf] += 1

    # --- report / write -----------------------------------------------------
    out_csv = ROOT / f'build/win/vtable_labels_{mod}.csv'
    with out_csv.open('w', newline='') as fh:
        w = csv.writer(fh)
        w.writerow(['rva', 'name_mangled', 'demangled', 'confidence'])
        for rva in sorted(proposals):
            dec, conf = proposals[rva]
            w.writerow([f'{rva:#x}', dec, pydemumble.demangle(dec) or '', conf])

    print(f'=== {mod} vtable labeller ===  (dll {dll.name})')
    print(f'  base-object vtables            : {len(base_vt)}')
    print(f'  original code-pointer runs     : {len(runs)}  '
          f'({sum(len(r) for r in runs)} slots)')
    print(f'  vtables matched to the binary  : {matched_vt}')
    print(f'  holdout precision (known slots): {holdout_ok}/{holdout_ok + holdout_bad}'
          + (f' = {100*holdout_ok/(holdout_ok+holdout_bad):.2f}%' if holdout_ok+holdout_bad else ''))
    print(f'  NEW labels proposed            : {len(proposals)}   '
          f'cross {tier_n["cross"]} / bracket {tier_n["bracket"]} / isolated {tier_n["isolated"]}')
    print(f'  rejected: name-conflict {name_conflict}, anchor-conflict {anchor_conflict}')
    print(f'  wrote -> {out_csv}')
    print('  NOTE: `cross` is immune to DLL/DOL vtable-reorder; `bracket` low-risk; '
          '`isolated` needs review (see --include-isolated).')

    if args.apply:
        if holdout_bad:
            print('  !! holdout has disagreements -- NOT applying; inspect first.')
            return 1
        accept = {'cross', 'bracket'} | ({'isolated'} if args.include_isolated else set())
        bak = backup(mp)
        applied = 0
        for r in rows:
            if r['kind'] != 'function':
                continue
            rva = int(r['rva'], 16)
            if rva in proposals and proposals[rva][1] in accept and not r.get('name_mangled'):
                r['name_mangled'] = proposals[rva][0]
                applied += 1
        with mp.open('w', newline='') as fh:
            w = csv.DictWriter(fh, fieldnames=rows[0].keys())
            w.writeheader()
            w.writerows(rows)
        print(f'  applied {applied} name_mangled ({sorted(accept)}) into {mp}  '
              f'(backup {bak.name})')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
