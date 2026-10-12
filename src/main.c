#include "common.h"
#include "malloc.h"
#include "siman.h"

    // /* A1E5C 800A125C 8008F1C0 */ .word gspF3DEX2_fifoTextStart
    // /* A1E60 800A1260 800A4C80 */ .word D_800A4C80_main
    // /* A1E64 800A1264 80090550 */ .word gspF3DEX2_NoN_fifoTextStart
    // /* A1E68 800A1268 800A50A0 */ .word D_800A50A0_main
    // /* A1E6C 800A126C 800918E0 */ .word 0x800918E0
    // /* A1E70 800A1270 800A54C0 */ .word D_800A54C0_main
    // /* A1E74 800A1274 80092A70 */ .word 0x80092A70
    // /* A1E78 800A1278 800A58D0 */ .word D_800A58D0_main
    // /* A1E7C 800A127C 80094330 */ .word 0x80094330
    // /* A1E80 800A1280 800A5C60 */ .word D_800A5C60_main
    // /* A1E84 800A1284 8008F1C0 */ .word gspF3DEX2_fifoTextStart
    // /* A1E88 800A1288 800A4C80 */ .word D_800A4C80_main
    // /* A1E8C 800A128C 80090550 */ .word gspF3DEX2_NoN_fifoTextStart
    // /* A1E90 800A1290 800A50A0 */ .word D_800A50A0_main
    // /* A1E94 800A1294 800918E0 */ .word 0x800918E0
    // /* A1E98 800A1298 800A54C0 */ .word D_800A54C0_main
    // /* A1E9C 800A129C 000003E8 */ .word 0x000003E8

// typedef struct UnkF3DEX2Data {

// }

extern s32 D_800A08B0_main;
extern void *D_800A1240_main[3];
extern void *D_800A124C_main[4]; //TODO: is this correct size?
extern void *D_800A125C_main;
extern s32 D_800A12A0_main;
extern u8 D_800CCF52_main;
extern OSMesgQueue D_800CCF38_main;
extern OSMesgQueue D_800CCF60_main;
extern s32 D_800D1F70_main;
extern u32 D_800D2094_main;

extern void func_8000E3C0_main(void);
void InitScheduler(s32, s32);
void func_8000EA10_main(void **arg1, s32 arg2, s32 arg3, u64 **arg4, s32 *arg5);
void HuProfInit(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u16 arg4);
void InitSI(void);
s16 InitController(s16 ch, s32 arg1);
void InitVibrator(void);
void dmaInit(void);
void FlushController(void);
void func_8004D814_main(void);
void func_8007D740_main(s32);
void func_8000F094_main(u32); // Set unk swap chain state
void func_8004D7D8_main(void);
s16 func_8004D6AC_main(u8 red, u8 green, u8 blue);
void HuPrcCall(s32 time);
void func_8004D6E8_main(s16);

#define TV_TYPE_NTSC 1
#define TV_TYPE_PAL 0
#define INTR_MESG_BUF_SIZE 256
#define OTHER_MESG_BUF_SIZE 8

void func_800354A0_main() {
    s32 iVar5;
    s32 stopLooping;

    OSMesg msg;
    OSMesg intrMesgBuf[INTR_MESG_BUF_SIZE + 4];
    OSMesg otherMesgBuf[OTHER_MESG_BUF_SIZE + 4];
    OSMesg *msgTempVar;

    iVar5 = 0;
    stopLooping = FALSE;

    if (osTvType == TV_TYPE_NTSC) {
        InitScheduler(2, 1);
    } else if (osTvType != TV_TYPE_NTSC) {
        stopLooping = FALSE;
        InitScheduler(0x1E, 1);
    } else {
        goto spinloop;
    }

    HuMemHeapInitPerm((void *)0x80140000, 0x1A0000);
    HuMemHeapInitTemp((void *)0x80128000, 0x18000);

    D_800CCF52_main = 3;

    func_8000EA10_main(D_800A1240_main, 3, 2, (void*)&D_800A124C_main, (void*)&D_800A125C_main);

    if (osTvType == TV_TYPE_PAL) {
        while (TRUE) {}
    }

    HuProfInit(0, 0x20, 0xD2, 0x20, 0xD4);
    InitSI();
    InitController(4, 1);
    InitVibrator();
    ContDataInit();
    dmaInit();

    DataInit((u32)mainfs_ROM_START);

    HuPrcSysInit();

    msgTempVar = &intrMesgBuf[4];
    osCreateMesgQueue(&D_800CCF38_main, msgTempVar, INTR_MESG_BUF_SIZE);
    AddSchedulerClient((void*)&intrMesgBuf, &D_800CCF38_main, 1); //TODO: (void*) cast
    msgTempVar = &otherMesgBuf[4];
    osCreateMesgQueue(&D_800CCF60_main, msgTempVar, OTHER_MESG_BUF_SIZE);
    AddSchedulerClient((void*)&otherMesgBuf, &D_800CCF60_main, 2); //TODO: (void*) cast

    FlushController();
    func_8007D740_main(2);
    func_8000F094_main(2);
    HuPrcCreate(func_8000E3C0_main, 1, 0, 0);

    while (!stopLooping) {
        if (osRecvMesg(&D_800CCF60_main, &msg, OS_MESG_NOBLOCK) != -1) {

            if (D_800D2094_main) // Mysteriously helpful, courtesy permuter.
            {}

            break;
        }

        osRecvMesg(&D_800CCF38_main, &msg, OS_MESG_BLOCK);
        switch ((s32)msg) {
            case 1: {
                s32 temp_s0;
                s16 temp_s1;

                if (D_800D2094_main - iVar5 >= 2) {
                    iVar5 = D_800D2094_main;
                    if (D_800A12A0_main < D_800CCF52_main) {
                        func_8004D7D8_main();
                        temp_s1 = func_8004D6AC_main(0xC8, 0, 0);
                        FlushController();
                        ContDataUpdate();
                        temp_s0 = D_800A08B0_main;
                        HuPrcCall(1);
                        if (temp_s0 != D_800A08B0_main) {
                            D_800A12A0_main++;
                        }
                        func_8004D6E8_main(temp_s1);
                        func_8004D814_main();
                    }
                }
            } break;

            case 777:
                D_800A12A0_main--;
                D_800D1F70_main++;
                break;

            case 2:
                stopLooping = TRUE;
                break;
        }
    }

spinloop:
    while (TRUE) {}
}

void func_800357AC_main(s16 count) {
    s16 i = 0;
    for (i = 0; i < count; i++) {
        memset(*(&D_800A1240_main[i]), 0, 0x25800); // sizeof(gZBuffer) ?
    }
}
