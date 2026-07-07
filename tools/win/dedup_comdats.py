#!/usr/bin/env python3
"""Strip redundant inline COMDATs from a base COFF so objdiff shows each once.

For the Pikmin Windows (VC6/PE) decomp. Under `/Od` every *referenced* inline
member is emitted as a COMDAT-select-ANY external in every TU that uses it (and
`SYSCORE_EXPORTS` widens that to every TU that merely includes the header), so a
single inline (`Stream::Stream`, `Vector3f::Vector3f`, ...) shows up in dozens of
objdiff units -- sysCore's objdiff is ~87% duplicate copies. The originals'
incremental linker kept exactly ONE copy of each such COMDAT: the one from the
object whose kept `.text` contribution physically contains that address.
`inline_owner.py` computes that owner per inline (byte-faithfully, from the `.ilk`
section-contribution table) into `inline_owner_<module>.csv`.

This tool consumes that owner map and, for each base object, **removes every shared
inline that object does NOT own** so the function survives in exactly one unit (its
owner) instead of N. Removal is done the minimal, low-risk way: the inline's
function symbol is rewritten to an *undefined external* (Section=0, Value=0),
leaving the rest of the COFF byte-for-byte unchanged. That is sufficient because:

  * objdiff lists a function only where a DEFINED text symbol names it, so an
    undefined external no longer appears as a function in that unit; and
  * `pe_extract.base_defined_functions()` keys off Section>0, so the carved objdiff
    *target* automatically drops the same inline -- base and target stay paired
    with zero extra plumbing (one source of truth: the stripped base).

References from *kept* functions in the same object (a call to the stripped inline)
still resolve: they reference the same symbol, now undefined, and objdiff pairs
relocations by name regardless of defined/undefined -- and `pe_extract` re-emits
the matching REL32 in the target from the map. The owner's copy stays defined, so
every inline is still present exactly once across the whole module.

Only functions listed in the owner map (i.e. genuinely duplicated across >1 unit)
are ever touched; a unit's uniquely-owned functions are left alone.

Usage:
    # rewrite every base obj of a module into a deduped tree (build wiring)
    python tools/win/dedup_comdats.py sysCore \
        --in-dir build/win/obj/sysCore --out-dir build/win/obj_dedup/sysCore
    # one object (what the ninja `dedup` edge runs)
    python tools/win/dedup_comdats.py sysCore \
        --obj build/win/obj/sysCore/camera.obj --out build/win/obj_dedup/sysCore/camera.obj
"""
from __future__ import annotations

import argparse
import csv
import struct
import sys
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

IMAGE_SYM_CLASS_EXTERNAL = 2
IMAGE_SYM_CLASS_STATIC = 3


def load_owner(path: Path) -> dict[str, str]:
    """decorated inline name -> the ONE objdiff unit that should keep it."""
    owner: dict[str, str] = {}
    with path.open(newline="") as fh:
        for row in csv.DictReader(fh):
            owner[row["decorated"]] = row["owner_unit"]
    return owner


def _defined_functions(obj: bytes):
    """Yield (symbol_index, record_offset, name, sclass) for each DEFINED function
    symbol (Section>0, derived type FUNCTION, external/static) in a base COFF."""
    num_sections, sym_ptr, num_syms = struct.unpack_from("<HxxxxII", obj, 2)
    strtab = sym_ptr + num_syms * 18
    i = 0
    while i < num_syms:
        off = sym_ptr + i * 18
        raw = obj[off:off + 8]
        value, secnum, typ, sclass, naux = struct.unpack_from("<IhHBB", obj, off + 8)
        if raw[:4] == b"\x00\x00\x00\x00":
            so = strtab + struct.unpack_from("<I", raw, 4)[0]
            name = obj[so:obj.index(b"\x00", so)].decode("latin1")
        else:
            name = raw.rstrip(b"\x00").decode("latin1")
        if (secnum > 0 and (typ >> 4) == 0x2
                and sclass in (IMAGE_SYM_CLASS_EXTERNAL, IMAGE_SYM_CLASS_STATIC)):
            yield i, off, name, sclass
        i += 1 + naux


