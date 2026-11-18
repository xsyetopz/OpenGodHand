// COMPILER: ee-gcc2.96
extern unsigned strlen(const char *);
// FUNCTION: GAME 0x334CA0
int func_00334CA0(char *s)
{
    unsigned n = strlen(s);
    unsigned i;
    unsigned m = n > 16 ? 16 : n;
    for (i = 0; i < m; i++) {
        if (s[i] == ':')
            return 1;
    }
    return 0;
}

extern void *memset(void *, int, unsigned);
extern int strcmp(const char *, const char *);
extern char D_004549F8[];
struct S4 { char c[4]; };
// FUNCTION: GAME 0x334D10
int func_00334D10(char *s)
{
    char b[6];
    memset(b, 0, 6);
    *(struct S4 *)b = *(struct S4 *)s;
    b[5] = 0;
    return strcmp(b, D_004549F8) == 0;
}

extern char *strcpy(char *, const char *);
extern char D_003DA4A0[], D_00454BB0[];
struct S6 { char c[6]; };
// FUNCTION: GAME 0x3352D0
void func_003352D0(char *s)
{
    if (s == 0) {
        *(struct S6 *)D_003DA4A0 = *(struct S6 *)D_00454BB0;
        return;
    }
    strcpy(D_003DA4A0, s);
}

extern void func_00329EA8(void), func_00325C60(void), func_00340680(int), func_003404F0(int);
extern int func_00325C78();
struct U1 { char _0[0xE8]; int mE8; };
struct U0 { char _0[4]; struct U1 *m4; };
struct U { char _0[4]; struct U0 *m4; };
// FUNCTION: GAME 0x336DB0
int func_00336DB0(struct U *u)
{
    struct U1 *w = u->m4->m4;
    int h = w->mE8;
    if (h) {
        func_00329EA8();
        func_00325C60();
        func_00340680(h);
        w->mE8 = 0;
        func_003404F0(0);
        return func_00325C78();
    }
}

extern int D_003E0710, D_003E0708;
struct W2 { char _0[0x24]; int (*m24)(void *, int); };
struct W1 { struct W2 *m0; };
struct W0 { char _0[8]; struct W1 *m8; };
struct W { char _0[8]; struct W0 *m8; };
// FUNCTION: GAME 0x338418
int func_00338418(struct W *w)
{
    struct W1 *o;
    int r;
    if (D_003E0710 == 1 && D_003E0708 <= 0)
        return 0;
    o = w->m8->m8;
    r = o->m0->m24(o, 0);
    return r / 2;
}

// FUNCTION: GAME 0x3383B0
int func_003383B0(struct W *w)
{
    struct W1 *o;
    int r;
    if (D_003E0710 == 1 && D_003E0708 <= 0)
        return 0;
    o = w->m8->m8;
    r = o->m0->m24(o, 0);
    return (0x4000 - r) / 2;
}

extern void func_00335CD8();
extern int func_003356B0();
extern void func_00335CE0();
// FUNCTION: GAME 0x335638
int func_00335638(int a, int b, int c, int d, int e)
{
    int r;
    func_00335CD8();
    r = func_003356B0(a, b, c, d, e);
    func_00335CE0();
    return r;
}

extern void func_00338A48();
extern char D_00455970[], D_00455920[], D_00455980[], D_00455950[];
struct Q { int m0; int m4; int m8; };
// FUNCTION: GAME 0x338D90
int func_00338D90(struct Q *q)
{
    if (q == 0) {
        func_00338A48(D_00455970, D_00455920);
        return 0;
    }
    if (q->m4 == 0) {
        func_00338A48(D_00455980, D_00455950);
        return 0;
    }
    return q->m8;
}

extern void func_00339458();
extern char D_00455AD0[], D_00455A80[], D_00455AE0[], D_00455AB0[];
struct Z { int m0; int m4; char _8[8]; int m10; int mC; };
// FUNCTION: GAME 0x3397C8
void func_003397C8(int *z)
{
    if (z == 0) {
        func_00339458(D_00455AD0, D_00455A80);
        return;
    }
    if (z[1] == 0) {
        func_00339458(D_00455AE0, D_00455AB0);
        return;
    }
    {
    int t = z[8];
    z[13] = 0;
    z[3] = 0;
    z[5] = 0;
    z[6] = 0;
    z[10] = 0;
    z[11] = 0;
    z[12] = 0;
    z[4] = t;
    }
}

extern void func_00336330();
extern char D_004551E8[];
struct D { int m0; int m4; int m8; int mC; int m10; int m14; int m18; };
// FUNCTION: GAME 0x336A40
void func_00336A40(struct D *d, int n)
{
    int old, a, b;
    if (d == 0) {
        func_00336330(d, D_004551E8);
        return;
    }
    a = d->m8;
    b = d->m10;
    old = d->m4;
    d->m4 = n;
    d->mC = (a + n - 1) / n;
    d->m10 = (b * old) / n;
    d->m14 = d->m18 * n;
}

extern char D_003DA398[], D_00454A00[];
struct S2 { char c[2]; };
// FUNCTION: GAME 0x335248
void func_00335248(char *s)
{
    if (s == 0) {
        D_003DA398[0] = 0;
        return;
    }
    if (*s != '/' && *s != '\\')
        *(struct S2 *)D_003DA398 = *(struct S2 *)D_00454A00;
    else
        D_003DA398[0] = 0;
    strcpy(D_003DA398, s);
}

extern int D_003E7FE8;
extern char D_003E7FF0[];
extern int D_003E7FE8;
extern char D_003E7FF0[];
// FUNCTION: GAME 0x33A0C0
void func_0033A0C0(void)
{
    if (D_003E7FE8 == 0)
        memset(D_003E7FF0, 0, 0xC00);
    D_003E7FE8++;
}

extern void func_0033A048();
extern char D_00455C28[], D_00455BD8[], D_00455C38[], D_00455C08[];
// FUNCTION: GAME 0x33A3C0
int func_0033A3C0(char *p)
{
    if (p == 0) {
        func_0033A048(D_00455C28, D_00455BD8);
        return 0;
    }
    if (p[4] == 0) {
        func_0033A048(D_00455C38, D_00455C08);
        return 0;
    }
    return *(int *)(p + 8);
}

extern void func_00332508();
extern int D_003E8DCC;
extern volatile int D_003E8DC8;
// FUNCTION: GAME 0x33AFC0
void func_0033AFC0(void)
{
    int a = D_003E8DCC;
    int v = D_003E8DC8;
    if (a == 0) {
        func_00332508();
        a = D_003E8DCC;
    }
    D_003E8DCC = a + 1;
}

extern int D_003E0710, D_003E0708;
extern void func_00326050();
extern char D_00455788[];
// FUNCTION: GAME 0x338710
void func_00338710(int *o, int n)
{
    if (D_003E0710 == 1 && D_003E0708 <= 0)
        return;
    if (48000 % n)
        func_00326050(D_00455788);
    o[12] = n;
}

extern void func_0033F130();
extern char D_004568D0[];
struct C { char _0[0xE]; char mE; char _f[0xD9]; int mE8; };
// FUNCTION: GAME 0x33CE98
int func_0033CE98(struct C *c)
{
    int t = c->mE;
    unsigned char u = c->mE;
    if (t == 1 && c->mE8 != 0)
        return 2;
    if (c == 0) {
        func_0033F130(D_004568D0);
        return -1;
    }
    return (char)u;
}
