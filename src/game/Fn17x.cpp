// Small units in .text 0x170000-0x17FFFF (vec copies, state resets, collision-off tails).
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

extern "C" {
void func_001B6FB8(void *);
void func_0017C028(void *, int);
void func_001331B8(cCollScrQ *, long, bool);
void func_001C7E08(void *);

// FUNCTION: GAME 0x17F5D0
int func_0017F5D0(void *s)
{
    func_001B6FB8(s);
    return 1;
}

// FUNCTION: GAME 0x173968
void func_00173968(sQ1 *s, const cVec *v)
{
    s->m_40 = *v;
}

// FUNCTION: GAME 0x17EEA0
int func_0017EEA0(sQ3 *s)
{
    func_001B6FB8(s);
    s->m_250 |= 0x10000;
    return 1;
}

// FUNCTION: GAME 0x17E1E8
int func_0017E1E8(sQ3 *s)
{
    func_001B6FB8(s);
    s->m_250 |= 0x10000;
    s->m_600 = 0;
    s->m_5b8 |= 8;
    return 1;
}

// FUNCTION: GAME 0x174650
void func_00174650(sQ5 *s)
{
    s->m_5b0 = (s->m_5b0 & -9) | 4;
    if (s->m_650)
        s->m_650->SetDamageCollActive(false);
    func_001331B8(&g_CollScr, s->m_540, false);
    func_001C7E08(s);
}

// FUNCTION: GAME 0x175450
void func_00175450(sQ5 *s)
{
    s->m_5b0 = (s->m_5b0 & -9) | 4;
    if (s->m_650)
        s->m_650->SetDamageCollActive(false);
    func_001331B8(&g_CollScr, s->m_540, false);
    func_001C7E08(s);
}

// FUNCTION: GAME 0x179C00
void func_00179C00(sQ5 *s)
{
    s->m_5b0 = (s->m_5b0 & -9) | 4;
    if (s->m_650)
        s->m_650->SetDamageCollActive(false);
    func_001331B8(&g_CollScr, s->m_540, false);
    func_001C7E08(s);
}

// FUNCTION: GAME 0x17A980
void func_0017A980(sQ5 *s)
{
    s->m_5b0 = (s->m_5b0 & -9) | 4;
    if (s->m_650)
        s->m_650->SetDamageCollActive(false);
    func_001331B8(&g_CollScr, s->m_540, false);
    func_001C7E08(s);
}

// FUNCTION: GAME 0x17D280
void func_0017D280(sQ5 *s)
{
    s->m_5b0 = (s->m_5b0 & -9) | 4;
    if (s->m_650)
        s->m_650->SetDamageCollActive(false);
    func_001331B8(&g_CollScr, s->m_540, false);
    func_001C7E08(s);
}
}

#ifdef NONMATCHING

// DRAFT: GAME 0x17C408
// diff: original copies the vec via $a2, compiled uses $v0
void func_0017C408(sQ2 *s, const cVec *v)
{
    s->m_100 = *v;
    func_0017C028(s, s->m_f0);
}


// DRAFT: GAME 0x17FC58
// diff: original loads 0x5B8 into $v1 and 0x250 into $v0, compiled swaps the registers
int func_0017FC58(sQ4 *s)
{
    func_001B6FB8(s);
    s->m_5b8 |= 8;
    s->m_250 |= 0x10000;
    s->m_a29 = 0;
    s->m_a28 = 0;
    s->m_a24 = 2;
    ((cOl2b *)s)->setOpenFix();
    return 1;
}
#endif

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

// FUNCTION: GAME 0x174C28
FN17_TIMER(func_00174C28, sTm654)
// FUNCTION: GAME 0x17A180
FN17_TIMER(func_0017A180, sTm654)
// FUNCTION: GAME 0x17CA90
FN17_TIMER(func_0017CA90, sTm654)
// FUNCTION: GAME 0x175ED8
FN17_TIMER(func_00175ED8, sTmD34)
// FUNCTION: GAME 0x177560
FN17_TIMER(func_00177560, sTmD34)

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

// FUNCTION: GAME 0x17B8F0
extern "C" void func_0017B8F0(sTv *s, void *a)
{
    s->m_vt = D_00421BB8;
    func_002AD288(s->m_d80, 2);
    func_001B6F38(s, a);
}

// FUNCTION: GAME 0x17E058
extern "C" int func_0017E058(sTv *s, const float *p, float r)
{
    const float *q = s->m_f0;
    int res = 0;
    if (capVu0MagnitudeSqXZ__FPCfT0(p, q) <= r)
        res = 1;
    return res;
}
