#ifndef _OVL_39_H
#define _OVL_39_H

#define SKIP_SPR_DECL
#include "common.h"

#define rand16() ((rand8() << 8) | rand8())

// EXTERN

typedef struct {
    /* 0x00 */ Gfx* unk00;
    /* 0x04 */ Gfx* unk04[3]; // unknown length
    /* 0x10 */ void* unk10;
    /* 0x14 */ void* unk14;
} HmfModelData_Unk64_Unk3C_Struct; // Size unknown

typedef struct {
    /* 0x00 */ char unk00[0x50];
    /* 0x50 */ s32 unk50;
} HmfModelData_Unk64_Unk60_Struct; // Size unknown

typedef struct {
    /* 0x00 */ char unk00[8];
    /* 0x08 */ s32 unk08;
} HmfModelData_Unk64_Unk98_Struct; // Size unknown

typedef struct {
    /* 0x00 */ char unk00[0xE];
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ char unk10[0x2C];
    /* 0x3C */ HmfModelData_Unk64_Unk3C_Struct* unk3C;
    /* 0x40 */ char unk40[4];
    /* 0x44 */ Vtx* unk44[1]; // unknown length
    /* 0x48 */ char unk48[0x18];
    /* 0x60 */ HmfModelData_Unk64_Unk60_Struct* unk60;
    /* 0x64 */ char unk64[0x34];
    /* 0x98 */ HmfModelData_Unk64_Unk98_Struct* unk98;
} HmfModelData_Unk64_Struct; // Size unknown

typedef struct {
    /* 0x00 */ char unk00[2];
    /* 0x02 */ u8 unk02;
    /* 0x03 */ char unk03[0x15];
    /* 0x18 */ s32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ f32 unk44;
    /* 0x48 */ char unk48[0x1C];
    /* 0x64 */ HmfModelData_Unk64_Struct* unk64;
    /* 0x68 */ char unk68[0xC];
    /* 0x74 */ f32 unk74[16];
    /* 0x78 */ char unkB4[0xC];
} HmfModelData_Struct; // Size 0xC0

typedef struct {
    /* 0x00 */ char unk00[2];
    /* 0x02 */ s16 unk02;
    /* 0x04 */ char unk04[0x14];
} D_800CCF58_CDB58_Struct; // Size 0x18

extern HmfModelData_Struct* HmfModelData;
extern D_800CCF58_CDB58_Struct* D_800CCF58_CDB58;

// LOCAL

typedef struct {
    /* 0x00 */ u8 unk00;
    /* 0x04 */ f32* unk04;
    /* 0x08 */ f32* unk08;
    /* 0x0C */ f32* unk0C;
} D_8010E700_2C5B70_Unk98_Struct; // Size 0x10

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s8 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ char unk0E[0x12];
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ char unk26[0x1A];
    /* 0x40 */ D_8010E700_2C5B70_Unk98_Struct* unk40;
    /* 0x44 */ D_8010E700_2C5B70_Unk98_Struct* unk44;
    /* 0x48 */ f32 unk48;
    /* 0x4C */ s16 unk4C;
    /* 0x4E */ s16 unk4E;
    /* 0x50 */ s16 unk50;
    /* 0x52 */ s16 unk52;
    /* 0x54 */ char unk54[8];
} D_8010E6E4_2C5B54_Struct; // Size 0x5C

typedef struct {
    /* 0x00 */ omObjData* unk00;
    /* 0x04 */ s16* unk04;
    /* 0x08 */ s16 unk08;
} D_8010E6F4_2C5B64_Unk00_Struct; // Size 0xC

typedef struct d_8010E6F4_2C5B64_unk04_struct {
    /* 0x00 */ s8 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s8 unk04;
    /* 0x05 */ s8 unk05;
    /* 0x06 */ char unk06[2];
    /* 0x08 */ s32 unk08;
    /* 0x0C */ s8 unk0C;
    /* 0x0D */ s8 unk0D;
    /* 0x0E */ s8 unk0E;
    /* 0x0F */ char unk0F[1];
    /* 0x10 */ s8 unk10;
    /* 0x11 */ char unk11[0xB];
    /* 0x1C */ s16 unk1C[2]; // unknown length
    /* 0x20 */ char unk20[2];
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ char unk26[6];
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ D_8010E6E4_2C5B54_Struct* unk3C;
    /* 0x40 */ void (*unk40)(D_8010E6F4_2C5B64_Unk00_Struct*, struct d_8010E6F4_2C5B64_unk04_struct*);
} D_8010E6F4_2C5B64_Unk04_Struct; // Size 0x44

typedef struct {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ char unk0A[2];
} D_8010E6F4_2C5B64_Unk0C_Struct; // Size 0xC

