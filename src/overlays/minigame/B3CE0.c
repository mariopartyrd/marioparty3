#include "overlays/minigame.h"
#include "gcc/memory.h"
#include "game/gamework_data.h"
#include "game/util.h"
#include "mallocblock.h"
#include "include_asm.h"

// EXTERN

s16 func_8000B0D4_BCD4(s32, s32);
void func_800DDD94_B0914_minigame(omObjData*);

// LOCAL

void func_800E3584_B6104_minigame(s16);

extern s8 D_800EB735_BE2B5_minigame;
extern u8 D_800EB739_BE2B9_minigame;
extern u8 D_800EB73A_BE2BA_minigame;
extern f32 D_800EB73C_BE2BC_minigame;
extern f32 D_800EB740_BE2C0_minigame;
extern f32 D_800EB744_BE2C4_minigame;
extern f32 D_800EB748_BE2C8_minigame;
extern f32 D_800EB74C_BE2CC_minigame;
extern f32 D_800EB750_BE2D0_minigame;
extern f32 D_800EB75C_BE2DC_minigame;
extern f32 D_800EB760_BE2E0_minigame;
extern f32 D_800EB764_BE2E4_minigame;
extern f32 D_800EB768_BE2E8_minigame;
extern f32 D_800EB76C_BE2EC_minigame;
extern s32 D_800EB770_BE2F0_minigame;
extern f32 D_800EB774_BE2F4_minigame;
extern f32 D_800EB778_BE2F8_minigame;
extern f32 D_800EB77C_BE2FC_minigame;
extern s16 D_800EB784_BE304_minigame[][14];

void func_800E1160_B3CE0_minigame(omObjData*, s32, s32, s32, s32, f32);
INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1160_B3CE0_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E123C_B3DBC_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E12B0_B3E30_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E12E0_B3E60_minigame);

void func_800E12EC_B3E6C_minigame(omObjData* arg0, f32 arg1) {
    func_800E1BA8_B4728_ObjData* temp_data = arg0->data;

    temp_data->unk38 = arg1;
}

void func_800E12F8_B3E78_minigame(omObjData* arg0, f32 arg1) {
    func_800E1BA8_B4728_ObjData* temp_data = arg0->data;

    temp_data->unk44 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1304_B3E84_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1310_B3E90_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E131C_B3E9C_minigame);

void func_800E1328_B3EA8_minigame(omObjData* arg0, f32 arg1) {
    func_800E1BA8_B4728_ObjData* temp_data = arg0->data;

    temp_data->unk48 = arg1;
}

void func_800E1334_B3EB4_minigame(omObjData* arg0, f32 arg1) {
    func_800E1BA8_B4728_ObjData* temp_data = arg0->data;

    temp_data->unk34 = arg1;
}

void func_800E1340_B3EC0_minigame(omObjData* arg0, f32 arg1) {
    func_800E1BA8_B4728_ObjData* temp_data = arg0->data;

    temp_data->unk64 = arg1;
}

void func_800E134C_B3ECC_minigame(omObjData* arg0, f32 arg1) {
    func_800E1BA8_B4728_ObjData* temp_data = arg0->data;

    temp_data->unk68 = arg1;
}

void func_800E1358_B3ED8_minigame(omObjData* arg0, f32 arg1) {
    func_800E1BA8_B4728_ObjData* temp_data = arg0->data;

    temp_data->unk6C = arg1;
}

void func_800E1364_B3EE4_minigame(omObjData* arg0, f32 arg1) {
    func_800E1BA8_B4728_ObjData* temp_data = arg0->data;

    temp_data->unk70 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1370_B3EF0_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E139C_B3F1C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E13CC_B3F4C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1404_B3F84_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1420_B3FA0_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1440_B3FC0_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1454_B3FD4_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1468_B3FE8_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E147C_B3FFC_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1490_B4010_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E149C_B401C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E14B0_B4030_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1510_B4090_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1594_B4114_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1610_B4190_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1718_B4298_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E17D4_B4354_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E17E4_B4364_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E17F4_B4374_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1804_B4384_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1810_B4390_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1820_B43A0_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1830_B43B0_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1840_B43C0_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1854_B43D4_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E18B4_B4434_minigame);

void func_800E18D8_B4458_minigame(void) {
    D_800EB73C_BE2BC_minigame = 15.0f;
    D_800EB740_BE2C0_minigame = 0.5f;
    D_800EB744_BE2C4_minigame = 1.45f;
    D_800EB748_BE2C8_minigame = 0.15f;
    D_800EB74C_BE2CC_minigame = 7.0f;
    D_800EB750_BE2D0_minigame = 30.0f;
    D_800EB778_BE2F8_minigame = 0.5f;
    D_800EB75C_BE2DC_minigame = 3.3333333f;
    D_800EB760_BE2E0_minigame = 18.0f;
    D_800EB764_BE2E4_minigame = 13.5f;
    D_800EB768_BE2E8_minigame = 9.0f;
    D_800EB76C_BE2EC_minigame = 4.5f;
    D_800EB770_BE2F0_minigame = 0;
    D_800EB774_BE2F4_minigame = 1.6f;
    D_800EB77C_BE2FC_minigame = 0.14500001f;
    D_800EB735_BE2B5_minigame = 1;
    D_800EB73A_BE2BA_minigame = 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E19E4_B4564_minigame);

void func_800E19F0_B4570_minigame(s8 arg0) {
    D_800EB739_BE2B9_minigame = arg0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E19FC_B457C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1A9C_B461C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1B3C_B46BC_minigame);

