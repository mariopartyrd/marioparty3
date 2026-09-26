#include "common.h"
#include "PR/osint.h"

void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msgBuf, s32 count) {
    mq->mtqueue = (OSThread *)&D_800A2DB0_main;
    mq->fullqueue = (OSThread *)&D_800A2DB0_main;
    mq->validCount = 0;
    mq->first = 0;
    mq->msgCount = count;
    mq->msg = msgBuf;
}
