#include "game/camera.h"
#include "include_asm.h"
#include "macros.h"
#include "types.h"

f32 HuMathCos(f32);
f32 HuMathSin(f32);

extern HuCamera* gCameraList;
extern u8 D_800D2008_D2C08;
extern s16 D_800D418E_D4D8E;

INCLUDE_ASM("asm/nonmatchings/camera", Hu3DCamInit);

void func_800123F4_12FF4(void)
{
    D_800D418E_D4D8E = D_800D2008_D2C08;
}

void Hu3DCamSetPositionOrientation(s16 camIndex, Vec * pos, Vec * at, Vec * up)
{
    HuCamera * camera = &gCameraList[camIndex];
    camera->pos = *pos;
    camera->at  = *at;
    camera->up  = *up;
}

void Hu3DCamSetPerspective(s16 camIndex, f32 fov, f32 near, f32 far)
{
    HuCamera * camera = &gCameraList[camIndex];
    camera->fov[0] = fov;
    camera->fov[1] = near;
    camera->fov[2] = far;
    camera->perspNorm = 1;
}

void CameraScissorSet(s16 camIndex, RectF* arg1)
{
    HuCamera * camera = &gCameraList[camIndex];
    camera->screenLeft = arg1->x1;
    camera->screenTop = arg1->y1;
    camera->screenRight = arg1->x2;
    camera->screenBottom = arg1->y2;
}

void CameraViewportSet(s16 camIndex, Vec* arg1, Vec* arg2)
{
    HuCamera * camera = &gCameraList[camIndex];
    camera->screenScale = *arg1;
    camera->screenPos = *arg2;
}

void Hu3DCamUpdateMtx(s16 camIndex)
{
    HuCamera * camera;
    HuCamMtxs * mtxs;

    camera = &gCameraList[camIndex];
    mtxs = &camera->mtxs[D_800D418E_D4D8E];

    guPerspective(&mtxs->perspMtx, &camera->perspNorm, camera->fov[0], (SCREEN_WIDTH / SCREEN_HEIGHT), camera->fov[1], camera->fov[2], 1.0f);
    guLookAt(&mtxs->lookAtMtx, camera->pos.x, camera->pos.y, camera->pos.z, camera->at.x, camera->at.y, camera->at.z, camera->up.x, camera->up.y, camera->up.z);
}

void func_80012640_13240(s16 camIndex, Gfx ** dispList)
{
    HuCamMtxs * camMtx;
    HuCamera * camera;

    camera = &gCameraList[camIndex];
    camMtx = &camera->mtxs[D_800D418E_D4D8E];
    camera->viewports[D_800D418E_D4D8E].vp.vscale[0] = (s16) camera->screenScale.x;
    camera->viewports[D_800D418E_D4D8E].vp.vscale[1] = (s16) camera->screenScale.y;
    camera->viewports[D_800D418E_D4D8E].vp.vscale[2] = (s16) camera->screenScale.z;
    camera->viewports[D_800D418E_D4D8E].vp.vtrans[0] = (s16) camera->screenPos.x;
    camera->viewports[D_800D418E_D4D8E].vp.vtrans[1] = (s16) camera->screenPos.y;
    camera->viewports[D_800D418E_D4D8E].vp.vtrans[2] = (s16) camera->screenPos.z;

    gSPViewport((*dispList)++, &camera->viewports[D_800D418E_D4D8E].vp);
    gSPPerspNormalize((*dispList)++, camera->perspNorm);
    gSPMatrix((*dispList)++, osVirtualToPhysical(&camMtx->perspMtx), G_MTX_PROJECTION | G_MTX_LOAD);
    gSPMatrix((*dispList)++, OS_PHYSICAL_TO_K0(&camMtx->lookAtMtx), G_MTX_LOAD);
}

void func_800127C4_133C4(s16 camIndex, Gfx ** dispList) {
    HuCamera * camera = &gCameraList[camIndex];
    gDPSetScissor((*dispList)++, G_SC_NON_INTERLACE, camera->screenLeft, camera->screenTop, camera->screenRight, camera->screenBottom);
}

void func_80012888_13488(s16 camIndex, void (*arg1)(void), void* arg2)
{
    HuCamera * camera = &gCameraList[camIndex];
    camera->unkA0 = arg1;
    camera->unkA4 = arg2;
}

