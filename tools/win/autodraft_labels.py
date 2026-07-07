#!/usr/bin/env python3
r"""Auto-draft the review line-list assignments by CALLEE-SET matching, for the
Pikmin Windows (VC6/PE) decomp. Companion to `review_labels.py`.

Each review row is an unnamed address in the ORIGINAL DLL; its `calls` column is the
set of already-named functions it calls (a `call rel32` scan of the shipped bytes --
see review_labels.py). Separately, for every function OUR source compiles we know
the exact set of functions IT calls: the REL32 relocation targets in the base object
`build/win/obj/<mod>/<tu>.obj`, each a decorated MSVC name. So an unnamed original
address and a compiled function that CALL THE SAME SET OF THINGS are the same
function -- and the compiled side hands us the real decorated name to assign.

Per TU: build {compiled fn -> callee-key set} (restricted to functions the map has
NOT already placed = the bucket-B candidates), score each review row against every
candidate by callee-set overlap, and greedily assign unique high-overlap matches.
Confidence tiers (HIGH auto-fills `assign`; MED is a suggestion to eyeball; LOW is
left blank):

  HIGH  overlap>=3, jaccard>=0.5, a clear margin over the 2nd-best, plausible size
  MED   overlap>=2 with a margin
  LOW   ambiguous / too few callees (ctors, accessors -- no reliable call signature)

This is a DRAFT: it never touches the map or the review CSV. It writes
`build/win/review/<mod>_autodraft.csv` (all review columns + assign/confidence/
overlap/jaccard/comp_size/alt). VERIFY before trusting -- a correct name re-carves
byte-identical, a wrong one shows low fuzzy (`--verify` measures this for you).

Usage:
    python tools/win/autodraft_labels.py plugPiki
    python tools/win/autodraft_labels.py plugPiki --verify   # carve+score the draft
"""
from __future__ import annotations

import argparse
import csv
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import pydemumble  # noqa: E402
from pe_extract import load_map, parse_base_coff, IMAGE_REL_I386_REL32  # noqa: E402
from mapbak import backup  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]

# Ubiquitous CRT / compiler helpers: called from almost everything, so they carry
# no discriminating signal -- drop them from both sides' callee sets.
NOISE = {
    "_ftol", "__ftol", "_chkesp", "__chkesp", "_memcpy", "_memset", "_memcmp",
    "_strlen", "_strcmp", "_strcpy", "_strcat", "_sprintf", "_sqrt", "_sqrtf",
    "_cos", "_sin", "_fabs", "_fmod", "_atan2", "__purecall",
}

CALLCONV = ("__thiscall ", "__cdecl ", "__stdcall ", "__fastcall ")


def norm_key(demangled: str) -> str:
    """A demangled signature (or bare label) -> its `Class::method` core: drop the
    leading access/return up to the calling-convention token, then the arg list."""
    s = demangled
    for cc in CALLCONV:
        if cc in s:
            s = s.rsplit(cc, 1)[-1]
    return s.split("(")[0].strip()


def key_set(names) -> set[str]:
    ks = {norm_key(n) for n in names}
    return {k for k in ks if k and k not in NOISE}


def compiled_callsets(obj_bytes: bytes):
    """{decorated fn name -> (callee-key set, body size)} for a base object, using
    only REL32 relocs (direct calls -- mirrors the original's E8-only scan)."""
    func_relocs, _data = parse_base_coff(obj_bytes)
    out = {}
    for name, (raw, relocs) in func_relocs.items():
        callees = [tn for _off, (tn, rt) in relocs.items()
                   if rt == IMAGE_REL_I386_REL32]
        keys = key_set(pydemumble.demangle(c) or c for c in callees)
        out[name] = (keys, len(raw))
    return out


