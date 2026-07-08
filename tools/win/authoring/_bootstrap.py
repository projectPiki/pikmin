"""sys.path + ROOT bootstrap for the tools/win/authoring/ scripts.

These are the map-authoring / `.ilk` reverse-engineering / metrics tools -- run
occasionally to (re)generate the tracked build inputs, NOT part of the routine build
(see tools/win/README.md). They live one directory below the build-core library
modules they reuse (`pe_extract`, `pe_symbols`, `mapbak`, which stay at tools/win/).

Running any of them as a script auto-puts this authoring/ dir on `sys.path[0]` (so
authoring siblings like `ilk_layout`/`ilk_functions` import). This module additionally:

* adds the parent `tools/win/` dir to `sys.path`, so the core libs import; and
* exposes ``ROOT`` (the repo root), which these scripts previously derived from a
  ``Path(__file__).resolve().parents[2]`` that silently pointed one level too shallow
  once the file moved down into authoring/.

Import it first, before any sibling/core import or ROOT use:

    import _bootstrap            # sets up sys.path for the core libs
    ROOT = _bootstrap.ROOT       # repo root
"""
import sys
from pathlib import Path

_HERE = Path(__file__).resolve().parent      # tools/win/authoring
_CORE = _HERE.parent                          # tools/win
ROOT = _CORE.parents[1]                       # repo root (tools/win -> tools -> repo)

for _p in (str(_CORE), str(_HERE)):
    if _p not in sys.path:
        sys.path.insert(0, _p)
