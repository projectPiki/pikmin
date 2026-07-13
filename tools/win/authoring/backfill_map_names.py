#!/usr/bin/env python3
"""DEPRECATED (2026-07-12): superseded by the `.ilk` overlay (see README ★ section /
ilk_map.py) — the `.ilk` fills every empty ``name_mangled`` authoritatively, not by
positional guess. Kept for reference only.

Backfill true MSVC ``name_mangled`` into a module's symbol map by positional
harvest from the compiled base objects.

Part of the Pikmin Windows (VC6/PE32) decomp. plugPiki's map (from Ghidra)
carries only *demangled* labels for internals (``Vector3f::operatorMultVF``,
``qdist2CC``, ``PaniMotionInfo::PaniMotionInfo2``) and an empty ``name_mangled``.
objdiff and pe_extract pair symbols by decorated name, and the demangled-name
bridge in pe_extract can't key the cases where Ghidra's label diverges from the
MSVC demangling (operators, arg/overload suffixes, data globals) -- so those
references show as spurious mismatches even when the bytes are identical.

This tool recovers the decorated names *positionally*, without relying on
demangling to line up:

  * For every function a base ``.obj`` defines and that carves from the DLL, it
    aligns the base disassembly (whose relocations carry the real decorated name
    at each call/data site) against the original bytes (whose call/data operands
    give the target VA at that same site) using an LCS over addr-blanked
    instructions.
  * An aligned reference site therefore yields ``target_va -> decorated name``.
    Aggregated across every TU, a map row's name is the decorated name voted by
    the overwhelming plurality of aligned sites; scattered single votes from
    mis-alignments are outvoted.

Safeguards (a wrong name would make objdiff mis-pair or carve the wrong body):
  * **Dominance** -- accept a VA's winner only with a clear plurality
    (``w >= 2*runner + 1``), so 1-off mis-alignment noise never wins.
  * **Corroboration** -- the harvested name must be demangling-consistent with
    the map label (lenient for operators and Ghidra's suffixes, strict enough to
    reject a mis-aligned data load, e.g. ``tekiMgr`` vs ``gameflow``).
  * **Uniqueness** -- a decorated name denotes exactly one address; if several
    VAs propose the same name, only the strongest-voted keeps it, and names an
    export already owns are off-limits. This prevents duplicate ``name_mangled``,
    which would make ``pe_extract.carve_row`` copy the wrong function body.

Validated with the objdiff-cli oracle (re-carve + ``report generate``): on
plugPiki it named ~3.2k rows, took +660 functions to byte-exact with **zero**
regressions of previously-exact functions. Dry-run by default; ``--apply`` writes
the map. Re-carve afterwards (``ninja -f build/win/build.ninja target``).

Usage:
    python tools/win/authoring/backfill_map_names.py \
        --dll     orig/GPIE01_01/files/plugins/plugPiki.dll \
        --map     config/GPIE01_01/win/plugPiki_map.csv \
        --obj-dir build/win/obj/plugPiki \
        [--apply]
"""
from __future__ import annotations

import argparse
import csv
import difflib
import glob
import re
import struct
import sys
from collections import defaultdict
from pathlib import Path

import _bootstrap  # noqa: E402,F401  (authoring/_bootstrap.py: sys.path + ROOT)
import capstone  # noqa: E402
from capstone import x86 as cs_x86  # noqa: E402
from pe_symbols import PEFile, demangle  # noqa: E402
from pe_extract import load_map  # noqa: E402

_MD = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
_MD.detail = True

_CC = re.compile(r"\b__(?:thiscall|cdecl|stdcall|fastcall|clrcall)\b")


# --- COFF reading (base object) ---------------------------------------------
def _parse_coff(data: bytes):
    """(sections, defined-function symbols, symname(idx)) for a COFF object."""
    _machine, nsec, _ts, symptr, nsym = struct.unpack_from("<HHIII", data, 0)
    strtab = symptr + nsym * 18
    sections = []
    off = 20
    for _ in range(nsec):
        (_vsz, _va, rawsz, rawptr, relptr, _lnptr, nrel, _nln, _ch) = \
            struct.unpack_from("<IIIIIIHHI", data, off + 8)
        sections.append(dict(rawsz=rawsz, rawptr=rawptr, relptr=relptr,
                             nrel=nrel, idx=len(sections) + 1))
        off += 40

    def symname(idx: int) -> str:
        o = symptr + idx * 18
        raw = data[o:o + 8]
        if raw[:4] == b"\x00\x00\x00\x00":
            so = strtab + struct.unpack_from("<I", raw, 4)[0]
            return data[so:data.index(b"\x00", so)].decode("latin1")
        return raw.rstrip(b"\x00").decode("latin1")

    funcs = []  # (name, secnum)
    i = 0
    while i < nsym:
        o = symptr + i * 18
        _value, secnum, typ, _sclass, naux = struct.unpack_from("<IhHBB", data, o + 8)
        if secnum > 0 and (typ >> 4) == 2:
            funcs.append((symname(i), secnum))
        i += 1 + naux
    return sections, funcs, symname


