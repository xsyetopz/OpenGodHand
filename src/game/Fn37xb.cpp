// Small functions in the ProDG game-code island 0x370000-0x383FFF.
#include "game/Fn37x.h"
extern "C" void func_003733C8(Fn37Obj *);

// FUNCTION: GAME 0x373938
extern "C" float func_00373938(Fn37Obj *o, int i)
{
    float r;
    if (!func_00373A50(o))
        r = 0.0f;
    else if (func_00373B20(o) == 1)
        r = *(float *)((char *)o + (i << 2) + 0x2C);
    else
        r = ((float *)o)[8];
    return r;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x373298
// diff: 9 words (300 vs 300 bytes); original reloads o->m_70 (lw v0,0x70) after the m_5C store, mine reuses e in a0. Tried: `type<2 && 4C&0x10` merged test with ~0x10u (fixed 73), all 120 store orders of the five entry stores (best 58,54,78,5C,70 = 9; 70-first orders 61+)
extern "C" int func_00373298(Fn37Sel *o, int idx)
{
    Fn37Ent *e = o->m_6C + idx;
    int r, t;
    o->m_58 = e->m_0A;
    o->m_54 = e->m_0B & 3;
    o->m_78 = idx;
    o->m_5C = e->m_11;
    o->m_70 = e;
    r = 0;
    if (o->m_70->m_10) {
        r = o->m_7C;
        if (func_00373B20((Fn37Obj *)o) == 1) {
            r = func_00374508(o, o->m_74, o->m_70);
        } else {
            if (((o->m_70->m_0B >> 2) & 3) < 2 && (o->m_4C & 0x10)) {
                t = 1;
            } else {
                o->m_4C &= ~0x10u;
                t = 0;
            }
            r = func_00373F38(o, o->m_74, o->m_70, r, t);
        }
    }
    if (r == 0)
        func_003733C8((Fn37Obj *)o);
    return r;
}
#endif

// FUNCTION: GAME 0x373A78
extern "C" int func_00373A78(Fn37Obj *o)
{
    if (!func_00373A50(o))
        return 1;
    if (func_00373B20(o) == 1) {
        int i;
        for (i = 0; i < o->m_58; i++)
            if (0.0f < ((float *)o)[7 + i])
                return 0;
        return 1;
    }
    if (0.0f < ((float *)o)[6])
        return 0;
    return 1;
}

// FUNCTION: GAME 0x3738A0
extern "C" void func_003738A0(Fn37Obj *o, float f, int idx)
{
    if (func_00373A50(o)) {
        if (func_00373B20(o) == 1) {
            if (idx < 0) {
                int i;
                for (i = 0; i < o->m_58; i++)
                    ((float *)o)[0x2C / 4 + i] = f;
            } else
                *(float *)((char *)o + (idx << 2) + 0x2C) = f;
        } else
            ((float *)o)[8] = f;
    }
}
