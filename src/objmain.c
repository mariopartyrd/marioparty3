#include "common.h"
#include "game/object.h"
#include "game/pause.h"
#include "malloc.h"
#include "mallocblock.h"

typedef struct unkProcessStruct {
    u16 stat;
    s16 unk2;
    Process *processInstance;
    void (*destructor)();
} unkProcessStruct;

extern s16 D_800A1774_main;
extern s16 D_800A1776_main;
extern s16 D_800A1778_main;
extern unkProcessStruct *D_800A177C_main;
extern s16 D_800A1780_main;
extern s8 D_800D1710_main;

void omDestroyPrcObj(void);
void func_8000BA00_main(void);
void func_8000BBFC_main(s32, s16);
void func_800166D0_main(void);
void func_8001AFE4_main(void);
void func_80021AF4_main(void);
void omInsertObj(omObjData *obj);
void omAddMember(u16 group, omObjData *obj);
void func_8004A354_main(omObjData *);
void func_8004A444_main(s32);
void func_8004A468_main(u16, u16, u16);
void func_8004CEA4_main();
void func_80047D4C_main(omObjData *obj);
extern u8 D_800A16B0_main[][2];
extern u8 D_800A1740_main[][2];
extern u16 D_800A1756_main;
extern s32 omprevovl;
extern u16 omovlstat;
extern u8 D_800A176C_main;
extern omObjData *omobjall;
extern s8 D_800A1784_main;
extern s16 D_800A18A8_main[][2];
extern u8 D_800A18B7_main[];
extern s16 D_800A1908_main;
extern s16 D_800A190C_main;
extern u16 D_800B23C2_main;
extern u16 D_800B23C4_main;
extern s16 D_800B23C6_main;
extern s16 D_800B23C8_main;
extern u16 D_800D1100_main;

typedef struct UnkomOvl {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    char unk_06[2]; // unused pad?
} UnkomOvl;

typedef struct {
    u16 next_idx;
    u16 max_objs;
    u16 num_objs;
    u16 *next;
    omObjData **objs;
} omObjGroup;

extern UnkomOvl D_800A1920_main[];

extern f32 D_800CB890_main;
extern s16 omobjlast;
extern s16 ommaxobjs;
extern u8 D_800CCF52_main;
extern s16 omnumobjs;
extern f32 D_800CCF98_main[];
extern omObjGroup omgroup[];
extern u16 D_800CD2F4_main;
extern s32 omovl;
extern u16 D_800CE202_main;
extern u16 D_800D0A3A_main;
extern omObjData *D_800D2118_main;
extern u16 D_800D4082_main;
extern f32 D_800D4198_main[];
extern f32 D_800D5210_main;
extern u16 D_800D530C_main;
extern s16 omobjfirst;
extern s32 D_800D6A40_main;
extern u16 D_800D6A56_main;
extern u8 D_800D6A90_main;
extern s16 omnextidx;

extern u8 D_800A1762_main;
extern u16 D_800B23C0_main;
extern u16 D_800CD050_main;

typedef struct OverlayInfo {
    u8 *rom_start;
    u8 *rom_end;
    u8 *ram_start;
    u8 *code_start;
    u8 *code_end;
    u8 *data_start;
    u8 *data_end;
    u8 *bss_start;
    u8 *bss_end;
} OverlayInfo; // sizeof 0x24

