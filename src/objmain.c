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

extern s16 D_800A1774_A2374;
extern s16 D_800A1776_A2376;
extern s16 D_800A1778_A2378;
extern unkProcessStruct *D_800A177C_A237C;
extern s16 D_800A1780_A2380;
extern s8 D_800D1710_D2310;

void omDestroyPrcObj(void);
void func_8000BA00_C600(void);
void func_8000BBFC_C7FC(s32, s16);
void func_800166D0_172D0(void);
void func_8001AFE4_1BBE4(void);
void func_80021AF4_226F4(void);
void omInsertObj(omObjData *obj);
void omAddMember(u16 group, omObjData *obj);
void func_8004A354_4AF54(omObjData *);
void func_8004A444_4B044(s32);
void func_8004A468_4B068(u16, u16, u16);
void func_8004CEA4_4DAA4();
void func_80047D4C_4894C(omObjData *obj);
extern u8 D_800A16B0_A22B0[][2];
extern u8 D_800A1740_A2340[][2];
extern u16 D_800A1756_A2356;
extern s32 omprevovl;
extern u16 omovlstat;
extern u8 D_800A176C_A236C;
extern omObjData *omobjall;
extern s8 D_800A1784_A2384;
extern s16 D_800A18A8_A24A8[][2];
extern u8 D_800A18B7_A24B7[];
extern s16 D_800A1908_A2508;
extern s16 D_800A190C_A250C;
extern u16 D_800B23C2_B2FC2;
extern u16 D_800B23C4_B2FC4;
extern s16 D_800B23C6_B2FC6;
extern s16 D_800B23C8_B2FC8;
extern u16 D_800D1100_D1D00;

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

extern UnkomOvl D_800A1920_A2520[];

extern f32 D_800CB890_CC490;
extern s16 omobjlast;
extern s16 ommaxobjs;
extern u8 D_800CCF52_CDB52;
extern s16 omnumobjs;
extern f32 D_800CCF98_CDB98[];
extern omObjGroup omgroup[];
extern u16 D_800CD2F4_CDEF4;
extern s32 omovl;
extern u16 D_800CE202_CEE02;
extern u16 D_800D0A3A_D163A;
extern omObjData *D_800D2118_D2D18;
extern u16 D_800D4082_D4C82;
extern f32 D_800D4198_D4D98[];
extern f32 D_800D5210_D5E10;
extern u16 D_800D530C_D5F0C;
extern s16 omobjfirst;
extern s32 D_800D6A40_D7640;
extern u16 D_800D6A56_D7656;
extern u8 D_800D6A90_D7690;
extern s16 omnextidx;

extern u8 D_800A1762_A2362;
extern u16 D_800B23C0_B2FC0;
extern u16 D_800CD050_CDC50;

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
    D_800D2118_D2D18 = NULL;
    D_800D530C_D5F0C = 0;
    D_800D6A90_D7690 = 0;

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
    D_800A1774_A2374 = prcCount;
    D_800A1776_A2376 = 0;
    D_800A1778_A2378 = 0;
    D_800A177C_A237C = (unkProcessStruct *)HuMemMemoryAllocTemp(prcCount * sizeof(unkProcessStruct));

    for (i = 0; i < D_800A1774_A2374; ++i) {
        prcInfo = &D_800A177C_A237C[i];
        prcInfo->stat = 1;
        prcInfo->unk2 = i + 1;
        prcInfo->processInstance = NULL;
        prcInfo->destructor = NULL;
    }

    D_800D5210_D5E10 = 20000.0f;
    D_800CB890_CC490 = 10000.0f;

    for (i = 0; i < 4; ++i) {
        D_800CCF98_CDB98[i] = 20000.0f;
        D_800D4198_D4D98[i] = 10000.0f;
    }

    D_800D6A40_D7640 = 0;
    D_800CD050_CDC50 = 0x5A;
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

    for (i = 0; i < D_800A1774_A2374; i++) {
        prcInfo = &D_800A177C_A237C[i];
        if (prcInfo->stat != 1) {
            HuPrcDtor(prcInfo->processInstance, prcInfo->destructor);
            HuPrcKill(prcInfo->processInstance);
        }
    }

    D_800A1774_A2374 = 0;
    D_800A1776_A2376 = 0;
    HuMemMemoryFreeTemp(D_800A177C_A237C);
    D_800A177C_A237C = NULL;
    HuMemFreeAllWithTag(0x7918);
    D_800D6A40_D7640 = 0;
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
            func_80047D4C_4894C(obj);
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
    D_800A177C_A237C[prc->dtor_idx].stat = stat;
}