typedef struct {
    /* 0x00 */ D_8010E6F4_2C5B64_Unk00_Struct* unk00;
    /* 0x04 */ D_8010E6F4_2C5B64_Unk04_Struct* unk04;
    /* 0x08 */ s16 unk08;
    /* 0x0C */ D_8010E6F4_2C5B64_Unk0C_Struct* unk0C;
    /* 0x10 */ s8 unk10;
} D_8010E6F4_2C5B64_Struct; // Size 0x14

typedef struct {
    /* 0x00 */ s8 unk00;
    /* 0x01 */ u8 unk01;
    /* 0x02 */ u8 unk02;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ s16 unk06;
} D_8010E6F8_2C5B68_Struct; // Size 8

typedef struct {
    /* 0x00 */ s8 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ s8 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
} D_8010E6FC_2C5B6C_Struct; // Size 0x18

typedef struct {
    /* 0x00 */ Vec unk00[4];
} D_8010E700_2C5B70_Unk60_Struct; // Size 0x30

typedef struct {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ s8 unk04;
    /* 0x08 */ f32* unk08;
    /* 0x0C */ f32* unk0C;
    /* 0x10 */ f32* unk10;
    /* 0x14 */ f32* unk14;
    /* 0x18 */ f32* unk18;
    /* 0x1C */ f32* unk1C;
    /* 0x20 */ f32 unk20[16];
    /* 0x60 */ D_8010E700_2C5B70_Unk60_Struct unk60;
    /* 0x90 */ s16 unk90;
    /* 0x94 */ f32 unk94;
    /* 0x98 */ D_8010E700_2C5B70_Unk98_Struct* unk98;
    /* 0x9C */ s16 unk9C;
    /* 0x9E */ s16 unk9E;
} D_8010E700_2C5B70_Struct; // Size 0xA0

// 2C0E70
void func_80109A00_2C0E70_tick_tock_hop(void);
D_8010E6F4_2C5B64_Struct* func_80109A94_2C0F04_tick_tock_hop(omObjData* arg0, s8 arg1, s16 arg2, s16 arg3);
s16 func_80109BE4_2C1054_tick_tock_hop(s8 arg0, s32 arg1, D_8010E6E4_2C5B54_Struct* arg2, void (*arg3)(D_8010E6F4_2C5B64_Unk00_Struct*, D_8010E6F4_2C5B64_Unk04_Struct*), s8 arg4);
void func_80109CC0_2C1130_tick_tock_hop(s8 arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
void func_80109E2C_2C129C_tick_tock_hop(s8 arg0);
s16 func_8010A07C_2C14EC_tick_tock_hop(u16 arg0, s32 arg1, s32 arg2, u16 arg3, s32 arg4);
void func_8010A21C_2C168C_tick_tock_hop(s16 arg0, s32 arg1, s32 arg2);
void func_8010A2B0_2C1720_tick_tock_hop(s16 arg0);
void func_8010A300_2C1770_tick_tock_hop(void);
s32 func_8010A3A8_2C1818_tick_tock_hop(s32 arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4);
s32 func_8010A4A8_2C1918_tick_tock_hop(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8);
void func_8010A620_2C1A90_tick_tock_hop(void);
s32 func_8010A788_2C1BF8_tick_tock_hop(s32 arg0, s32 arg1, s32 arg2);
void func_8010A9B0_2C1E20_tick_tock_hop(s16 arg0, f32* arg1, f32* arg2, f32* arg3);
void func_8010ABCC_2C203C_tick_tock_hop(void);
void func_8010D2FC_2C476C_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
s32 func_8010D34C_2C47BC_tick_tock_hop(s16 arg0, D_8010E700_2C5B70_Unk60_Struct* arg1, f32 arg2, s16 arg3, s32 arg4);
D_8010E700_2C5B70_Unk98_Struct* func_8010D49C_2C490C_tick_tock_hop(s16 arg0, s16 arg1);
void func_8010D568_2C49D8_tick_tock_hop(s16 arg0, D_8010E700_2C5B70_Unk60_Struct* arg1, f32 arg2);
void func_8010DA80_2C4EF0_tick_tock_hop(s16* arg0, s16 arg1);
void func_8010DB8C_2C4FFC_tick_tock_hop(omObjData* arg0);
void func_8010DD00_2C5170_tick_tock_hop(Vec arg0, Vec arg1, f32* arg2);
void func_8010DE30_2C52A0_tick_tock_hop(f32* arg0, f32* arg1);

extern D_8010E6F4_2C5B64_Struct* D_8010E6F4_2C5B64_tick_tock_hop;
extern D_8010E6F8_2C5B68_Struct* D_8010E6F8_2C5B68_tick_tock_hop;
extern D_8010E6FC_2C5B6C_Struct* D_8010E6FC_2C5B6C_tick_tock_hop;
extern D_8010E700_2C5B70_Struct* D_8010E700_2C5B70_tick_tock_hop;

#endif
