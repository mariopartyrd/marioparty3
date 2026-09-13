#include "game/sprite.h"
#include "game/hmfman.h"
#include "mallocblock.h"
#include "include_asm.h"

#define offsetof(st, m) ((u32) & (((st *)0)->m))

typedef struct {
    HuSprite *last;
    HuSprite *first;
} HuSprPrioBucket;

void *HuMemAlloc(s32 size);
void *HuMemMemoryReallocPerm(void *mem, u32 new_size);
HuSprite *func_800530AC_main(void);

void func_80052E68_main(HuSprGrp *group, u16 count);
void func_8008A0D0_main(Mtx *);
void func_80052518_main(HuSprite *arg0);
void func_80056F80_main(s16 arg0);
s16 func_8005630C_main(HuSprAnm *arg0);
void func_800563A4_main(HuSprAnm *arg0);
void func_800571C8_main(HuSprAnmDesc **arg0);
void func_80054218_main(Gfx **, s32, s32);
void func_80054658_main(Gfx **, s32, s32);
void func_80055628_main(void);
void func_80056CD0_main(void);
void func_80057158_main(void);

extern s32 D_800A1EA0_main; // redraw?
extern Mtx D_800BD7C0_main;
extern HuSprite *D_800BD804_main; // head of sorted draw list
extern s16 D_800D0468_main;
extern s16 D_800D10F2_main;
extern HuSprAnmDesc *D_800D0A50_main[0x100];
extern u16 D_800D554E_main;
extern u16 D_800CC3E6_main;
extern u16 D_800CB8A0_main;
extern HuSprite_Unk84_Struct *D_800C9530_main[];
extern void *D_800CE1B8_main[3];
extern u8 D_800D2008_main;
extern s32 D_800D1FDC_main;
extern void *D_800D59F4_main;
extern s8 HmfPauseF;
extern HuSprGrp *HuSprGrpLast;
extern HuSprGrp *HuSprGrpFirst;
HuSprGrp *HuSprGrpData[HUSPR_GRP_MAX] __attribute__((aligned(16)));
extern u16 HuSprGrpNum;

void func_80052330_main(void) {
    s16 i;
    void **p;

    HuSprGrpNum = 0;
    for (i = 0; i < HUSPR_GRP_MAX; i++) {
        HuSprGrpData[i] = NULL;
    }
    HuSprGrpFirst = NULL;
    HuSprGrpLast = NULL;
    D_800CB8A0_main = 0;
    D_800CE1B8_main[0] =
        D_800CE1B8_main[1] =
            D_800CE1B8_main[2] =
                D_800D59F4_main = NULL;
    D_800D1FDC_main = NULL;
    guOrtho(&D_800BD7C0_main, -160.0f, 160.0f, -120.0f, 120.0f, 0.0f, 8000.0f, 2.0f);
    D_800D0468_main = func_8001AC8C_main(0, func_80054218_main, 0);
    func_8001C8A8_main(D_800D0468_main, 1);
    D_800D10F2_main = func_8001AC8C_main(0, func_80054658_main, 6);
    func_80055628_main();
    func_80056CD0_main();
    D_800A1EA0_main = 1;
}

HuSprGrp *func_80052468_main(s16 arg0, u16 arg1) {
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
    D_800A1EA0_main = 1;
    return temp_v0;
}

void func_80052518_main(HuSprite *arg0) {
    s16 i;

    for (i = 0; i < 3; i++) {
        if (arg0->unk_128[i] != NULL) {
            func_80019C00_main(arg0->unk_128[i]);
        }
        if (arg0->unk_134[i] != NULL) {
            func_80019C00_main(arg0->unk_134[i]);
        }
        if (arg0->unk_108[i] != NULL) {
            func_80019C00_main(arg0->unk_108[i]);
        }
    }
    func_80019C00_main(arg0);
}

