#include "common.h"
#include "mallocblock.h"
#include "ovl_80.h"

typedef struct UnkCam3DStruct {
    f32 unk_00[2];
    f32 unk_08;
    f32 unk_0C;
} UnkCam3DStruct;

//is this even HVQ related
typedef struct UnkHvqStruct {
    s32 unk_00;
    s32 unk_04;
    u8* dest;
    s32 dmaSize;
    u32 src;
} UnkHvqStruct;

typedef struct UnkFAC88 {
    /* 0x00 */ u8 unk0;
    /* 0x01 */ u8 unk1;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ void* unk4;
    /* 0x08 */ void* unk_08;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
} UnkFAC88; //sizeof 0x14

extern s32 D_80102DB8_1169D8_shared_board;

typedef struct UnkModelStruct {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ s32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
} UnkModelStruct; //sizeof 0x3C

extern UnkModelStruct* D_80101248_114E68_shared_board;

typedef struct HVQHeader {
    s32 allocSize;
    u8* unk_04;
    char unk_08[8];
} HVQHeader; //TODO: there's like 3 of these, no idea if they are the same or not

extern u16 D_80102DC0_1169E0_shared_board;
extern UnkFAC88 *D_801030A8_116CC8_shared_board[6][6];
extern UnkFAC88 D_80102DD8_1169F8_shared_board[36];
extern OSMesgQueue D_80103468_117088_shared_board;
extern u16 D_80105212_118E32_shared_board;
extern u8 D_8010124C_114E6C_shared_board;
extern s32 D_801012C8_114EE8_shared_board[];
extern s32 D_80101318_114F38_shared_board[];
extern s32* D_80101240_114E60_shared_board;
extern u32 D_80102DB0_1169D0_shared_board;
extern s32 D_80102DB4_1169D4_shared_board;
extern u32* D_80101244_114E64_shared_board;
extern u16 D_80102DC0_1169E0_shared_board;
extern f32 D_8010341C_11703C_shared_board;
extern f32 D_801049F0_118610_shared_board[2];
extern f32 D_80101250_114E70_shared_board;
extern f32 D_801049F8_118618_shared_board[];
extern OSMesgQueue D_80103468_117088_shared_board;
extern void* D_80103480_1170A0_shared_board;
extern OSThread D_80103510_117130_shared_board;
extern OSThread D_80103EC0_117AE0_shared_board;
extern s32 D_80104070_117C90_shared_board;
extern void* D_80104898_1184B8_shared_board;
extern void* D_80104940_118560_shared_board;
extern void* D_801049E8_118608_shared_board;
extern OSThread D_80103EC0_117AE0_shared_board;
extern s32 D_80104070_117C90_shared_board;
extern s16 D_80102DC2_1169E2_shared_board;
extern s16 D_80102DC4_1169E4_shared_board;
extern s16 D_80102DC6_1169E6_shared_board;
extern s16 D_80102DC8_1169E8_shared_board;
extern f32 D_80101250_114E70_shared_board;
extern Process* D_80103414_117034_shared_board;
extern Process* D_80103410_117030_shared_board;
extern f32 D_80103418_117038_shared_board;
extern Vec D_80103420_117040_shared_board;
extern Vec D_8010342C_11704C_shared_board;
extern Vec D_80103438_117058_shared_board;
extern Vec D_80103444_117064_shared_board;
extern Vec D_8010125C_114E7C_shared_board;

void func_800E9358_FCF78_shared_board(void);            /* extern */
void MBBackTPLvlSet(u8 arg0);
s32 dmaRead(u32 src, u8 *dest, s32 size);
void func_8001F95C_2055C(s32, void (*func)(void));
void func_800E9328_FCF48_shared_board(void);
void func_800E6EC8_FAAE8_shared_board(void);
void func_800E7130_FAD50_shared_board(void);
void func_800E7068_FAC88_shared_board(void);
void func_800E71EC_FAE0C_shared_board(void);
void func_800E86CC_FC2EC_shared_board(void);
void func_800E90BC_FCCDC_shared_board(void);
void func_800E8DE0_FCA00_shared_board(void);

void func_800E6630_FA250_shared_board(u32 arg0) {
    HVQHeader* temp_v0;
    s32* temp_v0_2;
    u32 temp_s0;

    D_80102DB0_1169D0_shared_board = arg0;
    temp_v0 = HuMemMemoryAllocTemp(sizeof(HVQHeader));
    dmaRead(arg0, (u8*)temp_v0, sizeof(HVQHeader));
    D_80102DB4_1169D4_shared_board = temp_v0->allocSize;
    HuMemMemoryFreeTemp(temp_v0);
    temp_s0 = D_80102DB4_1169D4_shared_board * 4;
    temp_v0_2 = HuMemMemoryAllocTemp(temp_s0);
    D_80101240_114E60_shared_board = temp_v0_2;
    dmaRead(arg0 + 4, (u8*)temp_v0_2, temp_s0);
    D_80102DCC_1169EC_shared_board = HuMemMemoryAllocTemp(0x300); //TODO: hardcoded size
    D_80101248_114E68_shared_board = NULL;
}

void func_800E66D4_FA2F4_shared_board(void) {
    D_80101248_114E68_shared_board = NULL;
}

void MBBackClose(void) {
    if (D_80101240_114E60_shared_board != NULL) {
        HuMemMemoryFreeTemp(D_80101240_114E60_shared_board);
        D_80101240_114E60_shared_board = NULL;
        HuMemMemoryFreeTemp(D_80102DCC_1169EC_shared_board);
    }
}

extern s32 D_80105990_1195B0_shared_board;
extern s32* D_80101240_114E60_shared_board; //TODO: fix type
extern Vec D_80103450_117070_shared_board;

extern f32 D_80101254_114E74_shared_board;
extern f32 D_80101258_114E78_shared_board;

s32 func_800E7330_FAF50_shared_board(u16 arg0);

