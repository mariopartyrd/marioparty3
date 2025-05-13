#include "common.h"
#include "game/object.h"

typedef struct unkProcessStruct {
    s16 unk0;
    s16 unk2;
    Process* processInstance;
    void (*unk8)();
} unkProcessStruct;

void omDestroyPrcObj(void);
extern s16 D_800A1774_A2374;
extern s16 D_800A1776_A2376;
extern s16 D_800A1778_A2378;
extern unkProcessStruct* D_800A177C_A237C;

void func_8000BA00_C600(void);
void func_800166D0_172D0(void);
void func_8001AFE4_1BBE4(void);
void func_80021AF4_226F4(void);
void func_80037190_37D90(void);


void func_8004A444_4B044(s32);                           /* extern */
void func_8004A468_4B068(u16, u16, u16);               /* extern */
extern u8 D_800A16B0_A22B0[][2];
extern u8 D_800A1740_A2340[][2];
extern u16 D_800A1756_A2356;
extern s32 D_800A1758_A2358;
extern u16 D_800A1766_A2366;
extern s8 D_800A176C_A236C;
extern u8 D_800A1784_A2384;
extern s16 D_800A1908_A2508;
extern s16 D_800A190C_A250C;

typedef struct UnkomOvl {
    u16 unk_00;
    u16 unk_02;
    u16 unk_04;
    char unk_06[2]; //unused pad?
} UnkomOvl;

extern UnkomOvl D_800A1920_A2520[];

extern u8 D_800CCF52_CDB52;
extern u16 D_800CD2F4_CDEF4;
extern s32 D_800CE200_CEE00;
extern u16 D_800CE202_CEE02;
extern s16 D_800D0A3A_D163A;
extern u16 D_800D4082_D4C82;
extern u16 D_800D6A56_D7656;


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

INCLUDE_ASM("asm/nonmatchings/objmain", omInitObjMan);

INCLUDE_ASM("asm/nonmatchings/objmain", omDestroyObjMan);

INCLUDE_ASM("asm/nonmatchings/objmain", omAddObj);

INCLUDE_ASM("asm/nonmatchings/objmain", omSetObjPrio);

INCLUDE_ASM("asm/nonmatchings/objmain", omInsertObj);

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

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047CDC_488DC);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047D4C_4894C);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047DBC_489BC);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047DD4_489D4);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047DFC_489FC);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047E5C_48A5C);

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047E90_48A90);

Process* omAddPrcObj(void (*func)(), u16 priority, s32 stackSize, s32 extDataSize) {
    Process* temp_v0;
    s16 temp_s1;
    unkProcessStruct* temp_s0;

    if (D_800A1776_A2376 != D_800A1774_A2374) {
        temp_s1 = D_800A1778_A2378;
        temp_s0 = &D_800A177C_A237C[D_800A1778_A2378];
        temp_s0->unk0 = 4;
        D_800A1778_A2378 = temp_s0->unk2;
        temp_v0 = HuPrcCreate(func, priority, stackSize, extDataSize);
        temp_s0->processInstance = temp_v0;
        temp_v0->dtor_idx = temp_s1;
        HuPrcDtor(temp_s0->processInstance, omDestroyPrcObj);
        temp_s0->unk8 = 0;
        D_800A1776_A2376++;
        return temp_s0->processInstance;
    } else {
        return NULL;
    }
}

INCLUDE_ASM("asm/nonmatchings/objmain", func_80047F50_48B50);

INCLUDE_ASM("asm/nonmatchings/objmain", omDelPrcObj);

INCLUDE_ASM("asm/nonmatchings/objmain", omDestroyPrcObj);

INCLUDE_ASM("asm/nonmatchings/objmain", omPrcSetDestructor);

s32 omOvlCallEx(s32 arg0, s16 arg1, u16 arg2) {
    omOvlHisData* history;
    s32 ret;

    if (omovlhisidx < ARRAY_COUNT(omovlhis)) {
        history = &omovlhis[++omovlhisidx];
        history->overlayID = arg0;
        history->event = arg1;
        history->stat = arg2;
        omOvlGotoEx(arg0, arg1, arg2);
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
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

void omOvlGotoEx(s32 arg0, s16 arg1, u16 arg2) {
    u8 var_a0_2;
    u8 var_v1;

    if ((D_800CE200_CEE00 != 0x7F) & (D_800CE200_CEE00 != 0)) {
        D_800A1758_A2358 = D_800CE200_CEE00;
        D_800A1756_A2356 = D_800CE202_CEE02;
    }
    
    D_800A176C_A236C = 1;
    D_800CE200_CEE00 = arg0;
    omovlevtno = arg1;
    D_800A1766_A2366 = arg2;
    D_800D0A3A_D163A = 0;

    if (arg2 & 0x40 && D_800CCF52_CDB52 != 2) {
        func_8004A444_4B044(2);
    } else if (arg2 & 0x80 && (D_800CCF52_CDB52 != 3)) {
        func_8004A444_4B044(3);
    }

    if ((D_800D4082_D4C82 != D_800A1920_A2520[arg0].unk_00) || (D_800CD2F4_CDEF4 != D_800A1920_A2520[arg0].unk_02) || (D_800D6A56_D7656 != D_800A1920_A2520[arg0].unk_04)) {
        func_8004A468_4B068(D_800A1920_A2520[arg0].unk_00, D_800A1920_A2520[arg0].unk_02, D_800A1920_A2520[arg0].unk_04);
    }

    if (!(arg2 & 0x2000)) {
        if (arg2 & 2) {
            var_a0_2 = D_800A1740_A2340[GwSystem.current_board_index][0];
            var_v1 = D_800A1740_A2340[GwSystem.current_board_index][1];
        } else if (arg2 & 4) {
            var_a0_2 = D_800A16B0_A22B0[GwSystem.minigame_index - 1][0];
            var_v1 = D_800A16B0_A22B0[GwSystem.minigame_index - 1][1];
        } else {
            var_a0_2 = 1;
            var_v1 = 20;
        }

        if (arg2 & 0x100) {
            var_a0_2 = 1;
            var_v1 = 20;
        } else if (arg2 & 0x200) {
            var_a0_2 = 2;
            var_v1 = 20;
        } else if (arg2 & 0x400) {
            var_a0_2 = 3;
            var_v1 = 20;
        } else if (arg2 & 0x800) {
            var_a0_2 = 4;
            var_v1 = 20;
        } else if (arg2 & 0x1000) {
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

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A444_4B044);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A468_4B068);

INCLUDE_ASM("asm/nonmatchings/objmain", func_8004A49C_4B09C);
