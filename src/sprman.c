#include "game/sprite.h"
#include "mallocblock.h"
#include "include_asm.h"

#define offsetof(st, m) ((u32) & (((st *)0)->m))

void *HuMemAlloc(s32 size);

void func_80052E68_53A68(void *arg0, s32 arg1);
void func_80056F80_57B80(s16 arg0);

extern s32 D_800A1EA0_A2AA0; // redraw?
extern HuSprAnmDesc *D_800D0A50_D1650[0x100];
extern u16 D_800D554E_D614E;
extern u16 D_800CC3E6_CCFE6;
extern HuSprite_Unk84_Struct *D_800C9530_CA130[];
extern void *D_800CE1B8_CEDB8[3];
extern u8 D_800D2008_D2C08;
extern s32 D_800D1FDC_D2BDC;
extern void *D_800D59F4_D65F4;
extern HuSprGrp *HuSprGrpLast;
extern HuSprGrp *HuSprGrpFirst;
HuSprGrp *HuSprGrpData[HUSPR_GRP_MAX] __attribute__((aligned(16)));
extern u16 HuSprGrpNum;

INCLUDE_ASM("asm/nonmatchings/sprman", func_80052330_52F30);

HuSprGrp *func_80052468_53068(s16 arg0, u16 arg1) {
    HuSprGrp *temp_v0;

    // Allocation assumes 'members' is the last member of HuSprGrp.
    temp_v0 = HuMemAlloc(offsetof(HuSprGrp, members) + arg0 * sizeof(*temp_v0->members));
    if (temp_v0 == NULL) {
        return NULL;
    }
    temp_v0->unk_08 = arg1;
    temp_v0->unk_0A = arg0;
    if (HuSprGrpLast == NULL) {
        HuSprGrpLast = temp_v0;
    }
    temp_v0->next = HuSprGrpFirst;
    if (temp_v0->next != NULL) {
        temp_v0->next->prev = temp_v0;
    }
    temp_v0->prev = NULL;
    HuSprGrpFirst = temp_v0;
    HuSprGrpNum++;
    D_800A1EA0_A2AA0 = 1;
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80052518_53118);

INCLUDE_ASM("asm/nonmatchings/sprman", HuSprGrpKill);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80052700_53300);

s16 HuSprGrpCreate(u16 arg0, u16 arg1) {
    HuSprGrp *temp_v0_2;
    HuSprite **var_s2;
    HuSprite *temp_v0_3;
    s16 var_s4;
    s16 i;

    for (i = 0; i < HUSPR_GRP_MAX; i++) {
        if (HuSprGrpData[i] == NULL) {
            break;
        }
    }
    if (i == HUSPR_GRP_MAX) {
        return -1;
    }
    var_s4 = i;
    temp_v0_2 = func_80052468_53068(arg0, arg1);
    if (temp_v0_2 == NULL) {
        return -1;
    }
    HuSprGrpData[var_s4] = temp_v0_2;
    temp_v0_2->unk_0A = 0;
    temp_v0_2->unk_0C = 1;
    var_s2 = temp_v0_2->members;
    for (i = 0; i < arg0; i++) {
        *(var_s2++) = temp_v0_3 = HuMemAlloc(0x210);
        if (temp_v0_3 == NULL) {
            HuSprGrpKill(var_s4);
            return -1;
        }
        temp_v0_2->unk_0A++;
    }
    func_80052E68_53A68(temp_v0_2, arg0);
    return var_s4;
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_800528EC_534EC);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80052A90_53690);

void func_80052DD8_539D8(HuSprAnm *arg0) {
    arg0->unk00 = NULL;
    arg0->unk04 = 0;
    arg0->unk06 = 0;
    arg0->unk08 = 0;
    arg0->unk0A = 0;
    arg0->unk0C = 0.0f;
    arg0->unk10 = 1.0f;
    arg0->unk14 = 0;
    arg0->unk16 = 0;
    arg0->unk18 = 0;
    arg0->unk17 = 0;
}

void func_80052E14_53A14(HuSprite *arg0) {
    arg0->unk_68.unk00 = arg0->unk_84;
    arg0->unk_68.unk04 = arg0->unk_88;
    arg0->unk_68.unk06 = arg0->unk_0E;
    arg0->unk_68.unk0A = arg0->unk_8A;
    arg0->unk_68.unk08 = arg0->unk_0C;
    arg0->unk_68.unk0C = arg0->unk_8C;
    arg0->unk_68.unk10 = arg0->unk_10;
    arg0->unk_68.unk16 = arg0->unk_92;
    arg0->unk_68.unk14 = arg0->unk_90;
    arg0->unk_68.unk18 = 0;
    arg0->unk_68.unk17 = 0;
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80052E68_53A68);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800530AC_53CAC);

