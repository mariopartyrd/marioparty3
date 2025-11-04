#include "common.h"

//start of 113750 .data section
f32 D_80101E90_115AB0_shared_board[][2] = {
    {0.9f, 0.9f},
    {1.2f, 1.1f},
    {1.1f, 1.5f},
    {0.9f, 1.2f}
};

s16 D_80101EB0_115AD0_shared_board[][2] = {
    {34, 128},
    {286, 128},
    {160, 24},
    {160, 216}
};

s32 D_80101EC0_115AE0_shared_board[] = {
    0x00920080,
    0x00AE0080,
    0x00A0006C,
    0x00A00084
};

s16 D_80101ED0_115AF0_shared_board[][2] = {
    {-16, 0},
    {16, 0},
    {0, -12},
    {0, 12}
};

f32 D_80101EE0_115B00_shared_board[][2] = {
    {90.0f, -90.0f},
    {0.0f, 180.0f}
};

s32 D_80101EF0_115B10_shared_board[] = {
    0x001300B3,
    0x001300B4,
    0x001300B5,
    0x001300B6,
    0x001300B7,
    0x001300B8,
    0x001300B9,
    0x001300BA
};

s32 D_80101F10_115B30_shared_board[] = {
    0x001300C7,
    0x001300C8,
    0x001300C9,
    0x001300CA,
    0x001300CB,
    0x001300CC,
    0x001300CD,
    0x001300CE
};

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/113750", func_800FFB30_113750_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/113750", func_800FFD0C_11392C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/113750", func_800FFE90_113AB0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/113750", func_800FFEC4_113AE4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/113750", func_800FFF44_113B64_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/113750", func_80100130_113D50_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/113750", func_8010020C_113E2C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/113750", func_80100228_113E48_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/113750", func_8010024C_113E6C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/113750", func_80100630_114250_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/113750", func_8010067C_11429C_shared_board);
