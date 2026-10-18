#include "common.h"

// Build a fixed-point Euler rotation matrix with scale and translation.
INCLUDE_ASM("asm/nonmatchings/libhmath/mtxeulersrt2", func_8008AD60_main);

// Build a float rotation matrix around an arbitrary axis.
INCLUDE_ASM("asm/nonmatchings/libhmath/mtxeulersrt2", func_8008B0E0_main);
