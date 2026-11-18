// COMPILER: ee-gcc2.96
extern int D_003EE340[];

// FUNCTION: GAME 0x3592D0
void func_003592D0(int *p)
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
}

// FUNCTION: GAME 0x35C320
void func_0035C320(int *o, int i, int v)
{
    (o += i * 17)[0x1F30 / 4] = v;
}

// FUNCTION: GAME 0x35C338
int func_0035C338(int *o, int i)
{
    return (o += i * 17)[0x1F30 / 4];
}

// FUNCTION: GAME 0x35C350
void func_0035C350(int *o, int i, int v)
{
    (o += i * 17)[0x1F34 / 4] = v;
}

// FUNCTION: GAME 0x35C380
int func_0035C380(int *o, int i)
{
    return (o += i * 17)[0x1F3C / 4] != 0;
}

// FUNCTION: GAME 0x359AB0
int func_00359AB0(int *o)
{
    return func_0035C380(o, 1) != 0;
}

// FUNCTION: GAME 0x35C4C8
void func_0035C4C8(char *o, long *s)
{
    *(long *)(o + 0x138) = s[0];
    *(long *)(o + 0x140) = s[1];
}

// FUNCTION: GAME 0x35C4E0
void func_0035C4E0(char *o, long *s)
{
    *(long *)(o + 0x148) = s[0];
    *(long *)(o + 0x150) = s[1];
}

// FUNCTION: GAME 0x35D728
void func_0035D728(int *p)
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
}

// FUNCTION: GAME 0x35F958
void func_0035F958(int a, int b)
{
    int *p = D_003EE340;
    p[0] = a;
    p[1] = b;
}