void HuSprGrpKill(s16 arg0) {
    HuSprGrp *group = HuSprGrpData[arg0];
    HuSprGrp *next = group->next;
    HuSprGrp *prev = group->prev;

    if (group->members[0] != NULL) {
        s16 i;
        HuSprite **mp = group->members;

        for (i = 0; i < group->unk_0A; i++) {
            func_80052518_main(*mp++);
        }
    }
    if (next != NULL) {
        next->prev = prev;
    }
    if (prev != NULL) {
        prev->next = next;
    }
    if (HuSprGrpLast == group) {
        HuSprGrpLast = prev;
        if (prev != NULL) {
            prev->next = NULL;
        }
    }
    if (HuSprGrpFirst == group) {
        HuSprGrpFirst = next;
        if (next != NULL) {
            next->prev = NULL;
        }
    }
    HuMemFree(group);
    HuSprGrpData[arg0] = NULL;
    HuSprGrpNum--;
    D_800A1EA0_main = 1;
}

void func_80052700_main(void) {
    s16 i;

    HuSprGrpNum = 0;
    for (i = 0; i < HUSPR_GRP_MAX; i++) {
        if (HuSprGrpData[i] != NULL) {
            HuSprGrpKill(i);
        }
    }
    HuSprGrpFirst = NULL;
    HuSprGrpLast = NULL;
    D_800CB8A0_main = 0;
    D_800A1EA0_main = 1;
}

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
    temp_v0_2 = func_80052468_main(arg0, arg1);
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
    func_80052E68_main(temp_v0_2, arg0);
    return var_s4;
}

s32 func_800528EC_main(s16 group, s16 member, u16 count) {
    HuSprGrp *groupPtr = HuSprGrpData[group];
    HuSprite **mp = &groupPtr->members[member];
    HuSprite *sprite;
    s16 i;

    for (i = 0; i < count; i++) {
        func_80052518_main(*mp++);
    }
    groupPtr->unk_0A -= count;
    if (groupPtr->unk_0A == 0) {
        groupPtr->members[0] = NULL;
        HuSprGrpKill(group);
        return 0;
    }
    HuMemMemoryReallocPerm(groupPtr, offsetof(HuSprGrp, members) + groupPtr->unk_0A * sizeof(*groupPtr->members));
    mp = &groupPtr->members[member];
    for (i = 0; i < groupPtr->unk_0A - member; i++) {
        *mp = mp[count];
        mp++;
    }
    for (i = 0; i < groupPtr->unk_0A; i++) {
        sprite = groupPtr->members[i];
        sprite->unk_00 = i;
        sprite->unk_02 = groupPtr->unk_0A;
    }
    return 0;
}

s32 func_80052A90_main(s16 group, s16 member, u16 count) {
    HuSprGrp *oldGroup = HuSprGrpData[group];
    HuSprGrp *newGroup;
    HuSprite **mp;
    HuSprite *sprite;
    s16 newSlot;
    s16 i;

    for (i = 0; i < HUSPR_GRP_MAX; i++) {
        if (HuSprGrpData[i] == NULL) {
            break;
        }
    }
    if (i == HUSPR_GRP_MAX) {
        return -1;
    }
    newSlot = i;
    newGroup = func_80052468_main(count + oldGroup->unk_0A, oldGroup->unk_08);
    if (newGroup == NULL) {
        return -1;
    }
    HuSprGrpData[newSlot] = newGroup;
    newGroup->unk_0A = 0;
    newGroup->unk_0C = 1;
    mp = newGroup->members;
    for (i = 0; i < count; i++) {
        *(mp++) = sprite = HuMemAlloc(0x210);
        if (sprite == NULL) {
            HuSprGrpKill(newSlot);
            return -1;
        }
        newGroup->unk_0A++;
    }
    func_80052E68_main(newGroup, count);
    newGroup->members[0]->unk_2E = 0;
    if (member >= 0) {
        mp = newGroup->members + count - 1;
        for (i = 0; i < count; i++) {
            mp[member + 1] = *mp;
            mp--;
        }
        mp = newGroup->members;
        for (i = 0; i < member + 1; i++) {
            *(mp++) = oldGroup->members[i];
        }
    }
    mp = &newGroup->members[member] + count + 1;
    for (i = 0; i < oldGroup->unk_0A - (member + 1); i++) {
        *(mp++) = (oldGroup->members + member)[i + 1];
    }
    newGroup->unk_0A = count + oldGroup->unk_0A;
    for (i = 0; i < newGroup->unk_0A; i++) {
        HuSprite *member_sprite = newGroup->members[i];

        member_sprite->unk_00 = i;
        member_sprite->unk_02 = newGroup->unk_0A;
    }
    oldGroup->members[0] = NULL;
    HuSprGrpKill(group);
    HuSprGrpData[group] = newGroup;
    HuSprGrpData[newSlot] = NULL;
    return 0;
}

