#include "math.h"

extern f64 D_800C94E0_main;
extern f64 D_800A4380_main[];

f64 log(f64 x) {
    f64 power;
    f64 result;
    f64 exponent;
    f64 ratio;
    f64 squared;
    f64 term;
    s32 i;

    if (x == 1.) {
        return 0;
    }
    if (x < 0.5) {
        return -log(1 / x);
    }
    i = 3;
    power = result = 1.;
    exponent = 0.0;
    while (x > 2.71828182845904509) {
        x *= 0.367879441171442334;
        exponent += 1.0;
    }
    ratio = (x - 1) / (x + 1);
    squared = ratio * ratio;
    for (; i < 100; i += 2) {
        power *= squared;
        term = D_800A4380_main[i] * power;
        result += term;
        if (term <= D_800C94E0_main) {
            break;
        }
    }
    ratio = (x - 1) / (x + 1);
    return (ratio + ratio) * result + exponent;
}
