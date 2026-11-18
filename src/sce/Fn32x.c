// COMPILER: ee-gcc3.2-030926
// SCE library leaf accessors in 0x320000-0x33FFFF (ee-gcc 3.2, -O2 -G0).

// FUNCTION: GAME 0x320260
void func_00320260(void)
{
}

// FUNCTION: GAME 0x328D78
int func_00328D78(int *p)
{
    return p[4];
}

// FUNCTION: GAME 0x339430
int func_00339430(int *p)
{
    return p[6];
}

// FUNCTION: GAME 0x328DB8
int func_00328DB8(int *p)
{
    return p[5];
}

// FUNCTION: GAME 0x3280D0
signed char func_003280D0(signed char *p)
{
    return p[1];
}

// FUNCTION: GAME 0x327720
void func_00327720(char *p, int v)
{
    *(int *)(p + 0x9C) = v;
}

// FUNCTION: GAME 0x32B658
void func_0032B658(char *p, int v)
{
    *(int *)(p + 0x88) = v;
}

// FUNCTION: GAME 0x327768
void func_00327768(char *p, int v)
{
    *(int *)(p + 0x44) = v;
}

// FUNCTION: GAME 0x32AB20
void func_0032AB20(char *p, int v)
{
    p[0xAD] = v;
}

// FUNCTION: GAME 0x33C228
void func_0033C228(char *p)
{
    p[1] = 0;
}

// FUNCTION: GAME 0x320268
void func_00320268(void)
{
}

// FUNCTION: GAME 0x3202D8
void func_003202D8(void)
{
}

// FUNCTION: GAME 0x320720
short func_00320720(char *p)
{
    return *(short *)(p + 0x4);
}

// FUNCTION: GAME 0x320AE0
void func_00320AE0(void)
{
}

// FUNCTION: GAME 0x3262B8
void func_003262B8(void)
{
}

// FUNCTION: GAME 0x326490
void func_00326490(void)
{
}

// FUNCTION: GAME 0x327710
int func_00327710(char *p)
{
    return *(int *)(p + 0x2C);
}

// FUNCTION: GAME 0x327758
void func_00327758(char *p, int v)
{
    *(int *)(p + 0x3C) = v;
}

// FUNCTION: GAME 0x327760
void func_00327760(char *p, int v)
{
    *(int *)(p + 0x40) = v;
}

// FUNCTION: GAME 0x328C70
void func_00328C70(void)
{
}

// FUNCTION: GAME 0x328F68
signed char func_00328F68(char *p)
{
    return *(signed char *)(p + 0x2);
}

// FUNCTION: GAME 0x32AF80
void func_0032AF80(char *p, int v)
{
    *(char *)(p + 0x6D) = v;
}

// FUNCTION: GAME 0x32B488
void func_0032B488(void)
{
}

// FUNCTION: GAME 0x32B490
void func_0032B490(void)
{
}

// FUNCTION: GAME 0x32CE98
void func_0032CE98(void)
{
}

// FUNCTION: GAME 0x32F468
signed char func_0032F468(char *p)
{
    return *(signed char *)(p + 0x1);
}

// FUNCTION: GAME 0x32F4B0
void func_0032F4B0(char *p, int v)
{
    *(int *)(p + 0x1C) = v;
}

// FUNCTION: GAME 0x32F4B8
void func_0032F4B8(char *p, int v)
{
    *(char *)(p + 0x3) = v;
}

// FUNCTION: GAME 0x32F4C0
void func_0032F4C0(char *p, int v)
{
    *(char *)(p + 0x4) = v;
}

// FUNCTION: GAME 0x32F4C8
signed char func_0032F4C8(char *p)
{
    return *(signed char *)(p + 0xAC);
}

// FUNCTION: GAME 0x32F4F0
int func_0032F4F0(char *p)
{
    return *(int *)(p + 0x2B0);
}

// FUNCTION: GAME 0x32F528
int func_0032F528(char *p)
{
    return *(int *)(p + 0x1934);
}

// FUNCTION: GAME 0x32F570
int func_0032F570(char *p)
{
    return *(int *)(p + 0x1958);
}
