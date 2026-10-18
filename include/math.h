#ifndef _MATH_H_
#define _MATH_H_

#include "PR/ultratypes.h"

#define M_E 2.71828182845904523536
#define M_1_E 0.36787944117144232160
#define M_PI 3.14159265358979323846
#define M_PI_2 1.57079632679489661923
#define M_PI_4 0.78539816339744830962
#define M_DTOR (3.14159265358979323846/180.0)
#define M_RTOD 57.2957795130823208768

/* Single-precision constants are rounded independently of the double versions. */
#define M_Ef 2.71828182845904523536f
#define M_1_Ef 0.36787944117144232160f
#define M_PIf 3.14159265358979323846f
#define M_PI_2f 1.57079632679489661923f
#define M_PI_4f 0.78539816339744830962f
#define M_DTORf 0.01745329251994329577f
#define M_RTODf 57.2957795130823208768f

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

/* Application-owned default tolerance used by libhmath's epsilon helpers. */
extern f32 D_800A12A4_main;

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

s32 func_80089820_main(f32 value, f32 threshold);
s32 func_80089860_main(f32 value);

void HuVecNormalize3F(Vec *vec);
void HuVecCross(Vec *out, Vec *a, Vec *b);
void HuVecCopyXYZ(Vec *out, f32 x, f32 y, f32 z);
void HuVecCopy3F(Vec *out, Vec *a);
f32 HuVecGetLengthSqr3F(Vec *vec);
f32 HuVecGetLength3F(Vec *vec);

f32 HuVecDistanceSqr(const Vec *a, const Vec *b);
f32 HuVecDistance(const Vec *a, const Vec *b);

#endif
