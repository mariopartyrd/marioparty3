#include "ultra64.h"
#include "overlays/minigame.h"
#include "game/audio.h"
#include "game/camera.h"
#include "game/esprite.h"
#include "game/gamemes.h"
#include "game/gamework_data.h"
#include "game/hmflight.h"
#include "game/hmfman.h"
#include "game/object.h"
#include "game/pause.h"
#include "game/sprite.h"
#include "game/util.h"
#include "game/wipe.h"
#include "include_asm.h"

#define BSS __attribute__((section(".bss")))

// EXTERN

typedef struct {
    /* 0x00 */ char unk00[4];
    /* 0x04 */ s16 unk04;
    /* 0x06 */ char unk06[0x1E];
} D_800CD1DC_CDDDC_Struct; // Size 0x24

// C1F0
void func_8000B5F0_C1F0(u8 arg0);
void func_8000B710_C310(s32);

// 14EA0
void func_800142A0_14EA0(s32);
s32 func_80016784_17384(s32, s32);
void func_80016FB4_17BB4(s32, s32, s16);
void func_80017320_17F20(s32);
s16 func_80017790_18390(s16 model, s32 arg1, s16 arg2, s32 arg3);
void func_80017954_18554(s32, s32, s16, s32);
s16 func_80017AD8_186D8(s32);
s32 func_80017BB8_187B8(s16, s16);

// 8EA10
f32 atan2d(f32, f32);

// 8EFF0
f32 HuMathCos(f32);

// 8FB20
f32 HuMathSin(f32);

// esprite
extern D_800CD1DC_CDDDC_Struct* D_800CD1DC_CDDDC;

// pad
extern u16 D_800D5558_D6158[];

// save
s32 _CheckFlag(s32);

// unknown
extern s8 D_800CD280_CDE80;
extern u16 D_800D530C_D5F0C;

extern Gfx* gMainGfxPos;

// LOCAL

typedef struct {
    /* 0x00 */ s8 unk00;
    /* 0x01 */ s8 unk01;
    /* 0x02 */ s8 unk02;
    /* 0x03 */ s8 unk03;
    /* 0x04 */ s8 unk04;
    /* 0x05 */ char unk05[1];
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0C */ s32 unk0C;
} D_80115510_285FE0_Struct; // Size 0x10

// Required to align BSS.
typedef struct {
    s16 unk00[17];
    u8 unk22[8];
} D_80115640_286110_Struct;

void func_80105D08_2767D8_vine_with_me(omObjData* arg0);
void func_80106004_276AD4_vine_with_me(omObjData* arg0);
void func_8010683C_27730C_vine_with_me(omObjData* arg0);
void func_80106F1C_2779EC_vine_with_me(omObjData* arg0);
void func_801087BC_27928C_vine_with_me(void);
void func_8010ADB0_27B880_vine_with_me(Gfx** arg0, s32 arg1, s32 arg2);
void func_8010CEA8_27D978_vine_with_me(omObjData* arg0);
void func_8010CEE0_27D9B0_vine_with_me(omObjData* arg0);
void func_8010CF18_27D9E8_vine_with_me(omObjData* arg0, s8 arg1, s32 arg2);
void func_8010D46C_27DF3C_vine_with_me(omObjData* arg0);
void func_8010D48C_27DF5C_vine_with_me(omObjData* arg0);
void func_8010D4AC_27DF7C_vine_with_me(omObjData* arg0, s8 arg1, s8 arg2);

f32 BSS D_80112590_283060_vine_with_me[2];
f32 BSS D_80112598_283068_vine_with_me[2];
f32 BSS D_801125A0_283070_vine_with_me[2];
f32 BSS D_801125A8_283078_vine_with_me[2];
f32 BSS D_801125B0_283080_vine_with_me[2];
f32 BSS D_801125B8_283088_vine_with_me[2];
f32 BSS D_801125C0_283090_vine_with_me[2];
f32 BSS D_801125C8_283098_vine_with_me[2];
f32 BSS D_801125D0_2830A0_vine_with_me[4][9][14];
f32 BSS D_80112DB0_283880_vine_with_me[4][9][14];
f32 BSS D_80113590_284060_vine_with_me[4][9][14];
f32 BSS D_80113D70_284840_vine_with_me[4][9][14];
f32 BSS D_80114550_285020_vine_with_me[8][9][14];
D_80115510_285FE0_Struct BSS D_80115510_285FE0_vine_with_me[2];
D_80115510_285FE0_Struct* BSS D_80115530_286000_vine_with_me[4];
f32 BSS D_80115540_286010_vine_with_me[2];
s8 BSS D_80115548_286018_vine_with_me[4];
s32 BSS D_8011554C_28601C_vine_with_me[2];
s32 BSS D_80115554_286024_vine_with_me;
f32 BSS D_80115558_286028_vine_with_me;
u8 BSS D_8011555C_28602C_vine_with_me[4]; // unused?
s16 BSS D_80115560_286030_vine_with_me[17];
omObjData* BSS D_80115584_286054_vine_with_me[2];
static s8 BSS D_8011558C_28605C_vine_with_me;
static u8 BSS D_8011558D_28605D_vine_with_me[16];
omObjData* BSS D_801155A0_286070_vine_with_me;
s32 BSS D_801155A4_286074_vine_with_me[2];
f32 BSS D_801155AC_28607C_vine_with_me;
u8 BSS D_801155B0_286080_vine_with_me;
f32 BSS D_801155B4_286084_vine_with_me;
u16 BSS D_801155B8_286088_vine_with_me;
u8 BSS D_801155BC_28608C_vine_with_me[0x14]; // unused?
s32 BSS D_801155D0_2860A0_vine_with_me;
u8 BSS D_801155D4_2860A4_vine_with_me[4]; // unused?
f32 BSS D_801155D8_2860A8_vine_with_me[2][4];
s8 BSS D_801155F8_2860C8_vine_with_me[2];
s16 BSS D_801155FA_2860CA_vine_with_me;
f32 BSS D_801155FC_2860CC_vine_with_me[2];
f32 BSS D_80115604_2860D4_vine_with_me;
f32 BSS D_80115608_2860D8_vine_with_me;
f32 BSS D_8011560C_2860DC_vine_with_me;
f32 BSS D_80115610_2860E0_vine_with_me[8];
s32 BSS D_80115630_286100_vine_with_me[2];
f32 BSS D_80115638_286108_vine_with_me;
s16 BSS D_8011563C_28610C_vine_with_me;
D_80115640_286110_Struct BSS D_80115640_286110_vine_with_me;
s32 BSS D_8011566C_28613C_vine_with_me;
u8 BSS D_80115670_286140_vine_with_me[8];
u32 BSS D_80115678_286148_vine_with_me[8];

D_80111B50_282620_Struct D_80111B50_282620_vine_with_me = { 0 };

u32 D_80111B78_282648_vine_with_me[] = { 102, 60, -1, -1, -1, -1, 300 };

u32 D_80111B94_282664_vine_with_me = 0;

// TODO: the following arrays work but trigger multiple warnings: "missing braces around initializer"
// Ideally we should use these and remove the u32 arrays below.
/*
Gfx D_80111B98_282668_vine_with_me[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetRenderMode(G_RM_XLU_SURF, G_RM_XLU_SURF2),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 320, 240),
    gsSPEndDisplayList()
};

Gfx D_80111BE0_2826B0_vine_with_me[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetRenderMode(G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 320, 240),
    gsSPEndDisplayList()
};
*/

u32 D_80111B98_282668_vine_with_me[] = {
    0xE7000000, 0x00000000, 0xE3000A01, 0x00000000, 0xFCFFFFFF, 0xFFFCF279, 0xE200001C, 0x00504240,
    0xE2001E01, 0x00000000, 0xE3000C00, 0x00000000, 0xE3001201, 0x00002000, 0xED000000, 0x005003C0,
    0xDF000000, 0x00000000
};

u32 D_80111BE0_2826B0_vine_with_me[] = {
    0xE7000000, 0x00000000, 0xE3000A01, 0x00000000, 0xFCFFFFFF, 0xFFFCF279, 0xE200001C, 0x00552048,
    0xE2001E01, 0x00000000, 0xE3000C00, 0x00000000, 0xE3001201, 0x00002000, 0xED000000, 0x005003C0,
    0xDF000000, 0x00000000
};

u8 D_80111C28_2826F8_vine_with_me = 0;

s8 D_80111C2C_2826FC_vine_with_me[][6] = {
    { 6, 6, 5, 7, 5, 4 },
    { 6, 4, 6, 4, 5, 6 }
};

s8 D_80111C38_282708_vine_with_me[] = { 0, 0, 0, 0 };
s8 D_80111C3C_28270C_vine_with_me[] = { 1, 1, 0, 0 };
s8 D_80111C40_282710_vine_with_me[] = { 0, 0, 0, 0 };
s8 D_80111C44_282714_vine_with_me[] = { 6, 6, 5, 7, 5, 4, 7, 8, 7, 6, 5, 4, 5, 6, 7, 5, 0, 0, 0, 0, 0, 0, 0, 0 };
s8 D_80111C5C_28272C_vine_with_me[] = { 0, 0, 0, 0 };
f32 D_80111C60_282730_vine_with_me[] = { 0.0f, 0.0f };
f32 D_80111C68_282738_vine_with_me[] = { 0.0f, 0.0f };
f32 D_80111C70_282740_vine_with_me[] = { 0.0f, 0.0f };
f32 D_80111C78_282748_vine_with_me[] = { 6.0f, 6.0f };
f32 D_80111C80_282750_vine_with_me[] = { 0.0f, 0.0f };
u8 D_80111C88_282758_vine_with_me = 0;
f32 D_80111C8C_28275C_vine_with_me[] = { 0.0f, 0.0f };
u8 D_80111C94_282764_vine_with_me[] = { 0, 0, 0, 0 };
u8 D_80111C98_282768_vine_with_me[] = { 0, 0, 0, 0 };
s8 D_80111C9C_28276C_vine_with_me[] = { 0, 0, 0, 0, 0, 0, 0, 0 };
u32 D_80111CA4_282774_vine_with_me = 0;

const s16 D_80111CB0_282780_vine_with_me[] = {
    0x8260, 0x8261, 0x8262, 0x8263, 0x8264, 0x8265, 0x8266, 0x8267,
    0x8268, 0x8269, 0x826A, 0x826B, 0x826C, 0x826D, 0x826E, 0x826F,
    0x8270, 0x8271, 0x8272, 0x8273, 0x8274, 0x8275, 0x8276, 0x8277,
    0x8278, 0x8279, 0x0000, 0x0000
};

void func_801059A0_276470_vine_with_me(void) {
    omObjData* temp_v0;
    omObjData* temp_v0_2;

    func_800142A0_14EA0(0x20);
    omInitObjMan(50, 0);
    func_8004A208_4AE08();
    D_800CD280_CDE80 = 1;
    func_8000B5F0_C1F0(2);
    func_8000B710_C310(2);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 120.0f);
    ScissorSet(1, 0.0f, 120.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 240.0f, 511.0f);
    ViewportSet(1, 640.0f, 480.0f, 511.0f, 640.0f, 720.0f, 511.0f);
    Hu3DCamSetPerspective(0, 22.619865f, 1000.0f, 22000.0f);
    Hu3DCamSetPerspective(1, 22.619865f, 1000.0f, 22000.0f);
    HmfLightMaxSet(2);
    HmfLightDirSet(0, 0.0f, 0.0f, 90.0f);
    HmfLightColorSet(0, 0x90, 0x90, 0x90);
    HmfLightDirSet(1, 0.0f, 65.0f, 90.0f);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    CenterM[0].x = 0.0f;
    CenterM[0].y = -300.0f;
    CenterM[0].z = 0.0f;
    CRotM[0].x = 0.0f;
    CRotM[0].y = 0.0f;
    CRotM[0].z = 0.0f;
    CZoomM[0] = 3750.0f;
    CenterM[1].x = 0.0f;
    CenterM[1].y = -270.0f;
    CenterM[1].z = 0.0f;
    CRotM[1].x = 0.0f;
    CRotM[1].y = 0.0f;
    CRotM[1].z = 0.0f;
    CZoomM[1] = 3750.0f;
    omAddObj(0, 0, 0, -1, func_80105D08_2767D8_vine_with_me);
    temp_v0 = omAddObj(8, 23, 23, -1, func_8010683C_27730C_vine_with_me);
    D_801155A0_286070_vine_with_me = temp_v0;
    omSetStatBit(temp_v0, 0xA0);
    D_80115584_286054_vine_with_me[0] = omAddObj(3, 26, 7, -1, func_8010CEA8_27D978_vine_with_me);
    D_80115584_286054_vine_with_me[1] = omAddObj(3, 26, 7, -1, func_8010CEE0_27D9B0_vine_with_me);
    temp_v0_2 = omAddObj(0x7FDA, 0, 0, -1, omOutViewMulti);
    temp_v0_2->work[0] = 2;
    omSetStatBit(temp_v0_2, 0xA0);
    func_80045010_45C10(D_80111CB0_282780_vine_with_me, 1);
    WipeCreateIn(0xFF, 0x10);
    D_80111B50_282620_vine_with_me.unk01 = 4;
    D_80111B50_282620_vine_with_me.unk1C = -1;
    D_80111B50_282620_vine_with_me.unk1E = 5400;
    D_80111B50_282620_vine_with_me.unk03 = 0;
    D_80111B50_282620_vine_with_me.unk02 = 1;
    D_80111B50_282620_vine_with_me.unk22 = 60;
    D_80111B50_282620_vine_with_me.unk24 = 165;
    D_80111B50_282620_vine_with_me.unk04 = 0;
    D_80111B50_282620_vine_with_me.unk05 = 0;
    D_80111B50_282620_vine_with_me.unk20 = -1;
    func_800E5EA0_B8A20_minigame(&D_80111B50_282620_vine_with_me);
}

