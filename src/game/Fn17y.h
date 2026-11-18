// Small units in .text 0x170000-0x17FFFF, part 2 (collision bit sets, unit constructors).
#ifndef GAME_FN17Y_H
#define GAME_FN17Y_H

#include "game/cVec.h"

class cDamageUnitQ { public: void SetDamageCollActive(bool) __asm__("SetDamageCollActive__11cDamageUnitb"); };

struct sS1 {
    char _p0[0x600];
    cDamageUnitQ *m_600[4];
    char _p610[0xD30 - 0x610];
    unsigned m_d30[1];
};

static inline void SetBitY(unsigned *a, unsigned i) { a[i >> 5] |= 0x80000000u >> (i & 31); }

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

extern const char D_00421F20[];

struct sC2 {
    char _p0[0x214];
    const void *m_vt;
    char _p218[0x610 - 0x218];
    float m_610[16];
    int m_650[1];
};

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

#endif
