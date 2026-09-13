#include "common.h"
#include "common_structs.h"
#include "gameman.h"
#include "malloc.h"
#include "pad.h"
#include "process.h"
#include "game/object.h"
#include "game/util.h"

extern str800D5298 D_800D5298_main;
extern void *D_800CCF38_main;
extern u8 D_800CCF78_main[];
extern f32 CZoomM[];
extern u16 D_800CD2F4_main;
extern s32 D_800CDD50_main;
extern Process *D_800D0448_main;
extern u8 D_800D09A8_main;
extern Process *D_800D170C_main;
extern u8 D_800D1710_main;
extern s16 D_800D1F36_main;
extern u16 D_800D4082_main;
extern Vec CenterM[];
extern u16 D_800D6A56_main;
extern Vec CRotM[];
extern u16 D_800A190C_main;
extern u16 D_800A190E_main;

void func_8000E3C0_main(void) {
    s32 i;

    HuPrcVSleep();
    func_8004F290_main();

    CRot.x = 325.0f;
    CRot.y = 0.0f;
    CRot.z = 0.0f;

    CZoom = 2250.0f;

    Center.x =
        Center.y =
            Center.z = CRot.y;

    for (i = 0; i < 4; i++) {
        CRotM[i].x = 325.0f;
        CRotM[i].y =
            CRotM[i].z = 0.0f;

        CZoomM[i] = 2250.0f;

        CenterM[i].x =
            CenterM[i].y =
                CenterM[i].z = 0.0f;
    }

    D_800D1710_main = 3;
    D_800D4082_main = 0x1000;
    D_800CD2F4_main = 0x2004;
    D_800D6A56_main = 0x180;
    WipeInit();
    func_8001A070_main(&HuMemMemoryAllocPerm, &HuMemMemoryFreePerm, D_800D4082_main, D_800CD2F4_main, D_800D6A56_main, D_800D1710_main);
    Hu3DCamInit(1);
    pfInit();
    func_80036380_main((u32)strings_japanese_ROM_START);
    D_800D1F36_main = 0;

    do {
        if (CheckControllerRead(D_800D1F36_main) != 0) {
            break;
        }
    } while (++D_800D1F36_main < 4);

    if (D_800D1F36_main == 4) {
        D_800D1F36_main = -1;
    }

    HuMemHeapAllocPermSizeGet();
    D_800D0448_main = HuPrcCreate(&func_8000E740_main, 0xF000, 0x3000, 0);
    HuPrcCreate(&func_8000E78C_main, 0x4000, 0x3000, 0);
    D_800D170C_main = HuPrcCreate(&func_8000E7B8_main, 0x1000, 0x3000, 0);

    {
        s32 temp_s0 = func_8004FDC0_main();
        GWInit();
        func_8000E978_main();
        func_80000EA8_main(&D_800D5298_main);
        SLCurBoxNoSet(0);
        func_80050800_main();
        if (temp_s0 != 0) {
            omOvlCallEx(slerror, 0, 0x82);
        } else {
            omOvlCallEx(ovl_boot, 0, 0x84);
        }
    }

    D_800D5298_main.unk8 = audio_mbf0_ROM_START;
    D_800D5298_main.unkC = audio_sbf0_ROM_START;
    D_800A190E_main = 0;
    D_800A190C_main = 0;
    D_800D5298_main.unk0 = 0x70418F;
    D_800D5298_main.unk10 = audio_fxd0_ROM_START;
    D_800D5298_main.unk28 = 1;
    D_800D5298_main.unk2C = 0;
    D_800D5298_main.unk14 = (void *)0x802E0000;
    D_800D5298_main.unk18 = 0x80000;
    D_800D5298_main.unk5C = 0x6E;
    D_800D5298_main.unk60 = 0;
    D_800D5298_main.unk64 = 0;
    D_800D5298_main.unk68 = D_800CDD50_main;
    D_800D5298_main.unk44 = 0x3C;
    func_800007FC_main(&D_800D5298_main);

    if ((D_800D09A8_main & 1) != 0) {
        func_80000F30_main(1);
    } else {
        func_80000F30_main(0);
    }

    HuPrcKill(HuPrcCurrentGet());

    while (TRUE) {
        HuPrcVSleep();
    }
}

void func_8000E740_main(void) {
    while (TRUE) {
        HuPrcVSleep();
        func_800224BC_main();
        func_800143F0_main();
        func_8001BF90_main(0x2000000, 0x3D0800);
        pfClsScr();
    }
}

void func_8000E78C_main(void) {
    while (TRUE) {
        HuPrcVSleep();
        omMain();
    }
}

void func_8000E7B8_main(void) {
    while (TRUE) {
        HuPrcVSleep();
        rand8();
        func_8000BA30_main(); // esprite
        func_80014A3C_main(2);
        func_8001B0B4_main(&D_800CCF38_main, 2); // hmfman
    }
}

/* Initialize Players */
void func_8000E804_main(void) {
    s32 i;

    for (i = 0; i < MB_MAX_PLAYERS; i++) {
        memset(&GwPlayer[i], 0, sizeof(GW_PLAYER));
        if (CheckControllerRead(i) != PAD_NOT_INSERTED) {
            D_800CCF78_main[i] = 0;
            GwPlayer[i].stat &= ~1;
        } else {
            D_800CCF78_main[i] = 1;
            GwPlayer[i].stat |= 1;
        }

        GwPlayer[i].pad = i;
        GwPlayer[i].coin = 10;
        GwPlayer[i].gameCoin = 0;
        GwPlayer[i].group = i;
        GwPlayer[i].cpu_difficulty = 0;
        GwPlayer[i].star = 0;
        GwPlayer[i].gamePrize = 0;
        GwPlayer[i].stats.prize.bluePrize = 0;
        GwPlayer[i].stats.prize.redPrize = 0;
        GwPlayer[i].stats.prize.hatenaPrize = 0;
    }
}

/* Initialize Game Save Data */
void func_8000E978_main(void) {
    func_8000E804_main();
    GWMgRecordSet(0, 0x64);
    GWMgRecordSet(1, 0xE10);
    GWMgRecordSet(2, 0xE10);
    GWMgRecordSet(3, 0x708);
    GWMgRecordSet(4, 0x3E8);
    GWMgRecordSet(5, 0xE10);
    GWMgRecordSet(6, 0xE10);
    GWMgRecordSet(7, 0xE10);
    GWMgRecordSet(8, 0);
    GWMgRecordSet(9, 0x1518);
}
