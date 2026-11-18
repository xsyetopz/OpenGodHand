// COMPILER: ee-gcc2.9-991111
// FLAGS: -Isrc/sce/libio -Isrc/sce/libio/stub
// SCE libio _IO_do_write: the syswrite hook takes and returns 64-bit sizes, as in the SCE build.
#include "libioP.h"

typedef long (*sce_write_t)(_IO_FILE *, const void *, long);

// FUNCTION: GAME 0x392A80
int func_00392A80(_IO_FILE *fp, const char *data, _IO_size_t to_do)
{
    int count;
    if (to_do == 0)
        return 0;
    if (fp->_flags & _IO_IS_APPENDING)
        fp->_offset = _IO_pos_BAD;
    else if (fp->_IO_read_end != fp->_IO_write_base) {
        _IO_pos_t new_pos = _IO_SYSSEEK(fp, fp->_IO_write_base - fp->_IO_read_end, 1);
        if (new_pos == _IO_pos_BAD)
            return EOF;
        fp->_offset = new_pos;
    }
    count = ((sce_write_t)_IO_JUMPS(fp)->__write.pfn)(fp, data, to_do);
    if (fp->_cur_column)
        fp->_cur_column = _IO_adjust_column(fp->_cur_column - 1, data, to_do) + 1;
    _IO_setg(fp, fp->_IO_buf_base, fp->_IO_buf_base, fp->_IO_buf_base);
    fp->_IO_write_base = fp->_IO_write_ptr = fp->_IO_buf_base;
    fp->_IO_write_end = ((fp->_flags & (_IO_LINE_BUF + _IO_UNBUFFERED)) ? fp->_IO_buf_base : fp->_IO_buf_end);
    return count != to_do ? EOF : 0;
}
