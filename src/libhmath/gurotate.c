#include "common.h"

// Builds a floating-point axis-angle rotation matrix.
INCLUDE_ASM("asm/nonmatchings/libhmath/gurotate", func_80088570_main);

// Builds a floating-point scaling matrix.
INCLUDE_ASM("asm/nonmatchings/libhmath/gurotate", func_80088700_main);

// Builds a fixed-point scaling matrix.
INCLUDE_ASM("asm/nonmatchings/libhmath/gurotate", func_80088750_main);

// Builds a floating-point translation matrix.
INCLUDE_ASM("asm/nonmatchings/libhmath/gurotate", func_80088800_main);

// Builds a fixed-point translation matrix.
INCLUDE_ASM("asm/nonmatchings/libhmath/gurotate", func_80088850_main);
