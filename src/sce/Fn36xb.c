// COMPILER: ee-gcc2.96
// SCE library code (sd s0 prologues), built with ee-gcc 2.96 (C) at -O2 -G0.

extern int D_00760DB0;
extern int D_00459920[];
extern void (*D_00459948[])();
int func_00359518();
long long func_003520D8();
int func_00368FC0();
int (*func_0035A1C8())();
void func_00366960();
void func_0034D4A0();
void func_0034DAC0();
void func_0034D2D8();
int func_00368E90();
void func_0035A4D0(int *, int);
void func_00354B20(int *);
int func_0035E0F0(int, int);
int func_0035E9E8(int);
void *memset(void *, int, unsigned int);
void func_0034DF68(void *);
void func_0034DF80(void *);
void func_00366C50(int *, int, int);

extern int D_00766CE8[];
extern char D_0045A420[];
extern int D_0076A590[];
void func_0033ACA0();
int func_0036B888();
void func_0036BB78(int **);
void func_0036C438(int *, int);
void func_0036D6B0(int *, char *, int);
int func_00368B18(int, int *, int);
int func_00366E18();
void func_0034DD70();


// FUNCTION: GAME 0x34D210
int func_0034D210(char *a, int b, int c)
{
    int (*fn)() = func_0035A1C8(a, 0x4B);
    int o = (int)func_0035A1C8(a, 0x4C);
    int n;
    int *s3;
    if (fn)
        fn(o, b, c);
    s3 = (int *)(a + 0x78);
    if (*s3)
        return 0;
    n = c > 0x800 ? 0x800 : c;
    func_00366960(a + 0x10C, b, n);
    s3[0x90 / 4] = n;
    func_0034D4A0(s3);
    func_0034DAC0(a);
    func_0034D2D8(a);
    return 1;
}

int func_00344E18();
int func_00346FB0();

// FUNCTION: GAME 0x346ED0
void func_00346ED0(int *a, int *b)
{
    int buf[6];
    int h = a[4];
    int w = a[3];
    int k = a[2];
    b[0x44 / 4] = w;
    b[0x48 / 4] = h;
    if (k != 3) {
        func_00346FB0(b + 1, a[0], w, h);
    } else {
        int hh;
        func_00344E18(a[0], w, h, buf);
        func_00346FB0(b + 1, buf[0], buf[3], h);
        hh = h / 2;
        func_00346FB0(b + 5, buf[1], buf[4], hh);
        func_00346FB0(b + 9, buf[2], buf[5], hh);
    }
}

// FUNCTION: GAME 0x34CF38
int func_0034CF38(char *a, int *b, int *c)
{
    char lk[16];
    int *s0 = (int *)(a + 0xD30);
    int r;
    func_0034DF68(lk);
    if (s0[0x1F4 / 4] - s0[0x1F8 / 4] <= 0) {
        r = 0;
        *b = -1;
    } else {
        r = 1;
        *c = s0[0x1EC / 4];
        *b = ((int *)a)[0xF2C / 4 + s0[0x1F8 / 4] % 32];
        s0[0x1F8 / 4]++;
    }
    func_0034DF80(lk);
    return r;
}

int func_0035C480();
void func_0035CB20();

#ifdef NONMATCHING
// DRAFT: GAME 0x35C3A0 constant-register allocation (1/1000000 in a1/a2 vs v0/v1), 37 words
void func_0035C3A0(char *a)
{
    int *p = (int *)a;
    long long *q = (long long *)a;
    memset(a, 0, 0x1C0);
    p[0xC / 4] = 1;
    p[0x10 / 4] = 10;
    p[0] = 1;
    p[1] = 0;
    p[2] = 0;
    func_0035C480(a);
    q[0x108 / 8] = 0;
    q[0x130 / 8] = 1;
    q[0x138 / 8] = 0x412B;
    q[0x148 / 8] = 0x30D40;
    q[0x170 / 8] = 1000000;
    q[0x178 / 8] = -1;
    p[0x1B8 / 4] = 0;
    q[0x110 / 8] = 1;
    q[0x118 / 8] = 0;
    q[0x120 / 8] = 1;
    q[0x128 / 8] = 0;
    q[0x140 / 8] = 1000000;
    q[0x150 / 8] = 1000000;
    q[0x158 / 8] = 0;
    q[0x160 / 8] = 1000000;
    q[0x168 / 8] = 0;
    q[0x180 / 8] = 0;
    q[0x188 / 8] = 0;
    p[0x190 / 4] = 0;
    p[0x194 / 4] = 0;
    p[0x198 / 4] = 0;
    p[0x19C / 4] = 0;
    p[0x1A0 / 4] = 0;
    p[0x1A4 / 4] = 0;
    p[0x1A8 / 4] = 0;
    p[0x1AC / 4] = 0;
    p[0x1B0 / 4] = 0;
    p[0x1B4 / 4] = 0;
    func_0035CB20();
}
#endif

extern char D_0045A060[], D_0045A068[], D_0045A070[];
int func_0033ADF8();

#ifdef NONMATCHING
// DRAFT: GAME 0x360000 store order in the zero branch and s2 setup order (4 words at best)
void func_00360000(char *a)
{
    int buf[2];
    int out[2];
    int *s3 = (int *)(a + 0x18);
    int *s4 = (int *)(a + 0x28);
    int *v = (int *)(a + 8);
    int t = v[1];
    if (t == 0) {
        s3[2] = 0;
        s3[0] = 1;
        s3[1] = 0;
        s4[0] = 1;
        s4[2] = 0;
        s4[1] = 0;
    } else {
        buf[0] = t;
        buf[1] = v[2];
        func_0033ADF8(buf, D_0045A060, D_0045A068, out);
        s3[1] = out[0];
        s3[2] = out[1];
        s3[0] = 1;
        func_0033ADF8(buf, D_0045A070, D_0045A068, out);
        s4[0] = 1;
        s4[1] = out[0];
        s4[2] = out[1];
    }
}
#endif
