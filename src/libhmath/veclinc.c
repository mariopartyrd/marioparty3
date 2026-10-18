#include "common.h"
#include "math.h"

void HuVecLinearComb(Vec *out, f32 scaleA, Vec *a, f32 scaleB, Vec *b) {
    f32 x = (scaleA * a->x) + (scaleB * b->x);
    f32 y = (scaleA * a->y) + (scaleB * b->y);
    f32 z = (scaleA * a->z) + (scaleB * b->z);

    out->x = x;
    out->y = y;
    out->z = z;
}

void HuVecLinearComb2D(Vec *out, Vec *scale, Vec *a, Vec *b) {
    f32 scaleX;
    f32 scaleY;
    f32 x;
    f32 y;
    f32 z;

    scaleX = scale->x;
    scaleY = scale->y;

    x = (scaleX * a->x) + (scaleY * b->x);
    y = (scaleX * a->y) + (scaleY * b->y);
    z = (scaleX * a->z) + (scaleY * b->z);

    out->x = x;
    out->y = y;
    out->z = z;
}
