#include "common.h"
#include "ovl_80.h"

extern s32 fontcolor;

typedef struct UnkData {
    Process* unk_00;
    u16* unk_04;
    s16 unk_08;
} UnkData;

void func_800DA790_EE3B0_shared_board(u16 arg0, u16 arg1, char* arg2, u8 arg3, u8 arg4) {
    fontcolor = arg4;
    print8((arg0 + 1), (arg1 + 1), arg2);
    fontcolor = arg3;
    print8(arg0, arg1, arg2);
}

void func_800DA810_EE430_shared_board(void) {
    s16 temp_v0;
    s16 temp_v0_2;
    UnkData* temp_s0;

    temp_s0 = HuPrcCurrentGet()->user_data;

    for (;; HuPrcVSleep()) {
        if (*D_800D5558_D6158 == 0) {
            continue;
        } else if (*D_800D5558_D6158 != temp_s0->unk_04[temp_s0->unk_08]) {
            temp_s0->unk_08 = 0;
            continue;
        } else if (temp_s0->unk_04[++temp_s0->unk_08] == 0) {
            temp_s0->unk_08 = -1;
            break;
        }
    }
    
    while (1) {
        HuPrcVSleep();
    }
}

void func_800DA8BC_EE4DC_shared_board(u16* arg0) {
    Process* process;
    UnkData* temp_v0_2;

    process = omAddPrcObj(func_800DA810_EE430_shared_board, 0xEFFF, 0, 0x40);
    temp_v0_2 = HuMemMemoryAlloc(process->heap, sizeof(UnkData));
    process->user_data = temp_v0_2;
    temp_v0_2->unk_04 = arg0;
    temp_v0_2->unk_08 = 0;
    temp_v0_2->unk_00 = process;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE3B0", func_800DA91C_EE53C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE3B0", func_800DA938_EE558_shared_board);

void func_800DA948_EE568_shared_board(void) {
}

//this needs a \0 due to rodata splitting problems
void func_800DA950_EE570_shared_board(s32 arg0, s16 arg1) {
    
    sprintf(D_800D5218_D5E18, "KMS: %d", gStarBlockSpaceIndex);
    arg0 = (arg0 * 8) & 0xFFF8;
    func_800DA790_EE3B0_shared_board( arg0, (arg1 * 8), D_800D5218_D5E18, 0xF, 9);
    sprintf(D_800D5218_D5E18, "KMC: %d\0", gCoinBlockSpaceIndex);
    func_800DA790_EE3B0_shared_board(arg0, ((arg1 + 1) * 8), D_800D5218_D5E18, 0xF, 9);
}

void func_800DAA14_EE634_shared_board(void) {
}

void func_800DAA1C_EE63C_shared_board(void) {
}

void func_800DAA24_EE644_shared_board(void) {
}

void func_800DAA2C_EE64C_shared_board(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EE3B0", func_800DAA34_EE654_shared_board);
