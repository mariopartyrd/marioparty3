#include "game/hmfman.h"
#include "game/camera.h"
#include "macros.h"
#include "mallocblock.h"
#include "include_asm.h"

// graphics.c
u8 func_8000EF64_FB64(void* arg0, u16 arg1, s32 arg2, void* arg3, s32 arg4);

// hmflight.c
void func_80019968_1A568(s32);

// 20A20.c
void func_80021AF4_226F4(void);

// 22EB0.c
s16 func_8002C834_2D434(HmfModelData_Unk64_Struct*, s32);
void func_8002D514_2E114(void);
void func_80030030_30C30(f32);

// 30C40.c
void func_80030198_30D98(void);

// 32160.c
void func_80033450_34050(void);
void func_80033510_34110(void);

// 8AC70.c
void func_8008A070_8AC70(void*);

// unknown
void func_8000D3AC_DFAC(void);

extern Gfx* gMainGfxPos;

void func_8001EF60_1FB60(void);

extern u8 D_800A0540_A1140;
extern u8 D_800A0541_A1141;
extern u8 D_800A0542_A1142;
extern Gfx D_800A09B0_A15B0[];
extern Gfx D_800A0A08_A1608[];
extern Gfx D_800A0A38_A1638[];
extern s16 D_800A0A78_A1678;
extern s16 D_800C9932_CA532;
extern u16 D_800CBB72_CC772[];
extern s8 D_800CC0A8_CCCA8;
extern s32 D_800CC3D8_CCFD8[];
extern u16 D_800CD2F6_CDEF6;
extern u8 D_800CE19A_CED9A;
extern s8 D_800CE1C6_CEDC6;
extern u8 D_800CD280_CDE80;
extern s32 D_800D0444_D1044;
extern u16 D_800D05A0_D11A0[][128];
extern s32 D_800D10F4_D1CF4;
extern s32 D_800D1FE8_D2BE8;
extern s8 D_800D2008_D2C08;
extern s16 D_800D20EE_D2CEE;

// "Model Entry Over!\n"
extern const char D_800A6BBC_A77BC[];

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001A070_1AC70);

INCLUDE_ASM("asm/nonmatchings/hmfman", Hu3DModelCreate);

s16 Hu3DModelLink(s16 arg0) {
    HmfModel* temp_a1;
    s16 var_s0;

    for (var_s0 = 0; var_s0 < HU3D_MODEL_MAX; var_s0++) {
        if (HmfModelData[var_s0].unk64 == NULL) {
            break;
        }
    }
    if (var_s0 == HU3D_MODEL_MAX) {
        osSyncPrintf(D_800A6BBC_A77BC);
        return -1;
    }
    temp_a1 = &HmfModelData[var_s0];
    temp_a1->unk64 = HmfModelData[arg0].unk64;
    temp_a1->unk18 = HmfModelData[arg0].unk18;
    temp_a1->unk00 = HmfModelData[arg0].unk00;
    temp_a1->unk10 = HmfModelData[arg0].unk10;
    temp_a1->unk02 = HmfModelData[arg0].unk02;
    temp_a1->unk64->unk0B++;
    temp_a1->unk40 =
    temp_a1->unk03 =
    temp_a1->unk48 =
    temp_a1->unk4C =
    temp_a1->unk05 =
    temp_a1->unk54 =
    temp_a1->unk58 =
    temp_a1->unk07 =
    temp_a1->unk60 = 0;
    temp_a1->unk5C = 1.0f;
    temp_a1->unk50 = 1.0f;
    temp_a1->unk44 = 1.0f;
    temp_a1->unk06 = -1;
    temp_a1->unk04 = -1;
    temp_a1->unk09 = -1;
    temp_a1->unk08 = -1;
    temp_a1->unkB4 = 0;
    temp_a1->pos.x = temp_a1->pos.y = temp_a1->pos.z = 0.0f;
    temp_a1->rot.x = temp_a1->rot.y = temp_a1->rot.z = 0.0f;
    temp_a1->scale.x = temp_a1->scale.y = temp_a1->scale.z = 1.0f;
    temp_a1->unk01 = -1;
    func_8008A070_8AC70(temp_a1->unk74);
    D_800D1FE8_D2BE8++;
    return var_s0;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001A894_1B494);

