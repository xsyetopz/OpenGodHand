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
