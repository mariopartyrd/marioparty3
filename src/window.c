#include "common.h"
#include "malloc.h"

#define WINDOWS_MAX 16

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
    /* 0x01C */ char pad1C[0x10];                   /* maybe part of unk_1A[9]? */
    /* 0x02C */ s16 unk_2C;
    /* 0x02E */ s16 unk_2E;
    /* 0x030 */ char pad30[4];                      /* maybe part of unk_2E[3]? */
    /* 0x034 */ s16 unk_34;
    /* 0x036 */ char pad36[6];                      /* maybe part of unk_34[4]? */
    /* 0x03C */ u16 unk3C;                          /* inferred */
    /* 0x03E */ u16 unk3E;                          /* inferred */
    /* 0x040 */ char pad40[8];                      /* maybe part of unk3E[5]? */
    /* 0x048 */ u16 unk48;                          /* inferred */
    /* 0x04A */ u16 unk4A;                          /* inferred */
    /* 0x04C */ s16 unk4C;                          /* inferred */
    /* 0x04E */ char pad4E[6];                      /* maybe part of unk4C[4]? */
    /* 0x054 */ s16 unk54;                          /* inferred */
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
    /* 0x274 */ s16 unk274;                         /* inferred */
    /* 0x276 */ s16 unk276;                         /* inferred */
    /* 0x278 */ char pad278[4];                     /* maybe part of unk276[3]? */
} TextWindow;                                       /* size = 0x27C */

extern TextWindow* D_800CC69C_CD29C;
extern u8 D_800A2150_A2D50;
extern u8 gLanguageIndex;
extern s16 D_800BDA50_BE650[12];
extern s16 D_800BDA68_BE668;
extern s8 D_800CB99C_CC59C;
extern s8 D_800CD2A4_CDEA4;
extern void* D_800CE2C4_CEEC4;
extern Process* D_800D040C_D100C;
extern s8 D_800D1F34_D2B34;
extern void* D_800D1FE4_D2BE4;
extern void* D_800D4084_D4C84;
extern u8 D_800D5206_D5E06[5];
extern s8 D_800D5540_D6140;
extern s8 D_800D6A26_D7626;
extern s16 D_800D6B62_D7762;
extern s32 D_800A25D0_A31D0[];

s16 func_8005A968_5B568(s16, s16, s16, s16, s32, s16);
s16 func_8005B7B8_5C3B8(s16 win_id, u32 spriteMainFsPair, s16 arg2, s16 arg3, u16 arg4);
void func_8005BA90_5C690(s16, s16, s16);
void func_8005BCA4_5C8A4(s16, s16, s16);
void func_8005BDFC_5C9FC(s16, s32);
void func_8005BEE0_5CAE0(s16, s32);
void func_8005C060_5CC60(s16, s32, s32, s32, s32);
void func_8005D294_5DE94(s16);
void func_8005F904_60504(void);
void func_8005FBF8_607F8(s16, s32, s32, s32);
void func_8005FE90_60A90(s16);
void func_800554C4_560C4(s32, s32, s32);
s16 func_80055810_56410(void*);
s32 func_800364DC_370DC(u32);
void func_800365E8_371E8(u32);

INCLUDE_ASM("asm/nonmatchings/window", func_8005A0F0_5ACF0);

INCLUDE_ASM("asm/nonmatchings/window", func_8005A32C_5AF2C);

INCLUDE_ASM("asm/nonmatchings/window", func_8005A37C_5AF7C);

INCLUDE_ASM("asm/nonmatchings/window", func_8005A3C0_5AFC0);

INCLUDE_ASM("asm/nonmatchings/window", func_8005A428_5B028);

INCLUDE_ASM("asm/nonmatchings/window", func_8005A51C_5B11C);

INCLUDE_ASM("asm/nonmatchings/window", func_8005A54C_5B14C);

INCLUDE_ASM("asm/nonmatchings/window", func_8005A580_5B180);

INCLUDE_ASM("asm/nonmatchings/window", func_8005A5B0_5B1B0);

INCLUDE_ASM("asm/nonmatchings/window", func_8005A5EC_5B1EC);

INCLUDE_ASM("asm/nonmatchings/window", func_8005A61C_5B21C);

INCLUDE_ASM("asm/nonmatchings/window", func_8005A674_5B274);

