#ifndef _GAMEWORK_DATA_H
#define _GAMEWORK_DATA_H

#include "ultra64.h"
#include "game/object.h"

typedef struct GwCommon_s {
/* 0x00 */ u8 unk_00;
/* 0x01 */ u8 languageIndex;
/* 0x02 */ u16 mgRecord[8]; //is this still 8 in length like mp1?
/* 0x12 */ char unk_12[4];
/* 0x16 */ u8 mgUnlock[7]; //is this still 7 in length like mp1?
/* 0x1D */ char unk_1D[0x6E];
/* 0x8B */ u8 flag[0xC];
/* 0x97 */ char pad97[7];
/* 0x9E */ s8 unk9E;
/* 0x9F */ s8 unk9F;
/* 0xA0 */ s8 unkA0;
/* 0xA1 */ s8 unkA1;
/* 0xA2 */ s8 unkA2;
/* 0xA3 */ char padA3[1];
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

enum PlayerFlags {
    PLAYER_IS_CPU = 1,
};

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

// TODO: old GW_PLAYER definition from before we moved branches from master to main. Double check
//       if we want to keep docs and/or old member names.

// typedef struct mp3_PlayerData {
// /* 0x00 */ u8 group; //for which group you belong to in a minigame
// /* 0x01 */ u8 cpu_difficulty;
// /* 0x02 */ u8 controller_port;
// /* 0x03 */ u8 characterID;
// /* 0x04 */ u8 flags1; //value & 1 == Player is CPU
// /* 0x05 */ char unk_05;
// /* 0x06 */ s16 minigameCoinsWon; //extra coins collected in minigames
// /* 0x08 */ s16 minigameCoins; //coins for winning current minigame
// /* 0x0A */ s16 coins; //referenced as u16 and s16 (usually if u16 it's casted to s16)
// /* 0x0C */ char unk_0C[2];
// /* 0x0E */ s8 stars;
// /* 0x0F */ u8 chainIndexCur;
// /* 0x10 */ u8 spaceIndexCur;
// /* 0x11 */ u8 chainIndexNext;
// /* 0x12 */ u8 spaceIndexNext;
// /* 0x13 */ u8 unk_13; //(Chain Index?)
// /* 0x14 */ u8 unk_14; //(Space Index?)
// /* 0x15 */ u8 chainIndexPrevious;
// /* 0x16 */ u8 spaceIndexPrevious;
// /* 0x17 */ u8 flags2;
// /* 0x18 */ u8 items[3];
// /* 0x1B */ u8 bowser_suit_flags;
// /* 0x1C */ u8 turn_status; //space type landed on (blue, red, etc.)
// /* 0x1D */ s8 playerIndex;
// /* 0x1E */ char unk_1E[2]; //likely padding
// /* 0x20 */ void* unk_20;
// /* 0x24	*/ void* player_obj; //ptr to struct 0x48 in size (things like model position, rotation, etc.)
// /* 0x28 */ s16 minigameCoinsTotal; //for minigame star
// /* 0x2A */ s16 coinsPeak; //most coins held at once for coin star
// /* 0x2C */ s8 happeningSpacesLandedOn;
// /* 0x2D */ s8 redSpacesLandedOn;
// /* 0x2E */ s8 blueSpacesLandedOn;
// /* 0x2F */ s8 chanceSpacesLandedOn;
// /* 0x30 */ s8 bowserSpacesLandedOn;
// /* 0x31 */ s8 battleSpacesLandedOn;
// /* 0x32 */ s8 itemSpacesLandedOn;
// /* 0x33 */ s8 bankSpacesLandedOn;
// /* 0x34 */ s8 gameGuySpacesLandedOn;
// /* 0x35 */ char unk_35[3]; //likely padding
// } GW_PLAYER; //sizeof 0x38

extern GW_COMMON GwCommon;
extern GW_STORY GwStory;
extern GW_SYSTEM GwSystem;
extern GW_PLAYER GwPlayer[4];

#endif