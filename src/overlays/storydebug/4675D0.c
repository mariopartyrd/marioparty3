#include "common.h"

void func_801059D0_storydebug(void);

OvlEntrypoint D_801066E0_storydebug[] = {
    { 0, func_801059D0_storydebug },
    { -1, NULL }
};

void func_801059A0_storydebug(void) {
    ovlEventCall(D_801066E0_storydebug, omovlevtno);
}
