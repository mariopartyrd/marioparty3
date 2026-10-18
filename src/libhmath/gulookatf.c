#include "common.h"

#include "math.h"

static inline void Normalize(f32 *x, f32 *y, f32 *z) {
    f32 oldX = *x;
    f32 oldY = *y;
    f32 oldZ = *z;
    f32 length = 1.0f / HuSqrtf(oldX * oldX + oldY * oldY + oldZ * oldZ);
    *x *= length;
    *y *= length;
    *z *= length;
}

static inline void CopyVector(f32 *x, f32 *y, f32 *z, f32 a, f32 b, f32 c) {
    *x = a;
    *y = b;
    *z = c;
}

// Builds a floating-point look-at matrix from eye, target, and up vectors.
void guLookAtF(HuMtx4F mf, f32 xEye, f32 yEye, f32 zEye, f32 xAt, f32 yAt, f32 zAt, f32 xUp, f32 yUp, f32 zUp) {
    f32 xLook, yLook, zLook;
    f32 xRight, yRight, zRight;

    // Retain this inline copy to match the original parameter loads and spills.
    CopyVector(&xUp, &yUp, &zUp, xUp, yUp, zUp);

    xLook = xEye - xAt;
    yLook = yEye - yAt;
    zLook = zEye - zAt;
    Normalize(&xLook, &yLook, &zLook);

    mf[0][2] = xLook;
    mf[1][2] = yLook;
    mf[2][2] = zLook;
    mf[3][2] = -(xEye * xLook + yEye * yLook + zEye * zLook);

    xRight = yUp * zLook - zUp * yLook;
    yRight = zUp * xLook - xUp * zLook;
    zRight = xUp * yLook - yUp * xLook;
    Normalize(&xRight, &yRight, &zRight);

    mf[0][0] = xRight;
    mf[1][0] = yRight;
    mf[2][0] = zRight;
    mf[3][0] = -(xEye * xRight + yEye * yRight + zEye * zRight);

    xUp = yLook * zRight - zLook * yRight;
    yUp = zLook * xRight - xLook * zRight;
    zUp = xLook * yRight - yLook * xRight;
    Normalize(&xUp, &yUp, &zUp);

    mf[0][1] = xUp;
    mf[1][1] = yUp;
    mf[2][1] = zUp;
    mf[3][1] = -(xEye * xUp + yEye * yUp + zEye * zUp);
    mf[0][3] = mf[1][3] = mf[2][3] = 0.0f;
    mf[3][3] = 1.0f;
}
