#ifndef _BOARD_H
#define _BOARD_H

#include "ultra64.h"

typedef struct LinkData {
/* 0x00 */ s16 chainIndicies;
/* 0x02 */ s16 unk2;
/* 0x04 */ s16* spaces;
} LinkData; //sizeof 0x08

typedef struct event_list_entry {
    s16 activation_type;
    s16 execution_type;
    void (*event_fn)();
} event_list_entry;

typedef struct event_table_entry {
    s16 space_index;
    event_list_entry *event_list;
} event_table_entry;

typedef struct Unk800CD2A0 {
    u8 unk_00;
    s16 unk_02;
} Unk800CD2A0;

typedef struct DecisionTreeNonLeafNode {
    u8 type;
    union {
        s32 (*func) ();
        u32 data;
        s32 signed_data;
        u16 data_u16[2];
        u8 data_u8[4];
        s8 data_s8[4];
    } node_data1;
    union {
        u32 data;
        struct DecisionTreeNonLeafNode *node_data;
        u8 data_u8[4];
    } node_data2;
} DecisionTreeNonLeafNode;

typedef struct UnkMBGuideData {
    Object* obj;
    Process* unk_04;
    s16 amount;
    s16 spriteGroup;
} UnkMBGuideData; //sizeof 0x0C

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

typedef struct UnkBoard {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 unk_02;
/* 0x04 */ Object* unk_04;
/* 0x08 */ omObjData* unk_08;
} UnkBoard; //sizeof 0x0C

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

extern Unk800CD2A0 D_800CD2A0_CDEA0;
extern omOvlHisData D_800D4190_D4D90;

#endif //_BOARD_H