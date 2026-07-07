#!/usr/bin/env python3
r"""The per-function inventory of a shipped module, spined on the `.ilk`'s own
section-contribution table, for the Pikmin Windows (VC6/PE) decomp.

Where `ilk_reconcile.py` works from the `.ilk` *name* table (partial for sysCore --
only ~1461 names extract as plain strings) and infers each missing function's TU from
name/neighbour heuristics, this tool works from the `.ilk` *address* table, which is
complete and byte-faithful:

  * inventory   -- every kept `.text` contribution is one real function (they tile
                   `.text` exactly once).  sysCore 1815, plugPiki 10420.
  * TU          -- byte-faithful, from `ilk_layout.object_text_ranges()` (the object
                   whose kept `.text` span actually contains the function's RVA).
  * inline/strong -- from the COMDAT **selection** field at record+0x20:
                   2 = IMAGE_COMDAT_SELECT_ANY        -> an inline (a header-defined
                       body every referencing TU emits; the linker folds the copies),
                   1 = IMAGE_COMDAT_SELECT_NODUPLICATES -> a strong /Gy function with
                       exactly one definition,
                   0 = neither (a handful of specials).
                   Validated against inline_owner.py's independent duplicated-across-
                   units set: those land 2 (SELECT_ANY) ~all of the time.
  * name/status -- joined to `config/GPIE01_01/win/<module>_map.csv` by RVA for the
                   disassembler label, and to the objdiff `report.json` for whether
                   our source already emits/matches it (reusing pe_extract's decorated
                   <-> demangled bridge, so plugPiki's label-only map still pairs).

The point of the tool is the **unassigned** list: functions the shipped binary has
that our decomp does not yet emit, split inline-vs-strong and grouped by their true
TU -- the concrete "what to label/write next, and where" worklist that the two goals
this session asked for.

Writes `build/win/ilk_functions_<module>.csv` (one row per function) and
`build/win/ilk_functions_<module>.txt` (the unassigned worklist, by TU).

Usage:
    python tools/win/ilk_functions.py sysCore plugPiki
    python tools/win/ilk_functions.py plugPiki --csv --txt
"""
from __future__ import annotations

import argparse
import csv
import json
import struct
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from ilk_layout import _u32, object_text_ranges, text_descriptor  # noqa: E402
from pe_extract import demangled_key, map_label_key  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]

PLACEHOLDER = ('FUN_', 'sub_', 'loc_', 'DAT_', 'dword_', 'thunk_FUN_', 'unk_',
               'j_', 'byte_', 'off_', 'thunk_')


def find_ilk(mod: str) -> Path:
    for c in (ROOT / f'orig/GPIE01_01/files/{mod}.ilk',
              ROOT / f'orig/GPIE01_01/files/plugins/{mod}.ilk'):
        if c.exists():
            return c
    raise SystemExit(f'no .ilk found for {mod}')


def inventory(raw: bytes) -> dict[int, dict]:
    """distinct start-RVA -> {'size', 'kind'} for every kept .text contribution.

    kind = 'inline' if any record at that RVA is SELECT_ANY(2), else 'strong'
    (SELECT_NODUPLICATES=1) or 'other' (selection 0)."""
    tag, lo, hi = text_descriptor(raw)
    pat = struct.pack('<I', tag)
    sizes: dict[int, int] = {}
    sels: dict[int, set] = defaultdict(set)
    h = raw.find(pat)
    while h >= 0:
        if h >= 0x40 and h + 0x24 <= len(raw):
            chars = _u32(raw, h - 0x18)
            start = _u32(raw, h - 0x1c)
            size = _u32(raw, h - 0x14)
            sel = _u32(raw, h + 0x20)
            if (chars & 0x20) and not (chars & 0x800) and lo <= start < hi \
                    and 0 < size < 0x20000:
                sizes[start] = size
                sels[start].add(sel)
        h = raw.find(pat, h + 1)
    inv: dict[int, dict] = {}
    for rva, size in sizes.items():
        s = sels[rva]
        kind = 'inline' if 2 in s else ('strong' if 1 in s else 'other')
        inv[rva] = {'size': size, 'kind': kind}
    return inv


def tu_index(raw: bytes):
    """(sorted [(lo,hi,stem)], [lo...]) for bisect lookup of a function's TU."""
    ranges = object_text_ranges(raw)
    ivs = sorted((lo, hi, st) for st, (lo, hi) in ranges.items())
    return ivs, [i[0] for i in ivs]


