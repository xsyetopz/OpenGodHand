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
    F(self, 0x2D4) = F(self, 0x2D0);
    F(self, 0x2BC) = F(self, 0x2B4);
    return 1;
}
