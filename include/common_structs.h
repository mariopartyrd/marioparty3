#ifndef _PLAYER_H
#define _PLAYER_H

#include "common.h"
#include "process.h"
#include "math.h"
#include "game/object.h"

#define CUR_PLAYER -1
#define CUR_TURN -1

#define MAX_PLAYERS 4
#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNT_2D_ROWS(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNT_2D_COLS(arr) (s32)(sizeof(arr[0]) / sizeof(arr[0][0]))

#define SCREEN_WIDTH_CENTER SCREEN_WIDTH / 2.0f
#define SCREEN_HEIGHT_CENTER SCREEN_HEIGHT / 2.0f
#define ASPECT_RATIO (4.0f / 3.0f)

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
    /* 0x00 */ char unk_00[0x28];
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ char unk_2A[10];
    /* 0x34 */ DiceInstance* dice;
    /* 0x38 */ char unk_38[12];
} UnkDiceRelatedInner;

typedef struct UnkDiceRelated {
/* 0x00 */ s16 unk_00;
/* 0x02 */ char unk_02[6];
/* 0x08 */ UnkDiceRelatedInner UnkDiceInner;
} UnkDiceRelated; //sizeof 0x4C

typedef struct PartnerStats {
/* 0x2C */ s8 frontPoweredUp;
/* 0x2D */ s8 backPoweredUp;
/* 0x2E */ s8 frontHp;
/* 0x2F */ s8 backHp;
/* 0x30 */ s8 frontCost;
/* 0x31 */ s8 backCost;
/* 0x32 */ s8 frontPower;
/* 0x33 */ s8 backPower;
/* 0x34 */ s8 frontID;
/* 0x35 */ s8 backID;
} PartnerStats;

typedef struct {
/* 0x2C */ s8 hatenaPrize;  // happening-space star
/* 0x2D */ s8 redPrize;
/* 0x2E */ s8 bluePrize;
/* 0x2F */ s8 eventPrize;
/* 0x30 */ s8 kupaPrize;
/* 0x31 */ s8 battlePrize;
/* 0x32 */ s8 itemPrize;
/* 0x33 */ s8 bankPrize;
/* 0x34 */ s8 gamblePrize;
/* 0x35 */ s8 duelNo;
} PrizeStats;

typedef struct GwPlayer_s {
/* 0x00 */ u8 group;
/* 0x01 */ u8 cpu_difficulty;
/* 0x02 */ u8 pad;
/* 0x03 */ u8 chr;
/* 0x04 */ u8 stat;
/* 0x05 */ char unk_05;
/* 0x06 */ s16 gameCoin;
/* 0x08 */ s16 bonusCoin;
/* 0x0A */ s16 coin;
/* 0x0C */ s16 checkCoin;
/* 0x0E */ s8 star;
/* 0x0F */ s8 clink;
/* 0x10 */ s8 cidx;
/* 0x11 */ s8 nlink;
/* 0x12 */ s8 nidx;
/* 0x13 */ s8 nnlink;
/* 0x14 */ s8 nnidx;
/* 0x15 */ s8 blink; //b link
/* 0x16 */ s8 bidx;
/* 0x17 */ u8 rev; //related to reverse mushroom flags
/* 0x18 */ s8 itemNo[3];
/* 0x1B */ s8 itemTurn;
/* 0x1C */ u8 color;
/* 0x1D */ u8 turn;
/* 0x1E */ char unk_1E[2]; //likely padding
/* 0x20 */ void* unk_20;
/* 0x24 */ Object* player_obj;
/* 0x28 */ s16 gamePrize; //minigame star
/* 0x2A */ s16 coinPrize; //coin star
/* 0x2C */ union {
    PrizeStats      prize;
    PartnerStats    partners;
} stats;
/* 0x36 */ char unk_36[2];
} GW_PLAYER __attribute__((aligned(4))); //sizeof 0x38;

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
/* 0x06 */ u16 stat;
} omOvlHisData; //sizeof 0x08

