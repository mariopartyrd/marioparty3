#include "common.h"

// Returns the sign of a value.
s32 func_80089750_main(f32 value) {
    if (value < 0.0f) {
        return -1;
    }
    if (0.0f < value) {
        return 1;
    }
    return 0;
}

// Returns the sign of a value using a caller-supplied threshold.
s32 func_80089790_main(f32 value, f32 threshold) {
    if (value < -threshold) {
        return -1;
    }
    if (threshold < value) {
        return 1;
    }
    return 0;
}
