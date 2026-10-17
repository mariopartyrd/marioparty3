#include "math.h"

extern f64 D_800C94E0_main;
extern f64 D_800A4380_main[];

f64 atan2(f64 y, f64 x) {
    f64 ratio;
    f64 squared;
    f64 factor;
    f64 power;
    f64 term;
    f64 result;
    f64 tolerance;
    f64 angle;
    s32 i;

    if (y == 0.0) {
        return x > 0.0 ? 0.0 : M_PI;
    }
    if (x == 0.0) {
        return y > 0.0 ? M_PI / 2 : -M_PI / 2;
    }
    ratio = y / x;
    if (ratio == 1.0) {
        return y > 0.0 ? M_PI / 4 : -3 * M_PI / 4;
    }
    if (ratio == -1.0) {
        return x > 0.0 ? -M_PI / 4 : 3 * M_PI / 4;
    }
    if (ratio > 1.0 || ratio < -1.0) {
        angle = atan2(x, y);
        if (x > 0.0) {
            return M_PI / 2 - angle;
        }
        return y > 0.0 ? M_PI / 2 - angle : -3 * M_PI / 2 - angle;
    }

    squared = ratio * ratio;
    factor = 1.0 / (1.0 + squared);
    power = squared * factor;
    result = 1.0;
    term = (power + power) / 3.0;
    i = 4;
    tolerance = D_800C94E0_main;
    for (; i < 100; i += 2) {
        result += term;
        if (term <= tolerance) {
            break;
        }
        term *= power * i * D_800A4380_main[i + 1];
    }
    result *= ratio * factor;
    return x > 0.0 ? result : (y > 0.0 ? M_PI + result : -M_PI + result);
}

f64 atan2d(f64 y, f64 x) {
    return atan2(y, x) * 57.2957795130823229;
}
