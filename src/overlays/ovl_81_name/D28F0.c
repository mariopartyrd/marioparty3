#include "common.h"
#include "ovl_81.h"

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EAB20_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EAB6C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EABBC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EAD08_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EADBC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EAF70_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EAF94_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EAFC4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB094_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB140_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB164_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB19C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB1D8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB258_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB278_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB29C_name_81);

void func_800EB2BC_name_81(s16 arg0, s32 arg1, u32 arg2, u32 arg3, u32 arg4, u32 arg5, u32 arg6, s16 arg7) {
    s16 sp10[2];
    s16 temp_v0;

    if (arg2 != 0) {
        func_8006022C_main(arg2, 0);
    }
    if (arg3 != 0) {
        func_8006022C_main(arg3, 1);
    }
    if (arg4 != 0) {
        func_8006022C_main(arg4, 2);
    }
    if (arg5 != 0) {
        func_8006022C_main(arg5, 3);
    }
    if (arg6 != 0) {
        func_8006022C_main(arg6, 4);
    }
    func_80060394_main(1, sp10, arg1);
    temp_v0 = func_800EABBC_name_81(arg0, sp10, arg7);
    D_8010555C_name_81 = temp_v0;
    if (arg2 != 0) {
        func_8005B6BC_main(temp_v0, arg2, 0);
    }
    if (arg3 != 0) {
        func_8005B6BC_main(temp_v0, arg3, 1);
    }
    if (arg4 != 0) {
        func_8005B6BC_main(temp_v0, arg4, 2);
    }
    if (arg5 != 0) {
        func_8005B6BC_main(temp_v0, arg5, 3);
    }
    if (arg6 != 0) {
        func_8005B6BC_main(temp_v0, arg6, 4);
    }
    if (D_801011D0_name_81 != 0) {
        func_8005E1A8_main(temp_v0, D_801011D0_name_81);
    }
    func_8005B43C_main(temp_v0, arg1, -1, -1);
    if (arg0 == -1) {
        func_80061388_main(temp_v0);
    } else {
        func_80061388_main(temp_v0);
    }

    func_800EAB6C_name_81(temp_v0, GwSystem.current_player_index);
}

void func_800EB49C_name_81(s16 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    func_800EB2BC_name_81(arg0, arg1, arg2, arg3, arg4, arg5, arg6, -1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB4DC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB530_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB58C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB5E8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB658_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/D28F0", func_800EB664_name_81);
