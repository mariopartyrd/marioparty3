#include "common.h"

void HuVecSubtract(Vec* arg0, Vec* arg1, Vec* arg2) {
    f32 x = arg1->x - arg2->x;
    f32 y = arg1->y - arg2->y;
    f32 z = arg1->z - arg2->z;

    arg0->x = x;
    arg0->y = y;
    arg0->z = z;
}
