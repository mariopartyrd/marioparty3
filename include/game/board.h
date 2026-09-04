#ifndef _BOARD_H
#define _BOARD_H

#include "ultra64.h"

#define MINIGAME_ID(id) ((id) + 1)

#define COINS_MAX 999
#define STARS_MAX 99

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

enum BoardIndices {
    CHILLY_WATERS = 0,
    DEEP_BLOOBER_SEA = 1,
    SPINY_DESERT = 2,
    WOODY_WOODS = 3,
    CREEPY_CAVERN = 4,
    WALUIGIS_ISLAND = 5
};

enum {
    WATCH_AVAILABLE = 0,   /* may still spawn */
    WATCH_ISSUED    = 1,   /* handed out, not yet used */
    WATCH_USED      = 2,   /* used; jump pending at end of round */
    WATCH_SPENT     = 3,   /* jump applied */
};


// typedef struct SomeStruct2 {
//     /* 0x00 */ char pad0[2];
//     /* 0x02 */ s16 unk_02;
//     /* 0x04 */ UnkBoard2** unk_04;
//     /* 0x08 */ Process* proc;
//     /* 0x0C */ s16 unk_0C;
//     /* 0x0E */ char padE[2];
// } SomeStruct2; //sizeof 0x10

typedef struct BoardStatus {
    /* 0x00 */ s8 uiUpdatePaused;
    /* 0x01 */ s8 unk1;
    /* 0x02 */ u8 unk2[2];
    /* 0x04 */ u8 spaceType;
    /* 0x05 */ u8 uiVisible;
    /* 0x06 */ s8 prevStars;
    /* 0x07 */ s8 prevRank;
    /* 0x08 */ s16 prevCoins;
    /* 0x0A */ s16 playerIndex;
    /* 0x0C */ char unk_0C[2];
    /* 0x0E */ s16 unkE;
    /* 0x10 */ f32 xPos;
    /* 0x14 */ f32 yPos;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ omObjData* unk30;
    /* 0x34 */ char pad34[2];
    /* 0x36 */ s16 unk_36;
    /* 0x38 */ char unk_38[2];
    /* 0x3A */ s16 unk_3A;
    /* 0x3C */ char unk_3C[4];
    /* 0x40 */ s16 unk_40[3];
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ char pad48[0x1E];
    /* 0x66 */ s16 counts[3]; //star count, coin count?
} BoardStatus; //sizeof 0x6C

typedef struct UnkVibrateProcess {
    s16 playerNo;
    s16 vibrateStrength;
    s16 sleepTime;
    Process* proc;
} UnkVibrateProcess;

typedef struct UnkCoinThing {
/* 0x00 */ u8 digits[3];
/* 0x03 */ char unk_03[5];
/* 0x08 */ s16 unk_08[2];
} UnkCoinThing;

typedef struct HvqHeader {
    s32 magic;
    u8* unk4;
} HvqHeader;

typedef struct HvqUnk {
    s32 unk0;
    u8* unk4;
    HvqHeader* unk8;
} HvqUnk;

typedef struct UnkBoard7 {
    /* 0x00 */ s8  unk_00;
    /* 0x01 */ s8  unk_01;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ s16 unk_04;
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ Vec pos;
    /* 0x14 */ Vec vel;
} UnkBoard7; /* size 0x20 */

extern Unk800CD2A0 D_800CD2A0_CDEA0;
extern omOvlHisData D_800D4190_D4D90;

extern s16 mbDlgWinId;
extern s32 mbTurnOnF;
extern s16 mbCameraBtnF;
extern s16 mbItemBtnF;
extern s16 mbovlhisidx;
extern s32 mbGameMode;
extern s32 mbWalkNum;
extern s16 mbWinId;
extern omOvlHisData mbovlhis[5];
extern s32 D_8010197C_11559C_shared_board[];
extern BoardStatus mbStatusData[MB_MAX_PLAYERS]; //TODO: this is 4 right? not 5?
extern s32 mbCharNameMesTbl[];
extern Object* D_801011FC_114E1C_shared_board;
extern omObjData* D_801055E8_119208_shared_board[];
extern s8 HmfPauseF;
extern s32 D_801055F8_119218_shared_board;
extern s16 D_80105706_119326_shared_board;
extern s16 kakusiMasuCoin;
extern s16 kakusiMasuStar;
extern s16 kakusiMasuItem;
extern s16 mbItemCursorGrpId;

//size based on MB1_ObjectSetup (calls to MBItemHookSet)
//not really sure what to call this, it includes the boo event at index 0 for instance
extern void (*MBItemSubFunctions[22])(void);

//TODO: should these be here?
extern s16 D_800CE198_CED98;

#endif //_BOARD_H