void func_8005A6B0_5B2B0(void) {
    Process* temp_v0_4;
    void* temp_v0_6;
    s16 i;

    if (D_800A2150_A2D50 == 0) {
        D_800CC69C_CD29C = HuMemMemoryAllocTemp(sizeof(TextWindow) * WINDOWS_MAX);

        for (i = 0; i < WINDOWS_MAX; i++) {
            D_800CC69C_CD29C[i].unk5E = -1;
        }
        
        D_800CC69C_CD29C[0].unk62 = -1;
        D_800CC69C_CD29C[0].unk64 = 1;
        D_800CC69C_CD29C[0].unk5E = 0;
        D_800CC69C_CD29C[1].unk62 = 0;
        D_800CC69C_CD29C[1].unk64 = -1;
        D_800CC69C_CD29C[1].unk5E = -0x218;
        D_800D6A26_D7626 = 0;
        D_800D1F34_D2B34 = 0;
        D_800D6B62_D7762 = 0x2710;
        gLanguageIndex = GwCommon.languageIndex;

        if (gLanguageIndex >= LANGUAGE_MAX || gLanguageIndex == LANGUAGE_NONE) {
            gLanguageIndex = LANGUAGE_ENGLISH;
        }
        if (gLanguageIndex == LANGUAGE_JAPANESE) {
            D_800D1FE4_D2BE4 = HuReadFileTemp(0x0000002B);
            func_80036414_37014(strings_japanese_ROM_START);
        } else {
            D_800D1FE4_D2BE4 = HuReadFileTemp(0x0000002C);
            switch (gLanguageIndex) {
            case LANGUAGE_ENGLISH:
                func_80036414_37014(strings_english_ROM_START);
                break;
            case LANGUAGE_FRENCH:
                func_80036414_37014(strings_french_ROM_START);
                break;
            case LANGUAGE_GERMAN:
                func_80036414_37014(strings_german_ROM_START);
                break;
            case LANGUAGE_SPANISH:
                func_80036414_37014(strings_spanish_ROM_START);
                break;
            case LANGUAGE_ITALIAN:
                func_80036414_37014(strings_italian_ROM_START);
                break;
            }
        }
        
        temp_v0_4 = omAddPrcObj(func_8005DDDC_5E9DC, 0x1001, 0x800, 0);
        D_800D040C_D100C = temp_v0_4;
        omPrcSetStatBit(temp_v0_4, 0xA0);

        D_800A2150_A2D50 = 1;
        D_800CB99C_CC59C = 0;
        D_800D4084_D4C84 = HuReadFileTemp(0x00000029);
        D_800CE2C4_CEEC4 = HuReadFileTemp(0x0000002A);

        for (i = 0; i < ARRAY_COUNT(D_800BDA50_BE650); i++) {
            D_800BDA50_BE650[i] = -1;
        }

        temp_v0_6 = ReadMainFS(0x00000033);
        D_800BDA68_BE668 = func_80055810_56410(temp_v0_6);
        HuFreeFilePerm(temp_v0_6);

        for (i = 0; i < ARRAY_COUNT(D_800D5206_D5E06); i++) {
            D_800D5206_D5E06[i] = 0;
        }

        D_800D5540_D6140 = 0xC;
        D_800CD2A4_CDEA4 = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/window", func_8005A968_5B568);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B040_5BC40);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B238_5BE38);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B43C_5C03C);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B5EC_5C1EC);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B614_5C214);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B63C_5C23C);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B68C_5C28C);

void func_8005B6BC_5C2BC(s16 win_id, u32 arg1, s8 arg2) {
    TextWindow* textWindow = &D_800CC69C_CD29C[win_id];

    if (textWindow->unk_B8[arg2] != 0) {
        if (textWindow->usingStringIDBool[arg2] != 0) {
            func_800365E8_371E8(textWindow->unk_B8[arg2]);
        }
    }
    //pointer check
    if (0x80000000 < arg1) {
        textWindow->usingStringIDBool[arg2] = 0;
        textWindow->unk_B8[arg2] = arg1;
    } else {
        textWindow->usingStringIDBool[arg2] = 1;
        textWindow->unk_B8[arg2] = func_800364DC_370DC(arg1);
    }
    textWindow->unk_B2[arg2] = -1;
}

s16 func_8005B7B8_5C3B8(s16 win_id, u32 spriteMainFsPair, s16 arg2, s16 arg3, u16 arg4) {
    TextWindow* window = &D_800CC69C_CD29C[win_id];
    s16 spriteId;
    void *spriteBytes;
    s16 i;

    for (i = 4; i < ARRAY_COUNT(window->unk_6E); i++) {
        if (window->unk_6E[i] != -1) {
            continue;
        }
        break;
    }
    if (i >= ARRAY_COUNT(window->unk_6E)) {
        return -1;
    }

    spriteBytes = ReadMainFS(spriteMainFsPair);
    spriteId = func_80055810_56410(spriteBytes);
    window->unk_6E[i] = spriteId;
    HuMemMemoryFreePerm(spriteBytes);
    func_80055024_55C24(window->unk_6C, i, spriteId, arg4);
    func_80054904_55504(window->unk_6C, i, arg2, arg3);
    func_800554C4_560C4(window->unk_6C, i, 0);
    return i;
}

INCLUDE_ASM("asm/nonmatchings/window", func_8005B8F8_5C4F8);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B974_5C574);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BA28_5C628);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BA54_5C654);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BA90_5C690);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BB18_5C718);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BBC0_5C7C0);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BCA4_5C8A4);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BDA8_5C9A8);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BDFC_5C9FC);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BE30_5CA30);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BEE0_5CAE0);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BF70_5CB70);

