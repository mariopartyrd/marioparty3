#include "common.h"

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonregs", __rmonGetGRegisters);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonregs", __rmonSetGRegisters);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonregs", __rmonGetFRegisters);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonregs", __rmonSetFRegisters);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonregs", rmonGetRcpRegister);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonregs", __rmonGetSRegs);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonregs", __rmonSetSRegs);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonregs", __rmonGetVRegs);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonregs", __rmonSetVRegs);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonregs", __rmonGetRegisterContents);
