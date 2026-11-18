#include "game/cVec.h"

extern "C" void func_001B6FB8(void *);
extern "C" int setObjCollision__7cOmDoor(void *);
extern "C" void func_001BBF68(void *);

struct sD2 {
    char _p0[0x548];
    short m_548, m_54a;
    char _p54c[0x5B8 - 0x54C];
    unsigned m_5b8;
    char _p5bc[0x610 - 0x5BC];
    cVec m_610;
    char _p61c[0x624 - 0x61C];
    unsigned char m_624;
    char _p625[3];
    void *m_628;
    char _p62c[0x650 - 0x62C];
    char m_650[1];
};

#ifdef NONMATCHING
// DRAFT: GAME 0x17D488
// diff: 33 words, const load/store order and copy reloads from stack (orig 8 bytes longer); sibling of 0x1A8200 draft, tried store order
extern "C" int func_0017D488(sD2 *s)
{
    func_001B6FB8(s);
    struct { cVec v; float w; } t, u;
    u.w = 1.0f;
    t.v.x = 1.75f;
    t.v.y = 3.1f;
    t.v.z = 0.2f;
    u.v.x = -0.875f;
    t.w = 1.0f;
    u.v.y = 0;
    u.v.z = 0;
    s->m_548 = 1;
    s->m_54a = 1;
    s->m_610 = t.v;
    setObjCollision__7cOmDoor(s);
    s->m_624 = 1;
    s->m_628 = s->m_650;
    func_001BBF68(s);
    s->m_5b8 |= 2;
    return 1;
}
#endif
