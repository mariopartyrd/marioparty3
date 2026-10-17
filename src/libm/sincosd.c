#include "math.h"

extern f64 D_800C94F0_main;

void sincosd(f64 angle, f64 *sine, f64 *cosine) {
    *sine = sind(angle);
    *cosine = HuSqrt(1.0 - *sine * *sine) * D_800C94F0_main;
}
