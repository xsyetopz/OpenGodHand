// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/refill.c (0x3A6AA8).
#include <stdio.h>

void __sinit_(struct _reent *) __asm__("func_003A61F0");
int fflush_(FILE *) __asm__("func_003A6020");
void __smakebuf_(FILE *) __asm__("func_003A6950");
int _fwalk_(struct _reent *, int (*)(FILE *)) __asm__("func_003A6830");
int func_003A6A88(FILE *);

#ifdef NONMATCHING
// DRAFT: GAME 0x3A6AA8
// diff: 3 words (360 vs 360 bytes): `_data &&` null check gives the CHECK_INIT nop but adds a beqz on _data (same as fflush/ungetc/fileno); tried r local (85), no check (80)
int func_003A6AA8(FILE *fp)
{
    if (!fp->_data)
        fp->_data = _impure_ptr;
    if (fp->_data && !fp->_data->__sdidinit)
        __sinit_(fp->_data);
    fp->_r = 0;
    if (fp->_flags & __SEOF)
        return -1;
    if ((fp->_flags & __SRD) == 0) {
        if ((fp->_flags & __SRW) == 0)
            return -1;
        if (fp->_flags & __SWR) {
            if (fflush_(fp))
                return -1;
            fp->_flags &= ~__SWR;
            fp->_w = 0;
            fp->_lbfsize = 0;
        }
        fp->_flags |= __SRD;
    } else {
        if (fp->_ub._base != 0) {
            if ((fp->_r = fp->_ur) != 0) {
                fp->_p = fp->_up;
                return 0;
            }
        }
    }
    if (fp->_bf._base == 0)
        __smakebuf_(fp);
    if (fp->_flags & (__SLBF | __SNBF))
        _fwalk_(fp->_data, func_003A6A88);
    fp->_p = fp->_bf._base;
    fp->_r = (*fp->_read)(fp->_cookie, (char *)fp->_p, fp->_bf._size);
    fp->_flags &= ~__SMOD;
    if (fp->_r <= 0) {
        if (fp->_r == 0)
            fp->_flags |= __SEOF;
        else {
            fp->_r = 0;
            fp->_flags |= __SERR;
        }
        return -1;
    }
    return 0;
}
#endif
