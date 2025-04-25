#include "common.h"

void ovlEventCall(OvlEntrypoint* arg0, s16 arg1) {
    OvlEntrypoint* entry = arg0;
    s32 i;

    for (i = 0; entry->index >= 0; i++, entry++) {
        if (entry->index == arg1) {
            entry->fn();
        }
    }
}