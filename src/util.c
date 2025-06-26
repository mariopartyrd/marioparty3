#include "common.h"
#include "game/util.h"
#include "game/camera.h"
#include "game/data.h"
#include "game/hmfman.h"
#include "overlay.h"
#include "rom.h"

#define HAS_TEXT_SECTION 1
#define HAS_DATA_SECTION 2
#define HAS_BSS_SECTION 4

#ifdef MOD
extern OverlayTable mod_ovltbl[];
extern OverlayTable mod_modeovltbl[];
#else
extern OverlayTable _ovltbl[];
extern OverlayTable _modeovltbl[];
#endif


extern u8 D_800962F0_96EF0;
extern u32 rnd_seed;
extern RectF D_800975F0_981F0[];
extern Vec D_80097560_98160[];
extern Vec D_800975A8_981A8[];
extern s16 gNumOfControllers;

u16 func_8000B0A0_BCA0(s32 arg0, s32 arg1) {
    return Hu3DModelCreate(DataRead(arg0), arg1);
}

u16 func_8000B0D4_BCD4(s32 arg0, s32 arg1) {
    return Hu3DModelCreate(DataRead(arg0), arg1);
}

u16 func_8000B108_BD08(s32 arg0, s32 arg1) {
    return Hu3DModelCreate(DataRead(arg0), arg1);
}

s16 func_8000B13C_BD3C(s32 arg0) {
    return Hu3DModelCreate(DataRead(arg0), 0x1D);
}

u8 rand8(void) {
    rnd_seed = rnd_seed* 0x41C64E6D + 0x3039;
    return ((rnd_seed + 1) >> 16);
}

//checks if the overlay has a text, data, and bss section and dmas/clears the region if so
void func_8000B1A0_BDA0(s32 arg0, u8 sectionFlags) {
    u8* textVramEnd;
    u8* textVramStart;
    u8* romStart;
    u8* dataVramStart;
    u8* dataVramEnd;
    u8* bss_end;
    u8* bss_start;
    u8* curBssAddr;
    u8* textStart;
    u8* tmp;

    #ifdef MOD
    romStart = mod_modeovltbl[arg0].romStart;
    textVramStart = mod_modeovltbl[arg0].textVramStart;
    textVramEnd = mod_modeovltbl[arg0].textVramEnd;
    dataVramStart = mod_modeovltbl[arg0].dataVramStart;
    dataVramEnd = mod_modeovltbl[arg0].dataVramEnd;
    bss_start = mod_modeovltbl[arg0].bssVramStart;
    bss_end = mod_modeovltbl[arg0].bssVramEnd;
    textStart = mod_modeovltbl[arg0].vramStart;
    #else
    romStart = _modeovltbl[arg0].romStart;
    textVramStart = _modeovltbl[arg0].textVramStart;
    textVramEnd = _modeovltbl[arg0].textVramEnd;
    dataVramStart = _modeovltbl[arg0].dataVramStart;
    dataVramEnd = _modeovltbl[arg0].dataVramEnd;
    bss_start = _modeovltbl[arg0].bssVramStart;
    bss_end = _modeovltbl[arg0].bssVramEnd;
    textStart = _modeovltbl[arg0].vramStart;
    #endif


    if (sectionFlags & HAS_TEXT_SECTION) {
        dmaReadOvl(romStart, textStart, textVramEnd - textVramStart);
    }
    if (sectionFlags & HAS_DATA_SECTION) {
        dmaReadOvl(romStart + (textVramEnd - textVramStart), dataVramStart, dataVramEnd - dataVramStart);
    }
    if (sectionFlags & HAS_BSS_SECTION) {
        curBssAddr = tmp = bss_start;
        while (tmp < bss_end) {
            *curBssAddr++ = 0;
            tmp++;
        }
    }
}

// copies in an overlay and clears bss region.
void OvlLoad(s32 overlayIndex) {
    u8* rom_start;
    u8* rom_end;
    u8* bss_start;
    u8* bss_end;
    u8* curBssAddr;

    #ifdef MOD
    rom_start = mod_ovltbl[overlayIndex].romStart;
    rom_end = mod_ovltbl[overlayIndex].romEnd;
    bss_start = mod_ovltbl[overlayIndex].bssVramStart;
    bss_end = mod_ovltbl[overlayIndex].bssVramEnd;
    dmaReadOvl(rom_start, mod_ovltbl[overlayIndex].vramStart, rom_end - rom_start);
    #else
    rom_start = _ovltbl[overlayIndex].romStart;
    rom_end = _ovltbl[overlayIndex].romEnd;
    bss_start = _ovltbl[overlayIndex].bssVramStart;
    bss_end = _ovltbl[overlayIndex].bssVramEnd;
    dmaReadOvl(rom_start, _ovltbl[overlayIndex].vramStart, rom_end - rom_start);
    #endif

    curBssAddr = bss_start;
    while (bss_start < bss_end) {
        *curBssAddr++ = 0;
        bss_start++;
    }

    D_800962F0_96EF0 = 0;
}

void ScissorSet(u8 camIndex, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    D_800975F0_981F0[camIndex].x1 = arg1;
    D_800975F0_981F0[camIndex].y1 = arg2;
    D_800975F0_981F0[camIndex].x2 = arg3;
    D_800975F0_981F0[camIndex].y2 = arg4;
    CameraScissorSet(camIndex, &D_800975F0_981F0[camIndex]);
}

void ViewportSet(u8 camIndex, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    D_80097560_98160[camIndex].x = arg1;
    D_80097560_98160[camIndex].y = arg2;
    D_80097560_98160[camIndex].z = arg3;

    D_800975A8_981A8[camIndex].x = arg4;
    D_800975A8_981A8[camIndex].y = arg5;
    D_800975A8_981A8[camIndex].z = arg6;

    CameraViewportSet(camIndex, &D_80097560_98160[camIndex], &D_800975A8_981A8[camIndex]);
}

void func_8000B460_C060(omObjData* arg0, u16 arg1, s32 arg2) {
    s16 temp_v0;

    temp_v0 = func_8000B13C_BD3C(arg2);
    if ((temp_v0 >= 0)) {
        arg0->motion[arg1] = temp_v0;
    }
}

s8 func_8000B4B4_C0B4(void) {
    s8 temp_v1;

    if (gNumOfControllers > D_800962F0_96EF0) {
        temp_v1 = D_800962F0_96EF0++;
    } else {
        temp_v1 = -1;
    }
    return temp_v1;
}

u16 SprModelRead(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    void* temp_v0;

    temp_v0 = DataRead(arg0);
    temp_s0 = HmfSprModelCreate(temp_v0, arg1, arg2);
    HuMemMemoryFreePerm(temp_v0);
    return temp_s0;
}

s16 HmfAnimRead(s32 arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;
    void* temp_v0;

    temp_v0 = DataRead(arg1);
    temp_s0 = HmfAnimCreate(arg0, temp_v0, 0, arg2);
    HuMemMemoryFreePerm(temp_v0);
    return temp_s0;
}

s16 func_8000B5BC_C1BC(s32 arg0) {
    return Hu3DModelCreate(DataReadNum(arg0, 0x7918), 0);
}
