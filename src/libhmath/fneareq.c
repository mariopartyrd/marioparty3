#include "common.h"
#include "math.h"

// Tests whether two values are approximately equal.
s32 func_800898A0_main(f32 a, f32 b, f32 threshold) {
    return func_80089820_main(a - b, threshold);
}
