#include "overlays/minigame.h"
#include "gcc/memory.h"
#include "game/gamework_data.h"
#include "game/util.h"
#include "mallocblock.h"
#include "include_asm.h"

// EXTERN

s16 func_8000B0D4_main(s32, s32);
void func_800DDD94_minigame(omObjData *);

// LOCAL

void func_800E3584_minigame(s16);

extern s8 D_800EB735_minigame;
extern u8 D_800EB739_minigame;
extern u8 D_800EB73A_minigame;
extern f32 D_800EB73C_minigame;
extern f32 D_800EB740_minigame;
extern f32 D_800EB744_minigame;
extern f32 D_800EB748_minigame;
extern f32 D_800EB74C_minigame;
extern f32 D_800EB750_minigame;
extern f32 D_800EB75C_minigame;
extern f32 D_800EB760_minigame;
extern f32 D_800EB764_minigame;
extern f32 D_800EB768_minigame;
extern f32 D_800EB76C_minigame;
extern s32 D_800EB770_minigame;
extern f32 D_800EB774_minigame;
extern f32 D_800EB778_minigame;
extern f32 D_800EB77C_minigame;
extern s16 D_800EB784_minigame[][14];

void func_800E1160_minigame(omObjData *, s32, s32, s32, s32, f32);
INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1160_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E123C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E12B0_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E12E0_minigame);

void func_800E12EC_minigame(omObjData *arg0, f32 arg1) {
    func_800E1BA8_minigame_ObjData *temp_data = arg0->data;

    temp_data->unk38 = arg1;
}

void func_800E12F8_minigame(omObjData *arg0, f32 arg1) {
    func_800E1BA8_minigame_ObjData *temp_data = arg0->data;

    temp_data->unk44 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1304_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1310_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E131C_minigame);

void func_800E1328_minigame(omObjData *arg0, f32 arg1) {
    func_800E1BA8_minigame_ObjData *temp_data = arg0->data;

    temp_data->unk48 = arg1;
}

void func_800E1334_minigame(omObjData *arg0, f32 arg1) {
    func_800E1BA8_minigame_ObjData *temp_data = arg0->data;

    temp_data->unk34 = arg1;
}

void func_800E1340_minigame(omObjData *arg0, f32 arg1) {
    func_800E1BA8_minigame_ObjData *temp_data = arg0->data;

    temp_data->unk64 = arg1;
}

void func_800E134C_minigame(omObjData *arg0, f32 arg1) {
    func_800E1BA8_minigame_ObjData *temp_data = arg0->data;

    temp_data->unk68 = arg1;
}

void func_800E1358_minigame(omObjData *arg0, f32 arg1) {
    func_800E1BA8_minigame_ObjData *temp_data = arg0->data;

    temp_data->unk6C = arg1;
}

void func_800E1364_minigame(omObjData *arg0, f32 arg1) {
    func_800E1BA8_minigame_ObjData *temp_data = arg0->data;

    temp_data->unk70 = arg1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1370_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E139C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E13CC_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1404_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1420_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1440_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1454_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1468_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E147C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1490_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E149C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E14B0_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1510_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1594_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1610_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1718_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E17D4_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E17E4_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E17F4_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1804_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1810_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1820_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1830_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1840_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1854_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E18B4_minigame);

void func_800E18D8_minigame(void) {
    D_800EB73C_minigame = 15.0f;
    D_800EB740_minigame = 0.5f;
    D_800EB744_minigame = 1.45f;
    D_800EB748_minigame = 0.15f;
    D_800EB74C_minigame = 7.0f;
    D_800EB750_minigame = 30.0f;
    D_800EB778_minigame = 0.5f;
    D_800EB75C_minigame = 3.3333333f;
    D_800EB760_minigame = 18.0f;
    D_800EB764_minigame = 13.5f;
    D_800EB768_minigame = 9.0f;
    D_800EB76C_minigame = 4.5f;
    D_800EB770_minigame = 0;
    D_800EB774_minigame = 1.6f;
    D_800EB77C_minigame = 0.14500001f;
    D_800EB735_minigame = 1;
    D_800EB73A_minigame = 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E19E4_minigame);

