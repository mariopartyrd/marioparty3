#include "common.h"
#include "rom.h"

OSPiHandle *osCartRomInit(void);
extern OSPiHandle *D_800CDD50_main;
extern OSMesgQueue D_800B29F0_main;
extern void *D_800B2A08_main;
extern void *D_800CCFA8_main;
extern OSMesgQueue D_800D6B28_main;

void dmaInit(void) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &D_800D6B28_main, &D_800CCFA8_main, 0x2A);
    D_800CDD50_main = osCartRomInit();
    osCreateMesgQueue(&D_800B29F0_main, &D_800B2A08_main, 0xA);
}

s32 dmaStart(OSIoMesg *msg, u8 pri, s32 direction, u8 *src, u8 *dest, u32 size, OSMesgQueue *retQueue) {
    msg->hdr.pri = pri;
    msg->hdr.retQueue = retQueue;
    msg->dramAddr = dest;
    msg->devAddr = (u32)src;
    msg->size = size;
    return osEPiStartDma(D_800CDD50_main, msg, direction);
}

s32 dmaRead(u32 src, u8 *dest, s32 size) {
    OSIoMesg msg;
    s32 curBlockOffset;
    u32 curBlockSize;
    s32 err;

    osInvalDCache(dest, OS_DCACHE_ROUNDUP_SIZE(size));

    curBlockOffset = 0;
    while (size > 0) {
        curBlockSize = size;
        if (size > 0x4000) {
            curBlockSize = 0x4000;
        }
        err = dmaStart(&msg, 0, 0, &((u8*)src)[curBlockOffset], &dest[curBlockOffset], curBlockSize, &D_800B29F0_main);

        if (err != 0) {
            return err;
        }

        osRecvMesg(&D_800B29F0_main, 0, 1);
        size -= 0x4000;
        curBlockOffset += 0x4000;
    }
    return err;
}

s32 dmaReadOvl(u32 src, u8 *dest, s32 size) {
    OSIoMesg msg;
    s32 curBlockOffset;
    u32 var_v1;
    s32 err;

    osInvalICache(dest, OS_DCACHE_ROUNDUP_SIZE(size));
    osInvalDCache(dest, OS_DCACHE_ROUNDUP_SIZE(size));

    curBlockOffset = 0;
    while (size > 0) {
        var_v1 = size;
        if (size > 0x4000) {
            var_v1 = 0x4000;
        }
        err = dmaStart(&msg, 0, 0, &((u8*)src)[curBlockOffset], &dest[curBlockOffset], var_v1, &D_800B29F0_main);

        if (err != 0) {
            return err;
        }

        osRecvMesg(&D_800B29F0_main, 0, 1);
        size -= 0x4000;
        curBlockOffset += 0x4000;
    }
    return err;
}
