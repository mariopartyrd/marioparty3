#include "common.h"
#include "game/object.h"
#include "malloc.h"

typedef struct unkProcessStruct {
    s16 stat;
    s16 unk2;
    Process* processInstance;
    void (*destructor)();
} unkProcessStruct;

extern s16 D_800A1774_A2374;
extern s16 D_800A1776_A2376;
extern s16 D_800A1778_A2378;
extern unkProcessStruct* D_800A177C_A237C;
extern s16 D_800A1780_A2380;
extern s16 D_800D0A3A_D163A;
extern s8 D_800D1710_D2310;

void omDestroyPrcObj(void);
void func_8000BA00_C600(void);
void func_8000BB94_C794(s32);
void func_8000BBFC_C7FC(s32, s16);
void func_800166D0_172D0(void);
void func_8001AFE4_1BBE4(void);
void func_80021AF4_226F4(void);
void func_80037190_37D90(void);
void omInsertObj(omObjData * obj);
void func_80045350_45F50();
void omAddMember(u16 group, omObjData * obj);
void func_8004A354_4AF54(omObjData*);
void func_8004A444_4B044(s32);
void func_8004A468_4B068(u16, u16, u16);
void func_8004CEA4_4DAA4();
extern u8 D_800A16B0_A22B0[][2];
extern u8 D_800A1740_A2340[][2];
extern u16 D_800A1756_A2356;
extern s32 omprevovl;
extern u16 omovlstat;
extern s8 D_800A176C_A236C;
extern omObjData* omobjall;
extern u8 D_800A1784_A2384;
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
    char unk_06[2]; //unused pad?
} UnkomOvl;

