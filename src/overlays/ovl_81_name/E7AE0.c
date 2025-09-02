#include "common.h"
#include "ovl_81.h"

#define UNK_ARR_SIZE 4

extern s16 D_80101B40_E9910_name_81[UNK_ARR_SIZE][2];
extern s16 D_80101B60_E9930_name_81[UNK_ARR_SIZE][2];
extern UnkBoard4* D_80105504_ED2D4_name_81;
extern s16 D_80105508_ED2D8_name_81[UNK_ARR_SIZE][2];
void func_800FFD10_E7AE0_name_81(omObjData*);
extern s16 D_80101B50_E9920_name_81[UNK_ARR_SIZE][2];
extern f32 D_80101B70_E9940_name_81[UNK_ARR_SIZE];
extern omObjData* D_80105500_ED2D0_name_81;
UnkBoard4* func_800F4528_DC2F8_name_81(s16, s16);
void func_800F4584_DC354_name_81(UnkBoard4*);
void func_80100124_E7EF4_name_81(s32, s32);
extern s32 D_80105518_ED2E8_name_81;

void func_800FFD10_E7AE0_name_81(omObjData* obj) {
    s32 i;

    for (i = 0; i < UNK_ARR_SIZE; i++) {
        D_80105508_ED2D8_name_81[i][0] += D_80101B60_E9930_name_81[i][0];
        D_80105508_ED2D8_name_81[i][1] += D_80101B60_E9930_name_81[i][1];
        if (D_80101B60_E9930_name_81[i][0] < 0) {
            if (D_80105508_ED2D8_name_81[i][0] < D_80101B40_E9910_name_81[i][0]) {
                D_80105508_ED2D8_name_81[i][0] = D_80101B40_E9910_name_81[i][0];
            }
        }

        if (D_80101B60_E9930_name_81[i][0] > 0) {
            if (D_80105508_ED2D8_name_81[i][0] > D_80101B40_E9910_name_81[i][0]) {
                D_80105508_ED2D8_name_81[i][0] = D_80101B40_E9910_name_81[i][0];
            }
        }

        if (D_80101B60_E9930_name_81[i][1] < 0) {
            if (D_80105508_ED2D8_name_81[i][1] < D_80101B40_E9910_name_81[i][1]) {
                D_80105508_ED2D8_name_81[i][1] = D_80101B40_E9910_name_81[i][1];
            }
        }

        if (D_80101B60_E9930_name_81[i][1] > 0) {
            if (D_80105508_ED2D8_name_81[i][1] > D_80101B40_E9910_name_81[i][1]) {
                D_80105508_ED2D8_name_81[i][1] = D_80101B40_E9910_name_81[i][1];
            }
        }
        func_80054904_55504(D_80105504_ED2D4_name_81->unk_0A, i, D_80105508_ED2D8_name_81[i][0], D_80105508_ED2D8_name_81[i][1]);
    }
}

UnkBoard4* func_800FFEEC_E7CBC_name_81(void) {
    UnkBoard4* temp_v0;
    omObjData* temp_v0_2;
    void* temp_s4;
    s32 i;

    temp_v0 = func_800F4528_DC2F8_name_81(4, 0);
    D_80105504_ED2D4_name_81 = temp_v0;
    temp_s4 = DataRead(0x001301D4);
    
    for (i = 0; i < 4; i++) {
        temp_v0->unk_0C[i] = func_80055810_56410(temp_s4);
        func_80055024_55C24(temp_v0->unk_0A, i, temp_v0->unk_0C[i], 0);
        HuSprPriSet(temp_v0->unk_0A, i, 0);
        HuSprAttrSet(temp_v0->unk_0A, i, 0x8000);
        func_80054904_55504(temp_v0->unk_0A, i, D_80101B50_E9920_name_81[i][0], D_80101B50_E9920_name_81[i][1]);
        D_80105508_ED2D8_name_81[i][0] = D_80101B50_E9920_name_81[i][0];
        D_80105508_ED2D8_name_81[i][1] = D_80101B50_E9920_name_81[i][1];
        func_800552DC_55EDC(temp_v0->unk_0A, i, D_80101B70_E9940_name_81[i]);
    }

    DataClose(temp_s4);
    temp_v0_2 = omAddObj(0x1000, 0, 0, -1, func_800FFD10_E7AE0_name_81);
    D_80105500_ED2D0_name_81 = temp_v0_2;
    omSetStatBit(temp_v0_2, 0x20);
    return temp_v0;
}

void func_80100070_E7E40_name_81(UnkBoard4* arg0) {
    omDelObj(D_80105500_ED2D0_name_81);
    func_800F4584_DC354_name_81(arg0);
}

void func_801000A4_E7E74_name_81(UnkBoard4* arg0, u16 arg1) {
    s32 var_v0;
    s32 i;

    for (i = 0; i < 4; i++) {
        var_v0 = arg1 >> i;
        if (var_v0 & 1) {
            HuSprAttrSet(arg0->unk_0A, i, 0x8000);
        } else {
            HuSprAttrReset(arg0->unk_0A, i, 0x8000);
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E7AE0", func_80100124_E7EF4_name_81);

//TODO: what is this?
void func_801003C8_E8198_name_81(void) {
    s32 counter = 0x20;
    
    while (1) {
        s32 data = D_80105518_ED2E8_name_81;
        s32 adjusted = (counter < 0) ? (counter + 0x1F) : counter;
        func_80100124_E7EF4_name_81(data, adjusted >> 5);
        
        counter++;
        if (counter >= 0x40) {
            counter = 0; 
        }
        
        HuPrcVSleep();
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E7AE0", func_80100420_E81F0_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E7AE0", func_801005DC_E83AC_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E7AE0", func_80100604_E83D4_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E7AE0", func_801007C4_E8594_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E7AE0", func_80100864_E8634_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E7AE0", func_80100890_E8660_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E7AE0", func_801008E8_E86B8_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E7AE0", func_80100CA0_E8A70_name_81);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_81_name/E7AE0", func_80100CEC_E8ABC_name_81);
