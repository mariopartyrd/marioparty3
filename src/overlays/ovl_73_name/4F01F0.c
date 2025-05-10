#include "common.h"
#include "game/object.h"

typedef struct UnkOmData {
    omObjData* unk_00;
    void (*objFunc)(omObjData*); //func pointer
} UnkOmData;

extern UnkOmData D_80109338_4F3B88_name_73;
extern s8 D_80108E78_4F36C8_name_73;
void func_80106054_4F08A4_name_73(void);
void func_80106544_4F0D94_name_73(omObjData*);
void func_80106270_4F0AC0_name_73(omObjData*);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_801059A0_4F01F0_name_73);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_73_name/4F01F0", D_80108EA0_4F36F0_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80105E90_4F06E0_name_73);

void func_80105FD4_4F0824_name_73(void) {
    if (D_800D530C_D5F0C == 1) {
        if (D_80108E78_4F36C8_name_73 == 0) {
            WipeCreateOut(0, 0x14);
            D_80108E78_4F36C8_name_73 = 1;
            return;
        }
        if (WipeStatGet() == 0) {
            func_8004A994_4B594(30);
            func_8004AB0C_4B70C(30);
            func_80106054_4F08A4_name_73();
            omOvlReturnEx(1);
        }
    }
}

void func_80106054_4F08A4_name_73(void) {
    func_800E52F8_CD0C8_name_81();
    func_800E5000_CCDD0_name_81();
    func_800F64FC_DE2CC_name_81();
}

void func_80106080_4F08D0_name_73(void) {
    omObjData* temp_v0;

    temp_v0 = omAddObj(0x14, 5U, 8U, -1, NULL);
    D_80109338_4F3B88_name_73.unk_00 = temp_v0;
    temp_v0->model[1] = func_8000B108_BD08(0xA011B, 0x2B9);
    func_8001C814_1D414(temp_v0->model[1], 2, 2);
    func_8001C1A0_1CDA0(temp_v0->model[1], 0.9f, 0.9f, 0.9f);
    temp_v0->model[2] = func_8000B108_BD08(9, 0x2B9);
    func_8001C1A0_1CDA0(temp_v0->model[2], 2.0f, 1.0f, 2.0f);
    func_8000B460_C060(temp_v0, 0, 0xA011C);
    func_8000B460_C060(temp_v0, 1, 0xA011D);
    func_8000B460_C060(temp_v0, 2, 0xA011E);
    func_8000B460_C060(temp_v0, 3, 0xA011F);
    func_8000B460_C060(temp_v0, 4, 0xA0120);
    func_8001C5B4_1D1B4(temp_v0->model[1], temp_v0->motion[4]);
    func_8001C814_1D414(temp_v0->model[1], 2, 2);
    func_80106850_4F10A0_name_73(temp_v0, -1);
    temp_v0->trans.x = 0.0f;
    temp_v0->trans.y = 0.0f;
    temp_v0->trans.z = 0.0f;
    func_8001C0C4_1CCC4(temp_v0->model[0], temp_v0->trans.x, temp_v0->trans.y, temp_v0->trans.z);
    func_8001C0C4_1CCC4(temp_v0->model[1], 0.0f, 0.0f, 2300.0f);
    func_8001C0C4_1CCC4(temp_v0->model[2], 0.0f, 0.0f, 2300.0f);
    omPrcSetDestructor(0, func_80106544_4F0D94_name_73);
    D_80109338_4F3B88_name_73.objFunc = func_80106270_4F0AC0_name_73;
    while (1) {
        D_80109338_4F3B88_name_73.objFunc(temp_v0);
        HuPrcVSleep();   
    }
}

void func_80106270_4F0AC0_name_73(omObjData* arg0) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80106278_4F0AC8_name_73);

void func_80106544_4F0D94_name_73(omObjData* arg0) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_8010654C_4F0D9C_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80106560_4F0DB0_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80106574_4F0DC4_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80106730_4F0F80_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80106744_4F0F94_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80106850_4F10A0_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80106930_4F1180_name_73);

void func_80106B68_4F13B8_name_73(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80106B70_4F13C0_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80106BD8_4F1428_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80106C3C_4F148C_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80106CA0_4F14F0_name_73);

void func_80106D04_4F1554_name_73(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80106D0C_4F155C_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80106F38_4F1788_name_73);

void func_80107170_4F19C0_name_73(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80107178_4F19C8_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_801071E0_4F1A30_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80107244_4F1A94_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_801072A8_4F1AF8_name_73);

void func_801074B0_4F1D00_name_73(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_801074B8_4F1D08_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_801074DC_4F1D2C_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_8010751C_4F1D6C_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80107618_4F1E68_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80107654_4F1EA4_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80107710_4F1F60_name_73);

void func_80107AF4_4F2344_name_73(void) {
}

void func_80107AFC_4F234C_name_73(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80107B04_4F2354_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80107C74_4F24C4_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80107CA4_4F24F4_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80108304_4F2B54_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80108318_4F2B68_name_73);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_73_name/4F01F0", D_80108EC0_4F3710_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_801084B0_4F2D00_name_73);

void func_80108818_4F3068_name_73(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80108820_4F3070_name_73);

void func_80108D28_4F3578_name_73(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80108D30_4F3580_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80108E04_4F3654_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80108E18_4F3668_name_73);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_73_name/4F01F0", func_80108E2C_4F367C_name_73);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_73_name/4F01F0", D_80108ED4_4F3724_name_73);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_73_name/4F01F0", D_80108F10_4F3760_name_73);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_73_name/4F01F0", D_80108F18_4F3768_name_73);
