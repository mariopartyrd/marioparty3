#include "common.h"

void func_80105AAC_3D725C_name_58(void);
void func_80105ACC_3D727C_name_58(void);

/* .data */
OvlEntrypoint D_80105EE0_3D7690_name_58[] = {
    {0, func_80105AAC_3D725C_name_58},
    {1, func_80105ACC_3D727C_name_58},
    {-1, NULL},
};

void func_801059A0_3D7150_name_58(void) {
    ovlEventCall(D_80105EE0_3D7690_name_58, omovlevtno);
}