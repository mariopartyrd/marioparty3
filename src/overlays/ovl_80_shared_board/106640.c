#include "common.h"
#include "ovl_80.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106640", func_800F2A20_106640_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106640", func_800F2A34_106654_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106640", func_800F2A74_106694_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106640", func_800F2C48_106868_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106640", func_800F2CA4_1068C4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106640", func_800F2D8C_1069AC_shared_board);

typedef struct Unused {
    /* 0x00 */ char pad0[0xA];
    /* 0x0A */ s16 unkA;                            /* inferred */
    /* 0x0C */ char padC[4];                        /* maybe part of unkA[3]? */
    /* 0x10 */ f32* unk_10;
    /* 0x20 */ f32* unk_14;
} Unused;  
//unused?
void func_800F2DDC_1069FC_shared_board(Unused* arg0, s16 arg1, f32 arg2, f32 arg3) {
    arg0->unk_10[arg1] = arg2;
    arg0->unk_14[arg1] = arg3;
    HuSprScaleSet(arg0->unkA, arg1, arg2, arg3);
}
