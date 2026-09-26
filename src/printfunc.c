#include "common.h"

#define MAX_STRINGS 512

#define RGBA32_R(color) ((color) >> 24)
#define RGBA32_G(color) (((color) >> 16) & 0xFF)
#define RGBA32_B(color) (((color) >> 8) & 0xFF)
#define RGBA32_A(color) ((color) & 0xFF)
#define FILL_COLOR_RGBA5551(r, g, b, a) ((GPACK_RGBA5551(r, g, b, a) << 16) | GPACK_RGBA5551(r, g, b, a))

typedef struct strline_data {
    /* 0x00 */ u16 color;
    /* 0x02 */ s16 x;
    /* 0x04 */ s16 y;
    /* 0x06 */ s16 empstrline_next;
    /* 0x08 */ u8 str[64];
} strline_data;

// filled rect behind debug text
typedef struct Unk_D_800CC440 {
    u16 unk_00; // active
    s32 unk_04; // left
    s32 unk_08; // top
    s32 unk_0C; // right
    s32 unk_10; // bottom
    u32 unk_14; // color
} Unk_D_800CC440;

typedef struct Unk_D_800CE1DC {
    u8 unk_00; // red
    u8 unk_01; // green
    u8 unk_02; // blue
    s8 unk_03; // red speed
    s8 unk_04; // green speed
    s8 unk_05; // blue speed
    u8 unk_06; // red max
    u8 unk_07; // green max
    u8 unk_08; // blue max
    u8 unk_09; // red min
    u8 unk_0A; // green min
    u8 unk_0B; // blue min
} Unk_D_800CE1DC;

extern strline_data strline[MAX_STRINGS];
extern u16 strlinecnt;
extern u16 empstrline;
extern s32 fontcolor;
extern u16 D_800D6A46_main;
extern Unk_D_800CC440 D_800CC440_main[4];
extern u16 D_800CDD4C_main; // screen border enabled
extern Unk_D_800CE1DC D_800CE1DC_main;
extern u16 D_800A1D64_main;         // palette currently loaded for the font texture
extern u8 D_8009F730_main[];        // 64x64 CI4 font texture, 8x8 glyphs starting at ' '
extern u16 D_800A0330_main[16][16]; // font palettes

void pfInit(void) {
    s32 i;

    fontcolor = 15;
    empstrline = 0;

    // null every string by setting the first byte to 0
    for (i = 0; i < MAX_STRINGS; i++) {
        strline[i].str[0] = '\0';
    }

    pfClsScr();

    D_800D6A46_main = 0;
    for (i = 0; i < 4; i++) {
        D_800CC440_main[i].unk_00 = 0;
    }
    D_800CDD4C_main = 0;
}

void pfClsScr(void) {
    s32 i;

    empstrline = 0;
    strlinecnt = 0;
    for (i = 0; i < MAX_STRINGS; i++) {
        strline[i].empstrline_next = i + 1;
        if (strline[i].str[0] != 0) {
            strline[i].str[0] = 0;
        }
    }
}

void func_8004DCFC_main(s16 arg0) {
    strline_data *temp_v1;

    if ((strline[arg0].str[0] != '\0') && (strlinecnt != 0)) {
        strlinecnt -= 1;
        strline[arg0].str[0] = '\0';
        strline[arg0].empstrline_next = empstrline;
        empstrline = arg0;
    }
}

// unsure if this should be char* src or u8* src
s32 print8(u16 x, u16 y, char *src) {
    u8 *dst;
    strline_data *strLine;
    s16 prevStrIndex;

    strLine = &strline[empstrline];
    if (strlinecnt < MAX_STRINGS) {
        strlinecnt += 1;
        prevStrIndex = empstrline;
        empstrline = strLine->empstrline_next;
        strLine->color = fontcolor;
        strLine->x = x;
        strLine->y = y;
        dst = strLine->str;
        while (*(u8 *)src != '\0') {
            *dst++ = *(u8 *)src++;
        }
        *dst = '\0';
        return prevStrIndex;
    } else {
        return -1;
    }
}

// printWin?
s16 func_8004DE24_main(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Unk_D_800CC440 *temp;
    s32 i;

    if (D_800D6A46_main >= 4) {
        return -1;
    }
    for (i = 0; i < 4; i++) {
        if (D_800CC440_main[i].unk_00 == 0) {
            break;
        }
    }
    temp = &D_800CC440_main[i];
    temp->unk_00 = 1;
    temp->unk_04 = arg0;
    temp->unk_08 = arg1;
    temp->unk_0C = arg2;
    temp->unk_10 = arg3;
    temp->unk_14 = arg4;
    D_800D6A46_main++;
    return i;
}

void func_8004DEC8_main(s16 arg0) {
    if (D_800D6A46_main != 0) {
        D_800CC440_main[arg0].unk_00 = 0;
        D_800D6A46_main -= 1;
    }
}

void func_8004DF10_main(void) {
    s32 i;

    D_800D6A46_main = 0;
    for (i = 0; i < 4; i++) {
        D_800CC440_main[i].unk_00 = 0;
    }
}

