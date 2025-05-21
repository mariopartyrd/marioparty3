#include "ovl_39.h"

#define M_ID(m, i, j) ((m)[(i) * 4 + (j)])

// EXTERN

typedef struct {
    /* 0x00 */ void* unk00;
    /* 0x04 */ u16 unk04;
    /* 0x06 */ u16 unk06;
    /* 0x08 */ char unk08[4];
} Func_80055194_55D94_Unk00_Struct; // Size 0xC

typedef struct {
    /* 0x00 */ Func_80055194_55D94_Unk00_Struct* unk00;
    /* 0x04 */ char unk04[4];
    /* 0x08 */ u8* unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ char unk12[6];
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u16 unk1A;
} Func_80055194_55D94_Struct; // Size unknown

typedef struct {
    /* 0x00 */ char unk00[0x10];
    /* 0x10 */ s16 unk10;
} Func_80055520_56120_Unk84_Struct;

typedef struct {
    /* 0x00 */ char unk00[0x84];
    /* 0x84 */ Func_80055520_56120_Unk84_Struct* unk84;
    /* 0x88 */ char unk88[8];
    /* 0x90 */ s16 unk90;
} Func_80055520_56120_Struct; // Size unknown

s32 SprAttrReset();
s32 SprAttrSet();

void Hu3DModelRotSet(s16, f32, f32, f32);
void* HuMemAlloc(s32);
void* HuMemAllocTag(s32, s32);
void HuMemFree(void*);
void* memcpy(void*, const void*, unsigned int);
void func_80017D24_18924(f32*, f32, f32, f32);
s32 func_8001A894_1B494(s32, Gfx*, s32);
void func_80054FF8_55BF8(s32, s32, s32);
Func_80055194_55D94_Struct* func_80055194_55D94(s32);
Func_80055520_56120_Struct* func_80055520_56120(s32, s32);
f32 func_8008E108_8ED08(f32, f32);

extern s16 D_800CDD6A_CE96A;
extern f32 D_800D138C_D1F8C[];
extern u8 D_800D1FF0_D2BF0;
extern u8 D_800D2008_D2C08;

// LOCAL

typedef struct {
    /* 0x00 */ s8 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ u8 unk08;
    /* 0x0A */ s16 unk0A;
    /* 0x0C */ s16 unk0C;
    /* 0x0E */ s16 unk0E;
    /* 0x10 */ f32* unk10;
    /* 0x14 */ f32* unk14;
    /* 0x18 */ f32* unk18;
} D_8010E6F0_2C5B60_Struct; // Size 0x1C

typedef struct {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} RGBA;

void func_80109F30_2C13A0_tick_tock_hop(D_8010E6F4_2C5B64_Struct* arg0);
s32 func_8010AD60_2C21D0_tick_tock_hop(Func_80055194_55D94_Struct* arg0, f32 arg1);
s32 func_8010B4D0_2C2940_tick_tock_hop(Func_80055194_55D94_Struct* arg0, f32 arg1);
void func_8010CCD4_2C4144_tick_tock_hop(u16 arg0, Func_80055194_55D94_Struct* arg1, u16 arg2);
s16 func_8010CED8_2C4348_tick_tock_hop(Func_80055194_55D94_Struct* arg0, HmfModelData_Unk64_Struct* arg1, f32 arg2, u16 arg3, u16 arg4);
void func_8010D5DC_2C4A4C_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1);
f32 func_8010D938_2C4DA8_tick_tock_hop(D_8010E700_2C5B70_Struct* arg0, D_8010E700_2C5B70_Unk98_Struct* arg1, Vec* arg2, Vec* arg3);
void func_8010DFB0_2C5420_tick_tock_hop(f32* arg0);
void func_8010E2AC_2C571C_tick_tock_hop(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32* arg6);
void func_8010E364_2C57D4_tick_tock_hop(Vec* arg0, s16 arg1, f32* arg2, Vec* arg3);

D_8010E6F0_2C5B60_Struct* D_8010E6F0_2C5B60_tick_tock_hop;
D_8010E6F4_2C5B64_Struct* D_8010E6F4_2C5B64_tick_tock_hop;
D_8010E6F8_2C5B68_Struct* D_8010E6F8_2C5B68_tick_tock_hop;
D_8010E6FC_2C5B6C_Struct* D_8010E6FC_2C5B6C_tick_tock_hop;
D_8010E700_2C5B70_Struct* D_8010E700_2C5B70_tick_tock_hop;

// TODO: the following arrays work but trigger multiple warnings: "missing braces around initializer"
// Ideally we should use these and remove the u32 arrays below.
/*
Gfx D_8010E4B0_2C5920_tick_tock_hop[] = {
    gsSPSegment(0x00, 0x00000000),
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTileSize(G_TX_RENDERTILE, 0, 0, 0, 0),
    gsDPSetTileSize(1, 0, 0, 0, 0),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTile(G_IM_FMT_RGBA, G_IM_SIZ_4b, 0, 0x0000, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetDepthSource(G_ZS_PIXEL),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPNoOp(),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPPipeSync(),
    gsSPEndDisplayList()
};

Gfx D_8010E568_2C59D8_tick_tock_hop[] = {
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList()
};

Gfx D_8010E588_2C59F8_tick_tock_hop[] = {
    gsSPDisplayList(D_8010E568_2C59D8_tick_tock_hop),
    gsSPDisplayList(D_8010E4B0_2C5920_tick_tock_hop),
    gsSPEndDisplayList()
};

Gfx D_8010E5A0_2C5A10_tick_tock_hop[] = {
    gsDPPipeSync(),
    gsSPDisplayList(D_8010E588_2C59F8_tick_tock_hop),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsSPSetGeometryMode(G_ZBUFFER | G_CULL_BACK | G_LIGHTING | G_SHADING_SMOOTH),
    gsDPSetBlendColor(0x00, 0x00, 0x00, 0x00),
    gsDPSetPrimColor(0, 0, 0x00, 0x00, 0x00, 0xFF),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsSPEndDisplayList()
};
*/

u32 D_8010E4B0_2C5920_tick_tock_hop[] = {
    0xDB060000, 0x00000000, 0xE7000000, 0x00000000, 0xE3000A01, 0x00000000, 0xE3000800, 0x00800000,
    0xE3000F00, 0x00000000, 0xE3001001, 0x00000000, 0xE3000D01, 0x00000000, 0xE3000C00, 0x00000000,
    0xF2000000, 0x00000000, 0xF2000000, 0x01000000, 0xF5000000, 0x00000000, 0xF5000000, 0x01000000,
    0xE3001201, 0x00002000, 0xE3001402, 0x00000C00, 0xFCFFFFFF, 0xFFFE793C, 0xE3001700, 0x00000000,
    0xE2001E01, 0x00000000, 0xE2001D00, 0x00000000, 0xE200001C, 0x0F0A4000, 0x00000000, 0x00000000,
    0xE3001801, 0x000000C0, 0xE7000000, 0x00000000, 0xDF000000, 0x00000000, 0xD9000000, 0x00000000,
    0xD7000000, 0x00000000, 0xD9FFFFFF, 0x00200004, 0xDF000000, 0x00000000, 0xDE000000, 0x8010E568,
    0xDE000000, 0x8010E4B0, 0xDF000000, 0x00000000
};

u32 D_8010E5A0_2C5A10_tick_tock_hop[] = {
    0xE7000000, 0x00000000, 0xDE000000, 0x8010E588, 0xE3000A01, 0x00000000, 0xD9FFFFFF, 0x00220401,
    0xF9000000, 0x00000000, 0xFA000000, 0x000000FF, 0xD7000002, 0xFFFFFFFF, 0xDF000000, 0x00000000
};

u8 D_8010E5E0_2C5A50_tick_tock_hop[] = { 0, 1, 0, 1, 2, 0, 2, 3, 0, 3, 0, 0, 0, 0, 0 };

void func_80109A00_2C0E70_tick_tock_hop(void) {
    D_8010E6F8_2C5B68_tick_tock_hop = HuMemAllocTag(8 * sizeof(*D_8010E6F8_2C5B68_tick_tock_hop), 31000);
    memset(D_8010E6F8_2C5B68_tick_tock_hop, 0, 8 * sizeof(*D_8010E6F8_2C5B68_tick_tock_hop));
    D_8010E6FC_2C5B6C_tick_tock_hop = HuMemAllocTag(8 * sizeof(*D_8010E6FC_2C5B6C_tick_tock_hop), 31000);
    memset(D_8010E6FC_2C5B6C_tick_tock_hop, 0, 8 * sizeof(*D_8010E6FC_2C5B6C_tick_tock_hop));
    D_8010E6F0_2C5B60_tick_tock_hop = HuMemAllocTag(2 * sizeof(*D_8010E6F0_2C5B60_tick_tock_hop), 31000);
    memset(D_8010E6F0_2C5B60_tick_tock_hop, 0, 2 * sizeof(*D_8010E6F0_2C5B60_tick_tock_hop));
    D_8010E6F4_2C5B64_tick_tock_hop = HuMemAllocTag(5 * sizeof(*D_8010E6F4_2C5B64_tick_tock_hop), 31000);
}

