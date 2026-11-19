// Per-slot fade step update (ee-gcc 2.95.3-136, C++).

struct Fn31BSlot {
    unsigned char m_0, m_1, m_2, m_3;
    char _p4[2];
    unsigned short m_6;
    char _p8[2];
    short m_A;
    short m_C;
    char _pE[2];
};
struct Fn31BObj {
    char _p0[0x160];
    Fn31BSlot s[32];
    unsigned char m_360, m_361;
};

// FUNCTION: GAME 0x31BC98
extern "C" void func_0031BC98(Fn31BObj *o, int i)
{
    Fn31BSlot *s = &o->s[i];
    if (s->m_0 & 1)
        o->m_360 = 1;
    unsigned char f = s->m_0;
    if (f & 4) {
        s->m_1 = s->m_2;
        int q = ((s->m_2 - s->m_3) << 4) / s->m_6;
        s->m_0 = f & 3;
        s->m_C = 0;
        s->m_A = q;
    }
    if (s->m_0 & 2) {
        short c = s->m_C;
        if (c != 0)
            s->m_1 = (s->m_2 * 16 - c) / 16;
        unsigned char v = s->m_1;
        if (o->m_361 < v)
            o->m_361 = v;
    }
    if (s->m_A != 0)
        s->m_C = (unsigned short)s->m_C + (unsigned short)s->m_A;
}
