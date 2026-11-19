// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/fflush.c (0x3A6020).
#include <stdio.h>

int _fwalk_(struct _reent *, int (*)(FILE *)) __asm__("func_003A6830");
void __sinit_(struct _reent *) __asm__("func_003A61F0");

#ifdef NONMATCHING
// DRAFT: GAME 0x3A6020
// 3 words differ: compiled keeps beqz on fp->_data after the _impure_ptr store; original has no branch, a nop before lw 0x38(a0). Tried: no null check (48), fp&&, _data!=0 (3), _REENT, check order swapped (31)
int func_003A6020(FILE *fp)
{
    unsigned char *p;
    int n, t;

    if (fp == 0)
        return _fwalk_(_impure_ptr, func_003A6020);
    if (!fp->_data)
        fp->_data = _impure_ptr;
    if (fp->_data && !fp->_data->__sdidinit)
        __sinit_(fp->_data);
    t = fp->_flags;
    if ((t & __SWR) == 0)
        return 0;
    if ((p = fp->_bf._base) == 0)
        return 0;
    n = fp->_p - p;
    fp->_p = p;
    fp->_w = t & (__SLBF | __SNBF) ? 0 : fp->_bf._size;
    while (n > 0) {
        t = (*fp->_write)(fp->_cookie, (char *)p, n);
        if (t <= 0) {
            fp->_flags |= __SERR;
            return -1;
        }
        p += t;
        n -= t;
    }
    return 0;
}
#endif
