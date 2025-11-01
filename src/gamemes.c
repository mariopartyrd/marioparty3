#include "game/gamemes.h"
#include "game/audio.h"
#include "game/sprite.h"
#include "stdarg.h"
#include "include_asm.h"

f32 HuMathSin(f32);

extern Gfx* gMainGfxPos;
extern s8 HmfPauseF;

typedef struct {
    /* 0x00 */ u8 mesNo;
    /* 0x01 */ u8 stat;
    /* 0x02 */ s8 unk02;
    /* 0x03 */ u8 unk03;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ char unk18[4];
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s16 strGId[16];
    /* 0x40 */ s16 strSprId[16];
    /* 0x60 */ f32 unk60;
    /* 0x64 */ f32 unk64;
    /* 0x68 */ f32 unk68;
    /* 0x6C */ f32 unk6C;
    /* 0x70 */ s32 unk70;
} GAMEMES; // Size 0x74

s32 func_80037574_38174(GAMEMES* gMes, Gfx**);
s32 func_80037878_38478(GAMEMES* gMes, Gfx**);
s32 func_80037C44_38844(GAMEMES* gMes, Gfx**);
s32 func_8003843C_3903C(GAMEMES* gMes, Gfx**);
s32 func_80038934_39534(GAMEMES* gMes, Gfx**);
s32 func_80038D78_39978(GAMEMES* gMes, Gfx**);
s32 func_800392AC_39EAC(GAMEMES* gMes, Gfx**);
s32 func_8003966C_3A26C(GAMEMES* gMes, Gfx**);
s32 func_80039A6C_3A66C(GAMEMES* gMes, Gfx**);
s32 func_80039E80_3AA80(GAMEMES* gMes, Gfx**);
s32 func_8003A2EC_3AEEC(GAMEMES* gMes, Gfx**);
s32 func_8003B14C_3BD4C(GAMEMES* gMes, Gfx**);
s32 func_8003B7E8_3C3E8(GAMEMES* gMes, Gfx**);
s32 func_8003BB84_3C784(GAMEMES* gMes, Gfx**);
s32 func_8003C248_3CE48(GAMEMES* gMes, Gfx**);
s32 func_8003C644_3D244(GAMEMES* gMes, Gfx**);
s32 func_8003CA24_3D624(GAMEMES* gMes, Gfx**);
s32 func_8003CE20_3DA20(GAMEMES* gMes, Gfx**);
s32 func_8003D134_3DD34(GAMEMES* gMes, Gfx**);
s32 func_8003D4DC_3E0DC(GAMEMES* gMes, Gfx**);
s32 func_8003D890_3E490(GAMEMES* gMes, Gfx**);
s32 func_8003DC88_3E888(GAMEMES* gMes, Gfx**);
s32 func_8003DE60_3EA60(GAMEMES* gMes, Gfx**);
s32 func_8003E4A4_3F0A4(GAMEMES* gMes, Gfx**);
s32 func_8003EBC8_3F7C8(GAMEMES* gMes, Gfx**);
s32 func_8003EE98_3FA98(GAMEMES* gMes, Gfx**);
s32 GMesTimerExec(GAMEMES* gMes, Gfx**);
s32 func_8003F604_40204(GAMEMES* gMes, Gfx**);
s32 func_8003FD34_40934(GAMEMES* gMes, Gfx**);
s32 func_8003FFD0_40BD0(GAMEMES* gMes, Gfx**);
s32 func_80040290_40E90(GAMEMES* gMes, Gfx**);
s32 func_800407B8_413B8(GAMEMES* gMes, Gfx**);
s32 func_80040CF4_418F4(GAMEMES* gMes, Gfx**);
s32 func_80041700_42300(GAMEMES* gMes, Gfx**);
s32 func_80041B68_42768(GAMEMES* gMes, Gfx**);
s32 func_80042AC8_436C8(GAMEMES* gMes, Gfx**);
s32 func_800440D4_44CD4(GAMEMES* gMes, Gfx**);
s32 func_800448C0_454C0(GAMEMES* gMes, Gfx**);
s32 func_800452C4_45EC4(void);
s32 func_80045314_45F14(void);

