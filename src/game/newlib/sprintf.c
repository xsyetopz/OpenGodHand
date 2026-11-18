// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/sprintf.c (0x3A6C58).
#define _impure_ptr D_003FA62C
#include <limits.h>

#include <stdio.h>
#undef va_start
#undef va_end
#define va_start(AP, L) ((AP) = (va_list)__builtin_next_arg(L))
#define va_end(AP) ((void)0)

int vfprintf_(FILE *, const char *, __VALIST) __asm__("func_003A9D88");
#define vfprintf vfprintf_

#ifdef NONMATCHING
// DRAFT: GAME 0x3A6C58
// diff: va_start yields sp+0xE0 instead of &saved-a2 (sp+0xB0); prologue store order differs
int sprintf(char *str, const char *fmt, ...)
{
    int ret;
    va_list ap;
    FILE f;

    f._flags = __SWR | __SSTR;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._w = INT_MAX;
    f._data = _REENT;
    va_start(ap, fmt);
    ret = vfprintf(&f, fmt, ap);
    va_end(ap);
    *f._p = 0;
    return ret;
}
#endif