def strip_obj(raw: bytes, unit: str, owner: dict[str, str]) -> tuple[bytes, list[str]]:
    """Return (new_obj_bytes, stripped_names). Rewrites every defined function this
    unit does NOT own -- but that IS a duplicated inline (present in the owner map)
    -- into an undefined external (Section=0, Value=0). All other bytes are
    preserved exactly, so symbol indices, relocations and aux records are untouched.
    """
    out = bytearray(raw)
    stripped: list[str] = []
    for _idx, off, name, sclass in _defined_functions(raw):
        if sclass == IMAGE_SYM_CLASS_STATIC:
            # Internal-linkage functions (file-static `_Print`/`_Error`, `printMatrix`)
            # share a decorated name across TUs but are DISTINCT functions at distinct
            # DLL addresses -- the linker keeps every copy, not one. They are not
            # mergeable select-any COMDAT inlines (those are EXTERNAL), so they must
            # never be deduped: stripping the definition also strips the base static
            # that pe_extract's per-TU static discovery keys on, leaving the carved
            # target's call to `_Print` labelled with its Ghidra placeholder.
            continue
        ow = owner.get(name)
        if ow is None or ow == unit:
            continue  # not a tracked duplicate, or this unit is the rightful owner
        # -> undefined external: zero Value (+8, u32) and Section (+12, i16).
        struct.pack_into("<Ih", out, off + 8, 0, 0)
        stripped.append(name)
    return bytes(out), stripped


def process(module: str, owner: dict[str, str], jobs: list[tuple[Path, Path]],
            verbose: bool = False) -> int:
    total = 0
    per_owner: Counter = Counter()
    for src, dst in jobs:
        unit = src.stem
        new, stripped = strip_obj(src.read_bytes(), unit, owner)
        dst.parent.mkdir(parents=True, exist_ok=True)
        dst.write_bytes(new)
        total += len(stripped)
        for n in stripped:
            per_owner[owner[n]] += 1
        if verbose and stripped:
            print(f"  {unit}: stripped {len(stripped)}", file=sys.stderr)
    print(f"=== {module} COMDAT dedup ===")
    print(f"objects processed        : {len(jobs)}")
    print(f"inline copies stripped   : {total}")
    print(f"survivors by owner (top) : {dict(per_owner.most_common(8))}")
    return 0


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("module", help="module name (e.g. sysCore)")
    ap.add_argument("--owner", type=Path, help="inline owner CSV "
                    "(default build/win/inline_owner_<module>.csv)")
    ap.add_argument("--in-dir", type=Path, help="base obj dir to sweep")
    ap.add_argument("--out-dir", type=Path, help="deduped obj dir to write")
    ap.add_argument("--obj", type=Path, help="single base obj (with --out)")
    ap.add_argument("--out", type=Path, help="single deduped obj out")
    ap.add_argument("-v", "--verbose", action="store_true")
    args = ap.parse_args(argv)

    owner_csv = args.owner or (ROOT / f"build/win/inline_owner_{args.module}.csv")
    owner = load_owner(owner_csv)

    if args.obj:
        if not args.out:
            ap.error("--obj requires --out")
        jobs = [(args.obj, args.out)]
    elif args.in_dir:
        out_dir = args.out_dir or (args.in_dir.parent / (args.in_dir.name + "_dedup"))
        jobs = [(p, out_dir / p.name) for p in sorted(args.in_dir.glob("*.obj"))]
    else:
        ap.error("need --in-dir (+--out-dir) or --obj (+--out)")
    return process(args.module, owner, jobs, args.verbose)


if __name__ == "__main__":
    raise SystemExit(main())
