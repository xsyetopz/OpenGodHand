// COMPILER: ee-gcc2.96
// SCE library code (sd s0 prologues), built with ee-gcc 2.96 (C) at -O2 -G0.

void func_003403C8(char *);
void func_003404B0(char *);
void func_003403E0();
void func_00340520(char *);
void func_003389F8(char *);
void func_00338A10();
void func_003B9AF8(char *);
void func_003298C0(char *);

// FUNCTION: GAME 0x340480
void func_00340480(char *p)
{
    func_003403C8(p);
    func_003404B0(p);
    func_003403E0();
}

// FUNCTION: GAME 0x3404F0
void func_003404F0(char *p)
{
    func_003403C8(p);
    func_00340520(p);
    func_003403E0();
}

// FUNCTION: GAME 0x3402E0
void func_003402E0(char *p)
{
    func_003389F8(p);
    *p = 0;
    func_00338A10();
}

// FUNCTION: GAME 0x342A08
void func_00342A08(char *p)
{
    func_003B9AF8(p);
    func_003298C0(p);
}

void func_0033B658(char *);
void func_0033B670();
void func_0033B790(char *);
void func_003428A0(char *, int, int, int);
void func_00342910(char *);
void func_00348870(char *);
void func_00324950(char *);

// FUNCTION: GAME 0x3403C8
void func_003403C8(char *p)
{
    func_0033B658(p);
}

// FUNCTION: GAME 0x3403E0
void func_003403E0()
{
    func_0033B670();
}

// FUNCTION: GAME 0x340AE8
void func_00340AE8(char *p)
{
    func_0033B790(p);
}

// FUNCTION: GAME 0x342870
void func_00342870(char *p, int b, int c)
{
    func_003428A0(p, b, c, 1);
}

// FUNCTION: GAME 0x342888
void func_00342888(char *p)
{
    func_00342910(p);
}

// FUNCTION: GAME 0x342910
void func_00342910(char *p)
{
    func_00348870(p + 0x284);
}

// FUNCTION: GAME 0x342928
void func_00342928(char *p)
{
    func_00324950(p);
}

extern int D_00760D84;
extern int D_00760D88;
extern int D_00760D8C;
void *memset(void *, int, unsigned int);
char *func_003452B0();
void func_0034DC98();
void func_00349328();
void func_00346660(int);
void func_0033B938(int, int);

// FUNCTION: GAME 0x3406B0
void func_003406B0(void *p)
{
    memset(p, 0, 0x2C);
}

// FUNCTION: GAME 0x345598
int func_00345598()
{
    return *(int *)(func_003452B0() + 0x38);
}

// FUNCTION: GAME 0x3455B8
int func_003455B8()
{
    return *(int *)(func_003452B0() + 0x3C);
}

// FUNCTION: GAME 0x3492E8
int func_003492E8()
{
    return *(int *)(func_003452B0() + 0x10);
}

// FUNCTION: GAME 0x349778
int func_00349778()
{
    return *(int *)(func_003452B0() + 0x24);
}

// FUNCTION: GAME 0x349820
int func_00349820()
{
    return *(int *)(func_003452B0() + 0x188C);
}

// FUNCTION: GAME 0x345828
int func_00345828()
{
    func_0034DC98();
    return 0;
}

// FUNCTION: GAME 0x349308
int func_00349308()
{
    func_00349328();
    return 0;
}

// FUNCTION: GAME 0x346478
void func_00346478()
{
    func_00346660(8);
    func_00346660(9);
}

// FUNCTION: GAME 0x348A50
void func_00348A50()
{
    func_0033B938(2, D_00760D84);
}

// FUNCTION: GAME 0x348AA8
void func_00348AA8()
{
    func_0033B938(6, D_00760D88);
}

// FUNCTION: GAME 0x348B00
void func_00348B00()
{
    func_0033B938(5, D_00760D8C);
}

extern char D_003EC420[];
extern int D_003EC450;
extern char D_00457E88[];
extern char D_00457EA8[];
extern char D_00458848[];
extern int D_00760D80;
int memcmp(const void *, const void *, unsigned int);
void func_00340438(char *, int);
void func_00340A60(char *, int);
void func_00341D18(char *);
void func_00341B98(char *);
void func_00341A00(char *);
void func_0032AB70(char *, int);
void func_00329D38(char *, int);
int func_003570F8(int);
int func_003588B0(int);
void func_00345750(int);
void func_00348BE0(char *);
void func_00349A68(int);
void func_00347E20(char *, int);
void func_00359EC0(int, int, int);
void func_0033BE80();

// FUNCTION: GAME 0x3403F8
void func_003403F8(char *a, int b)
{
    func_003403C8(a);
    func_00340438(a, b);
    func_003403E0();
}

// FUNCTION: GAME 0x340A20
void func_00340A20(char *a, int b)
{
    func_003403C8(a);
    func_00340A60(a, b);
    func_003403E0();
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3404B0
// diff: bne/ordering: lui a0 hoisted above addiu sp (5 words)
void func_003404B0(char *p)
{
    memcmp(D_003EC420, D_003EC420, 0x168);
    D_003EC450 += 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x341EC0
// diff: bnel vs bne at 0x341ED0 (1 word)
void func_00341EC0(char *p)
{
    short m = *(short *)(p + 0x9C);
    if (m == 2) {
        func_00341D18(p);
        return;
    }
    if (m == 1) {
        func_00341B98(p);
        return;
    }
    func_00341A00(p);
}
#endif

// FUNCTION: GAME 0x342A30
void func_00342A30(char *a, int b)
{
    func_0032AB70(a, 0x14);
    func_00329D38(a, b);
}

// FUNCTION: GAME 0x345AF8
int func_00345AF8(char *p)
{
    int r = func_003570F8(*(int *)(p + 0x3C));
    if (r) {
        func_00345750(-0x137);
        func_00348BE0(D_00457E88);
        return -0x137;
    }
    return r;
}

// FUNCTION: GAME 0x345B38
int func_00345B38(char *p)
{
    int r = func_003588B0(*(int *)(p + 0x3C));
    if (r) {
        func_00345750(-0x133);
        func_00348BE0(D_00457EA8);
        return -0x133;
    }
    return r;
}

// FUNCTION: GAME 0x3467E8
void func_003467E8(char *p, int b)
{
    func_00349A68(*(int *)(p + 0x40));
    func_00347E20(p, b);
}

// FUNCTION: GAME 0x346B78
void func_00346B78(int a)
{
    if ((unsigned int)(a + 1) >= 3)
        func_00348BE0(D_00458848);
    else
        func_00359EC0(0, 0x3D, a);
}

// FUNCTION: GAME 0x3489B0
void func_003489B0(void)
{
    func_0033BE80();
    D_00760D80 = 0;
    D_00760D84 = 0;
    D_00760D88 = 0;
    D_00760D8C = 0;
}
