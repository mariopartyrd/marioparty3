#include "common.h"

#define MAX_STRINGS 512

typedef struct strline_data {
/* 0x00 */ u16 color;
/* 0x02 */ s16 x;
/* 0x04 */ s16 y;
/* 0x06 */ s16 empstrline_next;
/* 0x08 */ u8 str[64];
} strline_data;

typedef struct Unk_D_800CC440 {
    u16 unk_00;
    s32 unk_04;
    s32 unk_08;
    s32 unk_0C;
    s32 unk_10;
    s32 unk_14;
} Unk_D_800CC440;

extern strline_data strline[MAX_STRINGS];
extern u16 strlinecnt;
extern u16 empstrline;
extern s32 fontcolor;
extern u16 D_800D6A46_D7646;
extern Unk_D_800CC440 D_800CC440_CD040[4];
extern s16 D_800CDD4C_CE94C;

void pfInit(void) {
    s32 i;

    fontcolor = 15;
    empstrline = 0;

    //null every string by setting the first byte to 0
    for (i = 0; i < MAX_STRINGS; i++) {
        strline[i].str[0] = '\0';
    }

    pfClsScr();

    D_800D6A46_D7646 = 0;
    for (i = 0; i < 4; i++) {
        D_800CC440_CD040[i].unk_00 = 0;
    }
    D_800CDD4C_CE94C = 0;
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

void func_8004DCFC_4E8FC(s16 arg0) {
    strline_data* temp_v1;

    if ((strline[arg0].str[0] != '\0') && (strlinecnt != 0)) {
        strlinecnt -= 1;
        strline[arg0].str[0] = '\0';
        strline[arg0].empstrline_next = empstrline;
        empstrline = arg0;
    }
}

//unsure if this should be char* src or u8* src
s32 print8(u16 x, u16 y, char* src) {
    u8* dst;
    strline_data* strLine;
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
        while (*(u8*)src != '\0') {
            *dst++ = *(u8*)src++;
        }
        *dst = '\0';
        return prevStrIndex;
    } else {
        return -1;
    }
}

//printWin?
s16 func_8004DE24_4EA24(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Unk_D_800CC440* temp;
    s32 i;
    
    if (D_800D6A46_D7646 >= 4) {
        return -1;
    }
    for (i = 0; i < 4; i++) {
        if (D_800CC440_CD040[i].unk_00 == 0) {
            break;
        }
    }
    temp = &D_800CC440_CD040[i];
    temp->unk_00 = 1;
    temp->unk_04 = arg0;
    temp->unk_08 = arg1;
    temp->unk_0C = arg2;
    temp->unk_10 = arg3;
    temp->unk_14 = arg4;
    D_800D6A46_D7646++;
    return i;
}

void func_8004DEC8_4EAC8(s16 arg0) {
    if (D_800D6A46_D7646 != 0) {
        D_800CC440_CD040[arg0].unk_00 = 0;
        D_800D6A46_D7646 -= 1;
    }
}

void func_8004DF10_4EB10(void) {
    s32 i;

    D_800D6A46_D7646 = 0;
    for (i = 0; i < 4; i++) {
        D_800CC440_CD040[i].unk_00 = 0;
    }
}

typedef struct Unk_D_800CE1DC {
    u8 unk_00;
    u8 unk_01;
    u8 unk_02;
    u8 unk_03;
    u8 unk_04;
    u8 unk_05;

    u8 unk_06;
    u8 unk_07;
    u8 unk_08;
    u8 unk_09;
    u8 unk_0A;
    u8 unk_0B;
} Unk_D_800CE1DC;

extern s16 D_800CDD4C_CE94C;
extern Unk_D_800CE1DC D_800CE1DC_CEDDC;

void func_8004DF4C_4EB4C(s8 arg0, s8 arg1, s8 arg2) {
    D_800CE1DC_CEDDC.unk_00 = arg0;
    D_800CE1DC_CEDDC.unk_01 = arg1;
    D_800CE1DC_CEDDC.unk_02 = arg2;
    D_800CE1DC_CEDDC.unk_03 = D_800CE1DC_CEDDC.unk_04 = D_800CE1DC_CEDDC.unk_05 = 0;
    D_800CDD4C_CE94C = 1;
}

void func_8004DF7C_4EB7C(s8 arg0, s8 arg1, s8 arg2, s8 arg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7, u8 arg8) {
    D_800CE1DC_CEDDC.unk_03 = arg0;
    D_800CE1DC_CEDDC.unk_04 = arg1;
    D_800CE1DC_CEDDC.unk_05 = arg2;
    D_800CE1DC_CEDDC.unk_06 = arg3;
    D_800CE1DC_CEDDC.unk_07 = arg4;
    D_800CE1DC_CEDDC.unk_08 = arg5;
    D_800CE1DC_CEDDC.unk_09 = arg6;
    D_800CE1DC_CEDDC.unk_0A = arg7;
    D_800CE1DC_CEDDC.unk_0B = arg8;
}

void func_8004DFC0_4EBC0(void) {
    D_800CE1DC_CEDDC.unk_03 = D_800CE1DC_CEDDC.unk_04 = D_800CE1DC_CEDDC.unk_05 = 0;
}

void func_8004DFD8_4EBD8 (void) {
    D_800CDD4C_CE94C = 0;
}

void func_8004DFE4_4EBE4(s16 arg0, u8* src) {
    u8* dst;
    
    if (strline[arg0].str != NULL) {
        dst = strline[arg0].str;
        while (*src != '\0') {
            *dst++ = *src++;
        }
        *dst = '\0';
    }
}

INCLUDE_ASM("asm/nonmatchings/printfunc", pfDrawFonts);
