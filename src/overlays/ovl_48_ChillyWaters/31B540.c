#include "ChillyWaters.h"

typedef struct unkfunc_801059D0 {
    f32 unk0;
    f32 unk4;
    s16 unk8;
    s16 unkA;
    s32 imgSize; //may or may not include palette data and form header, unsure
    u32 unk10;
    Process* unk14;
} unkfunc_801059D0;

void func_80105A64_31B5D4_ChillyWaters(void);

void func_801059D0_31B540_ChillyWaters(s16 arg0, s16 arg1) {
    Process* process;
    unkfunc_801059D0* temp_v0;

    process = omAddPrcObj(func_80105A64_31B5D4_ChillyWaters, 0x3F00, 0x1000, 0);
    temp_v0 = HuMemAllocTag(sizeof(unkfunc_801059D0), 0x7918);
    process->user_data = temp_v0;
    temp_v0->unk14 = process;
    temp_v0->unk0 = arg0;
    temp_v0->unk4 = arg1;
}

void func_8010BCA4_3BF974_boardresult(void);
;
;
typedef struct ESprite3 {
    u8* rasterData; //is this actually correct?
    s16 unk4;
    s16 unk6;
} ESprite3; //unknown size

typedef struct ESprite2 {
    char unk_00[0x14];
    u16 unk_14;
    char unk_18[0x30];
    f32 unk_48;
    f32 unk_4C;
    char unk_50[0x34];
    ESprite3** unk_84;
} ESprite2; //unknown size

typedef struct ESprite {
    char unk_00[8];
    s16 unk_08;
    s16 unk_0A;
    s32 unk_0C;
    ESprite2* unk_10[4]; //unknown size
} ESprite; //unknown size

void func_800555E8_561E8(s32, s32, s32, s32, s32, s32);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B540", func_80105A64_31B5D4_ChillyWaters);

//from Ununnu's fork of my scratch:
//animate cracking of ice
// void func_80105A64_31B5D4_ChillyWaters(void) {
//     s32 sp24, sp2C, imgSize, temp_v0_9;
//     s16 temp_v0;
//     s16 temp_v0_2;
//     s16 temp_s6;
//     s16 i, j, k;
//     s16 temp_s7;
//     s16 var_s2;
//     s16 temp_v0_12;
//     f32 temp;
//     u8* var_a0;
//     u8* var_a1;
//     ESprite2* temp_v0_3;
//     ESprite3* temp_v0_4;
//     unkfunc_801059D0* temp_s3 = HuPrcCurrentGet()->user_data;
//     u8 sp18[] = {2, 2, 16, 6, 8, 6, 20, 4};
//     u8* temp_v0_5;
    
//     temp_v0 = func_8000B838_C438(0xB004A);
//     temp_s3->unk8 = temp_v0;

//     temp_v0_2 = HuSprGrpCreate(1, 0);
//     temp_s3->unkA = temp_v0_2;

//     func_80055024_55C24(temp_v0_2, 0, temp_v0, 0);
//     func_80054904_55504(temp_v0_2, 0, temp_s3->unk0, temp_s3->unk4);
//     HuSprAttrSet(temp_v0_2, 0, 0x5000U);
//     func_80055420_56020(temp_v0_2, 0, 0x20, 0xA0, 0x90);
//     func_800555E8_561E8(temp_v0_2, 0, 0x10, 0xC, 0x130, 0xE4);

//     temp_v0_3 = HuSprGet(temp_v0_2, 0);
//     temp_v0_4 = *temp_v0_3->unk_84;
//     //is temp_v0_4 a form file header?
//     temp_s6 = temp_v0_4->unk4; //width?
//     temp_s7 = temp_v0_4->unk6; //height?
//     temp_v0_5 = temp_v0_4->rasterData;
//     temp_s3->unk10 = temp_v0_5;

//     imgSize = (temp_s6 * temp_s7) / 2;
    
//     temp_s3->imgSize = HuMemAlloc(imgSize);
//     memset(temp_s3->imgSize, 0, imgSize);
//     (*temp_v0_3->unk_84)->rasterData = temp_s3->unkC;

//     var_s2 = 0;

//     for (i = 0; i < temp_s6 - 0x42;) {
//         temp = i * i;
//         for (j = 0; j < temp_s7; j++) {
//             temp_v0_9 = (i * temp_s6) / 2;
//             var_a1 = temp_v0_5 + temp_v0_9;
//             var_a0 = temp_v0_9 + temp_s3->unkC;
//             for (k = 0; k < temp_s6; k += 2) {
//                 if ((k - 0x42) * (k - 0x42) + (s16)(i - 0x2C) * (i - 0x2C) < temp) {
//                     *var_a0 = *var_a1;
//                 }
//                 var_a1++;
//                 var_a0++;
//             }
//         }
        
//         i = var_s2 + sp18[i & 7];
//         var_s2++;
//         //shouldn't it actually be this?
//         // var_s2 = var_s2 + sp18[i & 7];
//         // i++;
//         HuPrcSleep(2);
//     }

//     while (1) {
//         HuPrcVSleep();
//     }
// }

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B540", func_80105DB8_31B928_ChillyWaters);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_48_ChillyWaters/31B540", func_80105E20_31B990_ChillyWaters);