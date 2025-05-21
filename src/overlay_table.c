#include "common.h"

u8 D_800962F0_96EF0[] = {0, 0, 0, 0};

#define OVL_ENTRY(name) \
    { name##_ROM_START, name##_ROM_END, name##_VRAM, \
      name##_TEXT_START, name##_TEXT_END, \
      name##_DATA_START, name##_RODATA_END, \
      name##_BSS_START,  name##_BSS_END }


OverlayTable _ovltbl[OVL_COUNT] = {
  #define OVL_DEFINE(name)  OVL_ENTRY(name),
    #include "ovl_table.h"
  #undef OVL_DEFINE
};

//holds overlays that are loaded in addition to boards/duel mode
OverlayTable _modeovltbl[MODE_OVL_COUNT] = {
  #define OVL_DEFINE(name)  OVL_ENTRY(name),
    #include "ovl_table2.h"
  #undef OVL_DEFINE
};
