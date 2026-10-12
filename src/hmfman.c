#include "common.h"
#include "game/hmfman.h"
#include "game/camera.h"
#include "game/hmflight.h"
#include "macros.h"
#include "mallocblock.h"
#include "include_asm.h"

s32 func_80023264_main(HmfData *);
extern s32 D_800A0530_main;
extern s32 D_800C9940_main;

// graphics.c
u8 func_8000EF64_main(void *arg0, u16 arg1, s32 arg2, void *arg3, s32 arg4);

// hmfload.c
void func_8000F978_main(HmfData *);

// 20A20.c
void func_80021AF4_main(void);

// 22EB0.c
void func_800222B0_main(void *arg0, void *arg1, u16 arg2, u16 arg3, u16 arg4, u8 arg5);
void func_800224BC_main(void);
void func_80022660_main(HmfData *);
s16 func_8002C834_main(HmfData *, s32);
void func_8002D260_main(void);
s32 func_8002D3AC_main(void *);
void func_8002D514_main(void);
void func_80030030_main(f32);

// 30C40.c
void func_80030198_main(void);
s32 func_800300A4_main(void *, void *);

// 32160.c
void func_80033450_main(void);
void func_80033510_main(void);

// 8AC70.c
void func_8008A070_main(void *);

// unknown
void func_8000D3AC_main(void);

extern Gfx *gMainGfxPos;

void Hmfload(HmfData *, void *, s32);
void *func_80010AC8_main(void *);
void func_8001EF60_main(void);
s32 func_8001FF04_main(s32);
s32 func_8002D2D8_main(void *, HmfData *);

extern u8 D_800A0540_main;
extern u8 D_800A0541_main;
extern u8 D_800A0542_main;
extern Gfx D_800A09B0_main[];
extern Gfx D_800A0A08_main[];
extern Gfx D_800A0A38_main[];
extern s16 D_800A0A78_main;
extern s16 D_800C9932_main;
extern s32 D_800C9940_main;
extern u16 D_800CBB72_main[];
extern s8 D_800CC0A8_main;
extern s32 D_800CC3D8_main[];
extern u16 D_800CD2F6_main;
extern s16 D_800CDD6A_main;
extern u8 D_800CE19A_main;
extern s8 D_800CE1C6_main;
extern u8 D_800CD280_main;
extern s32 D_800D0444_main;
extern u16 D_800D05A0_main[][128];
extern s32 D_800D10F4_main;
extern s32 D_800D1F70_main;
extern s32 D_800D1FE8_main;
extern s8 D_800D2008_main;
extern s8 HmfPauseF;
extern s16 D_800D20EE_main;
extern u16 D_800D5204_main;

const char D_800A6BB8_main[] = "%x\n";
const char D_800A6BBC_main[] = "Model Entry Over!\n";

void func_8001A070_main(void *arg0, void *arg1, u16 arg2, u16 arg3, u16 arg4, u8 arg5) {
    s16 modelId;

    func_800222B0_main(arg0, arg1, arg2, arg3, arg4, arg5);
    func_8002D260_main();
    HmfModelData = HuMemAlloc(HU3D_MODEL_MAX * sizeof(HmfModel));
    for (modelId = 0; modelId < HU3D_MODEL_MAX; modelId++) {
        HmfModelData[modelId].hmf = NULL;
    }
    func_800224BC_main();
    D_800D20AC_main = 0;
    D_800D1F70_main = 0;
    D_800D20EE_main = 1;
    HmfPauseF = 0;
    D_800CD280_main = 1;
    D_800CC3D8_main[0] = D_800CC3D8_main[1] = 0;
    func_8000D3AC_main();
    D_800D1FE8_main = 0;
}

