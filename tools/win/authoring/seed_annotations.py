#!/usr/bin/env python3
"""Seed reccmp `// FUNCTION:` / `// GLOBAL:` annotations into the source tree from
a module's master symbol map.

For the Pikmin Windows (VC6/PE) decomp. reccmp pairs an original address with a
recompiled function by reading a `// FUNCTION: <MODULE> 0x<va>` marker placed
directly above the function's definition (and `// GLOBAL:` above a datum). Placing
5000+ of those by hand is the bottleneck; this walks `config/GPIE01_01/win/<name>_map.csv`
and drops each marker above the matching definition automatically.

The matcher is deliberately CONSERVATIVE - a wrong annotation makes reccmp compare
the wrong function, which is worse than a missing one. So it only writes when a
symbol resolves to exactly ONE definition site; every unresolved or ambiguous
symbol is reported for a human to place by hand. It is also idempotent (never
double-annotates) and dry-run by default.

How it finds a definition: a tolerant, dependency-free scan builds an index of
every function/data definition in the source, tracking namespace/class scope by
brace depth so it can fully-qualify both out-of-line (`void A::b() {`) and in-class
inline (`int b() {` inside `class A`) definitions. Symbols are matched by qualified
name (suffix-tolerant, since a demangled name may carry namespaces an out-of-line
definition omits) and disambiguated by argument count.

Usage:
    # dry run: report what would be annotated for sysCore, no writes
    python tools/win/authoring/seed_annotations.py --target sysCore \
        --map config/GPIE01_01/win/sysCore_map.csv \
        --src src/sysCommon --src src/sysDolphin --src include

    # actually write the markers, and dump a report of the leftovers
    python tools/win/authoring/seed_annotations.py --target sysCore --map ... --src ... \
        --apply --report build/win/seed_sysCore.txt

`--kind` limits to function|data (default both). `--filter <regex>` restricts to
symbols whose name matches. Module id in the marker = --target upper-cased
(reccmp `--paths` mode), override with --module.
"""
from __future__ import annotations

import argparse
import csv
import os
import re
import sys
from dataclasses import dataclass

# --------------------------------------------------------------------------- #
# Source blanking: neutralise comments, string/char literals, and preprocessor
# directives so the brace/paren scanner never trips over them. Newlines are kept
# so byte offsets still map back to line numbers.
# --------------------------------------------------------------------------- #


def blank_code(s: str) -> str:
    out = []
    i, n = 0, len(s)
    at_line_start = True
    while i < n:
        c = s[i]
        if c == "/" and i + 1 < n and s[i + 1] == "/":
            out.append("  ")
            i += 2
            while i < n and s[i] != "\n":
                out.append(" ")
                i += 1
        elif c == "/" and i + 1 < n and s[i + 1] == "*":
            out.append("  ")
            i += 2
            while i < n and not (s[i] == "*" and i + 1 < n and s[i + 1] == "/"):
                out.append("\n" if s[i] == "\n" else " ")
                i += 1
            if i < n:
                out.append("  ")
                i += 2
        elif c in '"\'':
            q = c
            out.append(" ")
            i += 1
            while i < n and s[i] != q:
                if s[i] == "\\" and i + 1 < n:
                    out.append("  ")
                    i += 2
                    continue
                out.append("\n" if s[i] == "\n" else " ")
                i += 1
            if i < n:
                out.append(" ")
                i += 1
        elif at_line_start and c == "#":
            # Blank the whole preprocessor logical line (handle \ continuation).
            while i < n:
                if s[i] == "\n":
                    if out and False:
                        pass
                    break
                if s[i] == "\\" and i + 1 < n and s[i + 1] == "\n":
                    out.append(" \n")
                    i += 2
                    continue
                out.append(" ")
                i += 1
        else:
            out.append(c)
            if c == "\n":
                at_line_start = True
            elif not c.isspace():
                at_line_start = False
            i += 1
            continue
        # reached here only from a blanking branch; recompute at_line_start
        at_line_start = out[-1].endswith("\n") if out else True
    return "".join(out)