void omInitObjMan(s16 numOfObjs, s32 numOfPrcs) {
    s16 prcCount;
    s32 i;
    omObjData *obj;
    unkProcessStruct *prcInfo;

    ommaxobjs = numOfObjs + 1;
    omnumobjs = 0;
    omnextidx = 0;
    omobjlast = -1;
    omobjfirst = -1;
    D_800D2118_main = NULL;
    D_800D530C_main = 0;
    D_800D6A90_main = 0;

    if (omobjall != NULL) {
        HuMemMemoryFreeTemp((void *)omobjall);
    }

    omobjall = (omObjData *)HuMemMemoryAllocTemp(ommaxobjs * sizeof(omObjData));

    for (i = 0; i < ommaxobjs; ++i) {
        obj = &omobjall[i];
        obj->stat = 1;
        obj->next = -1;
        obj->prev = -1;
        obj->prio = -1;
        obj->unk10 = 0;
        obj->rot.x =
            obj->rot.y =
                obj->rot.z = 0.0f;
        obj->trans.x =
            obj->trans.y =
                obj->trans.z = 0.0f;
        obj->scale.x =
            obj->scale.y =
                obj->scale.z = 1.0f;
        obj->motion = NULL;
        obj->model = NULL;
        obj->data = NULL;
        obj->func = NULL;
        obj->next_idx = i + 1;
        obj->mtncnt = 0;
        obj->motion = NULL;
    }

    for (i = 0; i < 10; ++i) {
        omgroup[i].max_objs = 0;
        omgroup[i].num_objs = 0;
        omgroup[i].next_idx = 0;
        omgroup[i].objs = NULL;
        omgroup[i].next = 0;
    }

    prcCount = numOfPrcs + 2;
    D_800A1774_main = prcCount;
    D_800A1776_main = 0;
    D_800A1778_main = 0;
    D_800A177C_main = (unkProcessStruct *)HuMemMemoryAllocTemp(prcCount * sizeof(unkProcessStruct));

    for (i = 0; i < D_800A1774_main; ++i) {
        prcInfo = &D_800A177C_main[i];
        prcInfo->stat = 1;
        prcInfo->unk2 = i + 1;
        prcInfo->processInstance = NULL;
        prcInfo->destructor = NULL;
    }

    D_800D5210_main = 20000.0f;
    D_800CB890_main = 10000.0f;

    for (i = 0; i < 4; ++i) {
        D_800CCF98_main[i] = 20000.0f;
        D_800D4198_main[i] = 10000.0f;
    }

    D_800D6A40_main = 0;
    D_800CD050_main = 0x5A;
}

void omDestroyObjMan(void) {
    omObjData *obj;
    omObjGroup *group;
    unkProcessStruct *prcInfo;
    s32 i;

    omobjlast = -1;

    for (i = 0; i < ommaxobjs; i++) {
        obj = &omobjall[i];
        if (obj->stat == 1) {
            continue;
        }
        if (obj->model != NULL) {
            HuMemMemoryFreeTemp(obj->model);
        }
        if (obj->motion != NULL) {
            HuMemMemoryFreeTemp(obj->motion);
        }
        if (obj->data != NULL) {
            HuMemFree(obj->data);
        }
    }

    HuMemMemoryFreeTemp(omobjall);
    omobjall = NULL;
    ommaxobjs = 0;

    for (i = 0; i < 10; i++) {
        if (omgroup[i].max_objs != 0) {
            if (omgroup[i].objs != NULL) {
                HuMemMemoryFreeTemp(omgroup[i].objs);
                omgroup[i].objs = NULL;
            }
            if (omgroup[i].next != NULL) {
                HuMemMemoryFreeTemp(omgroup[i].next);
                omgroup[i].next = NULL;
            }
            omgroup[i].max_objs = 0;
        }
    }

    for (i = 0; i < D_800A1774_main; i++) {
        prcInfo = &D_800A177C_main[i];
        if (prcInfo->stat != 1) {
            HuPrcDtor(prcInfo->processInstance, prcInfo->destructor);
            HuPrcKill(prcInfo->processInstance);
        }
    }

    D_800A1774_main = 0;
    D_800A1776_main = 0;
    HuMemMemoryFreeTemp(D_800A177C_main);
    D_800A177C_main = NULL;
    HuMemFreeAllWithTag(0x7918);
    D_800D6A40_main = 0;
}

omObjData *omAddObj(s16 prio, u16 mdlcnt, u16 mtncnt, s16 group, omObjFunc func) {
    omObjData *object;
    s32 i;

    if (omnumobjs == ommaxobjs) {
        return NULL;
    }

    object = &omobjall[omnextidx];
    object->next_idx_alloc = omnextidx;
    object->prio = prio;

    omInsertObj(object);

    if (mdlcnt != 0) {
        object->model = HuMemMemoryAllocTemp(mdlcnt * sizeof(s16));
        object->mdlcnt = mdlcnt;
        for (i = 0; i < mdlcnt; ++i) {
            object->model[i] = -1;
        }
    } else {
        object->model = NULL;
        object->mdlcnt = 0;
    }

    if (mtncnt != 0) {
        object->motion = HuMemMemoryAllocTemp(mtncnt * sizeof(s16));
        object->mtncnt = mtncnt;
    } else {
        object->motion = NULL;
        object->mtncnt = 0;
    }

    if (group >= 0) {
        omAddMember(group, object);
    } else {
        object->group = group;
        object->group_idx = 0;
    }

    object->stat = 4;
    object->unk10 = 0;
    object->func = func;
    object->work[0] = object->work[1] = object->work[2] = object->work[3] = 0;
    omnextidx = object->next_idx;
    ++omnumobjs;

    return object;
}

