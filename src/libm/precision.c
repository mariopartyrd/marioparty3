#include "libm.h"

void func_8008D740_main(s32 precision) {
    f64 tolerance = 1.0;
    s32 i;

    if (precision < 1) {
        precision = 1;
    }
    if (precision > 15) {
        precision = 15;
    }
    for (i = 0; i < precision; i++) {
        tolerance /= 10.0;
    }
    D_800C94E0_main = tolerance;
}
