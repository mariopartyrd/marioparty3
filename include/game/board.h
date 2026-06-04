#ifndef _BOARD_H
#define _BOARD_H

#include "ultra64.h"

struct event_list_entry {
    s16 activation_type;
    s16 execution_type;
    void (*event_fn)();
};

struct event_table_entry {
    s16 space_index;
    struct event_list_entry *event_list;
};

typedef struct Unk800CD2A0 {
    u8 unk_00;
    s16 unk_02;
} Unk800CD2A0;

extern Unk800CD2A0 D_800CD2A0_CDEA0;
extern omOvlHisData D_800D4190_D4D90;

#endif //_BOARD_H