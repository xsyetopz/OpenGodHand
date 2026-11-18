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
