#include "libm.h"

/* asin in degrees. */
f32 asindf(f32 x) {
    f32 factor;
    f32 term;
    f32 result;
    f32 squared;
    f32 power;
    s32 i;

    if (x == 0.0f) {
        return 0.0f;
    }
    if (1.0f <= x) {
        return 90.0f;
    }
    if (x <= -1.0f) {
        return -90.0f;
    }
    if (0.7070999742f < x || x < -0.7070999742f) {
        return atan2df(x / HuSqrtf(1.0f - x * x), 1.0f);
    }

    squared = x * x;
    result = 1.0f;
    term = 1.0f;
    factor = 2.0f;
    power = 1.0f;
    for (;;) {
        i = (s32)factor;
        term *= (factor - 1.0f) * (factor - 1.0f) * D_800A46A0[i] *
                D_800A46A0[(s32)(factor + 1.0f)];
        power *= squared;
        result += term * power;
        if (term * power < 1.0e-7f) {
            break;
        }
        factor += 2.0f;
    }
    return result * x * 57.29578018f;
}
