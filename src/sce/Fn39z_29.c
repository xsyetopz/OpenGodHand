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
