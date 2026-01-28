#include "game/hmflight.h"
#include "game/camera.h"
#include "game/hmfman.h"
#include "mallocblock.h"

// EXTERN

extern HuCamMtxs* D_800D0444_D1044;

f32 HuSqrtf(f32);

// LOCAL

typedef struct {
    /* 0x00 */ s8 r;
    /* 0x01 */ s8 g;
    /* 0x02 */ s8 b;
    /* 0x03 */ u8 stat;
    /* 0x04 */ s8 unk04;
    /* 0x05 */ s8 unk05;
    /* 0x06 */ s8 unk06;
} UnkLightData_unk02; // Size 7

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ UnkLightData_unk02 unk02[8];
    /* 0x3A */ char unk3A[6];
    /* 0x40 */ Light unk40[3][8][8];
} UnkLightData; // Size 0xC40

extern Light* D_800CB8A8_CC4A8;
extern s16 D_800CC0B4_CCCB4;
extern UnkLightData* D_800CE1D4_CEDD4;
extern u8 D_800D2008_D2C08;

void HmfLightInit(void) {
    s16 var_a1;

    if (D_800CE1D4_CEDD4 == NULL) {
        D_800CE1D4_CEDD4 = HuMemAlloc(sizeof(UnkLightData));
    }
    for (var_a1 = 0; var_a1 < 8; var_a1++) {
        D_800CE1D4_CEDD4->unk02[var_a1].stat = 0;
        D_800CE1D4_CEDD4->unk02[var_a1].r =
        D_800CE1D4_CEDD4->unk02[var_a1].g =
        D_800CE1D4_CEDD4->unk02[var_a1].b = 0x40;
        D_800CE1D4_CEDD4->unk02[var_a1].unk04 =
        D_800CE1D4_CEDD4->unk02[var_a1].unk05 = 0;
        D_800CE1D4_CEDD4->unk02[var_a1].unk06 = 100;
    }
    D_800CE1D4_CEDD4->unk00 = 1;
    func_80019968_1A568(1);
}

void HmfLightClose(void) {
}

void HmfLightExec(s16 arg0) {
    s16 var_s1;

    D_800CB8A8_CC4A8 = D_800CE1D4_CEDD4->unk40[D_800D2008_D2C08][arg0];
    for (var_s1 = 0; var_s1 < D_800CE1D4_CEDD4->unk00 + 1; var_s1++) {
        Light* temp_s0 = &D_800CB8A8_CC4A8[var_s1];

        temp_s0->l.col[0] = temp_s0->l.colc[0] = D_800CE1D4_CEDD4->unk02[var_s1].r;
        temp_s0->l.col[1] = temp_s0->l.colc[1] = D_800CE1D4_CEDD4->unk02[var_s1].g;
        temp_s0->l.col[2] = temp_s0->l.colc[2] = D_800CE1D4_CEDD4->unk02[var_s1].b;
        if (D_800CE1D4_CEDD4->unk02[var_s1].stat & 1) {
            f32 sp10[4][4];
            f32 temp_f24 = D_800CE1D4_CEDD4->unk02[var_s1].unk04;
            f32 temp_f26 = D_800CE1D4_CEDD4->unk02[var_s1].unk05;
            f32 temp_f28 = D_800CE1D4_CEDD4->unk02[var_s1].unk06;
            f32 temp_f22;
            f32 temp_f20;
            f32 temp_f24_2;
            f32 temp_f0;

            guMtxL2F(sp10, &D_800D0444_D1044->lookAtMtx);
            temp_f22 = temp_f24 * sp10[0][0] + temp_f26 * sp10[1][0] + temp_f28 * sp10[2][0];
            temp_f20 = temp_f24 * sp10[0][1] + temp_f26 * sp10[1][1] + temp_f28 * sp10[2][1];
            temp_f24_2 = temp_f24 * sp10[0][2] + temp_f26 * sp10[1][2] + temp_f28 * sp10[2][2];
            temp_f0 = temp_f22 * temp_f22 + temp_f20 * temp_f20 + temp_f24_2 * temp_f24_2;
            temp_f0 = HuSqrtf(temp_f0);
            temp_s0->l.dir[0] = (temp_f22 / temp_f0) * 120.0f;
            temp_s0->l.dir[1] = (temp_f20 / temp_f0) * 120.0f;
            temp_s0->l.dir[2] = (temp_f24_2 / temp_f0) * 120.0f;
        } else {
            temp_s0->l.dir[0] = D_800CE1D4_CEDD4->unk02[var_s1].unk04;
            temp_s0->l.dir[1] = D_800CE1D4_CEDD4->unk02[var_s1].unk05;
            temp_s0->l.dir[2] = D_800CE1D4_CEDD4->unk02[var_s1].unk06;
        }
    }
}

