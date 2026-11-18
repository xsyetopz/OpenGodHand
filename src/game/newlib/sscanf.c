// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/sscanf.c (0x3A6CE0).
#define _impure_ptr D_003FA62C
#include <stdio.h>
#undef va_start
#undef va_end
#define va_start(AP, L) ((AP) = (va_list)__builtin_next_arg(L))
#define va_end(AP) ((void)0)

int __svfscanf_(FILE *, const char *, __VALIST) __asm__("func_003A6EE8");
int eofread_(void *, char *, int) __asm__("func_003A6CD8");
int eofread_(void *, char *, int);
unsigned strlen(const char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x3A6CE0
// diff: 21 words with ap = next_arg(fmt) - 0x30 before the call (140 vs 152 bytes); see printf.c
int func_003A6CE0(const char *str, const char *fmt, ...)
{
    int ret;
    va_list ap;
    FILE f;

    f._flags = __SRD | __SSTR;
    f._bf._base = f._p = (unsigned char *)str;
    f._bf._size = f._r = strlen(str);
    f._read = (int (*)())eofread_;
    f._ub._base = 0;
    f._lb._base = 0;
    ap = (va_list)((char *)__builtin_next_arg(fmt) - 0x30);
    ret = __svfscanf_(&f, fmt, ap);
    va_end(ap);
    return ret;
}
#endif
