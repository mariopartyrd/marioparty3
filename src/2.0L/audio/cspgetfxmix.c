#include "common.h"

u8 alCSPGetChlFXMix(ALCSPlayer *seqp, u8 chan) {
    return seqp->chanState[chan].fxmix;
}
