// More small functions in the ProDG game-code island 0x380000-0x387430.
extern "C" {
void func_00380D68(char *, char *);
void func_00381CE0(char *, char *);
void func_00380F10(char *, char *, char *);
void func_00381DC0(char *, char *, char *);
void func_00380E88(char *, char *, char *);
void func_00381D38(char *, char *, char *);
void func_00380E10(char *);
void func_00383438(char *, char *);
void func_0031C900(int);
void func_002E0DE8(int, int, int, const char *);
extern char D_0045C3E0[];
void func_00384C60(char *);
void func_00385A20(char *);
}

// FUNCTION: GAME 0x382F00
extern "C" void func_00382F00(char *a, char *b)
{
    if (b[3] & 1)
        func_00381CE0(a, b + 0xA4);
    else
        func_00380D68(a, b + 0x34);
}

// FUNCTION: GAME 0x3833F8
extern "C" void func_003833F8(char *a, char *b)
{
    if (b[3] & 1)
        func_00381DC0(a, b + 0xA4, b);
    else
        func_00380F10(a, b + 0x34, b);
}

// FUNCTION: GAME 0x383438
extern "C" void func_00383438(char *a, char *b)
{
    if (b[3] & 1)
        func_00381D38(a, b + 0xA4, b);
    else
        func_00380E88(a, b + 0x34, b);
}

// FUNCTION: GAME 0x380638
extern "C" void func_00380638(int *p)
{
    int a = p[2];
    int b = p[3];
    short d = b - a + 7;
    func_002E0DE8(3, d, 0xC, D_0045C3E0);
}

// FUNCTION: GAME 0x384C60
extern "C" void func_00384C60(char *o)
{
    char *s = o + 0x370;
    func_00383438(o, s);
    if (*(int *)(s + 0xFC)) {
        func_0031C900(*(int *)(s + 0xFC));
        *(int *)(s + 0xFC) = 0;
    }
}

// FUNCTION: GAME 0x385A20
extern "C" void func_00385A20(char *o)
{
    char *s = o + 0x470;
    func_00380E88(o, o + 0x484, s);
    if (*(int *)(s + 0x84)) {
        func_0031C900(*(int *)(s + 0x84));
        *(int *)(s + 0x84) = 0;
    }
}

// FUNCTION: GAME 0x3806D8
extern "C" void func_003806D8(char *o)
{
    func_00380E10(o);
    func_00381D38(o, o + 0x348, o + 0x318);
    func_00384C60(o);
    func_00385A20(o);
}