def tu_at(rva: int, ivs, starts) -> str | None:
    import bisect
    i = bisect.bisect_right(starts, rva) - 1
    if 0 <= i < len(ivs) and ivs[i][0] <= rva < ivs[i][1]:
        return ivs[i][2]
    return None


def load_map(mp: Path):
    """rva -> {'name_mangled','name','va'} for function rows; plus image base."""
    by_rva: dict[int, dict] = {}
    base = None
    if not mp.exists():
        return by_rva, 0x10000000
    for r in csv.DictReader(mp.open(newline='')):
        if r['kind'] != 'function':
            continue
        rva = int(r['rva'], 16)
        by_rva[rva] = {'name_mangled': (r.get('name_mangled') or '').strip(),
                       'name': (r.get('name') or '').strip(),
                       'va': r.get('va', '')}
        if base is None and r.get('va'):
            base = int(r['va'], 16) - rva
    return by_rva, (base or 0x10000000)


def load_report(report: Path, module: str):
    """Emitted-function lookup: decorated-name -> best fuzzy, and
    qualified-name (arg-less) -> best fuzzy (the bridge for label-only maps,
    matching a Ghidra-style `Class::method` label; overloads collapse to their
    best, which is the most we can do since the label carries no arg list)."""
    rep = json.loads(report.read_text())
    by_dec: dict[str, float] = {}
    by_qual: dict[str, float] = {}
    for u in rep['units']:
        if not u['name'].startswith(module + '/'):
            continue
        for f in u.get('functions') or []:
            dec = f['name']
            fz = f.get('fuzzy_match_percent', 0.0)
            by_dec[dec] = max(by_dec.get(dec, 0.0), fz)
            k = demangled_key(dec)          # (qualified 'Class::method', argc)
            if k:
                by_qual[k[0]] = max(by_qual.get(k[0], 0.0), fz)
    return by_dec, by_qual


def emitted_status(row, by_dec, by_qual):
    """-> (status, fuzzy). status in matched/partial/unassigned."""
    fz = None
    if row and row['name_mangled'] and row['name_mangled'] in by_dec:
        fz = by_dec[row['name_mangled']]
    elif row and row['name']:
        k = map_label_key(row['name'])      # arg-less qualified string
        if k and k in by_qual:
            fz = by_qual[k]
    if fz is None:
        return 'unassigned', ''
    if fz >= 100.0:
        return 'matched', f'{fz:.1f}'
    return 'partial', f'{fz:.1f}'


def label_state(row) -> str:
    if not row:
        return 'no-map-row'
    if row['name_mangled']:
        return 'named'
    nm = row['name']
    if not nm or nm.startswith(PLACEHOLDER):
        return 'placeholder'
    return 'named'


