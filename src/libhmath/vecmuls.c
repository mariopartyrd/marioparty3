#include "common.h"
#include "math.h"

void HuVecMulScalar(Vec *out, f32 scalar, Vec *a) {
    f32 x = scalar * a->x;
    f32 y = scalar * a->y;
    f32 z = scalar * a->z;

    out->x = x;
    out->y = y;
    out->z = z;
}