INCLUDE_ASM("asm/nonmatchings/sprman", func_8005338C_53F8C);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800534C8_540C8);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80053558_54158);

void func_80054170_54D70(void) {
    if (D_800CE1B8_CEDB8[D_800D2008_D2C08] != NULL) {
        HuMemFree(D_800CE1B8_CEDB8[D_800D2008_D2C08]);
    }
    if (D_800D1FDC_D2BDC != NULL) {
        D_800CE1B8_CEDB8[D_800D2008_D2C08] = HuMemAlloc(D_800D1FDC_D2BDC);
    } else {
        D_800CE1B8_CEDB8[D_800D2008_D2C08] = NULL;
    }
    D_800D59F4_D65F4 = D_800CE1B8_CEDB8[D_800D2008_D2C08];
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80054218_54E18);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80054658_55258);

// HuSprPosSet?
void func_80054904_55504(s16 group, s16 member, s16 arg2, s16 arg3) {
    HuSprGrp *group_ptr = HuSprGrpData[group];
    HuSprite *sprite_ptr = group_ptr->members[member];

    if ((sprite_ptr->unk_48 != arg2) || (sprite_ptr->unk_4C != arg3)) {
        group_ptr->unk_0C = 1;
        sprite_ptr->unk_48 = arg2;
        sprite_ptr->unk_4C = arg3;
    }
}

void func_800549C0_555C0(s16 group, s16 member, s16 arg2) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_44 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_800549F4_555F4);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80054B1C_5571C);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80054EE0_55AE0);

void func_80054FF8_55BF8(s16 group, s16 member, s32 arg2) {
    HuSprGrpData[group]->members[member]->unk_90 = arg2;
}

void func_80055024_55C24(s16 group, s16 member, s16 arg2, s32 arg3) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_84 = D_800C9530_CA130[arg2];
    if (D_800C9530_CA130[arg2]->unk04 != 0) {
        sprite_ptr->unk_0E = 1;
    }
    sprite_ptr->unk_0C = arg3;
    sprite_ptr->unk_8C = 0.0f;
    sprite_ptr->unk_10 = 1.0f;
    sprite_ptr->unk_8A = 0;
    sprite_ptr->unk_88 = 0;
    sprite_ptr->unk_90 = 0;
    func_80052E14_53A14(sprite_ptr);
}

void func_800550B4_55CB4(s16 group, s16 member, f32 arg2) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_10 = arg2;
    func_80052E14_53A14(sprite_ptr);
}

void func_800550F4_55CF4(s16 group, s16 member, s32 arg2) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_88 &= 0x7F;
    sprite_ptr->unk_0E = arg2;
    func_80052E14_53A14(sprite_ptr);
}

void func_80055140_55D40(s16 group, s16 member, u16 arg2, s32 arg3) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_88 &= 0x7F;
    sprite->unk_0C = arg2;
    sprite->unk_8A = arg3;
    sprite->unk_8C = 0;
    func_80052E14_53A14(sprite);
}

HuSprite_Unk84_Struct *func_80055194_55D94(s16 arg0) {
    return D_800C9530_CA130[arg0];
}

u8 func_800551AC_55DAC(s16 group, s16 member) {
    return HuSprGrpData[group]->members[member]->unk_88;
}

void HuSprScaleSet(s16 group, s16 member, f32 x, f32 y) {
    HuSprGrp *group_ptr = HuSprGrpData[group];
    HuSprite *sprite_ptr = group_ptr->members[member];

    if (sprite_ptr->unk_50 != x || sprite_ptr->unk_54 != y || sprite_ptr->unk_60 != 1.0f || sprite_ptr->unk_64 != 1.0f) {
        group_ptr->unk_0C = 1;
        sprite_ptr->unk_50 = x;
        sprite_ptr->unk_54 = y;
        sprite_ptr->unk_64 = 1.0f;
        sprite_ptr->unk_60 = 1.0f;
    }
}

void HuSprPriSet(s16 group, s16 member, u16 prio) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    if (sprite_ptr->prio != prio) {
        sprite_ptr->prio = prio;
        D_800A1EA0_A2AA0 = 1;
    }
}

