#include "common.h"

s32 alCSPGetChlProgram(ALCSPlayer *seqp, u8 chan) {
    ALBank *bank = seqp->bank;
    ALChanState chanState = seqp->chanState[chan];
    s32 i;

    for (i = 0; i < bank->instCount; i++) {
        if (bank->instArray[i] == chanState.instrument) {
            return i;
        }
    }

    return -1;
}
