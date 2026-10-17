#include "libm.h"

static f32 threshold = 0.0625f;

f32 expf(f32 x) {
    f32 tolerance = 1.0e-7f;
    f32 term;
    f32 result;
    s32 halvings = 0;
    s32 i;

    if (x == 0.0f) {
        return 1.0f;
    }
    if (x < 0.0f) {
        return 1.0f / expf(-x);
    }
    while (x > threshold) {
        x *= 0.5f;
        tolerance *= 0.5f;
        halvings++;
    }
    term = result = 1.0f;
    for (i = 1; i < 100; i++) {
        term *= x * D_800A46A0[i];
        result += term;
        if (term <= tolerance) {
            break;
        }
    }
    for (i = 0; i < halvings; i++) {
        result *= result;
    }
    return result;
}