void func_80052DD8_main(HuSprAnm *arg0) {
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

void func_80052E14_main(HuSprite *arg0) {
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

void func_80052E68_main(HuSprGrp *group, u16 count) {
    HuSprite *sprite;
    s16 i;
    s16 j;

    for (i = 0; i < count; i++) {
        sprite = group->members[i];
        sprite->unk_04 = 0;
        sprite->unk_08 = 0;
        sprite->unk_18 = sprite->unk_1C = 1.0f;
        sprite->prio = 0x8000;
        sprite->unk_20 = 0;
        sprite->unk_24 = 0;
        sprite->unk_28[0] = sprite->unk_28[1] = sprite->unk_28[2] = 0;
        sprite->unk_2C = 0x100;
        if (i != 0) {
            sprite->unk_2E = 0;
        } else {
            sprite->unk_2E = -1;
        }
        sprite->unk_30.f = sprite->unk_34.f = 1.0f;
        sprite->unk_38 = sprite->unk_3A = 0;
        sprite->unk_3C = sprite->unk_3E = sprite->unk_40 = sprite->unk_42 = 0;
        sprite->unk_44 = 0;
        sprite->unk_116 = sprite->unk_114 = -1;
        sprite->unk_48 = 0.0f;
        sprite->unk_4C = 0.0f;
        sprite->unk_50 = sprite->unk_54 = 1.0f;
        sprite->unk_58 = 0.0f;
        sprite->unk_5C = 0;
        sprite->unk_60 = sprite->unk_64 = 1.0f;
        func_80052DD8_main(&sprite->unk_68);
        sprite->unk_84 = sprite->unk_68.unk00;
        sprite->unk_88 = sprite->unk_68.unk04;
        sprite->unk_0E = (u16)sprite->unk_68.unk06;
        sprite->unk_0C = (u16)sprite->unk_68.unk08;
        sprite->unk_8C = sprite->unk_68.unk0C;
        sprite->unk_10 = sprite->unk_68.unk10;
        sprite->unk_90 = (u16)sprite->unk_68.unk14;
        sprite->unk_92 = sprite->unk_68.unk16;
        sprite->unk_93 = sprite->unk_68.unk17;
        sprite->unk_94 = sprite->unk_68.unk18;
        sprite->unk_98 = NULL;
        sprite->unk_FC.f = 1.0f;
        for (j = 0; j < 0x10; j++) {
            sprite->unk_9C[j] = 0xFFFF;
            sprite->unk_BC[j] = 0;
        }
        sprite->unk_100 = 0;
        sprite->unk_104 = 0;
        sprite->unk_108[0] = sprite->unk_108[1] = sprite->unk_108[2] = NULL;
        sprite->unk_00 = i;
        sprite->unk_02 = count;
        sprite->unk_118 = sprite->unk_11C = NULL;
        sprite->unk_128[0] = sprite->unk_128[1] = sprite->unk_128[2] = NULL;
        sprite->unk_134[0] = sprite->unk_134[1] = sprite->unk_134[2] = NULL;
        func_8008A0D0_main(&sprite->unk_140[0]);
        func_8008A0D0_main(&sprite->unk_140[1]);
        func_8008A0D0_main(&sprite->unk_140[2]);
        sprite->unk_120 = NULL;
        sprite->unk_124 = NULL;
        sprite->unk_204 = sprite->unk_206 = 0;
        sprite->unk_208 = 0x140;
        sprite->unk_20A = 0xF0;
    }
}

// rebuild sprite draw list (highest priority first)
HuSprite *func_800530AC_main(void) {
    HuSprPrioBucket buckets[0x100];
    HuSprGrp *group;
    HuSprite *sprite;
    HuSprite *last;
    s32 i;
    s32 j;
    s32 bucket;
    s32 minBucket = -1;
    s32 maxBucket = 0;
    HuSprite *node = NULL;

    if (D_800A1EA0_main == 0) {
        return D_800BD804_main;
    }
    D_800A1EA0_main = 0;
    D_800CB8A0_main = 0;
    group = HuSprGrpLast;
    bzero(buckets, sizeof(buckets));
    while (group != NULL) {
        for (i = 0; i < group->unk_0A; i++) {
            sprite = group->members[i];
            sprite->unk_11C = NULL;
            sprite->unk_118 = NULL;
        }
        group = group->prev;
    }
    for (group = HuSprGrpLast; group != NULL; group = group->prev) {
        for (i = 0; i < group->unk_0A; i++) {
            sprite = group->members[i];
            if (sprite->unk_24 & 0x8000) {
                continue;
            }
            bucket = sprite->prio >> 8;
            if (minBucket < 0) {
                maxBucket = bucket;
                minBucket = maxBucket;
                buckets[maxBucket].first = sprite;
                buckets[maxBucket].last = sprite;
            } else {
                if (maxBucket < bucket) {
                    node = buckets[maxBucket].first;
                } else {
                    for (j = bucket; j < maxBucket + 1; j++) {
                        node = buckets[j].first;
                        if (node != NULL && sprite->prio <= node->prio) {
                            last = buckets[j].last;
                            if (last != NULL && sprite->prio <= last->prio) {
                                node = last;
                            }
                            break;
                        }
                    }
                    if (j == maxBucket + 1) {
                        node = buckets[maxBucket].first;
                    }
                }
                while (node != NULL) {
                    if (sprite->prio > node->prio) {
                        break;
                    }
                    node = node->unk_118;
                }
                if (node != NULL) {
                    sprite->unk_118 = node;
                    sprite->unk_11C = node->unk_11C;
                    if (node->unk_11C != NULL) {
                        node->unk_11C->unk_118 = sprite;
                    }
                    node->unk_11C = sprite;
                } else {
                    sprite->unk_118 = NULL;
                    sprite->unk_11C = buckets[minBucket].last;
                    buckets[minBucket].last->unk_118 = sprite;
                }
                if (buckets[bucket].last == NULL || sprite->prio <= buckets[bucket].last->prio) {
                    buckets[bucket].last = sprite;
                }
                if (buckets[bucket].first == NULL || sprite->prio > buckets[bucket].first->prio) {
                    buckets[bucket].first = sprite;
                }
                if (bucket < minBucket) {
                    minBucket = bucket;
                }
                if (maxBucket < bucket) {
                    maxBucket = bucket;
                }
            }
            D_800CB8A0_main++;
        }
    }
    D_800BD804_main = buckets[maxBucket].first;
    return buckets[maxBucket].first;
}

s16 func_8005338C_main(HuSprGrp *arg0) {
    HuSprite *sprite;
    s16 result = 0;
    s16 i;
    s16 j;

    for (j = 0; j < arg0->unk_0A; j++) {
        sprite = arg0->members[j];
        sprite->unk_116 = -1;
        sprite->unk_114 = -1;
    }
    for (i = 0; i < arg0->unk_0A; i++) {
        sprite = arg0->members[i];

        if (sprite->unk_2E >= 0) {
            HuSprite *parent = arg0->members[sprite->unk_2E];

            if (parent->unk_116 < 0) {
                parent->unk_116 = i;
            } else {
                for (j = 0; j < i; j++) {
                    HuSprite *other = arg0->members[j];

                    if (j != i && sprite->unk_2E == other->unk_2E && other->unk_114 < 0) {
                        other->unk_114 = i;
                        break;
                    }
                }
            }
        } else {
            result = i;
        }
    }
    return result;
}

void func_800534C8_main(f32 a0[][2], f32 a1[][2], f32 a2[][2]) {
    s16 i;

    for (i = 0; i < 3; i++) {
        a2[i][0] = a0[i][0] * a1[0][0] + a0[i][1] * a1[1][0];
        a2[i][1] = a0[i][0] * a1[0][1] + a0[i][1] * a1[1][1];
    }
    a2[2][0] += a1[2][0];
    a2[2][1] += a1[2][1];
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80053558_main);

void func_80054170_main(void) {
    if (D_800CE1B8_main[D_800D2008_main] != NULL) {
        HuMemFree(D_800CE1B8_main[D_800D2008_main]);
    }
    if (D_800D1FDC_main != NULL) {
        D_800CE1B8_main[D_800D2008_main] = HuMemAlloc(D_800D1FDC_main);
    } else {
        D_800CE1B8_main[D_800D2008_main] = NULL;
    }
    D_800D59F4_main = D_800CE1B8_main[D_800D2008_main];
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80054218_main);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80054658_main);

// HuSprPosSet?
void func_80054904_main(s16 group, s16 member, s16 arg2, s16 arg3) {
    HuSprGrp *group_ptr = HuSprGrpData[group];
    HuSprite *sprite_ptr = group_ptr->members[member];

    if ((sprite_ptr->unk_48 != arg2) || (sprite_ptr->unk_4C != arg3)) {
        group_ptr->unk_0C = 1;
        sprite_ptr->unk_48 = arg2;
        sprite_ptr->unk_4C = arg3;
    }
}

void func_800549C0_main(s16 group, s16 member, s16 arg2) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_44 = arg2;
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_800549F4_main);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80054B1C_main);

