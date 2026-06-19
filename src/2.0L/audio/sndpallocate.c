#include "common.h"
#include "PR/sndp.h"

ALSndId alSndpAllocate(ALSound *sound) {
    ALSndPlayer *sndp = D_800A2884_A3484->sndp;
    ALSoundState *sState = sndp->sndState;
    ALSndId i;

    for (i = 0; i < sndp->maxSounds; i++) {
        if (sState[i].sound == NULL) {
            sState[i].sound = sound;
            sState[i].priority = AL_DEFAULT_PRIORITY;
            sState[i].state = AL_STOPPED;
            sState[i].pitch = 1.0f;
            sState[i].pan = AL_PAN_CENTER;
            sState[i].fxMix = AL_DEFAULT_FXMIX;
            sState[i].vol = 32767 * sound->sampleVolume / AL_VOL_FULL;
            return i;
        }
    }

    return -1;
}
