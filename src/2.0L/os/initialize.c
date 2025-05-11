#include "common.h"

INCLUDE_ASM("asm/nonmatchings/2.0L/os/initialize", __createSpeedParam);

INCLUDE_ASM("asm/nonmatchings/2.0L/os/initialize", __osInitialize_common);

INCLUDE_ASM("asm/nonmatchings/2.0L/os/initialize", __osInitialize_autodetect);
