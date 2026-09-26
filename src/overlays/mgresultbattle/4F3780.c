#include "common.h"
#include "game/gamework_data.h"
#include "game/object.h"
#include "game/wipe.h"
#include "../ovl_80_shared_board/FA250.h"

void func_80105E0C_mgresultbattle(void);
void func_80105EF4_mgresultbattle(void);
void func_801060A4_mgresultbattle(void);
void func_80106660_mgresultbattle(void);
void func_80106BA0_mgresultbattle(void);
void func_80107400_mgresultbattle(void);
void func_80107D10_mgresultbattle(void);
void func_80108130_mgresultbattle(void);
void MBBackCreate(s32, s32);
void func_80105CAC_mgresultbattle(omObjData *);
void func_80105E64_mgresultbattle(omObjData *);
void func_80105F50_mgresultbattle(void);

extern u8 D_80108F8C_mgresultbattle[4];
extern s32 D_80108908_mgresultbattle[];

void func_801059A0_mgresultbattle(void) {
    s16 var_a0_2;
    s16 var_a1;
    s16 i;
    s16 j;

    var_a1 = 0;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < MB_MAX_PLAYERS; j++) {
            if (i != GwPlayer[j].group) {
                continue;
            }
            D_80108F8C_mgresultbattle[var_a1] = j;
            var_a1++;

            if (var_a1 >= 4) {
                break;
            }
        }
        if (var_a1 >= 4) {
            break;
        }
    }
    func_800142A0_main(0x78);
    omInitObjMan(0x1E, 0x1E);
    func_8000B690_main(1);
    ScissorSet(0, 0.0f, 0.0f, 320.0f, 240.0f);
    ViewportSet(0, 640.0f, 480.0f, 511.0f, 640.0f, 480.0f, 511.0f);
    Hu3DCamSetPerspective(0, 30.0f, 80.0f, 8000.0f);
    omSetStatBit(omAddObj(0x7FDA, 0, 0, -1, omOutView), 0xA0);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);

    for (var_a0_2 = 0, i = 0; i < MB_MAX_PLAYERS; i++) {
        if (GwPlayer[i].bonusCoin == 3) {
            var_a0_2++;
        }
    }

    if (var_a0_2 >= 4) {
        func_80037258_main();
        MBBackKill();
        MBBackClose();
        omOvlReturnEx(1);
        return;
    }
    func_801060A4_mgresultbattle();
    omAddPrcObj(func_80108130_mgresultbattle, 0x1001, 0x2000, 0);
    omAddPrcObj(func_80107400_mgresultbattle, 0x1001, 0x2000, 0);
    omAddPrcObj(func_80107D10_mgresultbattle, 0x1001, 0x2000, 0);
    omAddPrcObj(func_80106660_mgresultbattle, 0x1001, 0x2000, 0);
    omAddPrcObj(func_80106BA0_mgresultbattle, 0x1001, 0x2000, 0);
    omAddObj(0, 0, 0, -1, func_80105CAC_mgresultbattle);
    omAddObj(0, 0, 0, -1, func_80105E64_mgresultbattle);
    func_80105EF4_mgresultbattle();
    func_80105E0C_mgresultbattle();
    WipeCreateIn(0xFF, 0x10);
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80105CAC_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80105E0C_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80105E64_mgresultbattle);

void func_80105EF4_mgresultbattle(void) {
    GW_SYSTEM *system = &GwSystem;

    func_800E6630_shared_board((u32)hvq_data_ROM_START);

    if (!(system->playMode & 2)) {
        MBBackCreate(D_80108908_mgresultbattle[system->current_board_index], 0);
    } else {
        MBBackCreate(0x17, 0);
    }
    func_80105F50_mgresultbattle();
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80105F50_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80105F78_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_801060A4_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80106660_mgresultbattle);

void func_80106908_mgresultbattle(void) {
}

void func_80106910_mgresultbattle(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80106918_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_801069FC_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80106BA0_mgresultbattle);

void func_80106E98_mgresultbattle(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80106EA0_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80106ED0_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80107260_mgresultbattle);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultbattle/4F3780", D_80108908_mgresultbattle);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultbattle/4F3780", D_80108920_mgresultbattle);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultbattle/4F3780", D_801089A0_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80107400_mgresultbattle);

void func_801075EC_mgresultbattle(void) {
}

void func_801075F4_mgresultbattle(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_801075FC_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80107610_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80107B5C_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80107BDC_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80107C44_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80107CA4_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80107D10_mgresultbattle);

void func_80107F94_mgresultbattle(void) {
}

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultbattle/4F3780", D_801089C0_mgresultbattle);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultbattle/4F3780", D_801089D0_mgresultbattle);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultbattle/4F3780", D_801089D4_mgresultbattle);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultbattle/4F3780", D_801089D8_mgresultbattle);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultbattle/4F3780", D_80108A00_mgresultbattle);

INCLUDE_RODATA("asm/nonmatchings/overlays/mgresultbattle/4F3780", D_80108A10_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80107F9C_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_801080A0_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80108130_mgresultbattle);

void func_8010829C_mgresultbattle(void) {
}

void func_801082A4_mgresultbattle(void) {
}

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_801082AC_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_801082C0_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80108510_mgresultbattle);

INCLUDE_ASM("asm/nonmatchings/overlays/mgresultbattle/4F3780", func_80108858_mgresultbattle);
