// COMPILER: ee-gcc2.96
extern void *memset();
extern char D_00452408[], D_004523D8[], D_004522B8[];
extern int func_0033F130(), func_00327890(), func_003263E0();

// FUNCTION: GAME 0x0032AA30
int func_0032AA30(char *a, int b)
{
    int r;
    if (a == 0)
        return func_0033F130(D_004522B8);
    *(short *)(a + 0x40) = b;
    if (a[0xAD] == 1)
        r = func_00327890(*(int *)(a + 4));
    else
        r = 0;
    return func_003263E0(*(int *)(a + 0xC), *(short *)(a + 0x40) + r);
}

// FUNCTION: GAME 0x0032AD48
int func_0032AD48(int *a)
{
    int *o;
    if (a == 0) {
        func_0033F130(D_004523D8);
        return -1;
    }
    o = (int *)a[5];
    if (o)
        return ((int (*)())(*(int **)o)[9])(o, 1) / 2048;
    return 0;
}

// FUNCTION: GAME 0x0032ADA8
int func_0032ADA8(int *a, int b)
{
    int *o;
    if (a == 0 || b < 0) {
        func_0033F130(D_00452408);
        return -1;
    }
    o = (int *)a[b + 6];
    if (o)
        return ((int (*)())(*(int **)o)[9])(o, 1) / 2;
    return 0;
}

// FUNCTION: GAME 0x0032B7F0
int func_0032B7F0(unsigned short *p, int n, int *out)
{
    unsigned short u;
    if (n < 2) return 0;
    u = *p;
    u = (u >> 8) | (u << 8);
    if (u != 0x8001) return 0;
    *out = n;
    return 1;
}

// FUNCTION: GAME 0x0032F938
void func_0032F938(char *a)
{
    memset(a, 0, 0x18B8);
    *(int *)(a + 0x210) = 1;
    *(int *)(a + 0x1894) = 1;
    *(short *)(a + 0x1898) = 0;
    *(short *)(a + 0x189A) = 1;
    *(short *)(a + 0x189C) = 0;
    *(short *)(a + 0x189E) = 0;
    a[0xC] = 1;
}
