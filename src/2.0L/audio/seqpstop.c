#include "common.h"

void alSeqpStop(ALSeqPlayer *seqp) {
    ALEvent evt;

    evt.type = AL_SEQP_STOPPING_EVT;

    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
