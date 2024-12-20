#include "common.h"
#include "obj.h"

void _SetFlag(s32);
void _ClearFlag(s32);
s32 GWBoardFlagCheck(s32);
void _ClearFlag(s32);
void func_800ECF9C_100BBC(s8);
void func_800F8610_10C230(s32, s32, s32);
void func_800F8D84_10C9A4();
extern s16 D_800CD2A2;
extern s16 D_800D6A48;
extern s16 D_800D6B60;
extern s16 D_800CD2A2;
extern s16 D_800D4196;
extern s16 D_800D6A48;
extern s16 D_800D6B60;
extern omOvlHisData D_800D20F0[12];
extern s32 D_80101B40_115760[];

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8610_10C230);

void func_800F86B4_10C2D4(void) {
    D_800CD2A2 = 1;
    D_800D6B60 = 0;
    if (GWBoardFlagCheck(1) == 0) {
        if ((GwSystem.current_board_index != 6) && (func_800F8610_10C230(-2, 4, 0x192), (GwSystem.current_board_index != 6))) {
            func_800F8610_10C230(0x53, 0, 0x192);
        } else {
            func_800F8610_10C230(0x54, 0, 0x192);
        }
        
        func_800F8610_10C230(-2, 1, 0x192);
    }
    func_800F8D84_10C9A4();
    func_800ECF9C_100BBC(GwSystem.unk14);
    _ClearFlag(0xC);
    D_800D6A48 = 0;
}

void func_800F8774_10C394(void) {
    omOvlHisData* ovlHisData;

    D_800D4196 = 1;
    if (D_800D6B60 != 0) {
        ovlHisData = &D_800D20F0[--D_800D6B60];
        omOvlCallEx(ovlHisData->overlayID, ovlHisData->event, ovlHisData->stat);
        return;
    }
    if (D_800CD2A2 != 0) {
        D_800D4196 = 0;
        omOvlCallEx(D_80101B40_115760[GwSystem.current_board_index], 2, 0x192U);
        return;
    }
    if (D_800D6A48 != 0) {
        _SetFlag(0xC);
    } else {
        _ClearFlag(0xC);
    }
    omOvlReturnEx(1);
}


INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F884C_10C46C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8858_10C478);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8864_10C484);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F88D0_10C4F0);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F88FC_10C51C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8908_10C528);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F89D0_10C5F0);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8C74_10C894);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8D48_10C968);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8D54_10C974);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8D60_10C980);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8D6C_10C98C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8D78_10C998);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F8D84_10C9A4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F915C_10CD7C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9168_10CD88);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9174_10CD94);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9198_10CDB8);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F91A4_10CDC4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F92A0_10CEC0);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F933C_10CF5C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F93A4_10CFC4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F95FC_10D21C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F965C_10D27C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F96E0_10D300);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9A68_10D688);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9C68_10D888);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9CA0_10D8C0);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9D1C_10D93C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800F9F84_10DBA4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FA104_10DD24);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FA388_10DFA8);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FA448_10E068);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FA640_10E260);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FA818_10E438);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FA95C_10E57C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FAB98_10E7B8);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FB578_10F198);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FB624_10F244);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC3D0_10FFF0);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC4E0_110100);

extern s16 gCoinBlockSpaceIndex;
extern s16 gStarBlockSpaceIndex;
extern s16 gItemBlockSpaceIndex;
extern u16 D_800D03FC;
extern u16 D_800CE208;
extern u16 D_800CDD68;

extern s16 gPrevCoinBlockIndexes[];
extern s16 gPrevStarBlockIndexes[];
extern s16 gPrevItemBlockIndexes[];

s16 func_800EBCD4_FF8F4(u8);
s32 GWBoardFlagCheck(s32 input);

void func_800FC594_1101B4(void) {
    s32 i;

    if (GWBoardFlagCheck(0xF) != 0) {
        while (gCoinBlockSpaceIndex == -1 || gCoinBlockSpaceIndex == gStarBlockSpaceIndex || gCoinBlockSpaceIndex == gItemBlockSpaceIndex) {
            gCoinBlockSpaceIndex = func_800EBCD4_FF8F4(D_800D03FC);
            D_800D03FC += 1;
            for (i = 0; i < 10; i++) {
                if (gCoinBlockSpaceIndex == gPrevCoinBlockIndexes[i]) {
                    break;
                }
            }
            if (i != 0xA) {
                gCoinBlockSpaceIndex = -1;
            }
        }
        while (gStarBlockSpaceIndex == -1 || gCoinBlockSpaceIndex == gStarBlockSpaceIndex || gItemBlockSpaceIndex == gStarBlockSpaceIndex) {
            gStarBlockSpaceIndex = func_800EBCD4_FF8F4(D_800CE208);
            D_800CE208 += 1;
            for (i = 0; i < 10; i++) {
                if (gStarBlockSpaceIndex == gPrevStarBlockIndexes[i]) {
                    break;
                }
            }
            if (i != 0xA) {
                gStarBlockSpaceIndex = -1;
            }
        }
        
        while (gItemBlockSpaceIndex == -1 || gCoinBlockSpaceIndex == gItemBlockSpaceIndex || gStarBlockSpaceIndex == gItemBlockSpaceIndex) {
            gItemBlockSpaceIndex = func_800EBCD4_FF8F4(D_800CDD68);
            D_800CDD68 += 1;
            for (i = 0; i < 10; i++) {
                if (gItemBlockSpaceIndex == gPrevItemBlockIndexes[i]) {
                    break;
                }
            }
            if (i != 0xA) {
                gItemBlockSpaceIndex = -1;
            }
        }
    }
}

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC7C8_1103E8);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC8A4_1104C4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC938_110558);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC968_110588);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC998_1105B8);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FC9E0_110600);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FCA14_110634);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FCA4C_11066C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FCA7C_11069C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF0F8_112D18);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF158_112D78);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF41C_11303C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF75C_11337C);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF788_1133A8);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF794_1133B4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF7C4_1133E4);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF7F0_113410);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF800_113420);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF834_113454);

INCLUDE_ASM(s32, "overlays/shared_board/10C230", func_800FF840_113460);
