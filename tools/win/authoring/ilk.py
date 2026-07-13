#!/usr/bin/env python3
r"""ilk.py -- consolidated reader for the Microsoft Linker Database (``<module>.ilk``)
emitted by Visual C++ 6.0 ``link.exe`` (12.00.8168) under ``/INCREMENTAL:YES``.

This supersedes the ad-hoc extraction previously scattered across ilk_layout.py,
ilk_functions.py and the reconcile/pairing tools: it exposes the whole file through
one ``Ilk`` object. Every offset here was pinned against a hard answer key (the
shipped DLL export tables) and a controlled VC6 build lab; see docs/ILK_FORMAT.md
for the full derivation, evidence, and confidence table.

BIG PICTURE
-----------
The ``.ilk`` is a verbatim dump of the linker's in-memory database, which was mapped
at virtual address ``0x3FFF0000``. Therefore every internal pointer decodes as::

    file_offset = ptr - 0x3FFF0000

There is a SINGLE arena/base (the value ``0x40000000`` that older notes called a
"second base" is just file offset ``0x10000``). At file offset ``0x30`` the file
embeds a verbatim ``IMAGE_FILE_HEADER`` + ``IMAGE_OPTIONAL_HEADER32`` for the output
image, which is the reliable anchor for the arena base (``+0x24``), the string table
(``+0x2A8``) and the symbol hash table (``+0x2CC``).

WHAT IT YIELDS (per the shipped game, which ships .ilk but NO .pdb)
------------------------------------------------------------------
* every EXTERNAL/public symbol's mangled NAME and final image RVA
  (sysCore: 2629 symbols / 1478 exports; plugPiki: 18407 symbols / 3 exports);
* the incremental-link thunk for each thunked symbol (so you can tell the 5-byte
  ``E9`` jump-thunk apart from the real function body it targets);
* each symbol's OWNING OBJECT / translation unit (100% for obj-defined symbols);
* the full object inventory in LINK ORDER, including .lib members not on the
  command line, plus each object's section contributions (with folded-COMDAT copies).

HARD LIMITS (measured, not assumed)
-----------------------------------
* file-local STATICS get no record and their names are absent from the whole file
  -- the symbol table is exactly the COFF *external* set;
* there is NO per-symbol size field (size is only approximable by RVA-sorting within
  a section, which over-counts across the invisible statics);
* no CodeView types / locals / line numbers / source-file names (those needed the .pdb).

Usage:
    python ilk.py <file.ilk>                     # summary
    python ilk.py <file.ilk> --symbols out.csv   # per-symbol CSV
    python ilk.py <file.ilk> --modules out.csv    # per-object + contribution CSV
    python ilk.py <file.ilk> --validate <dll>     # answer-key check vs PE exports
"""
from __future__ import annotations

import csv
import os
import struct
import sys
from collections import defaultdict

# ---- header field offsets (constant across every VC6 .ilk observed) ----------
OFF_BASE = 0x24        # u32  arena virtual base (0x3FFF0000)
OFF_FILEHDR = 0x30     # IMAGE_FILE_HEADER, immediately followed by the optional header
OFF_STRTAB = 0x2A8     # u32  VA of string table; +0x2AC = used size, +0x2B0 = capacity
OFF_HASH = 0x2CC       # symbol hash-table descriptor
REC_SIZE = 0x3C        # symbol record stride (also the minimum inter-record spacing)
MOD_SIZE = 0x9C        # module (object) record size; contributions follow immediately
CONTRIB_SIZE = 0x40    # section-contribution record size

# ---- symbol-record +0x38 flag bits (see docs/ILK_FORMAT.md) ------------------
FLAG_BITS = [
    (0x0001, 'defined'), (0x0002, 'b1'), (0x0004, 'has_contrib'),
    (0x0020, 'comdat'), (0x0080, 'weak'), (0x0100, 'b8'),
    (0x1000, 'lib_ref'), (0x4000, 'imp'),
]


def flag_str(fl: int) -> str:
    out = [nm for bit, nm in FLAG_BITS if fl & bit]
    rem = fl & ~sum(bit for bit, _ in FLAG_BITS)
    if rem:
        out.append('0x%x' % rem)
    return '|'.join(out)