void func_800E1BA8_B4728_minigame(omObjData* arg0, u32 arg1, s32 arg2, u16 arg3, s32 arg4, s32 arg5) {
    func_800E1BA8_B4728_ObjData* temp_s0;
    s32 var_a0;

    for (var_a0 = 0; var_a0 < arg0->mdlcnt; var_a0++) {
        arg0->model[var_a0] = 0;
    }
    arg0->data = HuMemAllocTag(sizeof(func_800E1BA8_B4728_ObjData), 31000);
    memset(arg0->data, 0, sizeof(func_800E1BA8_B4728_ObjData));
    temp_s0 = arg0->data;
    temp_s0->unkE8 = HuMemAllocTag(arg0->mtncnt * sizeof(func_800E1BA8_B4728_UnkE8_ObjData), 31000);
    if (D_800EB73A_BE2BA_minigame == 1) {
        func_800E1160_B3CE0_minigame(arg0, 0, arg3, arg1 | arg2, arg4, 750.0f);
    } else {
        arg0->model[0] = func_8000B108_BD08(arg1 | arg2, arg4);
    }
    arg0->model[1] = func_8000B0D4_BCD4((D_800EB739_BE2B9_minigame != 0) ? 9 : 0, arg5);
    func_800E3584_B6104_minigame(arg0->model[1]);
    for (var_a0 = 0; var_a0 < arg0->mtncnt; var_a0++) {
        arg0->motion[var_a0] = -1;
    }
    for (var_a0 = 0; var_a0 < 21; var_a0++) {
        temp_s0->unk104[var_a0] = 0;
    }
    for (var_a0 = 0; var_a0 < arg0->mtncnt; var_a0++) {
        temp_s0->unkE8[var_a0].unk00 = 0;
        temp_s0->unkE8[var_a0].unk02 = 0;
        temp_s0->unkE8[var_a0].unk04 = -1;
        temp_s0->unkE8[var_a0].unk08 = -1;
    }
    temp_s0->unk57 = GwPlayer[arg3].pad;
    arg0->func = func_800DDD94_B0914_minigame;
    temp_s0->unk52 = 0;
    temp_s0->unkB4 = 1.0f;
    temp_s0->unk8C = 65536.0f;
    temp_s0->unkD0 = 0xFFFF;
    temp_s0->unk4C = 0.5f;
    temp_s0->unkCC = 1.0f;
    temp_s0->unk60 = 0;
    func_800E1328_B3EA8_minigame(arg0, 60.0f);
    func_800E1334_B3EB4_minigame(arg0, 150.0f);
    func_800E1340_B3EC0_minigame(arg0, 20.0f);
    func_800E134C_B3ECC_minigame(arg0, 30.0f);
    func_800E1358_B3ED8_minigame(arg0, 50.0f);
    func_800E1364_B3EE4_minigame(arg0, 40.0f);
    func_800E12EC_B3E6C_minigame(arg0, 1000.0f);
    temp_s0->unk9C = temp_s0->unkA0 = temp_s0->unkA4 = 0.0f;
    temp_s0->unk59 = (s8) arg3;
    temp_s0->unkC3 = -1;
    temp_s0->unkC4 = -1;
    temp_s0->unkB0 = 1.0f;
    switch (arg1 >> 16) {
        case 6:
            temp_s0->unkAC = 0.7f;
            break;
        case 4:
            temp_s0->unkAC = 0.9f;
            break;
        case 5:
            temp_s0->unkAC = 0.8f;
            break;
        default:
            temp_s0->unkAC = 1.0f;
            break;
    }
    var_a0 = GwPlayer[arg3].chr + 1;
    D_800EB784_BE304_minigame[temp_s0->unk59][0] = var_a0 + 0x1F;
    D_800EB784_BE304_minigame[temp_s0->unk59][1] = var_a0 + 0x28;
    D_800EB784_BE304_minigame[temp_s0->unk59][2] = var_a0 + 0x43;
    D_800EB784_BE304_minigame[temp_s0->unk59][3] = var_a0 + 0x3A;
    D_800EB784_BE304_minigame[temp_s0->unk59][4] = var_a0 + 0x31;
    D_800EB784_BE304_minigame[temp_s0->unk59][5] = var_a0 + 0x4C;
    D_800EB784_BE304_minigame[temp_s0->unk59][6] = var_a0 + 0x55;
    D_800EB784_BE304_minigame[temp_s0->unk59][7] = var_a0 + 0x9D;
    D_800EB784_BE304_minigame[temp_s0->unk59][8] = var_a0 + 0x94;
    D_800EB784_BE304_minigame[temp_s0->unk59][9] = var_a0 + 0xA6;
    D_800EB784_BE304_minigame[temp_s0->unk59][10] = var_a0 + 0x5E;
    D_800EB784_BE304_minigame[temp_s0->unk59][11] = var_a0 + 0x67;
    D_800EB784_BE304_minigame[temp_s0->unk59][12] = var_a0 + 0xAF;
    D_800EB784_BE304_minigame[temp_s0->unk59][13] = var_a0 + 0xB8;
}

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E210C_B4C8C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E21B8_B4D38_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2250_B4DD0_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2308_B4E88_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E23E0_B4F60_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E240C_B4F8C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2780_B5300_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E28BC_B543C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2B58_B56D8_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2BD4_B5754_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2C68_B57E8_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2CA4_B5824_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2DA4_B5924_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2E98_B5A18_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2ED4_B5A54_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2F40_B5AC0_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2FD8_B5B58_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E30B8_B5C38_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E317C_B5CFC_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E341C_B5F9C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E34D8_B6058_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E3568_B60E8_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E3584_B6104_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E3628_B61A8_minigame);
