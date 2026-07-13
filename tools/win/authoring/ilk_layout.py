#!/usr/bin/env python3
r"""DEPRECATED (2026-07-12): superseded by ilk.py, which decodes the whole `.ilk`
correctly (this file's pointer model — two bases, 0x80-stride table — was partly wrong;
see ILK_FORMAT.md). Use `ilk.py` / `ilk_map.py`. Kept only for callers not yet migrated.

Parse the object-contribution structure of a Microsoft incremental-link database
(`<module>.ilk`) for the Pikmin Windows (VC6/PE) decomp.

The `.ilk` is the linker's own record of how it built the module. This tool decodes
the parts of its (undocumented) format that we have confirmed, and exposes them as a
clean table:

  * **link order** -- the objects in the exact order the linker consumed them (this
    is the deterministic ownership key for COMDAT-select-ANY inlines: the earliest
    object in link order that emits a shared inline is the one the linker keeps -- see
    inline_owner.py / [[win-decomp-inline-dedup]]);
  * **object records** -- for each contributing object: its path, and a pointer+size
    into the `.ilk`'s second stream (the per-object debug/symbol data).

Confirmed format facts (sysBootup.ilk + sysCore.ilk, VC6 link 12.00.8168):
  * File starts with the ASCII tag ``Microsoft Linker Database\n``.
  * Internal pointers are *absolute to a virtual base*, not file offsets:
      - base ``0x3fff0000`` -> the primary database region (records, section table);
      - base ``0x40000000`` -> a second, large per-object stream (debug/symbol data;
        ~10 MB for sysCore vs the 11 MB file). An object record's size field is the
        length of THIS stream's data, NOT the object's `.text` contribution.
    A tagged pointer ``p`` dereferences to file offset ``p & 0xffff`` within its base
    region (both regions verified fully in-file for sysBootup: all 3051 pointers).
  * Object record (found at ``objpath_string_offset - 0x20``):
        +0x00  u32  pointer into the 0x40000000 stream (this object's data)
        +0x0c  u32  length of that stream data
        +0x20  ..   NUL-terminated object path (``.\Debug\<stem>.obj`` or a lib path)
  * Section descriptor records are a fixed 0x48 stride table near the file head
    (``?.bss``, ``?.rdata``, ``?.text`` ... each with 0x3fff-tagged link pointers).

DECODED (2026-07-05 s7): the per-object **`.text` address ranges** -- the section-
contribution table. Each contribution is a fixed 0x80-stride record; a record is
identified by the dword at its ``+0x00`` being the **.text section-descriptor body
pointer** (``MAP_BASE + text_name_offset + 8``; derived per-module, not hardcoded).
Fields relative to that dword ``h``:
    h-0x1c  u32  contribution RVA (16-aligned, packed consecutively)
    h-0x18  u32  section characteristics (0x60000020 CODE|EXEC|READ, |0x500000
                 ALIGN_16, |0x1000 LNK_COMDAT, |0x800 LNK_REMOVE)
    h-0x14  u32  contribution byte size
    h-0x04  u32  owner pointer -- identifies the contributing object
    h+0x00  u32  = the .text descriptor body pointer (the record tag)
The ``.ilk`` keeps a record for EVERY COMDAT copy, including the ones the linker
folded away: those carry the ``LNK_REMOVE`` (0x800) bit. **Dropping the REMOVE bit
leaves the KEPT contributions, which tile ``.text`` exactly once (verified: 0 gaps,
0 overlaps for sysCore).** Each object's ``.text`` range is the min..max of its kept
contributions, and an object's owner pointer is read straight from its module record
at ``record_offset - 0x08``. Validated: every AyuStack/Camera/Stream/... export lands
in the matching object's span, and the shared Vector3f/Node/CoreNode/String inline
COMDATs all land in ``graphics`` (link #1) -- exactly the byte-faithful attribution
inline_owner.py needs (replacing its ~50%-consistent link-order approximation).

Usage:
    python tools/win/authoring/ilk_layout.py sysCore                 # link order + objects
    python tools/win/authoring/ilk_layout.py sysCore --text-ranges   # per-object .text ranges
    python tools/win/authoring/ilk_layout.py plugPiki -o out.csv      # also write a CSV
"""
from __future__ import annotations

import argparse
import csv
import os
import re
import struct
from pathlib import Path

