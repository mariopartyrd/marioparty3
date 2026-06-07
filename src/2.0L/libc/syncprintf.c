#include "common.h"
#include "stdarg.h"
#include "xstdio.h"

extern char *(*__printfunc)(char *dst, const char *src, unsigned int count);

void __osSyncVPrintf(const char *fmt, va_list args) {
    if (__printfunc != NULL) {
        _Printf(__printfunc, NULL, fmt, args);
    }
}

void osSyncPrintf(const char *fmt, ...) {
    va_list ap;

    va_start(ap, fmt);
    if (__printfunc) {
        _Printf(__printfunc, NULL, fmt, ap);
    }
    va_end(ap);
}

void rmonPrintf(const char *fmt, ...) {
    int ans;
    va_list ap;

    va_start(ap, fmt);
    if (__printfunc != NULL) {
        _Printf(__printfunc, NULL, fmt, ap);
    }
    va_end(ap);
}