void MBBackCreate(s32 arg0, s32 arg1) {
    UnkModelStruct* temp_v0_3;
    s32 temp_s2;
    u32 temp_s0;
    s32* temp_v0;
    u32* temp_v0_2;

    D_80105990_1195B0_shared_board = arg0;
    D_80102DB8_1169D8_shared_board = D_80102DB0_1169D0_shared_board + D_80101240_114E60_shared_board[arg0];
    temp_v0 = HuMemMemoryAllocTemp(sizeof(HVQHeader));
    dmaRead((u32)D_80102DB8_1169D8_shared_board, (u8*)temp_v0, sizeof(HVQHeader));
    arg0 = *temp_v0;
    HuMemMemoryFreeTemp(temp_v0);
    arg0++;
    temp_s0 = arg0 * 4;
    temp_v0_2 = HuMemMemoryAllocTemp(temp_s0);
    D_80101244_114E64_shared_board = temp_v0_2;
    dmaRead(D_80102DB8_1169D8_shared_board + 4, (u8*)temp_v0_2, temp_s0);
    temp_v0_3 = HuMemMemoryAllocTemp(sizeof(UnkModelStruct));
    D_80101248_114E68_shared_board = temp_v0_3;
    dmaRead(D_80102DB8_1169D8_shared_board + D_80101244_114E64_shared_board[0], (u8*)&temp_v0_3->unk0, sizeof(UnkModelStruct));
    D_80103450_117070_shared_board.x = D_80101248_114E68_shared_board->unk18;
    D_80103450_117070_shared_board.y = D_80101248_114E68_shared_board->unk1C;
    D_80103450_117070_shared_board.z = D_80101248_114E68_shared_board->unk20;
    D_80101248_114E68_shared_board->unk18 *= 5.0f;
    D_80101248_114E68_shared_board->unk1C *= 5.0f;
    D_80101248_114E68_shared_board->unk20 *= 5.0f;
    D_80101248_114E68_shared_board->unk24 *= 5.0f;
    D_80101248_114E68_shared_board->unk28 *= 5.0f;
    D_80101248_114E68_shared_board->unk2C *= 5.0f;
    D_80103138_116D58_shared_board = HuMemMemoryAllocTemp(func_800E7330_FAF50_shared_board(0));
    dmaRead(D_80102DB8_1169D8_shared_board + D_80101244_114E64_shared_board[1], D_80103138_116D58_shared_board, func_800E7330_FAF50_shared_board(0));
    D_80102DC4_1169E4_shared_board = 0;
    D_80102DC2_1169E2_shared_board = 0;
    D_80102DC6_1169E6_shared_board = D_80101248_114E68_shared_board->unk0 * D_80101248_114E68_shared_board->unk8 / 2;
    D_80102DC8_1169E8_shared_board = D_80101248_114E68_shared_board->unk4 * D_80101248_114E68_shared_board->unkC / 2;
    D_80102DC0_1169E0_shared_board = 1;
    func_8001F95C_2055C(0, func_800E86CC_FC2EC_shared_board);
    func_800E7254_FAE74_shared_board();
    func_800E6FBC_FABDC_shared_board();
    if (arg1 != 0) {
        func_800E90BC_FCCDC_shared_board();
    }
    func_800E9730_FD350_shared_board(1.0f);
    MBBackTPLvlSet(0xFF);
    MBCameraSpeedSet(-1.0f);
    D_80101254_114E74_shared_board = 0.0f;
    D_80101258_114E78_shared_board = 0.0f;
    MBCameraZoomSet(1.0f);
}

void MBBackLoad(s32 arg0) {
    MBBackCreate(arg0, 1);
}

void MBBackKill(void) {
    if (D_80101244_114E64_shared_board != NULL) {
        HuMemMemoryFreeTemp(D_80101244_114E64_shared_board);
        D_80101244_114E64_shared_board = NULL;
        HuMemMemoryFreeTemp(D_80101248_114E68_shared_board);
        HuMemMemoryFreeTemp(D_80103138_116D58_shared_board);
        func_8001F95C_2055C(0, 0);
        func_800E728C_FAEAC_shared_board();
        func_800E9328_FCF48_shared_board();
    }
}

void MBBackOffsetSet(s16 arg0, s16 arg1) {
    D_80102DC2_1169E2_shared_board = arg0;
    D_80102DC4_1169E4_shared_board = arg1;
}


f32 MBBackMaxXGet(void) {
    return ((D_80102DC6_1169E6_shared_board - 160.0f) / D_8010341C_11703C_shared_board) + 160.0f;
}

f32 MBBackMaxYGet(void) {
    return ((D_80102DC8_1169E8_shared_board - 120.0f) / D_8010341C_11703C_shared_board) + 120.0f;
}

u16 MBBackPosClamp(f32* arg0, f32 arg1) {
    s32 var_v1;

    var_v1 = 0;
    if (arg0[0] <= (((-D_80102DC6_1169E6_shared_board + 160.0f) / arg1) + 160.0f)) {
        arg0[0] = ((-D_80102DC6_1169E6_shared_board + 160.0f) / arg1) + 160.0f;
        var_v1 = 1;
    }
    if (((D_80102DC6_1169E6_shared_board - 160.0f) / arg1) + 160.0f + ((320.0f / arg1) - (320.0f / (arg1 * D_80101250_114E70_shared_board))) <= arg0[0]) {
        arg0[0] = ((D_80102DC6_1169E6_shared_board - 160.0f) / arg1) + 160.0f + ((320.0f / arg1) - (320.0f / (arg1 * D_80101250_114E70_shared_board)));
        var_v1 |= 2;
    }
    if (arg0[1] <= ((-D_80102DC8_1169E8_shared_board + 120.0f) / arg1) + 120.0f) {
        arg0[1] = ((-D_80102DC8_1169E8_shared_board + 120.0f) / arg1) + 120.0f;
        var_v1 |= 4;
    }
    if (((D_80102DC8_1169E8_shared_board - 120.0f) / arg1) + 120.0f + ((240.0f / arg1) - (240.0f / (arg1 * D_80101250_114E70_shared_board))) <= arg0[1]) {
        arg0[1] = ((D_80102DC8_1169E8_shared_board - 120.0f) / arg1) + 120.0f + ((240.0f / arg1) - (240.0f / (arg1 * D_80101250_114E70_shared_board)));
        var_v1 |= 8;
    }
    return var_v1;
}

void MBBackDispSet(u16 arg0) {
    if (arg0) {
        D_80102DC0_1169E0_shared_board = D_80102DC0_1169E0_shared_board | 1;
    } else {
        D_80102DC0_1169E0_shared_board = D_80102DC0_1169E0_shared_board & ~1;
    }
}

void func_800E6C80_FA8A0_shared_board(void) {
    UnkHvqStruct* sp10;

    while (1) {
        osRecvMesg(&D_80103468_117088_shared_board, (OSMesg*)&sp10, 1);
        if (sp10 == NULL) {
            break;
        }
        dmaRead(sp10->src, sp10->dest, sp10->dmaSize);
        osSendMesg(&D_80104880_1184A0_shared_board, (OSMesg*)sp10, 0);
    }

    osSendMesg(&D_801049D0_1185F0_shared_board, (void* )1, 0);
    osDestroyThread(NULL);
}

