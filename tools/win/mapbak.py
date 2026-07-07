#!/usr/bin/env python3
"""One shared pre-apply backup for the symbol map, for the Pikmin Windows decomp.

Every map-mutating tool (`vtable_labels`, `autodraft_labels`, `objdiff_mappings`,
`review_labels`, `refresh_map_classkey`) used to drop its own copy of the ~1 MB map
next to the tracked `config/GPIE01_01/win/<mod>_map.csv` under a bespoke suffix
(`.vtbak`/`.autobak`/`.mapbak`/`.revbak`/`.bak`). That scattered five stale copies
into the *tracked* config dir and fragmented the "one map is the ground truth" story.

Instead, take ONE rolling backup per map under the git-ignored build tree. It is a
last-apply undo (`cp build/win/mapbak/<map>.bak <map>`); git holds the deeper
history (the map is tracked, so commit before a big pass to bank a restore point).
"""
from __future__ import annotations

from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MAPBAK_DIR = ROOT / "build" / "win" / "mapbak"


def backup(map_path: Path) -> Path:
    """Copy `map_path` to build/win/mapbak/<name>.bak (the single rolling undo) and
    return the backup path. Overwrites the previous backup for that map."""
    MAPBAK_DIR.mkdir(parents=True, exist_ok=True)
    dst = MAPBAK_DIR / (Path(map_path).name + ".bak")
    dst.write_bytes(Path(map_path).read_bytes())
    return dst
