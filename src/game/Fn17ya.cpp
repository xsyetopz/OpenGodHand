// Small units in .text 0x170000-0x17FFFF, part 2 (collision bit sets, unit constructors).
#include "game/Fn17y.h"

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

// FUNCTION: GAME 0x171070
FN17_CTOR(func_00171070, D_00420CA0, 0x22, 0x1AE0, 4, 6, 0x10F0, 0x6A)
// FUNCTION: GAME 0x17B870
FN17_CTOR(func_0017B870, D_00421BB8, 0xE, 0xD80, 2, 4, 0xAB0, 0x1E)

// FUNCTION: GAME 0x1755A8
FN17_CTOR2(func_001755A8, D_004211D8, 0x12, *(int *)(s + 0xD30) = 0;)
// FUNCTION: GAME 0x176C30
FN17_CTOR2(func_00176C30, D_004212E8, 0x12, *(int *)(s + 0xD30) = 0;)
// FUNCTION: GAME 0x171C90
FN17_CTOR2(func_00171C90, D_00420EF0, 0x13, *(int *)(s + 0xD90) = 0; *(int *)(s + 0xDA8) = 0;)

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

// FUNCTION: GAME 0x170F60
FN17_VEC(func_00170F60, 4.0f, 4.1f, 4.2f)
// FUNCTION: GAME 0x17EAF8
FN17_VEC(func_0017EAF8, 5.78f, 5.5f, 5.6f)

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
