// COMPILER: ee-gcc2.9-991111
// SCE helpers in 0x390000-0x3A4AF0 (copy-out and status lookups).

struct Ent { int _0[4]; int m10; int _14[2]; };
struct Grp { struct Ent e[4]; char _p[0x70 - 4 * 0x1C]; };
extern struct Grp D_0077C110[];
extern void *memcpy(void *, const void *, unsigned);

struct Tmp { char _p[0x60]; int n; char _q[0x10]; };
extern void func_00397BC8(int a, int b, struct Tmp *t);

// FUNCTION: GAME 0x397D20
int func_00397D20(int g, int e, void *dst)
{
    struct Tmp t;
    if (!D_0077C110[g].e[e].m10) return 0;
    func_00397BC8(g, e, &t);
    memcpy(dst, &t, t.n);
    return t.n;
}

extern void func_00397BC8_b(int a, int b, unsigned char *t) __asm__("func_00397BC8");

// FUNCTION: GAME 0x397D98
int func_00397D98(int g, int e)
{
    unsigned char t[0x78];
    if (!D_0077C110[g].e[e].m10) return 0x63;
    func_00397BC8_b(g, e, t);
    if (t[0x70] == 6 && t[0x71] == 2) return 5;
    return t[0x70];
}

// FUNCTION: GAME 0x393C30
char *func_00393C30(char *a) { return a + 8; }

// FUNCTION: GAME 0x393F28
int func_00393F28(char *a) { return *(int *)(a + 0x58); }

// FUNCTION: GAME 0x39A998
int func_0039A998(void) { return 1; }

// FUNCTION: GAME 0x39ADC0
void func_0039ADC0(int *a) { a[3] = a[2]; }

// FUNCTION: GAME 0x39ADD0
void func_0039ADD0(int *a) { a[2] = a[3]; }

extern int func_003B63A0(void);
extern void func_003B63F0(void);
extern unsigned char *func_00397BC8_p(int a, int b, int c) __asm__("func_00397BC8");
extern void func_003B0510(unsigned char *a, unsigned char *b);
extern int func_003978C8(int a, int b);
struct Ent2 { int _0; char *m4; int _8[2]; int m10; int _14[2]; };
struct Grp2 { struct Ent2 e[4]; char _p[0x70 - 4 * 0x1C]; };
extern struct Grp2 D_0077C110_2[] __asm__("D_0077C110");

// FUNCTION: GAME 0x397E18
int func_00397E18(int g, int e, int v)
{
    int s;
    unsigned char *p;
    if (!D_0077C110_2[g].e[e].m10) return 0;
    s = func_003B63A0();
    p = func_00397BC8_p(g, e, 0);
    p[0x71] = v;
    func_003B0510(p, p + 0x7F);
    if (s == 1) func_003B63F0();
    return 1;
}


// FUNCTION: GAME 0x398128
int func_00398128(int g, int e, int src)
{
    unsigned char t[0x80];
    int i;
    func_00397BC8_b(g, e, t);
    if (t[0x72] != 1) return 0;
    {
        int *p = (int *)D_0077C110_2[g].e[e].m4;
        char *d = (char *)p + 0xC;
        for (i = 0; i < 6; i++) d[i] = ((char *)src)[i];
        src = 1;
        p[1] = 1;
        p[2] = 6;
        if (func_003978C8(g, e) != 1) src = 0;
        return src;
    }
}

