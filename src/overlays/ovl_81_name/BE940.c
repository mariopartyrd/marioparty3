#include "common.h"
#include "ovl_81.h"

typedef struct UnkBE940 {
/* 0x00 */ s16 unk_00;
/* 0x02 */ char unk_02;
/* 0x04 */ Object* unk_04;
} UnkBE940; //sizeof 0x08

typedef struct UnkBE940_2 {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 unk_02;
/* 0x04 */ s32 unk_04;
/* 0x08 */ s32 unk_08;
/* 0x0C */ s16 unk_0C;
/* 0x0E */ char unk_0E[0x5A];
/* 0x68 */ s32 unk_68;
} UnkBE940_2; //sizeof 0x6C

typedef struct UnkBE940_3 {
/* 0x00 */ s16 unk_00;
/* 0x02 */ s16 unk_02;
/* 0x04 */ UnkBE940** unk_04;
/* 0x08 */ Process* unk_08;
} UnkBE940_3; //sizeof 0x0C

void* func_800D6B70_BE940_name_81(s32 arg0) {
    s32 sp10[3] = {0x17, 0x18, 0x19};
    UnkBE940* temp_v0;
    Object* temp_v0_2;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(UnkBE940));
    temp_v0->unk_00 = 0;
    temp_v0_2 = func_800D8010_BFDE0_name_81(sp10[arg0], 0);
    temp_v0->unk_04 = temp_v0_2;
    func_8001C258_1CE58(temp_v0_2->omObj1->model[0], 0x180, 0);
    func_8001C8E4_1D4E4(temp_v0->unk_04->omObj1->model[0], 0x1400);
    func_8001C448_1D048(temp_v0->unk_04->omObj1->model[0]);
    func_800D8944_C0714_name_81(temp_v0->unk_04);
    return temp_v0;
}

void func_800D6C3C_BEA0C_name_81(UnkBE940* arg0) {
    func_800D8F3C_C0D0C_name_81(arg0->unk_04);
    HuMemMemoryFreeTemp(arg0);
}

UnkBE940_2* func_800D6C6C_BEA3C_name_81(void) {
    UnkBE940_2* temp_v0;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(UnkBE940_2));
    temp_v0->unk_00 = 0;
    temp_v0->unk_02 = 0;
    temp_v0->unk_04 = 0;
    temp_v0->unk_08 = 0;
    temp_v0->unk_0C = 0;
    temp_v0->unk_68 = 0;
    return temp_v0;
}

void func_800D6CA0_BEA70_name_81(UnkBE940_3* arg0) {
    UnkBE940** var_s1;
    s32 i;

    if (arg0->unk_02 != 0){
        for (var_s1 = arg0->unk_04, i = 0; i < arg0->unk_02; var_s1++, i++) {
            func_800D6C3C_BEA0C_name_81(*var_s1);
        }
        HuMemMemoryFreeTemp(arg0->unk_04);
    }
    
    if (arg0->unk_08 != NULL) {
        omDelPrcObj(arg0->unk_08);
    }
    
    HuMemMemoryFreeTemp(arg0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D6D2C_BEAFC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/BE940", func_800D6E00_BEBD0_name_81);

//TODO: is arg0 typed correctly?
UnkBE940* func_800D6EC8_BEC98_name_81(UnkBE940_3* arg0, s16 arg1) {
    return arg0->unk_04[arg1];
}
