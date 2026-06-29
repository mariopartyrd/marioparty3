---
name: rename-a-function
description: Use this skill when you want to rename a function. Renaming a function requires additional steps in decompilation projects or the build will fail.
---

# Rename a function

Create a mapping from the old function name to the new function name in `symbol_addrs.txt`. For example, if we wanted to rename `func_8006D0D0_6DCD0` to `foo`, we would add the following line to `symbol_addrs.txt`:

```
foo = 0x8006D0D0;
```

Look to place that entry near other functions in the same file or with similar addresses. This will help maintain readability and organization in the symbol file.

If a C file exists that includes an `INCLUDE_ASM` line for the function, update the name there as well.

Example:

```
-INCLUDE_ASM("asm/nonmatchings/2.0L/audio/6DCD0", func_8006D0D0_6DCD0);
+INCLUDE_ASM("asm/nonmatchings/2.0L/audio/6DCD0", foo);
```

After you have made all these updates, run `./tools/build.sh --splat` to verify the build is successful and the ROM checksum matches. If you are doing several changes at once, you can defer running `./tools/build.sh --splat` until you have made all the changes.
