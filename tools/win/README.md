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

## Refreshing stale class-keys - `refresh_map_classkey.py`

`backfill_map_names.py` harvests `name_mangled` from *our* base objects, so if it
ran before the codebase-wide `struct`->`class` flip the names it froze carry the
old `struct` (`U`) key (`?findTeki@ActDecoy@@IAEPAUCreature@@XZ`). `pe_extract`
prefers the map's `name_mangled` when labelling a carved **target**'s relocation
operands, so those stale `U` names surface on the target side of objdiff while the
recompiled base shows `class` (`V`) - a spurious struct-vs-class diff on every
aggregate-signature callee. `backfill` can't fix it (it only fills *empty* rows).

This tool refreshes them surgically: it collects the decorated names the current
base objects **define**, indexes them by their class-key-neutral signature
(`pe_extract.canon_sig`), and for each map row whose `name_mangled` has the same
canonical signature as exactly one base name, adopts the base's spelling. So it
flips only rows whose sole drift is the class-key (`U`->`V` for flipped types),
leaves genuine structs alone, and can never invent a name.

```
python tools/win/refresh_map_classkey.py \
    --map config/GPIE01_01/win/plugPiki_map.csv \
    --obj-dir build/win/obj/plugPiki [--apply]      # dry-run by default; backs up to <map>.bak
ninja -f build/win/build.ninja target               # re-carve with the refreshed names
```

On plugPiki it refreshed **1052 rows, all pure `U`->`V` key swaps**; objdiff match
count is unchanged (the score is already class-key-tolerant) - it is a display +
ground-truth correctness fix that also matters for a real link/reccmp.

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
`report.json` (full, un-deduplicated - the artifact `ilk_reconcile.py`/
`inline_owner.py` and any per-unit tooling read) and `report_dedup.json` (the honest
progress metric). Both are generated from the **raw** obj/target tree via the
`build/win/full` objdiff project (emitted by `configure_win.py`), *not* the root
objdiff.json - the root config points at the deduped GUI tree where each inline
already appears once, which would hide the per-unit emitters `inline_owner.py` needs.

```
ninja -f build/win/build.ninja target   # re-carve the raw targets first
python tools/win/win_report.py
```

## Inline ownership - `inline_owner.py`

Decides, for each inline duplicated across many units, the ONE unit that should
own it - **byte-faithfully**, the way the original linker actually laid it out.
`owner(F)` = the object whose kept `.text` contribution physically **contains F's
address** (from `ilk_layout.object_text_ranges`), mapped back to its objdiff unit;
the first-in-link-order rule is the fallback for addresses that don't map (thunk/CRT
tail, or objects with no objdiff unit like `age`) **and for the case where the
byte-faithful address-owner is not a matchable emitter here** - an object that
includes the header but did not emit+carve the inline in our build (the ~13
`graphics` cases). Accepting such an owner would strip the inline from every *real*
emitter and leave it with ZERO copies, so the owner is only taken from `.ilk` range
when it is one of the units that actually emit the inline; otherwise the earliest
real emitter keeps it. This guarantees each inline survives in exactly one *pairable*
unit. It drives the COMDAT-dedup build pass (`dedup_comdats.py`, below). Output CSV
columns: `decorated,owner_unit,n_emitters,method` (`method` = `ilk-range` |
`link-order`).

```
python tools/win/inline_owner.py sysCore   # -> build/win/inline_owner_sysCore.csv
python tools/win/inline_owner.py plugPiki \
    --ilk orig/GPIE01_01/files/plugins/plugPiki.ilk   # plugin .ilk isn't at the default path
```

