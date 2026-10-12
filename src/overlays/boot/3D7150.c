#include "common.h"

void func_80105AAC_ovl_boot(void);
void func_80105ACC_ovl_boot(void);

/* .data */
OvlEntrypoint D_80105EE0_ovl_boot[] = {
    { 0, func_80105AAC_ovl_boot },
    { 1, func_80105ACC_ovl_boot },
    { -1, NULL },
};

void func_801059A0_ovl_boot(void) {
    ovlEventCall(D_80105EE0_ovl_boot, omovlevtno);
}
