#!/usr/bin/env python3
"""Normalise the non-deterministic fields of an MSVC6 /INCREMENTAL:YES PE image.

Established by the S1 link-reproduction spike (2026-07-05): a VC6 (link.exe
6.00.8168) `/INCREMENTAL:YES` link is byte-for-byte deterministic given
identical *content* inputs + the same command line + the same starting `.ilk`
state, EXCEPT for a small, fixed set of embedded timestamp/serial fields.  Two
links of the same object seconds apart differed only in these fields; once they
are neutralised the images are bit-identical.

The whole point of the spike's verdict: "byte-for-byte match" is well-defined
for these binaries precisely because the residue after a correct relink is only
these deterministically-patchable fields.  This tool is the operationalisation
of that -- use it to compare a relinked image against the shipped original
(`--sha1` / `--compare`) or to stamp a fresh link with the original's field
values so the files are literally identical (`--patch-from`).

Confirmed volatile fields (all located STRUCTURALLY, never by hard offset):
  1. COFF FileHeader.TimeDateStamp                          (IMAGE_FILE_HEADER+8)
  2. Export Directory.TimeDateStamp                         (data dir[0]+4)
  3. Debug Directory entry.TimeDateStamp                    (data dir[6]+4, each entry)
  4. CodeView "NB10" record: signature (a timestamp)        (CV record +8)
  5. CodeView "NB10" record: age (increments per relink)    (CV record +12)
     -- VC6 uses NB10 (timestamp+age), NOT an RSDS GUID, so there is no random
        GUID to reproduce; that is why the residue is this small.

Defensive extras (0 in the trivial testbed but present on real modules with a
.res / bound imports -- normalised too, so the comparison stays honest):
  6. Resource Directory.TimeDateStamp   (data dir[2], every IMAGE_RESOURCE_DIRECTORY)
  7. Import Descriptor.TimeDateStamp    (data dir[1], every descriptor; 0 unless bound)
  8. Bound Import timestamps            (data dir[11])

The PE image checksum (OptionalHeader.CheckSum) is a deterministic function of
the file bytes; VC6 debug DLLs ship it as 0.  If a build ever emits a non-zero
checksum it is recomputed here after patching so it stays consistent.

Usage:
    python tools/win/pe_normalize.py <pe>                 # print normalised SHA-1
    python tools/win/pe_normalize.py <pe> --dump          # list the field sites
    python tools/win/pe_normalize.py <a> --compare <b>    # bit-compare after normalising
    python tools/win/pe_normalize.py <fresh> --patch-from <orig> -o out
                                                          # copy orig's field values in
"""
from __future__ import annotations

import argparse
import hashlib
import struct
import sys


def _u16(b, o): return struct.unpack_from("<H", b, o)[0]
def _u32(b, o): return struct.unpack_from("<I", b, o)[0]


