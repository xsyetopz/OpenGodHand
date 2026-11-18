// COMPILER: ee-gcc2.96
int func_0035A1C8(int, int);
int func_0034B778(int);
int func_0034D450(int);
int func_0034D318();
int func_003587E8(void);
void func_00345750(int);
int func_00348BE0();
extern char D_004573B8[];
extern char D_00457830[];

// FUNCTION: GAME 0x340700
void func_00340700(int *a)
{
    int i;
    int *p = (int *)a[2];
    int *q = (int *)a[3];
    for (i = 0; i < 0x60; i++) {
        p[i] = 0;
        q[i] = 0;
    }
    a[5] = 0;
    a[6] = 0x40;
}

// FUNCTION: GAME 0x344D50
void func_00344D50(int a, int *b)
{
    int *d = (int *)(a + 0x88);
    int t = b[0x3C / 4];
    int v;
    int u;
    d[0] = b[0x58 / 4];
    d[1] = b[0x5C / 4];
    d[2] = ((signed char *)b)[0x6C];
    d[3] = ((signed char *)b)[0x6D];
    v = ((signed char *)b)[0x6E];
    d[5] = t;
    d[4] = v;
    u = b[0x40 / 4];
    d[7] = 0;
    d[6] = u;
}

// FUNCTION: GAME 0x34B738
int func_0034B738(int a)
{
    if (func_0035A1C8(a, 6)) return func_0034B778(a);
    return 0;
}

// DRAFT: GAME 0x34D2D8
// 13 words: original passes the call result straight to a0 and speculates a1 before the branch (72 vs 64 B)
#ifdef NONMATCHING
int func_0034D2D8(int a)
{
    int r = func_0034D450(a);
    if (r) return func_0034D318(r, a + 0x78);
    return r;
}
#endif

// FUNCTION: GAME 0x343BD0
int func_00343BD0(void)
{
    if (func_003587E8()) {
        func_00345750(-0x132);
        return func_00348BE0(D_004573B8);
    }
    return 0;
}

// FUNCTION: GAME 0x3448B0
void func_003448B0(int a, int b)
{
    int v = *(int *)(a + 0x2D4);
    if (v == 0) {
        *(int *)(a + 0x2D4) = b;
    } else if (v != b) {
        func_00348BE0(D_00457830);
    }
}

int *func_00348920(int);
int *func_00348938(int);

// FUNCTION: GAME 0x348258
void func_00348258(int a)
{
    int *s = func_00348920(a);
    int *p = func_00348938(a);
    int v;
    if (p && (v = s[1]) == 0) {
        void (*fn)() = (void (*)())p[0];
        if (fn) {
            fn();
            v = s[1];
        }
        s[1] = v + 1;
    }
}

// FUNCTION: GAME 0x3482C8
void func_003482C8(int a)
{
    int *s = func_00348920(a);
    int *p = func_00348938(a);
    if (p && s[1] != 0) {
        int v = s[1] - 1;
        s[1] = v;
        if (v == 0) {
            void (*fn)() = (void (*)())p[1];
            if (fn) fn();
        }
    }
}

int func_00346828(int);
int func_003466F8(int);
int func_00359168(int, int);
extern char D_00457918[];

// FUNCTION: GAME 0x344E88
int func_00344E88(int a, int b)
{
    if (func_00346828(a) != 1) return func_00348BE0(D_00457918);
    func_003448B0(a, 2);
    return func_00359168(func_003466F8(a), b);
}

extern char D_00456FE8[];
extern char D_00457010[];
int func_00340450();

// DRAFT: GAME 0x340A60
// 16 words: original keeps n in a0 (daddu a0,a1 at entry) and clamps from the pre-clamp quotient (movz/xori); 3 probes
#ifdef NONMATCHING
void func_00340A60(int *a, int n)
{
    int v;
    int w;
    if (a == 0) {
        func_00340450(D_00456FE8);
        return;
    }
    if (n <= 0) {
        func_00340450(D_00457010);
        return;
    }
    v = n / 750;
    a[4] = n;
    w = v > 0 ? v : 1;
    a[6] = v < 0x61 ? w : 0x60;
}
#endif

int func_00346968();
void func_00347A40(int);

// FUNCTION: GAME 0x348158
void func_00348158(int a)
{
    int x[2];
    func_00346968(a, &x[0], &x[1]);
    if (x[0] / x[1] >= *(int *)(a + 0x2FC) / 1000 && *(int *)(a + 0x2E8) == 2) {
        func_00347A40(a);
        *(int *)(a + 0x2E8) = 3;
    }
}
