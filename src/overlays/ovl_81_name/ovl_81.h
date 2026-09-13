#include "common.h"
#include "game/object.h"
#include "game/board.h"
#include "game/window.h"
#include "malloc.h"

typedef void (*PartnerFunc)(s16, s32, Object*, Object*, s32, s32);

typedef enum PartnerObjIndex {
    /* 0 */ PARTNEROBJINDEX_FRONT,
    /* 1 */ PARTNEROBJINDEX_BACK,
    /* 2 */ PARTNEROBJINDEX_MAX = MBD_MAX_PLAYERS,
} PartnerObjIndex;

#define POWERUP_NONE 1
#define POWERUP_ACTIVE 2

#define PARTNER_FRONT 0
#define PARTNER_BACK 1

typedef struct PartnerBaseAttributes {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 hp;
    /* 0x02 */ s8 power;
    /* 0x03 */ s8 cost;
    /* 0x04 */ void (*func1)(s16, s32, Object*, Object*, s32, s32);
    /* 0x08 */ void (*func2)(s16, s32, Object*, Object*, s32, s32);
    /* 0x0C */ void (*func3)(void);
    /* 0x10 */ void (*func4)(void);
} PartnerBaseAttributes; //sizeof 0x14

typedef struct UnkBoard4 {
    /* 0x00 */ struct UnkBoard4* unk_00; //TODO: is this correct?
    /* 0x04 */ struct UnkBoard4* unk_04; //TODO: is this correct?
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16* unk_0C;
    /* 0x10 */ f32* unk_10;
    /* 0x14 */ f32* unk_14;
    /* 0x18 */ s16* unk_18;
    /* 0x1C */ s16* unk_1C;
} UnkBoard4; //sizeof 0x20

typedef struct UnkBoard5 {
    /* 0x00 */ u8* unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s16* unk_0C;
    /* 0x10 */ f32* unk_10;
    /* 0x14 */ f32* unk_14;
    /* 0x18 */ s16* unk_18;
    /* 0x1C */ s16* unk_1C;
} UnkBoard5; //sizeof 0x20

extern UnkBoard4* D_80105400_name_81;
extern u16 D_80105404_name_81;
extern PartnerBaseAttributes PartnersBaseStats[];
extern Object* Duel_PartnerObjects[][PARTNEROBJINDEX_MAX];
extern process_func D_80101A90_name_81;
extern s32 D_80101A94_name_81;
extern s32 D_80101A98_name_81;
extern s16 D_80105494_name_81;
extern s16 D_80105496_name_81;
extern u8* D_80101980_name_81;
extern s32 D_80101984_name_81;
extern Object* D_80101988_name_81;
extern s32* D_801017DC_name_81[];
extern Process* D_8010195C_name_81;
extern s32* D_8010180C_name_81[];
extern s16 D_80101990_name_81;
extern s16 D_80105470_name_81[];
extern s32* D_8010183C_name_81[];
extern s16 D_80105480_name_81[];
extern s16 D_80101992_name_81;
extern s32 D_80101998_name_81[];
extern s16 D_801019C8_name_81[];
extern s16 D_8010555C_name_81;
extern s16 D_801011D0_name_81;