INCLUDE_ASM("asm/nonmatchings/sprman", func_80054EE0_main);

void func_80054FF8_main(s16 group, s16 member, s32 arg2) {
    HuSprGrpData[group]->members[member]->unk_90 = arg2;
}

void func_80055024_main(s16 group, s16 member, s16 arg2, u16 arg3) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_84 = D_800C9530_main[arg2];
    if (D_800C9530_main[arg2]->unk04 != 0) {
        sprite_ptr->unk_0E = 1;
    }
    sprite_ptr->unk_0C = arg3;
    sprite_ptr->unk_8C = 0.0f;
    sprite_ptr->unk_10 = 1.0f;
    sprite_ptr->unk_8A = 0;
    sprite_ptr->unk_88 = 0;
    sprite_ptr->unk_90 = 0;
    func_80052E14_main(sprite_ptr);
}

void func_800550B4_main(s16 group, s16 member, f32 arg2) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_10 = arg2;
    func_80052E14_main(sprite_ptr);
}

void func_800550F4_main(s16 group, s16 member, s32 arg2) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_88 &= 0x7F;
    sprite_ptr->unk_0E = arg2;
    func_80052E14_main(sprite_ptr);
}

void func_80055140_main(s16 group, s16 member, u16 arg2, s32 arg3) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_88 &= 0x7F;
    sprite->unk_0C = arg2;
    sprite->unk_8A = arg3;
    sprite->unk_8C = 0;
    func_80052E14_main(sprite);
}

