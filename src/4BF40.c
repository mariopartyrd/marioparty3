#include "common.h"
#include "game/camera.h"

extern f32 D_800CB890_main;
extern f32 D_800CCF98_main[];
extern f32 D_800CE17C_main[];
extern f32 D_800D04B8_main[][6];
extern f32 D_800D4198_main[];
extern f32 D_800D5210_main;
extern omObjData *D_800CE194_main;
extern s32 D_800D6AB8_main;

void func_8004CF00_main(omObjData *);

void omOutView(omObjData *object) {
    Vec pos, at, up;
    f32 rot_x = CRot.x;
    f32 rot_y = CRot.y;

    pos.x = Center.x + HuMathSin(rot_y) * HuMathCos(rot_x) * CZoom;
    pos.y = Center.y + -HuMathSin(rot_x) * CZoom;
    pos.z = Center.z + HuMathCos(rot_y) * HuMathCos(rot_x) * CZoom;
    at.x = Center.x;
    at.y = Center.y;
    at.z = Center.z;
    up.x = HuMathSin(rot_y) * HuMathSin(rot_x);
    up.y = HuMathCos(rot_x);
    up.z = HuMathCos(rot_y) * HuMathSin(rot_x);
    D_800CE17C_main[0] = pos.x;
    D_800CE17C_main[1] = pos.z;
    D_800CE17C_main[-1] = CRot.y; // actually D_800CE178_main?
    D_800CE17C_main[2] = gCameraList->fov[0];
    D_800CE17C_main[3] = D_800D5210_main;
    D_800CE17C_main[4] = D_800CB890_main;
    Hu3DCamSetPositionOrientation(0, &pos, &at, &up);
    Hu3DCamUpdateMtx(0);
}

void omOutViewMulti(omObjData *object) {
    u8 i;

    for (i = 0; i < object->work[0]; i++) {
        Vec pos, at, up;
        f32 rot_x = CRotM[i].x;
        f32 rot_y = CRotM[i].y;

        pos.x = CenterM[i].x + HuMathSin(rot_y) * HuMathCos(rot_x) * CZoomM[i];
        pos.y = CenterM[i].y + -HuMathSin(rot_x) * CZoomM[i];
        pos.z = CenterM[i].z + HuMathCos(rot_y) * HuMathCos(rot_x) * CZoomM[i];
        at.x = CenterM[i].x;
        at.y = CenterM[i].y;
        at.z = CenterM[i].z;
        up.x = HuMathSin(rot_y) * HuMathSin(rot_x);
        up.y = HuMathCos(rot_x);
        up.z = HuMathCos(rot_y) * HuMathSin(rot_x);
        D_800D04B8_main[i][1] = pos.x;
        D_800D04B8_main[i][2] = pos.z;
        D_800D04B8_main[i][0] = CRotM[i].y;
        D_800D04B8_main[i][3] = gCameraList[i].fov[0];
        D_800D04B8_main[i][4] = D_800CCF98_main[i];
        D_800D04B8_main[i][5] = D_800D4198_main[i];
        Hu3DCamSetPositionOrientation(i, &pos, &at, &up);
        Hu3DCamUpdateMtx(i);
    }
}

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004B760_main);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004B7B0_main);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004B904_main);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004B984_main);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004BC00_main);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004BCE4_main);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004C4C4_main);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004C76C_main);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004CB44_main);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004CD04_main);

void func_8004CEA4_main() {
    D_800CE194_main = omAddObj(0x7FD8, 0, 0, -1, func_8004CF00_main);
    omSetStatBit(D_800CE194_main, 0xA0);
    D_800CE194_main->work[0] = D_800D6AB8_main;
}

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004CF00_main);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004CF30_main);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004D094_main);