void omPrcSetStatBit(Process *prc, s32 stat) {
    D_800A177C_A237C[prc->dtor_idx].stat |= stat;
}

void omPrcResetStatBit(Process *prc, s32 stat) {
    D_800A177C_A237C[prc->dtor_idx].stat &= ~stat;
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

void func_80047C0C_4880C(u16 group, u16 max_objs) {
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

void func_80047D4C_4894C(omObjData *obj) {
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

omObjData **func_80047DBC_489BC(s16 arg0) {
    return omgroup[arg0].objs;
}

omObjData *func_80047DD4_489D4(s16 arg0, u16 arg1) {
    return omgroup[arg0].objs[arg1];
}

void func_80047DFC_489FC(s16 group, u32 stat) {
    omObjGroup *grp = &omgroup[group];
    s32 i;

    for (i = 0; i < grp->max_objs; i++) {
        if (grp->objs[i] != NULL) {
            grp->objs[i]->unk10 |= stat;
        }
    }
}

void func_80047E5C_48A5C(s16 group, u16 idx, s32 flags) {
    omgroup[group].objs[idx]->unk10 |= flags;
}

void func_80047E90_48A90(omObjData *obj, s32 arg1) {
    obj->unk10 |= arg1;
}

Process *omAddPrcObj(process_func func, u16 priority, s32 stackSize, s32 extDataSize) {
    s16 prevIdx;
    Process *newPrc;
    unkProcessStruct *temp_s0;

    if (D_800A1776_A2376 == D_800A1774_A2374) {
        return NULL;
    }

    prevIdx = D_800A1778_A2378;
    temp_s0 = &D_800A177C_A237C[D_800A1778_A2378];
    temp_s0->stat = 4;
    D_800A1778_A2378 = temp_s0->unk2;

    newPrc = HuPrcCreate(func, priority, stackSize, extDataSize);

    temp_s0->processInstance = newPrc;
    newPrc->dtor_idx = prevIdx;
    HuPrcDtor(temp_s0->processInstance, omDestroyPrcObj);

    temp_s0->destructor = NULL;
    ++D_800A1776_A2376;

    return temp_s0->processInstance;
}

Process *func_80047F50_48B50(process_func func, s32 priority, s32 stack_size, s32 extra_data_size, Process *parent) {
    unkProcessStruct *prcInfo;
    Process *process;
    s16 prevIdx;

    if (D_800A1776_A2376 == D_800A1774_A2374) {
        return NULL;
    }

    prevIdx = D_800A1778_A2378;
    prcInfo = &D_800A177C_A237C[D_800A1778_A2378];
    prcInfo->stat = 4;
    D_800A1778_A2378 = prcInfo->unk2;
    process = HuPrcCreateChild(func, priority, stack_size, extra_data_size, parent);
    prcInfo->processInstance = process;
    process->dtor_idx = prevIdx;
    HuPrcDtor(prcInfo->processInstance, omDestroyPrcObj);
    prcInfo->destructor = NULL;
    D_800A1776_A2376++;
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
    temp_s0 = &D_800A177C_A237C[currPrc->dtor_idx];
    if (temp_s0->destructor != NULL) {
        temp_s0->destructor();
    }
    temp_s0->stat = 1;
    temp_s0->unk2 = D_800A1778_A2378;
    D_800A1778_A2378 = currPrc->dtor_idx;
    --D_800A1776_A2376;
}

void omPrcSetDestructor(s32 arg0, void *arg1) {
    unkProcessStruct *unk = &D_800A177C_A237C[HuPrcCurrentGet()->dtor_idx];
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
        D_800A1756_A2356 = D_800CE202_CEE02;
    }

    D_800A176C_A236C = 1;
    omovl = ovlID;
    omovlevtno = event;
    omovlstat = stat;
    D_800D0A3A_D163A = 0;

    if (stat & 0x40 && D_800CCF52_CDB52 != 2) {
        func_8004A444_4B044(2);
    } else if (stat & 0x80 && (D_800CCF52_CDB52 != 3)) {
        func_8004A444_4B044(3);
    }

    if ((D_800D4082_D4C82 != D_800A1920_A2520[ovlID].unk_00) || (D_800CD2F4_CDEF4 != D_800A1920_A2520[ovlID].unk_02) || (D_800D6A56_D7656 != D_800A1920_A2520[ovlID].unk_04)) {
        func_8004A468_4B068(D_800A1920_A2520[ovlID].unk_00, D_800A1920_A2520[ovlID].unk_02, D_800A1920_A2520[ovlID].unk_04);
    }

    if (!(stat & 0x2000)) {
        if (stat & 2) {
            var_a0_2 = D_800A1740_A2340[GwSystem.current_board_index][0];
            var_v1 = D_800A1740_A2340[GwSystem.current_board_index][1];
        } else if (stat & 4) {
            var_a0_2 = D_800A16B0_A22B0[GwSystem.minigame_index - 1][0];
            var_v1 = D_800A16B0_A22B0[GwSystem.minigame_index - 1][1];
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

        D_800A1784_A2384 = var_v1;
        D_800A1908_A2508 = var_a0_2;
    }
    D_800A190C_A250C = 0;
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
    D_800A1762_A2362 = 4;
    D_800B23C0_B2FC0 = D_800CD050_CDC50;
    GMesClose();
    func_8001AFE4_1BBE4();
    func_80021AF4_226F4();
    omDestroyObjMan();
    func_8000BA00_C600();
    func_800166D0_172D0();
    D_800CD280_CDE80 = 1;
}

extern s32 fontcolor;
extern u16 omdispinfo;
extern s32 omovl;
extern u16 D_800A1906_A2506;
extern s16 D_800A1786_A2386;
extern u8 D_800A1783_A2383;
extern u8 D_800D1FA0_D2BA0;
extern void *D_800A1240_A1E40[3];
extern u8 D_800A1782_A2382;
extern u8 D_800A1848_A2448;
extern u8 D_800A1849_A2449;
extern u8 D_800B23CA_B2FCA;
extern u16 D_800A190A_A250A;
extern u16 D_800A190E_A250E;
extern f32 D_800D5410_D6010;
extern f32 D_800D51FC_D5DFC;
extern u8 D_800A176D_A236D;
extern s32 D_800CC370_CCF70;
extern omObjData *D_800D054C_D114C;
extern s16 D_800CE190_CED90;
extern void (*D_800CC3B8_CCFB8)(omObjData *);
void func_8004A950_4B550(void);
void func_8001BF14_1CB14(void);

extern u8 D_800A1762_A2362;
extern u8 D_800A176C_A236C;
extern u16 D_800D0A3A_D163A;

u16 func_8004B2C0_4BEC0(void);
void func_8000F024_FC24(void *, u8, s32);
void ResetVibrator(s16);
s32 func_80000F08_1B08(s32);
s32 func_8004DE24_4EA24(s32, s32, s32, s32, s32);
void func_8004B1AC_4BDAC(void);
void func_8004AE28_4BA28(void);
void func_800035E8_41E8(s32);
void func_8004AD70_4B970(void);
s32 func_80000DF0_19F0(void);
void func_8004B2C8_4BEC8(void);
void func_8000B7A0_C3A0(void);
void func_8001766C_1826C(void);
void func_8004A49C_4B09C(void);
void OvlLoad(s32 overlayIndex);
void HmfLightInit(void);
void HmfLightStatSet(s16 arg0, u8 arg1, u8 arg2);
void func_8001F6B0_202B0(s32);
void func_80045C2C_4682C(void);
void func_8004AB7C_4B77C(s32);
void func_8004ADDC_4B9DC(s32);
void func_80007D2C_892C(s32, s32);
void func_8004AA04_4B604(s32);
void func_801059A0(void);
s16 func_8004D6AC_4E2AC(s32, s32, s32);
void func_8004D6E8_4E2E8(s16);

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
        sprintf(D_800D5218_D5E18, "%8lX(%ld)", permSize, permUsed);
        print8(0x10U, 0x18U, D_800D5218_D5E18);
        tempSize = HuMemHeapAllocTempSizeGet();
        sprintf(D_800D5218_D5E18, "%8lX(%ld)", tempSize, HuMemUsedMemoryBlockGetTemp());
        print8(0x10U, 0x20U, D_800D5218_D5E18);
        sprintf(D_800D5218_D5E18, "OVL:%d(%ld<%ld)", omovlhisidx, omovl, (s32)(s16)D_800A1756_A2356);
        print8(0x18U, 0x28U, D_800D5218_D5E18);
        sprintf(D_800D5218_D5E18, "OBJ:%d/%d", omnumobjs, ommaxobjs);
        print8(0x18U, 0x30U, D_800D5218_D5E18);
        sprintf(D_800D5218_D5E18, "PRC:%d/%d", D_800A1776_A2376, D_800A1774_A2374);
        print8(0x18U, 0x38U, D_800D5218_D5E18);
        sprintf(D_800D5218_D5E18, "%02X", D_800A1906_A2506);
        print8(0x70U, 0x38U, D_800D5218_D5E18);
        i = func_80000F08_1B08(6);
        sprintf(D_800D5218_D5E18, "C:%04X D:%02X", i, func_80000F08_1B08(5));
        print8(0x28U, 0x40U, D_800D5218_D5E18);
        if (D_800A1786_A2386 == -1) {
            D_800A1786_A2386 = func_8004DE24_4EA24(0xE, 0x16, 0x82, 0x4A, 0xFF70);
        }
    }
    func_8004B1AC_4BDAC();
    func_8004AE28_4BA28();
    if (D_800A176C_A236C != 0) {
        if (D_800A1906_A2506 & 8) {
            D_800A1783_A2383 = 1;
            if (!(D_800A1906_A2506 & 1) && (D_800B23C0_B2FC0 != 0)) {
                D_800B23C0_B2FC0--;
                if (D_800A1762_A2362 != 0) {
                    D_800A1762_A2362--;
                }
                return;
            }
            func_8004A950_4B550();
        }
        if (D_800A1762_A2362 == 0) {
            if (D_800D1FA0_D2BA0 != 1) {
                if (D_800A1780_A2380 == 1) {
                    if (D_800D0A3A_D163A == 4) {
                        func_8001BF14_1CB14();
                    }
                    if (D_800D0A3A_D163A != 0) {
                        D_800D0A3A_D163A--;
                        return;
                    }
                    D_800CCF52_CDB52 = D_800D1710_D2310;
                    func_8000F024_FC24(D_800A1240_A1E40, D_800D1710_D2310, 2);
                    func_8001A070_1AC70(HuMemMemoryAllocPerm, HuMemMemoryFreePerm, D_800D4082_D4C82, D_800CD2F4_CDEF4, (u16)(s32)D_800D6A56_D7656, (u8)(s32)(u8)D_800D1710_D2310);
                    func_800224BC_230BC();
                    func_8001BF90_1CB90(0x02000000, 0x3D0800);
                    Hu3DCamInit(1);
                }
                D_800A1780_A2380 = 0;
                if (D_800A1782_A2382 == 0) {
                    if (D_800A1848_A2448 != 0) {
                        if (!(--D_800A1848_A2448 & 0xFF)) {
                            D_800A1849_A2449 = 1;
                        }
                        return;
                    } else {
                        D_800B23CA_B2FCA = 0;
                        if ((func_8004B2C0_4BEC0()) == 1) {
                            func_8004A950_4B550();
                            func_800035E8_41E8(0);
                            func_800035E8_41E8(1);
                            func_8004AD70_4B970();
                            if (D_800A1849_A2449 == 0) {
                                D_800A1848_A2448 = 5;
                                return;
                            } else if (D_800A1849_A2449 != 1) {
                                return;
                            } else if (func_80000DF0_19F0() != 0) {
                                return;
                            }
                            D_800B23CA_B2FCA = 1;
                            D_800A1782_A2382 = 1;
                            return;
                        }
                    }
                } else {
                    if (!(--D_800B23CA_B2FCA)) {
                        func_8004B2C8_4BEC8();
                        D_800A190A_A250A = D_800A1908_A2508;
                        D_800A190E_A250E = D_800A190C_A250C;
                        D_800A1782_A2382 = 0;
                        D_800A1849_A2449 = 0;
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
            D_800D6A58_D7658 = 0;
            func_8000B7A0_C3A0();
            func_8001766C_1826C();
            D_800A176C_A236C = 0;
            func_8004A49C_4B09C();
            OvlLoad(omovl);
            HmfLightInit();
            D_800D5410_D6010 = 1.0f;
            D_800D51FC_D5DFC = 1.0f;
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
            func_8001F38C_1FF8C(0, 0, 0);
            D_800CD280_CDE80 = 1;
            func_8001F6B0_202B0(1);
            func_80045C2C_4682C();
            if (D_800A176D_A236D == 0) {
                func_8004AD70_4B970();
                if (D_800A1783_A2383 == 1) {
                    func_8004AB7C_4B77C(0x7F);
                }
                func_8004ADDC_4B9DC(0x40);
                func_80007D2C_892C(-1, D_800A1784_A2384);
            }
            if (D_800A1783_A2383 == 1) {
                func_8004AA04_4B604(0x7F);
            }
            D_800A1783_A2383 = 0;
            D_800D1FA0_D2BA0 = 0;
            D_800D1100_D1D00 = 0;
            func_801059A0();
            for (i = 0; i < 4; i++) {
                if (CheckControllerRead(i) != 0) {
                    D_800D5558_D6158[i] = 0;
                }
            }
            if (D_800A176C_A236C != 0) {
                omOvlKill();
                D_800A1762_A2362 = 0;
                return;
            }
        } else {
            D_800A1762_A2362--;
            return;
        }
    }
    temp_s3 = func_8004D6AC_4E2AC(0, 0, 0xFF);
    D_800CC370_CCF70 = 0;
    D_800D054C_D114C = NULL;
    for (var_s1 = omobjlast; var_s1 != -1;) {
        obj = &omobjall[var_s1];
        D_800CE190_CED90 = 0;
        D_800CC370_CCF70++;
        D_800D054C_D114C = obj;
        var_s1 = obj->prev;
        if (!(obj->stat & 3)) {
            D_800CC3B8_CCFB8 = obj->func;
            func = obj->func;
            if (func != NULL && !(obj->stat & (0x40 | 0x10 | 0x08))) {
                func(obj);
            }
            D_800CE190_CED90 = 1;
            if (omobjlast != -1 && D_800A176C_A236C == 0) {
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
                    D_800CE190_CED90 = 2;
                }
            } else {
                break;
            }
        }
    }
    D_800CE190_CED90 = 4;
    func_8004D6E8_4E2E8(temp_s3);
    D_800CE190_CED90 = 5;
    if (D_800A176C_A236C != 0) {
        D_800CE190_CED90 = 6;
        omOvlKill();
        D_800CE190_CED90 = 7;
    }
    D_800CE190_CED90 = 8;
}

void func_80048E88_49A88(void);
char const D_800A7AE4_A86E4[] = " SE STP";
char const D_800A7AEC_A86EC[] = " MUSSTP";
char const D_800A7AF4_A86F4[] = " INFO  ";
char const D_800A7AFC_A86FC[] = " LIGHT ";
char const D_800A7B04_A8704[] = " RESET ";
char const D_800A7B0C_A870C[] = " CANCEL";

void func_800499B0_4A5B0(omObjData *);

void func_80048E88_49A88(void) {
    omObjData *temp_v0;

    temp_v0 = omAddObj(0x7FD9, 0, 0, -1, func_800499B0_4A5B0);
    D_800D2118_D2D18 = temp_v0;
    omSetStatBit(temp_v0, 0xA0);
    temp_v0->work[0] = 0;
    temp_v0->work[1] = 0;
    temp_v0->work[2] = 0;
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_80048EE8_49AE8);

INCLUDE_ASM("asm/nonmatchings/objmain", func_800499B0_4A5B0);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80049F98_4AB98);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80049FB8_4ABB8);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A0E0_4ACE0);

