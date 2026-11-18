// COMPILER: ee-gcc2.9-991111
// FLAGS: -Isrc/sce/libio -Isrc/sce/libio/stub
// SCE libio _IO_new_file_sync.
#include "libioP.h"

extern int func_00392A80(_IO_FILE *, const char *, _IO_size_t);
extern int *func_003A4FB8(void);

// FUNCTION: GAME 0x392E48
int func_00392E48(_IO_FILE *fp)
{
    int retval = 0;
    unsigned int delta;
    if (fp->_IO_write_ptr > fp->_IO_write_base)
        if (func_00392A80(fp, fp->_IO_write_base, fp->_IO_write_ptr - fp->_IO_write_base))
            return EOF;
    delta = fp->_IO_read_ptr - fp->_IO_read_end;
    if (delta != 0) {
        _IO_pos_t new_pos = _IO_SYSSEEK(fp, delta, 1);
        if (new_pos != _IO_pos_BAD)
            fp->_IO_read_end = fp->_IO_read_ptr;
        else if (*func_003A4FB8() == 0x1D)
            ;
        else
            retval = EOF;
    }
    if (retval != EOF)
        fp->_offset = _IO_pos_BAD;
    return retval;
}
