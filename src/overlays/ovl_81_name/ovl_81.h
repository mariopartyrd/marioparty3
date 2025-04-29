#include "common.h"
#include "game/object.h"
#include "malloc.h"

#define POWERUP_NONE 1
#define POWERUP_ACTIVE 2

#define PARTNER_FRONT 0
#define PARTNER_BACK 1

typedef struct DuelPartnerInitialStats {
    u8 unk_00;
    u8 hp;
    s8 power;
    s8 cost;
    char unk_04[0x10];
} DuelPartnerInitialStats; //sizeof 0x14

extern DuelPartnerInitialStats PartnersBaseStats[];
extern Object* Duel_PartnerObjects[][2];
extern s32 D_80101A8C_E985C_name_81;
extern s32 D_80101A90_E9860_name_81;
extern s32 D_80101A94_E9864_name_81;
extern s32 D_80101A98_E9868_name_81;
extern s16 D_80105494_ED264_name_81;
extern s16 D_80105496_ED266_name_81;

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
