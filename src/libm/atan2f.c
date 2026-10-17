#include "math.h"

extern f32 D_800A46A0[];

f32 atan2f(f32 y, f32 x) {
    f32 ratio;
    f32 factor;
    f32 power;
    f32 term;
    f32 result;
    f32 tolerance;
    f32 angle;
    s32 i;

    if (y == 0.0f) {
        return x > 0.0f ? 0.0f : 3.141592741f;
    }
    if (x == 0.0f) {
        return y > 0.0f ? 1.570796371f : -1.570796371f;
    }
    ratio = y / x;
    if (ratio == 1.0f) {
        return y > 0.0f ? 0.7853981853f : -2.356194496f;
    }
    if (ratio == -1.0f) {
        return x > 0.0f ? -0.7853981853f : 2.356194496f;
    }
    if (ratio > 1.0f || ratio < -1.0f) {
        angle = atan2f(x, y);
        if (x > 0.0f) {
            return 1.570796371f - angle;
        }
        return y > 0.0f ? 1.570796371f - angle : -4.712388992f - angle;
    }

    power = ratio * ratio;
    factor = 1.0f / (1.0f + power);
    power *= factor;
    result = 1.0f;
    term = (power + power) / 3.0f;
    i = 4;
    tolerance = 1.0e-7f;
    for (; i < 100; i += 2) {
        result += term;
        if (term <= tolerance) {
            break;
        }
        term *= power * i * D_800A46A0[i + 1];
    }
    result *= ratio * factor;
    return x > 0.0f ? result : (y > 0.0f ? 3.141592741f + result : -3.141592741f + result);
}

f32 atan2df(f32 y, f32 x) {
    return atan2f(y, x) * 57.29578018f;
}
