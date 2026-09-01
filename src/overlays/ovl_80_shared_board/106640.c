#include "common.h"
#include "106640.h"
#include "malloc.h"
#include "mallocblock.h"

extern UnkBoard8 *D_80105570_119190_shared_board;
extern u16 D_80105574_119194_shared_board;

void func_800F2A20_106640_shared_board(void) {
    D_80105570_119190_shared_board = NULL;
    D_80105574_119194_shared_board = 0;
}

void func_800F2A34_106654_shared_board(void) {
    while (D_80105570_119190_shared_board != NULL) {
        func_800F2CA4_1068C4_shared_board(D_80105570_119190_shared_board);
    }
}

static UnkBoard8 *func_800F2A74_106694_shared_board(s16 amount) {
    UnkBoard8 *temp_v0;
    s32 i;

    temp_v0 = HuMemMemoryAllocTemp(sizeof(UnkBoard8));
    if (temp_v0 != NULL) {
        D_80105574_119194_shared_board++;
        temp_v0->unk_00 = D_80105570_119190_shared_board;
        temp_v0->unk_04 = 0;

        if (D_80105570_119190_shared_board != NULL) {
            D_80105570_119190_shared_board->unk_04 = temp_v0;
        }

        D_80105570_119190_shared_board = temp_v0;
        temp_v0->amount = amount;

        temp_v0->model = HuMemMemoryAllocTemp(amount * (sizeof *temp_v0->model));
        for (i = 0; i < amount; i++) {
            temp_v0->model[i] = -1;
        }

        temp_v0->unk_10 = HuMemMemoryAllocTemp(amount * (sizeof *temp_v0->unk_10));
        for (i = 0; i < amount; i++) {
            temp_v0->unk_10[i] = 1.0f;
        }

        temp_v0->unk_14 = HuMemMemoryAllocTemp(amount * (sizeof *temp_v0->unk_14));
        for (i = 0; i < amount; i++) {
            temp_v0->unk_14[i] = 1.0f;
        }

        temp_v0->xPositions = HuMemMemoryAllocTemp(amount * (sizeof *temp_v0->xPositions));
        for (i = 0; i < amount; i++) {
            temp_v0->xPositions[i] = 0;
        }

        temp_v0->yPositions = HuMemMemoryAllocTemp(amount * (sizeof *temp_v0->yPositions));
        for (i = 0; i < amount; i++) {
            temp_v0->yPositions[i] = 0;
        }
    }
    return temp_v0;
}

UnkBoard8 *func_800F2C48_106868_shared_board(s16 arg0, s16 arg1) {
    UnkBoard8 *temp_v0;

    temp_v0 = func_800F2A74_106694_shared_board(arg0);
    if (temp_v0 != NULL) {
        temp_v0->spriteGroup = HuSprGrpCreate(arg0, arg1);
    }
    return temp_v0;
}

void func_800F2CA4_1068C4_shared_board(UnkBoard8* arg0) {
    s16 model;
    s32 i;

    if (arg0->unk_00 != NULL) {
        arg0->unk_00->unk_04 = arg0->unk_04;
    }

    if (arg0->unk_04 != NULL) {
        arg0->unk_04->unk_00 = arg0->unk_00;
    } else {
        D_80105570_119190_shared_board = arg0->unk_00;
    }

    for (i = 0; i < arg0->amount; i++) {
        model = arg0->model[i];
        if (model >= 0) {
            HuSprKill(model);
        }
    }

    HuSprGrpKill(arg0->spriteGroup);
    HuMemMemoryFreeTemp(arg0->xPositions);
    HuMemMemoryFreeTemp(arg0->yPositions);
    HuMemMemoryFreeTemp(arg0->unk_10);
    HuMemMemoryFreeTemp(arg0->unk_14);
    HuMemMemoryFreeTemp(arg0->model);
    HuMemMemoryFreeTemp(arg0);
    D_80105574_119194_shared_board--;
}

//unused
void func_800F2D8C_1069AC_shared_board(UnkBoard8* arg0, s16 member, s16 x, s16 y) {
    arg0->xPositions[member] = x;
    arg0->yPositions[member] = y;
    func_80054904_55504(arg0->spriteGroup, member, x, y);
}

//unused
void func_800F2DDC_1069FC_shared_board(UnkBoard8 *arg0, s16 member, f32 arg2, f32 arg3) {
    arg0->unk_10[member] = arg2; //rot?
    arg0->unk_14[member] = arg3; //scale?
    HuSprScaleSet(arg0->spriteGroup, member, arg2, arg3);
}
