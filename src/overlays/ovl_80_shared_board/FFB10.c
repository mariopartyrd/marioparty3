#include "common.h"
#include "ovl_80.h"

void func_800EBEF0_FFB10_shared_board(s16 arg0) {
    if ((GwSystem.current_player_index == 4) || (D_80101482_1150A2_shared_board != 0)) {
        func_800EE2A4_101EC4_shared_board(arg0);
        return;
    }
    func_800EDC58_101878_shared_board(arg0, GwSystem.current_player_index);
}

void func_800EBF48_FFB68_shared_board(s16 arg0, s32 arg1) {
    if ((GwSystem.current_player_index == 4) || (D_80101482_1150A2_shared_board != 0)) {
        func_800EE2C0_101EE0_shared_board(arg0);
        return;
    }
    func_800EDC74_101894_shared_board(arg0, arg1);
}

void func_800EBF98_FFBB8_shared_board(s16 arg0, s32 arg1) {
    if ((GwSystem.current_player_index == 4) || (D_80101482_1150A2_shared_board != 0)) {
        func_800EE2A4_101EC4_shared_board(arg0);
        return;
    }
    func_800EDC58_101878_shared_board(arg0, arg1);
}

s16 MBWinCreate(s16 arg0, s16* arg1, s16 arg2) {
    s32 result;
    
    if (arg2 == -1) {
        if (arg0 == arg2) {
            result = func_80061188_61D88(-1, 0, 0, arg1[0], arg1[1], 2);
        } else {
            result = func_80061188_61D88(arg0, 0, 0, arg1[0], arg1[1], 2);
        }
    } else {
        if (arg0 == -1) {
            result = func_80061188_61D88(-1, 0xA0 - arg1[0] / 2, arg2, arg1[0], arg1[1], 0);
        } else {
            result = func_80061188_61D88(arg0, 0xA0 - arg1[0] / 2, arg2, arg1[0], arg1[1], 0);
        }
    }

    if (D_800CB99C_CC59C == 0) {
        func_8005B63C_5C23C(result, 0x40, 0x40);
    }

    return result;
}

void MBWinOpen(s32 arg0) {
    s16 sp18[2];
    s16 temp_v0;

    func_80060394_60F94(1, sp18, arg0);
    temp_v0 = func_80061188_61D88(-1, 0, 0, sp18[0],sp18[1], 2);
    mbWinId = temp_v0;

    if (D_800CB99C_CC59C == 0) {
        func_8005B63C_5C23C(temp_v0, 0x40, 0x40);
    }

    func_8005B43C_5C03C(temp_v0, arg0, -1, -1);
    func_80061388_61F88(temp_v0);
}


void MBWinInsertOpen(s32 arg0, char* arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5) {
    s16 sp18[2];
    s16 temp_v0;

    //if arg isn't a pointer, treat as ID and return pointer to message from dynamic memory
    if (arg1 != NULL) {
        func_8006022C_60E2C((u32) arg1, 0);
    }
    if (arg2 != NULL) {
        func_8006022C_60E2C((u32) arg2, 1);
    }
    if (arg3 != NULL) {
        func_8006022C_60E2C((u32) arg3, 2);
    }
    if (arg4 != NULL) {
        func_8006022C_60E2C((u32) arg4, 3);
    }
    if (arg5 != NULL) {
        func_8006022C_60E2C((u32) arg5, 4);
    }
    
    func_80060394_60F94(1, sp18, arg0);
    temp_v0 = func_80061188_61D88(-1, 0, 0, sp18[0], sp18[1], 2);
    mbWinId = temp_v0;
    
    if (D_800CB99C_CC59C == 0) {
        func_8005B63C_5C23C(temp_v0, 0x40, 0x40);
    }
    if (arg1 != NULL) {
        func_8005B6BC_5C2BC(temp_v0, (u32) arg1, 0);
    }
    if (arg2 != 0) {
        func_8005B6BC_5C2BC(temp_v0, (u32) arg2, 1);
    }
    if (arg3 != 0) {
        func_8005B6BC_5C2BC(temp_v0, (u32) arg3, 2);
    }
    if (arg4 != 0) {
        func_8005B6BC_5C2BC(temp_v0, (u32) arg4, 3);
    }
    if (arg5 != 0) {
        func_8005B6BC_5C2BC(temp_v0, (u32) arg5, 4);
    }
    func_8005B43C_5C03C(temp_v0, arg0, -1, -1);
    func_80061388_61F88(temp_v0);
}

void func_800EC39C_FFFBC_shared_board(s32 arg0) {
    func_800EBF48_FFB68_shared_board(mbWinId, arg0);
}

void func_800EC3C0_FFFE0_shared_board(s32 arg0) {
    func_800EBF98_FFBB8_shared_board(mbWinId, arg0);
}

