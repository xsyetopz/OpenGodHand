// COMPILER: ee-gcc2.96
extern char D_00454458[], D_00454960[], D_00455130[], D_004551B8[], D_004551D0[];
extern int D_003D8484;
extern void (*D_003D8404)(int);
extern int D_003D8408, D_003D8480, D_003EADB8, D_003EADBC;
extern void (*D_003E9D30)(void);
extern char D_00456900[], D_00454D68[], D_00454FA0[], D_00454098[], D_003EADC0[];
extern void *memset(void *, int, unsigned);
extern int memcmp(const void *, const void *, unsigned);
extern unsigned strlen(const char *);
extern void scePrintf(const char *);
extern void func_003356B0(), func_00335D40();
void func_00332808(int *, char *);
void func_00334008(int *, char *);
void func_00336330(int *, char *);
extern void func_0033B6A0(), func_0033B6D0();

// FUNCTION: GAME 0x332E68
int func_00332E68(int *p)
{
    if (p == 0) {
        func_00332808((int *)p, D_00454458);
        return 0;
    }
    return p[3];
}

// FUNCTION: GAME 0x333130
int func_00333130(char *p)
{
    if (p == 0) {
        func_00332808((int *)p, D_00454458);
        return 0;
    }
    return p[2];
}

// FUNCTION: GAME 0x3347D0
int func_003347D0(int *p)
{
    if (p == 0) {
        func_00334008((int *)p, D_00454960);
        return 0;
    }
    return p[7];
}

// FUNCTION: GAME 0x334A90
int func_00334A90(char *p)
{
    if (p == 0) {
        func_00334008((int *)p, D_00454960);
        return 0;
    }
    return p[2];
}

// FUNCTION: GAME 0x3367C0
int func_003367C0(int *p)
{
    if (p == 0) {
        func_00336330((int *)p, D_00455130);
        return 0;
    }
    return p[4];
}

// FUNCTION: GAME 0x3369D0
int func_003369D0(char *p)
{
    if (p == 0) {
        func_00336330((int *)p, D_004551B8);
        return 0;
    }
    return p[1];
}

// FUNCTION: GAME 0x336A08
int func_00336A08(int *p)
{
    if (p == 0) {
        func_00336330((int *)p, D_004551D0);
        return 0;
    }
    return p[1];
}

// FUNCTION: GAME 0x33FA70
int func_0033FA70(int *p, int a, int b, int c, int d)
{
    if (p[3] == 0) {
        p[5] = 1;
        p[6] = a;
        p[7] = b;
        p[8] = c;
        p[9] = d;
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x33FAA0
int func_0033FAA0(int *p, int a, int b, int c, int d)
{
    if (p[3] == 0) {
        p[5] = 2;
        p[6] = a;
        p[7] = b;
        p[8] = c;
        p[9] = d;
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x33FAD0
int func_0033FAD0(int *p, int a, int b, int c, int d)
{
    if (p[3] == 0) {
        p[5] = 1;
        p[6] = a;
        p[7] = b;
        p[8] = c;
        p[9] = d;
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x331D40
void func_00331D40(void)
{
    if (D_003D8484 == 1)
        func_0033B6A0();
}

// FUNCTION: GAME 0x331D78
void func_00331D78(void)
{
    if (D_003D8484 == 1)
        func_0033B6D0();
}

// FUNCTION: GAME 0x335610
void func_00335610(int a, int b)
{
    func_003356B0(a, b, 0, 0, 0xFFFFF);
}

// FUNCTION: GAME 0x33C4C0
void func_0033C4C0(void)
{
    D_003E9D30();
}

// FUNCTION: GAME 0x33DD50
int func_0033DD50(void *a)
{
    return memcmp(a, D_00456900, 4) == 0;
}

// FUNCTION: GAME 0x3302B0
void func_003302B0(void)
{
    if (D_003D8404)
        D_003D8404(D_003D8408);
}

// FUNCTION: GAME 0x335B40
int func_00335B40(int *p)
{
    if (p == 0) {
        func_00335D40(D_00454D68);
        return -1;
    }
    return p[9];
}

// FUNCTION: GAME 0x335CA8
void func_00335CA8(char *p, int b)
{
    if (p == 0) {
        func_00335D40(D_00454FA0);
        return;
    }
    p[3] = b;
}

// FUNCTION: GAME 0x33C7C0
void func_0033C7C0(char *p)
{
    *(int *)(p + 0xCC) = 0;
    *(short *)(p + 0xE0) = 0;
    *(short *)(p + 0xE2) = -0x80;
    *(short *)(p + 0xE4) = -0x80;
    memset(p + 0xD0, 0, 0x10);
}

// FUNCTION: GAME 0x33F0B8
void func_0033F0B8(void)
{
    memset(D_003EADC0, 0, 0x100);
    D_003EADB8 = 0;
    D_003EADBC = 0;
}

// FUNCTION: GAME 0x33F0F0
void func_0033F0F0(void)
{
    memset(D_003EADC0, 0, 0x100);
    D_003EADB8 = 0;
    D_003EADBC = 0;
}

// FUNCTION: GAME 0x33FA30
void func_0033FA30(int *p)
{
    if (p) {
        *p = 0;
        memset(p, 0, 0x3C);
    }
}

// FUNCTION: GAME 0x331C98
void func_00331C98(int a)
{
    D_003D8480 = a;
    if (a == 1)
        scePrintf(D_00454098);
}

// FUNCTION: GAME 0x333B00
int func_00333B00(char *s)
{
    if (strlen(s) != 0x11)
        return 0;
    return s[8] == '.';
}
extern int D_00758400, D_003E8DCC, D_003E9944;
extern char D_003E9D60[];
extern void func_00338990(), func_003389F8(), func_00338AC0(), func_00338A10(), func_00338B40(), func_003389C8();
extern void func_003394D0(), func_00339550(), func_0033A0C0(), func_0033A140(), func_00332670();
extern void func_0033F9D8(), func_0033FA10(), func_0033F9B0(), func_0033FA00(), func_0033FB48();
extern void func_003325F8(), func_0033BDD8(), func_0033F888(), func_0033C520(), func_0033C708();

// FUNCTION: GAME 0x338A90
void func_00338A90(void)
{
    func_00338990();
    func_003389F8();
    func_00338AC0();
    func_00338A10();
}

// FUNCTION: GAME 0x338B10
void func_00338B10(void)
{
    func_003389F8();
    func_00338B40();
    func_00338A10();
    func_003389C8();
}

// FUNCTION: GAME 0x3394A0
void func_003394A0(void)
{
    func_00338990();
    func_003389F8();
    func_003394D0();
    func_00338A10();
}

// FUNCTION: GAME 0x339520
void func_00339520(void)
{
    func_003389F8();
    func_00339550();
    func_00338A10();
    func_003389C8();
}

// FUNCTION: GAME 0x33A090
void func_0033A090(void)
{
    func_00338990();
    func_003389F8();
    func_0033A0C0();
    func_00338A10();
}

// FUNCTION: GAME 0x33A110
void func_0033A110(void)
{
    func_003389F8();
    func_0033A140();
    func_00338A10();
    func_003389C8();
}
