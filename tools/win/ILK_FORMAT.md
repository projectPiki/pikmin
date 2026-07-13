# The Microsoft Linker Database (`.ilk`) format — VC6 / PE

Reference for the incremental-link database emitted by **Visual C++ 6.0 `link.exe`
(12.00.8168)** under `/INCREMENTAL:YES`, as shipped alongside the Pikmin Windows
build (`sysCore.dll`, `plugPiki.dll`, …). The shipped game ships `.ilk` files but
**no `.pdb`**, so the question this document answers is: *how much ground truth can
be recovered from the `.ilk` alone?*

Everything here was derived empirically and checked against a hard answer key — the
shipped DLLs' own PE export tables (1478 name→RVA pairs for sysCore) — and against a
controlled corpus of 13 single-variable VC6 link builds with `.map`-derived truth.
The consolidated reader is [`authoring/ilk.py`](authoring/ilk.py); run it with
`--validate <dll>` to reproduce the numbers below.

---

## 1. Executive summary — what this changes

Prior project belief (recorded in memory / `ilk_layout.py`) vs. what is now measured:

| Prior belief | Verdict | Reality |
|---|---|---|
| "The `.ilk` has **no cheap symbol→address map**." | **REFUTED** | Every external symbol has a 60-byte record carrying its real image RVA. sysCore: `rec.rva == real body` **1478/1478** exports. |
| "The name blob is only **partially** extractable (~1461/1815)." | **REFUTED** | It was a parser bug. All names are present; the authoritative count is the hash-table walk: sysCore **2629**, plugPiki **18407** symbols. |
| Export RVAs anchor real function bodies. | **REFUTED** | The game is `/INCREMENTAL`, so **1365/1478** sysCore exports point at 5-byte `E9` **jump thunks**, not bodies. The `.ilk` stores both the thunk and the real body RVA. |
| "The name blob has **no physical→TU link**." | **REFUTED** | Each symbol record points at its section contribution, which points at its owning module. **TU attribution is 100%** for object-defined symbols (sysCore 2624/2629). |
| Internal pointers use base `0x3FFF0000` **and** a second `0x40000000` stream; `ptr & 0xffff` maps to file. | **REFUTED** | One arena: `file_offset = ptr − 0x3FFF0000`, resolves 305029/305029 pointers on sysCore. `0x40000000` is just file offset `0x10000`. |

**The single most important operational fact:** because exports are thunked, any
tooling that anchored function addresses on export RVAs was anchoring on 5-byte
thunks, not on function bodies. The `.ilk`'s record `+0x20` is the real body RVA and
`+0x30` is the thunk — use those.

