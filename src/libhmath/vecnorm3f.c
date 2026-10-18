#include "common.h"
#include "math.h"

void HuVecNormalize3F(Vec *const vec) {
    const Vec *input = vec;
    const f32 x = input->x;
    const f32 y = input->y;
    const f32 z = input->z;
    f32 invMag;

    invMag = 1.0f / HuSqrtf((x * x) + (y * y) + (z * z));

    vec->x = invMag * x;
    vec->y = invMag * y;
    vec->z = invMag * z;
}
