// Units in .text 0x150000-0x16FFFF.

struct Pair8 {
    int v0, v1;
};
extern "C" int func_0015FD68(void *p);
// DRAFT: GAME 0x15FCB8
// diff: 10 words; original branches bltz to the return-0 tail and stores through two copies of the entry pointer (a0 and v1); compiled uses bgez/b.
#ifdef NONMATCHING
extern "C" int func_0015FCB8(Pair8 *self, int a, int b)
{
    int i = func_0015FD68(self);
    int r;
    if (i < 0) {
        r = 0;
    } else {
        Pair8 *e = self + i;
        e->v0 = b;
        e->v1 = a;
        r = 1;
    }
    return r;
}
#endif

struct Pool150 {
    char _pad[0x1C];
    unsigned cur;
    char _pad2[4];
    unsigned low;
};
extern "C" void *func_002A97A0(void *p);
extern "C" void func_003A52F0(void *p, int v, int n);
extern "C" int func_0014FF80(void *p);
// FUNCTION: GAME 0x150538
extern "C" int func_00150538(Pool150 *self)
{
    void *e = func_002A97A0(self);
    if (!e)
        return 0;
    unsigned c = self->cur - 1;
    self->cur = c;
    if (c < self->low)
        self->low = c;
    func_003A52F0(e, 0, 0x220);
    return func_0014FF80(e);
}

extern const char D_00420070[];
extern const char D_00420158[];
extern const char D_00420240[];
extern char g_DmgManage[];
extern char EspSys[];
extern "C" void func_001FE278(void *mgr, void *p);
extern "C" void effDataRelease__6espSys12eEffDataType(void *sys, int t);
extern "C" void func_001C2820(void *self, int a);
// FUNCTION: GAME 0x16F438
extern "C" void func_0016F438(char *self, int a)
{
    *(const void **)(self + 0x214) = D_00420070;
    void *p = *(void **)(self + 0x600);
    if (p) {
        func_001FE278(g_DmgManage, p);
        *(void **)(self + 0x600) = 0;
    }
    effDataRelease__6espSys12eEffDataType(EspSys, 0x258);
    func_001C2820(self, a);
}

// FUNCTION: GAME 0x16F720
extern "C" void func_0016F720(char *self, int a)
{
    *(const void **)(self + 0x214) = D_00420158;
    void *p = *(void **)(self + 0x600);
    if (p) {
        func_001FE278(g_DmgManage, p);
        *(void **)(self + 0x600) = 0;
    }
    effDataRelease__6espSys12eEffDataType(EspSys, 0x259);
    func_001C2820(self, a);
}

// FUNCTION: GAME 0x16FA10
extern "C" void func_0016FA10(char *self, int a)
{
    *(const void **)(self + 0x214) = D_00420240;
    void *p = *(void **)(self + 0x600);
    if (p) {
        func_001FE278(g_DmgManage, p);
        *(void **)(self + 0x600) = 0;
    }
    effDataRelease__6espSys12eEffDataType(EspSys, 0x25A);
    func_001C2820(self, a);
}

extern char Snd[];
extern "C" void func_002CBA48(void *snd, int a, int b, void *c, int d, int e, int f, int g);
// FUNCTION: GAME 0x16FEA0
extern "C" void func_0016FEA0(void *self)
{
    func_002CBA48(Snd, 2, 0, self, 0, 0, 0, 0);
    func_002CBA48(Snd, 2, 2, self, 0, 0, 0, 0);
}

extern "C" void func_001641B8(char *self);
extern "C" void func_00164238(void *p);
extern "C" void func_001643F8(void *p);
// FUNCTION: GAME 0x164140
extern "C" void func_00164140(char *self)
{
    switch ((unsigned char)self[0x64]) {
    case 0:
        func_001641B8(self);
        break;
    case 1:
        func_00164238(self);
        break;
    case 2:
    case 3:
        func_001643F8(self);
        break;
    }
}

extern char Sys[];
extern "C" void func_002CB8A0(void *snd, int a, int b, int c, int d, int e, int f);
// DRAFT: GAME 0x1641B8
// diff: 2 words; the -1 stored to self+0x60 is in v1 in the original, v0 in the compiled output.
#ifdef NONMATCHING
extern "C" void func_001641B8(char *self)
{
    char *g = Sys;
    if (*(long *)(g + 0x1A0) & 0x20000000)
        *(int *)(self + 0x60) = 10;
    if (*(long *)(g + 0x1A0) & 0x200000) {
        func_002CB8A0(Snd, 0, 0x161, -1, -1, 0, 0);
        *(int *)(self + 0x60) = -1;
    }
}
#endif

