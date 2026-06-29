#include "common.h"

ALPan alCSPGetChlPan(ALCSPlayer *seqp, u8 chan) {
    return seqp->chanState[chan].pan;
}
