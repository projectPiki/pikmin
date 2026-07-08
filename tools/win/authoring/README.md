# tools/win/authoring/

Map-authoring, `.ilk` reverse-engineering, and metrics tools for the Windows (VC6/PE)
decomp. These are run **occasionally** to (re)generate the *tracked* build inputs under
`config/<version>/win/` -- the `<mod>_map.csv`, `<mod>_inline_owner.csv`,
`<mod>_text_ranges.csv`, and `.def`. They are **not** part of the routine build.

The routine build + objdiff loop uses only the build-core scripts one level up in
`tools/win/` (`pe_extract`, `dedup_comdats`, `gen_placeholders`, `win_cc`, `win_compare`,
`undef_survey`, `gen_link_fillers`, `objdiff_mappings`, plus the `pe_symbols`/`mapbak`
libraries). Those depend only on the committed CSVs + the original DLL, so a clean checkout
builds and diffs **without** running anything in here or parsing the `.ilk`.

Each script here does `import _bootstrap` first (see [`_bootstrap.py`](_bootstrap.py)) to
reach the core libraries in `tools/win/` and the repo `ROOT`. Run them as scripts, e.g.

```sh
python tools/win/authoring/completeness.py plugPiki sysCore
python tools/win/authoring/ilk_layout.py sysCore --ranges-csv config/GPIE01_01/win/sysCore_text_ranges.csv
```

See [`../README.md`](../README.md) for the full core-vs-authoring split and
the `.ilk`-derived tracked inputs.
