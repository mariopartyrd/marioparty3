#include "common.h"
#include "../ovl_80_shared_board/ovl_80.h"

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801059A0_3CDEC0_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80105AFC_3CE01C_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80105C7C_3CE19C_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80105DE0_3CE300_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80105FA8_3CE4C8_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801060B4_3CE5D4_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80106184_3CE6A4_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801061CC_3CE6EC_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80106254_3CE774_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801062E8_3CE808_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801063A4_3CE8C4_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801068E4_3CEE04_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80106990_3CEEB0_opboardtutorial);

INCLUDE_RODATA("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", D_80107740_3CFC60_opboardtutorial);

INCLUDE_RODATA("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", D_80107744_3CFC64_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80106F40_3CF460_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80107408_3CF928_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80107448_3CF968_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801074A4_3CF9C4_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801074E8_3CFA08_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_8010751C_3CFA3C_opboardtutorial);

void func_80107550_3CFA70_opboardtutorial(void) {
    Hu3DCamInit(1);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    func_800E6630_FA250_shared_board(hvq_data_ROM_START);
    MBBackKill(0x15);
}

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80107594_3CFAB4_opboardtutorial);
