#include "common.h"
#include "game/object.h"
#include "../ovl_81_name/ovl_81.h"

typedef struct UnkOmData {
    omObjData *unk_00;
    void (*objFunc)(omObjData *); // func pointer
} UnkOmData;

extern UnkOmData D_80109338_mgresultduel;
extern s8 D_80108E78_mgresultduel;
void func_80106054_mgresultduel(void);
void func_80106544_mgresultduel(omObjData *);
void func_80106270_mgresultduel(omObjData *);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_801059A0_mgresultduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultduel/4F01F0", D_80108EA0_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80105E90_mgresultduel);

void func_80105FD4_mgresultduel(void) {
    if (D_800D530C_main == 1) {
        if (D_80108E78_mgresultduel == 0) {
            WipeCreateOut(0, 0x14);
            D_80108E78_mgresultduel = 1;
            return;
        }
        if (WipeStatGet() == 0) {
            HuAudSeqFadeOut(30);
            func_8004AB0C_main(30);
            func_80106054_mgresultduel();
            omOvlReturnEx(1);
        }
    }
}

void func_80106054_mgresultduel(void) {
    MBDBackKill();
    MBDBackClose();
    func_800F64FC_name_81();
}

void func_80106080_mgresultduel(void) {
    omObjData *temp_v0;

    temp_v0 = omAddObj(0x14, 5, 8, -1, NULL);
    D_80109338_mgresultduel.unk_00 = temp_v0;
    temp_v0->model[1] = func_8000B108_main(0xA011B, 0x2B9);
    func_8001C814_main(temp_v0->model[1], 2, 2);
    Hu3DModelScaleSet(temp_v0->model[1], 0.9f, 0.9f, 0.9f);
    temp_v0->model[2] = func_8000B108_main(9, 0x2B9);
    Hu3DModelScaleSet(temp_v0->model[2], 2.0f, 1.0f, 2.0f);
    func_8000B460_main(temp_v0, 0, 0xA011C);
    func_8000B460_main(temp_v0, 1, 0xA011D);
    func_8000B460_main(temp_v0, 2, 0xA011E);
    func_8000B460_main(temp_v0, 3, 0xA011F);
    func_8000B460_main(temp_v0, 4, 0xA0120);
    func_8001C5B4_main(temp_v0->model[1], temp_v0->motion[4]);
    func_8001C814_main(temp_v0->model[1], 2, 2);
    func_80106850_mgresultduel(temp_v0, -1);
    temp_v0->trans.x = 0.0f;
    temp_v0->trans.y = 0.0f;
    temp_v0->trans.z = 0.0f;
    Hu3DModelPosSet(temp_v0->model[0], temp_v0->trans.x, temp_v0->trans.y, temp_v0->trans.z);
    Hu3DModelPosSet(temp_v0->model[1], 0.0f, 0.0f, 2300.0f);
    Hu3DModelPosSet(temp_v0->model[2], 0.0f, 0.0f, 2300.0f);
    omPrcSetDestructor(0, func_80106544_mgresultduel);
    D_80109338_mgresultduel.objFunc = func_80106270_mgresultduel;
    while (1) {
        D_80109338_mgresultduel.objFunc(temp_v0);
        HuPrcVSleep();
    }
}

void func_80106270_mgresultduel(omObjData *arg0) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106278_mgresultduel);

void func_80106544_mgresultduel(omObjData *arg0) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_8010654C_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106560_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106574_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106730_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106744_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106850_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106930_mgresultduel);

void func_80106B68_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106B70_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106BD8_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106C3C_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106CA0_mgresultduel);

void func_80106D04_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106D0C_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106F38_mgresultduel);

void func_80107170_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107178_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_801071E0_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107244_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_801072A8_mgresultduel);

void func_801074B0_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_801074B8_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_801074DC_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_8010751C_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107618_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107654_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107710_mgresultduel);

void func_80107AF4_mgresultduel(void) {
}

void func_80107AFC_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107B04_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107C74_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107CA4_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108304_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108318_mgresultduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultduel/4F01F0", D_80108EC0_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_801084B0_mgresultduel);

void func_80108818_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108820_mgresultduel);

void func_80108D28_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108D30_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108E04_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108E18_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108E2C_mgresultduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultduel/4F01F0", D_80108ED4_mgresultduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultduel/4F01F0", D_80108F10_mgresultduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultduel/4F01F0", D_80108F18_mgresultduel);
