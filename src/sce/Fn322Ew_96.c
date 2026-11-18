// COMPILER: ee-gcc2.96
int func_00333CE0();
int func_0033FCB0();
void func_0032A9F0();
int func_0032F4C8();
void func_00329D38();
extern char D_00452B98[];
extern char D_00452BC0[];

// FUNCTION: GAME 0x3291B8
int func_003291B8(int *a)
{
    int *p = a;
    int r = 0;
    if (p != 0) {
        r = func_00333CE0(p[0], p[2], p[3], p[1]);
    } else {
        func_00333CE0(0, 0, 0, 0);
    }
    return r;
}

// FUNCTION: GAME 0x32DD18
int func_0032DD18(char *a, int b)
{
    if (a == 0) {
        func_0033FCB0(D_00452B98);
        return 0;
    }
    if (b > 0x20) {
        func_0033FCB0(D_00452BC0);
        return 0;
    }
    return *(int *)((int)a + (b << 2) + 0xC);
}

// FUNCTION: GAME 0x32ED48
void func_0032ED48(char *a, int b, int c)
{
    func_0032A9F0(*(int *)((int)a + (b << 2) + 0xC), c);
}

// FUNCTION: GAME 0x32F4F8
void func_0032F4F8(char *a, int b, int *c, int *d)
{
    char *p = a + (b << 4);
    b = (int)p;
    if (c) *c = *(int *)(b + 0x2B4);
    if (d) *d = *(int *)(p + 0x2B8);
}

// FUNCTION: GAME 0x32EFE8
void func_0032EFE8(char *a)
{
    int i = 0;
    int n = func_0032F4C8(*(int *)(a + 4));
    int *p;
    int *q;
    if (n > 0) {
        q = (int *)(a + 0x94);
        p = (int *)(a + 0xC);
        do {
            func_00329D38(*p++, *q++);
            i++;
        } while (i < n);
    }
}
