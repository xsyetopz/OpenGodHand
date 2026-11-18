// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/printf.c (0x3A6A20).
#define _impure_ptr D_003FA62C
#include <stdio.h>
#undef va_start
#undef va_end
#define va_start(AP, L) ((AP) = (va_list)__builtin_next_arg(L))
#define va_end(AP) ((void)0)

int vfprintf_(FILE *, const char *, __VALIST) __asm__("func_003A9D88");
#define vfprintf vfprintf_

#ifdef NONMATCHING
// DRAFT: GAME 0x3A6A20
// diff: 14 words: va_start must yield &saved-a1 (sp+0x58); __builtin_next_arg yields sp+0x90 and reorders prologue stores
int printf(const char *fmt, ...)
{
    int ret;
    va_list ap;

    va_start(ap, fmt);
    stdout->_data = _REENT;
    ret = vfprintf(stdout, fmt, ap);
    va_end(ap);
    return ret;
}
#endif