void func_800128BC_134BC(s16 camIndex, s32 arg1)
{
    gCameraList[camIndex].unkA8 = arg1;
}


void func_800128EC_134EC(s16 camIndex, s32 arg1)
{
    gCameraList[camIndex].unkAC = arg1;
}


void Hu3DCam3DToScreen(s16 camIndex, Vec * worldPos, Vec * outPos) 
{
    f32 x;
    f32 y;
    f32 z;
    f32 projectedX;
    f32 projectedY;
    f32 projectedZ;
    HuCamera * camera;
    HuMtx4F viewMtx;
    
    camera = &gCameraList[camIndex];
    guLookAtF(
        viewMtx, 
        camera->pos.x, 
        camera->pos.y, 
        camera->pos.z, 
        camera->at.x, 
        camera->at.y, 
        camera->at.z, 
        camera->up.x, 
        camera->up.y, 
        camera->up.z
    );

    x = worldPos->x;
    y = worldPos->y;
    z = worldPos->z;
    x -= camera->pos.x;
    y -= camera->pos.y;
    z -= camera->pos.z;
    projectedX = ((x * viewMtx[0][0]) + (y * viewMtx[1][0])) + (z * viewMtx[2][0]);
    projectedY = ((x * viewMtx[0][1]) + (y * viewMtx[1][1])) + (z * viewMtx[2][1]);
    projectedZ = ((x * viewMtx[0][2]) + (y * viewMtx[1][2])) + (z * viewMtx[2][2]);
    x = HuMathSin(camera->fov[0] / 2.0f) / HuMathCos(camera->fov[0] / 2.0f) * projectedZ * ASPECT_RATIO;
    y =  (HuMathSin(camera->fov[0] / 2.0f) / HuMathCos(camera->fov[0] / 2.0f)) * projectedZ;
    outPos->x = (projectedX * (SCREEN_WIDTH_CENTER / (-x))) + SCREEN_WIDTH_CENTER;
    outPos->y = ((projectedY * (SCREEN_HEIGHT_CENTER / y)) + SCREEN_HEIGHT_CENTER);
}

void func_80012B14_13714(s16 camIndex, Vec * worldPos, Vec * outPos) 
{
    f32 x;
    f32 y;
    f32 z;
    f32 projectedX;
    f32 projectedY;
    f32 projectedZ;
    HuCamera * camera;
    HuMtx4F viewMtx;
    f32 f2;
    f32 f4;
    
    camera = &gCameraList[camIndex];
    guLookAtF(
        viewMtx, 
        camera->pos.x, 
        camera->pos.y, 
        camera->pos.z, 
        camera->at.x, 
        camera->at.y, 
        camera->at.z, 
        camera->up.x, 
        camera->up.y, 
        camera->up.z
    );

    x = worldPos->x;
    y = worldPos->y;
    z = worldPos->z;
    x -= camera->pos.x;
    y -= camera->pos.y;
    z -= camera->pos.z;
    projectedX = ((x * viewMtx[0][0]) + (y * viewMtx[1][0])) + (z * viewMtx[2][0]);
    projectedY = ((x * viewMtx[0][1]) + (y * viewMtx[1][1])) + (z * viewMtx[2][1]);
    projectedZ = ((x * viewMtx[0][2]) + (y * viewMtx[1][2])) + (z * viewMtx[2][2]);
    x = HuMathSin(camera->fov[0] / 2.0f) / HuMathCos(camera->fov[0] / 2.0f) * projectedZ * (camera->screenScale.x / camera->screenScale.y);
    y =  (HuMathSin(camera->fov[0] / 2.0f) / HuMathCos(camera->fov[0] / 2.0f)) * projectedZ;
    f2 = camera->screenPos.x / 4.0f;
    outPos->x = (projectedX * (f2 / (-x))) + f2;
    f4 = camera->screenPos.y / 4.0f;
    outPos->y = ((projectedY * (f4 / y)) + f4);
}

INCLUDE_ASM("asm/nonmatchings/camera", func_80012D0C_1390C);

INCLUDE_ASM("asm/nonmatchings/camera", func_80012E54_13A54);

INCLUDE_ASM("asm/nonmatchings/camera", func_80013320_13F20);

INCLUDE_ASM("asm/nonmatchings/camera", func_80013350_13F50);
