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

extern int func_003B10D0_i(int (*)(void), void *, int, const char *, va_list) __asm__("func_003B10D0");
extern int func_003B10D0_j(int, int, int, int, va_list) __asm__("func_003B10D0");

// FUNCTION: GAME 0x3B1E90
int func_003B1E90(int a, int b, int *pn, int d, ...)
{
    va_list ap = (va_list)((char *)__builtin_next_arg(d) - 0x20);
    int r = func_003B10D0_j(a, b, *pn, d, ap);
    *pn -= r;
    return r;
}

extern int func_003B1DE8(void);

// FUNCTION: GAME 0x3B1EE0
int func_003B1EE0(int a, int b, int c, ...)
{
    int buf[4];
    va_list ap = (va_list)((char *)__builtin_next_arg(c) - 0x28);
    buf[0] = a;
    return func_003B10D0_i((int (*)(void))func_003B1DE8, buf, b, (const char *)c, ap);
}

extern void flush__7ostream(void *);
extern int _skip_ws__7istream(void *);
extern void func_0038AF30(int, int, va_list, void *);

// FUNCTION: GAME 0x38ADC8
void *func_0038ADC8(void **self, int fmt, ...)
{
    unsigned char *s = (unsigned char *)*self;
    int ok;
    va_list ap;
    if (s[0x1A]) {
        s[0x1A] |= 2;
        ok = 0;
    } else {
        if (*(void **)(s + 4)) {
            flush__7ostream(*(void **)(s + 4));
            s = (unsigned char *)*self;
        }
        if ((int)(*(long *)(s + 0x10) & 1))
            ok = _skip_ws__7istream(self);
        else
            ok = 1;
    }
    if (ok) {
        ap = (va_list)((char *)__builtin_next_arg(fmt) - 0x30);
        func_0038AF30(**(int **)self, fmt, ap, *self);
    }
    return self;
}