D_8010E6F4_2C5B64_Struct* func_80109A94_2C0F04_tick_tock_hop(omObjData* arg0, s8 arg1, s16 arg2, s16 arg3) {
    D_8010E6F4_2C5B64_Struct* temp_s2;

    if (arg1 >= 5) {
        return NULL;
    }
    temp_s2 = &D_8010E6F4_2C5B64_tick_tock_hop[arg1];
    if (arg3 != 0) {
        temp_s2->unk04 = HuMemAllocTag(arg3 * sizeof(*temp_s2->unk04), 31000);
        memset(temp_s2->unk04, 0, arg3 * sizeof(*temp_s2->unk04));
        temp_s2->unk0C = HuMemAllocTag((arg3 + 1) * sizeof(*temp_s2->unk0C), 31000);
    }
    temp_s2->unk08 = arg3;
    temp_s2->unk00 = HuMemAllocTag(sizeof(*temp_s2->unk00), 31000);
    if (arg2 != 0) {
        temp_s2->unk00->unk04 = HuMemAllocTag(arg2 * sizeof(*temp_s2->unk00->unk04), 31000);
        memset(temp_s2->unk00->unk04, 0, arg2 * sizeof(*temp_s2->unk00->unk04));
    }
    temp_s2->unk00->unk08 = arg2;
    temp_s2->unk10 = 1;
    temp_s2->unk00->unk00 = arg0;
    return temp_s2;
}

// 2C5B08 TODO: figure this out. File split?
const u8 workaround[8] = { 0 };

s16 func_80109BE4_2C1054_tick_tock_hop(s8 arg0, s32 arg1, D_8010E6E4_2C5B54_Struct* arg2, void (*arg3)(D_8010E6F4_2C5B64_Unk00_Struct*, D_8010E6F4_2C5B64_Unk04_Struct*), s8 arg4) {
    D_8010E6F4_2C5B64_Struct* temp_t2 = &D_8010E6F4_2C5B64_tick_tock_hop[arg0];
    D_8010E6F4_2C5B64_Unk04_Struct* var_v1 = temp_t2->unk04;
    s16 temp_v0 = temp_t2->unk08;
    s16 var_a0;

    for (var_a0 = 0; var_a0 < temp_v0; var_a0++, var_v1++) {
        if (var_v1->unk00 == 0) {
            var_v1->unk00 = 1;
            var_v1->unk08 = arg1;
            var_v1->unk02 = var_a0;
            var_v1->unk05 = arg4;
            var_v1->unk04 = 0;
            var_v1->unk3C = arg2;
            var_v1->unk40 = arg3;
            break;
        }
    }
    if (var_a0 == temp_v0) {
        osSyncPrintf("SetFunc Error %d!\n", arg0);
        return -1;
    }
    temp_t2->unk10 = 1;
    return var_a0;
}

void func_80109CC0_2C1130_tick_tock_hop(s8 arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    memset(arg1, 0, sizeof(*arg1));
    D_8010E6F4_2C5B64_tick_tock_hop[arg0].unk10 = 1;
}

void func_80109D18_2C1188_tick_tock_hop(s8 arg0, s8 arg1) {
    D_8010E6F4_2C5B64_Struct* temp_s2 = &D_8010E6F4_2C5B64_tick_tock_hop[arg0];
    D_8010E6F4_2C5B64_Unk04_Struct* var_s0;
    s16 var_s1;

    var_s0 = temp_s2->unk04;
    for (var_s1 = 0; var_s1 < temp_s2->unk08; var_s1++, var_s0++) {
        if (var_s0->unk05 == arg1) {
            func_80109CC0_2C1130_tick_tock_hop(arg0, var_s0);
        }
    }
}

void func_80109DCC_2C123C_tick_tock_hop(s8 arg0) {
    D_8010E6F4_2C5B64_Struct* temp_s0 = &D_8010E6F4_2C5B64_tick_tock_hop[arg0];

    memset(temp_s0->unk04, 0, temp_s0->unk08 * sizeof(*temp_s0->unk04));
    temp_s0->unk10 = 1;
}

void func_80109E2C_2C129C_tick_tock_hop(s8 arg0) {
    D_8010E6F4_2C5B64_Struct* temp_s1 = &D_8010E6F4_2C5B64_tick_tock_hop[arg0];
    D_8010E6F4_2C5B64_Unk04_Struct* temp_a1;
    s8 temp_s0;

    if (temp_s1->unk10 != 0) {
        func_80109F30_2C13A0_tick_tock_hop(temp_s1);
    }
    temp_s0 = 0;
    while (temp_s1->unk0C[temp_s0].unk04 != -1) {
        temp_s0 = temp_s1->unk0C[temp_s0].unk04;
        temp_a1 = &temp_s1->unk04[temp_s1->unk0C[temp_s0].unk08];
        if (temp_a1->unk00 != 0) {
            temp_a1->unk40(temp_s1->unk00, temp_a1);
        }
    }
}

void func_80109F30_2C13A0_tick_tock_hop(D_8010E6F4_2C5B64_Struct* arg0) {
    D_8010E6F4_2C5B64_Unk0C_Struct* temp_a1 = arg0->unk0C;
    D_8010E6F4_2C5B64_Unk04_Struct* var_t1 = arg0->unk04;
    s16 var_a3;
    s16 temp_a0;
    s16 var_a2;
    s16 var_t3;

    temp_a1->unk04 = -1;
    var_a3 = 1;
    for (var_t3 = 0; var_t3 < arg0->unk08; var_t3++, var_t1++) {
        if (var_t1->unk00 == 0) {
            continue;
        }
        var_a2 = temp_a0 = 0;
        while (temp_a1[temp_a0].unk04 != -1) {
            temp_a0 = temp_a1[temp_a0].unk04;
            if (temp_a1[temp_a0].unk00 < var_t1->unk08) {
                var_a2 = temp_a0;
                break;
            }
        }
        temp_a1[var_a3].unk08 = var_t3;
        temp_a1[var_a3].unk00 = var_t1->unk08;
        temp_a1[var_a3].unk04 = temp_a1[var_a2].unk04;
        temp_a1[var_a3].unk06 = var_a2;
        temp_a1[var_a2].unk04 = var_a3;
        if (temp_a1[var_a3].unk04 != -1) {
            temp_a1[temp_a1[var_a3].unk04].unk06 = var_a3;
        }
        var_a3++;
    }
    arg0->unk10 = 0;
}

s16 func_8010A07C_2C14EC_tick_tock_hop(u16 arg0, s32 arg1, s32 arg2, u16 arg3, s32 arg4) {
    D_8010E6F8_2C5B68_Struct* var_s0 = D_8010E6F8_2C5B68_tick_tock_hop;
    Func_80055520_56120_Struct* temp_v0_2;
    s16 var_s1;

    for (var_s1 = 0; var_s1 < 8; var_s1++, var_s0++) {
        if (var_s0->unk00 == 0) {
            var_s0->unk02 = func_8000B838_C438((arg1 << 16) | arg2);
            var_s0->unk01 = func_8005279C_5339C(1, 0);
            var_s0->unk06 = 0xFF;
            SprAttrReset(var_s0->unk01, 0, -1);
            func_80055024_55C24(var_s0->unk01, 0, var_s0->unk02, 0);
            SprAttrSet(var_s0->unk01, 0, arg4);
            func_800550F4_55CF4(var_s0->unk01, 0, arg3);
            SprPriSet(var_s0->unk01, 0, arg0);
            func_80054FF8_55BF8(var_s0->unk01, 0, 0);
            func_800550B4_55CB4(var_s0->unk01, 0, 1.0f);
            SprScale(var_s0->unk01, 0, 1.0f, 1.0f);
            func_80054904_55504(var_s0->unk01, 0, 100, 100);
            temp_v0_2 = func_80055520_56120(var_s0->unk01, 0);
            if (arg3 == 0) {
                var_s0->unk04 = 99;
            } else {
                var_s0->unk04 = temp_v0_2->unk84->unk10;
            }
            var_s0->unk00 = 2;
            func_8010A2B0_2C1720_tick_tock_hop(var_s1);
            break;
        }
    }
    return var_s1;
}