On sysCore: 392 duplicated inlines -> **316 attributed by `.ilk` range (byte-faithful,
each a matchable emitter)**, 76 link-order fallback (13 of which are address-owned by
a non-emitting object). graphics (link #1) owns ~95%, now confirmed exactly.
On plugPiki: 596 duplicated inlines -> **493 `.ilk` range + 103 link-order fallback**
(5 non-emitter); one decomp-only TU (`complexCreature`) has no matching original
object so it never owns an inline (only ever stripped) - harmless.

## COMDAT dedup - `dedup_comdats.py`

The destructive step the ownership map enables. For each base object, it rewrites
every duplicated inline this unit does **not** own (per `inline_owner_<mod>.csv`)
into an *undefined external* (Section=0, Value=0), leaving all other bytes - symbol
indices, relocations, aux records - untouched. That is enough: objdiff lists a
function only where a *defined* text symbol names it, and `pe_extract`'s
`base_defined_functions()` keys off Section>0, so the carved *target* drops the same
inline automatically (one source of truth: the stripped base). References from kept
functions still resolve - they name the same, now-undefined symbol, which objdiff and
`pe_extract` re-pair. The owner keeps the one defined copy, so every inline is present
exactly once module-wide.

```
python tools/win/dedup_comdats.py sysCore \
    --in-dir build/win/obj/sysCore --out-dir build/win/obj_dedup/sysCore
```

`configure_win.py` wires this in: for a module with an owner map it emits a `dedup`
edge (raw obj -> `build/win/obj_dedup/`) then carves the deduped target
(`build/win/target_dedup/`), and the **root objdiff.json GUI config points at that
deduped tree** so each inline shows once, in its owner unit. `ninja dedup` builds it;
a module auto-dedups once its `inline_owner_<mod>.csv` exists. Validated on both
modules (objdiff oracle): redundant copies **sysCore 6288 -> 0, plugPiki 4442 -> 0**;
distinct function names preserved (**926 -> 926**, **5699 -> 5699** - nothing vanishes);
0 still-duplicated; every surviving function's match% unchanged. (The result is in
fact *more* faithful than objdiff's own `--deduplicate`, which over-collapses a few
names - plugPiki keeps 5699 distinct vs `--deduplicate`'s 5696.) The raw tree is
retained for the un-deduplicated tooling report (below).

## Completeness - `completeness.py` (the "% of real binary")

objdiff's headline (matched / *emitted*) flatters us, because our source emits only
a fraction of the functions the shipped module actually contains. This tool fixes
the denominator to the **shipped ground truth** - every function the original linker
knew, read from the module's `.ilk` (same extraction as `ilk_reconcile.py`) - and
reports coverage, byte-exact matches, and a mean-fuzzy scalar against it. The
byte-exact / ground-truth ratio is the honest **"% of the real binary"**. Matching is
by decorated name; `--canon` also credits struct-vs-class-key-only differences.
Keying by name inherently deduplicates the inline-COMDAT copies, so no
`--deduplicate` report is needed.

```
python tools/win/completeness.py plugPiki sysCore --canon   # needs build/win/report.json
```

Latest (2026-07-05): plugPiki **33.8%** of real binary byte-exact (55.7% coverage),
sysCore **36.2%** (58.7%), total **34.1%**. (sysCore's `.ilk` extracts a partial
1461-fn denominator - see the `ilk_reconcile` caveat - so its number is a proxy.)

## `.ilk` object layout - `ilk_layout.py`

Decodes the `.ilk` (Microsoft Linker Database) object-contribution structure: the
exact **link order**, each object's record (path + per-object stream ptr/len), and
the per-object **`.text` address ranges**. Internal `.ilk` pointers are absolute to
a virtual base `0x3fff0000` (file offset = `ptr - 0x3fff0000`; verified 665111/665120
tagged dwords resolve in-file for sysCore).

The section-contribution table is a run of fixed **0x80-stride records**, each tagged
by the dword at `+0x00` == the `.text` section-descriptor body pointer (derived
per-module, not hardcoded). Fields relative to that dword `h`: `h-0x1c` contribution
RVA (16-aligned), `h-0x18` characteristics (bit `0x800` = `LNK_REMOVE` marks the
folded-away COMDAT duplicates), `h-0x14` size, `h-0x04` owner pointer. Dropping the
REMOVE bit leaves the kept contributions, which **tile `.text` exactly once**; an
object's owner pointer is read from its module record at `record_offset - 0x08`, so
each kept COMDAT is attributed to the exact object the linker placed it in. This is
the byte-faithful ground truth `inline_owner.py` consumes via `object_text_ranges()`.

```
python tools/win/ilk_layout.py sysCore -o build/win/ilk_layout_sysCore.csv
python tools/win/ilk_layout.py sysCore --text-ranges     # per-object .text ranges
```

## Function inventory - `ilk_functions.py`

The complete per-function inventory, spined on the `.ilk` **address** table (the
contribution records) instead of its partial name table. Every kept `.text`
contribution is one real function (they tile `.text` once): sysCore **1815**,
plugPiki **10420**. Each is tagged with its byte-faithful **TU** (`object_text_ranges`),
its **inline-vs-strong** kind from the COMDAT **selection** field at record `+0x20`
(`2`=SELECT_ANY=inline, `1`=SELECT_NODUPLICATES=strong; validated against
`inline_owner`), and its emitted/matched status from `report.json`. Incremental-link
`jmp` thunks (<=6 B, no label) are split out. Writes a per-function CSV and a
TU-grouped **unassigned worklist** (strong = real decomp work; inline = appears once
its class/header is written).

```
python tools/win/ilk_functions.py sysCore plugPiki --csv --txt
```

## Vtable labeller - `vtable_labels.py`

The reliable programmatic labeller for virtuals. The `.ilk` has **no** usable
symbol->address map (no PDB; the name blob has no addresses and the address records
have no names; order-based interpolation scores ~0% locally), so instead we transfer
names structurally: our base objects emit each declared class's vtable
`??_7Class@@6B@` with slots = the overriding virtuals' decorated names in declaration
order (even for undefined bodies). Match a base vtable to a run of code-pointers in
the DLL's `.rdata` by sliding until **>=2 known slots agree and 0 disagree**, then
transfer names onto the unknown slot RVAs. Proposals are tiered by exposure to the
DLL-vs-DOL vtable-reorder risk: `cross` (>=2 vtables agree, immune) / `bracket`
(anchored both sides) / `isolated` (exposed, not auto-applied).

```
python tools/win/vtable_labels.py plugPiki             # dry-run -> build/win/vtable_labels_plugPiki.csv
python tools/win/vtable_labels.py plugPiki --apply     # writes cross+bracket into the map (backup in build/win/mapbak/)
```

Validated: 100% holdout; plugPiki applied 304, re-carve gave +243 byte-exact, 0
regressions. Reaches virtuals only; non-virtual unlabelled functions go to
`review_labels.py`.

## Manual label review - `review_labels.py`

The TU-by-TU worklist for **manually** naming what nothing else can (strong
non-virtual bodies we do not emit). Each unlabelled slot gets orientation context: its
TU + address/size, inline/strong kind, the nearest **named neighbours** in that TU,
and its already-named **callees** (a `call rel32` scan of the original bytes). Fill the
`assign` column (decorated `?..` or a demangled `Class::method`); ingest re-decorates
demangled labels via the `.ilk` and writes the map (backup in `build/win/mapbak/`). Candidate name
pool per TU: `build/win/reconcile_<mod>/B_missing_by_tu.txt`.

```
python tools/win/review_labels.py plugPiki --emit                # -> build/win/review/plugPiki.csv
python tools/win/review_labels.py plugPiki --ingest [--apply]    # read assignments back
```

## Auto-drafting the review list - `autodraft_labels.py`

Most of the review list is **automatable**: a review row is an unnamed original
address whose `calls` column lists the already-named functions it calls; and for
every function our source compiles we know the exact set it calls (the REL32
relocation targets in `build/win/obj/<mod>/<tu>.obj`). An unnamed address and a
compiled function that **call the same set** are the same function -- and the base
object hands us the real decorated name. Per TU it scores each row against every
compiled-but-unplaced candidate by callee-set overlap and greedily assigns unique
high-overlap matches, tiered `HIGH`/`MED`/`LOW`. `--verify` re-carves the drafted
names into `build/win/verify/` and scores with objdiff (a correct name matches our
compiled body high; a wrong one carves unrelated bytes near 0); `--apply` writes the
`>= --min-confidence` tier into the map (backup in `build/win/mapbak/`; see
`mapbak.py` -- all map-mutating tools share one rolling pre-apply backup there).

A second signal, `--order`, pairs by POSITION instead of callees: within each TU the
placed names give (ilk#, va) anchors, and between anchors the unplaced names (ilk
order) and unlabelled addresses (va order) are paired 1:1 where counts match; every
proposal is re-carved and only those matching >= `--order-keep`% (default 80) are
kept (a positional misalignment -- e.g. two swapped near-identical dtors -- carves
wrong and is dropped). Both signals feed the same map, and applying names improves
the next round's fingerprints + anchors, so iterate to convergence.

```
python tools/win/autodraft_labels.py plugPiki --apply --min-confidence MED   # callee
python tools/win/autodraft_labels.py plugPiki --order --apply                # position
# refresh + repeat until it stops finding matches:
python tools/win/review_labels.py plugPiki --emit && ninja -f build/win/build.ninja target
```

Result (2026-07-07): callee-match applied 206 (0 wrong; +115 byte-exact); `--order`
kept 563/696 (oracle dropped 17 wrong + weak/not-carved; +473 byte-exact); a 2nd
round added +12. Net **plugPiki deduped byte-exact 3662 -> 4262 (+600), 0
regressions, all re-carve-verified**; the manual residue fell 2444 -> 1656 addresses.
sysCore auto-drafts to nothing -- its unlabelled set is genuinely undecompiled (no
compiled body to match), so it stays a `review_labels.py` manual job.

## Per-TU pairing worklist - `pair_worklist.py`

Lays out the line list as the bipartite pairing it is, one file per TU: the LEFT
side (unlabelled map addresses, from `review_labels.py`) beside the RIGHT side (the
UNPLACED `.ilk` labels -- ground-truth names the map cannot yet locate, via
`pe_extract.carve_row`, so exact/canon/bridge all count as "placed"). Work it TU by
TU; within a TU the names are in `.ilk` order, which tracks address order, so pairing
is largely positional + call-fingerprint.

TU attribution of an unplaced name (it has no address of its own):
* **path** -- a file-local static embeds its source path in the mangled name
  (`...\drawworldmap.cpp59771817::WorldMapTitleObj::...`); the `.cpp` basename IS the
  TU stem -> certain, even for un-emitted files.
* **high / class / ilk-order** -- neighbour-vote by `.ilk` order against PLACED names,
  whose byte-faithful TU comes from `tu_at(rva)` (the decoded `.text` contributions);
  plus the owning class's home TU.
* cross-module inline copies (sysCore's `Vector3f`/`Matrix4f`/... inlined into
  plugPiki) are quarantined to `_cross_module.csv` -- not this module's work.

```
python tools/win/pair_worklist.py plugPiki    # -> build/win/pairing/plugPiki/<tu>.csv + _summary.csv
```

`_summary.csv` is a work-priority list (by address count); TUs with 0 addresses are
inline-only (e.g. the `zen` particle lib) and need no pairing. Result (2026-07-07):
plugPiki 2238 addresses across 250 TUs, 3658 unplaced names attributed with **0 left
unattributed** (70 by embedded path, 325 cross-module inlines quarantined). sysCore
is limited by its partial `.ilk` name table (1461 fns; see the ground-truth caveat).

## Interactive symbol mapping via objdiff - `gen_placeholders.py` + `objdiff_mappings.py`

For the ragged residue the automated matchers can't align, objdiff's GUI lets a human
pick -- guided by the live byte diff -- which target symbol an unmatched base function
corresponds to ("choose target symbol"). That list is populated from the target
object's symbols, and the normal carve only puts NAME-matched functions there, so it
was empty. Fix: put the TU's unlabelled DLL functions in the target as `FUN_<addr>`
placeholders. This is **wired into the main build**:

1. **`gen_placeholders.py <mod>`** lists each TU's unlabelled function addresses (map
   rows with no decorated `name_mangled` and a `FUN_`/`sub_` label), grouped by
   byte-faithful TU (`tu_at`), map-only (no report -> no build cycle). `configure_win`
   runs it (the `placeholders` rule) and the **deduped/GUI** target carve pulls each
   TU's list via `pe_extract.py --extra`. The raw targets stay placeholder-free, so
   `win_report`/`ilk_reconcile`/`inline_owner` are unaffected; only the GUI's per-unit
   % drops (now a truer "% of the real binary").
