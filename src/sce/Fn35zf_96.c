// COMPILER: ee-gcc2.96
struct u8 { char c[8]; };
extern int func_0034DEC8();
extern int func_0034DD70();
extern int func_0035B0D8();
extern int func_0035A000();
extern int func_00359218();
extern int func_0035C2D0();
extern int func_0035BA58();
extern int (*D_003EE304)();
extern int D_00459920[];
extern void (*D_00459948[])();
extern int D_003EE2C4[];
extern int func_0035A6A8();
extern int D_003EE270[];
extern int func_00357258();
extern int D_00766C70;
extern struct u8 D_00766C78;
extern int func_00366E18();

// FUNCTION: GAME 0x35B5F8
int func_0035B5F8(char *a, int *b)
{
    int r;
    int v;
    *b = -1;
    r = func_0034DEC8(a);
    if (r)
        return func_0034DD70(0, 0xFF00011B);
    v = *(int *)(a + 0x920);
    if (v)
        *b = D_00459920[v];
    return r;
}

// FUNCTION: GAME 0x35AEE0
int func_0035AEE0(int a, int b)
{
    if (func_0034DEC8(a))
        return func_0034DD70(0, 0xFF000123, 4);
    func_0035B0D8(a, b);
    if (b)
        func_0035A000(a, 0xF, 4);
    return 0;
}

// FUNCTION: GAME 0x359080
int func_00359080(char *a, int *b, int *c)
{
    *c = 0;
    *b = -1;
    if (func_0034DEC8(a)) {
        func_0034DD70(0, 0xFF00013A);
        return 0;
    }
    if (func_00359218(a, 2))
        return 0;
    func_0035C2D0(a, 6, 0xB, c, b);
    if (D_003EE304)
        D_003EE304(a, *c);
    if (*c == 0)
        return 0;
    if (*(int *)(a + 0x968) == 0)
        *(long *)(a + 0x3780) = func_0035BA58();
    *(int *)(a + 0x968) += 1;
    return 1;
}

// FUNCTION: GAME 0x359F78
void func_00359F78(int a, int b)
{
    int i;
    int *p = D_003EE2C4;
    for (i = 7; i >= 0; i--) {
        int s = *p++;
        if (!func_0034DEC8(s))
            func_0035A000(s, a, b);
    }
}

// FUNCTION: GAME 0x35A620
void func_0035A620()
{
    int i;
    int *g = D_003EE270;
    int *p = g + 0x15;
    (*g)++;
    for (i = 7; i >= 0; i--) {
        int s = *p++;
        if (func_0034DEC8(s) != -1)
            func_0035A6A8(s);
    }
}

// FUNCTION: GAME 0x357280
int func_00357280()
{
    int i;
    int *p = D_003EE2C4;
    for (i = 0; i < 8; i++) {
        int s = *p++;
        if (!func_0034DEC8(s) && !func_00357258(s))
            return 0;
    }
    return 1;
}

// FUNCTION: GAME 0x3565E0
int func_003565E0(int a, struct u8 *b, char *c)
{
    D_00766C70 = 1;
    D_00766C78 = *b;
    *(struct u8 *)(*(char **)(c + 0x1FC0) + 0x11F8) = *b;
    func_0034DD70(c, 0xFF000F40);
    return 1;
}

// FUNCTION: GAME 0x350048
int func_00350048(int a, int *b, char *c)
{
    int x;
    int y;
    char *p = c + 0x30;
    int h = *b;
    int r1;
    int r2;
    r1 = func_00366E18(h, p, *(int *)(p + 0x160), &x, &y);
    r2 = func_00366E18(h, c + 0xE0, *(int *)(p + 0x164), &x, &y);
    if (r1 || r2)
        return func_0034DD70(a, 0xFF000D0D);
    return r2;
}

// FUNCTION: GAME 0x35B0E8
void func_0035B0E8(int *a, int *b, int *c)
{
    int i = a[0];
    int j = a[1];
    int o = D_00459920[i];
    void (*fn)() = D_00459948[i * 2 + j];
    if (!fn) {
        func_0034DD70(0, 0xFF000221, b, c);
        *b = 0;
        *c = 1;
        return;
    }
    fn(o, a);
}
