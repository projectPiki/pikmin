# Windows-decomp symbol tooling

Scripts for building the **master symbol map** of each Windows (VC6/PE) module -
the RVA-keyed table that drives reccmp annotation seeding and the objdiff
extractor. Everything downstream is only as good as this map, so it merges three
streams of truth per module and never lets an automated re-run clobber a human
label.

```
                pe_symbols.py            (exports: ground-truth names, from the PE)
  original PE  ------------------>  <name>_symbols.csv --+
                                                         |
  IDA .idb    -- ida/export_symbols.py ---->  <name>_ida.csv     --+
  Ghidra proj -- ghidra/export_symbols.py -->  <name>_ghidra.csv  -+
                                                         |         |
                                          merge_symbols.py  <------+
                                                         |
                                                         v
                              config/GPIE01_01/win/<name>_map.csv   (crown jewel)
```

## Interchange schema

Both disassembler exporters emit the same 6-column CSV so the merge is uniform:

| column         | meaning                                                        |
|----------------|----------------------------------------------------------------|
| `rva`          | `0x`-hex, **image-base-relative** (`ea - imagebase`). Join key. |
| `kind`         | `function` \| `thunk` \| `data` \| `string` \| `vtable`        |
| `size`         | bytes (aids boundaries + extraction)                           |
| `name_mangled` | decorated MSVC name if the DB kept one (vital for data/globals) |
| `name`         | demangled signature / human label                             |
| `source`       | `ida` \| `ghidra` (set by the exporter)                        |

RVA is image-base-relative on purpose: it stays correct even if the disassembler
rebased the image, and joins directly against `<name>_symbols.csv` (image base
`0x10000000` for sysCore + all plugins).

The merged `<name>_map.csv` adds `va` and a combined `source`
(`rva,va,kind,size,name_mangled,name,source`, e.g. `source=export+ida`).

## Ghidra exporter - `ghidra/export_symbols.py`

Jython (Python 2.7) Ghidra script. Best for **plugPiki** (the shared Ghidra
project has the richest labelling).

**Point Ghidra at it (GUI):** *Window -> Script Manager -> Manage Script Directories*
(the hamburger/bundle icon) -> **+** -> add `.../pikmin/tools/win/ghidra`. The script
then appears under the **Pikmin** category. Open the plugPiki program, run it, and
pick an output path (defaults to `<program>_ghidra.csv` in your home dir).

**Headless** (no GUI, reproducible):

```sh
analyzeHeadless <project-dir> <project-name> \
    -process plugPiki.dll \
    -scriptPath tools/win/ghidra \
    -postScript export_symbols.py "$PWD/plugPiki_ghidra.csv"
```

It walks `getFunctionManager().getFunctions()` (entry, full name, `isThunk`, body
size) plus user-labelled defined data/strings; auto-analysis data with only a
`DEFAULT`-source name is skipped.

## IDA exporter - `ida/export_symbols.py`

IDAPython (IDA 7.4+ / 9.x). Best for **sysCore** - its IDA database is the *only*
source of sysCore's internal function labels.

**Point IDA at it (GUI):** open the sysCore database, then *File -> Script file...*
-> pick `tools/win/ida/export_symbols.py`. It writes `<idb-stem>_ida.csv` next to
the `.idb` and prints the path to the Output window.

**Headless:**

```sh
ida -A -S"tools/win/ida/export_symbols.py $PWD/sysCore_ida.csv" sysCore.dll
```

It walks `idautils.Functions()` (size via `get_func`, `FUNC_THUNK` flag, stored
decorated name + IDA demangling) plus named data/strings from `idautils.Names()`.

> **Quick-and-dirty fallback:** *File -> Produce file -> Create MAP file* gives
> address+name but **loses size and mangling** - usable in a pinch, but the
> IDAPython script is strongly preferred because size and the decorated name both
> matter downstream. (A small `.map -> interchange CSV` shim can be added later if
> you ever need it.)

## Merge - `merge_symbols.py`

Folds the export table + disassembler labels into the master map. Merge policy:

- **Provenance precedence for the label:** manual > ida/ghidra > export. A human
  relabel supersedes the raw export name and survives a re-export.