INCLUDE_ASM("asm/nonmatchings/window", func_8005C02C_5CC2C);

INCLUDE_ASM("asm/nonmatchings/window", func_8005C060_5CC60);

INCLUDE_ASM("asm/nonmatchings/window", func_8005C154_5CD54);

INCLUDE_ASM("asm/nonmatchings/window", func_8005C190_5CD90);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CC18_5D818);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CC3C_5D83C);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CCF0_5D8F0);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CD38_5D938);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CD84_5D984);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CE10_5DA10);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CEB0_5DAB0);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CF94_5DB94);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CFE0_5DBE0);

INCLUDE_ASM("asm/nonmatchings/window", func_8005D294_5DE94);

INCLUDE_ASM("asm/nonmatchings/window", func_8005D2D4_5DED4);

INCLUDE_ASM("asm/nonmatchings/window", func_8005D2FC_5DEFC);

INCLUDE_ASM("asm/nonmatchings/window", func_8005D30C_5DF0C);

INCLUDE_ASM("asm/nonmatchings/window", func_8005D83C_5E43C);

INCLUDE_ASM("asm/nonmatchings/window", func_8005DAA4_5E6A4);

INCLUDE_ASM("asm/nonmatchings/window", func_8005DC94_5E894);

INCLUDE_ASM("asm/nonmatchings/window", func_8005DD14_5E914);

INCLUDE_ASM("asm/nonmatchings/window", func_8005DD54_5E954);

INCLUDE_ASM("asm/nonmatchings/window", func_8005DDDC_5E9DC);

INCLUDE_ASM("asm/nonmatchings/window", func_8005E0C0_5ECC0);

INCLUDE_ASM("asm/nonmatchings/window", func_8005E1A8_5EDA8);

INCLUDE_ASM("asm/nonmatchings/window", func_8005E1D8_5EDD8);

INCLUDE_ASM("asm/nonmatchings/window", func_8005E348_5EF48);

INCLUDE_ASM("asm/nonmatchings/window", func_8005EEE4_5FAE4);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F364_5FF64);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F524_60124);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F698_60298);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F744_60344);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F784_60384);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F7F4_603F4);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F904_60504);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F918_60518);

INCLUDE_ASM("asm/nonmatchings/window", func_8005FA90_60690);

INCLUDE_ASM("asm/nonmatchings/window", func_8005FBA4_607A4);

INCLUDE_ASM("asm/nonmatchings/window", func_8005FBF8_607F8);

INCLUDE_ASM("asm/nonmatchings/window", func_8005FE54_60A54);

INCLUDE_ASM("asm/nonmatchings/window", func_8005FE90_60A90);

INCLUDE_ASM("asm/nonmatchings/window", func_8005FFA8_60BA8);

INCLUDE_ASM("asm/nonmatchings/window", func_800600C0_60CC0);

