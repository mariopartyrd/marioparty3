#include "common.h"

typedef s16 Array2D[2][18];

void func_8000BBFC_main(u16, s16);
void func_8000BC48_main(u16, s32);
void func_8000BCC8_main(u16, s32);
void func_8000BE5C_main(u16, f32, f32);
void func_8000C184_main(u16);
void func_8001ACDC_main(s16);
void Hu3DModelRotSet(s16, f32, f32, f32);
void Hu3DModelScaleSet(s16, f32, f32, f32);
void func_8001C258_main(s16, s32, s32);
void HuSprKill(s16);
void func_8010B82C_msetup(s32);
void func_8010B858_msetup();
void func_8010B998_msetup();
s32 func_8010D684_msetup(s16, s16 *);
void func_8010DDD8_msetup(void *);
omObjData *func_8010DE38_msetup(s32, s32, s32);
void func_8010E4BC_msetup(Array2D *, s32, s32);
void func_8010E4D8_msetup(Array2D *, s32);
void func_8010E8C8_msetup(Array2D *, s32, s32, f32, f32, f32, f32, s32);
void func_8010F320_msetup(s32, s32, s16, s16);
extern s32 D_80119420_msetup;
extern s32 D_80119E94_msetup[];
extern s32 D_80119EAC_msetup[];
extern s32 D_80119EC4_msetup[];
extern s32 D_80119EE0_msetup[];
extern s16 D_8011A938_msetup;
extern s16 D_8011A948_msetup;
extern u8 D_8011AA45_msetup; // board index chosen
typedef struct UnkStarLift {
    char unk_00[0x04];
    s16 unk4;
} UnkStarLift;

s32 _CheckFlag(s32);             /* extern */
s16 func_80055810_main(void *); /* extern */

s32 func_80113ED4_msetup(UnkStarLift *arg0);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010ACC0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010AF40_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010B1F4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010B388_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010B4B8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010B588_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010B5D0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010B82C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010B858_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010B8E0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010B968_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010B998_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010B9B8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010BA10_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010BA3C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010BA6C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010BBF4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010BC18_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010BE8C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010BEB0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010BEF8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010CAF0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010CC70_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010CD14_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010CE8C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010D060_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010D094_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010D0C8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010D234_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010D4DC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010D5EC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010D684_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010D6D0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010DAC4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010DDD8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010DE38_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010E00C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010E044_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010E09C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010E21C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010E32C_msetup);

void func_8010E32C_msetup(Array2D *, s32, s32, s32);

void func_8010E4BC_msetup(Array2D *arg0, s32 arg1, s32 arg2) {
    func_8010E32C_msetup(arg0, arg1, arg2, 1);
}

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010E4D8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010E52C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010E8C8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010EB94_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010F2BC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010F2F4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010F320_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010F33C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010F43C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010F4E0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8010F87C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_8011035C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80110954_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80111650_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A6D8_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A6E4_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A6F0_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A6FC_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A708_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A714_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A720_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A72C_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A738_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A744_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A74C_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A754_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A75C_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A764_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A76C_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A774_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A77C_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A784_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A78C_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A794_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A79C_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A7A4_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A7AC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80112804_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80112E08_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80112F5C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_801132C4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_801138F8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80113DEC_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80113E20_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80113E54_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80113E88_msetup);

