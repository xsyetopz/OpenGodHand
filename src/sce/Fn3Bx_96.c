// COMPILER: ee-gcc2.96
// Error-hook helpers near 0x3B9D30 compile with ee-gcc 2.96 (dead sd/ld ra around a tail jump).

extern void func_003BA088();
extern void func_003BA058();
extern void func_0033F130(int);
extern void func_0033B658(void);
extern void func_0033B670(void);
extern void (*D_003FC7AC)(int, int);
extern int D_003FC7B0;
extern int D_003FC50C;
extern int D_003FC7A8;
extern char D_003FC7B8[];
extern char D_00460900[];
extern char D_00460928[];

extern void *memset(void *, int, unsigned);
extern void func_003B9DE0(const char *);

extern void *memset(void *, int, unsigned);
extern void func_003B9DE0(const char *);
extern void func_003B9FB8();
extern void func_003B9FD0();
extern void func_003BA058();
extern void func_003BA8C0();
extern void func_003BA900();
extern void func_003B9E10();
extern void func_003B9D98();
extern void func_003B9D48();
extern void func_003B9D30();
extern char D_00460818[];
extern char D_00460840[];
extern char D_004608B0[];
extern char D_00460888[];
extern void (*D_003D141C)();
extern void (*D_003E9D20)();
extern void (*D_003D1420)();
extern void (*D_003E9D18)();
extern void (*D_003E9D1C)();
extern void func_003B9B20();
extern void func_003B9BF0();
extern void func_003B9BB8();
extern void func_003B9CE8();
extern void func_00329EA8();
extern void func_003B9AF8();
extern void func_00326220();
extern void func_00326238();
extern void func_00325C60();
extern void func_0033F1A8();
extern void func_00325C78();
extern void func_00326250();
extern void func_003B9E60();
extern int func_003BA800();
extern void func_003BA000();
extern void func_003BA0C8();
extern void func_003BA830();
extern int *func_003B9F60(void);
extern int *func_003B9EB0();

// FUNCTION: GAME 0x3B9B20
void func_003B9B20(int *a)
{
    int *b, *c, *s;
    func_00329EA8();
    b = (int *)a[1];
    c = (int *)b[1];
    s = (int *)c[0x30];
    if (s) {
        func_00325C60();
        func_003BA058(s);
        func_003B9FD0(s);
        c[0x30] = 0;
        func_00325C78();
        func_00326220(a, 0);
        func_00326250(a);
        func_003B9E60();
    }
}

// FUNCTION: GAME 0x3B9BF0
void func_003B9BF0(int *a)
{
    int v[2];
    int s = a[0x30];
    if (!func_003BA800(s)) {
        a[0x22] = 0;
        ((void (*)())func_003BA058)(s);
    }
    if (a[1] == 1) {
        a[0x22] = 0;
        ((void (*)())func_003BA000)(s);
        a[1] = 2;
    } else if (a[1] == 2) {
        int t;
        func_003BA0C8(s);
        ((void (*)())func_003BA830)(s, &v[0], &v[1]);
        t = v[1] / 4 - a[0x22];
        a[0x25] = v[0];
        a[0x24] = t;
        a[0x22] += t;
        if (func_003BA800(s) == 3) {
            ((void (*)())func_003BA058)(s);
            a[1] = 0;
            a[6] = v[1] / 4;
        }
    }
}

// FUNCTION: GAME 0x3B9EB0
int *func_003B9EB0(int a, int b)
{
    int *p;
    if (!a) {
        func_003B9DE0(D_00460888);
        return 0;
    }
    if (b < 0x1800) {
        func_003B9DE0(D_004608B0);
        return 0;
    }
    p = func_003B9F60();
    if (p) {
        memset(p, 0, 0x3C);
        func_003B9FB8(p);
        p[2] = a;
        p[3] = b;
        p[6] = 2;
        p[0] = 1;
    }
    return p;
}

// FUNCTION: GAME 0x3B9998
void func_003B9998(int *a, int b, int c)
{
    int *s4 = &a[6];
    int s1, *s5, *s0;
    func_00329EA8();
    func_003B9AF8(a);
    func_00326220(a, 1);
    func_00326238(a, 0);
    func_003B9E10();
    func_003B9D98(func_003B9D48, 0);
    s5 = (int *)((int *)a[1])[1];
    s1 = a[4];
    func_00325C60();
    s0 = func_003B9EB0(b, c);
    if (!s0) {
        func_0033F1A8(D_00460818, D_00460840);
        return;
    }
    func_003BA8C0(s0, s1, *s4);
    func_003BA900(s0, 0x14);
    s5[0x30] = (int)s0;
    D_003D141C = func_003B9B20;
    D_003E9D20 = func_003B9BF0;
    D_003D1420 = func_003B9BB8;
    D_003E9D18 = func_003B9CE8;
    D_003E9D1C = func_003B9D30;
    func_00325C78();
}

// FUNCTION: GAME 0x3B9D30
void func_003B9D30(void)
{
    func_003BA088();
}

// FUNCTION: GAME 0x3B9D48
void func_003B9D48(int a, int b)
{
    func_0033F130(b);
}

