// More small functions from 0x2C0000-0x2D0000.
extern "C" void func_002CE488(char *a, int b);
extern "C" int *GetSeData__4cSndi(char *a, int b);
extern "C" void func_002CB7E8(char *a, int b);
extern "C" void func_0030F5A0(char *a);
extern "C" void func_002C0038(char *a);
extern "C" void func_002CE510(char *a, short b, int c);
extern "C" int func_002CDA38(char *a);
extern "C" void func_00375050(int a, int b);
extern "C" void func_002CE3E8(char *a);
extern "C" void *Getplayer__Fv(void);
extern "C" void func_002C8AD8(char *a);
extern "C" void func_002CF310(char *a);
extern "C" char *func_003A54D8(char *s, int c);
extern "C" int func_002CF600(char *a, int b, char *c);
extern "C" int func_002CFC78(char *a);
extern "C" int func_002CFC88(char *a);
extern "C" void func_002CD740(char *a);
extern "C" void SeFadeOut__4cSnd6eSndIds(char *a, int b, short c);
extern "C" void *memset(void *, int, unsigned long);
extern int D_00747A2C;
extern int D_0044CE48[];
extern "C" int *func_002CD8F8(char *a, int b);
extern "C" int func_002C38D8(char *g, int a, int b, int c);
extern "C" int func_00373A58(char *a);
extern "C" void func_003734F0(char *a);
extern "C" void func_003735E0(char *a, int b, float x, float y);
extern "C" int func_002CDA38(char *a);
extern "C" void func_002CE3E8(char *a);
extern "C" int func_002CD7C8(char *a, int b);
extern "C" void func_002CFE68(char *a, int b, int c, char *d);
struct SceEnt {
    int a, b;
};
struct SceHost {
    char pad[0x58];
    SceEnt e[1];
};
extern SceHost *g_Sce;
extern char g_SceAt[];
extern char *g_SaveManager;
extern char *CoreSave;
extern unsigned D_00747A24;

// FUNCTION: GAME 0x2C2418
extern "C" int func_002C2418(char *u, unsigned flags)
{
    char *g = g_SceAt;
    if (*(int *)(g + 0x70) == 0) {
        if (flags & 0x10) {
            *(char **)(g + 0x70) = u + 0x5C;
            g[0x64] = u[0x7C];
        } else if (flags & 0x20) {
            g[0x64] = u[0x7D];
        } else {
            *(char **)(g + 0x70) = u + 0x5C;
        }
    }
    return 0;
}

// FUNCTION: GAME 0x2CBE18
extern "C" void func_002CBE18(char *self, int a)
{
    for (char *n = *(char **)(self + 0x1C); n; n = *(char **)(n + 4))
        func_002CE488(n, a);
}

// FUNCTION: GAME 0x2CB340
extern "C" void func_002CB340(char *self, int id)
{
    int *se = GetSeData__4cSndi(self, id);
    if ((unsigned)(se[0x3C / 4] - 0x200) < 0x100)
        func_002CB7E8(self, id);
    else
        func_002CB7E8(self, id);
}

// FUNCTION: GAME 0x2C1270
extern "C" void func_002C1270(char *self)
{
    char **p = (char **)(self + 0x74);
    unsigned i = 0;
    do {
        i++;
        if (*p) {
            func_0030F5A0(*p);
            *p = 0;
        }
        p++;
    } while (i < 8);
}

// FUNCTION: GAME 0x2C4A18
extern "C" void endCasinoBattle__9cScenario(void)
{
    func_002C0038(g_SaveManager);
    D_00747A24 &= 0xF7FFFFFF;
    *(unsigned *)(CoreSave + 0x14) &= 0xFBFFFFFF;
}

// FUNCTION: GAME 0x2C53C8
extern "C" void move__9cScrArray(char *self)
{
    int n = *(int *)(self + 8);
    if (n > 0) {
        if (*(unsigned char *)(self + 4)) {
            int c = *(int *)(self + 0xC) + 1;
            *(int *)(self + 0xC) = c;
            if (c < n)
                return;
        } else {
            int c = *(int *)(self + 0xC) - 1;
            *(int *)(self + 0xC) = c;
            if (c >= 0)
                return;
        }
        *(int *)(self + 8) = 0;
        *(int *)(self + 0xC) = 0;
    }
}

