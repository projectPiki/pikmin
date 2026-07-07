#!/usr/bin/env python3
###
# Generates the ninja build for the Windows (VC6 / PE32) decomp target.
#
# This is the Windows counterpart to configure.py, kept deliberately separate from
# the PPC-only tools/project.py pipeline. It compiles the game's modules with the
# vendored VC6 toolchain in tools/vc6, can link a module's DLL (+PDB), carves the
# objdiff "target" objects out of the shipped originals, and can run reccmp.
#
# Modules (see the MODULES table below):
#   sysCore  -- src/sysCommon + src/sysDolphin -> sysCore.dll (links; reccmp-able)
#   plugPiki -- the six src/plugPiki* author dirs -> plugPiki.dll (compile+objdiff
#               only; a real link needs sysCore.lib and is deferred)
#
# Cross-platform by design: cl.exe/link.exe are PE32 tools, but Python + ninja run
# everywhere and the compiler is auto-wrapped with wine (or --wrapper wibo) off
# Windows, so contributors do not need Windows or PowerShell to build.
#
# Usage:
#   python3 configure_win.py
#   ninja -f build/win/build.ninja                 # compile every TU (all modules)
#   ninja -f build/win/build.ninja plugPiki        # compile just one module
#   ninja -f build/win/build.ninja sysCore.link    # link a module's DLL
#   ninja -f build/win/build.ninja sysCore.compare # reccmp vs the original
#   ninja -f build/win/build.ninja target          # carve every objdiff target obj
#   ninja -f build/win/build.ninja -k 0            # keep going, list every failure
###

import argparse
import json
import os
import sys
from pathlib import Path

sys.path.append(str(Path(__file__).parent / "tools"))
import ninja_syntax  # noqa: E402


# --- Module table -----------------------------------------------------------
# Each module is a DLL built from one or more source dirs, matched against a
# shipped original. `dll_rel` is the original's path under orig/<version>/.
# `link` modules get link + reccmp-compare edges; the others are compile+objdiff
# only (plugPiki would need sysCore.lib to link, which is deferred).
MODULES = [
    {
        "name": "sysCore",
        "src_globs": ["src/sysCommon/*.cpp", "src/sysDolphin/*.cpp"],
        "dll_rel": "files/sysCore.dll",
        "link": True,
        # sysCore owns the SYSCORE_API exports, so it compiles them as
        # __declspec(dllexport); every other module sees the default dllimport.
        "cflags": ["/D", "SYSCORE_EXPORTS"],
        "libs": ["msvcrtd.lib", "kernel32.lib", "user32.lib", "gdi32.lib",
                 "opengl32.lib", "glu32.lib", "wsock32.lib", "comdlg32.lib",
                 "advapi32.lib"],
        # Other modules whose import lib this one links against (for its cross-DLL
        # imports). Their exports are supplied at link, so the clean-link filler
        # pass must not stub them (would collide, LNK2005) -- fed via --provided.
        "needs": [],
    },
    {
        "name": "plugPiki",
        "src_globs": [
            "src/plugPikiColin/*.cpp", "src/plugPikiKando/*.cpp",
            "src/plugPikiNakata/*.cpp", "src/plugPikiNishimura/*.cpp",
            "src/plugPikiOgawa/*.cpp", "src/plugPikiYamashita/*.cpp",
        ],
        "dll_rel": "files/plugins/plugPiki.dll",
        # Links now (workstream b1): it imports sysCore via __declspec(dllimport),
        # resolved from sysCore's import lib; the clean-link filler pass supplies
        # the rest. Its ~341 sysCore imports must not be stubbed -> provided list.
        "link": True,
        "cflags": [],
        "libs": ["msvcrtd.lib", "kernel32.lib", "user32.lib", "gdi32.lib",
                 "opengl32.lib", "glu32.lib"],
        "needs": ["sysCore"],
    },
]


def is_windows() -> bool:
    return os.name == "nt"


