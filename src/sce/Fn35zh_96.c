// COMPILER: ee-gcc2.96
extern int func_003AFCE0();
extern int func_003AFCC0();
extern int func_003554E8();
extern int func_003509E8();
extern int func_00350A50();
extern int func_00356358();
extern int func_00355C08();
extern int func_0035C380();
extern int func_0035A1C8();
extern int func_0035BC50();
extern int func_0035AB98();
extern int func_00366918();

// FUNCTION: GAME 0x350988
int func_00350988(int a)
{
    if (func_003554E8(a))
        return 1;
    if (func_003509E8(a) && func_00350A50(a))
        return 1;
    return 0;
}

// FUNCTION: GAME 0x353500
int func_00353500(char *a, unsigned k)
{
    int *p = (int *)(a + 0xA0C);
    int v;
    switch (k) {
    case 1: v = p[8 / 4]; break;
    case 2: v = p[0xC / 4]; break;
    case 3: v = p[0x10 / 4]; break;
    default: return 1;
    }
    return v == 0;
}

// FUNCTION: GAME 0x3562F8
int func_003562F8(int *a)
{
    func_003AFCE0(a[0x40 / 4]);
    a[0x14 / 4] = (a[0x14 / 4] + 0x803) / 0x800 * 0x800;
    return func_003AFCC0(a[0x40 / 4]);
}

// FUNCTION: GAME 0x356928
int func_00356928(int *a, int b)
{
    if (!func_00356358(a, b))
        return b;
    return func_00355C08(a[0x1FC0 / 4] + 0x1198, b);
}

// FUNCTION: GAME 0x359A30
int func_00359A30(int a, int *b, int *out)
{
    int v;
    if (func_0035C380(a, 2)) {
        v = func_0035A1C8(a, 5);
        if (v == 1) {
            *out = v;
            return *b == 0;
        }
    }
    *out = 0;
    return 0;
}

// FUNCTION: GAME 0x35A0A0
int func_0035A0A0(int a, int b, int c)
{
    if (b == 6 && c == 1 && !func_0035C380(a, 3))
        return 0;
    if (b == 5 && c == 1 && !func_0035C380(a, 2))
        return 0;
    return 1;
}

// FUNCTION: GAME 0x35B9B0
int func_0035B9B0(char *a)
{
    int b[2];
    int *q = (int *)(a + 0xD30);
    int s1 = q[0x27C / 4];
    int s0 = q[0x280 / 4];
    if (*(int *)(a + 0x950) == 0)
        return 1;
    if (s1 == -5)
        return 0;
    func_0035AB98(a, b, b + 1);
    return func_00366918(s1 + s0 * 2000 / 0xEA24, s0, b[0], b[1]) != 0;
}

typedef struct { char c[0x38]; int w; } S3C;

// FUNCTION: GAME 0x35BBA0
int func_0035BBA0(S3C *d, S3C *s)
{
    *d = *s;
    return func_0035BC50(s, 0);
}

// FUNCTION: GAME 0x3509E8
extern int func_00355508();
int func_003509E8(int *a)
{
    int s = a[0xA68 / 4];
    int m = a[0x2C / 4];
    int r;
    if (s == -1)
        s = m;
    if (m < s)
        s = m;
    r = func_00355508(a);
    if (a[0x58 / 4] == 2)
        r += a[0x968 / 4];
    if (r < s) return 0;
    return 1;
}

// FUNCTION: GAME 0x355818
extern int func_003B63A0();
extern int func_003B63F0();
int func_00355818(int a)
{
    func_003B63A0();
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 | 0x10000;
    *(volatile int *)0x1000B000 = a;
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 & 0xFFFEFFFF;
    return func_003B63F0();
}

// FUNCTION: GAME 0x355880
int func_00355880(int a)
{
    func_003B63A0();
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 | 0x10000;
    *(volatile int *)0x1000B400 = a;
    *(volatile int *)0x1000F590 = *(volatile int *)0x1000F520 & 0xFFFEFFFF;
    return func_003B63F0();
}
