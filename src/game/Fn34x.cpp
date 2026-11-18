// Small leaf functions in 0x340000-0x34FFFF (SCE-library-looking region).

// FUNCTION: GAME 0x340128
extern "C" int func_00340128(char *p)
{
    return p[1];
}

// FUNCTION: GAME 0x342B98
extern "C" void func_00342B98(int *p)
{
    *p = 0;
}

// FUNCTION: GAME 0x342E80
extern "C" int func_00342E80()
{
    return 0x100;
}

// FUNCTION: GAME 0x3446D0
extern "C" void func_003446D0()
{
}

// FUNCTION: GAME 0x344790
extern "C" int func_00344790(char *p)
{
    return *(int *)(p + 0x200);
}

// FUNCTION: GAME 0x3466F0
extern "C" void func_003466F0()
{
}

// FUNCTION: GAME 0x346C10
extern "C" int func_00346C10()
{
    return 0x181F;
}

// FUNCTION: GAME 0x346C48
extern "C" int func_00346C48(char *p)
{
    return *(int *)(p + 0xA8);
}

// FUNCTION: GAME 0x349718
extern "C" void func_00349718(char *p, int v)
{
    *(int *)(p + 0x60) = v;
}

// FUNCTION: GAME 0x349720
extern "C" int func_00349720(char *p)
{
    return *(int *)(p + 0x60);
}