void MBDBackKill(void);
void MBDBackClose(void);
void func_800EBAD4_name_81(s32);
void func_800FC5D8_name_81(void);
void func_800FC4E4_name_81(void);
void func_800FC108_name_81(void);
void func_800D7F0C_name_81(void);
void func_800DBEB0_name_81(void);
void func_800DF210_name_81(void);
void func_800E0E38_name_81(void);
void func_800E28B0_name_81(void);
void func_800E4FF4_name_81(void);
void func_800E90B4_name_81(void);
void func_800E9564_name_81(void);
void func_800E9D9C_name_81(void);
void func_800F4030_name_81(void);
void func_800F4314_name_81(void);
void func_800FD55C_name_81(void);
void func_800DAAB0_name_81(void);
void func_800DF154_name_81(void);
s32 func_800F37B8_name_81(s16 playerIndex);
s32 func_800E1824_name_81(s32, s32, s32);
void func_800E1854_name_81(s32);
Process* func_800E0888_name_81(void);
void func_80100CEC_name_81(s32);
void func_800E5954_name_81(void);
void func_800E5BE8_name_81(void);
void func_800E5C20_name_81(void);
void func_800E856C_name_81(f32);
void MBDCameraSpeedSet(f32);
f32 MBDCameraSpeedGet(void);
void MBDCameraZoomSet(f32);
void MBDCamera3Dto2D(Vec*, Vec2f*);
f32 MBDCameraZoomGet(void);
Process* MBDCameraZoomMotStart(f32);
u16 MBDCameraPos3DSet(Vec*);
u16 MBDCameraPos2DSet(Vec2f*);
void MBDCameraPos2DGet(Vec2f*);
f32 MBDCameraSpeedGet(void);
void func_80100124_name_81(UnkBoard4*, s32);
Object* func_800D8314_name_81(s32, s32, f32, f32, s32);
void func_800FCF50_name_81(s32, s32);
void func_800D8E88_name_81(Object*);
void func_800D8F3C_name_81(Object*);
void func_800F8C68_name_81(s32);
void func_80100604_name_81(void);
s32 func_800F89D0_name_81(s32 playerIndex, s32 frontOrBackIndex, s16 arg2, s16 arg3);
void func_801007C4_name_81(void);
void func_800E5954_name_81(void);
void func_800E5964_name_81(void);
void func_801008E8_name_81(void);
void func_80100CA0_name_81(void);
void func_800DADA0_name_81(s8);
s32 func_800DB3E0_name_81(s8);
void func_800DB544_name_81(s8);
void func_800DB5AC_name_81(s8);
s32 func_800E1824_name_81(s32, s32, s32);
void func_800E1854_name_81(s32);
void func_800E5954_name_81(void);
void func_800E5BE8_name_81(void);
void func_800E5C20_name_81(void);
void func_800E856C_name_81(f32);
f32 func_800E8578_name_81(void);
void func_800F73C0_name_81(void);
void func_800F740C_name_81(void);
s16 func_800FC114_name_81(void);
void func_80100864_name_81(void);
void func_80100890_name_81(void);
UnkBoard4* func_800FFEEC_name_81(void);
void func_801000A4_name_81(UnkBoard4* arg0, u16 arg1);
void MBDCameraSpeedSet(f32);
s16 func_800EABBC_name_81(s16, s16*, s16);
void func_800EED68_name_81(s16, s32);
void func_800EF3B4_name_81(s16);
UnkBoard4* func_800F4528_name_81(s16 arg0, s16 arg1);
s32 func_800E1824_name_81(s32, s32, s32);
void func_800E1854_name_81(s32);
void func_800F4584_name_81(UnkBoard4*);
void func_800FAD04_name_81(s32 arg0);
void func_800D8F0C_name_81(Object*);
GW_PLAYER* MBDGetPlayerStruct(s32 playerIndex);
Object* MBDGetPlayerPartnerRef(s32 playerIndex, s32 frontOrBackIndex);
void func_800ECF1C_name_81(s32, Vec*, Vec*);
void func_800D7828_name_81(Vec*);
void func_800D7934_name_81(Vec*, f32);
void func_800D7EB8_name_81(void);
void func_800D8944_name_81(Object*);
void func_800DAB1C_name_81(void);
void func_800DF1B0_name_81(void);
void func_800E0CEC_name_81(void);
void func_800E2870_name_81(void);
void func_800E4F50_name_81(Addr);
void MBDBackLoad(s32);
void func_800E8D10_name_81(void);
void func_800E94D0_name_81(void);
void func_800E9B10_name_81(s32, s16);
void func_800EB664_name_81(void);
void func_800EF840_name_81(void);
void func_800EF880_name_81(void);
void func_800F3DFC_name_81(s32);
void func_800F3F4C_name_81(void);
void func_800F4080_name_81(void);
void func_800F4300_name_81(void);
void func_800F5BB4_name_81(s32 playerIndex);
void func_800F5EB0_name_81(s32);
void func_800F6390_name_81(void);
void func_800FC198_name_81(omObjData*);
void func_800E8180_name_81(f32, f32);
void func_800E4F50_name_81(Addr);
void func_800E8110_name_81(void);
void func_800E8180_name_81(f32, f32);
void func_800ED214_name_81(s32 playerIndex);
void func_800F82EC_name_81(s32);
Object* func_800D8010_name_81(u8, s32*);
Object* func_800F8034_name_81(s32);
Object* func_800F8050_name_81(s32);
void func_800F8108_name_81(s32 playerIndex);
void func_800F85A4_name_81(s32 playerIndex, s32 frontOrBackIndex);
void func_800D90D0_name_81(Object*, s16, u16);
s16 MBDGetCurrentPlayerIndex(void);
void func_800D918C_name_81(Object*, s16, s16, s16, s32);
s32 func_800EFE20_name_81(f32);
void func_800FB160_name_81(void);
void func_800D90D0_name_81(Object*, s16, u16);
void func_800FAEFC_name_81(s32);
void func_800FB038_name_81(Object*, s16, u16);
void func_800EB278_name_81(void);
void func_800EB29C_name_81(void);
void func_800EB58C_name_81(void);
void func_800FA120_name_81(void);
void func_800FC8C4_name_81(Vec*);
void func_800EAB6C_name_81(s32, s32);