// FUNCTION: GAME 0x3B9D60
void func_003B9D60(void)
{
}

// FUNCTION: GAME 0x3B9D68
void func_003B9D68(void)
{
    D_003FC50C++;
}

// FUNCTION: GAME 0x3B9D80
void func_003B9D80(void)
{
    D_003FC50C--;
}

// FUNCTION: GAME 0x3B9D98
void func_003B9D98(void (*a)(int, int), int b)
{
    D_003FC7AC = a;
    D_003FC7B0 = b;
}

// FUNCTION: GAME 0x3B9DB0
void func_003B9DB0(void)
{
    func_0033B658();
}

// FUNCTION: GAME 0x3B9DC8
void func_003B9DC8(void)
{
    func_0033B670();
}

// FUNCTION: GAME 0x3B9DE0
void func_003B9DE0(const char *a)
{
    if (D_003FC7AC)
        D_003FC7AC(D_003FC7B0, (int)a);
}

// 0x3B9E10 near-miss: only register allocation differs (orig counter in a0 and base in v1; ours v0)
// DRAFT: GAME 0x3B9E10
#ifdef NONMATCHING
void func_003B9E10(void)
{
    int *c = &D_003FC7A8;
    if (*c == 0)
        memset(D_003FC7B8, 0, 0x3C);
    *c = *c + 1;
}
#endif

// FUNCTION: GAME 0x3B9FB8
void func_003B9FB8(int *p)
{
    p[1] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
}

// FUNCTION: GAME 0x3B9FD0
void func_003B9FD0(void *a)
{
    func_003BA058(a);
    memset(a, 0, 0x3C);
}

// FUNCTION: GAME 0x3BA058
void func_003BA058(int *p)
{
    if (!p) {
        func_003B9DE0(D_00460900);
        return;
    }
    p[1] = 0;
}

// FUNCTION: GAME 0x3BA088
void func_003BA088(int *p)
{
    if (!p) {
        func_003B9DE0(D_00460928);
        return;
    }
    p[9] = 1;
}

extern void func_003B9FB8();
extern void func_003BA878();
extern void func_003BA8C0();
extern int func_003B63A0();
extern void func_003B63F0();
extern char D_004608D8[];
extern char D_00460AD0[];
extern char D_00460AF8[];
extern char D_00460B20[];
extern char D_00460B48[];
extern char D_00460B70[];

// FUNCTION: GAME 0x3B9CE8
void func_003B9CE8(int a, int b)
{
    int x;
    func_003BA878(a, 0, &x);
    func_003BA8C0(a, b, x);
}

// FUNCTION: GAME 0x3B9E60
void func_003B9E60(void)
{
    int *c = &D_003FC7A8;
    if (*c == 1)
        memset(D_003FC7B8, 0, 0x3C);
    *c = *c - 1;
}

// FUNCTION: GAME 0x3BA000
void func_003BA000(int *p)
{
    if (!p) {
        func_003B9DE0(D_004608D8);
        return;
    }
    ((void (*)())func_003BA058)();
    func_003B9FB8(p);
    p[1] = 1;
}

// FUNCTION: GAME 0x3BA830
void func_003BA830(int *a, int *b, int *c)
{
    if (!a) {
        func_003B9DE0(D_00460AD0);
        return;
    }
    if (b)
        *b = a[7];
    if (c)
        *c = a[8];
}

// FUNCTION: GAME 0x3BA878
void func_003BA878(int *a, int *b, int *c)
{
    if (!a) {
        func_003B9DE0(D_00460AF8);
        return;
    }
    if (b)
        *b = a[4];
    if (c)
        *c = a[5];
}

// FUNCTION: GAME 0x3BA8C0
void func_003BA8C0(int *a, int b, int c)
{
    if (!a || !b || !c) {
        func_003B9DE0(D_00460B20);
        return;
    }
    a[4] = b;
    a[5] = c;
}

// FUNCTION: GAME 0x3BA900
void func_003BA900(int *a, int b)
{
    if (!a) {
        func_003B9DE0(D_00460B48);
        return;
    }
    if (b <= 0) {
        func_003B9DE0(D_00460B70);
        return;
    }
    a[6] = 144000 / (b * 1536) + 1;
}

// 0x3BA978 near-miss: frame 0x20 with ra at 0x10 (extra 8 bytes of locals) and the constant hoisting/scheduling differ
#ifdef NONMATCHING
// DRAFT: GAME 0x3BA978
void func_003BA978(int a)
{
    int r = func_003B63A0(a);
    *(volatile unsigned *)0x1000F590 = *(volatile unsigned *)0x1000F520 | 0x10000;
    *(volatile int *)0x1000B000 = a;
    *(volatile unsigned *)0x1000F590 = *(volatile unsigned *)0x1000F520 & 0xFFFEFFFF;
    if (r)
        func_003B63F0();
}
#endif

// 0x3B9F60 near-miss: original is a do-while over D_003FC7B8 (stride 0x3C) with two induction pointers and loop padding; ours folds the one-element loop (24 vs 84 bytes)
