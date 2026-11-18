// COMPILER: ee-gcc2.96
extern char D_00458928[];
void func_00348BE0();
int func_003403C8(void);
int func_003403E0(void);
void func_00340970(int, int, int);
void func_003446D0(char *);
void func_003446D8(int);
void func_00344780(char *);
void func_00359EC0(int, int, void *);
int func_00345090();
int func_00346DD0(int, int);
int func_00360808(int, int);
int func_00349840(int);
int func_003492E8(int);
int func_00349468(int, int);
int func_0034B030();
void func_0035B0D8(int, int (*)(), int);
void func_0035A000(int, int, int);
void func_0032B300(int, int);
void func_0035C538(int, int);
void func_0035B5B8(int, int *, int *);
int func_0036C920(int, int, int);
void func_0034BD98(int, int);
void func_0034BFA8(char *, int, int);
void func_0034BFC8(char *);
int func_0034FEE0(int);
int func_0034DD70(char *, int);

// FUNCTION: GAME 0x340920
void func_00340920(int a, int b, int c)
{
    func_003403C8();
    func_00340970(a, b, c);
    func_003403E0();
}

// FUNCTION: GAME 0x342CB0
void func_00342CB0(int *a, int *b, int *c, int *d, int *e)
{
    int t2 = a[2];
    int t3 = a[3];
    *d = (t2 / 2 + 31) / 32 * 32;
    *e = t3 / 2;
    *b = t2;
    *c = t3;
}

// FUNCTION: GAME 0x346D80
int func_00346D80(int a, int *b)
{
    int r = func_00346DD0(a, b[0x30 / 4]) == 1;
    if (b[0x88 / 4]) r = func_00360808(b[0x88 / 4], b[0x8C / 4]) == 1;
    return r;
}

// FUNCTION: GAME 0x34AFF0
void func_0034AFF0(int a)
{
    func_0035B0D8(a, func_0034B030, 2);
    func_0035A000(a, 0xF, 2);
}

// FUNCTION: GAME 0x34B478
void func_0034B478(int a, int b, int c)
{
    func_0032B300(a, c);
    func_0035C538(b, c);
}

// FUNCTION: GAME 0x34B4B8
void func_0034B4B8(int a, int *b, int c)
{
    int x[2];
    func_0035B5B8(a, &x[0], &x[1]);
    *b = func_0036C920(c, x[0], x[1]);
}

// FUNCTION: GAME 0x34BD58
void func_0034BD58(int a)
{
    func_0034BD98(a, 0);
    func_0034BD98(a, 1);
    func_0034BD98(a, 2);
}

// FUNCTION: GAME 0x34FE90
void func_0034FE90(char *a)
{
    int *p = *(int **)(a + 0x1F7C);
    if (func_0034FEE0(*p)) func_0034DD70(a, 0xFF000D0A);
}

// FUNCTION: GAME 0x345040
void func_00345040(char *a)
{
    int s = *(int *)(a + 0x3C);
    func_00359EC0(s, 0x4B, func_00345090);
    func_00359EC0(s, 0x4C, a);
}

// Diff: 2 words, a1 is copied to v1 early in the original (b held across the branch).
#ifdef NONMATCHING
// DRAFT: GAME 0x344680
void func_00344680(char *a, int b)
{
    if (*(int *)(a + 0x1EC)) func_003446D0(a);
    else func_003446D8(b);
    func_00344780(a);
}
#endif
