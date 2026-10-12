#include "game/esprite.h"
#include "game/data.h"
#include "game/sprite.h"
#include "mallocblock.h"
#include "include_asm.h"

// malloc
void HuMemMemoryFreePerm(void *ptr);

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
} D_800CD1DC_main_Struct; // Size 0x24

extern u16 D_800C951C_main;
extern u16 D_800CB8BC_main;
extern D_800CD1DC_main_Struct *D_800CD1DC_main; // esprite?
extern s16 D_800D5438_main;

void func_8000B7A0_main(void) {
    u16 var_a0;

    func_80052330_main();
    D_800CD1DC_main = HuMemAlloc(0x100 * sizeof(D_800CD1DC_main_Struct));
    D_800C951C_main = 0x100;
    D_800CB8BC_main = 0;
    for (var_a0 = 0; var_a0 < 0x100; var_a0++) {
        D_800CD1DC_main_Struct *temp_v0 = &D_800CD1DC_main[var_a0];

        temp_v0->unk00 = 0;
        temp_v0->unk02 = var_a0 + 1;
        temp_v0->unk1C = 0xFF;
        temp_v0->unk1E = 0xFF;
        temp_v0->unk20 = 0;
    }
    D_800D5438_main = 0;
}

s16 func_8000B838_main(s32 arg0) {
    void *temp_v0;
    s16 temp_s0;

    temp_v0 = DataRead(arg0);
    temp_s0 = func_80055810_main(temp_v0);
    HuMemMemoryFreePerm(temp_v0);
    return temp_s0;
}

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000B880_main);

void func_8000BA00_main() {
    func_80056BAC_main();
    HuMemFree(D_800CD1DC_main);
    D_800CD1DC_main = NULL;
}

INCLUDE_ASM("asm/nonmatchings/esprite", func_8000BA30_main);

// espDispOn?
void func_8000BB54_main(u16 arg0) {
    HuSprAttrReset(D_800CD1DC_main[arg0].unk04, 0, 0x8000);
}

// espDispOff?
void func_8000BB94_main(u16 arg0) {
    HuSprAttrSet(D_800CD1DC_main[arg0].unk04, 0, 0x8000);
}

// Set sprite center.
void func_8000BBD4_main(u16 spriteId, s16 x, s16 y) {
    D_800CD1DC_main_Struct *sprite;

    sprite = D_800CD1DC_main + spriteId;
    sprite->unkA = x;
    sprite->unkC = y;
}

void func_8000BBFC_main(u16 spriteId, s16 arg1) {
    D_800CD1DC_main_Struct *sprite;

    sprite = D_800CD1DC_main + spriteId;
    sprite->unk1E = arg1;
    sprite->unk1C = arg1;
    func_80055458_main(sprite->unk04, 0, arg1);
}

// espAttrSet?
void func_8000BC48_main(u16 arg0, u16 arg1) {
    D_800CD1DC_main_Struct *temp = &D_800CD1DC_main[arg0];

    HuSprAttrSet(temp->unk04, 0, arg1);
}

// espAttrReset
void func_8000BC88_main(u16 arg0, u16 arg1) {
    D_800CD1DC_main_Struct *temp = &D_800CD1DC_main[arg0];

    HuSprAttrReset(temp->unk04, 0, arg1);
}

void func_8000BCC8_main(u16 spriteId, s32 arg1) {
    D_800CD1DC_main_Struct *sprite;

    sprite = D_800CD1DC_main + spriteId;
    HuSprPriSet(sprite->unk04, 0, arg1);
}

void func_8000BD08_main(u16 spriteId, f32 arg1) {
    D_800CD1DC_main_Struct *sprite;

    sprite = D_800CD1DC_main + spriteId;
    func_800550B4_main(sprite->unk04, 0, arg1);
}

void func_8000BD50_main(u16 spriteId, s16 arg1) {
    D_800CD1DC_main_Struct *sprite;

    sprite = D_800CD1DC_main + spriteId;
    func_80054FF8_main(sprite->unk04, 0, arg1);
}

void func_8000BD94_main(u16 spriteId, s32 arg1, s32 arg2) {
    D_800CD1DC_main_Struct *sprite;

    sprite = D_800CD1DC_main + spriteId;
    func_80055140_main(sprite->unk04, 0, arg1, (u16)arg2);
}

