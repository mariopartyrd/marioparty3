#include "common.h"
#include "math.h"

void HuVecAddScaled(Vec *out, Vec *a, f32 scalar, Vec *b) {
    f32 x = a->x + (scalar * b->x);
    f32 y = a->y + (scalar * b->y);
    f32 z = a->z + (scalar * b->z);

    out->x = x;
    out->y = y;
    out->z = z;
}
