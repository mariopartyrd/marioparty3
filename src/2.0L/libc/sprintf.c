#include "common.h"
#include "stdarg.h"
#include "xstdio.h"

#include "gcc/string.h"

static char *proutSprintf(char *dst, const char *src, unsigned int count);

int sprintf(char *dst, const char *fmt, ...) {
    s32 ans;
    va_list ap;
    va_start(ap, fmt);
    ans = _Printf(proutSprintf, dst, fmt, ap);
    if (ans >= 0) {
        dst[ans] = 0;
    }
    return ans;
}

char *proutSprintf(char *dst, const char *src, unsigned int count) {
    return (char *)memcpy((u8 *)dst, (u8 *)src, count) + count;
}