void func_800E19F0_minigame(s8 arg0) {
    D_800EB739_minigame = arg0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E19FC_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1A9C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E1B3C_minigame);

void func_800E1BA8_minigame(omObjData *arg0, u32 arg1, s32 arg2, u16 arg3, s32 arg4, s32 arg5) {
    func_800E1BA8_minigame_ObjData *temp_s0;
    s32 var_a0;

    for (var_a0 = 0; var_a0 < arg0->mdlcnt; var_a0++) {
        arg0->model[var_a0] = 0;
    }
    arg0->data = HuMemAllocTag(sizeof(func_800E1BA8_minigame_ObjData), 31000);
    memset(arg0->data, 0, sizeof(func_800E1BA8_minigame_ObjData));
    temp_s0 = arg0->data;
    temp_s0->unkE8 = HuMemAllocTag(arg0->mtncnt * sizeof(func_800E1BA8_minigame_UnkE8_ObjData), 31000);
    if (D_800EB73A_minigame == 1) {
        func_800E1160_minigame(arg0, 0, arg3, arg1 | arg2, arg4, 750.0f);
    } else {
        arg0->model[0] = func_8000B108_main(arg1 | arg2, arg4);
    }
    arg0->model[1] = func_8000B0D4_main((D_800EB739_minigame != 0) ? 9 : 0, arg5);
    func_800E3584_minigame(arg0->model[1]);
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
    arg0->func = func_800DDD94_minigame;
    temp_s0->unk52 = 0;
    temp_s0->unkB4 = 1.0f;
    temp_s0->unk8C = 65536.0f;
    temp_s0->unkD0 = 0xFFFF;
    temp_s0->unk4C = 0.5f;
    temp_s0->unkCC = 1.0f;
    temp_s0->unk60 = 0;
    func_800E1328_minigame(arg0, 60.0f);
    func_800E1334_minigame(arg0, 150.0f);
    func_800E1340_minigame(arg0, 20.0f);
    func_800E134C_minigame(arg0, 30.0f);
    func_800E1358_minigame(arg0, 50.0f);
    func_800E1364_minigame(arg0, 40.0f);
    func_800E12EC_minigame(arg0, 1000.0f);
    temp_s0->unk9C = temp_s0->unkA0 = temp_s0->unkA4 = 0.0f;
    temp_s0->unk59 = (s8)arg3;
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
    D_800EB784_minigame[temp_s0->unk59][0] = var_a0 + 0x1F;
    D_800EB784_minigame[temp_s0->unk59][1] = var_a0 + 0x28;
    D_800EB784_minigame[temp_s0->unk59][2] = var_a0 + 0x43;
    D_800EB784_minigame[temp_s0->unk59][3] = var_a0 + 0x3A;
    D_800EB784_minigame[temp_s0->unk59][4] = var_a0 + 0x31;
    D_800EB784_minigame[temp_s0->unk59][5] = var_a0 + 0x4C;
    D_800EB784_minigame[temp_s0->unk59][6] = var_a0 + 0x55;
    D_800EB784_minigame[temp_s0->unk59][7] = var_a0 + 0x9D;
    D_800EB784_minigame[temp_s0->unk59][8] = var_a0 + 0x94;
    D_800EB784_minigame[temp_s0->unk59][9] = var_a0 + 0xA6;
    D_800EB784_minigame[temp_s0->unk59][10] = var_a0 + 0x5E;
    D_800EB784_minigame[temp_s0->unk59][11] = var_a0 + 0x67;
    D_800EB784_minigame[temp_s0->unk59][12] = var_a0 + 0xAF;
    D_800EB784_minigame[temp_s0->unk59][13] = var_a0 + 0xB8;
}

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E210C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E21B8_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2250_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2308_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E23E0_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E240C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2780_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E28BC_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2B58_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2BD4_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2C68_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2CA4_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2DA4_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2E98_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2ED4_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2F40_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E2FD8_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E30B8_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E317C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E341C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E34D8_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E3568_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E3584_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B3CE0", func_800E3628_minigame);
