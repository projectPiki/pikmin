#!/usr/bin/env python3
r"""Refresh stale aggregate class-keys in a module's symbol-map ``name_mangled``
column so the carved objdiff *target* spells references the same way the current
base does.

Part of the Pikmin Windows (VC6/PE32) decomp. plugPiki's map got its internal
``name_mangled`` from ``backfill_map_names.py``, which harvested them positionally
from OUR compiled base objects. That harvest ran *before* the codebase-wide
``struct``->``class`` conversion, so the names it froze into the map carry the old
``struct`` key: ``?findTeki@ActDecoy@@IAEPA U Creature@@XZ`` instead of the true
``...PA V Creature@@...`` the shipped binary (and our post-flip base) use. MSVC
mangles ``class X`` as ``V`` and ``struct X`` as ``U``, so the same function has
two spellings depending on the declaration.

``pe_extract.resolve_name`` prefers the map's ``name_mangled`` when naming a
carved target's relocation operands, so those stale ``U`` names surface on the
*target* side of objdiff while the *base* side (recompiled from the flipped
headers) shows ``V`` -- a spurious struct-vs-class mismatch across every function
that references an aggregate-signature callee (e.g. ``ActDecoy::exec``).
``backfill_map_names.py`` cannot fix this: it only fills *empty* rows, and these
already carry a (stale) name.

This tool refreshes them **surgically and without guessing**: it collects the
decorated names our current base objects actually define, indexes them by their
class-key-neutralised signature (``pe_extract.canon_sig``), and for every map row
whose ``name_mangled`` has the same canonical signature as exactly one base name
adopts the base's spelling. So it flips exactly the rows whose only drift is the
class-key -- ``U``->``V`` for the flipped types -- and leaves genuinely-``struct``
types (the base still emits ``U`` for those) and unmatched rows untouched. It can
never invent a name: it only ever copies a spelling the base emits.

Dry-run by default; ``--apply`` writes the map (a rolling pre-apply backup goes to
``build/win/mapbak/<map>.bak`` -- see ``tools/win/mapbak.py``).
Re-carve afterwards: ``ninja -f build/win/build.ninja target``.

Usage:
    python tools/win/refresh_map_classkey.py \
        --map     config/GPIE01_01/win/plugPiki_map.csv \
        --obj-dir build/win/obj/plugPiki \
        [--apply]
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
from pe_extract import canon_sig  # noqa: E402
from mapbak import backup  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]


def defined_symbol_names(data: bytes) -> set[str]:
    """Decorated names of every symbol a COFF object *defines* (secnum > 0).

    Definitions (functions and COMDAT data) carry the object's own, current
    spelling of each type -- the ground truth we want to adopt. Undefined
    externals and ``__imp_`` thunks are skipped so cross-DLL import spellings
    never contaminate the internal-reference index."""
    _machine, nsec, _ts, symptr, nsym = struct.unpack_from("<HHIII", data, 0)
    strtab = symptr + nsym * 18
    names: set[str] = set()

    def symname(o: int) -> str:
        raw = data[o:o + 8]
        if raw[:4] == b"\x00\x00\x00\x00":
            so = strtab + struct.unpack_from("<I", raw, 4)[0]
            return data[so:data.index(b"\x00", so)].decode("latin1")
        return raw.rstrip(b"\x00").decode("latin1")

    i = 0
    while i < nsym:
        o = symptr + i * 18
        _value, secnum, _typ, _sclass, naux = struct.unpack_from("<IhHBB", data, o + 8)
        if secnum > 0:
            nm = symname(o)
            if nm.startswith("?"):  # decorated MSVC name (skips labels/__imp_/CRT)
                names.add(nm)
        i += 1 + naux
    return names


def base_canon_index(obj_dir: Path) -> dict[str, str]:
    """canonical signature -> the single decorated base name with it.

    Signatures shared by more than one distinct base name are dropped (a name
    is only adopted when the canonical match is unambiguous)."""
    canon: dict[str, str] = {}
    ambiguous: set[str] = set()
    for objpath in sorted(glob.glob(str(obj_dir / "*.obj"))):
        for nm in defined_symbol_names(Path(objpath).read_bytes()):
            c = canon_sig(nm)
            if not c:
                continue
            prev = canon.get(c)
            if prev is None:
                canon[c] = nm
            elif prev != nm:
                ambiguous.add(c)
    for c in ambiguous:
        canon.pop(c, None)
    return canon


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--map", required=True, type=Path)
    ap.add_argument("--obj-dir", required=True, type=Path,
                    help="dir of this module's compiled base .obj files")
    ap.add_argument("--apply", action="store_true",
                    help="write the map (default: dry-run); backs up to "
                         "build/win/mapbak/<map>.bak")
    args = ap.parse_args(argv)

    canon = base_canon_index(args.obj_dir)
    print(f"base defines {len(canon)} unambiguous canonical signatures")

    rows = list(csv.DictReader(args.map.open(encoding="utf-8")))
    changes = []  # (va, old, new, label)
    per_type = defaultdict(int)
    for r in rows:
        nm = (r.get("name_mangled") or "").strip()
        if not nm.startswith("?"):
            continue
        c = canon_sig(nm)
        if not c:
            continue
        b = canon.get(c)
        if b and b != nm:
            changes.append((r.get("va", ""), nm, b, r.get("name", "")))
            r["name_mangled"] = b
            per_type[(nm, b)] += 1

    print(f"refreshed {len(changes)} name_mangled (class-key drift -> base spelling)")
    for va, old, new, label in sorted(changes, key=lambda c: c[3])[:25]:
        print(f"  {va:>10}  {label:32.32}  {old}\n{'':44}-> {new}")
    if len(changes) > 25:
        print(f"  ... and {len(changes) - 25} more")

    if args.apply:
        bak = backup(args.map)
        with args.map.open("w", encoding="utf-8", newline="") as f:
            w = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
            w.writeheader()
            w.writerows(rows)
        print(f"\nbacked up -> {bak}")
        print(f"WROTE {args.map} (+{len(changes)} refreshed). Re-carve: "
              f"ninja -f build/win/build.ninja target")
    else:
        print(f"\n(dry-run) re-run with --apply to write {args.map}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
