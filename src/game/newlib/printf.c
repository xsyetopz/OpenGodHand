// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/printf.c (0x3A6A20).
#include <stdio.h>
#undef va_start
#undef va_end
#define va_start(AP, L) ((AP) = (va_list)__builtin_next_arg(L))
#define va_end(AP) ((void)0)

int vfprintf_(FILE *, const char *, __VALIST) __asm__("func_003A9D88");
#define vfprintf vfprintf_

#ifdef NONMATCHING
// DRAFT: GAME 0x3A6A20
// diff: 13 words: ap = next_arg(fmt) - 0x38 now gives sp+0x58; remaining: original reloads _impure_ptr after the _data store and orders sd ra before sd a2/daddu a1
int printf(const char *fmt, ...)
{
    int ret;
    va_list ap;

    ap = (va_list)((char *)__builtin_next_arg(fmt) - 0x38);
    _stdout_r(_REENT)->_data = _REENT;
    ret = vfprintf(_stdout_r(_REENT), fmt, ap);
    va_end(ap);
    return ret;
}
#endif
