#include "common.h"
#include "ovl_80.h"

UnkBoard2* func_800D6B70_EA790_shared_board(s32 arg0) {
    s32 sp10[3] = {22, 22, 22};
    UnkBoard2* temp_v0;
    Object* temp_v0_2;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(UnkBoard2));
    temp_v0->unk_00 = 0;
    temp_v0->obj = MBModelCreate(sp10[arg0], 0);
    func_8001C258_1CE58(temp_v0->obj->omObj1->model[0], 0x180, 0);
    func_8001C8E4_1D4E4(temp_v0->obj->omObj1->model[0], 0x1400);
    func_8001C448_1D048(temp_v0->obj->omObj1->model[0]);
    func_800D9714_ED334_shared_board(temp_v0->obj);
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EA790", func_800D6C3C_EA85C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EA790", func_800D6C6C_EA88C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EA790", func_800D6CA0_EA8C0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EA790", func_800D6D2C_EA94C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EA790", func_800D6E00_EAA20_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/EA790", func_800D6EC8_EAAE8_shared_board);