typedef struct GW_SYSTEM {
    /* 0x00 - 800CD058 */ s8 playMode; //0x01 - Lite Play pause screen, 0x04 - Story Play pause screen
    /* 0x01 - 800CD059 */ s8 current_board_index;
    /* 0x02 - 800CD05A */ s8 total_turns;
    /* 0x03 - 800CD05B */ s8 current_turn;
    /* 0x04 - 800CD05C */ s8 current_game_length; // 00=Lite Play,01=Standard Play,02=Full Play,03=Custom Play
    /* 0x05 - 800CD05D */ s8 current_star_spawn; // Index of star space (index into star_spawn_indices)
    /* 0x06 - 800CD05E */ s8 star_spawn_indices[7];
    /* 0x0D - 800CD065 */ s8 unk_0D;
    /* 0x0E - 800CD066 */ s8 unk_0E;
    /* 0x0F - 800CD067 */ s8 current_player_index;
    /* 0x10 - 800CD068 */ s8 minigame_index;
    /* 0x11 - 800CD069 */ s8 current_space_index;
    /* 0x12 - 800CD06A */ s8 save_mode; //00 - Save every turn, 01 - Save this turn, 02 - Don't save
    /* 0x13 - 800CD06B */ s8 show_minigame_explanations; //00 - show, 01 - hide
    /* 0x14 - 800CD06C */ s8 message_speed; //00 - Fast, 01 - Normal, 02 - Slow
    /* 0x15 - 800CD06D */ s8 walk_speed; //00 - Fast, 01 - Normal, 02 - Slow
    /* 0x16 - 800CD06E */ s8 show_com_minigames; //00 - Show COM minigame, 01 - Hide COM minigame
    /* 0x17 - 800CD06F */ char unk_17[0x27]; //unknown
    union {
        /* 0x3E - 800CD096 */ s16 halfWordBytes[9]; //bytes related to storing information for each board
        /* 0x3E - 800CD096 */ s8 bytes[18]; //bytes related to storing information for each board
    } boardData;
    /* 0x50 - 800CD0A8 */ char unk_50[1];
    /* 0x51 - 800CD0A9 */ u8 cur_player_used_item; //1 if player already used an item this turn
    /* 0x52 - 800CD0AA */ s16 unk_52;
    /* 0x54 - 800CD0AC */ s16 forceShopHost; //0 is toad, baby bowser is 1
    /* 0x56 - 800CD0AE */ s16 slow_dice_flags;
    /* 0x58 - 800CD0B0 */ s16 unk_58;
    /* 0x5A - 800CD0B2 */ s16 playerIndexVisitingBowser;
    /* 0x5C - 800CD0B4 */ u16 bank_coins;
    /* 0x5E - 800CD0B6 */ u8 data_flags[8]; //unknown what this is, unknown size
    /* 0x66 - 800CD0B8 */ u8 unk_66[0x3E];
} GW_SYSTEM; //sizeof 0xA4
typedef struct GwCommon_s {
/* 0x00 */ u8 unk_00;
/* 0x01 */ u8 languageIndex;
/* 0x02 */ u16 mgRecord[8]; //is this still 8 in length like mp1?
/* 0x12 */ char unk_12[4];
/* 0x16 */ u8 mgUnlock[7]; //is this still 7 in length like mp1?
/* 0x1D */ char unk_1D[0x6E];
/* 0x8B */ u8 flag[12]; //is this still 12 in length like mp1?
/* 0x97 */ char unk_9D[0xD];
} GW_COMMON; //sizeof 0xA4?

typedef struct GW_STORY {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 unk3[12];
    /* 0x0F */ u8 unkF;
    /* 0x10 */ u8 unk10[6][12];
    /* 0x58 */ u8 unk58[6];
    /* 0x5E */ u8 unk5E[6];
    /* 0x64 */ char unk_64[0x10];
} GW_STORY; /* size = 0x74 */

typedef struct MinigameTable {
    /* 0x00 */ u8 minigameType;
    /* 0x01 */ char unk_01[0x13];
} MinigameTable;

typedef struct RectF {
/* 0x00 */ f32 x1;
/* 0x04 */ f32 y1;
/* 0x08 */ f32 x2;
/* 0x0C */ f32 y2;
} RectF; //sizeof 0x10

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

typedef struct {
    Mtx perspMtx;
    Mtx lookAtMtx;
} HuCamMtxs;

typedef struct HuCamera {
    /* 0x000 */ u16 perspNorm;
    /* 0x002 */ char pad2[2];
    /* 0x004 */ f32 unk4;
    /* 0x008 */ f32 unk8;
    /* 0x00C */ f32 unkC;
    /* 0x010 */ Vec pos;
    /* 0x01C */ Vec at;
    /* 0x028 */ Vec up;
    /* 0x034 */ Vec screenScale;
    /* 0x040 */ Vec screenPos;
    /* 0x04C */ s32 unk4C;
    /* 0x050 */ f32 fov[3];
    /* 0x05C */ f32 unk5C;
    /* 0x060 */ Vp viewports[3];
    /* 0x090 */ f32 screenLeft;
    /* 0x094 */ f32 screenTop;
    /* 0x098 */ f32 screenRight;
    /* 0x09C */ f32 screenBottom;
    /* 0x0A0 */ void (*unkA0)(void); //TODO: get correct signature for this
    /* 0x0A4 */ void* unkA4;
    /* 0x0A8 */ s32 unkA8;
    /* 0x0AC */ s32 unkAC;
    /* 0x0B0 */ HuCamMtxs mtxs[3];
} HuCamera;

#endif
