// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/sprintf.c (0x3A6C58).
#include <limits.h>

#include <stdio.h>
#undef va_start
#undef va_end
#define va_start(AP, L) ((AP) = (va_list)__builtin_next_arg(L))
#define va_end(AP) ((void)0)

int vfprintf_(FILE *, const char *, __VALIST) __asm__("func_003A9D88");
#define vfprintf vfprintf_

// FUNCTION: GAME 0x3A6C58
int sprintf(char *str, const char *fmt, ...)
{
    int ret;
    va_list ap;
    FILE f;

    f._flags = __SWR | __SSTR;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._w = INT_MAX;
    f._data = _REENT;
    ap = (va_list)((char *)__builtin_next_arg(fmt) - 0x30);
    ret = vfprintf(&f, fmt, ap);
    va_end(ap);
    *f._p = 0;
    return ret;
}
