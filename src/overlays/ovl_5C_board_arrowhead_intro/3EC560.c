#include "common.h"

void func_80105B64_3EC724_board_arrowhead_intro(void);
void func_80105BA0_3EC760_board_arrowhead_intro(void);
void func_8010DA88_3F4648_board_arrowhead_intro(void);
void func_8010DB04_3F46C4_board_arrowhead_intro(void);

board_overlay_entrypoint D_80116570_3FD130_board_arrowhead_intro[] = {
    {0, func_80105B64_3EC724_board_arrowhead_intro},
    {1, func_80105BA0_3EC760_board_arrowhead_intro},
    {2, func_8010DA88_3F4648_board_arrowhead_intro},
    {3, func_8010DB04_3F46C4_board_arrowhead_intro},
    {-1, NULL}
};

void func_801059A0_3EC560_board_arrowhead_intro(void) {
    ovlEventCall(D_80116570_3FD130_board_arrowhead_intro, omovlevtno);
}