HuSprite_Unk84_Struct *func_80055194_main(s16 arg0) {
    return D_800C9530_main[arg0];
}

u8 func_800551AC_main(s16 group, s16 member) {
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
        D_800A1EA0_main = 1;
    }
}

void func_800552DC_main(s16 group, s16 member, f32 arg2) {
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
        D_800A1EA0_main = 1;
    }
    if ((sprite_ptr->unk_5C & 0x4000) && (attr & 0x4000)) {
        D_800A1EA0_main = 1;
    }
    sprite_ptr->unk_5C &= ~attr;
    sprite_ptr->unk_24 = sprite_ptr->unk_5C;
}

void HuSprAttrSet(s16 group, s16 member, s32 attr) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    if (!(sprite_ptr->unk_5C & 0x8000) && (attr & 0x8000)) {
        D_800A1EA0_main = 1;
    }
    if (!(sprite_ptr->unk_5C & 0x4000) && (attr & 0x4000)) {
        D_800A1EA0_main = 1;
    }
    sprite_ptr->unk_5C |= attr;
    sprite_ptr->unk_24 = sprite_ptr->unk_5C;
}

void func_80055420_main(s16 group, s16 member, u8 r, u8 g, u8 b) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_28[0] = r;
    sprite_ptr->unk_28[1] = g;
    sprite_ptr->unk_28[2] = b;
}

void func_80055458_main(s16 group, s16 member, u16 arg2) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_2C = arg2;
}