void func_8004DF4C_main(s8 arg0, s8 arg1, s8 arg2) {
    D_800CE1DC_main.unk_00 = arg0;
    D_800CE1DC_main.unk_01 = arg1;
    D_800CE1DC_main.unk_02 = arg2;
    D_800CE1DC_main.unk_03 = D_800CE1DC_main.unk_04 = D_800CE1DC_main.unk_05 = 0;
    D_800CDD4C_main = 1;
}

void func_8004DF7C_main(s8 arg0, s8 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    D_800CE1DC_main.unk_03 = arg0;
    D_800CE1DC_main.unk_04 = arg1;
    D_800CE1DC_main.unk_05 = arg2;
    D_800CE1DC_main.unk_06 = arg3;
    D_800CE1DC_main.unk_07 = arg4;
    D_800CE1DC_main.unk_08 = arg5;
    D_800CE1DC_main.unk_09 = arg6;
    D_800CE1DC_main.unk_0A = arg7;
    D_800CE1DC_main.unk_0B = arg8;
}

void func_8004DFC0_main(void) {
    D_800CE1DC_main.unk_03 = D_800CE1DC_main.unk_04 = D_800CE1DC_main.unk_05 = 0;
}

void func_8004DFD8_main(void) {
    D_800CDD4C_main = 0;
}

void func_8004DFE4_main(s16 arg0, u8 *src) {
    u8 *dst;

    if (strline[arg0].str) {
        dst = strline[arg0].str;
        while (*src != '\0') {
            *dst++ = *src++;
        }
        *dst = '\0';
    }
}

