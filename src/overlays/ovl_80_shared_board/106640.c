#include "common.h"
#include "ovl_80.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106640", func_800F2A20_106640_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/106640", func_800F2A34_106654_shared_board);

extern UnkBoard8* D_80105570_119190_shared_board;
extern u16 D_80105574_119194_shared_board;

UnkBoard8* func_800F2A74_106694_shared_board(s16 arg0) {
    UnkBoard8* temp_v0;
    s32 i;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(UnkBoard8));
    if (temp_v0 != NULL) {
        D_80105574_119194_shared_board++;
        temp_v0->unk_00 = D_80105570_119190_shared_board;
        temp_v0->unk_04 = 0;
        
        if (D_80105570_119190_shared_board != NULL) {
            D_80105570_119190_shared_board->unk_04 = temp_v0;
        }
        
        D_80105570_119190_shared_board = temp_v0;
        temp_v0->unk_08 = arg0;
        
        temp_v0->unk_0C = HuMemMemoryAllocTemp(arg0 * (sizeof *temp_v0->unk_0C));
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_0C[i] = -1;
        }

        temp_v0->unk_10 = HuMemMemoryAllocTemp(arg0 * (sizeof *temp_v0->unk_10));
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_10[i] = 1.0f;
        }

        temp_v0->unk_14 = HuMemMemoryAllocTemp(arg0 * (sizeof *temp_v0->unk_14));
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_14[i] = 1.0f;
        }

        temp_v0->unk_18 = HuMemMemoryAllocTemp(arg0 * (sizeof *temp_v0->unk_18));
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_18[i] = 0;
        }

        temp_v0->unk_1C = HuMemMemoryAllocTemp(arg0 * (sizeof *temp_v0->unk_1C));
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_1C[i] = 0;
        }
    }
    return temp_v0;
}

UnkBoard8* func_800F2C48_106868_shared_board(s16 arg0, s16 arg1) {
    UnkBoard8* temp_v0;

    temp_v0 = func_800F2A74_106694_shared_board(arg0);
    if (temp_v0 != NULL) {
        temp_v0->unk_0A = HuSprGrpCreate(arg0, arg1);
    }
    return temp_v0;
}

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
