#include "common.h"

extern s32 D_80102700_116320_shared_board;
extern s16 D_80102704_116324_shared_board;

typedef struct UnkBoard6 {
    s8 unk_00;
    char unk_01[0x1B];
} UnkBoard6; //sprite data?

extern UnkBoard6 D_80102708_116328_shared_board[32];

void func_800D76D0_EB2F0_shared_board(s32 arg0) {
    s32 i;

    D_80102700_116320_shared_board = arg0;
    for (i = 0; i < ARRAY_COUNT(D_80102708_116328_shared_board); i++) {
        D_80102708_116328_shared_board[i].unk_00 = -1;
    }

    D_80102704_116324_shared_board = 0;
}

void func_800D7714_EB334_shared_board(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EB2F0", func_800D771C_EB33C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EB2F0", func_800D7770_EB390_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EB2F0", func_800D7790_EB3B0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EB2F0", MBMapFullStarGlowKill);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EB2F0", MBMapFullStarGrow);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EB2F0", MBMapFullStarGlowCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EB2F0", MBMapFullLinePosFix);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EB2F0", MBMapFullLineCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EB2F0", func_800D7D00_EB920_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EB2F0", MBMapFullLineFlash);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EB2F0", MBMapFullMain);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EB2F0", MBMapFullExec);