s16 Hu3DModelCreate(u8 *data, u32 arg1) {
    HmfModel *modelP;
    HmfData *hmf;
    void *var_a1;
    s16 modelId;
    s16 var_a0;

    for (modelId = 0; modelId < HU3D_MODEL_MAX; modelId++) {
        if (HmfModelData[modelId].hmf == NULL) {
            break;
        }
    }
    if (modelId == HU3D_MODEL_MAX) {
        osSyncPrintf(D_800A6BBC_main);
        return -1;
    }
    D_800D5204_main = 10000 + modelId * 2;
    D_800CDD6A_main = 10001 + modelId * 2;
    modelP = &HmfModelData[modelId];
    modelP->unk08 = 0xFF;
    hmf = modelP->hmf = HuMemAlloc(sizeof(HmfData));
    hmf->unk0E = D_800D5204_main;
    if (data[0] == 'M' && data[1] == 'T') {
        hmf->unk14 = 0;
        hmf->unk84 = 0;
        hmf->unk38 = 0;
        hmf->unkC8 = 0;
        hmf->unk98 = NULL;
        if (data[2] == 'N' && data[3] == 'X') {
            modelP->unk02 = func_8002D3AC_main(data);
            arg1 &= ~(0x10 | 0x1);
        } else {
            var_a1 = data + 8;
            if (data[8] == 'M') {
                if (data[9] == 'T' && data[10] == 'N' && data[11] == 'X') {
                    modelP->unk02 = func_8002D3AC_main(var_a1);
                    arg1 &= ~0x11;
                    var_a1 = func_80010AC8_main(data + 12);
                } else {
                    modelP->unk02 = 0xFF;
                }
            } else {
                modelP->unk02 = 0xFF;
            }
            modelP->unk08 = func_800300A4_main(data, var_a1);
        }
    } else {
        Hmfload(hmf, data, arg1);
        if (hmf->unk38 != 0) {
            HuMemSetTag(hmf->unk50, D_800CDD6A_main);
            modelP->unk10 = func_8001FF04_main(modelId);
        } else {
            modelP->unk10 = -1;
        }
        hmf->unk00 = (arg1 >> 10) & 7;
        modelP->unk18 = arg1;
        modelP->unk02 = func_8002D2D8_main(data, hmf);
        if (modelP->unk02 != 0xFF) {
            if (hmf->unk14 == 0) {
                func_8000F978_main(hmf);
            } else {
                goto skip;
            }
        }
    }
    if (hmf->unk14 == 0) {
        arg1 |= 4;
    }
skip:
    modelP->unk18 = arg1;
    if (arg1 & 8) {
        gFreeFunc(data);
    }
    if (arg1 & 1) {
        D_800C9940_main = modelP->unk18;
        func_80022660_main(hmf);
    }
    hmf->unk0B = 1;
    if (arg1 & 0x10) {
        for (var_a0 = 0; var_a0 < hmf->unk10; var_a0++) {
            if (hmf->unk60[var_a0].unk50 & 0x06000000) {
                break;
            }
        }
        if (var_a0 == hmf->unk10) {
            HuMemFreeAllWithTag(D_800D5204_main);
        }
    }
    modelP->unk40 =
        modelP->unk03 =
            modelP->unk48 =
                modelP->unk4C =
                    modelP->unk05 =
                        modelP->unk54 =
                            modelP->unk58 =
                                modelP->unk07 =
                                    modelP->unk60 = 0;
    modelP->unk5C = 1.0f;
    modelP->unk50 = 1.0f;
    modelP->unk44 = 1.0f;
    modelP->unk06 = -1;
    modelP->unk04 = -1;
    modelP->unk09 = -1;
    modelP->pos.x = modelP->pos.y = modelP->pos.z = 0.0f;
    modelP->rot.x = modelP->rot.y = modelP->rot.z = 0.0f;
    modelP->scale.x = modelP->scale.y = modelP->scale.z = 1.0f;
    modelP->unk01 = -1;
    modelP->unk00 = 0;
    modelP->unkB4 = 0;
    func_8008A070_main(modelP->mtx);
    D_800D1FE8_main++;
    return modelId;
}

