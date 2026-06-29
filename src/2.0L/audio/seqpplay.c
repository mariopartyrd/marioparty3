#include "common.h"

void alSeqpPlay(ALSeqPlayer *seqp) {
    ALEvent evt;

    evt.type = AL_SEQP_PLAY_EVT;

    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
