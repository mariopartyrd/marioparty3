#include "libm.h"

static f64 threshold = 0.0625;

f64 exp(f64 x) {
    f64 tolerance = D_800C94E0_main;
    f64 term;
    f64 result;
    s32 halvings = 0;
    s32 i;

    if (x == 0) {
        return 1;
    }
    if (x < 0) {
        return 1 / exp(-x);
    }
    while (x > threshold) {
        x *= 0.5;
        tolerance *= 0.5;
        halvings++;
    }
    term = result = 1.0;
    for (i = 1; i < 100; i++) {
        term *= x * D_800A4380_main[i];
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
