struct VolEnt {
    short *m_0;
    char _p[6];
    unsigned short m_a;
    unsigned short m_c;
    short m_e;
    short m_10;
    char _p2[2];
};
struct VolObj {
    char _p[0x26];
    signed char m_26;
    char _p1[5];
    unsigned m_2c;
    unsigned m_30;
    unsigned m_34;
    unsigned m_38;
};
extern VolEnt D_003F2638[];
extern "C" void SdeSystemVolGet(void *, int);
extern "C" void SdeSystemVolSet(void *, short, short, short);
extern "C" void SdePlayVolReset(int);

// DRAFT: GAME 0x37AD88
// diff: 33 words, v/cur land in a3/t0 instead of a1/a3 (orig keeps v in a1 = SdeSystemVolSet arg) and r is returned via v1 not v0; tried movn via int z=k&mask (fixes movn), nested ternary (bnez/movz), inline (short)e->m_a (worse), hoisted unsigned short lo/hi (worse), early return 0
#ifdef NONMATCHING
extern "C" int func_0037AD88(VolObj *self)
{
    VolEnt *e = &D_003F2638[self->m_26];
    SdeSystemVolGet((char *)self + 0x15C, 0x14);
    short v = *e->m_0;
    short cur = v;
    short step;
    if (self->m_2c & 8)
        step = e->m_10;
    else
        step = e->m_e;
    if (self->m_2c & 0x80) {
        unsigned k = self->m_34;
        if (k & 0x8000)
            v = (short)e->m_a;
        if (k & 0x2000)
            v = (short)e->m_c;
        int z1 = k & 0x1000;
        int z2 = k & 0x4000;
        if (z1)
            v = 0;
        if (z2)
            v = 0;
    } else {
        unsigned k = self->m_38;
        if (k & 0x8000)
            v = v - step;
        if (k & 0x2000)
            v = v + step;
    }
    short lo = (short)e->m_a;
    if (v < lo)
        v = (short)e->m_c;
    short hi = (short)e->m_c;
    if (hi < v)
        v = lo;
    int r = 0;
    if (v != cur) {
        *e->m_0 = v;
        SdeSystemVolSet((char *)self + 0x15C, v, lo, cur);
        SdePlayVolReset(7);
        r = 1;
    }
    return r;
}
#endif
