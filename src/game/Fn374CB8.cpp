// SdeIssTblGet / sibling table getters (ee-gcc 2.95.3-136, C++).

struct Fn374Ent {
    short m_0;
    short m_2;
    char _p4[0xA];
    unsigned short m_E;
    char _p10[0x20];
};
struct Fn374Hd {
    short m_0;
    char _p2[2];
    Fn374Ent *m_4;
    char _p8[0x18];
};
extern Fn374Hd Sde_iss_hed[];
extern "C" void func_00374D98(short, short, Fn374Ent *);

#ifdef NONMATCHING
// DRAFT: GAME 0x374CB8
// 26 differing words: original keeps a in a0 and the header/entry pointer in a3, mine swaps them (a to a3); tried indexed/shifted address, ptr reuse, e hoist, store order.
extern "C" int SdeIssTblGet(short a, short b, Fn374Ent *out)
{
    Fn374Hd *h = &Sde_iss_hed[a];
    Fn374Ent *e;
    if (b < h->m_0) {
        e = h->m_4 + b;
        if ((e->m_E & 0x8000) == 0) {
            *out = *e;
            out->m_0 = a;
            out->m_2 = b;
            return 0;
        }
    }
    func_00374D98(a, b, out);
    return -1;
}
#endif
