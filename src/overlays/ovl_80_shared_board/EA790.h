#ifndef _ovl_80_EA790
#define _ovl_80_EA790

#include "common.h"
#include "game/board.h"

typedef struct UnkBoard2 {
/* 0x00 */ s16 unk_00;
/* 0x04 */ Object* obj;
} UnkBoard2;

typedef struct UnkEA790Struct {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ UnkBoard2** unk_04;
    /* 0x08 */ Process* proc;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unkE;                            /* inferred */
    /* 0x10 */ OSMesgQueue unk10;                   /* inferred */
    /* 0x28 */ void* unk28;                         /* inferred */
    /* 0x2C */ char pad2C[0x3C];                    /* maybe part of unk28[0x10]? */
    /* 0x68 */ GW_PLAYER* player;
} UnkEA790Struct;                                   /* size = 0x6C */

UnkBoard2 *func_800D6B70_EA790_shared_board(s32 arg0);
UnkEA790Struct* func_800D6C6C_EA88C_shared_board(void);
void func_800D6CA0_EA8C0_shared_board(UnkEA790Struct* arg0);
void func_800D6D2C_EA94C_shared_board(UnkEA790Struct *arg0, UnkBoard2 *arg1, u16 arg2);
void func_800D6E00_EAA20_shared_board(UnkEA790Struct *arg0, UnkBoard2* arg1); //unused
UnkBoard2* func_800D6EC8_EAAE8_shared_board(UnkEA790Struct* arg0, s16 arg1);

#endif //_ovl_80_EA790