struct cObj {
    char _p0[0x2D0];
    unsigned m_2D0;
    char _p2D4[0x2FE - 0x2D4];
    short m_2FE;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x14E690
// diff: ~50 words, u8 range flag (slti/andi 0xFF) becomes movn/sltiu; tried &&, inline u8 helper, manual u8 flags
extern "C" void setId__4cObj6eObjId(cObj *self, int id)
{
    self->m_2FE = id;
    unsigned char a = 0;
    int v = id & 0xFFFF;
    self->m_2D0 = 0;
    if (v >= 0x100)
        a = v < 0x1FF;
    if (a) {
        self->m_2D0 = 0x80000000;
        return;
    }
    unsigned char b = 0;
    if (v >= 0x200)
        b = v < 0x300;
    if (b) {
        self->m_2D0 = 0x40000000;
        return;
    }
    unsigned char c = 0;
    if (v >= 0x300)
        c = v < 0x500;
    if (c) {
        self->m_2D0 = 0x20000000;
        return;
    }
    unsigned char d = 0;
    if (v >= 0x500)
        d = v < 0x600;
    if (d) {
        self->m_2D0 = 0x10000000;
        return;
    }
    unsigned char e = 0;
    if (v >= 0x600)
        e = v < 0x700;
    if (e)
        self->m_2D0 = 0x800000;
}
#endif
