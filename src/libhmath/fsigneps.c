#include "common.h"
#include "math.h"

// Returns the sign of a value using the global epsilon threshold.
s32 func_800897D0_main(f32 value) {
    if (value < -D_800A12A4_main) {
        return -1;
    }
    if (D_800A12A4_main < value) {
        return 1;
    }
    return 0;
}