typedef struct {
    u16 next_idx;
    u16 max_objs;
    u16 num_objs;
    u16* next;
    omObjData** objs;
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
extern s16 D_800D0A3A_D163A;
extern s32 D_800D2118_D2D18;
extern u16 D_800D4082_D4C82;
extern f32 D_800D4198_D4D98[];
extern f32 D_800D5210_D5E10;
extern u16 D_800D530C_D5F0C;
extern s16 omobjfirst;
extern s32 D_800D6A40_D7640;
extern u16 D_800D6A56_D7656;
extern s8 D_800D6A90_D7690;
extern s16 omnextidx;


extern s8 D_800A1762_A2362;
extern u16 D_800B23C0_B2FC0;
extern u16 D_800CD050_CDC50;
extern omOvlHisData omovlhis[12];

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

void omInitObjMan(s16 numOfObjs, s32 numOfPrcs)
{
    s16 prcCount;
    s32 i;
    omObjData* obj;
    unkProcessStruct* prcInfo;

    ommaxobjs = numOfObjs + 1;
    omnumobjs = 0;
    omnextidx = 0;
    omobjlast = -1;
    omobjfirst = -1;
    D_800D2118_D2D18 = 0;
    D_800D530C_D5F0C = 0;
    D_800D6A90_D7690 = 0;

    if (omobjall != NULL) {
        HuMemMemoryFreeTemp((void *)omobjall);
    }

    omobjall = (omObjData *)HuMemMemoryAllocTemp(ommaxobjs* sizeof(omObjData));

    for (i = 0; i < ommaxobjs; ++i)
    {
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

    for (i = 0; i < 10; ++i)
    {
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
    D_800A177C_A237C = (unkProcessStruct *)HuMemMemoryAllocTemp(prcCount* sizeof(unkProcessStruct));

    for (i = 0; i < D_800A1774_A2374; ++i)
    {
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

INCLUDE_ASM("asm/nonmatchings/objmain", omDestroyObjMan);

omObjData* omAddObj(s16 prio, u16 mdlcnt, u16 mtncnt, s16 group, omObjFunc func)
{
    omObjData* object;
    s32 i;

    if (omnumobjs == ommaxobjs) {
        return NULL;
    }

    object = &omobjall[omnextidx];
    object->next_idx_alloc = omnextidx;
    object->prio = prio;

    omInsertObj(object);

    if (mdlcnt != 0) {
        object->model = HuMemMemoryAllocTemp(mdlcnt* sizeof(s16));
        object->mdlcnt = mdlcnt;
        for (i = 0; i < mdlcnt; ++i) {
            object->model[i] = -1;
        }
    } else {
        object->model = NULL;
        object->mdlcnt = 0;
    }

    if (mtncnt != 0) {
        object->motion = HuMemMemoryAllocTemp(mtncnt* sizeof(s16));
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

void omSetObjPrio(omObjData* obj, s16 prio)
{
    obj->prio = prio;

    if (omobjlast != omobjfirst)
    {
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
void omInsertObj(omObjData* obj)
{
    s16 next_idx_alloc;
    s16 prio;
    s16 obj_idx;
    omObjData* obj_new;
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

INCLUDE_ASM("asm/nonmatchings/objmain", omDelObj);

void omSetStat(omObjData* obj, u16 stat) {
    obj->stat = stat;
}

void omSetStatBit(omObjData* obj, u16 stat) {
    obj->stat |= stat;
}

void omResetStatBit(omObjData* obj, u16 stat) {
    obj->stat &= ~stat;
}

void omPrcSetStat(Process* prc, s32 stat) {
    D_800A177C_A237C[prc->dtor_idx].stat = stat;
}

void omPrcSetStatBit(Process* prc, s32 stat) {
    D_800A177C_A237C[prc->dtor_idx].stat |= stat;
}

void omPrcResetStatBit(Process* prc, s32 stat) {
    D_800A177C_A237C[prc->dtor_idx].stat &= ~stat;
}

void omSetTra(omObjData* obj, float x, float y, float z) {
    obj->trans.x = x;
    obj->trans.y = y;
    obj->trans.z = z;
}

void omSetRot(omObjData* obj, float x, float y, float z) {
    obj->rot.x = x;
    obj->rot.y = y;
    obj->rot.z = z;
}

void omSetSca(omObjData* obj, float x, float y, float z) {
    obj->scale.x = x;
    obj->scale.y = y;
    obj->scale.z = z;
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047C0C_4880C);

void omAddMember(u16 group, omObjData* obj)
{
    omObjGroup* group_ptr = &omgroup[group];

    if (group_ptr->num_objs != group_ptr->max_objs)
    {
        obj->group = group;
        obj->group_idx = group_ptr->next_idx;
        group_ptr->objs[group_ptr->next_idx] = obj;
        group_ptr->next_idx = group_ptr->next[group_ptr->next_idx];
        ++group_ptr->num_objs;
    }
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047D4C_4894C);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047DBC_489BC);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047DD4_489D4);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047DFC_489FC);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047E5C_48A5C);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047E90_48A90);

Process* omAddPrcObj(process_func func, u16 priority, s32 stackSize, s32 extDataSize)
{
    s16 prevIdx;
    Process* newPrc;
    unkProcessStruct* temp_s0;

    if (D_800A1776_A2376 == D_800A1774_A2374) {
        return NULL;
    }

    prevIdx             = D_800A1778_A2378;
    temp_s0             = &D_800A177C_A237C[D_800A1778_A2378];
    temp_s0->stat       = 4;
    D_800A1778_A2378    = temp_s0->unk2;

    newPrc = HuPrcCreate(func, priority, stackSize, extDataSize);

    temp_s0->processInstance = newPrc;
    newPrc->dtor_idx         = prevIdx;
    HuPrcDtor(temp_s0->processInstance, omDestroyPrcObj);

    temp_s0->destructor = NULL;
    ++D_800A1776_A2376;

    return temp_s0->processInstance;
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047F50_48B50);

INCLUDE_ASM("asm/nonmatchings/objmain", omDelPrcObj);

void omDestroyPrcObj(void)
{
    Process* currPrc;
    unkProcessStruct* temp_s0;

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

INCLUDE_ASM("asm/nonmatchings/objmain", omPrcSetDestructor);

s32 omOvlCallEx(s32 ovlID, s16 event, u16 stat) {
    omOvlHisData* history;

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

    if ((omovl != name_7F) && (omovl != test_menu1)) {
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
    omOvlHisData* history;
    
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
    func_80037190_37D90();
    func_8001AFE4_1BBE4();
    func_80021AF4_226F4();
    omDestroyObjMan();
    func_8000BA00_C600();
    func_800166D0_172D0();
    D_800CD280_CDE80 = 1;
}

INCLUDE_ASM("asm/nonmatchings/objmain", omMain);

void func_80048E88_49A88(void);
INCLUDE_ASM("asm/nonmatchings/objmain", func_80048E88_49A88);

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

void func_8004A354_4AF54(omObjData* arg0) {
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

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A468_4B068);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A49C_4B09C);
