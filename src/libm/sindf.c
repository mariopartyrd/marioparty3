#include "libm.h"

f32 D_800C9500_main;

f32 sindf(f32 angle) {
    f32 period;
    f32 wholeAngle;
    f32 fraction;
    f32 square;
    f32 result;
    s32 index;
    s32 sign = 0;

    period = 360.0f;
    wholeAngle = angle * 0.002777777845f;
    index = (s32)wholeAngle;
    angle -= (f32)index * period;
    if (angle < 0.0f) {
        angle += 360.0f;
    }

    if (angle < 90.0f || 270.0f < angle) {
        D_800C9500_main = 1.0f;
    } else {
        D_800C9500_main = -1.0f;
    }

    if (180.0f < angle) {
        sign = 1;
        angle -= 180.0f;
    }
    if (90.0f < angle) {
        angle = 180.0f - angle;
    }

    fraction = angle + 0.5f;
    index = (s32)fraction;
    wholeAngle = (f32)index;
    index = (s32)wholeAngle;
    fraction = angle - wholeAngle;
    fraction *= 0.01745329238f;
    square = fraction * fraction;

    result = D_800A4830_main[index] * (1.0f - (0.125f * square * (4.0f + square))) +
             D_800A4830_main[90 - index] * fraction;
    if (sign != 0) {
        fraction = -result;
    } else {
        fraction = result;
    }
    return fraction;
}
