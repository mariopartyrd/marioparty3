#ifndef _PLAYER_H
#define _PLAYER_H

#include "common.h"
#include "process.h"
#include "math.h"
#include "game/object.h"

#define CUR_PLAYER -1
#define CUR_TURN -1

#define MBD_MAX_PLAYERS 2
#define MB_MAX_PLAYERS 4

#define    OS_K0_TO_PHYSICAL(x)    (u32)(((char *)(x)-0x80000000))
#define    OS_PHYSICAL_TO_K0(x)    (void *)(((u32)(x)+0x80000000))

typedef struct Vec2f {
/* 0x00 */ f32 x;
/* 0x04 */ f32 y;
} Vec2f;

typedef struct objectIndirect3t {
/* 0x00 */ struct objectt *unk0;
/* 0x04 */ f32 unk4;
} objectIndirect3;

typedef struct DiceInstance {
    char unk_00[0x4C];
    s32 unk_4C;
} DiceInstance; //unk size

typedef struct UnkDiceRelatedInner {
    /* 0x00 */ char pad0[2];
    /* 0x02 */ s8 unk2;
    /* 0x03 */ s8 unk3;
    /* 0x04 */  s8 unk4;
    /* 0x05 */ s8 unk5;
    /* 0x06 */ s8 unk6;
    /* 0x07 */ s8 unk7;
    /* 0x08 */ s8 unk8;
    /* 0x09 */ char unk_09[5];
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 unk_12;
    /* 0x14 */ s16 unk_14;
    /* 0x16 */ s16 unk16;                             /* inferred */
    /* 0x16 */ char pad18[0x10];
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ char pad2A[0xA];                     /* maybe part of unk_28[6]? */
    /* 0x34 */ DiceInstance* dice;
    /* 0x38 */ char pad38[0xC];                     /* maybe part of dice[4]? */
} UnkDiceRelatedInner;                              /* size = 0x44 */

typedef struct UnkDiceRelated {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk_02[6];  
    /* 0x08 */ UnkDiceRelatedInner UnkDiceInner;
} UnkDiceRelated;

typedef struct SpaceData {
/* 0x00 */ s8 unk_00;
/* 0x01 */ u8 space_type; // enum board_space_type
/* 0x02 */ s16 unk_02;
/* 0x04 */ s32 unk_04;
/* 0x08 */ Vec coords;
/* 0x14 */ Vec rot;
/* 0x20 */ void* event_list;
} SpaceData; //sizeof 0x24

typedef struct omOvlHisData { //Object Manager History Data
/* 0x00 */ s32 overlayID;
/* 0x04 */ s16 event;
/* 0x06 */ s16 stat;
} omOvlHisData; //sizeof 0x08

typedef struct MinigameTable {
    /* 0x00 */ u8 minigameType;
    /* 0x01 */ char unk_01[5];
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ char unk_0E[6];
} MinigameTable;

typedef struct OvlEntrypoint {
/* 0x00 */ s16 index;
/* 0x04 */ void (*fn)(void);
} OvlEntrypoint; //sizeof 0x08

typedef struct RGB {
/* 0x00 */ u8 r;
/* 0x01 */ u8 g;
/* 0x02 */ u8 b;
} RGB; //sizeof 0x3

typedef struct str800D5298 {
    s32 unk0;
    s32 unk4;
    void *unk8; // mbf0 rom
    void *unkC; // sbf0 rom
    void *unk10; // fxd0 rom
    void *unk14; // audio ram location?
    s32 unk18; // audio ram size?
    s32 unks1C24[3];
    s32 unk28;
    s32 unk2C;
    s32 unks3040[5];
    s32 unk44;
    s32 unks4858[5];
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
} str800D5298;

typedef struct HeapNode {
/* 0x00 */ s32 size;
/* 0x04 */ u8 heap_constant;
/* 0x05 */ u8 active;
/* 0x08 */ struct HeapNode* prev;
/* 0x0C */ struct HeapNode* next;
} HeapNode;

typedef struct UnkOvl81 {
/* 0x00 */ void* unk0;
/* 0x04 */ void* unk4;
/* 0x08 */ void* unk8;
/* 0x0C */ char unk_0C[0x14];
/* 0x20 */ s16 unk_20;
/* 0x22 */ char unk_22[2];
} UnkOvl81;

typedef struct UnkOvl81_1 {
    s32 unk_00;
    char unk_04[0xC];
} UnkOvl81_1;

typedef struct Unk800D6B48 {
    void* unk_00;
    void* unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
    s16 unk_18;
} Unk800D6B48; //sizeof 0x18

typedef struct Unk3 {
    u8 unk_00;
    u8 unk_01;
    s16 unk_02;
    omObjData* unk_04;
    s16 winID;
    char unk_0A[2];
    void* unk_0C;
} Unk3; //sizeof 0x10

#endif
