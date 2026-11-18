// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/fread.c (0x3A6308).
#include <stdio.h>

void *memcpy_(void *, const void *, unsigned) __asm__("func_003A62D8");
int __srefill_(FILE *) __asm__("func_003A6AA8");
#define memcpy memcpy_

// FUNCTION: GAME 0x3A6308
unsigned int func_003A6308(void *buf, unsigned int size, unsigned int count, FILE *fp)
{
    register unsigned int resid;
    register char *p;
    register int r;
    unsigned int total;

    if ((resid = count * size) == 0)
        return 0;
    if (fp->_r < 0)
        fp->_r = 0;
    total = resid;
    p = (char *)buf;
    while (resid > (r = fp->_r)) {
        (void)memcpy((void *)p, (void *)fp->_p, (unsigned)r);
        fp->_p += r;
        p += r;
        resid -= r;
        if (__srefill_(fp))
            return (total - resid) / size;
    }
    (void)memcpy((void *)p, (void *)fp->_p, resid);
    fp->_r -= resid;
    fp->_p += resid;
    return count;
}
