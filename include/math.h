#ifndef _MATH_H_
#define _MATH_H_

#include "PR/ultratypes.h"

#define M_PI 3.14159265358979323846

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec;

typedef struct {
    s32 x;
    s32 y;
    s32 z;
} HuVec3I;

/* Libultra trigonometry takes angles in radians. */
f32 sinf(f32 angle);
f32 cosf(f32 angle);
f32 sqrtf(f32 x);

/* KMC and libhmath square-root entry points remain distinct from libultra. */
f64 sqrt(f64 x);
f32 kmc_sqrtf(f32 x);
f64 HuSqrt(f64 x);
f32 HuSqrtf(f32 x);

/* Scalar libm uses d for degrees and a trailing f for single precision. */
f64 sind(f64 angle);
f32 sindf(f32 angle);
f64 cosd(f64 angle);
f32 cosdf(f32 angle);
void sincosd(f64 angle, f64 *sine, f64 *cosine);
void sincosdf(f32 angle, f32 *sine, f32 *cosine);

/* Inverse trigonometry returns degrees; asin/acos clamp inputs to [-1, 1]. */
f32 asindf(f32 x);
f32 acosdf(f32 x);
f64 atan2d(f64 y, f64 x);
f32 atan2df(f32 y, f32 x);

/* Radian atan2 and the exponential/logarithm functions use conventional names. */
f64 atan2(f64 y, f64 x);
f32 atan2f(f32 y, f32 x);
f64 exp(f64 x);
f32 expf(f32 x);
f64 log(f64 x);
f32 logf(f32 x);

void HuVecCopyXYZ(Vec * out, f32 x, f32 y, f32 z);
void HuVecCopy3F(Vec * out, Vec * a);
f32 HuVecGetLengthSqr3F(Vec * vec);
f32 HuVecGetLength3F(Vec * vec);

f32 HuVecDistanceSqr(Vec *a, Vec *b);
f32 HuVecDistance(Vec *a, Vec *b);

#endif
