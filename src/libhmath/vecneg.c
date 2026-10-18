#include "common.h"
#include "math.h"

void HuVecNeg(Vec *out, Vec *a) {
    f32 x = -a->x;
    f32 y = -a->y;
    f32 z = -a->z;

    out->x = x;
    out->y = y;
    out->z = z;
}
