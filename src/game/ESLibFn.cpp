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
void func_002EBC50(EsObj *, int);
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
#define CALL1_EBC50(s) ((void (*)(EsObj *))func_002EBC50)(s)
VT_SET(2EBF70, D_0044E8C8, CALL1_EBC50)

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

struct cHeap {
    void free(void *);
};
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

// ---- medium units ----
struct EsSrcA {
    char pad[0x13C];
    float f13C, f140, f144;
    char pad1[0x150 - 0x148];
    float f150;
    char pad2[0x16C - 0x154];
    unsigned char b16C;
    char pad3[0x170 - 0x16D];
    unsigned char b170;
};

struct EsObjA {
    char pad[0x110];
    EsSrcA *src;
    char pad0[0x11C - 0x114];
    unsigned int flags;
    char pad1[0x2B0 - 0x120];
    float f2B0, f2B4, f2B8, f2BC;
    char pad2[0x2C8 - 0x2C0];
    float f2C8;
    unsigned char b2CC;
    char pad3;
    unsigned char b2CE;
    char pad4;
    float f2D0;
};

extern "C" unsigned char D_0061B644;

// 0x2E9BA0 NEAR-MISS: 13 words differ (field copy scheduling)
#ifdef NONMATCHING
extern "C" int func_002E9BA0(EsObjA *self)
{
    EsSrcA *s = self->src;
    self->flags &= ~0x1000000;
    float v = s->f144 * 0.01f;
    self->f2B0 = v;
    self->f2B4 = v;
    self->f2BC = s->f150 * 0.1f;
    self->f2C8 = s->f13C * 1000.0f;
    self->f2D0 = s->f140;
    self->b2CC = s->b16C;
    self->b2CE = s->b170 + 1;
    D_0061B644 = 0;
    return 1;
}
#endif

struct EsSrcB {
    char pad[0x16C];
    int i16C;
    unsigned char b170;
    char pad1[0x18C - 0x171];
    signed char b18C;
    unsigned char b18D, b18E, b18F, b190;
};

struct EsParamB {
    char pad[0x40];
    float f40;
};

struct EsObjB {
    char pad[0x110];
    EsSrcB *src;
    char pad0[0x2B0 - 0x114];
    int i2B0, i2B4, i2B8;
    unsigned short s2BC;
    unsigned char b2BE, b2BF, b2C0;
    char pad1[0x2C4 - 0x2C1];
    float f2C4;
};

// FUNCTION: GAME 0x2EFCA8
extern "C" int func_002EFCA8(EsObjB *self, EsParamB *p)
{
    self->f2C4 = p->f40;
    EsSrcB *s = self->src;
    self->i2B0 = s->i16C;
    self->i2B4 = s->b170;
    self->i2B8 = s->b18C;
    self->s2BC = s->b18D;
    self->b2BE = s->b18E;
    self->b2BF = s->b18F;
    self->b2C0 = s->b190;
    if ((unsigned int)self->i2B8 >= 2)
        return 0;
    if (self->b2BF >= 2)
        return 0;
    return self->b2C0 < 2;
}

struct EsObjC : EsObj {
    char pad1[0x2D8 - 0xF4];
    float f2D8, f2DC;
};

// FUNCTION: GAME 0x2EC310
extern "C" void func_002EC310(EsObjC *self)
{
    func_002FBED0(self);
    if (self->f2DC != 0.0f) {
        self->f2D8 += self->f2DC;
        if (self->f2D8 > 1.0f)
            self->f2D8 -= 1.0f;
        if (self->f2D8 < 0.0f)
            self->f2D8 += 1.0f;
    }
}

#define FREE_BLOCK(p) \
    if (p)            \
    (*(cHeap **)((char *)(p) - 0x20))->free(p)

struct EsObjD : EsObj {
    char pad1[0x2BC - 0xF4];
    void *p2BC, *p2C0, *p2C4, *p2C8, *p2CC, *p2D0;
};

extern "C" const char D_0044E960[];

// FUNCTION: GAME 0x2EBC50
extern "C" void func_002EBC50(EsObj *s, int a1)
{
    EsObjD *self = (EsObjD *)s;
    self->vt = D_0044E960;
    FREE_BLOCK(self->p2CC);
    FREE_BLOCK(self->p2D0);
    FREE_BLOCK(self->p2C4);
    FREE_BLOCK(self->p2C8);
    FREE_BLOCK(self->p2BC);
    FREE_BLOCK(self->p2C0);
    func_002FBE28(self, a1);
}

