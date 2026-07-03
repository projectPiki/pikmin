"""Export the open IDA database's symbols to the Pikmin Windows-decomp
interchange CSV (rva,kind,size,name_mangled,name,source).

For the Pikmin Windows (VC6/PE) decomp. The IDA database of sysCore.dll holds the
only source of sysCore's internal (non-exported) function labels, hand-made while
reversing the GameCube build. This dumps every function, named datum, and string
as one RVA-keyed row so `merge_symbols.py` can fold it into the master map
alongside the authoritative PE-export table from `pe_symbols.py`.

RVA is image-base-relative (ea - image base), so it stays correct even if IDA
rebased the image. For sysCore/plugPiki the PE image base is 0x10000000, matching
`config/GPIE01_01/win/<name>_symbols.csv`.

How to run (IDAPython, IDA 7.4+ / 9.x):
    File -> Script file... -> pick this script.  It writes <idb-stem>_ida.csv
    next to the .idb and prints the path to the Output window.
    Headless:  ida -A -S"export_symbols.py out.csv" sysCore.dll

Prefers the stored (decorated) name for `name_mangled` and IDA's demangling for
`name`; for data/globals the decorated name is what objdiff needs downstream.
"""
import os

import idaapi
import idautils
import idc

try:
    import ida_bytes
    import ida_funcs
    import ida_name
    import ida_nalt
except ImportError:  # very old IDAPython; degrade gracefully
    ida_bytes = ida_funcs = ida_name = ida_nalt = None


def image_base():
    return idaapi.get_imagebase()


def demangle(name):
    if not name:
        return ""
    disable = idc.get_inf_attr(idc.INF_SHORT_DN) if hasattr(idc, "get_inf_attr") else 0
    out = idc.demangle_name(name, disable)
    return out or name


def func_size(ea):
    f = ida_funcs.get_func(ea) if ida_funcs else None
    if f is not None:
        return f.end_ea - f.start_ea
    return idc.get_func_attr(ea, idc.FUNCATTR_END) - ea


def is_thunk(ea):
    if not ida_funcs:
        return False
    f = ida_funcs.get_func(ea)
    return bool(f and (f.flags & ida_funcs.FUNC_THUNK))


def stored_name(ea):
    """The name IDA stores at ea (decorated/mangled for MSVC C++ symbols)."""
    if ida_name:
        return ida_name.get_name(ea)
    return idc.get_name(ea)


def export_functions(base, rows, seen):
    for ea in idautils.Functions():
        rva = ea - base
        seen.add(rva)
        raw = stored_name(ea)
        if not raw:
            continue  # unnamed sub_ still gives address+size, but no label to carry
        mangled = raw if (raw.startswith("?") or raw.startswith("_")) else ""
        rows.append((rva, "thunk" if is_thunk(ea) else "function",
                     func_size(ea), mangled, demangle(raw), "ida"))


def export_data(base, rows, seen):
    # idautils.Names() yields every user/auto name; keep the data ones we haven't
    # already emitted as functions. Placeholder auto-names are filtered downstream.
    for ea, raw in idautils.Names():
        rva = ea - base
        if rva in seen:
            continue
        flags = ida_bytes.get_flags(ea) if ida_bytes else idc.get_full_flags(ea)
        if ida_bytes and not ida_bytes.is_data(flags):
            continue
        seen.add(rva)
        size = idc.get_item_size(ea)
        is_str = bool(ida_bytes.is_strlit(flags)) if ida_bytes else False
        mangled = raw if (raw.startswith("?") or raw.startswith("_")) else ""
        rows.append((rva, "string" if is_str else "data",
                     size, mangled, demangle(raw), "ida"))


def out_path():
    args = idc.ARGV if hasattr(idc, "ARGV") else []
    if len(args) > 1:
        return args[1]
    idb = idc.get_idb_path() or "symbols.idb"
    stem = os.path.splitext(idb)[0]
    return stem + "_ida.csv"


def main():
    base = image_base()
    rows, seen = [], set()
    export_functions(base, rows, seen)
    export_data(base, rows, seen)
    rows.sort(key=lambda r: r[0])

    path = out_path()
    with open(path, "w") as f:
        f.write("rva,kind,size,name_mangled,name,source\n")
        for rva, kind, size, mangled, name, source in rows:
            # Minimal CSV quoting: signatures contain commas.
            def q(s):
                s = str(s)
                if any(c in s for c in ',"\n'):
                    return '"' + s.replace('"', '""') + '"'
                return s
            f.write("0x%08x,%s,%d,%s,%s,%s\n"
                    % (rva, kind, size, q(mangled), q(name), source))
    print("wrote %d symbols (image_base=0x%08x) -> %s" % (len(rows), base, path))


if __name__ == "__main__":
    main()