void HmfLightReset(void) {
    s16 var_a3;

    D_800CB8A8_CC4A8 = D_800CE1D4_CEDD4->unk40[D_800D2008_D2C08][0];
    for (var_a3 = 0; var_a3 < D_800CE1D4_CEDD4->unk00 + 1; var_a3++) {
        D_800CB8A8_CC4A8[var_a3].l.col[0] = D_800CB8A8_CC4A8[var_a3].l.colc[0] = D_800CE1D4_CEDD4->unk02[var_a3].r;
        D_800CB8A8_CC4A8[var_a3].l.col[1] = D_800CB8A8_CC4A8[var_a3].l.colc[1] = D_800CE1D4_CEDD4->unk02[var_a3].g;
        D_800CB8A8_CC4A8[var_a3].l.col[2] = D_800CB8A8_CC4A8[var_a3].l.colc[2] = D_800CE1D4_CEDD4->unk02[var_a3].b;
    }
}

void HmfLightMaxSet(s16 arg0) {
    if (arg0 >= 8) {
        arg0 = 7;
    }
    D_800CE1D4_CEDD4->unk00 = arg0;
}

void HmfLightStatSet(s16 arg0, u8 arg1, u8 arg2) {
    if (D_800CE1D4_CEDD4->unk00 >= arg0) {
        D_800CE1D4_CEDD4->unk02[arg0].stat &= ~arg1;
        D_800CE1D4_CEDD4->unk02[arg0].stat |= arg2;
    }
}

void HmfLightColorSet(s16 arg0, u8 arg1, u8 arg2, u8 arg3) {
    if (D_800CE1D4_CEDD4->unk00 >= arg0) {
        D_800CE1D4_CEDD4->unk02[arg0].r = arg1;
        D_800CE1D4_CEDD4->unk02[arg0].g = arg2;
        D_800CE1D4_CEDD4->unk02[arg0].b = arg3;
    }
}

void HmfLightDirSet(s16 arg0, f32 arg1, f32 arg2, f32 arg3) {
    if (D_800CE1D4_CEDD4->unk00 >= arg0) {
        f32 temp_f0 = arg1 * arg1 + arg2 * arg2 + arg3 * arg3;

        temp_f0 = HuSqrtf(temp_f0);
        D_800CE1D4_CEDD4->unk02[arg0].unk04 = (arg1 / temp_f0) * 120.0f;
        D_800CE1D4_CEDD4->unk02[arg0].unk05 = (arg2 / temp_f0) * 120.0f;
        D_800CE1D4_CEDD4->unk02[arg0].unk06 = (arg3 / temp_f0) * 120.0f;
    }
}

void func_80019668_1A268(HmfData_UnkD0* arg0) {
    Light* temp_s0 = &arg0->unk08[D_800D2008_D2C08];

    temp_s0->l.col[0] = temp_s0->l.colc[0] = arg0->unk00;
    temp_s0->l.col[1] = temp_s0->l.colc[1] = arg0->unk01;
    temp_s0->l.col[2] = temp_s0->l.colc[2] = arg0->unk02;
    if (arg0->unk03 & 1) {
        f32 sp10[4][4];
        f32 temp_f22 = arg0->unk04;
        f32 temp_f26 = arg0->unk05;
        f32 temp_f28 = arg0->unk06;
        f32 temp_f24;
        f32 temp_f20;
        f32 temp_f22_2;
        f32 temp_f0;

        guMtxL2F(sp10, &D_800D0444_D1044->lookAtMtx);
        temp_f24 = temp_f22 * sp10[0][0] + temp_f26 * sp10[1][0] + temp_f28 * sp10[2][0];
        temp_f20 = temp_f22 * sp10[0][1] + temp_f26 * sp10[1][1] + temp_f28 * sp10[2][1];
        temp_f22_2 = temp_f22 * sp10[0][2] + temp_f26 * sp10[1][2] + temp_f28 * sp10[2][2];
        temp_f0 = temp_f24 * temp_f24 + temp_f20 * temp_f20 + temp_f22_2 * temp_f22_2;
        temp_f0 = HuSqrtf(temp_f0);
        temp_s0->l.dir[0] = (temp_f24 / temp_f0) * 120.0f;
        temp_s0->l.dir[1] = (temp_f20 / temp_f0) * 120.0f;
        temp_s0->l.dir[2] = (temp_f22_2 / temp_f0) * 120.0f;
    } else {
        temp_s0->l.dir[0] = arg0->unk04;
        temp_s0->l.dir[1] = arg0->unk05;
        temp_s0->l.dir[2] = arg0->unk06;
    }
}

s16 func_80019828_1A428(s16 arg0, s16 arg1) {
    HmfData* temp_v0_2 = HmfModelData[arg0].hmf;
    UnkLightData_unk02* temp_s5 = temp_v0_2->unkC0;
    s16 temp_v0 = temp_v0_2->unk20;
    s16 var_s2;

    for (var_s2 = 0; var_s2 < temp_v0; var_s2++) {
        HmfLightColorSet(arg1 + var_s2, temp_s5[var_s2].r, temp_s5[var_s2].g, temp_s5[var_s2].b);
        HmfLightDirSet(arg1 + var_s2, temp_s5[var_s2].unk04, temp_s5[var_s2].unk05, temp_s5[var_s2].unk06);
        HmfLightStatSet(arg1 + var_s2, 1, temp_s5[var_s2].stat);
    }
    return temp_v0;
}

void func_80019968_1A568(s16 arg0) {
    D_800CC0B4_CCCB4 = arg0;
}