s16 func_8001ABD4_1B7D4(s16 arg0, s8 arg1) {
    s16 temp_v0 = Hu3DModelLink(arg0);

    if (temp_v0 < 0) {
        return -1;
    }
    HmfModelData[temp_v0].unk00 = arg1;
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001AC34_1B834);

s16 func_8001AC8C_1B88C(s32 arg0, void (*arg1)(Gfx**, s32, s32), u8 arg2) {
    s16 var_v0 = func_8001A894_1B494(arg0, NULL, arg2);
    HmfModel* var_v1 = &HmfModelData[var_v0];

    var_v1->unk70 = arg1;
    return var_v0;
}

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001ACDC_1B8DC);

void func_8001AFE4_1BBE4(void) {
    s16 var_s0;

    for (var_s0 = 0; var_s0 < 0x80; var_s0++) {
        if (HmfModelData[var_s0].unk64 != NULL) {
            func_8001ACDC_1B8DC(var_s0);
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
    s16 var_s1;

    for (var_s1 = 0; var_s1 < D_800CBB72_CC772[arg1]; var_s1++) {
        HmfModel* temp_s0 = &HmfModelData[D_800D05A0_D11A0[arg1][var_s1]];

        if (!(temp_s0->unk01 & arg2) && arg2 != 0) {
            continue;
        }
        D_800CD2F6_CDEF6 = D_800D05A0_D11A0[arg1][var_s1];
        if (temp_s0->unk64->unk00 != D_800CE19A_CED9A) {
            gDPFullSync(gMainGfxPos++);
            gSPEndDisplayList(gMainGfxPos++);
            func_8000EF64_FB64(arg0, D_800CE19A_CED9A, 0, NULL, 0);
            D_800CE19A_CED9A = temp_s0->unk64->unk00;
            arg0 = gMainGfxPos;
        }
        if (temp_s0->unk70 != NULL) {
            temp_s0->unk70(&gMainGfxPos, D_800D0444_D1044, D_800D10F4_D1CF4);
        } else if (temp_s0->unk64->unk3C != NULL) {
            gSPDisplayList(gMainGfxPos++, temp_s0->unk64->unk3C);
        }
    }
    return arg0;
}

void func_8001BF14_1CB14(void) {
    s16 var_a0;

    HuMemSetDirty();
    for (var_a0 = 0; var_a0 < HU3D_MODEL_MAX; var_a0++) {
        HmfModelData[var_a0].unk64 = NULL;
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
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, arg1);
    gSPDisplayList(gMainGfxPos++, D_800A0A08_A1608);
    gDPSetColorImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, arg0);
    if (D_800CD280_CDE80 != 0) {
        gDPSetFillColor(gMainGfxPos++, PACK_FILL_COLOR(D_800A0540_A1140, D_800A0541_A1141, D_800A0542_A1142, 1));
        gSPDisplayList(gMainGfxPos++, D_800A0A38_A1638);
    }
}

void Hu3DModelPosSet(s16 arg0, f32 x, f32 y, f32 z) {
    if (arg0 >= 0 && HmfModelData[arg0].unk64 != NULL) {
        HmfModelData[arg0].pos.x = x;
        HmfModelData[arg0].pos.y = y;
        HmfModelData[arg0].pos.z = z;
    }
}

void Hu3DModelPosGet(s16 arg0, Vec* arg1) {
    arg1->x = HmfModelData[arg0].pos.x;
    arg1->y = HmfModelData[arg0].pos.y;
    arg1->z = HmfModelData[arg0].pos.z;
}

void Hu3DModelRotSet(s16 arg0, f32 x, f32 y, f32 z) {
    if (arg0 >= 0 && HmfModelData[arg0].unk64 != NULL) {
        HmfModelData[arg0].rot.x = x;
        HmfModelData[arg0].rot.y = y;
        HmfModelData[arg0].rot.z = z;
    }
}

void Hu3DModelScaleSet(s16 arg0, f32 x, f32 y, f32 z) {
    if (arg0 >= 0 && HmfModelData[arg0].unk64 != NULL) {
        HmfModelData[arg0].scale.x = x;
        HmfModelData[arg0].scale.y = y;
        HmfModelData[arg0].scale.z = z;
    }
}

void func_8001C1F0_1CDF0(s16 arg0, s32 arg1) {
    s16 var_s0;

    for (var_s0 = 0; var_s0 < HU3D_MODEL_MAX; var_s0++) {
        func_8001C258_1CE58(var_s0, arg0, arg1);
    }
}

void func_8001C258_1CE58(s16 arg0, s32 arg1, s32 arg2) {
    HmfModel* model = &HmfModelData[arg0];

    if (model->unk64 != NULL) {
        if (arg1 & 0xB3F82) {
            arg2 |= 0x800000;
        }
        if (arg1 & 0x1C00) {
            func_8001C8E4_1D4E4(arg0, arg2 & 0x1C00);
        }
        model->unk18 &= ~arg1;
        model->unk18 |= arg2;
    }
}

void func_8001C2FC_1CEFC(s16 arg0, s32 arg1, s32 arg2) {
    HmfModelData_Unk64_Struct* temp_a3 = HmfModelData[arg0].unk64;
    s16 var_t0;

    for (var_t0 = 0; var_t0 < temp_a3->unk10; var_t0++) {
        temp_a3->unk60[var_t0].unk50 &= ~arg1;
        temp_a3->unk60[var_t0].unk50 |= arg2;
    }
}

void func_8001C39C_1CF9C(s16 arg0, s32 arg1, s32 arg2, s32 arg3) {
    HmfModelData_Unk64_Struct* temp_s0 = HmfModelData[arg0].unk64;
    s16 temp_v0 = func_8002C834_2D434(temp_s0, arg1);

    if (temp_v0 >= 0) {
        temp_s0->unk60[temp_v0].unk50 &= ~arg2;
        temp_s0->unk60[temp_v0].unk50 |= arg3;
    }
}

INCLUDE_RODATA("asm/nonmatchings/hmfman", D_800A6BB8_A77B8);

INCLUDE_RODATA("asm/nonmatchings/hmfman", D_800A6BBC_A77BC);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C448_1D048);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C514_1D114);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C5B4_1D1B4);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C624_1D224);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C6A8_1D2A8);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C718_1D318);

