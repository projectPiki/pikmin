#!/usr/bin/env python3
###
# reccmp wrapper for the Windows build's `compare` target.
#
# Sets PYTHONIOENCODING=utf-8 (reccmp prints a U+2728 sparkle on a 100% match,
# which crashes the cp1252 Windows console) and runs reccmp-reccmp in --paths mode
# against the shipped original. Kept as a tiny Python helper (not an inline ninja
# command) so it is identical on Windows and Linux/macOS.
#
# Usage: python win_compare.py <orig.dll> <recomp.dll> <recomp.pdb> <src-root> [extra reccmp args...]
###

import os
import subprocess
import sys


def main():
    if len(sys.argv) < 5:
        print("usage: win_compare.py <orig> <recomp> <pdb> <src-root> [extra...]",
              file=sys.stderr)
        return 2
    orig, recomp, pdb, src = sys.argv[1:5]
    extra = sys.argv[5:]
    env = dict(os.environ, PYTHONIOENCODING="utf-8")
    return subprocess.call(
        ["reccmp-reccmp", "--paths", orig, recomp, pdb, src, *extra], env=env)


if __name__ == "__main__":
    sys.exit(main())
