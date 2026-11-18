// COMPILER: ee-gcc2.96
char *func_003452B0(void);
void func_003B9D80(void);
void func_00324AC8(void);
int func_00329F98(int);

// FUNCTION: GAME 0x3496F0
void func_003496F0(int a)
{
    *(int *)(func_003452B0() + 0x58) = a;
}

// FUNCTION: GAME 0x3497F8
void func_003497F8(int a)
{
    *(int *)(func_003452B0() + 0x188C) = a;
}

// FUNCTION: GAME 0x349D78
int func_00349D78(void)
{
    func_003B9D80();
    func_00324AC8();
    return 0;
}

// FUNCTION: GAME 0x34A7F0
int func_0034A7F0(char *a)
{
    return func_00329F98(**(int **)(a + 0x2004)) == 3;
}

// FUNCTION: GAME 0x349F80
void func_00349F80(int **a, int b, int c)
{
    ((void (*)(int **, int, int, int))(*a)[6])(a, 0, b, c);
}

// FUNCTION: GAME 0x34BFC8
void func_0034BFC8(int *a)
{
    int i = 2;
    do {
        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
        a[3] = 0;
        a += 4;
    } while (--i >= 0);
}

// FUNCTION: GAME 0x34CA00
void func_0034CA00(char *a, int b, int c)
{
    if (b != 8) { char *q = a + b * 0x74; *(int *)(q + 0x1318) = c; }
}

// FUNCTION: GAME 0x34CA68
void func_0034CA68(char *a, int b, int c)
{
    if (b != 8) { char *q = a + b * 0x74; *(int *)(q + 0x131C) = c; }
}

// FUNCTION: GAME 0x3493D8
void func_003493D8(void)
{
    char *p = func_003452B0();
    void (*f)(int) = *(void (**)(int))(p + 0x40);
    int x = *(int *)(p + 0x44);
    if (f) f(x);
}

// FUNCTION: GAME 0x349408
void func_00349408(void)
{
    char *p = func_003452B0();
    void (*f)(int) = *(void (**)(int))(p + 0x48);
    int x = *(int *)(p + 0x4C);
    if (f) f(x);
}

extern int D_00760DB0;
void func_0034B7A8(int);
void func_0034B818(int);
void func_00350248(int, int, int, int *);
void func_00344E58(int *, int);

// FUNCTION: GAME 0x349438
void func_00349438(void)
{
    char *p = func_003452B0();
    void (*f)(int) = *(void (**)(int))(p + 0x50);
    int x = *(int *)(p + 0x54);
    if (f) f(x);
}

// FUNCTION: GAME 0x34B778
int func_0034B778(int a)
{
    func_0034B7A8(a);
    func_0034B818(a);
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x344648
// diff: 2 words, fn pointer loaded into v1 instead of v0
void func_00344648(int a)
{
    char *p = func_003452B0();
    ((void (*)(int, int))*(int *)(p + 0x28))(*(int *)(p + 0x30), a);
}
#endif

// FUNCTION: GAME 0x3446D8
void func_003446D8(int a)
{
    char *p = func_003452B0();
    ((void (*)(int, int))*(int *)(p + 0x2C))(*(int *)(p + 0x30), a);
}

// FUNCTION: GAME 0x344E18
void func_00344E18(int a, int b, int c, int d)
{
    int x[4];
    func_00350248(a, b, c, x);
    func_00344E58(x, d);
}

// FUNCTION: GAME 0x34CA30
int func_0034CA30(char *a, int b)
{
    char *q;
    if (b == 8) return 0;
    q = a + b * 0x74;
    return *(int *)(q + 0x1318);
}

// FUNCTION: GAME 0x34CA98
int func_0034CA98(char *a, int b)
{
    char *q;
    if (b == 8) return 1;
    q = a + b * 0x74;
    return *(int *)(q + 0x131C);
}

// FUNCTION: GAME 0x34C8F0
void func_0034C8F0(char *a, int b, int c)
{
    int *q = (int *)(a + b * 0x74 + 0x1320);
    if (q[9] >= 0) q[9] += c;
}

// FUNCTION: GAME 0x344610
unsigned func_00344610(char *a, unsigned b)
{
    unsigned *p = (unsigned *)(a + 0x1EC);
    unsigned r = 0;
    unsigned n = p[3] + b;
    if (!(p[1] < n)) {
        r = p[2];
        p[3] = n;
        p[2] = r + b;
    }
    return r;
}

// FUNCTION: GAME 0x34CC40
int func_0034CC40(int **a)
{
    return ((int (*)(void))(*a)[4])() == D_00760DB0;
}

extern int D_00760DB4, D_00760D88, D_00760D8C, D_003EE084;
void *memcpy(void *, const void *, unsigned);
int func_0033B810(int, int, int, int);
void func_00346510(void), func_003465E8(void), func_003465B8(void);
int func_003464D8();

// FUNCTION: GAME 0x346498
void func_00346498(void)
{
    // barrier blocks sibcall; original 2.96 build kept jal+ld ra+jr
    if (!D_003EE084) {
        func_00346510();
        __asm__ volatile("");
    } else {
        func_003464D8();
        __asm__ volatile("");
    }
}

// FUNCTION: GAME 0x3464D8
int func_003464D8(int a, int b, void *c)
{
    memcpy(c, (void *)(0x70000000 + a), b);
    return 0;
}

// FUNCTION: GAME 0x34CC78
int func_0034CC78(int **a)
{
    return ((int (*)(void))(*a)[4])() == D_00760DB4;
}

// FUNCTION: GAME 0x348210
int func_00348210(int *a, int *b, int *c)
{
    *a = 0x249E4;
    *b = 0x9C40;
    *c = 0x800;
    return *a + *b + *c;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x34B618
// diff: 7 words, slt/movz operands allocated in a different register order
char *func_0034B618(char *a)
{
    char *p = *(char **)(a + 0x36B0);
    int *s = *(int **)(a + 0x2004);
    if (!p) return 0;
    return s[0x10] > 0 ? 0 : p + 0xD0C;
}
#endif

// FUNCTION: GAME 0x34DA50
int func_0034DA50(int a, int (*f)(int, int *))
{
    int x;
    if (f(a, &x)) return x;
    return -1;
}

// FUNCTION: GAME 0x34DA88
int func_0034DA88(int a, int b, int (*f)(int, int, int *))
{
    int x;
    if (f(a, b & 0xFF, &x)) return x;
    return -1;
}

// FUNCTION: GAME 0x348A70
void func_00348A70(int a, int b, int c)
{
    D_00760D88 = func_0033B810(6, a, b, c);
}

// FUNCTION: GAME 0x348AC8
void func_00348AC8(int a, int b, int c)
{
    D_00760D8C = func_0033B810(5, a, b, c);
}

// FUNCTION: GAME 0x34DAE8
int func_0034DAE8(char *a)
{
    int *p = (int *)(a + 0x78);
    if (!p[0]) return 0;
    return p[1] * 100 + p[2];
}

// FUNCTION: GAME 0x346578
void func_00346578(void)
{
    // barrier blocks sibcall; original 2.96 build kept jal+ld ra+jr
    if (!D_003EE084) {
        func_003465E8();
        __asm__ volatile("");
    } else {
        func_003465B8();
        __asm__ volatile("");
    }
}
