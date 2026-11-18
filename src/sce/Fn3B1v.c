// COMPILER: ee-gcc2.9-991111
// SCE library scePrintf, ee-gcc 2.9-991111 -O2 -G0.
typedef void *va_list;
extern void func_003B10D0(int (*)(void), void *, unsigned, const char *, va_list);
extern int func_003B63A0(void);
extern void func_003B63F0(void);
extern int func_003B1E40(void);
extern int func_003B1E68(void);

// FUNCTION: GAME 0x3B1F28
void scePrintf(const char *fmt, ...)
{
    int buf[4];
    int lock;
    va_list ap;
    buf[0] = 0;
    lock = func_003B63A0();
    ap = (va_list)((char *)__builtin_next_arg(fmt) - 0x38);
    func_003B10D0(func_003B1E40, buf, 0xFFFFFFFFu, fmt, ap);
    if (lock)
        func_003B63F0();
}

// FUNCTION: GAME 0x3B1FA8
void func_003B1FA8(const char *fmt, ...)
{
    int buf[4];
    int lock;
    va_list ap;
    buf[0] = 0;
    lock = func_003B63A0();
    ap = (va_list)((char *)__builtin_next_arg(fmt) - 0x38);
    func_003B10D0(func_003B1E68, buf, 0xFFFFFFFFu, fmt, ap);
    if (lock)
        func_003B63F0();
}
