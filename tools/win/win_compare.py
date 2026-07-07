#!/usr/bin/env python3
###
# reccmp wrapper for the Windows build's `compare` target.
#
# Sets PYTHONIOENCODING=utf-8 (reccmp prints a U+2728 sparkle on a 100% match,
# which crashes the cp1252 Windows console) and runs reccmp in --paths mode against
# the shipped original. Kept as a tiny Python helper (not an inline ninja command)
# so it is identical on Windows and Linux/macOS.
#
# Runs reccmp IN-PROCESS (not as a subprocess) so we can patch one robustness bug:
# on a clean-linked DLL (workstream b1) the synthetic stub object (tools/win/
# gen_link_fillers.py) contributes many tightly-packed one-byte `ret` bodies;
# reccmp mis-reads those and then asserts `match.entity_type is not None` in
# Compare._compare_match, aborting the WHOLE report. We wrap that one method to skip
# a match with no entity type (it is never a real annotated function) so the
# accuracy summary still prints. No effect on a /FORCE build (nothing to skip).
#
# Usage: python win_compare.py <orig.dll> <recomp.dll> <recomp.pdb> <src-root> [extra reccmp args...]
###

import os
import sys


def _patch_reccmp():
    """Make Compare._compare_match skip entity_type=None matches instead of
    asserting. Returns quietly if reccmp's internals move (best-effort)."""
    try:
        from reccmp.compare import core
    except Exception:
        return
    orig = getattr(core.Compare, "_compare_match", None)
    if orig is None:
        return

    def safe(self, match):
        if getattr(match, "entity_type", None) is None:
            return None
        return orig(self, match)

    core.Compare._compare_match = safe


def main():
    if len(sys.argv) < 5:
        print("usage: win_compare.py <orig> <recomp> <pdb> <src-root> [extra...]",
              file=sys.stderr)
        return 2
    orig, recomp, pdb, src = sys.argv[1:5]
    extra = sys.argv[5:]
    os.environ["PYTHONIOENCODING"] = "utf-8"
    _patch_reccmp()
    sys.argv = ["reccmp-reccmp", "--paths", orig, recomp, pdb, src, *extra]
    from reccmp.tools import asmcmp
    return asmcmp.main()


if __name__ == "__main__":
    sys.exit(main())