void omSetObjPrio(omObjData *obj, s16 prio) {
    obj->prio = prio;

    if (omobjlast != omobjfirst) {
        if (obj->next >= 0) {
            omobjall[obj->next].prev = obj->prev;
        }
        if (obj->prev >= 0) {
            omobjall[obj->prev].next = obj->next;
        }

        if (obj->prev < 0) {
            omobjfirst = omobjall[obj->next].next_idx_alloc;
        }
        if (obj->next < 0) {
            omobjlast = omobjall[obj->prev].next_idx_alloc;
        }

        omInsertObj(obj);
    }
}

// register object into linked list, sort based on priority
void omInsertObj(omObjData *obj) {
    s16 next_idx_alloc;
    s16 prio;
    s16 obj_idx;
    omObjData *obj_new;
    s16 prev_idx;

    next_idx_alloc = obj->next_idx_alloc;
    prio = obj->prio;

    if (omobjfirst == -1) {
        obj->prev = -1;
        obj->next = -1;
        omobjfirst = next_idx_alloc;
        omobjlast = next_idx_alloc;
        return;
    }
    for (obj_idx = omobjfirst; obj_idx != -1; obj_idx = obj_new->next) {
        obj_new = &omobjall[obj_idx];
        if (obj_new->prio <= prio) {
            break;
        }
        prev_idx = obj_idx;
    }
    if (obj_idx != -1) {
        obj->prev = obj_new->prev;
        obj->next = obj_idx;
        if (obj_new->prev != -1) {
            omobjall[obj_new->prev].next = next_idx_alloc;
        } else {
            omobjfirst = next_idx_alloc;
        }
        obj_new->prev = next_idx_alloc;
    } else {
        obj->next = -1;
        obj->prev = prev_idx;
        obj_new->next = next_idx_alloc;
        omobjlast = next_idx_alloc;
    }
}

void omDelObj(omObjData *obj) {
    u16 idx = obj->next_idx_alloc;

    if (omnumobjs != 0 && obj->stat != 1) {
        omnumobjs--;

        if (obj->group >= 0) {
            func_80047D4C_main(obj);
        }

        if (obj->motion != NULL) {
            HuMemMemoryFreeTemp(obj->motion);
            obj->motion = NULL;
        }

        if (obj->model != NULL) {
            HuMemMemoryFreeTemp(obj->model);
            obj->model = NULL;
        }

        if (obj->data != NULL) {
            HuMemFree(obj->data);
            obj->data = NULL;
        }

        obj->stat = 1;

        if (obj->next >= 0) {
            omobjall[obj->next].prev = obj->prev;
        }

        if (obj->prev < 0 || (omobjall[obj->prev].next = obj->next, obj->prev < 0)) {
            omobjfirst = omobjall[obj->next].next_idx_alloc;
        }

        if (obj->next < 0) {
            omobjlast = omobjall[obj->prev].next_idx_alloc;
        }

        obj->next_idx = omnextidx;
        omnextidx = idx;
    }
}

void omSetStat(omObjData *obj, u16 stat) {
    obj->stat = stat;
}

void omSetStatBit(omObjData *obj, u16 stat) {
    obj->stat |= stat;
}

void omResetStatBit(omObjData *obj, u16 stat) {
    obj->stat &= ~stat;
}

void omPrcSetStat(Process *prc, s32 stat) {
    D_800A177C_main[prc->dtor_idx].stat = stat;
}

void omPrcSetStatBit(Process *prc, s32 stat) {
    D_800A177C_main[prc->dtor_idx].stat |= stat;
}

void omPrcResetStatBit(Process *prc, s32 stat) {
    D_800A177C_main[prc->dtor_idx].stat &= ~stat;
}

void omSetTra(omObjData *obj, f32 x, f32 y, f32 z) {
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
}

void omSetRot(omObjData *obj, f32 x, f32 y, f32 z) {
    obj->rot.x = x;
    obj->rot.y = y;
    obj->rot.z = z;
}

void omSetSca(omObjData *obj, f32 x, f32 y, f32 z) {
    obj->scale.x = x;
    obj->scale.y = y;
    obj->scale.z = z;
}

