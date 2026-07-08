#!/usr/bin/env python3
r"""Per-TU PAIRING worklist for the Pikmin Windows (VC6/PE) decomp line list.

Naming the map is a bipartite pairing, per translation unit:
  * LEFT  -- unlabelled map addresses (review_labels.py's rows: a `FUN_`/`sub_`
             placeholder at a real DLL address, with its call fingerprint).
  * RIGHT -- UNPLACED `.ilk` labels: a ground-truth decorated name the map does not
             yet hold at any address. Every one needs to be paired to some address.

`autodraft_labels.py` already pairs the callee-matchable subset; this tool lays out
what is LEFT, grouped by TU, so the remaining pairing can be worked file by file.

TU attribution of an unplaced name (it has no address of its own, by definition):
  precise  -- a PLACED name has a byte-faithful TU via tu_at(rva) (the .ilk .text
              contributions, decoded in ilk_layout). Unplaced names are attributed
              by ILK-ORDER neighbour vote against those precise TUs (the name table
              clusters by contributing object).
  class    -- else the owning class's home TU (where its placed methods live).
  guess    -- else (a whole un-started class -> no placed neighbour/sibling) the
              ilk-order BRACKET (nearest placed TU either side) and a source grep of
              the class name (its .cpp basename lowercases to the TU stem). Recorded
              with its evidence in _unattributed.csv for a human to confirm.

Writes build/win/pairing/<mod>/:
  _summary.csv        tu, addresses, names, balance, note   (work smallest-balanced first)
  <tu>.csv            an ADDR block (va/size/calls) then a NAME block (ilk#/conf/name)
  _unattributed.csv   names with only a guessed TU + the evidence

Usage:
    python tools/win/authoring/pair_worklist.py plugPiki
"""
from __future__ import annotations

import argparse
import bisect
import csv
import re
import subprocess
import sys
from collections import Counter, defaultdict
from pathlib import Path

# A source path embedded in a file-local static's name, e.g.
#   ...\drawworldmap.cpp59771817::  (demangled)  or  ...\drawworldmap.cpp59771817@@
# The .cpp basename lowercases straight to the byte-faithful TU stem -> CERTAIN.
PATHRE = re.compile(r"[\\/]([A-Za-z0-9_]+)\.cpp\d*(?:::|@)")

import _bootstrap  # noqa: E402,F401  (authoring/_bootstrap.py: sys.path + ROOT)
from ilk_functions import find_ilk, tu_at, tu_index  # noqa: E402
from ilk_reconcile import extract_ilk, owner_class  # noqa: E402
from pe_extract import load_map as pe_load_map  # noqa: E402

ROOT = _bootstrap.ROOT


def class_source_stem(cls: str, cache: dict) -> str | None:
    """Educated guess: the .cpp whose basename (lowercased = TU stem) defines the
    most `Cls::` methods. Used only for whole un-started classes."""
    if cls in cache:
        return cache[cls]
    stem = None
    try:
        r = subprocess.run(["git", "grep", "-l", f"{cls}::", "--", "src/*.cpp"],
                           cwd=ROOT, capture_output=True, text=True)
        files = [ln for ln in r.stdout.splitlines() if ln.endswith(".cpp")]
        if files:
            # prefer the file whose stem best matches / most hits
            best = max(files, key=lambda f: subprocess.run(
                ["git", "grep", "-c", f"{cls}::", "--", f],
                cwd=ROOT, capture_output=True, text=True).stdout.count(":") or 1)
            stem = Path(best).stem.lower()
    except Exception:
        stem = None
    cache[cls] = stem
    return stem


