#include "common.h"

INCLUDE_ASM("asm/nonmatchings/2.0L/os/timerintr", __osTimerServicesInit);

INCLUDE_ASM("asm/nonmatchings/2.0L/os/timerintr", __osTimerInterrupt);

INCLUDE_ASM("asm/nonmatchings/2.0L/os/timerintr", __osSetTimerIntr);

INCLUDE_ASM("asm/nonmatchings/2.0L/os/timerintr", __osInsertTimer);