def write_objdiff_json(root: Path, build_dir: Path, units: list[dict]) -> Path:
    """Emit the root objdiff.json spanning every configured module.

    objdiff requires its config at the project root named exactly objdiff.json,
    so this shares that slot with the PPC/DOL config emitted by configure.py --
    re-run configure.py to switch objdiff back to the GameCube build. Each unit
    pairs our compiled base .obj with the carved target .obj; objdiff rebuilds
    both on demand via `ninja -f build/win/build.ninja <path>`.

    For modules with an inline-owner map (build/win/inline_owner_<mod>.csv) the
    base/target here are the DEDUPED objects (redundant inline COMDATs stripped so
    each inline shows once, in its owner unit -- see tools/win/dedup_comdats.py);
    other modules use their raw objects. The raw, un-deduplicated per-unit report
    that inline_owner.py/ilk_reconcile.py/win_report.py consume comes from the
    separate full config below, not this one.
    """
    ninja = (build_dir / "build.ninja").as_posix()
    config = {
        "min_version": "2.0.0-beta.5",
        "custom_make": "ninja",
        "custom_args": ["-f", ninja],
        "build_base": True,
        "build_target": True,
        "watch_patterns": ["*.cpp", "*.h", "*.hpp", "*.inc", "*.py",
                           "*.def", "*.csv"],
        "units": units,
    }
    out = root / "objdiff.json"
    out.write_text(json.dumps(config, indent=2) + "\n", encoding="utf-8")
    return out


