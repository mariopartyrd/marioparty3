#include "common.h"

// Tests whether a value lies within plus or minus a threshold.
s32 func_80089820_main(f32 value, f32 threshold) {
    return (-threshold <= value) & (value <= threshold);
}