void func_800552DC_55EDC(s16 group, s16 member, f32 arg2) {
    HuSprGrp *group_ptr = HuSprGrpData[group];
    HuSprite *sprite_ptr = group_ptr->members[member];

    if (sprite_ptr->unk_58 != arg2) {
        group_ptr->unk_0C = 1;
        sprite_ptr->unk_58 = arg2;
    }
}

void HuSprAttrReset(s16 group, s16 member, s32 attr) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    if ((sprite_ptr->unk_5C & 0x8000) && (attr & 0x8000)) {
        D_800A1EA0_A2AA0 = 1;
    }
    if ((sprite_ptr->unk_5C & 0x4000) && (attr & 0x4000)) {
        D_800A1EA0_A2AA0 = 1;
    }
    sprite_ptr->unk_5C &= ~attr;
    sprite_ptr->unk_24 = sprite_ptr->unk_5C;
}

void HuSprAttrSet(s16 group, s16 member, s32 attr) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    if (!(sprite_ptr->unk_5C & 0x8000) && (attr & 0x8000)) {
        D_800A1EA0_A2AA0 = 1;
    }
    if (!(sprite_ptr->unk_5C & 0x4000) && (attr & 0x4000)) {
        D_800A1EA0_A2AA0 = 1;
    }
    sprite_ptr->unk_5C |= attr;
    sprite_ptr->unk_24 = sprite_ptr->unk_5C;
}

void func_80055420_56020(s16 group, s16 member, u8 r, u8 g, u8 b) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_28[0] = r;
    sprite_ptr->unk_28[1] = g;
    sprite_ptr->unk_28[2] = b;
}

void func_80055458_56058(s16 group, s16 member, u16 arg2) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_2C = arg2;
}

void func_80055484_56084(s16 group, s16 member, u8 arg2, u8 arg3, u8 arg4, u16 arg5) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_28[0] = arg2;
    sprite_ptr->unk_28[1] = arg3;
    sprite_ptr->unk_28[2] = arg4;
    sprite_ptr->unk_2C = arg5;
}

void func_800554C4_560C4(s16 group, s16 member, u16 arg2) {
    HuSprGrpData[group]->members[member]->unk_2E = arg2;
}

void func_800554F0_560F0(s16 group, s16 member, u8 arg2, u8 arg3) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_93 = arg2;
    sprite->unk_94 = arg3;
}

HuSprite *HuSprGet(s16 group, s16 member) {
    return HuSprGrpData[group]->members[member];
}

void func_80055548_56148(s16 group, s16 member, u16 arg2, u16 arg3, u16 arg4, u16 arg5) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_3C = arg2;
    sprite->unk_3E = arg3;
    sprite->unk_40 = arg4;
    sprite->unk_42 = arg5;
}

void func_80055588_56188(s16 group, s16 member, s32 arg2, s32 arg3) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_30 = arg2;
    sprite->unk_34 = arg3;
}

void func_800555B8_561B8(s16 group, s16 member, u16 arg2, u16 arg3) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_38 = arg2;
    sprite->unk_3A = arg3;
}

void func_800555E8_561E8(s16 group, s16 member, u16 arg2, u16 arg3, u16 arg4, u16 arg5) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_204 = arg2;
    sprite->unk_206 = arg3;
    sprite->unk_208 = arg4;
    sprite->unk_20A = arg5;
}

void func_80055628_56228(void) {
    s16 i;

    D_800CC3E6_CCFE6 = 0;
    for (i = 0; i < 0x100; i++) {
        D_800C9530_CA130[i] = NULL;
    }
}

INCLUDE_ASM("asm/nonmatchings/sprman", HuSprKill);