extern s8 D_800B1A50_B2650;
extern u8 gMesCloseF;
extern u8 D_800B1A52_B2652;
extern s8 gMesTimerId;
extern s16 D_800B1A54_B2654;
extern s16 D_800B1A58_B2658[];
extern s16 D_800B1A70_B2670[];
extern s16 D_800B1A88_B2688[];
extern s16 D_800B1AC0_B26C0[];
extern s16 D_800B1AF8_B26F8[];
extern s16 D_800B1B30_B2730[];
extern s16 D_800B1B50_B2750[];
extern s16 D_800B1B70_B2770[];
extern GAMEMES gMesData[];
extern s32 D_800CE200_CEE00;

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80036610_37210);

void func_8003661C_3721C(void) {
    s16 i;

    D_800B1A50_B2650 = 0;
    for (i = 0; i < 8; i++) {
        gMesData[i].mesNo = 0;
    }
    for (i = 0; i < 9; i++) {
        D_800B1A58_B2658[i] = D_800B1A70_B2670[i] = -1;
    }
    for (i = 0; i < 27; i++) {
        D_800B1A88_B2688[i] = D_800B1AC0_B26C0[i] = D_800B1AF8_B26F8[i] = -1;
    }
    for (i = 0; i < 16; i++) {
        D_800B1B30_B2730[i] = D_800B1B50_B2750[i] = -1;
    }
    for (i = 0; i < 37; i++) {
        D_800B1B70_B2770[i] = -1;
    }
    gMesCloseF = FALSE;
    gMesTimerId = -1;
    D_800B1A52_B2652 = 0;
}

void GMesExec(Gfx** arg0) {
    s16 result = FALSE;
    s16 i, j;

    if (HmfPauseF != 0 && !gMesCloseF) {
        return;
    }
    for (i = 0; i < 8; i++) {
        if (gMesData[i].stat != GMES_STAT_NONE) {
            GAMEMES* gMes = &gMesData[i];

            switch (gMes->mesNo) {
                case GMES_MES_0:
                    result = func_80037574_38174(gMes, arg0);
                    break;
                case GMES_MES_1:
                    result = func_80037878_38478(gMes, arg0);
                    break;
                case GMES_MES_2:
                    result = func_80037C44_38844(gMes, arg0);
                    break;
                case GMES_MES_3:
                    result = func_8003843C_3903C(gMes, arg0);
                    break;
                case GMES_MES_4:
                    result = func_80038934_39534(gMes, arg0);
                    break;
                case GMES_MES_5:
                    result = func_80038D78_39978(gMes, arg0);
                    break;
                case GMES_MES_MG_START:
                    result = func_800392AC_39EAC(gMes, arg0);
                    break;
                case GMES_MES_7:
                    result = func_8003966C_3A26C(gMes, arg0);
                    break;
                case GMES_MES_8:
                    result = func_80039A6C_3A66C(gMes, arg0);
                    break;
                case GMES_MES_9:
                    result = func_80039E80_3AA80(gMes, arg0);
                    break;
                case GMES_MES_10:
                    result = func_8003A2EC_3AEEC(gMes, arg0);
                    break;
                case GMES_MES_11:
                    result = func_8003B14C_3BD4C(gMes, arg0);
                    break;
                case GMES_MES_12:
                    result = func_8003B7E8_3C3E8(gMes, arg0);
                    break;
                case GMES_MES_13:
                    result = func_8003BB84_3C784(gMes, arg0);
                    break;
                case GMES_MES_14:
                    result = func_8003C248_3CE48(gMes, arg0);
                    break;
                case GMES_MES_15:
                    result = func_8003C644_3D244(gMes, arg0);
                    break;
                case GMES_MES_16:
                    result = func_8003CA24_3D624(gMes, arg0);
                    break;
                case GMES_MES_MG_FINISH:
                    result = func_8003CE20_3DA20(gMes, arg0);
                    break;
                case GMES_MES_18:
                    result = func_8003D134_3DD34(gMes, arg0);
                    break;
                case GMES_MES_19:
                    result = func_8003D4DC_3E0DC(gMes, arg0);
                    break;
                case GMES_MES_20:
                    result = func_8003D890_3E490(gMes, arg0);
                    break;
                case GMES_MES_21:
                    result = func_8003DC88_3E888(gMes, arg0);
                    break;
                case GMES_MES_MG_LOSER:
                    result = func_8003E4A4_3F0A4(gMes, arg0);
                    break;
                case GMES_MES_24:
                    result = func_8003EBC8_3F7C8(gMes, arg0);
                    break;
                case GMES_MES_25:
                    result = func_8003EE98_3FA98(gMes, arg0);
                    break;
                case GMES_MES_TIMER:
                    result = GMesTimerExec(gMes, arg0);
                    break;
                case GMES_MES_MG_RECORD:
                    result = func_8003F604_40204(gMes, arg0);
                    break;
                case GMES_MES_31:
                    result = func_8003FD34_40934(gMes, arg0);
                    break;
                case GMES_MES_33:
                    result = func_8003FFD0_40BD0(gMes, arg0);
                    break;
                case GMES_MES_29:
                    result = func_80040290_40E90(gMes, arg0);
                    break;
                case GMES_MES_28:
                    result = func_800407B8_413B8(gMes, arg0);
                    break;
                case GMES_MES_MG_DRAW:
                    result = func_80041700_42300(gMes, arg0);
                    break;
                case GMES_MES_MG_WINNER:
                    result = func_8003DE60_3EA60(gMes, arg0);
                    break;
                case GMES_MES_MG_WINNERS_2:
                    result = func_80040CF4_418F4(gMes, arg0);
                    break;
                case GMES_MES_MG_WINNERS_3:
                    result = func_80041B68_42768(gMes, arg0);
                    break;
                case GMES_MES_MG_WINNERS_4:
                    result = func_80042AC8_436C8(gMes, arg0);
                    break;
                case GMES_MES_36:
                    result = func_800440D4_44CD4(gMes, arg0);
                    break;
                case GMES_MES_37:
                    result = func_800448C0_454C0(gMes, arg0);
                    break;
            }
            gMes->unk04++;
            if (gMes->unk04 >= 0x4000) {
                gMes->unk04 = 0x2000;
            }
            if (result == FALSE) {
                gMes->stat = GMES_STAT_NONE;
                if (D_800B1A52_B2652 == 0) {
                    for (j = 0; j < GMES_MAX; j++) {
                        if (gMesData[j].stat != GMES_STAT_NONE && gMesData[j].mesNo != GMES_MES_TIMER) {
                            break;
                        }
                    }
                    if (j == GMES_MAX) {
                        func_80037258_37E58();
                    }
                }
            }
        }
    }
}

