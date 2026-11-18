// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/wsetup.c (0x3AE730).
#define _impure_ptr D_003FA62C
#include <stdio.h>

void __sinit_(struct _reent *) __asm__("func_003A61F0");
void __smakebuf_(FILE *) __asm__("func_003A6950");

#ifdef NONMATCHING
// DRAFT: GAME 0x3AE730
// diff: original has a load-delay nop in CHECK_INIT
int func_003AE730(FILE *fp)
{
    if (!fp->_data)
        fp->_data = _REENT;
    if (!fp->_data->__sdidinit)
        __sinit_(fp->_data);
    if ((fp->_flags & __SWR) == 0) {
        if ((fp->_flags & __SRW) == 0)
            return -1;
        if (fp->_flags & __SRD) {
            fp->_flags &= ~(__SRD | __SEOF);
            fp->_r = 0;
            fp->_p = fp->_bf._base;
        }
        fp->_flags |= __SWR;
    }
    if (fp->_bf._base == 0)
        __smakebuf_(fp);
    if (fp->_flags & __SLBF) {
        fp->_w = 0;
        fp->_lbfsize = -fp->_bf._size;
    } else
        fp->_w = fp->_flags & __SNBF ? 0 : fp->_bf._size;
    return 0;
}
#endif
