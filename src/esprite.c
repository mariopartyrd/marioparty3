#include "game/esprite.h"
#include "game/data.h"
#include "game/sprite.h"
#include "mallocblock.h"
#include "include_asm.h"

// malloc
void HuMemMemoryFreePerm(void* ptr);

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04; // gid?
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk8;
    /* 0x0A */ s16 unkA; // x center
    /* 0x0C */ s16 unkC; // y center
    /* 0x0E */ s16 unkE;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ char unk18[4];
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ char unk22[2];
} D_800CD1DC_CDDDC_Struct; // Size 0x24

extern u16 D_800C951C_CA11C;
extern u16 D_800CB8BC_CC4BC;
extern D_800CD1DC_CDDDC_Struct* D_800CD1DC_CDDDC; // esprite?
extern s16 D_800D5438_D6038;

void func_8000B7A0_C3A0(void) {
    u16 var_a0;

    func_80052330_52F30();
    D_800CD1DC_CDDDC = HuMemAlloc(0x100 * sizeof(D_800CD1DC_CDDDC_Struct));
    D_800C951C_CA11C = 0x100;
    D_800CB8BC_CC4BC = 0;
    for (var_a0 = 0; var_a0 < 0x100; var_a0++) {
        D_800CD1DC_CDDDC_Struct* temp_v0 = &D_800CD1DC_CDDDC[var_a0];

        temp_v0->unk00 = 0;
        temp_v0->unk02 = var_a0 + 1;
        temp_v0->unk1C = 0xFF;
        temp_v0->unk1E = 0xFF;
        temp_v0->unk20 = 0;
    }
    D_800D5438_D6038 = 0;
}

s16 func_8000B838_C438(s32 arg0) {
    void* temp_v0;
    s16 temp_s0;

    temp_v0 = DataRead(arg0);
    temp_s0 = func_80055810_56410(temp_v0);
    HuMemMemoryFreePerm(temp_v0);
    return temp_s0;
}

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000B880_C480);

void func_8000BA00_C600() {
    func_80056BAC_577AC();
    HuMemFree(D_800CD1DC_CDDDC);
    D_800CD1DC_CDDDC = NULL;
}

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BA30_C630);

// espDispOn?
void func_8000BB54_C754(u16 arg0) {
    HuSprAttrReset(D_800CD1DC_CDDDC[arg0].unk04, 0, 0x8000);
}

// espDispOff?
void func_8000BB94_C794(u16 arg0) {
    HuSprAttrSet(D_800CD1DC_CDDDC[arg0].unk04, 0, 0x8000);
}

// Set sprite center.
void func_8000BBD4_C7D4(u16 spriteId, s16 x, s16 y) {
    D_800CD1DC_CDDDC_Struct *sprite;

    sprite = D_800CD1DC_CDDDC + spriteId;
    sprite->unkA = x;
    sprite->unkC = y;
}

void func_8000BBFC_C7FC(u16 spriteId, s16 arg1) {
    D_800CD1DC_CDDDC_Struct *sprite;

    sprite = D_800CD1DC_CDDDC + spriteId;
    sprite->unk1E = arg1;
    sprite->unk1C = arg1;
    func_80055458_56058(sprite->unk04, 0, arg1);
}

// espAttrSet?
void func_8000BC48_C848(u16 arg0, u16 arg1) {
    D_800CD1DC_CDDDC_Struct* temp = &D_800CD1DC_CDDDC[arg0];

    HuSprAttrSet(temp->unk04, 0, arg1);
}

// espAttrReset
void func_8000BC88_C888(u16 arg0, u16 arg1) {
    D_800CD1DC_CDDDC_Struct* temp = &D_800CD1DC_CDDDC[arg0];

    HuSprAttrReset(temp->unk04, 0, arg1);
}

void func_8000BCC8_C8C8(u16 spriteId, s32 arg1) {
    D_800CD1DC_CDDDC_Struct *sprite;

    sprite = D_800CD1DC_CDDDC + spriteId;
    HuSprPriSet(sprite->unk04, 0, arg1);
}