import _bootstrap  # noqa: E402,F401  (authoring/_bootstrap.py: sys.path + ROOT)
ROOT = _bootstrap.ROOT

MAGIC = b'Microsoft Linker Database'
# The whole file is conceptually mapped at this virtual base: an internal pointer's
# file offset is simply ``ptr - MAP_BASE``. Verified against sysCore.ilk (665111 of
# 665120 tagged dwords resolve in-file; the 9 stragglers are coincidental values).
# The low region (offset < ~size of the primary DB) holds records + the section
# table; the high region holds the per-object debug/symbol stream.
MAP_BASE = 0x3FFF0000


def deref(ptr: int, size: int) -> int | None:
    """A tagged internal pointer -> file offset, or None if it isn't one."""
    if MAP_BASE <= ptr:
        off = ptr - MAP_BASE
        if off < size:
            return off
    return None


def parse_objects(raw: bytes) -> list[dict]:
    """Contributing objects in link order (first occurrence of each stem wins).

    Returns dicts: {stem, path, offset (of the record), stream_ptr, stream_len}."""
    def u32(o: int) -> int:
        return struct.unpack_from('<I', raw, o)[0]
    out: list[dict] = []
    seen: set[str] = set()
    for m in re.finditer(rb'[\x20-\x7e]{5,}', raw):
        s = m.group().decode('latin1')
        if not s.lower().endswith('.obj'):
            continue
        stem = os.path.basename(s.replace('\\', '/'))[:-4].lower()
        if stem in seen:
            continue
        seen.add(stem)
        hdr = m.start() - 0x20
        if hdr < 0:
            continue
        out.append({
            'stem': stem,
            'path': s,
            'offset': hdr,
            'stream_ptr': u32(hdr),
            'stream_len': u32(hdr + 0xC),
        })
    return out


def _u32(raw: bytes, o: int) -> int:
    return struct.unpack_from('<I', raw, o)[0]


def text_descriptor(raw: bytes) -> tuple[int, int, int]:
    """(tag, text_lo_rva, text_hi_rva) for this module's `.text` section.

    The tag is the descriptor-body pointer every `.text` contribution record
    references at its `+0x00`. Derived per-module: for each `.text\\0\\0\\0` name
    string, ``MAP_BASE + off + 8`` is a candidate tag; the real one is the value
    that occurs thousands of times (once per contribution). The descriptor body
    holds the section RVA at +0x08 and virtual size at +0x14."""
    best = None
    for m in re.finditer(rb'\.text\x00\x00\x00', raw):
        off = m.start()
        if off & 3:
            continue
        tag = MAP_BASE + off + 8
        cnt = raw.count(struct.pack('<I', tag))
        if best is None or cnt > best[0]:
            body = off + 8
            lo = _u32(raw, body + 8)
            hi = lo + _u32(raw, body + 0x14)
            best = (cnt, tag, lo, hi)
    if best is None or best[0] < 16:
        raise SystemExit('could not locate the .text section descriptor')
    return best[1], best[2], best[3]


def text_contributions(raw: bytes) -> tuple[list[tuple[int, int, int]], int, int]:
    """The KEPT `.text` contributions as (rva, size, owner_ptr), plus (lo, hi).

    Filters the section-contribution table to code contributions that the linker
    kept (CODE bit set, LNK_REMOVE clear) and whose RVA lies in `.text`; these
    tile the section exactly once."""
    tag, lo, hi = text_descriptor(raw)
    pat = struct.pack('<I', tag)
    recs: list[tuple[int, int, int]] = []
    h = raw.find(pat)
    while h >= 0:
        if h >= 0x20 and h + 4 <= len(raw):
            chars = _u32(raw, h - 0x18)
            start = _u32(raw, h - 0x1c)
            size = _u32(raw, h - 0x14)
            owner = _u32(raw, h - 0x04)
            if ((chars & 0x20) and not (chars & 0x800) and lo <= start < hi
                    and 0 < size < 0x20000 and MAP_BASE <= owner < MAP_BASE + len(raw)):
                recs.append((start, size, owner))
        h = raw.find(pat, h + 1)
    return recs, lo, hi


