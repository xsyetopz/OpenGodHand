// COMPILER: ee-gcc2.96
// SCE library varargs printf wrappers, ee-gcc 2.96 -O2 -G0.
typedef void *va_list;
extern int vsprintf(char *, const char *, va_list);
extern int scePrintf(const char *, ...);
extern int D_003CF9E0;
extern int D_003DA4D0, D_003DA4D4;
extern char D_003DA4D8[];

// FUNCTION: GAME 0x326050
void func_00326050(const char *fmt, ...)
{
    char buf[0x80];
    va_list ap = (va_list)((char *)__builtin_next_arg(fmt) - 0x38);
    if (D_003CF9E0 == 0) {
        vsprintf(buf, fmt, ap);
        scePrintf(buf);
    }
}

// FUNCTION: GAME 0x3260C8
void func_003260C8(const char *fmt, ...)
{
    char buf[0x80];
    va_list ap = (va_list)((char *)__builtin_next_arg(fmt) - 0x38);
    if (D_003CF9E0 != 2) {
        vsprintf(buf, fmt, ap);
        scePrintf(buf);
    }
}

// FUNCTION: GAME 0x335D40
void func_00335D40(const char *fmt, ...)
{
    va_list ap = (va_list)((char *)__builtin_next_arg(fmt) - 0x38);
    vsprintf(D_003DA4D8, fmt, ap);
    if (D_003DA4D0)
        ((void (*)(int, char *))D_003DA4D0)(D_003DA4D4, D_003DA4D8);
}

extern char D_00760C80[];
extern void *memset(void *, int, unsigned);
extern void func_00348C98(char *);

// FUNCTION: GAME 0x348BE0
void func_00348BE0(const char *fmt, ...)
{
    va_list ap;
    memset(D_00760C80, 0, 0x100);
    ap = (va_list)((char *)__builtin_next_arg(fmt) - 0x38);
    vsprintf(D_00760C80, fmt, ap);
    func_00348C98(D_00760C80);
}
