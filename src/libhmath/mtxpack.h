#ifndef _LIBHMATH_MTXPACK_H_
#define _LIBHMATH_MTXPACK_H_

#include "PR/ultratypes.h"

#define HU_MTX_UNPACK_PAIR(src, fraction, input, fixed, row, pair)                                                        \
    ((fixed)[0] = ((src)->m[(row) / 2][((row) % 2) * 2 + (pair)] & 0xFFFF0000) | (fraction)[row][(pair) * 2],             \
     (fixed)[1] = (((src)->m[(row) / 2][((row) % 2) * 2 + (pair)] << 16) & 0xFFFF0000) | (fraction)[row][(pair) * 2 + 1], \
     (input)[row][(pair) * 2] = (fixed)[0] * (1.0f / 65536.0f),                                                           \
     (input)[row][(pair) * 2 + 1] = (fixed)[1] * (1.0f / 65536.0f))

#define HU_MTX_PACK_PAIR(output, dst, first, second, row, pair)                                      \
    ((first) = (output)[row][(pair) * 2] * 65536.0f,                                                 \
     (second) = (output)[row][(pair) * 2 + 1] * 65536.0f,                                            \
     (dst)->m[(row) / 2][((row) % 2) * 2 + (pair)] = ((first) & 0xFFFF0000) | ((u32)(second) >> 16), \
     (dst)->m[2 + (row) / 2][((row) % 2) * 2 + (pair)] = (((first) << 16) & 0xFFFF0000) | ((second) & 0xFFFF))

#endif
