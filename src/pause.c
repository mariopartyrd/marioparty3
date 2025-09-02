#include "game/pause.h"
#include "game/audio.h"
#include "game/data.h"
#include "game/gamework_data.h"
#include "game/hmfman.h"
#include "game/process.h"
#include "game/sprite.h"
#include "game/window.h"
#include "mallocblock.h"
#include "include_asm.h"
#include "macros.h"

// EXTERN

typedef struct MinigameTable {
    /* 0x00 */ u8 minigameType;
    /* 0x01 */ char unk_01[5];
    /* 0x06 */ s16 unk_06;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ char unk_0E[6];
} MinigameTable;

// 22EB0
s16 func_8002C834_2D434(HmfData*, const char*);

extern MinigameTable D_800A6D44_A7944[];

// LOCAL

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s8 unk04;
    /* 0x05 */ u8 unk05;
    /* 0x06 */ u8 unk06;
    /* 0x07 */ u8 unk07;
} D_800B2350_B2F50_Struct; // Size 8

typedef struct {
    /* 0x00 */ s16 unk00;
    /* 0x02 */ s16 unk02;
    /* 0x04 */ s16 unk04;
} UnkPausePrcData; // Size 6

void func_800453FC_45FFC(void);
void func_80045964_46564(s16, s16);
s16 func_80045B24_46724(s16, s16);
omObjData* func_80045F48_46B48(u32, s16, s16, s16);
void func_800461D8_46DD8(void);

extern u8 D_800A1590_A2190[];
extern s16 D_800A159C_A219C[];
extern u8* D_800A1610_A2210[];
extern u8 D_800A1630_A2230[];
extern u8 D_800A1640_A2240[][4];
extern s16 D_800B2340_B2F40[3];
extern s16 D_800B2344_B2F44;
extern D_800B2350_B2F50_Struct D_800B2350_B2F50[];
extern omObjData* D_800B2390_B2F90;
extern f32 D_800B23A0_B2FA0;
extern f32 D_800B23A4_B2FA4;
extern f32 D_800B23A8_B2FA8;
extern u16 D_800C9520_CA120;
extern s8 D_800CB99C_CC59C;
extern u16 D_800CE214_CEE14;
extern Process* D_800CE298_CEE98;
extern s16 D_800D0A38_D1638;
extern u8 D_800D2008_D2C08;
extern s8 D_800D2132_D2D32;
extern s16 D_800D6ADA_D76DA;

void func_80045350_45F50(void) {
    s32 var_v1;

    if (D_800A6D44_A7944[GwSystem.minigame_index - 1].minigameType == 6) {
        return;
    }
    for (var_v1 = 0; var_v1 < 4; var_v1++) {
        GW_PLAYER* temp_v0 = &GwPlayer[var_v1];

        temp_v0->gameCoin = 0;
        temp_v0->bonusCoin = 0;
    }
}

void func_800453BC_45FBC(void) {
    D_800CE298_CEE98 = omAddPrcObj(func_800453FC_45FFC, 0x3FFF, 0x800, 0);
    omPrcSetStatBit(D_800CE298_CEE98, 0xA0);
}