void func_8010A21C_2C168C_tick_tock_hop(s16 arg0, s32 arg1, s32 arg2) {
    D_8010E6F8_2C5B68_Struct* temp_s0 = &D_8010E6F8_2C5B68_tick_tock_hop[arg0];

    if (temp_s0->unk00 != 0) {
        func_80054FF8_55BF8(temp_s0->unk01, 0, 0);
        SprAttrReset(temp_s0->unk01, 0, 0x8000);
        func_80054904_55504(temp_s0->unk01, 0, arg1, arg2);
        temp_s0->unk00 = 2;
    }
}

void func_8010A2B0_2C1720_tick_tock_hop(s16 arg0) {
    D_8010E6F8_2C5B68_Struct* temp_s0 = &D_8010E6F8_2C5B68_tick_tock_hop[arg0];

    if (temp_s0->unk00 != 0) {
        SprAttrSet(temp_s0->unk01, 0, 0x8000);
        temp_s0->unk00 = 1;
    }
}

void func_8010A300_2C1770_tick_tock_hop(void) {
    D_8010E6F8_2C5B68_Struct* var_s0;
    s16 var_s1;

    var_s0 = D_8010E6F8_2C5B68_tick_tock_hop;
    for (var_s1 = 0; var_s1 < 8; var_s1++, var_s0++) {
        if (var_s0->unk00 == 2 && func_80055520_56120(var_s0->unk01, 0)->unk90 + 1 >= var_s0->unk04) {
            SprAttrSet(var_s0->unk01, 0, 0x8000);
            func_80054FF8_55BF8(var_s0->unk01, 0, 0);
        }
    }
}

s32 func_8010A3A8_2C1818_tick_tock_hop(s32 arg0, s32 arg1, f32 arg2, s32 arg3, s32 arg4) {
    D_8010E6FC_2C5B6C_Struct* var_s0;
    HmfModelData_Struct* temp_v0_3;
    s16 var_s1;

    var_s0 = D_8010E6FC_2C5B6C_tick_tock_hop;
    for (var_s1 = 0; var_s1 < 8; var_s1++, var_s0++) {
        if (var_s0->unk00 == 0) {
            var_s0->unk0A = func_8000B108_BD08((arg0 << 16) | arg1, arg4);
            func_8001C258_1CE58(var_s0->unk0A, 4, 4);
            temp_v0_3 = &HmfModelData[var_s0->unk0A];
            temp_v0_3->unk40 = 0.0f;
            temp_v0_3->unk44 = 0.0f;
            if (temp_v0_3->unk64->unk98 != NULL) {
                temp_v0_3->unk64->unk98->unk08 = 0;
            }
            var_s0->unk04 = arg3;
            var_s0->unk0C = arg2;
            var_s0->unk08 = -1;
            var_s0->unk00 = 1;
            break;
        }
    }
    return var_s1;
}

s32 func_8010A4A8_2C1918_tick_tock_hop(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, f32 arg7, f32 arg8) {
    D_8010E6FC_2C5B6C_Struct* temp_s0;
    HmfModelData_Struct* temp_s1;

    if (arg0 >= 8) {
        return 0;
    }
    if (D_8010E6FC_2C5B6C_tick_tock_hop[arg0].unk00 == 0) {
        return 0;
    }
    temp_s0 = &D_8010E6FC_2C5B6C_tick_tock_hop[arg0];
    temp_s1 = &HmfModelData[temp_s0->unk0A];
    if ((temp_s1->unk18 & 4) && temp_s0->unk08 == -1) {
        Hu3DModelPosSet(temp_s0->unk0A, arg1, arg2, arg3);
        Hu3DModelRotSet(temp_s0->unk0A, arg4, arg5, arg6);
        Hu3DModelScaleSet(temp_s0->unk0A, arg7, arg7, arg7);
        if (arg8 == 0.0f) {
            func_8001C258_1CE58(temp_s0->unk0A, 4, 0);
            temp_s0->unk08 = 1;
            temp_s0->unk14 = 0.0f;
            temp_s0->unk10 = 0.0f;
            temp_s1->unk44 = temp_s0->unk0C;
        } else {
            temp_s0->unk08 = 0;
            temp_s0->unk14 = arg8;
            temp_s0->unk10 = 0.0f;
        }
        return 1;
    }
    return 0;
}

void func_8010A620_2C1A90_tick_tock_hop(void) {
    D_8010E6FC_2C5B6C_Struct* var_s0;
    HmfModelData_Struct* temp_s1;
    s16 var_s2;

    var_s0 = D_8010E6FC_2C5B6C_tick_tock_hop;
    for (var_s2 = 0; var_s2 < 8; var_s2++, var_s0++) {
        if (var_s0->unk00 == 0 || var_s0->unk08 == -1) {
            continue;
        }
        temp_s1 = &HmfModelData[var_s0->unk0A];
        if (var_s0->unk08 != 0) {
            if (D_800CCF58_CDB58[temp_s1->unk02].unk02 <= temp_s1->unk40) {
                temp_s1->unk40 = 0.0f;
                if (temp_s1->unk64->unk98 != NULL) {
                    temp_s1->unk64->unk98->unk08 = 0;
                }
                if (!(var_s0->unk04 & 1)) {
                    func_8001C258_1CE58(var_s0->unk0A, 4, 4);
                    var_s0->unk08 = -1;
                    temp_s1->unk44 = 0;
                }
            }
        } else if (var_s0->unk14 <= var_s0->unk10++) {
            func_8001C258_1CE58(var_s0->unk0A, 4, 0);
            var_s0->unk08 = 1;
            temp_s1->unk44 = var_s0->unk0C;
        }
    }
}

s32 func_8010A788_2C1BF8_tick_tock_hop(s32 arg0, s32 arg1, s32 arg2) {
    D_8010E6F0_2C5B60_Struct* var_s0;
    s16 temp_v0_2;
    s16 var_s3;

    var_s0 = D_8010E6F0_2C5B60_tick_tock_hop;
    for (var_s3 = 0; var_s3 < 2; var_s3++, var_s0++) {
        if (var_s0->unk00 == 0) {
            temp_v0_2 = func_8000B838_C438((arg0 << 16) | arg1);
            var_s0->unk08 = temp_v0_2;
            if (arg2 & 1) {
                var_s0->unk0A = func_8010B4D0_2C2940_tick_tock_hop(func_80055194_55D94(temp_v0_2), 1.0f);
            } else {
                var_s0->unk0A = func_8010AD60_2C21D0_tick_tock_hop(func_80055194_55D94(temp_v0_2), 1.0f);
            }
            if (arg2 & 8) {
                func_8001C258_1CE58(var_s0->unk0A, 4, 4);
            }
            var_s0->unk10 = &HmfModelData[var_s0->unk0A].unk1C;
            var_s0->unk14 = &HmfModelData[var_s0->unk0A].unk20;
            var_s0->unk18 = &HmfModelData[var_s0->unk0A].unk24;
            var_s0->unk04 = arg2;
            var_s0->unk0C = func_80055194_55D94(temp_v0_2)->unk10;
            var_s0->unk0E = 0;
            var_s0->unk00 = 1;
            break;
        }
    }
    if (var_s3 == 2) {
        osSyncPrintf("SetBill Error! \n");
    }
    return var_s3;
}

void func_8010A90C_2C1D7C_tick_tock_hop(s16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    if (arg0 < 2) {
        HmfModelData_Struct* temp_v0 = &HmfModelData[D_8010E6F0_2C5B60_tick_tock_hop[arg0].unk0A];

        temp_v0->unk1C = arg1;
        temp_v0->unk20 = arg2;
        temp_v0->unk24 = arg3;
        func_8001C258_1CE58(D_8010E6F0_2C5B60_tick_tock_hop[arg0].unk0A, 4, 0);
        D_8010E6F0_2C5B60_tick_tock_hop[arg0].unk04 &= ~0x18;
    }
}

void func_8010A9B0_2C1E20_tick_tock_hop(s16 arg0, f32* arg1, f32* arg2, f32* arg3) {
    HmfModelData_Struct* temp_t1;
    D_8010E6F0_2C5B60_Struct* temp_s0;

    if (arg0 >= 2) {
        return;
    }
    temp_t1 = &HmfModelData[D_8010E6F0_2C5B60_tick_tock_hop[arg0].unk0A];
    if (arg1 != NULL) {
        D_8010E6F0_2C5B60_tick_tock_hop[arg0].unk10 = arg1;
    } else {
        D_8010E6F0_2C5B60_tick_tock_hop[arg0].unk10 = &temp_t1->unk1C;
    }
    if (arg2 != NULL) {
        D_8010E6F0_2C5B60_tick_tock_hop[arg0].unk14 = arg2;
    } else {
        D_8010E6F0_2C5B60_tick_tock_hop[arg0].unk14 = &temp_t1->unk20;
    }
    if (arg3 != NULL) {
        D_8010E6F0_2C5B60_tick_tock_hop[arg0].unk18 = arg3;
    } else {
        D_8010E6F0_2C5B60_tick_tock_hop[arg0].unk18 = &temp_t1->unk24;
    }
    func_8001C258_1CE58(D_8010E6F0_2C5B60_tick_tock_hop[arg0].unk0A, 4, 0);
    temp_s0 = &D_8010E6F0_2C5B60_tick_tock_hop[arg0];
    temp_s0->unk04 &= ~0x18;
    temp_s0->unk04 |= 0x10;
}