Hard limits (measured, so you don't chase them): file-local **statics** get no
record and their names appear nowhere in the file; there is **no per-symbol size
field**; and there are **no types / locals / line numbers / source paths** (those
lived in the `.pdb`).

---

## 2. High level — what is stored

### Per symbol (external/public symbols only)
- mangled **name** (MSVC decorated);
- final image **RVA** of the real body;
- **incremental thunk** RVA (if the symbol is thunked);
- **section** number, COFF **type** (function vs. data), **storage class**
  (external / weak-external), and COMDAT flag;
- **owning object / translation unit** (via the contribution back-pointer);
- the offset of the symbol **within** its object's section contribution.

"External symbols" = exactly the COFF external + COMDAT symbol set: defined functions
and data, every COMDAT copy (winners *and* folded losers), weak externals, imports
(`__imp_*`), absolutes (`__except_list`), and incremental markers. **Not** included:
static functions, static/global-`static` variables, function-local statics, string
literals (`$SG*`), EH scope tables (`$T*`) — these are absent by name from the whole
file.

### Per object / translation unit
- object **path** (`.\Debug\<stem>.obj`) or `.lib`-member identity;
- **link order** index (1-based);
- COFF `PointerToSymbolTable`, `NumberOfSymbols`, `NumberOfSections`, `TimeDateStamp`;
- one **section-contribution** record per COFF section: placed RVA (0 = folded /
  discarded), section characteristics, allocated length + incremental slack (so
  `raw size = alloc − slack`), owning-module back-pointer, relocation/line counts,
  and a content checksum used as the incremental change-detection key.

The object inventory in the `.ilk` is the **complete** link input, including `.lib`
members that never appear on the command line (sysCore names 92 objects vs. 42 on the
command line; plugPiki 367 vs. 4 — the rest come from the six per-developer static
libraries).

### Also present, `.ilk`-exclusive
The **effective link command line** (all switches + the command-line file list, with
response files expanded and the `LINK` env var merged in — not strictly verbatim),
and the **PDB signature+age** at `+0x238`/`+0x23c` that keys the `.ilk` to its `.pdb`
and image. These exist in no other shipped artefact.

---

## 3. Low level — byte layout

All multi-byte integers are little-endian. "VA" = a value in the arena address space;
convert with `file_offset = VA − arena_base`.

### 3.1 Header and the single arena
```
0x00  char[27]  "Microsoft Linker Database\n\x07\x1a"   file magic
0x24  u32       arena base VA (always 0x3FFF0000)       <-- the ONE pointer base
0x30  IMAGE_FILE_HEADER (20 bytes) + IMAGE_OPTIONAL_HEADER32   verbatim, for the image
        0x44+0x14  u32  BaseOfCode == .text VirtualAddress (needed to place thunks)
0x224 u32       TimeDateStamp of the link that (re)created the .ilk
0x238 u32       PDB signature   (== image NB10 CodeView signature)
0x23c u32       PDB age
0x2A8 u32/u32/u32   string-table  VA / used size / capacity
0x2CC symbol hash-table descriptor:
        +0x04 u32  bucket count (sysCore 0x400, plugPiki 0x1000)
        +0x0C u32  number of symbol records   (authoritative count)
        +0x38 u32  VA of the first bucket array
```
The whole file is a raw dump of the linker's heap mapped at `0x3FFF0000`. There is no
second base and no `& 0xffff` masking.

### 3.2 String table
A flat blob of NUL-terminated, **fully deduplicated** MSVC-decorated names, preceded by
a 4-byte reserved prefix. Located from the header (`+0x2A8`), not by scanning. Not
hashed or sorted in place — names are reached only by index from a symbol record. A
name's presence implies the symbol is in the shipped image (no phantom/discarded
names).

### 3.3 Symbol record — 60 bytes (`0x3C`)
An in-memory `IMAGE_SYMBOL` plus resolution state. Records are packed `0x3C` apart in
runs but are **not** one flat array; the authoritative set is the union of the hash
chains. Offsets are relative to the record base `R` (the address a bucket slot / chain
link points at):

```
+0x00  u32  self-pointer, == VA(R+8)  — the record signature (100% of records)
+0x04  u32  hash chain: VA of next record in bucket (0 = end)
+0x08  8    IMAGE_SYMBOL Name union:
              u32@+0x08 == 0  ->  u32@+0x0C = offset into the string table (long name)
              else            ->  inline short name, <= 8 bytes (no NUL if exactly 8)
+0x10  u32  Value = symbol's offset within its obj-section contribution
+0x14  u32  low16 = SectionNumber (1-based PE section; 0xFFFF=ABS, 0=UNDEF)
            high16 = Type (0x20 = FUNCTION, 0 = not-a-function)
+0x18  u32  StorageClass (2 = EXTERNAL, 0x69 = WEAK_EXTERNAL, 0 = label/special)
+0x1C  u32  VA of the section-CONTRIBUTION record of the defining obj-section  <-- TU
+0x20  u32  final image RVA of the real symbol body            <-- USE THIS, not exports
+0x24  u32  VA of the next symbol defined by the same module (per-TU linked list)
+0x28  u32  always zero
+0x2C  u32  VA of a module record that references this symbol (0 = unreferenced)
+0x30  u32  /INCREMENTAL thunk offset, relative to .text VA (0 = not thunked)
              thunk_rva = BaseOfCode + this;  thunk is a 5-byte E9 jmp to +0x20
+0x34  u32  always zero
+0x38  u32  flags: 0x0001 defined, 0x0004 has-contribution, 0x0020 COMDAT,
              0x0080 weak-external, 0x1000 library/linker symbol (rest: see ilk.py)
```
Identity checks that all hold on every file: `rva == contrib_rva + value` (21413/21413);
`thunk_rva == real E9 thunk` (sysCore 1365/1365); name == export 1478/1478.

### 3.4 Symbol hash table
Descriptor at `+0x2CC`. Bucket array = `nbuckets` u32 slots, each `0` or the VA of a
record base; chains hang off record `+0x04`. A freshly linked module (and sysCore) has
one bucket array; a heavily relinked module grows it into **several 1024-slot
segments** (plugPiki: 6). The robust way to find every segment is to scan for runs of
≥512 u32 slots that are all either `0` or a record self-pointer VA (this is what
`ilk.py` does). Walking all chains yields exactly the header count (sysCore 2629,
plugPiki 18407) — a built-in correctness check.

