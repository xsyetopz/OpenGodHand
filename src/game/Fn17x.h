// Small units in .text 0x170000-0x17FFFF (vec copies, state resets, collision-off tails).
#ifndef GAME_FN17X_H
#define GAME_FN17X_H

#include "game/cVec.h"

class cCollScrQ;
extern cCollScrQ g_CollScr;
class cDamageUnitQ { public: void SetDamageCollActive(bool) __asm__("SetDamageCollActive__11cDamageUnitb"); };
class cOl2b { public: void setOpenFix(); };

struct sQ1 {
    char _p0[0x40];
    cVec m_40;
};
struct sQ2 {
    char _p0[0xF0];
    int m_f0;
    char _pf4[0x100 - 0xF4];
    cVec m_100;
};
struct sQ3 {
    char _p0[0x250];
    unsigned m_250;
    char _p254[0x5B8 - 0x254];
    unsigned m_5b8;
    char _p5bc[0x600 - 0x5BC];
    char m_600;
};
struct sQ4 {
    char _p0[0x250];
    unsigned m_250;
    char _p254[0x5B8 - 0x254];
    unsigned m_5b8;
    char _p5bc[0xA24 - 0x5BC];
    int m_a24;
    char m_a28;
    char m_a29;
};
struct sQ5 {
    char _p0[0x540];
    long m_540;
    char _p548[0x5B0 - 0x548];
    int m_5b0;
    char _p5b4[0x650 - 0x5B4];
    cDamageUnitQ *m_650;
};

// 15-frame countdown state machine: state 0 arms the timer, state 1 counts it down, then clears the state bytes.
struct sTm654 {
    char _p0[0x2F4];
    unsigned char m_2f4, m_2f5, m_2f6, m_2f7;
    char _p2f8[0x654 - 0x2F8];
    unsigned short m_t;
};
struct sTmD34 {
    char _p0[0x2F4];
    unsigned char m_2f4, m_2f5, m_2f6, m_2f7;
    char _p2f8[0xD34 - 0x2F8];
    unsigned short m_t;
};

#define FN17_TIMER(NAME, STRUCT)                      \
    extern "C" void NAME(STRUCT *s)                   \
    {                                                 \
        switch (s->m_2f5) {                           \
        case 0:                                       \
            s->m_t = 15;                              \
            s->m_2f5 = 1;                             \
            s->m_2f6 = 0;                             \
            s->m_2f7 = 0;                             \
        case 1:                                       \
            s->m_t--;                                 \
            if ((short)s->m_t <= 0) {                 \
                s->m_2f4 = 0;                         \
                s->m_2f5 = 0;                         \
                s->m_2f6 = 0;                         \
                s->m_2f7 = 0;                         \
            }                                         \
            break;                                    \
        }                                             \
    }

extern const char D_00421BB8[];
extern "C" float capVu0MagnitudeSqXZ__FPCfT0(const float *, const float *);
extern "C" void func_002AD288(void *p, int n);
extern "C" void func_001B6F38(void *self, void *a);

struct sTv {
    char _p0[0xF0];
    const float *m_f0;
    char _pf4[0x214 - 0xF4];
    const void *m_vt;
    char _p218[0xD80 - 0x218];
    char m_d80[1];
};

class cDamageTake;
class cOmBase { public: int checkDamage(cDamageTake *d); };

struct sR1 {
    char _p0[0xF0];
    cVec *m_f0;
    char _pf4[0x100 - 0xF4];
    cVec m_100;
    char _p10c[0x490 - 0x10C];
    cVec m_490;
};
struct sR2 {
    char _p0[0x2F4];
    unsigned char m_2f4, m_2f5, m_2f6, m_2f7;
    char _p2f8[0x54A - 0x2F8];
    short m_54a;
    char _p54c[0x5B0 - 0x54C];
    unsigned m_5b0;
    char _p5b4[0x650 - 0x5B4];
    cDamageTake *m_650;
};
struct sR3 {
    char _p0[0x600];
    cDamageUnitQ *m_600[4];
    char _p610[0xD90 - 0x610];
    unsigned m_d90[1];
};

static inline void SetBitQ(unsigned *a, unsigned i) { a[i >> 5] |= 0x80000000u >> (i & 31); }

#define FN17_DMG(NAME)                                              \
    extern "C" void NAME(sR2 *s)                                    \
    {                                                               \
        int r = ((cOmBase *)s)->checkDamage(s->m_650);              \
        if (r == 1) {                                               \
            if (s->m_54a <= 0) {                                    \
                s->m_2f4 = 2;                                       \
                s->m_5b0 |= 1;                                      \
                s->m_2f6 = 0;                                       \
                s->m_2f7 = 0;                                       \
                s->m_2f5 = 0;                                       \
            } else {                                                \
                s->m_2f4 = r;                                       \
                s->m_2f5 = 0;                                       \
                s->m_2f6 = 0;                                       \
                s->m_2f7 = 0;                                       \
            }                                                       \
        }                                                           \
    }

#endif
