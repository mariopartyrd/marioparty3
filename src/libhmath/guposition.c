#include "common.h"

// Builds a floating-point position matrix from Euler rotation, scale, and translation.
INCLUDE_ASM("asm/nonmatchings/libhmath/guposition", func_80088CB0_main);

// Builds a fixed-point position matrix from Euler rotation, scale, and translation.
INCLUDE_ASM("asm/nonmatchings/libhmath/guposition", func_80088E50_main);

// Builds a floating-point matrix that aligns the negative Z axis to a direction.
INCLUDE_ASM("asm/nonmatchings/libhmath/guposition", func_80089190_main);
