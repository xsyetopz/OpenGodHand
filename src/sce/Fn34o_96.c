// COMPILER: ee-gcc2.96
int func_0034DD70();
int func_0034DEC8();
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

int func_0035A1C8(char *, int);
int func_00366D28(int, int, int);
void func_0034FA28(char *, int *, int *);
void func_0034F718(char *);
void func_0034FAD8(char *);
void func_0034F930(char *);
void func_0034FB70(char *);
void func_0034FC20(char *);
void func_0034DDE0(char *);
extern char D_003EE25C[];
int func_0034F418(char *);
int func_0034E268(char *);
int func_0034E2C8(char *);
void func_0034F6C0(char *);
int func_0034DEB8();

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

// FUNCTION: GAME 0x34E268
int func_0034E268(char *a)
{
    int x = **(int **)(a + 0x1F7C);
    int y = func_0035A1C8(a, 0x55);
    int z = func_0035A1C8(a, 0x56);
    return func_00366D28(x, y, z);
}

// FUNCTION: GAME 0x34F6C0
void func_0034F6C0(char *a)
{
    int b[2];
    func_0034FA28(a, b, b + 1);
    func_0034F718(a);
    func_0034FAD8(a);
    func_0034F930(a);
    func_0034FB70(a);
    func_0034FC20(a);
}

// FUNCTION: GAME 0x34DD70
int func_0034DD70(char *a, int b)
{
    int r = 0;
    if (b) {
        if (a == 0) {
            func_0034DDE0(D_003EE25C);
        } else {
            func_0034DDE0(a + 0x9F8);
            if (*(int *)(a + 0x48) > 0) *(int *)(a + 0x48) = -*(int *)(a + 0x48);
        }
        r = b;
    }
    return r;
}

// FUNCTION: GAME 0x34E1F0
int func_0034E1F0(char *a)
{
    int r;
    if (func_0034F418(a) == 1) return 0;
    func_0034E268(a);
    r = func_0034E2C8(a);
    if (*(int *)(a + 0x48) == 2) func_0034F6C0(a);
    return r;
}

// FUNCTION: GAME 0x34DE20
int func_0034DE20(char *a, int b, int c)
{
    if (a == 0) {
        func_0034DEB8(D_003EE25C);
    } else {
        if (func_0034DEC8(a)) return func_0034DD70(0, 0xFF000101);
        func_0034DEB8(a + 0x9F8, b, c);
    }
    return 0;
}

// FUNCTION: GAME 0x34FDF0
void func_0034FDF0(int *a)
{
    int *p;
    int i;
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    *(long long *)(a + 4) = 0x7FFFFFFFFFFFFFFFLL;
    *(long long *)(a + 6) = 0x7FFFFFFFFFFFFFFFLL;
    a[8] = 0;
    a[9] = 0x7FFFFFFF;
    a[0xA] = 0x7FFFFFFF;
    a[0xB] = -1;
    a[0xC] = -1;
    a[0xD] = -1;
    a[0xE] = -1;
    a[0xF] = 0;
    i = 0x43;
    p = a + 0x53;
    for (; i >= 0; i--) *p-- = 0;
    a[0x54] = 0;
    a[0x55] = 0;
    a[0x56] = -1;
}
