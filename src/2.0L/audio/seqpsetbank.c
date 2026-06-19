#include "common.h"

void alSeqpSetBank(ALSeqPlayer *seqp, ALBank *b) {
    ALEvent evt;

    evt.type = AL_SEQP_BANK_EVT;
    evt.msg.spbank.bank = b;

    alEvtqPostEvent(&seqp->evtq, &evt, 0);
}