s32 Hu3DModelLink(s16 linkMdlId) {
    HmfModel *modelP;
    s16 modelId;

    for (modelId = 0; modelId < HU3D_MODEL_MAX; modelId++) {
        if (HmfModelData[modelId].hmf == NULL) {
            break;
        }
    }
    if (modelId == HU3D_MODEL_MAX) {
        osSyncPrintf(D_800A6BBC_main);
        return -1;
    }
    modelP = &HmfModelData[modelId];
    modelP->hmf = HmfModelData[linkMdlId].hmf;
    modelP->unk18 = HmfModelData[linkMdlId].unk18;
    modelP->unk00 = HmfModelData[linkMdlId].unk00;
    modelP->unk10 = HmfModelData[linkMdlId].unk10;
    modelP->unk02 = HmfModelData[linkMdlId].unk02;
    modelP->hmf->unk0B++;
    modelP->unk40 =
        modelP->unk03 =
            modelP->unk48 =
                modelP->unk4C =
                    modelP->unk05 =
                        modelP->unk54 =
                            modelP->unk58 =
                                modelP->unk07 =
                                    modelP->unk60 = 0;
    modelP->unk5C = 1.0f;
    modelP->unk50 = 1.0f;
    modelP->unk44 = 1.0f;
    modelP->unk06 = -1;
    modelP->unk04 = -1;
    modelP->unk09 = -1;
    modelP->unk08 = -1;
    modelP->unkB4 = 0;
    modelP->pos.x = modelP->pos.y = modelP->pos.z = 0.0f;
    modelP->rot.x = modelP->rot.y = modelP->rot.z = 0.0f;
    modelP->scale.x = modelP->scale.y = modelP->scale.z = 1.0f;
    modelP->unk01 = -1;
    func_8008A070_main(modelP->mtx);
    D_800D1FE8_main++;
    return modelId;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001A894_main);

s16 func_8001ABD4_main(s16 arg0, s8 arg1) {
    s16 idx = Hu3DModelLink(arg0);

    if (idx < 0) {
        return -1;
    }
    HmfModelData[idx].unk00 = arg1;
    return idx;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001AC34_main);

s16 func_8001AC8C_main(s32 arg0, void (*arg1)(Gfx **, s32, s32), u8 arg2) {
    s16 idx = func_8001A894_main(arg0, NULL, arg2);
    HmfModel *var_v1 = &HmfModelData[idx];

    var_v1->unk70 = arg1;
    return idx;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001ACDC_main);

void func_8001AFE4_main(void) {
    s16 i;

    for (i = 0; i < HU3D_MODEL_MAX; i++) {
        if (HmfModelData[i].hmf != NULL) {
            func_8001ACDC_main(i);
        }
    }
    func_80033510_main();
    func_80033450_main();
    func_80030198_main();
    func_80021AF4_main();
    func_8002D514_main();
    func_8001EF60_main();
    D_800CC3D8_main[0] = D_800CC3D8_main[1] = 0;
    func_80030030_main(1.0f);
    func_80019968_main(1);
    func_8000D3AC_main();
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001B0B4_main);

Gfx *func_8001BD24_main(Gfx *arg0, s16 arg1, u16 arg2) {
    s16 i;

    for (i = 0; i < D_800CBB72_main[arg1]; i++) {
        HmfModel *temp_s0 = &HmfModelData[D_800D05A0_main[arg1][i]];

        if (!(temp_s0->unk01 & arg2) && arg2 != 0) {
            continue;
        }
        D_800CD2F6_main = D_800D05A0_main[arg1][i];
        if (temp_s0->hmf->unk00 != D_800CE19A_main) {
            gDPFullSync(gMainGfxPos++);
            gSPEndDisplayList(gMainGfxPos++);
            func_8000EF64_main(arg0, D_800CE19A_main, 0, NULL, 0);
            D_800CE19A_main = temp_s0->hmf->unk00;
            arg0 = gMainGfxPos;
        }
        if (temp_s0->unk70 != NULL) {
            temp_s0->unk70(&gMainGfxPos, D_800D0444_main, D_800D10F4_main);
        } else if (temp_s0->hmf->unk3C != NULL) {
            gSPDisplayList(gMainGfxPos++, temp_s0->hmf->unk3C);
        }
    }
    return arg0;
}

void func_8001BF14_main(void) {
    s16 i;

    HuMemSetDirty();
    for (i = 0; i < HU3D_MODEL_MAX; i++) {
        HmfModelData[i].hmf = NULL;
    }
    gCameraList = NULL;
    D_800C9932_main = 0;
    D_800D2008_main = 0;
    D_800D20EE_main = 0;
}