void func_80105D08_2767D8_vine_with_me(omObjData* arg0) {
    s32 var_s0;

    D_801155B8_286088_vine_with_me = 0;
    D_8011563C_28610C_vine_with_me = 0;
    D_8011566C_28613C_vine_with_me = 0;
    D_801155D0_2860A0_vine_with_me = 0;
    D_8011558C_28605C_vine_with_me = 0;
    D_801155B0_286080_vine_with_me = 0;
    D_801155D8_2860A8_vine_with_me[0][0] = D_801155D8_2860A8_vine_with_me[1][0] = 1000.0f;
    D_801155D8_2860A8_vine_with_me[0][1] = D_801155D8_2860A8_vine_with_me[1][1] = 700.0f;
    D_801155D8_2860A8_vine_with_me[0][2] = D_801155D8_2860A8_vine_with_me[1][2] = 0.0f;
    D_801155D8_2860A8_vine_with_me[0][3] = D_801155D8_2860A8_vine_with_me[1][3] = 450.0f;
    D_801155A4_286074_vine_with_me[0] = D_801155A4_286074_vine_with_me[1] = 0;
    D_8011554C_28601C_vine_with_me[0] = D_8011554C_28601C_vine_with_me[1] = 0;
    D_80115540_286010_vine_with_me[0] = D_80115540_286010_vine_with_me[1] = 0.0f;
    D_801155FC_2860CC_vine_with_me[0] = D_801155FC_2860CC_vine_with_me[1] = 0.0f;
    D_80115548_286018_vine_with_me[0] = D_80115548_286018_vine_with_me[1] = 0;
    D_8011560C_2860DC_vine_with_me = 0.0f;
    D_801155F8_2860C8_vine_with_me[0] = D_801155F8_2860C8_vine_with_me[1] = 0;
    D_80115558_286028_vine_with_me = 1.0f;
    D_80115604_2860D4_vine_with_me = 1.0f;
    D_801155AC_28607C_vine_with_me = 0.5f;
    D_801155B4_286084_vine_with_me = 0.5f;
    D_80115554_286024_vine_with_me = -1;
    for (var_s0 = 0; var_s0 < 2; var_s0++) {
        D_80115530_286000_vine_with_me[var_s0] = &D_80115510_285FE0_vine_with_me[var_s0];
        bzero(D_80115530_286000_vine_with_me[var_s0], sizeof(D_80115510_285FE0_Struct));
    }
    D_80115670_286140_vine_with_me[0] = D_80115670_286140_vine_with_me[1] = 4;
    for (var_s0 = 0; var_s0 < 4; var_s0++) {
        s32 temp_v1 = GwPlayer[var_s0].group;

        if (temp_v1 < 2) {
            if (D_80115670_286140_vine_with_me[temp_v1] == 4) {
                D_80115670_286140_vine_with_me[temp_v1] = var_s0;
            }
        }
    }
    for (var_s0 = 0; var_s0 < 2; var_s0++) {
        D_80115530_286000_vine_with_me[var_s0]->unk00 = var_s0;
        D_80115530_286000_vine_with_me[var_s0]->unk02 = GwPlayer[D_80115670_286140_vine_with_me[var_s0]].pad;
        D_80115530_286000_vine_with_me[var_s0]->unk03 = GwPlayer[D_80115670_286140_vine_with_me[var_s0]].chr;
        D_80115530_286000_vine_with_me[var_s0]->unk01 = var_s0;
        D_80115530_286000_vine_with_me[var_s0]->unk04 = (GwPlayer[D_80115670_286140_vine_with_me[var_s0]].stat & 1) ? GwPlayer[D_80115670_286140_vine_with_me[var_s0]].cpu_difficulty : -1;
    }
    func_8001AC8C_1B88C(0, func_8010ADB0_27B880_vine_with_me, 2);
    arg0->func = func_80106004_276AD4_vine_with_me;
}

void func_80106004_276AD4_vine_with_me(omObjData* arg0) {
    s32 temp_s1;
    u8 var_a0;

    D_8011566C_28613C_vine_with_me = D_801155D0_2860A0_vine_with_me;
    D_801155D0_2860A0_vine_with_me++;
    D_801155FA_2860CA_vine_with_me = 0;
    CenterM[0].x = 0.0f;
    CenterM[0].y = -300.0f;
    CenterM[0].z = 0.0f;
    CenterM[1].x = 0.0f;
    CenterM[1].y = -270.0f;
    CenterM[1].z = 0.0f;
    if (D_801155D0_2860A0_vine_with_me >= D_80111B78_282648_vine_with_me[D_8011563C_28610C_vine_with_me]) {
        D_801155D0_2860A0_vine_with_me = D_801155D0_2860A0_vine_with_me - D_80111B78_282648_vine_with_me[D_8011563C_28610C_vine_with_me];
        D_8011563C_28610C_vine_with_me++;
    }
    switch (D_8011563C_28610C_vine_with_me) {
        case 1:
        case 5:
            break;
        case 0:
            if (D_801155D0_2860A0_vine_with_me == 1 && D_801155B8_286088_vine_with_me == 0 && D_800D530C_D5F0C == 0) {
                D_80115554_286024_vine_with_me = HuAudFXPlay(0x495);
            }
            if (D_801155D0_2860A0_vine_with_me == 28 && D_801155B8_286088_vine_with_me == 0 && D_800D530C_D5F0C == 0) {
                HuAudSeqPlay(0x30);
            }
            if (D_801155D0_2860A0_vine_with_me == 30) {
                func_800E6F1C_B9A9C_minigame();
            }
            break;
        case 2:
            if (D_80111B50_282620_vine_with_me.unk1E == 900) {
                GMesCreate(GMES_MES_TIMER, 0x1F, 0xA0, 0x18);
                D_80111B50_282620_vine_with_me.unk03 = 2;
            }
            if (D_8011558C_28605C_vine_with_me == 0) {
                break;
            }
            D_8011563C_28610C_vine_with_me = 3;
            D_801155D0_2860A0_vine_with_me = 0;
            /* fallthrough */
        case 3:
            if (D_801155D0_2860A0_vine_with_me < D_8011566C_28613C_vine_with_me) {
                func_800E6F1C_B9A9C_minigame();
                D_8011558C_28605C_vine_with_me--;
                D_80111B50_282620_vine_with_me.unk06 = 0;
                D_80111B50_282620_vine_with_me.unk18 = D_80115670_286140_vine_with_me[D_8011558C_28605C_vine_with_me];
            }
            if (D_801155D0_2860A0_vine_with_me == 2 && D_801155D0_2860A0_vine_with_me != D_8011558C_28605C_vine_with_me) {
                func_800E6F34_B9AB4_minigame(0x1E);
            }
            if (D_801155D0_2860A0_vine_with_me == 15 && D_80115554_286024_vine_with_me != -1) {
                func_8004AEF0_4BAF0(D_80115554_286024_vine_with_me, 0xF);
                D_80115554_286024_vine_with_me = -1;
            }
            break;
        case 4:
            temp_s1 = D_801155D0_2860A0_vine_with_me;
            if (temp_s1 == 1) {
                HmfModelData[D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->model[1]].pos.x = D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->trans.x;
                HmfModelData[D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->model[1]].pos.y = D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->trans.y;
                HmfModelData[D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->model[1]].pos.z = D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->trans.z;
                HmfModelData[D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->model[1]].rot.x = D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->rot.x;
                HmfModelData[D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->model[1]].rot.y = D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->rot.y;
                HmfModelData[D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->model[1]].rot.z = D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->rot.z;
                func_8001C258_1CE58(D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->model[1], 4, 0);
                func_8001C258_1CE58(D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->model[0], 4, 4);
                GwPlayer[D_80115670_286140_vine_with_me[D_8011558C_28605C_vine_with_me]].bonusCoin = 10;
                if (D_801155F8_2860C8_vine_with_me[1 - D_8011558C_28605C_vine_with_me] != 0) {
                    func_8001C5B4_1D1B4(D_80115584_286054_vine_with_me[temp_s1 - D_8011558C_28605C_vine_with_me]->model[0], D_80115584_286054_vine_with_me[temp_s1 - D_8011558C_28605C_vine_with_me]->motion[6]);
                }
            }
            if (D_801155D0_2860A0_vine_with_me == 30) {
                s32 sp12[] = { 0, 1, 2, 3, 4, 5, 6, 7 };

                func_80017954_18554(D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->model[1], 1, sp12[D_80115530_286000_vine_with_me[D_8011558C_28605C_vine_with_me]->unk03], D_80115530_286000_vine_with_me[D_8011558C_28605C_vine_with_me]->unk08);
                func_8001C5B4_1D1B4(D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->model[1], D_80115584_286054_vine_with_me[D_8011558C_28605C_vine_with_me]->motion[5]);
                func_80045ED0_46AD0(D_80115530_286000_vine_with_me[D_8011558C_28605C_vine_with_me]->unk0C);
            }
            break;
    }
    func_800E6F40_B9AC0_minigame();
    switch (D_8011563C_28610C_vine_with_me) {
        case 2:
            if (D_8011558C_28605C_vine_with_me != 0 || func_800E6E8C_B9A0C_minigame() != 3) {
                break;
            }
            D_8011563C_28610C_vine_with_me = 3;
            D_801155D0_2860A0_vine_with_me = 0;
            D_8011558C_28605C_vine_with_me = 2;
            D_80111B50_282620_vine_with_me.unk06 = 4;
            D_80111B50_282620_vine_with_me.unk22 = 90;
            D_80111B50_282620_vine_with_me.unk24 = 144;
            /* fallthrough */
        case 3:
            if (func_800E6E8C_B9A0C_minigame() == 4) {
                D_8011563C_28610C_vine_with_me = (D_8011558C_28605C_vine_with_me == 2) ? 5 : 4;
                D_801155D0_2860A0_vine_with_me = 0;
            }
            break;
        case 4:
        case 5:
            if (func_800E6E8C_B9A0C_minigame() != 5) {
                break;
            }
            D_8011563C_28610C_vine_with_me = 6;
            D_801155D0_2860A0_vine_with_me = 0;
            /* fallthrough */
        case 6:
            if (D_801155D0_2860A0_vine_with_me < D_8011566C_28613C_vine_with_me) {
                WipeCreateOut(0, 0x14);
            } else if (D_801155D0_2860A0_vine_with_me >= 32) {
                D_801155B8_286088_vine_with_me = 1;
            }
            break;
    }
    // TODO: why 2U?
    if (_CheckFlag(0xF) && D_800D530C_D5F0C == 0 && D_801155B0_286080_vine_with_me == 0 && D_8011563C_28610C_vine_with_me == 2U) {
        for (var_a0 = 0; var_a0 < 2; var_a0++) {
            if (D_80115530_286000_vine_with_me[var_a0]->unk04 == -1 && (D_800D5558_D6158[D_80115530_286000_vine_with_me[var_a0]->unk02] & 0x10)) {
                D_801155B0_286080_vine_with_me = 1;
            }
        }
    }
    if (D_801155B8_286088_vine_with_me == 0 && D_800D530C_D5F0C == 0 && D_801155B0_286080_vine_with_me == 0) {
        return;
    }
    if (D_800D530C_D5F0C != 0 && D_801155B0_286080_vine_with_me == 0) {
        D_801155B0_286080_vine_with_me = 1;
    }
    if (D_801155B0_286080_vine_with_me != 0) {
        if (D_801155B0_286080_vine_with_me == 1) {
            WipeCreateOut(0, 0x14);
            HuAudSeqFadeOut(0x14);
            func_8004AB0C_4B70C(0x14);
        }
        D_801155B0_286080_vine_with_me++;
        if (D_801155B0_286080_vine_with_me < 25) {
            return;
        }
    }
    HuAudSeqFadeOut(0x1E);
    func_80017320_17F20(D_80115630_286100_vine_with_me[0]);
    func_80017320_17F20(D_80115630_286100_vine_with_me[1]);
    omOvlReturnEx(1);
}

