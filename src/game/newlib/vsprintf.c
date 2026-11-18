// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/vsprintf.c (0x3A7AE8).
#include <limits.h>
#include <stdio.h>

int vfprintf_(FILE *, const char *, __VALIST) __asm__("func_003A9D88");
#define vfprintf vfprintf_

// FUNCTION: GAME 0x3A7AE8
int vsprintf(char *str, const char *fmt, __VALIST ap)
{
    int ret;
    FILE f;

    f._flags = __SWR | __SSTR;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._w = INT_MAX;
    f._data = _REENT;
    ret = vfprintf(&f, fmt, ap);
    *f._p = 0;
    return ret;
}
