#ifndef _GAME_HVQ_H
#define _GAME_HVQ_H

#include "ultra64.h"

typedef struct HvqImageHeader {
    u32 size;
    u32 modeOffsets[2];
    u32 meanOffsets[3];
    u32 amplitudeOffsets[3];
    u32 rawOffsets[3];
} HvqImageHeader;

void func_800698E8_6A4E8(HvqImageHeader *header, u16 *output, s32 stride, u8 *work);

#endif