struct MeshHdr {
    char _pad[0x14];
    unsigned short n;
};
struct MeshBase {
    char _pad[0x20];
    int off[1];
};
// DRAFT: GAME 0x1551E0
// diff: 23 words; original divides by a variable 0x18 (a2) with break check, a second 0x18 check before mul by 0x90, bnez-skip for q++; compiled folds to movz. 0x1552F0 is the same unit with 0x70.
#ifdef NONMATCHING
extern "C" int func_001551E0(char *self, int i)
{
    MeshBase *b = *(MeshBase **)(self + 0x388);
    MeshHdr *h = (MeshHdr *)((char *)b + b->off[i]);
    MeshBase *volatile k0 = b;
    MeshHdr *volatile k1 = h;
    (void)k0;
    (void)k1;
    int n = h->n;
    int d = 0x18;
    int q = n / d;
    if (n % d)
        q++;
    int m = 0x90;
    return q * m + 0x10;
}

#endif

struct Tab8 {
    unsigned lo, hi;
};
extern Tab8 D_004A5D80[];
// DRAFT: GAME 0x155BE8
// diff: 25 words; semantics match (64-bit pack of two table words), but scheduling/reg choice differ and compiled is 4 bytes longer (original reuses v0 for 0x10000000 in both paths).
#ifdef NONMATCHING
extern "C" void func_00155BE8(char **self, int idx, int slot)
{
    char *o = self[slot + 0x88];
    if (idx >= 0) {
        Tab8 *t = &D_004A5D80[idx & 0xFF];
        unsigned a = t->hi | 0x30000000;
        unsigned b = t->lo & 0x0FFFFFFF;
        *(long *)(o + 0x50) = ((long)b << 32) | (long)a;
        *(long *)(o + 0x60) = 0x10000000;
    } else {
        *(long *)(o + 0x50) = 0x10000000;
        *(long *)(o + 0x60) = 0x10000000;
    }
}
#endif

extern "C" void func_00157568(void *p);
extern "C" void func_00157C18(void *p);
// FUNCTION: GAME 0x1582A0
extern "C" void func_001582A0(char *self, int a, int b, float f, int pad, unsigned short flags)
{
    float c;
    if (*(int *)(self + 0x428) != a || *(int *)(self + 0x42C) != b || (c = *(float *)(self + 0x440), !((flags & 4) ? (c == -f) : (c == f))))
        func_00157568(self);
    func_00157C18(self);
}

struct V4f {
    float x, y, z, w;
};
extern "C" void func_001B6FB8(void *self);
extern "C" void *func_001FE218(void *mgr, void *self, int kind);
extern "C" void func_001FDC00(void *e, void *at, V4f *a, V4f *b, float s, float t);
extern "C" void func_001C28A0(void *self);
// DRAFT: GAME 0x16FD68
// diff: 8-10 words; calls/vectors/branch match, only the tail halfword/byte store order and v0/v1 choice for 0x620/6 differ (scheduler).
#ifdef NONMATCHING
extern "C" int func_0016FD68(char *self)
{
    V4f a, b;
    func_001B6FB8(self);
    a.x = 0;
    a.y = 0;
    a.z = 0;
    a.w = 1.0f;
    void *e = func_001FE218(g_DmgManage, self, 2);
    *(void **)(self + 0x600) = e;
    if (e) {
        V4f *q = &b;
        b.x = 0;
        b.y = 0;
        b.z = 0;
        q->w = 1.0f;
        func_001FDC00(e, self + 0x80, &a, q, 3.0f, 0.8f);
    }
    char *p = self + 0x620;
    *(int *)(self + 0x5E8) = 0;
    *(int *)(self + 0x5E4) = 0;
    *(int *)(self + 0x5F0) = 0;
    *(int *)(self + 0x5EC) = 0;
    *(short *)(self + 0x54A) = 1;
    *(char *)(self + 0x60C) = 6;
    *(short *)(self + 0x5F6) = -1;
    *(short *)(self + 0x548) = 1;
    *(short *)(self + 0x5F4) = -1;
    *(char **)(self + 0x608) = p;
    func_001C28A0(self);
    return 1;
}
#endif