Gfx *pfDrawFonts(Gfx *gfx) {
    u16 count;
    s32 i;
    u16 pal;
    u16 color;
    u16 x;
    u16 y;
    u8 *str;
    u8 c;
    s8 speed;

    count = strlinecnt;

    if (D_800D6A46_main != 0) {
        gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, 319, 339);
        gDPPipeSync(gfx++);
        gDPSetTextureLOD(gfx++, G_TL_LOD);
        gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
        gDPSetTexturePersp(gfx++, G_TP_NONE);
        gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
        for (i = 0; i < 4; i++) {
            if (D_800CC440_main[i].unk_00 != 0) {
                if (RGBA32_A(D_800CC440_main[i].unk_14) == 0xFF) {
                    gDPPipeSync(gfx++);
                    gDPSetCycleType(gfx++, G_CYC_FILL);
                    gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
                    gDPSetFillColor(gfx++, FILL_COLOR_RGBA5551(RGBA32_R(D_800CC440_main[i].unk_14),
                                                               RGBA32_G(D_800CC440_main[i].unk_14),
                                                               RGBA32_B(D_800CC440_main[i].unk_14),
                                                               RGBA32_A(D_800CC440_main[i].unk_14)));
                } else {
                    gDPPipeSync(gfx++);
                    gDPSetCycleType(gfx++, G_CYC_1CYCLE);
                    gDPSetCombineMode(gfx++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
                    gDPSetRenderMode(gfx++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
                    gDPSetPrimColor(gfx++, 0, 0, RGBA32_R(D_800CC440_main[i].unk_14),
                                    RGBA32_G(D_800CC440_main[i].unk_14), RGBA32_B(D_800CC440_main[i].unk_14),
                                    RGBA32_A(D_800CC440_main[i].unk_14));
                }
                gDPFillRectangle(gfx++, D_800CC440_main[i].unk_04, D_800CC440_main[i].unk_08,
                                 D_800CC440_main[i].unk_0C, D_800CC440_main[i].unk_10);
            }
        }
    }

    if (D_800CDD4C_main != 0) {
        if (D_800CE1DC_main.unk_03 != 0) {
            speed = D_800CE1DC_main.unk_03;
            if (speed < 0) {
                if (D_800CE1DC_main.unk_00 + speed >= D_800CE1DC_main.unk_09) {
                    D_800CE1DC_main.unk_00 += speed;
                } else {
                    D_800CE1DC_main.unk_00 = D_800CE1DC_main.unk_09;
                    D_800CE1DC_main.unk_03 = -D_800CE1DC_main.unk_03;
                }
            } else {
                if (D_800CE1DC_main.unk_00 + speed <= D_800CE1DC_main.unk_06) {
                    D_800CE1DC_main.unk_00 += speed;
                } else {
                    D_800CE1DC_main.unk_00 = D_800CE1DC_main.unk_06;
                    D_800CE1DC_main.unk_03 = -D_800CE1DC_main.unk_03;
                }
            }
        }
        if (D_800CE1DC_main.unk_04 != 0) {
            speed = D_800CE1DC_main.unk_04;
            if (speed < 0) {
                if (D_800CE1DC_main.unk_01 + speed >= D_800CE1DC_main.unk_0A) {
                    D_800CE1DC_main.unk_01 += speed;
                } else {
                    D_800CE1DC_main.unk_01 = D_800CE1DC_main.unk_0A;
                    D_800CE1DC_main.unk_04 = -D_800CE1DC_main.unk_04;
                }
            } else {
                if (D_800CE1DC_main.unk_01 + speed <= D_800CE1DC_main.unk_07) {
                    D_800CE1DC_main.unk_01 += speed;
                } else {
                    D_800CE1DC_main.unk_01 = D_800CE1DC_main.unk_07;
                    D_800CE1DC_main.unk_04 = -D_800CE1DC_main.unk_04;
                }
            }
        }
        if (D_800CE1DC_main.unk_05 != 0) {
            speed = D_800CE1DC_main.unk_05;
            if (speed < 0) {
                if (D_800CE1DC_main.unk_02 + speed >= D_800CE1DC_main.unk_0B) {
                    D_800CE1DC_main.unk_02 += speed;
                } else {
                    D_800CE1DC_main.unk_02 = D_800CE1DC_main.unk_0B;
                    D_800CE1DC_main.unk_05 = -D_800CE1DC_main.unk_05;
                }
            } else {
                if (D_800CE1DC_main.unk_02 + speed <= D_800CE1DC_main.unk_08) {
                    D_800CE1DC_main.unk_02 += speed;
                } else {
                    D_800CE1DC_main.unk_02 = D_800CE1DC_main.unk_08;
                    D_800CE1DC_main.unk_05 = -D_800CE1DC_main.unk_05;
                }
            }
        }
        gDPPipeSync(gfx++);
        gDPSetCycleType(gfx++, G_CYC_FILL);
        gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
        gDPSetFillColor(gfx++, FILL_COLOR_RGBA5551(D_800CE1DC_main.unk_00, D_800CE1DC_main.unk_01,
                                                   D_800CE1DC_main.unk_02, 1));
        gDPFillRectangle(gfx++, 24, 16, 296, 16);
        gDPFillRectangle(gfx++, 24, 224, 296, 224);
        gDPFillRectangle(gfx++, 24, 16, 24, 224);
        gDPFillRectangle(gfx++, 296, 16, 296, 224);
    }

    gDPSetScissor(gfx++, G_SC_NON_INTERLACE, 0, 0, 319, 339);
    gDPPipeSync(gfx++);
    gDPSetCycleType(gfx++, G_CYC_COPY);
    gDPSetAlphaCompare(gfx++, G_AC_THRESHOLD);
    gDPSetTextureLOD(gfx++, G_TL_LOD);
    gDPSetRenderMode(gfx++, G_RM_NOOP, G_RM_NOOP2);
    gSPTexture(gfx++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(gfx++, G_TP_NONE);
    gDPSetTextureLUT(gfx++, G_TT_RGBA16);
    gDPSetBlendColor(gfx++, 0xFF, 0xFF, 0xFF, 0xFF);
    gDPLoadTextureBlock_4b(gfx++, D_8009F730_main, G_IM_FMT_CI, 64, 64, D_800A1D64_main,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK,
                           G_TX_NOLOD, G_TX_NOLOD);
    gDPSetBlendColor(gfx++, 0, 0, 0, 1);
    for (pal = 0; pal < 16; pal++) {
        gDPLoadTLUT_pal16(gfx++, pal, D_800A0330_main[pal]);
    }

    for (i = 0; i < MAX_STRINGS; i++) {
        if (strline[i].str[0] != '\0') {
            str = strline[i].str;
            color = strline[i].color;
            x = strline[i].x;
            y = strline[i].y;
            if (color != D_800A1D64_main) {
                D_800A1D64_main = color;
                gDPTileSync(gfx++);
                gDPSetTile(gfx++, G_IM_FMT_CI, G_IM_SIZ_4b, 4, 0, G_TX_RENDERTILE, color, 0, 0, 0, 0, 0, 0);
            }
            for (; *str != '\0'; str++) {
                if (*str >= ' ') {
                    c = *str - ' ';
                    gSPTextureRectangle(gfx++, x << 2, y << 2, (x + 7) << 2, (y + 7) << 2, G_TX_RENDERTILE,
                                        ((c % 8) * 8) << 5, ((c / 8) * 8) << 5, 4 << 10, 1 << 10);
                    x += 8;
                    if (x >= 320) {
                        x = 0;
                        y += 8;
                    }
                }
            }
            if (--count == 0) {
                break;
            }
        }
    }

    gDPPipeSync(gfx++);
    gSPTexture(gfx++, 0, 0, 0, G_TX_RENDERTILE, G_OFF);
    gDPSetCombineMode(gfx++, G_CC_SHADE, G_CC_SHADE);
    gDPSetRenderMode(gfx++, G_RM_ZB_OPA_SURF, G_RM_ZB_OPA_SURF2);
    gDPSetTextureLUT(gfx++, G_TT_NONE);
    gDPSetTexturePersp(gfx++, G_TP_PERSP);
    gDPSetTextureFilter(gfx++, G_TF_BILERP);
    return gfx;
}
