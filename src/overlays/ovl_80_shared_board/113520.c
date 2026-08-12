#include "common.h"
#include "ovl_80.h"

void func_800FFA0C_11362C_shared_board(void);
extern s8 D_80101E80_115AA0_shared_board[];

void MBPlayerVibrate(s16 playerIndex, s16 vibrationStrength) {
    if (playerIndex == CUR_PLAYER) {
        playerIndex = MBPlayerTurnGet();
    }
    if (playerIndex != 4) {
        switch (vibrationStrength) {
            case 0:
                omVibrate(playerIndex, 5, 0, 5);
                break;
            case 1:
                omVibrate(playerIndex, 2, 3, 10);
                break;
            case 2:
                omVibrate(playerIndex, 10, 0, 10);
                break;
            case 3:
                omVibrate(playerIndex, 2, 2, 20);
                break;
            case 4:
                omVibrate(playerIndex, 20, 0, 20);
                break;
            case 5:
                omVibrate(playerIndex, 30, 0, 30);
                break;
        }
    }
}

void func_800FFA0C_11362C_shared_board(void) {
    UnkVibrateProcess* temp_s0;

    temp_s0 = HuPrcCurrentGet()->user_data;
    while (1) {
        MBPlayerVibrate(temp_s0->playerNo, temp_s0->vibrateStrength);
        HuPrcSleep(temp_s0->sleepTime);        
    }
}

UnkVibrateProcess* MBPlayerVibrateObjCreate(s16 playerNo, s16 vibrateStrength, s32 sleepTime) {
    Process* temp_v0_2;
    s16 temp_s1;
    UnkVibrateProcess* temp_v0;
    s8 temp;

    temp_s1 = D_80101E80_115AA0_shared_board[vibrateStrength] + sleepTime;
    temp_v0 = HuMemMemoryAllocTemp(sizeof(UnkVibrateProcess));
    if (temp_v0 != NULL) {
        temp_v0->playerNo = playerNo;
        temp_v0->vibrateStrength = vibrateStrength;
        temp_v0->sleepTime = (temp_s1 - 1);
        temp_v0_2 = omAddPrcObj(func_800FFA0C_11362C_shared_board, 0x1005, 0, 0);
        temp_v0->proc = temp_v0_2;
        temp_v0_2->user_data = temp_v0;
    }
    return temp_v0;
}

void MBPlayerVibrateObjKill(UnkVibrateProcess* arg0) {
    if (arg0 != NULL) {
        omDelPrcObj(arg0->proc);
        HuMemMemoryFreeTemp(arg0);
    }
}
