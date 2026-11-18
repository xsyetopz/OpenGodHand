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