void func_8010683C_27730C_vine_with_me(omObjData* arg0) {
    s32 sp10[] = {
        0x0052000D,
        0x0052000C,
        0x00520009,
        0x0052000A,
        0x0052000B,
        0x0052000E,
        0x00210008,
        0x00210009,
        0x0021000A,
        0x0021000B,
        0x0021000C,
        0x0021000D,
        0x0021000E,
        0x0021000F,
        0x0052000F,
        0x00520010,
        0x00520011
    };
    s16 var_s3;

    for (var_s3 = 0; var_s3 < 17; var_s3++) {
        D_80115560_286030_vine_with_me[var_s3] = func_8000B838_C438(sp10[var_s3]);
        D_80115640_286110_vine_with_me.unk00[var_s3] = InitEspriteSlot(D_80115560_286030_vine_with_me[var_s3], 0, 0);
        func_8000BB94_C794(D_80115640_286110_vine_with_me.unk00[var_s3]);
    }
    arg0->model[0] = func_8000B108_BD08(0x520008, 0x23D);
    func_8001C8A8_1D4A8(arg0->model[0], 1);
    omSetTra(arg0, 1950.0f, 172.0f, 0.0f);
    omSetSca(arg0, 1.0f, 0.594f, 0.0f);
    omSetRot(arg0, 0.0f, 0.0f, 5.0f);
    arg0->model[1] = Hu3DModelLink(arg0->model[0]);
    func_8001C8A8_1D4A8(arg0->model[1], 2);
    Hu3DModelPosSet(arg0->model[1], 1950.0f, 172.0f, 0.0f);
    Hu3DModelScaleSet(arg0->model[1], 1.0f, 0.594f, 0.0f);
    Hu3DModelRotSet(arg0->model[1], 0.0f, 0.0f, 5.0f);
    arg0->model[6] = func_8000B108_BD08(8, 0xA3D);
    func_8001C8A8_1D4A8(arg0->model[6], 1);
    Hu3DModelPosSet(arg0->model[6], 300.0f, -350.0f, 0.0f);
    arg0->model[7] = Hu3DModelLink(arg0->model[6]);
    func_8001C8A8_1D4A8(arg0->model[7], 2);
    Hu3DModelPosSet(arg0->model[7], 300.0f, -350.0f, 0.0f);
    arg0->model[10] = func_8000B108_BD08(0x520007, 0x23D);
    func_8001C8A8_1D4A8(arg0->model[10], 1);
    Hu3DModelPosSet(arg0->model[10], 475.0f, -370.0f, 0.0f);
    arg0->model[11] = Hu3DModelLink(arg0->model[10]);
    func_8001C8A8_1D4A8(arg0->model[11], 2);
    Hu3DModelPosSet(arg0->model[11], 475.0f, -370.0f, 0.0f);
    arg0->model[2] = func_8000B108_BD08(0x520001, 0x619);
    func_8001C8A8_1D4A8(arg0->model[2], 1);
    Hu3DModelPosSet(D_801155A0_286070_vine_with_me->model[2], 375.0f, -375.0f, -250.0f);
    Hu3DModelScaleSet(D_801155A0_286070_vine_with_me->model[2], 1.4375f, 1.4375f, 1.0f);
    arg0->model[3] = Hu3DModelLink(arg0->model[2]);
    func_8001C8A8_1D4A8(arg0->model[3], 2);
    Hu3DModelPosSet(arg0->model[3], 375.0f, -375.0f, -250.0f);
    Hu3DModelScaleSet(arg0->model[3], 1.4375f, 1.4375f, 1.0f);
    arg0->model[8] = func_8000B108_BD08(0x520006, 0x23D);
    func_8001C8A8_1D4A8(arg0->model[8], 1);
    Hu3DModelPosSet(arg0->model[8], 475.0f, -300.0f, 0.0f);
    arg0->model[9] = Hu3DModelLink(arg0->model[8]);
    func_8001C8A8_1D4A8(arg0->model[9], 2);
    Hu3DModelPosSet(arg0->model[9], 475.0f, -300.0f, 0.0f);
    arg0->model[4] = func_8000B108_BD08(0x520002, 0x49D);
    Hu3DModelPosSet(arg0->model[4], 325.0f, -650.0f, 0.0f);
    Hu3DModelScaleSet(arg0->model[4], 0.5f, 0.5f, 1.0f);
    func_8001C814_1D414(arg0->model[4], 3, 0);
    func_8001C8A8_1D4A8(arg0->model[4], 1);
    arg0->model[5] = Hu3DModelLink(arg0->model[4]);
    Hu3DModelPosSet(arg0->model[5], 325.0f, -650.0f, 0.0f);
    Hu3DModelScaleSet(arg0->model[5], 0.5f, 0.5f, 1.0f);
    func_8001C814_1D414(arg0->model[5], 3, 0);
    func_8001C8A8_1D4A8(arg0->model[5], 2);
    for (var_s3 = 0; var_s3 < 8; var_s3++) {
        D_80115678_286148_vine_with_me[var_s3] = 90;
        D_80115640_286110_vine_with_me.unk22[var_s3] = 0;
        arg0->model[12 + var_s3] = func_8000B108_BD08(0x520003, 0x6BD);
        Hu3DModelRotSet(arg0->model[12 + var_s3], 0.0f, 0.0f, 0.0f);
        func_8001C814_1D414(arg0->model[12 + var_s3], 2, 2);
        func_8001C8A8_1D4A8(arg0->model[12 + var_s3], 0);
        func_8001FDE8_209E8(arg0->model[12 + var_s3]);
    }
    for (var_s3 = 0; var_s3 < 2; var_s3++) {
        s32 sp58[] = { 4, 5 };

        func_8000B460_C060(arg0, var_s3, sp58[var_s3] | 0x520000);
        func_8001C5B4_1D1B4(arg0->model[12 + var_s3], arg0->motion[var_s3]);
        D_80115630_286100_vine_with_me[var_s3] = func_80016784_17384(arg0->model[12 + var_s3], 2);
        func_8001ACDC_1B8DC(arg0->motion[var_s3]);
    }
    for (var_s3 = 0; var_s3 < 8; var_s3++) {
        func_8001C5B4_1D1B4(arg0->model[12 + var_s3], arg0->motion[0]);
    }
    arg0->func = func_80106F1C_2779EC_vine_with_me;
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
void func_80106F1C_2779EC_vine_with_me(omObjData* arg0) {
    f32 temp_f12;
    f32 temp_fs1;
    f32 temp_f20;
    f32 temp_f20_4;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 var_f10;
    f32 var_f14;
    f32 var_f16;
    f32 var_f20;
    f32 var_f24;
    s32 temp_s0_4;
    s32 temp_a0_3;
    s32 temp_s2;
    s32 var_s1;

    if (D_8011563C_28610C_vine_with_me == 4 && D_801155D0_2860A0_vine_with_me < 0x1F) {
        D_80115604_2860D4_vine_with_me = (1.0f - D_801155D0_2860A0_vine_with_me / 30.0f) * 1.0 + (D_801155D0_2860A0_vine_with_me / 30.0f) * 2.375;
        D_801155B4_286084_vine_with_me = (1.0f - D_801155D0_2860A0_vine_with_me / 30.0f) * 0.5 + (D_801155D0_2860A0_vine_with_me / 30.0f) * 0.77200000000000002;
        D_801155AC_28607C_vine_with_me = (1.0f - D_801155D0_2860A0_vine_with_me / 30.0f) * 0.5 + (D_801155D0_2860A0_vine_with_me / 30.0f) * (D_8011558C_28605C_vine_with_me != 0 ? 0.780000000000000027 : 0.220000000000000001);
        temp_f26 = D_80115604_2860D4_vine_with_me * 320.0f * 2.0f;
        temp_f24 = D_80115604_2860D4_vine_with_me * 240.0f * 2.0f;
        var_f16 = -D_801155B4_286084_vine_with_me * D_80115604_2860D4_vine_with_me + 0.5;
        var_f10 = -D_801155AC_28607C_vine_with_me * D_80115604_2860D4_vine_with_me + 0.5;
        var_f14 = var_f16 + D_80115604_2860D4_vine_with_me * 1.0;
        temp_f12 = var_f10 + D_80115604_2860D4_vine_with_me * 0.5;
        temp_fs1 = var_f16 + D_80115604_2860D4_vine_with_me * 0.5;
        temp_f20 = var_f10 + D_80115604_2860D4_vine_with_me * 0.25;
        var_f16 = (var_f16 < 0.0) ? 0.0f : (var_f16 > 1.0) ? 1.0f : var_f16;
        var_f10 = (var_f10 < 0.0) ? 0.0f : (var_f10 > 1.0) ? 1.0f : var_f10;
        var_f14 = (var_f14 < 0.0) ? 0.0f : (var_f14 > 1.0) ? 1.0f : var_f14;
        temp_f12 = (temp_f12 < 0.0) ? 0.0f : (temp_f12 > 1.0) ? 1.0f : temp_f12;
        var_f16 *= 320.0f;
        var_f10 *= 240.0f;
        var_f14 *= 320.0f;
        temp_f12 *= 240.0f;
        temp_fs1 *= 1280.0f;
        temp_f20 *= 960.0f;
        ScissorSet(0, var_f16, var_f10, var_f14, temp_f12);
        ViewportSet(0, temp_f26, temp_f24, 511.0f, temp_fs1, temp_f20, 511.0f);
        var_f16 = -D_801155B4_286084_vine_with_me * D_80115604_2860D4_vine_with_me + 0.5;
        var_f10 = -D_801155AC_28607C_vine_with_me * D_80115604_2860D4_vine_with_me + 0.5;
        var_f14 = var_f16 + D_80115604_2860D4_vine_with_me * 1.0;
        temp_f12 = var_f10 + D_80115604_2860D4_vine_with_me * 1.0;
        temp_fs1 = var_f16 + D_80115604_2860D4_vine_with_me * 0.5;
        temp_f20 = var_f10 + D_80115604_2860D4_vine_with_me * 0.75;
        var_f10 += D_80115604_2860D4_vine_with_me * 0.5;
        var_f16 = (var_f16 < 0.0) ? 0.0f : (var_f16 > 1.0) ? 1.0f : var_f16;
        var_f10 = (var_f10 < 0.0) ? 0.0f : (var_f10 > 1.0) ? 1.0f : var_f10;
        var_f14 = (var_f14 < 0.0) ? 0.0f : (var_f14 > 1.0) ? 1.0f : var_f14;
        temp_f12 = (temp_f12 < 0.0) ? 0.0f : (temp_f12 > 1.0) ? 1.0f : temp_f12;
        var_f16 *= 320.0f;
        var_f10 *= 240.0f;
        var_f14 *= 320.0f;
        temp_f12 *= 240.0f;
        temp_fs1 *= 1280.0f;
        temp_f20 *= 960.0f;
        ScissorSet(1, var_f16, var_f10, var_f14, temp_f12);
        ViewportSet(1, temp_f26, temp_f24, 511.0f, temp_fs1, temp_f20, 511.0f);
    }
    D_80115558_286028_vine_with_me = 1.0f / D_80115604_2860D4_vine_with_me;
    D_80115608_2860D8_vine_with_me = (-D_801155B4_286084_vine_with_me * D_80115604_2860D4_vine_with_me + 0.5) * 320.0 * 4.0;
    D_80115638_286108_vine_with_me = (-D_801155AC_28607C_vine_with_me * D_80115604_2860D4_vine_with_me + 0.5) * 240.0 * 4.0;
    func_801087BC_27928C_vine_with_me();
    if (func_80049F98_4AB98() != 0) {
        return;
    }
    var_f20 = -300.0f;
    var_f24 = -375.0f;
    if (D_8011563C_28610C_vine_with_me == 0 && D_801155D0_2860A0_vine_with_me == 90) {
        D_80111B94_282664_vine_with_me++;
    }
    if (D_80111B94_282664_vine_with_me != 0 && D_80111B94_282664_vine_with_me < 120) {
        HmfModelData[arg0->model[8]].pos.x = HmfModelData[arg0->model[10]].pos.x =
        HmfModelData[arg0->model[9]].pos.x = HmfModelData[arg0->model[11]].pos.x =
        HmfModelData[arg0->model[4]].pos.x = HmfModelData[arg0->model[5]].pos.x = 375.0f;
        HmfModelData[arg0->model[6]].pos.x = HmfModelData[arg0->model[7]].pos.x = 300.0f;
        if (D_80111B94_282664_vine_with_me == 1) {
            func_8001C258_1CE58(arg0->model[8], 4, 0);
            func_8001C258_1CE58(arg0->model[9], 4, 0);
            func_8001C258_1CE58(arg0->model[10], 4, 0);
            func_8001C258_1CE58(arg0->model[11], 4, 0);
        }
        if (D_80111B94_282664_vine_with_me == 4) {
            func_8001C6A8_1D2A8(arg0->model[4], 0.0f);
            func_8001C6A8_1D2A8(arg0->model[5], 0.0f);
            func_8001C258_1CE58(arg0->model[4], 4, 0);
            func_8001C258_1CE58(arg0->model[5], 4, 0);
            func_8001C8E4_1D4E4(D_80115584_286054_vine_with_me[0]->model[0], 0x400);
            func_8001C8E4_1D4E4(D_80115584_286054_vine_with_me[1]->model[0], 0x400);
        }
        if (D_80111B94_282664_vine_with_me != 0 && D_80111B94_282664_vine_with_me < 0xE) {
            temp_f22 = 1.0 - D_80111B94_282664_vine_with_me / 13.0f;
            temp_f22 = 1.0f - temp_f22 * temp_f22;
            var_f24 = temp_f22 * 600.0 + -975.0;
            Hu3DModelPosSet(arg0->model[10], 375.0f, var_f24, 0.0f);
            Hu3DModelPosSet(arg0->model[11], 375.0f, var_f24, 0.0f);
            if (D_80111B94_282664_vine_with_me != 0 && D_80111B94_282664_vine_with_me < 0xE) {
                temp_f22 = 1.0 - D_80111B94_282664_vine_with_me / 13.0f;
                temp_f22 = 1.0f - temp_f22 * temp_f22;
                var_f20 = temp_f22 * 700.0 + -1000.0;
                Hu3DModelPosSet(arg0->model[8], 375.0f, var_f20, 0.0f);
                Hu3DModelPosSet(arg0->model[9], 375.0f, var_f20, 0.0f);
            }
        }
        if (D_80111B94_282664_vine_with_me >= 12 && D_80111B94_282664_vine_with_me < 21) {
            f32 sp20[9] = { 80.0f, 90.0f, 110.0f, 110.0f, -20.0f, -10.0f, -20.0f, -15.0f, -20.0f };
            f32 sp48[9] = { -5.0f, -15.0f, -35.0f, -35.0f, -20.0f, -10.0f, -20.0f, -15.0f, -20.0f };
            f32 sp70[9] = { 0.0f, 0.0f, 0.0f, 0.0f, -31.0f, -20.0f, -31.0f, -25.0f, -31.0f };

            Hu3DModelPosSet(arg0->model[8], 375.0f, var_f20 - 75.0 + sp20[D_80111B94_282664_vine_with_me - 12], 0.0f);
            Hu3DModelPosSet(arg0->model[9], 375.0f, var_f20 - 75.0 + sp20[D_80111B94_282664_vine_with_me - 12], 0.0f);
            Hu3DModelPosSet(arg0->model[10], 375.0f, var_f24 + sp48[D_80111B94_282664_vine_with_me - 12], 0.0f);
            Hu3DModelPosSet(arg0->model[11], 375.0f, var_f24 + sp48[D_80111B94_282664_vine_with_me - 12], 0.0f);
            D_8011560C_2860DC_vine_with_me = sp70[D_80111B94_282664_vine_with_me - 12];
            HmfModelData[arg0->model[2]].pos.y += ((D_8011560C_2860DC_vine_with_me + 0.75) / 15.0) * 16.0;
            HmfModelData[arg0->model[3]].pos.y += ((D_8011560C_2860DC_vine_with_me + 0.75) / 15.0) * 16.0;
        }
        if (D_80111B94_282664_vine_with_me == 16) {
            func_8001C6A8_1D2A8(arg0->model[6], 0.0f);
            func_8001C258_1CE58(arg0->model[6], 4, 0);
            func_8001C258_1CE58(arg0->model[7], 4, 0);
            func_8001C8E4_1D4E4(arg0->model[2], 0);
            func_8001C8E4_1D4E4(arg0->model[3], 0);
            func_8001C8E4_1D4E4(arg0->model[10], 0);
            func_8001C8E4_1D4E4(arg0->model[11], 0);
            HuAudFXPlay(0x491);
            omVibrate(D_80115670_286140_vine_with_me[0], 2, 2, 0x14);
            omVibrate(D_80115670_286140_vine_with_me[1], 2, 2, 0x14);
        }
        if (D_80111B94_282664_vine_with_me >= 21 && D_80111B94_282664_vine_with_me < 46) {
            D_8011560C_2860DC_vine_with_me = -31.25f;
            HmfModelData[arg0->model[2]].pos.y += -33.3333333333333357;
            HmfModelData[arg0->model[3]].pos.y += -33.3333333333333357;
        }
        if (D_80111B94_282664_vine_with_me >= 46 && D_80111B94_282664_vine_with_me < 86) {
            temp_f22 = (D_80111B94_282664_vine_with_me - 45) / 40.0;
            temp_f22 = temp_f22 * temp_f22 * 0.75 + temp_f22 * 0.25;
            Hu3DModelPosSet(arg0->model[8], 375.0f, temp_f20_4 = -395.0 - temp_f22 * 600.0, 0.0f);
            Hu3DModelPosSet(arg0->model[9], 375.0f, temp_f20_4, 0.0f);
            Hu3DModelPosSet(arg0->model[10], 375.0f, temp_f20_4, 0.0f);
            Hu3DModelPosSet(arg0->model[11], 375.0f, temp_f20_4, 0.0f);
            D_8011560C_2860DC_vine_with_me = -30.0 - temp_f22 * 600.0;
            HmfModelData[arg0->model[2]].pos.y += (D_8011560C_2860DC_vine_with_me / 15.0) * 16.0;
            HmfModelData[arg0->model[3]].pos.y += (D_8011560C_2860DC_vine_with_me / 15.0) * 16.0;
        }
        if (D_80111B94_282664_vine_with_me == 86) {
            func_8001C258_1CE58(arg0->model[8], 4, 4);
            func_8001C258_1CE58(arg0->model[9], 4, 4);
            func_8001C258_1CE58(arg0->model[10], 4, 4);
            func_8001C258_1CE58(arg0->model[11], 4, 4);
            func_8001C258_1CE58(arg0->model[2], 4, 4);
            func_8001C258_1CE58(arg0->model[3], 4, 4);
        }
        if (++D_80111B94_282664_vine_with_me == 120) {
            func_8001C258_1CE58(arg0->model[4], 4, 4);
            func_8001C258_1CE58(arg0->model[6], 4, 4);
            func_8001C258_1CE58(arg0->model[7], 4, 4);
        }
        HmfModelData[arg0->model[8]].pos.x -= D_80115548_286018_vine_with_me[2] * 450.0;
        HmfModelData[arg0->model[10]].pos.x -= D_80115548_286018_vine_with_me[2] * 450.0;
        HmfModelData[arg0->model[9]].pos.x -= D_80115548_286018_vine_with_me[3] * 450.0;
        HmfModelData[arg0->model[11]].pos.x -= D_80115548_286018_vine_with_me[3] * 450.0;
        HmfModelData[arg0->model[6]].pos.x -= D_80115548_286018_vine_with_me[2] * 450.0;
        HmfModelData[arg0->model[7]].pos.x -= D_80115548_286018_vine_with_me[3] * 450.0;
        HmfModelData[arg0->model[4]].pos.x -= D_80115548_286018_vine_with_me[2] * 450.0;
        HmfModelData[arg0->model[5]].pos.x -= D_80115548_286018_vine_with_me[3] * 450.0;
    }
    for (var_s1 = 0; var_s1 < 8; var_s1++) {
        temp_s2 = D_80115678_286148_vine_with_me[var_s1];
        if (temp_s2 == 30) {
            Hu3DModelPosSet(arg0->model[12 + var_s1], D_80115610_2860E0_vine_with_me[var_s1], -840.0 - D_80115640_286110_vine_with_me.unk22[var_s1] * 30.0, 0.0f);
            Hu3DModelRotSet(arg0->model[12 + var_s1], 0.0f, ((rand8() & 0xFF) / 256.0) * 96.0 - 48.0 + ((D_8011558D_28605D_vine_with_me[8 + var_s1] + 1) % 3 - 1) * 0.0, 0.0f);
            func_80016FB4_17BB4(arg0->model[12 + var_s1], D_80115630_286100_vine_with_me[D_8011558D_28605D_vine_with_me[8 + var_s1] == 3], 0);
            func_8001C814_1D414(arg0->model[12 + var_s1], 2, 2);
            func_8001C258_1CE58(arg0->model[12 + var_s1], 4, 0);
            func_8001C8A8_1D4A8(arg0->model[12 + var_s1], D_80115640_286110_vine_with_me.unk22[var_s1] != 0 ? 2 : 1);
        } else if (temp_s2 == 89) {
            func_8001C258_1CE58(arg0->model[12 + var_s1], 4, 4);
        } else if (temp_s2 >= 31 && temp_s2 < 36) {
            Hu3DModelPosSet(arg0->model[12 + var_s1], D_80115610_2860E0_vine_with_me[var_s1], -840.0 - D_80115640_286110_vine_with_me.unk22[var_s1] * 30.0 + (temp_s2 - 0x1E) * 40.0, 0.0f);
        } else if (temp_s2 >= 79) {
            Hu3DModelPosSet(arg0->model[12 + var_s1], D_80115610_2860E0_vine_with_me[var_s1], -640.0 - D_80115640_286110_vine_with_me.unk22[var_s1] * 30.0 - (temp_s2 - 79.0) * (temp_s2 - 79.0) - (temp_s2 - 0x4F) * 10.0, 0.0f);
        } else {
            Hu3DModelPosSet(arg0->model[12 + var_s1], D_80115610_2860E0_vine_with_me[var_s1], -640.0 - D_80115640_286110_vine_with_me.unk22[var_s1] * 30.0, 0.0f);
            func_8001C6A8_1D2A8(arg0->model[12 + var_s1], temp_s2 - 30.0);
        }
        if (temp_s2 >= 31 && temp_s2 < 89) {
            temp_a0_3 = (temp_s2 - 30 + D_8011558D_28605D_vine_with_me[var_s1] / 2) * 2;
            if (D_8011558D_28605D_vine_with_me[8 + var_s1] == 3) {
                temp_s0_4 = temp_a0_3 / 60;
                temp_s0_4 = temp_a0_3 - temp_s0_4 * 60;
            } else {
                temp_s0_4 = temp_a0_3 / 74;
                temp_s0_4 = temp_a0_3 - temp_s0_4 * 74;
            }
            func_80016FB4_17BB4(arg0->model[12 + var_s1], D_80115630_286100_vine_with_me[D_8011558D_28605D_vine_with_me[8 + var_s1] == 3], temp_s0_4);
            if (D_8011558D_28605D_vine_with_me[8 + var_s1] != 3 && D_801155FA_2860CA_vine_with_me == 0) {
                if (temp_s0_4 == 18 || temp_s0_4 == 38 || temp_s0_4 == 58) {
                    HuAudFXPlay(0x494);
                }
            }
        }
        D_80115678_286148_vine_with_me[var_s1] += (D_80115678_286148_vine_with_me[var_s1] < 90);
    }
    D_80115548_286018_vine_with_me[0] -= (D_80115548_286018_vine_with_me[0] > 0);
    D_80115548_286018_vine_with_me[1] -= (D_80115548_286018_vine_with_me[1] > 0);
}

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_31_vine_with_me/276470", D_80111FA0_282A70_vine_with_me);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_31_vine_with_me/276470", D_80111FB0_282A80_vine_with_me);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_31_vine_with_me/276470", D_80111FC0_282A90_vine_with_me);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_31_vine_with_me/276470", D_80111FD0_282AA0_vine_with_me);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_31_vine_with_me/276470", D_80111FE0_282AB0_vine_with_me);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_31_vine_with_me/276470", D_80111FF0_282AC0_vine_with_me);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_31_vine_with_me/276470", D_80112000_282AD0_vine_with_me);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_31_vine_with_me/276470", D_80112010_282AE0_vine_with_me);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_31_vine_with_me/276470", D_80112030_282B00_vine_with_me);