s32 func_80113ED4_msetup(UnkStarLift *arg0) {
#define MODE_PARTY 0
#define MODE_DUEL 1
#define FLAG_WALUIGIS_ISLAND 0x31
#define FLAG_BACKTRACK 0x30
    Array2D sp20;
    s16 unk_68;
    s32 *mainFSArray;
    s32 boardCountMaxCopy;
    f32 var_f20;
    void *temp_v0_4;
    omObjData *temp_s5;
    s16 prevBoardIndex;
    s16 backgroundEspriteSlot;
    s16 var_s6;
    s32 pad;
    s32 var_fp;
    s32 boardCountMax;
    s32 *boardDescriptionId;
    s16 curBoardIndex;
    s16 temp;
    s32 i;
    f32 tempFloat;

    boardDescriptionId = NULL;
    mainFSArray = NULL;
    curBoardIndex = D_8011AA45_msetup;
    arg0->unk4 = 0;
    backgroundEspriteSlot = -1;
    var_s6 = -1;
    boardCountMax = 6;
    var_fp = 70;
    tempFloat = 1.0f;

    switch (D_8011A938_msetup) { // current mode
        case MODE_PARTY:
            boardDescriptionId = D_80119EC4_msetup;
            mainFSArray = D_80119E94_msetup; // party mode board backgrounds
            tempFloat = 1.0f;
            var_fp = 74;
            boardCountMax = 5;
            if (_CheckFlag(FLAG_WALUIGIS_ISLAND) != 0) {
                boardCountMax = 6;
            }
            break;
        case MODE_DUEL:
            boardDescriptionId = D_80119EE0_msetup;
            mainFSArray = D_80119EAC_msetup; // duel mode board backgrounds
            var_fp = 74;
            boardCountMax = 5;
            if (_CheckFlag(FLAG_BACKTRACK) != 0) {
                boardCountMax = 6;
            }
            break;
    }

    func_8010B998_msetup();
    func_8010E4BC_msetup(&sp20, 2, 0);
    func_8010E4D8_msetup(&sp20, 2);
    temp = sp20[0][12];
    temp_s5 = func_8010DE38_msetup(0x40, 0x100, 0x48);
    func_8010B82C_msetup(boardDescriptionId[6]);
    func_8010B858_msetup();
    HuAudFXPlay(0x2D9);
    func_8010E8C8_msetup(&sp20, 2, 0xF, 720.0f, 565.0f, 0.1f, 1.0f, 1);
    func_8001C258_main(sp20[1][12], 4, 4);

    for (var_f20 = 0.0f; var_f20 < 180.0f; var_f20 += (180.0f / 7.0f)) {
        Hu3DModelRotSet(temp, 0, var_f20, 0);
        HuPrcVSleep();
    }

    Hu3DModelRotSet(temp, 0, 180.0f, 0);
    temp_s5->work[0] = 1;
    temp_s5->work[1] = 36;

    for (var_f20 = 1.0f; var_f20 < 2.5f; var_f20 += (3.0f / 14.0f)) {
        Hu3DModelScaleSet(temp, var_f20, var_f20, var_f20);
        HuPrcVSleep();
    }

    Hu3DModelScaleSet(temp, 2.5f, 2.5f, 2.5f);
    prevBoardIndex = -1;
    pad = func_8010D684_msetup(D_8011A948_msetup, &unk_68);
    boardCountMaxCopy = boardCountMax;
    while (1) {
        pad = func_8010D684_msetup(D_8011A948_msetup, &unk_68);
        if (pad & A_BUTTON) {
            HuAudFXPlay(2);
            break;
        }
        if (pad & B_BUTTON) {
            HuAudFXPlay(4);
            curBoardIndex = -1;
            break;
        }
        if (pad & (U_JPAD | R_JPAD)) {
            curBoardIndex++;
            curBoardIndex = (boardCountMaxCopy <= curBoardIndex) ? 0 : curBoardIndex;
            HuAudFXPlay(1);
            temp_s5->work[0] = 4;
        } else {
            if (pad & (D_JPAD | L_JPAD)) {
                if (--curBoardIndex < 0) {
                    curBoardIndex = boardCountMax - 1;
                }
                HuAudFXPlay(1);
                temp_s5->work[0] = 3;
            }
        }
        // check if background image should update
        if (prevBoardIndex != curBoardIndex) {
            if (backgroundEspriteSlot >= 0) {
                for (i = 255; i > 0; i -= (255 / 5)) {
                    func_8000BBFC_main(backgroundEspriteSlot, i);
                    HuPrcVSleep();
                }
                func_8000C184_main(backgroundEspriteSlot);
                HuSprKill(var_s6);
            }
            temp_v0_4 = DataReadTemp(mainFSArray[curBoardIndex]);
            var_s6 = func_80055810_main(temp_v0_4);
            DataCloseTemp(temp_v0_4);
            backgroundEspriteSlot = InitEspriteSlot(var_s6, 0, 1);
            func_8000BC48_main(backgroundEspriteSlot, 0x1000);
            func_8000BCC8_main(backgroundEspriteSlot, 1);
            func_8000BBD4_main(backgroundEspriteSlot, 0xA0, var_fp);
            func_8000BE5C_main(backgroundEspriteSlot, tempFloat, tempFloat);
            for (i = 0; i < 255; i += (255 / 5)) {
                func_8000BBFC_main(backgroundEspriteSlot, i);
                HuPrcVSleep();
            }
            func_8000BBFC_main(backgroundEspriteSlot, 0xFF);
            prevBoardIndex = curBoardIndex;
            func_8010B82C_msetup(boardDescriptionId[curBoardIndex]);
        }
        HuPrcVSleep();
    }

    arg0->unk4 = curBoardIndex;
    if (curBoardIndex >= 0) {
        D_8011AA45_msetup = curBoardIndex;
    }

    temp_s5->work[0] = 2;
    temp_s5->work[1] = 17;

    for (i = 255; i > 0; i -= (255 / 5)) {
        func_8000BBFC_main(backgroundEspriteSlot, i);
        HuPrcVSleep();
    }

    func_8000BBFC_main(backgroundEspriteSlot, 0);

    for (var_f20 = 2.5f; var_f20 > 1.0f; var_f20 += -(3.0f / 14.0f)) {
        Hu3DModelScaleSet(temp, var_f20, var_f20, var_f20);
        HuPrcVSleep();
    }

    Hu3DModelScaleSet(temp, 1.0f, 1.0f, 1.0f);

    for (var_f20 = 180.0f; var_f20 < 360.0f; var_f20 += (180.0f / 7.0f)) {
        Hu3DModelRotSet(temp, 0, var_f20, 0);
        HuPrcVSleep();
    }

    Hu3DModelRotSet(temp, 0, 0.0f, 0);
    func_8001C258_main(sp20[1][12], 4, 0);
    HuAudFXPlay(0x2DA);
    func_8010E8C8_msetup(&sp20, 2, 7, 360.0f, 400.0f, 1.0f, 0.1f, 1);

    if (curBoardIndex >= 0) {
        func_8010F320_msetup(D_80119420_msetup, 0, sp20[0][12], -1);
        func_8010F320_msetup(D_80119420_msetup, 2, backgroundEspriteSlot, var_s6);
        func_8001ACDC_main(sp20[1][12]);
    } else {
        for (i = 0; i < 2; i++) {
            func_8001ACDC_main(sp20[i][12]);
        }
        func_8000C184_main(backgroundEspriteSlot);
        HuSprKill(var_s6);
    }
    func_8010DDD8_msetup(temp_s5);
    return 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_801145D0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80114AA0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_801150A0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_801152C4_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_801157B8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80115A9C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80115E78_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A7D8_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A7E0_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A7E8_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A7F0_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A7F8_msetup);

INCLUDE_RODATA("asm/nonmatchings/overlays/msetup/506F20", D_8011A800_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80115EE0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_801167B8_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80116FE0_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80117818_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80117820_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80117910_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80117A3C_msetup);

INCLUDE_ASM("asm/nonmatchings/overlays/msetup/506F20", func_80118D48_msetup);
