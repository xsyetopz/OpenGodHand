// Small units in .text 0x170000-0x17FFFF (vec copies, state resets, collision-off tails).
#include "game/Fn17x.h"

extern "C" {
int func_001B6FB8(void *);
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

// FUNCTION: GAME 0x17FC58
extern "C" int func_0017FC58(sQ4 *s)
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

extern "C" {
void func_0017C028(void *, void *, void *);
void func_001717C0(void *, void *, void *);

// FUNCTION: GAME 0x17C408
void func_0017C408(sR1 *s, const cVec *v)
{
    s->m_100 = *v;
    func_0017C028(s, s->m_f0, &s->m_100);
}

// FUNCTION: GAME 0x17C3A0
void func_0017C3A0(sR1 *s, const cVec *v)
{
    s->m_490 = *v;
    *s->m_f0 = s->m_490;
    func_0017C028(s, s->m_f0, &s->m_100);
}

// FUNCTION: GAME 0x171A08
void func_00171A08(sR1 *s, const cVec *v)
{
    s->m_490 = *v;
    *s->m_f0 = s->m_490;
    func_001717C0(s, s->m_f0, &s->m_100);
}

// FUNCTION: GAME 0x173638
void func_00173638(sR3 *s, unsigned i)
{
    if (s->m_600[i])
        s->m_600[i]->SetDamageCollActive(false);
    SetBitQ(s->m_d90, i);
}
}

// FUNCTION: GAME 0x173DE8
FN17_DMG(func_00173DE8)
// FUNCTION: GAME 0x174BB0
FN17_DMG(func_00174BB0)
// FUNCTION: GAME 0x179358
FN17_DMG(func_00179358)
// FUNCTION: GAME 0x17A108
FN17_DMG(func_0017A108)
// FUNCTION: GAME 0x17CA18
FN17_DMG(func_0017CA18)