def run(mod: str, report: Path, want_csv: bool, want_txt: bool) -> dict:
    ilk = find_ilk(mod)
    raw = ilk.read_bytes()
    inv = inventory(raw)
    ivs, starts = tu_index(raw)
    map_by_rva, base = load_map(ROOT / f'config/GPIE01_01/win/{mod}_map.csv')
    by_dec, by_qual = load_report(report, mod)

    rows = []
    for rva in sorted(inv):
        m = map_by_rva.get(rva)
        tu = tu_at(rva, ivs, starts) or '?'
        status, fz = emitted_status(m, by_dec, by_qual)
        # a <=6-byte body with no disassembler label is an incremental-link
        # `jmp rel32` thunk (sysCore packs them in a tail run, plugPiki scatters
        # them), not a real function to decompile -- bucket it out of strong/inline.
        label = label_state(m)
        kind = 'thunk' if inv[rva]['size'] <= 6 and label == 'no-map-row' \
            else inv[rva]['kind']
        rows.append({
            'rva': f'{rva:#x}', 'va': f'{rva + base:#x}',
            'size': inv[rva]['size'], 'tu': tu, 'kind': kind,
            'status': status, 'fuzzy': fz, 'label': label,
            'name_mangled': m['name_mangled'] if m else '',
            'name': m['name'] if m else '',
        })

    # -- summary ------------------------------------------------------------
    n = len(rows)
    by_status = Counter(r['status'] for r in rows)
    by_kind = Counter(r['kind'] for r in rows)
    unassigned = [r for r in rows if r['status'] == 'unassigned']
    ua_kind = Counter(r['kind'] for r in unassigned)
    ua_label = Counter(r['label'] for r in unassigned)
    # unassigned strong functions are the real decomp work; cross split by TU
    real = n - by_kind['thunk']
    print(f'\n=== {mod} function inventory (.ilk address table) ===  ({ilk.name})')
    print(f'  kept .text contributions             : {n}  '
          f"({by_kind['thunk']} incremental-link thunks -> {real} real functions)")
    print(f'  real: inline / strong / other        : '
          f"{by_kind['inline']} / {by_kind['strong']} / {by_kind['other']}")
    print(f'  matched (100%) / partial / UNASSIGNED : '
          f"{by_status['matched']} / {by_status['partial']} / {by_status['unassigned']}")
    print(f'  UNASSIGNED (excl. thunks)  strong/inline/other : '
          f"{ua_kind['strong']} / {ua_kind['inline']} / {ua_kind['other']}  "
          f"(+{ua_kind['thunk']} thunks)")
    print(f'  UNASSIGNED label  named/placeholder/no-row : '
          f"{ua_label['named']} / {ua_label['placeholder']} / {ua_label['no-map-row']}")

    if want_csv:
        out = ROOT / f'build/win/ilk_functions_{mod}.csv'
        with out.open('w', newline='') as fh:
            w = csv.DictWriter(fh, fieldnames=['rva', 'va', 'size', 'tu', 'kind',
                               'status', 'fuzzy', 'label', 'name_mangled', 'name'])
            w.writeheader()
            w.writerows(rows)
        print(f'  wrote -> {out}')

    if want_txt:
        out = ROOT / f'build/win/ilk_functions_{mod}.txt'
        bytu_strong: dict[str, list] = defaultdict(list)
        bytu_inline: dict[str, list] = defaultdict(list)
        for r in unassigned:
            if r['kind'] == 'strong':
                bytu_strong[r['tu']].append(r)
            elif r['kind'] == 'inline':
                bytu_inline[r['tu']].append(r)
            # 'thunk'/'other' are not real decomp work -> omitted from the worklist
        lines = [
            f'# {mod}: UNASSIGNED functions (in the shipped .ilk, not emitted by our'
            f' source), by byte-faithful TU.',
            f'# {len(unassigned)} unassigned of {n}  '
            f"(strong {ua_kind['strong']}, inline {ua_kind['inline']}, "
            f"other {ua_kind['other']}, thunk {ua_kind['thunk']}).",
            '# STRONG = a real out-of-line body to decompile.  INLINE = a header body'
            ' that appears once its class/header is written.',
            '# Each line:  va  size  kind  [label]  name',
        ]
        lines.append('\n########## STRONG (real decomp work) ##########')
        for tu in sorted(bytu_strong, key=lambda t: -len(bytu_strong[t])):
            lines.append(f'\n## {tu}   ({len(bytu_strong[tu])} strong)')
            for r in sorted(bytu_strong[tu], key=lambda r: int(r['va'], 16)):
                nm = r['name'] or '(no map label)'
                lines.append(f"  {r['va']}  {r['size']:>5}B  {r['label']:11s}  {nm}")
        lines.append('\n\n########## INLINE (label via headers/class decls) ##########')
        for tu in sorted(bytu_inline, key=lambda t: -len(bytu_inline[t])):
            lines.append(f'\n## {tu}   ({len(bytu_inline[tu])} inline)')
            for r in sorted(bytu_inline[tu], key=lambda r: int(r['va'], 16)):
                nm = r['name'] or '(no map label)'
                lines.append(f"  {r['va']}  {r['size']:>5}B  {r['label']:11s}  {nm}")
        out.write_text('\n'.join(lines) + '\n', encoding='utf-8')
        print(f'  wrote -> {out}')

    return {'module': mod, 'n': n, 'by_status': dict(by_status),
            'by_kind': dict(by_kind), 'unassigned_kind': dict(ua_kind)}


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('modules', nargs='+')
    ap.add_argument('--report', type=Path, default=ROOT / 'build/win/report.json')
    ap.add_argument('--csv', action='store_true', help='write the per-function CSV')
    ap.add_argument('--txt', action='store_true', help='write the unassigned worklist')
    args = ap.parse_args(argv)
    for mod in args.modules:
        run(mod, args.report, args.csv, args.txt)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
