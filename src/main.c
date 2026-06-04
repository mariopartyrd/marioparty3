#include "common.h"

extern s32 D_800A08B0_A14B0;
extern void *D_800A1240_A1E40[3];
extern void *D_800A124C_A1E4C;
extern void *D_800A125C_A1E5C;
extern s32 D_800A12A0_A1EA0;
extern u8 D_800CCF52_CDB52;
extern OSMesgQueue D_800CCF38_CDB38;
extern OSMesgQueue D_800CCF60_CDB60;
extern s32 D_800D1F70_D2B70;
extern u32 D_800D2094_D2C94;

extern void func_8000E3C0_EFC0(void);

#define TV_TYPE_NTSC 1
#define TV_TYPE_PAL 0
#define INTR_MESG_BUF_SIZE 256
#define OTHER_MESG_BUF_SIZE 8

void func_800354A0_360A0() {
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

    D_800CCF52_CDB52 = 3;

    func_8000EA10_F610(&D_800A1240_A1E40, 3, 2, &D_800A124C_A1E4C, &D_800A125C_A1E5C);

    if (osTvType == TV_TYPE_PAL) {
        while (TRUE) {}
    }

    HuProfInit(0, 0x20, 0xD2, 0x20, 0xD4);
    InitSI();
    InitController(4, 1);
    InitVibrator();
    ContDataInit();
    dmaInit();

    DataInit(&mainfs_ROM_START);

    HuPrcSysInit();

    msgTempVar = &intrMesgBuf[4];
    osCreateMesgQueue(&D_800CCF38_CDB38, msgTempVar, INTR_MESG_BUF_SIZE);
    AddSchedulerClient(&intrMesgBuf, &D_800CCF38_CDB38, 1);
    msgTempVar = &otherMesgBuf[4];
    osCreateMesgQueue(&D_800CCF60_CDB60, msgTempVar, OTHER_MESG_BUF_SIZE);
    AddSchedulerClient(&otherMesgBuf, &D_800CCF60_CDB60, 2);

    FlushController();
    func_8007D740_7E340(2);
    func_8000F094_FC94(2);
    HuPrcCreate(func_8000E3C0_EFC0, 1, 0, 0);

    while (!stopLooping) {
        if (osRecvMesg(&D_800CCF60_CDB60, &msg, OS_MESG_NOBLOCK) != -1) {

            if (D_800D2094_D2C94) // Mysteriously helpful, courtesy permuter.
            {}

            break;
        }

        osRecvMesg(&D_800CCF38_CDB38, &msg, OS_MESG_BLOCK);
        switch ((s32)msg) {
            case 1: {
                s32 temp_s0;
                s16 temp_s1;

                if (D_800D2094_D2C94 - iVar5 >= 2) {
                    iVar5 = D_800D2094_D2C94;
                    if (D_800A12A0_A1EA0 < D_800CCF52_CDB52) {
                        func_8004D7D8_4E3D8();
                        temp_s1 = func_8004D6AC_4E2AC(0xC8, 0, 0);
                        FlushController();
                        ContDataUpdate();
                        temp_s0 = D_800A08B0_A14B0;
                        HuPrcCall(1);
                        if (temp_s0 != D_800A08B0_A14B0) {
                            D_800A12A0_A1EA0++;
                        }
                        func_8004D6E8_4E2E8(temp_s1);
                        func_8004D814_4E414();
                    }
                }
            } break;

            case 777:
                D_800A12A0_A1EA0--;
                D_800D1F70_D2B70++;
                break;

            case 2:
                stopLooping = TRUE;
                break;
        }
    }

spinloop:
    while (TRUE) {}
}

void func_800357AC_363AC(s16 count) {
    s16 i = 0;
    for (i = 0; i < count; i++) {
        memset(*(&D_800A1240_A1E40[i]), 0, 0x25800); // sizeof(gZBuffer) ?
    }
}
