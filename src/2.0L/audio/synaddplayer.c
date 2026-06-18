#include "common.h"

void alSynAddPlayer(ALSynth *drvr, ALPlayer *client) {
    OSIntMask mask = osSetIntMask(OS_IM_NONE);

    client->samplesLeft = drvr->curSamples;
    client->next = drvr->head;
    drvr->head = client;

    osSetIntMask(mask);
}
