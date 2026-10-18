#include "common.h"

// Vec3 near-equal test with an explicit epsilon.
INCLUDE_ASM("asm/nonmatchings/libhmath/vecneareq", func_80089E90_main);

// Vec3 near-equal test using the default epsilon.
INCLUDE_ASM("asm/nonmatchings/libhmath/vecneareq", func_80089F30_main);

// Look-at convenience wrapper using a stack scratch buffer.
INCLUDE_ASM("asm/nonmatchings/libhmath/vecneareq", func_80089FD0_main);
