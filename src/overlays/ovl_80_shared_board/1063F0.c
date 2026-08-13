#include "common.h"

void func_800F288C_1064AC_shared_board(void);

RectF D_80101770_115390_shared_board = {
    16.0f, 12.0f, 304.0f, 228.0f
};

void func_800F27D0_1063F0_shared_board(void) {
    D_80101770_115390_shared_board.x1 = 16.0f;
    D_80101770_115390_shared_board.y1 = 12.0f;
    D_80101770_115390_shared_board.x2 = 304.0f;
    D_80101770_115390_shared_board.y2 = 228.0f;
    CameraScissorSet(0, &D_80101770_115390_shared_board);
}

void func_800F2834_106454_shared_board(void) {
    D_80101770_115390_shared_board.x1 = 16.0f;
    D_80101770_115390_shared_board.y1 = 12.0f;
    D_80101770_115390_shared_board.x2 = 16.0f;
    D_80101770_115390_shared_board.y2 = 228.0f;
    CameraScissorSet(0, &D_80101770_115390_shared_board);
}

void func_800F288C_1064AC_shared_board(void) {
    s32 i;

    D_80101770_115390_shared_board.x1 = 16.0f;
    D_80101770_115390_shared_board.x2 = 304.0f;

    for (i = 0; i < 9; i++) {
        HuPrcVSleep();
        D_80101770_115390_shared_board.x1 += 32.0f;
        CameraScissorSet(0, &D_80101770_115390_shared_board);        
    }
    omDelPrcObj(NULL);
}

void func_800F292C_10654C_shared_board(void) {
    omAddPrcObj(func_800F288C_1064AC_shared_board, 0x1002, 0, 0);
}

void func_800F2958_106578_shared_board(void) {
    s32 i;

    D_80101770_115390_shared_board.x1 = 16.0f;
    D_80101770_115390_shared_board.x2 = 16.0f;

    for (i = 0; i < 9; i++) {
        HuPrcVSleep();
        D_80101770_115390_shared_board.x2 += 32.0f;
        CameraScissorSet(0, &D_80101770_115390_shared_board);
    }

    omDelPrcObj(NULL);
}

void func_800F29EC_10660C_shared_board(void) {
    omAddPrcObj(func_800F2958_106578_shared_board, 0x1002, 0, 0);
}