def pairing_data(mod: str) -> dict:
    """Compute the per-TU pairing structures (no file output). Returns a dict of
    {names: tu->[(ilk#,conf,dec,dem)], addrs: tu->[review rows],
     anchors: tu->sorted [(ilk#,va)] of PLACED names, foreign, unattributed, ...}."""
    ilk = find_ilk(mod)
    raw = ilk.read_bytes()
    ivs, starts = tu_index(raw)
    smap = pe_load_map(ROOT / f"config/GPIE01_01/win/{mod}_map.csv")

    # ground-truth names in .ilk file order; functions only
    gt = extract_ilk(ilk)
    gt_idx = {dec: i for i, (dec, _dem) in enumerate(gt)}
    gt_dem = dict(gt)
    # functions only; drop adjustor [thunk]s (they aren't standalone body targets)
    fns = [dec for dec, dem in gt if "(" in dem and not dem.startswith("[thunk]")]

    # placed = a .ilk name the map can already LOCATE (exact decorated, the class-key
    # canon, or the demangled-label bridge -- i.e. what objdiff/pe_extract pair); it
    # needs no pairing. placed_tu is the byte-faithful TU of its address, used to
    # anchor the ilk-order voting for the unplaced names.
    placed: set[str] = set()
    placed_tu: dict[str, str] = {}
    anchors: dict[str, list] = defaultdict(list)   # tu -> [(ilk#, va)] of placed names
    for d in fns:
        sym = smap.carve_row(d)
        if sym is not None:
            placed.add(d)
            t = tu_at(sym.rva, ivs, starts)
            if t:
                placed_tu[d] = t
                anchors[t].append((gt_idx[d], sym.va))
    unplaced = [d for d in fns if d not in placed]

    # ilk-order index -> precise TU, for neighbour voting
    idx_tu = {gt_idx[d]: placed_tu[d] for d in placed if d in gt_idx}
    order = sorted(idx_tu)

    # class -> home TU (majority of its placed methods)
    cls_tu: dict[str, Counter] = defaultdict(Counter)
    for d in placed:
        c = owner_class(gt_dem.get(d) or "")
        if c and d in placed_tu:
            cls_tu[c][placed_tu[d]] += 1

    # FOREIGN classes: another module's exports whose INLINE copies appear in this
    # .ilk but are not this module's functions to pair (e.g. sysCore's Vector3f /
    # Matrix4f / StdSystem inlined into plugPiki). Skip them out of the work list.
    import pydemumble
    foreign_classes: set[str] = set()
    foreign_names: set[str] = set()             # exact decorated (free fns w/o a class)
    sc = ROOT / "config/GPIE01_01/win/sysCore_symbols.csv"
    if mod != "sysCore" and sc.exists():
        for r in csv.DictReader(sc.open(newline="")):
            m = r.get("mangled", "")
            foreign_names.add(m)
            c = owner_class(pydemumble.demangle(m) or "")
            if c:
                foreign_classes.add(c)

    def neighbour_tu(i: int, win: int = 40):
        votes: Counter = Counter()
        for off in range(1, win + 1):
            for j in (i - off, i + off):
                if j in idx_tu:
                    votes[idx_tu[j]] += (win - off + 1)
        if not votes:
            return None, 0.0
        tu, w = votes.most_common(1)[0]
        return tu, w / sum(votes.values())

    def bracket(i: int):
        k = bisect.bisect_left(order, i)
        lo = idx_tu[order[k - 1]] if k > 0 else None
        hi = idx_tu[order[k]] if k < len(order) else None
        return lo, hi

    src_cache: dict = {}
    attributed: dict[str, list] = defaultdict(list)   # tu -> [(ilk#, conf, dec, dem)]
    unattributed = []                                  # rows with only a guess
    foreign = []                                       # other-module inline copies
    for d in unplaced:
        i, dem = gt_idx[d], gt_dem[d]
        pm = PATHRE.search(dem) or PATHRE.search(d)
        if pm:                                         # embedded source path = certain
            attributed[pm.group(1).lower()].append((i, "path", d, dem))
            continue
        cls = owner_class(dem)
        if cls in foreign_classes or d in foreign_names:   # sysCore inline in plugPiki
            foreign.append((i, d, dem, cls or "(free fn)"))
            continue
        ntu, nfrac = neighbour_tu(i)
        ctu = cls_tu[cls].most_common(1)[0][0] if cls and cls_tu.get(cls) else None
        if ctu and ntu and ctu == ntu:
            attributed[ctu].append((i, "high", d, dem))
        elif ntu and nfrac >= 0.6:
            attributed[ntu].append((i, "ilk-order", d, dem))
        elif ctu:
            attributed[ctu].append((i, "class", d, dem))
        elif ntu:
            attributed[ntu].append((i, "ilk-order-weak", d, dem))
        else:
            lo, hi = bracket(i)
            guess = class_source_stem(cls, src_cache) if cls else None
            tu = guess or (lo if lo == hi else None)
            if tu:
                attributed[tu].append((i, "guess", d, dem))
            unattributed.append((i, d, dem, cls or "", guess or "",
                                 lo or "", hi or ""))

    # LEFT side: unlabelled addresses per TU (post-apply review list)
    review = ROOT / f"build/win/review/{mod}.csv"
    addrs: dict[str, list] = defaultdict(list)
    if review.exists():
        for r in csv.DictReader(review.open(newline="")):
            addrs[r["tu"]].append(r)

    return {
        "names": dict(attributed), "addrs": dict(addrs),
        "anchors": {t: sorted(v) for t, v in anchors.items()},
        "foreign": foreign, "unattributed": unattributed,
        "n_fns": len(fns), "n_unplaced": len(unplaced),
    }