#define SlideReadUint(buffer, src)    \
    do {                              \
        (buffer) = ((*src++) << 24);  \
        (buffer) += ((*src++) << 16); \
        (buffer) += ((*src++) << 8);  \
        (buffer) += (*src++);         \
    } while (0)

void func_800E6CF8_FA918_shared_board(u8 *input, u8 *output, s32 compressedSize) {
    u8 *src = input + 4;       // Skip metadata
    s32 flagLen = 0;           // Remaining bits in the bit buffer
    s32 flag = 0;              // Buffer holding bits for control decisions
    s32 size = compressedSize; // Bytes left to decompress
    u8 *matchPtr;              // Pointer for back-reference matches
    u32 offset, len;           // Offset and length for back-references
    u32 dist;                  // Temporary value for reading data

    while (size != 0) {
        // Refill the bit buffer if empty
        if (flagLen == 0) {
            SlideReadUint(flag, src);
            flagLen = 32;
        }

        // Determine if the next data is a literal or back-reference
        if (flag >> 31) {
            *output++ = *src++; // Write literal byte
            size--;
        } else {
            // Read the next 16 bits for the back-reference
            dist = (*src++ << 8);
            dist += (*src++);
            len = (dist >> 12) & 0xF;
            dist &= 0xFFF;
            // Calculate the pointer for the back-reference match
            matchPtr = output - dist;

            // Handle extended match lengths
            if (len == 0) {
                len = (*src++) + 0x12;
            } else {
                len += 2;
            }

            size -= len;
            if (size < 0) {
                break; // Prevent buffer overflow
            }

            // Copy the match data from the back-reference
            while (len > 0) {
                *output++ = matchPtr[-1];
                matchPtr++;
                len--;
            }
        }

        // Shift the bit buffer and decrement remaining bits
        flag <<= 1;
        flagLen--;

        // Exit if all bytes have been decompressed
        if (size == 0) {
            break;
        }
    }
}

// decodes HVQ board image tile?
void func_800E6DEC_FAA0C_shared_board(void) {
    HvqUnk *sp10;
    HvqHeader *temp_a0;

    func_8006A370_6AF70(0xFF);
    func_80069E68_6AA68(D_80103138_116D58_shared_board); //"HVQ-MPS 1.1"
    while (1) {
        osRecvMesg(&D_80104880_1184A0_shared_board, (void *)&sp10, 1);
        if (sp10 != NULL) {
            temp_a0 = sp10->unk8;
            D_80102DD0_1169F0_shared_board = sp10->unk8;
            if (temp_a0->magic == 0x48565153) { //"HVQS"
                                                // is HVQS, decode it
                func_800698E8_6A4E8(&temp_a0->unk4, sp10->unk4, 0x40, D_80102DCC_1169EC_shared_board);
            } else {
                // 0x1800 size for decoded tile
                func_800E6CF8_FA918_shared_board((u8 *)&D_80102DD0_1169F0_shared_board->unk4, sp10->unk4, 0x1800);
            }
            osSendMesg(&D_80104928_118548_shared_board, sp10, 0);
        } else {
            break;
        }
    }

    osSendMesg(&D_801049D0_1185F0_shared_board, (void *)2, 0);
    osDestroyThread(NULL);
}

void func_800E6EC8_FAAE8_shared_board(void) {
    osCreateMesgQueue(&D_80103468_117088_shared_board, &D_80103480_1170A0_shared_board, 0x24);
    osCreateMesgQueue(&D_80104880_1184A0_shared_board, &D_80104898_1184B8_shared_board, 0x24);
    osCreateMesgQueue(&D_80104928_118548_shared_board, &D_80104940_118560_shared_board, 0x24);
    osCreateMesgQueue(&D_801049D0_1185F0_shared_board, &D_801049E8_118608_shared_board, 2);
    D_80104070_117C90_shared_board = 1;
    osCreateThread(&D_80103EC0_117AE0_shared_board, 0x64, (void (*)(void*)) func_800E6DEC_FAA0C_shared_board, NULL, &D_80104880_1184A0_shared_board, 1);
    osStartThread(&D_80103EC0_117AE0_shared_board);
    osCreateThread(&D_80103510_117130_shared_board, 0x65, (void*)func_800E6C80_FA8A0_shared_board, NULL, &D_80103EC0_117AE0_shared_board, 4);
    osStartThread(&D_80103510_117130_shared_board);
}

void func_800E6FBC_FABDC_shared_board(void) {
    D_80104070_117C90_shared_board = 3;
}

void func_800E6FCC_FABEC_shared_board(void) {
    D_80104070_117C90_shared_board = 1;
}

void func_800E6FDC_FABFC_shared_board(void) {
    if (osGetThreadPri(&D_80103EC0_117AE0_shared_board) != D_80104070_117C90_shared_board) {
        osSetThreadPri(&D_80103EC0_117AE0_shared_board, D_80104070_117C90_shared_board);
    }
}


void func_800E7018_FAC38_shared_board(void) {
    UnkHvqStruct* sp10;

    while (1) {
        if (osRecvMesg(&D_80104928_118548_shared_board, (OSMesg*)&sp10, 0) != 0) {
            break;
        }
        if (sp10 != NULL) {
            HuMemMemoryFreePerm(sp10->dest);
            sp10->dest = NULL;
        }
    }
}

void func_800E7068_FAC88_shared_board(void) {
    s32 i;

    osJamMesg(&D_80103468_117088_shared_board, NULL, OS_MESG_NOBLOCK);
    osJamMesg(&D_80104880_1184A0_shared_board, NULL, OS_MESG_NOBLOCK);

    func_800E6FBC_FABDC_shared_board();
    func_800E6FDC_FABFC_shared_board();

    osRecvMesg(&D_801049D0_1185F0_shared_board, NULL, OS_MESG_BLOCK);
    osRecvMesg(&D_801049D0_1185F0_shared_board, NULL, OS_MESG_BLOCK);

    for (i = 0; i < ARRAY_COUNT(D_80102DD8_1169F8_shared_board); i++) {
        UnkFAC88* temp = &D_80102DD8_1169F8_shared_board[i];
        if (temp->unk_08 != NULL) {
            HuMemMemoryFreePerm(temp->unk_08);
            temp->unk_08 = NULL;
        }
    }
}

