#!/usr/bin/env python3
"""
Delete the blank line(s) that follow a reorder-restore pair:

    .set    macro          <- kept
    .set    reorder        <- kept
                           <- removed
                           <- removed

Nothing else is touched.

Usage: strip_nop.py file.s [file.s ...]
"""
import sys


def code(line):
    """The line with comments and surrounding whitespace removed."""
    return line.split("#")[0].strip()


def words(line):
    return code(line).split()


def strip(lines):
    out = []
    removed = 0
    i = 0
    n = len(lines)
    while i < n:
        out.append(lines[i])
        if (words(lines[i]) == [".set", "reorder"]
                and i >= 1 and words(lines[i - 1]) == [".set", "macro"]):
            i += 1
            while i < n and not code(lines[i]):
                i += 1
                removed += 1
            continue
        i += 1
    return out, removed


def main(paths):
    for path in paths:
        with open(path) as f:
            lines = f.readlines()
        out, removed = strip(lines)
        if removed:
            with open(path, "w") as f:
                f.writelines(out)
        print("%s: %d blank line(s) removed" % (path, removed), file=sys.stderr)


if __name__ == "__main__":
    main(sys.argv[1:])