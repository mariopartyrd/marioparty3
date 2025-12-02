#ifndef _GAME_WINDOW_H
#define _GAME_WINDOW_H

#include "ultra64.h"

#define WINDOWS_MAX 16

#define MAKE_MESSID(bank, mess) (((bank) << 16)+(mess))
#define MAKE_MESSID_PTR(ptr) ((u32)(ptr))

typedef struct TextWindow {
    /* 0x000 */ u8 unk_00;
    /* 0x001 */ char pad1[3];                       /* maybe part of unk_00[4]? */
    /* 0x004 */ s8 unk_04;
    /* 0x005 */ u8 unk_05;
    /* 0x006 */ char pad6[0xA];                     /* maybe part of unk_05[0xB]? */
    /* 0x010 */ u8 unk_10;
    /* 0x011 */ char pad11[7];                      /* maybe part of unk_10[8]? */
    /* 0x018 */ s16 unk_18;
    /* 0x01A */ s16 unk_1A;
    /* 0x01C */ char pad1C[4];                      /* maybe part of unk_1A[3]? */
    /* 0x020 */ s8 unk20;                           /* inferred */
    /* 0x021 */ char pad21[8];                      /* maybe part of unk20[9]? */
    /* 0x029 */ s8 unk_29;
    /* 0x02A */ s8 unk_2A;
    /* 0x02B */ char pad2B[1];
    /* 0x02C */ s16 unk_2C;
    /* 0x02E */ s16 unk_2E;
    /* 0x030 */ char pad30[4];                      /* maybe part of unk_2E[3]? */
    /* 0x034 */ s16 unk_34;
    /* 0x036 */ char pad36[6];                      /* maybe part of unk_34[4]? */
    /* 0x03C */ u16 unk3C;
    /* 0x03E */ u16 unk3E;
    /* 0x040 */ char pad40[8];                      /* maybe part of unk3E[5]? */
    /* 0x048 */ u16 unk48;
    /* 0x04A */ u16 unk4A;
    /* 0x04C */ s16 unk4C;
    /* 0x04E */ char pad4E[6];                      /* maybe part of unk4C[4]? */
    /* 0x054 */ s16 unk54;
    /* 0x056 */ char pad56[8];                      /* maybe part of unk54[5]? */
    /* 0x05E */ s16 unk5E;
    /* 0x060 */ char pad60[2];
    /* 0x062 */ s16 unk62;
    /* 0x064 */ s16 unk64;
    /* 0x066 */ char pad66[6];                      /* maybe part of unk64[4]? */
    /* 0x06C */ s16 unk_6C;
    /* 0x06E */ s16 unk_6E[0xC];
    /* 0x086 */ char pad86[0x27];                   /* maybe part of unk_6E[2]? */
    /* 0x0AD */ s8 usingStringIDBool[5];
    /* 0x0B2 */ s8 unk_B2[6];
    /* 0x0B8 */ s32 unk_B8[4];
    /* 0x0C8 */ char padC8[0x1AC];                  /* maybe part of unk_B8[0x1B]? */
    /* 0x274 */ s16 unk274;
    /* 0x276 */ s16 unk276;
    /* 0x278 */ char pad278[4];                     /* maybe part of unk276[3]? */
} TextWindow;                                       /* size = 0x27C */

void func_8005A6B0_5B2B0(void);
s16 func_8005A968_5B568(s16, s16, s16, s16, s32, s16);
void func_8005B43C_5C03C(s16, s32, s32, s32);
void func_8005B6BC_5C2BC(s16 win_id, u32 arg1, s8 arg2);
void func_8005BDFC_5C9FC(s16, s32);
void func_8005BE30_5CA30(s16, s32);
void func_8005BEE0_5CAE0(s16, s32);
void func_8005C02C_5CC2C(s16, s32);
void func_8005C060_5CC60(s16, s32, s32, s32, s32);
void func_8005D294_5DE94(s16);
void func_8005E1A8_5EDA8(s16, s16);
void func_8005F364_5FF64(s16);
void func_8005F524_60124(void);
void func_8005FBF8_607F8(s16, s32, s32, s32);
void func_8005FE90_60A90(s16);
void func_8005FFA8_60BA8(s16);
void func_8006022C_60E2C(u32 mesg, s32);
void func_80060394_60F94(s32, s16*, s32);
void func_80061388_61F88(s16);

extern TextWindow* D_800CC69C_CD29C;

#endif
