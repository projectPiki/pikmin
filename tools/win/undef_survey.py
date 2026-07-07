#!/usr/bin/env python3
r"""Survey the UNRESOLVED external symbols across a module's compiled base objects
-- the exact set a non-`/FORCE` link would report -- for the Pikmin Windows decomp.

This is the concrete input to workstream (b) (the filler-object / clean-link pass):
to link the DLL without `/FORCE`, every symbol referenced-but-not-defined by our
objects must be supplied, either carved from the original DLL (if the map has its
address) or stubbed (Dolphin SDK / CRT / genuinely-absent code). The tool parses
each `build/win/obj/<mod>/*.obj` COFF symbol table, collects symbols that are an
undefined external (Section=0, StorageClass=EXTERNAL) in >=1 object and defined
(Section>0) in NONE, and buckets them:

  carve-fn   -- a function the map has an address for -> pe_extract can carve a
                filler object (the bulk of the clean-link work).
  carve-data -- a data symbol the map has an address for -> carve into .rdata/.data
                (pe_extract already carves data; .bss-by-size is the remaining gap).
  stub       -- not in the map: Dolphin SDK (OS*/GX*/VI*/PAD*/MTX*/DVD*), CRT
                (_*), or code we simply have not reversed -> needs a stub/decl.

Writes `build/win/undef_<mod>.csv` (name, bucket, refs, demangled).

Usage:
    python tools/win/undef_survey.py sysCore plugPiki
"""
from __future__ import annotations

import argparse
import csv
import glob
import struct
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import pydemumble  # noqa: E402
from pe_extract import demangled_key, map_label_key  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]

# Dolphin SDK / CRT prefixes that we stub rather than carve (not in the DLL as our code)
SDK_PREFIXES = ('OS', 'GX', 'VI', 'PAD', 'MTX', 'DVD', 'DSP', 'AI', 'AR', 'CARD',
                'GD', 'Jac', 'PPCMt', 'PPCMf', '__PS', 'C_MTX', 'PSMTX', 'PSVEC',
                'DC', 'VEC',   # DC* = data-cache ops, VEC* = paired-single vec math
                'HIO')         # HIO* = host I/O (Dolphin dev-kit mailbox)


def coff_symbols(raw: bytes):
    """Yield (name, section_number, storage_class) for each COFF symbol."""
    if raw[:2] == b'MZ':
        return
    nsym = struct.unpack_from('<I', raw, 12)[0]
    symptr = struct.unpack_from('<I', raw, 8)[0]
    strtab = symptr + nsym * 18
    i = 0
    while i < nsym:
        o = symptr + i * 18
        if struct.unpack_from('<I', raw, o)[0] == 0:
            off = struct.unpack_from('<I', raw, o + 4)[0]
            e = raw.find(b'\0', strtab + off)
            name = raw[strtab + off:e].decode('latin1')
        else:
            name = raw[o:o + 8].rstrip(b'\0').decode('latin1')
        value = struct.unpack_from('<I', raw, o + 8)[0]
        sec = struct.unpack_from('<h', raw, o + 12)[0]
        sclass = raw[o + 16]
        naux = raw[o + 17]
        yield name, sec, sclass, value
        i += 1 + naux


def bucket(name: str, in_map_fn: bool, in_map_data: bool, in_map_qual: bool) -> str:
    # resolved at link time by the standard import libraries -> NOT a filler:
    if name.startswith('__imp_'):
        return 'import'                          # cross-DLL (sysCore.lib / opengl)
    if in_map_fn or in_map_qual:
        return 'carve-fn'
    if in_map_data:
        return 'carve-data'
    if name.lstrip('_?').startswith(SDK_PREFIXES):
        return 'stub-sdk'                        # Dolphin SDK (needs a decl/stub)
    if not name.startswith('?'):
        return 'crt'                             # C runtime (MSVCRTD) / compiler helpers
    return 'stub-code'                           # our own referenced-but-unwritten code


def run(mod: str) -> None:
    objs = glob.glob(str(ROOT / f'build/win/obj/{mod}/*.obj'))
    defined: set[str] = set()
    undef_refs: Counter = Counter()
    for op in objs:
        raw = Path(op).read_bytes()
        for name, sec, sclass, value in coff_symbols(raw):
            if sclass != 2:                      # IMAGE_SYM_CLASS_EXTERNAL
                continue
            if sec > 0 or (sec == 0 and value > 0):   # defined, or COMMON (tentative)
                defined.add(name)
            elif sec == 0:                            # UNDEF external (value == 0)
                undef_refs[name] += 1
    unresolved = {n: c for n, c in undef_refs.items() if n not in defined}

    # map addresses
    mp = ROOT / f'config/GPIE01_01/win/{mod}_map.csv'
    map_fn: set[str] = set()
    map_data: set[str] = set()
    map_qual: set[str] = set()               # Ghidra-label qualified keys (address-bearing)
    if mp.exists():
        for r in csv.DictReader(mp.open(newline='')):
            nm = (r.get('name_mangled') or '').strip()
            if nm:
                (map_fn if r['kind'] == 'function' else map_data).add(nm)
            if r['kind'] == 'function':
                k = map_label_key(r.get('name') or '')
                if k:
                    map_qual.add(k)

    rows = []
    for n, c in sorted(unresolved.items(), key=lambda kv: -kv[1]):
        dk = demangled_key(n)
        b = bucket(n, n in map_fn, n in map_data, bool(dk) and dk[0] in map_qual)
        rows.append((n, b, c, pydemumble.demangle(n) or ''))

    out = ROOT / f'build/win/undef_{mod}.csv'
    with out.open('w', newline='') as fh:
        w = csv.writer(fh)
        w.writerow(['name_mangled', 'bucket', 'refs', 'demangled'])
        w.writerows(rows)

    dist = Counter(r[1] for r in rows)
    fillers = dist.get('carve-fn', 0) + dist.get('carve-data', 0)
    print(f'=== {mod}: {len(unresolved)} unresolved external symbols ===')
    print('   -- filler-carveable (the (b) core, map has an address) --')
    for b in ('carve-fn', 'carve-data'):
        print(f'   {b:11s}: {dist.get(b, 0)}')
    print('   -- need a hand-written stub/decl --')
    for b in ('stub-code', 'stub-sdk'):
        print(f'   {b:11s}: {dist.get(b, 0)}')
    print('   -- resolved by standard libs at link (NOT fillers) --')
    for b in ('import', 'crt'):
        print(f'   {b:11s}: {dist.get(b, 0)}')
    print(f'   => {fillers} carveable + {dist.get("stub-code",0)+dist.get("stub-sdk",0)} '
          f'stubs = the non-/FORCE gap   -> {out}')


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('modules', nargs='+')
    args = ap.parse_args(argv)
    for m in args.modules:
        run(m)
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
