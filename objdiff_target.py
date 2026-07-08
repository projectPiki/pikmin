#!/usr/bin/env python3
"""Switch the shared root ``objdiff.json`` between the DOL and Win32 diff targets.

objdiff mandates its config at the repo root named exactly ``objdiff.json``, and both
``configure.py`` (DOL / GameCube, PPC) and ``configure_win.py`` (Win32 debug DLLs, VC6)
generate that one file -- so only one target's diff project can be *active* at a time.
This helper makes flipping between them a single, lossless command:

* it **snapshots** the outgoing config to ``build/objdiff_cache/<target>.json`` before it
  is overwritten, so any in-flight objdiff GUI ``symbol_mappings`` (manual base<->target
  pairings you have not yet baked into the map) are never silently dropped;
* it **restores** the requested target's cached config first, so the regenerating
  configure preserves that target's mappings across the round trip;
* it then runs that target's configure to bring the config fresh (picking up any
  added/removed source files).

Neither ``configure.py`` nor ``tools/project.py`` is touched -- this only marshals the
shared slot, so the DOL flow is unaffected.

    python objdiff_target.py            # (or `status`) show the active target
    python objdiff_target.py win [...]  # activate Win32 (extra args pass to configure_win.py)
    python objdiff_target.py dol [...]  # activate DOL   (extra args pass to configure.py)
    python objdiff_target.py win --dry-run   # show what it would do, run nothing

See tools/win/README.md.
"""
from __future__ import annotations

import json
import shutil
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent
CFG = ROOT / "objdiff.json"
CACHE = ROOT / "build" / "objdiff_cache"
CONFIGURE = {"dol": "configure.py", "win": "configure_win.py"}


def detect(path: Path = CFG) -> str | None:
    """Which target owns the objdiff.json at ``path`` (``dol`` | ``win`` | ``None``).

    A Win32 config always references ``build/win/`` in its unit/base/target paths and
    custom_args; any other valid objdiff.json at the root is the DOL one.
    """
    if not path.is_file():
        return None
    try:
        blob = path.read_text(encoding="utf-8-sig")  # utf-8-sig tolerates a leading BOM
        json.loads(blob)  # validate it is real JSON before trusting the heuristic
    except (ValueError, OSError):
        return None
    return "win" if ("build/win/" in blob or "build\\win\\" in blob) else "dol"


def switch(target: str, extra: list[str], dry: bool = False) -> int:
    cur = detect()
    if cur == target:
        print(f"objdiff.json is already the {target} target; regenerating it fresh.")
    else:
        CACHE.mkdir(parents=True, exist_ok=True)
        if cur and CFG.is_file():
            dst = CACHE / f"{cur}.json"
            print(f"cache outgoing {cur} config -> {dst.relative_to(ROOT)}")
            if not dry:
                shutil.copy2(CFG, dst)
        cached = CACHE / f"{target}.json"
        if cached.is_file():
            print(f"restore cached {target} config so its symbol_mappings are preserved")
            if not dry:
                shutil.copy2(cached, CFG)
    cmd = [sys.executable, str(ROOT / CONFIGURE[target]), *extra]
    print(f"$ {' '.join(cmd)}")
    if dry:
        print("(dry-run: nothing executed)")
        return 0
    sys.stdout.flush()  # so our messages precede the child configure's output under a pipe
    return subprocess.run(cmd, cwd=ROOT).returncode


def status() -> int:
    cur = detect()
    print(f"active objdiff target: {cur or 'none (no objdiff.json at repo root)'}")
    for t in ("dol", "win"):
        cached = (CACHE / f"{t}.json").is_file()
        marks = "".join([" <- active" if cur == t else "",
                         "  (cached)" if cached else ""])
        print(f"  python objdiff_target.py {t}{marks}")
    return 0


def main(argv: list[str]) -> int:
    if not argv or argv[0] in ("status", "help", "-h", "--help"):
        return status()
    target = argv[0].lower()
    if target not in CONFIGURE:
        print(f"unknown target {target!r}; expected dol | win | status", file=sys.stderr)
        return 2
    rest = argv[1:]
    dry = "--dry-run" in rest
    return switch(target, [a for a in rest if a != "--dry-run"], dry)


if __name__ == "__main__":
    raise SystemExit(main(sys.argv[1:]))
