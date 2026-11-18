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
