#ifndef _GAME_CAMERA_H
#define _GAME_CAMERA_H

#include "ultra64.h"
#include "game/hmfman.h"
#include "math.h"

// Forward declaration to prevent issues with hmfman.h.
struct HmfModel;

typedef struct {
    Mtx perspMtx;
    Mtx lookAtMtx;
} HuCamMtxs;

typedef struct HuCamera {
    /* 0x000 */ u16 perspNorm;
    /* 0x002 */ s16 unk2;
    /* 0x004 */ s16 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00C */ f32 unkC;
    /* 0x010 */ Vec pos;
    /* 0x01C */ Vec at;
    /* 0x028 */ Vec up;
    /* 0x034 */ Vec screenScale;
    /* 0x040 */ Vec screenPos;
    /* 0x04C */ s32 unk4C;
    /* 0x050 */ f32 fov[3];
    /* 0x05C */ f32 unk5C;
    /* 0x060 */ Vp viewports[3];
    /* 0x090 */ f32 screenLeft;
    /* 0x094 */ f32 screenTop;
    /* 0x098 */ f32 screenRight;
    /* 0x09C */ f32 screenBottom;
    /* 0x0A0 */ void (*unkA0)(void*, struct HmfModel*); // TODO: unsure about first arg type.
    /* 0x0A4 */ void* unkA4;
    /* 0x0A8 */ void (*unkA8)(s32);
    /* 0x0AC */ void (*unkAC)(s32);
    /* 0x0B0 */ HuCamMtxs mtxs[3];
} HuCamera; //0x230 in size?

typedef struct RectF {
/* 0x00 */ f32 x1;
/* 0x04 */ f32 y1;
/* 0x08 */ f32 x2;
/* 0x0C */ f32 y2;
} RectF; //sizeof 0x10

void Hu3DCamInit(u32 arg0);
void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamSetPerspective(s16 camIndex, f32 fov, f32 near, f32 far);
void CameraScissorSet(s16 camIndex, RectF* arg1);
void CameraViewportSet(s16 camIndex, Vec* arg1, Vec* arg2);
void Hu3DCamUpdateMtx(s16 camIndex);
void func_80012640_13240(s16 camIndex, Gfx** dispList);
void func_800127C4_133C4(s16 camIndex, Gfx** dispList);
void func_80012888_13488(s16 camIndex, void (*arg1)(void*, struct HmfModel*), void* arg2);

extern HuCamera* gCameraList;

#endif
