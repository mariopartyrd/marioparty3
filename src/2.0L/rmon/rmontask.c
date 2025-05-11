#include "common.h"

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmontask", __rmonMaskIdleThreadInts);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmontask", __rmonGetTCB);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmontask", __rmonStopUserThreads);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmontask", __rmonListThreads);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmontask", __rmonGetThreadStatus);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmontask", __rmonThreadStatus);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmontask", __rmonStopThread);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmontask", __rmonRunThread);