# --------------------------------------------------------------------------- #
# Definition index
# --------------------------------------------------------------------------- #
@dataclass
class Def:
    full_name: str      # fully-qualified, e.g. "AyuStack::create"
    method: str         # last component, e.g. "create"
    argc: int
    kind: str           # "function" | "data"
    file: str
    line: int           # 1-based line where the definition's declarator starts
    indent: str


_KEYWORDS = {
    "if", "for", "while", "switch", "catch", "return", "sizeof", "do", "else",
    "namespace", "class", "struct", "union", "enum", "typedef", "template",
    "operator", "new", "delete", "throw", "case", "default", "typename",
}

_TRAILERS = re.compile(r"\s*(?:const|volatile|throw\s*\([^)]*\))\s*$")


def count_args(argstr: str) -> int:
    s = argstr.strip()
    if s in ("", "void"):
        return 0
    depth, n = 0, 1
    for ch in s:
        if ch in "(<[":
            depth += 1
        elif ch in ")>]":
            depth -= 1
        elif ch == "," and depth == 0:
            n += 1
    return n


def split_params(text: str):
    """Given text ending in a top-level `(...)`, return (before, argstr) where
    `before` is everything left of the matching '(' and argstr the parameter text.
    Returns None if `text` does not end in a balanced parameter list."""
    text = _TRAILERS.sub("", text.rstrip())
    if not text.endswith(")"):
        return None
    depth, i = 0, len(text) - 1
    while i >= 0:
        if text[i] == ")":
            depth += 1
        elif text[i] == "(":
            depth -= 1
            if depth == 0:
                break
        i -= 1
    if i < 0:
        return None
    return text[:i].rstrip(), text[i + 1 : -1]


_NAME_TAIL = re.compile(
    r"(~?[A-Za-z_]\w*(?:\s*::\s*~?[A-Za-z_]\w*)*(?:\s*::\s*)?operator\s*\S+|"
    r"~?[A-Za-z_]\w*(?:\s*::\s*~?[A-Za-z_]\w*)*)\s*$"
)


def declared_name(before: str):
    """Extract the (possibly qualified) declarator name from the text preceding a
    parameter list - i.e. strip the return type. Returns (cleaned_name, start_index
    within `before`) or None. The offset lets the caller anchor the annotation on
    the line where the NAME actually sits, not the header's first line (which may be
    an access-specifier label or a preceding un-terminated macro call)."""
    m = _NAME_TAIL.search(before.rstrip())
    if not m:
        return None
    name = re.sub(r"\s+", "", m.group(1))
    return name, m.start(1)


def _scope_prefix(stack: list) -> str:
    return "::".join(s for s in stack if s)


