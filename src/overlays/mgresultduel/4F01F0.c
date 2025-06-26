#include "common.h"
#include "game/object.h"

typedef struct UnkOmData {
    omObjData* unk_00;
    void (*objFunc)(omObjData*); //func pointer
} UnkOmData;

extern UnkOmData D_80109338_4F3B88_mgresultduel;
extern s8 D_80108E78_4F36C8_mgresultduel;
void func_80106054_4F08A4_mgresultduel(void);
void func_80106544_4F0D94_mgresultduel(omObjData*);
void func_80106270_4F0AC0_mgresultduel(omObjData*);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_801059A0_4F01F0_mgresultduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultduel/4F01F0", D_80108EA0_4F36F0_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80105E90_4F06E0_mgresultduel);

void func_80105FD4_4F0824_mgresultduel(void) {
    if (D_800D530C_D5F0C == 1) {
        if (D_80108E78_4F36C8_mgresultduel == 0) {
            WipeCreateOut(0, 0x14);
            D_80108E78_4F36C8_mgresultduel = 1;
            return;
        }
        if (WipeStatGet() == 0) {
            HuAudSeqFadeOut(30);
            func_8004AB0C_4B70C(30);
            func_80106054_4F08A4_mgresultduel();
            omOvlReturnEx(1);
        }
    }
}

void func_80106054_4F08A4_mgresultduel(void) {
    func_800E52F8_CD0C8_name_81();
    func_800E5000_CCDD0_name_81();
    func_800F64FC_DE2CC_name_81();
}

void func_80106080_4F08D0_mgresultduel(void) {
    omObjData* temp_v0;

    temp_v0 = omAddObj(0x14, 5U, 8U, -1, NULL);
    D_80109338_4F3B88_mgresultduel.unk_00 = temp_v0;
    temp_v0->model[1] = func_8000B108_BD08(0xA011B, 0x2B9);
    func_8001C814_1D414(temp_v0->model[1], 2, 2);
    Hu3DModelScaleSet(temp_v0->model[1], 0.9f, 0.9f, 0.9f);
    temp_v0->model[2] = func_8000B108_BD08(9, 0x2B9);
    Hu3DModelScaleSet(temp_v0->model[2], 2.0f, 1.0f, 2.0f);
    func_8000B460_C060(temp_v0, 0, 0xA011C);
    func_8000B460_C060(temp_v0, 1, 0xA011D);
    func_8000B460_C060(temp_v0, 2, 0xA011E);
    func_8000B460_C060(temp_v0, 3, 0xA011F);
    func_8000B460_C060(temp_v0, 4, 0xA0120);
    func_8001C5B4_1D1B4(temp_v0->model[1], temp_v0->motion[4]);
    func_8001C814_1D414(temp_v0->model[1], 2, 2);
    func_80106850_4F10A0_mgresultduel(temp_v0, -1);
    temp_v0->trans.x = 0.0f;
    temp_v0->trans.y = 0.0f;
    temp_v0->trans.z = 0.0f;
    Hu3DModelPosSet(temp_v0->model[0], temp_v0->trans.x, temp_v0->trans.y, temp_v0->trans.z);
    Hu3DModelPosSet(temp_v0->model[1], 0.0f, 0.0f, 2300.0f);
    Hu3DModelPosSet(temp_v0->model[2], 0.0f, 0.0f, 2300.0f);
    omPrcSetDestructor(0, func_80106544_4F0D94_mgresultduel);
    D_80109338_4F3B88_mgresultduel.objFunc = func_80106270_4F0AC0_mgresultduel;
    while (1) {
        D_80109338_4F3B88_mgresultduel.objFunc(temp_v0);
        HuPrcVSleep();   
    }
}

void func_80106270_4F0AC0_mgresultduel(omObjData* arg0) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106278_4F0AC8_mgresultduel);

void func_80106544_4F0D94_mgresultduel(omObjData* arg0) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_8010654C_4F0D9C_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106560_4F0DB0_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106574_4F0DC4_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106730_4F0F80_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106744_4F0F94_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106850_4F10A0_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106930_4F1180_mgresultduel);

void func_80106B68_4F13B8_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106B70_4F13C0_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106BD8_4F1428_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106C3C_4F148C_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106CA0_4F14F0_mgresultduel);

void func_80106D04_4F1554_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106D0C_4F155C_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80106F38_4F1788_mgresultduel);

void func_80107170_4F19C0_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107178_4F19C8_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_801071E0_4F1A30_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107244_4F1A94_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_801072A8_4F1AF8_mgresultduel);

void func_801074B0_4F1D00_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_801074B8_4F1D08_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_801074DC_4F1D2C_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_8010751C_4F1D6C_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107618_4F1E68_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107654_4F1EA4_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107710_4F1F60_mgresultduel);

void func_80107AF4_4F2344_mgresultduel(void) {
}

void func_80107AFC_4F234C_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107B04_4F2354_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107C74_4F24C4_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80107CA4_4F24F4_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108304_4F2B54_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108318_4F2B68_mgresultduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultduel/4F01F0", D_80108EC0_4F3710_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_801084B0_4F2D00_mgresultduel);

void func_80108818_4F3068_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108820_4F3070_mgresultduel);

void func_80108D28_4F3578_mgresultduel(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108D30_4F3580_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108E04_4F3654_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108E18_4F3668_mgresultduel);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultduel/4F01F0", func_80108E2C_4F367C_mgresultduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultduel/4F01F0", D_80108ED4_4F3724_mgresultduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultduel/4F01F0", D_80108F10_4F3760_mgresultduel);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultduel/4F01F0", D_80108F18_4F3768_mgresultduel);
