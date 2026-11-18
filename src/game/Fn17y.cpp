// Small units in .text 0x170000-0x17FFFF, part 2 (collision bit sets, unit constructors).
#include "game/cVec.h"

class cDamageUnitQ { public: void SetDamageCollActive(bool) __asm__("SetDamageCollActive__11cDamageUnitb"); };

struct sS1 {
    char _p0[0x600];
    cDamageUnitQ *m_600[4];
    char _p610[0xD30 - 0x610];
    unsigned m_d30[1];
};

static inline void SetBitY(unsigned *a, unsigned i) { a[i >> 5] |= 0x80000000u >> (i & 31); }

extern "C" {
// FUNCTION: GAME 0x1769E0
void func_001769E0(sS1 *s, unsigned i)
{
    if (s->m_600[i])
        s->m_600[i]->SetDamageCollActive(false);
    SetBitY(s->m_d30, i);
}
// FUNCTION: GAME 0x178068
void func_00178068(sS1 *s, unsigned i)
{
    if (s->m_600[i])
        s->m_600[i]->SetDamageCollActive(false);
    SetBitY(s->m_d30, i);
}
}

extern const char D_00420CA0[];
extern const char D_00421BB8[];
extern "C" void *func_001B6E90(void *);
extern "C" void func_002AD238(void *, int, int, void *, void *, int);

struct sC1 {
    char _p0[0x214];
    const void *m_vt;
};

#define FN17_CTOR(NAME, VT, N, OFF1, A1, A2, OFF2, A6)                          \
    extern "C" sC1 *NAME(sC1 *s)                                                \
    {                                                                           \
        func_001B6E90(s);                                                       \
        s->m_vt = VT;                                                           \
        char *p = (char *)s + 0x600;                                            \
        for (int i = N; i != -1; i--) {                                     \
            __asm__ volatile("sqc2 $vf0,0(%0)\n\tsqc2 $vf0,0x10(%0)\n\tsqc2 $vf0,0x20(%0)\n\tsqc2 $vf0,0x30(%0)" : : "r"(p) : "memory"); \
            p += 0x50;                                                          \
        }                                                                       \
        func_002AD238((char *)s + OFF1, A1, A2, (char *)s + 0x600, (char *)s + OFF2, A6); \
        return s;                                                               \
    }

// FUNCTION: GAME 0x171070
FN17_CTOR(func_00171070, D_00420CA0, 0x22, 0x1AE0, 4, 6, 0x10F0, 0x6A)
// FUNCTION: GAME 0x17B870
FN17_CTOR(func_0017B870, D_00421BB8, 0xE, 0xD80, 2, 4, 0xAB0, 0x1E)

extern const char D_004211D8[];
extern const char D_004212E8[];
extern const char D_00420EF0[];
extern "C" void func_0016F640(void *, int);

#define FN17_CTOR2(NAME, VT, N, TAIL)                                           \
    extern "C" char *NAME(char *s)                                              \
    {                                                                           \
        char *p = s + 0x610;                                                    \
        func_001B6E90(s);                                                       \
        *(const void **)(s + 0x214) = VT;                                       \
        for (int i = N; i != -1; i--) {                                         \
            __asm__ volatile("sqc2 $vf0,0(%0)\n\tsqc2 $vf0,0x10(%0)\n\tsqc2 $vf0,0x20(%0)\n\tsqc2 $vf0,0x30(%0)\n\tsqc2 $vf0,0x40(%0)" : : "r"(p) : "memory"); \
            func_0016F640(p, 0);                                                \
            p += 0x60;                                                          \
        }                                                                       \
        TAIL                                                                    \
        return s;                                                               \
    }

// FUNCTION: GAME 0x1755A8
FN17_CTOR2(func_001755A8, D_004211D8, 0x12, *(int *)(s + 0xD30) = 0;)
// FUNCTION: GAME 0x176C30
FN17_CTOR2(func_00176C30, D_004212E8, 0x12, *(int *)(s + 0xD30) = 0;)
// FUNCTION: GAME 0x171C90
FN17_CTOR2(func_00171C90, D_00420EF0, 0x13, *(int *)(s + 0xD90) = 0; *(int *)(s + 0xDA8) = 0;)

extern const char D_00421F20[];

struct sC2 {
    char _p0[0x214];
    const void *m_vt;
    char _p218[0x610 - 0x218];
    float m_610[16];
    int m_650[1];
};

// FUNCTION: GAME 0x17D5D0
extern "C" char *func_0017D5D0(char *s)
{
    func_001B6E90(s);
    *(const void **)(s + 0x214) = D_00421F20;
    __asm__ volatile("sqc2 $vf0,0x610(%0)\n\tsqc2 $vf0,0x620(%0)\n\tsqc2 $vf0,0x630(%0)\n\tsqc2 $vf0,0x640(%0)" : : "r"(s) : "memory");
    int i = 7;
    int *p = (int *)(s + 0x670);
    for (; i >= 0; i--)
        *p-- = 0;
    *(int *)(s + 0x674) = 0;
    return s;
}

struct sC3 {
    char _p0[0x5A0];
    unsigned m_5a0;
    char _p5a4[0x600 - 0x5A4];
    cVec m_600;
};
extern "C" void func_001B6FB8(void *);
extern "C" void func_001BDA00(void *);
extern "C" void func_001BD698(void *);
extern "C" void func_001BDD88(void *, float);

// FUNCTION: GAME 0x17C508
extern "C" int func_0017C508(sC3 *s)
{
    func_001B6FB8(s);
    struct { cVec v; float w; } t;
    t.v.x = 4.22f;
    t.v.y = 3.812f;
    t.v.z = 0.2f;
    t.w = 1.0f;
    s->m_600 = t.v;
    func_001BDA00(s);
    func_001BD698(s);
    func_001BDD88(s, 4.0f);
    s->m_5a0 |= 0x10;
    return 1;
}

