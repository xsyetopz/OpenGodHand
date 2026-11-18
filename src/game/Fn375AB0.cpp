// Sibling table getter (ee-gcc 2.95.3-136, C++).

struct Fn375Ent {
    short m_0;
    short m_2;
    char _p4[0xA];
    unsigned short m_E;
    char _p10[0x20];
};
struct Fn375Hd {
    char _p0[0x14];
    short m_14;
    char _p16[2];
    Fn375Ent *m_18;
    char _p1C[4];
};
extern Fn375Hd D_0076EA50[];
extern "C" void func_00375B90(short, short, Fn375Ent *);

#ifdef NONMATCHING
// DRAFT: GAME 0x375AB0
// 23 differing words: same as 0x374CB8, original keeps a in a0 and the entry pointer in a3, mine puts a in a3; tried ptr reuse via cast.
extern "C" int func_00375AB0(short a, short b, Fn375Ent *out)
{
    Fn375Ent *e = (Fn375Ent *)&D_0076EA50[a];
    if (b < ((Fn375Hd *)e)->m_14) {
        e = ((Fn375Hd *)e)->m_18 + b;
        if ((e->m_E & 0x8000) == 0) {
            *out = *e;
            out->m_2 = b;
            out->m_0 = a;
            return 0;
        }
    }
    func_00375B90(a, b, out);
    return -1;
}
#endif
