#!/usr/bin/env python3
###
# Compile driver for the VC6 (MSVC 6.0) Windows build.
#
# VC6's cl.exe has neither /showIncludes nor -MMD, so ninja cannot get header
# dependencies from the compiler the way the DOL/MWCC build does. This wrapper
# runs the given cl command, then writes a gcc-style depfile ($out.d) by scanning
# the translation unit's #include graph (project headers only -- VC6 system headers
# under tools/vc6/include are treated as fixed and skipped). ninja consumes the
# depfile via `deps = gcc`, giving precise incremental rebuilds.
#
# Pure Python and path-native, so it runs on Windows and under wine/wibo on
# Linux/macOS without the wine-path rewriting that transform_dep.py does for MWCC.
#
# Usage (from ninja):
#   python win_cc.py --out <obj> --src <cpp> [-I <dir> ...] -- <compiler cmd...>
###

import argparse
import os
import re
import subprocess
import sys
from pathlib import Path

# Matches `#include <foo>` / `#include "foo"` at the start of a (logical) line.
INCLUDE_RE = re.compile(rb'^[ \t]*#[ \t]*include[ \t]*[<"]([^>"]+)[>"]', re.MULTILINE)


def scan_includes(src: Path, inc_dirs):
    """Transitively collect the project headers #included from `src`.

    Resolves each include against the including file's own directory and the -I
    roots, in that order. Anything that resolves nowhere is a system header
    (VC6's own) and is skipped -- those never change during the decomp."""
    seen = set()
    deps = []
    stack = [src]
    while stack:
        f = stack.pop()
        try:
            key = f.resolve()
        except OSError:
            continue
        if key in seen or not f.is_file():
            continue
        seen.add(key)
        if f != src:
            deps.append(f)
        try:
            data = f.read_bytes()
        except OSError:
            continue
        for m in INCLUDE_RE.finditer(data):
            inc = m.group(1).decode("utf-8", "replace").replace("\\", "/")
            for root in (f.parent, *inc_dirs):
                cand = root / inc
                if cand.is_file():
                    stack.append(cand)
                    break
            # else: unresolved => VC6 system header, skip
    return deps


def write_depfile(dep_path: Path, target: str, deps):
    def esc(p):
        return str(p).replace("\\", "/").replace(" ", "\\ ")

    lines = [f"{esc(target)}:"] + [f"  {esc(d)}" for d in deps]
    dep_path.parent.mkdir(parents=True, exist_ok=True)
    dep_path.write_text(" \\\n".join(lines) + "\n", encoding="utf-8")


def main():
    argv = sys.argv[1:]
    if "--" in argv:
        i = argv.index("--")
        pre, cmd = argv[:i], argv[i + 1:]
    else:
        pre, cmd = argv, []

    ap = argparse.ArgumentParser(description="VC6 compile-and-depfile driver")
    ap.add_argument("--out", required=True, help="output object (depfile target)")
    ap.add_argument("--src", required=True, help="source translation unit")
    ap.add_argument("--dep", help="depfile path (default: <out>.d)")
    ap.add_argument("-I", dest="inc", action="append", default=[],
                    help="project include root (repeatable)")
    args = ap.parse_args(pre)

    if not cmd:
        ap.error("no compiler command given after --")

    # Ensure the object's directory exists (cl won't create it).
    Path(args.out).parent.mkdir(parents=True, exist_ok=True)

    rc = subprocess.call(cmd)

    # Best-effort deps even on failure, so ninja is correct on the next run.
    dep_path = Path(args.dep) if args.dep else Path(args.out + ".d")
    inc_dirs = [Path(p) for p in args.inc]
    try:
        deps = scan_includes(Path(args.src), inc_dirs)
        write_depfile(dep_path, args.out, deps)
    except OSError as e:
        print(f"win_cc: warning: could not write depfile {dep_path}: {e}",
              file=sys.stderr)

    return rc


if __name__ == "__main__":
    sys.exit(main())
