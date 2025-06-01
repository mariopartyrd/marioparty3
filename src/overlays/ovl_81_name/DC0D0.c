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
        
        temp_v0->unk_0C = HuMemMemoryAllocTemp(arg0 * sizeof(*temp_v0->unk_0C));
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_0C[i] = -1;
        }
        
        temp_v0->unk_10 = HuMemMemoryAllocTemp(arg0 * sizeof(*temp_v0->unk_10));
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_10[i] = 1.0f;
        }
    
        temp_v0->unk_14 = HuMemMemoryAllocTemp(arg0 * sizeof(*temp_v0->unk_14));
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_14[i] = 1.0f;
        }
        
        temp_v0->unk_18 = HuMemMemoryAllocTemp(arg0 * sizeof(*temp_v0->unk_18));
        for (i = 0; i < arg0; i++) {
            temp_v0->unk_18[i] = 0;
        }

        temp_v0->unk_1C = HuMemMemoryAllocTemp(arg0 * sizeof(*temp_v0->unk_1C));
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
        temp_v0->unk_0A = HuSprGrpCreate(arg0, arg1);
    }
    return temp_v0;
}

void func_800F4584_DC354_name_81(UnkBoard4* arg0) {
    s32 i;

    if (arg0->unk_00 != NULL) {
        arg0->unk_00->unk_04 = arg0->unk_04;
    }
    
    if (arg0->unk_04 != NULL) {
        arg0->unk_04->unk_00 = arg0->unk_00;
    } else {
        D_80105400_ED1D0_name_81 = arg0->unk_00;
    }
    
    for (i = 0; i < arg0->unk_08; i++) {
        if (arg0->unk_0C[i] >= 0) {
            func_80055670_56270(arg0->unk_0C[i]);
        }
    }
    
    func_800525C8_531C8(arg0->unk_0A);
    HuMemMemoryFreeTemp(arg0->unk_18);
    HuMemMemoryFreeTemp(arg0->unk_1C);
    HuMemMemoryFreeTemp(arg0->unk_10);
    HuMemMemoryFreeTemp(arg0->unk_14);
    HuMemMemoryFreeTemp(arg0->unk_0C);
    HuMemMemoryFreeTemp(arg0);
    D_80105404_ED1D4_name_81 -= 1;
}

void func_800F466C_DC43C_name_81(UnkBoard4* arg0, s16 arg1, s16 arg2, s16 arg3) {
    arg0->unk_18[arg1] = arg2;
    arg0->unk_1C[arg1] = arg3;
    func_80054904_55504(arg0->unk_0A, arg1, arg2, arg3);
}

void func_800F46BC_DC48C_name_81(UnkBoard4* arg0, s16 arg1, f32 arg2, f32 arg3) {
    arg0->unk_10[arg1] = arg2;
    arg0->unk_14[arg1] = arg3;
    HuSprScaleSet(arg0->unk_0A, arg1, arg2, arg3);
}
