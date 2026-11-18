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
