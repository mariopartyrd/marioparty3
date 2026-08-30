#ifndef _ovl_80_106640
#define _ovl_80_106640

#include "common.h"

//very closely resembles UnkBoard5, but member at offset 0x08 must be s16 here instead of s32?
typedef struct UnkBoard8 {
    struct UnkBoard8* unk_00; //double check this
    struct UnkBoard8* unk_04; //?
    s16 amount; //number of entries for model, rot, scale, x/y positions
    s16 spriteGroup;
    s16* model;
    f32* unk_10; //rot?
    f32* unk_14; //scale?
    s16* xPositions;
    s16* yPositions;
} UnkBoard8; //sizeof 0x20

void func_800F2A20_106640_shared_board(void);
void func_800F2A34_106654_shared_board(void);
UnkBoard8 *func_800F2C48_106868_shared_board(s16 arg0, s16 arg1);
void func_800F2CA4_1068C4_shared_board(UnkBoard8* arg0);
void func_800F2D8C_1069AC_shared_board(UnkBoard8* arg0, s16 member, s16 x, s16 y); //unused
void func_800F2DDC_1069FC_shared_board(UnkBoard8 *arg0, s16 member, f32 arg2, f32 arg3);

#endif //_ovl_80_106640