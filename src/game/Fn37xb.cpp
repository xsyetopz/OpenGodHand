// Small functions in the ProDG game-code island 0x370000-0x383FFF.
#include "game/Fn37x.h"
extern "C" void func_003733C8(Fn37Obj *);

#ifdef NONMATCHING
// DRAFT: GAME 0x373938
// diff: 12 words; branch layout differs (original bnel with 0x20 load in the likely delay slot)
extern "C" float func_00373938(Fn37Obj *o, int i)
{
    float r;
    if (func_00373A50(o)) {
        if (func_00373B20(o) == 1)
            r = ((float *)o)[0x2C / 4 + i];
        else
            r = ((float *)o)[8];
    } else
        r = 0.0f;
    return r;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x373298
// diff: 73 words; entry pointer lands in v1 not a0, 4C load not hoisted above the type test, t0 spilled to s2
extern "C" int func_00373298(Fn37Sel *o, int idx)
{
    Fn37Ent *e = o->m_6C + idx;
    int r, t;
    o->m_70 = e;
    o->m_58 = e->m_0A;
    o->m_78 = idx;
    o->m_54 = e->m_0B & 3;
    o->m_5C = e->m_11;
    r = 0;
    if (o->m_70->m_10) {
        r = o->m_7C;
        if (func_00373B20((Fn37Obj *)o) == 1) {
            r = func_00374508(o, o->m_74, o->m_70);
        } else {
            if (((o->m_70->m_0B >> 2) & 3) < 2) {
                if (o->m_4C & 0x10) {
                    t = 1;
                } else {
                    o->m_4C &= ~0x10;
                    t = 0;
                }
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
