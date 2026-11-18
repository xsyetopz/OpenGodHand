// COMPILER: ee-gcc2.96
int func_0035D7B8(int);
int func_0035DA58(int, int);
int func_0035E9E8(int);
void func_0035D728(int);
extern char D_00459C48[];
int func_003A93F8();
int func_0035DDB0();
int func_0035F1D0();
int func_0035F418();

// FUNCTION: GAME 0x35DA58
int func_0035DA58(int a, int b)
{
    int r = 0;
    int i;
    for (i = 0; i < 0x1A; i++) {
        int p = a + i * 64 + 0x180;
        if (*(unsigned char *)(p + 0x18) == b) {
            r = p;
            break;
        }
    }
    return r;
}

// FUNCTION: GAME 0x35DD50
int func_0035DD50(int a, int b, int c)
{
    int p = func_003A93F8(a, D_00459C48);
    if (p) {
        int r = func_0035DDB0(p + 4, b);
        func_0035DDB0(r + 1, c);
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x35E0F0
int func_0035E0F0(int a, int b)
{
    int s = *(int *)(a + 4);
    if (func_0035D7B8(a)) return func_0035DA58(s, b);
    return 0;
}

// FUNCTION: GAME 0x35F3C8
int func_0035F3C8(int a, int b, int c)
{
    func_0035F1D0(a, b, c, 0);
    return func_0035F418(a, b, c);
}

// DRAFT: GAME 0x35DC10
// 2 words: sw zero/lw order swapped (local `int *d = b` declared first narrows 3 to 2)
#ifdef NONMATCHING
int func_0035DC10(int a, int *b)
{
    int *d = b;
    int s;
    s = *(int *)(a + 4) + 0x80;
    *d = 0;
    if (func_0035D7B8(a)) {
        *d = *(int *)s;
        return 1;
    }
    return 0;
}
#endif

// DRAFT: GAME 0x35DC60
// 3 words: prologue save order
#ifdef NONMATCHING
int func_0035DC60(int a, int *b)
{
    int s;
    *b = -1;
    s = *(int *)(a + 4) + 0x80;
    if (func_0035D7B8(a)) {
        *b = *(unsigned char *)(s + 4);
        return 1;
    }
    return 0;
}
#endif

// DRAFT: GAME 0x35DCB0
// 3 words: prologue save order
#ifdef NONMATCHING
int func_0035DCB0(int a, int *b)
{
    int s;
    *b = 0;
    s = *(int *)(a + 4) + 0x80;
    if (func_0035D7B8(a)) {
        *b = *(short *)(s + 8);
        return 1;
    }
    return 0;
}
#endif

// DRAFT: GAME 0x35DD00
// 3 words: prologue save order
#ifdef NONMATCHING
int func_0035DD00(int a, int *b)
{
    int s;
    *b = 0;
    s = *(int *)(a + 4) + 0x80;
    if (func_0035D7B8(a)) {
        *b = *(int *)(s + 0xC);
        return 1;
    }
    return 0;
}
#endif

// DRAFT: GAME 0x35D758
// 18 words: original loop counter in v0, bnez exit
#ifdef NONMATCHING
void func_0035D758(int n, int p)
{
    if (n > 0) {
        do {
            func_0035D728(p);
            p += 0x10;
        } while (--n != 0);
    }
}
#endif

// DRAFT: GAME 0x35E968
// 9 words: original uses movz for the byte > 1 test
#ifdef NONMATCHING
int func_0035E968(int a, int b)
{
    if (func_0035E9E8(a) == 0xC0) return (*(unsigned char *)(b + 0x20) != 0) & (*(unsigned char *)(b + 0x20) >= 2);
    return 0;
}
#endif

// DRAFT: GAME 0x35E9A8
// 9 words: original uses movz for the byte > 1 test
#ifdef NONMATCHING
int func_0035E9A8(int a, int b)
{
    if (func_0035E9E8(a) == 0xE0) return (*(unsigned char *)(b + 0x20) != 0) & (*(unsigned char *)(b + 0x20) >= 2);
    return 0;
}
#endif

extern int D_003EE330;
extern int D_003EE338[];
extern int D_003EE800[];
void func_0035FEE8(void);
void func_0036CAA8(void);
void func_0035FE78(void);
void func_00360CC8(void);
void func_0035FFB0(int);
void func_0036CB98(int);
void func_00360710(int);
extern void *memset(void *, int, unsigned);

// FUNCTION: GAME 0x35F900
void func_0035F900(void)
{
    if (D_003EE330 > 0) {
        func_0035FEE8();
        func_0036CAA8();
        func_0035FE78();
        func_00360CC8();
        D_003EE330--;
    }
}

// FUNCTION: GAME 0x35FB88
void func_0035FB88(int *a)
{
    if (a) {
        int s = a[0x30 / 4];
        a[0] = 0;
        func_0035FFB0(a[0x24 / 4]);
        func_0036CB98(s);
        D_003EE338[0]--;
    }
}

// FUNCTION: GAME 0x35FEA8
void func_0035FEA8(void)
{
    memset(D_003EE800, 0, 0x26C);
    D_003EE800[2] = 8;
    func_00360710(0);
}


void func_0035FF98(int);

// DRAFT: GAME 0x35FA88
// 14 words: original loads base+count in one lui/addiu then adds 0x18 after blez
#ifdef NONMATCHING
int *func_0035FA88(void)
{
    int *p = D_003EE338 + 6;
    int i;
    for (i = 0; i < D_003EE338[1]; i++, p += 0x25)
        if (*p == 0) return p;
    return 0;
}
#endif

// DRAFT: GAME 0x35FF48
// 14 words: same shape as 0x35FA88
#ifdef NONMATCHING
int *func_0035FF48(void)
{
    int *p = D_003EE800 + 3;
    int i;
    for (i = 0; i < D_003EE800[2]; i++, p += 0x13)
        if (*p == 0) return p;
    return 0;
}
#endif

int *func_0035FF48(void);
void func_0035FC18(int);
int func_00360CA0();

// FUNCTION: GAME 0x35FEF0
int *func_0035FEF0(void)
{
    int *p = func_0035FF48();
    if (p) {
        func_0035FF98((int)p);
        D_003EE800[0] = D_003EE800[0] + 1;
        *p = 1;
        return p;
    }
    return p;
}

// FUNCTION: GAME 0x35F8B8
int func_0035F8B8(void)
{
    memset(D_003EE338, 0, 0x4C8);
    D_003EE338[1] = 8;
    func_0035FC18(1);
    return func_00360CA0();
}

extern int D_003EE340[];

// FUNCTION: GAME 0x35FBD8
void func_0035FBD8(int a, int b, int c)
{
    void (*fn)() = (void (*)())D_003EE340[0];
    int n = D_003EE340[2] + 1;
    int arg = D_003EE340[1];
    D_003EE340[2] = n;
    if (fn) fn(arg, c);
}

extern volatile int D_003EEA78;
extern int D_003EEA7C;
extern int D_003EEA80;
extern int *D_0045A260[];

// DRAFT: GAME 0x360AA8
// 13 words: register allocation (orig a1/a2/a3 vs mine a3/t0), andi/xori order
#ifdef NONMATCHING
void func_00360AA8(void)
{
    D_003EEA78--;
    if (D_003EEA78 == 0) {
        int idx = D_003EEA7C;
        if (idx != -1) {
            int v = D_003EEA80;
            int x = v ^ 0xC00;
            if ((v & 0xC7) != 0x82) *D_0045A260[idx] = x;
        }
    }
    if (D_003EEA78 < 0) D_003EEA78 = 0;
}
#endif

extern int D_00766CA0;
extern int D_003EE334;
int func_0035F8A8(void);
void func_0035FE60(void);
void func_0035FE90(void);
void func_0036CA50(void);

// FUNCTION: GAME 0x35F838
void func_0035F838(void)
{
    if (D_003EE330 <= 0) {
        D_00766CA0 = func_0035F8A8();
        func_0035F8B8();
        func_0035FE60();
        func_0035FE90();
        func_0036CA50();
        D_003EE334 = 0;
        D_003EE330++;
    }
}