void func_80047C0C_main(u16 group, u16 max_objs) {
    omObjGroup *grp = &omgroup[group];
    s32 i;

    if (grp->objs != NULL) {
        HuMemMemoryFreeTemp(grp->objs);
    }
    if (grp->next != NULL) {
        HuMemMemoryFreeTemp(grp->next);
    }

    grp->next_idx = 0;
    grp->max_objs = max_objs;
    grp->num_objs = 0;
    grp->objs = HuMemMemoryAllocTemp(max_objs * sizeof(omObjData *));
    grp->next = HuMemMemoryAllocTemp(max_objs * sizeof(u16));

    for (i = 0; i < max_objs; i++) {
        grp->objs[i] = NULL;
        grp->next[i] = i + 1;
    }
}

void omAddMember(u16 group, omObjData *obj) {
    omObjGroup *group_ptr = &omgroup[group];

    if (group_ptr->num_objs != group_ptr->max_objs) {
        obj->group = group;
        obj->group_idx = group_ptr->next_idx;
        group_ptr->objs[group_ptr->next_idx] = obj;
        group_ptr->next_idx = group_ptr->next[group_ptr->next_idx];
        ++group_ptr->num_objs;
    }
}

void func_80047D4C_main(omObjData *obj) {
    omObjGroup *grp;

    if (obj->group != -1) {
        grp = &omgroup[obj->group];
        grp->objs[obj->group_idx] = NULL;
        grp->next[obj->group_idx] = grp->next_idx;
        grp->next_idx = obj->group_idx;
        obj->group = -1;
        grp->num_objs--;
    }
}

omObjData **func_80047DBC_main(s16 arg0) {
    return omgroup[arg0].objs;
}

omObjData *func_80047DD4_main(s16 arg0, u16 arg1) {
    return omgroup[arg0].objs[arg1];
}

void func_80047DFC_main(s16 group, u32 stat) {
    omObjGroup *grp = &omgroup[group];
    s32 i;

    for (i = 0; i < grp->max_objs; i++) {
        if (grp->objs[i] != NULL) {
            grp->objs[i]->unk10 |= stat;
        }
    }
}

void func_80047E5C_main(s16 group, u16 idx, s32 flags) {
    omgroup[group].objs[idx]->unk10 |= flags;
}

void func_80047E90_main(omObjData *obj, s32 arg1) {
    obj->unk10 |= arg1;
}

Process *omAddPrcObj(process_func func, u16 priority, s32 stackSize, s32 extDataSize) {
    s16 prevIdx;
    Process *newPrc;
    unkProcessStruct *temp_s0;

    if (D_800A1776_main == D_800A1774_main) {
        return NULL;
    }

    prevIdx = D_800A1778_main;
    temp_s0 = &D_800A177C_main[D_800A1778_main];
    temp_s0->stat = 4;
    D_800A1778_main = temp_s0->unk2;

    newPrc = HuPrcCreate(func, priority, stackSize, extDataSize);

    temp_s0->processInstance = newPrc;
    newPrc->dtor_idx = prevIdx;
    HuPrcDtor(temp_s0->processInstance, omDestroyPrcObj);

    temp_s0->destructor = NULL;
    ++D_800A1776_main;

    return temp_s0->processInstance;
}

Process *func_80047F50_main(process_func func, s32 priority, s32 stack_size, s32 extra_data_size, Process *parent) {
    unkProcessStruct *prcInfo;
    Process *process;
    s16 prevIdx;

    if (D_800A1776_main == D_800A1774_main) {
        return NULL;
    }

    prevIdx = D_800A1778_main;
    prcInfo = &D_800A177C_main[D_800A1778_main];
    prcInfo->stat = 4;
    D_800A1778_main = prcInfo->unk2;
    process = HuPrcCreateChild(func, priority, stack_size, extra_data_size, parent);
    prcInfo->processInstance = process;
    process->dtor_idx = prevIdx;
    HuPrcDtor(prcInfo->processInstance, omDestroyPrcObj);
    prcInfo->destructor = NULL;
    D_800A1776_main++;
    return prcInfo->processInstance;
}

s32 omDelPrcObj(Process *arg0) {
    if (arg0 != NULL) {
        return HuPrcKill(arg0);
    } else if (HuPrcKill(HuPrcCurrentGet()) == 0) {
        HuPrcVSleep();
    }
    return -1;
}

void omDestroyPrcObj(void) {
    Process *currPrc;
    unkProcessStruct *temp_s0;

    currPrc = HuPrcCurrentGet();
    temp_s0 = &D_800A177C_main[currPrc->dtor_idx];
    if (temp_s0->destructor != NULL) {
        temp_s0->destructor();
    }
    temp_s0->stat = 1;
    temp_s0->unk2 = D_800A1778_main;
    D_800A1778_main = currPrc->dtor_idx;
    --D_800A1776_main;
}

