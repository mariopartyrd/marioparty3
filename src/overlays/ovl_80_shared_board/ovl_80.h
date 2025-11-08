#include "common.h"
#include "game/object.h"
#include "game/board.h"
#include "malloc.h"

#define MINIGAME_ID(id) ((id) + 1)

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
/* 0x04 */ Object* unk_04;
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

typedef struct UnkBoard7 {
    s8 unk_00;
    char unk_01[0x1F];
} UnkBoard7;

//very closely resembles UnkBoard5, but member at offset 0x08 must be s16 here instead of s32?
typedef struct UnkBoard8 {
    struct UnkBoard8* unk_00; //?
    struct UnkBoard8* unk_04; //?
    s16 unk_08;
    s16 unk_0A;
    s16* unk_0C;
    f32* unk_10;
    f32* unk_14;
    s16* unk_18;
    s16* unk_1C;
} UnkBoard8; //sizeof 0x20

void MBModelAttrSetDispOff(Object*);

void func_800EE97C_10259C_shared_board(Object* arg0);
void func_800F641C_10A03C_shared_board(s32 playerIndex);
void func_800E9940_FD560_shared_board(Vec*, f32*);
UnkBoard8* func_800F2C48_106868_shared_board(s16 arg0, s16 arg1);
void func_800F2CA4_1068C4_shared_board(UnkBoard8*);
void func_800F66DC_10A2FC_shared_board(s32);
void func_800F6BC4_10A7E4_shared_board(s32);
void func_800F6ECC_10AAEC_shared_board(s32);
Object* MBModelFileCreate(s32, s32, f32, s32, s32);
s32 PlayerHasEmptyItemSlot(s32 arg0);
Object* func_800D912C_ECD4C_shared_board(s32, s32, f32, s32, s32);
void MBModelKill(Object*);
void MBDlgWinCreate(s32, s32);
void MBDlgWinClose(void);
void MBDlgWinKill(void);
void func_800D7714_EB334_shared_board(void); 
void MBModelClose(void); 
void func_800DCB8C_F07AC_shared_board(void); 
void func_800DF8B4_F34D4_shared_board(void); 
void func_800E18FC_F551C_shared_board(void); 
void func_800E4BA0_F87C0_shared_board(void); 
void func_800E6404_FA024_shared_board(void); 
void func_800E66D4_FA2F4_shared_board(void); 
void func_800E66E0_FA300_shared_board(void); 
void func_800E69D8_FA5F8_shared_board(void); 
void func_800EA284_FDEA4_shared_board(void); 
void func_800EA694_FE2B4_shared_board(void); 
void func_800EB09C_FECBC_shared_board(void); 
void func_800F27C4_1063E4_shared_board(void);
void func_800F2A34_106654_shared_board(void);
void func_800F4730_108350_shared_board(void);
void func_800FC8A4_1104C4_shared_board(void);
void func_80012640_13240(s16, Gfx**);
void func_800127C4_133C4(s16, Gfx**);
void func_80017C10_18810(Mtx*, f32, f32, f32);
void func_80017CD0_188D0(Mtx*, f32, f32, f32);
void func_800185A4_191A4(Mtx*, f32);
u16 func_8004D6AC_4E2AC(s32, s32, s32);
void func_8004D6E8_4E2E8(s16);
void func_800898F0_8A4F0(Mtx*, Mtx*);
void func_80089980_8A580(Mtx*, Mtx*);
void func_800E989C_FD4BC_shared_board(void*);
s16 MBMasuBlockGet(u16, u8);
void func_800DA790_EE3B0_shared_board(u16 arg0, u16 arg1, char* arg2, u8 arg3, u8 arg4);
Object* MBModelCreate(u8, u32*);
void MBModelTempAllocFree(Object*);
void func_800F3400_107020_shared_board(omObjData*);
void func_800F4190_107DB0_shared_board(void);
void func_800F43FC_10801C_shared_board(s32);
void func_800F4798_1083B8_shared_board(u32, s32);
void func_800F4874_108494_shared_board(s32, s16, s16);
s32 func_800EECB0_1028D0_shared_board(s32);
s32 MBMotionCheck(Object*);
void MBMotionShiftSet(Object*, s16, s32, s32, u16);
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
void func_800DE9AC_F25CC_shared_board(s32, s32);
void func_800F76A4_10B2C4_shared_board(s32 arg0);
s16 MBMasuLinkMasuIdGet(u16 arg0, u16 arg1);
s16 MBMasuLinkNumGet(u16);
void func_800FF900_113520_shared_board(s16, s16);
s16 GetCurrentPlayerIndex(void);
void omVibrate(s16, s32, s32, s32);
void func_800F7610_10B230_shared_board(void);
void MBDlgWinExec(s32, s32);
void func_800F74E4_10B104_shared_board(void);
void func_800F76A4_10B2C4_shared_board(s32);
void func_800F7578_10B198_shared_board(void);
void func_800F7FE8_10BC08_shared_board(void);
void MBCoinChangeCreate(s32 player, s32 coins);
void func_800DB884_EF4A4_shared_board(s32);
s32 func_800DBEC0_EFAE0_shared_board(s32);
void MBCoinChangeStatusCreate(s32, s32);
void func_800E48F4_F8514_shared_board(void);
void MBDlgWinClose(void);
void MBDlgWinKill(void);
void MBDlgWinInsertCreate(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_800ECC0C_10082C_shared_board(Vec*);
void func_800ED128_100D48_shared_board(Vec*, Vec*, Vec*, s32);
void func_800F5D44_109964_shared_board(s32, s32);
void func_800E6CF8_FA918_shared_board(u8* input, u8* output, s32 compressedSize);
s32 BoardGetTurnTier(s32);
void func_800F5E24_109A44_shared_board(s32);
void func_800D95C4_ED1E4_shared_board(f32);
void func_800EA60C_FE22C_shared_board(void);
void MBMasuCreate(s32, s32);
void func_800F453C_10815C_shared_board(void);
void func_800F4874_108494_shared_board(s32, s16, s16);
void func_800E69D8_FA5F8_shared_board(void);
void func_800E66E0_FA300_shared_board(void);
void MBHelpWinKill(Unk3*);
void MBWinOpen(s32);
void MBWinInsertOpen(s32 arg0, char* arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5);
void func_800EC3C0_FFFE0_shared_board(s32);
void func_800EC3E4_100004_shared_board(void);
u32 func_800EE884_1024A4_shared_board(Object* arg0, s16 arg1, s16 arg2);
void func_800E69BC_FA5DC_shared_board(s32);
s32 func_800E9344_FCF64_shared_board(f32, f32);
void func_800E6630_FA250_shared_board(Addr);
f32 func_800D76D0_EB2F0_shared_board(s32);
void MBModelInit(void);
void MBModelDispOn(Object*);
void MBModelDispOff(Object*);
void func_800DB5DC_EF1FC_shared_board(void);
void func_800DF854_F3474_shared_board(void);
void MBCoinChangeInit(void);
void func_800E4B60_F8780_shared_board(void);
void func_800E6264_F9E84_shared_board(void);
void func_800E63F0_FA010_shared_board(void);
void func_800E9EF4_FDB14_shared_board(void);
void func_800ECAB4_1006D4_shared_board(void);
void func_800F25D8_1061F8_shared_board(s16);
void func_800F26E8_106308_shared_board(void);
void func_800F27D0_1063F0_shared_board(void);
void func_800F2A20_106640_shared_board(void);
void func_800F8908_10C528_shared_board(void);
void func_800F68E0_10A500_shared_board(s32 arg0, s32 arg1, s16 arg2);
void func_800F6BC4_10A7E4_shared_board(s32 arg0);
void func_800F66DC_10A2FC_shared_board(s32 arg0);
void func_800F6ECC_10AAEC_shared_board(s32 arg0);
s32 func_800E4A7C_F869C_shared_board(void);
s32 func_800FFA4C_11366C_shared_board(s32, s32, s32);
void MBDlgResultWinExec(s32);
void func_800FFAEC_11370C_shared_board(s32);
void MBDlgWinInsertCreateY(s16 arg0, s32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, s16 arg7);
void func_800EBF48_FFB68_shared_board(s16, s32);
s16 MBWinCreate(s16, s16*, s16);
void MBMotionSet(Object* arg0, s16 arg1, u16 arg2);
void func_800E6420_FA040_shared_board(s16, s32);
f32 MBVecAngleGet(Vec*);
void func_800E644C_FA06C_shared_board(s16, s16, s16, s32);
void func_800ECF9C_100BBC_shared_board(s16);
void MBSaveInit(void);
void func_800EDC20_101840_shared_board(s32);
s32 func_800EDC40_101860_shared_board(void);
void MBDlgWinExecY(s16, s32, s32);
void func_800EDC58_101878_shared_board(s16, s32);
void func_800EE2A4_101EC4_shared_board(s16);
void func_800EDC74_101894_shared_board(s16, s32);
void func_800EE2C0_101EE0_shared_board(s16);
void func_800F2304_105F24_shared_board(s32 playerIndex, s16 arg1, u16 arg2);
void func_800F6780_10A3A0_shared_board(s32, s32, f32, f32);
Process* func_8010FB54_3256C4_ChillyWaters(s16, s16, s16, s16, s16, s16);
void MBMapFullExec(s32);
void MBItemHelpCreate(void);
void func_800E3584_F71A4_shared_board(void);
void MBItemScaleEff(void);
void MBItemScaleEffCreate(void);
void MBItemDescExec(s32);
s32 func_800F6724_10A344_shared_board(s32);
void func_800F6848_10A468_shared_board(s32, s32, f32*, f32*);
void func_800F69B0_10A5D0_shared_board(s32, s32, u16);
void func_8010067C_11429C_shared_board(s32);
void func_800E1450_F5070_shared_board(omObjData* arg0);
f32 func_800E72DC_FAEFC_shared_board(void);
void MBModelAttrSetDispOn(Object*);
void func_800EBCFC_FF91C_shared_board(s16*);
s32 func_800037C4_43C4(s16);                        /* extern */
void func_800DECBC_F28DC_shared_board(void);               /* extern */
void func_800E6FBC_FABDC_shared_board(void);               /* extern */
void func_800E9730_FD350_shared_board(f32);              /* extern */
void func_800E9AC8_FD6E8_shared_board(f32);              /* extern */
void func_800ECB14_100734_shared_board(s16, s16);      /* extern */
void func_800F2834_106454_shared_board(void);              /* extern */
void func_800F5D8C_1099AC_shared_board(void);              /* extern */
void func_800F91A4_10CDC4_shared_board(void);           /* extern */
void func_800F93A4_10CFC4_shared_board(void);           /* extern */
void func_800FF0F8_112D18_shared_board(void);           /* extern */
void func_800FF158_112D78_shared_board(void);           /* extern */
extern s16 D_80105706_119326_shared_board;
extern s16 D_80101482_1150A2_shared_board;
extern s32 D_80102CB0_1168D0_shared_board;
extern s32 D_80102CB4_1168D4_shared_board;
extern s32 D_80101040_114C60_shared_board[];
extern s16 D_801010E8_114D08_shared_board[][2];
extern s32 (*MBItemFunctions[])(void);
extern s16 D_8010570C_11932C_shared_board;
extern s16 mbWinId;
extern UnkBoard7 D_80104A00_118620_shared_board[];
extern s32 D_80105200_118E20_shared_board;
extern s32 D_80101B40_115760_shared_board[];
extern s16 D_800D6A48_D7648;
extern s16 mbDlgWinId;
extern f32 D_80105650_119270_shared_board;
extern Object* D_80105628_119248_shared_board;
extern s32 D_80101490_1150B0_shared_board[];
extern Object* D_801011FC_114E1C_shared_board;
extern s16 D_80101480_1150A0_shared_board;
extern s16 D_80101482_1150A2_shared_board;
extern s16 D_8010570C_11932C_shared_board;
extern void (*D_80101B64_115784_shared_board)(void);
extern void (*D_80101B68_115788_shared_board)(void);
extern void (*D_80101B6C_11578C_shared_board)(void);
extern s16 D_80105664_119284_shared_board;
extern s16 D_80105666_119286_shared_board;
extern u8 D_80101DE8_115A08_shared_board[][3];
extern s32 D_80102DCC_1169EC_shared_board;
extern HvqHeader* D_80102DD0_1169F0_shared_board;
extern Addr D_101358;
extern Addr D_101398;
extern s16 D_800CCF28_CDB28;
extern Mtx* D_800D1F68_D2B68;
extern u16 gTotalSpaces;
extern s16 D_80105260_118E80_shared_board;
extern u16 D_80105262_118E82_shared_board;
extern u8 D_80101308_114F28_shared_board[]; //u8 array that links space type to render type
extern Gfx D_801013D8_114FF8_shared_board[];
extern u8* D_80105220_118E40_shared_board[]; //space form images
extern f32 D_80105290_118EB0_shared_board[];
extern s32 D_801052B0_118ED0_shared_board;
extern u8 (*D_801012C4_114EE4_shared_board)[SPACES_MAX];
extern s32 D_80103138_116D58_shared_board;
extern OSMesgQueue D_80104880_1184A0_shared_board;
extern OSMesgQueue D_80104928_118548_shared_board;
extern OSMesgQueue D_801049D0_1185F0_shared_board;
extern s32 D_800D41B0_D4DB0[];
extern s32 D_801014A0_1150C0_shared_board[];
extern void (*MBItemSubFunctions[22])(void); //size based on func_80107CC4_31D834_ChillyWaters (calls to MBItemHookSet)
extern s32 D_80105654_119274_shared_board;
extern s32 D_80105630_119250_shared_board[3];
extern s32 D_80105634_119254_shared_board;
extern s32 D_80105638_119258_shared_board;
extern LinkData* D_80105218_118E38_shared_board;
extern SpaceData* D_80105214_118E34_shared_board;
extern u8 D_80105268_118E88_shared_board[];
extern s32 D_801055F8_119218_shared_board;
extern s32 D_80101A50_115670_shared_board[]; //randomly generated items
extern s32 D_80100F90_114BB0_shared_board;
extern s32 D_8010197C_11559C_shared_board[]; //item mainFS ID array

extern u8 D_801014C0_1150E0_shared_board[];
#define SHARED_BOARD_UNK_SIZE_0 4
extern s16 D_801055FC_11921C_shared_board[SHARED_BOARD_UNK_SIZE_0];
extern s16 D_80105608_119228_shared_board[SHARED_BOARD_UNK_SIZE_0][3];
extern s16 D_80101908_115528_shared_board[];
extern s32 D_80101788_1153A8_shared_board;
extern s32 D_8010178C_1153AC_shared_board;
extern char D_800D5218_D5E18[];
extern s16 kakusiMasuCoin;
extern s16 kakusiMasuStar;
extern s16 kakusiMasuItem;
extern s16 D_80105588_1191A8_shared_board[];
extern RGB D_8010188C_1154AC_shared_board[];
extern s8 D_800D20B1_D2CB1;
extern s32 D_80101780_1153A0_shared_board;
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
