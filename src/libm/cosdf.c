#include "libm.h"

f32 cosdf(f32 angle) {
    f32 period;
    f32 wholeAngle;
    f32 fraction;
    f32 square;
    f32 result;
    s32 index;
    s32 sign = 0;

    period = 360.0f;
    if (0.0f < angle) {
    } else {
        angle = -angle;
    }
    wholeAngle = angle * 0.002777777845f;
    index = (s32)wholeAngle;
    angle -= (f32)index * period;
    if (270.0f < angle) {
        angle -= 270.0f;
    } else if (angle > 90.0f) {
        sign = 1;
        if (angle > 180.0f) {
            angle = 270.0f - angle;
        } else {
            angle -= 90.0f;
        }
    } else {
        angle = 90.0f - angle;
    }
    fraction = angle + 0.5f;
    index = (s32)fraction;
    wholeAngle = (f32)index;
    index = (s32)wholeAngle;
    fraction = angle - wholeAngle;
    fraction *= M_DTORf;
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
