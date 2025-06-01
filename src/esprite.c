#include "game/esprite.h"

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ char unk08[8];
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ char unk18[0xC];
} D_800CD1DC_CDDDC_Struct; // Size 0x24

extern u16 D_800C951C_CA11C;
extern u16 D_800CB8BC_CC4BC;
extern D_800CD1DC_CDDDC_Struct* D_800CD1DC_CDDDC;
extern s16 D_800D5438_D6038;

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000B7A0_C3A0);

s16 func_8000B838_C438(s32 arg0) {
    void* temp_v0;
    s16 temp_s0;

    temp_v0 = DataRead(arg0);
    temp_s0 = func_80055810_56410(temp_v0);
    HuMemMemoryFreePerm(temp_v0);
    return temp_s0;
}

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000B880_C480);

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BA00_C600);

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BA30_C630);

void func_8000BB54_C754(u16 arg0) {
    HuSprAttrReset(D_800CD1DC_CDDDC[arg0].unk04, 0, 0x8000);
}

void func_8000BB94_C794(u16 arg0) {
    HuSprAttrSet(D_800CD1DC_CDDDC[arg0].unk04, 0, 0x8000);
}

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BBD4_C7D4);

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BBFC_C7FC);

void func_8000BC48_C848(u16 arg0, u16 arg1) {
    D_800CD1DC_CDDDC_Struct* temp = &D_800CD1DC_CDDDC[arg0];

    HuSprAttrSet(temp->unk04, 0, arg1);
}

void func_8000BC88_C888(u16 arg0, u16 arg1) {
    D_800CD1DC_CDDDC_Struct* temp = &D_800CD1DC_CDDDC[arg0];

    HuSprAttrReset(temp->unk04, 0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BCC8_C8C8);

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BD08_C908);

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BD50_C950);

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BD94_C994);

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BDDC_C9DC);

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BE1C_CA1C);

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BE5C_CA5C);

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BEAC_CAAC);

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BF00_CB00);

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BF48_CB48);

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BF8C_CB8C);

s16 InitEspriteSlot(s16 arg0, u16 arg1, u16 arg2) {
    D_800CD1DC_CDDDC_Struct* temp_s0;
    s16 temp_s3;
    s16 temp_v0;

    if (D_800CB8BC_CC4BC == D_800C951C_CA11C) {
        return -1;
    }
    D_800CB8BC_CC4BC++;
    temp_s3 = D_800D5438_D6038;
    temp_s0 = &D_800CD1DC_CDDDC[temp_s3];
    D_800D5438_D6038 = temp_s0->unk02;
    temp_s0->unk04 = temp_v0 = HuSprGrpCreate(1, 0);
    temp_s0->unk00 |= 1;
    temp_s0->unk06 = arg0;
    temp_s0->unk10 = temp_s0->unk14 = 1.0f;
    func_80055458_56058(temp_v0, 0, 0x100);
    HuSprAttrReset(temp_v0, 0, 0xFFFF);
    HuSprAttrSet(temp_v0, 0, 0x1000);
    HuSprScaleSet(temp_v0, 0, 1.0f, 1.0f);
    func_800550F4_55CF4(temp_v0, 0, arg2);
    func_80055024_55C24(temp_v0, 0, arg0, arg1);
    HuSprPriSet(temp_v0, 0, 10);
    if (arg2 == 0) {
        func_80054FF8_55BF8(temp_v0, 0, 0);
    }
    return temp_s3;
}

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000C184_CD84);