void func_800E7130_FAD50_shared_board(void) {
    UnkFAC88* var_s0 = D_80102DD8_1169F8_shared_board;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80102DD8_1169F8_shared_board); i++, var_s0++) {
        var_s0->unk0 = 0;
        var_s0->unk1 = 0;
        var_s0->unk2 = -1;
        var_s0->unk4 = HuMemAlloc(0x1800);
        var_s0->unk_08 = NULL;
    }

    bzero(D_801030A8_116CC8_shared_board, sizeof(D_801030A8_116CC8_shared_board));
}

void func_800E71A8_FADC8_shared_board(void) {
    UnkFAC88* var_v1 = D_80102DD8_1169F8_shared_board;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80102DD8_1169F8_shared_board); i++, var_v1++) {
        if ((var_v1->unk_08 == NULL) && (var_v1->unk0 == 0)) {
            var_v1->unk2 = -1;
        }
        var_v1->unk0 = 0;
    }
}

void func_800E71EC_FAE0C_shared_board(void) {
    UnkFAC88* var_s0 = D_80102DD8_1169F8_shared_board;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80102DD8_1169F8_shared_board); i++, var_s0++) {
        var_s0->unk0 = 0;
        var_s0->unk2 = -1;

        if (var_s0->unk4 != NULL) {
            HuMemFree(var_s0->unk4);
            var_s0->unk4 = NULL;
        }
    }
}

void func_800E7254_FAE74_shared_board(void) {
    func_800E7130_FAD50_shared_board();
    func_800E6EC8_FAAE8_shared_board();
    D_80102DC0_1169E0_shared_board |= 4;
}

void func_800E728C_FAEAC_shared_board(void) {
    func_800E7068_FAC88_shared_board();
    func_800E71EC_FAE0C_shared_board();
    D_80102DC0_1169E0_shared_board &= ~4;
}

void func_800E72C4_FAEE4_shared_board(void) {
    D_80102DC0_1169E0_shared_board &= ~4;
}

f32 MBBackMdlScaleGet(void) {
    if (D_80101248_114E68_shared_board == NULL) {
        return 1.0f;
    } else {
        return D_80101248_114E68_shared_board->unk14;
    }
}

u16 func_800E7300_FAF20_shared_board(s32 arg0, s32 arg1) {
    return ((((D_80101248_114E68_shared_board->unkC - arg1) - 1) * D_80101248_114E68_shared_board->unk8) + arg0 + 1);
}

s32 func_800E7330_FAF50_shared_board(u16 arg0) {
    arg0++;
    return D_80101244_114E64_shared_board[(arg0 + 1)] - D_80101244_114E64_shared_board[(arg0 + 0)];
}

s32 func_800E7358_FAF78_shared_board(u16 arg0) {
    arg0++;
    return D_80102DB8_1169D8_shared_board + D_80101244_114E64_shared_board[(arg0)];
}

extern s32 D_8010345C_11707C_shared_board;
extern u16 D_8010345E_11707E_shared_board;
extern s32 D_80103460_117080_shared_board;

typedef struct UnkFAF78 {
    /* 0x00 */ s32 unk_00;   /* count */
    /* 0x04 */ s32 *unk_04;  /* id list */
    /* 0x08 */ char pad08[4];
} UnkFAF78; /* size = 0xC */

extern UnkFAF78 *D_80103464_117084_shared_board;

UnkFAC88 *func_800E7384_FAFA4_shared_board(u16 arg0) {
    UnkFAC88 *entry;
    UnkFAC88 *slot;
    u16 bank;
    s32 i;
    s32 size;

    slot = NULL;
    entry = D_80102DD8_1169F8_shared_board;
    bank = 0;

    if (D_8010345C_11707C_shared_board != 0) {
        for (i = 0; i < D_80103464_117084_shared_board[D_80103460_117080_shared_board].unk_00 - 1; i++) {
            if (arg0 == D_80103464_117084_shared_board[D_80103460_117080_shared_board].unk_04[i]) {
                bank = D_8010345C_11707C_shared_board;
            }
        }
    }

    for (i = 0; i < 36; i++, entry++) {
        if (entry->unk2 == -1) {
            slot = entry;
        } else if (entry->unk2 == arg0) {
            if (entry->unk1 == bank) {
                entry->unk0 = 1;
                return entry;
            }
        }
    }

    if (slot != NULL) {
        slot->unk0 = 1;
        slot->unk2 = arg0;
        slot->unk1 = bank;
        slot->unk10 = func_800E7358_FAF78_shared_board(arg0);
        size = func_800E7330_FAF50_shared_board(arg0);
        slot->unkC = size;
        slot->unk_08 = HuMemMemoryAllocPerm(size);
        osSendMesg(&D_80103468_117088_shared_board, slot, OS_MESG_NOBLOCK);
    }
    return slot;
}

