---
name: decompile-function-to-c
description: Use this skill when you want to decompile a function to C code. This skill will help guide you through the assembly code to C code conversion process.
---

## Choose a function to decompile

If you are told specifically which function to decompile, start with that one.

Otherwise, use the `./tools/next_candidate.py` script to find a function that is a good candidate for decompilation.

```
next_candidate.py Usage

python3 tools/next_candidate.py                      # top 50, smallest unblocked first
python3 tools/next_candidate.py 8F320                # scope to a segment/overlay
python3 tools/next_candidate.py --sort biggest --min-size 0x40   # biggest ready functions
python3 tools/next_candidate.py --show-blockers      # list each one's pending callees
python3 tools/next_candidate.py -n 0                 # full best-to-worst list
python3 tools/next_candidate.py --json               # machine-readable
python3 tools/next_candidate.py --ignore ignore_funcs.local.txt  # ignore functions in this file
```

Run `./tools/next_candidate.py --ignore ignore_funcs.local.txt` to identify a good candidate. The first function listed in the output is the best candidate for decompilation. Proceed with trying to match this one.

Do not be alarmed at the number of functions that may be remaining. We should methodically work through them one by one, and not try to cut corners by trying to batch several together.

## Locate where to write the C code

Due to the work we've done to map out C file locations in marioparty3.yaml, a C file should already exist for the function you want to decompile. That C file will contain a line like the following in place of the function you want to decompile:

```c
INCLUDE_ASM("asm/nonmatchings/file", func_80012345_67890);
```

## Decompile the function to C

Replace that line with a normal C function declaration and implementation. For example:

```c
void func_80012345_67890() {
    // Your code here
}
```

As part of this process, you may discover that you need to make other updates in order to successfully decompile the function. This is fine, but if the update is significant, consider isolating it into a separate commit so that it's easier to review the actual decompilation work.

You might also discover that, in the process of finding a match for your intended target function, you find you are confident about how to match other functions. This is fine to do, just be clear in how you organize your commits so that it's easy to review the work.

## Verifying the C code is a match

The following script builds the ROM and checks if the SHA1 checksum matches the original ROM. If it does, then your C code is a perfect match!

```bash
./tools/build.sh
# The last line printed will be "OK" if the checksum matches.
```

## Iterating towards a match

If checksum verification fails after source changes, it could be due to an issue in the function you decompiled, or it could be due to an issue in another function that shares dependencies with the function you decompiled.

Use `python3 tools/asm-differ/diff.py --no-pager <function name>` to diff relevant functions against target assembly from the project root. You must do a build first; this command will not reflect your C code changes until a build is performed.

Based on the results of the diff, think through what the underlying issue might be and update the source code accordingly.

If you make larger changes, like changes to the marioparty3.yaml or symbol_addrs.txt, you need to run `./tools/build.sh --splat` to regenerate files based on those changes.

## Wrap-up steps

### For successful match

#### Formatting

Run the following to ensure that all code files are formatted correctly:

```bash
./tools/format.py
```

#### Double check the build

Run the following to ensure that a clean build has no issues:

```bash
./tools/build.sh --clean --splat
# The last line printed will be "OK" if the checksum matches.
```

If there is some issue, stop and investigate before proceeding.

#### Commit the match

If the function was decompiled successfully and the checksum matches, congratulations! Create a git commit with the following format:

```
Match `<function-name>`

<brief details worth noting, if any>
```

### For a failed match

#### Ignore the function

If there is a reason you don't think future attempts could match the function successfully, you can add it to the `ignore_funcs.local.txt` file in the repo root. This will prevent it from being suggested as a candidate for decompilation in the future.

## Tips

= The top level Makefile sometimes alters the compiler flags for specific files. - Most game code is -O1. - libultra code is usually -O2, and was a custom build that may have alterations from the standard.

## Acceptable code validation checklist

- Adhere to the general Code Quality Standards.
- No manual pointer arithmetic for known struct fields.
- Struct and array accesses use `->`, `.`, or indexed access where appropriate.
- Function parameters are typed as specifically as the available context allows.
- Struct sizes and field offsets match assembly access patterns.
- `./tools/build.sh` succeeds before the match is considered complete.