INCLUDE_ASM("asm/nonmatchings/window", func_8006010C_60D0C);

void func_80060144_60D44(void) {
}

INCLUDE_ASM("asm/nonmatchings/window", func_8006014C_60D4C);

INCLUDE_ASM("asm/nonmatchings/window", func_80060174_60D74);

INCLUDE_ASM("asm/nonmatchings/window", func_800601BC_60DBC);

INCLUDE_ASM("asm/nonmatchings/window", func_8006022C_60E2C);

INCLUDE_ASM("asm/nonmatchings/window", func_80060290_60E90);

INCLUDE_ASM("asm/nonmatchings/window", func_8006034C_60F4C);

INCLUDE_ASM("asm/nonmatchings/window", func_80060388_60F88);

INCLUDE_ASM("asm/nonmatchings/window", func_80060394_60F94);

INCLUDE_ASM("asm/nonmatchings/window", func_800604A8_610A8);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7CB0_A88B0);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7CD4_A88D4);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7CF8_A88F8);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7D1C_A891C);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7D40_A8940);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7D64_A8964);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7D88_A8988);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7DAC_A89AC);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7DD0_A89D0);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7DF4_A89F4);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7E18_A8A18);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7E3C_A8A3C);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7E60_A8A60);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7E84_A8A84);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7EA8_A8AA8);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7ECC_A8ACC);

INCLUDE_ASM("asm/nonmatchings/window", func_800605A4_611A4);

INCLUDE_ASM("asm/nonmatchings/window", func_80060848_61448);

INCLUDE_ASM("asm/nonmatchings/window", func_80060858_61458);

INCLUDE_ASM("asm/nonmatchings/window", func_80060880_61480);

INCLUDE_ASM("asm/nonmatchings/window", func_80060C14_61814);

INCLUDE_ASM("asm/nonmatchings/window", func_80060DEC_619EC);

INCLUDE_ASM("asm/nonmatchings/window", func_80060EA8_61AA8);

INCLUDE_ASM("asm/nonmatchings/window", func_8006105C_61C5C);

INCLUDE_ASM("asm/nonmatchings/window", func_800610E0_61CE0);

INCLUDE_ASM("asm/nonmatchings/window", func_80061100_61D00);

s32 func_80061188_61D88(s16 arg0, s16 arg1, s16 arg2, s32 arg3, s32 arg4, u16 arg5) {
    TextWindow* temp_s2;
    s32 temp_v0;
    s32 temp_s0_2;
    s32 temp_s1;
    s32 temp_s0 = arg3 + 2;
    
    if ((arg0 != -1) & (arg4 < 0x30)) {
        arg4 = 0x30;
    }
    
    temp_v0 = func_8005A968_5B568(arg1, arg2, temp_s0, arg4, 0, arg5);
    func_8005BDFC_5C9FC(temp_v0, 0);
    temp_s2 = &D_800CC69C_CD29C[temp_v0];
    func_8005BCA4_5C8A4(temp_v0, temp_s0 / 2, arg4 / 2);
    func_8005BA90_5C690(temp_v0, (temp_s2->unk3C + temp_s0 / 2), (temp_s2->unk3E + arg4 / 2));
    temp_s2->unk276 = arg0;
    
    if (arg0 != -1) {
        temp_s2->unk274 = func_8005B7B8_5C3B8(temp_v0, D_800A25D0_A31D0[arg0], (0x18 - temp_s2->unk48), (0x18 - temp_s2->unk4A), 0);
    }
    
    temp_s2->unk54 = 6;
    temp_s2->unk4C = 6;
    func_8005BEE0_5CAE0(temp_v0, 0xD0);
    func_8005C060_5CC60(temp_v0, 1, 0x40, 0xF0, 0xFF);
    func_8005FBF8_607F8(temp_v0, 0x40, 0x20, 0xB0);
    func_8005D294_5DE94(temp_v0);
    func_8005FE90_60A90(temp_v0);
    func_8005F904_60504();
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/window", func_80061388_61F88);

INCLUDE_ASM("asm/nonmatchings/window", func_800615B8_621B8);

INCLUDE_ASM("asm/nonmatchings/window", func_80061934_62534);

INCLUDE_ASM("asm/nonmatchings/window", func_80061A5C_6265C);
