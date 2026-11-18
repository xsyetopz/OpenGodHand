// COMPILER: ee-gcc2.96
// SCE library code (sd s0 prologues), built with ee-gcc 2.96 (C) at -O2 -G0.

extern int D_00459920[];
int func_00356358();
int func_0036C920();

#ifdef NONMATCHING
// DRAFT: GAME 0x354128 p=b+3 lands in a2 then moved to a1 (original keeps it in a1); 51 words
void func_00354128(char *a, int *b)
{
    int *s1 = (int *)(a + 0xD30);
    int *p = b + 3;
    int v;
    b[0x3C / 4] = p[0x28 / 4];
    b[0x38 / 4] = p[0x24 / 4] - ((int *)a)[0xE6C / 4] + s1[0x164 / 4];
    b[0x4C / 4] = p[0x24 / 4];
    b[0x50 / 4] = p[0x24 / 4] + s1[0x164 / 4];
    if (func_00356358(a, p)) {
        v = func_0036C920(b[0x3C / 4], (b[0xE8 / 4] - s1[0x160 / 4]) * 1000, D_00459920[b[0x6C / 4]]);
        b[0x4C / 4] = v;
        b[0x50 / 4] = b[0x38 / 4] = v + s1[0x164 / 4];
    }
    if (s1[0x284 / 4] < b[0x38 / 4]) {
        s1[0x284 / 4] = b[0x38 / 4];
        s1[0x288 / 4] = b[0x3C / 4];
    }
}
#endif

int func_003538B0();
int func_0033A010();
int func_00369FB8();
int func_00351C18();
int func_00351B70();
void func_00358768();

#ifdef NONMATCHING
// DRAFT: GAME 0x3537C0 s-register numbering differs (a in s1 vs s2, s1 loaded value); same instruction count
int func_003537C0(char *a, int b)
{
    int s3, s4, r;
    int s1;
    int *s5 = *(int **)(a + 0x1FC0);
    char *s6;
    s1 = s5[0];
    func_003538B0(a);
    s4 = func_0033A010(b, 0, 1);
    s6 = (char *)s5 + 0x8C;
    s3 = func_00369FB8(s1, b);
    s1 = func_0033A010(b, 0, 1) - s4;
    r = func_00351C18(a, s3, s1, 0xFF000F07);
    func_00351B70(a, s1);
    if (r)
        return r;
    if (!s6[0x58])
        s5[0x16C / 4] = 1;
    func_00358768(a, 1, *(int *)(s6 + 0x18));
    return 0;
}
#endif

extern char D_00458B50[];
int func_00346828();
int func_00346C48();
void func_0035FC60();
void func_0035FC78();
void func_00348BE0();

// FUNCTION: GAME 0x347218
void func_00347218(int a, int b, int c, int d)
{
    int o;
    if (func_00346828(a) != 1) {
        func_00348BE0(D_00458B50);
        return;
    }
    o = func_00346C48(a);
    func_0035FC60(o, b, c);
    func_0035FC78(o, d);
}

int func_0034C588();

#ifdef NONMATCHING
// DRAFT: GAME 0x34C2D0 a1=d copy scheduled after sd ra vs before sll in the original
int func_0034C2D0(char *a, int b, int *c, int d)
{
    int buf[8];
    int *base = (int *)(a + 0x1310);
    int *p = base + b * 29;
    c[1] = 0;
    c[3] = 0;
    c[5] = 0;
    c[6] = 0;
    c[0] = 0;
    c[2] = 0;
    c[4] = 0;
    if (!p[1] || !p[5])
        return 0;
    func_0034C588(p[5], d, buf, buf + 4);
    c[0] = buf[0];
    c[3] = buf[5];
    c[1] = buf[1];
    c[2] = buf[4];
    return 0;
}
#endif

int func_003417F0();

#ifdef NONMATCHING
// DRAFT: GAME 0x341900 gcc hoists the 3 sh stores above the sw stores (original: sw first, sw 0x34 in bgezl delay slot); 22 words
int func_00341900(char *a, int b, int c)
{
    short r[4];
    int *w = (int *)a;
    short *h = (short *)a;
    h[1] = 1;
    if (func_003417F0(b, c, r, a + 0xC, a + 0xD, a + 0xF, a + 0xE, a + 0x14, a + 0x18, a + 0x10, r + 2) < 0)
        return 0;
    w[0x34 / 4] = 0;
    w[0x30 / 4] = 0;
    w[0x2C / 4] = 0;
    w[0x28 / 4] = 0;
    w[0x20 / 4] = 0;
    h[0x1C / 2] = 0;
    h[0x26 / 2] = 0;
    h[0x24 / 2] = 0;
    w[0x50 / 4] = a[0xE];
    w[0x54 / 4] = a[0xF];
    h[0x9C / 2] = (unsigned short)r[2];
    w[0x5C / 4] = w[0x3C / 4];
    h[0x98 / 2] = 4;
    w[0x58 / 4] = *(int *)(a + 0x10);
    w[0x60 / 4] = w[0x40 / 4];
    w[0x64 / 4] = w[0x44 / 4];
    w[0x8C / 4] = 0;
    w[0x88 / 4] = 0;
    return r[0];
}
#endif

