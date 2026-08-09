#!/usr/bin/env python3
"""
Find the next good candidate function(s) to decompile.

A good candidate is a not-yet-decompiled function whose callees have already
been decompiled (so you won't get stuck on an unknown helper), and/or which is
small / makes few calls (so it's quick to do).

How it decides "decompiled" vs "pending":

  * PENDING  functions come from the `glabel` functions in
    asm/nonmatchings/ -- each .s there is one function still waiting to be
    written in C. (Plain rodata/data .s files have no `glabel` and are
    skipped.)
  * DECOMPILED functions come from real C function definitions in src/.
    Decompiling a function deletes its .s, so the two sets are complementary.

For every pending function we read the `jal X` calls in its own .s file. A
callee "blocks" the candidate when that callee is itself still pending -- i.e.
it is a glabel in nonmatchings and not (also) defined in src. A callee that is
already decompiled, or that is external (a library builtin, etc.), does not
block.

Candidates are then ranked best-first: fewest blockers, then smallest, then
fewest distinct callees.

Usage:
    python3 tools/next_candidate.py                 # top 50 overall
    python3 tools/next_candidate.py 8F320           # only a segment / overlay
    python3 tools/next_candidate.py -n 0            # everything, best-to-worst
    python3 tools/next_candidate.py --show-blockers # list each one's blockers
    python3 tools/next_candidate.py --sort size      # smallest first
    python3 tools/next_candidate.py --json          # machine-readable
"""

import argparse
import json
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
NONMATCHINGS = ROOT / "asm" / "nonmatchings"
SRC = ROOT / "src"

GLABEL_RE = re.compile(r"^glabel\s+(\w+)\s*$")
# `nonmatching NAME, 0xSIZE`  (rodata `nonmatching NAME` lines have no size)
NONMATCH_SIZE_RE = re.compile(r"^nonmatching\s+(\w+)\s*,\s*(0x[0-9A-Fa-f]+|\d+)\s*$")
# A `jal TARGET` instruction (tail-calls via `jr`/`b` are not captured).
JAL_RE = re.compile(r"\bjal\s+([A-Za-z0-9_]+)")

# Rough detector for a top-level C function definition in src/:
#   <type tokens>  name(args) {
# at column 0, skipping INCLUDE_ASM/GLOBAL_ASM stub lines. Multi-line
# signatures are occasionally missed, but that only weakens the informational
# "decompiled callee" label -- it never affects ranking (see module docstring).
SRC_DEF_RE = re.compile(r"^\w.*?\b([A-Za-z_]\w*)\s*\([^;]*\)\s*\{")
STUB_RE = re.compile(r"INCLUDE_ASM|GLOBAL_ASM")
# Harmless false positives from the definition regex (control keywords).
C_KEYWORDS = {
    "if", "for", "while", "switch", "return", "do", "else", "sizeof",
}


def scan_nonmatchings():
    """Walk every .s under asm/nonmatchings once.

    Returns:
        candidates: name -> {path, size, callees:set, total_calls:int}
        glabel_set: set of every pending-function name (every glabel seen).
    """
    candidates = {}
    glabel_set = set()
    files = sorted(NONMATCHINGS.rglob("*.s"))

    for path in files:
        name = None
        sizes = {}          # name -> size, from `nonmatching NAME, 0xSIZE`
        callees = set()
        total_calls = 0
        try:
            text = path.read_text(errors="replace")
        except OSError:
            continue

        for line in text.splitlines():
            m = GLABEL_RE.match(line)
            if m:
                name = m.group(1)
                continue
            m = NONMATCH_SIZE_RE.match(line)
            if m:
                sizes[m.group(1)] = int(m.group(2), 0)
                continue
            for jm in JAL_RE.finditer(line):
                total_calls += 1
                callees.add(jm.group(1))

        if name is None:
            continue  # pure data/rodata file, not a function

        glabel_set.add(name)
        callees.discard(name)  # ignore self-recursion

        size = sizes.get(name)
        if size is None and len(sizes) == 1:
            size = next(iter(sizes.values()))  # tolerate unnamed size line

        candidates[name] = {
            "path": str(path.relative_to(ROOT)),
            "size": size if size is not None else 0,
            "callees": callees,
            "total_calls": total_calls,
        }

    return candidates, glabel_set


def scan_src_decompiled():
    """Return the set of function names defined as real C in src/."""
    defined = set()
    for path in sorted(SRC.rglob("*.c")):
        try:
            text = path.read_text(errors="replace")
        except OSError:
            continue
        for line in text.splitlines():
            if STUB_RE.search(line):
                continue
            m = SRC_DEF_RE.match(line)
            if m:
                fname = m.group(1)
                if fname not in C_KEYWORDS:
                    defined.add(fname)
    return defined


def load_ignore_names(path):
    """Read an ignore file: one function name per line.

    Supports line comments introduced by '//' or '#' -- either trailing a
    function name or standing alone on their own line -- and blank lines,
    both of which are skipped. Only the first whitespace-delimited token
    left after stripping the comment is taken as the function name.

    A missing file is silently treated as an empty set (nothing ignored),
    so --ignore may point at a file that does not always exist.
    """
    try:
        text = Path(path).read_text(errors="replace")
    except FileNotFoundError:
        return set()
    except OSError as exc:
        sys.exit(f"error: cannot read ignore file {path!r}: {exc}")

    names = set()
    for line in text.splitlines():
        # Drop an inline or full-line comment: from the first marker to EOL.
        for marker in ("//", "#"):
            idx = line.find(marker)
            if idx != -1:
                line = line[:idx]
        token = line.split()
        if token:
            names.add(token[0])
    return names