- **Placeholder guard:** auto-names (`sub_`, `FUN_`, `loc_`, `dword_`, `DAT_`, ...)
  never outrank a real name - they still contribute address + size, but the
  export's true name stays put.
- **Mangled name preserved** from whichever source kept it (objdiff names
  data/global/vtable relocations by decorated symbol).
- Exports expand to a **body row** at `real_va` plus a **thunk row** at the export
  `va` when `/INCREMENTAL:YES` routed it through a 5-byte `jmp` stub.

```sh
# sysCore: authoritative exports + IDA internals
python tools/win/merge_symbols.py --target sysCore \
    --exports config/GPIE01_01/win/sysCore_symbols.csv \
    --labels  sysCore_ida.csv \
    -o config/GPIE01_01/win/sysCore_map.csv

# plugPiki: exports + Ghidra internals (--labels is repeatable)
python tools/win/merge_symbols.py --target plugPiki \
    --exports config/GPIE01_01/win/plugPiki_symbols.csv \
    --labels  plugPiki_ghidra.csv \
    -o config/GPIE01_01/win/plugPiki_map.csv
```

`--labels` is repeatable, so a module labelled in both disassemblers merges both.
With no `--exports` (e.g. `sysBootup.exe`, 0 exports) pass `--image-base 0x400000`.

## Seed annotations - `seed_annotations.py`

Turns the master map into reccmp markers in the source tree: it drops a
`// FUNCTION: <MODULE> 0x<va>` above each matching function definition (and
`// GLOBAL:` above each datum). A dependency-free, scope-tracking scan indexes
every definition in the given sources - qualifying both out-of-line
(`void A::b() {`) and in-class inline (`int b() {` inside `class A`) members - then
matches each map symbol by qualified name and argument count.

It is deliberately **conservative**: it only writes when a symbol resolves to
exactly ONE definition (a wrong marker makes reccmp diff the wrong function), is
**idempotent** (never double-annotates), and is **dry-run by default**. Everything
it can't place confidently is counted and, with `--report`, listed for hand
placement.

```sh
# dry run - see what it would place, and dump the leftovers
python tools/win/seed_annotations.py --target sysCore \
    --map config/GPIE01_01/win/sysCore_map.csv \
    --src src/sysCommon --src src/sysDolphin --src include \
    --kind both --report build/win/seed_sysCore.txt

# actually write the markers
python tools/win/seed_annotations.py --target sysCore --map ... --src ... --apply
```

Scope `--src` to the module's own directories (sysCore = `src/sysCommon` +
`src/sysDolphin`; plugPiki = the `src/plugPiki*` dirs) plus `include`, so a method
name can't match an unrelated module. `--kind function|data|both`, `--filter
<regex>` narrows to matching names, `--module` overrides the marker id (default =
`--target` upper-cased). On first run this places ~730 of sysCore's and ~4500 of
plugPiki's functions automatically; the rest (compiler-generated ctors/`operator=`,
true overloads, un-labelled `sub_*`) are reported for manual work.

## Building sysCore (VC6 -> ninja)

The Windows target builds with **Python + ninja**, the same stack as the DOL
decomp (`configure.py`), kept separate from the PPC-only `tools/project.py`. No
PowerShell, no NMake - so contributors on Linux/macOS can build too (cl.exe/link.exe
run under **wine**, auto-wrapped off Windows; pass `--wrapper` for wibo).

```
python configure_win.py                    # generate build/win/build.ninja
ninja -f build/win/build.ninja             # compile every sysCore TU
ninja -f build/win/build.ninja -k 0        # keep going, list every failing TU
ninja -f build/win/build.ninja link        # link sysCore.dll (+PDB)
ninja -f build/win/build.ninja compare     # reccmp vs the shipped original
```

`configure_win.py` globs `src/sysCommon` + `src/sysDolphin`, emits the confirmed
VC6 flags (`/ZI /GZ /GX /GR- /MDd /Od /W3 /Zm600`, per-TU `/Fd` PDBs, `/I include`
+ `/I tools/vc6/include` only), and self-regenerates when it or its helpers change.
Switches: `--develop` (define `DEVELOP`), `--force` (link `/force` to emit the DLL
despite the not-yet-decompiled externals, for a whole-module reccmp baseline).

VC6 `cl` has neither `/showIncludes` nor `-MMD`, so **`win_cc.py`** wraps each
compile: it runs `cl`, then writes a gcc-style depfile from a transitive `#include`
scan (project headers only) that ninja consumes via `deps = gcc` - precise
incremental rebuilds without recompiling the world on a header touch.
`win_compare.py` wraps `reccmp-reccmp` (sets `PYTHONIOENCODING` for the console).