s16 GMesCreate(s16 mesNo, ...) {
    GAMEMES* gMes;
    va_list args;
    s32 chr;
    s16 mesId;
    s16 i;

    va_start(args, mesNo);
    for (mesId = 0; mesId < GMES_MAX; mesId++) {
        if (gMesData[mesId].stat == GMES_STAT_NONE) {
            break;
        }
    }
    if (mesId == GMES_MAX) {
        return GMES_ID_NONE;
    }
    gMes = &gMesData[mesId];
    gMes->stat = GMES_STAT_EXIST;
    gMes->mesNo = mesNo;
    gMes->unk04 = 0;
    gMes->unk60 = 160.0f;
    gMes->unk64 = 120.0f;
    gMes->unk6C = 1.0f;
    gMes->unk68 = 1.0f;
    gMes->unk70 = 0;
    gMes->unk03 = 0xFF;
    gMes->unk06 = 0x3C;
    gMes->unk0E = 0;
    gMes->unk0C = 0;
    gMes->unk0A = 0;
    gMes->unk08 = 0;
    gMes->unk10 = gMes->unk14 = 0.0f;
    for (i = 0; i < GMES_STRMAX; i++) {
        gMes->strSprId[i] = gMes->strGId[i] = HUSPR_NONE;
    }
    switch (mesNo) {
        case GMES_MES_0:
        case GMES_MES_1:
        case GMES_MES_2:
        case GMES_MES_11:
        case GMES_MES_12:
        case GMES_MES_13:
        case GMES_MES_31:
        case GMES_MES_33:
            gMes->unk06 = 0x2D;
            break;
        case GMES_MES_MG_DRAW:
            gMes->unk06 = 0x82;
            break;
        case GMES_MES_MG_RECORD:
            gMes->unk60 = 160.0f;
            gMes->unk64 = 180.0f;
            break;
        case GMES_MES_MG_WINNER:
            gMes->unk0E = chr = va_arg(args, s32);
            gMes->unk64 = func_800452C4_45EC4();
            gMes->unk06 = 0x78;
            break;
        case GMES_MES_29:
        case GMES_MES_36:
        case GMES_MES_37:
            gMes->unk06 = 0x78;
            break;
        case GMES_MES_MG_LOSER:
            gMes->unk0E = chr = va_arg(args, s32);
            break;
        case GMES_MES_24:
        case GMES_MES_25:
            gMes->unk1C = va_arg(args, s32);
            gMes->unk60 = va_arg(args, s32);
            gMes->unk64 = va_arg(args, s32);
            gMes->unk68 = va_arg(args, f64);
            gMes->unk6C = va_arg(args, f64);
            gMes->unk02 = va_arg(args, s32);
            break;
        case GMES_MES_TIMER:
            gMesTimerId = mesId;
            gMes->unk08 = va_arg(args, s32);
            gMes->unk60 = va_arg(args, s32);
            gMes->unk64 = va_arg(args, s32);
            gMes->unk60 = 160.0f;
            gMes->unk64 = 28.0f;
            break;
        case GMES_MES_MG_WINNERS_2:
            gMes->unk0C = chr = va_arg(args, s32);
            gMes->unk0E = chr = va_arg(args, s32);
            gMes->unk06 = 0x78;
            break;
        case GMES_MES_MG_WINNERS_3:
            gMes->unk0A = chr = va_arg(args, s32);
            gMes->unk0C = chr = va_arg(args, s32);
            gMes->unk0E = chr = va_arg(args, s32);
            gMes->unk64 = func_80045314_45F14();
            gMes->unk06 = 0x78;
            break;
        case GMES_MES_MG_WINNERS_4:
            gMes->unk08 = chr = va_arg(args, s32);
            gMes->unk0A = chr = va_arg(args, s32);
            gMes->unk0C = chr = va_arg(args, s32);
            gMes->unk0E = chr = va_arg(args, s32);
            gMes->unk06 = 0x78;
            break;
    }
    D_800B1A54_B2654 = 0x5A;
    va_end(args);
    return mesId;
}

