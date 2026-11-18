// COMPILER: ee-gcc2.96
// FLAGS: -O2
extern int memcmp();
extern char D_00457040[], D_00457048[], D_00457050[], D_00457058[];
extern void func_00344680();
extern void func_00348BE0();
extern int func_0035D918();
extern int func_0035E520();

// FUNCTION: GAME 0x340E90
int func_00340E90(char *p)
{
    if (memcmp(p, D_00457040, 4) == 0 && memcmp(p + 8, D_00457048, 4) == 0)
        return 1;
    return 0;
}

// FUNCTION: GAME 0x341798
int func_00341798(char *p)
{
    if (memcmp(p, D_00457050, 4) == 0 || memcmp(p, D_00457058, 4) == 0)
        return 1;
    return 0;
}

// FUNCTION: GAME 0x344710
void func_00344710(char *o)
{
    int i;
    int *p = (int *)(o + 0x280);
    for (i = 31; i >= 0; i--) {
        if (*p) {
            func_00344680(o, *p);
            *p = 0;
        }
        p--;
    }
}

// FUNCTION: GAME 0x3451D8
int func_003451D8(int a)
{
    int s[2];
    int r = func_0035D918(a, 0xE0, s);
    int t;
    if (r != 1)
        return 0;
    t = s[0];
    if (t != r)
        return 0;
    if (func_0035E520(a, 0xE0, s + 1) != t)
        return 0;
    return s[1] == 3;
}

// FUNCTION: GAME 0x3452C0
void func_003452C0(int a, char *b)
{
    func_00348BE0(b);
}
