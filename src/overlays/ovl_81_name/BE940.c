#include "common.h"
#include "ovl_81.h"

#define POWERUP_NONE 1
#define POWERUP_ACTIVE 2

typedef struct DuelPartnerInitialStats {
    u8 unk_00;
    u8 hp;
    s8 power;
    s8 cost;
    char unk_04[0x10];
} DuelPartnerInitialStats; //sizeof 0x14

extern DuelPartnerInitialStats PartnersBaseStats[];
extern Object* D_80105450_ED220_name_81[][2];

GW_PLAYER* DuelGetPlayerStruct(s32 player);
Object* func_800F8960_E0730_name_81(s32 arg0, s32 arg1);
void func_800ECF1C_D4CEC_name_81(s32, Vec*, Vec*);
void HuVecAdd(Vec* out, Vec* a, Vec* b);
void func_800D7828_BF5F8_name_81(Vec*);
void func_800D7934_BF704_name_81(Vec*, f32);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D6B70_BE940_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D6C3C_BEA0C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D6C6C_BEA3C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D6CA0_BEA70_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D6D2C_BEAFC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D6E00_BEBD0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D6EC8_BEC98_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D6EE0_BECB0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7250_BF020_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7280_BF050_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D742C_BF1FC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7518_BF2E8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7568_BF338_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D75E8_BF3B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D76A0_BF470_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D76D0_BF4A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7828_BF5F8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7898_BF668_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7934_BF704_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D79D0_BF7A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7A6C_BF83C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7CEC_BFABC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7D70_BFB40_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7DA0_BFB70_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7DC8_BFB98_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7E14_BFBE4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7E68_BFC38_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7EB8_BFC88_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7F0C_BFCDC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D7F4C_BFD1C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D8010_BFDE0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D8314_C00E4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D85A8_C0378_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D85B4_C0384_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D87DC_C05AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D87E8_C05B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D8944_C0714_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D898C_C075C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D8B18_C08E8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D8E34_C0C04_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D8E88_C0C58_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D8EB8_C0C88_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D8F0C_C0CDC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D8F3C_C0D0C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D9098_C0E68_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D90D0_C0EA0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D918C_C0F5C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D9234_C1004_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D92A8_C1078_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D92F8_C10C8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D9384_C1154_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D94C4_C1294_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D9668_C1438_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D96F4_C14C4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D974C_C151C_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80101C48_E9A18_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80101C4C_E9A1C_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80101C50_E9A20_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80101C54_E9A24_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D97B0_C1580_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D9DD0_C1BA0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D9E50_C1C20_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D9EFC_C1CCC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D9F5C_C1D2C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D9F78_C1D48_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D9F90_C1D60_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DA00C_C1DDC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DA460_C2230_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DA85C_C262C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DAAB0_C2880_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DAB1C_C28EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DABE0_C29B0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DADA0_C2B70_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DB148_C2F18_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DB38C_C315C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DB3E0_C31B0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DB4DC_C32AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DB544_C3314_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DB58C_C335C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DB5AC_C337C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DB600_C33D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DB624_C33F4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DB648_C3418_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DBAB0_C3880_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DBD88_C3B58_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DBEB0_C3C80_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DBEF0_C3CC0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DBFF8_C3DC8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC018_C3DE8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC044_C3E14_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC07C_C3E4C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC0B4_C3E84_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC0EC_C3EBC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC324_C40F4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC384_C4154_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC390_C4160_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC3A0_C4170_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC3AC_C417C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC410_C41E0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC4B4_C4284_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC4C0_C4290_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC4E4_C42B4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC5CC_C439C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC660_C4430_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC700_C44D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC7A0_C4570_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC7CC_C459C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DC800_C45D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DCA64_C4834_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DCB04_C48D4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DCBA8_C4978_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DCC8C_C4A5C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DCE10_C4BE0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DCE40_C4C10_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DCE6C_C4C3C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD1E0_C4FB0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD2BC_C508C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD2DC_C50AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD30C_C50DC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD3B4_C5184_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD41C_C51EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD518_C52E8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD554_C5324_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD564_C5334_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD570_C5340_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD59C_C536C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD5CC_C539C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD75C_C552C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD9A0_C5770_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102300_EA0D0_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102348_EA118_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DD9EC_C57BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DE4D0_C62A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DF154_C6F24_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DF1B0_C6F80_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DF210_C6FE0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DF348_C7118_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DF49C_C726C_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_801023C8_EA198_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_801023D8_EA1A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DF594_C7364_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800DFBF4_C79C4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E02B4_C8084_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E0300_C80D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E0310_C80E0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E03F0_C81C0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E0888_C8658_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E08D8_C86A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E0924_C86F4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E0950_C8720_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E0CEC_C8ABC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E0D64_C8B34_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E0E38_C8C08_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E0E70_C8C40_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E14B0_C9280_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E14D8_C92A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E1504_C92D4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E1560_C9330_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E1694_C9464_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E16C4_C9494_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E172C_C94FC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E1824_C95F4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E1854_C9624_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E18C0_C9690_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E18D8_C96A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E18E8_C96B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E1960_C9730_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E1A24_C97F4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E1F38_C9D08_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E1F88_C9D58_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E1F94_C9D64_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E1FB8_C9D88_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E209C_C9E6C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E24AC_CA27C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E2550_CA320_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E27D4_CA5A4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E2870_CA640_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E28B0_CA680_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E2978_CA748_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E2AD0_CA8A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E2F84_CAD54_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E2F94_CAD64_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E31A0_CAF70_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E3400_CB1D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E35C4_CB394_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E35D4_CB3A4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E363C_CB40C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E3858_CB628_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E3868_CB638_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E38B0_CB680_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E39AC_CB77C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E3A0C_CB7DC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E3C6C_CBA3C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E415C_CBF2C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E4188_CBF58_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E47B8_CC588_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E4914_CC6E4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E4A74_CC844_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E4AD0_CC8A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E4B38_CC908_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E4B64_CC934_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E4E64_CCC34_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E4EAC_CCC7C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E4F50_CCD20_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E4FF4_CCDC4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5000_CCDD0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5040_CCE10_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E52DC_CD0AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E52F8_CD0C8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5360_CD130_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5374_CD144_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E53B0_CD180_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E53E8_CD1B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5424_CD1F4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E545C_CD22C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E55E4_CD3B4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5618_CD3E8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5690_CD460_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5784_CD554_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5860_CD630_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5954_CD724_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5964_CD734_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5974_CD744_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E59B0_CD780_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5A00_CD7D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5AC8_CD898_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5B3C_CD90C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5B80_CD950_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5BE8_CD9B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5C20_CD9F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5C58_CDA28_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5C70_CDA40_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5C94_CDA64_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5CC4_CDA94_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5CEC_CDABC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5D18_CDAE8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5DD8_CDBA8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E5FB0_CDD80_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E77D8_CF5A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E7C04_CF9D4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E7C10_CF9E0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E7C1C_CF9EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E7D18_CFAE8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E7D90_CFB60_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E7E80_CFC50_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E7EF8_CFCC8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8110_CFEE0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8164_CFF34_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8180_CFF50_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8194_CFF64_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E856C_D033C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8578_D0348_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8584_D0354_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8648_D0418_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E86B8_D0488_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8704_D04D4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E875C_D052C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8870_D0640_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E887C_D064C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E88B0_D0680_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E88E4_D06B4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E88F0_D06C0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E88FC_D06CC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E890C_D06DC_name_81);

