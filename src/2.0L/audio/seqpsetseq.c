#include "common.h"

void alSeqpSetSeq(ALSeqPlayer *seqp, ALSeq *seq) {
    ALEvent evt;

    evt.type = AL_SEQP_SEQ_EVT;
    evt.msg.spseq.seq = seq;

    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
