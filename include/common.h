#ifndef _COMMON_H_
#define _COMMON_H_

#define IS_DEBUG_PANIC(statement, file, line) do {} while(1)
#define ASSERT(condition) \
    if (!(condition)) { \
        IS_DEBUG_PANIC("Assertion failed: " #condition, __FILE__, __LINE__); \
    }

#define FALSE 0
#define TRUE 1

#include "ultra64.h"
#include "types.h"

#include "game/audio.h"
#include "game/camera.h"
#include "game/data.h"
#include "game/esprite.h"
#include "game/gamemes.h"
#include "game/gamework_data.h"
#include "game/hmflight.h"
#include "game/hmfman.h"
#include "game/object.h"
#include "game/sprite.h"
#include "game/util.h"
#include "game/window.h"
#include "game/wipe.h"

#include "common_structs.h"
#include "functions.us.h"

#include "variables.h"
#include "macros.h"
#include "enums.h"
#include "overlay.h"
#include "input.h"

#ifndef RECOMP
#include "include_asm.h"
#include "ld_addrs.h"
#endif

#endif
