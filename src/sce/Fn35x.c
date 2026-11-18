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
int func_00347080();
int func_003470F0();
int func_00347160(int);
void func_00346C58(int, int, int *);
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

// FUNCTION: GAME 0x34BEB8
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

typedef struct { char c[24]; } S24;

// FUNCTION: GAME 0x34C158
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

// FUNCTION: GAME 0x358598
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

// FUNCTION: GAME 0x35B500
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

// FUNCTION: GAME 0x347008
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

// FUNCTION: GAME 0x35F578
void func_0035F578(int a, int *b, int c, int *d, int e, int f, int g, int h)
{
    func_0035EA30(a, b, e, f, g, h);
    func_0035F5F0(a, b, c, d, 0);
    *d = 1;
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
