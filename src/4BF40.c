#include "common.h"

void Hu3DCamSetPositionOrientation(s16 camIndex, Vec* pos, Vec* at, Vec* up);
void Hu3DCamUpdateMtx(s32);
extern f32 D_800CB890_CC490;
extern f32 D_800CE17C_CED7C[];
extern f32 D_800D5210_D5E10;

void omOutView(omObjData* object) {
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
    D_800CE17C_CED7C[0] = pos.x;
    D_800CE17C_CED7C[1] = pos.z;
    D_800CE17C_CED7C[-1] = CRot.y; // actually D_800CE178_CED78?
    D_800CE17C_CED7C[2] = gCameraList->fov[0];
    D_800CE17C_CED7C[3] = D_800D5210_D5E10;
    D_800CE17C_CED7C[4] = D_800CB890_CC490;
    Hu3DCamSetPositionOrientation(0, &pos, &at, &up);
    Hu3DCamUpdateMtx(0);
}

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004B4D4_4C0D4);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004B760_4C360);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004B7B0_4C3B0);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004B904_4C504);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004B984_4C584);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004BC00_4C800);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004BCE4_4C8E4);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004C4C4_4D0C4);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004C76C_4D36C);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004CB44_4D744);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004CD04_4D904);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004CEA4_4DAA4);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004CF00_4DB00);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004CF30_4DB30);

INCLUDE_ASM("asm/nonmatchings/4BF40", func_8004D094_4DC94);
