#include "common.h"

void func_80107744_39CAC4_WaluigisIsland(void);
void func_80107780_39CB00_WaluigisIsland(void);
void func_80107B54_39CED4_WaluigisIsland(void);
void func_80107BD8_39CF58_WaluigisIsland(void);
void func_8011A848_3AFBC8_WaluigisIsland(void);

OvlEntrypoint D_8011B550_3B08D0_WaluigisIsland[] = {
    {0, func_80107744_39CAC4_WaluigisIsland},
    {1, func_80107780_39CB00_WaluigisIsland},
    {2, func_80107B54_39CED4_WaluigisIsland},
    {3, func_80107BD8_39CF58_WaluigisIsland},
    {4, func_8011A848_3AFBC8_WaluigisIsland},
    {-1, NULL},
};

void func_801059A0_39AD20_WaluigisIsland(void) {
    ovlEventCall(D_8011B550_3B08D0_WaluigisIsland, omovlevtno);
}
