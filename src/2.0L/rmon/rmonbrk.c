#include "common.h"

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonbrk", __rmonSetBreak);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonbrk", __rmonListBreak);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonbrk", __rmonClearBreak);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonbrk", __rmonGetBranchTarget);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonbrk", __rmonSetSingleStep);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonbrk", __rmonGetExceptionStatus);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonbrk", __rmonHitBreak);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonbrk", __rmonHitSpBreak);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonbrk", __rmonHitCpuFault);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonbrk", rmonFindFaultedThreads);
