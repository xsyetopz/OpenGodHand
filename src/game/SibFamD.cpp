// Sibling families of matched anchors 0x174650, 0x17ADE0, 0x173638 and 0x1755A8, parameterised by macro.
#include "game/cVec.h"

class cCollScrD;
extern cCollScrD g_CollScr;
class cDamageUnitD { public: void SetDamageCollActive(bool) __asm__("SetDamageCollActive__11cDamageUnitb"); };

// ---- 0x174650 family: clear damage collision, drop collision-screen entry.
struct sD5 {
    char _p0[0x540];
    long m_540;
    char _p548[0x5B0 - 0x548];
    int m_5b0;
    char _p5b4[0x650 - 0x5B4];
    cDamageUnitD *m_650;
    cDamageUnitD *m_654;
};
extern "C" {
void func_001331B8(cCollScrD *, long, bool);
void func_001C7E08(void *);
}
#define SIBD_COLL(NAME, FLD)                                        \
    extern "C" void NAME(sD5 *s)                                    \
    {                                                               \
        s->m_5b0 = (s->m_5b0 & -9) | 4;                             \
        if (s->FLD)                                                 \
            s->FLD->SetDamageCollActive(false);                     \
        func_001331B8(&g_CollScr, s->m_540, false);                 \
        func_001C7E08(s);                                           \
    }

// FUNCTION: GAME 0x182488
SIBD_COLL(func_00182488, m_650)
// FUNCTION: GAME 0x1875F8
SIBD_COLL(func_001875F8, m_650)
// FUNCTION: GAME 0x18BF40
SIBD_COLL(func_0018BF40, m_650)
// FUNCTION: GAME 0x18CD48
SIBD_COLL(func_0018CD48, m_650)
// FUNCTION: GAME 0x18DB00
SIBD_COLL(func_0018DB00, m_650)
// FUNCTION: GAME 0x18E8B8
SIBD_COLL(func_0018E8B8, m_650)
// FUNCTION: GAME 0x190068
SIBD_COLL(func_00190068, m_654)
// FUNCTION: GAME 0x199C68
SIBD_COLL(func_00199C68, m_650)
// FUNCTION: GAME 0x19D1E8
SIBD_COLL(func_0019D1E8, m_650)
// FUNCTION: GAME 0x19FD50
SIBD_COLL(func_0019FD50, m_650)

// ---- 0x17ADE0 family: mode-table dispatchers.
class cFnD;
typedef void (cFnD::*cFnDPmf)();
class cFnD {
public:
    virtual void v();
    char pad[0x2F4];
    unsigned char type;
};
extern "C" {
int func_001B76B0(cFnD *);
void func_001B76D8(cFnD *);
}
#define SIBD_MODE(NAME, TAB)                          \
    extern cFnDPmf TAB[];                             \
    extern "C" void NAME(cFnD *self)                  \
    {                                                 \
        if (func_001B76B0(self)) {                    \
            (self->*TAB[self->type])();               \
            func_001B76D8(self);                      \
        }                                             \
    }

// FUNCTION: GAME 0x1A6E00
SIBD_MODE(func_001A6E00, D_003BDBB0)
// FUNCTION: GAME 0x1A7880
SIBD_MODE(func_001A7880, D_003BDBC0)
// FUNCTION: GAME 0x1A8778
SIBD_MODE(func_001A8778, D_003BDBE0)
// FUNCTION: GAME 0x1A9720
SIBD_MODE(func_001A9720, D_003BDC08)
// FUNCTION: GAME 0x1B2648
SIBD_MODE(func_001B2648, D_003BDCF8)
// FUNCTION: GAME 0x1B8990
SIBD_MODE(func_001B8990, D_003BDD98)
// FUNCTION: GAME 0x1BBB48
SIBD_MODE(func_001BBB48, D_003BDDB8)
// FUNCTION: GAME 0x1BDFA0
SIBD_MODE(func_001BDFA0, D_003BDDE8)

