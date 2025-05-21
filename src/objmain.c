#include "common.h"
#include "game/object.h"
#include "malloc.h"

typedef struct unkProcessStruct {
    s16 unk0;
    s16 unk2;
    Process* processInstance;
    void (*unk8)();
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
void func_800166D0_172D0(void);
void func_8001AFE4_1BBE4(void);
void func_80021AF4_226F4(void);
void func_80037190_37D90(void);
void omInsertObj(omObjData * obj);
void func_80047CDC_488DC(u16 arg0, omObjData * obj);
void func_8004A444_4B044(s32);
void func_8004A468_4B068(u16, u16, u16);
extern u8 D_800A16B0_A22B0[][2];
extern u8 D_800A1740_A2340[][2];
extern u16 D_800A1756_A2356;
extern s32 D_800A1758_A2358;
extern u16 D_800A1766_A2366;
extern s8 D_800A176C_A236C;
extern omObjData* D_800A1770_A2370;
extern u8 D_800A1784_A2384;
extern s16 D_800A1908_A2508;
extern s16 D_800A190C_A250C;

typedef struct UnkomOvl {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    char unk_06[2]; //unused pad?
} UnkomOvl;

typedef struct
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u16* unk8;
    omObjData** objs;        // 000C
} HuObjUnk1;

extern UnkomOvl D_800A1920_A2520[];

