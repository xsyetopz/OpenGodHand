// COMPILER: ee-gcc2.9-991111
// SCE libm float helpers and small runtime stubs in 0x394F20-0x3A53A8.

extern int D_003F8590[];
extern int D_003F8560[];
extern int *_impure_ptr;
extern void func_0031E870(long, long);

// FUNCTION: GAME 0x395388
int *func_00395388(void)
{
    return D_003F8560;
}

// FUNCTION: GAME 0x3970A0
unsigned int func_003970A0(unsigned int a)
{
    if ((a >> 28) == 7)
    {
        a &= 0xFFFFFFF;
        a |= 0x80000000;
    }
    return a;
}

// FUNCTION: GAME 0x397100
int func_00397100(unsigned int i)
{
    if (i < 10)
        return D_003F8590[i];
    return 0;
}

// FUNCTION: GAME 0x3A4AC8
int func_003A4AC8(long *p)
{
    long x = p[1];
    func_0031E870(x, x);
    return 0;
}

// FUNCTION: GAME 0x3A4FB8
int *func_003A4FB8(void)
{
    return _impure_ptr;
}
