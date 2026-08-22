#ifndef __DECODE_H
#define __DECODE_H

#include "ultra64.h"

typedef enum
{
    DECODE_NONE = 0,
    DECODE_LZ,              // lzss
    DECODE_SLIDE,           // yaz0/szs
    DECODE_FSLIDE,          // yaz0/szs, no loopback
    DECODE_FSLIDE_2,        // yaz0/szs, no loopback
    DECODE_RLE              // custom rle variant
} EDecodeType;

typedef struct DecodeStruct {
/* 0x00 */ u16 chunkLen;
/* 0x02 */ s16 pad;
/* 0x04 */ u32 src;
/* 0x08 */ u8* dest;
/* 0x0C */ u32 len;
} DecodeStruct;

void HuDecodeNone(DecodeStruct* decode);
void HuDecodeLZ(DecodeStruct* decode);
void HuDecodeSlide(DecodeStruct* decode);
void HuDecodeFslide(DecodeStruct* decode);
void HuDecodeRLE(DecodeStruct* decode);
void DecodeData(u32 src, void * dest, s32 len, EDecodeType decodeType);

#endif