INCLUDE_RODATA("asm/nonmatchings/overlays/ovl_31_vine_with_me/276470", D_80112040_282B10_vine_with_me);

// https://decomp.me/scratch/mEGSE
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_vine_with_me/276470", func_801087BC_27928C_vine_with_me);

// TODO: only works with -Wa,--vr4300mul-off.
#ifdef NON_MATCHING
void func_8010ADB0_27B880_vine_with_me(Gfx** arg0, s32 arg1, s32 arg2) {
    f32 sp10[2];
    s16 var_s1;
    s16 var_t3;
    s16 var_t8;
    s16 var_t9;
    s32 temp_a3_3;
    s32 temp_s2;
    s32 temp_t2;
    s32 var_a2;
    s32 var_v1_2;
    HuSprite_Unk84_Unk00_Struct* temp_s5;
    HuSprite_Unk84_Unk00_Struct* new_s5;
    HuSprite* temp_t1;
    s32 temp_3b;

    D_80111C28_2826F8_vine_with_me = (D_80111C28_2826F8_vine_with_me == 0);
    if (D_80111C28_2826F8_vine_with_me != 0) {
        return;
    }
    gSPDisplayList(gMainGfxPos++, D_80111BE0_2826B0_vine_with_me);
    gDPSetTextureLUT(gMainGfxPos++, G_TT_RGBA16);
    temp_t1 = HuSprGet(D_800CD1DC_CDDDC[D_80115640_286110_vine_with_me.unk00[16]].unk04, 0);
    temp_s5 = &temp_t1->unk_84->unk00[temp_t1->unk_90];
    gDPLoadTLUT_pal16(gMainGfxPos++, 0, temp_t1->unk_84->unk0C);
    gDPSetRenderMode(gMainGfxPos++, G_RM_AA_TEX_EDGE, G_RM_AA_TEX_EDGE2);
    gDPSetAlphaCompare(gMainGfxPos++, G_AC_THRESHOLD);
    gDPSetBlendColor(gMainGfxPos++, 0x00, 0x00, 0x00, 0xE0);
    for (var_s1 = 0; var_s1 < 2; var_s1++) {
        if (D_801155D8_2860A8_vine_with_me[var_s1][3] > 720.0) {
            D_801155D8_2860A8_vine_with_me[var_s1][3] -= 654.5454545454545;
        }
        if (D_801155D8_2860A8_vine_with_me[var_s1][3] < 0.0) {
            D_801155D8_2860A8_vine_with_me[var_s1][3] += 654.5454545454545;
        }
        sp10[var_s1] = -D_801155D8_2860A8_vine_with_me[var_s1][3] * 0.22;
    }
    for (var_t8 = 0; var_t8 < 3; var_t8++) {
        s32 var_s4 = 15;

        gDPLoadTextureTile_4b(gMainGfxPos++, temp_s5->unk00, G_IM_FMT_CI, 124, 0, 0, var_t8 * var_s4, 124, var_t8 * var_s4 + 15, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        for (var_t9 = 0; var_t9 < 2; var_t9++) {
            s32 var_t1_x = var_t8 * var_s4;

            if (var_t1_x >= 0x1D) {
                continue;
            }
            temp_t2 = var_t1_x + var_s4 + 1;
            for (var_t3 = 0; var_t3 < 4; var_t3++) {
                s32 new_a1 = var_t3 * 0x24 * 4;

                if ((s32) ((var_t3 * 0x240 + (s32) (sp10[var_t9] * 4.0f)) * D_80115604_2860D4_vine_with_me + D_80115608_2860D8_vine_with_me) < 0xA00) {
                    if ((s32) ((var_t1_x + var_t9 * 0x79) * 4 * D_80115604_2860D4_vine_with_me + D_80115638_286108_vine_with_me) < 0x780) {
                        gSPScisTextureRectangle(gMainGfxPos++,
                            (s32) ((var_t3 * 0x24 * 4 * 4 + (s32) (sp10[var_t9] * 4.0f)) * D_80115604_2860D4_vine_with_me + D_80115608_2860D8_vine_with_me),
                            (s32) ((var_t1_x + var_t9 * 0x79) * 4 * D_80115604_2860D4_vine_with_me + D_80115638_286108_vine_with_me),
                            (s32) (((new_a1 + 0x7C) * 4 + (s32) (sp10[var_t9] * 4.0f)) * D_80115604_2860D4_vine_with_me + D_80115608_2860D8_vine_with_me),
                            (s32) (((temp_t2 >= 0x1D) ? (var_t9 * 0x79 * 4 + 0x6E) : ((temp_t2 + var_t9 * 0x79) * 4)) * D_80115604_2860D4_vine_with_me + D_80115638_286108_vine_with_me),
                            0, 0, var_t8 * var_s4 * 32, (s32) (D_80115558_286028_vine_with_me * 1024.0f), (s32) (D_80115558_286028_vine_with_me * 1024.0f));
                    }
                }
            }
        }
    }
    temp_t1 = HuSprGet(D_800CD1DC_CDDDC[D_80115640_286110_vine_with_me.unk00[5]].unk04, 0);
    temp_s5 = &temp_t1->unk_84->unk00[temp_t1->unk_90];
    gDPLoadTLUT_pal16(gMainGfxPos++, 0, temp_t1->unk_84->unk0C);
    gDPSetRenderMode(gMainGfxPos++, G_RM_AA_OPA_SURF, G_RM_AA_OPA_SURF2);
    gDPSetAlphaCompare(gMainGfxPos++, G_AC_NONE);
    gDPSetBlendColor(gMainGfxPos++, 0x00, 0x00, 0x00, 0x00);
    for (var_t3 = 0; var_t3 < 6; var_t3++) {
        gDPLoadTextureTile_4b(gMainGfxPos++, temp_s5->unk00, G_IM_FMT_CI, 320, 0,
            var_t3 * 0x3B, 0, var_t3 * 0x3B + 0x3C, 0x22, 0,
            G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        temp_3b = var_t3 * 0x3B;
        var_v1_2 = temp_3b + 0x3C;
        var_v1_2 = MIN(0x140, var_v1_2);
        if ((s32) (temp_3b * 4 * D_80115604_2860D4_vine_with_me + D_80115608_2860D8_vine_with_me) < 0xA00) {
            if ((s32) (D_80115604_2860D4_vine_with_me * 412.0f + D_80115638_286108_vine_with_me) < 0x780) {
                gDPLoadTLUT_pal16(gMainGfxPos++, 0, temp_t1->unk_84->unk0C);
                gSPScisTextureRectangle(gMainGfxPos++,
                    (s32) (temp_3b * 4 * D_80115604_2860D4_vine_with_me + D_80115608_2860D8_vine_with_me),
                    (s32) (D_80115604_2860D4_vine_with_me * 412.0f + D_80115638_286108_vine_with_me),
                    (s32) (var_v1_2 * 4 * D_80115604_2860D4_vine_with_me + D_80115608_2860D8_vine_with_me),
                    (s32) (D_80115604_2860D4_vine_with_me * 548.0f + D_80115638_286108_vine_with_me),
                    0, temp_3b * 32, 0, (s32) (D_80115558_286028_vine_with_me * 1024.0f), (s32) (D_80115558_286028_vine_with_me * 1024.0f));
            }
        }
    }
    gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    gDPSetRenderMode(gMainGfxPos++, G_RM_AA_XLU_SURF, G_RM_AA_XLU_SURF2);
    gDPSetAlphaCompare(gMainGfxPos++, G_AC_THRESHOLD);
    gDPSetBlendColor(gMainGfxPos++, 0x00, 0x00, 0x00, 0xE0);
    for (var_s1 = 0; var_s1 < 2; var_s1++) {
        temp_s2 = (D_80115540_286010_vine_with_me[var_s1] * (1.0 - D_80115548_286018_vine_with_me[var_s1] / 20.0) + D_801155FC_2860CC_vine_with_me[var_s1] * (D_80115548_286018_vine_with_me[var_s1] / 20.0)) * 14.0 + 32.0;
        temp_t1 = HuSprGet(D_800CD1DC_CDDDC[D_80115640_286110_vine_with_me.unk00[6 + D_80115530_286000_vine_with_me[var_s1]->unk03]].unk04, 0);
        temp_s5 = new_s5 = &temp_t1->unk_84->unk00[temp_t1->unk_90];
        if (D_80115530_286000_vine_with_me[var_s1]->unk03 == 7) {
            gDPLoadTLUT_pal256(gMainGfxPos++, temp_t1->unk_84->unk0C);
        } else {
            gDPLoadTLUT_pal16(gMainGfxPos++, 0, temp_t1->unk_84->unk0C);
        }
        if ((s32) (temp_s2 * 4 * D_80115604_2860D4_vine_with_me + D_80115608_2860D8_vine_with_me) < 0xA00 && (s32) ((var_s1 * 64 + 0x1A0) * D_80115604_2860D4_vine_with_me + D_80115638_286108_vine_with_me) < 0x780) {
            if (D_80115530_286000_vine_with_me[var_s1]->unk03 == 7) {
                gDPLoadTextureTile(gMainGfxPos++, temp_s5->unk00, G_IM_FMT_CI, G_IM_SIZ_8b, 18, 0, 0, 0, 18, 18, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            } else {
                gDPLoadTextureTile_4b(gMainGfxPos++, temp_s5->unk00, G_IM_FMT_CI, 18, 0, 0, 0, 18, 18, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            }
            gSPScisTextureRectangle(gMainGfxPos++,
                (s32) (temp_s2 * 4 * D_80115604_2860D4_vine_with_me + D_80115608_2860D8_vine_with_me),
                (s32) ((var_s1 * 0x12 + 0x66) * 4 * D_80115604_2860D4_vine_with_me + D_80115638_286108_vine_with_me),
                (s32) ((temp_s2 + 0x12) * 4 * D_80115604_2860D4_vine_with_me + D_80115608_2860D8_vine_with_me),
                (s32) (((var_s1 * 0x12 + 0x78) * 4 - 3) * D_80115604_2860D4_vine_with_me + D_80115638_286108_vine_with_me),
                0, 0, 0, (s32) (D_80115558_286028_vine_with_me * 1024.0f), (s32) (D_80115558_286028_vine_with_me * 1024.0f));
            }
    }
    gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
    if (D_8011563C_28610C_vine_with_me >= 3 && D_8011558C_28605C_vine_with_me < 2) {
        temp_t1 = HuSprGet(D_800CD1DC_CDDDC[D_80115640_286110_vine_with_me.unk00[15]].unk04, 0);
        temp_s5 = &temp_t1->unk_84->unk00[temp_t1->unk_90];
        gDPSetTextureLUT(gMainGfxPos++, G_TT_NONE);
        for (var_t8 = 0; var_t8 < 4; var_t8++) {
            gDPLoadTextureTile(gMainGfxPos++, temp_s5->unk00, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 0,
                0, var_t8 * 8, 64, var_t8 * 8 + 8 + (var_t8 != 3), 0,
                G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            for (var_a2 = 0; var_a2 < 2; var_a2++) {
                s32 temp_s32;
                s32 temp_37 = 0x37;

                if (D_801155A4_286074_vine_with_me[var_a2] < 5) {
                    continue;
                }
                temp_s32 = (-D_801155A4_286074_vine_with_me[var_a2] + 7) * 0x240 + 0x1E4;
                temp_a3_3 = temp_s32 + (s32) ((12.0 - D_801155D8_2860A8_vine_with_me[var_a2][2] * 0.16) * 4.0);
                if ((s32) (temp_a3_3 * D_80115604_2860D4_vine_with_me + D_80115608_2860D8_vine_with_me) >= 0xA00) {
                    continue;
                }
                if ((s32) ((var_a2 * 0x7D + (var_t8 * 8 + (temp_37 - 2))) * 4 * D_80115604_2860D4_vine_with_me + D_80115638_286108_vine_with_me) >= 0x780) {
                    continue;
                }
                gSPScisTextureRectangle(gMainGfxPos++,
                    (s32) (temp_a3_3 * D_80115604_2860D4_vine_with_me + D_80115608_2860D8_vine_with_me),
                    (s32) ((var_a2 * 0x7D + (var_t8 * 8 + temp_37)) * 4 * D_80115604_2860D4_vine_with_me + D_80115638_286108_vine_with_me),
                    (s32) ((temp_a3_3 + 0xFC) * D_80115604_2860D4_vine_with_me + D_80115608_2860D8_vine_with_me),
                    (s32) ((var_a2 * 0x7D + (var_t8 * 8 + temp_37) + 7 + (var_t8 != 3 ? 2 : 0)) * 4 * D_80115604_2860D4_vine_with_me + D_80115638_286108_vine_with_me),
                    0, 0, var_t8 * 256, (s32) (D_80115558_286028_vine_with_me * 1024.0f), (s32) (D_80115558_286028_vine_with_me * 1024.0f));
            }
        }
    }
    gDPPipeSync(gMainGfxPos++);
    gDPSetBlendColor(gMainGfxPos++, 0xFF, 0xFF, 0xFF, 0x00);
    gDPPipeSync(gMainGfxPos++);
}
#else
INCLUDE_ASM("asm/nonmatchings/overlays/ovl_31_vine_with_me/276470", func_8010ADB0_27B880_vine_with_me);
#endif

void func_8010CEA8_27D978_vine_with_me(omObjData* arg0) {
    func_8010CF18_27D9E8_vine_with_me(arg0, 0, 0);
    arg0->func = func_8010D46C_27DF3C_vine_with_me;
}

void func_8010CEE0_27D9B0_vine_with_me(omObjData* arg0) {
    func_8010CF18_27D9E8_vine_with_me(arg0, 1, 1);
    arg0->func = func_8010D48C_27DF5C_vine_with_me;
}

void func_8010CF18_27D9E8_vine_with_me(omObjData* arg0, s8 arg1, s32 arg2) {
    s32 sp10[] = { 2, 3, 7, 4, 5, 6, 8, 9 };
    s32 sp30[] = { 162, 162, 162, 162, 162, 162, 162, 3 };
    s32 sp50[] = { 160, 160, 160, 160, 160, 160, 160, 0 };
    s32 sp70[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
    s32 sp90[][8] = {
        { 164, 164, 164, 164, 164, 164, 164, 27 },
        { 165, 165, 165, 165, 165, 165, 165, 28 }
    };
    u16 temp_v0;
    u16 var_s1;

    temp_v0 = D_80115530_286000_vine_with_me[arg1]->unk03;
    arg0->model[0] = func_8000B108_BD08((sp10[temp_v0] << 16) | sp30[temp_v0], 0x4B9);
    arg0->model[1] = func_8000B108_BD08((sp10[temp_v0] << 16) | sp50[temp_v0], 0x4AD);
    D_80115530_286000_vine_with_me[arg1]->unk06 = func_80017790_18390(arg0->model[1], 1, sp70[temp_v0], (sp10[temp_v0] << 16) | sp90[0][temp_v0]);
    D_80115530_286000_vine_with_me[arg1]->unk08 = func_80017AD8_186D8((sp10[temp_v0] << 16) | sp90[1][temp_v0]);
    func_8001C514_1D114(arg0->model[1]);
    D_80115530_286000_vine_with_me[arg1]->unk0C = (rand8() & 1) ? 0x2F : 0x30;
    func_8000B460_C060(arg0, 0, func_80017BB8_187B8(temp_v0, 0));
    func_8000B460_C060(arg0, 1, func_80017BB8_187B8(temp_v0, 0x42));
    func_8000B460_C060(arg0, 2, func_80017BB8_187B8(temp_v0, 0x43));
    func_8000B460_C060(arg0, 3, func_80017BB8_187B8(temp_v0, (temp_v0 == 5) ? 5 : 0x1F));
    func_8000B460_C060(arg0, 4, func_80017BB8_187B8(temp_v0, 0x1F));
    func_8000B460_C060(arg0, 5, func_80017BB8_187B8(temp_v0, D_80115530_286000_vine_with_me[arg1]->unk0C));
    func_8000B460_C060(arg0, 6, func_80017BB8_187B8(temp_v0, 0x3A));
    D_80115530_286000_vine_with_me[arg1]->unk0C |= (sp10[temp_v0] << 16);
    func_8001C2FC_1CEFC(arg0->model[0], 0x600, 0x400);
    func_8001C2FC_1CEFC(arg0->model[1], 0x600, 0x400);
    func_8001C5B4_1D1B4(arg0->model[0], arg0->motion[1]);
    func_8001C814_1D414(arg0->model[0], 2, 2);
    func_8001C8A8_1D4A8(arg0->model[0], (arg1 != 0) ? 2 : 1);
    func_8001C8A8_1D4A8(arg0->model[1], (arg1 != 0) ? 2 : 1);
    for (var_s1 = 0; var_s1 < 24; var_s1++) {
        if (var_s1 == 0) {
            arg0->model[2] = func_8000B108_BD08(0x520000, 0x4B9);
        } else {
            arg0->model[var_s1 + 2] = Hu3DModelLink(arg0->model[2]);
        }
        Hu3DModelPosSet(arg0->model[var_s1 + 2], 0.0f, var_s1 * -50.0, 0.0f);
        Hu3DModelRotSet(arg0->model[var_s1 + 2], 0.0f, 0.0f, 0.0f);
        Hu3DModelScaleSet(arg0->model[var_s1 + 2], 1.0f, 1.0f, 1.0f);
        func_8001C8A8_1D4A8(arg0->model[var_s1 + 2], (arg1 != 0) ? 2 : 1);
    }
    D_801155B8_286088_vine_with_me = 0;
}

void func_8010D46C_27DF3C_vine_with_me(omObjData* arg0) {
    func_8010D4AC_27DF7C_vine_with_me(arg0, 0, 0);
}

void func_8010D48C_27DF5C_vine_with_me(omObjData* arg0) {
    func_8010D4AC_27DF7C_vine_with_me(arg0, 1, 1);
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
void func_8010D4AC_27DF7C_vine_with_me(omObjData* arg0, s8 arg1, s8 arg2) {
    f32 sp18[6];
    f32 sp30[6];
    f32 sp48[6];
    f32 sp60[6][9];
    f32 sp138[6][9];
    f32 sp210[6][9];
    D_80115510_285FE0_Struct* sp3C4;
    f32 sp3CC;
    s8 sp3D7;
    s32 sp3DC;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f12_5;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_5;
    f32 temp_f2_17;
    f32 temp_f2_4;
    f32 temp_f2_7;
    f32 temp_f4_5;
    f32 temp_f6_3;
    f32 temp_f6_4;
    f32 var_f24;
    f32 var_f26;
    f32 var_f4_2;
    f32 var_f4_3;
    f32 var_f6;
    f32 var_f8;
    f64 var_f4;
    s32 temp_f0_13;
    s32 temp_f0_5;
    s32 temp_s0;
    s32 temp_t1;
    s32 temp_t2;
    s32 temp_t6;
    s32 temp_v1_19;
    s32 var_a0_2;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_s5;
    s32 var_s7;
    s32 var_t7;
    s32 var_v1_2;
    s8 var_s6;
    u32 temp_fp;

    sp3C4 = D_80115530_286000_vine_with_me[arg2];
    sp3CC = D_80111C60_282730_vine_with_me[arg1];
    sp3D7 = 0;
    sp3DC = D_80111CA4_282774_vine_with_me / 14;
    sp3DC = D_80111CA4_282774_vine_with_me % 14;
    if (D_80111CA4_282774_vine_with_me == 0 && arg2 == 0) {
        s32 sp2E8[] = { 2, 4, 3, 4, 2 };

        for (var_s4 = 0; var_s4 < 15; var_s4++) {
            do {
                var_s5 = (rand8() % 5) & 0xFF;
            } while (sp2E8[var_s5] == 0);
            sp2E8[var_s5]--;
            D_80111C44_282714_vine_with_me[var_s4 + 1] = var_s5 + 4;
        }
        for (var_s4 = 0; var_s4 < 2; var_s4++) {
            for (var_s5 = 0; var_s5 < 5; var_s5++) {
                D_80111C2C_2826FC_vine_with_me[var_s4][var_s5 + 1] = D_80111C44_282714_vine_with_me[var_s5 + 1];
            }
        }
    }
    if (D_80111CA4_282774_vine_with_me == 0) {
        sp3CC = 900.0f;
    }
    if (D_80111CA4_282774_vine_with_me == 0x2A) {
        sp3D7 = 1;
    } else if (D_80111CA4_282774_vine_with_me < 0x56 || D_8011563C_28610C_vine_with_me >= 3) {
        sp3D7 = -1;
    }
    if (arg2 == 0) {
        for (var_s7 = (D_80111CA4_282774_vine_with_me != 0) * 13; var_s7 < 14; var_s7++) {
            temp_s0 = (var_s7 + D_80111CA4_282774_vine_with_me) % 14;
            temp_fp = var_s7 + D_80111CA4_282774_vine_with_me;
            for (var_s5 = 0; var_s5 < 5; var_s5++) {
                f32 sp300[] = { 8.75f, 7.75f, 6.5f, 5.25f, 4.0f };

                var_f24 = 0.0f;
                var_f26 = 0.0f;
                temp_f0 = HuMathSin(temp_fp * sp300[var_s5] * 0.9375) * -80.0 - 90.0;
                for (var_s4 = 0; var_s4 < var_s5 + 4; var_s4++) {
                    if (temp_f0 > 90.0) {
                        temp_f20 = temp_f0 - 270.0;
                    } else {
                        temp_f20 = temp_f0 + 90.0;
                    }
                    temp_f20 = temp_f20 * ((f32) var_s4 * 0.25 / 10.0 + 0.75) - 90.0;
                    D_801125D0_2830A0_vine_with_me[var_s5][var_s4][temp_s0] = var_f26;
                    D_80113590_284060_vine_with_me[var_s5][var_s4][temp_s0] = var_f24;
                    D_80114550_285020_vine_with_me[var_s5][var_s4][temp_s0] = temp_f20;
                    var_f26 += HuMathCos(temp_f20) * 50.0;
                    var_f24 += HuMathSin(temp_f20) * 50.0;
                }
                D_801125D0_2830A0_vine_with_me[var_s5][var_s4][temp_s0] = var_f26;
                D_80113590_284060_vine_with_me[var_s5][var_s4][temp_s0] = var_f24;
                D_80114550_285020_vine_with_me[var_s5][var_s4][temp_s0] = D_80114550_285020_vine_with_me[var_s5][var_s4 - 1][temp_s0];
            }
        }
    }
    D_80111C8C_28275C_vine_with_me[arg1] = (D_80111C68_282738_vine_with_me[arg1] > D_80111C60_282730_vine_with_me[arg1])
        ? ((D_80111C68_282738_vine_with_me[arg1] - D_80111C60_282730_vine_with_me[arg1]) * 0.0625 + 20.0)
        : 20.0f;
    if (!(D_80111C80_282750_vine_with_me[arg1] >= 10.0f)
        && (D_8011563C_28610C_vine_with_me != 0)
        && (D_8011563C_28610C_vine_with_me != 1 || D_801155D0_2860A0_vine_with_me >= 5))
    {
        if (D_80111C70_282740_vine_with_me[arg1] > -550.0) {
            if (D_80111C3C_28270C_vine_with_me[arg1] == 1) {
                f64 fake_ft0 = D_80111C38_282708_vine_with_me[arg1] * 450.0 + 400.0;

                var_f4 = fake_ft0;
                if (D_80111C60_282730_vine_with_me[arg1] < var_f4 && D_80111C8C_28275C_vine_with_me[arg1] > 0.0) {
                    D_80111C60_282730_vine_with_me[arg1] = MIN(var_f4, D_80111C60_282730_vine_with_me[arg1] + D_80111C8C_28275C_vine_with_me[arg1]);
                }
            } else {
                f64 fake_ft0 = D_80111C68_282738_vine_with_me[arg1] + 400.0;

                var_f4 = fake_ft0;
                if (D_80111C60_282730_vine_with_me[arg1] < var_f4 && D_80111C8C_28275C_vine_with_me[arg1] > 0.0) {
                    D_80111C60_282730_vine_with_me[arg1] = MIN(var_f4, D_80111C60_282730_vine_with_me[arg1] + D_80111C8C_28275C_vine_with_me[arg1]);
                }
            }
        }
    }
    if (D_80111C5C_28272C_vine_with_me[arg1] <= 0 && D_80111C60_282730_vine_with_me[arg1] <= 550.0f) {
        D_80111C60_282730_vine_with_me[arg1] += -D_80111C5C_28272C_vine_with_me[arg1] * 450.0 - (D_80111C60_282730_vine_with_me[arg1] - 550.0);
    }
    if (D_80111C5C_28272C_vine_with_me[arg1] >= 12 && D_80111C60_282730_vine_with_me[arg1] >= 1250.0f) {
        D_80111C60_282730_vine_with_me[arg1] -= (D_80111C5C_28272C_vine_with_me[arg1] - 12) * 450.0 + D_80111C60_282730_vine_with_me[arg1] - 1250.0;
    }
    if (D_80111C60_282730_vine_with_me[arg1] > 1375.0) {
        D_80111C60_282730_vine_with_me[arg1] -= 450.0;
        sp3CC -= 450.0;
        D_80111C68_282738_vine_with_me[arg1] -= 450.0;
        D_801125A8_283078_vine_with_me[arg1] -= 450.0;
        D_80111C5C_28272C_vine_with_me[arg1]++;
        if (D_80111C80_282750_vine_with_me[arg1] > 0.0f) {
            D_801125B8_283088_vine_with_me[arg1] -= 450.0;
            D_801125C0_283090_vine_with_me[arg1] -= 450.0;
            D_801125C8_283098_vine_with_me[arg1] -= 450.0;
        }
        for (var_s5 = 0; var_s5 < 8; var_s5++) {
            if (D_80115640_286110_vine_with_me.unk22[var_s5] == arg1) {
                D_80115610_2860E0_vine_with_me[var_s5] -= 450.0;
            }
        }
        D_80111C38_282708_vine_with_me[arg1]--;
        D_80111C40_282710_vine_with_me[arg1] = (D_80111C40_282710_vine_with_me[arg1] == 0);
        for (var_s5 = 0; var_s5 < 5; var_s5++) {
            D_80111C2C_2826FC_vine_with_me[arg1][var_s5] = D_80111C2C_2826FC_vine_with_me[arg1][var_s5 + 1];
        }
        D_80111C2C_2826FC_vine_with_me[arg1][5] = D_80111C44_282714_vine_with_me[D_80111C5C_28272C_vine_with_me[arg1] + 5];
    }
    if (D_80111C60_282730_vine_with_me[arg1] < 875.0
        && D_80111C5C_28272C_vine_with_me[arg1] > 0
        && (D_8011563C_28610C_vine_with_me != 0 || D_80111C3C_28270C_vine_with_me[arg1] != 2))
    {
        D_80111C60_282730_vine_with_me[arg1] += 450.0;
        sp3CC += 450.0;
        D_80111C68_282738_vine_with_me[arg1] += 450.0;
        D_801125A8_283078_vine_with_me[arg1] += 450.0;
        D_80111C5C_28272C_vine_with_me[arg1]--;
        if (D_80111C80_282750_vine_with_me[arg1] > 0.0f) {
            D_801125B8_283088_vine_with_me[arg1] += 450.0;
            D_801125C0_283090_vine_with_me[arg1] += 450.0;
            D_801125C8_283098_vine_with_me[arg1] += 450.0;
        }
        for (var_s5 = 0; var_s5 < 8; var_s5++) {
            if (D_80115640_286110_vine_with_me.unk22[var_s5] == arg1) {
                D_80115610_2860E0_vine_with_me[var_s5] += 450.0;
            }
        }
        D_80111C38_282708_vine_with_me[arg1]++;
        D_80111C40_282710_vine_with_me[arg1] = (D_80111C40_282710_vine_with_me[arg1] == 0);
        for (var_s5 = 5; var_s5 > 0; var_s5--) {
            D_80111C2C_2826FC_vine_with_me[arg1][var_s5] = D_80111C2C_2826FC_vine_with_me[arg1][var_s5 - 1];
        }
        D_80111C2C_2826FC_vine_with_me[arg1][0] = D_80111C44_282714_vine_with_me[D_80111C5C_28272C_vine_with_me[arg1]];
    }
    for (var_s5 = 0; var_s5 < 6; var_s5++) {
        for (var_s4 = 0; var_s4 < 4; var_s4++) {
            func_8001C258_1CE58(arg0->model[2 + var_s5 * 4 + var_s4], 4, 4);
        }
    }
    for (var_s4 = 0; var_s4 < 5; var_s4++) {
        if (D_8011563C_28610C_vine_with_me >= 4
            && D_8011558C_28605C_vine_with_me != 2
            && D_801155D0_2860A0_vine_with_me >= 30
            && (s32) (-D_80114550_285020_vine_with_me[var_s4][0][sp3DC] + 540.0f) % 360 < 271)
        {
            D_80111C9C_28276C_vine_with_me[var_s4] = 1;
        }
    }
    for (var_s5 = 0; var_s5 < 6; var_s5++) {
        temp_t1 = (D_80111C40_282710_vine_with_me[arg1] + var_s5) % 2;
        temp_t6 = 1 - ((D_80111C40_282710_vine_with_me[arg1] + var_s5) % 2) * 2;
        var_t7 = (D_80111C60_282730_vine_with_me[arg1] < 900.0f);
        if (D_80111C2C_2826FC_vine_with_me[arg1][var_s5] != 0) {
            sp18[var_s5] = var_s5 * 450.0;
            sp30[var_s5] = 0.0f;
            for (var_s4 = 0; var_s4 < D_80111C2C_2826FC_vine_with_me[arg1][var_s5]; var_s4++) {
                sp60[var_s5][var_s4] = sp18[var_s5] + D_801125D0_2830A0_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5] - 4][var_s4][sp3DC] * temp_t6;
                sp138[var_s5][var_s4] = D_80112DB0_283880_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5]][var_s4][sp3DC];
                sp210[var_s5][var_s4 + 1] = (temp_t1 != 0)
                    ? (-D_80113D70_284840_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5]][var_s4][sp3DC] + 540.0f)
                    : D_80113D70_284840_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5]][var_s4][sp3DC];
            }
            sp18[var_s5] += D_801125D0_2830A0_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5] - 4][var_s4][sp3DC] * temp_t6;
            sp60[var_s5][var_s4] = sp18[var_s5];
            sp30[var_s5] = sp138[var_s5][var_s4] = D_80112DB0_283880_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5]][var_s4][sp3DC];
            sp210[var_s5][0] = sp210[var_s5][1];
            sp48[var_s5] = (temp_t1 != 0)
                ? (-D_80113D70_284840_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5]][var_s4][sp3DC] + 540.0f)
                : D_80113D70_284840_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5]][var_s4][sp3DC];
            for (var_s4 = 0; var_s4 < D_80111C2C_2826FC_vine_with_me[arg1][var_s5]; var_s4 += 2) {
                var_v1_2 = (var_s4 + 1 == D_80111C2C_2826FC_vine_with_me[arg1][var_s5]) ? 1 : 2;
                temp_f2_4 = sp60[var_s5][var_s4 + var_v1_2] - sp60[var_s5][var_s4];
                temp_f12 = sp138[var_s5][var_s4 + var_v1_2] - sp138[var_s5][var_s4];
                temp_f20_2 = HuSqrtf(temp_f2_4 * temp_f2_4 + temp_f12 * temp_f12);
                Hu3DModelPosSet(arg0->model[2 + var_s5 * 4 + (var_s4 >> 1)], sp60[var_s5][var_s4] - (var_t7 && var_s5 == 5) * 450.0 * 6.0, sp138[var_s5][var_s4], 0.0f);
                Hu3DModelRotSet(arg0->model[2 + var_s5 * 4 + (var_s4 >> 1)], 0.0f, 0.0f, (sp210[var_s5][var_s4 + 1] + sp210[var_s5][var_s4 + var_v1_2]) / 2.0 + 90.0);
                Hu3DModelScaleSet(arg0->model[2 + var_s5 * 4 + (var_s4 >> 1)], 1.0f, temp_f20_2 / 50.0, 1.0f);
                if (D_80111C2C_2826FC_vine_with_me[arg1][var_s5] >= 4 && D_80111C98_282768_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5]] == 0) {
                    func_8001C258_1CE58(arg0->model[2 + var_s5 * 4 + (var_s4 >> 1)], 4, 0);
                }
            }
            for (; var_s4 < 8; var_s4 += 2) {
                func_8001C258_1CE58(arg0->model[2 + var_s5 * 4 + (var_s4 >> 1)], 4, 4);
            }
        }
    }
    if (D_80111C3C_28270C_vine_with_me[arg1] == 1) {
        D_80111C98_282768_vine_with_me[arg1] += (D_80111C98_282768_vine_with_me[arg1] < 0xFF);
        if (D_80111C78_282748_vine_with_me[arg1] < D_80111C2C_2826FC_vine_with_me[arg1][D_80111C38_282708_vine_with_me[arg1]]
            && D_80111C78_282748_vine_with_me[arg1] + 0.4375 >= D_80111C2C_2826FC_vine_with_me[arg1][D_80111C38_282708_vine_with_me[arg1]])
        {
            func_8001C624_1D224(arg0->model[0], HmfModelData[arg0->motion[1]].unk02, 0, 4, 2);
        }
        D_80111C78_282748_vine_with_me[arg1] += 0.4375;
        if (D_80111C2C_2826FC_vine_with_me[arg1][D_80111C38_282708_vine_with_me[arg1]] <= D_80111C78_282748_vine_with_me[arg1]) {
            D_80111C78_282748_vine_with_me[arg1] = D_80111C2C_2826FC_vine_with_me[arg1][D_80111C38_282708_vine_with_me[arg1]];
            if (D_80111C94_282764_vine_with_me[arg1] >= 0xFF) {
                D_80111C94_282764_vine_with_me[arg1] = 0xF;
            }
        }
        temp_f2_7 = D_80111C78_282748_vine_with_me[arg1];
        temp_f0_5 = temp_f2_7;
        temp_f6_3 = temp_f2_7 - temp_f0_5;
        D_80111C68_282738_vine_with_me[arg1] = (temp_f6_3 == 0.0)
            ? sp60[D_80111C38_282708_vine_with_me[arg1]][temp_f0_5]
            : (sp60[D_80111C38_282708_vine_with_me[arg1]][temp_f0_5] * (1.0 - temp_f6_3) + temp_f6_3 * sp60[D_80111C38_282708_vine_with_me[arg1]][temp_f0_5 + 1]);
        D_80111C70_282740_vine_with_me[arg1] = (temp_f6_3 == 0.0)
            ? sp138[D_80111C38_282708_vine_with_me[arg1]][temp_f0_5]
            : (sp138[D_80111C38_282708_vine_with_me[arg1]][temp_f0_5] * (1.0 - temp_f6_3) + temp_f6_3 * sp138[D_80111C38_282708_vine_with_me[arg1]][temp_f0_5 + 1]);
        D_80112590_283060_vine_with_me[arg1] = (temp_f6_3 == 0.0)
            ? sp210[D_80111C38_282708_vine_with_me[arg1]][temp_f0_5]
            : (sp210[D_80111C38_282708_vine_with_me[arg1]][temp_f0_5] * (1.0 - temp_f6_3) + temp_f6_3 * sp210[D_80111C38_282708_vine_with_me[arg1]][temp_f0_5 + 1]);
        if (D_80111C94_282764_vine_with_me[arg1] == 0) {
            if (sp3D7 != -1) {
                if (sp3C4->unk04 != -1) {
                    f32 var_f24_2 = D_80111C68_282738_vine_with_me[arg1];
                    f32 var_f20 = D_80111C70_282740_vine_with_me[arg1];
                    f32 temp_f28 = (var_f24_2 - D_801125A8_283078_vine_with_me[arg1]) * 1.25;
                    f32 var_f26_2 = (var_f20 - D_801125B0_283080_vine_with_me[arg1]) * 1.25;
                    f32 sp318[10];
                    f32 sp340[10];
                    f32 sp368[10];
                    u8 sp390[4] = { 4, 4, 6, 9 };
                    u8 sp398[4] = { 0x96, 0x5A, 0x3C, 0x14 };
                    u8 sp3A0[4] = { 14, 6, 3, 2 };

                    if (D_80111C98_282768_vine_with_me[arg1] >= sp398[sp3C4->unk04]) {
                        if (rand8() % sp3A0[sp3C4->unk04] == 0 || D_80111C38_282708_vine_with_me[arg1] + D_80111C5C_28272C_vine_with_me[arg1] == 0xF) {
                            for (var_s6 = 0; var_s6 < 14; var_s6++) {
                                if (var_s6 < sp390[sp3C4->unk04]) {
                                    temp_v1_19 = D_80111C38_282708_vine_with_me[arg1] + 1;
                                    if (temp_v1_19 < 6) {
                                        var_s5 = temp_v1_19;
                                    } else {
                                        var_s5 = 5;
                                    }
                                    for (; var_s5 > D_80111C38_282708_vine_with_me[arg1]; var_s5--) {
                                        temp_t1 = (D_80111C40_282710_vine_with_me[arg1] + var_s5) % 2;
                                        temp_t2 = 1 - ((D_80111C40_282710_vine_with_me[arg1] + var_s5) % 2) * 2;
                                        if (D_80111C2C_2826FC_vine_with_me[arg1][var_s5] != 0) {
                                            temp_f4_5 = var_s5 * 450.0;
                                            for (var_s4 = 0; var_s4 < D_80111C2C_2826FC_vine_with_me[arg1][var_s5]; var_s4++) {
                                                sp318[var_s4] = temp_f4_5 + D_801125D0_2830A0_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5] - 4][var_s4][sp3DC + var_s6] * temp_t2;
                                                sp340[var_s4] = D_80112DB0_283880_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5]][var_s4][sp3DC + var_s6];
                                                sp368[var_s4 + 1] = (temp_t1 != 0)
                                                    ? (-D_80113D70_284840_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5]][var_s4][sp3DC + var_s6] + 540.0f)
                                                    : D_80113D70_284840_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5]][var_s4][sp3DC + var_s6];
                                            }
                                            temp_f4_5 += D_801125D0_2830A0_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5] - 4][var_s4][sp3DC + var_s6] * temp_t2;
                                            sp318[var_s4] = temp_f4_5;
                                            temp_f12_2 = D_80112DB0_283880_vine_with_me[D_80111C2C_2826FC_vine_with_me[arg1][var_s5]][var_s4][sp3DC + var_s6];
                                            sp340[var_s4] = temp_f12_2;
                                            sp368[0] = sp368[1];
                                            if (HuSqrtf((var_f24_2 - temp_f4_5) * (var_f24_2 - temp_f4_5) + (var_f20 - temp_f12_2) * (var_f20 - temp_f12_2)) < 90.0) {
                                                sp3D7 = 1;
                                                goto block_213c;
                                            }
                                            for (var_s4 = D_80111C2C_2826FC_vine_with_me[arg1][var_s5] - 1; var_s4 >= 0; var_s4--) {
                                                if (HuSqrtf((var_f24_2 - sp318[var_s4]) * (var_f24_2 - sp318[var_s4]) + (var_f20 - sp340[var_s4]) * (var_f20 - sp340[var_s4])) < 40.0) {
                                                    sp3D7 = 1;
                                                    goto block_213c;
                                                }
                                            }
                                        }
                                    }
                                }
                                var_f26_2 -= 2.5;
                                if (D_80111C98_282768_vine_with_me[arg1] >= sp398[sp3C4->unk04] + 30
                                    && var_f24_2 + temp_f28 < (-D_80111C5C_28272C_vine_with_me[arg1] + 12) * 450.0 + 1800.0 + 110.0
                                    && (-D_80111C5C_28272C_vine_with_me[arg1] + 12) * 450.0 + 1800.0 - 100.0 < var_f24_2 + temp_f28
                                    && var_f20 + var_f26_2 <= -182.5
                                    && var_f20 > -182.5)
                                {
                                    sp3D7 = 1;
                                    break;
                                }
                                var_f24_2 += temp_f28;
                                var_f20 += var_f26_2;
                            }
                        }
                    }
                } else if (sp3D7 != -1 && (D_800D5558_D6158[sp3C4->unk02] & 0x8000)) {
                    sp3D7 = 1;
                }
            }