void func_80055484_main(s16 group, s16 member, u8 arg2, u8 arg3, u8 arg4, u16 arg5) {
    HuSprite *sprite_ptr = HuSprGrpData[group]->members[member];

    sprite_ptr->unk_28[0] = arg2;
    sprite_ptr->unk_28[1] = arg3;
    sprite_ptr->unk_28[2] = arg4;
    sprite_ptr->unk_2C = arg5;
}

void func_800554C4_main(s16 group, s16 member, s16 arg2) {
    HuSprGrpData[group]->members[member]->unk_2E = arg2;
}

void func_800554F0_main(s16 group, s16 member, u8 arg2, u8 arg3) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_93 = arg2;
    sprite->unk_94 = arg3;
}

HuSprite *HuSprGet(s16 group, s16 member) {
    return HuSprGrpData[group]->members[member];
}

void func_80055548_main(s16 group, s16 member, u16 arg2, u16 arg3, u16 arg4, u16 arg5) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_3C = arg2;
    sprite->unk_3E = arg3;
    sprite->unk_40 = arg4;
    sprite->unk_42 = arg5;
}

void func_80055588_main(s16 group, s16 member, s32 arg2, s32 arg3) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_30.i = arg2;
    sprite->unk_34.i = arg3;
}

void func_800555B8_main(s16 group, s16 member, u16 arg2, u16 arg3) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_38 = arg2;
    sprite->unk_3A = arg3;
}

void func_800555E8_main(s16 group, s16 member, u16 arg2, u16 arg3, u16 arg4, u16 arg5) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];

    sprite->unk_204 = arg2;
    sprite->unk_206 = arg3;
    sprite->unk_208 = arg4;
    sprite->unk_20A = arg5;
}

void func_80055628_main(void) {
    s16 i;

    D_800CC3E6_main = 0;
    for (i = 0; i < 0x100; i++) {
        D_800C9530_main[i] = NULL;
    }
}

void HuSprKill(s16 arg0) {
    HuSprite_Unk84_Struct *desc = D_800C9530_main[arg0];
    s16 i;

    if (desc->unk04 != NULL) {
        HuSprCelAnm *cel = *desc->unk04;
        if (cel != NULL) {
            for (i = 0; i < desc->unk12; i++) {
                HuMemFree(cel->unk04);
                cel++;
            }
        }
        HuMemFree(*desc->unk04);
        HuMemFree(desc->unk04);
    }
    func_80019C00_main(desc->unk0C);
    {
        HuSprite_Unk84_Unk00_Struct *cel = desc->unk00;
        for (i = 0; i < desc->unk10; i++) {
            func_80019C00_main(cel->unk00);
            cel++;
        }
    }
    HuMemFree(desc->unk00);
    HuMemFree(desc);
    D_800C9530_main[arg0] = NULL;
    D_800CC3E6_main--;
}

