#include "common.h"
#include "math.h"

void HuVecAdd(Vec *out, Vec *a, Vec *b) {
    f32 x = a->x + b->x;
    f32 y = a->y + b->y;
    f32 z = a->z + b->z;

    out->x = x;
    out->y = y;
    out->z = z;
}