2. Open the repo root in objdiff as usual; an unmatched base function now offers the
   `FUN_<addr>` target placeholders. Map it to the one whose byte diff matches. objdiff
   records the choice in that unit's **`symbol_mappings`** in the root `objdiff.json` --
   which `configure_win` now PRESERVES across regeneration.
3. **`objdiff_mappings.py <mod> --apply`** (reads the root `objdiff.json` by default)
   writes each decorated base name onto the map row at the placeholder's address
   (direction-agnostic: whichever side is `FUN_<hex>` gives the address). Re-carve
   (`ninja objdiff`) to confirm -- a correct choice carves byte-identical, and the
   now-named address drops out of the placeholder set.

Verified end-to-end (2026-07-07): reverting a known function to a placeholder, mapping
it, and round-tripping reproduces its exact decorated name. Notes: COFF symbol names
must be valid UTF-8 (objdiff rejects otherwise) and non-empty -- `pe_extract` sanitises
stray high bytes and synthesises `FUN_<va>`; objdiff's `report generate` does NOT itself
apply `symbol_mappings` (GUI/diff-engine only), so the value is in the round-trip into
the map.

## Unresolved-externals survey - `undef_survey.py`

The input to the non-`/FORCE` clean-link (workstream b): the external symbols
referenced-but-not-defined across our compiled base objects. Buckets each as
`carve-fn`/`carve-data` (map has an address -> `pe_extract` can carve a filler),
`stub-code`/`stub-sdk` (needs a hand stub/decl -- our unwritten code / Dolphin SDK),
or `import`/`crt` (resolved at link by `sysCore.lib` / MSVCRTD -- **not** fillers).

