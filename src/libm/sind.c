#include "libm.h"

f64 D_800C94F0_main;

f64 sind(f64 angle) {
    f64 term = 1;
    f64 wholeAngle;
    s32 index;
    s32 sign;
    f64 fraction;
    f64 sinTbl;
    f64 cosTbl;
    f64 result;
    s32 toggle;
    s32 termIndex;
    s32 termsRemaining;

    toggle = 1;
    sign = 0;
    wholeAngle = angle * 0.00277777777777777788;
    index = (s32)wholeAngle;
    angle -= (f64)(index * 360);
    if (angle < 0.0) {
        angle += 360.0;
    }

    if (angle < 90.0 || 270.0 < angle) {
        D_800C94F0_main = 1.0;
    } else {
        D_800C94F0_main = -1.0;
    }

    if (180.0 < angle) {
        sign = 1;
        angle -= 180.0;
    }
    if (90.0 < angle) {
        angle = 180.0 - angle;
    }

    fraction = angle + 0.5;
    index = (s32)fraction;
    wholeAngle = (f64)index;
    index = (s32)wholeAngle;
    fraction = angle - wholeAngle;
    fraction *= M_DTOR;

    sinTbl = D_800A49A0_main[index];
    result = sinTbl;
    cosTbl = D_800A49A0_main[90 - index];

    termsRemaining = 8;
    termIndex = 0;
    do {
        term = D_800A4380_main[9 - termsRemaining] * (term * fraction);
        if (-D_800C94E0_main <= term && term <= D_800C94E0_main) {
            break;
        }
        if (toggle) {
            wholeAngle = D_800A4350_main[termIndex] ? term * cosTbl : -term * cosTbl;
            result += wholeAngle;
            toggle = 0;
        } else {
            wholeAngle = D_800A4350_main[termIndex] ? term * sinTbl : -term * sinTbl;
            result += wholeAngle;
            toggle = 1;
        }
        termIndex++;
    } while (--termsRemaining > 0);

    if (sign) {
        wholeAngle = -result;
    } else {
        wholeAngle = result;
    }
    return wholeAngle;
}
