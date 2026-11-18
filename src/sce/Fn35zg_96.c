// COMPILER: ee-gcc2.96
extern int func_0034DD70();
extern int func_003562F8();
extern int func_0035B5B8();
extern int func_0035B500();
extern int func_0035B568();
extern int func_0035C2D0();
extern int func_0035AE18();
extern int D_003EE278;
extern int func_00366C50();
extern int func_00358678();
extern int func_0035BB40();
extern void (*func_0035A1C8())();
extern int func_00358A48();
extern int func_00358A28();
extern int func_00358AA8();
extern int func_00357FC8();
extern int func_00358090();
extern int func_003580E8();
extern int func_003581E0();
extern int func_0035AB98();
extern int func_00366918();
extern int func_0035A810();

// FUNCTION: GAME 0x350040
void func_00350040()
{
}

// FUNCTION: GAME 0x35A2A8
void func_0035A2A8()
{
}

// FUNCTION: GAME 0x359218
int func_00359218(int *a, int b)
{
    int v = a[0x58 / 4];
    if (!v) {
        a[0x58 / 4] = b;
        return 0;
    }
    if (v == b)
        return 0;
    return func_0034DD70(a, 0xFF000207);
}

// FUNCTION: GAME 0x356988
void func_00356988(char *a, int b)
{
    char *g = *(char **)(a + 0x1FC0);
    int *s = (int *)(g + 0x1128);
    if (s[0x1C / 4] != 1) {
        func_003562F8(g + 0x1198);
        s[0x1C / 4] = 1;
        s[0x20 / 4] = b;
    }
}

// FUNCTION: GAME 0x35B4A0
void func_0035B4A0(int a, unsigned b)
{
    int buf[2];
    if (b < 2)
        return;
    if (b != 2)
        return;
    func_0035B5B8(a, buf, buf + 1);
    func_0035B500(a, buf[0], buf[1]);
    func_0035B568(a, buf[0], buf[1]);
}

// FUNCTION: GAME 0x358A48
int func_00358A48(int *a)
{
    if (a[0x48 / 4] == 4) {
        int r = func_0035C2D0(a, 7, 7, 0, 0);
        if (r)
            return r;
    }
    a[0x48 / 4] = 1;
    a[0x4C / 4] = 1;
    return 0;
}

// FUNCTION: GAME 0x35ACA0
int func_0035ACA0(char *a, int *b, int *c)
{
    int r = func_0035AE18(a);
    a += 0xD30;
    if (r) {
        *b = *(int *)(a + 0x2A8);
        *c = D_003EE278;
        return 0;
    }
    return r;
}

// FUNCTION: GAME 0x358600
void func_00358600(int *a)
{
    func_00366C50(a, 0, 0x2A);
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[6] = 0;
    a[7] = 0;
    a[8] = 0;
    a[9] = 0;
    a[10] = 0;
    a[11] = 0;
    a[12] = 0;
    func_00358678(a + 0x38 / 4);
    func_00358678(a + 0x50 / 4);
    func_00358678(a + 0x68 / 4);
    func_00358678(a + 0x80 / 4);
}

// FUNCTION: GAME 0x358688
void func_00358688(char *a)
{
    int i;
    char *p;
    func_00366C50(a, 0, 0x38);
    p = a;
    for (i = 4; i >= 0; i--) {
        func_0035BB40(p);
        p += 0x20;
    }
    func_0035BB40(a + 0xA0);
    *(long *)(a + 0xC0) = 0;
    *(long *)(a + 0xC8) = 0;
    *(long *)(a + 0xD0) = 0;
    *(int *)(a + 0xD8) = 0;
    *(int *)(a + 0xDC) = 0;
}

// FUNCTION: GAME 0x358700
void func_00358700(int a, int b, int c)
{
    int *s = (int *)(a + 0x950);
    void (*fn)();
    *s = *s + b;
    fn = func_0035A1C8(a, 0x24);
    if (fn)
        fn(a, c, s);
}

// FUNCTION: GAME 0x358768
void func_00358768(int a, int b, int c)
{
    int *s = (int *)(a + 0x950);
    void (*fn)();
    s[1] = s[1] + b;
    fn = func_0035A1C8(a, 0x25);
    if (fn)
        fn(a, c, s);
}

// FUNCTION: GAME 0x3589C0
int func_003589C0(int *a)
{
    int r;
    if (a[0x48 / 4] == 1)
        return 0;
    r = func_00358A48(a);
    if (r)
        return r;
    a[0x4C / 4] = 0;
    a[0x48 / 4] = 0;
    func_00358A28(1);
    r = func_00358AA8(a);
    func_00358A28(0);
    return r;
}

// FUNCTION: GAME 0x3582C0
int func_003582C0(int *a)
{
    if (!a[1])
        return func_0034DD70(0, 0xFF000204);
    if ((unsigned)a[0x40 / 4] < 0x37D0)
        return func_0034DD70(0, 0xFF000205);
    return 0;
}

// FUNCTION: GAME 0x357988
int func_00357988(int a)
{
    int b = a;
    int *x = (int *)(b + 0xA0C);
    int *y;
    b += 0xD30;
    y = (int *)b;
    if (x[0x38 / 4] == 0)
        return 1;
    if (x[0x14 / 4] == 0)
        return 1;
    if (y[0x2B0 / 4] != 0)
        return 1;
    if (y[0x2CC / 4] >= x[0xB4 / 4])
        return 1;
    return func_00357FC8(a) != 0;
}

// FUNCTION: GAME 0x357E58
int func_00357E58(char *a)
{
    int *p = (int *)(a + *(int *)(a + 0x200C) * 0x74 + 0x1320);
    int *o = (int *)p[1];
    int r = ((int (*)())(*(int **)o)[0x24 / 4])(o, 1);
    if (r < p[3] * 80 / 100)
        return 0;
    return 1;
}

// FUNCTION: GAME 0x357ED8
int func_00357ED8(char *a)
{
    if (func_00357F58(a) || func_00357FC8(a) || func_00358090(a) || func_003580E8(a) || *(int *)(a + 0x60))
        return func_003581E0(a);
    return 0;
}

// FUNCTION: GAME 0x357F58
int func_00357F58(char *a)
{
    int *x = (int *)(a + 0xA0C);
    int s0 = x[0x50 / 4];
    int s1 = x[0x54 / 4];
    int buf[2];
    if (s0 == -4)
        return 0;
    func_0035AB98(a, buf, buf + 1);
    if (buf[0] < 0)
        return 0;
    return func_00366918(buf[0], buf[1], s0, s1) == 0;
}

// FUNCTION: GAME 0x35A8E8
int func_0035A8E8(char *a)
{
    int s;
    int b[2];
    if (!func_0035A1C8(a, 6))
        return 0;
    s = (int)func_0035A1C8(a, 0x33);
    if (s) {
        func_0035A810(a, a + 0xD30, b, b + 1);
        return s < b[0] / b[1];
    }
    return 0;
}
