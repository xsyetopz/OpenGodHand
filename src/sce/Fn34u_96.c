// COMPILER: ee-gcc2.96
extern char D_00760D90[];
extern void (*D_003EE07C)(int, int);
char *func_003452B0(void);
void func_00324950(void);
void func_003B9D68(void);
void func_00366C50(char *, int, int);
int func_003463F8(int);
int func_0035A1C8(char *, int);
void func_0034B8C8(char *);
int func_00397100(void);
int func_00397550(int, int, int);
void func_00347498(void);
void func_003475F0(char *);
int func_00348938(int);
int func_003492E8(int);
int func_00349468(int, int);
int func_003403C8(void);
int func_00340580(int, int);
int func_003403E0(void);

void func_0035C2D0(char *, int, int, int, int);
int func_00346828(int *);
void func_00348BE0(char *);
extern char D_00458238[], D_00458758[];
typedef struct { char c[16]; } B16;
extern int D_00760D84;
int func_0034CAF8(int, int *, int *);
long func_0034CCB0(long, int);
void func_0035FD20(int, int *, int *);
void func_0033BA10(int, int, int, int, int);
int func_0034C2B8(int, int, int *);

// FUNCTION: GAME 0x349738
void func_00349738(int *a, int b)
{
    char *p = func_003452B0();
    if (a) a[0x17] = b;
    *(int *)(p + 0x24) = b;
}

// FUNCTION: GAME 0x349D38
int func_00349D38(void)
{
    func_00324950();
    func_003B9D68();
    func_00366C50(D_00760D90, 0, 7);
    return 0;
}

// FUNCTION: GAME 0x34BBC0
void func_0034BBC0(int *d, int *s, int acc)
{
    int i;
    for (i = 0; i < 8; i++) {
        int t = s[i];
        d[i] = acc;
        acc += t;
    }
}

// FUNCTION: GAME 0x346410
void func_00346410(int a)
{
    int r = func_003463F8(a);
    if (D_003EE07C) D_003EE07C(a, r);
}

// FUNCTION: GAME 0x34B888
int func_0034B888(char *a)
{
    if (func_0035A1C8(a, 6)) {
        char *p = a + 0x365C;
        *(char **)(a + 0x2114) = p;
        func_0034B8C8(p);
        return 0;
    }
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x34DDE0
// diff: 13 words, extra branch-likely and shifted v1 copy of b around the a[2] store
void func_0034DDE0(int *a, int b)
{
    if (!a[2]) a[2] = b;
    if (b && a[0]) ((void (*)(int))a[0])(a[1]);
}
#endif

// FUNCTION: GAME 0x34E8E8
int func_0034E8E8(unsigned char *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (*p++) return 0;
    return 1;
}

// FUNCTION: GAME 0x346660
void func_00346660(void)
{
    int h = func_00397100();
    while (func_00397550(h, 1, 0x1E)) {}
}

// FUNCTION: GAME 0x347450
void func_00347450(char *a)
{
    if (*(int *)(a + 0x17C)) {
        func_00347498();
        func_003475F0(a);
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x348968
// diff: 3 words, constant 1 compared via a0 instead of v1 and bne vs bnel
int func_00348968(int *a)
{
    if (func_00348938(a[1]) && a[0] == 1) return a[7] != 0;
    return 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x3492A0
// diff: 11 words, result copy lands in a2 instead of staying in a1
int func_003492A0(int a)
{
    int r = func_003492E8(a);
    int x = 0;
    if (r != 1) x = func_00349468(a, 0);
    return x;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x34C0A0
// diff: 4 words, final a[5] test uses slt/movz instead of blezl
int func_0034C0A0(int *a)
{
    if (!a[1]) return -1;
    if (a[0]) return 0;
    if (!a[2]) return -1;
    if (a[3] <= 0) return -1;
    if (a[5] <= 0) return 0;
    return -1;
}
#endif

// FUNCTION: GAME 0x340538
int func_00340538(int a, int b)
{
    int r;
    func_003403C8();
    r = func_00340580(a, b);
    func_003403E0();
    return r;
}

// FUNCTION: GAME 0x344520
void func_00344520(int a, int b, int c)
{
    char *p = func_003452B0();
    *(int *)(p + 0x28) = a;
    *(int *)(p + 0x2C) = b;
    *(int *)(p + 0x30) = c;
}

// FUNCTION: GAME 0x34B8F8
void func_0034B8F8(char *a)
{
    if (func_0035A1C8(a, 6)) func_0035C2D0(a, 3, 6, 0, 0);
    __asm__ volatile("");
}

// FUNCTION: GAME 0x34B940
void func_0034B940(char *a)
{
    if (func_0035A1C8(a, 6)) func_0035C2D0(a, 3, 7, 0, 0);
    __asm__ volatile("");
}

// FUNCTION: GAME 0x34CD68
int func_0034CD68(char *a)
{
    if (func_0035A1C8(a, 0x31) || func_0035A1C8(a, 0x38)) return 1;
    return 0;
}

// FUNCTION: GAME 0x34CDB0
int func_0034CDB0(char *a)
{
    if (func_0035A1C8(a, 0x31) || func_0035A1C8(a, 0x39)) return 1;
    return 0;
}

// FUNCTION: GAME 0x3466F8
int func_003466F8(int *a)
{
    if (func_00346828(a) != 1) {
        func_00348BE0(D_00458238);
        return 0;
    }
    return a[0x3C / 4];
}

// FUNCTION: GAME 0x346AE8
int func_00346AE8(int *a)
{
    if (func_00346828(a) != 1) {
        func_00348BE0(D_00458758);
        return 0;
    }
    return a[0x1C0 / 4];
}

// FUNCTION: GAME 0x346FC0
void func_00346FC0(char *a, int b, int *c)
{
    int x[2];
    func_0035FD20(*(int *)(a + 0xA8), &x[0], &x[1]);
    c[0x58 / 4] = 0;
    c[0x50 / 4] = x[0];
    c[0x54 / 4] = x[1];
    c[0x5C / 4] = 0;
}

// FUNCTION: GAME 0x348A08
void func_00348A08(int a, int b, int c, int d)
{
    func_0033BA10(2, a, b, c, d);
    D_00760D84 = a;
}

// FUNCTION: GAME 0x34C208
void func_0034C208(char *a, int b, int c, B16 *d)
{
    a += b * 0x74 + 0x1320;
    a += c * 16;
    *(B16 *)a = *d;
}

// FUNCTION: GAME 0x34C250
void func_0034C250(char *a, int b, int c, B16 *d)
{
    a += b * 0x74 + 0x1320;
    a += c * 16;
    *d = *(B16 *)a;
}

// FUNCTION: GAME 0x34FCE0
void func_0034FCE0(char *a)
{
    int x[2];
    int v = *(int *)(a + 0x1324);
    if (v) {
        func_0034CAF8(v, &x[0], &x[1]);
        *(long *)(a + 0x988) = func_0034CCB0(*(long *)(a + 0x988), x[0]);
    }
}

// Diff: 6 words (register temps v0/v1 vs v1/a0; ra reload order).
#ifdef NONMATCHING
// DRAFT: GAME 0x34A9B8
void func_0034A9B8(char *a, int *b, int *c)
{
    int x[8];
    func_0034C2B8((int)a, *(int *)(a + 0x200C), x);
    *b = x[0];
    *c = x[1];
}
#endif