### 3.5 Module (object) record — `0x9C` bytes, followed by its contributions
```
P+0x00  u32  cmdline obj: char* name-as-given;  .lib member: archive member offset
P+0x04  ptr  char* canonical/full path
P+0x08  u32  LINK ORDER index (1-based)
P+0x0C  u32  COFF PointerToSymbolTable of the .obj   (NOT the object's byte size)
P+0x10  u32  NumberOfSymbols
P+0x18  u32  NumberOfSections  (== P+0x1C)
P+0x38  u32  COFF TimeDateStamp
P+0x9C  ...  contributions[nsect], 0x40 bytes each
```
A module record is self-validating: its first contribution's module back-pointer
(`+0x18`) points back at `P`. Note: incremental relinks leave **stale** module records
from earlier generations; dedup by link-order index keeping the record with the most
placed contributions. (Per-symbol TU attribution via `+0x1C` is exact regardless and
is the recommended route to object ownership.)

### 3.6 Section-contribution record — `0x40` bytes (one per obj section)
```
C+0x00  u32  RVA in the output image   (0 = not placed: folded COMDAT / LNK_REMOVE)
C+0x04  u32  IMAGE_SCN characteristics (verbatim from the obj section header)
C+0x08  u32  allocated length (raw size + incremental slack)
C+0x14  u32  slack/pad bytes           => raw size = C+0x08 − C+0x14
C+0x18  ptr  Module*  (owning object)
C+0x1C  ptr  SectionName* (name inline at that record +0x2C)
C+0x24  u32  NumberOfRelocations | (NumberOfLinenumbers << 16)
C+0x30  u32  content checksum (incremental change-detection key)
```
A folded/discarded COMDAT copy is marked by `characteristics & 0x800` (LNK_REMOVE) and
`RVA == 0`; the surviving copy carries the attribution. The placed (`RVA != 0`)
contributions tile each section with 0 overlaps.

### 3.7 The incremental thunk table
`/INCREMENTAL` reserves a block of 5-byte `E9 rel32` jump thunks at the start of
`.text`. A thunk is minted for every **address-referenced** external `.text` symbol
(called, or address-taken via a vtable / function-pointer table), not only exports;
some dead thunks from prior generations also linger. Unthunked exports are data
(sysCore: 113 unthunked = 99 `.rdata` + 14 `.data`). `vtable slots hold thunk RVAs`,
not body RVAs — relevant to any vtable→function mapping.

### 3.8 Byte accounting
Every region is reachable from the header; independent accounting reaches **95.5%**
(sysCore) / **95.7%** (plugPiki) of the file with no unexplained span ≥100 KB. The
residual ~4.5% is per-object COFF section-descriptor detail (relocation/line
sub-streams) not needed for symbol/address/TU recovery. The bulk (11.3 MB for a 1.7 MB
DLL) is the verbatim heap dump — module records + contribution arrays dominate — not a
copy of the image (a `.text` slice appears 0 times in the `.ilk`).

---

## 4. How to extract it

```
1.  read arena_base @ 0x24;  off(VA) = VA - arena_base
2.  read .text VA from the embedded optional header (0x44 + 0x14)
3.  strtab   = off(u32 @ 0x2A8)
4.  find bucket arrays: runs of >=512 u32 slots each 0-or-record-self-ptr
5.  for each slot, follow chain via record+0x04; a record is valid iff u32@R == VA(R+8)
6.  per record: name (union @ +0x08/+0x0C), rva @ +0x20, thunk @ +0x30 (+ .text VA),
    section/type @ +0x14, contrib @ +0x1C -> module @ contrib+0x18  (owning TU)
7.  cross-check: walked count == u32 @ 0x2CC+0x0C
```
Gotchas: exports are thunks — resolve `E9 rel32` or just use `+0x20`; the name field is
a union (short names are inline); `.def`-exported names may be undecorated while the
record keeps the `_cdecl` name (`_name`) — try both; plugPiki's hash is multi-segment;
statics are simply not there.

---

## 5. Relationship to the other build artefacts