D_8010E6F0_2C5B60_Struct* func_8010AB40_2C1FB0_tick_tock_hop(s16 arg0) {
    if (arg0 >= 2) {
        return NULL;
    }
    return &D_8010E6F0_2C5B60_tick_tock_hop[arg0];
}

HmfModelData_Struct* func_8010AB78_2C1FE8_tick_tock_hop(s16 arg0) {
    if (arg0 >= 2) {
        return NULL;
    }
    return &HmfModelData[D_8010E6F0_2C5B60_tick_tock_hop[arg0].unk0A];
}

void func_8010ABCC_2C203C_tick_tock_hop(void) {
    D_8010E6F0_2C5B60_Struct* var_s1;
    HmfModelData_Struct* temp_s0;
    s16 var_s2;

    var_s1 = D_8010E6F0_2C5B60_tick_tock_hop;
    for (var_s2 = 0; var_s2 < 2; var_s2++, var_s1++) {
        if (var_s1->unk00 == 0 || (var_s1->unk04 & 8)) {
            continue;
        }
        temp_s0 = &HmfModelData[var_s1->unk0A];
        if (var_s1->unk04 & 0x10) {
            temp_s0->unk1C = *var_s1->unk10;
            temp_s0->unk20 = *var_s1->unk14;
            temp_s0->unk24 = *var_s1->unk18;
        }
        temp_s0->unk28 = D_800D138C_D1F8C[0];
        temp_s0->unk2C = D_800D138C_D1F8C[1];
        func_8010DFB0_2C5420_tick_tock_hop(temp_s0->unk74);
        func_80017D24_18924(temp_s0->unk74, 0.0f, 0.0f, D_800D138C_D1F8C[2]);
        if (var_s1->unk04 & 1) {
            if (var_s1->unk04 & 2) {
                func_8010CCD4_2C4144_tick_tock_hop(var_s1->unk0A, func_80055194_55D94(var_s1->unk08), var_s1->unk0E);
                var_s1->unk0E++;
                if (var_s1->unk0E >= var_s1->unk0C) {
                    if (var_s1->unk04 & 4) {
                        var_s1->unk0E = 0;
                    } else {
                        var_s1->unk0E = 0;
                        var_s1->unk04 |= 8;
                        func_8001C258_1CE58(var_s1->unk0A, 4, 4);
                    }
                }
            }
        }
    }
}

