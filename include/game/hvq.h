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

void hvqMpsDecode1(void *data, u16 *output, s32 stride, u8 *work);

#endif