void func_800E89CC_D079C_name_81(void) {
    func_800E4F50_CCD20_name_81(hvq_data_ROM_START);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E89EC_D07BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8A1C_D07EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8A44_D0814_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8AB0_D0880_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8D10_D0AE0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8D54_D0B24_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E8EE8_D0CB8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9030_D0E00_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E90B4_D0E84_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E90F4_D0EC4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9108_D0ED8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E911C_D0EEC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9158_D0F28_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9180_D0F50_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9190_D0F60_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E919C_D0F6C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9200_D0FD0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9230_D1000_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E924C_D101C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E93C0_D1190_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9468_D1238_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E94D0_D12A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9524_D12F4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9530_D1300_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9564_D1334_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9580_D1350_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E95B0_D1380_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E95C4_D1394_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9B00_D18D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9B10_D18E0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9D9C_D1B6C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9E60_D1C30_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9E84_D1C54_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9EB0_D1C80_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9ECC_D1C9C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800E9F4C_D1D1C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA010_D1DE0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA0C0_D1E90_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA1FC_D1FCC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA22C_D1FFC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA2C8_D2098_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA388_D2158_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA3CC_D219C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA46C_D223C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA4D4_D22A4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA68C_D245C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA698_D2468_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA6A4_D2474_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA6B0_D2480_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA708_D24D8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA760_D2530_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA788_D2558_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA7D4_D25A4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA848_D2618_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA898_D2668_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA8DC_D26AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA940_D2710_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EA97C_D274C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EAA7C_D284C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EAAF8_D28C8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EAB20_D28F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EAB6C_D293C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EABBC_D298C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EAD08_D2AD8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EADBC_D2B8C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EAF70_D2D40_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EAF94_D2D64_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EAFC4_D2D94_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB094_D2E64_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB140_D2F10_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB164_D2F34_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB19C_D2F6C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB1D8_D2FA8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB258_D3028_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB278_D3048_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB29C_D306C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB2BC_D308C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB49C_D326C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB4DC_D32AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB530_D3300_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB58C_D335C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB5E8_D33B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB658_D3428_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB664_D3434_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB680_D3450_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB6C4_D3494_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB708_D34D8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB740_D3510_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB780_D3550_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB7BC_D358C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB7D8_D35A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB804_D35D4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB8B0_D3680_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB984_D3754_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EB9D4_D37A4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EBA1C_D37EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EBA50_D3820_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EBAD4_D38A4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EBB00_D38D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EBC60_D3A30_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EBD1C_D3AEC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EBDDC_D3BAC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EBE60_D3C30_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EBF2C_D3CFC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EBFE0_D3DB0_name_81);

