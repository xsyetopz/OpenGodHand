// COMPILER: ee-gcc2.96
extern int func_00366C50();
extern void func_00368E68();
extern int *D_003F1A98;
// FUNCTION: GAME 0x368D60
int func_00368D60(int n, int *buf)
{
    int i;
    int *p, *q;
    D_003F1A98 = buf;
    func_00366C50(buf, 0, n * 64 + 4);
    func_00368E68(D_003F1A98);
    q = D_003F1A98;
    q[3] = n;
    p = q + 4;
    for (i = 0; i < n; i++) {
        *p = 1;
        p += 64;
    }
    return 0;
}

extern int func_00360720();
extern void func_0035FBD8();
extern char D_0045A0A0[];
// FUNCTION: GAME 0x360520
void func_00360520(int a, unsigned *src, short *dst)
{
    int i;
    if (func_00360720(a) == 1) {
        short *d = dst;
        unsigned *s = src;
        for (i = 0; i < 256; i++) {
            *d = *s >> 15;
            s++;
            d++;
        }
    } else {
        func_0035FBD8(0, 0, D_0045A0A0);
    }
}

#ifdef NONMATCHING

// DRAFT: GAME 0x369E98
// diff: orig s1=a2/s2=a1 and stores [1] before [0]; ours stores [0] first (4 words, 4 probes)
extern int func_0036C5F8();
extern int func_00369F20();
struct P { int a; int b; };
extern struct P D_003F1AA0;
int func_00369E98(char *o, int a, int b)
{
    struct P *p;
    if (o == 0)
        p = &D_003F1AA0;
    else {
        if (func_0036C5F8(o))
            return func_00369F20(0, 0xFF030203);
        p = (struct P *)(o + 0x250);
    }
    p->b = b;
    p->a = a;
    return 0;
}

// DRAFT: GAME 0x360200
// diff: orig does a0+=0x28 in place and uses likely-branch delay slots; ours uses t1/bne (many words, 4 probes)
extern void func_0033ADF8();
struct Q { int pad[10]; int k, a, b; };
void func_00360200(struct Q *q, int a1, int a2, int *oa, int *ob)
{
    int t[2];
    int r[2];
    if (q->k == 1) {
        if (q->a != 0) {
            t[0] = q->a;
            t[1] = q->b;
            func_0033ADF8(t, a1, a2, r);
            *oa = r[0];
            *ob = r[1];
            return;
        }
    }
    *oa = 0;
    *ob = 0;
}

// DRAFT: GAME 0x36BFB0
// diff: orig loads -1 into v0 before 0x17F into v1 for the third loop; ours reverses (2 words, 4 probes)
extern unsigned char D_003F1AC8[];
extern unsigned char D_003F1C48[];
extern unsigned char *D_003F1ABC;
void func_0036BFB0(void)
{
    unsigned char *p = D_003F1AC8;
    int i;
    for (i = 0x17F; i >= 0; i--)
        *p++ = 0;
    for (i = 0; i < 0x100; i++)
        *p++ = i;
    for (i = 0x17F; i >= 0; i--)
        *p++ = 255;
    D_003F1ABC = D_003F1C48;
}
#endif
