// Small unnamed functions in 0x2E0000-0x2EFFFF, placed next to ESLib.
// Objects are local structs: a vtable pointer sits at 0xF0.

struct cObj;
void ReleaseObj(cObj *obj);

struct EsObj {
    char pad0[0xF0];
    const void *vt;
};

struct EsObjB2 : EsObj {
    char pad1[0x2B0 - 0xF4];
    cObj *m_obj;
};

extern "C" {
void func_002DF950(int, int);
void func_002FBE28(EsObj *, ...);
EsObj *func_002FBCC8(EsObj *);
void func_002FBED0(EsObj *);
void func_002FEB18(EsObj *);
void func_002EBC50(EsObj *);
void func_00300148();
void func_0031EEA8(void *, const void *, const void *);
}

#define VT_SET(addr, vtsym, callee)                         \
    extern "C" const char vtsym[];                          \
    extern "C" void func_00##addr(EsObj *self)              \
    {                                                       \
        self->vt = vtsym;                                   \
        callee(self);                                       \
    }

#define VT_AFTER(addr, vtsym)                               \
    extern "C" const char vtsym[];                          \
    extern "C" EsObj *func_00##addr(EsObj *self)            \
    {                                                       \
        func_002FBCC8(self);                                \
        self->vt = vtsym;                                   \
        return self;                                        \
    }

#define TAIL(addr, callee)                                  \
    extern "C" void func_00##addr(EsObj *self)              \
    {                                                       \
        callee(self);                                       \
    }

#define SINGLETON(addr, obj, vtsym, init)                   \
    extern "C" int obj[];                                   \
    extern "C" const char vtsym[];                          \
    extern "C" const char D_007863C8[];                     \
    extern "C" void *func_00##addr()                        \
    {                                                       \
        if (obj[0] == 0) {                                  \
            init();                                         \
            func_0031EEA8(obj, vtsym, D_007863C8);          \
        }                                                   \
        return obj;                                         \
    }

// FUNCTION: GAME 0x2E0AB8
extern "C" void func_002E0AB8()
{
    func_002DF950(1, 0xFFFF);
}

// FUNCTION: GAME 0x2E0AD8
extern "C" int func_002E0AD8()
{
    return 1;
}

// FUNCTION: GAME 0x2EFB40
extern "C" int func_002EFB40()
{
    return 1;
}

extern "C" unsigned char D_0061B289;
extern "C" int DISPLAY_H;

// FUNCTION: GAME 0x2E0AE0
extern "C" int func_002E0AE0(int x)
{
    int m = D_0061B289;
    if (x < -m)
        return 1;
    return DISPLAY_H * 2 + m < x;
}

// FUNCTION: GAME 0x2E16B0
VT_SET(2E16B0, D_0044E090, func_002FBE28)
// FUNCTION: GAME 0x2E3458
VT_SET(2E3458, D_0044E238, func_002FBE28)
// FUNCTION: GAME 0x2E9B40
VT_SET(2E9B40, D_0044E6D8, func_002FBE28)
// FUNCTION: GAME 0x2EA8E0
VT_SET(2EA8E0, D_0044E770, func_002FBE28)
// 0x2EBC20: not a unit start; the unit begins with an 8-byte fragment of the previous function.
// 0x2EFC78: not a unit start; the unit begins with an 8-byte fragment of the previous function.
// FUNCTION: GAME 0x2EBF70
VT_SET(2EBF70, D_0044E8C8, func_002EBC50)

// FUNCTION: GAME 0x2E81D8
VT_AFTER(2E81D8, D_0044E6D8)
// FUNCTION: GAME 0x2E9B68
VT_AFTER(2E9B68, D_0044E770)

// FUNCTION: GAME 0x2E1710
TAIL(2E1710, func_002FBED0)
// FUNCTION: GAME 0x2E82F8
TAIL(2E82F8, func_002FBED0)
// FUNCTION: GAME 0x2EFB48
TAIL(2EFB48, func_002FBED0)
// FUNCTION: GAME 0x2E28D0
TAIL(2E28D0, func_002FEB18)