class Ilk:
    """Reader for one .ilk. All ``*_va`` values are arena VAs; use :meth:`off` to map
    a VA to a file offset. Records/tables are decoded lazily via the accessors."""

    def __init__(self, path: str):
        self.path = path
        self.b = open(path, 'rb').read()
        self.n = len(self.b)
        if self.b[:25] != b'Microsoft Linker Database':
            raise ValueError('not a Microsoft Linker Database (.ilk): ' + path)
        self.base = self.u32(OFF_BASE)
        # embedded PE headers (verbatim IMAGE_FILE_HEADER + IMAGE_OPTIONAL_HEADER32)
        (self.machine, self.nsect_img, self.timestamp, self.coff_symtab,
         self.coff_nsym, self.opt_size, self.characteristics) = \
            struct.unpack_from('<HHIIIHH', self.b, OFF_FILEHDR)
        self.image_base = self.u32(OFF_FILEHDR + 20 + 28)   # OptionalHeader.ImageBase
        self.text_va = self.u32(OFF_FILEHDR + 20 + 0x14)    # BaseOfCode == .text VA
        # string table + symbol hash table
        self.strtab = self.off(self.u32(OFF_STRTAB))
        self.strtab_used = self.u32(OFF_STRTAB + 4)
        self.nbuckets = self.u32(OFF_HASH + 0x04)
        self.nsyms_hdr = self.u32(OFF_HASH + 0x0C)
        self.bucket0 = self.off(self.u32(OFF_HASH + 0x38))

    # -- primitive access ------------------------------------------------------
    def u32(self, o):
        if o is None or o < 0 or o + 4 > self.n:
            return None
        return struct.unpack_from('<I', self.b, o)[0]

    def is_ptr(self, v):
        return v is not None and self.base <= v < self.base + self.n

    def off(self, va):
        """VA -> file offset, or None if out of the arena."""
        if not va:
            return None
        t = va - self.base
        return t if 0 <= t < self.n else None

    def cstr(self, o, cap=1024):
        if o is None or not (0 <= o < self.n):
            return None
        e = self.b.find(b'\x00', o, o + cap)
        if e < 0 or e == o:
            return None
        return self.b[o:e].decode('latin1')

    # -- symbol records --------------------------------------------------------
    def _record_signature(self, R):
        """A symbol record starts with a self-pointer: u32@R == VA(R+8)."""
        return self.u32(R) == (self.base + R + 8) & 0xFFFFFFFF

    def _self_ptr_vas(self):
        vas = set()
        for R in range(0, self.n - REC_SIZE, 4):
            if struct.unpack_from('<I', self.b, R)[0] == (self.base + R + 8) & 0xFFFFFFFF:
                vas.add((self.base + R) & 0xFFFFFFFF)
        return vas

    def bucket_arrays(self):
        """Every symbol-hash bucket array: a run of >=512 u32 slots each 0 or a record
        self-pointer VA. plugPiki grew the table into 6 such 1024-slot segments; a
        freshly linked module (and sysCore) has one."""
        vas = self._self_ptr_vas()
        arrs = []
        o = 0
        while o < self.n - 4:
            v = struct.unpack_from('<I', self.b, o)[0]
            if v in vas or v == 0:
                s = o
                while o < self.n - 4:
                    v = struct.unpack_from('<I', self.b, o)[0]
                    if v in vas or v == 0:
                        o += 4
                    else:
                        break
                if (o - s) // 4 >= 512:
                    arrs.append((s, (o - s) // 4))
            else:
                o += 4
        return arrs

    def record_offsets(self):
        """Authoritative symbol set: the union of every bucket chain (chain link at
        record +0x04). Returns exactly ``nsyms_hdr`` records on every file tested."""
        real, order = set(), []
        for s, sl in self.bucket_arrays():
            for i in range(sl):
                v = self.u32(s + 4 * i)
                guard = 0
                while v:
                    R = self.off(v)
                    if R is None or R in real or not self._record_signature(R):
                        break
                    real.add(R)
                    order.append(R)
                    v = self.u32(R + 0x04)
                    guard += 1
                    if guard > (1 << 21):
                        break
        return order

    def name_of(self, R):
        """IMAGE_SYMBOL Name union at R+0x08: if u32@+0x08==0 the name is a string-table
        offset at +0x0C, else it is an inline short name (<=8 bytes)."""
        if self.u32(R + 0x08) == 0:
            return self.cstr(self.strtab + self.u32(R + 0x0C)) or ''
        raw = self.b[R + 0x08:R + 0x10]
        e = raw.find(b'\x00')
        return raw[:8 if e < 0 else e].decode('latin1')

    def module_name(self, mod_va):
        """Module record VA -> (basename, full). A .lib member stores the archive member
        offset at +0x00 instead of an as-given name pointer."""
        o = self.off(mod_va)
        if o is None:
            return ('', '')
        full = self.cstr(self.off(self.u32(o + 4)), 260) or ''
        given = self.cstr(self.off(self.u32(o)), 260) if self.is_ptr(self.u32(o)) else None
        base = given if given else full.replace('\\', '/').split('/')[-1]
        return (base, full)

    def symbol(self, R):
        contrib_va = self.u32(R + 0x1C)
        co = self.off(contrib_va)
        mod_va = self.u32(co + 0x18) if co is not None else 0
        obj, obj_full = self.module_name(mod_va) if mod_va else ('', '')
        thunk_off = self.u32(R + 0x30)
        return dict(
            rec_off=R,
            name=self.name_of(R),
            value=self.u32(R + 0x10),           # offset within its obj-section contribution
            section=self.u32(R + 0x14) & 0xFFFF,  # 1-based PE section (0xFFFF=ABS, 0=UNDEF)
            coff_type=self.u32(R + 0x14) >> 16,   # 0x20 = FUNCTION
            storage_class=self.u32(R + 0x18),     # 2 EXTERNAL, 0x69 WEAK_EXTERNAL
            rva=self.u32(R + 0x20),               # final image RVA of the real symbol body
            contrib_va=contrib_va,
            contrib_rva=self.u32(co) if co is not None else None,
            contrib_chars=self.u32(co + 4) if co is not None else None,
            contrib_len=self.u32(co + 8) if co is not None else None,
            obj=obj, obj_full=obj_full,           # DEFINING module == TU attribution
            thunk_off=thunk_off,
            thunk_rva=(self.text_va + thunk_off) if thunk_off else 0,
            flags=self.u32(R + 0x38),
            flag_str=flag_str(self.u32(R + 0x38)),
            is_comdat=bool(self.u32(R + 0x38) & 0x20),
            is_weak=bool(self.u32(R + 0x38) & 0x80),
        )

    def symbols(self):
        return [self.symbol(R) for R in record_offsets_sorted(self)]

    # -- module (object) + contribution tables ---------------------------------
    def section_name(self, ptr):
        o = self.off(ptr)
        if o is None:
            return None
        nxt = self.u32(o)
        if self.is_ptr(nxt) and self.off(nxt) == o + 0x2C:
            return self.cstr(o + 0x2C, 64)
        return None

    def modules(self):
        """Every contributing object/lib-member, in link order. A module record is
        self-validating: its first contribution's Module* (+0x18) points back at it."""
        out = []
        for P in range(0, self.n - MOD_SIZE - CONTRIB_SIZE, 4):
            idx = self.u32(P + 8)
            if not (1 <= idx <= 100000):
                continue
            nsec = self.u32(P + 0x18)
            if nsec == 0 or nsec > 500 or self.u32(P + 0x1C) != nsec:
                continue
            if P + MOD_SIZE + nsec * CONTRIB_SIZE > self.n:
                continue
            if self.u32(P + MOD_SIZE + 0x18) != self.base + P:
                continue
            v0, v1 = self.u32(P), self.u32(P + 4)
            full = self.cstr(self.off(v1)) if self.is_ptr(v1) else None
            if full is None:
                continue
            if self.is_ptr(v0):
                given, kind, arch = self.cstr(self.off(v0)), 'cmdline', None
            else:
                given, kind, arch = None, 'lib', v0
            out.append(dict(
                base=P, index=idx, kind=kind, arch_off=arch,
                name=full, name_as_given=given, nsect=nsec,
                coff_symtab_ptr=self.u32(P + 0x0C),   # COFF PointerToSymbolTable (NOT size)
                nsym=self.u32(P + 0x10), timestamp=self.u32(P + 0x38),
            ))
        # A heavily-relinked module keeps stale module records from earlier incremental
        # generations; the live set is one record per link-order index, so dedup keeping
        # the record with the most PLACED contributions (rva != 0).
        best = {}
        for m in out:
            placed = sum(1 for c in self.contributions(m) if c['rva'])
            if m['index'] not in best or placed > best[m['index']][0]:
                best[m['index']] = (placed, m)
        return [m for _placed, m in sorted(best.values(), key=lambda pm: pm[1]['index'])]

    def contributions(self, m):
        cs = []
        for i in range(m['nsect']):
            C = m['base'] + MOD_SIZE + i * CONTRIB_SIZE
            alloc = self.u32(C + 0x08)
            pad = self.u32(C + 0x14)
            chars = self.u32(C + 0x04)
            cs.append(dict(
                off=C, index=i + 1, module=m['base'],
                rva=self.u32(C),                       # 0 => not placed (folded COMDAT / LNK_REMOVE)
                chars=chars, alloc=alloc, pad=pad,
                raw=(alloc - pad) if (alloc is not None and pad is not None) else None,
                section=self.section_name(self.u32(C + 0x1C)),
                nreloc=(self.u32(C + 0x24) or 0) & 0xFFFF,
                nline=(self.u32(C + 0x24) or 0) >> 16,
                checksum=self.u32(C + 0x30),
                folded=bool((chars or 0) & 0x800) or self.u32(C) == 0,
            ))
        return cs


def record_offsets_sorted(ilk: Ilk):
    return ilk.record_offsets()


def add_size_by_sort(syms):
    """Approximate per-symbol size: next symbol's RVA minus this one's, within each PE
    section. Exact only where no invisible file-local static sits between two records."""
    bysec = defaultdict(list)
    for s in syms:
        bysec[s['section']].append(s)
    for _sec, lst in bysec.items():
        lst.sort(key=lambda s: s['rva'])
        for i, s in enumerate(lst):
            s['size_by_sort'] = (lst[i + 1]['rva'] - s['rva']) if i + 1 < len(lst) else None


# ---- PE export answer key (for --validate) -----------------------------------
def pe_exports(dll):
    data = open(dll, 'rb').read()
    e = struct.unpack_from('<I', data, 0x3C)[0]
    opt, optsz = e + 24, struct.unpack_from('<H', data, e + 20)[0]
    nsec = struct.unpack_from('<H', data, e + 6)[0]
    sh = opt + optsz
    # PE section header: +8 VirtualSize (Misc), +12 VirtualAddress, +20 PointerToRawData
    secs = [(struct.unpack_from('<I', data, sh + 40 * i + 12)[0],   # VirtualAddress
             struct.unpack_from('<I', data, sh + 40 * i + 8)[0],    # VirtualSize
             struct.unpack_from('<I', data, sh + 40 * i + 20)[0])   # PointerToRawData
            for i in range(nsec)]

    def r2o(rva):
        for va, vs, raw in secs:
            if va <= rva < va + max(vs, 0x1000):
                o = raw + (rva - va)
                return o if 0 <= o < len(data) else None
        return None

    o = r2o(struct.unpack_from('<I', data, opt + 96)[0])
    nname = struct.unpack_from('<I', data, o + 24)[0]
    afun, aname, aord = (r2o(struct.unpack_from('<I', data, o + k)[0]) for k in (28, 32, 36))
    out = {}
    for i in range(nname):
        nrva = struct.unpack_from('<I', data, aname + 4 * i)[0]
        ordi = struct.unpack_from('<H', data, aord + 2 * i)[0]
        frva = struct.unpack_from('<I', data, afun + 4 * ordi)[0]
        no = r2o(nrva)
        out[data[no:data.index(b'\x00', no)].decode('latin1')] = frva

    def resolve(frva):
        oo = r2o(frva)
        if oo is not None and oo + 5 <= len(data) and data[oo] == 0xE9:
            return frva + 5 + struct.unpack_from('<i', data, oo + 1)[0], True
        return frva, False
    return out, resolve


def _validate(ilk, syms, dll):
    exp, resolve = pe_exports(dll)
    byname = {s['name']: s for s in syms}

    def lookup(nm):
        return byname.get(nm) or byname.get('_' + nm)
    rva_ok = th_ok = th_tot = norec = 0
    for nm, frva in exp.items():
        body, isth = resolve(frva)
        s = lookup(nm)
        if s is None:
            norec += 1
            continue
        if s['rva'] == body:
            rva_ok += 1
        if isth:
            th_tot += 1
            if s['thunk_off'] and ilk.text_va + s['thunk_off'] == frva:
                th_ok += 1
    print('VALIDATE %s: %d exports' % (os.path.basename(dll), len(exp)))
    print('  export has a record   : %d/%d (no record: %d)' % (len(exp) - norec, len(exp), norec))
    print('  rec.rva == real body  : %d/%d' % (rva_ok, len(exp) - norec))
    print('  rec.thunk == export   : %d/%d' % (th_ok, th_tot))


SYM_COLS = ['rec_off', 'name', 'rva', 'value', 'section', 'coff_type', 'storage_class',
            'flags', 'flag_str', 'is_comdat', 'is_weak', 'thunk_off', 'thunk_rva',
            'size_by_sort', 'obj', 'obj_full', 'contrib_va', 'contrib_rva',
            'contrib_chars', 'contrib_len']
MOD_COLS = ['index', 'kind', 'name', 'name_as_given', 'nsect', 'nsym',
            'coff_symtab_ptr', 'timestamp']


def _hex(v):
    return ('0x%x' % v) if isinstance(v, int) else v


def main(argv):
    if not argv:
        raise SystemExit(__doc__)
    path = argv[0]
    sym_csv = mod_csv = validate = None
    i = 1
    while i < len(argv):
        a = argv[i]
        if a == '--symbols':
            sym_csv = argv[i + 1]; i += 2
        elif a == '--modules':
            mod_csv = argv[i + 1]; i += 2
        elif a == '--validate':
            validate = argv[i + 1]; i += 2
        else:
            i += 1

    ilk = Ilk(path)
    arrs = ilk.bucket_arrays()
    syms = ilk.symbols()
    add_size_by_sort(syms)
    syms.sort(key=lambda s: (s['rva'] if s['rva'] is not None else 0, s['name']))
    mods = ilk.modules()

    print('%s  %d bytes  base=0x%08x  strtab=0x%x (%d B)  .text VA=0x%x'
          % (os.path.basename(path), ilk.n, ilk.base, ilk.strtab, ilk.strtab_used, ilk.text_va))
    print('symbols: %d walked / %d header (match=%s) via %d bucket segment(s)'
          % (len(syms), ilk.nsyms_hdr, len(syms) == ilk.nsyms_hdr, len(arrs)))
    print('  functions (type 0x20): %d   thunked: %d   comdat: %d'
          % (sum(s['coff_type'] == 0x20 for s in syms),
             sum(1 for s in syms if s['thunk_off']),
             sum(1 for s in syms if s['is_comdat'])))
    print('  attributed to a TU   : %d/%d   distinct objects: %d'
          % (sum(1 for s in syms if s['obj']), len(syms), len({s['obj'] for s in syms if s['obj']})))
    # Authoritative object inventory is the per-symbol +0x1C attribution above; the raw
    # module-record scan over-counts stale incremental generations on relinked files.
    print('raw module records (incl. stale relink gens): %d  [use per-symbol obj for ownership]'
          % len(mods))

    if sym_csv:
        with open(sym_csv, 'w', newline='', encoding='utf-8') as fh:
            w = csv.DictWriter(fh, fieldnames=SYM_COLS, extrasaction='ignore')
            w.writeheader()
            for s in syms:
                w.writerow({k: _hex(s.get(k)) for k in SYM_COLS})
        print('wrote', sym_csv)
    if mod_csv:
        with open(mod_csv, 'w', newline='', encoding='utf-8') as fh:
            w = csv.writer(fh)
            w.writerow(['mod_index', 'kind', 'object', 'link_order', 'contrib_i',
                        'section', 'rva', 'raw_size', 'alloc', 'folded', 'checksum'])
            for m in mods:
                for c in ilk.contributions(m):
                    w.writerow([m['index'], m['kind'], m['name'], m['index'], c['index'],
                                c['section'], _hex(c['rva']), _hex(c['raw']), _hex(c['alloc']),
                                int(c['folded']), _hex(c['checksum'])])
        print('wrote', mod_csv)
    if validate:
        _validate(ilk, syms, validate)


if __name__ == '__main__':
    main(sys.argv[1:])
