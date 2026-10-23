#include "libm.h"

void sincosdf(f32 angle, f32 *sine, f32 *cosine) {
    *sine = sindf(angle);
    *cosine = HuSqrtf(1.0f - *sine * *sine) * D_800C9500_main;
}
