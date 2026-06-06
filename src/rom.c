#include "common.h"
#include "rom.h"

OSPiHandle *osCartRomInit(void);
extern OSPiHandle *D_800CDD50_CE950;
extern OSMesgQueue D_800B29F0_B35F0;
extern void *D_800B2A08_B3608;
extern void *D_800CCFA8_CDBA8;
extern OSMesgQueue D_800D6B28_D7728;

void dmaInit(void) {
    osCreatePiManager(OS_PRIORITY_PIMGR, &D_800D6B28_D7728, &D_800CCFA8_CDBA8, 0x2A);
    D_800CDD50_CE950 = osCartRomInit();
    osCreateMesgQueue(&D_800B29F0_B35F0, &D_800B2A08_B3608, 0xA);
}

s32 dmaStart(OSIoMesg *msg, u8 pri, s32 direction, u8 *src, u8 *dest, u32 size, OSMesgQueue *retQueue) {
    msg->hdr.pri = pri;
    msg->hdr.retQueue = retQueue;
    msg->dramAddr = dest;
    msg->devAddr = (u32)src;
    msg->size = size;
    return osEPiStartDma(D_800CDD50_CE950, msg, direction);
}

s32 dmaRead(u8 *src, u8 *dest, s32 size) {
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
        err = dmaStart(&msg, 0, 0, &src[curBlockOffset], &dest[curBlockOffset], curBlockSize, &D_800B29F0_B35F0);

        if (err != 0) {
            return err;
        }

        osRecvMesg(&D_800B29F0_B35F0, 0, 1);
        size -= 0x4000;
        curBlockOffset += 0x4000;
    }
    return err;
}

s32 dmaReadOvl(u8 *src, u8 *dest, s32 size) {
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
        err = dmaStart(&msg, 0, 0, &src[curBlockOffset], &dest[curBlockOffset], var_v1, &D_800B29F0_B35F0);

        if (err != 0) {
            return err;
        }

        osRecvMesg(&D_800B29F0_B35F0, 0, 1);
        size -= 0x4000;
        curBlockOffset += 0x4000;
    }
    return err;
}
