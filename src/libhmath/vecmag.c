#include <PR/ultratypes.h>
#include "math.h"

f32 HuVecGetLengthSqr(f32 x, f32 y, f32 z) {
    return (x * x) + (y * y) + (z * z);
}

f32 mulHuVecGetLength(f32 x, f32 y, f32 z) {
    return HuSqrtf(HuVecGetLengthSqr(x, y, z));
}
