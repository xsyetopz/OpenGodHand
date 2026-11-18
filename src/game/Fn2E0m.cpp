// Mid-size unnamed units in 0x2E0000-0x2FFFFF.
extern char D_0061B7C0[];
extern unsigned D_0071B7C0[], D_0071B840[], D_0071B8C0[];
extern char EspSys[];
extern int D_0061B674, D_003C3BB4;
extern char D_0061B670, D_003C3BB0;
extern char D_0044EC08[], D_0044EC28[];
extern "C" int *func_00306030(char *, int, int);
extern "C" void func_002D9F68(void *, const char *, ...);

// FUNCTION: GAME 0x2FB060
extern "C" int func_002FB060(char *p)
{
    unsigned d = p - D_0061B7C0;
    unsigned i = d >> 10;
    if (i >= 0x400)
        return 0;
    unsigned w = d >> 15;
    unsigned bit = 0x80000000u >> (i & 0x1F);
    if (!(D_0071B7C0[w] & bit))
        return 0;
    if (D_0071B840[w] & bit)
        return 0;
    return (D_0071B8C0[w] & bit) == 0;
}

// FUNCTION: GAME 0x2F11F0
extern "C" int func_002F11F0(char *self)
{
    char *o = *(char **)(self + 0x110);
    *(int *)(self + 0x2B0) = *(unsigned char *)(o + 0x16C);
    *(int *)(self + 0x2B4) = *(unsigned char *)(o + 0x170);
    D_0061B674 = *(int *)(o + 0x174);
    int *r = func_00306030(EspSys, *(int *)(self + 0x2B0), *(int *)(self + 0x2B4) + 1);
    if (!r) {
        func_002D9F68(self, D_0044EC08, *(int *)(self + 0x2B0), *(int *)(self + 0x2B4));
        return 0;
    }
    if (*r != 0x545345) {
        func_002D9F68(self, D_0044EC28, *(int *)(self + 0x2B0), *(int *)(self + 0x2B4));
        return 0;
    }
    D_003C3BB0 = 0;
    D_003C3BB4 = 0;
    D_0061B674 = 0;
    D_0061B670 = 0;
    return 1;
}

extern char D_0044EB50[];
#define F(p, o) (*(float *)((p) + (o)))

// FUNCTION: GAME 0x2F00E0
extern "C" int func_002F00E0(char *self)
{
    char *o = *(char **)(self + 0x110);
    F(self, 0x2B0) = F(o, 0x13C) * 0.01f;
    F(self, 0x2B4) = F(o, 0x140) * 0.01f;
    F(self, 0x2D0) = F(o, 0x144) * 0.01f;
    F(self, 0x2C8) = F(o, 0x148) * 0.1f;
    F(self, 0x2CC) = F(o, 0x14C) * 0.1f;
    F(self, 0x2DC) = F(o, 0x150) * 0.1f;
    *(unsigned char *)(self + 0x2E0) = *(unsigned char *)(o + 0x18C);
    *(unsigned char *)(self + 0x2E1) = *(unsigned char *)(o + 0x18D);
    *(unsigned char *)(self + 0x2E2) = *(unsigned char *)(o + 0x18E);
    if (!(*(unsigned char *)(self + 0x2E0) < 3))
        func_002D9F68(self, D_0044EB50, *(unsigned char *)(self + 0x2E0));
    F(self, 0x2B8) = F(self, 0x2B0);
    F(self, 0x2BC) = F(self, 0x2B4);
    F(self, 0x2D4) = F(self, 0x2D0);
    return 1;
}

extern int D_00741DB8;
extern "C" void *func_002B5E50();
extern "C" void func_002FBFB0(void *);
extern "C" void func_002FBE50(void *);

// FUNCTION: GAME 0x2FBED0
extern "C" void func_002FBED0(char *self)
{
    if (func_002B5E50() && *(char **)(self + 0x114) && *(int *)(*(char **)(self + 0x114) + 0x250) < 0)
        func_002FBE50(self);
    func_002FBFB0(self);
    if (*(unsigned *)(*(char **)(self + 0x110) + 4) & 0x800) {
        if (!D_00741DB8)
            *(unsigned *)(self + 0x11C) |= 0x800000;
        else
            *(unsigned *)(self + 0x11C) &= 0xFF7FFFFF;
    }
    if (*(unsigned *)(*(char **)(self + 0x110) + 4) & 0x400) {
        if (D_00741DB8)
            *(unsigned *)(self + 0x11C) |= 0x800000;
        else
            *(unsigned *)(self + 0x11C) &= 0xFF7FFFFF;
    }
}

struct Qv2 { float f[4]; };
extern char D_0044FAD0[];
extern "C" void *func_002FBD98(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x2FBCC8 (6 words off: store order of 0x240/0x246/0x210/0x23E/0x23F/0x245; rotation tried, no change)
extern "C" void *func_002FBCC8(void *p)
{
    char *self = (char *)p;
    func_002FBD98(self);
    *(char **)(self + 0xF0) = D_0044FAD0;
    float *v = (float *)(self + 0x188);
    float *u = (float *)(self + 0x1F8);
    v[0] = 1.0f;
    v[1] = 1.0f;
    v[2] = 1.0f;
    v[3] = 1.0f;
    u[0] = 1.0f;
    u[1] = 1.0f;
    u[2] = 1.0f;
    u[3] = 1.0f;
    *(short *)(self + 0x238) = -1;
    *(char *)(self + 0x246) = 1;
    F(self, 0x210) = 1.0f;
    *(char *)(self + 0x23E) = 1;
    *(char *)(self + 0x23F) = 1;
    *(char *)(self + 0x245) = 1;
    F(self, 0x240) = 1.0f;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv2 *)(self + 0x280)));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv2 *)(self + 0x290)));
    *(unsigned *)(self + 0x11C) |= 0x4000000;
    *(unsigned *)(self + 0x11C) |= 0x2000000;
    *(int *)(self + 0x280) = 0;
    *(int *)(self + 0x284) = 0;
    *(int *)(self + 0x288) = 0;
    *(int *)(self + 0x290) = 0;
    *(int *)(self + 0x294) = 0;
    *(int *)(self + 0x298) = 0;
    *(char *)(self + 0x2A1) = 0;
    *(char *)(self + 0x2A0) = 0;
    *(short *)(self + 0x276) = 0;
    return self;
}
#endif

typedef int TI128 __attribute__((mode(TI)));
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);
extern "C" void sceVu0DivVector(float *, float *, float);
extern "C" void func_0030A570(int *, float *);

#ifdef NONMATCHING
// DRAFT: GAME 0x2FDDA8 (4 words off: the -1 constant load is hoisted above the lw instead of after it; tried early returns, r=-1 temp, ternary forms, no change)
extern "C" int func_002FDDA8(float *m, int *out)
{
    float v[4] __attribute__((aligned(16)));
    float u[4] __attribute__((aligned(16)));
    int s[4] __attribute__((aligned(16)));
    *(TI128 *)u = 0;
    u[3] = 1.0f;
    sceVu0ApplyMatrix(v, m, u);
    float w = v[3];
    *out = (int)(w * 10.0f) + 50;
    sceVu0DivVector(v, v, w);
    func_0030A570(s, v);
    if (s[2] >= 0 && (unsigned)(s[0] - 0xA0) <= 0xFEC0) {
        unsigned char bad = (unsigned)(s[1] - 0xA0) > 0xFEC0;
        return bad ? -1 : 0;
    }
    return -1;
}
#endif