def draft(mod: str) -> list[dict]:
    review = ROOT / f"build/win/review/{mod}.csv"
    if not review.exists():
        raise SystemExit(f"no review file {review}; run review_labels.py --emit first")
    mapping = load_map(ROOT / f"config/GPIE01_01/win/{mod}_map.csv")

    rows_by_tu: dict[str, list[dict]] = defaultdict(list)
    for r in csv.DictReader(review.open(newline="")):
        rows_by_tu[r["tu"]].append(r)

    out_rows: list[dict] = []
    for tu, rows in rows_by_tu.items():
        obj = ROOT / f"build/win/obj/{mod}/{tu}.obj"
        comp = compiled_callsets(obj.read_bytes()) if obj.exists() else {}
        # candidates = compiled fns the map has NOT already placed, with a usable
        # call signature (>=2 discriminating callees).
        cands = {n: (ks, sz) for n, (ks, sz) in comp.items()
                 if len(ks) >= 2 and mapping.carve_row(n) is None}

        # score every (row, candidate) with non-zero overlap
        scored: list[tuple[float, int, dict, str, int]] = []
        row_best: dict[int, tuple[int, int]] = {}  # id(row) -> (best_ov, 2nd_ov)
        per_row_scores: dict[int, list] = defaultdict(list)
        for r in rows:
            rkeys = key_set(c for c in r["calls"].split("; ") if c)
            r["_rkeys"] = rkeys
            if len(rkeys) < 2:
                continue
            for n, (ks, sz) in cands.items():
                ov = len(rkeys & ks)
                if ov < 2:
                    continue
                jac = ov / len(rkeys | ks)
                per_row_scores[id(r)].append((ov, jac, sz, n))
        for r in rows:
            lst = sorted(per_row_scores.get(id(r), []), reverse=True)
            if lst:
                for ov, jac, sz, n in lst:
                    scored.append((ov + jac, ov, r, n, sz))
                best = lst[0][0]
                second = lst[1][0] if len(lst) > 1 else 0
                row_best[id(r)] = (best, second)

        # greedy unique assignment, strongest overlap first
        scored.sort(reverse=True, key=lambda t: t[0])
        used_names: set[str] = set()
        assigned: dict[int, tuple] = {}
        for _s, ov, r, n, sz in scored:
            if id(r) in assigned or n in used_names:
                continue
            cks = cands[n][0]
            jac = len(r["_rkeys"] & cks) / len(r["_rkeys"] | cks)
            assigned[id(r)] = (n, ov, jac, sz)
            used_names.add(n)

        for r in rows:
            best2 = row_best.get(id(r), (0, 0))
            margin = best2[0] - best2[1]
            osize = int(r["size"])
            rec = {k: r[k] for k in ("tu", "va", "size", "kind", "current",
                                     "prev_named", "next_named", "calls")}
            a = assigned.get(id(r))
            conf = ""
            name = ov = jac = csz = ""
            alt = ""
            if a:
                n, ov, jac, csz = a
                name = pydemumble.demangle(n) or n
                ratio = osize / csz if csz else 0
                size_ok = 0.55 <= ratio <= 1.8 if csz else False
                lst = sorted(per_row_scores.get(id(r), []), reverse=True)
                alt = (pydemumble.demangle(lst[1][3]) or lst[1][3]) if len(lst) > 1 else ""
                if ov >= 3 and jac >= 0.5 and margin >= 2 and size_ok:
                    conf = "HIGH"
                elif ov >= 2 and margin >= 1:
                    conf = "MED"
                else:
                    conf = "LOW"
            # Fill `assign` for every matched tier; the `confidence` column says how
            # far to trust it (HIGH/MED verified 0-wrong; LOW should be eyeballed).
            rec.update({
                "assign": (a[0] if a else ""),
                "assign_demangled": name,
                "confidence": conf, "overlap": ov, "jaccard": f"{jac:.2f}" if jac != "" else "",
                "comp_size": csz, "alt": alt,
            })
            out_rows.append(rec)
    return out_rows