INCLUDE_ASM("asm/nonmatchings/hmfman", func_8001C760_1D360);

f32 func_8001C7D0_1D3D0(s16 arg0) {
    if (HmfModelData[arg0].unk04 == 0xFF) {
        return -1.0f;
    }
    return HmfModelData[arg0].unk4C;
}

void func_8001C814_1D414(s16 arg0, s16 arg1, s16 arg2) {
    HmfModel* temp_a3 = &HmfModelData[arg0];

    temp_a3->unk03 &= ~arg1;
    temp_a3->unk03 |= arg2;
    if (temp_a3->unk64->unk98 != NULL) {
        temp_a3->unk64->unk98->unk02 &= ~arg1;
        temp_a3->unk64->unk98->unk02 |= arg2;
    }
    if (temp_a3->unk04 != 0xFF) {
        temp_a3->unk05 &= ~arg1;
        temp_a3->unk05 |= arg2;
    }
}

void func_8001C8A8_1D4A8(s16 arg0, s16 arg1) {
    if (arg0 >= 0 && HmfModelData[arg0].unk64 != NULL) {
        HmfModelData[arg0].unk01 = arg1;
    }
}

void func_8001C8E4_1D4E4(s16 arg0, u32 arg1) {
    HmfModelData[arg0].unk18 &= ~0x1C00;
    HmfModelData[arg0].unk18 |= arg1;
    HmfModelData[arg0].unk64->unk00 = (arg1 >> 10) & 7;
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
