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
void func_8000B5F0_C1F0(u8 arg0);
s32 func_8000B710_C310(s32 arg0);

// 14EA0
void func_800142A0_14EA0(s32);

// 20A20
void Hu3DAnimInit(s32);

// unknown
extern u16 D_800D530C_D5F0C;

enum {
    FGRP_CAMERA
};

typedef struct {
    /* 0x00 */ omObjData* unk00;
    /* 0x04 */ char unk04[0x86];
    /* 0x8A */ s16 unk8A;
    /* 0x8C */ omObjData* unk8C;
    /* 0x90 */ char unk90[0x64];
} PlayerView; // Size 0xF4

typedef struct {
    /* 0x000 */ PlayerView* views;
    /* 0x004 */ char unk04[0x1A0];
    /* 0x1A4 */ u8 unk1A4[0x30]; // mtx?
} MinigameData; // Size 0x1D4

typedef struct {
    /* 0x00 */ omObjData* unk00;
    /* 0x04 */ char unk04[4];
    /* 0x08 */ s32 unk08;
    /* 0x0C */ f32 unk0C;
    /* 0x10 */ char unk10[0xC];
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ char unk1E[0x6E];
} D_801137C8_2AF258_Struct; // Size 0x8C

void m254_InitEnvironment(void);
void m254_CreateMinigame(void);
void m254_CheckExitRequest(omObjData* object);
void m254_WaitExitWipeOut(omObjData* object);
void m254_ExitOverlay(omObjData* object);
void func_80106044_2A1AD4_motor_rooter(omObjData* object);
void func_80106298_2A1D28_motor_rooter(omObjData* object);
void func_801062BC_2A1D4C_motor_rooter(omObjData* object);
void func_80106508_2A1F98_motor_rooter(omObjData* object);
void func_80106998_2A2428_motor_rooter(omObjData* object);
void func_80106BAC_2A263C_motor_rooter(omObjData* object);
void func_80107210_2A2CA0_motor_rooter(omObjData* object);
void func_801079E8_2A3478_motor_rooter(omObjData* object);
void m254_InitCamera(FuncContext* ctx);
void func_801082E0_2A3D70_motor_rooter(FuncContext* ctx);
void func_80108BF0_2A4680_motor_rooter(FuncContext* ctx);
void func_8010CD84_2A8814_motor_rooter(void*, s32);
s16 func_8010D03C_2A8ACC_motor_rooter(f32);
void func_8010D0AC_2A8B3C_motor_rooter(f32*, s16, f32);
void func_8010D2E4_2A8D74_motor_rooter(s32);

// BSS
extern f32* D_801137C0_2AF250_motor_rooter;
extern MinigameData* m254_minigame; // D_801137C4_2AF254_motor_rooter
extern D_801137C8_2AF258_Struct* D_801137C8_2AF258_motor_rooter;
extern s16 D_801137CC_2AF25C_motor_rooter;
extern s16 D_801137CE_2AF25E_motor_rooter;
extern s16 m254_playerId[]; // D_801137D4_2AF264_motor_rooter

extern s32 D_80111550_2ACFE0_motor_rooter;
extern s32 D_8011245C_2ADEEC_motor_rooter;

extern s16 D_801135E0_2AF070_motor_rooter[];
extern s16 D_801135EC_2AF07C_motor_rooter[];
extern s16 D_801135FC_2AF08C_motor_rooter[];

void m254_OverlayMain(void) {
    m254_InitEnvironment();
}

