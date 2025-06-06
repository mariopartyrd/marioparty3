#include "common.h"

void func_800F86B4_10C2D4_shared_board(void);
void func_800F8774_10C394_shared_board(void);

//entry 0
void func_801059D0_31B3E0_name_47(void) {
    if (_CheckFlag(0) != 0) {
        GWBoardFlagSet(1);
    } else {
        GWBoardFlagClear(1);
    }
    omInitObjMan(0xA, 0);
    func_800F86B4_10C2D4_shared_board();
    omOvlGotoEx(name_47, 1, 0x192);
    omOvlHisChg(0, name_47, 1, 0x192);
}

//entry 1
void func_80105A44_31B454_name_47(void) {
    omInitObjMan(0xA, 0);
    func_800F8774_10C394_shared_board();
}

void func_80105A6C_31B47C_name_47(void) {
    omOvlReturnEx(1);
    omOvlKill();
    HuPrcVSleep();
}

//entry 2
void func_80105A98_31B4A8_name_47(void) {
    omInitObjMan(0xA, 0xA);
    func_8004A208_4AE08();
    omAddPrcObj(func_80105A6C_31B47C_name_47, 0x1005, 0, 0);
}
