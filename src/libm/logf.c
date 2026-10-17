#include "libm.h"

f32 logf(f32 x) {
    f32 power;
    f32 result;
    f32 exponent;
    f32 ratio;
    f32 squared;
    f32 term;
    s32 i;

    if (x == 1) {
        return 0;
    }
    if (x < 0.5f) {
        return -logf(1 / x);
    }
    i = 3;
    power = result = 1;
    exponent = 0.0;
    while (x > 2.71828182845904509f) {
        x *= 0.367879441171442334f;
        exponent += 1;
    }
    ratio = (x - 1) / (x + 1);
    squared = ratio * ratio;
    for (; i < 100; i += 2) {
        power *= squared;
        term = D_800A46A0[i] * power;
        result += term;
        if (term <= 1.0e-7f) {
            break;
        }
    }
    ratio = (x - 1) / (x + 1);
    return (ratio + ratio) * result + exponent;
}