class Indexer:
    def __init__(self):
        self.defs: dict[str, list[Def]] = {}   # method -> [Def]

    def add(self, d: Def):
        self.defs.setdefault(d.method, []).append(d)

    def scan_file(self, path: str):
        with open(path, "r", encoding="utf-8", errors="replace") as f:
            raw = f.read()
        code = blank_code(raw)
        # Precompute line-start offsets for offset->line mapping.
        line_starts = [0]
        for i, ch in enumerate(raw):
            if ch == "\n":
                line_starts.append(i + 1)

        def line_of(off: int) -> int:
            import bisect
            return bisect.bisect_right(line_starts, off)  # 1-based

        scope: list[str] = []            # namespace/class names (or "" for anon/other)
        scope_is_class: list[bool] = []  # parallel: is this scope a class/struct body?
        scope_depth: list[int] = []      # inside-depth at which each was pushed
        depth = 0
        func_body_depth = None           # depth of a function body we're skipping
        prev = 0
        for m in re.finditer(r"[;{}]", code):
            i = m.start()
            c = code[i]
            header = code[prev:i]
            prev = i + 1
            if c == ";":
                # A statement at namespace/file scope (not inside a function body or a
                # class body) may be a data definition (`System* gsys;`, `int A::x;`).
                if func_body_depth is None and not (scope_is_class and scope_is_class[-1]):
                    self._maybe_data(header, i, line_of, scope)
                continue
            if c == "}":
                if scope_depth and scope_depth[-1] == depth:
                    scope.pop()
                    scope_is_class.pop()
                    scope_depth.pop()
                if func_body_depth is not None and depth <= func_body_depth:
                    func_body_depth = None
                depth -= 1
                continue
            # c == '{'
            depth += 1
            if func_body_depth is not None:
                continue  # nested block inside a function body: ignore contents
            kind = self._classify(header, i, line_of, scope)
            if kind in ("namespace", "class"):
                scope.append(kind_name(kind, header))
                scope_is_class.append(kind == "class")
                scope_depth.append(depth)
            elif kind == "function":
                func_body_depth = depth  # skip until this body closes
            else:
                # other block (enum/extern/init/control): keep depth, no scope name
                scope.append("")
                scope_is_class.append(False)
                scope_depth.append(depth)

    def _classify(self, header, brace_off, line_of, scope):
        h = re.sub(r"\s+", " ", header).strip()
        nm = re.search(r"\bnamespace\s+(\w+)\s*$", h)
        if nm or re.search(r"\bnamespace\s*$", h):
            return "namespace"
        if re.search(r"\b(class|struct)\s+\w+", h) and "(" not in h.split("{")[0]:
            # a class/struct definition header (not a function returning class ptr)
            if not re.search(r"\)\s*$", h):
                return "class"
        # function definition?
        sp = split_params(header)
        if sp is not None:
            before, argstr = sp
            res = declared_name(before)
            if res and res[0].split("::")[-1].strip("~") not in _KEYWORDS:
                name, npos = res
                full = self._qualify(name, scope)
                # Anchor on the line where the declarator name sits (npos is its
                # offset within `header`, which starts at brace_off - len(header)).
                name_off = brace_off - len(header) + npos
                ln = line_of(name_off)
                self.add(Def(
                    full_name=full, method=name.split("::")[-1], argc=count_args(argstr),
                    kind="function", file=self._cur, line=ln, indent=self._indent_at(ln),
                ))
                return "function"
        return "other"

    def _qualify(self, name: str, scope: list) -> str:
        prefix = _scope_prefix(scope)
        if "::" in name and prefix and name.startswith(prefix.split("::")[-1] + "::"):
            # out-of-line def `A::b` inside namespace/class already named up-stack
            return (prefix + "::" + name) if prefix else name
        if prefix:
            return prefix + "::" + name
        return name

    def _indent_at(self, line: int) -> str:
        ln = self._lines[line - 1] if 0 < line <= len(self._lines) else ""
        return ln[: len(ln) - len(ln.lstrip())]

    _DATA_SKIP = re.compile(
        r"\b(typedef|using|friend|return|extern|template|public|private|protected|"
        r"operator|delete|new|namespace|class|struct|union|enum|case|goto|throw)\b"
    )

    def _maybe_data(self, header, end_off, line_of, scope):
        """Record a namespace/file-scope data DEFINITION (`Type name;`, `Type A::x;`).

        Conservative on purpose: anything with a parameter list, multiple declarators,
        or a disqualifying keyword is skipped rather than risk a wrong GLOBAL marker.
        In-class member *declarations* are excluded by the caller (they duplicate the
        out-of-line definition and would only create ambiguity)."""
        code_part = header.split("=", 1)[0]  # drop any initializer
        if "(" in code_part or "{" in code_part or "}" in code_part:
            return
        if self._DATA_SKIP.search(code_part):
            return
        core = re.sub(r"\[[^\]]*\]", "", code_part)  # strip array bounds
        if "," in core:  # multiple declarators -> ambiguous, skip
            return
        m = _NAME_TAIL.search(core.rstrip())
        if not m:
            return
        if not core[: m.start(1)].strip():  # no type before the name -> not a definition
            return
        name = re.sub(r"\s+", "", m.group(1))
        full = self._qualify(name, scope)
        name_off = end_off - len(header) + m.start(1)
        ln = line_of(name_off)
        self.add(Def(full_name=full, method=name.split("::")[-1], argc=-1,
                     kind="data", file=self._cur, line=ln, indent=self._indent_at(ln)))

    # public entry that wires per-file state
    def index(self, path):
        with open(path, "r", encoding="utf-8", errors="replace") as f:
            self._lines = f.read().splitlines()
        self._cur = path
        self.scan_file(path)


