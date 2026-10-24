#include "common.h"
#include "math.h"

f32 HuVecGetLength3F(Vec *vec) {
    return HuSqrtf(HuVecGetLengthSqr3F(vec));
}
