// COMPILER: ee-gcc2.96
extern int func_0035D110(), func_00360000(), func_0035A1C8(), func_0035D2E0(), func_0035D430(), func_0035D3A8(), func_0035E9E8();
extern unsigned char *func_0035E0F0();
extern int func_0035E9A8(), func_0035E8F8();
extern void func_0035FD98(int *, int, int);
extern long func_0031DE10(), func_003B7FE0();

// FUNCTION: GAME 0x35D0E0
int func_0035D0E0(int a)
{
    int *p = (int *)(a + 0x2150);
    p[2] = a + 0x3678;
    func_0035D110(a, a + 0x3678, p[4]);
    return 0;
}

// FUNCTION: GAME 0x35FD20
void func_0035FD20(int *a, int *b, int *c)
{
    a += 5;
    if (a[0] != 1) {
        *b = 0;
        *c = 0;
    } else {
        int t = a[1];
        *c = a[2];
        *b = t;
    }
}

// FUNCTION: GAME 0x35EA30
void func_0035EA30(int x, int *b, int c, int d, int e, int f)
{
    b[0x11] = e;
    b[0x12] = f;
    func_0035FD98(b, c, d);
}

// FUNCTION: GAME 0x35FFD8
void func_0035FFD8(int *a, int b, int c)
{
    int *p = a + 2;
    p[0] = 1;
    p[1] = b;
    p[2] = c;
    func_00360000(a);
}

// FUNCTION: GAME 0x35C548
void func_0035C548(long *a, long *b)
{
    if (*(int *)((char *)a + 0xC) == 0) {
        long v = func_0031DE10(a[0x26], b[0]);
        a[0x25] += func_003B7FE0(v, b[1]);
    }
}

// FUNCTION: GAME 0x35D288
int func_0035D288(int a)
{
    int r;
    if (!func_0035A1C8(a, 5))
        return 0;
    func_0035D2E0(a);
    r = func_0035D430(a);
    func_0035D3A8(a);
    return r;
}

// FUNCTION: GAME 0x35E148
int func_0035E148(int a, unsigned char b, int *o)
{
    unsigned char *s;
    *o = -1;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (func_0035E9E8(b) != 0xC0)
        return 0;
    *o = s[0x19];
    return 1;
}

// FUNCTION: GAME 0x35E238
int func_0035E238(int a, unsigned char b, int *o)
{
    unsigned char *s;
    *o = 0;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (func_0035E9E8(b) != 0xC0)
        return 0;
    *o = s[0x1B];
    return 1;
}

// FUNCTION: GAME 0x35E2A8
int func_0035E2A8(int a, unsigned char b, int *o)
{
    unsigned char *s;
    *o = 0;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (func_0035E9E8(b) != 0xC0)
        return 0;
    *o = *(int *)(s + 0x1C);
    return 1;
}

// FUNCTION: GAME 0x35E318
int func_0035E318(int a, unsigned char b, int *o)
{
    unsigned char *s;
    *o = -1;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (func_0035E9E8(b) != 0xE0)
        return 0;
    *o = s[0x19];
    return 1;
}

// FUNCTION: GAME 0x35E4B0
int func_0035E4B0(int a, unsigned char b, int *o)
{
    unsigned char *s;
    *o = 0;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (func_0035E9E8(b) != 0xE0)
        return 0;
    *o = func_0035E8F8(s[0x1F]);
    return 1;
}

// FUNCTION: GAME 0x35E520
int func_0035E520(int a, unsigned char b, int *o)
{
    unsigned char *s;
    *o = -1;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (!func_0035E9A8(b, s))
        return 0;
    *o = s[0x21];
    return 1;
}

// FUNCTION: GAME 0x35E590
int func_0035E590(int a, unsigned char b, int *o)
{
    unsigned char *s;
    *o = -1;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (!func_0035E9A8(b, s))
        return 0;
    *o = s[0x22];
    return 1;
}

// FUNCTION: GAME 0x35E600
int func_0035E600(int a, unsigned char b, int *o)
{
    unsigned char *s;
    *o = 0;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (!func_0035E9A8(b, s))
        return 0;
    *o = s[0x23] & 1;
    return 1;
}

// FUNCTION: GAME 0x35E6E8
int func_0035E6E8(int a, unsigned char b, int *o)
{
    unsigned char *s;
    *o = 0;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (!func_0035E9A8(b, s))
        return 0;
    *o = s[0x24];
    return 1;
}

// FUNCTION: GAME 0x35E758
int func_0035E758(int a, unsigned char b, int *o)
{
    unsigned char *s;
    int t;
    *o = -1;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (!func_0035E9A8(b, s))
        return 0;
    t = s[0x25];
    *o = t;
    if (t >= 0x40)
        *o = -1;
    return 1;
}

// FUNCTION: GAME 0x35E7E0
int func_0035E7E0(int a, unsigned char b, int *o)
{
    unsigned char *s;
    int t;
    *o = -1;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (!func_0035E9A8(b, s))
        return 0;
    t = s[0x26];
    *o = t;
    if (t >= 0x40)
        *o = -1;
    return 1;
}

// FUNCTION: GAME 0x35E868
int func_0035E868(int *a, unsigned char b, int *o)
{
    unsigned char *s;
    *o = -1;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (!func_0035E9A8(b, s))
        return 0;
    if (a[3] < 0xD2)
        return 0;
    *o = s[0x27];
    return 1;
}