// FUNCTION: GAME 0x2E2558
SINGLETON(2E2558, D_007863B8, D_0044E120, func_00300148)
// FUNCTION: GAME 0x2E3408
SINGLETON(2E3408, D_007863D8, D_0044E2C8, func_00300148)
// FUNCTION: GAME 0x2E76A0
SINGLETON(2E76A0, D_00786408, D_0044E5C8, func_00300148)
// FUNCTION: GAME 0x2E7FE8
SINGLETON(2E7FE8, D_00786418, D_0044E6D0, func_00300148)
// FUNCTION: GAME 0x2E9AF0
SINGLETON(2E9AF0, D_00786428, D_0044E768, func_00300148)
// FUNCTION: GAME 0x2EA890
SINGLETON(2EA890, D_00786438, D_0044E800, func_00300148)
// FUNCTION: GAME 0x2EBBD0
SINGLETON(2EBBD0, D_00786448, D_0044E8B0, func_00300148)
// FUNCTION: GAME 0x2EFC28
SINGLETON(2EFC28, D_00786468, D_0044EAA0, func_00300148)

struct EsObjSrc {
    char pad[0x13C];
    float f13C, f140, f144, f148;
    char pad2[0x16C - 0x14C];
    int i16C;
};

struct EsObjCopy {
    char pad[0x110];
    EsObjSrc *src;
    char pad2[0x2B0 - 0x114];
    float f2B0, f2B4, f2B8, f2BC;
    int i2C0;
};

// FUNCTION: GAME 0x2E16D8
extern "C" int func_002E16D8(EsObjCopy *self)
{
    EsObjSrc *s = self->src;
    self->f2B0 = s->f13C;
    self->f2B4 = s->f140;
    self->f2B8 = s->f144;
    self->f2BC = s->f148;
    self->i2C0 = s->i16C;
    return 1;
}

struct EsObjFlag {
    char pad[0x11C];
    unsigned int flags;
    char pad2[0x2CB - 0x120];
    unsigned char b2CB;
};

// FUNCTION: GAME 0x2E7FA8
extern "C" void func_002E7FA8(EsObjFlag *self)
{
    if (!(self->flags & 0x800000) && self->b2CB)
        func_002FEB18((EsObj *)self);
}

// FUNCTION: GAME 0x2E6368
extern "C" const char D_0044E538[];
extern "C" void func_002E6368(EsObjB2 *self, int a1)
{
    self->vt = D_0044E538;
    if (self->m_obj)
        ReleaseObj(self->m_obj);
    func_002FBE28(self, a1);
}

struct ESLib {
    static float ESHermite(float t, float p0, float p1, float m0, float m1);
    static float ESCatMullRom(float t, float p0, float p1, float p2, float p3);
};

// FUNCTION: GAME 0x2E1528
float ESLib::ESHermite(float t, float p0, float p1, float m0, float m1)
{
    float t2 = t * t;
    float t3 = t2 * t;
    float b = t2 * 3.0f;
    float t3x2 = t3 + t3;
    float h11 = t3 - t2;
    float a = t3x2 - b;
    float h01 = -t3x2 + b;
    float h10 = h11 - t2 + t;
    return a * p0 + p0 + p1 * h01 + m0 * h10 + m1 * h11;
}

struct CatMat {
    float m[16];
};
extern "C" void sceVu0ApplyMatrix(float *, CatMat *, float *);
extern "C" const CatMat D_0044E050;

// FUNCTION: GAME 0x2E1580
float ESLib::ESCatMullRom(float t, float p0, float p1, float p2, float p3)
{
    CatMat m = D_0044E050;
    float v[4];
    float *p = v;
    v[0] = t * t * t;
    v[1] = t * t;
    v[2] = t;
    p[3] = 1.0f;
    sceVu0ApplyMatrix(p, &m, p);
    return p0 * v[0] + p1 * v[1] + p2 * v[2] + p3 * v[3];
}

struct EsObjInit : EsObj {
    char pad1[0x2B0 - 0xF4];
    int i2B0, i2B4, i2B8, i2BC, i2C0, i2C4, i2C8;
    char pad2[0x2D4 - 0x2CC];
    float f2D4;
    int i2D8, i2DC;
    char pad3[0x30C - 0x2E0];
    int i30C;
    char pad4[0x324 - 0x310];
    int i324;
    char pad5[0x330 - 0x328];
    int i330, i334, i338, i33C;
};



