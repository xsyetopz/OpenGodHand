// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/ungetc.c (0x3AE598), with CHECK_INIT on the FILE's reent.
#include <stdio.h>

void __sinit_(struct _reent *) __asm__("func_003A61F0");
int fflush_(FILE *) __asm__("func_003A6020");
int write_(int, const char *, int) __asm__("func_003B0268");
extern const char D_0045FC90[];

#ifdef NONMATCHING
// DRAFT: GAME 0x3AE598
// diff: original has the CHECK_INIT load-delay nop after lw a0,0x54(s0) (404 vs 400 bytes)
int func_003AE598(int c, FILE *fp)
{
    if (c == EOF)
        return EOF;
    if (!fp->_data)
        fp->_data = _REENT;
    if (!fp->_data->__sdidinit)
        __sinit_(fp->_data);
    fp->_flags &= ~__SEOF;
    if ((fp->_flags & __SRD) == 0) {
        if ((fp->_flags & __SRW) == 0)
            return EOF;
        if (fp->_flags & __SWR) {
            if (fflush_(fp))
                return EOF;
            fp->_flags &= ~__SWR;
            fp->_w = 0;
            fp->_lbfsize = 0;
        }
        fp->_flags |= __SRD;
    }
    c = (unsigned char)c;
    if (fp->_ub._base != NULL) {
        if (fp->_r >= fp->_ub._size) {
            write_(1, D_0045FC90, 0x44);
            return EOF;
        }
        *--fp->_p = c;
        fp->_r++;
        return c;
    }
    if (fp->_bf._base != NULL && fp->_p > fp->_bf._base && fp->_p[-1] == c) {
        fp->_p--;
        fp->_r++;
        return c;
    }
    fp->_ur = fp->_r;
    fp->_up = fp->_p;
    fp->_ub._base = fp->_ubuf;
    fp->_ub._size = sizeof(fp->_ubuf);
    fp->_ubuf[sizeof(fp->_ubuf) - 1] = c;
    fp->_p = &fp->_ubuf[sizeof(fp->_ubuf) - 1];
    fp->_r = 1;
    return c;
}

#endif
