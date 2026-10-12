#include "overlays/ovl_36.h"
#include "overlays/minigame.h"
#include "gcc/memory.h"
#include "game/camera.h"
#include "game/gamemes.h"
#include "game/gamework_data.h"
#include "game/hmflight.h"
#include "game/hmfman.h"
#include "game/wipe.h"
#include "mallocblock.h"
#include "include_asm.h"

#define PLAYERS_TOTAL 2

// C1F0
void func_8000B5F0_main(u8 arg0);
s32 func_8000B710_main(s32 arg0);

// 14EA0
void func_800142A0_main(s32);

// 20A20
void Hu3DAnimInit(s32);

// unknown
extern u16 D_800D530C_main;

enum {
    FGRP_CAMERA
};

typedef struct {
    /* 0x00 */ omObjData *unk00;
    /* 0x04 */ char unk04[0x86];
    /* 0x8A */ s16 unk8A;
    /* 0x8C */ omObjData *unk8C;
    /* 0x90 */ char unk90[0x64];
} PlayerView; // Size 0xF4

typedef struct {
    /* 0x000 */ PlayerView *views;
    /* 0x004 */ char unk04[0x1A0];
    /* 0x1A4 */ u8 unk1A4[0x30]; // mtx?
} MinigameData;                  // Size 0x1D4

typedef struct {
    /* 0x00 */ omObjData *unk00;
    /* 0x04 */ char unk04[4];
    /* 0x08 */ s32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ char unk10[0xC];
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ char unk1E[0x6E];
} D_801137C8_motor_rooter_Struct; // Size 0x8C

void m254_InitEnvironment(void);
void m254_CreateMinigame(void);
void m254_CheckExitRequest(omObjData *object);
void m254_WaitExitWipeOut(omObjData *object);
void m254_ExitOverlay(omObjData *object);
void func_80106044_motor_rooter(omObjData *object);
void func_80106298_motor_rooter(omObjData *object);
void func_801062BC_motor_rooter(omObjData *object);
void func_80106508_motor_rooter(omObjData *object);
void func_80106998_motor_rooter(omObjData *object);
void func_80106BAC_motor_rooter(omObjData *object);
void func_80107210_motor_rooter(omObjData *object);
void func_801079E8_motor_rooter(omObjData *object);
void m254_InitCamera(FuncContext *ctx);
void func_801082E0_motor_rooter(FuncContext *ctx);
void func_80108BF0_motor_rooter(FuncContext *ctx);
void func_8010CD84_motor_rooter(void *, s32);
s16 func_8010D03C_motor_rooter(f32);
void func_8010D0AC_motor_rooter(f32 *, s16, f32);
void func_8010D2E4_motor_rooter(s32);

// BSS
extern f32 *D_801137C0_motor_rooter;
extern MinigameData *m254_minigame; // D_801137C4_motor_rooter
extern D_801137C8_motor_rooter_Struct *D_801137C8_motor_rooter;
extern s16 D_801137CC_motor_rooter;
extern s16 D_801137CE_motor_rooter;
extern s16 m254_playerId[]; // D_801137D4_motor_rooter

extern s32 D_80111550_motor_rooter;
extern s32 D_8011245C_motor_rooter;

extern s16 D_801135E0_motor_rooter[];
extern s16 D_801135EC_motor_rooter[];
extern s16 D_801135FC_motor_rooter[];

void m254_OverlayMain(void) {
    m254_InitEnvironment();
}