void func_800E7514_FB134_shared_board(void) {
    s32 tileX;
    s32 tileY;
    s32 x;
    s32 y;

    tileY = (s32)(((f32)((D_80102DC8_1169E8_shared_board + D_80102DC4_1169E4_shared_board) - 0x78) -
                   ((240.0f - (240.0f / D_80101250_114E70_shared_board)) / 2.0f)) / 48.0f);

    for (y = 0; y < 6; y++, tileY++) {
        tileX = (s32)(((f32)((D_80102DC6_1169E6_shared_board + D_80102DC2_1169E2_shared_board) - 0xA0) -
                       ((320.0f - (320.0f / D_80101250_114E70_shared_board)) / 2.0f)) / 64.0f);

        for (x = 0; x < 6; x++, tileX++) {
            if ((tileX < 0) || (tileY < 0) ||
                (tileX >= D_80101248_114E68_shared_board->unk8) ||
                (tileY >= D_80101248_114E68_shared_board->unkC)) {
                D_801030A8_116CC8_shared_board[x][y] = NULL;
            } else {
                D_801030A8_116CC8_shared_board[x][y] =
                    func_800E7384_FAFA4_shared_board(func_800E7300_FAF20_shared_board(tileX, tileY));
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800E76EC_FB30C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800E86CC_FC2EC_shared_board);

f32 MBCameraZoomGet(void) {
    return D_80101250_114E70_shared_board;
}

void MBCameraZoomSet(f32 zoom) {
    D_80101250_114E70_shared_board = zoom;
}

void func_800E8DE0_FCA00_shared_board(void) {
    f32 target;
    f32 diff;
    f32 step;
    f32 next;
    f32 temp;

    target = *(f32 *)HuPrcCurrentGet()->user_data;

    while (1) {
        diff = D_80101250_114E70_shared_board - target;
        step = (0.0f < diff) ? diff : 0.0f - (D_80101250_114E70_shared_board - target);
        
        if (step <= 0.005f) {
            break;
        }
        
        step /= 4.0f;
        if (step < 0.005f) {
            step = 0.005f;
        }
        if (target < D_80101250_114E70_shared_board) {
            next = D_80101250_114E70_shared_board - step;
        } else {
            next = step + D_80101250_114E70_shared_board;
        }
        D_80101250_114E70_shared_board = next;
        HuPrcVSleep();
    }

    D_80101250_114E70_shared_board = target;
    D_80103414_117034_shared_board = NULL;
    omDelPrcObj(NULL);
}

Process* MBCameraZoomMotStart(f32 arg0) {
    Process* temp_v0;
    f32* temp_v0_2;

    if (D_80103414_117034_shared_board != NULL) {
        omDelPrcObj(D_80103414_117034_shared_board);
    }
    D_80103414_117034_shared_board = omAddPrcObj(func_800E8DE0_FCA00_shared_board, 1U, 0, 0x40);

    temp_v0_2 = HuMemMemoryAlloc(D_80103414_117034_shared_board->heap, 0x10);
    D_80103414_117034_shared_board->user_data = temp_v0_2;
    *temp_v0_2 = arg0;
    return D_80103414_117034_shared_board;
}

void func_800E8F54_FCB74_shared_board(void) {
    f32 temp_f22;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f20;
    s32 var_s0;
    s32 i;

    temp_f22 = *(f32*)HuPrcCurrentGet()->user_data;
    temp_f2 = D_80101250_114E70_shared_board - temp_f22;
    if (temp_f2 > 0.0f) {
        var_f20 = temp_f2 / 5.0f;
    } else {
        var_f20 = (0.0f - (D_80101250_114E70_shared_board - temp_f22)) / 5.0f;
    }
    for (i = 0; i < 5; i++, HuPrcVSleep()) {
        if (temp_f22 < D_80101250_114E70_shared_board) {
            D_80101250_114E70_shared_board = D_80101250_114E70_shared_board - var_f20;
        } else {
            D_80101250_114E70_shared_board = var_f20 + D_80101250_114E70_shared_board;
        }
    }

    D_80101250_114E70_shared_board = temp_f22;
    D_80103414_117034_shared_board = NULL;
    omDelPrcObj(NULL);
}

Process* func_800E9044_FCC64_shared_board(f32 arg0) {
    Process* proc;
    f32* temp_v0_2;

    if (D_80103414_117034_shared_board != NULL) {
        omDelPrcObj(D_80103414_117034_shared_board);
    }

    proc = omAddPrcObj(func_800E8F54_FCB74_shared_board, 1, 0, 0x40);
    D_80103414_117034_shared_board = proc;
    temp_v0_2 = HuMemMemoryAlloc(proc->heap, 0x10);
    D_80103414_117034_shared_board->user_data = temp_v0_2;
    *temp_v0_2 = arg0;
    return D_80103414_117034_shared_board;
}

void func_800E90BC_FCCDC_shared_board(void) {
    Process* temp_v0;
    f32 temp_f2;
    f32 temp_f4;

    temp_f2 = (f32) (D_80101248_114E68_shared_board->unk4 * D_80101248_114E68_shared_board->unkC) / 240.0f;
    D_8010341C_11703C_shared_board = temp_f2;
    temp_f4 = (f32) (D_80101248_114E68_shared_board->unk0 * D_80101248_114E68_shared_board->unk8) / 320.0f;
    if (temp_f2 < temp_f4) {
        D_8010341C_11703C_shared_board = temp_f4;
    }
    D_80103420_117040_shared_board.x = D_80101248_114E68_shared_board->unk18;
    D_80103420_117040_shared_board.y = D_80101248_114E68_shared_board->unk1C;
    D_80103420_117040_shared_board.z = D_80101248_114E68_shared_board->unk20;
    D_8010342C_11704C_shared_board.x = D_80101248_114E68_shared_board->unk24;
    D_8010342C_11704C_shared_board.y = D_80101248_114E68_shared_board->unk28;
    D_8010342C_11704C_shared_board.z = D_80101248_114E68_shared_board->unk2C;
    D_80103438_117058_shared_board.x = D_80101248_114E68_shared_board->unk30;
    D_80103438_117058_shared_board.y = D_80101248_114E68_shared_board->unk34;
    D_80103438_117058_shared_board.z = D_80101248_114E68_shared_board->unk38;
    D_80103444_117064_shared_board.x = (f32) (D_8010341C_11703C_shared_board * 640.0f);
    D_80103444_117064_shared_board.y = (f32) (D_8010341C_11703C_shared_board * 480.0f);
    D_80103444_117064_shared_board.z = 511.0f;
    D_801049F8_118618_shared_board[0] = 640.0f;
    D_801049F8_118618_shared_board[1] = 480.0f;
    D_801049F0_118610_shared_board[0] = 159.5f;
    D_801049F0_118610_shared_board[1] = 119.5f;
    D_80103418_117038_shared_board = 1.0f;
    temp_v0 = omAddPrcObj(func_800E9358_FCF78_shared_board, 0x1001U, 0, 0);
    D_80103410_117030_shared_board = temp_v0;
    omPrcSetStatBit(temp_v0, 0x80);
    D_80103414_117034_shared_board = 0;
    Hu3DCamSetPerspective(0, D_80101248_114E68_shared_board->unk10, 10.0f, 200.0f);
    Hu3DCamSetPositionOrientation(0, &D_80103420_117040_shared_board, &D_8010342C_11704C_shared_board, &D_80103438_117058_shared_board);
    Hu3DCamUpdateMtx(0);
}

void func_800E92D4_FCEF4_shared_board(void) {
    if (D_80103410_117030_shared_board != NULL) {
        omDelPrcObj(D_80103410_117030_shared_board);
        D_80103410_117030_shared_board = NULL;
    }
    if (D_80103414_117034_shared_board != NULL) {
        omDelPrcObj(D_80103414_117034_shared_board);
        D_80103414_117034_shared_board = NULL;
    }
}

void func_800E9328_FCF48_shared_board(void) {
    func_800E92D4_FCEF4_shared_board();
}

void func_800E9344_FCF64_shared_board(f32 arg0, f32 arg1) {
    D_80101258_114E78_shared_board = arg0;
    D_80101254_114E74_shared_board = arg1;
}

extern f32 D_80102DBC_1169DC_shared_board;
f32 HuVecDistance(Vec*, Vec*);
void MBVecNormalize(Vec*);

void func_800E9358_FCF78_shared_board(void) {
    Vec sp10;
    s16 sp20[2];
    Vec sp28;
    Vec sp38;
    f32 temp_f2;
    f32 temp_f4;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f2;

    while (1) {
        temp_f4 = HuVecDistance(&D_80103420_117040_shared_board, &D_8010342C_11704C_shared_board);
        var_f2 = D_80101254_114E74_shared_board;
        if ((var_f2 == 0.0f) || (var_f0 = D_80101258_114E78_shared_board, (var_f0 == 0.0f))) {
            var_f2 = temp_f4 + 1000.0f;
            var_f0 = var_f2 - 2000.0f;
        }
        if (var_f0 < 10.0f) {
            var_f0 = 10.0f;
        }
        Hu3DCamSetPerspective(0, D_80101248_114E68_shared_board->unk10, var_f0, var_f2);
        Hu3DCamSetPositionOrientation(0, &D_80103420_117040_shared_board, &D_8010342C_11704C_shared_board, &D_80103438_117058_shared_board);
        Hu3DCamUpdateMtx(0);

        sp38.x = ((((D_801049F0_118610_shared_board[0] - 160.0f) * D_8010341C_11703C_shared_board * -4.0f) + 640.0f) - D_801049F8_118618_shared_board[0]) / D_80103418_117038_shared_board;
        sp38.y = ((((D_801049F0_118610_shared_board[1] - 120.0f) * D_8010341C_11703C_shared_board * -4.0f) + 480.0f) - D_801049F8_118618_shared_board[1]) / D_80103418_117038_shared_board;
        sp38.z = 0.0f;

        temp_f2 = HuVecGetLength3F(&sp38) / 4.0f;

        if (temp_f2 <= 1.0f) {
            D_80102DC0_1169E0_shared_board &= 0xFFFD;
            D_801049F8_118618_shared_board[0] = ((D_801049F0_118610_shared_board[0] - 160.0f) * D_8010341C_11703C_shared_board * -4.0f) + 640.0f;
            D_801049F8_118618_shared_board[1] = ((D_801049F0_118610_shared_board[1] - 120.0f) * D_8010341C_11703C_shared_board * -4.0f) + 480.0f;
        } else {
            D_80102DC0_1169E0_shared_board |= 2;
            if ((D_80102DBC_1169DC_shared_board >= 0.0f) && (D_80102DBC_1169DC_shared_board < temp_f2)) {
                MBVecNormalize(&sp38);
                HuVecMulScalar(&sp38, D_80102DBC_1169DC_shared_board * 4.0f, &sp38);
            }
            D_801049F8_118618_shared_board[0] += sp38.x;
            D_801049F8_118618_shared_board[1] = D_801049F8_118618_shared_board[1] + sp38.y;
        }

        sp20[0] = D_801049F8_118618_shared_board[0] / 4.0f;
        sp20[1] = D_801049F8_118618_shared_board[1] / 4.0f;

        sp10.x = D_801049F8_118618_shared_board[0] * D_80101250_114E70_shared_board;
        sp10.y = D_801049F8_118618_shared_board[1] * D_80101250_114E70_shared_board;
        sp10.z = 511.5f;

        sp28.x = D_8010341C_11703C_shared_board * 640.0f * D_80101250_114E70_shared_board;
        sp28.y = D_8010341C_11703C_shared_board * 480.0f * D_80101250_114E70_shared_board;
        sp28.z = 511.0f;

        CameraViewportSet(0, &sp28, &sp10);
        MBBackOffsetSet(-sp20[0] + 0xA0, -sp20[1] + 0x78);
        HuPrcVSleep();
    }
}

void func_800E9730_FD350_shared_board(f32 arg0) {
    D_80103418_117038_shared_board = arg0;
}

f32 func_800E973C_FD35C_shared_board(void) {
    return D_80103418_117038_shared_board;
}

u16 MBCameraPos3DSet(Vec *arg0) {
    Vec sp10;
    f32 scale;
    f32 halfW;
    f32 halfH;
    f32* temp;
    
    D_8010125C_114E7C_shared_board.x = arg0->x;
    D_8010125C_114E7C_shared_board.y = arg0->y;
    D_8010125C_114E7C_shared_board.z = arg0->z;

    HuVecCopyXYZ(&sp10, arg0->x, arg0->y + 10.0f, arg0->z);
    Hu3DCam3DToScreen(0, &sp10, D_801049F0_118610_shared_board);

    temp = D_801049F0_118610_shared_board;

    halfW = 320.0f / (2.0f * D_8010341C_11703C_shared_board);
    temp[0] += halfW - (halfW / D_80101250_114E70_shared_board);

    halfH = 240.0f / (2.0f * D_8010341C_11703C_shared_board);
    D_801049F0_118610_shared_board[1] += halfH - (halfH / D_80101250_114E70_shared_board);

    return MBBackPosClamp(D_801049F0_118610_shared_board, D_8010341C_11703C_shared_board);
}

u16 MBCameraPos2DSet(f32* arg0) {
    D_801049F0_118610_shared_board[0] = arg0[0] / D_8010341C_11703C_shared_board + 160.0f;
    D_801049F0_118610_shared_board[1] = arg0[1] / D_8010341C_11703C_shared_board + 120.0f;
    return MBBackPosClamp(D_801049F0_118610_shared_board, D_8010341C_11703C_shared_board);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBCameraPos3DGet);

void MBCameraPos2DGet(f32 *arg0) {
    arg0[0] = -((D_801049F8_118618_shared_board[0] / 4.0f) - 160.0f);
    arg0[1] = -((D_801049F8_118618_shared_board[1] / 4.0f) - 120.0f);
}

void MBCamera3Dto2D(Vec* arg0, f32* arg1) {
    UnkCam3DStruct sp10;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f6;

    Hu3DCam3DToScreen(0, arg0, sp10.unk_00);
    temp_f6 = 2.0f * D_8010341C_11703C_shared_board;
    temp_f2 = 320.0f / temp_f6;
    sp10.unk_00[0] = (temp_f2 - (temp_f2 / D_80101250_114E70_shared_board)) + sp10.unk_00[0];
    temp_f0 = 240.0f / temp_f6;
    sp10.unk_00[1] =  (temp_f0 - (temp_f0 / D_80101250_114E70_shared_board)) + sp10.unk_00[1];
    sp10.unk_00[0] = ((sp10.unk_00[0] - 160.0f) * D_8010341C_11703C_shared_board) + 160.0f;
    sp10.unk_00[1] = ((sp10.unk_00[1] - 120.0f) * D_8010341C_11703C_shared_board) + 120.0f;
    sp10.unk_08 = (D_801049F8_118618_shared_board[0] / 4.0f) - 160.0f;
    sp10.unk_0C = (D_801049F8_118618_shared_board[1] / 4.0f) - 120.0f;
    arg1[0] = sp10.unk_00[0] + sp10.unk_08;
    arg1[1] = sp10.unk_00[1] + sp10.unk_0C;
}

void MBBackTPLvlSet(u8 arg0) {
    D_8010124C_114E6C_shared_board = arg0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBBackInvertSet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBBackFlipSet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBCameraSpeedSet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBCameraSpeedGet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBCameraStopCheck);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800E9AF0_FD710_shared_board);

void func_800E9BB0_FD7D0_shared_board(void) {
    func_800E6630_FA250_shared_board((u32)hvq_data_ROM_START);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800E9BD0_FD7F0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBCameraOffsetSet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800E9C28_FD848_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800E9C94_FD8B4_shared_board);

void func_800E9EF4_FDB14_shared_board(void) {
    s32 i;

    for (i = 0; i < 64; i++) {
        D_80104A00_118620_shared_board[i].unk_00 = 0;
    }

    D_80105200_118E20_shared_board = 0;
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800E9F24_FDB44_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EA0B8_FDCD8_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EA200_FDE20_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EA284_FDEA4_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EA2BC_FDEDC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EA2D0_FDEF0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EA2E4_FDF04_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EA320_FDF40_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EA348_FDF68_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EA358_FDF78_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EA364_FDF84_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EA4CC_FE0EC_shared_board);

void MBMasuBmpCreate(s16 arg0) {
    s32 *var_s2;
    s32 i;

    D_80105260_118E80_shared_board = arg0;

    switch (arg0) {
        case 0:
        default:
            var_s2 = D_801012C8_114EE8_shared_board;
            break;
        case 1:
            var_s2 = D_80101318_114F38_shared_board;
            break;
    }

    for (i = 0; i < SPACE_TYPES_TOTAL; i++) {
        if (var_s2[i] != 0) {
            D_80105220_118E40_shared_board[i] = DataRead(var_s2[i]);
        } else {
            D_80105220_118E40_shared_board[i] = NULL;
        }
    }
}

void MBMasuBmpKill(void) {
    s32 i;

    for (i = 0; i < SPACE_TYPES_TOTAL; i++) {
        if (D_80105220_118E40_shared_board[i] != 0) {
            DataClose(D_80105220_118E40_shared_board[i]);
        }
        D_80105220_118E40_shared_board[i] = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EA60C_FE22C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBMasuArrowAngleAdd);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EA694_FE2B4_shared_board);

void func_800EA6B0_FE2D0_shared_board(s16 arg0) {
    MBMasuBmpKill();
    MBMasuBmpCreate(arg0);
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBMasuStarSet);

void MBMasuDraw(Gfx **arg0, Mtx *arg1, s32 arg2) {
    Gfx **gfxPos = arg0;
    Mtx sp10;
    f32 sp50[2];
    Mtx *sp5C;
    u8 *sp64;
    u8 *sp6C;
    s32 sp74;
    u16 sp7E;
    s32 sp84;
    s32 sp94;
    SpaceData *temp_s0;
    s16 var_v0;
    Mtx *temp_s0_3;
    s32 i, j;
    s32 var_s5;
    u32 temp_s4;

    sp5C = arg1;
    var_s5 = 0;
    if (!(arg2 & 0xFF) && (D_80105262_118E82_shared_board != 0) && (D_801012C4_114EE4_shared_board != 0)) {
        sp7E = func_8004D6AC_4E2AC(0xC8, 0xC8, 0xC8);
        gSPDisplayList((*gfxPos)++, D_801013D8_114FF8_shared_board);
        func_80012640_13240(0, gfxPos);
        func_800127C4_133C4(0, gfxPos);
        MBCameraPos3DGet(sp50);

        if ((D_80105260_118E80_shared_board == 0) || (var_v0 = 8, (D_80105260_118E80_shared_board != 1))) {
            var_v0 = 0x10;
            sp64 = D_101358;
            sp6C = D_80101308_114F28_shared_board;
            sp74 = 0;
        } else {
            var_v0 = 8;
            sp64 = D_101398;
            sp6C = NULL;
            sp74 = 1;
        }
        // iterate over all space types
        for (i = 0; i < SPACE_TYPES_TOTAL; i++) {
            if (D_80105220_118E40_shared_board[i] != 0) {
                if (sp74 == 0) {
                    switch (sp6C[i]) {
                        case 0:
                            gDPLoadTextureBlock((*gfxPos)++, D_80105220_118E40_shared_board[i] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b,
                                                32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                            break;
                        case 1:
                            // + 0x10 to skip image header data
                            gDPLoadTextureBlock((*gfxPos)++, D_80105220_118E40_shared_board[i] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b,
                                                16, 32, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, 4, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                            break;
                        case 2:
                            gDPLoadTextureBlock((*gfxPos)++, D_80105220_118E40_shared_board[i] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b,
                                                16, 16, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
                            break;
                    }
                } else {
                    gDPLoadTextureBlock((*gfxPos)++, D_80105220_118E40_shared_board[i] + 0x10, G_IM_FMT_RGBA, G_IM_SIZ_32b,
                                        var_v0, var_v0, 0, G_TX_MIRROR | G_TX_WRAP, G_TX_MIRROR | G_TX_WRAP, 4, 4, G_TX_NOLOD, G_TX_NOLOD);
                }
                // read over a space types space array
                for (j = 0; j < gTotalSpaces; j++) {
                    s32 spaceId = D_801012C4_114EE4_shared_board[i][j];
                    if (spaceId == 0xff) {
                        break;
                    }
                    temp_s0 = MBMasuGet(spaceId);
                    func_80089980_8A580(&sp10, &sp5C[1]);
                    func_80017C10_18810(&sp10, temp_s0->coords.x, temp_s0->coords.y, temp_s0->coords.z);
                    if ((i == 0xD) && (var_s5 < D_801052B0_118ED0_shared_board)) {
                        func_800185A4_191A4(&sp10, D_80105290_118EB0_shared_board[var_s5++]);
                    }
                    func_80017CD0_188D0(&sp10, temp_s0->rot.x, 1.0f, temp_s0->rot.z);
                    temp_s0_3 = &MTXBuf[MTXBufNum++];
                    func_800898F0_8A4F0(&sp10, temp_s0_3);
                    gSPMatrix((*gfxPos)++, OS_K0_TO_PHYSICAL(temp_s0_3), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
                    gSPVertex((*gfxPos)++, sp64, 4, 0);
                    gSP1Quadrangle((*gfxPos)++, 0, 1, 2, 3, 0);
                }
            }
        }

        func_8004D6E8_4E2E8(sp7E);
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EAE00_FEA20_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBMasuCreate);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EB09C_FECBC_shared_board);

SpaceData *MBMasuGet(s16 arg0) {
    return &D_80105214_118E34_shared_board[arg0];
}

s16 MBMasuLinkMasuIdGet(u16 linkIdx, u16 spaceIdx) {
    return D_80105218_118E38_shared_board[linkIdx].spaces[spaceIdx];
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBMasuLinkNumGet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EB1CC_FEDEC_shared_board);

void func_800EB24C_FEE6C_shared_board(s16 arg0, s8 *chainOut, s8 *linkOut) {
    s32 chain;
    s32 link;

    for (chain = 0; chain < D_80105212_118E32_shared_board; chain++) {
        for (link = 0; link < MBMasuLinkNumGet(chain); link++) {
            if (MBMasuLinkMasuIdGet(chain, link) == arg0) {
                *chainOut = chain;
                *linkOut = link;
                return;
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EB310_FEF30_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EB3C0_FEFE0_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EB4F0_FF110_shared_board);

extern s16 D_801054F8_119118_shared_board;
extern u8 D_80101468_115088_shared_board[];
extern s16 D_801054B6_1190D6_shared_board;
extern s16 D_801054B8_1190D8_shared_board[];
extern s16 D_801052B8_118ED8_shared_board[];

s16 MBMasuBlockGet(u16 arg0, u8 arg1) {
    u8 var_s1;
    SpaceData *space;
    s32 i, j;
    var_s1 = 0;

    for (i = 0; i < gTotalSpaces; i++) {
        space = MBMasuGet(i);
        if (D_80101468_115088_shared_board[space->space_type & 0xF] & arg0) {
            var_s1++;
        }
    }

    var_s1 -= D_801054F8_119118_shared_board;
    if (arg1 < 5) {
        var_s1 -= D_801054B6_1190D6_shared_board;
    }

    var_s1 = MBRand(var_s1);

    for (i = 0;; i = (++i < gTotalSpaces) ? i : 0) {
        space = MBMasuGet(i);
        for (j = 0; j < D_801054F8_119118_shared_board; j++) {
            if (D_801054B8_1190D8_shared_board[j] == i) {
                break;
            }
        }

        if (j == D_801054F8_119118_shared_board) {
            if (arg1 < 5) {
                for (j = 0; j < D_801054B6_1190D6_shared_board; j++) {
                    if (D_801052B8_118ED8_shared_board[j] == i) {
                        break;
                    }
                }
                if (j == D_801054B6_1190D6_shared_board) {
                    if (D_80101468_115088_shared_board[space->space_type & 0xF] & arg0) {
                        if (var_s1 == 0) {
                            break;
                        }
                        var_s1--;
                    }
                }
            } else {
                if (D_80101468_115088_shared_board[space->space_type & 0xF] & arg0) {
                    if (var_s1 == 0) {
                        break;
                    }
                    var_s1--;
                }
            }
        }
    }

    return i;
}

void MBMasuTypeSet(s16 spaceIdx, s32 newSpaceType) {
    MBMasuGet(spaceIdx)->space_type = newSpaceType;
}

// unused, sets all space types in a link to a new type
void func_800EB820_FF440_shared_board(u16 linkNo, u16 curSpaceType, u8 newSpaceType) {
    s32 linkSpaceCount;
    SpaceData *space;
    s32 i;

    linkSpaceCount = MBMasuLinkNumGet(linkNo);

    for (i = 0; i < linkSpaceCount; i++) {
        space = MBMasuGet(MBMasuLinkMasuIdGet(linkNo, i));
        if (space->space_type == curSpaceType) {
            space->space_type = newSpaceType;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EB8BC_FF4DC_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EB97C_FF59C_shared_board);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBMasuEventSet);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBMasuEventTblAdd);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", MBMasuEventCall);

INCLUDE_ASM("asm/nonmatchings/overlays/ovl_80_shared_board/FA250", func_800EBCB0_FF8D0_shared_board);

void MBMasuCurSet(s16 arg0) {
    GwSystem.current_space_index = arg0;
}

s16 MBMasuCurGet(void) {
    return GwSystem.current_space_index;
}

s16 MBMasuKakusiBlockGet(u8 arg0) {
    return MBMasuBlockGet((1 << SPACE_BLUE), arg0);
}

void MBMasuBlockTblExtSet(s16 *arg0) {
    s32 i;

    for (i = 0; *arg0 != -1; i++) {
        D_801052B8_118ED8_shared_board[i] = *arg0++;
    }
    
    D_801054B6_1190D6_shared_board = i;
}

void MBMasuBlockTblSet(s16 *arg0) {
    s32 i;

    for (i = 0; *arg0 != -1; i++) {
        D_801054B8_1190D8_shared_board[i] = *arg0++;
    }
    
    D_801054F8_119118_shared_board = i;
}

void func_800EBDAC_FF9CC_shared_board(void) {
    s32 var_s0;
    s32 i, j;

    if (D_801012C4_114EE4_shared_board != NULL) {
        HuMemMemoryFreeTemp(D_801012C4_114EE4_shared_board);
    }

    D_801012C4_114EE4_shared_board = HuMemMemoryAllocTemp(SPACE_TYPES_TOTAL * SPACES_MAX);

    for (i = 0; i < SPACE_TYPES_TOTAL; i++) {
        var_s0 = 0;

        for (j = 0; j < gTotalSpaces; j++) {
            if (MBMasuGet(j)->space_type == i) {
                D_801012C4_114EE4_shared_board[i][var_s0] = j;
                var_s0++;
            }
        }

        D_801012C4_114EE4_shared_board[i][var_s0] = 0xFF;
        D_80105268_118E88_shared_board[i] = var_s0;
    }
}

u8 func_800EBEAC_FFACC_shared_board(s32 arg0, s32 arg1) {
    return D_801012C4_114EE4_shared_board[arg0][arg1];
}

void MBMasuDispOn(void) {
    D_80105262_118E82_shared_board = 1;
}

void MBMasuDispOff(void) {
    D_80105262_118E82_shared_board = 0;
}