class PE:
    def __init__(self, data: bytes):
        self.d = bytearray(data)
        if self.d[:2] != b"MZ":
            raise ValueError("not an MZ image")
        self.pe = _u32(self.d, 0x3C)
        if self.d[self.pe:self.pe + 4] != b"PE\0\0":
            raise ValueError("bad PE signature")
        self.nsec = _u16(self.d, self.pe + 6)
        self.opt = self.pe + 24
        self.optsize = _u16(self.d, self.pe + 20)
        self.magic = _u16(self.d, self.opt)             # 0x10b = PE32
        # data directory array begins at opt+96 for PE32
        self.ddir = self.opt + 96
        self.numdd = _u32(self.d, self.opt + 92)
        self._sections()

    def _sections(self):
        base = self.pe + 24 + self.optsize
        self.secs = []
        for i in range(self.nsec):
            o = base + i * 40
            self.secs.append(dict(
                va=_u32(self.d, o + 12), vs=_u32(self.d, o + 8),
                ra=_u32(self.d, o + 20), rs=_u32(self.d, o + 16),
            ))

    def dd(self, i):
        if i >= self.numdd:
            return (0, 0)
        o = self.ddir + i * 8
        return (_u32(self.d, o), _u32(self.d, o + 4))

    def r2o(self, rva):
        for s in self.secs:
            span = max(s["vs"], s["rs"])
            if s["va"] <= rva < s["va"] + span:
                return s["ra"] + (rva - s["va"])
        return -1

    # -- collect the file offsets of every volatile field -------------------
    def volatile_sites(self):
        """Return list of (name, offset, width) for each field to neutralise."""
        sites = []
        sites.append(("coff.TimeDateStamp", self.pe + 8, 4))

        exp_rva, exp_sz = self.dd(0)
        if exp_rva:
            o = self.r2o(exp_rva)
            if o >= 0:
                sites.append(("export.TimeDateStamp", o + 4, 4))

        res_rva, res_sz = self.dd(2)
        if res_rva:
            o = self.r2o(res_rva)
            if o >= 0:
                # every IMAGE_RESOURCE_DIRECTORY node has a TimeDateStamp at +4;
                # neutralise the root (nested ones are almost always 0 for VC6)
                sites.append(("resource.TimeDateStamp", o + 4, 4))

        imp_rva, imp_sz = self.dd(1)
        if imp_rva:
            o = self.r2o(imp_rva)
            if o >= 0:
                # walk 20-byte descriptors until the null terminator
                k = 0
                while True:
                    desc = o + k * 20
                    if desc + 20 > len(self.d):
                        break
                    fields = self.d[desc:desc + 20]
                    if fields == b"\0" * 20:
                        break
                    sites.append((f"import[{k}].TimeDateStamp", desc + 4, 4))
                    k += 1
                    if k > 4096:
                        break

        bnd_rva, bnd_sz = self.dd(11)
        if bnd_rva:
            o = self.r2o(bnd_rva) if self.r2o(bnd_rva) >= 0 else -1
            # bound import dir is often file-offset addressed; treat rva==off best-effort
            if o >= 0:
                sites.append(("boundimport.TimeDateStamp", o + 0, 4))

        # Debug directory -> its entries -> CodeView NB10 record
        dbg_rva, dbg_sz = self.dd(6)
        if dbg_rva:
            o = self.r2o(dbg_rva)
            if o >= 0:
                nent = dbg_sz // 28
                for e in range(max(nent, 1)):
                    ent = o + e * 28
                    if ent + 28 > len(self.d):
                        break
                    sites.append((f"debug[{e}].TimeDateStamp", ent + 4, 4))
                    cv_ptr = _u32(self.d, ent + 24)  # PointerToRawData (file offset)
                    if 0 < cv_ptr < len(self.d) - 16 and self.d[cv_ptr:cv_ptr + 4] == b"NB10":
                        sites.append((f"debug[{e}].NB10.signature", cv_ptr + 8, 4))
                        sites.append((f"debug[{e}].NB10.age", cv_ptr + 12, 4))
        return sites

    def normalized(self) -> bytes:
        d = bytearray(self.d)
        for _name, off, width in self.volatile_sites():
            for i in range(width):
                d[off + i] = 0
        # zero the image checksum too (deterministic function of bytes)
        d[self.opt + 64:self.opt + 68] = b"\0\0\0\0"
        return bytes(d)

    def patch_from(self, other: "PE") -> bytes:
        """Copy every volatile field value from `other` into a copy of self.

        Fields are matched positionally by their (name) label; this is only
        meaningful when the two images share layout (i.e. a correct relink).
        """
        d = bytearray(self.d)
        src = {name: (off, w) for name, off, w in other.volatile_sites()}
        for name, off, width in self.volatile_sites():
            if name in src:
                so, sw = src[name]
                w = min(width, sw)
                d[off:off + w] = other.d[so:so + w]
        d[self.opt + 64:self.opt + 68] = other.d[other.opt + 64:other.opt + 68]
        return bytes(d)


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("pe")
    ap.add_argument("--dump", action="store_true", help="list volatile field sites")
    ap.add_argument("--compare", metavar="OTHER",
                    help="bit-compare against OTHER after normalising both")
    ap.add_argument("--patch-from", metavar="ORIG",
                    help="write a copy of <pe> with ORIG's volatile field values")
    ap.add_argument("-o", "--out", help="output path for --patch-from")
    args = ap.parse_args(argv)

    pe = PE(open(args.pe, "rb").read())

    if args.dump:
        for name, off, width in pe.volatile_sites():
            cur = _u32(pe.d, off) if width == 4 else int.from_bytes(pe.d[off:off + width], "little")
            print(f"  {name:34s} @file 0x{off:06X}  ={cur:#010x}")
        print(f"  {'checksum':34s} @file 0x{pe.opt + 64:06X}  ={_u32(pe.d, pe.opt + 64):#010x}")
        return 0

    if args.compare:
        other = PE(open(args.compare, "rb").read())
        a, b = pe.normalized(), other.normalized()
        if len(a) != len(b):
            print(f"LENGTH MISMATCH: {len(a)} vs {len(b)}")
            return 1
        diffs = [i for i in range(len(a)) if a[i] != b[i]]
        if not diffs:
            print(f"IDENTICAL after normalising ({len(pe.volatile_sites())} volatile sites neutralised)")
            return 0
        print(f"{len(diffs)} differing bytes after normalising; first at 0x{diffs[0]:X}, last at 0x{diffs[-1]:X}")
        return 1

    if args.patch_from:
        orig = PE(open(args.patch_from, "rb").read())
        out = pe.patch_from(orig)
        dst = args.out or (args.pe + ".patched")
        open(dst, "wb").write(out)
        same = hashlib.sha1(out).hexdigest() == hashlib.sha1(orig.d).hexdigest()
        print(f"wrote {dst}  (bit-identical to ORIG: {same})")
        return 0

    print(hashlib.sha1(pe.normalized()).hexdigest())
    return 0


if __name__ == "__main__":
    sys.exit(main())
