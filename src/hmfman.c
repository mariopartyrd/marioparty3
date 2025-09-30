#include "game/hmfman.h"
#include "game/camera.h"
#include "macros.h"
#include "mallocblock.h"
#include "include_asm.h"

// graphics.c
u8 func_8000EF64_FB64(void* arg0, u16 arg1, s32 arg2, void* arg3, s32 arg4);

// hmflight.c
void func_80019968_1A568(s32);

// hmfload.c
void func_8000F978_10578(HmfData*);

// 20A20.c
void func_80021AF4_226F4(void);

// 22EB0.c
void func_800222B0_22EB0(void* arg0, void* arg1, u16 arg2, u16 arg3, u16 arg4, u8 arg5);
void func_800224BC_230BC(void);
void func_80022660_23260(HmfData*);
s16 func_8002C834_2D434(HmfData*, s32);
void func_8002D260_2DE60(void);
s32 func_8002D3AC_2DFAC(void*);
void func_8002D514_2E114(void);
void func_80030030_30C30(f32);

// 30C40.c
void func_80030198_30D98(void);
s32 func_800300A4_30CA4(void*, void*);

// 32160.c
void func_80033450_34050(void);
void func_80033510_34110(void);

// 8AC70.c
void func_8008A070_8AC70(void*);

// unknown
void func_8000D3AC_DFAC(void);

extern Gfx* gMainGfxPos;

void Hmfload(HmfData*, void*, s32);
void* func_80010AC8_116C8(void*);
void func_8001EF60_1FB60(void);
s32 func_8001FF04_20B04(s32);
s32 func_8002D2D8_2DED8(void*, HmfData*);

extern u8 D_800A0540_A1140;
extern u8 D_800A0541_A1141;
extern u8 D_800A0542_A1142;
extern Gfx D_800A09B0_A15B0[];
extern Gfx D_800A0A08_A1608[];
extern Gfx D_800A0A38_A1638[];
extern s16 D_800A0A78_A1678;
extern s16 D_800C9932_CA532;
extern s32 D_800C9940_CA540;
extern u16 D_800CBB72_CC772[];
extern s8 D_800CC0A8_CCCA8;
extern s32 D_800CC3D8_CCFD8[];
extern u16 D_800CD2F6_CDEF6;
extern s16 D_800CDD6A_CE96A;
extern u8 D_800CE19A_CED9A;
extern s8 D_800CE1C6_CEDC6;
extern u8 D_800CD280_CDE80;
extern s32 D_800D0444_D1044;
extern u16 D_800D05A0_D11A0[][128];
extern s32 D_800D10F4_D1CF4;
extern s32 D_800D1F70_D2B70;
extern s32 D_800D1FE8_D2BE8;
extern s8 D_800D2008_D2C08;
extern s8 D_800D20B1_D2CB1;
extern s16 D_800D20EE_D2CEE;
extern u16 D_800D5204_D5E04;

const char D_800A6BB8_A77B8[] = "%x\n";
const char D_800A6BBC_A77BC[] = "Model Entry Over!\n";

void func_8001A070_1AC70(void* arg0, void* arg1, u16 arg2, u16 arg3, u16 arg4, u8 arg5) {
    s16 modelId;

    func_800222B0_22EB0(arg0, arg1, arg2, arg3, arg4, arg5);
    func_8002D260_2DE60();
    HmfModelData = HuMemAlloc(HU3D_MODEL_MAX * sizeof(HmfModel));
    for (modelId = 0; modelId < HU3D_MODEL_MAX; modelId++) {
        HmfModelData[modelId].hmf = NULL;
    }
    func_800224BC_230BC();
    D_800D20AC_D2CAC = 0;
    D_800D1F70_D2B70 = 0;
    D_800D20EE_D2CEE = 1;
    D_800D20B1_D2CB1 = 0;
    D_800CD280_CDE80 = 1;
    D_800CC3D8_CCFD8[0] = D_800CC3D8_CCFD8[1] = 0;
    func_8000D3AC_DFAC();
    D_800D1FE8_D2BE8 = 0;
}

