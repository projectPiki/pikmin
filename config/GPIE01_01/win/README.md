# GPIE01_01 Windows (VC6/PE) symbol assets

Generated symbol tables and module-definition files for the Windows debug build
of Pikmin (GPIE01_01, USA Rev 1). These are **derived artifacts** - regenerate
them from the shipped originals rather than editing by hand.

## Files

For each PE target `<name>` (`sysCore`, `sysBootup`, `plugPiki`, `plugTexConv`,
`plugAtxServer`, `filterDvw`, `filterJmp`):

- `<name>_symbols.csv` - export table as
  `target,ordinal,rva,va,real_rva,real_va,forwarder,mangled,demangled`.
  `va` = ImageBase + `rva`. The modules were linked `/INCREMENTAL:YES`, so most
  exports point at a 5-byte `jmp rel32` thunk rather than the real function body;
  `real_rva`/`real_va` follow that jump to the body (equal to `rva`/`va` for the
  ~8% of exports that are not thunks). **Use `real_va` in reccmp
  `// FUNCTION: <name> 0x...` annotations** - annotating the thunk `va` makes
  reccmp diff the real body against a run of jmp stubs and report 0%.
  (For `sysCore`, 1365 of 1478 exports resolve through a thunk.)
- `<name>.def` - module-definition file listing every export pinned to its
  original ordinal (`@<n>`), so the recompiled DLL reproduces the shipped
  export table and ordinals. Not generated for `sysBootup` - it is an `.exe`
  with no exports and is not linked with `/def`.
- `<name>_map.csv` - **master symbol map**: the authoritative export table merged
  with manual disassembler labels (IDA for `sysCore`, Ghidra for `plugPiki`) into
  one RVA-keyed table `rva,va,kind,size,name_mangled,name,source`. This is the
  join key for reccmp `// FUNCTION:`/`// GLOBAL:` seeding and the objdiff
  extractor. Produced by `tools/win/authoring/merge_symbols.py` from `<name>_symbols.csv`
  plus disassembler dumps (`ghidra/export_symbols.py`, `ida/export_symbols.py`);
  see `tools/win/README.md` for the full workflow and merge policy. The raw
  per-disassembler dumps are regeneratable inputs and are **not** tracked - only
  the merged map is.

## How to regenerate

Originals live (git-ignored) under `orig/GPIE01_01/files/` and
`orig/GPIE01_01/files/plugins/`. From the repo root:

```sh
python tools/win/pe_symbols.py orig/GPIE01_01/files/sysCore.dll \
    --target sysCore -o config/GPIE01_01/win/sysCore_symbols.csv
python tools/win/authoring/gen_def.py orig/GPIE01_01/files/sysCore.dll \
    --name sysCore   -o config/GPIE01_01/win/sysCore.def
```

`pe_symbols.py` is a dependency-free pure-Python PE reader; demangling uses
`pydemumble` (installed as a reccmp dependency) when present.

## Export counts (verified 2026-07-03)

| target        | image base   | exports |
|---------------|--------------|---------|
| sysCore       | 0x10000000   | 1478    |
| plugPiki      | 0x10000000   | 3       |
| plugTexConv   | 0x10000000   | 3       |
| plugAtxServer | 0x10000000   | 3       |
| filterDvw     | 0x10000000   | 3       |
| filterJmp     | 0x10000000   | 3       |
| sysBootup.exe | 0x00400000   | 0 (exe) |

## Known caveat: demangling

77 of the 1478 `sysCore` exports do not demangle and keep their raw mangled name
in the `demangled` column. All contain MSVC extended fixed-width integer type
codes (`_E` unsigned char, `_G` unsigned short, `_H` int, `_I` unsigned int,
`_N` bool) that the bundled `pydemumble` does not decode. This is cosmetic - the
`mangled`, `rva`, `va`, and `ordinal` fields (everything reccmp needs) are
correct for these symbols.