void func_8004A208_4AE08(void) {
    func_80045350_45F50();
    if (omovlstat & 0x10) {
        func_80048E88_49A88();
        if (omovlstat & 4) {
            D_800D6A58_D7658 = 1;
        }
    }
    if (omovlstat & 0x20) {
        func_8004CEA4_4DAA4();
    }
    func_8004CF30_4DB30();
    if (_CheckFlag(0xF) != 0) {
        D_800B23C2_B2FC2 = func_8000B838_C438(0x94);
        D_800B23C4_B2FC4 = InitEspriteSlot(D_800B23C2_B2FC2, 0, 1);
        func_8000BBFC_C7FC(D_800B23C4_B2FC4, 0x100);
        func_8000BCC8_C8C8(D_800B23C4_B2FC4, 1);
        D_800B23C8_B2FC8 = D_800A18B7_A24B7[GwSystem.minigame_index];
        func_8000BBD4_C7D4(D_800B23C4_B2FC4, D_800A18A8_A24A8[D_800B23C8_B2FC8][0], D_800A18A8_A24A8[D_800B23C8_B2FC8][1]);
        D_800B23C6_B2FC6 = 0;
        omSetStatBit(omAddObj(10, 0, 0, -1, func_8004A354_4AF54), 0xA0);
    }
}

