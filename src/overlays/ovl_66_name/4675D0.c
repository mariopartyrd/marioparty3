#include "common.h"

void func_801059D0_467600_name_66(void);

board_overlay_entrypoint D_801066E0_468310_name_66[] = {
    {0, func_801059D0_467600_name_66},
    {-1, NULL}
};

void func_801059A0_4675D0_name_66(void) {
    ovlEventCall(D_801066E0_468310_name_66, omovlevtno);
}