def _section_relocs(data: bytes, sec: dict, symname) -> dict:
    """field-offset-within-section -> decorated name of the relocation target."""
    out = {}
    for k in range(sec["nrel"]):
        o = sec["relptr"] + k * 10
        vaddr, symidx, _typ = struct.unpack_from("<IIH", data, o)
        out[vaddr] = symname(symidx)
    return out


def _norm(text: str) -> str:
    """Blank absolute displacements/immediates so alignment compares opcode+reg
    shape, not the addresses (which the relocations/carve differ on)."""
    return re.sub(r"0x[0-9a-f]+", "#", text)


def _base_refs(code: bytes, relocs: dict):
    """(normalized-insn list, decorated-name-or-None per insn) for a base body."""
    seq, names = [], []
    for insn in _MD.disasm(code, 0):
        rname = None
        for f in range(insn.address, insn.address + insn.size):
            if f in relocs:
                rname = relocs[f]
                break
        seq.append(_norm(f"{insn.mnemonic} {insn.op_str}"))
        names.append(rname)
    return seq, names


def _orig_targets(code: bytes, va: int, lo: int, hi: int):
    """(normalized-insn list, in-image-target-VA-or-None per insn) for an original
    body disassembled at its real VA."""
    seq, tgts = [], []
    for insn in _MD.disasm(code, va):
        t = None
        op0 = insn.bytes[0]
        is_branch = op0 in (0xE8, 0xE9) or (
            op0 == 0x0F and len(insn.bytes) > 1 and 0x80 <= insn.bytes[1] <= 0x8F)
        if is_branch and insn.encoding.imm_size == 4:
            t = insn.operands[-1].imm & 0xFFFFFFFF
        elif not is_branch:
            for op in insn.operands:
                if op.type == cs_x86.X86_OP_MEM and op.mem.base == 0 and op.mem.index == 0:
                    v = op.mem.disp & 0xFFFFFFFF
                elif op.type == cs_x86.X86_OP_IMM and insn.encoding.imm_size == 4:
                    v = op.imm & 0xFFFFFFFF
                else:
                    continue
                if lo <= v < hi:
                    t = v
                    break
        seq.append(_norm(f"{insn.mnemonic} {insn.op_str}"))
        tgts.append(t)
    return seq, tgts


# --- Corroboration (harvested decorated name vs map label) ------------------
def _strip_params(t: str) -> str:
    t = t.rstrip()
    if not t.endswith(")"):
        return t
    d, i = 0, len(t) - 1
    while i >= 0:
        if t[i] == ")":
            d += 1
        elif t[i] == "(":
            d -= 1
            if d == 0:
                return t[:i]
        i -= 1
    return t


def _name_parts(decorated: str):
    """(class, method) from a decorated MSVC name; robust to operators & data."""
    dem = demangle(decorated)
    if not dem or dem == decorated:
        return None
    dem = _CC.split(_strip_params(dem))[-1].strip()
    m = re.search(r"(?:[A-Za-z_]\w*::)*(?:operator\s*\S+|~?[A-Za-z_]\w*)$", dem)
    tok = m.group(0) if m else (dem.split()[-1] if dem.split() else "")
    return tok.rsplit("::", 1) if "::" in tok else ["", tok]


def _label_parts(label: str):
    label = re.sub(r"\s+", "", label or "")
    return label.rsplit("::", 1) if "::" in label else ["", label]


def _corroborates(decorated: str, label: str) -> bool:
    """Does a harvested decorated name plausibly belong to this map label?
    Lenient for operators (a free operator may be grouped under a class label)
    and Ghidra's arg/overload suffixes (qdist2CC, PaniMotionInfo2); strict enough
    to reject a mis-aligned data load (tekiMgr vs gameflow)."""
    hp = _name_parts(decorated)
    if hp is None:
        return False
    hcls, hmeth = hp
    lcls, lmeth = _label_parts(label)
    if hmeth.startswith("operator") and lmeth.startswith("operator"):
        return True
    if hcls and lcls and hcls != lcls:
        return False
    return hmeth == lmeth or lmeth.startswith(hmeth) or hmeth.startswith(lmeth)


