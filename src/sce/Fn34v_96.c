// COMPILER: ee-gcc2.96
char *func_003452B0(void);
void func_003B9D80(void);
void func_00324AC8(void);
int func_00329F98(int);

// FUNCTION: GAME 0x3496F0
void func_003496F0(int a)
{
    *(int *)(func_003452B0() + 0x58) = a;
}

// FUNCTION: GAME 0x3497F8
void func_003497F8(int a)
{
    *(int *)(func_003452B0() + 0x188C) = a;
}

// FUNCTION: GAME 0x349D78
int func_00349D78(void)
{
    func_003B9D80();
    func_00324AC8();
    return 0;
}

// FUNCTION: GAME 0x34A7F0
int func_0034A7F0(char *a)
{
    return func_00329F98(**(int **)(a + 0x2004)) == 3;
}

// FUNCTION: GAME 0x349F80
void func_00349F80(int **a, int b, int c)
{
    ((void (*)(int **, int, int, int))(*a)[6])(a, 0, b, c);
}

// FUNCTION: GAME 0x34BFC8
void func_0034BFC8(int *a)
{
    int i = 2;
    do {
        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
        a[3] = 0;
        a += 4;
    } while (--i >= 0);
}

// FUNCTION: GAME 0x34CA00
void func_0034CA00(char *a, int b, int c)
{
    if (b != 8) { char *q = a + b * 0x74; *(int *)(q + 0x1318) = c; }
}

// FUNCTION: GAME 0x34CA68
void func_0034CA68(char *a, int b, int c)
{
    if (b != 8) { char *q = a + b * 0x74; *(int *)(q + 0x131C) = c; }
}

// FUNCTION: GAME 0x3493D8
void func_003493D8(void)
{
    char *p = func_003452B0();
    void (*f)(int) = *(void (**)(int))(p + 0x40);
    int x = *(int *)(p + 0x44);
    if (f) f(x);
}

// FUNCTION: GAME 0x349408
void func_00349408(void)
{
    char *p = func_003452B0();
    void (*f)(int) = *(void (**)(int))(p + 0x48);
    int x = *(int *)(p + 0x4C);
    if (f) f(x);
}