## Diffing in objdiff - `pe_extract.py`

objdiff supports **x86 COFF** natively, and the VC6 build already emits COFF `.obj`
files, so the compiled `build/win/obj/*.obj` serve directly as objdiff *base*
objects. The only synthesized part is the *target* ("expected") object, carved out
of the original DLL by **`pe_extract.py`**:

- it reads the base obj's symbol table for the functions that TU defines (VC6 emits
  one COMDAT section per function),
- joins those decorated names to `<mod>_map.csv` for each function's real body
  address + size, copies the bytes verbatim out of the DLL, and gives each the same
  decorated name as the base so objdiff pairs them,
- reconstructs relocations with capstone: REL32 for `call`/`jmp` targets and DIR32
  for absolute data/global references, each pointing at the map symbol it lands on
  (incremental-link thunk rows carry the real function's name, so thunked calls
  resolve correctly). The reloc field is rewritten to the addend, mirroring what a
  genuine MSVC object stores, so target relocations compare byte-for-byte to base.

```
python configure_win.py                    # also writes objdiff.json (see below)
ninja -f build/win/build.ninja             # base objs (objdiff rebuilds on edit)
ninja -f build/win/build.ninja target      # carve every objdiff target object
```

`configure_win.py` generates the root **`objdiff.json`** (one unit per TU,
`build_base`/`build_target` true so objdiff rebuilds both via ninja on demand).
objdiff requires that file at the repo root named exactly `objdiff.json`, so it
**shares the slot with the DOL/PPC config** emitted by `configure.py`: whichever
configure you ran last wins - **re-run `configure.py` to switch objdiff back to the
GameCube build.** Open the repo in the objdiff GUI / VS Code extension to diff.

Validated against the reccmp oracle: reccmp-exact functions (e.g. `AyuStack::pop`,
`reset`) carve byte-identical to the base and objdiff scores them 100%; partial
functions diverge in both tools. (objdiff and reccmp use different scoring, so
absolute %s on partials differ - they agree on what is matched.) The
`objdiff-cli report generate -p . -o <out>` command emits per-function %s
non-interactively for a machine-checkable cross-reference.

## Backfilling mangled names - `backfill_map_names.py`

plugPiki's map (from Ghidra) has an **empty `name_mangled`** for ~10k internal
functions - only demangled labels (`Vector3f::operatorMultVF`, `qdist2CC`,
`PaniMotionInfo::PaniMotionInfo2`). objdiff and `pe_extract` pair by decorated
name, and the demangled-name bridge can't key the cases where Ghidra's label
diverges from the MSVC demangling (operators, arg/overload suffixes, data
globals), so those references show as spurious mismatches even when the bytes are
identical. This tool recovers the decorated names **positionally**: for each
function a base obj defines and that carves, it aligns the base disassembly
(relocations carry the true decorated name at each call/data site) against the
original bytes (operands give the target VA at the same site) and reads off
`target_va -> decorated name`. Votes are aggregated across every TU.

Three safeguards keep a wrong name (which would mis-pair or carve the wrong body)
out: **dominance** (accept only a clear plurality, `w >= 2*runner + 1`, so 1-off
mis-alignments never win), **corroboration** (harvested name must be
demangling-consistent with the label - rejects e.g. a mis-aligned `tekiMgr` vs
`gameflow` load), and **uniqueness** (a decorated name denotes one address; on a
collision only the strongest-voted VA keeps it, and export-owned names are
off-limits - so no duplicate `name_mangled` for `carve_row` to trip on).

```
python tools/win/backfill_map_names.py \
    --dll orig/GPIE01_01/files/plugins/plugPiki.dll \
    --map config/GPIE01_01/win/plugPiki_map.csv \
    --obj-dir build/win/obj/plugPiki [--apply]      # dry-run by default
ninja -f build/win/build.ninja target               # re-carve with the new names
```