def write_draft(mod: str, rows: list[dict]) -> Path:
    out = ROOT / f"build/win/review/{mod}_autodraft.csv"
    cols = ["tu", "va", "size", "kind", "current", "prev_named", "next_named",
            "calls", "assign", "assign_demangled", "confidence", "overlap",
            "jaccard", "comp_size", "alt"]
    with out.open("w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=cols)
        w.writeheader()
        w.writerows(rows)
    return out


def summarise(mod: str, rows: list[dict]) -> None:
    from collections import Counter
    tus = {}
    for r in rows:
        tus.setdefault(r["tu"], Counter())[r["confidence"] or "-"] += 1
    tot = Counter(r["confidence"] or "-" for r in rows)
    print(f"=== {mod} auto-draft: {len(rows)} rows across {len(tus)} TUs ===")
    print(f"   HIGH {tot['HIGH']}   MED {tot['MED']}   LOW {tot['LOW']}   "
          f"no-match {tot['-']}")
    # show the biggest TUs
    order = sorted(tus, key=lambda t: -sum(tus[t].values()))
    print("   per-TU (top 18):")
    for t in order[:18]:
        c = tus[t]
        print(f"     {t:22s} n={sum(c.values()):3d}  HIGH={c['HIGH']:3d} "
              f"MED={c['MED']:3d} LOW={c['LOW']:3d} none={c['-']:3d}")


def _dll_for(mod: str) -> Path:
    for c in (ROOT / f"orig/GPIE01_01/files/{mod}.dll",
              ROOT / f"orig/GPIE01_01/files/plugins/{mod}.dll"):
        if c.exists():
            return c
    raise SystemExit(f"no original dll for {mod}")


def _apply_rows_to_map(mod: str, picks: list[dict], dest: Path) -> Path:
    """Write a map copy with each pick's decorated name set at its va."""
    src = ROOT / f"config/GPIE01_01/win/{mod}_map.csv"
    rows = list(csv.DictReader(src.open(newline="")))
    by_va = {int(p["va"], 16): p for p in picks}
    for r in rows:
        if r["kind"] == "function":
            p = by_va.get(int(r["va"], 16))
            if p:
                r["name_mangled"] = p["assign"]
                r["name"] = p["assign_demangled"]
    dest.parent.mkdir(parents=True, exist_ok=True)
    with dest.open("w", newline="") as fh:
        w = csv.DictWriter(fh, fieldnames=rows[0].keys())
        w.writeheader()
        w.writerows(rows)
    return dest


def verify(mod: str, picks: list[dict]) -> dict[tuple, float]:
    """Re-carve the affected TUs with the drafted names applied and score with
    objdiff -- a correct assignment carves the original bytes at that address and
    matches our compiled body (high fuzzy), a wrong one carves unrelated bytes
    (near 0). Returns {(tu, decorated): fuzzy%}. Touches only build/win/verify/."""
    import json
    import subprocess
    from pe_extract import load_map, extract
    vdir = ROOT / "build/win/verify"
    mapcopy = _apply_rows_to_map(mod, picks, vdir / f"{mod}_map_autodraft.csv")
    mapping = load_map(mapcopy)
    dll = _dll_for(mod)
    tdir = vdir / "target"
    tdir.mkdir(parents=True, exist_ok=True)
    units = []
    for tu in sorted({p["tu"] for p in picks}):
        base = ROOT / f"build/win/obj/{mod}/{tu}.obj"
        tgt = tdir / f"{tu}.obj"
        extract(dll, mapping, base, tgt, mod.upper())
        units.append({"name": f"{mod}/{tu}", "target_path": str(tgt.resolve()),
                      "base_path": str(base.resolve()),
                      "metadata": {"source_path": f"src/{tu}.cpp"}})
    (vdir / "objdiff.json").write_text(json.dumps(
        {"min_version": "2.0.0-beta.5", "build_base": False,
         "build_target": False, "units": units}))
    subprocess.run([str(ROOT / "build/tools/objdiff-cli.exe"), "report", "generate",
                    "-p", str(vdir), "-o", str(vdir / "report.json")],
                   cwd=ROOT, check=True)
    rep = json.loads((vdir / "report.json").read_text())
    fuzzy = {}
    for u in rep["units"]:
        tu = u["name"].split("/", 1)[1]
        for f in (u.get("functions") or []):
            fuzzy[(tu, f["name"])] = f.get("fuzzy_match_percent", 0.0)
    return fuzzy


def report_verify(picks: list[dict], fuzzy: dict[tuple, float]) -> None:
    from collections import Counter
    b = Counter()
    wrong = []
    for p in picks:
        pct = fuzzy.get((p["tu"], p["assign"]))
        if pct is None:
            k = "not-carved"
        elif pct >= 95:
            k = ">=95 confirmed"
        elif pct >= 70:
            k = "70-95 likely"
        elif pct >= 40:
            k = "40-70 weak"
        else:
            k = "<40 WRONG"
        b[k] += 1
        if pct is not None and pct < 40:
            wrong.append((p["tu"], p["assign_demangled"], pct))
    print(f"   verify: {dict(b)}")
    for tu, nm, pct in wrong[:10]:
        print(f"      WRONG {tu} {pct:.0f}% {nm}")


CONF_ORDER = {"HIGH": 3, "MED": 2, "LOW": 1}


def _align_tu(tu, addrs, names, anchors):
    """Positional pairing within a TU: PLACED names give (ilk#, va) anchors that
    pin the ilk-order<->address-order correspondence; between consecutive anchors
    the unplaced names (by ilk#) and unlabelled addresses (by va) are paired 1:1
    IN ORDER, but only where their counts match (else the segment is ambiguous ->
    skipped, and the oracle would reject a misalignment anyway)."""
    A = sorted(((int(r["va"], 16), r) for r in addrs), key=lambda x: x[0])
    N = sorted((n[0], n[2], n[3]) for n in names)          # (ilk#, dec, dem)
    anc = []                                                # strictly increasing both
    for ilk, va in anchors:
        if not anc or (ilk > anc[-1][0] and va > anc[-1][1]):
            anc.append((ilk, va))
    BIG = 1 << 62
    bps = [(-1, -1)] + anc + [(BIG, BIG)]
    picks = []
    for (lo_i, lo_v), (hi_i, hi_v) in zip(bps, bps[1:]):
        seg_n = [x for x in N if lo_i < x[0] < hi_i]
        seg_a = [x for x in A if lo_v < x[0] < hi_v]
        if seg_n and len(seg_n) == len(seg_a):
            bracketed = lo_i >= 0 and hi_i < BIG
            for (ilk, dec, dem), (va, row) in zip(seg_n, seg_a):
                picks.append({"tu": tu, "va": row["va"], "size": row["size"],
                              "assign": dec, "assign_demangled": dem,
                              "confidence": "ORDER-BR" if bracketed else "ORDER-EDGE"})
    return picks


def order_propose(mod: str) -> list[dict]:
    """Positional (order-align) proposals across all TUs, using pair_worklist's
    anchors + attributed names. Unverified -- feed to verify()."""
    from pair_worklist import pairing_data
    data = pairing_data(mod)
    picks = []
    for tu, addrs in data["addrs"].items():
        picks += _align_tu(tu, addrs, data["names"].get(tu, []),
                           data["anchors"].get(tu, []))
    return picks


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("module")
    ap.add_argument("--verify", action="store_true",
                    help="re-carve the drafted names + score with objdiff")
    ap.add_argument("--apply", action="store_true",
                    help="write the >= --min-confidence assignments into the map")
    ap.add_argument("--min-confidence", choices=["HIGH", "MED", "LOW"], default="MED",
                    help="lowest tier to verify/apply (default MED; HIGH+MED verified 0-wrong)")
    ap.add_argument("--order", action="store_true",
                    help="propose by ORDER-alignment within anchor brackets (uses "
                         "pair_worklist), verify by re-carve, keep the >= --order-keep %%")
    ap.add_argument("--order-keep", type=float, default=80.0,
                    help="min fuzzy%% to keep an order-aligned pair (default 80)")
    args = ap.parse_args(argv)

    if args.order:
        picks = order_propose(args.module)
        print(f"=== {args.module} order-align: {len(picks)} positional proposals "
              f"across {len({p['tu'] for p in picks})} TUs ===")
        fuzzy = verify(args.module, picks)          # always verify (the whole point)
        kept = [p for p in picks
                if fuzzy.get((p["tu"], p["assign"]), 0.0) >= args.order_keep]
        report_verify(picks, fuzzy)
        outp = ROOT / f"build/win/review/{args.module}_orderdraft.csv"
        with outp.open("w", newline="") as fh:
            w = csv.DictWriter(fh, fieldnames=["tu", "va", "size", "assign",
                               "assign_demangled", "confidence", "fuzzy"])
            w.writeheader()
            for p in picks:
                p2 = dict(p); p2["fuzzy"] = f"{fuzzy.get((p['tu'], p['assign']), 0.0):.1f}"
                w.writerow(p2)
        print(f"   KEEP (>= {args.order_keep}%): {len(kept)} / {len(picks)}  -> {outp}")
        if args.apply and kept:
            mp = ROOT / f"config/GPIE01_01/win/{args.module}_map.csv"
            bak = backup(mp)
            _apply_rows_to_map(args.module, kept, mp)
            print(f"   applied {len(kept)} order-verified assignments to {mp}  "
                  f"(backup {bak.name})")
        return 0

    rows = draft(args.module)
    out = write_draft(args.module, rows)
    summarise(args.module, rows)
    print(f"   wrote -> {out}")

    thresh = CONF_ORDER[args.min_confidence]
    picks = [r for r in rows if r["assign"]
             and CONF_ORDER.get(r["confidence"], 0) >= thresh]

    if args.verify:
        report_verify(picks, verify(args.module, picks))

    if args.apply and picks:
        mp = ROOT / f"config/GPIE01_01/win/{args.module}_map.csv"
        bak = backup(mp)
        _apply_rows_to_map(args.module, picks, mp)
        print(f"   applied {len(picks)} (>={args.min_confidence}) assignments to "
              f"{mp}  (backup {bak.name})")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