def classify(candidates, glabel_set, decompiled):
    """Annotate each candidate with its blocking (still-pending) callees."""
    results = []
    for name, info in candidates.items():
        callees = info["callees"]
        blockers = sorted(
            c for c in callees
            if c in glabel_set and c not in decompiled
        )
        results.append({
            "name": name,
            "path": info["path"],
            "size": info["size"],
            "distinct_calls": len(callees),
            "total_calls": info["total_calls"],
            "blockers": blockers,
            "decompiled_callees": sorted(c for c in callees if c in decompiled),
            "external_callees": sorted(
                c for c in callees if c not in glabel_set and c not in decompiled
            ),
        })
    return results


def sort_key(item, mode):
    """Best-first ordering. Blockers always gate first (a function whose deps
    aren't met is never a great next pick); within that:
      blockers (default) -> smallest first  (quickest to decompile)
      biggest            -> largest  first  (most code matched per function)
      size               -> smallest first, ignoring blocker priority"""
    if mode == "size":
        return (item["size"], len(item["blockers"]), item["distinct_calls"], item["name"])
    if mode == "biggest":
        return (len(item["blockers"]), -item["size"], item["distinct_calls"], item["name"])
    return (len(item["blockers"]), item["size"], item["distinct_calls"], item["name"])


def main(argv=None):
    ap = argparse.ArgumentParser(
        description=__doc__,
        formatter_class=argparse.RawDescriptionHelpFormatter,
    )
    ap.add_argument(
        "filter", nargs="?",
        help="substring matched against each function's .s path or name "
             "(e.g. a segment like '8F320', an overlay dir, or '2.0L')",
    )
    ap.add_argument("-n", "--limit", type=int, default=50,
                    help="show the top N candidates (0 = all). Default: 50")
    ap.add_argument("--all", action="store_true",
                    help="show every candidate (alias for -n 0)")
    ap.add_argument("--ignore", metavar="FILE",
                    help="path to a text file of function names to exclude "
                         "from the output. One name per line; lines may carry "
                         "'//' or '#' comments (inline or standalone) and "
                         "blank lines are ignored. A missing file is "
                         "silently treated as empty.")
    ap.add_argument("--sort", choices=["blockers", "size", "biggest"],
                    default="blockers",
                    help="ranking emphasis. 'blockers' (default): unblocked "
                         "then smallest. 'biggest': unblocked then largest "
                         "(most code matched per pick). 'size': smallest "
                         "regardless of blockers.")
    ap.add_argument("--min-size", default="0",
                    help="skip functions smaller than this size "
                         "(e.g. '0x10' to drop 8-byte return-stubs). "
                         "Accepts hex or decimal. Default: 0")
    ap.add_argument("--show-blockers", action="store_true",
                    help="append each candidate's still-pending callees")
    ap.add_argument("--json", action="store_true",
                    help="emit JSON instead of human-readable text")
    args = ap.parse_args(argv)

    if not NONMATCHINGS.is_dir():
        sys.exit(f"error: {NONMATCHINGS} not found (run from the repo root)")

    sys.stderr.write("Scanning asm/nonmatchings and src ...\n")
    candidates, glabel_set = scan_nonmatchings()
    decompiled = scan_src_decompiled()

    # A function that is both a glabel (has a .s) AND defined in src is already
    # decompiled -- its .s is just a stale leftover. Drop it so we never
    # recommend redoing finished work.
    stale = sorted(n for n in candidates if n in decompiled)
    for n in stale:
        del candidates[n]

    results = classify(candidates, glabel_set, decompiled)

    if args.ignore:
        ignore_names = load_ignore_names(args.ignore)
        results = [r for r in results if r["name"] not in ignore_names]

    if args.filter:
        needle = args.filter.lower()
        results = [
            r for r in results
            if needle in r["name"].lower() or needle in r["path"].lower()
        ]

    try:
        min_size = int(args.min_size, 0)
    except ValueError:
        sys.exit(f"error: invalid --min-size value: {args.min_size!r}")
    if min_size > 0:
        results = [r for r in results if r["size"] >= min_size]

    results.sort(key=lambda r: sort_key(r, args.sort))

    limit = 0 if args.all else args.limit
    shown = results if limit <= 0 else results[:limit]

    if args.json:
        json.dump(shown, sys.stdout, indent=2)
        sys.stdout.write("\n")
        return

    total = len(results)
    zero_block = sum(1 for r in results if not r["blockers"])
    sys.stderr.write(
        f"{total} pending function(s)"
        f"{f' matching {args.filter!r}' if args.filter else ''}, "
        f"{zero_block} with no pending callees"
        + (f" ({len(stale)} already-decompiled .s files skipped).\n\n"
           if stale else ".\n\n")
    )

    # Header (to stderr so stdout is just the ranked list).
    sys.stderr.write(
        f"{'#':>4}  {'size':>7}  {'calls':>5}  {'undec':>5}  function\n"
    )
    for i, r in enumerate(shown, 1):
        mark = "*" if not r["blockers"] else " "
        undec = len(r["blockers"])
        sys.stdout.write(
            f"{mark}{i:>3}  {r['size']:>#7x}  {r['distinct_calls']:>5}  "
            f"{undec:>5}  {r['name']}\n"
        )
        if args.show_blockers and r["blockers"]:
            sys.stdout.write(f"        pending callees: {', '.join(r['blockers'])}\n")
        elif args.show_blockers and not r["blockers"]:
            sys.stdout.write("        pending callees: (none -- all calls already decompiled)\n")

    if limit > 0 and total > limit:
        sys.stderr.write(
            f"\nShowing top {limit} of {total}. Use --all (or -n 0) for the full list.\n"
        )


if __name__ == "__main__":
    main()
