// COMPILER: ee-gcc2.96
// SCE library code (sd s0 prologues), built with ee-gcc 2.96 (C) at -O2 -G0.

extern int D_00760DB0;
extern int D_00760DB4;
void *memset(void *, int, unsigned int);
void func_0034DF68(void *);
void func_0034DF80(void *);
void func_0034BFA8(char *, int, int);
void func_0034C1F8(char *);
void func_003592D0(char *);
int **func_003395A0(void *, int, int);
int **func_00338B90(void *, int);
int func_00355130(int, int, int);
int *func_00397100(int);
void func_003974D0(int *, int, int);
void func_00397450(int *, int, int);
void func_00366C50(int *, int, int);
int func_0036C920(int);
extern int D_003EE278;
extern char D_003EC668[];
void func_00348950(char *, int), func_00345EC8(int);
void func_00348670(int, int, int, int, int);
void func_00327FA8(int, int, int, int, int);
void func_00327E18(int, int, int, int, int);
void func_00328448(int, int);
void func_0035EF30(int, void *), func_0035EF38(int, void *), func_0035EF40(int, void *);
void func_0035EF50(int, void *), func_0035EF60(int, void *), func_0035EF70(int, void *);
int func_0035EF78();
extern void func_00365D18(), func_00366730(), func_00365EC0(), func_00366368(), func_00366110(), func_003665C0();
int func_00346E70(int);
void func_00346ED0(char *, char *), func_00346FA0(char *, char *);
void func_00346FC0(int, char *, char *);
void func_00347008(int, char *);
int func_00346D80(int, char *);
int func_00346E20(int, int);
int func_00346D08();
void func_0034C890();
void func_0034CAF8(int, int *, int *);
long long func_0034CCB0(long long, int);
int func_0036A3E8(int, int **);
extern int D_003EE0A4;
void func_00355AC8();
int func_003569E0(int, int, int, int, int, int, int, int);
void func_00355BB8(int, int);
void func_00368E80(char *), func_00369118(char *), func_00369130(char *), func_00369158(char *);
extern void func_00366EC0();
int func_0035F788();
int func_00329F98(int);
void func_0032A160(int, int *, int *);
int func_00360B18();
int func_00360C58();
void func_0035C5A0(int, long long *, long long *, int *);
void func_00349F80(int, int, int *);
void func_00349FB0(int, int, int *);
int CreateSema(void *);
void func_00355988(int *);
void func_00366960(int, int, int);
int func_00342BC8();
void func_00342D00();
int func_00342E50();
int func_00342E80();
int func_00347080();
int func_003470F0();
int func_00347160(int);
int func_00346C58();
void func_0035F578(int, int *, int, int *, int, int, int, int);
void func_0035F698(int, int *, int *);
void func_0035EA30(int, int *, int, int, int, int);
void func_0035F5F0(int, int *, int, int *, int);
int func_0034DA50(int, void *);
extern void func_0035DE38(), func_0035DE88(), func_0035DED8(), func_0035DF28();
extern void func_0035DFE0(), func_0035E030(), func_0035E080();

#ifdef NONMATCHING
// DRAFT: GAME 0x36DD18
// diff: store order of 19 sw differs (scheduler permutes; source order unknown)
void func_0036DD18(char *p)
{
    int *q = (int *)(p + 0x160);
    memset(q, 0, 0x4D0);
    q[0xD4 / 4] = 1;
    q[0x7C / 4] = 0xFF;
    q[0x4C0 / 4] = 0;
    q[0x4C / 4] = 1;
    q[0x70 / 4] = 0;
    q[0x74 / 4] = 0xFF;
    q[0x78 / 4] = 0xFF;
    q[0x40C / 4] = 0;
    q[0x410 / 4] = 0;
    q[0x414 / 4] = 0;
    q[0x418 / 4] = 0;
    q[0x41C / 4] = 0;
    q[0x420 / 4] = 0;
    q[0x428 / 4] = 0;
    q[0x3C8 / 4] = 0;
    q[0x49C / 4] = 0;
    q[0x4A0 / 4] = 0;
    q[0x4B0 / 4] = 0;
    q[0xD0 / 4] = 0;
}
#endif

