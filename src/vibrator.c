#include "common.h"
#include "siman.h"
#include "game/vibrator.h"

static OSPfs D_800BD860_main[4];
static VibratorState D_800BDA00_main[4];
static functionListEntry D_800BDA30_main;
static functionListEntry D_800BDA3C_main;
static s16 D_800BDA48_main;

void RetraceCallbackVibrator(void) {
    s16 i;
    VibratorState *state;
    OSPfs *pfs;

    if (D_800BDA48_main == 0) {
        for (i = 0; i < 4; i++) {
            state = &D_800BDA00_main[i];
            pfs = &D_800BD860_main[i];

            if (state->stat != 0) {
                if (state->duration != 0) {
                    state->duration--;
                    osMotorStop(pfs);
                }
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            state = &D_800BDA00_main[i];
            pfs = &D_800BD860_main[i];

            switch (state->mode) {
                case 1:
                    // stopping mode
                    state->duration--;
                    if (state->duration == 0) {
                        state->stat = 1;
                        state->mode = 0;
                    }
                    osMotorStop(pfs);
                    break;

                case 2:
                    // starting mode
                    osMotorStart(pfs);
                    state->stat = 2;
                    state->mode = 0;
                    break;

                case 3:
                    // oscillating mode
                    if (state->timer <= 0) {
                        switch (state->stat) {
                            case 1:
                                if (state->onTime != 0) {
                                    osMotorStart(pfs);
                                    state->stat = 2;
                                    state->timer = state->onTime;
                                }
                                break;
                            case 2:
                                if (state->offTime != 0) {
                                    osMotorStop(pfs);
                                    state->stat = 1;
                                    state->timer = state->offTime;
                                }
                                break;
                        }
                    }
                    state->timer--;

                    // check if oscillation should end
                    if (state->duration != 0) {
                        state->duration--;
                        if (state->duration == 0) {
                            state->mode = 1;
                            state->duration = 3;
                        }
                    }
                    break;
            }
        }
    }
}

void PRENMICallbackVibrator(void) {
    s16 i;
    s16 id;

    D_800BDA48_main = 0;

    for (i = 0; i < 4; ++i) {
        id = i;
        _ResetVibrator(&id);
    }
}

s32 _InitVibrator(void) {
    s16 i;

    for (i = 0; i < 4; ++i) {
        _ResetVibrator(&i);
    }

    return 0;
}

void InitVibrator(void) {
    unkMesg siMesg;

    D_800BDA48_main = 1;
    RequestSIFunction(&siMesg, &_InitVibrator, NULL, 1);
    AddSIClient(&D_800BDA30_main, 0, &RetraceCallbackVibrator);
    AddSIClient(&D_800BDA3C_main, 1, &PRENMICallbackVibrator);
}

s32 _ResetVibrator(s16 *contId) {
    s16 id;
    s32 result;

    id = *contId;
    result = osMotorInit(&D_800CE1A0_main, &D_800BD860_main[id], (s32)id);
    if (result == 0) {
        D_800BDA00_main[*contId].stat = 1; // motor initialized and off
        osMotorStop(&D_800BD860_main[*contId]);
    } else {
        D_800BDA00_main[*contId].stat = 0; // no rumble pak
    }
    D_800BDA00_main[*contId].mode = 0; // set to idle mode
    return result;
}

void ResetVibrator(s16 contId) {
    unkMesg siMesg;
    RequestSIFunction(&siMesg, _ResetVibrator, &contId, 1);
}

void _StartVibrator(s16 *contId) {
    VibratorState *state;

    state = &D_800BDA00_main[*contId];
    if (state->stat != 0) {
        state->mode = 2; // set to starting mode
    }
}

void StartVibrator(s16 contId) {
    unkMesg siMesg;
    RequestSIFunction(&siMesg, _StartVibrator, &contId, 1);
}

void _StopVibrator(s16 *contId) {
    VibratorState *state;

    state = &D_800BDA00_main[*contId];
    if (state->stat != 0) {
        state->mode = 1;     // set to stopping mode
        state->duration = 3; // 3-frame wind-down
    }
}

void StopVibrator(s16 contId) {
    unkMesg siMesg;
    RequestSIFunction(&siMesg, _StopVibrator, &contId, 1);
}

void _RepeatVibrator(VibratorSetting *setting) {
    VibratorState *state;

    state = &D_800BDA00_main[setting->stateIdx];
    if (state->stat != 0) {
        state->stat = 1; // start with motor off
        state->mode = 3; // oscillating mode
        state->onTime = setting->onTime;
        state->offTime = setting->offTime;
        state->duration = setting->duration;
        state->timer = 0;
    }
}

void RepeatVibrator(s16 contId, s16 onTime, s16 offTime, s16 duration) {
    unkMesg siMesg;
    VibratorSetting setting;

    setting.stateIdx = contId;
    setting.onTime = onTime;
    setting.offTime = offTime;
    setting.duration = duration;
    RequestSIFunction(&siMesg, _RepeatVibrator, &setting, 1);
}
