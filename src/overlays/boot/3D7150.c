#include "common.h"

void func_80105AAC_3D725C_ovl_boot(void);
void func_80105ACC_3D727C_ovl_boot(void);

/* .data */
OvlEntrypoint D_80105EE0_3D7690_ovl_boot[] = {
    {0, func_80105AAC_3D725C_ovl_boot},
    {1, func_80105ACC_3D727C_ovl_boot},
    {-1, NULL},
};

void func_801059A0_3D7150_ovl_boot(void) {
    ovlEventCall(D_80105EE0_3D7690_ovl_boot, omovlevtno);
}