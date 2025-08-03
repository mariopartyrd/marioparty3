#include "common.h"
#include "ovl_80.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECAD0_1006F0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECB14_100734_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECB58_100778_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECB90_1007B0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECBD0_1007F0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECC0C_10082C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECC28_100848_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECC54_100874_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECD00_100920_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECDD4_1009F4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECE4C_100A6C_shared_board);

s32 RNGPercentChance(s8 arg0) {
    u8 randByte = rand8();
    s32 chance = arg0;
    return (randByte * 99 >> 8) < chance;
}

s16 GetTurnsElapsed(void) {
    GW_SYSTEM* system = &GwSystem;
    
    return system->total_turns - system->current_turn + 1;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECF18_100B38_shared_board);

void func_800ECF9C_100BBC_shared_board(s16 arg0) {
    func_800EDC20_101840_shared_board(D_80101490_1150B0_shared_board[arg0]);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ECFC8_100BE8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED128_100D48_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED1E4_100E04_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED20C_100E2C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED290_100EB0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED35C_100F7C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED410_101030_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED518_101138_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED5E0_101200_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED694_1012B4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED75C_10137C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED810_101430_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED91C_10153C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED998_1015B8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800ED9F8_101618_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800EDA58_101678_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800EDAF0_101710_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/1006F0", func_800EDB98_1017B8_shared_board);
