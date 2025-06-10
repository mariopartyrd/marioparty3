#include "game/hmflight.h"
#include "include_asm.h"

INCLUDE_ASM("asm/nonmatchings/hmflight", HmfLightInit);

void HmfLightClose(void) {
}

INCLUDE_ASM("asm/nonmatchings/hmflight", HmfLightExec);

INCLUDE_ASM("asm/nonmatchings/hmflight", HmfLightReset);

INCLUDE_ASM("asm/nonmatchings/hmflight", HmfLightMaxSet);

INCLUDE_ASM("asm/nonmatchings/hmflight", HmfLightStatSet);

INCLUDE_ASM("asm/nonmatchings/hmflight", HmfLightColorSet);

INCLUDE_ASM("asm/nonmatchings/hmflight", HmfLightDirSet);

INCLUDE_ASM("asm/nonmatchings/hmflight", func_80019668_1A268);

INCLUDE_ASM("asm/nonmatchings/hmflight", func_80019828_1A428);

INCLUDE_ASM("asm/nonmatchings/hmflight", func_80019968_1A568);
