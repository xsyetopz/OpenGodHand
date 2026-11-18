// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/fileno.c (0x3A6130), with CHECK_INIT on the FILE's reent.
#define _impure_ptr D_003FA62C
#include <stdio.h>

void __sinit_(struct _reent *) __asm__("func_003A61F0");

// FUNCTION: GAME 0x3A6130
int func_003A6130(FILE *fp)
{
    if (!fp->_data)
        fp->_data = _REENT;
    if (!fp->_data->__sdidinit)
        __sinit_(fp->_data);
    return fp->_file;
}
