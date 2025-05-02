#include "common.h"
#include "game/object.h"
#include "malloc.h"

typedef enum PartnerObjIndex {
    /* 0 */ PARTNEROBJINDEX_FRONT,
    /* 1 */ PARTNEROBJINDEX_BACK,
    /* 2 */ PARTNEROBJINDEX_MAX,
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
    /* 0x04 */ void (*func1)(s16, s32, Vec*, Vec*, s32, s32);
    /* 0x08 */ void (*func2)(s16, s32, Vec*, Vec*, s32, s32);
    /* 0x0C */ void (*func3)(void);
    /* 0x10 */ void (*func4)(void);
} PartnerBaseAttributes; //sizeof 0x14

extern PartnerBaseAttributes PartnersBaseStats[];
extern Object* Duel_PartnerObjects[][PARTNEROBJINDEX_MAX];
extern s32 D_80101A8C_E985C_name_81;
extern s32 D_80101A90_E9860_name_81;
extern s32 D_80101A94_E9864_name_81;
extern s32 D_80101A98_E9868_name_81;
extern s16 D_80105494_ED264_name_81;
extern s16 D_80105496_ED266_name_81;
extern s32 D_80101980_E9750_name_81;
extern s32 D_80101984_E9754_name_81;
extern Object* D_80101988_E9758_name_81;
extern s32* D_801017DC_E95AC_name_81[];
extern s32 D_8010195C_E972C_name_81;

void func_800D8F0C_C0CDC_name_81(Object*);
GW_PLAYER* Duel_GetPlayerStruct(s32 playerIndex);
Object* Duel_GetPlayerPartnerRef(s32 playerIndex, s32 frontOrBackIndex);
void func_800ECF1C_D4CEC_name_81(s32, Vec*, Vec*);
void HuVecAdd(Vec* out, Vec* a, Vec* b);
void func_800D7828_BF5F8_name_81(Vec*);
void func_800D7934_BF704_name_81(Vec*, f32);
void func_800D7EB8_BFC88_name_81(void);
void func_800D8944_C0714_name_81(Object*);
void func_800D8E88_C0C58_name_81(Object*);
void func_800DAB1C_C28EC_name_81(void);
void func_800DF1B0_C6F80_name_81(void);
void func_800E0CEC_C8ABC_name_81(void);
void func_800E2870_CA640_name_81(void);
void func_800E4F50_CCD20_name_81(Addr);
void func_800E52DC_CD0AC_name_81(s32);
void func_800E8D10_D0AE0_name_81(void);
void func_800E94D0_D12A0_name_81(void);
void func_800E9B10_D18E0_name_81(s32, s16);
void func_800EB664_D3434_name_81(void);
void func_800F3DFC_DBBCC_name_81(s32);
void func_800F3F4C_DBD1C_name_81(void);
void func_800F4080_DBE50_name_81(void);
void func_800F4300_DC0D0_name_81(void);
void func_800F5BB4_DD984_name_81(s32 playerIndex);
void func_800F5EB0_DDC80_name_81(s32);
void func_800F6390_DE160_name_81(void);
void func_800F8C68_E0A38_name_81(s32);
void func_800FC198_E3F68_name_81(omObjData*);
void func_800E8180_CFF50_name_81(f32, f32);
void func_800E4F50_CCD20_name_81(Addr); 
void func_800E52DC_CD0AC_name_81(s32);
void func_800E8110_CFEE0_name_81(void);
void func_800E8180_CFF50_name_81(f32, f32);
void func_800ED214_D4FE4_name_81(s32 playerIndex);
void func_800F82EC_E00BC_name_81(s32);
void func_8001F9E4_205E4(s16, u8);
void func_8001FA68_20668(s16);
Object* func_800D8010_BFDE0_name_81(u8, s32*);
Object* func_800F8034_DFE04_name_81(s32);
Object* func_800F8050_DFE20_name_81(s32);
void func_800F8108_DFED8_name_81(s32 playerIndex);
void func_800D8F3C_C0D0C_name_81(Object*);
void func_800F85A4_E0374_name_81(s32 playerIndex, s32 frontOrBackIndex);
void func_800D90D0_C0EA0_name_81(Object*, s16, u16);
s16 Duel_GetCurrentPlayerIndex(void);
void func_800D918C_C0F5C_name_81(Object*, s16, s16, s16, s32);
s32 func_800EFE20_D7BF0_name_81(f32);
void func_800FB160_E2F30_name_81(void);
void func_800D90D0_C0EA0_name_81(Object*, s16, u16);
void func_800FAEFC_E2CCC_name_81(s32);
void func_800FB038_E2E08_name_81(Object*, s16, u16);
extern s16 D_80101992_E9762_name_81;
extern s8* D_80101968_E9738_name_81;
extern s8* D_8010196C_E973C_name_81;
extern s8* D_80101970_E9740_name_81;
extern s8* D_80101974_E9744_name_81;
extern s8* D_80101978_E9748_name_81;
extern s8* D_8010197C_E974C_name_81;
extern Vec D_80105540_ED310_name_81;
extern s32 D_8010554C_ED31C_name_81;
extern s32 D_80105550_ED320_name_81;
extern s32 D_80105558_ED328_name_81;
extern s32 D_80105620_ED3F0_name_81;
extern s32 D_8010570C_ED4DC_name_81;
extern s32 D_80105718_ED4E8_name_81;
extern s32 D_8010571C_ED4EC_name_81;
