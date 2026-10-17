#include "math.h"

extern f32 D_800A4340_main;
extern f32 D_800A46A0[];

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
    while (x > D_800A4340_main) {
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