```
python tools/win/undef_survey.py sysCore plugPiki      # -> build/win/undef_<mod>.csv
```

Note the referenced-undefined set this measures is only ONE axis of the clean-link
gap; the larger axis is the `.def`'s **exported-but-undefined** symbols (see below).

## Clean-link fillers - `gen_link_fillers.py`

Makes a module link **without `/FORCE`** (workstream b1). Two axes force a symbol to
be defined: (1) referenced-but-undefined (from `undef_survey.py`), and (2) the far
larger **exported-but-undefined** -- the `.def` exports the full original surface
(sysCore 1478), of which ~544 are undecompiled and error `LNK2001` on the `.exp`
without `/FORCE`. This tool unions both into ONE synthetic COFF **stub object**
(`build/win/stubs/<mod>_stubs.obj`) defining every name by its exact decorated name:
vftable/rtti/`@@3`-data get a zero word in `.data`, everything else a 1-byte `ret` in
`.text`. It links purely by name -- no C++ source, no carving (carving a real body
drags in its whole transitive closure, which only resolves once the entire image is
present -> a **b2** concern; those names are stubbed for b1 and listed in
`<mod>_carve.txt` as the b2 byte-carve worklist). `--provided <pe_symbols.csv>`
(repeatable) marks symbols an import lib supplies so they are not stubbed (else
LNK2005) -- e.g. plugPiki passes `sysCore_symbols.csv`.

