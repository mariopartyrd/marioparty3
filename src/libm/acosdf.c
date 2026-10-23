#include "math.h"

/* acos in degrees. */
f32 acosdf(f32 x) {
    if (x == 0.0f) {
        return 90.0f;
    }
    if (1.0f <= x) {
        return 0.0f;
    }
    if (x <= -1.0f) {
        return 180.0f;
    }
    return 90.0f - asindf(x);
}
