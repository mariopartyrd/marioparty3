---
name: rename-a-c-file-or-header-file
description: Use this skill when you want to rename a C file and/or a header file. Renaming a C file or associated header (.h) file requires additional steps in decompilation projects or the build will fail.
---

# Rename a C file or a Header File

## Instructions

C files and their associated header files are mapped to specific ROM addresses via the Splat project configuration in `marioparty3.yaml`.

A file will typically have a code segment, such as:

```
# Results in a C file at `src/6B050.c`
- [0x6B050, c]

# Results in a C file at `src/decode.c`
- [0xAE30, c, decode]

# Results in a C file at `src/2.0L/audio/cseq.c`
- [0x6EC30, c, 2.0L/audio/cseq]
```

It may also have data and/or rodata segments. Data segment(s) are mapped to the code via the third argument. The third argument should match the name of the C file.

Examples:

```
- [0xA3380, data, 6B050]
- [0xA8B90, .rodata, 6B050]
```

To rename 6B050.c to foo.c, we would need to do the following:

```
- [0x6B050, c, foo]

- [0xA3380, data, foo]

- [0xA8B90, .rodata, foo]
```

In this example, assuming 6B050.c exists on disk, you would most likely want to manually rename it to foo.c, else the next `./tools/build.sh --splat` call will generate a new foo.c.

When you do a manual file rename, update any INCLUDE_ASM in the file to reference the new file path/name.

After you have made all these updates, run `./tools/build.sh --splat` to verify the build is successful and the ROM checksum matches. If you are doing several changes at once, you can defer running `./tools/build.sh --splat` until you have made all the changes.

## Custom Make Rules

In rare cases a C file will have a custom compiler flags. Be sure to check the project `Makefile` and update the C file's name there also.