void func_800EC114_D3EE4_name_81(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EC11C_D3EEC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EC1E4_D3FB4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EC298_D4068_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EC36C_D413C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EC420_D41F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EC548_D4318_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EC6F4_D44C4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EC91C_D46EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EC99C_D476C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ECBB4_D4984_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ECC34_D4A04_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ECD0C_D4ADC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ECD88_D4B58_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ECDE8_D4BB8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ECE10_D4BE0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ECE38_D4C08_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ECF1C_D4CEC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ED118_D4EE8_name_81);

void func_800ED214_D4FE4_name_81(s32 playerIndex) {
    Vec sp10;
    Vec sp20;
    GW_PLAYER* player;
    Object* temp_v0;

    player = DuelGetPlayerStruct(playerIndex);
    func_800ECF1C_D4CEC_name_81(playerIndex, &sp10, &sp20);
    if (player->stats.partners.frontID != PARTNER_NONE) {
        temp_v0 = func_800F8960_E0730_name_81(playerIndex, 0);
        HuVecCopy3F(&temp_v0->coords, &player->player_obj->coords);
        HuVecAdd(&temp_v0->coords, &temp_v0->coords, &sp10);
        func_800D7828_BF5F8_name_81(&sp10);
        HuVecCopy3F(&temp_v0->unk18, &sp10);
    }
    if (player->stats.partners.backID != PARTNER_NONE) {
        temp_v0 = func_800F8960_E0730_name_81(playerIndex, 1);
        HuVecCopy3F(&temp_v0->coords, &player->player_obj->coords);
        HuVecAdd(&temp_v0->coords, &temp_v0->coords, &sp20);
        func_800D7828_BF5F8_name_81(&sp20);
        func_800D7934_BF704_name_81(&sp20, 180.0f);
        HuVecCopy3F(&temp_v0->unk18, &sp20);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ED31C_D50EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ED4AC_D527C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ED520_D52F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ED68C_D545C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ED70C_D54DC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ED788_D5558_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ED7EC_D55BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800ED9C4_D5794_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EDA38_D5808_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EDBEC_D59BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EDC6C_D5A3C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EDCE8_D5AB8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EDD50_D5B20_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EDDBC_D5B8C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EDE1C_D5BEC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EDEC4_D5C94_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EDF48_D5D18_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EDF78_D5D48_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EDFAC_D5D7C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EE0D0_D5EA0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EE0F4_D5EC4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EE114_D5EE4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EE40C_D61DC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EE468_D6238_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102450_EA220_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102458_EA228_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102468_EA238_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102478_EA248_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102484_EA254_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102494_EA264_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_801024A0_EA270_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_801024D0_EA2A0_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102500_EA2D0_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102520_EA2F0_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102540_EA310_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EE74C_D651C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EEC40_D6A10_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EED24_D6AF4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EED30_D6B00_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EED50_D6B20_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EED5C_D6B2C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EED68_D6B38_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EED84_D6B54_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EEDA0_D6B70_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF0A0_D6E70_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF0BC_D6E8C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF0D8_D6EA8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF3B4_D7184_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF3D0_D71A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF3EC_D71BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF3F8_D71C8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF754_D7524_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF7C8_D7598_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF7D4_D75A4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF800_D75D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF840_D7610_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF880_D7650_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF8EC_D76BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EF9C4_D7794_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EFA8C_D785C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EFABC_D788C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EFB00_D78D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EFB3C_D790C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EFBE8_D79B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EFC28_D79F8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EFD24_D7AF4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EFE20_D7BF0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EFE8C_D7C5C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EFEAC_D7C7C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EFEC8_D7C98_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800EFFBC_D7D8C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F001C_D7DEC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F008C_D7E5C_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102580_EA350_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F0208_D7FD8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F0378_D8148_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F03C8_D8198_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F03F0_D81C0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F0480_D8250_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F04FC_D82CC_name_81);

void func_800F05AC_D837C_name_81(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F05B4_D8384_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F061C_D83EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F06A8_D8478_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F06D4_D84A4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F0700_D84D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F0708_D84D8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F08BC_D868C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F0C30_D8A00_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F0C4C_D8A1C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F0D1C_D8AEC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F0DF8_D8BC8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F0E4C_D8C1C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F0EA8_D8C78_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F0FE8_D8DB8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F1340_D9110_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F13C0_D9190_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F140C_D91DC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F14A8_D9278_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F159C_D936C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F1784_D9554_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F2090_D9E60_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F21CC_D9F9C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F2238_DA008_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F22E8_DA0B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F23FC_DA1CC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F2408_DA1D8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F24DC_DA2AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F2618_DA3E8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F32CC_DB09C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F336C_DB13C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3500_DB2D0_name_81);

s16 DuelGetCurrentPlayerIndex(void){
    return GwSystem.current_player_index;
}

GW_PLAYER* DuelGetPlayerStruct(s32 player) {
    if (player < 0) {
        player = DuelGetCurrentPlayerIndex();
    }
    return &GwPlayer[player];
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F379C_DB56C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F37B8_DB588_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F37E0_DB5B0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3850_DB620_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3880_DB650_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F38DC_DB6AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F397C_DB74C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3A04_DB7D4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3AF4_DB8C4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3B54_DB924_name_81);

void func_800F3B8C_DB95C_name_81(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3B94_DB964_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3C28_DB9F8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3C98_DBA68_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3D50_DBB20_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3D74_DBB44_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3DC0_DBB90_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3DFC_DBBCC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3E58_DBC28_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3E88_DBC58_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3EC0_DBC90_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3F18_DBCE8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F3F4C_DBD1C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F4030_DBE00_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F4080_DBE50_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F40E4_DBEB4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F413C_DBF0C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F41DC_DBFAC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F4208_DBFD8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F429C_DC06C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F42C8_DC098_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F4300_DC0D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F4314_DC0E4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F4354_DC124_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F4528_DC2F8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F4584_DC354_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F466C_DC43C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F46BC_DC48C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F4710_DC4E0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F4E90_DCC60_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F4F20_DCCF0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F52B8_DD088_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F53C4_DD194_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F54A4_DD274_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F55FC_DD3CC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F56C0_DD490_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F57B0_DD580_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F5834_DD604_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F5BB4_DD984_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F5E2C_DDBFC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F5EB0_DDC80_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F6110_DDEE0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F6220_DDFF0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F628C_DE05C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F6390_DE160_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F6408_DE1D8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F64FC_DE2CC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F6550_DE320_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F6600_DE3D0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F664C_DE41C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F6688_DE458_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F66BC_DE48C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F6CA0_DEA70_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F6CEC_DEABC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F6E3C_DEC0C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F6F84_DED54_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F6FE8_DEDB8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F7228_DEFF8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F7378_DF148_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F7394_DF164_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F73AC_DF17C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F73C0_DF190_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F740C_DF1DC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F7458_DF228_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F74E4_DF2B4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F75EC_DF3BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F76F8_DF4C8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F79D0_DF7A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F79DC_DF7AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F79E8_DF7B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F7BB4_DF984_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F7D94_DFB64_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F7F90_DFD60_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F7FDC_DFDAC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F8034_DFE04_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F8050_DFE20_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F8108_DFED8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F821C_DFFEC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F82EC_E00BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F8358_E0128_name_81);

void func_800F8418_E01E8_name_81(s32 arg0, s32 partnerID, s32 arg2) {
    GW_PLAYER* player;

    player = DuelGetPlayerStruct(arg0);
    switch (arg2) {
        case 0:
        player->stats.partners.frontID = partnerID;
        player->stats.partners.frontPoweredUp = POWERUP_NONE;
        player->stats.partners.frontHp = PartnersBaseStats[partnerID].hp;
        player->stats.partners.frontCost = PartnersBaseStats[partnerID].cost;
        player->stats.partners.frontPower = PartnersBaseStats[partnerID].power;
        break;
    case 1:
        player->stats.partners.backID = partnerID;
        player->stats.partners.backPoweredUp = POWERUP_NONE;
        player->stats.partners.backHp = PartnersBaseStats[partnerID].hp;
        player->stats.partners.backCost = PartnersBaseStats[partnerID].cost;
        player->stats.partners.backPower = PartnersBaseStats[partnerID].power;
        break;
    }
    if (player->stats.partners.frontID != PARTNER_NONE) {
        player->stats.partners.frontPower = PartnersBaseStats[player->stats.partners.frontID].power;
        player->stats.partners.frontCost = PartnersBaseStats[player->stats.partners.frontID].cost;
    }
    if (player->stats.partners.backID != PARTNER_NONE) {
        player->stats.partners.backPower = PartnersBaseStats[player->stats.partners.backID].power;
        player->stats.partners.backCost = PartnersBaseStats[player->stats.partners.backID].cost;
    }
    if (arg0 == 0) {
        GWBoardFlagClear(0x12);
    } else {
        GWBoardFlagClear(0x13);
    }
}

void func_800F85A4_E0374_name_81(s32 arg0, s32 frontOrBackBool) {
    GW_PLAYER* player = DuelGetPlayerStruct(arg0);

    switch (frontOrBackBool) {
    case 0:
        player->stats.partners.frontID = PARTNER_NONE;
        player->stats.partners.frontPoweredUp = 0;
        player->stats.partners.frontHp = 0;
        player->stats.partners.frontCost = 0;
        player->stats.partners.frontPower = 0;
        break;
    case 1:
        player->stats.partners.backID = PARTNER_NONE;
        player->stats.partners.backPoweredUp = 0;
        player->stats.partners.backHp = 0;
        player->stats.partners.backCost = 0;
        player->stats.partners.backPower = 0;
        break;
    }

    if (player->stats.partners.frontID != PARTNER_NONE) {
        player->stats.partners.frontPower = PartnersBaseStats[player->stats.partners.frontID].power * player->stats.partners.frontPoweredUp;
        player->stats.partners.frontCost = PartnersBaseStats[player->stats.partners.frontID].cost * player->stats.partners.frontPoweredUp;
    }
    if (player->stats.partners.backID != PARTNER_NONE) {
        player->stats.partners.backPower = PartnersBaseStats[player->stats.partners.backID].power * player->stats.partners.backPoweredUp;
        player->stats.partners.backCost = PartnersBaseStats[player->stats.partners.backID].cost * player->stats.partners.backPoweredUp;
    }
    if (arg0 == 0) {
        GWBoardFlagClear(0x12);
    } else {
        GWBoardFlagClear(0x13);
    }
}

void func_800F86F8_E04C8_name_81(s32 arg0) {
    GW_PLAYER* temp_v0 = DuelGetPlayerStruct(arg0);
    s32 frontID = temp_v0->stats.partners.frontID;
    s32 frontHP = temp_v0->stats.partners.frontHp;
    s32 frontPoweredUp = temp_v0->stats.partners.frontPoweredUp;
    s32 frontCost = temp_v0->stats.partners.frontCost;
    s32 frontPower = temp_v0->stats.partners.frontPower;
    Object* temp;

    temp_v0->stats.partners.frontID = temp_v0->stats.partners.backID;
    temp_v0->stats.partners.frontHp = temp_v0->stats.partners.backHp;
    temp_v0->stats.partners.frontPoweredUp = temp_v0->stats.partners.backPoweredUp;
    temp_v0->stats.partners.frontCost = temp_v0->stats.partners.backCost;
    temp_v0->stats.partners.frontPower = temp_v0->stats.partners.backPower;
    temp_v0->stats.partners.backID = frontID;
    temp_v0->stats.partners.backHp = frontHP;
    temp_v0->stats.partners.backPoweredUp = frontPoweredUp;
    temp_v0->stats.partners.backCost = frontCost;
    temp_v0->stats.partners.backPower = frontPower;

    temp = D_80105450_ED220_name_81[arg0][0];
    D_80105450_ED220_name_81[arg0][0] = D_80105450_ED220_name_81[arg0][1];
    D_80105450_ED220_name_81[arg0][1] = temp;

    func_800ED214_D4FE4_name_81(arg0);
    func_800F5BB4_DD984_name_81(arg0);
    func_800F5EB0_DDC80_name_81(arg0);
}

void Duel_PowerUpPartners(s32 playerIndex) {
    GW_PLAYER* player = DuelGetPlayerStruct(playerIndex);

    if ((player->stats.partners.frontID != PARTNER_NONE)
        && (player->stats.partners.frontPoweredUp == POWERUP_NONE)) {
        player->stats.partners.frontPoweredUp = 2;
        player->stats.partners.frontHp *= 2;
        player->stats.partners.frontCost *= 2;
        player->stats.partners.frontPower *= 2;
    }
    if ((player->stats.partners.backID != PARTNER_NONE) &&
        (player->stats.partners.backPoweredUp == POWERUP_NONE)) {
        player->stats.partners.backPoweredUp = 2;
        player->stats.partners.backHp *= 2;
        player->stats.partners.backCost *= 2;
        player->stats.partners.backPower *= 2;
    }
}

void Duel_PowerDownPartners(s32 playerIndex) {
    GW_PLAYER* player = DuelGetPlayerStruct(playerIndex);
    
    if ((player->stats.partners.frontID != PARTNER_NONE) && (player->stats.partners.frontPoweredUp == POWERUP_ACTIVE)) {
        player->stats.partners.frontPoweredUp = 1;
        player->stats.partners.frontHp = (player->stats.partners.frontHp + 1) / 2;
        player->stats.partners.frontCost = player->stats.partners.frontCost / 2;
        player->stats.partners.frontPower = player->stats.partners.frontPower / 2;
    }
    if ((player->stats.partners.backID != PARTNER_NONE) && (player->stats.partners.backPoweredUp == POWERUP_ACTIVE)) {
        player->stats.partners.backPoweredUp = POWERUP_NONE;
        player->stats.partners.backHp = (player->stats.partners.backHp + 1) / 2;
        player->stats.partners.backCost = player->stats.partners.backCost / 2;
        player->stats.partners.backPower = player->stats.partners.backPower / 2;
    }
}

Object* func_800F8960_E0730_name_81(s32 arg0, s32 arg1) {
    return D_80105450_ED220_name_81[arg0][arg1];
}

s32 func_800F8980_E0750_name_81(s32 playerIndex) {
    GW_PLAYER* player = DuelGetPlayerStruct(playerIndex);
    s32 totalPartnerCost = 0;
    
    if (player->stats.partners.frontID != PARTNER_NONE) {
        totalPartnerCost = player->stats.partners.frontCost;
    }
    if (player->stats.partners.backID != PARTNER_NONE) {
        totalPartnerCost += player->stats.partners.backCost;
    }
    return totalPartnerCost;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F89D0_E07A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F8AEC_E08BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F8C68_E0A38_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F8CD8_E0AA8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F8D9C_E0B6C_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_801026B8_EA488_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_801026E8_EA4B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F8EB8_E0C88_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F90BC_E0E8C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800F924C_E101C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FA120_E1EF0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FAB1C_E28EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FAB68_E2938_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FAC1C_E29EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FAC4C_E2A1C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FAC94_E2A64_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FAD04_E2AD4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FADB4_E2B84_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FAE18_E2BE8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FAE98_E2C68_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FAEE8_E2CB8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FAEFC_E2CCC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FAFAC_E2D7C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FB038_E2E08_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FB0B8_E2E88_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FB148_E2F18_name_81);

void func_800FB158_E2F28_name_81(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FB160_E2F30_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FB524_E32F4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FB59C_E336C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FBDD4_E3BA4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FBF00_E3CD0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FBFA4_E3D74_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC030_E3E00_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC108_E3ED8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC114_E3EE4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC120_E3EF0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC18C_E3F5C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC198_E3F68_name_81);

void func_800FC260_E4030_name_81(s32 arg0, s16 arg1) {
    Process* temp_v0_2;
    Object* temp_a0;
    UnkOvl81_1* temp_v0_3;
    s32 frontPartnerID;
    s32 backPartnerID;
    Object* temp_v0;
    s32 i;

    func_800E8D10_D0AE0_name_81();
    func_800E4F50_CCD20_name_81(hvq_data_ROM_START);
    if (arg0 >= 0) {
        func_800E52DC_CD0AC_name_81(arg0);
    }
    func_800E94D0_D12A0_name_81();
    if (arg1 >= 0) {
        func_800E9B10_D18E0_name_81(0x13, arg1);
    }
    func_800D7EB8_BFC88_name_81();
    func_800F3F4C_DBD1C_name_81();
    func_800F3DFC_DBBCC_name_81(0);
    func_800F3DFC_DBBCC_name_81(1);
    for (i = 0; i < 2; i++) {
        func_800D8944_C0714_name_81(DuelGetPlayerStruct(i)->player_obj);
        temp_v0 = DuelGetPlayerStruct(i)->player_obj;
        temp_v0->unkA |= 2;
        temp_a0 = DuelGetPlayerStruct(i)->player_obj;
        func_800D8E88_C0C58_name_81(temp_a0);
    }

    func_8001FDE8_209E8(DuelGetPlayerStruct(0)->player_obj->unk3C->model[0]);
    func_8001FDE8_209E8(DuelGetPlayerStruct(1)->player_obj->unk3C->model[0]);
    func_800F8C68_E0A38_name_81(0);
    func_800F8C68_E0A38_name_81(1);
    func_800F4300_DC0D0_name_81();
    func_800DF1B0_C6F80_name_81();
    func_800E0CEC_C8ABC_name_81();
    func_800E2870_CA640_name_81();
    func_800F6390_DE160_name_81();
    for (i = 0; i < 2; i++) {
        frontPartnerID = GwPlayer[i].stats.partners.frontID;
        backPartnerID = GwPlayer[i].stats.partners.backID;
        GwPlayer[i].stats.partners.frontID = PARTNER_KOOPA; //?
        GwPlayer[i].stats.partners.backID = PARTNER_KOOPA; //?
        func_800F5BB4_DD984_name_81(i);
        func_800F5EB0_DDC80_name_81(i);
        GwPlayer[i].stats.partners.frontID = frontPartnerID;
        GwPlayer[i].stats.partners.backID = backPartnerID;
        func_800F5BB4_DD984_name_81(i);
        func_800F5EB0_DDC80_name_81(i);
    }
    func_800DAB1C_C28EC_name_81();
    func_8005A6B0_5B2B0();
    func_800EB664_D3434_name_81();
    D_80105494_ED264_name_81 = -1;
    D_800D1360_D1F60.unk_20 = 0;
    D_80105496_ED266_name_81 = 0;
    func_800F4080_DBE50_name_81();
    D_80101A8C_E985C_name_81 = 0;
    D_80101A90_E9860_name_81 = 0;
    D_80101A94_E9864_name_81 = 0;
    D_80101A98_E9868_name_81 = 0;
    for (i = 0; i < 2; i++) {
        temp_v0_2 = omAddPrcObj(func_800FC198_E3F68_name_81, 0, 0, 0x40);
        temp_v0_3 = HuMemMemoryAlloc(temp_v0_2->heap, sizeof(UnkOvl81_1));
        temp_v0_2->user_data = temp_v0_3;
        temp_v0_3->unk_00 = i;
        omPrcSetStatBit(temp_v0_2, 0xA0);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC4E4_E42B4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC590_E4360_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC59C_E436C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC5A8_E4378_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC5B4_E4384_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC5C0_E4390_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC5CC_E439C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC5D8_E43A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC888_E4658_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC894_E4664_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC8A0_E4670_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC8C4_E4694_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC8D0_E46A0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC8DC_E46AC_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102758_EA528_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_80102788_EA558_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_801027B8_EA588_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_801027C8_EA598_name_81);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_81_name/BE940", D_801027EC_EA5BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC8E8_E46B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FC9FC_E47CC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FCAB4_E4884_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FCC84_E4A54_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FCCCC_E4A9C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FCD44_E4B14_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FCF50_E4D20_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FD298_E5068_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FD498_E5268_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FD4DC_E52AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FD55C_E532C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FD5F0_E53C0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FD620_E53F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FD6F4_E54C4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FF420_E71F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FF480_E7250_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FF640_E7410_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FF944_E7714_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FF970_E7740_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FF97C_E774C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FF9AC_E777C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FF9D8_E77A8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FF9E8_E77B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FFA1C_E77EC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FFA28_E77F8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FFAE0_E78B0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FFBEC_E79BC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FFC2C_E79FC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FFCCC_E7A9C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FFD10_E7AE0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800FFEEC_E7CBC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_80100070_E7E40_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_801000A4_E7E74_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_80100124_E7EF4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_801003C8_E8198_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_80100420_E81F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_801005DC_E83AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_80100604_E83D4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_801007C4_E8594_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_80100864_E8634_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_80100890_E8660_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_801008E8_E86B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_80100CA0_E8A70_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_80100CEC_E8ABC_name_81);