s16 Hu3DModelCreate(u8* data, u32 arg1) {
    HmfModel* modelP;
    HmfData* hmf;
    void* var_a1;
    s16 modelId;
    s16 var_a0;

    for (modelId = 0; modelId < HU3D_MODEL_MAX; modelId++) {
        if (HmfModelData[modelId].hmf == NULL) {
            break;
        }
    }
    if (modelId == HU3D_MODEL_MAX) {
        osSyncPrintf(D_800A6BBC_A77BC);
        return -1;
    }
    D_800D5204_D5E04 = 10000 + modelId * 2;
    D_800CDD6A_CE96A = 10001 + modelId * 2;
    modelP = &HmfModelData[modelId];
    modelP->unk08 = 0xFF;
    hmf = modelP->hmf = HuMemAlloc(sizeof(HmfData));
    hmf->unk0E = D_800D5204_D5E04;
    if (data[0] == 'M' && data[1] == 'T') {
        hmf->unk14 = 0;
        hmf->unk84 = 0;
        hmf->unk38 = 0;
        hmf->unkC8 = 0;
        hmf->unk98 = NULL;
        if (data[2] == 'N' && data[3] == 'X') {
            modelP->unk02 = func_8002D3AC_2DFAC(data);
            arg1 &= ~(0x10 | 0x1);
        } else {
            var_a1 = data + 8;
            if (data[8] == 'M') {
                if (data[9] == 'T' && data[10] == 'N' && data[11] == 'X') {
                    modelP->unk02 = func_8002D3AC_2DFAC(var_a1);
                    arg1 &= ~0x11;
                    var_a1 = func_80010AC8_116C8(data + 12);
                } else {
                    modelP->unk02 = 0xFF;
                }
            } else {
                modelP->unk02 = 0xFF;
            }
            modelP->unk08 = func_800300A4_30CA4(data, var_a1);
        }
    } else {
        Hmfload(hmf, data, arg1);
        if (hmf->unk38 != 0) {
            HuMemSetTag(hmf->unk50, D_800CDD6A_CE96A);
            modelP->unk10 = func_8001FF04_20B04(modelId);
        } else {
            modelP->unk10 = -1;
        }
        hmf->unk00 = (arg1 >> 10) & 7;
        modelP->unk18 = arg1;
        modelP->unk02 = func_8002D2D8_2DED8(data, hmf);
        if (modelP->unk02 != 0xFF) {
            if (hmf->unk14 == 0) {
                func_8000F978_10578(hmf);
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
        D_800C9940_CA540 = modelP->unk18;
        func_80022660_23260(hmf);
    }
    hmf->unk0B = 1;
    if (arg1 & 0x10) {
        for (var_a0 = 0; var_a0 < hmf->unk10; var_a0++) {
            if (hmf->unk60[var_a0].unk50 & 0x06000000) {
                break;
            }
        }
        if (var_a0 == hmf->unk10) {
            HuMemFreeAllWithTag(D_800D5204_D5E04);
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
    func_8008A070_8AC70(modelP->mtx);
    D_800D1FE8_D2BE8++;
    return modelId;
}

s16 Hu3DModelLink(s16 linkMdlId) {
    HmfModel* modelP;
    s16 modelId;

    for (modelId = 0; modelId < HU3D_MODEL_MAX; modelId++) {
        if (HmfModelData[modelId].hmf == NULL) {
            break;
        }
    }
    if (modelId == HU3D_MODEL_MAX) {
        osSyncPrintf(D_800A6BBC_A77BC);
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
    func_8008A070_8AC70(modelP->mtx);
    D_800D1FE8_D2BE8++;
    return modelId;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001A894_1B494);

s16 func_8001ABD4_1B7D4(s16 arg0, s8 arg1) {
    s16 idx = Hu3DModelLink(arg0);

    if (idx < 0) {
        return -1;
    }
    HmfModelData[idx].unk00 = arg1;
    return idx;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001AC34_1B834);

s16 func_8001AC8C_1B88C(s32 arg0, void (*arg1)(Gfx**, s32, s32), u8 arg2) {
    s16 idx = func_8001A894_1B494(arg0, NULL, arg2);
    HmfModel* var_v1 = &HmfModelData[idx];

    var_v1->unk70 = arg1;
    return idx;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001ACDC_1B8DC);

void func_8001AFE4_1BBE4(void) {
    s16 i;

    for (i = 0; i < HU3D_MODEL_MAX; i++) {
        if (HmfModelData[i].hmf != NULL) {
            func_8001ACDC_1B8DC(i);
        }
    }
    func_80033510_34110();
    func_80033450_34050();
    func_80030198_30D98();
    func_80021AF4_226F4();
    func_8002D514_2E114();
    func_8001EF60_1FB60();
    D_800CC3D8_CCFD8[0] = D_800CC3D8_CCFD8[1] = 0;
    func_80030030_30C30(1.0f);
    func_80019968_1A568(1);
    func_8000D3AC_DFAC();
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001B0B4_1BCB4);

Gfx* func_8001BD24_1C924(Gfx* arg0, s16 arg1, u16 arg2) {
    s16 i;

    for (i = 0; i < D_800CBB72_CC772[arg1]; i++) {
        HmfModel* temp_s0 = &HmfModelData[D_800D05A0_D11A0[arg1][i]];

        if (!(temp_s0->unk01 & arg2) && arg2 != 0) {
            continue;
        }
        D_800CD2F6_CDEF6 = D_800D05A0_D11A0[arg1][i];
        if (temp_s0->hmf->unk00 != D_800CE19A_CED9A) {
            gDPFullSync(gMainGfxPos++);
            gSPEndDisplayList(gMainGfxPos++);
            func_8000EF64_FB64(arg0, D_800CE19A_CED9A, 0, NULL, 0);
            D_800CE19A_CED9A = temp_s0->hmf->unk00;
            arg0 = gMainGfxPos;
        }
        if (temp_s0->unk70 != NULL) {
            temp_s0->unk70(&gMainGfxPos, D_800D0444_D1044, D_800D10F4_D1CF4);
        } else if (temp_s0->hmf->unk3C != NULL) {
            gSPDisplayList(gMainGfxPos++, temp_s0->hmf->unk3C);
        }
    }
    return arg0;
}

void func_8001BF14_1CB14(void) {
    s16 i;

    HuMemSetDirty();
    for (i = 0; i < HU3D_MODEL_MAX; i++) {
        HmfModelData[i].hmf = NULL;
    }
    gCameraList = NULL;
    D_800C9932_CA532 = 0;
    D_800D2008_D2C08 = 0;
    D_800D20EE_D2CEE = 0;
}

void func_8001BF90_1CB90(u32 arg0, u32 arg1) {
    gSPSegment(gMainGfxPos++, 0x00, 0x00000000);
    gSPDisplayList(gMainGfxPos++, D_800A09B0_A15B0);
    gDPSetDepthImage(gMainGfxPos++, arg1);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, arg1);
    gSPDisplayList(gMainGfxPos++, D_800A0A08_A1608);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, arg0);
    if (D_800CD280_CDE80 != 0) {
        gDPSetFillColor(gMainGfxPos++, PACK_FILL_COLOR(D_800A0540_A1140, D_800A0541_A1141, D_800A0542_A1142, 1));
        gSPDisplayList(gMainGfxPos++, D_800A0A38_A1638);
    }
}

void Hu3DModelPosSet(s16 idx, f32 x, f32 y, f32 z) {
    if (idx >= 0 && HmfModelData[idx].hmf != NULL) {
        HmfModelData[idx].pos.x = x;
        HmfModelData[idx].pos.y = y;
        HmfModelData[idx].pos.z = z;
    }
}

void Hu3DModelPosGet(s16 idx, Vec* arg1) {
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

void func_8001C1F0_1CDF0(s16 arg0, s32 arg1) {
    s16 i;

    for (i = 0; i < HU3D_MODEL_MAX; i++) {
        func_8001C258_1CE58(i, arg0, arg1);
    }
}

void func_8001C258_1CE58(s16 idx, s32 arg1, s32 arg2) {
    HmfModel* model = &HmfModelData[idx];

    if (model->hmf != NULL) {
        if (arg1 & 0xB3F82) {
            arg2 |= 0x800000;
        }
        if (arg1 & 0x1C00) {
            func_8001C8E4_1D4E4(idx, arg2 & 0x1C00);
        }
        model->unk18 &= ~arg1;
        model->unk18 |= arg2;
    }
}

void func_8001C2FC_1CEFC(s16 idx, s32 arg1, s32 arg2) {
    HmfData* temp_a3 = HmfModelData[idx].hmf;
    s16 var_t0;

    for (var_t0 = 0; var_t0 < temp_a3->unk10; var_t0++) {
        temp_a3->unk60[var_t0].unk50 &= ~arg1;
        temp_a3->unk60[var_t0].unk50 |= arg2;
    }
}

void func_8001C39C_1CF9C(s16 idx, s32 arg1, s32 arg2, s32 arg3) {
    HmfData* temp_s0 = HmfModelData[idx].hmf;
    s16 temp_v0 = func_8002C834_2D434(temp_s0, arg1);

    if (temp_v0 >= 0) {
        temp_s0->unk60[temp_v0].unk50 &= ~arg2;
        temp_s0->unk60[temp_v0].unk50 |= arg3;
    }
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C448_1D048);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C514_1D114);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C5B4_1D1B4);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C624_1D224);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C6A8_1D2A8);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C718_1D318);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C760_1D360);

