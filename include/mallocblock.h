#ifndef __MALLOCBLOCK_H
#define __MALLOCBLOCK_H

#include "libultra.h"

typedef enum
{
    TAG_DELAYED_FREE = -1,
} EHuMemTag;

typedef struct HuMallocHeader
{
    void* data;                    // 0000
    u8 framesLeft;                  // 0004
    s16 tag;                        // 0006
    s32 size;                       // 0008
    s32 creationFrame;              // 000C
    struct HuMallocHeader* prev;   // 0010
    struct HuMallocHeader* next;   // 0014
} HuMallocHeader;

typedef HuMallocHeader *(*HuAllocFunc)(u32 size);
typedef void (*HuFreeFunc)(void* ptr);

extern s16 gHuMemIsDirty;
extern s16 D_800A08A2_main;

extern s16 D_800C993C_main;
extern void* D_800C9950_main[];

extern HuMallocHeader* gLastMallocBlock;
extern HuFreeFunc gFreeFunc;
extern HuMallocHeader* gLastFreedBlock;
extern u8 D_800D1FF0_main;
extern s32 D_800D20AC_main;
extern void* D_800D2140_main[];
extern HuAllocFunc gMallocFunc;
extern HuMallocHeader* gFirstMallocBlock;


void HuMemInit(HuAllocFunc malloc, HuFreeFunc free);
void* HuMemAlloc(s32 size);
void* HuMemAllocTag(s32 size, s16 tag);
void HuMemFree(void* data);
void HuMemBlockFree(HuMallocHeader* block);
void HuMemFreeAllWithTag(s16 tag);
void func_80019C00_main(void* data);
void func_80019C68_main(s16 arg0);
void HuMemSetDirty(void);
void HuMemFreeAll(void);
void HuMemCleanUp(void);
void HuMemSetTag(void* data, s16 tag);

#endif
