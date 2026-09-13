#include "game/window.h"
#include "game/sprite.h"
#include "common.h"
#include "malloc.h"

extern TextWindow *D_800CC69C_main;
extern u8 D_800A2150_main;
extern u8 gLanguageIndex;
extern u8 D_800A232C_main[];
extern u8 *D_800A2344_main[];
extern s16 D_800BDA50_main[12];
extern s8 D_800BDA6D_main;
extern s16 D_800BDA68_main;
extern s8 D_800CD2A4_main;
extern void *D_800CE2C4_main;
extern Process *D_800D040C_main;
extern s8 D_800D1F34_main;
extern void *D_800D1FE4_main;
extern void *D_800D4084_main;
extern u8 D_800D5206_main[5];
extern s8 D_800D5540_main;
extern s8 D_800D6A26_main;
extern s16 D_800D6B62_main;
extern s32 D_800A25D0_main[];
extern s8 D_800BDA6A_main;
extern u16 D_800BDA6C_main;
extern u16 D_800BDA6E_main;
extern u8 D_800D5206_main[5];
extern s8 D_800D5540_main;

s16 func_8005BA54_main(s16, s16);
void func_8005BB18_main(s16, f32, f32);
void func_800615B8_main(s16, s32);

void func_8005A6B0_main(void) {
    Process *temp_v0_4;
    void *temp_v0_6;
    s16 i;

    if (D_800A2150_main == 0) {
        D_800CC69C_main = HuMemMemoryAllocTemp(sizeof(TextWindow) * WINDOWS_MAX);

        for (i = 0; i < WINDOWS_MAX; i++) {
            D_800CC69C_main[i].unk5E = -1;
        }

        D_800CC69C_main[0].unk62 = -1;
        D_800CC69C_main[0].unk64 = 1;
        D_800CC69C_main[0].unk5E = 0;
        D_800CC69C_main[1].unk62 = 0;
        D_800CC69C_main[1].unk64 = -1;
        D_800CC69C_main[1].unk5E = -0x218;
        D_800D6A26_main = 0;
        D_800D1F34_main = 0;
        D_800D6B62_main = 0x2710;
        gLanguageIndex = GwCommon.languageIndex;

        if (gLanguageIndex >= LANGUAGE_MAX || gLanguageIndex == LANGUAGE_NONE) {
            gLanguageIndex = LANGUAGE_ENGLISH;
        }
        if (gLanguageIndex == LANGUAGE_JAPANESE) {
            D_800D1FE4_main = DataReadTemp(0x0000002B);
            func_80036414_main((u32)strings_japanese_ROM_START);
        } else {
            D_800D1FE4_main = DataReadTemp(0x0000002C);
            switch (gLanguageIndex) {
                case LANGUAGE_ENGLISH:
                    func_80036414_main((u32)strings_english_ROM_START);
                    break;
                case LANGUAGE_FRENCH:
                    func_80036414_main((u32)strings_french_ROM_START);
                    break;
                case LANGUAGE_GERMAN:
                    func_80036414_main((u32)strings_german_ROM_START);
                    break;
                case LANGUAGE_SPANISH:
                    func_80036414_main((u32)strings_spanish_ROM_START);
                    break;
                case LANGUAGE_ITALIAN:
                    func_80036414_main((u32)strings_italian_ROM_START);
                    break;
            }
        }

        temp_v0_4 = omAddPrcObj(func_8005DDDC_main, 0x1001, 0x800, 0);
        D_800D040C_main = temp_v0_4;
        omPrcSetStatBit(temp_v0_4, 0xA0);

        D_800A2150_main = 1;
        D_800CB99C_main = 0;
        D_800D4084_main = DataReadTemp(0x00000029);
        D_800CE2C4_main = DataReadTemp(0x0000002A);

        for (i = 0; i < ARRAY_COUNT(D_800BDA50_main); i++) {
            D_800BDA50_main[i] = -1;
        }

        temp_v0_6 = DataRead(0x00000033);
        D_800BDA68_main = func_80055810_main(temp_v0_6);
        DataClose(temp_v0_6);

        for (i = 0; i < ARRAY_COUNT(D_800D5206_main); i++) {
            D_800D5206_main[i] = 0;
        }

        D_800D5540_main = 0xC;
        D_800CD2A4_main = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/window", func_8005A968_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B040_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B238_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B43C_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B5EC_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B614_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B63C_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005B68C_main);

void func_8005B6BC_main(s16 win_id, u32 arg1, s8 arg2) {
    TextWindow *textWindow = &D_800CC69C_main[win_id];

    if (textWindow->unk_B8[arg2] != 0) {
        if (textWindow->usingStringIDBool[arg2] != 0) {
            func_800365E8_main(textWindow->unk_B8[arg2]);
        }
    }
    // pointer check
    if (0x80000000 < arg1) {
        textWindow->usingStringIDBool[arg2] = 0;
        textWindow->unk_B8[arg2] = (char *)arg1;
    } else {
        textWindow->usingStringIDBool[arg2] = 1;
        textWindow->unk_B8[arg2] = func_800364DC_main((void *)arg1);
    }
    textWindow->unk_B2[arg2] = -1;
}

s16 func_8005B7B8_main(s16 win_id, u32 spriteMainFsPair, s16 arg2, s16 arg3, u16 arg4) {
    TextWindow *window = &D_800CC69C_main[win_id];
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

    spriteBytes = DataRead(spriteMainFsPair);
    spriteId = func_80055810_main(spriteBytes);
    window->unk_6E[i] = spriteId;
    HuMemMemoryFreePerm(spriteBytes);
    func_80055024_main(window->unk_6C, i, spriteId, arg4);
    func_80054904_main(window->unk_6C, i, arg2, arg3);
    func_800554C4_main(window->unk_6C, i, 0);
    return i;
}

void func_8005B8F8_main(s16 arg0, s16 arg1) {
    HuSprKill(func_8005BA54_main(arg0, arg1));
    D_800CC69C_main[arg0].unk_6E[arg1] = -1;
}

INCLUDE_ASM("asm/nonmatchings/window", func_8005B974_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BA28_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BA54_main);

void func_8005BA90_main(s16 winId, s16 arg1, s16 arg2) {
    TextWindow *window;

    window = &D_800CC69C_main[winId];

    func_80054904_main(window->unk_6C, 0, arg1, arg2);
    window->unk3C = arg1;
    window->unk3E = arg2;
}

INCLUDE_ASM("asm/nonmatchings/window", func_8005BB18_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BBC0_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BCA4_main);

void func_8005BDA8_main(s16 winId, f32 arg1) {
    TextWindow *window;

    window = &D_800CC69C_main[winId];
    func_800552DC_main(window->unk_6C, 0, arg1);
}

INCLUDE_ASM("asm/nonmatchings/window", func_8005BDFC_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005BE30_main);

void func_8005BEE0_main(s16 winId, s16 arg1) {
    TextWindow *window;

    window = &D_800CC69C_main[winId];

    if (arg1 == 0) {
        HuSprAttrSet(window->unk_6C, 0, 0x8000);
    } else {
        HuSprAttrReset(window->unk_6C, 0, 0x8000);
    }
    func_80055458_main(window->unk_6C, 0, arg1 & 0xFFFF);
}

INCLUDE_ASM("asm/nonmatchings/window", func_8005BF70_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005C02C_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005C060_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005C154_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005C190_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CC18_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CC3C_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CCF0_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CD38_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CD84_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CE10_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CEB0_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CF94_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005CFE0_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005D294_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005D2D4_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005D2FC_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005D30C_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005D83C_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005DAA4_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005DC94_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005DD14_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005DD54_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005DDDC_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005E0C0_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005E1A8_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005E1D8_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005E348_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005EEE4_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F364_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F524_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F698_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F744_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F784_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F7F4_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F904_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005F918_main);

u8 func_8005FA90_main(u8 *arg0) {
    s16 i, j;

    for (i = 0; i < 10; i += 2) {
        if (D_800A232C_main[i] == arg0[0] && D_800A232C_main[i + 1] == arg0[1]) {
            return i / 2;
        }
    }
    for (i = 0; i < 16; i++) {
        for (j = 0; j < 32; j += 2) {
            if (D_800A2344_main[i][j] == arg0[0] && D_800A2344_main[i][j + 1] == arg0[1]) {
                return i * 16 + j / 2;
            }
        }
    }
    return 16;
}

INCLUDE_ASM("asm/nonmatchings/window", func_8005FBA4_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005FBF8_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005FE54_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005FE90_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8005FFA8_main);

void func_800600C0_main(s16 winId, s32 arg1) {
    TextWindow *window;

    window = &D_800CC69C_main[winId];
    if (arg1 != 0) {
        window->unk_38 |= 0x10;
    } else {
        window->unk_38 &= ~0x10;
    }
}

// Sets an option disabled.
INCLUDE_ASM("asm/nonmatchings/window", func_8006010C_main);

void func_80060144_main(s16 obj) {
#ifdef DEBUG

#endif
}

s16 func_8006014C_main(s32 winId) {
    return D_800CC69C_main[winId].unk_31;
}

INCLUDE_ASM("asm/nonmatchings/window", func_80060174_main);

INCLUDE_ASM("asm/nonmatchings/window", func_800601BC_main);

// Called to indicate that `str` should be the replacement at a
// "replacement index" location in the main string.
void func_8006022C_main(u32 str, s16 index) {
    D_800BDA6A_main = 1;
    D_800BDA6E_main = 0;
    D_800BDA6C_main = 0;
    func_800605A4_main(str);
    D_800CD2A4_main = 0;
    D_800D5206_main[index] = D_800BDA6D_main;
}

INCLUDE_ASM("asm/nonmatchings/window", func_80060290_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8006034C_main);

void func_80060388_main(s8 arg0) {
    D_800D5540_main = arg0;
}

INCLUDE_ASM("asm/nonmatchings/window", func_80060394_main);

void func_800604A8_main(s16 *arg0, s16 arg1, s16 arg2) {
    u32 i;

    if (arg2 < arg1) {
        arg0[1] = 0x64;
        arg0[0] = 0x64;
        return;
    }

    D_800BDA6A_main = 0;
    D_800BDA6E_main = 0;
    D_800BDA6C_main = 0;

    for (i = arg1; arg2 >= i; i++) {
        func_800605A4_main(i);
    }

    for (i = 0; i < ARRAY_COUNT(D_800D5206_main); i++) {
        D_800D5206_main[i] = 0;
    }

    D_800D5540_main = 0xC;
    arg0[0] = D_800BDA6C_main + 10;
    arg0[1] = D_800BDA6E_main + 6;
}

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7CB0_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7CD4_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7CF8_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7D1C_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7D40_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7D64_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7D88_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7DAC_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7DD0_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7DF4_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7E18_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7E3C_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7E60_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7E84_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7EA8_main);

INCLUDE_RODATA("asm/nonmatchings/window", D_800A7ECC_main);

INCLUDE_ASM("asm/nonmatchings/window", func_800605A4_main);

void func_80060848_main() {
    D_800CD2A4_main = 1;
}

INCLUDE_ASM("asm/nonmatchings/window", func_80060858_main);

INCLUDE_ASM("asm/nonmatchings/window", func_80060880_main);

INCLUDE_ASM("asm/nonmatchings/window", func_80060C14_main);

INCLUDE_ASM("asm/nonmatchings/window", func_80060DEC_main);

INCLUDE_ASM("asm/nonmatchings/window", func_80060EA8_main);

INCLUDE_ASM("asm/nonmatchings/window", func_8006105C_main);

INCLUDE_ASM("asm/nonmatchings/window", func_800610E0_main);

INCLUDE_ASM("asm/nonmatchings/window", func_80061100_main);

// Obtains a window handle
s32 func_80061188_main(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u16 arg5) {
    TextWindow *temp_s2;
    s32 temp_v0;
    s32 temp_s0_2;
    s32 temp_s1;
    s32 temp_s0 = arg3 + 2;

    if ((arg0 != -1) & (arg4 < 0x30)) {
        arg4 = 0x30;
    }

    temp_v0 = func_8005A968_main(arg1, arg2, temp_s0, arg4, 0, arg5);
    func_8005BDFC_main(temp_v0, 0);
    temp_s2 = &D_800CC69C_main[temp_v0];
    func_8005BCA4_main(temp_v0, temp_s0 / 2, arg4 / 2);
    func_8005BA90_main(temp_v0, (temp_s2->unk3C + temp_s0 / 2), (temp_s2->unk3E + arg4 / 2));
    temp_s2->unk276 = arg0;

    if (arg0 != -1) {
        temp_s2->unk274 = func_8005B7B8_main(temp_v0, D_800A25D0_main[arg0], (0x18 - temp_s2->unk48), (0x18 - temp_s2->unk4A), 0);
    }

    temp_s2->unk54 = 6;
    temp_s2->unk4C = 6;
    func_8005BEE0_main(temp_v0, 0xD0);
    func_8005C060_main(temp_v0, 1, 0x40, 0xF0, 0xFF);
    func_8005FBF8_main(temp_v0, 0x40, 0x20, 0xB0);
    func_8005D294_main(temp_v0);
    func_8005FE90_main(temp_v0);
    func_8005F904_main();
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/window", func_80061388_main);

INCLUDE_ASM("asm/nonmatchings/window", func_800615B8_main);

void func_80061934_main(s16 winId, s16 arg1) {
    s16 temp_v0;
    TextWindow *temp_s0;

    temp_s0 = &D_800CC69C_main[winId];
    func_800600C0_main(winId, 1);
    func_800615B8_main(winId, 0);
    func_8005B8F8_main(winId, temp_s0->unk274);
    temp_v0 = func_8005B7B8_main(winId, D_800A25D0_main[arg1], 0x18 - temp_s0->unk48, 0x18 - temp_s0->unk4A, 0);
    temp_s0->unk274 = temp_v0;
    func_80054904_main(temp_s0->unk_6C, temp_v0, 0x18 - temp_s0->unk48, 0x18 - temp_s0->unk4A);
    HuSprScaleSet(temp_s0->unk_6C, temp_s0->unk274, 1.0f, 1.0f);
    func_800615B8_main(winId, 1);
    func_800600C0_main(winId, 0);
}

void func_80061A5C_main(s16 arg0, s16 arg1) {
    s16 i;

    if (arg1 == 0) {
        func_8005D294_main(arg0);

        for (i = 0; i < 5; i++) {
            func_8005BB18_main(arg0, 1.0f, 1.0f - HuMathSin(i * 18.0f));
            HuPrcVSleep();
        }

        func_8005FE90_main(arg0);
        HuPrcVSleep();
        return;
    }
    func_8005FE90_main(arg0);
}