struct EsObjE : EsObj {
    char pad1[0x30C - 0xF4];
    void *p30C;
    char pad2[0x324 - 0x310];
    void *p324;
    char pad3[0x330 - 0x328];
    void *p330, *p334, *p338, *p33C;
};

// FUNCTION: GAME 0x2E3500
extern "C" void func_002E3500(EsObjE *self, int a1)
{
    self->vt = D_0044E300;
    FREE_BLOCK(self->p330);
    FREE_BLOCK(self->p334);
    FREE_BLOCK(self->p338);
    FREE_BLOCK(self->p33C);
    FREE_BLOCK(self->p324);
    FREE_BLOCK(self->p30C);
    func_002EBC50(self, a1);
}

extern "C" int D_0061B540[];

struct EsObjF {
    char pad[0x2BC];
    unsigned int n;
};

// FUNCTION: GAME 0x2E8168
extern "C" void func_002E8168(EsObjF *self, float step)
{
    D_0061B540[0] = 0;
    float f = 0.0f;
    for (unsigned int i = 1; i < self->n; i++) {
        if ((i & 1) == 0) {
            D_0061B540[i] = (int)-f;
        } else {
            D_0061B540[i] = (int)f;
            f += step;
        }
    }
}

extern "C" void func_002E2C50(EsObj *);
extern "C" void func_002E2D40(EsObj *);
extern "C" void func_002E2E00(EsObj *);
extern "C" void func_002FBE50(EsObj *);

struct EsObjG : EsObj {
    char pad1[0x24C - 0xF4];
    unsigned char b24C;
    char pad2[0x2C4 - 0x24D];
    int i2C4;
    char pad3[0x2CC - 0x2C8];
    unsigned int flags;
    char pad4[0x2D5 - 0x2D0];
    unsigned char b2D5;
};

// 0x2E2800 NEAR-MISS: ~20 words differ; original reloads flags after the byte store and shares the epilogue
#ifdef NONMATCHING
extern "C" void func_002E2800(EsObjG *self)
{
    func_002FBED0(self);
    if (!(*(unsigned char *)&self->flags & 1)) {
        switch ((unsigned int)self->i2C4) {
        case 0:
            func_002E2C50(self);
            break;
        case 1:
            func_002E2D40(self);
            break;
        case 2:
            func_002E2E00(self);
            break;
        default:
            func_002FBE50(self);
            break;
        }
    } else if (self->flags & 4) {
        self->b24C = self->b2D5 ? self->b2D5 : 30;
        self->flags &= ~4;
    }
}
#endif

struct EsObjJ : EsObj {
    char pad1[0x2B8 - 0xF4];
    float f2B8, f2BC, f2C0, f2C4;
};

// FUNCTION: GAME 0x2EA9F0
extern "C" void func_002EA9F0(EsObjJ *self)
{
    self->f2B8 += self->f2C0;
    self->f2BC += self->f2C4;
    if (self->f2B8 > 2.0f)
        self->f2B8 -= 2.0f;
    if (self->f2BC > 2.0f)
        self->f2BC -= 2.0f;
    if (self->f2B8 < -2.0f)
        self->f2B8 += 2.0f;
    if (self->f2BC < -2.0f)
        self->f2BC += 2.0f;
    func_002FBED0(self);
}

struct EsSrcK {
    char pad[0x13C];
    float f13C, f140;
    char pad1[0x18C - 0x144];
    signed char b18C, b18D, b18E;
    unsigned char b18F;
};

struct EsObjK {
    char pad[0x110];
    EsSrcK *src;
    char pad1[0x2B0 - 0x114];
    float f2B0, f2B4;
    int i2B8, i2BC;
    float f2C0, f2C4;
    int i2C8, i2CC;
};

extern "C" void func_002D9F68(void *, const char *);
extern "C" const char D_0044E808[];

// 0x2EA908 NEAR-MISS: 4 words differ; register choice $a2 vs $v1 for s->b18F
#ifdef NONMATCHING
extern "C" int func_002EA908(EsObjK *self)
{
    self->i2B8 = 0;
    self->i2BC = 0;
    EsSrcK *s = self->src;
    self->f2C0 = s->f13C * 0.1f;
    self->f2C4 = s->f140 * 0.1f;
    self->i2C8 = s->b18C + 2;
    self->f2B0 = (float)s->b18D * 0.1f + 1.0f;
    self->f2B4 = (float)s->b18E * 0.1f + 1.0f;
    unsigned int k = s->b18F;
    self->i2CC = k;
    if (k >= 4) {
        func_002D9F68(self, D_0044E808);
        self->i2CC = 0;
        return 0;
    }
    if (k != 0 && self->i2C8 == 2)
        self->i2C8 = 3;
    return 1;
}
#endif

