#include "common.h"
#include "game/camera.h"

extern u8 D_80097660_main;
extern u8 D_80097661_main;
extern s32 D_800CE178_main; // TODO: type correctly
void func_80020E94_main(void *, struct HmfModel *);

typedef struct UnkC1F0 {
    char unk_00[0x18];
} UnkC1F0;

extern UnkC1F0 D_800D04B8_main[];

void func_8000B5F0_main(u8 arg0) {
    D_80097660_main = arg0;
    Hu3DCamInit(D_80097660_main);
    gCameraList[0].fov[0] = 45.0f;
    D_80097661_main = 0;
}

s32 func_8000B638_main(void) {
    s32 temp_s0;

    temp_s0 = D_80097661_main;
    func_80012888_main(D_80097661_main, &func_80020E94_main, &D_800CE178_main);
    D_80097661_main++;
    return temp_s0;
}

void func_8000B690_main(s32 arg0) {
    s32 i;

    D_80097660_main = arg0;
    Hu3DCamInit(D_80097660_main);

    for (i = 0; i < D_80097660_main; i++) {
        gCameraList[i].fov[0] = 45.0f;
    }

    D_80097661_main = 0;
}

s32 func_8000B710_main(s32 arg0) {
    s32 i;

    for (i = 0; i < arg0; i++) {
        func_80012888_main(i, &func_80020E94_main, &D_800D04B8_main[i]);
        D_80097661_main++;
    }

    return D_80097661_main;
}