// FUNCTION: GAME 0x3550D0
int func_003550D0(int a, int b, int c)
{
    char lk[16];
    int r;
    func_0034DF68(lk);
    r = func_00355130(a, b, c);
    func_0034DF80(lk);
    return r;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x358598
// diff: store order: 0x28 hoisted above 0x1C, 11 words
void func_00358598(int *p)
{
    func_00366C50(p, 0, 0x10);
    p[0x2C / 4] = -1;
    p[0x1C / 4] = 1;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[8] = 0;
    p[9] = -1;
    p[10] = -1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x35B500
// diff: lw/addu/sw ordering of the two += updates, 7 words
void func_0035B500(char *a)
{
    char lk[16];
    int *s = (int *)(a + 0xD30);
    int r = func_0036C920(D_003EE278);
    func_0034DF68(lk);
    s[0x2A8 / 4] += r;
    s[0x2CC / 4] += r;
    func_0034DF80(lk);
}
#endif

// FUNCTION: GAME 0x35F578
void func_0035F578(int a, int *b, int c, int *d, int e, int f, int g, int h)
{
    func_0035EA30(a, b, e, f, g, h);
    func_0035F5F0(a, b, c, d, 0);
    *d = 1;
}

// FUNCTION: GAME 0x359370
void func_00359370(int *p, int b, int c)
{
    int *q = (int *)(((b + 7) & -8));
    int n = c - ((int)q - b);
    memset(q, 0, n);
    p[0] = (int)q;
    p[4] = 0;
    p[2] = 0;
    p[3] = 0;
    p[1] = n / 16;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x355910
// diff: 4 words, store order 0x18,0x8,0,0x50 vs 0,0x50,0x18,0x8
int func_00355910(int *p, int a, unsigned int b, int c, int d, int e)
{
    int sema[6];
    p[0x54 / 4] = e;
    p[6] = c << 11;
    p[2] = c;
    p[0] = a;
    p[0x50 / 4] = d;
    p[1] = (b & 0xFFFFFFF) | 0x20000000;
    sema[2] = 1;
    sema[1] = 1;
    p[0x40 / 4] = CreateSema(sema);
    func_00355988(p);
    *(long long *)(p + 0x48 / 4) = 0;
    return 1;
}
#endif

// FUNCTION: GAME 0x356648
int func_00356648(int a, int b, int c)
{
    int v[4];
    int r;
    func_00355AC8(a, &v[0], &v[1], &v[2], &v[3]);
    r = func_003569E0((v[0] & 0xFFFFFFF) | 0x20000000, v[1], (v[2] & 0xFFFFFFF) | 0x20000000, v[3], b, c, 0, 0);
    func_00355BB8(a, r);
    return r;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x35FAD8
// diff: store order permuted (0x3C first vs 0x0), 16 words
void func_0035FAD8(int *p, int b, int c)
{
    int v;
    memset(p, 0, 0x94);
    v = (b + 0x1F) & -0x20;
    p[0x50 / 4] = b;
    p[0x54 / 4] = c;
    p[0] = 1;
    p[0x3C / 4] = v + 0x400;
    p[0x40 / 4] = v + 0x800;
    p[0x44 / 4] = v + 0xC00;
    p[0x58 / 4] = -1;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[0x28 / 4] = 1;
    p[0x2C / 4] = 0;
    p[0x34 / 4] = 0;
    p[0x38 / 4] = v;
    p[0x64 / 4] = 0;
}
#endif

// FUNCTION: GAME 0x369078
int *func_00369078(int *p)
{
    char *q = (char *)p;
    func_00366C50(p, 0, 0x40);
    p[0] = 2;
    func_00368E80(q + 4);
    p[4] = 2;
    func_00369118(q + 0x18);
    func_00369130(q + 0x28);
    func_00369130(q + 0x48);
    func_00369130(q + 0x68);
    func_00369130(q + 0x88);
    func_00369158(q + 0xA8);
    p[0xD0 / 4] = 0;
    p[0xD8 / 4] = 0;
    p[0xDC / 4] = 0;
    p[0xD4 / 4] = (int)func_00366EC0;
    p[0xE0 / 4] = 0;
    p[0xE4 / 4] = 0;
    p[0xE8 / 4] = 0;
    return p;
}

// FUNCTION: GAME 0x35F788
int func_0035F788(int a, int b, int c)
{
    *(int *)(a + 0x50) = 0;
    func_0035EF30(a, func_00365D18);
    func_0035EF38(a, func_00366730);
    func_0035EF40(a, func_00365EC0);
    func_0035EF50(a, func_00366368);
    func_0035EF60(a, func_00366110);
    func_0035EF70(a, func_003665C0);
    return func_0035EF78(a, b, c);
}

// FUNCTION: GAME 0x36A668
int func_0036A668(int a, int *b, int *c)
{
    int **o = func_00338B90((void *)b[0], b[1]);
    int r, n;
    if (!o)
        return -1;
    r = func_0036A3E8(a, o);
    n = ((int (*)(int **, int))(*o)[9])(o, 1);
    *c = b[1] - n;
    ((void (*)(int **))(*o)[3])(o);
    return r;
}