extern "C" void func_002E9808(void *, int, int, int);
extern "C" void func_002E8B38(void *, int, int);
extern "C" void func_002E83D8(int, int, int, int, int);
extern "C" void func_002E8EE8(void *, int, int, int);

struct EsObjL {
    char pad[0x11C];
    unsigned int flags;
};

// FUNCTION: GAME 0x2E8318
extern "C" void func_002E8318(EsObjL *self)
{
    if (self->flags & 0x800000)
        return;
    func_002E9808(self, 4, 12, 2);
    func_002E9808(self, 4, 12, 1);
    func_002E9808(self, 4, 12, 0);
    func_002E8B38(self, 4, 11);
    func_002E83D8(10, 0x3B00, 0x3A00, 0, 1);
    func_002E83D8(10, 0x3A00, 0x3900, 1, 0);
    func_002E8EE8(self, 4, 9, 1);
}

// ---- 0x2F0000 range ----
// FUNCTION: GAME 0x2F0058
extern "C" void func_002F0058() {}
// FUNCTION: GAME 0x2F1750
extern "C" void func_002F1750() {}
// FUNCTION: GAME 0x2F4230
extern "C" void func_002F4230() {}
// FUNCTION: GAME 0x2F4B28
extern "C" void func_002F4B28() {}

// FUNCTION: GAME 0x2F00B8
VT_SET(2F00B8, D_0044EAB8, func_002FBE28)
// FUNCTION: GAME 0x2F11C8
VT_SET(2F11C8, D_0044EB70, func_002FBE28)
// FUNCTION: GAME 0x2F1B18
VT_SET(2F1B18, D_0044EC68, func_002FBE28)
// FUNCTION: GAME 0x2F2FF8
VT_SET(2F2FF8, D_0044EF08, func_002FBE28)
// FUNCTION: GAME 0x2F3E18
VT_SET(2F3E18, D_0044EFA0, func_002FBE28)
// FUNCTION: GAME 0x2F3E40
VT_SET(2F3E40, D_0044F078, func_002FBE28)

#define VT_NEW(addr, vtsym)                                 \
    extern "C" const char vtsym[];                          \
    extern "C" EsObj *func_00##addr(EsObj *self)            \
    {                                                       \
        if (self) {                                         \
            func_002FBCC8(self);                            \
            self->vt = vtsym;                               \
        }                                                   \
        return self;                                        \
    }
// FUNCTION: GAME 0x2F4DA0
VT_SET(2F4DA0, D_0044F270, func_002FBE28)
// FUNCTION: GAME 0x2F5328
VT_SET(2F5328, D_0044F308, func_002FBE28)
// FUNCTION: GAME 0x2F5560
VT_SET(2F5560, D_0044F3A0, func_002FBE28)
// FUNCTION: GAME 0x2F6CD0
VT_SET(2F6CD0, D_0044F598, func_002FBE28)
// FUNCTION: GAME 0x2F70E8
VT_SET(2F70E8, D_0044F630, func_002FBE28)
// FUNCTION: GAME 0x2F6230
VT_SET(2F6230, D_0044F4F8, CALL1_EBC50)
// FUNCTION: GAME 0x2F7178
VT_SET(2F7178, D_0044F6D8, CALL1_EBC50)
// FUNCTION: GAME 0x2FFCC8
VT_NEW(2FFCC8, D_0044EAB8)
// FUNCTION: GAME 0x2FFD08
VT_NEW(2FFD08, D_0044EB70)
// FUNCTION: GAME 0x2FFD48
VT_NEW(2FFD48, D_0044EC68)

// FUNCTION: GAME 0x2FFC88
VT_NEW(2FFC88, D_0044EA10)
// FUNCTION: GAME 0x2FFE10
VT_NEW(2FFE10, D_0044EFA0)
// FUNCTION: GAME 0x2FFE50
VT_NEW(2FFE50, D_0044F078)
// FUNCTION: GAME 0x2FFE90
VT_NEW(2FFE90, D_0044F1C8)
// FUNCTION: GAME 0x2FFED0
VT_NEW(2FFED0, D_0044F270)
// FUNCTION: GAME 0x2FFF50
VT_NEW(2FFF50, D_0044F3A0)
// FUNCTION: GAME 0x2FFC20
VT_NEW(2FFC20, D_0044E820)
struct EsObjZ : EsObj {
    char pad1[0x2B0 - 0xF4];
    int i2B0;
};
extern "C" const char D_0044EE38[];
// FUNCTION: GAME 0x2FFD88
extern "C" EsObj *func_002FFD88(EsObjZ *self)
{
    if (self) {
        func_002FBCC8(self);
        self->i2B0 = 0;
        self->vt = D_0044EE38;
    }
    return self;
}

