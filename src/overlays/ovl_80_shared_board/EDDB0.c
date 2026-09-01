#include "common.h"

extern s32 (*D_80102BC4_1167E4_shared_board)(void);
extern s32 D_80102BC0_1167E0_shared_board;

//main CPU decision logic function
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EDDB0", MBComTreeExec);

void MBComItemDecideHookSet(void (arg0)(void)) {
    D_80102BC4_1167E4_shared_board = arg0;
}

s32 MBComItemDecide(void) {
    return D_80102BC4_1167E4_shared_board();
}

void func_800DA778_EE398_shared_board(s32 arg0) {
    D_80102BC0_1167E0_shared_board = arg0;
}