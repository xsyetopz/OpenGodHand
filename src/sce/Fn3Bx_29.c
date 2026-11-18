// COMPILER: ee-gcc2.9-991111
// SCE library units built by SCE ee-gcc 2.9x (sd s0 prologues), -O2 -G0.

extern int *func_003A4FB8(void);
extern void iSignalSema(int);
extern void func_003B0D80(int);
extern void func_003B0D48(int);
extern void func_003B0E30(int);
extern void func_003B2450(void);
extern int D_003FAE54;
extern void func_003B3E70(void);
extern int D_003FAEE4;
extern int WaitSema(int);
extern int func_003B5C48(int, int, int, int *);
extern int func_003B5E78(int, int, int, int *, int);
extern void func_003B6818(int);
extern void func_003AF8C0(int);
extern int func_003B00D0(int, int *);
extern void (*D_003D141C)(void);

// FUNCTION: GAME 0x3B0360
int func_003B0360(void)
{
    *func_003A4FB8() = 5;
    return -1;
}

// FUNCTION: GAME 0x3B0D20
int func_003B0D20(int a, int b, int c, int d)
{
    iSignalSema(d);
    __asm__ volatile("sync\n\tei");
    return 0;
}

// FUNCTION: GAME 0x3B0E30
void func_003B0E30(int c)
{
    if (c == 10) {
        func_003B0D48(13);
        func_003B0D48(10);
    } else
        func_003B0D48(c);
}

// FUNCTION: GAME 0x3B1E40
int func_003B1E40(int a, int b, int c)
{
    if (c)
        func_003B0D80(c);
    return 1;
}

// FUNCTION: GAME 0x3B1E68
int func_003B1E68(int a, int b, int c)
{
    if (c)
        func_003B0E30(c);
    return 1;
}

// FUNCTION: GAME 0x3B2AA0
void func_003B2AA0(void)
{
    func_003B2450();
    D_003FAE54 = 0;
}

// FUNCTION: GAME 0x3B3EC8
int func_003B3EC8(void)
{
    func_003B3E70();
    WaitSema(D_003FAEE4);
    return 0;
}

// FUNCTION: GAME 0x3B5E50
int func_003B5E50(int a, int b, int c)
{
    int v;
    return func_003B5C48(a, b, c, &v);
}

// FUNCTION: GAME 0x3B60A0
int func_003B60A0(int a, int b, int c)
{
    int v;
    return func_003B5E78(a, b, c, &v, 0);
}

// FUNCTION: GAME 0x3B6820
void func_003B6820(int a)
{
    func_003B6818(a);
    func_003AF8C0(a);
}

// FUNCTION: GAME 0x3B7AA8
int func_003B7AA8(int a)
{
    int v = a;
    return func_003B00D0(0x10, &v);
}

// FUNCTION: GAME 0x3B9AF8
void func_003B9AF8(void)
{
    if (D_003D141C)
        D_003D141C();
}