void m254_InitEnvironment(void) {
    omObjData* temp_v0;

    Hu3DAnimInit(50);
    func_800142A0_14EA0(0x30);
    omInitObjMan(50, 0);
    func_8004A208_4AE08();
    temp_v0 = omAddObj(0x7FDA, 0, 0, -1, omOutViewMulti);
    temp_v0->work[0] = 2;
    omSetStatBit(temp_v0, 0xA0);
    HmfLightColorSet(0, 0xFF, 0xFF, 0xFF);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    HmfLightDirSet(1, -56.0f, 50.0f, 56.0f);
    func_8000B5F0_C1F0(2);
    func_8000B710_C310(2);
    ScissorSet(0, 0.0f, 0.0f, 152.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 320.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 60.0f, 40.0f, 4000.0f);
    ScissorSet(1, 168.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 960.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(1, 60.0f, 40.0f, 4000.0f);
    func_8001F38C_1FF8C(0xFF, 0xFF, 0xFF);
    D_800EC1B8_BED38_minigame = 0;
    D_800EC280_BEE00_minigame = 0;
    D_800EBE28_BE9A8_minigame = 0;
    m254_CreateSystem();
    m254_CreateMinigame();
    omAddObj(100, 0, 0, -1, func_80106044_2A1AD4_motor_rooter);
    omAddObj(1000, 0, 0, -1, m254_CheckExitRequest);
    func_80045010_45C10(D_801135E0_2AF070_motor_rooter, 1);
    func_80045010_45C10(D_801135EC_2AF07C_motor_rooter, 1);
    func_80045010_45C10(D_801135FC_2AF08C_motor_rooter, 1);
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
    D_801137CE_2AF25E_motor_rooter = (rand16() % 201) / 100;
    switch (D_801137CE_2AF25E_motor_rooter) {
        case 0:
            D_801137CC_2AF25C_motor_rooter = 280;
            func_8010CD84_2A8814_motor_rooter(&D_80111550_2ACFE0_motor_rooter, 321);
            break;
        case 1:
            D_801137CC_2AF25C_motor_rooter = 300;
            func_8010CD84_2A8814_motor_rooter(&D_8011245C_2ADEEC_motor_rooter, 341);
            break;
        default:
            D_801137CC_2AF25C_motor_rooter = 280;
            func_8010CD84_2A8814_motor_rooter(&D_80111550_2ACFE0_motor_rooter, 321);
            D_801137CE_2AF25E_motor_rooter = 0;
            break;
    }
    func_8010D2E4_2A8D74_motor_rooter(0);
    D_801137C8_2AF258_motor_rooter = HuMemAllocTag(2 * sizeof(D_801137C8_2AF258_Struct), 31000); // PLAYERS_TOTAL?
    memset(D_801137C8_2AF258_motor_rooter, 0, 2 * sizeof(D_801137C8_2AF258_Struct));
}

void m254_CheckExitRequest(omObjData* object) {
    if (D_800D530C_D5F0C == 1) {
        WipeCreateOut(0, 20);
        object->func = m254_WaitExitWipeOut;
    }
}

void m254_WaitExitWipeOut(omObjData* object) {
    if (WipeStatGet() == 0) {
        object->func = m254_ExitOverlay;
    }
}

void m254_ExitOverlay(omObjData* object) {
    osViBlack(0);
    omOvlReturnEx(1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80105F04_2A1994_motor_rooter);

void func_80106044_2A1AD4_motor_rooter(omObjData* object) {
    s16 i;

    func_8001EF24_1FB24(0x3CA, 1000, 0xFF, 0xFF, 0xFF);
    func_800E18D8_B4458_minigame();
    func_800E19F0_B4570_minigame(1);
    for (i = 0; i < 2; i++) {
        D_800EC1C0_BED40_minigame[i] = omAddObj(10, 2, 0, -1, func_801062BC_2A1D4C_motor_rooter);
        m254_minigame->views[i].unk00 = omAddObj(100, 21, 0, -1, func_80106508_2A1F98_motor_rooter);
        m254_minigame->views[i].unk8C = omAddObj(200, 15, 0, -1, func_80106998_2A2428_motor_rooter);
        omAddObj(500, 1, 0, -1, func_80107210_2A2CA0_motor_rooter);
        omAddObj(800, 5, 0, -1, func_801079E8_2A3478_motor_rooter);
        D_800EC598_BF118_minigame[i] = D_801137C8_2AF258_motor_rooter[i].unk00 = omAddObj(300, 11, 40, -1, func_80106BAC_2A263C_motor_rooter);
    }
    memset(m254_minigame->unk1A4, 0, sizeof(m254_minigame->unk1A4));
    m254_SetFunc(FGRP_CAMERA, 0, -1, NULL, m254_InitCamera, 0, FALSE);
    m254_SetFunc(1, 0, -1, NULL, func_80108BF0_2A4680_motor_rooter, 0, FALSE);
    WipeCreateIn(0xFF, 0x10);
    object->func = func_80106298_2A1D28_motor_rooter;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80106298_2A1D28_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801062BC_2A1D4C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801064EC_2A1F7C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80106508_2A1F98_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80106968_2A23F8_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80106998_2A2428_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80106B7C_2A260C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80106BAC_2A263C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801070CC_2A2B5C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80107210_2A2CA0_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801076AC_2A313C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801079E8_2A3478_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80107D50_2A37E0_motor_rooter);

void m254_InitCamera(FuncContext* ctx) {
    s16 i;

    for (i = 0; i < 2; i++) {
        CZoomM[i] = 100.0f;
        CenterM[i].x = D_801137C0_2AF250_motor_rooter[0];
        CenterM[i].y = D_801137C0_2AF250_motor_rooter[1];
        CenterM[i].z = D_801137C0_2AF250_motor_rooter[2];
        CRotM[i].x = D_801137C0_2AF250_motor_rooter[3] - 180.0f;
        CRotM[i].y = D_801137C0_2AF250_motor_rooter[4];
        CRotM[i].z = D_801137C0_2AF250_motor_rooter[5];
    }
    m254_ResetFunc(FGRP_CAMERA, ctx);
    m254_SetFunc(FGRP_CAMERA, 0, -1, NULL, func_801082E0_2A3D70_motor_rooter, 0, FALSE);
}

void func_801082E0_2A3D70_motor_rooter(FuncContext* ctx) {
    PlayerView* view;
    D_801137C8_2AF258_Struct* var_s1;
    f32 sp10[7];
    s16 temp_v0;
    s16 i;

    view = m254_minigame->views;
    var_s1 = D_801137C8_2AF258_motor_rooter;
    for (i = 0; i < 2; i++, var_s1++, view++) {
        if (var_s1->unk08 & 0x80) {
            continue;
        }
        temp_v0 = func_8010D03C_2A8ACC_motor_rooter(var_s1->unk0C);
        func_8010D0AC_2A8B3C_motor_rooter(sp10, temp_v0, var_s1->unk0C);
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

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80108514_2A3FA4_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801087C0_2A4250_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801089B8_2A4448_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80108BF0_2A4680_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80108E6C_2A48FC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80108FDC_2A4A6C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80109134_2A4BC4_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_801091A0_2A4C30_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010961C_2A50AC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010972C_2A51BC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80109C94_2A5724_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_80109EFC_2A598C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010A174_2A5C04_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010A440_2A5ED0_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010ABC4_2A6654_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010AF0C_2A699C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010B394_2A6E24_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010B970_2A7400_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010BB78_2A7608_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010BCD0_2A7760_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010BDE4_2A7874_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010BDF0_2A7880_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010C084_2A7B14_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010C44C_2A7EDC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010C824_2A82B4_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010CB2C_2A85BC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010CD84_2A8814_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010D03C_2A8ACC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010D0AC_2A8B3C_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010D1A8_2A8C38_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010D2E4_2A8D74_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010DC3C_2A96CC_motor_rooter);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_36_motor_rooter/main", func_8010DD10_2A97A0_motor_rooter);