def run(mod: str) -> None:
    data = pairing_data(mod)
    attributed, addrs = data["names"], data["addrs"]
    unattributed, foreign = data["unattributed"], data["foreign"]

    outdir = ROOT / f"build/win/pairing/{mod}"
    outdir.mkdir(parents=True, exist_ok=True)
    for f in outdir.glob("*.csv"):
        f.unlink()

    all_tus = sorted(set(addrs) | set(attributed))
    summ = []
    for tu in all_tus:
        A = sorted(addrs.get(tu, []), key=lambda r: int(r["va"], 16))
        N = sorted(attributed.get(tu, []))
        with (outdir / f"{tu}.csv").open("w", newline="") as fh:
            w = csv.writer(fh)
            w.writerow(["slot", "va/ilk#", "size", "confidence", "decorated",
                        "demangled", "context (calls / current)"])
            for r in A:
                w.writerow(["ADDR", r["va"], r["size"], "", "", "",
                            r["calls"] or r["current"]])
            for i, conf, dec, dem in N:
                w.writerow(["NAME", i, "", conf, dec, dem, ""])
        bal = len(A) - len(N)
        note = ("balanced" if bal == 0 else
                ("more addresses" if bal > 0 else "more names"))
        summ.append((tu, len(A), len(N), bal, note))

    # sort by ADDRESSES (the actual pairing work) so inline-only buckets with no
    # placeholder addresses (e.g. the zen particle lib) sink to the bottom.
    with (outdir / "_summary.csv").open("w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["tu", "addresses", "names", "addr_minus_names", "note"])
        for row in sorted(summ, key=lambda s: (-s[1], -s[2])):
            w.writerow(row)
    with (outdir / "_unattributed.csv").open("w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["ilk#", "decorated", "demangled", "owner_class",
                    "src_grep_guess", "ilk_bracket_lo", "ilk_bracket_hi"])
        for row in sorted(unattributed):
            w.writerow(row)
    with (outdir / "_cross_module.csv").open("w", newline="") as fh:
        w = csv.writer(fh)
        w.writerow(["ilk#", "decorated", "demangled", "foreign_owner_class"])
        for row in sorted(foreign):
            w.writerow(row)

    conf_mix = Counter(c for lst in attributed.values() for _i, c, _d, _m in lst)
    print(f"=== {mod} pairing worklist ===")
    print(f"   .ilk functions {data['n_fns']}; "
          f"placed {data['n_fns'] - data['n_unplaced']}; "
          f"UNPLACED {data['n_unplaced']}")
    print(f"   unlabelled addresses (review) {sum(len(v) for v in addrs.values())}")
    print(f"   attribution mix: {dict(conf_mix)}")
    print(f"   cross-module inlines skipped (see _cross_module.csv): {len(foreign)}")
    print(f"   still guess-only (see _unattributed.csv): {len(unattributed)}")
    print(f"   wrote {len(all_tus)} per-TU files + _summary.csv -> {outdir}/")


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("module")
    args = ap.parse_args(argv)
    run(args.module)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