def kind_name(kind: str, header: str) -> str:
    h = re.sub(r"\s+", " ", header).strip()
    if kind == "namespace":
        m = re.search(r"\bnamespace\s+(\w+)", h)
        return m.group(1) if m else ""
    m = re.search(r"\b(?:class|struct)\s+(\w+)", h)
    return m.group(1) if m else ""


# --------------------------------------------------------------------------- #
# Symbol parsing + matching
# --------------------------------------------------------------------------- #
@dataclass
class Symbol:
    va: str
    kind: str
    qualified: str
    method: str
    argc: int
    raw: str


_PLACEHOLDER = re.compile(r"^(?:sub|loc|locret|unk|nullsub|j|off|byte|word|dword|qword|FUN|DAT|LAB)_")


def parse_symbol(row) -> Symbol | None:
    name = row["name"].strip()
    kind = row["kind"]
    if not name or _PLACEHOLDER.match(name):
        return None
    if kind == "function":
        sp = split_params(name)
        if sp is None:
            # A demangled name with no parameter list is an extern "C" / bare free
            # function (e.g. `cosf`, `searchKanjiCode`); match it by name, arg count
            # unknown (-1). Anything else (IDA-sanitised `operatorPlus`, etc.) is skipped.
            if re.fullmatch(r"[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*", name):
                return Symbol(row["va"], "function", name, name.split("::")[-1], -1, name)
            return None
        before, argstr = sp
        qualified = re.sub(r"\s+", "", before)
        if not qualified or "(" in qualified:
            return None
        return Symbol(row["va"], "function", qualified, qualified.split("::")[-1],
                      count_args(argstr), name)
    if kind == "data":
        # demangled data looks like "Type Class::var" or "Type var" (no params)
        m = re.search(r"([A-Za-z_]\w*(?:::[A-Za-z_]\w*)*)\s*$", name.replace("*", " ").replace("&", " "))
        if not m:
            return None
        qualified = m.group(1)
        return Symbol(row["va"], "data", qualified, qualified.split("::")[-1], -1, name)
    return None


def match(sym: Symbol, index: Indexer):
    """Return (Def, reason). reason in {ok, none, ambiguous}."""
    cands = index.defs.get(sym.method, [])
    cands = [d for d in cands if d.kind == sym.kind]
    if not cands:
        return None, "none"

    def q_ok(d: Def) -> bool:
        # A definition may be MORE qualified than the demangled symbol (demangling
        # can drop enclosing namespaces), never less: a bare global `foo` must not
        # match a member `Class::foo`.
        return d.full_name == sym.qualified or d.full_name.endswith("::" + sym.qualified)

    q = [d for d in cands if q_ok(d)]
    if not q:
        return None, "none"

    def argc_ok(d: Def) -> bool:
        # Unknown arg count on either side (-1) can't refute; otherwise must agree.
        # Guards against a lone same-named overload absent from source (e.g. a
        # compiler-generated copy ctor landing on the default ctor).
        return sym.argc < 0 or d.argc < 0 or d.argc == sym.argc

    if len(q) == 1:
        return (q[0], "ok") if argc_ok(q[0]) else (None, "none")
    a = [d for d in q if argc_ok(d)]
    if len(a) == 1:
        return a[0], "ok"
    return None, "ambiguous"


