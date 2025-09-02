#ifndef _MACROS_H_
#define _MACROS_H_

#include "PR/gbi.h"

#define SCREEN_WIDTH 320.0f
#define SCREEN_HEIGHT 240.0f
#define SCREEN_WIDTH_CENTER SCREEN_WIDTH / 2.0f
#define SCREEN_HEIGHT_CENTER SCREEN_HEIGHT / 2.0f
#define ASPECT_RATIO (4.0f / 3.0f)

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNT_2D_ROWS(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNT_2D_COLS(arr) (s32)(sizeof(arr[0]) / sizeof(arr[0][0]))

#define ALIGN_16(size) (((size) + 0x1F) & ~0xF)

#define PACK_FILL_COLOR(r, g, b, a) (GPACK_RGBA5551(r, g, b, a) << 0x10) | GPACK_RGBA5551(r, g, b, a)

#endif