void func_800453FC_45FFC(void) {
    void* temp_v0_3;
    s16 sp18[4];
    s16 sp20[2];
    s16 var_s7 = 0;
    s16 var_s6;
    s16 var_s0_3;
    s16 var_s1;
    s16 var_s4;
    s16 var_s2;

    HuPrcSleep(2);
    D_800CB99C_CC59C = 1;
    var_s6 = GwSystem.minigame_index - 1;
    sp18[0] = D_800A6D44_A7944[var_s6].unk_06;
    sp18[1] = D_800A6D44_A7944[var_s6].unk_08;
    sp18[2] = D_800A6D44_A7944[var_s6].unk_0A;
    sp18[3] = D_800A6D44_A7944[var_s6].unk_0C;
    for (var_s4 = 0; var_s4 < 4; var_s4++) {
        if (sp18[var_s4] == -1) {
            break;
        }
    }
    var_s1 = (var_s4 >= 2) ? 0x41 : 0x6E;
    if (D_800A6D44_A7944[var_s6].minigameType == 6) {
        var_s1 = 0x8C;
        var_s4 = 0;
    }
    temp_v0_3 = DataRead(0xC008F);
    D_800D0A38_D1638 = func_80055810_56410(temp_v0_3);
    D_800D6ADA_D76DA = HuSprGrpCreate(1, 5);
    DataClose(temp_v0_3);
    func_80055024_55C24(D_800D6ADA_D76DA, 0, D_800D0A38_D1638, 0);
    HuSprAttrSet(D_800D6ADA_D76DA, 0, 0x01001000);
    func_80054904_55504(D_800D6ADA_D76DA, 0, 0xA0, var_s1 - 20);
    HuSprPriSet(D_800D6ADA_D76DA, 0, 1);
    for (var_s2 = 0; var_s2 < ARRAY_COUNT(D_800B2340_B2F40) - 1; var_s2++) {
        D_800B2340_B2F40[var_s2] = func_80045B24_46724(0x3C, var_s1 + var_s2 * 0x41);
    }
    for (var_s2 = 0; var_s2 < ARRAY_COUNT(D_800B2340_B2F40) - 1; var_s2++) {
        func_80045964_46564(D_800B2340_B2F40[var_s2], var_s6);
        if (var_s4 <= var_s2 + var_s7 * 2) {
            func_8005FE90_60A90(D_800B2340_B2F40[var_s2]);
        } else {
            func_8005FFA8_60BA8(D_800B2340_B2F40[var_s2]);
            func_8005B43C_5C03C(D_800B2340_B2F40[var_s2], sp18[var_s2 + var_s7 * 2], -1, -1);
        }
    }
    if (var_s4 < 3) {
        func_80060394_60F94(1, sp20, 0x3919);
        D_800B2344_B2F44 = var_s0_3 = func_8005A968_5B568((0x140 - sp20[0]) / 2, 0xE0 - sp20[1], sp20[0], sp20[1], 0, 0);
        func_8005B43C_5C03C(var_s0_3, 0x3919, -1, -1);
    } else {
        func_80060394_60F94(1, sp20, 0x3918);
        D_800B2344_B2F44 = var_s0_3 = func_8005A968_5B568((0x140 - sp20[0]) / 2, 0xE0 - sp20[1], sp20[0], sp20[1], 0, 0);
        func_8005B43C_5C03C(var_s0_3, 0x3918, -1, -1);
    }
    func_8005C02C_5CC2C(var_s0_3, 0);
    func_8005BDFC_5C9FC(var_s0_3, 0);
    func_8005BE30_5CA30(var_s0_3, 0);
    func_8005BEE0_5CAE0(var_s0_3, 0xD0);
    func_8005FBF8_607F8(var_s0_3, 0xFF, 0xFF, 0xFF);
    HuPrcVSleep();
    HuAudFXPlay(6);
    D_800D2132_D2D32 = 1;
    while (func_80049F98_4AB98() != 0) {
        if (var_s4 >= 3 && (D_800C9520_CA120 & 0x300)) {
            var_s7 ^= 1;
            for (var_s2 = 0; var_s2 < 2; var_s2++) {
                func_80045964_46564(D_800B2340_B2F40[var_s2], var_s6);
                if (var_s4 <= var_s2 + var_s7 * 2) {
                    func_8005FE90_60A90(D_800B2340_B2F40[var_s2]);
                } else {
                    func_8005FFA8_60BA8(D_800B2340_B2F40[var_s2]);
                    func_8005B43C_5C03C(D_800B2340_B2F40[var_s2], sp18[var_s2 + var_s7 * 2], -1, -1);
                }
            }
        }
        HuPrcVSleep();
    }
    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_80045964_46564(s16 arg0, s16 arg1) {
    u8 sp10[4];
    s16 var_a2;
    s16 var_a1;
    s16 var_s0;

    var_a2 = 0;
    for (var_s0 = 0; var_s0 < 4; var_s0++) {
        for (var_a1 = 0; var_a1 < 4; var_a1++) {
            if (var_s0 == GwPlayer[var_a1].group) {
                sp10[var_a2] = var_a1;
                var_a2++;
            }
        }
        if (var_a2 >= 4) {
            break;
        }
    }
    for (var_s0 = 0; var_s0 < 4; var_s0++) {
        func_8005B6BC_5C2BC(arg0, 0x1C00 + GwPlayer[sp10[var_s0]].chr, var_s0);
    }
}

void func_80045A90_46690(void) {
    s16 i;

    HuSprGrpKill(D_800D6ADA_D76DA);
    HuSprKill(D_800D0A38_D1638);
    if (D_800CE214_CEE14 == 0) {
        for (i = 0; i < ARRAY_COUNT(D_800B2340_B2F40); i++) {
            func_8005F364_5FF64(D_800B2340_B2F40[i]);
        }
    }
    omDelPrcObj(D_800CE298_CEE98);
}

s16 func_80045B24_46724(s16 arg0, s16 arg1) {
    TextWindow* temp_v0_2;
    s16 temp_v0;

    temp_v0 = func_8005A968_5B568(arg0, arg1, 0xC8, 0x3C, 0, 0);
    func_8005BE30_5CA30(temp_v0, 0);
    temp_v0_2 = &D_800CC69C_CD29C[temp_v0];
    temp_v0_2->unk_29 = 0;
    temp_v0_2->unk_2A = 1;
    func_8005BDFC_5C9FC(temp_v0, 0);
    func_8005BEE0_5CAE0(temp_v0, 0xD0);
    func_8005FBF8_607F8(temp_v0, 0x30, 0x40, 0x80);
    func_8005C060_5CC60(temp_v0, 2, 0x40, 0xFF, 0xFF);
    return temp_v0;
}

s32 func_80045BF0_467F0(s32 arg0) {
    u32 var_v0;
    u32 var_v1;

    for (var_v1 = 0; var_v1 < 9; var_v1++) {
        if ((arg0 & 0xFF) == D_800A1590_A2190[var_v1]) {
            break;
        }
    }
    if (var_v1 >= 9) {
        var_v1 = -1;
    }
    return var_v1;
}

void func_80045C2C_4682C(void) {
    s32 var_v1;

    D_800B2390_B2F90 = NULL;
    for (var_v1 = 0; var_v1 < 8; var_v1++) {
        D_800B2350_B2F50[var_v1].unk00 = -1;
    }
}

// TODO: type of arg1 assumed. Implies unk06 and unk07.
s16 func_80045C64_46864(u32 arg0, D_800B2350_B2F50_Struct* arg1) {
    s32 temp_v0;
    s32 var_v1;
    s16 var_a2;
    s16 var_a1;
    s32 temp_a0;

    temp_v0 = func_80045BF0_467F0(arg0);
    if (temp_v0 < 0) {
        return -1;
    }
    temp_a0 = (arg0 >> 16) & 0xFF;
    for (var_v1 = 0; var_v1 < 8; var_v1++) {
        if (temp_a0 == D_800A1630_A2230[var_v1]) {
            break;
        }
    }
    if (var_v1 >= 8) {
        return -1;
    }
    temp_a0 = var_v1;
    var_a2 = D_800A159C_A219C[temp_v0];
    var_a1 = D_800A1610_A2210[temp_a0][temp_v0];
    var_v1 = var_a1;
    if (var_v1 == 0xFF) {
        var_a1 = -1;
        var_a2 = -1;
    }
    if (arg1 != NULL) {
        arg1->unk00 = var_a2;
        arg1->unk06 = temp_a0;
        arg1->unk07 = var_a1 + 1;
    }
    return var_a1;
}

// https://decomp.me/scratch/TTLIZ
void func_80045D38_46938(omObjData*);
INCLUDE_ASM("asm/nonmatchings/pause", func_80045D38_46938);

omObjData* func_80045ED0_46AD0(u32 arg0) {
    return func_80045F48_46B48(arg0, -1, -1, -1);
}

omObjData* func_80045EF4_46AF4(u32 arg0, s16 arg1) {
    return func_80045F48_46B48(arg0, arg1, -1, -1);
}

omObjData* func_80045F1C_46B1C(u32 arg0, s16 arg1, s16 arg2) {
    return func_80045F48_46B48(arg0, arg1, -1, arg2);
}

omObjData* func_80045F48_46B48(u32 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_800B2350_B2F50_Struct sp18;
    omObjData* temp_v0_2;

    if (func_80045C64_46864(arg0, &sp18) >= 0) {
        u8 temp_06 = sp18.unk06;

        D_800B2350_B2F50[temp_06].unk00 = sp18.unk00;
        D_800B2350_B2F50[temp_06].unk02 = arg1;
        D_800B2350_B2F50[temp_06].unk04 = arg2;
        D_800B2350_B2F50[temp_06].unk05 = arg3;
        D_800B2350_B2F50[temp_06].unk06 = sp18.unk06;
        D_800B2350_B2F50[temp_06].unk07 = sp18.unk07;
        if (D_800B2390_B2F90 == NULL) {
            D_800B2390_B2F90 = omAddObj(32000, 0, 0, -1, func_80045D38_46938);
            D_800B2390_B2F90->work[0] = 0;
        }
    }
    return D_800B2390_B2F90;
}

void func_80046030_46C30(s16 arg0, s16 arg1) {
    HmfData* temp_s0 = HmfModelData[arg0].hmf;
    HmfModelData_Unk64_Unk60_Unk54_Struct* var_a0;
    Process* temp_v0_4;
    UnkPausePrcData* temp_v0_5;
    s16 temp_v0;
    s16 temp_v1;
    s16 var_a1;

    temp_v0 = func_8002C834_2D434(temp_s0, "aura");
    temp_v1 = temp_s0->unk60[temp_v0].unk22;
    var_a0 = temp_s0->unk60[temp_v0].unk54;
    for (var_a1 = 0; var_a1 < temp_v1; var_a1++, var_a0++) {
        var_a0->unk00 |= 0x80;
    }
    func_8001C448_1D048(arg0);
    func_8001C514_1D114(arg0);
    func_8001C954_1D554(arg0);
    temp_v0_4 = omAddPrcObj(func_800461D8_46DD8, 0x3F00, 0x1000, 0);
    omPrcSetStatBit(temp_v0_4, 0xA0);
    temp_v0_4->user_data = temp_v0_5 = HuMemAllocTag(sizeof(UnkPausePrcData), 31000);
    temp_v0_5->unk00 = arg0;
    temp_v0_5->unk02 = temp_v0;
    temp_v0_5->unk04 = arg1;
    HmfModelData[arg0].unkBC = (void*) temp_v0_4; // TODO: is unkBC just a void* data?
    D_800B23A0_B2FA0 = D_800B23A4_B2FA4 = D_800B23A8_B2FA8 = 1.0f;
}

void func_800461B4_46DB4(s16 arg0) {
    func_80046030_46C30(arg0, 5);
}

// TODO: doesn't work with -Wa,--vr4300mul-off.
void func_800461D8_46DD8(void) {
    s32 var_s1 = 0;
    UnkPausePrcData* temp_s4 = HuPrcCurrentGet()->user_data;
    HmfData* temp_s6 = HmfModelData[temp_s4->unk00].hmf;
    s16 temp_v0_2 = temp_s6->unk60[temp_s4->unk02].unk2A;
    s16 temp_v1_0 = temp_s6->unk60[temp_s4->unk02].unk28;

    while (TRUE) {
        Vtx* var_s0 = &temp_s6->unk44[D_800D2008_D2C08][temp_v1_0];
        s16 var_s2;

        for (var_s2 = 0; var_s2 < temp_v0_2; var_s2++, var_s0++) {
            f32 temp_f12 = var_s0->v.ob[0];
            f32 temp_f0 = var_s0->v.ob[1];
            f32 temp_f2 = var_s0->v.ob[2];
            f32 temp_f0_2 = HuSqrtf(temp_f12 * temp_f12 + temp_f0 * temp_f0 + temp_f2 * temp_f2) + var_s1;
            f32 temp_f32 = (s16) temp_f0_2;
            f32 temp_f6 = ((s16) temp_f0_2 % 30) / 30.0f;
            s16 temp_v0_4 = (s16) (temp_f32 / 30.0f) % 8;
            s32 var_a1 = D_800A1640_A2240[temp_v0_4][0];
            s32 var_a2 = D_800A1640_A2240[temp_v0_4][1];
            s32 var_a3 = D_800A1640_A2240[temp_v0_4][2];
            s16 temp_v1 = (temp_v0_4 + 1) % 8;

            var_s0->v.cn[0] = (s32) ((D_800A1640_A2240[temp_v1][0] * temp_f6 + (1.0f - temp_f6) * var_a1) * D_800B23A0_B2FA0);
            var_s0->v.cn[1] = (s32) ((D_800A1640_A2240[temp_v1][1] * temp_f6 + (1.0f - temp_f6) * var_a2) * D_800B23A4_B2FA4);
            var_s0->v.cn[2] = (s32) ((D_800A1640_A2240[temp_v1][2] * temp_f6 + (1.0f - temp_f6) * var_a3) * D_800B23A8_B2FA8);
        }
        var_s1 += temp_s4->unk04;
        if (var_s1 > 240) {
            var_s1 -= 240;
        } else if (var_s1 < 0) {
            var_s1 += 240;
        }
        HuPrcVSleep();
    }
}

void func_80046558_47158(s16 arg0) {
    Process* temp_s0 = (void*) HmfModelData[arg0].unkBC; // TODO

    HuMemFree(temp_s0->user_data);
    omDelPrcObj(temp_s0);
}

void func_800465A8_471A8(s32 arg0, f32 arg1, f32 arg2, f32 arg3) {
    D_800B23A0_B2FA0 = arg1;
    D_800B23A4_B2FA4 = arg2;
    D_800B23A8_B2FA8 = arg3;
}

const char D_800A7A28_A8628[] = "CAME";
const char D_800A7A30_A8630[] = "STAT";
