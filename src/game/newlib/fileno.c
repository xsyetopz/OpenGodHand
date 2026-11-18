// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdio/fileno.c fileno (0x3A6130).
#include <stdio.h>
#include <reent.h>

extern struct _reent *_impure_ptr;
extern void __sinit_(struct _reent *) __asm__("func_003A61F0");

#ifdef NONMATCHING
// DRAFT: GAME 0x3A6130
// diff: 3 words; null-checked CHECK_INIT gives the nop but adds an extra beqz on _data (same as ungetc)
int func_003A6130(FILE *fp)
{
    if (!fp->_data)
        fp->_data = _impure_ptr;
    if (fp->_data && !fp->_data->__sdidinit)
        __sinit_(fp->_data);
    return fp->_file;
}
#endif