void func_8004A354_4AF54(omObjData *arg0) {
    D_800B23C6_B2FC6 += 10;
    if (D_800B23C6_B2FC6 > 180) {
        D_800B23C6_B2FC6 -= 180;
    }
    func_8000BBFC_C7FC(D_800B23C4_B2FC4, HuMathSin(D_800B23C6_B2FC6) * 255.0f);
    func_8000BBD4_C7D4(D_800B23C4_B2FC4, D_800A18A8_A24A8[D_800B23C8_B2FC8][0], D_800A18A8_A24A8[D_800B23C8_B2FC8][1]);
    if (D_800D1100_D1D00 == 1) {
        func_8000BB54_C754(D_800B23C4_B2FC4);
    } else {
        func_8000BB94_C794(D_800B23C4_B2FC4);
    }
}

void func_8004A444_4B044(s32 arg0) {
    D_800A1780_A2380 = 1;
    D_800D0A3A_D163A = 4;
    D_800D1710_D2310 = arg0;
}

void func_8004A468_4B068(u16 arg0, u16 arg1, u16 arg2) {
    D_800D4082_D4C82 = arg0;
    D_800CD2F4_CDEF4 = arg1;
    D_800D6A56_D7656 = arg2;
    D_800A1780_A2380 = 1;
    D_800D0A3A_D163A = 4;
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A49C_4B09C);
