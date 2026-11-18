// COMPILER: ee-gcc2.96
// FLAGS: -O2
// SCE helpers in 0x32D000-0x330000 compiled with 2.96 (continuation of Fn328_96.c).
extern int func_0032EBD8();
extern int func_00330268();
extern void func_0032D868();
extern void func_0033FC70();
extern void func_0033FC88();
extern int func_0032DC90();
extern void func_0032DD70();
extern void func_0033FCB0();
extern void func_0033FCA0();
extern void func_0033FCA8();
extern void func_0032E090();
extern int func_0032F4C8();
extern int func_0032A9F0();
extern void *memset();
extern char D_00452C98[], D_00452DB0[], D_003D1E70[];
extern int D_003D1E68;
extern int func_0032F4F0();
extern int func_0032F528();
extern int func_0033BF18();
extern void func_0032E770();
extern void func_0032ECD8();
extern int func_0032F330();
extern char D_00452DE8[], D_00452E20[];
extern int D_003D147C;
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

// FUNCTION: GAME 0x32DFC0
void func_0032DFC0(char *o, int a, int b)
{
    if (!o) {
        func_0033FCB0(D_00452C98);
        return;
    }
    func_0033FC70();
    *(int *)(o + 0x1C4) = a;
    *(int *)(o + 0x1C8) = a + b;
    func_0033FC88();
}

// FUNCTION: GAME 0x32E040
void func_0032E040(int a, int b)
{
    func_0033FCA0();
    func_0033FC70();
    func_0032E090(a, b);
    func_0033FC88();
    func_0033FCA8();
}

// FUNCTION: GAME 0x32E228
int func_0032E228(char *o)
{
    if (!o) {
        func_0033FCB0(D_00452DB0);
        return -1;
    }
    if ((unsigned char)(o[1] - 1) < 3)
        return func_0032F4C8(*(int *)(o + 4));
    return 0;
}

// FUNCTION: GAME 0x32F230
void func_0032F230()
{
    func_0033FC70();
    if (!D_003D1E68)
        memset(D_003D1E70, 0, 0x6590);
    D_003D1E68++;
    func_0033FC88();
}

// FUNCTION: GAME 0x32F288
void func_0032F288()
{
    func_0033FC70();
    if (--D_003D1E68 == 0)
        memset(D_003D1E70, 0, 0x6590);
    func_0033FC88();
}

// FUNCTION: GAME 0x32F428
void func_0032F428(char *o)
{
    func_0033FC70();
    if (o)
        memset(o, 0, 0x1964);
    func_0033FC88();
}

// FUNCTION: GAME 0x32E2B8
int func_0032E2B8(char *o)
{
    if (!o) {
        func_0033FCB0(D_00452DE8);
        return -1;
    }
    if ((unsigned char)(o[1] - 1) < 3)
        return func_0032F4F0(*(int *)(o + 4));
    return 0;
}

// FUNCTION: GAME 0x32E348
int func_0032E348(char *o)
{
    if (!o) {
        func_0033FCB0(D_00452E20);
        return -1;
    }
    if ((unsigned char)(o[1] - 1) < 3)
        return func_0032F528(*(int *)(o + 4));
    return 0;
}

// FUNCTION: GAME 0x32E720
void func_0032E720(int a)
{
    if (func_0033BF18(&D_003D147C)) {
        func_0032E770(a);
        D_003D147C = 0;
    }
}

// FUNCTION: GAME 0x32EC78
void func_0032EC78(int a, int b, int c)
{
    func_0033FCA0();
    func_0033FC70();
    func_0032ECD8(a, b, c);
    func_0033FC88();
    func_0033FCA8();
}

// FUNCTION: GAME 0x32F2D8
int func_0032F2D8(int a, int b, int c)
{
    int r;
    func_0033FC70();
    r = func_0032F330(a, b, c);
    func_0033FC88();
    return r;
}

// FUNCTION: GAME 0x32F470
void func_0032F470(char *o)
{
    func_0033FC70();
    *(int *)(o + 0x10) = 0;
    *(int *)(o + 8) = 0;
    *(int *)(o + 0xC) = 0;
    o[1] = 1;
    func_0033FC88();
}

// FUNCTION: GAME 0x32F538
int func_0032F538(char *o)
{
    int n = *(int *)(o + 0x2B0);
    int s = 0;
    if (n > 0) {
        int *p = (int *)(o + 0x2BC);
        do {
            s += *p;
            p += 4;
        } while (--n);
    }
    return s;
}

// FUNCTION: GAME 0x328288
int func_00328288(char *o, int v)
{
    func_00329028();
    func_00328190(o);
    *(int *)(o + 0x5C) = v;
    func_00329040();
    return 1;
}

// FUNCTION: GAME 0x328398
void func_00328398(char *o)
{
    func_003282D0(o);
    do {
        func_0033F590();
    } while (o[1] != 1 || *(int *)(o + 0x24) != 0);
}

// FUNCTION: GAME 0x3283E8
void func_003283E8(int a, int b, int c)
{
    func_00329070();
    func_00328438(a, b, c);
    func_00329088();
}

// FUNCTION: GAME 0x328CE8
int func_00328CE8(int a, int b)
{
    int r;
    func_00329070();
    r = func_00328D30(a, b);
    func_00329088();
    return r;
}

// FUNCTION: GAME 0x3297A8
int func_003297A8(int a, int b)
{
    int r;
    func_0033E6A8();
    r = func_003297F0(a, b);
    func_0033E6B0();
    return r;
}

// FUNCTION: GAME 0x32A160
void func_0032A160(int a, int b, int c)
{
    func_0033E6A8();
    func_0032A1B0(a, b, c);
    func_0033E6B0();
}

// FUNCTION: GAME 0x32A6D0
void func_0032A6D0(int a, int b, int c)
{
    func_0033E6A8();
    func_0032A720(a, b, c);
    func_0033E6B0();
}
