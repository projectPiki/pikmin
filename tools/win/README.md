# Windows-decomp symbol tooling

Scripts for building the **master symbol map** of each Windows (VC6/PE) module —
the RVA-keyed table that drives reccmp annotation seeding and the objdiff
extractor. Everything downstream is only as good as this map, so it merges three
streams of truth per module and never lets an automated re-run clobber a human
label.

```
                pe_symbols.py            (exports: ground-truth names, from the PE)
  original PE ──────────────►  <name>_symbols.csv ─┐
                                                    │
  IDA .idb   ── ida/export_symbols.py ──► <name>_ida.csv     ─┐
  Ghidra proj ─ ghidra/export_symbols.py ► <name>_ghidra.csv ─┤
                                                    │          │
                                        merge_symbols.py  ◄────┘
                                                    │
                                                    ▼
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

## Ghidra exporter — `ghidra/export_symbols.py`

Jython (Python 2.7) Ghidra script. Best for **plugPiki** (the shared Ghidra
project has the richest labelling).

**Point Ghidra at it (GUI):** *Window → Script Manager → Manage Script Directories*
(the hamburger/bundle icon) → **+** → add `…/pikmin/tools/win/ghidra`. The script
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

## IDA exporter — `ida/export_symbols.py`

IDAPython (IDA 7.4+ / 9.x). Best for **sysCore** — its IDA database is the *only*
source of sysCore's internal function labels.

**Point IDA at it (GUI):** open the sysCore database, then *File → Script file…*
→ pick `tools/win/ida/export_symbols.py`. It writes `<idb-stem>_ida.csv` next to
the `.idb` and prints the path to the Output window.

**Headless:**

```sh
ida -A -S"tools/win/ida/export_symbols.py $PWD/sysCore_ida.csv" sysCore.dll
```

It walks `idautils.Functions()` (size via `get_func`, `FUNC_THUNK` flag, stored
decorated name + IDA demangling) plus named data/strings from `idautils.Names()`.

> **Quick-and-dirty fallback:** *File → Produce file → Create MAP file* gives
> address+name but **loses size and mangling** — usable in a pinch, but the
> IDAPython script is strongly preferred because size and the decorated name both
> matter downstream. (A small `.map → interchange CSV` shim can be added later if
> you ever need it.)

## Merge — `merge_symbols.py`

Folds the export table + disassembler labels into the master map. Merge policy:

- **Provenance precedence for the label:** manual > ida/ghidra > export. A human
  relabel supersedes the raw export name and survives a re-export.
- **Placeholder guard:** auto-names (`sub_`, `FUN_`, `loc_`, `dword_`, `DAT_`, …)
  never outrank a real name — they still contribute address + size, but the
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

## Seed annotations — `seed_annotations.py`

Turns the master map into reccmp markers in the source tree: it drops a
`// FUNCTION: <MODULE> 0x<va>` above each matching function definition (and
`// GLOBAL:` above each datum). A dependency-free, scope-tracking scan indexes
every definition in the given sources — qualifying both out-of-line
(`void A::b() {`) and in-class inline (`int b() {` inside `class A`) members — then
matches each map symbol by qualified name and argument count.

It is deliberately **conservative**: it only writes when a symbol resolves to
exactly ONE definition (a wrong marker makes reccmp diff the wrong function), is
**idempotent** (never double-annotates), and is **dry-run by default**. Everything
it can't place confidently is counted and, with `--report`, listed for hand
placement.

```sh
# dry run — see what it would place, and dump the leftovers
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

## Where the disassembler dumps live

The raw `<name>_ida.csv` / `<name>_ghidra.csv` are **inputs you regenerate**, not
tracked artifacts — drop them anywhere (repo root or scratch) and point `--labels`
at them. Only the merged `config/GPIE01_01/win/<name>_map.csv` is the tracked
deliverable. See the sibling scripts (`pe_symbols.py`, `gen_def.py`,
`build_slice.ps1`, `diff_func.ps1`) for the build/match half of the workflow.
