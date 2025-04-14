#include "common.h"
#include "game/object.h"
#include "malloc.h"

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
    /* 0x30 */ s32 unk30;
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

typedef struct LinkData {
/* 0x00 */ s16 chainIndicies;
/* 0x02 */ s16 unk2;
/* 0x04 */ s16* spaces;
} LinkData; //sizeof 0x08

typedef struct UnkBoard {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 unk_02;
/* 0x04 */ s32 unk_04;
/* 0x08 */ omObjData* unk_08;
} UnkBoard; //sizeof 0x0C

typedef struct UnkBoard2 {
/* 0x00 */ s16 unk_00;
/* 0x04 */ Object* obj;
} UnkBoard2;

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

void func_800DA790_EE3B0_shared_board(s32, u16, char*, s32, s32);
Object* func_800D90C8_ECCE8_shared_board(u8, s32);
void func_800D9714_ED334_shared_board(Object*);
void func_800F3400_107020_shared_board(omObjData*);
void func_800F4190_107DB0_shared_board(void);
void func_800F43FC_10801C_shared_board(s32);
void func_800F4798_1083B8_shared_board(u32, s32);
void func_800F4874_108494_shared_board(s32, s16, s16);
s32 func_800EECB0_1028D0_shared_board(s32);
s32 func_800D9E0C_EDA2C_shared_board(s32);
void func_800D9D84_ED9A4_shared_board(s32, s16, s32, s32, u16);
void func_800EE7AC_1023CC_shared_board(omObjData* func);
s32 BoardPlayerRankCalc(s32 player);
void UpdatePlayerBoardStatus(s32);
void func_800F6A88_10A6A8_shared_board(s16, u16);
void func_800F6AD0_10A6F0_shared_board(s32, f32, f32);
void func_800F6E4C_10AA6C_shared_board(s32, s32, s32*, s32*);
void func_800F6748_10A368_shared_board(s16, s16, f32*, f32*);
void func_800F64E4_10A104_shared_board(s32, s32);
void func_800F3A80_1076A0_shared_board(s32);
void func_800F3BD0_1077F0_shared_board(s32);
void func_800F3E34_107A54_shared_board(s32);
void func_800F3FF4_107C14_shared_board(s32);
void func_800F5F98_109BB8_shared_board(s32, s32);
void func_800F6AA4_10A6C4_shared_board(s16 arg0, s16 arg1);
void func_800F4994_1085B4_shared_board(s32);
void func_800F4348_107F68_shared_board(void);
void func_800F462C_10824C_shared_board(s32);
void func_800F5644_109264_shared_board(void);
void func_800F5BF4_109814_shared_board(s32, s32, s32);
void func_800F3D70_107990_shared_board(s32);
void func_800F3F0C_107B2C_shared_board(s32);
void func_800F59B4_1095D4_shared_board(omObjData*);
s32 func_800F2198_105DB8_shared_board(s16);
void func_800DC128_EFD48_shared_board(s32);
void func_800DCA64_F0684_shared_board(s32);
void func_800F696C_10A58C_shared_board(s32, s32, f32, f32);
s32 func_800DEB2C_F274C_shared_board(s32);
void func_800EC590_1001B0_shared_board(s32, s32);
void func_800DE9AC_F25CC_shared_board(s32, s32);
void func_800F76A4_10B2C4_shared_board(s32 arg0);
s16 func_800EB184_FEDA4_shared_board(u16 arg0, u16 arg1);
void func_800FF900_113520_shared_board(s16, s16);
s16 GetCurrentPlayerIndex(void);
void func_8004B25C_4BE5C(s16, s32, s32, s32);
void func_800F7610_10B230_shared_board(void);
void func_800EC590_1001B0_shared_board(s32, s32);
void func_800F74E4_10B104_shared_board(void);
void func_800F76A4_10B2C4_shared_board(s32);
void func_800F7578_10B198_shared_board(void);
void func_800F7FE8_10BC08_shared_board(void);
void ShowPlayerCoinChange(s32 player, s32 coins);
void func_800DB884_EF4A4_shared_board(s32);
s32 func_800DBEC0_EFAE0_shared_board(s32);
void func_800E1F28_F5B48_shared_board(s32, s32);
void func_800E48F4_F8514_shared_board(void);
void func_800EC6C8_1002E8_shared_board(void);
void func_800EC6EC_10030C_shared_board(void);
void func_800EC8EC_10050C_shared_board(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_800ECC0C_10082C_shared_board(Vec*);
void func_800ED128_100D48_shared_board(Vec*, Vec*, Vec*, s32);
void func_800F5D44_109964_shared_board(s32, s32);
void func_800E6CF8_FA918_shared_board(u8* input, u8* output, s32 compressedSize);
s32 BoardGetTurnTier(s32);
void func_800F5E24_109A44_shared_board(s32);
void func_800D95C4_ED1E4_shared_board(f32);
void func_800EA60C_FE22C_shared_board(void);
void func_800EAE10_FEA30_shared_board(s32, s32);
void func_800F453C_10815C_shared_board(void);
void func_800F4874_108494_shared_board(s32, s16, s16);
void func_800E69D8_FA5F8_shared_board(void);
void func_800E66E0_FA300_shared_board(void);
void func_800E21F4_F5E14_shared_board(void*);
s16 func_800EB184_FEDA4_shared_board(u16 arg0, u16 arg1);
void func_800EC134_FFD54_shared_board(s32);
void func_800EC1E8_FFE08_shared_board(s32, char*, s32, s32, s32, s32);
void func_800EC3C0_FFFE0_shared_board(s32);
void func_800EC3E4_100004_shared_board(void);
u32 func_800EE884_1024A4_shared_board(s32 arg0, s16 arg1, s16 arg2);
void func_800E69BC_FA5DC_shared_board(s32);
s32 func_800E9344_FCF64_shared_board(f32, f32);
void func_800E6630_FA250_shared_board(Addr);
f32 func_800D76D0_EB2F0_shared_board(void*);
void func_800D8F80_ECBA0_shared_board(void);
void func_800D9AA4_ED6C4_shared_board(Object*);
void func_800D9B24_ED744_shared_board(Object*);
void func_800DB5DC_EF1FC_shared_board(void);
void func_800DF854_F3474_shared_board(void);
void func_800E17B0_F53D0_shared_board(void);
void func_800E4B60_F8780_shared_board(void);
void func_800E6264_F9E84_shared_board(void);
void func_800E63F0_FA010_shared_board(void);
void func_800E9EF4_FDB14_shared_board(void);
void func_800ECAB4_1006D4_shared_board(void);
void func_800F25D8_1061F8_shared_board(s32);
void func_800F26E8_106308_shared_board(void);
void func_800F27D0_1063F0_shared_board(void);
void func_800F2A20_106640_shared_board(void);
void func_800F8908_10C528_shared_board(void);
void func_800F68E0_10A500_shared_board(s32 arg0, s32 arg1, s32 arg2);
void func_800F6BC4_10A7E4_shared_board(s32 arg0);
void func_800F66DC_10A2FC_shared_board(s32 arg0);
void func_800F6ECC_10AAEC_shared_board(s32 arg0);
s32 func_800E4A7C_F869C_shared_board(void);
s32 func_800FFA4C_11366C_shared_board(s32, s32, s32);
void func_800EC414_100034_shared_board(s32);
void func_800FFAEC_11370C_shared_board(s32);
void func_800EC70C_10032C_shared_board(s16, s32, s32, s32, s32, s32, s32, s16);
void func_800EBF48_FFB68_shared_board(s16, s8);
s16 func_800EBFE8_FFC08_shared_board(s16, s16*, s16);
void func_800D9CE8_ED908_shared_board(Object*, s16, u16);
void func_800E6420_FA040_shared_board(s16, s32);

extern Object* D_801011FC_114E1C_shared_board;
extern s16 D_80101480_1150A0_shared_board;
extern s16 D_80105702_119322_shared_board;
extern s16 D_8010570C_11932C_shared_board;
extern s32 D_80101B64_115784_shared_board;
extern s32 D_80101B68_115788_shared_board;
extern s32 D_80101B6C_11578C_shared_board;
extern s16 D_80105664_119284_shared_board;
extern s16 D_80105666_119286_shared_board;
extern u8 D_80101DE8_115A08_shared_board[][3];
extern s32 D_80102DCC_1169EC_shared_board;
extern HvqHeader* D_80102DD0_1169F0_shared_board;
extern s32 D_80103138_116D58_shared_board;
extern OSMesgQueue D_80104880_1184A0_shared_board;
extern OSMesgQueue D_80104928_118548_shared_board;
extern OSMesgQueue D_801049D0_1185F0_shared_board;
extern s32 D_800D41B0_D4DB0[];
extern s32 D_801014A0_1150C0_shared_board[];
extern void (*D_80102C58_116878_shared_board[22])(void); //size based on func_80107CC4_31D834_ChillyWaters (calls to func_800E2960_F6580_shared_board)
extern s32 D_80105654_119274_shared_board;
extern s32 D_80105630_119250_shared_board[];
extern s32 D_80105634_119254_shared_board;
extern s32 D_80105638_119258_shared_board;
extern LinkData* D_80105218_118E38_shared_board;
extern SpaceData* D_80105214_118E34_shared_board;
extern u8 D_80105268_118E88_shared_board[];
extern s32 D_801055F8_119218_shared_board;
extern s32 D_80101A50_115670_shared_board[]; //randomly generated items
extern s32 D_80100F90_114BB0_shared_board;
void (*D_80102C70_116890_shared_board)(void);
extern s16 D_800C9520_CA120[];
extern s32 D_8010197C_11559C_shared_board[22]; //item mainFS ID array
// s32 D_8010197C_11559C_shared_board[] = {
//     0x0013018E,
//     0x0013018F,
//     0x00130190,
//     0x00130191,
//     0x00130192,
//     0x00130193,
//     0x00130194,
//     0x00130195,
//     0x00130196,
//     0x00130197,
//     0x00130198,
//     0x00130199,
//     0x0013019A,
//     0x0013019B,
//     0x0013019C,
//     0x0013019D,
//     0x0013019E,
//     0x0013019F,
//     0x001301A0,
//     0x001301A1,
//     0x0013019D, //toad item bag
//     0x001301B6, //baby bowser item bag
// };

extern u8 D_801014C0_1150E0_shared_board[];
extern s16 D_80105592_1191B2_shared_board[];
#define SHARED_BOARD_UNK_SIZE_0 4
extern s16 D_801055FC_11921C_shared_board[SHARED_BOARD_UNK_SIZE_0];
extern s16 D_80105608_119228_shared_board[SHARED_BOARD_UNK_SIZE_0][3];
extern s16 D_80101908_115528_shared_board[];
extern s16 D_80105598_1191B8_shared_board;
extern s16 D_8010559A_1191BA_shared_board;
extern s32 D_80101788_1153A8_shared_board;
extern s32 D_8010178C_1153AC_shared_board;
extern char D_800D5218_D5E18[];
extern s16 gCoinBlockSpaceIndex;
extern s16 gStarBlockSpaceIndex;
extern s16 D_80105588_1191A8_shared_board[];
extern RGB D_8010188C_1154AC_shared_board[];
extern s8 D_800D20B1_D2CB1;
extern s32 D_80101780_1153A0_shared_board;
extern s16 D_8010559C_1191BC_shared_board[];
extern s16 D_801018E4_115504_shared_board[17][2];
extern s32 D_80101790_1153B0_shared_board;
extern f32 D_801055C8_1191E8_shared_board;
extern s16 D_801055E4_119204_shared_board;
extern Vec2f D_801055CC_1191EC_shared_board;
extern Vec2f D_801055DC_1191FC_shared_board;
extern Vec2f D_801055D4_1191F4_shared_board;
extern s16 PlayerBoardStatusRootPosition[8][2];
extern Process* D_80105580_1191A0_shared_board;
extern s16 D_801055C2_1191E2_shared_board;
extern s16 D_801055C4_1191E4_shared_board;
extern s32 D_80101784_1153A4_shared_board;
extern BoardStatus D_801057E0_119400_shared_board[];
extern UnkBoard D_80105718_119338_shared_board[16];
extern omObjData* D_801055E8_119208_shared_board[];
extern s32 D_80101F30_115B50_shared_board[3];
extern s32 D_80101944_115564_shared_board[]; //mainFS ids for character images
extern s32 D_801019D0_1155F0_shared_board[];
extern SpaceData* D_80105214_118E34_shared_board;