def object_text_ranges(raw: bytes) -> dict[str, tuple[int, int]]:
    """object stem -> (lo_rva, hi_rva) of its `.text` contribution span.

    Ownership is byte-faithful: an object's owner pointer is read from its module
    record at ``offset - 0x08`` and matched against the contribution table's owner
    field, so each kept COMDAT copy is attributed to the exact object the linker
    laid it in (not a link-order guess)."""
    recs, _lo, _hi = text_contributions(raw)
    byo: dict[int, list[int]] = {}
    for start, size, owner in recs:
        r = byo.setdefault(owner, [1 << 32, 0])
        r[0] = min(r[0], start)
        r[1] = max(r[1], start + size)
    out: dict[str, tuple[int, int]] = {}
    for o in parse_objects(raw):
        sp = byo.get(_u32(raw, o['offset'] - 0x08))
        if sp:
            out[o['stem']] = (sp[0], sp[1])
    return out


def find_ilk(mod: str) -> Path:
    for c in (ROOT / f'orig/GPIE01_01/files/{mod}.ilk',
              ROOT / f'orig/GPIE01_01/files/plugins/{mod}.ilk'):
        if c.exists():
            return c
    raise SystemExit(f'no .ilk found for {mod}')


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument('module', help='module stem, e.g. sysCore or plugPiki')
    ap.add_argument('--ilk', type=Path, help='override .ilk path')
    ap.add_argument('-o', '--out', type=Path, help='write the object table as CSV')
    ap.add_argument('--text-ranges', action='store_true',
                    help='print per-object .text address ranges (byte-faithful)')
    ap.add_argument('--ranges-csv', type=Path,
                    help='write per-object .text ranges as CSV (stem,lo_rva,hi_rva); '
                         'this is the tracked <mod>_text_ranges.csv build input that '
                         'lets the routine build attribute a function to its TU without '
                         'parsing the .ilk (see tools/win/README.md)')
    args = ap.parse_args(argv)

    ilk = args.ilk or find_ilk(args.module)
    raw = ilk.read_bytes()
    if not raw.startswith(MAGIC):
        raise SystemExit(f'{ilk}: not a Microsoft Linker Database (bad magic)')

    if args.ranges_csv:
        ranges = object_text_ranges(raw)
        args.ranges_csv.parent.mkdir(parents=True, exist_ok=True)
        with args.ranges_csv.open('w', newline='') as fh:
            w = csv.writer(fh)
            w.writerow(['stem', 'lo_rva', 'hi_rva'])
            for stem, (a, b) in sorted(ranges.items(), key=lambda kv: kv[1][0]):
                w.writerow([stem, f'{a:#x}', f'{b:#x}'])
        print(f'wrote {len(ranges)} object ranges -> {args.ranges_csv}')
        return 0

    if args.text_ranges:
        recs, lo, hi = text_contributions(raw)
        ranges = object_text_ranges(raw)
        cov = sum(hi_ - lo_ for lo_, hi_ in ranges.values())
        print(f'=== {args.module}.ilk per-object .text ranges ===  ({ilk})')
        print(f'.text RVA {lo:#x}..{hi:#x} ({hi - lo} bytes); '
              f'{len(recs)} kept contributions; {len(ranges)} objects mapped')
        for stem, (a, b) in sorted(ranges.items(), key=lambda kv: kv[1][0]):
            print(f'  {a:#08x}..{b:#08x}  {b - a:>7}B  {stem}')
        print(f'covered by mapped objects: {cov:#x} of {hi - lo:#x}')
        return 0

    objs = parse_objects(raw)
    print(f'=== {args.module}.ilk object contributions ===  ({ilk}, {len(raw)} bytes)')
    print(f'{len(objs)} objects in link order:')
    for i, o in enumerate(objs):
        d = deref(o['stream_ptr'], len(raw))
        tag = f'stream@{d:#x}' if d is not None else f'raw {o["stream_ptr"]:#010x}'
        print(f'  [{i:3d}] {o["stem"]:24} stream_len={o["stream_len"]:>8}  ({tag})')

    if args.out:
        args.out.parent.mkdir(parents=True, exist_ok=True)
        with args.out.open('w', newline='') as fh:
            w = csv.writer(fh)
            w.writerow(['link_index', 'stem', 'path', 'record_offset',
                        'stream_ptr', 'stream_len'])
            for i, o in enumerate(objs):
                w.writerow([i, o['stem'], o['path'], hex(o['offset']),
                            hex(o['stream_ptr']), o['stream_len']])
        print(f'wrote -> {args.out}')
    return 0


if __name__ == '__main__':
    raise SystemExit(main())
