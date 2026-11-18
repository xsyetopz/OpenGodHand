// COMPILER: ee-gcc2.96
int func_0034DD70();
int func_0034DEC8(int);
void func_0035A000(int, int, int);
int func_0034D450(int);
void func_0034D318(char *, int);
void func_0034D4A0(char *);
void func_0034DAC0(int);
int func_0035D610();
void func_0034D508(int, char *);
void func_0035D6D8(int);
int func_0035D828(int, int *);
void func_0034C158(char *, int *, char *, int);
int func_0035C2D0(char *, int, int, int, int);
int func_0035D918(int, int, int *);

// FUNCTION: GAME 0x34CCE8
int func_0034CCE8(int a)
{
    if (func_0034DEC8(a)) return func_0034DD70(0, 0xFF000161, 1);
    func_0035A000(a, 0x31, 1);
    return 0;
}

// FUNCTION: GAME 0x34D3E8
void func_0034D3E8(char *a)
{
    char *s = a + 0x78;
    int r = func_0034D450((int)a);
    if (r) {
        func_0034D318(s, r);
        func_0034D4A0(s);
        func_0034DAC0((int)a);
    }
}

// FUNCTION: GAME 0x34D4A0
void func_0034D4A0(char *a)
{
    int s = func_0035D610(a + 0x94, *(int *)(a + 0x90));
    if (s) {
        func_0034D508(s, a);
        func_0035D6D8(s);
    }
}

// FUNCTION: GAME 0x34D1B8
int func_0034D1B8(void)
{
    int x;
    int s = func_0035D610();
    if (!s) return 0;
    if (!func_0035D828(s, &x)) x = 0;
    func_0035D6D8(s);
    return x;
}

// FUNCTION: GAME 0x34C990
int func_0034C990(char *a, int b, int c, int d)
{
    char *p = a + 0x1310;
    int r = 0;
    p += b * 0x74;
    if (*(int *)(p + 4) == 0) r = func_0035C2D0(a, *(int *)(p + 0x4C), 0xC, c, d);
    *(int *)(a + 0x44) = 1;
    return r;
}

// FUNCTION: GAME 0x34D7A8
int func_0034D7A8(int a, int b, int c)
{
    int x;
    for (; b <= c; b++)
        if (func_0035D918(a, b & 0xFF, &x) && x) return b;
    return 0;
}
