#ifndef _TYPES_H_
#define _TYPES_H_

#define NULL 0

/// Linker symbol address, as in `ld_addrs.h`.
typedef u8 Addr[];
typedef f32 HuMtx4F[4][4];

typedef union {
    struct {
        s16 integer[4][4];
        u16 fraction[4][4];
    } parts;
    // Sixteen integer components followed by sixteen fractional components.
    u16 packed[32];
} HuMtxFixed;

#endif