# --- Harvest ----------------------------------------------------------------
def harvest(dll: Path, map_path: Path, obj_dir: Path):
    """Return (rows, changes) where changes is a list of (va, label, name, w, runner).
    ``rows`` is the CSV rows with accepted names filled into ``name_mangled``."""
    mapping = load_map(map_path)
    pe = PEFile(dll.read_bytes())
    lo = pe.image_base
    hi = max(pe.image_base + s.vaddr + max(s.vsize, s.raw_size) for s in pe.sections)

    votes: dict[int, dict[str, int]] = defaultdict(lambda: defaultdict(int))
    for objpath in sorted(glob.glob(str(obj_dir / "*.obj"))):
        data = Path(objpath).read_bytes()
        sections, funcs, symname = _parse_coff(data)
        secmap = {s["idx"]: s for s in sections}
        for name, secnum in funcs:
            row = mapping.carve_row(name)
            if row is None:
                continue
            sec = secmap.get(secnum)
            if sec is None:
                continue
            bcode = data[sec["rawptr"]:sec["rawptr"] + sec["rawsz"]]
            brel = _section_relocs(data, sec, symname)
            ocode = pe.data[pe.rva_to_off(row.rva):pe.rva_to_off(row.rva) + row.size]
            bseq, bnames = _base_refs(bcode, brel)
            oseq, otgts = _orig_targets(ocode, row.va, lo, hi)
            sm = difflib.SequenceMatcher(a=bseq, b=oseq, autojunk=False)
            for tag, i1, i2, j1, j2 in sm.get_opcodes():
                if tag != "equal":
                    continue
                for k in range(i2 - i1):
                    m, tgt = bnames[i1 + k], otgts[j1 + k]
                    if m is None or tgt is None or m.startswith(("__imp_", ".")):
                        continue
                    res = mapping.resolve(tgt)
                    if res is None or res[1] != 0:
                        continue  # only name a symbol at its exact start (addend 0)
                    votes[res[0].va][m] += 1

    rows = list(csv.DictReader(map_path.open(encoding="utf-8")))
    by_va = {int(r["va"], 16): r for r in rows}
    taken: dict[str, set] = defaultdict(set)
    for r in rows:
        nm = r["name_mangled"].strip()
        if nm:
            taken[nm].add(int(r["va"], 16))

    # Per-VA: dominant, corroborated proposal.
    proposals = []  # (va, label, name, w, runner)
    for va, counter in votes.items():
        row = by_va.get(va)
        if row is None or row["name_mangled"].strip():
            continue
        ranked = sorted(counter.items(), key=lambda kv: -kv[1])
        name, w = ranked[0]
        runner = ranked[1][1] if len(ranked) > 1 else 0
        if w < 2 * runner + 1:
            continue
        if not _corroborates(name, row.get("name", "")):
            continue
        proposals.append((va, row.get("name", ""), name, w, runner))

    # Uniqueness: each decorated name -> the single strongest-voted VA.
    best_va: dict[str, tuple] = {}
    for va, _label, name, w, _runner in proposals:
        pre = taken.get(name)
        if pre and va not in pre:
            continue  # an export already owns this name at another VA
        if name not in best_va or w > best_va[name][0]:
            best_va[name] = (w, va)

    changes = []
    for va, label, name, w, runner in proposals:
        if best_va.get(name, (0, None))[1] != va:
            continue
        by_va[va]["name_mangled"] = name
        changes.append((va, label, name, w, runner))
    return rows, changes


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--dll", required=True, type=Path)
    ap.add_argument("--map", required=True, type=Path)
    ap.add_argument("--obj-dir", required=True, type=Path,
                    help="dir of this module's compiled base .obj files")
    ap.add_argument("--apply", action="store_true", help="write the map (default: dry-run)")
    args = ap.parse_args(argv)

    rows, changes = harvest(args.dll, args.map, args.obj_dir)
    print(f"accepted {len(changes)} new name_mangled")
    for va, label, name, w, runner in sorted(changes, key=lambda c: c[1])[:20]:
        print(f"  {va:#010x}  {label:34} -> {name}   ({w} vs {runner})")
    if len(changes) > 20:
        print(f"  ... and {len(changes) - 20} more")

    if args.apply:
        with args.map.open("w", encoding="utf-8", newline="") as f:
            w = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
            w.writeheader()
            w.writerows(rows)
        print(f"\nWROTE {args.map} (+{len(changes)} name_mangled). Re-carve: "
              f"ninja -f build/win/build.ninja target")
    else:
        print(f"\n(dry-run) re-run with --apply to write {args.map}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