block_213c:
            if (sp3D7 == 1) {
                D_80111C3C_28270C_vine_with_me[arg1] = 0;
                D_80112598_283068_vine_with_me[arg1] = D_80111C8C_28275C_vine_with_me[arg1] = (D_80111C68_282738_vine_with_me[arg1] - D_801125A8_283078_vine_with_me[arg1]) * 1.25;
                D_801125A0_283070_vine_with_me[arg1] = (D_80111C70_282740_vine_with_me[arg1] - D_801125B0_283080_vine_with_me[arg1]) * 1.25;
                func_8001C624_1D224(arg0->model[0], HmfModelData[arg0->motion[3]].unk02, 0, 7, sp3D7);
                var_f4_2 = D_80111C68_282738_vine_with_me[arg1];
                var_f8 = D_80111C70_282740_vine_with_me[arg1];
                temp_f12_5 = D_80112598_283068_vine_with_me[arg1];
                var_f6 = D_801125A0_283070_vine_with_me[arg1];
                for (var_a0_2 = 1; var_a0_2 < 60; var_a0_2++) {
                    var_f6 -= 2.5;
                    if ((-D_80111C5C_28272C_vine_with_me[arg1] + 12) * 450.0 + 1800.0 - 165.0 < var_f4_2 + temp_f12_5
                        && var_f8 + var_f6 <= -182.5
                        && var_f8 > -182.5)
                    {
                        break;
                    }
                    var_f4_2 += temp_f12_5;
                    var_f8 += var_f6;
                }
                if (D_80111C88_282758_vine_with_me != 0
                    && var_a0_2 < 60
                    && var_f4_2 + temp_f12_5 >= (-D_80111C5C_28272C_vine_with_me[arg1] + 12) * 450.0 + 1800.0 + 70.0)
                {
                    D_80112598_283068_vine_with_me[arg1] = ((-D_80111C5C_28272C_vine_with_me[arg1] + 12) * 450.0 + 1800.0 + 70.0 - D_80111C68_282738_vine_with_me[arg1]) / (f32) var_a0_2;
                }
            }
        }
    } else if (D_80111C3C_28270C_vine_with_me[arg1] == 0) {
        D_801125A0_283070_vine_with_me[arg1] -= 2.5;
        D_80111C68_282738_vine_with_me[arg1] += D_80112598_283068_vine_with_me[arg1];
        D_80111C70_282740_vine_with_me[arg1] += D_801125A0_283070_vine_with_me[arg1];
    } else if (D_80111C3C_28270C_vine_with_me[arg1] == 2 && D_80111CA4_282774_vine_with_me == 0x5C) {
        D_80111C3C_28270C_vine_with_me[arg1] = 0;
        D_80111C70_282740_vine_with_me[arg1] += 1.0;
        D_80112598_283068_vine_with_me[arg1] = 10.0f;
        D_801125A0_283070_vine_with_me[arg1] = 30.0f;
        func_8001C624_1D224(arg0->model[0], HmfModelData[arg0->motion[3]].unk02, 0, 4, 1);
    }
    if (D_80111C3C_28270C_vine_with_me[arg1] == 0) {
        if (D_80111C70_282740_vine_with_me[arg1] <= -812.5 || D_80111C80_282750_vine_with_me[arg1] > 0.0f) {
            if (D_80111C80_282750_vine_with_me[arg1] == 10.0f) {
                D_801125B8_283088_vine_with_me[arg1] = D_80111C68_282738_vine_with_me[arg1];
                D_801125C0_283090_vine_with_me[arg1] = D_80111C60_282730_vine_with_me[arg1];
                D_801125C8_283098_vine_with_me[arg1] = D_80111C38_282708_vine_with_me[arg1] * 450.0 + 400.0;
                if (D_80111C5C_28272C_vine_with_me[arg1] <= 0 && D_801125C8_283098_vine_with_me[arg1] <= 900.0f) {
                    D_801125C8_283098_vine_with_me[arg1] += -D_80111C5C_28272C_vine_with_me[arg1] * 450.0 - (D_801125C8_283098_vine_with_me[arg1] - 900.0);
                }
                if (D_80111C5C_28272C_vine_with_me[arg1] >= 12 && D_801125C8_283098_vine_with_me[arg1] >= 1250.0f) {
                    D_801125C8_283098_vine_with_me[arg1] -= (D_80111C5C_28272C_vine_with_me[arg1] - 12) * 450.0 + D_801125C8_283098_vine_with_me[arg1] - 1250.0;
                }
                D_80112598_283068_vine_with_me[arg1] = 0.0f;
                D_801125A0_283070_vine_with_me[arg1] = 65.0f;
                if (D_80111C68_282738_vine_with_me[arg1] < D_80111C60_282730_vine_with_me[arg1] - 900.0) {
                    D_801125B8_283088_vine_with_me[arg1] = D_80111C60_282730_vine_with_me[arg1] - 900.0;
                }
                if (D_80111C68_282738_vine_with_me[arg1] > D_80111C38_282708_vine_with_me[arg1] * 450.0 + 800.0) {
                    D_801125B8_283088_vine_with_me[arg1] = D_80111C38_282708_vine_with_me[arg1] * 450.0 + 800.0;
                }
                D_80112590_283060_vine_with_me[arg1] = atan2d(-D_801125A0_283070_vine_with_me[arg1] * 0.5, -(D_801125B8_283088_vine_with_me[arg1] * 0.96 + D_80111C38_282708_vine_with_me[arg1] * 450.0 * 0.04 - D_801125B8_283088_vine_with_me[arg1]) * 0.5);
                func_8001C5B4_1D1B4(arg0->model[0], arg0->motion[3]);
                func_8001C6A8_1D2A8(arg0->model[0], 0.0f);
                func_8001C814_1D414(arg0->model[0], 1, 1);
            }
            if (D_80111C80_282750_vine_with_me[arg1] == 20.0f) {
                for (var_s2 = 0, var_s3 = 0; var_s2 < 8; var_s2++) {
                    if (D_80115678_286148_vine_with_me[var_s2] == 90) {
                        D_80115678_286148_vine_with_me[var_s2] = (rand8() & 0xF) + 15;
                        D_80115640_286110_vine_with_me.unk22[var_s2] = arg1;
                        D_80115610_2860E0_vine_with_me[var_s2] = D_801125C8_283098_vine_with_me[arg1] + (var_s3 - 1.5) * 440.0 + (rand8() - 0x80);
                        var_s3++;
                        D_8011558D_28605D_vine_with_me[8 + var_s2] = rand8() & 3;
                        D_8011558D_28605D_vine_with_me[var_s2] = rand8() % 74;
                        if (var_s3 >= 4) {
                            break;
                        }
                    }
                }
            }
            if (D_80111C80_282750_vine_with_me[arg1] == 35.0f) {
                D_80111C80_282750_vine_with_me[arg1] = 0.0f;
                D_80111C94_282764_vine_with_me[arg1] = 0xFF;
                D_80111C3C_28270C_vine_with_me[arg1] = 1;
                D_80111C78_282748_vine_with_me[arg1] = 0;
                D_80111C68_282738_vine_with_me[arg1] = sp18[D_80111C38_282708_vine_with_me[arg1]];
                D_80111C70_282740_vine_with_me[arg1] = sp30[D_80111C38_282708_vine_with_me[arg1]];
                D_80112590_283060_vine_with_me[arg1] = sp48[D_80111C38_282708_vine_with_me[arg1]];
                func_8001C5B4_1D1B4(arg0->model[0], arg0->motion[2]);
                func_8001C814_1D414(arg0->model[0], 2, 2);
            } else {
                D_80111C80_282750_vine_with_me[arg1] += 1.0f;
                if (D_80111C80_282750_vine_with_me[arg1] == 10.0f && D_8011563C_28610C_vine_with_me >= 3) {
                    D_80111C80_282750_vine_with_me[arg1] -= 1.0f;
                }
                if (D_80111C80_282750_vine_with_me[arg1] == 1.0f) {
                    func_8004ACE0_4B8E0(0x286, D_80115670_286140_vine_with_me[arg1]);
                    func_8004AC98_4B898(0x493, arg1);
                    omVibrate(D_80115670_286140_vine_with_me[arg1], 0xA, 0, 0xA);
                    D_801155FA_2860CA_vine_with_me = 1;
                }
                if (D_80111C80_282750_vine_with_me[arg1] < 10.0f) {
                    D_80111C70_282740_vine_with_me[arg1] = -812.5f;
                    D_80112598_283068_vine_with_me[arg1] = D_801125A0_283070_vine_with_me[arg1] = 0.0f;
                } else if (D_80111C80_282750_vine_with_me[arg1] > 10.0f) {
                    D_80111C68_282738_vine_with_me[arg1] = D_801125B8_283088_vine_with_me[arg1] * ((35.0f - D_80111C80_282750_vine_with_me[arg1]) / 25.0) + D_80111C38_282708_vine_with_me[arg1] * 450.0 * ((D_80111C80_282750_vine_with_me[arg1] - 10.0f) / 25.0);
                    D_80111C60_282730_vine_with_me[arg1] = D_801125C0_283090_vine_with_me[arg1] * ((35.0f - D_80111C80_282750_vine_with_me[arg1]) / 25.0) + D_801125C8_283098_vine_with_me[arg1] * ((D_80111C80_282750_vine_with_me[arg1] - 10.0f) / 25.0);
                }
            }
        } else {
            if (D_80111C5C_28272C_vine_with_me[arg1] >= 8 || D_8011563C_28610C_vine_with_me == 0) {
                if (D_80111C5C_28272C_vine_with_me[arg1] < 8) {
                    temp_f20_3 = -D_80111C5C_28272C_vine_with_me[arg1] * 450.0 - 75.0 + 435.0;
                } else {
                    temp_f20_3 = (-D_80111C5C_28272C_vine_with_me[arg1] + 12) * 450.0 + 1800.0;
                }
                if (D_80111C5C_28272C_vine_with_me[arg1] >= 8
                    && temp_f20_3 + 75.0 - (D_80111C88_282758_vine_with_me == 0 ? 10.0 : 0.0) <= D_80111C68_282738_vine_with_me[arg1]
                    && D_801125A8_283078_vine_with_me[arg1] < temp_f20_3 + 75.0 - (D_80111C88_282758_vine_with_me == 0 ? 10.0 : 0.0)
                    && D_80111C70_282740_vine_with_me[arg1] > -182.5)
                {
                    D_80111C68_282738_vine_with_me[arg1] = temp_f20_3 + 70.0 - (D_80111C88_282758_vine_with_me == 0 ? 10.0 : 0.0);
                    D_80112590_283060_vine_with_me[arg1] = 275.0f;
                    D_80112598_283068_vine_with_me[arg1] /= 1.5;
                    func_8001C5B4_1D1B4(arg0->model[0], arg0->motion[4]);
                    func_8001C6A8_1D2A8(arg0->model[0], 8.0f);
                    func_8001C814_1D414(arg0->model[0], 1, 1);
                }
                if (D_80111C68_282738_vine_with_me[arg1] < temp_f20_3 + 135.0
                    && temp_f20_3 - 165.0 < D_80111C68_282738_vine_with_me[arg1]
                    && D_80111C70_282740_vine_with_me[arg1] <= -182.5
                    && D_801125B0_283080_vine_with_me[arg1] > -182.5)
                {
                    D_80111C3C_28270C_vine_with_me[arg1] = 2;
                    D_80111C68_282738_vine_with_me[arg1] =
                        (D_80111C68_282738_vine_with_me[arg1] > temp_f20_3 + 75.0) ? (temp_f20_3 + 75.0)
                        : (D_80111C68_282738_vine_with_me[arg1] < temp_f20_3 - 95.0) ? (temp_f20_3 - 95.0)
                        : D_80111C68_282738_vine_with_me[arg1];
                    D_80111C70_282740_vine_with_me[arg1] = (D_8011563C_28610C_vine_with_me == 0) ? -176.25f : -182.5f;
                    D_80112590_283060_vine_with_me[arg1] = 270.0f;
                    D_80112598_283068_vine_with_me[arg1] = 0.0f;
                    D_801125A0_283070_vine_with_me[arg1] = 0;
                    if (D_80111C5C_28272C_vine_with_me[arg1] >= 8) {
                        if (D_8011558C_28605C_vine_with_me == 4) {
                            D_8011558C_28605C_vine_with_me = (rand8() & 1) + 1;
                        }
                        if (D_80111C5C_28272C_vine_with_me[arg1] >= 8 && D_8011563C_28610C_vine_with_me == 2 && D_8011558C_28605C_vine_with_me == 0) {
                            D_8011558C_28605C_vine_with_me = (arg2 != 0) ? (arg1 + 1) : 4;
                        }
                    }
                    func_8001C5B4_1D1B4(arg0->model[0], arg0->motion[4]);
                    func_8001C6A8_1D2A8(arg0->model[0], 8.0f);
                    func_8001C814_1D414(arg0->model[0], 3, 0);
                    func_8001C624_1D224(arg0->model[0], HmfModelData[arg0->motion[0]].unk02, 0, 0x14, 2);
                    if (D_80111C5C_28272C_vine_with_me[arg1] < 8) {
                        func_8001C8E4_1D4E4(arg0->model[0], 0);
                    }
                    if (D_80111C5C_28272C_vine_with_me[arg1] >= 8
                        && (D_8011563C_28610C_vine_with_me == 2
                        || (D_8011563C_28610C_vine_with_me == 3 && D_801155D0_2860A0_vine_with_me < 30)))
                    {
                        D_801155F8_2860C8_vine_with_me[arg1] = 1;
                    }
                }
            }
            if (D_80111C3C_28270C_vine_with_me[arg1] == 0 && D_80111CA4_282774_vine_with_me >= 0x66) {
                for (var_s5 = 5; var_s5 > D_80111C38_282708_vine_with_me[arg1]; var_s5--) {
                    if (D_80111C2C_2826FC_vine_with_me[arg1][var_s5] == 0) {
                        continue;
                    }
                    if (HuSqrtf((D_80111C68_282738_vine_with_me[arg1] - sp18[var_s5]) * (D_80111C68_282738_vine_with_me[arg1] - sp18[var_s5]) + (D_80111C70_282740_vine_with_me[arg1] - sp30[var_s5]) * (D_80111C70_282740_vine_with_me[arg1] - sp30[var_s5])) < 90.0) {
                        D_80111C3C_28270C_vine_with_me[arg1] = 1;
                        D_80111C38_282708_vine_with_me[arg1] = var_s5;
                        D_80111C78_282748_vine_with_me[arg1] = D_80111C2C_2826FC_vine_with_me[arg1][var_s5];
                        D_80111C98_282768_vine_with_me[arg1] = 0;
                        D_80111C68_282738_vine_with_me[arg1] = sp18[D_80111C38_282708_vine_with_me[arg1]];
                        D_80111C70_282740_vine_with_me[arg1] = sp30[D_80111C38_282708_vine_with_me[arg1]];
                        D_80112590_283060_vine_with_me[arg1] = sp48[D_80111C38_282708_vine_with_me[arg1]];
                        func_8001C5B4_1D1B4(arg0->model[0], arg0->motion[1]);
                        func_8001C814_1D414(arg0->model[0], 2, 2);
                        if (D_80111C38_282708_vine_with_me[arg1] != 1) {
                            func_8004AC98_4B898(0x492, arg1);
                        }
                        break;
                    }
                    for (var_s4 = D_80111C2C_2826FC_vine_with_me[arg1][var_s5] - 1; var_s4 >= 0; var_s4--) {
                        if (HuSqrtf((D_80111C68_282738_vine_with_me[arg1] - sp60[var_s5][var_s4]) * (D_80111C68_282738_vine_with_me[arg1] - sp60[var_s5][var_s4]) + (D_80111C70_282740_vine_with_me[arg1] - sp138[var_s5][var_s4]) * (D_80111C70_282740_vine_with_me[arg1] - sp138[var_s5][var_s4])) < 40.0) {
                            D_80111C3C_28270C_vine_with_me[arg1] = 1;
                            D_80111C38_282708_vine_with_me[arg1] = var_s5;
                            D_80111C78_282748_vine_with_me[arg1] = var_s4;
                            D_80111C98_282768_vine_with_me[arg1] = 0;
                            D_80111C68_282738_vine_with_me[arg1] = sp18[D_80111C38_282708_vine_with_me[arg1]];
                            D_80111C70_282740_vine_with_me[arg1] = sp30[D_80111C38_282708_vine_with_me[arg1]];
                            D_80112590_283060_vine_with_me[arg1] = sp48[D_80111C38_282708_vine_with_me[arg1]];
                            func_8001C5B4_1D1B4(arg0->model[0], arg0->motion[2]);
                            func_8001C814_1D414(arg0->model[0], 2, 2);
                            if (D_80111C38_282708_vine_with_me[arg1] != 1) {
                                func_8004AC98_4B898(0x492, arg1);
                            }
                            break;
                        }
                        if (D_80111C3C_28270C_vine_with_me[arg1] == 1) {
                            break;
                        }
                    }
                }
            }
        }
    }
    if (D_8011558C_28605C_vine_with_me == 4 && arg2 == 1) {
        D_8011558C_28605C_vine_with_me = 2 - arg1;
    }
    if (D_80111C3C_28270C_vine_with_me[arg1] == 1) {
        temp_f2_17 = D_80111C78_282748_vine_with_me[arg1];
        temp_f0_13 = temp_f2_17;
        temp_f6_4 = temp_f2_17 - temp_f0_13;
        D_80111C68_282738_vine_with_me[arg1] = (temp_f6_4 == 0.0)
            ? sp60[D_80111C38_282708_vine_with_me[arg1]][temp_f0_13]
            : (sp60[D_80111C38_282708_vine_with_me[arg1]][temp_f0_13] * (1.0 - temp_f6_4) + temp_f6_4 * sp60[D_80111C38_282708_vine_with_me[arg1]][temp_f0_13 + 1]);
        D_80111C70_282740_vine_with_me[arg1] = (temp_f6_4 == 0.0)
            ? sp138[D_80111C38_282708_vine_with_me[arg1]][temp_f0_13]
            : (sp138[D_80111C38_282708_vine_with_me[arg1]][temp_f0_13] * (1.0 - temp_f6_4) + temp_f6_4 * sp138[D_80111C38_282708_vine_with_me[arg1]][temp_f0_13 + 1]);
        D_80112590_283060_vine_with_me[arg1] = (temp_f6_4 == 0.0)
            ? sp210[D_80111C38_282708_vine_with_me[arg1]][temp_f0_13]
            : (sp210[D_80111C38_282708_vine_with_me[arg1]][temp_f0_13] * (1.0 - temp_f6_4) + temp_f6_4 * sp210[D_80111C38_282708_vine_with_me[arg1]][temp_f0_13 + 1]);
    }
    omSetTra(arg0,
        D_80111C68_282738_vine_with_me[arg1] + HuMathCos(D_80112590_283060_vine_with_me[arg1]) * 125.0,
        D_80111C70_282740_vine_with_me[arg1] + HuMathSin(D_80112590_283060_vine_with_me[arg1]) * 125.0,
        0.0f);
    if (D_801155F8_2860C8_vine_with_me[arg1] > 0) {
        var_f4_3 = 90.0f;
        if (D_801155F8_2860C8_vine_with_me[arg1] >= 0x33) {
            temp_f20_5 = (D_801155F8_2860C8_vine_with_me[arg1] - 50) / 10.0f;
            temp_f20_5 = ((-HuMathCos(temp_f20_5 * 180.0f) + 1.0f) / 2.0f) * 0.75 + temp_f20_5 * 0.25;
            var_f4_3 = 90.0 - temp_f20_5 * 95.0;
        }
        omSetRot(arg0, 0, var_f4_3, D_80112590_283060_vine_with_me[arg1] + 90.0);
        D_801155F8_2860C8_vine_with_me[arg1] += (D_801155F8_2860C8_vine_with_me[arg1] < 60);
        if (D_8011563C_28610C_vine_with_me == 3 && D_8011558C_28605C_vine_with_me != arg1) {
            D_801155F8_2860C8_vine_with_me[arg1] = 0;
        }
    } else {
        omSetRot(arg0, 0,
            (D_80111C80_282750_vine_with_me[arg1] > 0.0f && D_80112590_283060_vine_with_me[arg1] > -90.0) ? -90.0f : 90.0f,
            D_80112590_283060_vine_with_me[arg1] + 90.0);
    }
    D_80111C94_282764_vine_with_me[arg1] -= (D_80111C94_282764_vine_with_me[arg1] != 0 && D_80111C94_282764_vine_with_me[arg1] < 0xFF);
    if (D_8011563C_28610C_vine_with_me < 4 || D_8011563C_28610C_vine_with_me == 5 || D_8011558C_28605C_vine_with_me != arg1) {
        func_8001C258_1CE58(arg0->model[0], 4, (D_80111C94_282764_vine_with_me[arg1] != 0 && ((arg1 + D_80111CA4_282774_vine_with_me) & 1)) ? 4 : 0);
    }
    D_801125A8_283078_vine_with_me[arg1] = D_80111C68_282738_vine_with_me[arg1];
    D_801125B0_283080_vine_with_me[arg1] = D_80111C70_282740_vine_with_me[arg1];
    if (D_80111C5C_28272C_vine_with_me[arg1] <= 0 && D_80111C60_282730_vine_with_me[arg1] <= 550.0f) {
        D_80111C60_282730_vine_with_me[arg1] += -D_80111C5C_28272C_vine_with_me[arg1] * 450.0 - (D_80111C60_282730_vine_with_me[arg1] - 550.0);
    }
    if (D_80111C5C_28272C_vine_with_me[arg1] >= 12 && D_80111C60_282730_vine_with_me[arg1] >= 1250.0f) {
        D_80111C60_282730_vine_with_me[arg1] -= (D_80111C5C_28272C_vine_with_me[arg1] - 12) * 450.0 + D_80111C60_282730_vine_with_me[arg1] - 1250.0;
    }
    D_801155D8_2860A8_vine_with_me[arg1][0] += D_80111C60_282730_vine_with_me[arg1] - sp3CC;
    D_801155D8_2860A8_vine_with_me[arg1][1] += D_80111C60_282730_vine_with_me[arg1] - sp3CC;
    D_801155D8_2860A8_vine_with_me[arg1][2] += D_80111C60_282730_vine_with_me[arg1] - sp3CC;
    D_801155D8_2860A8_vine_with_me[arg1][3] += D_80111C60_282730_vine_with_me[arg1] - sp3CC;
    if (D_80111C5C_28272C_vine_with_me[arg1] < 8) {
        Hu3DModelPosSet(D_801155A0_286070_vine_with_me->model[arg1 + 2],
            ((-D_80111C60_282730_vine_with_me[arg1] - D_80111C5C_28272C_vine_with_me[arg1] * 450.0 - 75.0) / 15.0) * 16.0 + D_80111C60_282730_vine_with_me[arg1] + 437.5,
            (arg1 != 0 ? -388.3333333333333 : -361.6666666666667) + (arg1 != 0 ? 23.333333333333332 : 0.0) + 1.0,
            -250.0f);
        Hu3DModelScaleSet(D_801155A0_286070_vine_with_me->model[arg1 + 2], 1.4375f, 1.4375f, 1.0f);
    } else {
        func_8001C258_1CE58(D_801155A0_286070_vine_with_me->model[arg1 + 2], 4, 4);
        func_8001C258_1CE58(D_801155A0_286070_vine_with_me->model[arg1], 4, 0);
        if (arg1 == 0) {
            omSetTra(D_801155A0_286070_vine_with_me, (D_80111C5C_28272C_vine_with_me[0] - 8) * -450.0 + 3750.0, 172.0f, 0);
        } else {
            Hu3DModelPosSet(D_801155A0_286070_vine_with_me->model[1], (D_80111C5C_28272C_vine_with_me[arg1] - 8) * -450.0 + 3750.0, 172.0f, 0.0f);
        }
    }
    CenterM[arg1].x = D_80111C60_282730_vine_with_me[arg1];
    if (D_80111C38_282708_vine_with_me[arg1] + D_80111C5C_28272C_vine_with_me[arg1] != D_80115540_286010_vine_with_me[arg1]) {
        if (D_80115540_286010_vine_with_me[arg1] <= 15.0f) {
            D_801155FC_2860CC_vine_with_me[arg1] = D_80115540_286010_vine_with_me[arg1] * (1.0 - D_80115548_286018_vine_with_me[arg1] / 20.0) + D_801155FC_2860CC_vine_with_me[arg1] * (D_80115548_286018_vine_with_me[arg1] / 20.0);
            D_80115540_286010_vine_with_me[arg1] = D_80111C38_282708_vine_with_me[arg1] + D_80111C5C_28272C_vine_with_me[arg1];
            D_80115548_286018_vine_with_me[arg1] = 0x14;
        }
    }
    if (D_80111C3C_28270C_vine_with_me[arg1] == 2
        && D_8011563C_28610C_vine_with_me >= 2U // TODO: why 2U?
        && D_80115540_286010_vine_with_me[arg1] <= 15.0f)
    {
        D_801155FC_2860CC_vine_with_me[arg1] = D_80115540_286010_vine_with_me[arg1] * (1.0 - D_80115548_286018_vine_with_me[arg1] / 20.0) + D_801155FC_2860CC_vine_with_me[arg1] * (D_80115548_286018_vine_with_me[arg1] / 20.0);
        D_80115540_286010_vine_with_me[arg1] = 16.0f;
        D_80115548_286018_vine_with_me[arg1] = 0x14;
    }
    if (D_8011558C_28605C_vine_with_me == 2
        && D_80115540_286010_vine_with_me[arg1] > 15.0f
        && (D_8011563C_28610C_vine_with_me == 3 || D_8011563C_28610C_vine_with_me == 5 || D_8011563C_28610C_vine_with_me == 6))
    {
        D_80115540_286010_vine_with_me[arg1] = D_80115540_286010_vine_with_me[arg1] * (1.0 - D_80115548_286018_vine_with_me[arg1] / 20.0) + D_801155FC_2860CC_vine_with_me[arg1] * (D_80115548_286018_vine_with_me[arg1] / 20.0);
        D_801155FC_2860CC_vine_with_me[arg1] = D_80115540_286010_vine_with_me[arg1];
        D_80115548_286018_vine_with_me[arg1] = 0;
    }
    D_80115548_286018_vine_with_me[2 + arg1] = D_80111C5C_28272C_vine_with_me[arg1];
    if (arg2 == 1) {
        D_80111CA4_282774_vine_with_me++;
    }
}
