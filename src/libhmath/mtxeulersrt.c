#include "common.h"

// Build a fixed-point rotation matrix from Euler angles.
INCLUDE_ASM("asm/nonmatchings/libhmath/mtxeulersrt", func_8008A960_main);

// Build a float Euler rotation matrix with scale and translation.
INCLUDE_ASM("asm/nonmatchings/libhmath/mtxeulersrt", func_8008ABA0_main);
