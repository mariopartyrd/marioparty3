#include "common.h"
#include "PR/sndp.h"

void alSndpDeallocate(ALSndId id) {
    ALSndPlayer *sndp = D_800A2884_A3484->sndp;
    ALSoundState *sState = sndp->sndState;

    if (sState[id].state != AL_STOPPED) {
        return;
    }

    sState[id].sound = NULL;
    if (sndp->target == id) {
        sndp->target = -1;
    }
}
