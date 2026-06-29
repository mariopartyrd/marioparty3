#include "common.h"

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmisc", __rmonSetFault);

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmisc", __rmonInit);

void __rmonPanic(void) {
    for (;;) {}
}

INCLUDE_ASM("asm/nonmatchings/2.0L/rmon/rmonmisc", __rmonSetComm);