f32 func_8001C7D0_1D3D0(s16 idx) {
    if (HmfModelData[idx].unk04 == 0xFF) {
        return -1.0f;
    }
    return HmfModelData[idx].unk4C;
}

void func_8001C814_1D414(s16 idx, s16 arg1, s16 arg2) {
    HmfModel* temp_a3 = &HmfModelData[idx];

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

void func_8001C8A8_1D4A8(s16 idx, s16 arg1) {
    if (idx >= 0 && HmfModelData[idx].hmf != NULL) {
        HmfModelData[idx].unk01 = arg1;
    }
}

void func_8001C8E4_1D4E4(s16 idx, u32 arg1) {
    HmfModelData[idx].unk18 &= ~0x1C00;
    HmfModelData[idx].unk18 |= arg1;
    HmfModelData[idx].hmf->unk00 = (arg1 >> 10) & 7;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C92C_1D52C);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C954_1D554);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001CAA4_1D6A4);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001CD34_1D934);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001CE28_1DA28);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001CF1C_1DB1C);

void func_8001D330_1DF30(s16 arg0) {
    D_800A0A78_A1678 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001D33C_1DF3C);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001D558_1E158);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001D638_1E238);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001D874_1E474);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001DACC_1E6CC);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001DDB8_1E9B8);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001E500_1F100);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001E65C_1F25C);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001E888_1F488);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001EBC0_1F7C0);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001ED54_1F954);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001EED8_1FAD8);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001EF24_1FB24);

void func_8001EF60_1FB60(void) {
    D_800CE1C6_CEDC6 = 0;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001EF6C_1FB6C);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001EFEC_1FBEC);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F038_1FC38);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F154_1FD54);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F1FC_1FDFC);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F304_1FF04);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F358_1FF58);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F38C_1FF8C);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F3A8_1FFA8);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F450_20050);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F4BC_200BC);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F668_20268);

void func_8001F6B0_202B0(s8 arg0) {
    D_800CC0A8_CCCA8 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F6BC_202BC);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F6F8_202F8);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F734_20334);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F95C_2055C);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F974_20574);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001F9E4_205E4);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001FA68_20668);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001FB34_20734);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001FBBC_207BC);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001FBFC_207FC);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001FD08_20908);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001FDE8_209E8);

INCLUDE_RODATA("asm/nonmatchings/hmfman", D_800A6C04_A7804);