void func_800557A0_563A0(void) {
    s16 i;

    for (i = 0; i < 0x100; i++) {
        if (D_800C9530_CA130[i] != NULL) {
            HuSprKill(i);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80055810_56410);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80055DBC_569BC);

void func_80055FF4_56BF4(HuSprAnm *arg0, s16 arg1, u16 arg2, u16 arg3) {
    func_80052DD8_539D8(arg0);
    arg0->unk06 = arg3;
    arg0->unk08 = arg2;
    arg0->unk00 = func_80055194_55D94(arg1);
}

s16 func_80056054_56C54(void *arg0, HuSprAnm *arg1, u16 arg2, u16 arg3) {
    s16 temp = func_80055810_56410(arg0);

    func_80055FF4_56BF4(arg1, temp, arg2, arg3);
    return temp;
}

HuSprite_Unk84_Unk00_Struct *func_800560B8_56CB8(HuSprite_Unk84_Struct **arg0, u16 arg1) {
    return &(*arg0)->unk00[arg1];
}

HuSprite_Unk84_Unk00_Struct *func_800560D8_56CD8(s16 arg0, u16 arg1) {
    return &D_800C9530_CA130[arg0]->unk00[arg1];
}

HuSprite_Unk84_Unk00_Struct *func_80056108_56D08(HuSprAnm *arg0) {
    return &arg0->unk00->unk00[arg0->unk14];
}

void *func_80056128_56D28(HuSprite_Unk84_Struct **arg0, u16 arg1) {
    HuSprite_Unk84_Unk00_Struct *entry = &(*arg0)->unk00[arg1];

    return entry->unk00;
}

void *func_8005614C_56D4C(s16 arg0, u16 arg1) {
    HuSprite_Unk84_Unk00_Struct *entry = &D_800C9530_CA130[arg0]->unk00[arg1];

    return entry->unk00;
}

void func_80056180_56D80(HuSprite_Unk84_Struct **arg0, u16 arg1, void *arg2) {
    HuSprite_Unk84_Unk00_Struct *entry = &(*arg0)->unk00[arg1];

    func_80019C00_1A800(entry->unk00);
    entry->unk00 = arg2;
}

void func_800561D0_56DD0(s16 arg0, u16 arg1, void *arg2) {
    HuSprite_Unk84_Unk00_Struct *entry = &D_800C9530_CA130[arg0]->unk00[arg1];

    func_80019C00_1A800(entry->unk00);
    entry->unk00 = arg2;
}

void *func_80056230_56E30(HuSprAnm *arg0) {
    HuSprite_Unk84_Unk00_Struct *entry = &arg0->unk00->unk00[arg0->unk14];

    return entry->unk00;
}

void *func_80056254_56E54(HuSprite_Unk84_Struct **arg0) {
    return (*arg0)->unk0C;
}

void *func_80056260_56E60(s16 arg0) {
    return D_800C9530_CA130[arg0]->unk0C;
}

void func_8005627C_56E7C(HuSprite_Unk84_Struct **arg0, void *arg1) {
    func_80019C00_1A800((*arg0)->unk0C);
    (*arg0)->unk0C = arg1;
}

void func_800562BC_56EBC(s16 arg0, void *arg1) {
    func_80019C00_1A800(D_800C9530_CA130[arg0]->unk0C);
    D_800C9530_CA130[arg0]->unk0C = arg1;
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_8005630C_56F0C);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800563A4_56FA4);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056650_57250);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056758_57358);

void func_80056BAC_577AC(void) {
    s16 i;

    func_80052700_53300();
    func_800557A0_563A0();
    func_80057158_57D58();
    for (i = 0; i < 3; i++) {
        if (D_800CE1B8_CEDB8[i] != NULL) {
            HuMemFree(D_800CE1B8_CEDB8[i]);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056C28_57828);

u16 func_80056C74_57874(u8 **arg0) {
    u8 *p = *arg0;
    u16 val = (p[0] << 8) + p[1];

    *arg0 = p + 2;
    return val;
}

u32 func_80056C98_57898(u8 **arg0) {
    u8 *p = *arg0;
    u32 val = (p[0] << 24) + (p[1] << 16) + (p[2] << 8) + p[3];

    *arg0 = p + 4;
    return val;
}

void func_80056CD0_578D0(void) {
    s16 i;

    D_800D554E_D614E = 0;
    for (i = 0; i < 0x100; i++) {
        D_800D0A50_D1650[i] = NULL;
    }
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056D18_57918);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056F80_57B80);

void func_800570A8_57CA8(s16 group, s16 member, s16 arg2) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];
    s32 i;

    sprite->unk_98 = D_800D0A50_D1650[arg2];
    sprite->unk_FC.f = 1.0f;
    for (i = 0; i < 0x10; i++) {
        sprite->unk_9C[i] = 0xFFFF;
        sprite->unk_BC[i] = 0;
    }
    sprite->unk_104 = 0;
}

void func_8005712C_57D2C(s16 group, s16 member, s32 arg2) {
    HuSprGrpData[group]->members[member]->unk_FC.i = arg2;
}

void func_80057158_57D58(void) {
    s16 i;

    for (i = 0; i < 0x100; i++) {
        if (D_800D0A50_D1650[i] != NULL) {
            func_80056F80_57B80(i);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_800571C8_57DC8);
