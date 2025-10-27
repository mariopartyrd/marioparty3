#include "common.h"
#include "mallocblock.h"

typedef struct RGB2 {
    s32 r;
    s32 g;
    s32 b;
} RGB2;

void MBHelpWinKill(Unk3*);
void* func_800E210C_F5D2C_shared_board(s32, s32, s32);
void func_8010067C_11429C_shared_board(s32);
s32 func_800E9AE0_FD700_shared_board(void);
void func_800ED91C_10153C_shared_board(s32, s32, s32);
void func_80105EA8_31BA18_ChillyWaters(void);
f32 MBVecAngleGet(Vec*);
void MBComItemDecideHookSet(void*);
void MBItemHookSet(s32, void*);
void func_800EA660_FE280_shared_board(f32);
void func_800EA6E0_FE300_shared_board(s32, s16);
void MBMasuBlockTblExtSet(void*);
void MBMasuBlockTblSet(void*);
void func_800EBDAC_FF9CC_shared_board(void);
void MBObjectSetup(s32 arg0, s16 arg1, s32 arg2, s32 unused);
void func_80105FB0_31BB20_ChillyWaters(void);
void func_8010603C_31BBAC_ChillyWaters(void);
void func_80108250_31DDC0_ChillyWaters(void);
void func_8010841C_31DF8C_ChillyWaters(void);
void func_801086E0_31E250_ChillyWaters(void);
void func_801088B4_31E424_ChillyWaters(void);
void func_80108B24_31E694_ChillyWaters(void);
void func_80108BA4_31E714_ChillyWaters(void);
void func_80116AA0_32C610_ChillyWaters(void);
void func_80118B7C_32E6EC_ChillyWaters(void);
void func_8010DE7C_3239EC_ChillyWaters(void);
void func_8010F2FC_324E6C_ChillyWaters(void);
void func_8010F6C4_325234_ChillyWaters(void);
void func_8010F730_3252A0_ChillyWaters(void);
void func_8010FC24_325794_ChillyWaters(void);
void func_80110194_325D04_ChillyWaters(void);
void func_801104E0_326050_ChillyWaters(void);
void func_8011093C_3264AC_ChillyWaters(void);
void func_80110BC8_326738_ChillyWaters(void);
void func_80111018_326B88_ChillyWaters(void);
void func_801112D8_326E48_ChillyWaters(void);
void func_80111678_3271E8_ChillyWaters(void);
void func_80112074_327BE4_ChillyWaters(void);
void func_80112BCC_32873C_ChillyWaters(void);
void func_801138E4_329454_ChillyWaters(void);
void func_80114B80_32A6F0_ChillyWaters(void);
void ItemUseWackyWatch(void);
void func_80116DAC_32C91C_ChillyWaters(void);
void func_80116F5C_32CACC_ChillyWaters(void);
void func_801176A4_32D214_ChillyWaters(void);
void func_801177DC_32D34C_ChillyWaters(void);
void func_80117C60_32D7D0_ChillyWaters(void);
void func_8011C88C_3323FC_ChillyWaters(void);
void func_800EBA60_FF680_shared_board(void*);
void func_800F8D48_10C968_shared_board(void*);
void func_800F8D6C_10C98C_shared_board(s32);
void MBStart(s32);
void func_80107CC4_31D834_ChillyWaters(void);
void func_8011A8D8_330448_ChillyWaters(void);
void func_80108478_31DFE8_ChillyWaters(void);
void func_80108574_31E0E4_ChillyWaters(s16);
void func_80116484_32BFF4_ChillyWaters(void*, void*, void*);
void func_800ED998_1015B8_shared_board(s32, s32, s32);
void func_801155C4_32B134_ChillyWaters(omObjData*);
void func_80115734_32B2A4_ChillyWaters(omObjData*);
void func_801158FC_32B46C_ChillyWaters(omObjData*);
void func_8011548C_32AFFC_ChillyWaters(s32, s32, f32*);

extern RGB D_8011E4B8_334028_ChillyWaters[2];
extern s32 D_8011FB80_3356F0_ChillyWaters[4];
extern void* D_8011FB90_335700_ChillyWaters;
extern s16 D_8011FB8E_3356FE_ChillyWaters;

//size based on func_80107CC4_31D834_ChillyWaters (calls to MBItemHookSet)
//not really sure what to call this, it includes the boo event at index 0 for instance
extern void (*MBItemSubFunctions[22])(void);


extern char D_8011D77C_3332EC_ChillyWaters[];
extern char D_8011DB5C_3336CC_ChillyWaters[];
extern char D_8011DB70_3336E0_ChillyWaters[];
extern char D_8011D578_3330E8_ChillyWaters[]; //ai
extern char D_8011DA84_3335F4_ChillyWaters[]; //spaces
extern char D_8011DA98_333608_ChillyWaters[]; //chain
extern s32 D_8011FB10_335680_ChillyWaters;
extern s32 D_8011FB18_335688_ChillyWaters[10];
extern s16 D_800CE194_CED94[];
extern char D_8011E2CC_333E3C_ChillyWaters[]; //unknown type
extern char D_8011E344_333EB4_ChillyWaters[]; //unknown type
extern char D_8011E4D8_334048_ChillyWaters[]; //unknown type
extern char D_8011E718_334288_ChillyWaters[]; //unknown type
extern s16 D_8011D2C0_332E30_ChillyWaters[8];
extern s32 D_8011D31C_332E8C_ChillyWaters; //unknown type
extern s32 D_8011D320_332E90_ChillyWaters; //unknown type
extern s16 D_8011D2A0_332E10_ChillyWaters[8];
extern s16 D_8011D2B0_332E20_ChillyWaters[8];
extern Unk3* D_8011FAC0_335630_ChillyWaters;           // used with direction arrows
extern Unk3* D_8011FAC4_335634_ChillyWaters;           // used with direction arrows
extern Unk3* D_8011FAC8_335638_ChillyWaters;           // used with direction arrows
extern Unk3* D_8011FACC_33563C_ChillyWaters;           // used with direction arrows
extern Unk3* D_8011FAD0_335640_ChillyWaters;           // used with direction arrows