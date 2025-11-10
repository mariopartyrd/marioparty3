#include "common.h"
#include "ovl_80.h"

void func_800E1F70_F5B90_shared_board(Unk3*);
extern u8 D_800D6A90_D7690;
extern char D_80102180_115DA0_shared_board[];
extern s16 D_800D41C2;

s32 D_80100F20_114B40_shared_board[] = {
    0x00003000,
    0x00003001,
    0x00003002,
    0x00003003,
    0x00003004,
    0x00003005,
    0x00003006,
    0x00003007,
    0x00003008,
    0x00003009,
    0x0000300A,
    0x0000300B,
    0x0000300C,
    0x0000300D,
    0x0000300E,
    0x0000300F,
    0x00003010,
    0x00003011,
    0x00003012,
    0x00003013,
    0x00003014,
    0x00003015,
    0x00003016,
    0x00003017,
    0x0000301A,
    0x0000301B
};

void func_800E1F70_F5B90_shared_board(Unk3* arg0) {
    s16 sp18[2];

    if (arg0->unk_0C != NULL) {
        func_8006022C_60E2C((u32)arg0->unk_0C, 0);
    }
    
    func_80060394_60F94(1, sp18, D_80100F20_114B40_shared_board[arg0->unk_00]);
    arg0->winID = func_8005A968_5B568(
        0xA0 - sp18[0] / 2,
        arg0->unk_02,
        sp18[0],
        sp18[1],
        0,
        0
    );
    
    if (arg0->unk_0C != NULL) {
        func_8005B6BC_5C2BC(arg0->winID, (u32)arg0->unk_0C, 0);
    }
    func_8005BE30_5CA30(arg0->winID, 5);
    func_8005BEE0_5CAE0(arg0->winID, 0);
    func_8005BDFC_5C9FC(arg0->winID, 0);
    func_8005B63C_5C23C(arg0->winID, 0, 0x20000);
    func_8005B43C_5C03C(arg0->winID, D_80100F20_114B40_shared_board[arg0->unk_00], -1, -1);
}

void func_800E2074_F5C94_shared_board(Unk3* arg0) {
    func_8005F364_5FF64(arg0->winID);
    arg0->winID = -1;
}

void func_800E20A4_F5CC4_shared_board(omObjData* arg0) {
    Unk3* temp_a0;

    temp_a0 = (Unk3*)arg0->data;
    if ((temp_a0->unk_01 == 1) && (D_800D6A90_D7690 != 0)) {
        if (temp_a0->winID >= 0) {
            func_800E2074_F5C94_shared_board(temp_a0);
        }
    } else if (temp_a0->winID < 0) {
        func_800E1F70_F5B90_shared_board(temp_a0);
    }
}

Unk3* func_800E210C_F5D2C_shared_board(s16 arg0, s16 arg1, u8 arg2) {
    Unk3* temp_v0;
    char* temp_v0_3;
    omObjData* temp_v0_2;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(Unk3));
    if (temp_v0 != NULL) {
        temp_v0->unk_00 = arg0;
        temp_v0->unk_02 = arg1;
        temp_v0->unk_01 = arg2;
        temp_v0_2 = omAddObj(0x100, 0, 0, -1, func_800E20A4_F5CC4_shared_board);
        temp_v0->unk_04 = temp_v0_2;
        temp_v0_2->data = temp_v0;
        omSetStatBit(temp_v0->unk_04, 0x80);
        temp_v0->winID = -1;
        if (arg0 != 6) {
            temp_v0->unk_0C = NULL;
        } else {
            temp_v0_3 = HuMemMemoryAllocTemp(8);
            temp_v0->unk_0C = temp_v0_3;
            sprintf(temp_v0_3, D_80102180_115DA0_shared_board, D_800D41C2);
            return temp_v0;           
        }

    }
    return temp_v0;
}

void MBHelpWinKill(Unk3* arg0) {
    if (arg0 != NULL) {
        arg0->unk_04->data = NULL;
        omDelObj(arg0->unk_04);
        if (arg0->winID >= 0) {
            func_8005F364_5FF64(arg0->winID);
            if (arg0->unk_0C != NULL) {
                HuMemMemoryFreeTemp(arg0->unk_0C);
            }
        }
        HuMemMemoryFreeTemp(arg0);
    }
}
