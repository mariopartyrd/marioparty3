#include "common.h"

void func_8008D2C0_main(HuMtx4F mtx, u16 *perspNorm, f32 fov, f32 aspect, f32 near, f32 far, f32 scale) {
    f32 sincos[2];
    f32 cotangent;
    f32 depthScale;
    f32 clipSum;
    f32 xScale;
    f32 zScale;
    f32 zOffset;

    sincosdf(fov * 0.5f, &sincos[0], &sincos[1]);
    cotangent = sincos[1] / sincos[0];
    depthScale = scale / (near - far);
    clipSum = near + far;
    cotangent *= scale;
    xScale = cotangent / aspect;
    zScale = clipSum * depthScale;
    zOffset = (near + near) * far * depthScale;
    mtx[2][3] = -scale;
    mtx[0][1] = mtx[0][2] = mtx[0][3] = mtx[1][0] = mtx[1][2] = mtx[1][3] =
        mtx[2][0] = mtx[2][1] = mtx[3][0] = mtx[3][1] = mtx[3][3] = 0.0f;
    mtx[1][1] = cotangent;
    mtx[2][2] = zScale;
    mtx[3][2] = zOffset;
    mtx[0][0] = xScale;
    if (perspNorm != NULL) {
        if (clipSum <= 2.0f) {
            *perspNorm = 65535;
        } else {
            *perspNorm = 131072.0f / clipSum;
            if (*perspNorm == 0) {
                *perspNorm = 1;
            }
        }
    }
}