// FUNCTION: GAME 0x2CBE68
extern "C" void func_002CBE68(char *self, int a, int b)
{
    for (char *n = *(char **)(self + 0x1C); n; n = *(char **)(n + 4))
        func_002CE510(n, a, b);
}

// FUNCTION: GAME 0x2CE430
extern "C" void func_002CE430(char *self)
{
    if (func_002CDA38(self)) {
        if (*(unsigned *)(self + 0xC) & 1)
            func_00375050(*(int *)(self + 0x14), 0);
        else
            func_002CE3E8(self);
    }
}

// FUNCTION: GAME 0x2CB128
extern "C" void func_002CB128(char *self)
{
    if (D_00747A2C >= 0 && *(int *)(self + 0x28) && *(int *)(self + 0x2C) && Getplayer__Fv()) {
        char *n = *(char **)(self + 0x2C);
        do {
            func_002C8AD8(n);
            n = *(char **)n;
        } while (n);
    }
}

// FUNCTION: GAME 0x2CB208
extern "C" void func_002CB208(char *self)
{
    int *p = D_0044CE48;
    unsigned i = 0;
    do {
        func_002CB7E8(self, *p);
        i++;
        func_002CF310((char *)GetSeData__4cSndi(self, *p));
        p++;
    } while (i < 12);
}

// FUNCTION: GAME 0x2CB830
extern "C" int func_002CB830(char *self, int id)
{
    int r = 1;
    if (func_002CFC78((char *)GetSeData__4cSndi(self, id)) == 1)
        return 1;
    if (func_002CFC88((char *)GetSeData__4cSndi(self, id)))
        r = 0;
    return r;
}

// FUNCTION: GAME 0x2CD668
extern "C" void func_002CD668(char *self, int a, int b)
{
    *(char **)(self + 0x380) = self;
    memset(self, 0, 0x380);
    *(int *)(self + 0x384) = b;
    func_002CD740(self);
    *(char **)(self + 0x38C) = self;
    *(int *)(self + 0x388) = 0;
    *(int *)(*(char **)(self + 0x380) + 0x10) = a;
}

// FUNCTION: GAME 0x2CA6B0
extern "C" void func_002CA6B0(char *self)
{
    for (char *n = *(char **)(self + 0x1C); n; n = *(char **)(n + 4)) {
        unsigned long f = *(int *)(n + 0xC);
        unsigned long b = (f >> 3) & 1;
        if (b)
            SeFadeOut__4cSnd6eSndIds(self, *(int *)(n + 0x14), 10);
    }
}

struct RingEnt {
    short a, b;
    int c;
};
struct RingHost {
    char pad[0x160];
    RingEnt e[16];
    int pos;
};

// FUNCTION: GAME 0x2CBDC0
extern "C" void func_002CBDC0(RingHost *self, short a, short b, int c)
{
    self->pos = (self->pos + 1) % 16;
    self->e[self->pos].a = a;
    self->e[self->pos].b = b;
    self->e[self->pos].c = c;
}

// FUNCTION: GAME 0x2CD890
extern "C" void func_002CD890(char *self, int key)
{
    if (!key)
        return;
    if (!*(int *)(self + 0x380))
        return;
    int *r = func_002CD8F8(self, key);
    int *p = (int *)r[1];
    p[2] = r[2];
    p[3] = p[3] + (r[6] + r[3]);
    if (r[2])
        ((int **)r[2])[1] = p;
    r[5] = 0;
}

// FUNCTION: GAME 0x2CB638
extern "C" void func_002CB638(char *self, int id, char *str)
{
    char *p = func_003A54D8(str, 0x2E);
    if (p)
        *p = 0;
    func_002CF600((char *)GetSeData__4cSndi(self, id), id, str);
}