s32 GMesStatGet(void) {
    s16 stat;
    s16 i;

    for (i = 0, stat = GMES_STAT_NONE; i < GMES_MAX; i++) {
        if (gMesData[i].mesNo != GMES_MES_TIMER) {
            stat |= gMesData[i].stat;
        }
    }
    return stat;
}

INCLUDE_ASM("asm/nonmatchings/gamemes", func_800370A4_37CA4);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_800370D0_37CD0);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80037114_37D14);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003714C_37D4C);

void GMesClose(void) {
    gMesTimerId = -1;
    gMesCloseF = TRUE;
    GMesExec(&gMainGfxPos);
    gMesCloseF = FALSE;
    func_80037258_37E58();
    D_800B1A52_B2652 = 0;
}

INCLUDE_ASM("asm/nonmatchings/gamemes", func_800371DC_37DDC);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003724C_37E4C);

void func_80037258_37E58(void) {
    s16 i;

    for (i = 0; i < 9; i++) {
        if (i == 2 && gMesTimerId != -1) {
            continue;
        }
        if (D_800B1A58_B2658[i] != -1) {
            HuSprKill(D_800B1A58_B2658[i]);
        }
        if (D_800B1A70_B2670[i] != -1) {
            HuSprKill(D_800B1A70_B2670[i]);
        }
        D_800B1A58_B2658[i] = D_800B1A70_B2670[i] = -1;
    }
    for (i = 0; i < 27; i++) {
        if (D_800B1A88_B2688[i] != -1) {
            HuSprKill(D_800B1A88_B2688[i]);
        }
        if (D_800B1AC0_B26C0[i] != -1) {
            HuSprKill(D_800B1AC0_B26C0[i]);
        }
        if (D_800B1AF8_B26F8[i] != -1) {
            HuSprKill(D_800B1AF8_B26F8[i]);
        }
        D_800B1A88_B2688[i] = D_800B1AC0_B26C0[i] = D_800B1AF8_B26F8[i] = -1;
    }
    for (i = 0; i < 16; i++) {
        if (D_800B1B30_B2730[i] != -1) {
            HuSprKill(D_800B1B30_B2730[i]);
        }
        if (D_800B1B50_B2750[i] != -1) {
            HuSprKill(D_800B1B50_B2750[i]);
        }
        D_800B1B30_B2730[i] = D_800B1B50_B2750[i] = -1;
    }
    for (i = 0; i < 37; i++) {
        if (D_800B1B70_B2770[i] != -1) {
            HuSprKill(D_800B1B70_B2770[i]);
        }
        D_800B1B70_B2770[i] = -1;
    }
}