void omPrcSetDestructor(s32 arg0, void *arg1) {
    unkProcessStruct *unk = &D_800A177C_main[HuPrcCurrentGet()->dtor_idx];
    unk->destructor = arg1;
}

s32 omOvlCallEx(s32 ovlID, s16 event, u16 stat) {
    omOvlHisData *history;

    // history is full, cannot call overlay
    if (omovlhisidx >= ARRAY_COUNT(omovlhis)) {
        return FALSE;
    }

    history = &omovlhis[++omovlhisidx];
    history->overlayID = ovlID;
    history->event = event;
    history->stat = stat;
    omOvlGotoEx(ovlID, event, stat);
    return TRUE;
}

s32 omOvlReturnEx(s16 level) {
    omovlhisidx -= level;

    if (omovlhisidx < 0) {
        omovlhisidx = 0;
        omOvlGotoEx(omovlhis[0].overlayID, omovlhis[0].event, omovlhis[0].stat);
        return 0;
    }
    omOvlGotoEx(omovlhis[omovlhisidx].overlayID, omovlhis[omovlhisidx].event, omovlhis[omovlhisidx].stat);
    return 1;
}

void omOvlGotoEx(s32 ovlID, s16 event, u16 stat) {
    u8 var_a0_2;
    u8 var_v1;

    if (omovl != selmenu && omovl != selmenu2) {
        omprevovl = omovl;
        D_800A1756_main = D_800CE202_main;
    }

    D_800A176C_main = 1;
    omovl = ovlID;
    omovlevtno = event;
    omovlstat = stat;
    D_800D0A3A_main = 0;

    if (stat & 0x40 && D_800CCF52_main != 2) {
        func_8004A444_main(2);
    } else if (stat & 0x80 && (D_800CCF52_main != 3)) {
        func_8004A444_main(3);
    }

    if ((D_800D4082_main != D_800A1920_main[ovlID].unk_00) || (D_800CD2F4_main != D_800A1920_main[ovlID].unk_02) || (D_800D6A56_main != D_800A1920_main[ovlID].unk_04)) {
        func_8004A468_main(D_800A1920_main[ovlID].unk_00, D_800A1920_main[ovlID].unk_02, D_800A1920_main[ovlID].unk_04);
    }

    if (!(stat & 0x2000)) {
        if (stat & 2) {
            var_a0_2 = D_800A1740_main[GwSystem.current_board_index][0];
            var_v1 = D_800A1740_main[GwSystem.current_board_index][1];
        } else if (stat & 4) {
            var_a0_2 = D_800A16B0_main[GwSystem.minigame_index - 1][0];
            var_v1 = D_800A16B0_main[GwSystem.minigame_index - 1][1];
        } else {
            var_a0_2 = 1;
            var_v1 = 20;
        }

        if (stat & 0x100) {
            var_a0_2 = 1;
            var_v1 = 20;
        } else if (stat & 0x200) {
            var_a0_2 = 2;
            var_v1 = 20;
        } else if (stat & 0x400) {
            var_a0_2 = 3;
            var_v1 = 20;
        } else if (stat & 0x800) {
            var_a0_2 = 4;
            var_v1 = 20;
        } else if (stat & 0x1000) {
            var_a0_2 = 5;
            var_v1 = 20;
        }

        D_800A1784_main = var_v1;
        D_800A1908_main = var_a0_2;
    }
    D_800A190C_main = 0;
}

void omOvlHisChg(s16 level, s32 overlay, s16 event, s16 stat) {
    s32 ovlhisIndex = omovlhisidx - level;
    omOvlHisData *history;

    if (ovlhisIndex >= 0) {
        history = &omovlhis[ovlhisIndex];
        history->overlayID = overlay;
        history->event = event;
        history->stat = stat;
    }
}

void omOvlKill(void) {
    D_800A1762_main = 4;
    D_800B23C0_main = D_800CD050_main;
    GMesClose();
    func_8001AFE4_main();
    func_80021AF4_main();
    omDestroyObjMan();
    func_8000BA00_main();
    func_800166D0_main();
    D_800CD280_main = 1;
}