// ---- 0x173638 family: release one damage unit, set a collision bit.
static inline void SetBitD(unsigned *a, unsigned i) { a[i >> 5] |= 0x80000000u >> (i & 31); }
#define SIBD_BIT(NAME, BOFF)                                        \
    struct sB_##NAME {                                              \
        char _p0[0x600];                                            \
        cDamageUnitD *m_600[4];                                     \
        char _p610[(BOFF) - 0x610];                                 \
        unsigned m_b[1];                                            \
    };                                                              \
    extern "C" void NAME(sB_##NAME *s, unsigned i)                  \
    {                                                               \
        if (s->m_600[i])                                            \
            s->m_600[i]->SetDamageCollActive(false);                \
        SetBitD(s->m_b, i);                                         \
    }

// FUNCTION: GAME 0x191860
SIBD_BIT(func_00191860, 0xF80)
// FUNCTION: GAME 0x197430
SIBD_BIT(func_00197430, 0x9D0)
// FUNCTION: GAME 0x198A58
SIBD_BIT(func_00198A58, 0x9D0)
// FUNCTION: GAME 0x1A2350
SIBD_BIT(func_001A2350, 0xD90)
// FUNCTION: GAME 0x1A37F0
SIBD_BIT(func_001A37F0, 0xD90)

// ---- 0x1755A8 family: constructors that clear an array of 0x60-byte records.
extern "C" void *func_001B6E90(void *);
extern "C" void func_0016F640(void *, int);
extern const char D_00423F58[];
extern const char D_00424E18[];
extern const char D_00424F28[];
extern const char D_00426E78[];
#define SIBD_CTOR2(NAME, VT, N, TAIL, ST)                                         \
    extern "C" char *NAME(char *s)                                              \
    {                                                                           \
        char *p = s + (ST);                                                    \
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

// FUNCTION: GAME 0x196058
SIBD_CTOR2(func_00196058, D_00424E18, 9, *(int *)(s + 0x9D0) = 0;, 0x610)
// FUNCTION: GAME 0x197680
SIBD_CTOR2(func_00197680, D_00424F28, 9, *(int *)(s + 0x9D0) = 0;, 0x610)
// FUNCTION: GAME 0x1A0D68
SIBD_CTOR2(func_001A0D68, D_00426E78, 0x13, *(int *)(s + 0xD90) = 0;, 0x610)

// FUNCTION: GAME 0x1901C8
SIBD_CTOR2(func_001901C8, D_00423F58, 0x18, *(int *)(s + 0xF80) = 0;, 0x620)

// ---- Round 31: small families.
struct sD1 {
    char _p0[0xF0];
    cVec *m_f0;
    char _pf4[0x100 - 0xF4];
    cVec m_100;
    char _p10c[0x490 - 0x10C];
    cVec m_490;
};
extern "C" {
void func_001717C0(void *, void *, void *);
void SetInitialPosition__5cOl30RC4cVecT1(void *, void *, void *);
void func_001A9210(void *, void *, void *);
void func_002AD238(void *, int, int, void *, void *, int);
void func_002AD288(void *, int);
void func_001B6F38(void *, void *);
void func_0017DF88(void *);
void func_001B55A0(void *);
void func_001BDBB8(void *);
void func_001AC908(cFnD *);
void func_002A87E8(cFnD *, int);
}

#define SIBD_POS(NAME, CALLEE)                                  \
    extern "C" void NAME(sD1 *s, const cVec *v)                 \
    {                                                           \
        s->m_490 = *v;                                          \
        *s->m_f0 = s->m_490;                                    \
        CALLEE(s, s->m_f0, &s->m_100);                          \
    }
#define SIBD_POS2(NAME, CALLEE)                                 \
    extern "C" void NAME(sD1 *s, const cVec *v)                 \
    {                                                           \
        s->m_100 = *v;                                          \
        CALLEE(s, s->m_f0, &s->m_100);                          \
    }

// FUNCTION: GAME 0x183240
SIBD_POS(func_00183240, SetInitialPosition__5cOl30RC4cVecT1)
// FUNCTION: GAME 0x1A9588
SIBD_POS(func_001A9588, func_001A9210)
// FUNCTION: GAME 0x1832A8
SIBD_POS2(func_001832A8, SetInitialPosition__5cOl30RC4cVecT1)
// FUNCTION: GAME 0x1A95F0
SIBD_POS2(func_001A95F0, func_001A9210)

struct sD6 {
    char _p0[0x214];
    const void *m_vt;
};
#define SIBD_OBJ(NAME, VT, CALLEE)                              \
    extern const char VT[];                                     \
    extern "C" void NAME(sD6 *s, void *a)                       \
    {                                                           \
        s->m_vt = VT;                                           \
        CALLEE(s);                                              \
        func_001B6F38(s, a);                                    \
    }
// FUNCTION: GAME 0x1B3A70
SIBD_OBJ(func_001B3A70, D_00428778, func_001B55A0)
// FUNCTION: GAME 0x1BD650
SIBD_OBJ(func_001BD650, D_00429420, func_001BDBB8)

#define SIBD_RES(NAME, VT, OFF)                                 \
    extern const char VT[];                                     \
    struct sRes_##NAME {                                        \
        char _p0[0x214];                                        \
        const void *m_vt;                                       \
        char _p218[(OFF) - 0x218];                              \
    };                                                          \
    extern "C" void NAME(sRes_##NAME *s, void *a)               \
    {                                                           \
        s->m_vt = VT;                                           \
        func_002AD288((char *)s + (OFF), 2);                    \
        func_001B6F38(s, a);                                    \
    }
// FUNCTION: GAME 0x182908
SIBD_RES(func_00182908, D_00422A80, 0xB10)
// FUNCTION: GAME 0x1A8930
SIBD_RES(func_001A8930, D_00427A58, 0xE40)

struct sC1D {
    char _p0[0x214];
    const void *m_vt;
};
#define SIBD_CTOR(NAME, VT, N, OFF1, A1, A2, OFF2, A6)                          \
    extern const char VT[];                                                     \
    extern "C" sC1D *NAME(sC1D *s)                                              \
    {                                                                           \
        func_001B6E90(s);                                                       \
        s->m_vt = VT;                                                           \
        char *p = (char *)s + 0x600;                                            \
        for (int i = N; i != -1; i--) {                                         \
            __asm__ volatile("sqc2 $vf0,0(%0)\n\tsqc2 $vf0,0x10(%0)\n\tsqc2 $vf0,0x20(%0)\n\tsqc2 $vf0,0x30(%0)" : : "r"(p) : "memory"); \
            p += 0x50;                                                          \
        }                                                                       \
        func_002AD238((char *)s + OFF1, A1, A2, (char *)s + 0x600, (char *)s + OFF2, A6); \
        return s;                                                               \
    }
// FUNCTION: GAME 0x182888
SIBD_CTOR(func_00182888, D_00422A80, 0xD, 0xB10, 6, 1, 0xA60, 7)
// FUNCTION: GAME 0x1A88B0
SIBD_CTOR(func_001A88B0, D_00427A58, 0xE, 0xE40, 2, 4, 0xAB0, 0x26)

extern const char D_00426F88[];
// FUNCTION: GAME 0x1A25A0
SIBD_CTOR2(func_001A25A0, D_00426F88, 0x13, *(int *)(s + 0xD90) = 0; *(int *)(s + 0xD94) = 0;, 0x610)

#define SIBD_DISP(NAME, TAB, EXTRA)                   \
    extern cFnDPmf TAB[];                             \
    extern "C" void NAME(cFnD *self)                  \
    {                                                 \
        if (func_001B76B0(self)) {                    \
            (self->*TAB[self->type])();               \
            EXTRA(self);                              \
            func_002A87E8(self, 0);                   \
            func_001B76D8(self);                      \
        }                                             \
    }
// FUNCTION: GAME 0x1AC838
SIBD_DISP(func_001AC838, D_003BDC18, func_001AC908)
