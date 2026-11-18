// COMPILER: ee-gcc2.96
extern char D_00457140[], D_00459008[];
void func_00348BE0();
int func_00346C10(int, int);
int func_003472E8(int *);
char *func_003452B0(void);
int func_00346C48(int);
int func_0035FD58(int, int, int, int);
int func_00346828(int *);
void func_00347E58(int *, int);
void func_003466C0(int);
void func_00349738(int, int);
void func_00348C78(void);
void func_003466D8(void);
void func_00348CB8(int);
int *func_0034B618(int);
void func_0034B478(int, char *, int);
void func_00348E18(int);
void func_00348F68(int);

// Diff: 19 words, compare chain layout differs.
#ifdef NONMATCHING
// DRAFT: GAME 0x342E00
int func_00342E00(int a)
{
    if (a == 1) return 1;
    if (a == 0 || a == 2) return 2;
    if (a == 3) return 3;
    func_00348BE0(D_00457140);
    return 3;
}
#endif

extern char D_004571D8[], D_00457B90[], D_00457BA8[], D_00457BC0[], D_00458F48[];
extern long long D_00458140;
int func_003403C8(void);
int func_003403E0(void);
void func_003407A0(int, int, int, int);
int func_00342E88(void);
int func_00342F40(int *);
void func_00348A08(int, int (*)(), int, char *);
void func_00348AC8(int (*)(), int, char *);
void func_00348A70(int (*)(), int, char *);
void func_00348B20(void);
int func_00349238();
int func_00349250();
int func_003492A0();
int func_0031E8C0(int);
int func_0031E348(int, long long);
int func_0031E978(int);
void func_003467E8(char *, int, int);
void func_00335C68(int);
int func_0035A1C8(char *, int);
void func_0035C2D0(char *, int, int, int, int);
int func_0034DD70(char *, int);
// FUNCTION: GAME 0x342F40
int func_00342F40(int *a)
{
    int r = func_00346C10(a[2], a[3]);
    if (func_003472E8(a) == 1) r += 0x20000;
    return r;
}

// Diff: 10 words, result register (a0 vs v0) and movn/movz order.
#ifdef NONMATCHING
// DRAFT: GAME 0x3441D0
int func_003441D0(int *a)
{
    int *p = (int *)func_003452B0();
    int r = 0;
    if (a[6] == 0) {
        r = -1;
        if (p[0x28 / 4]) r = 0;
        if (p[0x2C / 4] == 0) r = -1;
    }
    return r;
}
#endif

// FUNCTION: GAME 0x347700
int func_00347700(int a, int b, int c, int d)
{
    return func_0035FD58(func_00346C48(a), b, c, d == 1);
}

// FUNCTION: GAME 0x347AA8
void func_00347AA8(int *a)
{
    if (func_00346828(a) != 1) {
        func_00348BE0(D_00459008);
        return;
    }
    func_00347E58(a, 0);
}

// FUNCTION: GAME 0x3497A0
void func_003497A0(int a)
{
    func_003466C0(a);
    func_00349738(a, 1);
    func_00348C78();
    func_00349738(a, 0);
    func_003466D8();
    func_00348CB8(a);
}

// FUNCTION: GAME 0x34A6F8
int func_0034A6F8(int a, int *b, int *c)
{
    int *p = func_0034B618(a);
    if (!p) return -1;
    *b = p[3];
    *c = p[4];
    return 0;
}

// Diff: 13 words, load register and tail-call layout.
#ifdef NONMATCHING
// DRAFT: GAME 0x348DD8
void func_00348DD8(int *a)
{
    if (a[0x284 / 4] == 1 || a[0x2A4 / 4] == 1) func_00348E18((int)a);
    else func_00348F68((int)a);
}
#endif

// Diff: 6 words, a3 load base register (v1 vs v0).
#ifdef NONMATCHING
// DRAFT: GAME 0x34B3E0
void func_0034B3E0(char *a, int b)
{
    int *p = *(int **)(a + 0x2004);
    int h;
    p[0x2C / 4] = b;
    h = p[0];
    if (b == 0 && *(int *)(a + 0x50) == 1) return;
    func_0034B478(h, a + 0x1020, b);
}
#endif

// Diff: 10 words, reloaded b[6] lands in v1/v0 instead of a2/v1.
#ifdef NONMATCHING
// DRAFT: GAME 0x344220
void func_00344220(char *a, int *b)
{
    int *v = (int *)(a + 0x1EC);
    int *p = (int *)(a + 0x280);
    int i;
    v[0] = b[6];
    v[1] = b[7];
    v[2] = b[6];
    v[3] = 0;
    *(int *)(a + 0x200) = 0;
    for (i = 0x1F; i >= 0; i--) *p-- = 0;
}
#endif

// FUNCTION: GAME 0x340740
void func_00340740(int a, short b, int c, int d)
{
    func_003403C8();
    func_003407A0(a, b, c, d);
    func_003403E0();
}

// FUNCTION: GAME 0x342F98
int func_00342F98(int *a)
{
    int r;
    if (!a) {
        func_00348BE0(D_004571D8);
        return 0;
    }
    r = func_00342E88();
    return r + func_00342F40(a);
}

// FUNCTION: GAME 0x345490
void func_00345490(void)
{
    func_00348A08(2, func_00349238, 0, D_00457B90);
    func_00348AC8(func_00349250, 0, D_00457BA8);
    func_00348A70(func_003492A0, 0, D_00457BC0);
    func_00348B20();
}

// Diff: 2 words, D_00458140 address via lui $v1 instead of lui $at.
#ifdef NONMATCHING
// DRAFT: GAME 0x346100
void func_00346100(char *a)
{
    int s = *(int *)(a + 0x1C8);
    int r = func_0031E8C0(s);
    r = func_0031E348(r, D_00458140);
    r = func_0031E978(r);
    func_003467E8(a, r, s);
}
#endif

// FUNCTION: GAME 0x347908
void func_00347908(int *a, int b)
{
    if (func_00346828(a) != 1) {
        func_00348BE0(D_00458F48, b);
        return;
    }
    func_00335C68(a[0x48 / 4]);
}

// FUNCTION: GAME 0x34B988
void func_0034B988(char *a, int b)
{
    if (func_0035A1C8(a, 6)) func_0035C2D0(a, 3, 8, b, 0);
    __asm__ volatile("");
}

// FUNCTION: GAME 0x34C930
int func_0034C930(char *a, int b, int c, int d)
{
    int *p = (int *)(a + 0x1310);
    p = (int *)((char *)p + b * 0x74);
    if (p[1] == 0) {
        func_0035C2D0(a, p[0x4C / 4], 0xB, c, d);
        return;
    }
    return 0;
}
