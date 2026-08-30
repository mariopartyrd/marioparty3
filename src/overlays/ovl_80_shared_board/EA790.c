#include "common.h"
#include "ovl_80.h"

//this file matches BE940.c in ovl_81

UnkBoard2 *func_800D6B70_EA790_shared_board(s32 arg0) {
    s32 sp10[3] = { 0x00000016, 0x00000016, 0x00000016 };
    UnkBoard2 *temp_v0;
    Object *temp_v0_2;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(UnkBoard2));
    temp_v0->unk_00 = 0;
    temp_v0->obj = MBModelCreate(sp10[arg0], NULL);
    func_8001C258_1CE58(temp_v0->obj->omObj1->model[0], 0x180, 0);
    func_8001C8E4_1D4E4(temp_v0->obj->omObj1->model[0], 0x1400);
    func_8001C448_1D048(temp_v0->obj->omObj1->model[0]);
    MBModelTempAllocFree(temp_v0->obj);
    return temp_v0;
}

static void func_800D6C3C_EA85C_shared_board(UnkBoard2* arg0) {
    MBModelKill(arg0->obj);
    HuMemMemoryFreeTemp(arg0);
}

UnkEA790Struct* func_800D6C6C_EA88C_shared_board(void) {
    UnkEA790Struct* temp_v0;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(UnkEA790Struct));
    temp_v0->unk_00 = 0;
    temp_v0->unk_02 = 0;
    temp_v0->unk_04 = 0;
    temp_v0->proc = NULL;
    temp_v0->unk_0C = 0;
    temp_v0->player = NULL;
    return temp_v0;
}

void func_800D6CA0_EA8C0_shared_board(UnkEA790Struct* arg0) {
    UnkBoard2** var_s1;
    s32 i;

    if (arg0->unk_02 != 0) {
        var_s1 = arg0->unk_04;
        for (i = 0; i < arg0->unk_02; i++) {
            func_800D6C3C_EA85C_shared_board(*var_s1++);
        }
        HuMemMemoryFreeTemp(arg0->unk_04);
    }
    
    if (arg0->proc != NULL) {
        omDelPrcObj(arg0->proc);
    }
    
    HuMemMemoryFreeTemp(arg0);
}

void func_800D6D2C_EA94C_shared_board(UnkEA790Struct *arg0, UnkBoard2 *arg1, u16 arg2) {
    UnkBoard2 **newList;
    UnkBoard2 **dst;
    UnkBoard2 **src;
    s32 i;

    newList = HuMemMemoryAllocTemp(++arg0->unk_02 * sizeof(UnkBoard2 *));
    dst = newList;
    if (arg0->unk_04 != NULL) {
        src = arg0->unk_04;
        for (i = 0; i < arg0->unk_02 - 1; i++) {
            *dst++ = *src++;
        }
    }

    if (1) {
        *dst = arg1;
    } else {
        *dst = arg1;
    }

    if (arg0->unk_04 != NULL) {
        HuMemMemoryFreeTemp(arg0->unk_04);
    }
    
    arg0->unk_04 = newList;

    arg1->unk_00 = arg2;
    if (arg2 & 1) {
        arg0->unk_0C = arg0->unk_02 - 1;
    }
}

//unused
void func_800D6E00_EAA20_shared_board(UnkEA790Struct *arg0, UnkBoard2* arg1) {
    UnkBoard2 **newList;
    UnkBoard2 **dst;
    UnkBoard2 **src;
    s16 count;
    s32 i;

    count = arg0->unk_02;
    newList = NULL;
    if (count >= 2) {
        count--;
        arg0->unk_02 = count;
        newList = HuMemMemoryAllocTemp(count * sizeof(s32));
        dst = newList;
        src = arg0->unk_04;
        for (i = 0; i <= arg0->unk_02; i++) {
            if (*src == arg1) {
                src++;
            } else {
                *dst = *src;
                src++;
                dst++;
            }
        }
    } else {
        arg0->unk_02 = 0;
    }

    if (arg0->unk_04 != NULL) {
        HuMemMemoryFreeTemp(arg0->unk_04);
    }
    arg0->unk_04 = newList;
}

UnkBoard2* func_800D6EC8_EAAE8_shared_board(UnkEA790Struct* arg0, s16 arg1) {
    return arg0->unk_04[arg1];
}
