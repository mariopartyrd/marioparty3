#include "common.h"
#include "ovl_81.h"

typedef struct UnkE78B0 {
    s16 unk_00;
    s16 unk_02;
    s16 unk_04;
    Process* proc;
} UnkE78B0; //sizeof 0xC

void func_800FFAE0_E78B0_name_81(s16, s16);

void func_800FFAE0_E78B0_name_81(s16 playerNo, s16 arg1) {
    if (playerNo == CUR_PLAYER) {
        playerNo = Duel_GetCurrentPlayerIndex();
    }
    
    //??
    if (playerNo != 4) {
        switch (arg1) {
        case 0:
            omVibrate(playerNo, 5, 0, 5);
            break;
        case 1:
            omVibrate(playerNo, 2, 3, 10);
            break;
        case 2:
            omVibrate(playerNo, 10, 0, 10);
            break;
        case 3:
            omVibrate(playerNo, 2, 2, 20);
            break;
        case 4:
            omVibrate(playerNo, 20, 0, 20);
            break;
        case 5:
            omVibrate(playerNo, 30, 0, 30);
            break;
        }
    }
}

void func_800FFBEC_E79BC_name_81(void) {
    UnkE78B0* temp_s0 = (UnkE78B0*)HuPrcCurrentGet()->user_data;

    while (1) {
        func_800FFAE0_E78B0_name_81(temp_s0->unk_00, temp_s0->unk_02);
        HuPrcSleep(temp_s0->unk_04);    
    }
}

void* func_800FFC2C_E79FC_name_81(s16 arg0, s16 arg1, s32 arg2) {
    Process* process;
    s16 temp_s1;
    UnkE78B0* unk;
    static s8 D_80101B10_E98E0_name_81[] = {5, 10, 10, 20, 20, 30};

    temp_s1 = D_80101B10_E98E0_name_81[arg1] + arg2;
    unk = HuMemMemoryAllocTemp(sizeof(UnkE78B0));

    if (unk != NULL) {
        unk->unk_00 = arg0;
        unk->unk_02 = arg1;
        unk->unk_04 = temp_s1 - 1;
        process = omAddPrcObj(func_800FFBEC_E79BC_name_81, 0x1005U, 0, 0);
        unk->proc = process;
        process->user_data = unk;
    }
    
    return unk;
}

void func_800FFCCC_E7A9C_name_81(UnkE78B0* arg0) {
    if (arg0 != NULL) {
        omDelPrcObj(arg0->proc);
        HuMemMemoryFreeTemp(arg0);
    }
}
