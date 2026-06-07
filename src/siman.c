#include "common.h"
#include "process.h"
#include "siman.h"

// TODO: find SI thread stack size
void InitSI(void) {
    D_800BD7B0_BE3B0 = NULL;
    D_800BD7B4_BE3B4 = NULL;
    osCreateMesgQueue(&D_800CE1A0_CEDA0, &D_800BCD00_BD900, 32);
    osSetEventMesg(OS_EVENT_SI, &D_800CE1A0_CEDA0, (OSMesg)32);
    osCreateMesgQueue(&D_800D1220_D1E20, &D_800BCD80_BD980, 32);
    osCreateThread(&D_800BCE00_BDA00, 0x14, SIProc, NULL, &D_800BD7B0_BE3B0, HOS_PRIORITY_SIMGR);
    osStartThread(&D_800BCE00_BDA00);
}

functionListEntry **GetSIClientListTable(functionListEntry *entry) {
    switch (entry->type) {
        case 0:
            return &D_800BD7B0_BE3B0;
        case 1:
            return &D_800BD7B4_BE3B4;
        default:
            return NULL;
    }
}

/* Function Linked List Insertion */
s32 _AddSIClient(functionListEntry *node) {
    functionListEntry *pYoungest;
    functionListEntry *child;

    // Add node as youngest child of a linked list
    pYoungest = (functionListEntry *)GetSIClientListTable(node);
    child = pYoungest->child;
    if (child != NULL) {
        pYoungest = child;
        if (pYoungest->child != NULL) {
            do {
                pYoungest = pYoungest->child;
            } while (pYoungest->child != NULL);
        }
    }
    pYoungest->child = node;
    node->child = NULL;
    return 0;
}

void AddSIClient(functionListEntry *entry, s16 type, void *func) {
    OSMesg msgBuffer;
    OSMesgQueue mq;
    unkMesg msgOut;

    msgOut.func = (HuSiFunc)&_AddSIClient;
    msgOut.arg = entry;
    msgOut.recvQueue = &mq;
    entry->func = func;
    entry->type = type;

    osCreateMesgQueue(&mq, &msgBuffer, OS_MESG_BLOCK);
    osSendMesg(&D_800D1220_D1E20, &msgOut, OS_MESG_BLOCK);
    osRecvMesg(&mq, NULL, 1);
}

/* Function Linked List Deletion */
s32 _RemoveSIClient(functionListEntry *arg0) {
    functionListEntry *var_v0;
    functionListEntry *var_v1;
    functionListEntry **root;

    root = GetSIClientListTable(arg0);
    var_v0 = *root;
    var_v1 = NULL;
    // Search until the end of the list
    while (var_v0 != NULL) {
        // Check if the node is the one we're looking for
        if (var_v0 == arg0) {
            // If this wasn't at the start of the list (previous node is nonnull), remove it from the list
            if (var_v1 != NULL) {
                var_v1->child = arg0->child;
            } else {
                // Otherwise set the root of the list to the next node
                *root = arg0->child;
            }
            return 0;
        }
        var_v1 = var_v0;
        var_v0 = var_v0->child;
    }
    return 0;
}

void RemoveSIClient(void *entry) {
    OSMesg msgBuffer;
    OSMesgQueue mq;
    unkMesg msgOut;

    msgOut.func = (HuSiFunc)&_RemoveSIClient;
    msgOut.arg = entry;
    msgOut.recvQueue = &mq;

    osCreateMesgQueue(&mq, &msgBuffer, 1);
    osSendMesg(&D_800D1220_D1E20, &msgOut, OS_MESG_BLOCK);
    osRecvMesg(&mq, NULL, OS_MESG_BLOCK);
}

/* Do all functions in functionList of type "type" */
void CallSIClient(s16 type) {
    functionListEntry *funcList;

    funcList = NULL;
    switch (type) {
        case 0:
            funcList = D_800BD7B0_BE3B0;
            break;
        case 1:
            funcList = D_800BD7B4_BE3B4;
            break;
    }
    if (funcList != NULL) {
        do {
            funcList->func();
            funcList = funcList->child;
        } while (funcList != 0);
    }
}

/* Wait for message to do all functions in a global function list
 * or to run custom functions?
 */
void SIProc(void *arg0) {
    unkMesgWrapper msgWrapper;

    AddSchedulerClient(&msgWrapper, &D_800D1220_D1E20, 3);

    while (TRUE) {
        osRecvMesg(&D_800D1220_D1E20, (OSMesg *)&msgWrapper.unkMsg, OS_MESG_BLOCK);
        switch ((s32)msgWrapper.unkMsg) {
            case 1:
                CallSIClient((s16)0);
                break;
            case 2:
                CallSIClient((s16)1);
                break;
            default: {
                unkMesg *recvdMsg;
                recvdMsg = msgWrapper.unkMsg;
                recvdMsg->ret = recvdMsg->func(recvdMsg->arg);
                if (recvdMsg->recvQueue != NULL) {
                    osSendMesg(recvdMsg->recvQueue, NULL, OS_MESG_BLOCK);
                }
            }
        }
    }
}

s32 RequestSIFunction(unkMesg *siMessg, void *func, void *arg, s32 type) {
    OSMesgQueue msgQueue;
    OSMesg tmpMsg;

    siMessg->func = func;
    siMessg->arg = arg;
    siMessg->recvQueue = &msgQueue;
    osCreateMesgQueue(&msgQueue, &tmpMsg, 1);
    osSendMesg(&D_800D1220_D1E20, siMessg, OS_MESG_BLOCK);
    switch (type) {
        case 0:
            siMessg->ret = 0;
            break;
        case 1:
            osRecvMesg(&msgQueue, NULL, OS_MESG_BLOCK);
            break;
        case 2:
            while (osRecvMesg(&msgQueue, NULL, OS_MESG_NOBLOCK)) {
                HuPrcVSleep();
            }
            break;
    }
    return siMessg->ret;
}