# --------------------------------------------------------------------------- #
# Driver
# --------------------------------------------------------------------------- #
def collect_sources(roots) -> list[str]:
    exts = (".cpp", ".c", ".cc", ".cxx", ".h", ".hpp")
    files = []
    for root in roots:
        if os.path.isfile(root):
            files.append(root)
            continue
        for dp, _, fns in os.walk(root):
            for fn in fns:
                if fn.endswith(exts):
                    files.append(os.path.join(dp, fn))
    return sorted(set(files))


def main(argv=None) -> int:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--target", required=True, help="module name, e.g. sysCore")
    ap.add_argument("--map", required=True, help="the module's master _map.csv")
    ap.add_argument("--src", action="append", required=True, help="source root(s) to scan; repeatable")
    ap.add_argument("--module", help="marker module id (default: --target upper-cased)")
    ap.add_argument("--kind", default="function", choices=["function", "data", "both"])
    ap.add_argument("--filter", help="only symbols whose name matches this regex")
    ap.add_argument("--apply", action="store_true", help="write markers (default: dry run)")
    ap.add_argument("--report", help="write the unmatched/ambiguous list to this file")
    args = ap.parse_args(argv)

    module = args.module or args.target.upper()
    want = {"both": {"function", "data"}}.get(args.kind, {args.kind})
    filt = re.compile(args.filter) if args.filter else None

    print(f"indexing sources under {args.src} ...", file=sys.stderr)
    index = Indexer()
    for path in collect_sources(args.src):
        index.index(path)
    ndefs = sum(len(v) for v in index.defs.values())
    print(f"  {ndefs} definitions indexed", file=sys.stderr)

    matched, none, ambig, skipped, already = [], [], [], 0, 0
    with open(args.map, newline="") as f:
        for row in csv.DictReader(f):
            if row["kind"] not in want:
                continue
            if filt and not filt.search(row["name"]):
                continue
            sym = parse_symbol(row)
            if sym is None:
                skipped += 1
                continue
            d, reason = match(sym, index)
            if reason == "ok":
                matched.append((sym, d))
            elif reason == "ambiguous":
                ambig.append(sym)
            else:
                none.append(sym)

    # Group writes per file, insert bottom-up so earlier line numbers stay valid.
    per_file: dict[str, list] = {}
    for sym, d in matched:
        per_file.setdefault(d.file, []).append((d.line, sym, d))

    written = 0
    for path, items in per_file.items():
        with open(path, "r", encoding="utf-8", errors="replace") as f:
            lines = f.readlines()
        items.sort(key=lambda t: t[0], reverse=True)
        for line, sym, d in items:
            above = lines[line - 2] if line >= 2 else ""
            if re.match(r"\s*// (FUNCTION|GLOBAL):", above):
                already += 1
                continue
            marker = "GLOBAL" if sym.kind == "data" else "FUNCTION"
            text = f"{d.indent}// {marker}: {module} {sym.va}\n"
            if args.apply:
                lines.insert(line - 1, text)
                written += 1
            else:
                written += 1
        if args.apply:
            with open(path, "w", encoding="utf-8", errors="replace", newline="") as f:
                f.writelines(lines)

    verb = "wrote" if args.apply else "would write"
    print(f"\n{args.target}: {verb} {written} markers "
          f"(already-annotated {already}, ambiguous {len(ambig)}, "
          f"unmatched {len(none)}, unparseable {skipped})")

    if args.report:
        with open(args.report, "w", encoding="utf-8") as f:
            f.write(f"# {args.target}: {len(none)} unmatched, {len(ambig)} ambiguous\n\n")
            f.write("## ambiguous (multiple candidate definitions)\n")
            for s in ambig:
                f.write(f"{s.va}\t{s.raw}\n")
            f.write("\n## unmatched (no definition found)\n")
            for s in none:
                f.write(f"{s.va}\t{s.raw}\n")
        print(f"report -> {args.report}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