def write_full_config(build_dir: Path, units: list[dict]) -> Path:
    """Emit build/win/full/objdiff.json -- the RAW (un-deduplicated) per-unit view.

    inline_owner.py needs to see every emitter of each inline, and ilk_reconcile.py
    needs faithful per-unit symbol emission, so both (via win_report.py) score the
    raw obj/target tree, never the deduped GUI config. Its project dir is not the
    repo root, so unit paths are absolute (machine-local; this file lives in the
    git-ignored build dir and is regenerated by configure_win.py). Read with
    `objdiff-cli report generate -p build/win/full`. Building is left to the raw
    `target` phony, so no custom_make here.
    """
    config = {
        "min_version": "2.0.0-beta.5",
        "build_base": False,
        "build_target": False,
        "units": units,
    }
    out = build_dir / "full" / "objdiff.json"
    out.parent.mkdir(parents=True, exist_ok=True)
    out.write_text(json.dumps(config, indent=2) + "\n", encoding="utf-8")
    return out


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("--version", type=str.upper, default="GPIE01_01",
                    help="game version to build (default: GPIE01_01)")
    ap.add_argument("--build-dir", type=Path, default=Path("build/win"),
                    metavar="DIR", help="build directory (default: build/win)")
    ap.add_argument("--vc6", type=Path, default=Path("tools/vc6"),
                    metavar="DIR", help="VC6 toolchain root (default: tools/vc6)")
    ap.add_argument("--develop", action="store_true",
                    help="define DEVELOP (PRINT/ERROR become real calls)")
    ap.add_argument("--force", action="store_true",
                    help="link with /force (emit the DLL despite not-yet-decompiled "
                         "externals, for a whole-module reccmp baseline)")
    if not is_windows():
        ap.add_argument("--wrapper", type=Path, default=None, metavar="BIN",
                        help="PE runner for cl/link (default: wine; e.g. path to wibo)")
    args = ap.parse_args()

    root = Path(__file__).parent.resolve()
    build_dir = args.build_dir
    obj_root = build_dir / "obj"
    target_root = build_dir / "target"
    vc6 = args.vc6
    cl = vc6 / "bin" / "cl.exe"
    link = vc6 / "bin" / "link.exe"

    # --- wine/wibo wrapper (off Windows), mirroring configure.py's convention ----
    wrapper = None if is_windows() else (args.wrapper or Path("wine"))
    wrapper_cmd = f"{wrapper} " if wrapper else ""

    # --- Confirmed original build flags (see the win-decomp-facts memory) --------
    # /ZI (Edit&Continue, not /Zi) + /GZ reproduce the padded fixed frame and the
    # push ebx/esi/edi + rep-stosd prologue. /Zm600 raises the compiler heap for
    # bigfont_usa.h's 508 KB array (C1076); codegen-neutral. /I include ONLY of the
    # project headers -- include/stl's PPC/MSL replacements must not shadow VC6's
    # system headers, which we reach via /I tools/vc6/include (so no INCLUDE env
    # is needed and the build stays self-contained under wine).
    # /wd4003 silences the empty-macro-argument warning C4003 that
    # TERNARY_BUILD_MATCHING(, const)-style macros (immut/NRef) emit under VC6's
    # preprocessor -- warning-only, so codegen-neutral. BUILD_MATCHING is defined
    # because the original was built with it (per project guidance): it selects the
    # "matching" arm of TERNARY_BUILD_MATCHING, making immut -> (nothing) and
    # NRef -> &, reproducing the shipped code's const-incorrect rvalue binding
    # (which VC6 permits by default -- there is no /Zc:referenceBinding in VC6).
    cflags = [
        "/nologo", "/c", "/MDd", "/Od", "/GX", "/GR-", "/GZ", "/ZI", "/W3", "/Zm600",
        "/wd4003",
        "/D", "WIN32", "/D", "_DEBUG", "/D", "_WINDOWS", "/D", "_USRDLL", "/D", "_MBCS",
        "/D", "BUILD_MATCHING", "/D", "PIKI_USE_JAUDIO=0", "/D", "PIKI_USE_DGX=0",
        "/D", f"VERSION_{args.version}",
        "/I", "include", "/I", str(vc6 / "include"),
    ]
    if args.develop:
        cflags += ["/D", "DEVELOP"]

    win_cc = Path("tools/win/win_cc.py")
    win_compare = Path("tools/win/win_compare.py")
    pe_extract = Path("tools/win/pe_extract.py")
    dedup_comdats = Path("tools/win/dedup_comdats.py")
    undef_survey = Path("tools/win/undef_survey.py")
    gen_link_fillers = Path("tools/win/gen_link_fillers.py")
    gen_placeholders = Path("tools/win/gen_placeholders.py")
    python = sys.executable or "python3"

    # --- Resolve each module's TUs and asset paths ------------------------------
    modules = []
    for spec in MODULES:
        tus = []
        for pat in spec["src_globs"]:
            tus += sorted(root.glob(pat))
        tus = [t.relative_to(root) for t in tus]
        if not tus:
            print(f"configure_win: warning: module {spec['name']} matched no .cpp",
                  file=sys.stderr)
            continue
        name = spec["name"]
        modules.append({
            **spec,
            "tus": tus,
            "obj_dir": obj_root / name,
            "target_dir": target_root / name,
            "obj_dedup_dir": build_dir / "obj_dedup" / name,
            "target_dedup_dir": build_dir / "target_dedup" / name,
            "owner_csv": build_dir / f"inline_owner_{name}.csv",
            "undef_csv": build_dir / f"undef_{name}.csv",
            "stub_obj": build_dir / "stubs" / f"{name}_stubs.obj",
            "carve_names": build_dir / "stubs" / f"{name}_carve.txt",
            "definition": Path(f"config/{args.version}/win/{name}.def"),
            "orig": Path(f"orig/{args.version}/{spec['dll_rel']}"),
            "map": Path(f"config/{args.version}/win/{name}_map.csv"),
            "dll": build_dir / f"{name}.dll",
            "pdb": build_dir / f"{name}.pdb",
        })

    if not modules:
        sys.exit("configure_win: no modules matched any source files")

    # --- Emit build.ninja -------------------------------------------------------
    out_path = build_dir / "build.ninja"
    out_path.parent.mkdir(parents=True, exist_ok=True)
    with out_path.open("w", encoding="utf-8") as f:
        n = ninja_syntax.Writer(f)
        n.comment("Auto-generated by configure_win.py -- do not edit. Re-run it to")
        n.comment("pick up added/removed source files. See tools/win/README.md.")
        n.newline()
        n.variable("ninja_required_version", "1.7")  # for deps=gcc
        n.variable("builddir", str(build_dir))        # .ninja_log/.ninja_deps home
        n.variable("python", python)
        n.newline()
        n.variable("cflags", " ".join(cflags))
        n.newline()

        # Compile: cl has no depfile support, so win_cc.py runs cl then scans
        # #includes into $out.d, which ninja reads via deps=gcc. Per-TU /Fd PDB
        # (required by /ZI; keeps runs independent).
        n.comment("Compile (VC6 cl.exe) + Python-scanned header deps")
        n.rule(
            name="cc",
            command=(f"$python {win_cc} --out $out --src $in -I include -- "
                     f"{wrapper_cmd}{cl} $cflags $mflags /Fo$out /Fd$out.pdb $in"),
            description="CC $out",
            depfile="$out.d",
            deps="gcc",
        )
        n.newline()

        # Link is per-module: ldflags/libs are overridden on each link edge.
        n.comment("Link a module DLL (per-edge $ldflags / $libs)")
        n.rule(
            name="link",
            command=f"{wrapper_cmd}{link} $ldflags /out:$out @$out.rsp $libs",
            description="LINK $out",
            rspfile="$out.rsp",
            rspfile_content="$in_newline",
        )
        n.newline()

        n.comment("reccmp compare vs the original (per-edge $orig/$dll/$pdb)")
        n.rule(
            name="compare",
            command=f"$python {win_compare} $orig $dll $pdb src",
            description="COMPARE $dll",
            pool="console",
        )
        n.newline()

        # Carve the objdiff "target" object for a TU out of the original DLL:
        # the functions the base $in defines, copied from the DLL with their
        # relocations reconstructed (see tools/win/pe_extract.py). $dll/$map are
        # overridden per edge.
        n.comment("objdiff target objects carved from the original DLL")
        n.rule(
            name="extract",
            command=(f"$python {pe_extract} --dll $dll --map $map "
                     f"--base $in --out $out --extra $extra"),
            description="EXTRACT $out",
        )
        n.newline()

        # Per-TU UNLABELLED addresses -> FUN_<addr> placeholder target symbols, so
        # objdiff's manual "choose target symbol" can map an unmatched base function
        # onto the original's real (still-unnamed) function. Added only to the DEDUPED
        # (GUI) targets below; the raw targets stay placeholder-free so the tooling
        # reports (win_report / ilk_reconcile / inline_owner) are unaffected.
        n.comment("Placeholder target symbols for objdiff manual mapping")
        n.rule(
            name="placeholders",
            command=f"$python {gen_placeholders} $module --out $outdir",
            description="PLACEHOLDERS $module",
        )
        n.newline()

        # Strip every redundant inline COMDAT the object does not own (per the
        # inline-owner map) so objdiff shows each inline once. pe_extract then
        # carves the deduped base, so base and target stay paired automatically.
        n.comment("Dedup: strip inline COMDATs this object does not own")
        n.rule(
            name="dedup",
            command=(f"$python {dedup_comdats} $module --owner $owner "
                     f"--obj $in --out $out"),
            description="DEDUP $out",
        )
        n.newline()

        # Workstream (b1): the symbols a clean (non-/FORCE) link needs. `undef`
        # surveys every unresolved external across a module's objects; `fillers`
        # turns that + the .def export surface into one synthetic stub object
        # ($out) so the DLL links without /FORCE. See tools/win/gen_link_fillers.py.
        n.comment("Clean-link fillers: survey unresolved externals, then stub them")
        n.rule(
            name="undef",
            command=f"$python {undef_survey} $module",
            description="UNDEF $module",
        )
        n.newline()
        n.rule(
            name="fillers",
            command=(f"$python {gen_link_fillers} $module --undef $undef "
                     f"--def $def --objs-dir $objs_dir --stub-obj $out "
                     f"--carve-names $carve $provided"),
            description="FILLERS $out",
        )
        n.newline()

        # Preserve any objdiff GUI symbol_mappings (manual base<->target maps the
        # user made in the "choose target symbol" UI) across this regeneration --
        # they live in the root objdiff.json we are about to overwrite.
        prev_mappings: dict[str, dict] = {}
        existing = root / "objdiff.json"
        if existing.exists():
            try:
                for u in json.loads(existing.read_text()).get("units", []):
                    if u.get("symbol_mappings"):
                        prev_mappings[u["name"]] = u["symbol_mappings"]
            except (ValueError, OSError):
                pass

        all_objs = []
        all_targets = []
        dedup_targets = []
        objdiff_units = []   # root GUI config (deduped where a map exists)
        full_units = []      # build/win/full config (raw, absolute paths)
        for m in modules:
            name = m["name"]
            # objdiff targets are carved from the original DLL keyed by the map;
            # only wire them when both are present (map is tracked, DLL is a local
            # git-ignored original).
            can_objdiff = m["map"].exists() and m["orig"].exists()
            # dedup a module only once its byte-faithful inline-owner map exists
            # (generate it with tools/win/inline_owner.py); otherwise fall back to
            # the raw objects in the GUI config.
            dedup_on = can_objdiff and m["owner_csv"].exists()
            # placeholder target symbols need the .ilk (for byte-faithful TU) too.
            ilk = m["orig"].with_suffix(".ilk")
            can_ph = can_objdiff and ilk.exists()
            ph_dir = build_dir / "placeholders" / name
            ph_stamp = build_dir / "placeholders" / f"{name}.stamp"

            n.comment(f"==== module {name} ({len(m['tus'])} TUs) ====")
            mflags = " ".join(m.get("cflags", []))
            extract_imp = [str(pe_extract), str(m["map"]), str(m["orig"])]
            # raw edges get a never-created sentinel for $extra (pe_extract skips a
            # missing --extra file); deduped edges override it with the TU's CSV.
            none_csv = build_dir / "placeholders" / "none.csv"
            extract_vars = {"dll": str(m["orig"]), "map": str(m["map"]),
                            "extra": str(none_csv)}
            if can_ph:
                n.build(str(ph_stamp), "placeholders", str(m["map"]),
                        implicit=[str(gen_placeholders), str(ilk)],
                        variables={"module": name, "outdir": str(ph_dir)})
            objs = []
            targets = []
            for tu in m["tus"]:
                obj = m["obj_dir"] / (tu.stem + ".obj")
                n.build(str(obj), "cc", str(tu), implicit=[str(win_cc)],
                        variables={"mflags": mflags})
                objs.append(str(obj))
                if not can_objdiff:
                    continue
                # Raw target -> the un-deduplicated full report (tooling).
                tgt = m["target_dir"] / (tu.stem + ".obj")
                n.build(str(tgt), "extract", str(obj), implicit=extract_imp,
                        variables=extract_vars)
                targets.append(str(tgt))
                full_units.append({
                    "name": f"{name}/{tu.stem}",
                    "target_path": str((root / tgt).resolve()),
                    "base_path": str((root / obj).resolve()),
                    "metadata": {"source_path": tu.as_posix()},
                })

                if dedup_on:
                    # Deduped base (inline COMDATs this unit doesn't own removed),
                    # then carve its target from that deduped base.
                    dobj = m["obj_dedup_dir"] / (tu.stem + ".obj")
                    n.build(str(dobj), "dedup", str(obj),
                            implicit=[str(dedup_comdats), str(m["owner_csv"])],
                            variables={"module": name, "owner": str(m["owner_csv"])})
                    dtgt = m["target_dedup_dir"] / (tu.stem + ".obj")
                    # the GUI (deduped) target gets the TU's FUN_<addr> placeholders
                    # for objdiff manual mapping; order-only on the stamp so they are
                    # generated first (and regenerated when the map changes).
                    dvars = extract_vars
                    dorder = None
                    if can_ph:
                        dvars = {**extract_vars,
                                 "extra": str(ph_dir / (tu.stem.lower() + ".csv"))}
                        dorder = [str(ph_stamp)]
                    n.build(str(dtgt), "extract", str(dobj), implicit=extract_imp,
                            order_only=dorder, variables=dvars)
                    dedup_targets.append(str(dtgt))
                    base_p, tgt_p = str(dobj), str(dtgt)
                else:
                    base_p, tgt_p = str(obj), str(tgt)
                gui_unit = {
                    "name": f"{name}/{tu.stem}",
                    "target_path": tgt_p.replace("\\", "/"),
                    "base_path": base_p.replace("\\", "/"),
                    "metadata": {"source_path": tu.as_posix()},
                }
                if gui_unit["name"] in prev_mappings:
                    gui_unit["symbol_mappings"] = prev_mappings[gui_unit["name"]]
                objdiff_units.append(gui_unit)
            n.newline()

            # Per-module compile alias: `ninja ... plugPiki` builds that module.
            n.build(name, "phony", objs)
            all_objs += objs
            all_targets += targets

            if m["link"]:
                # Cross-module imports: link against each needed module's import lib
                # (a side output of its link) and feed that module's exports to the
                # filler pass as --provided so they are NOT stubbed (LNK2005).
                need_libs = [build_dir / f"{nm}.lib" for nm in m.get("needs", [])]
                provided_csvs = [Path(f"config/{args.version}/win/{nm}_symbols.csv")
                                 for nm in m.get("needs", [])]
                provided_arg = " ".join(f"--provided {c}" for c in provided_csvs)

                # Clean-link fillers (b1): survey unresolved externals -> stub obj.
                # The stub obj lets the DLL link WITHOUT /FORCE (every referenced or
                # exported-but-undefined symbol gets a stub); it is a link input but
                # not part of the `<module>` compile phony (it is not a TU).
                n.build(str(m["undef_csv"]), "undef", objs,
                        implicit=[str(undef_survey), str(m["map"])],
                        variables={"module": name})
                n.build(str(m["stub_obj"]), "fillers",
                        [str(m["undef_csv"]), str(m["definition"])] + objs,
                        implicit=[str(gen_link_fillers), str(pe_extract)]
                        + [str(c) for c in provided_csvs],
                        variables={"module": name, "undef": str(m["undef_csv"]),
                                   "def": str(m["definition"]),
                                   "objs_dir": str(m["obj_dir"]),
                                   "carve": str(m["carve_names"]),
                                   "provided": provided_arg})

                ldflags = [
                    "/nologo", "/dll", "/debug", "/incremental:yes",
                    "/subsystem:windows",
                    f"/def:{m['definition']}", f"/libpath:{vc6 / 'lib'}",
                ]
                if args.force:
                    ldflags.append("/force")  # escape hatch; the stubs make it needless
                # A DLL link also emits <name>.lib/.exp; declaring the .lib as an
                # implicit output lets a dependent module order against it. Import
                # libs go in $libs (not the object rsp) + implicit for ordering.
                n.build(str(m["dll"]), "link", objs + [str(m["stub_obj"])],
                        implicit=[str(m["definition"])] + [str(l) for l in need_libs],
                        implicit_outputs=[str(build_dir / f"{name}.lib")],
                        variables={"ldflags": " ".join(ldflags),
                                   "libs": " ".join(m["libs"] + [str(l) for l in need_libs])})
                n.build(f"{name}.link", "phony", str(m["dll"]))
                n.build(f"{name}.compare", "compare",
                        implicit=[str(m["dll"]), str(m["pdb"]), str(win_compare)],
                        variables={"orig": str(m["orig"]), "dll": str(m["dll"]),
                                   "pdb": str(m["pdb"])})
            n.newline()

        # Aggregate phonies across all modules.
        if all_targets:
            n.build("target", "phony", all_targets)
            n.newline()
        # `dedup` builds the decluttered GUI tree (deduped bases + their targets).
        if dedup_targets:
            n.build("dedup", "phony", dedup_targets)
            n.newline()
        # `objdiff` = the one command that refreshes EVERYTHING objdiff reads: the raw
        # tree win_report/inline_owner/ilk_reconcile consume AND the deduped GUI tree.
        # Rebuilding only `target` (raw) after a pe_extract/map change leaves the GUI's
        # deduped carves stale -- the exact trap that hid a fixed `_Print` pairing. Use
        # this so the two trees never drift out of sync.
        if all_targets or dedup_targets:
            n.build("objdiff", "phony", all_targets + dedup_targets)
            n.newline()

        # Regenerate build.ninja when this script or its inputs change.
        n.comment("Re-run configure_win.py when it or its helpers change")
        cfg_cmd = f"$python {Path(__file__).name}"
        if args.develop:
            cfg_cmd += " --develop"
        if args.force:
            cfg_cmd += " --force"
        if wrapper:
            cfg_cmd += f" --wrapper {wrapper}"
        n.rule(name="configure", command=cfg_cmd, generator=True,
               description="configure_win.py")
        n.build(str(out_path), "configure",
                implicit=[Path(__file__).name, str(win_cc), str(win_compare),
                          str(pe_extract), str(dedup_comdats), str(undef_survey),
                          str(gen_link_fillers), str(gen_placeholders),
                          str(Path("tools/ninja_syntax.py"))])
        n.newline()

        n.default(all_objs)

    total = sum(len(m["tus"]) for m in modules)
    print(f"wrote {out_path} ({len(modules)} modules, {total} TUs)")
    for m in modules:
        print(f"  {m['name']}: {len(m['tus'])} TUs"
              + ("  (links + reccmp)" if m["link"] else "  (compile + objdiff only)"))
    print(f"  ninja -f {out_path}                 # compile all")
    print(f"  ninja -f {out_path} <module>        # compile one module")
    print(f"  ninja -f {out_path} <module>.link   # link that DLL")

    if objdiff_units:
        objdiff_path = write_objdiff_json(root, build_dir, objdiff_units)
        n_dedup = len(dedup_targets)
        print(f"  ninja -f {out_path} target          # carve raw objdiff targets (full report)")
        if n_dedup:
            print(f"  ninja -f {out_path} dedup           # build the decluttered (deduped) GUI tree")
            print(f"  ninja -f {out_path} objdiff         # BOTH trees (use this so raw + GUI stay in sync)")
        print(f"wrote {objdiff_path} ({len(objdiff_units)} units"
              + (f", {n_dedup} deduped" if n_dedup else "") + ") -- open the repo in objdiff")
        print("  (this replaces the DOL objdiff.json; re-run configure.py to switch back)")
        full_path = write_full_config(build_dir, full_units)
        print(f"wrote {full_path} ({len(full_units)} raw units) -- the un-deduplicated "
              "report source (win_report.py / inline_owner.py)")
    else:
        print("objdiff: skipped (no module has both its map CSV and original DLL)")


if __name__ == "__main__":
    main()