extern s32 fontcolor;
extern u16 omdispinfo;
extern s32 omovl;
extern u16 D_800A1906_main;
extern s16 D_800A1786_main;
extern u8 D_800A1783_main;
extern u8 D_800D1FA0_main;
extern void *D_800A1240_main[3];
extern u8 D_800A1782_main;
extern u8 D_800A1848_main;
extern u8 D_800A1849_main;
extern u8 D_800B23CA_main;
extern u16 D_800A190A_main;
extern u16 D_800A190E_main;
extern f32 D_800D5410_main;
extern f32 D_800D51FC_main;
extern u8 D_800A176D_main;
extern s32 D_800CC370_main;
extern omObjData *D_800D054C_main;
extern s16 D_800CE190_main;
extern void (*D_800CC3B8_main)(omObjData *);
void func_8004A950_main(void);
void func_8001BF14_main(void);

extern u8 D_800A1762_main;
extern u8 D_800A176C_main;
extern u16 D_800D0A3A_main;

u16 func_8004B2C0_main(void);
void func_8000F024_main(void *, u8, s32);
void ResetVibrator(s16);
s32 func_80000F08_main(s32);
s32 func_8004DE24_main(s32, s32, s32, s32, s32);
void func_8004B1AC_main(void);
void func_8004AE28_main(void);
void func_8004AD70_main(void);
s32 func_80000DF0_main(void);
void func_8004B2C8_main(void);
void func_8000B7A0_main(void);
void func_8001766C_main(void);
void func_8004A49C_main(void);
void OvlLoad(s32 overlayIndex);
void HmfLightInit(void);
void HmfLightStatSet(s16 arg0, u8 arg1, u8 arg2);
void func_8001F6B0_main(s32);
void func_80045C2C_main(void);
void func_8004AB7C_main(s32);
void func_8004ADDC_main(s32);
void func_80007D2C_main(s32, s32);
void func_8004AA04_main(s32);
void func_801059A0(void);
void func_8004D6E8_main(s16);