void GMesSprKill(GAMEMES* gMes) {
    s16 i;

    for (i = 0; i < 16; i++) {
        if (gMes->strGId[i] != -1) {
            HuSprGrpKill(gMes->strGId[i]);
        }
        if (gMes->strSprId[i] != -1) {
            HuSprKill(gMes->strSprId[i]);
        }
    }
}

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A7450_A8050);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80037574_38174);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80037878_38478);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80037C44_38844);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80038208_38E08);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003843C_3903C);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80038934_39534);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80038D78_39978);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_800392AC_39EAC);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003966C_3A26C);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80039A6C_3A66C);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80039E80_3AA80);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003A2EC_3AEEC);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003A308_3AF08);

void func_8003A37C_3AF7C(GAMEMES* gMes, const char*, s32, s32, s32);
INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003A37C_3AF7C);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003A3C4_3AFC4);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003A81C_3B41C);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003A9C8_3B5C8);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003AC9C_3B89C);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003AE44_3BA44);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003AE9C_3BA9C);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003B128_3BD28);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003B14C_3BD4C);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003B170_3BD70);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003B4D8_3C0D8);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003B7E8_3C3E8);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003BB84_3C784);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003C058_3CC58);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003C248_3CE48);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003C644_3D244);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003CA24_3D624);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003CE20_3DA20);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003D134_3DD34);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003D4DC_3E0DC);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003D890_3E490);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003DC88_3E888);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003DCA4_3E8A4);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A76F8_A82F8);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A7700_A8300);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A7708_A8308);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A7714_A8314);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A771C_A831C);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A7724_A8324);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A772C_A832C);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A7734_A8334);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A773C_A833C);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A7744_A8344);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003DE60_3EA60);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003E4A4_3F0A4);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003EBC8_3F7C8);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003EE98_3FA98);

s32 GMesTimerExec(GAMEMES* gMes, Gfx** arg1) {
    f32 temp_f22;
    u8 temp_s2;
    u8 temp_s0;

    if (gMes->unk04 == 0) {
        func_8003A37C_3AF7C(gMes, "99", 0, -1, -1);
        func_80054904_55504(gMes->strGId[0], 0, gMes->unk60, gMes->unk64);
        func_80055458_56058(gMes->strGId[0], 1, 0x100);
        func_80055458_56058(gMes->strGId[0], 2, 0x100);
        gMes->unk0A = 0;
    }
    temp_s2 = gMes->unk08 % 100;
    temp_s0 = temp_s2 / 10;
    if (temp_s0 == 0) {
        HuSprAttrSet(gMes->strGId[0], 1, 0x8000);
    } else {
        HuSprAttrReset(gMes->strGId[0], 1, 0x8000);
    }
    func_80055140_55D40(gMes->strGId[0], 1, temp_s0, 0);
    func_800550F4_55CF4(gMes->strGId[0], 1, 1);
    temp_s0 = temp_s2 % 10;
    func_80055140_55D40(gMes->strGId[0], 2, temp_s0, 0);
    func_800550F4_55CF4(gMes->strGId[0], 2, 1);
    switch (gMes->unk0A) {
        case 0:
            if (gMes->unk04 < 14) {
                temp_f22 = HuMathSin(gMes->unk04 * 10.0f) * 5.0f + (1.0f - HuMathSin(130.0f) * 5.0f);
                HuSprScaleSet(gMes->strGId[0], 1, temp_f22, temp_f22);
                HuSprScaleSet(gMes->strGId[0], 2, temp_f22, temp_f22);
            } else {
                gMes->unk0A = 1;
            }
            break;
        case 1:
            if (gMes->unk0E != gMes->unk08 && gMes->unk08 < 6) {
                gMes->unk0C = 0;
                if (gMes->unk08 != 0) {
                    gMes->unk0A = 3;
                    HuAudFXPlay(8);
                }
            } else {
                func_80055458_56058(gMes->strGId[0], 1, 0x100);
                func_80055458_56058(gMes->strGId[0], 2, 0x100);
            }
            break;
        case 2:
            if (gMes->unk0C < 10) {
                func_80055458_56058(gMes->strGId[0], 1, 230 - gMes->unk0C * 23);
                func_80055458_56058(gMes->strGId[0], 2, 230 - gMes->unk0C * 23);
            } else {
                gMes->unk0A = 1;
                gMes->stat = GMES_STAT_KILL;
            }
            gMes->unk0C++;
            break;
        case 3:
            if (gMes->unk0C < 11) {
                temp_f22 = 1.0f + HuMathSin(gMes->unk0C * 18.0f);
                HuSprScaleSet(gMes->strGId[0], 1, temp_f22, temp_f22);
                HuSprScaleSet(gMes->strGId[0], 2, temp_f22, temp_f22);
                temp_f22 = 230.0f - HuMathSin(gMes->unk0C * 18.0f) * 60.0f;
                func_80055458_56058(gMes->strGId[0], 1, temp_f22);
                func_80055458_56058(gMes->strGId[0], 2, temp_f22);
            } else {
                gMes->unk0A = 1;
            }
            gMes->unk0C++;
            break;
    }
    gMes->unk0E = gMes->unk08;
    if (gMesCloseF || gMes->stat == GMES_STAT_KILL) {
        GMesSprKill(gMes);
        gMesTimerId = -1;
        return FALSE;
    }
    return TRUE;
}

