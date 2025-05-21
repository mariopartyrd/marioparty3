// overlay.h
#ifndef OVERLAY_H
#define OVERLAY_H

#include "common.h"    // whatever you need for u8*

typedef struct OverlayTable {
/* 0x00 */ u8* romStart;
/* 0x04 */ u8* romEnd;
/* 0x08 */ u8* vramStart;
/* 0x0C */ u8* textVramStart;
/* 0x10 */ u8* textVramEnd;
/* 0x14 */ u8* dataVramStart;
/* 0x18 */ u8* dataVramEnd;
/* 0x1C */ u8* bssVramStart;
/* 0x20 */ u8* bssVramEnd;
} OverlayTable; //sizeof 0x24


// the enum of all your overlay IDs:
typedef enum {
  #define OVL_DEFINE(name)  name,
    #include "ovl_table.h"
  #undef OVL_DEFINE

    OVL_COUNT
} OverlayID;

typedef enum {
  #define OVL_DEFINE(name)  name,
    #include "ovl_table2.h"
  #undef OVL_DEFINE

    MODE_OVL_COUNT
} ModeOverlayID;

extern OverlayTable _ovltbl[OVL_COUNT];
extern OverlayTable _modeovltbl[MODE_OVL_COUNT];

#endif // OVERLAY_H