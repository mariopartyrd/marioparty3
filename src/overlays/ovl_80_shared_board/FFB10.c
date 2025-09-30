#include "common.h"
#include "ovl_80.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EBEF0_FFB10_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EBF48_FFB68_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EBF98_FFBB8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EBFE8_FFC08_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC134_FFD54_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC1E8_FFE08_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC39C_FFFBC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC3C0_FFFE0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC3E4_100004_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC414_100034_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC4E4_100104_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC590_1001B0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC5B4_1001D4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC5EC_10020C_shared_board);

void func_800EC628_100248_shared_board(s32 arg0, s32 arg1) {
    s16 sp10[4];
    s16 temp_v0;

    func_80060394_60F94(1, sp10, arg1);
    temp_v0 = func_800EBFE8_FFC08_shared_board(arg0, sp10, -1);
    D_80105702_119322_shared_board = temp_v0;
    func_8005B43C_5C03C(temp_v0, arg1, -1, -1);
    func_80061388_61F88(temp_v0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC6A8_1002C8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC6C8_1002E8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC6EC_10030C_shared_board);

void func_800EC70C_10032C_shared_board(s16 arg0, s32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, s16 arg7) {
    s16 sp10[4];
    s16 temp_v0;

    if (arg2 != 0) {
        func_8006022C_60E2C(arg2, 0);
    }
    if (arg3 != 0) {
        func_8006022C_60E2C(arg3, 1);
    }
    if (arg4 != 0) {
        func_8006022C_60E2C(arg4, 2);
    }
    if (arg5 != 0) {
        func_8006022C_60E2C(arg5, 3);
    }
    if (arg6 != 0) {
        func_8006022C_60E2C(arg6, 4);
    }

    func_80060394_60F94(1, sp10, arg1);
    temp_v0 = func_800EBFE8_FFC08_shared_board(arg0, sp10, arg7);
    D_80105702_119322_shared_board = temp_v0;
    
    if (arg2 != 0) {
        func_8005B6BC_5C2BC(temp_v0, arg2, 0);
    }
    if (arg3 != 0) {
        func_8005B6BC_5C2BC(temp_v0, arg3, 1);
    }
    if (arg4 != 0) {
        func_8005B6BC_5C2BC(temp_v0, arg4, 2);
    }
    if (arg5 != 0) {
        func_8005B6BC_5C2BC(temp_v0, arg5, 3);
    }
    if (arg6 != 0) {
        func_8005B6BC_5C2BC(temp_v0, arg6, 4);
    }
    if (D_80101480_1150A0_shared_board != 0) {
        func_8005E1A8_5EDA8(temp_v0, D_80101480_1150A0_shared_board);
    }
    func_8005B43C_5C03C(temp_v0, arg1, -1, -1);
    if (arg0 == -1) {
        func_80061388_61F88(temp_v0);
    } else {
        func_80061388_61F88(temp_v0);
    }
    
    func_800EBF48_FFB68_shared_board(temp_v0, GwSystem.current_player_index);
}

void ShowMessage(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_800EC70C_10032C_shared_board(arg0, arg1, arg2, arg3, arg4, arg5, arg6, -1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC92C_10054C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC980_1005A0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800EC9DC_1005FC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800ECA38_100658_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800ECAA8_1006C8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FFB10", func_800ECAB4_1006D4_shared_board);