extern f32 D_800CB890_CC490;
extern s16 D_800CC430_CD030;
extern s16 D_800CCF50_CDB50;
extern u8 D_800CCF52_CDB52;
extern s16 D_800CCF8C_CDB8C;
extern f32 D_800CCF98_CDB98[];
extern HuObjUnk1 D_800CD1E0_CDDE0[];
extern u16 D_800CD2F4_CDEF4;
extern s32 D_800CE200_CEE00;
extern u16 D_800CE202_CEE02;
extern s16 D_800D0A3A_D163A;
extern s32 D_800D2118_D2D18;
extern u16 D_800D4082_D4C82;
extern f32 D_800D4198_D4D98[];
extern f32 D_800D5210_D5E10;
extern u16 D_800D530C_D5F0C;
extern s16 D_800D5560_D6160;
extern s32 D_800D6A40_D7640;
extern u16 D_800D6A56_D7656;
extern s8 D_800D6A90_D7690;
extern s16 D_800D6B40_D7740;


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

    D_800CCF50_CDB50 = numOfObjs + 1;
    D_800CCF8C_CDB8C = 0;
    D_800D6B40_D7740 = 0;
    D_800CC430_CD030 = -1;
    D_800D5560_D6160 = -1;
    D_800D2118_D2D18 = 0;
    D_800D530C_D5F0C = 0;
    D_800D6A90_D7690 = 0;

    if (D_800A1770_A2370 != NULL) {
        HuMemMemoryFreeTemp((void *)D_800A1770_A2370);
    }

    D_800A1770_A2370 = (omObjData *)HuMemMemoryAllocTemp(D_800CCF50_CDB50* sizeof(omObjData));

    for (i = 0; i < D_800CCF50_CDB50; ++i)
    {
        obj = &D_800A1770_A2370[i];
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
        D_800CD1E0_CDDE0[i].unk2 = 0;
        D_800CD1E0_CDDE0[i].unk4 = 0;
        D_800CD1E0_CDDE0[i].unk0 = 0;
        D_800CD1E0_CDDE0[i].objs = NULL;
        D_800CD1E0_CDDE0[i].unk8 = 0;
    }

    prcCount = numOfPrcs + 2;
    D_800A1774_A2374 = prcCount;
    D_800A1776_A2376 = 0;
    D_800A1778_A2378 = 0;
    D_800A177C_A237C = (unkProcessStruct *)HuMemMemoryAllocTemp(prcCount* sizeof(unkProcessStruct));

    for (i = 0; i < D_800A1774_A2374; ++i)
    {
        prcInfo = &D_800A177C_A237C[i];
        prcInfo->unk0 = 1;
        prcInfo->unk2 = i + 1;
        prcInfo->processInstance = NULL;
        prcInfo->unk8 = 0;
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

// clean up?
INCLUDE_ASM("asm/nonmatchings/objmain", omDestroyObjMan);

omObjData* omAddObj(s16 priority, u16 arg1, u16 arg2, s16 arg3, omObjFunc func)
{
    omObjData* temp_s0;
    s16* temp_v1;
    s32 temp_s1;
    s32 var_a0;
    s32 var_a0_2;

    if (D_800CCF8C_CDB8C == D_800CCF50_CDB50) {
        return NULL;
    }

    temp_s0 = &D_800A1770_A2370[D_800D6B40_D7740];
    temp_s0->next_idx_alloc = D_800D6B40_D7740;
    temp_s0->prio = priority;

    omInsertObj(temp_s0);

    if (arg1 != 0) {
        temp_s0->model = HuMemMemoryAllocTemp(arg1* sizeof(s16));
        temp_s0->mdlcnt = arg1;
        for (var_a0 = 0; var_a0 < arg1; ++var_a0) {
            temp_s0->model[var_a0] = -1;
        }
    } else {
        temp_s0->model = NULL;
        temp_s0->mdlcnt = 0;
    }

    if (arg2 != 0) {
        temp_s0->motion = HuMemMemoryAllocTemp(arg2* sizeof(s16));
        temp_s0->mtncnt = arg2;
    } else {
        temp_s0->motion = NULL;
        temp_s0->mtncnt = 0;
    }

    if (arg3 >= 0) {
        func_80047CDC_488DC(arg3, temp_s0);
    } else {
        temp_s0->group = arg3;
        temp_s0->group_idx = 0;
    }

    temp_s0->stat = 4;
    temp_s0->unk10 = 0;
    temp_s0->func = func;
    temp_s0->work[0] = temp_s0->work[1] = temp_s0->work[2] = temp_s0->work[3] = 0;
    D_800D6B40_D7740 = temp_s0->next_idx;
    ++D_800CCF8C_CDB8C;

    return temp_s0;
}

void omSetObjPrio(omObjData* arg0, s16 arg1)
{
    s16 temp_a0;

    arg0->prio = arg1;

    if (D_800CC430_CD030 != D_800D5560_D6160)
    {
        temp_a0 = arg0->next;
        if (temp_a0 >= 0) {
            D_800A1770_A2370[temp_a0].prev = arg0->prev;
        }

        if ((arg0->prev < 0) || (D_800A1770_A2370[arg0->prev].next = arg0->next, arg0->prev < 0)) {
            D_800D5560_D6160 = D_800A1770_A2370[arg0->next].next_idx_alloc;
        }
        if (arg0->next < 0) {
            D_800CC430_CD030 = D_800A1770_A2370[arg0->prev].next_idx_alloc;
        }

        omInsertObj(arg0);
    }
}

// register object into linked list, sort based on priority
void omInsertObj(omObjData* obj)
{
    s16 temp_a0;
    s16 temp_t0;
    s16 temp_t1;
    s16 var_a2;
    omObjData* temp_a3;
    s16 temp_t4;

    temp_t0 = obj->next_idx_alloc;
    temp_t1 = obj->prio;

    if (D_800D5560_D6160 == -1) {
        obj->prev = -1;
        obj->next = -1;
        D_800D5560_D6160 = temp_t0;
        D_800CC430_CD030 = temp_t0;
    } else {
        var_a2 = D_800D5560_D6160;
        while (var_a2 != -1) {
            temp_a3 = &D_800A1770_A2370[var_a2];
            if (temp_a3->prio <= temp_t1) {
                break;
            }
            temp_t4 = var_a2;
            var_a2 = temp_a3->next;
        }
        if (var_a2 != -1) {
            obj->prev = temp_a3->prev;
            obj->next = var_a2;
            temp_a0 = temp_a3->prev;
            if (temp_a0 != -1) {
                D_800A1770_A2370[temp_a0].next = temp_t0;
            } else {
                D_800D5560_D6160 = temp_t0;
            }
            temp_a3->prev = temp_t0;
        } else {
            obj->next = -1;
            obj->prev = temp_t4;
            temp_a3->next = temp_t0;
            D_800CC430_CD030 = temp_t0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/objmain", omDelObj);

INCLUDE_ASM("asm/nonmatchings/objmain", omSetStat);

INCLUDE_ASM("asm/nonmatchings/objmain", omSetStatBit);

INCLUDE_ASM("asm/nonmatchings/objmain", omResetStatBit);

INCLUDE_ASM("asm/nonmatchings/objmain", omPrcSetStat);

INCLUDE_ASM("asm/nonmatchings/objmain", omPrcSetStatBit);

INCLUDE_ASM("asm/nonmatchings/objmain", omPrcResetStatBit);

INCLUDE_ASM("asm/nonmatchings/objmain", omSetTra);

INCLUDE_ASM("asm/nonmatchings/objmain", omSetRot);

INCLUDE_ASM("asm/nonmatchings/objmain", omSetSca);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047C0C_4880C);

void func_80047CDC_488DC(u16 arg0, omObjData* obj)
{
    HuObjUnk1* temp_a2;

    temp_a2 = &D_800CD1E0_CDDE0[arg0];
    if (temp_a2->unk4 != temp_a2->unk2)
    {
        obj->group = arg0;
        obj->group_idx = temp_a2->unk0;
        temp_a2->objs[temp_a2->unk0] = obj;
        temp_a2->unk0 = temp_a2->unk8[temp_a2->unk0];
        ++temp_a2->unk4;
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
    temp_s0->unk0       = 4;
    D_800A1778_A2378    = temp_s0->unk2;

    newPrc = HuPrcCreate(func, priority, stackSize, extDataSize);

    temp_s0->processInstance = newPrc;
    newPrc->dtor_idx         = prevIdx;
    HuPrcDtor(temp_s0->processInstance, omDestroyPrcObj);

    temp_s0->unk8 = NULL;
    ++D_800A1776_A2376;

    return temp_s0->processInstance;
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047F50_48B50);

INCLUDE_ASM("asm/nonmatchings/objmain", omDelPrcObj);

void omDestroyPrcObj(void)
{
    process_func func;
    Process* currPrc;
    unkProcessStruct* temp_s0;

    currPrc = HuPrcCurrentGet();
    temp_s0 = &D_800A177C_A237C[currPrc->dtor_idx];
    func = temp_s0->unk8;
    if (func != NULL) {
        func();
    }
    temp_s0->unk0 = 1;
    temp_s0->unk2 = D_800A1778_A2378;
    D_800A1778_A2378 = currPrc->dtor_idx;
    --D_800A1776_A2376;
}

INCLUDE_ASM("asm/nonmatchings/objmain", omPrcSetDestructor);

s32 omOvlCallEx(s32 ovlID, s16 event, u16 stat) {
    omOvlHisData* history;
    s32 overlayLoadedStatus;

    if (omovlhisidx < ARRAY_COUNT(omovlhis)) {
        history = &omovlhis[++omovlhisidx];
        history->overlayID = ovlID;
        history->event = event;
        history->stat = stat;
        omOvlGotoEx(ovlID, event, stat);
        overlayLoadedStatus = TRUE;
    } else { //else, history is full, cannot call overlay
        overlayLoadedStatus = FALSE;
    }
    return overlayLoadedStatus;
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

    if ((D_800CE200_CEE00 != name_7F) & (D_800CE200_CEE00 != test_menu1)) {
        D_800A1758_A2358 = D_800CE200_CEE00;
        D_800A1756_A2356 = D_800CE202_CEE02;
    }
    
    D_800A176C_A236C = 1;
    D_800CE200_CEE00 = ovlID;
    omovlevtno = event;
    D_800A1766_A2366 = stat;
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


void omOvlHisChg(s16 arg0, s32 overlay, s16 event, s16 stat) {
    s32 ovlhisIndex = omovlhisidx - arg0;
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

INCLUDE_ASM("asm/nonmatchings/objmain", func_80048E88_49A88);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80048EE8_49AE8);

INCLUDE_ASM("asm/nonmatchings/objmain", func_800499B0_4A5B0);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80049F98_4AB98);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80049FB8_4ABB8);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A0E0_4ACE0);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A208_4AE08);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A354_4AF54);

void func_8004A444_4B044(s32 arg0) {
    D_800A1780_A2380 = 1;
    D_800D0A3A_D163A = 4;
    D_800D1710_D2310 = arg0;
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A468_4B068);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A49C_4B09C);
