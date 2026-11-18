// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/fprintf.c (0x3AE188; vfprintf-style callee func_003AB158).

#include <stdio.h>
#undef va_start
#undef va_end
#define va_start(AP, L) ((AP) = (va_list)__builtin_next_arg(L))
#define va_end(AP) ((void)0)

int vfprintf_(FILE *, const char *, __VALIST) __asm__("func_003AB158");
#define vfprintf vfprintf_

#ifdef NONMATCHING
// DRAFT: GAME 0x3AE188
// diff: va_start yields wrong ap base; prologue store order differs
int func_003AE188(FILE *fp, const char *fmt, ...)
{
    int ret;
    va_list ap;

    va_start(ap, fmt);
    ret = vfprintf(fp, fmt, ap);
    va_end(ap);
    return ret;
}
#endif