void func_800EC3E4_100004_shared_board(void) {
    func_80061A5C_6265C(mbWinId, 0);
    func_8005F364_5FF64(mbWinId);
}

void MBDlgResultWinExec(s32 arg0) {
    s16 sp18[2];
    s16 temp_v0;

    func_80060394_60F94(1, sp18, arg0);
    temp_v0 = func_80061188_61D88(-1, 0, 0, sp18[0], sp18[1], 2);
    mbDlgWinId = temp_v0;
    
    if (D_800CB99C_CC59C == 0) {
        func_8005B63C_5C23C(temp_v0, 0x40, 0x40);
    }
    
    func_8005B43C_5C03C(temp_v0, arg0, -1, -1);
    func_80061388_61F88(temp_v0);
    func_800EBEF0_FFB10_shared_board(temp_v0);
    func_80061A5C_6265C(temp_v0, 0);
    func_8005F364_5FF64(temp_v0);
}

void MBDlgWinExecY(s16 arg0, s32 arg1, s32 arg2) {
    s16 sp10[2];
    s16 temp_v0;

    func_80060394_60F94(1, sp10, arg1);
    temp_v0 = MBWinCreate(arg0, sp10, arg2);
    mbDlgWinId = temp_v0;
    func_8005B43C_5C03C(temp_v0, arg1, -1, -1);
    func_80061388_61F88(temp_v0);
    func_800EBEF0_FFB10_shared_board(temp_v0);
    func_80061A5C_6265C(temp_v0, 0);
    func_8005F364_5FF64(temp_v0);
}

void MBDlgWinExec(s32 arg0, s32 arg1) {
    MBDlgWinExecY(arg0, arg1, -1);
}

void func_800EC5B4_1001D4_shared_board(s16 arg0, s32 arg1) {
    D_80101482_1150A2_shared_board = 1;
    MBDlgWinExecY(arg0, arg1, -1);
    D_80101482_1150A2_shared_board = 0;
}

void func_800EC5EC_10020C_shared_board(s16 arg0, s32 arg1, s16 arg2) {
    D_80101482_1150A2_shared_board = 1;
    MBDlgWinExecY(arg0, arg1, arg2);
    D_80101482_1150A2_shared_board = 0;
}

void MBDlgWinCreate(s32 arg0, s32 arg1) {
    s16 sp10[2];
    s16 temp_v0;

    func_80060394_60F94(1, sp10, arg1);
    temp_v0 = MBWinCreate(arg0, sp10, -1);
    mbDlgWinId = temp_v0;
    func_8005B43C_5C03C(temp_v0, arg1, -1, -1);
    func_80061388_61F88(temp_v0);
}

void func_800EC6A8_1002C8_shared_board(void) {
    func_80061388_61F88(mbDlgWinId);
}

void MBDlgWinClose(void) {
    func_80061A5C_6265C(mbDlgWinId, 0);
}


void MBDlgWinKill(void) {
    func_8005F364_5FF64(mbDlgWinId);
}


void MBDlgWinInsertCreateY(s16 arg0, s32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, s16 arg7) {
    s16 sp10[2];
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
    temp_v0 = MBWinCreate(arg0, sp10, arg7);
    mbDlgWinId = temp_v0;
    
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

void MBDlgWinInsertCreate(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    MBDlgWinInsertCreateY(arg0, arg1, arg2, arg3, arg4, arg5, arg6, -1);
}

void func_800EC92C_10054C_shared_board(s16 arg0, s32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6) {
    D_80101482_1150A2_shared_board = 1;
    MBDlgWinInsertCreateY(arg0, arg1, arg2, arg3, arg4, arg5, arg6, -1);
    D_80101482_1150A2_shared_board = 0;
}

void func_800EC980_1005A0_shared_board(s16 arg0, s32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, s16 arg7) {
    D_80101482_1150A2_shared_board = 1;
    MBDlgWinInsertCreateY(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
    D_80101482_1150A2_shared_board = 0;
}

void func_800EC9DC_1005FC_shared_board(void) {
    D_800CC69C_CD29C[mbDlgWinId].unk20 = 1;
    HuPrcVSleep();
    func_800EBF48_FFB68_shared_board(mbDlgWinId, GwSystem.current_player_index);
}

void func_800ECA38_100658_shared_board(void) {
    D_80101482_1150A2_shared_board = 1;
    D_800CC69C_CD29C[mbDlgWinId].unk20 = 1;
    HuPrcVSleep();
    func_800EBF48_FFB68_shared_board(mbDlgWinId, GwSystem.current_player_index);
    D_80101482_1150A2_shared_board = 0;
}

void func_800ECAA8_1006C8_shared_board(s32 arg0) {
    D_80101480_1150A0_shared_board = arg0;
}

void func_800ECAB4_1006D4_shared_board(void) {
    D_80101480_1150A0_shared_board = 0;
    D_80101482_1150A2_shared_board = 0;
}