void func_8001BF90_main(u32 arg0, u32 arg1) {
    gSPSegment(gMainGfxPos++, 0x00, 0x00000000);
    gSPDisplayList(gMainGfxPos++, D_800A09B0_main);
    gDPSetDepthImage(gMainGfxPos++, arg1);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, arg1);
    gSPDisplayList(gMainGfxPos++, D_800A0A08_main);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, arg0);
    if (D_800CD280_main != 0) {
        gDPSetFillColor(gMainGfxPos++, PACK_FILL_COLOR(D_800A0540_main, D_800A0541_main, D_800A0542_main, 1));
        gSPDisplayList(gMainGfxPos++, D_800A0A38_main);
    }
}

void Hu3DModelPosSet(s16 idx, f32 x, f32 y, f32 z) {
    if (idx >= 0 && HmfModelData[idx].hmf != NULL) {
        HmfModelData[idx].pos.x = x;
        HmfModelData[idx].pos.y = y;
        HmfModelData[idx].pos.z = z;
    }
}

void Hu3DModelPosGet(s16 idx, Vec *arg1) {
    arg1->x = HmfModelData[idx].pos.x;
    arg1->y = HmfModelData[idx].pos.y;
    arg1->z = HmfModelData[idx].pos.z;
}

void Hu3DModelRotSet(s16 idx, f32 x, f32 y, f32 z) {
    if (idx >= 0 && HmfModelData[idx].hmf != NULL) {
        HmfModelData[idx].rot.x = x;
        HmfModelData[idx].rot.y = y;
        HmfModelData[idx].rot.z = z;
    }
}

void Hu3DModelScaleSet(s16 idx, f32 x, f32 y, f32 z) {
    if (idx >= 0 && HmfModelData[idx].hmf != NULL) {
        HmfModelData[idx].scale.x = x;
        HmfModelData[idx].scale.y = y;
        HmfModelData[idx].scale.z = z;
    }
}

void func_8001C1F0_main(s16 arg0, s32 arg1) {
    s16 i;

    for (i = 0; i < HU3D_MODEL_MAX; i++) {
        func_8001C258_main(i, arg0, arg1);
    }
}

void func_8001C258_main(s16 idx, s32 arg1, s32 arg2) {
    HmfModel *model = &HmfModelData[idx];

    if (model->hmf != NULL) {
        if (arg1 & 0xB3F82) {
            arg2 |= 0x800000;
        }
        if (arg1 & 0x1C00) {
            func_8001C8E4_main(idx, arg2 & 0x1C00);
        }
        model->unk18 &= ~arg1;
        model->unk18 |= arg2;
    }
}

void func_8001C2FC_main(s16 idx, s32 arg1, s32 arg2) {
    HmfData *temp_a3 = HmfModelData[idx].hmf;
    s16 var_t0;

    for (var_t0 = 0; var_t0 < temp_a3->unk10; var_t0++) {
        temp_a3->unk60[var_t0].unk50 &= ~arg1;
        temp_a3->unk60[var_t0].unk50 |= arg2;
    }
}

void func_8001C39C_main(s16 idx, s32 arg1, s32 arg2, s32 arg3) {
    HmfData *temp_s0 = HmfModelData[idx].hmf;
    s16 temp_v0 = func_8002C834_main(temp_s0, arg1);

    if (temp_v0 >= 0) {
        temp_s0->unk60[temp_v0].unk50 &= ~arg2;
        temp_s0->unk60[temp_v0].unk50 |= arg3;
    }
}

void func_8001C448_main(s16 arg0) {
    func_8001C258_main(arg0, 0x00800001, 1);
    D_800C9940_main = HmfModelData[arg0].unk18;

    if (D_800C9940_main & 0x10) {
        osSyncPrintf("RemakeStatic Error! Executed DynamicFree already!\n");
        D_800A0530_main = 0x10002;
        return;
    }

    if (func_80023264_main(HmfModelData[arg0].hmf) != NULL) {
        func_8001C954_main(arg0);
    }
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C514_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C5B4_main);