extern Vec D_80105460_name_81;
extern s32 D_801019E0_name_81[][2];
extern s32 D_80101A08_name_81[];
extern s32 D_80101A1C_name_81[];
extern s16 D_80101992_name_81;
extern s16 D_80101994_name_81;
extern s8* D_80101968_name_81;
extern s8* D_8010196C_name_81;
extern s8* D_80101970_name_81;
extern s8* D_80101974_name_81;
extern s8* D_80101978_name_81;
extern s8* D_8010197C_name_81;
extern Vec D_80105540_name_81;
extern s32 D_8010554C_name_81;
extern s32 D_80105550_name_81;
extern s32 D_80105558_name_81;
extern s32 D_80105620_name_81;
extern s32 D_8010570C_name_81;
extern s32 D_80105718_name_81;
extern s32 D_8010571C_name_81;

Process* func_800E415C_name_81(void);
Process* func_800E47B8_name_81(s16, s8, Vec*, Vec*, s32);
void func_800E5954_name_81(void);
void func_800E5964_name_81(void);
void MBDBackTPLvlSet(u8);
void func_800EAFC4_name_81(s32);
Process* func_800EC1E4_name_81(Vec*, Vec*, Vec*, f32);
void func_800EFABC_name_81(void*);
void func_800F57B0_name_81(s16);
void func_800F5E2C_name_81(u32);
void func_800F74E4_name_81(s32);
void func_800F75EC_name_81(s32);
void func_800F8358_name_81(s32);
void func_800F8D9C_name_81(s32, s32*, s32*);
void func_800F8EB8_name_81(u32 partnerID, s32 arg1, s32* damageAmount, s32* arg3, s32 arg4);
void func_800FAB1C_name_81(void);
void func_800FAC4C_name_81(void);
void func_800FAEE8_name_81(void);
void func_800FAFAC_name_81(void);
void func_800FC888_name_81(s32);
void func_800FC8C4_name_81(Vec*);
Vec* func_800FC8D0_name_81(void);
void func_800FFAE0_name_81(s16, s16);
void func_800EB49C_name_81(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_800D85A8_name_81(f32);
void func_800D87DC_name_81(f32);
void func_800EF3EC_name_81(s32);