// GMesUpdate? GMesTimerUpdate? GMesTimerSet?
void func_8003F578_40178(s16 arg0) {
    if (gMesTimerId < 0 || arg0 < 0) {
        return;
    }
    gMesData[gMesTimerId].unk08 = arg0;
}

// GMesKill? GMesTimerKill?
void func_8003F5C0_401C0(void) {
    if (gMesTimerId < 0) {
        return;
    }
    gMesData[gMesTimerId].unk0A = 2;
    gMesData[gMesTimerId].unk0C = 0;
}

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003F604_40204);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003FD34_40934);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_8003FFD0_40BD0);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80040290_40E90);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_800407B8_413B8);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A77BC_A83BC);

INCLUDE_RODATA("asm/nonmatchings/gamemes", jtbl_800A77C0_A83C0);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80040CF4_418F4);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80041700_42300);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A7810_A8410);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A7830_A8430);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80041B68_42768);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80042AC8_436C8);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A78C8_A84C8);

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A78CC_A84CC);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_800440D4_44CD4);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_800448C0_454C0);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_80045010_45C10);

INCLUDE_ASM("asm/nonmatchings/gamemes", func_800450B8_45CB8);

s32 func_80045208_45E08(void* arg0, void* arg1);
INCLUDE_ASM("asm/nonmatchings/gamemes", func_80045208_45E08);

s32 func_800452A0_45EA0(void* arg0, void* arg1) {
    return func_80045208_45E08(arg0, arg1);
}

void func_800452BC_45EBC(void) {
}

INCLUDE_RODATA("asm/nonmatchings/gamemes", D_800A78F4_A84F4);

INCLUDE_RODATA("asm/nonmatchings/gamemes", jtbl_800A78F8_A84F8);

s32 func_800452C4_45EC4(void) {
    switch (D_800CE200_CEE00) {
        case 0x1:
        case 0x2:
        case 0x6:
        case 0x1B:
        case 0x1D:
        case 0x1E:
        case 0x22:
        case 0x23:
        case 0x24:
        case 0x34:
        case 0x38:
        case 0x41:
            return 120;
        case 0xF:
            return 190;
        case 0x13:
        case 0x27:
        case 0x2C:
        case 0x43:
            return 160;
        default:
            return 180;
    }
}

s32 func_80045314_45F14(void) {
    switch (D_800CE200_CEE00) {
        case 2:
            return 20;
        case 3:
            return -20;
        default:
            return 0;
    }
}