Dry-run by default; back up the map before `--apply`. Validated with the
objdiff-cli oracle (re-carve + `report generate`): on plugPiki it named ~3.2k
rows and took **+660 functions to byte-exact with zero regressions** of
previously-exact functions. Re-run whenever the base objects or the map's Ghidra
labels improve.

## Reconciling names against the `.ilk` - `ilk_reconcile.py`

The shipped `<module>.ilk` is the ground truth for symbol *names*: it carries
every decorated MSVC name the original linker knew, in objects' contribution
order (so names cluster by TU). This tool extracts that list (validating each
candidate by demangling it) and diffs it against what our source emits (the base
symbols in the objdiff `report.json`) and what the map holds, writing a laundry
list into `build/win/reconcile_<module>/`:

- **`A_wrong_names.txt`** / **`A_classkey_types.txt`** - names we emit that the
  `.ilk` never had (typos, signature drift, and dominantly the struct-vs-class key,
  since MSVC mangles `class` as `V` and `struct` as `U`). The `_classkey_types`
  file is the actionable "flip these `struct`s to `class`" list, ranked by how many
  of our functions each type affects.
- **`B_missing_by_tu.txt`** - `.ilk` functions our source does *not* emit
  (unimplemented or mis-named), bucketed by probable TU. TU is inferred, in
  descending confidence, from: a source path embedded in a file-local static's
  symbol (`path`, certain); class-home agreeing with the `.ilk`-order neighbours
  (`high`); neighbour consensus alone (`ilk-order`); or the class-home vote alone.
  A small `hard` residue (whole un-started TUs) is left for a human.
- **`C_map_placeholders.txt`** - map rows still on `FUN_`/`sub_`/`DAT_` labels.

```
python tools/win/ilk_reconcile.py plugPiki       # needs a fresh build/win/report.json
python tools/win/ilk_reconcile.py sysCore
```

Caveat: some modules store the `.ilk` name table differently and only a fraction
of names extract as plain strings (sysCore yields ~1660 vs plugPiki's ~11800);
those modules are export-covered elsewhere, so the partial run is low-impact - but
treat a surprisingly low ground-truth count with suspicion.

## Progress report - `win_report.py`

Generates the objdiff progress report two ways and prints them side by side.
Under `/Od`, every referenced inline member is emitted as a COMDAT-select-ANY
external in *every* TU that uses it (and `SYSCORE_EXPORTS` widens that to every TU
that includes the header), so one inline is counted in dozens of units - sysCore's
raw report is ~87% redundant duplicate copies. objdiff-cli's `--deduplicate`
collapses those weak/global symbols to give the honest number. We keep both:
`report.json` (full, un-deduplicated - the artifact `ilk_reconcile.py` and any
per-unit tooling read) and `report_dedup.json` (the honest progress metric).

```
ninja -f build/win/build.ninja target   # re-carve first
python tools/win/win_report.py
```

## Inline ownership - `inline_owner.py`

Decides, for each inline duplicated across many units, the ONE unit that should
own it - the way the original linker did. MSVC's incremental linker keeps the
COMDAT copy from the *first object in link order* that emits it, so
`owner(F) = the emitter of F whose object is earliest in link order`, with link
order read straight from the `.ilk` object-contribution table. This drives the
planned COMDAT-dedup build pass (strip each shared inline from every base object
except its owner, so objdiff shows it once). See the CAVEAT in the script header:
the rule is enough to declutter deterministically (graphics, link #1, owns ~94%),
but byte-faithful per-unit attribution needs the `.ilk`'s exact address ranges.

```
python tools/win/inline_owner.py sysCore   # -> build/win/inline_owner_sysCore.csv
```

## Where the disassembler dumps live

The raw `<name>_ida.csv` / `<name>_ghidra.csv` are **inputs you regenerate**, not
tracked artifacts - drop them anywhere (repo root or scratch) and point `--labels`
at them. Only the merged `config/GPIE01_01/win/<name>_map.csv` is the tracked
deliverable. See the sibling scripts (`pe_symbols.py`, `gen_def.py`,
`configure_win.py` + `win_cc.py`, and the per-function `build_slice.ps1` /
`diff_func.ps1`) for the build/match half of the workflow.
