#include "common.h"

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmem", __rmonWriteWordTo);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmem", __rmonReadWordAt);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmem", __rmonMemcpy);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmem", __rmonCopyWords);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmem", __rmonReadMem);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmem", __rmonWriteMem);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmem", __rmonListProcesses);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmem", __rmonLoadProgram);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmem", __rmonGetExeName);

INCLUDE_RODATA("asm/nonmatchings/2.0L/rmon/rmonmem", D_800A8900_A9500);

INCLUDE_RODATA("asm/nonmatchings/2.0L/rmon/rmonmem", D_800A8908_A9508);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmem", __rmonGetRegionCount);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmem", __rmonGetRegions);
