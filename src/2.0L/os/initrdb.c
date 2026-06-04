#include "common.h"
#include "libultra.h"

extern u32 __osDisableInt(void);
extern void __osRestoreInt(u32);

extern u8 *D_800D5554_D6154;
extern s32 D_800CE174_CED74;
extern s32 D_800D6A8C_D768C;
extern s32 D_800CC43C_CD03C;
extern s32 D_800D1FC8_D2BC8;

void osInitRdb(u8 *sendBuf, u32 sendSize) {
    register u32 int_disabled;

    sendSize >>= 2;

    if (((u32)sendBuf & 3) != 0) {
        sendBuf = (u8 *)(((u32)sendBuf & 3) + 4);
        sendSize--;
    }

    int_disabled = __osDisableInt();

    D_800D5554_D6154 = sendBuf;
    D_800CE174_CED74 = sendSize;
    D_800D6A8C_D768C = 0;
    D_800CC43C_CD03C = 0;
    D_800D1FC8_D2BC8 = 0;

    __osRestoreInt(int_disabled);
}
