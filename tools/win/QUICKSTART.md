# Windows target -- contributor quickstart

Byte-match the **Windows debug build** (VC6 / x86) of Pikmin, function by function, in the
same objdiff loop you already use for the GameCube DOL. The Windows DLLs (`sysCore`,
`plugPiki`) build from the *same* `src/` as the DOL -- only the compiler and a few platform
`#ifdef`s differ -- so most functions are already close.

## One-time setup
- **Python + ninja** on `PATH` (same as the DOL build).
- The **VC6 toolchain** in `tools/vc6/` (see [`README.md`](README.md) / the VC6 setup notes).
- Your `orig/<version>/...` game files present -- the shipped `sysCore.dll` / `plugPiki.dll`
  are the match targets, exactly like the DOL is for the GameCube build.

## The daily loop
1. **Activate the Windows diff target** (it shares objdiff's single config slot with the
   DOL -- the switch is lossless):
   ```sh
   python objdiff_target.py win
   ```
2. **Open the repo root in objdiff** (GUI or the VS Code extension) -- same as the DOL. Units
   are named `sysCore/<tu>` and `plugPiki/<tu>`; pick one.
3. **Edit the matching `.cpp`** under `src/` until the function reads 100%. objdiff rebuilds
   the compiled object on save (via `configure_win`'s ninja) and re-diffs it against the
   target carved from the shipped DLL. Platform-specific code is guarded by `#ifdef WIN32` /
   `_MSC_VER`; the *shared* code is usually what needs nudging to match VC6's x86 codegen.
4. **Switch back to the DOL** anytime, losslessly:
   ```sh
   python objdiff_target.py dol
   ```

That is the whole daily loop. You do **not** run any `tools/win/authoring/` script to match
a function -- the target objects are pre-carved from the shipped DLL by the build (the PE
analog of `dtk dol split`), driven by the tracked `config/<version>/win/<mod>_map.csv`.

## When a function has no target to diff against
If a function appears only on the base side (no target), the map has no symbol for its
address yet (there is no PDB, so the map is reconstructed). Two paths:
- **objdiff "choose target symbol":** the carve adds `FUN_<addr>` placeholders for a TU's
  unlabelled functions -- pick the one whose byte diff matches, bake it into the map with
  `python tools/win/objdiff_mappings.py <mod> --apply`, and re-diff.
- **Map authoring:** larger gaps are map work -- see [`authoring/`](authoring/) and
  [`README.md`](README.md).

## Progress
```sh
python tools/win/authoring/completeness.py plugPiki sysCore   # % of the real binary byte-exact
```

## More
- Build/diff internals, the symbol map, carving: [`README.md`](README.md).
- Repo layout (build-core vs authoring) and the tracked inputs: [`authoring/README.md`](authoring/README.md).
