#include "common.h"
#include "game/camera.h"

extern u8 D_80097660_98260;
extern u8 D_80097661_98261;
extern s32 D_800CE178_CED78; //TODO: type correctly
void func_80020E94_21A94(void); //TODO: get correct signature

typedef struct UnkC1F0 {
    char unk_00[0x18];
} UnkC1F0;

extern UnkC1F0 D_800D04B8_D10B8[];

void func_8000B5F0_C1F0(u8 arg0) {
    D_80097660_98260 = arg0;
    Hu3DCamInit(D_80097660_98260);
    gCameraList[0].fov[0] = 45.0f;
    D_80097661_98261 = 0;
}

s32 func_8000B638_C238(void) {
    s32 temp_s0;

    temp_s0 = D_80097661_98261;
    func_80012888_13488(D_80097661_98261, &func_80020E94_21A94, &D_800CE178_CED78);
    D_80097661_98261++;
    return temp_s0;
}

void func_8000B690_C290(s32 arg0) {
    s32 i;

    D_80097660_98260 = arg0;
    Hu3DCamInit(D_80097660_98260);

    for (i = 0; i < D_80097660_98260; i++) {
        gCameraList[i].fov[0] = 45.0f;
    }

    D_80097661_98261 = 0;
}

s32 func_8000B710_C310(s32 arg0) {
    s32 i;
    
    for (i = 0; i < arg0; i++) {
        func_80012888_13488(i, &func_80020E94_21A94, &D_800D04B8_D10B8[i]);
        D_80097661_98261++;
    }

    return D_80097661_98261;
}
