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

// FUNCTION: GAME 0x34CDF8
void func_0034CDF8(char *p, int n)
{
    char lk[16];
    int *s = (int *)(p + 0xD30);
    int c, i;
    func_0034DF68(lk);
    c = s[0x164 / 4];
    i = s[0x168 / 4];
    c += n;
    i++;
    s[0x164 / 4] = c;
    ((int *)p)[0xE9C / 4 + i % 32] = c;
    s[0x168 / 4] = i;
    func_0034DF80(lk);
}

// FUNCTION: GAME 0x34CBB0
void func_0034CBB0(void)
{
    char lk[16];
    int **o = func_003395A0(lk, 8, 0);
    D_00760DB0 = ((int (*)(int **))(*o)[4])(o);
    ((void (*)(int **))(*o)[3])(o);
    o = func_00338B90(lk, 8);
    D_00760DB4 = ((int (*)(int **))(*o)[4])(o);
    ((void (*)(int **))(*o)[3])(o);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x34BEB8
// diff: store order: 0x28 hoisted, epilogue lds interleaved, 15 words
void func_0034BEB8(char *a, int *b, int *c, int i)
{
    int *pb = b + i;
    int *pc = c + i;
    int *s = (int *)(a + i * 0x74);
    func_0034BFA8((char *)s, 2, *pc != 0);
    s += 4;
    s[0] = *pb;
    s[1] = *pc;
    s[0x2C / 4] = 0;
    s[2] = 0;
    s[3] = 0;
    s[4] = 0;
    s[5] = 0;
    s[6] = 0;
    s[7] = 0;
    s[8] = 0;
    s[9] = 0;
    s[0xA] = 0;
}
#endif

typedef struct { char c[24]; } S24;

#ifdef NONMATCHING
// DRAFT: GAME 0x34C158
// diff: s1/s2/s3 reg assignment and copy placed before b[1]=c, 20 words
void func_0034C158(char *p, S24 *a, int *b, int c)
{
    char lk[16];
    func_0034DF68(lk);
    b[1] = c;
    *(S24 *)p = *a;
    func_0034C1F8(p + 0x18);
    *(int *)(p + 0x20) = 0;
    *(int *)(p + 0x24) = 0;
    func_003592D0(p + 0x28);
    func_0034DF80(lk);
}
#endif

// FUNCTION: GAME 0x346510
int func_00346510(int a, int b, int c)
{
    int *o = func_00397100(8);
    o[0x80 / 4] = a;
    func_003974D0(o, c, b / 16);
    return 0;
}

// FUNCTION: GAME 0x3465E8
int func_003465E8(int a, int b, int c)
{
    int *o = func_00397100(9);
    o[0x80 / 4] = c;
    func_00397450(o, a, b / 16);
    return 0;
}

// FUNCTION: GAME 0x34C748
void func_0034C748(char *a, int i, int b, int c)
{
    char lk[16];
    int *s = (int *)(a + i * 0x74 + 0x1338);
    func_0034DF68(lk);
    s[0] = b;
    s[1] = c;
    func_0034DF80(lk);
}

// FUNCTION: GAME 0x34C6D8
void func_0034C6D8(char *a, int i, int *b, int *c)
{
    char lk[16];
    int *s = (int *)(a + i * 0x74 + 0x1338);
    func_0034DF68(lk);
    *b = s[0];
    *c = s[1];
    func_0034DF80(lk);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x347008
// diff: load/store interleave differs (struct-copy scheduling), 10 words
void func_00347008(int a, char *b)
{
    int *d = (int *)(b + 0x60);
    int *s;
    *d = func_00347080(a);
    d[1] = func_003470F0(a);
    s = (int *)(a + 0x88);
    d[2] = s[2];
    d[3] = s[3];
    d[4] = s[4];
    d[5] = func_00347160(s[5]);
    d[6] = func_00347160(s[6]);
}
#endif

// FUNCTION: GAME 0x3498E8
void func_003498E8(char *a, int b, int c)
{
    int buf[40];
    int buf2[28];
    int s1 = *(int *)(a + 0xA8);
    func_00346C58((int)a, b, buf);
    func_0035F578(s1, buf, c, buf2, 0, 0, buf[0x44 / 4], buf[0x48 / 4]);
    func_0035F698(s1, buf, buf2);
}

// FUNCTION: GAME 0x34D6F0
void func_0034D6F0(int a, int *b)
{
    b[0] = func_0034DA50(a, func_0035DE38);
    b[1] = func_0034DA50(a, func_0035DE88);
    b[2] = func_0034DA50(a, func_0035DED8);
    b[3] = func_0034DA50(a, func_0035DF28);
    b[4] = func_0034DA50(a, func_0035DFE0);
    b[5] = func_0034DA50(a, func_0035E030);
    b[6] = func_0034DA50(a, func_0035E080);
}

// FUNCTION: GAME 0x34F188
int func_0034F188(int **a, int b, int c)
{
    int buf[2];
    ((void (*)())(*a)[6])(a, 0, c, buf);
    func_00366960(buf[0], b, buf[1]);
    ((void (*)(int **, int, int *))(*a)[8])(a, 1, buf);
    return buf[1];
}

#ifdef NONMATCHING
// DRAFT: GAME 0x342E88
// diff: constants folded (0x840 vs separate +0x40,+0x40,+0x800) and add order, 22 words
int func_00342E88(int a)
{
    int v[11];
    int t, u;
    func_00342BC8(a, &v[0], &v[1], &v[2], &v[3], &v[4], &v[5]);
    func_00342D00(a, &v[6], &v[7]);
    t = func_00342E50(a, &v[8], &v[9], &v[10]);
    u = func_00342E80();
    return v[1] + v[2] + v[3] + 0x40 + t + (v[0] + v[4]) + (v[6] + 0x40 + (v[7] + v[5])) + u + 0x800;
}
#endif

// FUNCTION: GAME 0x349988
void func_00349988(char *a, int b, int c, int d, int e, int f, int g)
{
    int buf[40];
    int buf2[28];
    int s = *(int *)(a + 0xA8);
    func_00346C58((int)a, b, buf);
    func_0035F578(s, buf, c, buf2, d, e, f, g);
    func_0035F788(s, buf, buf2);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x34B0F0
// diff: epilogue: lds hoisted above sw *c/*d, 4 words (locals order A,B,C,w)
void func_0034B0F0(int a, int b, int *c, int *d)
{
    long long A[2];
    long long B[2];
    int C[4];
    int w[2];
    D_003EE0A4 = func_00329F98(b);
    func_0032A160(b, &w[0], &w[1]);
    A[0] = w[0];
    A[1] = w[1];
    B[0] = func_00360B18();
    B[1] = func_00360C58();
    func_0035C5A0(a, A, B, C);
    *c = C[0];
    *d = C[2];
}
#endif

// FUNCTION: GAME 0x34A038
void func_0034A038(char *a, int b, int c, int *d)
{
    int buf[2];
    int *s1 = *(int **)(a + 0x2004);
    int s3 = s1[1];
    int n;
    func_00349F80(s3, s1[2], buf);
    n = buf[1];
    if (c < n)
        n = c;
    if (n > 0x19000)
        n = 0x19000;
    func_00366960(buf[0], b, n);
    func_00349FB0(s3, n, buf);
    s1[0x48 / 4] += n;
    *d = n;
}

// FUNCTION: GAME 0x346C58
int func_00346C58(int a, char *b, char *c)
{
    int *bi = (int *)b;
    int *ci = (int *)c;
    ci[0] = func_00346E70(bi[2]);
    func_00346ED0(b, c);
    func_00346FA0(b, c);
    func_00346FC0(a, b, c);
    func_00347008(a, c);
    {
        int x = bi[0x88 / 4];
        int y = bi[0x8C / 4];
        ci[0x88 / 4] = x;
        ci[0x8C / 4] = y;
    }
    ci[0x90 / 4] = func_00346D80(a, b);
    ci[0x94 / 4] = func_00346E20(a, bi[0x30 / 4]);
    return func_00346D08(a, b);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x34AA20
// diff: buf+4/buf+8 kept in s2/s3 and frame 0x40 vs 0x30 (CSE of &buf[1],&buf[2]), 44 words
void func_0034AA20(char *a)
{
    int buf[3];
    int *s1 = *(int **)(a + 0x2004);
    func_0034C890(a, *(int *)(a + 0x200C), buf);
    if (buf[0]) {
        func_0034CAF8(buf[0], &buf[1], &buf[2]);
        *(long long *)(a + 0x9B8) = func_0034CCB0(*(long long *)(a + 0x9B8), buf[1]);
        *(long long *)(a + 0x9C0) = func_0034CCB0(*(long long *)(a + 0x9C0), buf[2]);
        func_0034CAF8(s1[1], &buf[1], &buf[2]);
        *(long long *)(a + 0x9D0) = func_0034CCB0(*(long long *)(a + 0x9D0), buf[1]);
        *(long long *)(a + 0x9D8) = func_0034CCB0(*(long long *)(a + 0x9D8), buf[2]);
    }
}
#endif

// FUNCTION: GAME 0x3428A0
void func_003428A0(int a, int b, int c, int d)
{
    func_00348950(D_003EC668, 0);
    func_00345EC8(a);
    func_00348670(a, 0, b, c, d);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x349AD0
// diff: reg assignment: compiler gives s3=a0, original s0=a0 (9 words)
void func_00349AD0(int a, int b, int c, int d, int e)
{
    func_00327FA8(a, b, c, d, e);
    func_00327E18(a, b, c, d, e);
    func_00328448(a, e);
}
#endif
