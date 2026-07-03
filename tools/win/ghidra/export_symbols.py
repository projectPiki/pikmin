# Export the current Ghidra program's symbols to the Pikmin Windows-decomp
# interchange CSV (rva,kind,size,name_mangled,name,source).
#
# @category Pikmin
# @menupath Tools.Pikmin.Export symbol map
#
# For the Pikmin Windows (VC6/PE) decomp. Ghidra holds the richest labelling of
# plugPiki.dll (the IDA export plus community labels). This dumps every function,
# defined datum, and string as one RVA-keyed row so `merge_symbols.py` can fold it
# into the master map alongside the authoritative PE-export table from
# `pe_symbols.py`.
#
# RVA is image-base-relative (entry - program image base), so it stays correct
# even if the program was rebased in Ghidra. For sysCore/plugPiki the PE image
# base is 0x10000000, matching `config/GPIE01_01/win/<name>_symbols.csv`.
#
# Runs two ways:
#   GUI      - Script Manager -> run (writes next to the project, or prompts).
#   headless - analyzeHeadless <proj-dir> <proj> -process plugPiki.dll \
#                  -scriptPath tools/win/ghidra -postScript export_symbols.py <out.csv>
#
# This is a Jython (Python 2.7) Ghidra script - keep it 2/3-agnostic.
import csv
import os

from ghidra.program.model.symbol import SourceType


def image_base():
    return currentProgram.getImageBase().getOffset()


def rva_of(addr):
    return addr.getOffset() - image_base()


def mangled_at(addr, fallback_name):
    """Best mangled/decorated symbol at addr, if Ghidra kept one.

    Ghidra promotes the demangled signature to the primary symbol but keeps the
    original decorated name as another symbol at the same address. For data/globals
    the decorated name is what objdiff needs, so hunt for a `?`/`_`-prefixed label.
    """
    best = ""
    for sym in currentProgram.getSymbolTable().getSymbols(addr):
        nm = sym.getName()
        if nm == fallback_name:
            continue
        if nm.startswith("?") or nm.startswith("__") or (nm.startswith("_") and "@" in nm):
            # Prefer the longest such candidate (fuller signature).
            if len(nm) > len(best):
                best = nm
    return best


def export_functions(rows, seen):
    fm = currentProgram.getFunctionManager()
    for fn in fm.getFunctions(True):
        if monitor.isCancelled():
            break
        entry = fn.getEntryPoint()
        rva = rva_of(entry)
        seen.add(rva)
        name = fn.getName(True)  # include namespace path
        kind = "thunk" if fn.isThunk() else "function"
        size = fn.getBody().getNumAddresses()
        rows.append((rva, kind, size, mangled_at(entry, fn.getName()), name, "ghidra"))


def export_data(rows, seen):
    listing = currentProgram.getListing()
    for d in listing.getDefinedData(True):
        if monitor.isCancelled():
            break
        addr = d.getAddress()
        rva = rva_of(addr)
        if rva in seen:
            continue  # already covered as a function body
        sym = currentProgram.getSymbolTable().getPrimarySymbol(addr)
        # Skip auto-analysis data with no user/import label; it carries no info.
        if sym is None or sym.getSource() == SourceType.DEFAULT:
            continue
        name = sym.getName()
        kind = "string" if d.hasStringValue() else "data"
        size = d.getLength()
        rows.append((rva, kind, size, mangled_at(addr, name), name, "ghidra"))
        seen.add(rva)


def resolve_out_path():
    args = getScriptArgs()
    if args:
        return args[0]
    prog = currentProgram.getName()
    if prog.lower().endswith(".dll") or prog.lower().endswith(".exe"):
        prog = prog[: prog.rfind(".")]
    default = os.path.join(os.path.expanduser("~"), prog + "_ghidra.csv")
    try:
        f = askFile("Export symbol map", "Save")  # GUI prompt
        return f.getAbsolutePath()
    except Exception:
        return default


def main():
    rows = []
    seen = set()
    export_functions(rows, seen)
    export_data(rows, seen)
    rows.sort(key=lambda r: r[0])

    out = resolve_out_path()
    f = open(out, "wb") if str is bytes else open(out, "w")
    try:
        w = csv.writer(f, lineterminator="\n")
        w.writerow(["rva", "kind", "size", "name_mangled", "name", "source"])
        for rva, kind, size, mangled, name, source in rows:
            w.writerow(["0x%08x" % rva, kind, size, mangled, name, source])
    finally:
        f.close()
    println("wrote %d symbols (image_base=0x%08x) -> %s"
            % (len(rows), image_base(), out))


main()
