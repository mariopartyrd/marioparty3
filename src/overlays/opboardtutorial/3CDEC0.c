#include "common.h"
#include "../ovl_80_shared_board/FA250.h"

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801059A0_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80105AFC_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80105C7C_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80105DE0_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80105FA8_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801060B4_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80106184_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801061CC_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80106254_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801062E8_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801063A4_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801068E4_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80106990_opboardtutorial);

INCLUDE_RODATA("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", D_80107740_opboardtutorial);

INCLUDE_RODATA("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", D_80107744_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80106F40_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80107408_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_80107448_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801074A4_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_801074E8_opboardtutorial);

INCLUDE_ASM("asm/nonmatchings/overlays/opboardtutorial/3CDEC0", func_8010751C_opboardtutorial);

void func_80107550_opboardtutorial(void) {
    Hu3DCamInit(1);
    HmfLightColorSet(1, 0xFF, 0xFF, 0xFF);
    func_800E6630_shared_board((u32)hvq_data_ROM_START);
    MBBackLoad(0x15);
}

void func_80107594_opboardtutorial() {
    MBBackKill();
    MBBackClose();
}
