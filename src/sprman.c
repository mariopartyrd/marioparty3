#include "game/sprite.h"
#include "include_asm.h"

#define offsetof(st, m) ((u32)&(((st*)0)->m))

void* HuMemAlloc(s32 size);

void func_80052E68_53A68(void* arg0, s32 arg1);

extern s32 D_800A1EA0_A2AA0; // redraw?
extern HuSprite_Unk84_Struct* D_800C9530_CA130[];
extern HuSprGrp* D_800C9934_CA534;
#define HuSprGrpLast D_800C9934_CA534
extern HuSprGrp* D_800CC0A0_CCCA0;
#define HuSprGrpFirst D_800CC0A0_CCCA0
HuSprGrp* HuSprGrpData[HUSPR_GRP_MAX]__attribute__((aligned(16)));
extern u16 HuSprGrpNum;
extern u16 D_800D520C_D5E0C;
#define HuSprGrpNum D_800D520C_D5E0C

INCLUDE_ASM("asm/nonmatchings/sprman", func_80052330_52F30);

HuSprGrp* func_80052468_53068(s16 arg0, u16 arg1) {
    HuSprGrp* temp_v0;

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
    HuSprGrp* temp_v0_2;
    HuSprite** var_s2;
    HuSprite* temp_v0_3;
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

INCLUDE_ASM("asm/nonmatchings/sprman", func_80052DD8_539D8);

void func_80052E14_53A14(HuSprite* arg0) {
    arg0->unk_68 = arg0->unk_84;
    arg0->unk_6C = arg0->unk_88;
    arg0->unk_6E = arg0->unk_0E;
    arg0->unk_72 = arg0->unk_8A;
    arg0->unk_70 = arg0->unk_0C;
    arg0->unk_74 = arg0->unk_8C;
    arg0->unk_78 = arg0->unk_10;
    arg0->unk_7E = arg0->unk_92;
    arg0->unk_7C = arg0->unk_90;
    arg0->unk_80 = 0;
    arg0->unk_7F = 0;
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80052E68_53A68);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800530AC_53CAC);

INCLUDE_ASM("asm/nonmatchings/sprman", func_8005338C_53F8C);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800534C8_540C8);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80053558_54158);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80054170_54D70);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80054218_54E18);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80054658_55258);

//HuSprPosSet?
void func_80054904_55504(s16 group, s16 member, s16 arg2, s16 arg3) {
    HuSprGrp* group_ptr = HuSprGrpData[group];
    HuSprite* sprite_ptr = group_ptr->members[member];

    if ((sprite_ptr->unk_48 != arg2) || (sprite_ptr->unk_4C != arg3)) {
        group_ptr->unk_0C = 1;
        sprite_ptr->unk_48 = arg2;
        sprite_ptr->unk_4C = arg3;
    }
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_800549C0_555C0);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800549F4_555F4);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80054B1C_5571C);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80054EE0_55AE0);

void func_80054FF8_55BF8(s16 group, s16 member, s32 arg2) {
    HuSprGrpData[group]->members[member]->unk_90 = arg2;
}

void func_80055024_55C24(s16 group, s16 member, s16 arg2, s32 arg3) {
    HuSprite* sprite_ptr = HuSprGrpData[group]->members[member];

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
    HuSprite* sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_10 = arg2;
    func_80052E14_53A14(sprite_ptr);
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_800550F4_55CF4);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80055140_55D40);

HuSprite_Unk84_Struct* func_80055194_55D94(s16 arg0) {
    return D_800C9530_CA130[arg0];
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_800551AC_55DAC);

void HuSprScaleSet(s16 group, s16 member, f32 x, f32 y) {
    HuSprGrp* group_ptr = HuSprGrpData[group];
    HuSprite* sprite_ptr = group_ptr->members[member];

    if (sprite_ptr->unk_50 != x || sprite_ptr->unk_54 != y || sprite_ptr->unk_60 != 1.0f || sprite_ptr->unk_64 != 1.0f) {
        group_ptr->unk_0C = 1;
        sprite_ptr->unk_50 = x;
        sprite_ptr->unk_54 = y;
        sprite_ptr->unk_64 = 1.0f;
        sprite_ptr->unk_60 = 1.0f;
    }
}

void HuSprPriSet(s16 group, s16 member, u16 prio) {
    HuSprite* sprite_ptr = HuSprGrpData[group]->members[member];

    if (sprite_ptr->prio != prio) {
        sprite_ptr->prio = prio;
        D_800A1EA0_A2AA0 = 1;
    }
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_800552DC_55EDC);

void HuSprAttrReset(s16 group, s16 member, s32 attr) {
    HuSprite* sprite_ptr = HuSprGrpData[group]->members[member];

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
    HuSprite* sprite_ptr = HuSprGrpData[group]->members[member];

    if (!(sprite_ptr->unk_5C & 0x8000) && (attr & 0x8000)) {
        D_800A1EA0_A2AA0 = 1;
    }
    if (!(sprite_ptr->unk_5C & 0x4000) && (attr & 0x4000)) {
        D_800A1EA0_A2AA0 = 1;
    }
    sprite_ptr->unk_5C |= attr;
    sprite_ptr->unk_24 = sprite_ptr->unk_5C;
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80055420_56020);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80055458_56058);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80055484_56084);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800554C4_560C4);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800554F0_560F0);

HuSprite* HuSprGet(s16 group, s16 member) {
    return HuSprGrpData[group]->members[member];
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80055548_56148);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80055588_56188);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800555B8_561B8);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800555E8_561E8);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80055628_56228);

INCLUDE_ASM("asm/nonmatchings/sprman", HuSprKill);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800557A0_563A0);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80055810_56410);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80055DBC_569BC);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80055FF4_56BF4);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056054_56C54);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800560B8_56CB8);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800560D8_56CD8);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056108_56D08);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056128_56D28);

INCLUDE_ASM("asm/nonmatchings/sprman", func_8005614C_56D4C);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056180_56D80);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800561D0_56DD0);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056230_56E30);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056254_56E54);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056260_56E60);

INCLUDE_ASM("asm/nonmatchings/sprman", func_8005627C_56E7C);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800562BC_56EBC);

INCLUDE_ASM("asm/nonmatchings/sprman", func_8005630C_56F0C);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800563A4_56FA4);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056650_57250);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056758_57358);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056BAC_577AC);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056C28_57828);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056C74_57874);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056C98_57898);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056CD0_578D0);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056D18_57918);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056F80_57B80);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800570A8_57CA8);

INCLUDE_ASM("asm/nonmatchings/sprman", func_8005712C_57D2C);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80057158_57D58);

INCLUDE_ASM("asm/nonmatchings/sprman", func_800571C8_57DC8);
