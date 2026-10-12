#include "common.h"
#include "libultra.h"

extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32);

extern u8 *D_800D5554_main;
extern s32 D_800CE174_main;
extern s32 D_800D6A8C_main;
extern s32 D_800CC43C_main;
extern s32 D_800D1FC8_main;

void osInitRdb(u8 *sendBuf, u32 sendSize) {
    register u32 int_disabled;

    sendSize >>= 2;

    if (((u32)sendBuf & 3) != 0) {
        sendBuf = (u8 *)(((u32)sendBuf & 3) + 4);
        sendSize--;
    }

    int_disabled = __osDisableInt();

    D_800D5554_main = sendBuf;
    D_800CE174_main = sendSize;
    D_800D6A8C_main = 0;
    D_800CC43C_main = 0;
    D_800D1FC8_main = 0;

    __osRestoreInt(int_disabled);
}