| Info | `.obj` | `vc60.pdb` | `<out>.pdb` | **`.ilk`** | `.exp`/`.lib` | `.map` | `.dll` |
|---|:--:|:--:|:--:|:--:|:--:|:--:|:--:|
| External names + RVAs | ✓ | | ✓ | **✓** | exports | ✓ | exports |
| File-local **statics** | ✓ | ✓ | ✓ | **✗** | ✗ | ✗ | ✗ |
| Types / locals / lines / source | via pdb | ✓ | ✓ | **✗** | ✗ | ✗ | ✗ |
| **TU attribution** of each symbol | self | | ✓ | **✓** | ✗ | ✓ (`Lib:Object`) | ✗ |
| Folded-COMDAT copies | | | | **✓** | ✗ | partial | ✗ |
| Link order / full obj inventory incl. lib members | | | | **✓** | ✗ | partial | ✗ |
| Incremental thunk map | | | | **✓** | ✗ | ✗ | (thunks only) |
| Effective link command line | | | | **✓** | ✗ | ✗ | ✗ |
| Raw section bytes | ✓ | | | **✗** | ✗ | ✗ | ✓ |

Coupling: an `.ilk` is only written by a `/INCREMENTAL:YES` link that **also** wrote a
`.pdb` (`/PDB:NONE` disables incremental linking). Deleting the `.pdb` forces a full
relink (`LNK6006`), and the `+0x238` signature keys the triple `{dll, ilk, pdb}`. But
this only constrains *relinking* — the `.ilk`'s content is fully self-describing for
*mining*, and (per lab variant v09) the name+address content is present even when the
link omitted `/DEBUG`. That is exactly why the shipped, `.pdb`-less `.ilk` is so rich.

---

## 6. Confidence and limits

**CERTAIN (answer-keyed):** pointer encoding; symbol record `+0x00/+0x04/+0x08/+0x0C/
+0x10/+0x14/+0x18/+0x1C/+0x20/+0x30/+0x38`; hash-table walk == header count; RVA ==
export body (1478/1478); thunk == export thunk (1365/1365); TU attribution 100% for
obj-defined symbols; module link order; contribution RVA/chars/length/slack; folded ==
`chars&0x800 && rva==0`; statics absent; no size field; string table complete +
deduplicated.

**PROBABLE:** record `+0x24` per-module linked list; `+0x2C` referencing-module;
contribution `+0x30` is a content checksum (algorithm not reversed — not needed).

**Corrected by adversarial review (do not use the earlier forms):** the embedded
command line is the *effective* argv, not verbatim, and omits `.lib`-member objects;
thunks track *address-referenced* symbols (call/vtable/function-pointer) plus dead
incremental leftovers, not "cross-TU calls" specifically; module `+0x0C` is
`PointerToSymbolTable`, not object size.

**Open / not needed for mining:** the exact per-object relocation/line sub-stream
layout (the ~4.5% residual); a clean header-driven module enumeration (the `+0x268`
header slot is not the module table — module records are found by structural scan, and
per-symbol `+0x1C` attribution is the exact route to ownership anyway).

---

## 7. What is worth extracting (recommendation)

Ranked by payoff for the decomp, all recoverable from the shipped `.ilk` + `.dll`:

1. **Per-symbol name → real body RVA** (`+0x20`), thunk-aware. Ground truth for
   ~2.6k sysCore / ~18.4k plugPiki external symbols — this obsoletes the export-RVA
   anchoring and much of the autodraft/vtable/pairing heuristics.
2. **Symbol → owning object / TU** (`+0x1C` → module). 100% for obj-defined symbols;
   replaces the `.ilk`-order / class-home guessing in the pairing tools.
3. **Function vs. data + COMDAT/weak flags** (`+0x14`/`+0x38`) and the **thunk map**
   (`+0x30`) — lets you separate thunks from bodies and identify inline/COMDAT copies.
4. **Object inventory + link order + contributions** — for byte-faithful COMDAT
   ownership (folded copies included) and for `.text` tiling.

**Do not bother mining the `.ilk` for:** file-local statics (absent — recover from the
`.obj`/`.pdb` if you ever obtain them, or from disassembly), per-symbol sizes (no
field; approximate by RVA-sort within a section, accepting over-count across invisible
statics), or any type/local/line/source information (never in the `.ilk`).

Use [`authoring/ilk.py`](authoring/ilk.py) — `--symbols out.csv` / `--modules out.csv`
/ `--validate <dll>`.
