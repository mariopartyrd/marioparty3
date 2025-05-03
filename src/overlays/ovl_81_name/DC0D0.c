#include "common.h"
#include "ovl_81.h"

void func_800F4300_DC0D0_name_81(void) {
    D_80105400_ED1D0_name_81 = 0;
    D_80105404_ED1D4_name_81 = 0;
}

void func_800F4314_DC0E4_name_81(void) {
    while (D_80105400_ED1D0_name_81 != 0) {
        func_800F4584_DC354_name_81(D_80105400_ED1D0_name_81);
    }
}

UnkBoard4* func_800F4354_DC124_name_81(s16 arg0) {
    UnkBoard4* temp_v0;
    s32 i;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(UnkBoard4));
    if (temp_v0 != NULL) {
        D_80105404_ED1D4_name_81++;
        
        temp_v0->unk_00 = (void* ) D_80105400_ED1D0_name_81;
        temp_v0->unk_04 = NULL;
        
        if (D_80105400_ED1D0_name_81 != NULL) {
            D_80105400_ED1D0_name_81->unk_04 = temp_v0;
        }
        
        D_80105400_ED1D0_name_81 = temp_v0;
        temp_v0->unk_08 = arg0;
        
        temp_v0->unk_0C = HuMemMemoryAllocTemp(arg0 * 2);
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_0C[i] = -1;
        }
        
        temp_v0->unk_10 = HuMemMemoryAllocTemp(arg0 * 4);
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_10[i] = 1.0f;
        }
    
        temp_v0->unk_14 = HuMemMemoryAllocTemp(arg0 * 4);
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_14[i] = 1.0f;
        }
        
        temp_v0->unk_18 = HuMemMemoryAllocTemp(arg0 * 2);
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_18[i] = 0;
        }

        temp_v0->unk_1C = HuMemMemoryAllocTemp(arg0 * 2);
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_1C[i] = 0;
        }

    }
    return temp_v0;
}

UnkBoard4* func_800F4528_DC2F8_name_81(s16 arg0, s16 arg1) {
    UnkBoard4* temp_v0;

    temp_v0 = func_800F4354_DC124_name_81(arg0);
    if (temp_v0 != NULL) {
        temp_v0->unk_0A = func_8005279C_5339C(arg0, arg1);
    }
    return temp_v0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DC0D0", func_800F4584_DC354_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DC0D0", func_800F466C_DC43C_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/DC0D0", func_800F46BC_DC48C_name_81);
