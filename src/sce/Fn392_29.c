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

// ostream operator<< / write thunks (a1/a2 pass through untouched)
extern int __ls__7ostreamPCc();
extern int write__7ostreamPCci();

// FUNCTION: GAME 0x38A548
int func_0038A548() { return __ls__7ostreamPCc(); }
// FUNCTION: GAME 0x38A568
int func_0038A568() { return __ls__7ostreamPCc(); }
// FUNCTION: GAME 0x38A5C8
int func_0038A5C8() { return write__7ostreamPCci(); }
// FUNCTION: GAME 0x38A5E8
int func_0038A5E8() { return write__7ostreamPCci(); }
// FUNCTION: GAME 0x38A608
int func_0038A608() { return write__7ostreamPCci(); }

extern int func_0031EDD0();
extern int func_00388D18();
extern int func_00389548();
extern int flush__7ostream();

// FUNCTION: GAME 0x38A4B8
int func_0038A4B8(void *a) { return func_00388D18(a, func_0031EDD0(a)); }

typedef struct { int *sb; } sce_os_t;
// FUNCTION: GAME 0x38A628
sce_os_t *func_0038A628(sce_os_t *os, char c) { _IO_putc(c, *(_IO_FILE **)os->sb); return os; }
// FUNCTION: GAME 0x38A660
sce_os_t *func_0038A660(sce_os_t *os, char c) { _IO_putc(c, *(_IO_FILE **)os->sb); return os; }
// FUNCTION: GAME 0x38A698
sce_os_t *func_0038A698(sce_os_t *os, char c) { _IO_putc(c, *(_IO_FILE **)os->sb); return os; }

typedef struct { char pad[0x10]; long long state; } sce_ios_t;
#ifdef NONMATCHING
// DRAFT: GAME 0x38A6D0
int func_0038A6D0(sce_ios_t **os)
{
    if ((*os)->state & 0x6000)
        return func_00389548(os);
    return 0;
}
#endif

typedef struct { char pad[0x1A]; unsigned char skip; } sce_ios2_t;
// FUNCTION: GAME 0x38A700
int func_0038A700(void **os)
{
    char *p = (char *)*os;
    if (*(unsigned char *)(p + 0x1A))
        return 0;
    if (*(void **)(p + 4))
        flush__7ostream(*(void **)(p + 4));
    return 1;
}

// Lazy singleton initialisers: construct once, register destructor via func_0031EE80/EEA8.
extern int __tf3ios();
extern int __tf7filebuf();
extern int func_0031EE80();
extern int func_0031EEA8();
extern int func_0038A340();
extern int func_0038D2B8();
extern int D_00786718[], D_00786748[], D_00786788[], D_00786798[], D_007867A8[];
extern char D_0045D210[], D_0045D208[], D_0045D1D8[], D_0045D1E8[], D_0045DB78[], D_0045DB88[], D_0045DB90[], D_0045DBA0[], D_0045DBA8[], D_00786768[];

// FUNCTION: GAME 0x38A7E0
int *func_0038A7E0()
{
    if (!D_00786718[0]) {
        __tf3ios();
        func_0031EE80(D_00786718, D_0045D210, D_0045D208, 1);
    }
    return D_00786718;
}

// FUNCTION: GAME 0x389BD8
int *func_00389BD8()
{
    if (!D_00786748[0]) {
        func_0038A7E0();
        func_0038A340();
        func_0031EE80(D_00786748, D_0045D1D8, D_0045D1E8, 2);
    }
    return D_00786748;
}

// FUNCTION: GAME 0x393AB8
int *func_00393AB8()
{
    if (!D_00786788[0]) {
        func_0038A7E0();
        func_0031EE80(D_00786788, D_0045DB78, D_0045DB88, 1);
    }
    return D_00786788;
}

// FUNCTION: GAME 0x393DD0
int *func_00393DD0()
{
    if (!D_00786798[0]) {
        func_0038A340();
        func_0031EE80(D_00786798, D_0045DB90, D_0045DBA0, 1);
    }
    return D_00786798;
}

// FUNCTION: GAME 0x393F30
int *func_00393F30()
{
    if (!D_007867A8[0]) {
        __tf7filebuf();
        func_0031EEA8(D_007867A8, D_0045DBA8, D_00786768);
    }
    return D_007867A8;
}

// FUNCTION: GAME 0x38AF30
int func_0038AF30(int a, int b, int c, char *p)
{
    int flags = 0;
    int r = func_0038D2B8(a, b, c, &flags);
    if (p)
        p[0x1A] |= *(volatile int *)&flags;
    return r;
}

extern int func_00387CD8();
extern int func_0030F5C8();
extern int func_0030F5A0();
extern int _$_7filebuf();
extern char D_0045DAE8[], D_0045D340[];
extern unsigned char D_0045F039[];

// FUNCTION: GAME 0x3875A8
int func_003875A8(_IO_FILE *fp)
{
    int c;
    do {
        c = _IO_getc(fp);
    } while (c != EOF && (D_0045F039[c] & 8));
    return c;
}

// FUNCTION: GAME 0x388278
void *func_00388278(void *a, int *out)
{
    unsigned long long v;
    int neg;
    if (func_00387CD8(a, &v, &neg)) {
        if (neg)
            v = -v;
        *out = v != 0;
    }
    return a;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x38B6E8
int func_0038B6E8(char *p, unsigned flags)
{
    *(char **)(p + 0x28) = D_0045D340;
    if (*(void **)(p + 0x20))
        func_0030F5C8(*(void **)(p + 0x20));
    if (flags & 1)
        return func_0030F5A0(p);
    return 0;
}
#endif

// FUNCTION: GAME 0x3935D0
int func_003935D0(char *p, int flags)
{
    *(char **)(p + 0x50) = D_0045DAE8;
    func_00392A80((_IO_FILE *)p, *(char **)(p + 0x10), *(char **)(p + 0x14) - *(char **)(p + 0x10));
    return _$_7filebuf(p, flags);
}

// FUNCTION: GAME 0x38F1A0
int *func_0038F1A0(int *dst, int *src)
{
    if (src != dst) {
        int *buf = *(int **)src;
        char *d = *(char **)dst;
        int v = *buf;
        if (!v)
            d[0x1A] = 4;
        else
            d[0x1A] = 0;
        *(int *)d = v;
        *(short *)(d + 0x18) = 0x20;
        *(long long *)(d + 0x10) = 0x11;
        *(int *)(d + 0x1C) = 6;
        d[0x1B] = 0;
        *(int *)(d + 4) = 0;
        *(int *)(d + 8) = 0;
        *(int *)(d + 0x20) = 0;
    }
    return dst;
}