void m254_InitEnvironment(void) {
    omObjData *temp_v0;

    Hu3DAnimInit(50);
    func_800142A0_main(0x30);
    omInitObjMan(50, 0);
    func_8004A208_main();
    temp_v0 = omAddObj(0x7FDA, 0, 0, -1, omOutViewMulti);
    temp_v0->work[0] = 2;
    omSetStatBit(temp_v0, 0xA0);
    HmfLightColorSet(0, 0xFF, 0xFF, 0xFF);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    HmfLightDirSet(1, -56.0f, 50.0f, 56.0f);
    func_8000B5F0_main(2);
    func_8000B710_main(2);
    ScissorSet(0, 0.0f, 0.0f, 152.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 320.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 60.0f, 40.0f, 4000.0f);
    ScissorSet(1, 168.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 960.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(1, 60.0f, 40.0f, 4000.0f);
    func_8001F38C_main(0xFF, 0xFF, 0xFF);
    D_800EC1B8_minigame = 0;
    D_800EC280_minigame = 0;
    D_800EBE28_minigame = 0;
    m254_CreateSystem();
    m254_CreateMinigame();
    omAddObj(100, 0, 0, -1, func_80106044_motor_rooter);
    omAddObj(1000, 0, 0, -1, m254_CheckExitRequest);
    func_80045010_main(D_801135E0_motor_rooter, 1);
    func_80045010_main(D_801135EC_motor_rooter, 1);
    func_80045010_main(D_801135FC_motor_rooter, 1);
}

void m254_CreateMinigame(void) {
    s16 player1Set = FALSE;
    s16 player2Set = FALSE;
    s16 i;

    for (i = 0; i < 4; i++) {
        if (GwPlayer[i].group == 0) {
            if (!player1Set) {
                m254_playerId[0] = i;
                player1Set = TRUE;
            }
        } else if (GwPlayer[i].group == 1) {
            if (!player2Set) {
                m254_playerId[1] = i;
                player2Set = TRUE;
            }
        }
    }
    m254_minigame = HuMemAllocTag(sizeof(MinigameData), 31000);
    memset(m254_minigame, 0, sizeof(MinigameData));
    m254_minigame->views = HuMemAllocTag(PLAYERS_TOTAL * sizeof(PlayerView), 31000);
    memset(m254_minigame->views, 0, PLAYERS_TOTAL * sizeof(PlayerView));
    D_801137CE_motor_rooter = (rand16() % 201) / 100;
    switch (D_801137CE_motor_rooter) {
        case 0:
            D_801137CC_motor_rooter = 280;
            func_8010CD84_motor_rooter(&D_80111550_motor_rooter, 321);
            break;
        case 1:
            D_801137CC_motor_rooter = 300;
            func_8010CD84_motor_rooter(&D_8011245C_motor_rooter, 341);
            break;
        default:
            D_801137CC_motor_rooter = 280;
            func_8010CD84_motor_rooter(&D_80111550_motor_rooter, 321);
            D_801137CE_motor_rooter = 0;
            break;
    }
    func_8010D2E4_motor_rooter(0);
    D_801137C8_motor_rooter = HuMemAllocTag(2 * sizeof(D_801137C8_motor_rooter_Struct), 31000); // PLAYERS_TOTAL?
    memset(D_801137C8_motor_rooter, 0, 2 * sizeof(D_801137C8_motor_rooter_Struct));
}

void m254_CheckExitRequest(omObjData *object) {
    if (D_800D530C_main == 1) {
        WipeCreateOut(0, 20);
        object->func = m254_WaitExitWipeOut;
    }
}

void m254_WaitExitWipeOut(omObjData *object) {
    if (WipeStatGet() == 0) {
        object->func = m254_ExitOverlay;
    }
}

void m254_ExitOverlay(omObjData *object) {
    osViBlack(0);
    omOvlReturnEx(1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80105F04_motor_rooter);

void func_80106044_motor_rooter(omObjData *object) {
    s16 i;

    func_8001EF24_main(0x3CA, 1000, 0xFF, 0xFF, 0xFF);
    func_800E18D8_minigame();
    func_800E19F0_minigame(1);
    for (i = 0; i < 2; i++) {
        D_800EC1C0_minigame[i] = omAddObj(10, 2, 0, -1, func_801062BC_motor_rooter);
        m254_minigame->views[i].unk00 = omAddObj(100, 21, 0, -1, func_80106508_motor_rooter);
        m254_minigame->views[i].unk8C = omAddObj(200, 15, 0, -1, func_80106998_motor_rooter);
        omAddObj(500, 1, 0, -1, func_80107210_motor_rooter);
        omAddObj(800, 5, 0, -1, func_801079E8_motor_rooter);
        D_800EC598_minigame[i] = D_801137C8_motor_rooter[i].unk00 = omAddObj(300, 11, 40, -1, func_80106BAC_motor_rooter);
    }
    memset(m254_minigame->unk1A4, 0, sizeof(m254_minigame->unk1A4));
    m254_SetFunc(FGRP_CAMERA, 0, -1, NULL, m254_InitCamera, 0, FALSE);
    m254_SetFunc(1, 0, -1, NULL, func_80108BF0_motor_rooter, 0, FALSE);
    WipeCreateIn(0xFF, 0x10);
    object->func = func_80106298_motor_rooter;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80106298_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801062BC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801064EC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80106508_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80106968_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80106998_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80106B7C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80106BAC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801070CC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80107210_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801076AC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801079E8_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80107D50_motor_rooter);

void m254_InitCamera(FuncContext *ctx) {
    s16 i;

    for (i = 0; i < 2; i++) {
        CZoomM[i] = 100.0f;
        CenterM[i].x = D_801137C0_motor_rooter[0];
        CenterM[i].y = D_801137C0_motor_rooter[1];
        CenterM[i].z = D_801137C0_motor_rooter[2];
        CRotM[i].x = D_801137C0_motor_rooter[3] - 180.0f;
        CRotM[i].y = D_801137C0_motor_rooter[4];
        CRotM[i].z = D_801137C0_motor_rooter[5];
    }
    m254_ResetFunc(FGRP_CAMERA, ctx);
    m254_SetFunc(FGRP_CAMERA, 0, -1, NULL, func_801082E0_motor_rooter, 0, FALSE);
}

void func_801082E0_motor_rooter(FuncContext *ctx) {
    PlayerView *view;
    D_801137C8_motor_rooter_Struct *var_s1;
    f32 sp10[7];
    s16 temp_v0;
    s16 i;

    view = m254_minigame->views;
    var_s1 = D_801137C8_motor_rooter;
    for (i = 0; i < 2; i++, var_s1++, view++) {
        if (var_s1->unk08 & 0x80) {
            continue;
        }
        temp_v0 = func_8010D03C_motor_rooter(var_s1->unk0C);
        func_8010D0AC_motor_rooter(sp10, temp_v0, var_s1->unk0C);
        CenterM[i].x = sp10[1];
        CenterM[i].y = sp10[2];
        CenterM[i].z = sp10[3];
        CRotM[i].x = sp10[4] - 180.0f;
        CRotM[i].y = sp10[5];
        CRotM[i].z = sp10[6];
        if (CRotM[i].x > 360.0f) {
            CRotM[i].x -= 360.0f;
        } else if (CRotM[i].x < 0.0f) {
            CRotM[i].x += 360.0f;
        }
        if (CRotM[i].y > 360.0f) {
            CRotM[i].y -= 360.0f;
        } else if (CRotM[i].y < 0.0f) {
            CRotM[i].y += 360.0f;
        }
        var_s1->unk1C = temp_v0 + 1;
        view->unk8A = temp_v0;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80108514_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801087C0_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801089B8_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80108BF0_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80108E6C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80108FDC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80109134_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801091A0_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010961C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010972C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80109C94_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80109EFC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010A174_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010A440_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010ABC4_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010AF0C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010B394_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010B970_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010BB78_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010BCD0_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010BDE4_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010BDF0_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010C084_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010C44C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010C824_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010CB2C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010CD84_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010D03C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010D0AC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010D1A8_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010D2E4_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010DC3C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010DD10_motor_rooter);