extern "C" const char D_0044E300[];
extern "C" const char D_0044E8C8[];
// FUNCTION: GAME 0x2E3480
extern "C" EsObjInit *func_002E3480(EsObjInit *self)
{
    func_002FBCC8(self);
    self->f2D4 = 1.0f;
    self->vt = D_0044E300;
    self->i2B0 = 0;
    self->i2B4 = 0;
    self->i2B8 = 0;
    self->i2C0 = 0;
    self->i2C4 = 0;
    self->i2C8 = 0;
    self->i2D8 = 0;
    self->i2DC = 0;
    self->i2BC = 0;
    self->i30C = 0;
    self->i324 = 0;
    self->i330 = 0;
    self->i334 = 0;
    self->i338 = 0;
    self->i33C = 0;
    return self;
}

// FUNCTION: GAME 0x2EBF08
extern "C" EsObjInit *func_002EBF08(EsObjInit *self)
{
    func_002FBCC8(self);
    self->f2D4 = 1.0f;
    self->vt = D_0044E8C8;
    self->i2B0 = 0;
    self->i2B4 = 0;
    self->i2B8 = 0;
    self->i2BC = 0;
    self->i2C0 = 0;
    self->i2C4 = 0;
    self->i2C8 = 0;
    self->i2D8 = 0;
    self->i2DC = 0;
    return self;
}

struct EsFlagObj {
    char pad[0x250];
    unsigned int flags;
};

struct EsFlagCopy {
    char pad[0x114];
    EsFlagObj *src;
    char pad2[0x2B0 - 0x118];
    EsFlagObj *dst;
};

// FUNCTION: GAME 0x2E6AF8
extern "C" void func_002E6AF8(EsFlagCopy *self)
{
    if (self->src) {
        if (self->src->flags & 2)
            self->dst->flags |= 2;
        else
            self->dst->flags &= ~2;
        if (self->src->flags & 0x8000)
            self->dst->flags |= 0x8000;
        else
            self->dst->flags &= ~0x8000;
    }
}

extern "C" int DISPLAY_W;
extern "C" unsigned char D_0061B288;
extern "C" char D_0061B298[];

// FUNCTION: GAME 0x2E0B18
extern "C" int func_002E0B18(int x, int n)
{
    if (x >= DISPLAY_W)
        return 1;
    int d = DISPLAY_W - x;
    int u = D_0061B288;
    if (d < n * u) {
        int idx = d / u;
        if (idx < 0)
            return 1;
        D_0061B298[idx] = 0;
    }
    return 0;
}

// FUNCTION: GAME 0x2E12D8
extern "C" int func_002E12D8(signed char c)
{
    switch (c) {
    case 1:
        return 0x7D;
    case 2:
        return 0x60;
    case 3:
        return 0x7C;
    case 4:
        return 0x7B;
    }
    return c;
}

struct cHeap;
void *_MemoryAlloc(unsigned int, unsigned int, cHeap &);
struct EsGlobal {
    char pad[8];
    unsigned char b8, b9;
    unsigned short sA;
    char pad2[0x14 - 0xC];
    void *p14;
};
extern "C" EsGlobal D_0061B280;
extern "C" cHeap D_00754200;
extern "C" unsigned int D_00747A34;
extern "C" char D_00580D40[];
extern "C" const char D_0044E030[];
extern "C" const char D_0044E040[];
extern "C" void func_001FFD00(const char *, const char *);

// 0x2E1348: near-miss, 20 words differ (136 vs 144 bytes). Store scheduling and the
// branch layout differ; the original keeps the alloc result in $a2 across the test.
#ifdef NONMATCHING
extern "C" void func_002E1348()
{
    D_0061B280.b9 = 8;
    D_0061B280.sA = 0;
    D_0061B280.b8 = 8;
    void *p = _MemoryAlloc(0x1000, 0x40, D_00754200);
    D_0061B280.p14 = p;
    if (!(D_00747A34 & 0x4000))
        func_001FFD00(D_00580D40, D_0044E030);
    else
        func_001FFD00(D_00580D40, D_0044E040);
}
#endif