s32 func_8010AD60_2C21D0_tick_tock_hop(Func_80055194_55D94_Struct* arg0, f32 arg1) {
    HmfModelData_Unk64_Struct* temp_s6;
    Gfx* temp_v0_0;
    Gfx* temp_v0;
    u32 temp_s5;
    s32 temp_s0;
    s32 var_s7;
    s16 temp_v0_2;
    s16 var_s4;

    temp_v0_0 = temp_v0 = HuMemAlloc(0x10000);
    temp_v0_2 = func_8001A894_1B494(0x4C1, temp_v0_0, 4);
    temp_s6 = HmfModelData[temp_v0_2].unk64;
    temp_s6->unk60->unk50 |= 0x01010000;
    temp_s5 = func_8010CED8_2C4348_tick_tock_hop(arg0, temp_s6, 1.0f, 0, 0x64);
    gSPDisplayList(temp_v0++, osVirtualToPhysical(D_8010E5A0_2C5A10_tick_tock_hop));
    gDPPipeSync(temp_v0++);
    gDPSetCycleType(temp_v0++, G_CYC_1CYCLE);
    gDPPipeSync(temp_v0++);
    gSPClearGeometryMode(temp_v0++, G_CULL_BOTH | G_LIGHTING);
    gSPSetGeometryMode(temp_v0++, G_ZBUFFER | G_SHADE | G_CULL_FRONT | G_TEXTURE_GEN_LINEAR | G_SHADING_SMOOTH);
    gDPSetColorDither(temp_v0++, G_CD_NOISE);
    gDPSetTexturePersp(temp_v0++, G_TP_NONE);
    gDPSetTextureFilter(temp_v0++, G_TF_BILERP);
    gDPSetTextureConvert(temp_v0++, G_TC_FILT);
    gDPSetAlphaDither(temp_v0++, G_AD_PATTERN);
    gDPSetAlphaCompare(temp_v0++, G_AC_NONE);
    gDPSetBlendColor(temp_v0++, 0x01, 0x01, 0x01, 0x01);
    gDPPipeSync(temp_v0++);
    gDPSetRenderMode(temp_v0++, G_RM_ZB_XLU_SURF, G_RM_NOOP2);
    gDPSetCombineLERP(temp_v0++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(temp_v0++, 0, 0, 0xFF, 0xFF, 0xFF, arg1 * 255.0f);
    gDPPipeSync(temp_v0++);
    gSPTexture(temp_v0++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(temp_v0++, G_TP_PERSP);
    if (arg0->unk1A >= 2) {
        gDPSetTextureLUT(temp_v0++, G_TT_RGBA16);
        var_s7 = 0x800;
        if (arg0->unk18 == 4) {
            gDPLoadTLUT_pal16(temp_v0++, 0, arg0->unk0C);
        } else {
            gDPLoadTLUT_pal256(temp_v0++, arg0->unk0C);
        }
    } else {
        gDPSetTextureLUT(temp_v0++, G_TT_NONE);
        var_s7 = 0x1000;
    }
    gDPPipeSync(temp_v0++);
    for (var_s4 = 0; var_s4 < temp_s5; var_s4++) {
        gSPSegment(temp_v0++, 0x02, osVirtualToPhysical(arg0->unk08 + var_s7 * var_s4));
        gDPLoadTextureBlock(temp_v0++, 0x02000000, G_IM_FMT_CI, G_IM_SIZ_8b,
            arg0->unk00->unk04, arg0->unk00->unk06 / temp_s5, 0,
            G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
            G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gDPPipeSync(temp_v0++);
        gSPSegment(temp_v0++, 0x01, osVirtualToPhysical(&temp_s6->unk44[0][var_s4 * 4]));
        gSPVertex(temp_v0++, 0x01000000, 4, 0);
        gSP2Triangles(temp_v0++, 0, 1, 2, 0, 1, 3, 2, 0);
    }
    gSPClearGeometryMode(temp_v0++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(temp_v0++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_TEXTURE_GEN_LINEAR);
    gDPPipeSync(temp_v0++);
    gSPEndDisplayList(temp_v0++);
    temp_s0 = (u32) temp_v0 - (u32) temp_v0_0;
    temp_s6->unk3C->unk00 = HuMemAllocTag(temp_s0, temp_s6->unk0E);
    bcopy(temp_v0_0, temp_s6->unk3C->unk00, temp_s0);
    HuMemFree(temp_v0_0);
    return temp_v0_2;
}

s32 func_8010B4D0_2C2940_tick_tock_hop(Func_80055194_55D94_Struct* arg0, f32 arg1) {
    HmfModelData_Unk64_Struct* temp_s4;
    Gfx* temp_v0_0;
    Gfx* temp_v0;
    s32 temp_s0;
    s16 temp_v0_2;
    s16 var_a2;
    s16 var_s1;

    temp_v0_0 = temp_v0 = HuMemAlloc(0x10000);
    temp_v0_2 = func_8001A894_1B494(0x4C1, temp_v0_0, 4);
    temp_s4 = HmfModelData[temp_v0_2].unk64;
    temp_s4->unk60->unk50 |= 0x01010000;
    HuMemFree(temp_s4->unk3C);
    temp_s4->unk3C = HuMemAllocTag(0x14, D_800CDD6A_CE96A);
    func_8010CED8_2C4348_tick_tock_hop(arg0, temp_s4, 1.0f, 0, 0x1E);
    gSPDisplayList(temp_v0++, osVirtualToPhysical(D_8010E5A0_2C5A10_tick_tock_hop));
    gDPPipeSync(temp_v0++);
    gDPSetCycleType(temp_v0++, G_CYC_1CYCLE);
    gDPPipeSync(temp_v0++);
    gSPClearGeometryMode(temp_v0++, G_CULL_BOTH | G_LIGHTING);
    gSPSetGeometryMode(temp_v0++, G_ZBUFFER | G_CULL_FRONT | G_TEXTURE_GEN_LINEAR);
    gDPSetColorDither(temp_v0++, G_CD_NOISE);
    gDPSetTexturePersp(temp_v0++, G_TP_NONE);
    gDPSetTextureFilter(temp_v0++, G_TF_BILERP);
    gDPSetTextureConvert(temp_v0++, G_TC_FILT);
    gDPSetAlphaDither(temp_v0++, G_AD_PATTERN);
    gDPSetAlphaCompare(temp_v0++, G_AC_NONE);
    gDPSetBlendColor(temp_v0++, 0x01, 0x01, 0x01, 0x01);
    gDPPipeSync(temp_v0++);
    gDPSetRenderMode(temp_v0++, G_RM_ZB_XLU_SURF, G_RM_NOOP2);
    if (arg0->unk1A >= 2) {
        gDPSetCombineLERP(temp_v0++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        gDPSetPrimColor(temp_v0++, 0, 0, 0xFF, 0xFF, 0xFF, arg1 * 255.0f);
    } else {
        if (arg0->unk18 & 0x8000) {
            gDPSetCombineLERP(temp_v0++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
        } else {
            gDPSetCombineLERP(temp_v0++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
        }
        gDPSetPrimColor(temp_v0++, 0, 0, 0xFF, 0xFF, 0xFF, arg1 * 255.0f);
    }
    gDPPipeSync(temp_v0++);
    gSPTexture(temp_v0++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(temp_v0++, G_TP_PERSP);
    if (arg0->unk1A >= 2) {
        gDPSetTextureLUT(temp_v0++, G_TT_RGBA16);
        if (arg0->unk18 == 4) {
            gDPLoadTLUT_pal16(temp_v0++, 0, arg0->unk0C);
        } else {
            gDPLoadTLUT_pal256(temp_v0++, arg0->unk0C);
        }
        gDPPipeSync(temp_v0++);
        var_a2 = 2;
    } else {
        gDPSetTextureLUT(temp_v0++, G_TT_NONE);
        gDPPipeSync(temp_v0++);
        var_a2 = (arg0->unk18 & 0x8000) ? 4 : 0;
    }
    switch (arg0->unk18 & 0xFFF) {
        case 4:
            gDPLoadTextureBlock_4b(temp_v0++, 0x02000000, var_a2,
                arg0->unk00->unk04, arg0->unk00->unk06, 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
        case 8:
            gDPLoadTextureBlock(temp_v0++, 0x02000000, var_a2, G_IM_SIZ_8b,
                arg0->unk00->unk04, arg0->unk00->unk06, 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
        case 16:
            gDPLoadTextureBlock(temp_v0++, 0x02000000, var_a2, G_IM_SIZ_16b,
                arg0->unk00->unk04, arg0->unk00->unk06, 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
    }
    gDPPipeSync(temp_v0++);
    gSPSegment(temp_v0++, 0x01, osVirtualToPhysical(temp_s4->unk44[0]));
    gSPVertex(temp_v0++, 0x01000000, 4, 0);
    gSP2Triangles(temp_v0++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSPClearGeometryMode(temp_v0++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(temp_v0++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_TEXTURE_GEN_LINEAR);
    gDPPipeSync(temp_v0++);
    gSPEndDisplayList(temp_v0++);
    temp_s0 = (u32) temp_v0 - (u32) temp_v0_0;
    temp_s4->unk3C->unk00 = temp_s4->unk3C->unk10 = HuMemAllocTag(temp_s0, temp_s4->unk0E);
    bcopy(temp_v0_0, temp_s4->unk3C->unk00, temp_s0);
    HuMemFree(temp_v0_0);
    for (var_s1 = 0; var_s1 < D_800D1FF0_D2BF0; var_s1++) {
        temp_v0 = *(temp_s4->unk3C->unk04 + var_s1) = HuMemAllocTag(0x100, temp_s4->unk0E);
        gDPPipeSync(temp_v0++);
        gSPSegment(temp_v0++, 0x02, osVirtualToPhysical(arg0->unk00->unk00));
        gSPDisplayList(temp_v0++, osVirtualToPhysical(temp_s4->unk3C->unk10));
        gSPEndDisplayList(temp_v0++);
    }
    temp_s4->unk3C->unk00 = temp_s4->unk3C->unk04[D_800D2008_D2C08];
    return temp_v0_2;
}

s16 func_8010C0E8_2C3558_tick_tock_hop(Func_80055194_55D94_Struct* arg0, RGBA* arg1) {
    HmfModelData_Unk64_Struct* temp_s4;
    Gfx* temp_v0_0;
    Gfx* temp_v0_2;
    s32 temp_s0;
    s32 temp_v0;
    s32 var_a2;
    s32 var_s1;

    temp_v0_0 = temp_v0_2 = HuMemAlloc(0x10000);
    temp_v0 = func_8001A894_1B494(0x8C1, temp_v0_0, 4);
    temp_s4 = HmfModelData[temp_v0].unk64;
    temp_s4->unk60->unk50 |= 0x01010000;
    HuMemFree(temp_s4->unk3C);
    temp_s4->unk3C = HuMemAllocTag(0x18, D_800CDD6A_CE96A);
    func_8010CED8_2C4348_tick_tock_hop(arg0, temp_s4, 1.0f, 0, 0);
    gSPDisplayList(temp_v0_2++, osVirtualToPhysical(D_8010E5A0_2C5A10_tick_tock_hop));
    gDPPipeSync(temp_v0_2++);
    gDPSetCycleType(temp_v0_2++, G_CYC_1CYCLE);
    gDPPipeSync(temp_v0_2++);
    gSPClearGeometryMode(temp_v0_2++, G_CULL_BOTH | G_LIGHTING);
    gSPSetGeometryMode(temp_v0_2++, G_ZBUFFER | G_CULL_FRONT | G_TEXTURE_GEN_LINEAR);
    gDPSetColorDither(temp_v0_2++, G_CD_NOISE);
    gDPSetTexturePersp(temp_v0_2++, G_TP_NONE);
    gDPSetTextureFilter(temp_v0_2++, G_TF_BILERP);
    gDPSetTextureConvert(temp_v0_2++, G_TC_FILT);
    gDPSetAlphaDither(temp_v0_2++, G_AD_PATTERN);
    gDPSetAlphaCompare(temp_v0_2++, G_AC_NONE);
    gDPSetBlendColor(temp_v0_2++, 0x01, 0x01, 0x01, 0x01);
    gDPPipeSync(temp_v0_2++);
    gDPSetRenderMode(temp_v0_2++, G_RM_ZB_XLU_SURF, G_RM_NOOP2);
    if (arg0->unk18 & 0x8000) {
        gDPSetCombineLERP(temp_v0_2++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
    } else {
        gDPSetCombineLERP(temp_v0_2++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    }
    gDPPipeSync(temp_v0_2++);
    gSPEndDisplayList(temp_v0_2++);
    temp_s0 = (u32) temp_v0_2 - (u32) temp_v0_0;
    temp_s4->unk3C->unk10 = HuMemAllocTag(temp_s0, temp_s4->unk0E);
    bcopy(temp_v0_0, temp_s4->unk3C->unk10, temp_s0);
    HuMemFree(temp_v0_0);
    temp_v0_0 = temp_v0_2 = HuMemAlloc(0x10000);
    gSPTexture(temp_v0_2++, 0x8000, 0x8000, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTexturePersp(temp_v0_2++, G_TP_PERSP);
    if (arg0->unk1A >= 2) {
        gDPSetTextureLUT(temp_v0_2++, G_TT_RGBA16);
        if (arg0->unk18 == 4) {
            gDPLoadTLUT_pal16(temp_v0_2++, 0, arg0->unk0C);
        } else {
            gDPLoadTLUT_pal256(temp_v0_2++, arg0->unk0C);
        }
        gDPPipeSync(temp_v0_2++);
        var_a2 = 2;
    } else {
        gDPSetTextureLUT(temp_v0_2++, G_TT_NONE);
        gDPPipeSync(temp_v0_2++);
        var_a2 = (arg0->unk18 & 0x8000) ? 4 : 0;
    }
    switch (arg0->unk18 & 0xFFF) {
        case 4:
            gDPLoadTextureBlock_4b(temp_v0_2++, 0x02000000, var_a2,
                arg0->unk00->unk04, arg0->unk00->unk06, 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
        case 8:
            gDPLoadTextureBlock(temp_v0_2++, 0x02000000, var_a2, G_IM_SIZ_8b,
                arg0->unk00->unk04, arg0->unk00->unk06, 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
        case 16:
            gDPLoadTextureBlock(temp_v0_2++, 0x02000000, var_a2, G_IM_SIZ_16b,
                arg0->unk00->unk04, arg0->unk00->unk06, 0,
                G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP,
                G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            break;
    }
    gDPPipeSync(temp_v0_2++);
    gSPSegment(temp_v0_2++, 0x01, osVirtualToPhysical(temp_s4->unk44[0]));
    gSPVertex(temp_v0_2++, 0x01000000, 4, 0);
    gSP2Triangles(temp_v0_2++, 0, 1, 2, 0, 1, 3, 2, 0);
    gSPClearGeometryMode(temp_v0_2++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA);
    gSPSetGeometryMode(temp_v0_2++, G_ZBUFFER | G_SHADE | G_CULL_BACK | G_TEXTURE_GEN_LINEAR);
    gDPPipeSync(temp_v0_2++);
    gSPEndDisplayList(temp_v0_2++);
    temp_s0 = (u32) temp_v0_2 - (u32) temp_v0_0;
    temp_s4->unk3C->unk14 = HuMemAllocTag(temp_s0, temp_s4->unk0E);
    bcopy(temp_v0_0, temp_s4->unk3C->unk14, temp_s0);
    HuMemFree(temp_v0_0);
    for (var_s1 = 0; var_s1 < D_800D1FF0_D2BF0; var_s1++) {
        temp_v0_2 = temp_s4->unk3C->unk04[var_s1] = HuMemAllocTag(0x100, temp_s4->unk0E);
        gDPPipeSync(temp_v0_2++);
        gSPSegment(temp_v0_2++, 0x02, osVirtualToPhysical(arg0->unk00->unk00));
        gSPDisplayList(temp_v0_2++, osVirtualToPhysical(temp_s4->unk3C->unk10));
        gDPSetPrimColor(temp_v0_2++, 0, 0, arg1->r, arg1->g, arg1->b, arg1->a);
        gDPPipeSync(temp_v0_2++);
        gSPDisplayList(temp_v0_2++, osVirtualToPhysical(temp_s4->unk3C->unk14));
        gDPPipeSync(temp_v0_2++);
        gSPEndDisplayList(temp_v0_2++);
    }
    temp_s4->unk3C->unk00 = temp_s4->unk3C->unk04[D_800D2008_D2C08];
    return temp_v0;
}

void func_8010CCD4_2C4144_tick_tock_hop(u16 arg0, Func_80055194_55D94_Struct* arg1, u16 arg2) {
    HmfModelData_Struct* var_v1 = &HmfModelData[arg0];
    HmfModelData_Unk64_Struct* temp_s2 = var_v1->unk64;
    Gfx* temp_s0 = temp_s2->unk3C->unk04[D_800D2008_D2C08];

    temp_s2->unk3C->unk00 = temp_s0;
    gDPPipeSync(&temp_s0[0]);
    gSPSegment(&temp_s0[1], 0x02, osVirtualToPhysical(arg1->unk00[arg2].unk00));
    gSPDisplayList(&temp_s0[2], osVirtualToPhysical(temp_s2->unk3C->unk10));
    gDPPipeSync(&temp_s0[3]);
    gSPEndDisplayList(&temp_s0[4]);
}

void func_8010CDA4_2C4214_tick_tock_hop(u16 arg0, Func_80055194_55D94_Struct* arg1, u16 arg2, RGBA* arg3) {
    HmfModelData_Struct* temp_hmf = &HmfModelData[arg0];
    HmfModelData_Unk64_Struct* temp_s3 = temp_hmf->unk64;
    HmfModelData_Unk64_Unk3C_Struct* temp_v1 = temp_s3->unk3C;
    Gfx* temp_s0 = temp_v1->unk04[D_800D2008_D2C08];

    temp_v1->unk00 = temp_s0;
    gDPPipeSync(&temp_s0[0]);
    gSPSegment(&temp_s0[1], 0x02, osVirtualToPhysical(arg1->unk00[arg2].unk00));
    gSPDisplayList(&temp_s0[2], osVirtualToPhysical(temp_s3->unk3C->unk10));
    gDPSetPrimColor(&temp_s0[3], 0, 0, arg3->r, arg3->g, arg3->b, arg3->a);
    gDPPipeSync(&temp_s0[4]);
    gSPDisplayList(&temp_s0[5], osVirtualToPhysical(temp_s3->unk3C->unk14));
    gDPPipeSync(&temp_s0[6]);
    gSPEndDisplayList(&temp_s0[7]);
}

s16 func_8010CED8_2C4348_tick_tock_hop(Func_80055194_55D94_Struct* arg0, HmfModelData_Unk64_Struct* arg1, f32 arg2, u16 arg3, u16 arg4) {
    Vtx* temp_s7;
    Vtx* var_s1;
    Vtx_t* var_t0;
    Vtx_t* var_a3;
    s32 var_a2;
    s32 temp_s4;
    s32 temp_a1;
    s32 sp24;
    s32 temp_f2;
    s32 var_s0;
    s32 var_s2;
    s32 sp2C;
    s32 temp_lo;
    s32 temp_s3;
    s32 var_s0_2;
    s32 var_a2_2;

    if (arg0->unk1A >= 2) {
        var_a2 = 0x800;
    } else {
        var_a2 = 0x1000;
    }
    temp_s4 = arg0->unk00->unk04;
    temp_a1 = arg0->unk00->unk06;
    sp24 = (f64) (temp_s4 * 0x64) * arg2 / 32.0;
    temp_f2 = (f64) (temp_a1 * 0x64) * arg2 / 32.0;
    if ((arg0->unk18 & 0xFFF) == 4) {
        var_s0 = ((temp_s4 + 1) & 0xFFFE) * temp_a1 * 4;
    } else {
        var_s0 = temp_s4 * temp_a1 * arg0->unk18;
    }
    var_s0 = (var_s0 < 0) ? (var_s0 + 7) : var_s0;
    var_s0 >>= 3;
    var_s2 = var_s0 / var_a2;
    if (var_s2 <= 0) {
        var_s2 = 1;
    }
    sp2C = temp_a1 / var_s2;
    temp_lo = temp_f2 / var_s2;
    temp_s3 = var_s2 * 4;
    temp_s7 = var_s1 = HuMemAllocTag(temp_s3 * sizeof(Vtx), arg1->unk0E);
    memset(temp_s7, 0, temp_s3 * sizeof(Vtx));
    for (var_s0_2 = 0; var_s0_2 < var_s2; var_s0_2++, var_s1 += 4) {
        var_s1[0].v.ob[0] = (s32) (sp24 * 0.5);
        var_s1[0].v.ob[1] = (s32) (temp_f2 * 0.5 - temp_lo * var_s0_2);
        var_s1[0].v.tc[0] = (temp_s4 - 1) * 64;
        var_s1[0].v.tc[1] = 0;
        var_s1[1].v.ob[0] = (s32) (sp24 * 0.5);
        var_s1[1].v.ob[1] = (s32) (temp_f2 * 0.5 - temp_lo * (var_s0_2 + 1));
        var_s1[1].v.tc[0] = (temp_s4 - 1) * 64;
        var_s1[1].v.tc[1] = (sp2C - 1) * 64;
        var_s1[2].v.ob[0] = (s32) -(sp24 * 0.5);
        var_s1[2].v.ob[1] = (s32) (temp_f2 * 0.5 - temp_lo * var_s0_2);
        var_s1[2].v.tc[0] = 0;
        var_s1[2].v.tc[1] = 0;
        var_s1[3].v.ob[0] = (s32) -(sp24 * 0.5);
        var_s1[3].v.ob[1] = (s32) (temp_f2 * 0.5 - temp_lo * (var_s0_2 + 1));
        var_s1[3].v.tc[0] = 0;
        var_s1[3].v.tc[1] = (sp2C - 1) * 64;
        for (var_a2_2 = 0; var_a2_2 < 4; var_a2_2++) {
            var_s1[var_a2_2].v.ob[0] += arg3;
            var_s1[var_a2_2].v.ob[1] += arg4;
            var_s1[var_a2_2].v.ob[2] = 0;
            var_s1[var_a2_2].v.flag = 0;
            var_s1[var_a2_2].v.cn[3] = 0xFF;
            var_s1[var_a2_2].v.cn[0] = var_s1[var_a2_2].v.cn[1] = var_s1[var_a2_2].v.cn[2] = 0;
        }
    }
    var_s1 = temp_s7;
    for (var_s0_2 = 0; var_s0_2 < D_800D1FF0_D2BF0; var_s0_2++) {
        arg1->unk44[var_s0_2] = HuMemAllocTag(temp_s3 * sizeof(Vtx), arg1->unk0E);
        var_t0 = &arg1->unk44[var_s0_2]->v;
        var_a3 = &var_s1->v;
        for (var_a2_2 = 0; var_a2_2 < temp_s3; var_a2_2++) {
            *(var_t0++) = *(var_a3++);
        }
    }
    HuMemFree(temp_s7);
    return var_s2;
}

void func_8010D2FC_2C476C_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E700_2C5B70_tick_tock_hop = HuMemAllocTag(2 * sizeof(*D_8010E700_2C5B70_tick_tock_hop), 31000);
    memset(D_8010E700_2C5B70_tick_tock_hop, 0, 2 * sizeof(*D_8010E700_2C5B70_tick_tock_hop));
    arg1->unk40 = func_8010D5DC_2C4A4C_tick_tock_hop;
}

s32 func_8010D34C_2C47BC_tick_tock_hop(s16 arg0, D_8010E700_2C5B70_Unk60_Struct* arg1, f32 arg2, s16 arg3, s32 arg4) {
    HmfModelData_Struct* temp_v1 = &HmfModelData[arg0];
    D_8010E700_2C5B70_Struct* var_s0;
    s16 var_s1;

    var_s0 = D_8010E700_2C5B70_tick_tock_hop;
    for (var_s1 = 0; var_s1 < 2; var_s1++, var_s0++) {
        if (var_s0->unk04 == 0) {
            var_s0->unk08 = &temp_v1->unk1C;
            var_s0->unk0C = &temp_v1->unk20;
            var_s0->unk10 = &temp_v1->unk24;
            var_s0->unk14 = &temp_v1->unk28;
            var_s0->unk18 = &temp_v1->unk2C;
            var_s0->unk1C = &temp_v1->unk30;
            var_s0->unk60 = *arg1;
            var_s0->unk94 = arg2;
            var_s0->unk90 = 4;
            if (arg3 != 0) {
                var_s0->unk98 = HuMemAllocTag(arg3 * 0x10, 0x7918);
            }
            var_s0->unk9C = arg3;
            var_s0->unk9E = 0;
            var_s0->unk00 = arg4;
            var_s0->unk04 = 1;
            break;
        }
    }
    if (var_s1 == 2) {
        return -1;
    }
    return var_s1;
}

D_8010E700_2C5B70_Unk98_Struct* func_8010D49C_2C490C_tick_tock_hop(s16 arg0, s16 arg1) {
    D_8010E700_2C5B70_Unk98_Struct* temp_v0;
    HmfModelData_Struct* var_v1;

    if (arg0 >= 2) {
        return NULL;
    }
    if (D_8010E700_2C5B70_tick_tock_hop[arg0].unk04 == 0) {
        return NULL;
    }
    if (D_8010E700_2C5B70_tick_tock_hop[arg0].unk9E >= D_8010E700_2C5B70_tick_tock_hop[arg0].unk9C) {
        return NULL;
    }
    temp_v0 = &D_8010E700_2C5B70_tick_tock_hop[arg0].unk98[D_8010E700_2C5B70_tick_tock_hop[arg0].unk9E];
    var_v1 = &HmfModelData[arg1];
    temp_v0->unk04 = &var_v1->unk1C;
    temp_v0->unk08 = &var_v1->unk20;
    temp_v0->unk0C = &var_v1->unk24;
    D_8010E700_2C5B70_tick_tock_hop[arg0].unk9E++;
    return temp_v0;
}

void func_8010D568_2C49D8_tick_tock_hop(s16 arg0, D_8010E700_2C5B70_Unk60_Struct* arg1, f32 arg2) {
    D_8010E700_2C5B70_Struct* temp_s0;

    if (arg0 < 2 && D_8010E700_2C5B70_tick_tock_hop[arg0].unk04 != 0) {
        temp_s0 = &D_8010E700_2C5B70_tick_tock_hop[arg0];
        memcpy(&temp_s0->unk60, arg1, temp_s0->unk90 * sizeof(Vec));
        temp_s0->unk94 = arg2;
    }
}

void func_8010D5DC_2C4A4C_tick_tock_hop(D_8010E6F4_2C5B64_Unk00_Struct* arg0, D_8010E6F4_2C5B64_Unk04_Struct* arg1) {
    D_8010E700_2C5B70_Struct* var_s2;
    Vec sp20[4];
    f32 temp_f0;
    s32 temp_v1;
    s16 var_s6;
    s16 var_s3;
    s16 var_s1;

    var_s2 = D_8010E700_2C5B70_tick_tock_hop;
    for (var_s6 = 0; var_s6 < 2; var_s6++, var_s2++) {
        if (var_s2->unk04 == 0) {
            continue;
        }
        if (var_s2->unk00 & 1) {
            for (var_s3 = 0; var_s3 < var_s2->unk9E; var_s3++) {
                var_s2->unk98[var_s3].unk00 = 0;
            }
            continue;
        }
        func_8010E2AC_2C571C_tick_tock_hop(*var_s2->unk08, *var_s2->unk0C, *var_s2->unk10, *var_s2->unk14, *var_s2->unk18, *var_s2->unk1C, var_s2->unk20);
        func_8010E364_2C57D4_tick_tock_hop(var_s2->unk60.unk00, 4, var_s2->unk20, sp20);
        for (var_s3 = 0; var_s3 < var_s2->unk9E; var_s3++) {
            D_8010E700_2C5B70_Unk98_Struct* temp_s0_2 = &var_s2->unk98[var_s3];

            if (!(var_s2->unk00 & 4) && *temp_s0_2->unk08 > var_s2->unk94) {
                temp_s0_2->unk00 = 0;
                continue;
            }
            temp_f0 = func_8010D938_2C4DA8_tick_tock_hop(var_s2, temp_s0_2, &sp20[D_8010E5E0_2C5A50_tick_tock_hop[0]], &sp20[D_8010E5E0_2C5A50_tick_tock_hop[1]]);
            if (temp_f0 == 0.0f) {
                temp_s0_2->unk00 = 0;
                continue;
            }
            if (temp_f0 > 0.0f) {
                temp_s0_2->unk00 = 1;
                for (var_s1 = 1; var_s1 < 4; var_s1++) {
                    temp_v1 = var_s1 * 3;
                    temp_f0 = func_8010D938_2C4DA8_tick_tock_hop(var_s2, temp_s0_2, &sp20[D_8010E5E0_2C5A50_tick_tock_hop[temp_v1]], &sp20[D_8010E5E0_2C5A50_tick_tock_hop[temp_v1 + 1]]);
                    if (temp_f0 == 0.0f) {
                        temp_s0_2->unk00 = 1;
                        break;
                    }
                    if (temp_f0 < 0.0f) {
                        temp_s0_2->unk00 = 0;
                        break;
                    }
                }
            } else {
                temp_s0_2->unk00 = 1;
                for (var_s1 = 1; var_s1 < 4; var_s1++) {
                    temp_v1 = var_s1 * 3;
                    temp_f0 = func_8010D938_2C4DA8_tick_tock_hop(var_s2, temp_s0_2, &sp20[D_8010E5E0_2C5A50_tick_tock_hop[temp_v1]], &sp20[D_8010E5E0_2C5A50_tick_tock_hop[temp_v1 + 1]]);
                    if (temp_f0 == 0.0f) {
                        temp_s0_2->unk00 = 1;
                        break;
                    }
                    if (temp_f0 > 0.0f) {
                        temp_s0_2->unk00 = 0;
                        break;
                    }
                }
            }
        }
    }
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
f32 func_8010D938_2C4DA8_tick_tock_hop(D_8010E700_2C5B70_Struct* arg0, D_8010E700_2C5B70_Unk98_Struct* arg1, Vec* arg2, Vec* arg3) {
    Vec sp0;
    Vec sp10;
    Vec sp20;

    sp0.x = *arg1->unk04;
    sp0.z = *arg1->unk0C;
    sp10.x = arg2->x - sp0.x;
    sp10.z = arg2->z - sp0.z;
    sp20.x = arg3->x - sp0.x;
    sp20.z = arg3->z - sp0.z;
    return sp10.z * sp20.x - sp10.x * sp20.z;
}

s32 func_8010D99C_2C4E0C_tick_tock_hop(f32* arg0, u8* arg1, f32 arg2, f32 arg3, f32 arg4) {
    f32 temp_div = *arg1 / arg4;

    *arg0 = arg2 + (arg3 - arg2) * temp_div;
    if (++(*arg1) > arg4) {
        *arg1 = 0;
        *arg0 = arg3;
        return 1;
    }
    return 0;
}

f32 func_8010DA14_2C4E84_tick_tock_hop(f32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    if (arg0 > 1.0f) {
        arg0 = 1.0f;
    }
    return (1.0f - arg0) * (1.0f - arg0) * arg1 + 2.0f * (1.0f - arg0) * arg0 * arg2 + arg0 * arg0 * arg3;
}

void func_8010DA80_2C4EF0_tick_tock_hop(s16* arg0, s16 arg1) {
    s16 temp_id;
    s16 temp_a1;
    s16 var_s1;

    for (var_s1 = 0; var_s1 < arg1; var_s1++) {
        arg0[var_s1] = var_s1;
    }
    for (var_s1 = arg1 - 1; var_s1 >= 0; var_s1--) {
        temp_id = rand16() % (var_s1 + 1);
        temp_a1 = arg0[var_s1];
        arg0[var_s1] = arg0[temp_id];
        arg0[temp_id] = temp_a1;
    }
}

void func_8010DB8C_2C4FFC_tick_tock_hop(omObjData* arg0) {
    HmfModelData_Struct* temp_v0 = &HmfModelData[arg0->model[0]];

    arg0->scale.x = temp_v0->unk34;
    arg0->scale.y = temp_v0->unk38;
    arg0->scale.z = temp_v0->unk3C;
    arg0->trans.x = temp_v0->unk1C;
    arg0->trans.y = temp_v0->unk20;
    arg0->trans.z = temp_v0->unk24;
    if (temp_v0->unk28 >= 360.0f) {
        temp_v0->unk28 -= 360.0f;
    }
    if (temp_v0->unk28 < 0.0f) {
        temp_v0->unk28 += 360.0f;
    }
    if (temp_v0->unk2C >= 360.0f) {
        temp_v0->unk2C -= 360.0f;
    }
    if (temp_v0->unk2C < 0.0f) {
        temp_v0->unk2C += 360.0f;
    }
    if (temp_v0->unk30 >= 360.0f) {
        temp_v0->unk30 -= 360.0f;
    }
    if (temp_v0->unk30 < 0.0f) {
        temp_v0->unk30 += 360.0f;
    }
    arg0->rot.x = temp_v0->unk28;
    arg0->rot.y = temp_v0->unk2C;
    arg0->rot.z = temp_v0->unk30;
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
void func_8010DD00_2C5170_tick_tock_hop(Vec arg0, Vec arg1, f32* arg2) {
    Vec sp10;
    f32 var_f2;
    f32 temp_360 = 360.0f;

    sp10.x = arg1.x - arg0.x;
    sp10.y = arg1.y - arg0.y;
    sp10.z = arg1.z - arg0.z;
    var_f2 = func_8008E108_8ED08(sp10.y, sqrtf(sp10.x * sp10.x + sp10.z * sp10.z));
    if (var_f2 < 0.0f) {
        var_f2 += temp_360;
    } else if (var_f2 >= temp_360) {
        var_f2 -= temp_360;
    }
    *(arg2++) = var_f2;
    var_f2 = func_8008E108_8ED08(sp10.x, sp10.z);
    if (var_f2 < 0.0f) {
        var_f2 += temp_360;
    } else if (var_f2 >= temp_360) {
        var_f2 -= temp_360;
    }
    *(arg2++) = var_f2;
}

void func_8010DE30_2C52A0_tick_tock_hop(f32* arg0, f32* arg1) {
    f32 var_f2;

    while (*arg1 < 0.0f) {
        *arg1 += 360.0f;
    }
    while (*arg1 >= 360.0f) {
        *arg1 -= 360.0f;
    }
    while (*arg0 < 0.0f) {
        *arg0 += 360.0f;
    }
    while (*arg0 >= 360.0f) {
        *arg0 -= 360.0f;
    }
    var_f2 = *arg1 - *arg0;
    if (!(var_f2 > 0.0f)) {
        var_f2 = -var_f2;
    }
    if (var_f2 > 180.0f) {
        if (*arg0 < *arg1) {
            *arg1 -= 360.0f;
        } else {
            *arg0 -= 360.0f;
        }
    }
}

void func_8010DFB0_2C5420_tick_tock_hop(f32* arg0) {
    s16 i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            M_ID(arg0, i, j) = 0.0f;
        }
        M_ID(arg0, i, i) = 1.0f;
    }
}

void func_8010E038_2C54A8_tick_tock_hop(f32* arg0, f32 arg1, f32 arg2, f32 arg3) {
    func_8010DFB0_2C5420_tick_tock_hop(arg0);
    M_ID(arg0, 3, 0) = arg1;
    M_ID(arg0, 3, 1) = arg2;
    M_ID(arg0, 3, 2) = arg3;
}

void func_8010E090_2C5500_tick_tock_hop(f32* arg0, f32 arg1) {
    func_8010DFB0_2C5420_tick_tock_hop(arg0);
    M_ID(arg0, 1, 1) = HuMathCos(arg1);
    M_ID(arg0, 1, 2) = HuMathSin(arg1);
    M_ID(arg0, 2, 1) = -HuMathSin(arg1);
    M_ID(arg0, 2, 2) = HuMathCos(arg1);
}

void func_8010E0F8_2C5568_tick_tock_hop(f32* arg0, f32 arg1) {
    func_8010DFB0_2C5420_tick_tock_hop(arg0);
    M_ID(arg0, 0, 0) = HuMathCos(arg1);
    M_ID(arg0, 0, 2) = -HuMathSin(arg1);
    M_ID(arg0, 2, 0) = HuMathSin(arg1);
    M_ID(arg0, 2, 2) = HuMathCos(arg1);
}

void func_8010E160_2C55D0_tick_tock_hop(f32* arg0, f32* arg1, f32* arg2) {
    s16 i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            M_ID(arg2, i, j) = M_ID(arg0, i, 0) * M_ID(arg1, 0, j) + M_ID(arg0, i, 1) * M_ID(arg1, 1, j) + M_ID(arg0, i, 2) * M_ID(arg1, 2, j) + M_ID(arg0, i, 3) * M_ID(arg1, 3, j);
        }
    }
}

void func_8010E214_2C5684_tick_tock_hop(f32* arg0, f32* arg1) {
    *(arg1++) = M_ID(arg0, 3, 0) * M_ID(arg0, 0, 0) + M_ID(arg0, 3, 1) * M_ID(arg0, 1, 0) + M_ID(arg0, 3, 2) * M_ID(arg0, 2, 0);
    *(arg1++) = M_ID(arg0, 3, 0) * M_ID(arg0, 0, 1) + M_ID(arg0, 3, 1) * M_ID(arg0, 1, 1) + M_ID(arg0, 3, 2) * M_ID(arg0, 2, 1);
    *(arg1++) = M_ID(arg0, 3, 0) * M_ID(arg0, 0, 2) + M_ID(arg0, 3, 1) * M_ID(arg0, 1, 2) + M_ID(arg0, 3, 2) * M_ID(arg0, 2, 2);
}

void func_8010E2AC_2C571C_tick_tock_hop(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32* arg6) {
    f32 sp10[16];
    f32 sp50[16];
    f32 sp90[16];
    f32 spD0[16];

    func_8010E038_2C54A8_tick_tock_hop(sp10, arg0, arg1, arg2);
    func_8010E090_2C5500_tick_tock_hop(sp50, arg3);
    func_8010E0F8_2C5568_tick_tock_hop(sp90, arg4);
    func_8010E160_2C55D0_tick_tock_hop(sp50, sp90, spD0);
    func_8010E160_2C55D0_tick_tock_hop(spD0, sp10, arg6);
}

void func_8010E364_2C57D4_tick_tock_hop(Vec* arg0, s16 arg1, f32* arg2, Vec* arg3) {
    s16 var_t0;

    for (var_t0 = 0; var_t0 < arg1; var_t0++) {
        arg3[var_t0].x = (M_ID(arg2, 3, 0) + arg0[var_t0].x) * M_ID(arg2, 0, 0) + (M_ID(arg2, 3, 1) + arg0[var_t0].y) * M_ID(arg2, 1, 0) + (M_ID(arg2, 3, 2) + arg0[var_t0].z) * M_ID(arg2, 2, 0);
        arg3[var_t0].y = (M_ID(arg2, 3, 0) + arg0[var_t0].x) * M_ID(arg2, 0, 1) + (M_ID(arg2, 3, 1) + arg0[var_t0].y) * M_ID(arg2, 1, 1) + (M_ID(arg2, 3, 2) + arg0[var_t0].z) * M_ID(arg2, 2, 1);
        arg3[var_t0].z = (M_ID(arg2, 3, 0) + arg0[var_t0].x) * M_ID(arg2, 0, 2) + (M_ID(arg2, 3, 1) + arg0[var_t0].y) * M_ID(arg2, 1, 2) + (M_ID(arg2, 3, 2) + arg0[var_t0].z) * M_ID(arg2, 2, 2);
    }
}
