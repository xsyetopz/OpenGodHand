struct Blk32 {
    char b[0x20];
};
struct Blk16 {
    char b[0x10];
};
struct Ent {
    short m_0;
    char _p2[2];
    int m_4;
    int m_8;
    unsigned char m_c;
    unsigned char m_d;
    short m_e;
    unsigned short m_10;
    short m_12;
    unsigned short m_14, m_16, m_18, m_1a, m_1c, m_1e;
    Blk32 m_20;
    Blk16 m_40;
};
extern "C" Ent *func_0037D170();
extern "C" int func_00377FF8();

// FUNCTION: GAME 0x374DF8
extern "C" int func_00374DF8(Ent *self, int arg)
{
    Ent *e;
    if ((*(unsigned short *)&self->m_e & 0x8000) || (e = func_0037D170()) == 0)
        return 0;
    e->m_0 = 3;
    if (arg != 0)
        e->m_4 = arg;
    else
        e->m_4 = func_00377FF8();
    e->m_c = 2;
    e->m_d = 1;
    e->m_8 = 0;
    e->m_e = -1;
    e->m_12 = -1;
    e->m_10 = 0;
    e->m_14 = 0;
    e->m_16 = 0;
    e->m_18 = 0;
    e->m_1a = 0;
    e->m_1c = 0;
    e->m_1e = 0;
    e->m_20 = *(Blk32 *)self;
    e->m_40 = *(Blk16 *)((char *)self + 0x20);
    if (*(unsigned short *)((char *)e + 0x48) != 0xFFFF)
        e->m_d |= 8;
    return e->m_4;
}
