// COMPILER: ee-gcc2.96
// FLAGS: -O2
// SCE helpers in 0x3229D0-0x32D000 compiled with 2.96.
extern int func_00329028();
extern int func_00329040();
extern int func_00329070();
extern int func_00329088();
extern int func_00328190();
extern void func_003282D0();
extern void func_0033F590();
extern void func_00328438();
extern int func_00328D30();
extern int func_0033E6A8();
extern int func_0033E6B0();
extern int func_003297F0();
extern void func_0032A1B0();
extern void func_0032A720();
extern void func_0033F130();
extern float func_0032AE50();
extern char D_00452318[], D_004523D8[];
extern int D_003D1414;
extern int func_00329490();
extern int func_00336BA8();
extern int func_00326800();
extern void *memset();
extern int func_0032BC98();
extern int func_0033FC70();
extern int func_0033FC88();
extern int func_0032D430();
extern void func_0033FCB0();
extern int func_0032ED48();
extern char D_00452FB0[], D_00452FD8[];

// FUNCTION: GAME 0x32ABB0
void func_0032ABB0(char *o, int v)
{
    if (!o) {
        func_0033F130(D_00452318);
        return;
    }
    *(int *)(o + 0x38) = v;
    D_003D1414 = v;
}

// FUNCTION: GAME 0x32AE10
float func_0032AE10(int a)
{
    float r;
    func_0033E6A8();
    r = func_0032AE50(a);
    func_0033E6B0();
    return r;
}

// FUNCTION: GAME 0x329438
int func_00329438(int a, int b, int c)
{
    int r;
    func_0033E6A8();
    r = func_00329490(a, b, c);
    func_0033E6B0();
    return r;
}

// FUNCTION: GAME 0x3297F0
int func_003297F0(int a, int b)
{
    int r = func_00329490(2, a + 0x400, b - 0x400);
    if (r) {
        func_00336BA8(r, a, 0x400);
        return r;
    }
    return 0;
}

// FUNCTION: GAME 0x3290A0
void func_003290A0(int a, int b)
{
    func_0033F130(b);
}

// FUNCTION: GAME 0x3292C0
void func_003292C0(int a, int b)
{
    func_0033F130(b);
}

// FUNCTION: GAME 0x32B4C8
int func_0032B4C8(char *o)
{
    return func_00326800(*(int *)(o + 4));
}

// FUNCTION: GAME 0x32BD90
int func_0032BD90(int a, int b)
{
    return func_0032BC98(a, b, 0, 0xFFFFF);
}

// FUNCTION: GAME 0x32D3A8
int func_0032D3A8(int a, int b, int c, int d)
{
    int s[3];
    int r;
    memset(s, 0, 12);
    s[0] = a;
    s[1] = b;
    s[2] = 0;
    func_0033FC70();
    r = func_0032D430(s, c, d);
    func_0033FC88();
    return r;
}

// FUNCTION: GAME 0x32ECD8
int func_0032ECD8(char *o, int i, int v)
{
    if (!o) {
        func_0033FCB0(D_00452FB0);
        return;
    }
    if (i >= 0x21) {
        func_0033FCB0(D_00452FD8);
        return;
    }
    *(int *)(o + i * 4 + 0x1EC) = v;
    return func_0032ED48(o, i, *(int *)(o + 0x1E8) + v);
}
