// COMPILER: ee-gcc2.96
extern unsigned char *func_0035E0F0();
extern int func_0035E9E8();
extern int func_0035A1C8(), func_0035B9B0();
extern int func_0035C368(), func_0034CA98(), func_0035D048(), func_0035C350();
extern int func_0035C338(), func_0034CA30(), func_0035D0D0(), func_0035C320();
extern int func_0035D428(), func_00368FC0();
extern int func_0035D360(), func_0036C5F8(), func_00369F20(), func_0036C8D0();

// FUNCTION: GAME 0x35E388
int func_0035E388(int a, unsigned char b, int *o)
{
    unsigned char *s;
    int t;
    *o = 0;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (func_0035E9E8(b) != 0xE0)
        return 0;
    t = *(unsigned short *)(s + 0x1A);
    *o = t == 0xFFFF ? 0 : t;
    return 1;
}

// FUNCTION: GAME 0x35E9A8
int func_0035E9A8(b, s)
    int b;
    unsigned char *s;
{
    unsigned t;
    if (func_0035E9E8(b) != 0xE0)
        return 0;
    t = s[0x20];
    return t < 2 ? t != 0 : 0;
}

// FUNCTION: GAME 0x35CFC8
void func_0035CFC8(int a)
{
    if (func_0035C368(a, 8) == 1)
        return;
    if (func_0034CA98(a, *(int *)(a + 0x2160)) != 1)
        return;
    if (!func_0035D048(a))
        return;
    func_0035C350(a, 8, 1);
}

// FUNCTION: GAME 0x35D050
void func_0035D050(int a)
{
    if (func_0035C338(a, 8) == 1)
        return;
    if (func_0034CA30(a, *(int *)(a + 0x2160)) != 1)
        return;
    if (!func_0035D0D0(a))
        return;
    func_0035C320(a, 8, 1);
}

// FUNCTION: GAME 0x35D3A8
void func_0035D3A8(int a)
{
    if (func_0035C338(a, 6) == 1)
        return;
    if (func_0034CA30(a, *(int *)(a + 0x20D8)) != 1)
        return;
    if (!func_0035D428(a))
        return;
    func_0035C320(a, 6, 1);
}

// FUNCTION: GAME 0x35E968
int func_0035E968(b, s)
    int b;
    unsigned char *s;
{
    unsigned t;
    if (func_0035E9E8(b) != 0xC0)
        return 0;
    t = s[0x20];
    return t < 2 ? t != 0 : 0;
}

// FUNCTION: GAME 0x35E1B8
int func_0035E1B8(int a, unsigned char b, int *o)
{
    unsigned char *s;
    *o = 0;
    s = func_0035E0F0(a, b);
    if (!s)
        return 0;
    if (func_0035E9E8(b) != 0xC0)
        return 0;
    if (s[0x19] != 1)
        return 0;
    *o = s[0x1A];
    return 1;
}

// FUNCTION: GAME 0x35D2E0
void func_0035D2E0(int a)
{
    if (func_0035C368(a, 6) == 1)
        return;
    if (func_0034CA98(a, *(int *)(a + 0x20D8)) != 1)
        return;
    if (!func_0035D360(a))
        return;
    func_0035C350(a, 6, 1);
}
