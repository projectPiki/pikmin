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
    },
    {
        "name": "plugPiki",
        "src_globs": [
            "src/plugPikiColin/*.cpp", "src/plugPikiKando/*.cpp",
            "src/plugPikiNakata/*.cpp", "src/plugPikiNishimura/*.cpp",
            "src/plugPikiOgawa/*.cpp", "src/plugPikiYamashita/*.cpp",
        ],
        "dll_rel": "files/plugins/plugPiki.dll",
        "link": False,
        "cflags": [],
        "libs": [],
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
                     f"--base $in --out $out"),
            description="EXTRACT $out",
        )
        n.newline()

        all_objs = []
        all_targets = []
        objdiff_units = []
        for m in modules:
            name = m["name"]
            # objdiff targets are carved from the original DLL keyed by the map;
            # only wire them when both are present (map is tracked, DLL is a local
            # git-ignored original).
            can_objdiff = m["map"].exists() and m["orig"].exists()

            n.comment(f"==== module {name} ({len(m['tus'])} TUs) ====")
            mflags = " ".join(m.get("cflags", []))
            objs = []
            targets = []
            for tu in m["tus"]:
                obj = m["obj_dir"] / (tu.stem + ".obj")
                n.build(str(obj), "cc", str(tu), implicit=[str(win_cc)],
                        variables={"mflags": mflags})
                objs.append(str(obj))
                if can_objdiff:
                    tgt = m["target_dir"] / (tu.stem + ".obj")
                    n.build(str(tgt), "extract", str(obj),
                            implicit=[str(pe_extract), str(m["map"]), str(m["orig"])],
                            variables={"dll": str(m["orig"]), "map": str(m["map"])})
                    targets.append(str(tgt))
                    objdiff_units.append({
                        "name": f"{name}/{tu.stem}",
                        "target_path": str(tgt).replace("\\", "/"),
                        "base_path": str(obj).replace("\\", "/"),
                        "metadata": {"source_path": tu.as_posix()},
                    })
            n.newline()

            # Per-module compile alias: `ninja ... plugPiki` builds that module.
            n.build(name, "phony", objs)
            all_objs += objs
            all_targets += targets

            if m["link"]:
                ldflags = [
                    "/nologo", "/dll", "/debug", "/incremental:yes",
                    "/subsystem:windows",
                    f"/def:{m['definition']}", f"/libpath:{vc6 / 'lib'}",
                ]
                if args.force:
                    ldflags.append("/force")
                n.build(str(m["dll"]), "link", objs,
                        implicit=[str(m["definition"])],
                        variables={"ldflags": " ".join(ldflags),
                                   "libs": " ".join(m["libs"])})
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
                          str(pe_extract), str(Path("tools/ninja_syntax.py"))])
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
        print(f"  ninja -f {out_path} target          # carve objdiff target objects")
        print(f"wrote {objdiff_path} ({len(objdiff_units)} units) -- open the repo in objdiff")
        print("  (this replaces the DOL objdiff.json; re-run configure.py to switch back)")
    else:
        print("objdiff: skipped (no module has both its map CSV and original DLL)")


if __name__ == "__main__":
    main()
