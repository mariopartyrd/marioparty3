#include "overlays/minigame.h"
#include "game/data.h"
#include "game/hmfman.h"
#include "include_asm.h"

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4A80_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4A90_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4BA4_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4C2C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4C88_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4D9C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E4E30_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5138_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E561C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5638_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5664_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E567C_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5690_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5798_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5848_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E58B4_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E58D4_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E58F8_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5978_minigame);

void func_800E5A00_minigame(omObjData *arg0, u16 arg1, s32 arg2, s32 arg3, u16 arg4) {
    func_800E1BA8_minigame_ObjData *temp_a1;
    func_800E1BA8_minigame_UnkE8_ObjData *temp_v0_2;
    s16 temp_v0;

    temp_v0 = func_8001F1FC_main(DataRead(arg2), 0x18);
    if (temp_v0 < 0) {
        return;
    }
    temp_a1 = (func_800E1BA8_minigame_ObjData *)arg0->data;
    arg0->motion[arg1] = temp_v0;
    temp_v0_2 = &temp_a1->unkE8[arg1];
    temp_v0_2->unk00 = arg3 | 4;
    temp_v0_2->unk02 = arg4;
}

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5A98_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5B08_minigame);

INCLUDE_ASM("asm/nonmatchings/overlays/minigame/B7600", func_800E5C18_minigame);