void func_800557A0_main(void) {
    s16 i;

    for (i = 0; i < 0x100; i++) {
        if (D_800C9530_main[i] != NULL) {
            HuSprKill(i);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80055810_main);

s32 func_80055DBC_main(u16 arg0, u16 arg1, u16 arg2, u16 arg3, u16 arg4) {
    HuSprite_Unk84_Struct *desc;
    HuSprite_Unk84_Unk00_Struct *cel;
    s16 i;
    s16 slot;

    for (i = 0; i < 0x100 && D_800C9530_main[i] != NULL; i++) {
    }
    if (i == 0x100) {
        return -1;
    }
    slot = i;
    desc = HuMemAlloc(0x1C);
    if (desc == NULL) {
        return -1;
    }
    desc->unk10 = arg4;
    desc->unk12 = 0;
    desc->unk14 = arg0;
    desc->unk16 = arg1 * arg4;
    desc->unk18 = arg2;
    desc->unk1A = arg3;
    desc->unk00 = NULL;
    desc->unk04 = 0;
    desc->unk08 = NULL;
    desc->unk0C = NULL;
    D_800C9530_main[slot] = desc;
    D_800CC3E6_main++;
    cel = HuMemAlloc(desc->unk10 * 0xC);
    if (cel != NULL) {
        desc->unk00 = cel;
    } else {
        HuSprKill(slot);
        return -1;
    }
    for (i = 0; i < desc->unk10; i++) {
        s32 size;

        cel->unk04 = arg0;
        cel->unk06 = arg1;
        cel->unk08 = arg0 >> 1;
        cel->unk0A = arg1 >> 1;
        size = cel->unk04 * cel->unk06 * (desc->unk18 & 0x7FFF);
        cel->unk00 = HuMemAlloc(size / 8);
        if (cel->unk00 == NULL) {
            desc->unk10 = i;
            HuSprKill(slot);
            return -1;
        }
        if (i == 0) {
            desc->unk08 = cel->unk00;
        }
        cel++;
    }
    if (desc->unk1A != 0) {
        void *pal = HuMemAlloc(desc->unk1A * 2);

        if (pal != NULL) {
            desc->unk0C = pal;
        } else {
            HuSprKill(slot);
            return -1;
        }
    }
    return slot;
}

void func_80055FF4_main(HuSprAnm *arg0, s16 arg1, u16 arg2, u16 arg3) {
    func_80052DD8_main(arg0);
    arg0->unk06 = arg3;
    arg0->unk08 = arg2;
    arg0->unk00 = func_80055194_main(arg1);
}

s16 func_80056054_main(void *arg0, HuSprAnm *arg1, u16 arg2, u16 arg3) {
    s16 temp = func_80055810_main(arg0);

    func_80055FF4_main(arg1, temp, arg2, arg3);
    return temp;
}

HuSprite_Unk84_Unk00_Struct *func_800560B8_main(HuSprite_Unk84_Struct **arg0, u16 arg1) {
    return &(*arg0)->unk00[arg1];
}

HuSprite_Unk84_Unk00_Struct *func_800560D8_main(s16 arg0, u16 arg1) {
    return &D_800C9530_main[arg0]->unk00[arg1];
}

HuSprite_Unk84_Unk00_Struct *func_80056108_main(HuSprAnm *arg0) {
    return &arg0->unk00->unk00[arg0->unk14];
}

void *func_80056128_main(HuSprite_Unk84_Struct **arg0, u16 arg1) {
    HuSprite_Unk84_Unk00_Struct *entry = &(*arg0)->unk00[arg1];

    return entry->unk00;
}

void *func_8005614C_main(s16 arg0, u16 arg1) {
    HuSprite_Unk84_Unk00_Struct *entry = &D_800C9530_main[arg0]->unk00[arg1];

    return entry->unk00;
}

void func_80056180_main(HuSprite_Unk84_Struct **arg0, u16 arg1, void *arg2) {
    HuSprite_Unk84_Unk00_Struct *entry = &(*arg0)->unk00[arg1];

    func_80019C00_main(entry->unk00);
    entry->unk00 = arg2;
}

void func_800561D0_main(s16 arg0, u16 arg1, void *arg2) {
    HuSprite_Unk84_Unk00_Struct *entry = &D_800C9530_main[arg0]->unk00[arg1];

    func_80019C00_main(entry->unk00);
    entry->unk00 = arg2;
}

void *func_80056230_main(HuSprAnm *arg0) {
    HuSprite_Unk84_Unk00_Struct *entry = &arg0->unk00->unk00[arg0->unk14];

    return entry->unk00;
}

void *func_80056254_main(HuSprite_Unk84_Struct **arg0) {
    return (*arg0)->unk0C;
}

void *func_80056260_main(s16 arg0) {
    return D_800C9530_main[arg0]->unk0C;
}

void func_8005627C_main(HuSprite_Unk84_Struct **arg0, void *arg1) {
    func_80019C00_main((*arg0)->unk0C);
    (*arg0)->unk0C = arg1;
}

void func_800562BC_main(s16 arg0, void *arg1) {
    func_80019C00_main(D_800C9530_main[arg0]->unk0C);
    D_800C9530_main[arg0]->unk0C = arg1;
}

s16 func_8005630C_main(HuSprAnm *arg0) {
    HuSprite_Unk84_Struct *desc = arg0->unk00;

    if (desc == NULL) {
        return -1;
    }
    if (arg0->unk06 == 1) {
        HuSprCelAnm *cel;
        HuSprCelFrame *frame;

        if (desc->unk04 == NULL) {
            return 0;
        }
        cel = &(*desc->unk04)[arg0->unk08];
        frame = &cel->unk04[arg0->unk0A];
        arg0->unk14 = frame->unk00;
        arg0->unk17 = frame->unk04;
        arg0->unk18 = frame->unk05;
        arg0->unk16 = frame->unk06;
    } else if (arg0->unk06 >= 2) {
        if (arg0->unk06 < 4) {
            arg0->unk14 = arg0->unk0A;
        }
    }
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_800563A4_main);

void func_80056650_main(HuSprite *sprite) {
    HuSprAnm *anm = &sprite->unk_68;

    func_80052E14_main(sprite);
    if (!(sprite->unk_68.unk04 & 0x80)) {
        if (func_8005630C_main(anm) == 0) {
            sprite->unk_68.unk04 |= 0x80;
        }
    } else {
        if (HmfPauseF == 0 || (sprite->unk_24 & 0x1000000)) {
            func_800563A4_main(anm);
        }
    }
    sprite->unk_88 = anm->unk04;
    sprite->unk_0E = (u16)anm->unk06;
    sprite->unk_90 = (u16)anm->unk14;
    sprite->unk_93 = anm->unk17;
    sprite->unk_94 = anm->unk18;
    sprite->unk_92 = anm->unk16;
    sprite->unk_8A = (u16)anm->unk0A;
    sprite->unk_8C = anm->unk0C;
    sprite->unk_10 = anm->unk10;
    sprite->unk_18 = sprite->unk_50 * sprite->unk_60;
    sprite->unk_1C = sprite->unk_54 * sprite->unk_64;
    if (sprite->unk_98 != NULL) {
        func_800571C8_main(&sprite->unk_98);
    }
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056758_main);

void func_80056BAC_main(void) {
    s16 i;

    func_80052700_main();
    func_800557A0_main();
    func_80057158_main();
    for (i = 0; i < 3; i++) {
        if (D_800CE1B8_main[i] != NULL) {
            HuMemFree(D_800CE1B8_main[i]);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056C28_main);

u16 func_80056C74_main(u8 **arg0) {
    u8 *p = *arg0;
    u16 val = (p[0] << 8) + p[1];

    *arg0 = p + 2;
    return val;
}

u32 func_80056C98_main(u8 **arg0) {
    u8 *p = *arg0;
    u32 val = (p[0] << 24) + (p[1] << 16) + (p[2] << 8) + p[3];

    *arg0 = p + 4;
    return val;
}

void func_80056CD0_main(void) {
    s16 i;

    D_800D554E_main = 0;
    for (i = 0; i < 0x100; i++) {
        D_800D0A50_main[i] = NULL;
    }
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_80056D18_main);

void func_80056F80_main(s16 arg0) {
    HuSprAnmDesc *desc = D_800D0A50_main[arg0];
    s32 i;

    for (i = 0; i < desc->unk02; i++) {
        HuSprAnmEntry *group = desc->unk04[i];

        if (group->unk00 != 0) {
            s32 j;

            for (j = 0; j < group->unk02; j++) {
                HuSprAnmEntry *cel = group->unk04[j];

                HuMemFree(cel->unk04);
                HuMemFree(cel);
            }
            HuMemFree(group->unk04);
        }
        HuMemFree(group);
    }
    HuMemFree(desc->unk04);
    HuMemFree(desc->unk0C);
    HuMemFree(desc);
    D_800D0A50_main[arg0] = NULL;
    D_800D554E_main--;
}

void func_800570A8_main(s16 group, s16 member, s16 arg2) {
    HuSprite *sprite = HuSprGrpData[group]->members[member];
    s32 i;

    sprite->unk_98 = D_800D0A50_main[arg2];
    sprite->unk_FC.f = 1.0f;
    for (i = 0; i < 0x10; i++) {
        sprite->unk_9C[i] = 0xFFFF;
        sprite->unk_BC[i] = 0;
    }
    sprite->unk_104 = 0;
}

void func_8005712C_main(s16 group, s16 member, s32 arg2) {
    HuSprGrpData[group]->members[member]->unk_FC.i = arg2;
}

void func_80057158_main(void) {
    s16 i;

    for (i = 0; i < 0x100; i++) {
        if (D_800D0A50_main[i] != NULL) {
            func_80056F80_main(i);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/sprman", func_800571C8_main);