#define FN17_VEC(NAME, X, Y, ARG)                       \
    extern "C" int NAME(sC3 *s)                         \
    {                                                   \
        func_001B6FB8(s);                               \
        struct { cVec v; float w; } t;                  \
        t.v.x = X;                                      \
        t.v.y = Y;                                      \
        t.v.z = 0.2f;                                   \
        t.w = 1.0f;                                     \
        s->m_600 = t.v;                                 \
        func_001BDA00(s);                               \
        func_001BD698(s);                               \
        func_001BDD88(s, ARG);                          \
        return 1;                                       \
    }

// FUNCTION: GAME 0x170F60
FN17_VEC(func_00170F60, 4.0f, 4.1f, 4.2f)
// FUNCTION: GAME 0x17EAF8
FN17_VEC(func_0017EAF8, 5.78f, 5.5f, 5.6f)

struct sK1 {
    char _p0[0xF0];
    const float *m_f0;
    char _pf4[0x2F4 - 0xF4];
    unsigned char m_2f4, m_2f5, m_2f6, m_2f7;
    char _p2f8[0x490 - 0x2F8];
    float m_490[4];
    char _p4a0[0x5B0 - 0x4A0];
    int m_5b0;
    char _p5b4[0x5C0 - 0x5B4];
    cVec m_5c0;
};
struct V16Y {
    float x, y, z, w;
} __attribute__((aligned(16)));

#define FN17_STOP(NAME)                                                         \
    extern "C" void NAME(sK1 *s)                                                \
    {                                                                           \
        long f = (unsigned)s->m_5b0;                                            \
        long x = (f >> 1) & 1;                                                  \
        if (x)                                                                  \
            return;                                                             \
        V16Y a;                                                                 \
        __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(&a) : "memory");             \
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(&a), "r"(s->m_f0), "r"(s->m_490) : "memory"); \
        V16Y b = a;                                                             \
        s->m_5c0 = *(cVec *)&b;                                                 \
        s->m_5b0 = (s->m_5b0 | 1) & -5;                                         \
        s->m_2f4 = 2;                                                           \
        s->m_2f5 = 0;                                                           \
        s->m_2f6 = 0;                                                           \
        s->m_2f7 = 0;                                                           \
    }

// FUNCTION: GAME 0x1746B0
FN17_STOP(func_001746B0)

struct vtQ {
    char _p[0x80];
    short adj;
    short _pad;
    cVec *(*fn)(void *);
};
struct sP1 {
    char _p0[0x214];
    vtQ *m_vt;
    char _p218[0x8D0 - 0x218];
    cVec m_8d0;
};

// FUNCTION: GAME 0x17B568
extern "C" cVec *func_0017B568(sP1 *s)
{
    cVec *p = s->m_vt->fn((char *)s + s->m_vt->adj);
    s->m_8d0 = *p;
    s->m_8d0.y += 4.1f;
    return &s->m_8d0;
}

// FUNCTION: GAME 0x171B70
extern "C" int func_00171B70(sC3 *s)
{
    func_001B6FB8(s);
    float k = 3.2f;
    struct { cVec v; float w; } t;
    t.v.x = k;
    t.v.y = 3.1f;
    t.v.z = 0.2f;
    t.w = 1.0f;
    s->m_600 = t.v;
    func_001BDA00(s);
    func_001BD698(s);
    func_001BDD88(s, k);
    s->m_5a0 |= 0x10;
    return 1;
}

struct sTy {
    char _p0[0x2F4];
    unsigned char m_2f4, m_2f5, m_2f6, m_2f7;
    char _p2f8[0x654 - 0x2F8];
    unsigned short m_t;
};
struct cSndY {
    void SeCall(int, int, void *, int, void *, int, int) __asm__("SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii");
};
extern cSndY Snd;

// FUNCTION: GAME 0x1793D0
extern "C" void func_001793D0(sTy *s)
{
    switch (s->m_2f5) {
    case 0:
        Snd.SeCall(2, 2, s, 0, 0, 0, 0);
        s->m_t = 15;
        s->m_2f5 = 1;
        s->m_2f6 = 0;
        s->m_2f7 = 0;
    case 1:
        s->m_t--;
        if ((short)s->m_t <= 0) {
            s->m_2f7 = 0;
            s->m_2f4 = 0;
            s->m_2f5 = 0;
            s->m_2f6 = 0;
        }
        break;
    }
}

class cFnY;
typedef void (cFnY::*cFnYPmf)();
class cFnY {
public:
    virtual void v();
    char pad[0x2F4];
    unsigned char type;
};
extern "C" {
int func_001B76B0(cFnY *self);
void func_001B76D8(cFnY *self);
}

#define FN17_MODE(NAME, TAB)                          \
    extern cFnYPmf TAB[];                              \
    extern "C" void NAME(cFnY *self)                   \
    {                                                  \
        if (func_001B76B0(self)) {                     \
            (self->*TAB[self->type])();                \
            func_001B76D8(self);                       \
        }                                              \
    }

// FUNCTION: GAME 0x17ADE0
FN17_MODE(func_0017ADE0, D_003BDA20)
// FUNCTION: GAME 0x17E230
FN17_MODE(func_0017E230, D_003BDA68)
// FUNCTION: GAME 0x17EED8
FN17_MODE(func_0017EED8, D_003BDA98)
// FUNCTION: GAME 0x17F5F0
FN17_MODE(func_0017F5F0, D_003BDAB0)
// FUNCTION: GAME 0x17FCB8
FN17_MODE(func_0017FCB8, D_003BDAD0)
