#!/usr/bin/env python3
"""Generate a module-definition (.def) file from a PE's export table.

Pins every export to its original ordinal (`@<ord>`) so the recompiled DLL
reproduces the shipped export table byte-for-byte -- which keeps ordinals and
the export directory layout matching under reccmp. Names are the raw MSVC
decorated symbols exactly as they appear in the original binary.

Usage:
    python tools/win/gen_def.py <pe-file> --name sysCore [-o sysCore.def]
"""
from __future__ import annotations

import argparse
import sys

from pe_symbols import parse_exports


def build_def(name: str, exports) -> str:
    lines = [f"LIBRARY {name}", "EXPORTS"]
    for e in sorted(exports, key=lambda x: x.ordinal):
        entry = e.mangled or e.forwarder
        if not entry:
            continue
        if e.forwarder:
            lines.append(f"    {entry}={e.forwarder} @{e.ordinal}")
        else:
            lines.append(f"    {entry} @{e.ordinal}")
    return "\n".join(lines) + "\n"


def main(argv: list[str] | None = None) -> int:
    ap = argparse.ArgumentParser(description="PE export table -> .def")
    ap.add_argument("pe", help="path to the .dll/.exe")
    ap.add_argument("--name", required=True, help="LIBRARY name (e.g. sysCore)")
    ap.add_argument("-o", "--out", help="output .def path (default: stdout)")
    args = ap.parse_args(argv)

    _pe, exports = parse_exports(args.pe)
    text = build_def(args.name, exports)
    if args.out:
        with open(args.out, "w", newline="") as f:
            f.write(text)
        print(f"{args.pe}: {len(exports)} exports -> {args.out}", file=sys.stderr)
    else:
        sys.stdout.write(text)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