void omMain(void) {
    omObjData *obj;
    void (*func)(omObjData *);
    s16 temp_s3;
    s16 var_v1;
    s16 *model;
    s16 model_id;
    s32 i;
    s32 var_s0;
    s32 var_a0;
    s16 var_s1;
    u32 permSize;
    u32 permUsed;
    u32 tempSize;
    u8 temp_v0;
    u8 temp_v0_2;

    fontcolor = 0xE;
    permSize = HuMemHeapAllocPermSizeGet();
    permUsed = HuMemUsedMemoryBlockGetPerm();
    if (omdispinfo != 0) {
        sprintf(D_800D5218_main, "%8lX(%ld)", permSize, permUsed);
        print8(0x10, 0x18, D_800D5218_main);
        tempSize = HuMemHeapAllocTempSizeGet();
        sprintf(D_800D5218_main, "%8lX(%ld)", tempSize, HuMemUsedMemoryBlockGetTemp());
        print8(0x10, 0x20, D_800D5218_main);
        sprintf(D_800D5218_main, "OVL:%d(%ld<%ld)", omovlhisidx, omovl, (s32)(s16)D_800A1756_main);
        print8(0x18, 0x28, D_800D5218_main);
        sprintf(D_800D5218_main, "OBJ:%d/%d", omnumobjs, ommaxobjs);
        print8(0x18, 0x30, D_800D5218_main);
        sprintf(D_800D5218_main, "PRC:%d/%d", D_800A1776_main, D_800A1774_main);
        print8(0x18, 0x38, D_800D5218_main);
        sprintf(D_800D5218_main, "%02X", D_800A1906_main);
        print8(0x70, 0x38, D_800D5218_main);
        i = func_80000F08_main(6);
        sprintf(D_800D5218_main, "C:%04X D:%02X", i, func_80000F08_main(5));
        print8(0x28, 0x40, D_800D5218_main);
        if (D_800A1786_main == -1) {
            D_800A1786_main = func_8004DE24_main(0xE, 0x16, 0x82, 0x4A, 0xFF70);
        }
    }
    func_8004B1AC_main();
    func_8004AE28_main();
    if (D_800A176C_main != 0) {
        if (D_800A1906_main & 8) {
            D_800A1783_main = 1;
            if (!(D_800A1906_main & 1) && (D_800B23C0_main != 0)) {
                D_800B23C0_main--;
                if (D_800A1762_main != 0) {
                    D_800A1762_main--;
                }
                return;
            }
            func_8004A950_main();
        }
        if (D_800A1762_main == 0) {
            if (D_800D1FA0_main != 1) {
                if (D_800A1780_main == 1) {
                    if (D_800D0A3A_main == 4) {
                        func_8001BF14_main();
                    }
                    if (D_800D0A3A_main != 0) {
                        D_800D0A3A_main--;
                        return;
                    }
                    D_800CCF52_main = D_800D1710_main;
                    func_8000F024_main(D_800A1240_main, D_800D1710_main, 2);
                    func_8001A070_main(HuMemMemoryAllocPerm, HuMemMemoryFreePerm, D_800D4082_main, D_800CD2F4_main, (u16)(s32)D_800D6A56_main, (u8)(s32)(u8)D_800D1710_main);
                    func_800224BC_main();
                    func_8001BF90_main(0x02000000, 0x3D0800);
                    Hu3DCamInit(1);
                }
                D_800A1780_main = 0;
                if (D_800A1782_main == 0) {
                    if (D_800A1848_main != 0) {
                        if (!(--D_800A1848_main & 0xFF)) {
                            D_800A1849_main = 1;
                        }
                        return;
                    } else {
                        D_800B23CA_main = 0;
                        if ((func_8004B2C0_main()) == 1) {
                            func_8004A950_main();
                            func_800035E8_main(0);
                            func_800035E8_main(1);
                            func_8004AD70_main();
                            if (D_800A1849_main == 0) {
                                D_800A1848_main = 5;
                                return;
                            } else if (D_800A1849_main != 1) {
                                return;
                            } else if (func_80000DF0_main() != 0) {
                                return;
                            }
                            D_800B23CA_main = 1;
                            D_800A1782_main = 1;
                            return;
                        }
                    }
                } else {
                    if (!(--D_800B23CA_main)) {
                        func_8004B2C8_main();
                        D_800A190A_main = D_800A1908_main;
                        D_800A190E_main = D_800A190C_main;
                        D_800A1782_main = 0;
                        D_800A1849_main = 0;
                    } else {
                        return;
                    }
                }
            }
            HuMemHeapInitTemp((void *)0x80128000, 0x18000);
            for (i = 0; i < 4; i++) {
                if (CheckControllerRead(i) != 0) {
                    ResetVibrator(i);
                }
            }
            D_800D6A58_main = 0;
            func_8000B7A0_main();
            func_8001766C_main();
            D_800A176C_main = 0;
            func_8004A49C_main();
            OvlLoad(omovl);
            HmfLightInit();
            D_800D5410_main = 1.0f;
            D_800D51FC_main = 1.0f;
            HmfLightMaxSet(3);
            HmfLightColorSet(0, 0x40, 0x40, 0x40);
            HmfLightColorSet(1, 0x40, 0x40, 0x60);
            HmfLightDirSet(1, 0.0f, 0.0f, 100.0f);
            HmfLightColorSet(2, 0, 0, 0);
            HmfLightDirSet(2, 100.0f, 100.0f, 100.0f);
            HmfLightColorSet(3, 0, 0, 0);
            HmfLightDirSet(3, 100.0f, 100.0f, 100.0f);
            HmfLightStatSet(0, 0, 0);
            HmfLightStatSet(1, 0, 0);
            HmfLightStatSet(2, 0, 0);
            HmfLightStatSet(3, 0, 0);
            func_8001F38C_main(0, 0, 0);
            D_800CD280_main = 1;
            func_8001F6B0_main(1);
            func_80045C2C_main();
            if (D_800A176D_main == 0) {
                func_8004AD70_main();
                if (D_800A1783_main == 1) {
                    func_8004AB7C_main(0x7F);
                }
                func_8004ADDC_main(0x40);
                func_80007D2C_main(-1, D_800A1784_main);
            }
            if (D_800A1783_main == 1) {
                func_8004AA04_main(0x7F);
            }
            D_800A1783_main = 0;
            D_800D1FA0_main = 0;
            D_800D1100_main = 0;
            func_801059A0();
            for (i = 0; i < 4; i++) {
                if (CheckControllerRead(i) != 0) {
                    D_800D5558_main[i] = 0;
                }
            }
            if (D_800A176C_main != 0) {
                omOvlKill();
                D_800A1762_main = 0;
                return;
            }
        } else {
            D_800A1762_main--;
            return;
        }
    }
    temp_s3 = func_8004D6AC_main(0, 0, 0xFF);
    D_800CC370_main = 0;
    D_800D054C_main = NULL;
    for (var_s1 = omobjlast; var_s1 != -1;) {
        obj = &omobjall[var_s1];
        D_800CE190_main = 0;
        D_800CC370_main++;
        D_800D054C_main = obj;
        var_s1 = obj->prev;
        if (!(obj->stat & 3)) {
            D_800CC3B8_main = obj->func;
            func = obj->func;
            if (func != NULL && !(obj->stat & (0x40 | 0x10 | 0x08))) {
                func(obj);
            }
            D_800CE190_main = 1;
            if (omobjlast != -1 && D_800A176C_main == 0) {
                if (!(obj->stat & 3)) {
                    if (omobjall[var_s1].stat & 3) {
                        var_s1 = obj->prev;
                    }
                    model = obj->model;
                    if (model != NULL) {
                        model_id = *model;
                        if (model_id != -1 && !(obj->stat & 0x100)) {
                            Hu3DModelPosSet(model_id, obj->trans.x, obj->trans.y, obj->trans.z);
                            Hu3DModelRotSet(*obj->model, obj->rot.x, obj->rot.y, obj->rot.z);
                            Hu3DModelScaleSet(*obj->model, obj->scale.x, obj->scale.y, obj->scale.z);
                        }
                    }
                    D_800CE190_main = 2;
                }
            } else {
                break;
            }
        }
    }
    D_800CE190_main = 4;
    func_8004D6E8_main(temp_s3);
    D_800CE190_main = 5;
    if (D_800A176C_main != 0) {
        D_800CE190_main = 6;
        omOvlKill();
        D_800CE190_main = 7;
    }
    D_800CE190_main = 8;
}