void func_8001C624_main(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4) {
    HmfModel *temp_a0;

    temp_a0 = &HmfModelData[arg0];
    if (temp_a0->unk04 != 0xFF) {
        temp_a0->unk02 = temp_a0->unk04;
        temp_a0->unk40 = temp_a0->unk4C;
        temp_a0->unk03 = temp_a0->unk05;
        temp_a0->unk48 = temp_a0->unk54;
    }
    temp_a0->unk04 = (u8)arg1;
    temp_a0->unk4C = arg2;
    temp_a0->unk0E = (u16)0;
    temp_a0->unk0C = arg3;
    temp_a0->unk05 = (u8)arg4;
    temp_a0->unk54 = 0.0f;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C6A8_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C718_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C760_main);

f32 func_8001C7D0_main(s16 idx) {
    if (HmfModelData[idx].unk04 == 0xFF) {
        return -1.0f;
    }
    return HmfModelData[idx].unk4C;
}

void func_8001C814_main(s16 idx, s16 arg1, s16 arg2) {
    HmfModel *temp_a3 = &HmfModelData[idx];

    temp_a3->unk03 &= ~arg1;
    temp_a3->unk03 |= arg2;
    if (temp_a3->hmf->unk98 != NULL) {
        temp_a3->hmf->unk98->unk02 &= ~arg1;
        temp_a3->hmf->unk98->unk02 |= arg2;
    }
    if (temp_a3->unk04 != 0xFF) {
        temp_a3->unk05 &= ~arg1;
        temp_a3->unk05 |= arg2;
    }
}

void func_8001C8A8_main(s16 idx, s16 arg1) {
    if (idx >= 0 && HmfModelData[idx].hmf != NULL) {
        HmfModelData[idx].unk01 = arg1;
    }
}

void func_8001C8E4_main(s16 idx, u32 arg1) {
    HmfModelData[idx].unk18 &= ~0x1C00;
    HmfModelData[idx].unk18 |= arg1;
    HmfModelData[idx].hmf->unk00 = (arg1 >> 10) & 7;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C92C_main);

// officially named "DynamicFree"
INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C954_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001CAA4_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001CD34_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001CE28_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001CF1C_main);

void func_8001D330_main(s16 arg0) {
    D_800A0A78_main = arg0;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001D33C_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001D558_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001D638_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001D874_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001DACC_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001DDB8_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001E500_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001E65C_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001E888_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001EBC0_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001ED54_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001EED8_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001EF24_main);

void func_8001EF60_main(void) {
    D_800CE1C6_main = 0;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001EF6C_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001EFEC_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F038_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F154_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F1FC_main);

void func_8001F304_main(s16 arg0, s16 arg1) {
    HmfModel *temp_v0;

    temp_v0 = &HmfModelData[arg0];
    temp_v0->unk02 = arg1;
    temp_v0->unk03 = 0;
    temp_v0->unk48 =
        temp_v0->unk40 = 0.0f;
    temp_v0->unk44 = 1.0f;
    temp_v0->unk04 = 0xFF;
}

f32 func_8001F358_main(s16 arg0) {
    return D_800CCF58_main[arg0].unk02;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F38C_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F3A8_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F450_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F4BC_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F668_main);

void func_8001F6B0_main(s8 arg0) {
    D_800CC0A8_main = arg0;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F6BC_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F6F8_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F734_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F95C_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F974_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F9E4_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001FA68_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001FB34_main);

void func_8001FBBC_main(s16 arg0, s8 arg1, s8 arg2, s8 arg3) {
    HmfModel *other;

    other = HmfModelData[arg0].unkB4;
    if (other != NULL) {
        other->unk00 = arg1;
        other->unk01 = arg2;
        other->unk02 = arg3;
    }
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001FBFC_main);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001FD08_main);

void func_8001FDE8_main(s16 arg0) {
    HmfModelData[arg0].unk02 = 0xFF;
}

INCLUDE_RODATA("asm/nonmatchings/hmfman", D_800A6C04_main);
