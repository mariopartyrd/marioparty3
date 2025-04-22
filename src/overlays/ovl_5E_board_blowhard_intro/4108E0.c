#include "common.h"

void func_80105B64_410AA4_board_blowhard_intro(void);
void func_80105BA0_410AE0_board_blowhard_intro(void);
void func_8010DA88_4189C8_board_blowhard_intro(void);
void func_8010DB10_418A50_board_blowhard_intro(void);

board_overlay_entrypoint D_80119C70_424BB0_board_blowhard_intro[] = {
    {0, func_80105B64_410AA4_board_blowhard_intro},
    {1, func_80105BA0_410AE0_board_blowhard_intro},
    {2, func_8010DA88_4189C8_board_blowhard_intro},
    {3, func_8010DB10_418A50_board_blowhard_intro},
    {-1, NULL}
};

void func_801059A0_4108E0_board_blowhard_intro(void) {
    ovlEventCall(D_80119C70_424BB0_board_blowhard_intro, omovlevtno);
}