void func_80048E88_main(void);
char const D_800A7AE4_main[] = " SE STP";
char const D_800A7AEC_main[] = " MUSSTP";
char const D_800A7AF4_main[] = " INFO  ";
char const D_800A7AFC_main[] = " LIGHT ";
char const D_800A7B04_main[] = " RESET ";
char const D_800A7B0C_main[] = " CANCEL";

void func_800499B0_main(omObjData *);

void func_80048E88_main(void) {
    omObjData *temp_v0;

    temp_v0 = omAddObj(0x7FD9, 0, 0, -1, func_800499B0_main);
    D_800D2118_main = temp_v0;
    omSetStatBit(temp_v0, 0xA0);
    temp_v0->work[0] = 0;
    temp_v0->work[1] = 0;
    temp_v0->work[2] = 0;
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_80048EE8_main);

INCLUDE_ASM("asm/nonmatchings/objmain", func_800499B0_main);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80049F98_main);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80049FB8_main);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A0E0_main);

void func_8004A208_main(void) {
    func_80045350_main();
    if (omovlstat & 0x10) {
        func_80048E88_main();
        if (omovlstat & 4) {
            D_800D6A58_main = 1;
        }
    }
    if (omovlstat & 0x20) {
        func_8004CEA4_main();
    }
    func_8004CF30_main();
    if (_CheckFlag(0xF) != 0) {
        D_800B23C2_main = func_8000B838_main(0x94);
        D_800B23C4_main = InitEspriteSlot(D_800B23C2_main, 0, 1);
        func_8000BBFC_main(D_800B23C4_main, 0x100);
        func_8000BCC8_main(D_800B23C4_main, 1);
        D_800B23C8_main = D_800A18B7_main[GwSystem.minigame_index];
        func_8000BBD4_main(D_800B23C4_main, D_800A18A8_main[D_800B23C8_main][0], D_800A18A8_main[D_800B23C8_main][1]);
        D_800B23C6_main = 0;
        omSetStatBit(omAddObj(10, 0, 0, -1, func_8004A354_main), 0xA0);
    }
}

void func_8004A354_main(omObjData *arg0) {
    D_800B23C6_main += 10;
    if (D_800B23C6_main > 180) {
        D_800B23C6_main -= 180;
    }
    func_8000BBFC_main(D_800B23C4_main, HuMathSin(D_800B23C6_main) * 255.0f);
    func_8000BBD4_main(D_800B23C4_main, D_800A18A8_main[D_800B23C8_main][0], D_800A18A8_main[D_800B23C8_main][1]);
    if (D_800D1100_main == 1) {
        func_8000BB54_main(D_800B23C4_main);
    } else {
        func_8000BB94_main(D_800B23C4_main);
    }
}

void func_8004A444_main(s32 arg0) {
    D_800A1780_main = 1;
    D_800D0A3A_main = 4;
    D_800D1710_main = arg0;
}

void func_8004A468_main(u16 arg0, u16 arg1, u16 arg2) {
    D_800D4082_main = arg0;
    D_800CD2F4_main = arg1;
    D_800D6A56_main = arg2;
    D_800A1780_main = 1;
    D_800D0A3A_main = 4;
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A49C_main);
