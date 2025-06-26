#include "overlays/minigame.h"
#include "game/data.h"
#include "game/hmfman.h"
#include "include_asm.h"

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4A80_B7600_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4A90_B7610_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4BA4_B7724_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4C2C_B77AC_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4C88_B7808_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4D9C_B791C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4E30_B79B0_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5138_B7CB8_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E561C_B819C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5638_B81B8_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5664_B81E4_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E567C_B81FC_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5690_B8210_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5798_B8318_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5848_B83C8_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E58B4_B8434_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E58D4_B8454_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E58F8_B8478_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5978_B84F8_minigame);

void func_800E5A00_B8580_minigame(omObjData* arg0, u16 arg1, s32 arg2, s32 arg3, u16 arg4) {
    func_800E1BA8_B4728_ObjData* temp_a1;
    func_800E1BA8_B4728_UnkE8_ObjData* temp_v0_2;
    s16 temp_v0;

    temp_v0 = func_8001F1FC_1FDFC(DataRead(arg2), 0x18);
    if (temp_v0 < 0) {
        return;
    }
    temp_a1 = (func_800E1BA8_B4728_ObjData*) arg0->data;
    arg0->motion[arg1] = temp_v0;
    temp_v0_2 = &temp_a1->unkE8[arg1];
    temp_v0_2->unk00 = arg3 | 4;
    temp_v0_2->unk02 = arg4;
}

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5A98_B8618_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5B08_B8688_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5C18_B8798_minigame);
