#include "common.h"

void ovlEventCall(OvlEntrypoint *arg0, s16 arg1) {
    OvlEntrypoint *entry = arg0;

    for (; entry->index >= 0; entry++) {
        if (entry->index == arg1) {
            entry->fn();
        }
    }
}