int func_003500E8();
void func_0034D3E8();
void func_00350040();
int func_00350048();

// FUNCTION: GAME 0x34FF98
int func_0034FF98(char *a)
{
    int *s0 = (int *)func_003500E8(a);
    int *s2;
    char *s3;
    int r;
    if (!s0)
        return 0;
    if (!s0[0])
        return 0;
    s2 = *(int **)(a + 0x1F7C);
    func_0034D3E8(a);
    func_00350040(a);
    s3 = a + 0xD30;
    r = func_00350048(a, s2, s0);
    if (r)
        return r;
    s2[0x2C / 4] = s0[0x28 / 4];
    *(long long *)(s3 + 0x150) = *(long long *)((char *)s0 + 0x18);
    s2[0x30 / 4] = s0[0x2C / 4];
    *(long long *)((char *)s2 + 0x10) = *(long long *)((char *)s0 + 0x20);
    return r;
}

void *memcpy(void *, const void *, unsigned int);
void func_00354430();
void func_003542B8();

// FUNCTION: GAME 0x354210
void func_00354210(char *a, int *b, int c)
{
    int buf[3];
    char *s2 = *(char **)(a + 0x1FC0);
    if ((unsigned)(b[0x74 / 4] - 1) < 2)
        func_00354430(s2 + 0x1094, b[0x54 / 4]);
    func_003542B8(c, buf, buf + 1, buf + 2);
    if (buf[0] == 3) {
        memcpy(*(void **)b[0x54 / 4], (void *)buf[1], buf[2]);
        ((int *)b[0x54 / 4])[1] = buf[2];
    } else
        func_00354430(b[0x54 / 4], s2 + 0x1094);
}

int func_0035EA88();

#ifdef NONMATCHING
// DRAFT: GAME 0x35F5F0 gcc CSEs d+e*16 into one reg; original keeps d (s1) and e*16 (s0) separate and adds twice
void func_0035F5F0(int *a, int *b, int c, char *d, int e)
{
    int off = e * 16;
    int v;
    *(int *)(d + off + 4) = c;
    *(int *)(d + off + 8) = b[0x44 / 4];
    if (func_0035EA88(a, b[0x44 / 4]) == 1)
        *(int *)(d + off + 12) = b[0x48 / 4] / 2;
    else
        *(int *)(d + off + 12) = b[0x48 / 4];
    v = a[2];
    if (!v)
        v = b[0x44 / 4];
    *(int *)(d + off + 16) = v;
}
#endif

int func_00348968();
void func_00348C78();
void func_00348498();
void func_003483F8();
void func_003482C8();

// FUNCTION: GAME 0x348870
void func_00348870(int *a)
{
    int s1, s3;
    int **s2;
    if (func_00348968(a) == 1) {
        s1 = a[0x1C / 4];
        s3 = a[1];
        s2 = (int **)a[0x14 / 4];
        if (s1) {
            func_00348C78();
            func_00348498(a);
            a[0] = 0;
            func_003483F8(s3, s1);
            ((void (*)(int **))(*s2)[3])(s2);
            a[0x1C / 4] = 0;
            func_003482C8(s3);
        }
    }
}

extern char D_00459748[];
void func_0039AA38();
void func_00355C88();
void func_00356648();

#ifdef NONMATCHING
// DRAFT: GAME 0x3566E8 v0/v1 swap and bnel vs bnez: constant 1 return kept in v0 by the original (5 words)
int func_003566E8(int a, int b, char *c)
{
    char *base = *(char **)(c + 0x1FC0);
    int r = 1;
    int *s1 = (int *)(base + 0x1128);
    int *s0 = (int *)(base + 0x1198);
    if (s1[0x18 / 4] == 1) {
        func_0039AA38(base + 0x1150);
        return r;
    }
    func_00355C88(s0);
    if (s1[0x14 / 4]) {
        if (!s0[0x10 / 4]) {
            s1[0x18 / 4] = 1;
            func_00356648(s0, D_00459748, 0x10);
            s0[0x14 / 4] = s0[0x18 / 4];
            func_00355C88(s0);
        }
    }
    return r;
}
#endif