```
python tools/win/gen_link_fillers.py plugPiki \
    --undef build/win/undef_plugPiki.csv --def config/GPIE01_01/win/plugPiki.def \
    --objs-dir build/win/obj/plugPiki --stub-obj build/win/stubs/plugPiki_stubs.obj \
    --carve-names build/win/stubs/plugPiki_carve.txt \
    --provided config/GPIE01_01/win/sysCore_symbols.csv
```

Wired into `configure_win.py`: `ninja -f build/win/build.ninja <mod>.link` runs the
survey + fillers + a non-`/FORCE` link automatically (`plugPiki.link` builds sysCore
first for its import lib). `<mod>.compare` then runs reccmp (`win_compare.py` patches
one reccmp assertion that a half-stubbed image trips). Result (2026-07-06): both
sysCore + plugPiki link clean; sysCore whole-image reccmp 53.52% (/FORCE) -> 77.88%.

## Data carving - `pe_extract.py --no-data` opt-out (W-DATA carver)

`pe_extract.py` now carves data sections into the objdiff target alongside `.text`,
so strings, fp-constant pools and vftables are diffed for the first time.
**Mechanism:** a base relocation names every symbol a function or vftable references
(`??_C@...`, `??_7X@@6B@`) and the carved DLL bytes at the aligned offset give its
address - so discovery seeds from code (only functions that carved byte-identical
*modulo relocations*, so base reloc offsets line up with the DLL operands), then
BFS's through data->data pointers (pointer arrays, vftable slots). Each discovered
symbol's bytes are carved from the DLL into `.rdata`/`.data`; code and vftable-slot
relocations are named after the base's target so objdiff pairs them (`.bss` /
uninitialised data is skipped in this first slice). `completeness.py` reports the
result (matched/total data bytes); `--no-data` restores the old `.text`-only carve
for A/B. Result (2026-07-05): **sysCore 22838/22842 data bytes byte-exact (100%),
plugPiki 59526/62813 (94.8%)** - with **zero** change to the function metric.

## Where the disassembler dumps live

The raw `<name>_ida.csv` / `<name>_ghidra.csv` are **inputs you regenerate**, not
tracked artifacts - drop them anywhere (repo root or scratch) and point `--labels`
at them. Only the merged `config/GPIE01_01/win/<name>_map.csv` is the tracked
deliverable. See the sibling scripts (`pe_symbols.py`, `gen_def.py`,
`configure_win.py` + `win_cc.py`, and the per-function `build_slice.ps1` /
`diff_func.ps1`) for the build/match half of the workflow.