void func_8000BDDC_main(u16 spriteId, s32 arg1) {
    D_800CD1DC_main_Struct *sprite;

    sprite = D_800CD1DC_main + spriteId;
    func_800550F4_main(sprite->unk04, 0, (u16)arg1);
}

u8 func_8000BE1C_main(u16 spriteId) {
    D_800CD1DC_main_Struct *sprite;

    sprite = D_800CD1DC_main + spriteId;
    return func_800551AC_main(sprite->unk04, 0);
}

// Scale sprite.
void func_8000BE5C_main(u16 spriteId, f32 x, f32 y) {
    D_800CD1DC_main_Struct *sprite;

    sprite = D_800CD1DC_main + spriteId;
    HuSprScaleSet(sprite->unk04, 0, x, y);
}

void func_8000BEAC_main(u16 spriteId, s32 arg1, s32 arg2, s32 arg3) {
    D_800CD1DC_main_Struct *sprite;

    sprite = D_800CD1DC_main + spriteId;
    func_80055420_main(sprite->unk04, 0, arg1, arg2, arg3);
}

void func_8000BF00_main(u16 spriteId, f32 arg1) {
    D_800CD1DC_main_Struct *sprite;

    sprite = D_800CD1DC_main + spriteId;
    func_800552DC_main(sprite->unk04, 0, arg1);
}

void func_8000BF48_main(u16 spriteId, s16 arg1, s16 arg2, s16 arg3) {
    u16 temp_v0;
    D_800CD1DC_main_Struct *sprite;

    sprite = D_800CD1DC_main + spriteId;
    sprite->unk00 |= 2;
    sprite->unk1C = arg1;
    if (arg2 > 0) {
        sprite->unk1E = arg2;
    }
    sprite->unk20 = arg3;
}

void func_8000BF8C_main(u16 spriteId, s16 arg1) {
    u16 temp_v0;
    D_800CD1DC_main_Struct *sprite;
    u16 phi_return;

    sprite = D_800CD1DC_main + spriteId;
    sprite->unk00 &= 0xFFFD;
    if (arg1 > 0) {
        sprite->unk1E = arg1;
        sprite->unk1C = arg1;
        func_80055458_main(sprite->unk04, 0, arg1 & 0xFFFF);
    }
}

s16 InitEspriteSlot(s16 arg0, u16 arg1, u16 arg2) {
    D_800CD1DC_main_Struct *temp_s0;
    s16 temp_s3;
    s16 temp_v0;

    if (D_800CB8BC_main == D_800C951C_main) {
        return -1;
    }
    D_800CB8BC_main++;
    temp_s3 = D_800D5438_main;
    temp_s0 = &D_800CD1DC_main[temp_s3];
    D_800D5438_main = temp_s0->unk02;
    temp_s0->unk04 = temp_v0 = HuSprGrpCreate(1, 0);
    temp_s0->unk00 |= 1;
    temp_s0->unk06 = arg0;
    temp_s0->unk10 = temp_s0->unk14 = 1.0f;
    func_80055458_main(temp_v0, 0, 0x100);
    HuSprAttrReset(temp_v0, 0, 0xFFFF);
    HuSprAttrSet(temp_v0, 0, 0x1000);
    HuSprScaleSet(temp_v0, 0, 1.0f, 1.0f);
    func_800550F4_main(temp_v0, 0, arg2);
    func_80055024_main(temp_v0, 0, arg0, arg1);
    HuSprPriSet(temp_v0, 0, 10);
    if (arg2 == 0) {
        func_80054FF8_main(temp_v0, 0, 0);
    }
    return temp_s3;
}

// CloseEsprite
void func_8000C184_main(u16 arg0) {
    D_800CD1DC_main_Struct *sprite;

    sprite = D_800CD1DC_main + arg0;
    if ((sprite->unk00 & 1) != 0) {
        HuSprGrpKill(sprite->unk04);
        sprite->unk00 = 0;
        sprite->unk02 = D_800D5438_main;
        D_800D5438_main = arg0;
        D_800CB8BC_main--;
    }
}
