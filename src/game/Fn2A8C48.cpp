extern "C" {
struct HE8C {
    int m_0;
    float m_4;
};

void func_002A8AA8(HE8C *h, int hole, int len, HE8C item, int extra);

// DRAFT: GAME 0x2A8C48
// 56 words differ: register allocation (original keeps first in s4 plus a copy s3, s0=last-1, s2=byte count); tried plain while loop (55) and byte-count/copy form (56)
#ifdef NONMATCHING
void func_002A8C48(HE8C *first, HE8C *last, int extra)
{
    HE8C *l = last;
    if ((l - first) >= 2) {
        int bytes = (char *)l - (char *)first;
        HE8C *f = first;
        do {
            bytes -= 8;
            HE8C *p = l - 1;
            HE8C v = *p;
            l--;
            HE8C w = v;
            *p = *f;
            func_002A8AA8(f, 0, bytes >> 3, w, extra);
        } while ((l - first) >= 2);
    }
}
#endif
}