void func_8000BD08_C908(u16 spriteId, f32 arg1) {
    D_800CD1DC_CDDDC_Struct *sprite;

    sprite = D_800CD1DC_CDDDC + spriteId;
    func_800550B4_55CB4(sprite->unk04, 0, arg1);
}

void func_8000BD50_C950(u16 spriteId, s16 arg1) {
    D_800CD1DC_CDDDC_Struct *sprite;

    sprite = D_800CD1DC_CDDDC + spriteId;
    func_80054FF8_55BF8(sprite->unk04, 0, arg1);
}

void func_8000BD94_C994(u16 spriteId, s32 arg1, s32 arg2) {
    D_800CD1DC_CDDDC_Struct *sprite;

    sprite = D_800CD1DC_CDDDC + spriteId;
    func_80055140_55D40(sprite->unk04, 0, arg1, (u16)arg2);
}

void func_8000BDDC_C9DC(u16 spriteId, s32 arg1) {
    D_800CD1DC_CDDDC_Struct *sprite;

    sprite = D_800CD1DC_CDDDC + spriteId;
    func_800550F4_55CF4(sprite->unk04, 0, (u16)arg1);
}

u8 func_8000BE1C_CA1C(u16 spriteId) {
    D_800CD1DC_CDDDC_Struct *sprite;

    sprite = D_800CD1DC_CDDDC + spriteId;
    return func_800551AC_55DAC(sprite->unk04, 0);
}

// Scale sprite.
void func_8000BE5C_CA5C(u16 spriteId, f32 x, f32 y) {
    D_800CD1DC_CDDDC_Struct *sprite;

    sprite = D_800CD1DC_CDDDC + spriteId;
    HuSprScaleSet(sprite->unk04, 0, x, y);
}

void func_8000BEAC_CAAC(u16 spriteId, s32 arg1, s32 arg2, s32 arg3) {
    D_800CD1DC_CDDDC_Struct *sprite;

    sprite = D_800CD1DC_CDDDC + spriteId;
    func_80055420_56020(sprite->unk04, 0, arg1, arg2, arg3);
}

void func_8000BF00_CB00(u16 spriteId, f32 arg1) {
    D_800CD1DC_CDDDC_Struct *sprite;

    sprite = D_800CD1DC_CDDDC + spriteId;
    func_800552DC_55EDC(sprite->unk04, 0, arg1);
}

void func_8000BF48_CB48(u16 spriteId, s16 arg1, s16 arg2, s16 arg3) {
    u16 temp_v0;
    D_800CD1DC_CDDDC_Struct *sprite;

    sprite = D_800CD1DC_CDDDC + spriteId;
    sprite->unk00 |= 2;
    sprite->unk1C = arg1;
    if (arg2 > 0) {
        sprite->unk1E = arg2;
    }
    sprite->unk20 = arg3;
}

void func_8000BF8C_CB8C(u16 spriteId, s16 arg1) {
    u16 temp_v0;
    D_800CD1DC_CDDDC_Struct *sprite;
    u16 phi_return;

    sprite = D_800CD1DC_CDDDC + spriteId;
    sprite->unk00 &= 0xFFFD;
    if (arg1 > 0) {
        sprite->unk1E = arg1;
        sprite->unk1C = arg1;
        func_80055458_56058(sprite->unk04, 0, arg1 & 0xFFFF);
    }
}

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

// CloseEsprite
void func_8000C184_CD84(u16 arg0) {
    D_800CD1DC_CDDDC_Struct *sprite;

    sprite = D_800CD1DC_CDDDC + arg0;
    if ((sprite->unk00 & 1) != 0) {
        HuSprGrpKill(sprite->unk04);
        sprite->unk00 = 0;
        sprite->unk02 = D_800D5438_D6038;
        D_800D5438_D6038 = arg0;
        D_800CB8BC_CC4BC--;
    }
}