// ---- destructor clones: store vptr, then `if (f & 1) delete` ----
extern "C" void func_0030F5A0(void *);

#define DTOR_CLONE(name, vtsym, off)                        \
    extern "C" char vtsym[];                                \
    extern "C" void name(char *p, int f)                    \
    {                                                       \
        *(char **)(p + off) = vtsym;                        \
        if (f & 1)                                          \
            func_0030F5A0(p);                               \
    }

// FUNCTION: GAME 0x2D9E30
DTOR_CLONE(func_002D9E30, D_0044D388, 0)
// FUNCTION: GAME 0x31F330
DTOR_CLONE(func_0031F330, D_00451288, 0)
// FUNCTION: GAME 0x31F3C8
DTOR_CLONE(func_0031F3C8, D_00451288, 0)
// FUNCTION: GAME 0x321818
DTOR_CLONE(func_00321818, D_00451288, 0)
// FUNCTION: GAME 0x3218B0
DTOR_CLONE(func_003218B0, D_00451288, 0)
// FUNCTION: GAME 0x1337E0
DTOR_CLONE(_$_21cCollisionScrollSolid, D_0041D5A8, 0x5C)
// FUNCTION: GAME 0x1339C0
DTOR_CLONE(_$_15cCollisionSolid, D_0041D808, 0x30)
// FUNCTION: GAME 0x2D5C38
DTOR_CLONE(func_002D5C38, D_0044D1C8, 0x30)

// 0x173AD8 near-miss (cluster of 6 identical 0x1D4 units; no COP2). See diff note below.
#ifdef NONMATCHING
#include "game/cVec.h"
#include "game/cObj.h"
#include "game/cDamageUnit.h"
#include "game/cDamageManage.h"

struct cV4 : cVec { float w; };

extern "C" {
void func_001B6FB8(void *);
void setMeshDispFromLayer__7cOmBaseUib(void *, unsigned, int);
}
extern cDamageManage g_DmgManage;

class Obj173AD8 : public cObj {
public:
    char _pad2F8[0x548 - 0x2F8];
    short m_s548;
    short m_s54A;
    char _pad54C[0x650 - 0x54C];
    cDamageUnit *m_take;
};

// DRAFT: GAME 0x173AD8
// Diff: prologue matches through 0x173BB4 (frame 0x90 vs 0x80); the rest differs. The original keeps a second
// copy of i (a3) for the `i >= lo` test and spills partsNum to 0x10($sp); mine uses 0x40($sp) and a single i.
extern "C" int func_00173AD8(Obj173AD8 *self)
{
    func_001B6FB8(self);
    cV4 a, b;
    cV4 c, d;
    cV4 *pc = &c;
    a.x = 1.02f; a.y = 1.288f; a.z = 1.02f; a.w = 1.0f;
    b.x = 1.02f; b.y = 1.288f; b.z = 1.02f; b.w = 1.0f;
    c.x = 0; c.y = 0; c.z = 0; pc->w = 1.0f;
    self->m_take = (cDamageUnit *)g_DmgManage.CreateDamageTake((cGameObj *)self, (DMG_KIND)2);
    if (self->m_take) {
        cV4 *pd = &d;
        d.x = 0; d.y = 0; d.z = 0; pd->w = 1.0f;
        self->m_take->AddDamageCollCylinder(*(cMatrix *)((char *)self + 0x80), c, d, b.y, b.x * 0.5f);
    }
    self->m_s548 = 1;
    self->m_s54A = 1;
    setMeshDispFromLayer__7cOmBaseUib(self, 0, 1);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x40, 0);
    if (self->m_partsNum != 1) {
        for (int i = 1; i < 6 && self->m_partsNum != i; i++) {
            *(unsigned *)((char *)self->getParts(i) + 0x154) |= 8;
            *(unsigned *)((char *)self->getParts(i) + 0x154) |= 0x10;
        }
    }
    return 1;
}
#endif
