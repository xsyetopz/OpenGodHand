struct sA {
    char _p0[0x2C];
    unsigned m_2c;
    int m_30;
    unsigned m_34;
    unsigned m_38;
};

struct sB {
    char _p0[0xA];
    unsigned short m_a;
    unsigned short m_c;
    short m_e;
    short m_10;
};

// FUNCTION: GAME 0x37A8F8
extern "C" short func_0037A8F8(sA *a, sB *b, short v)
{
    short step;
    if (a->m_2c & 8)
        step = b->m_10;
    else
        step = b->m_e;
    if (a->m_2c & 0x80) {
        unsigned f = a->m_34;
        if (f & 0x8000)
            v = (short)b->m_a;
        if (f & 0x2000)
            v = (short)b->m_c;
        v = (f & 0x1000) ? 0 : v;
        v = (f & 0x4000) ? 0 : v;
    } else {
        unsigned f = a->m_38;
        if (f & 0x8000)
            v -= step;
        if (f & 0x2000)
            v += step;
    }
    if (v < (short)b->m_a)
        v = (short)b->m_c;
    return ((short)b->m_c >= v) ? v : (short)b->m_a;
}
