extern "C" {
struct HE8A {
    int m_0;
    float m_4;
};

void func_002A8A08(HE8A *h, int i, int lim, long item);

// DRAFT: GAME 0x2A8AA8
// 22 words differ: only register numbering (original uses t1/t2/t3, we t0/t1/t2; t0 unused); tried struct copy by value, long reassembly of item via lwu pair (fixes tail), c = cmp; sc -= c, unused 5th param (no effect)
#ifdef NONMATCHING
void func_002A8AA8(HE8A *h, int hole, int len, HE8A item, int cmp)
{
    int top = hole;
    int sc = top * 2 + 2;
    while (sc < len) {
        int c = h[sc].m_4 < h[sc - 1].m_4;
        sc -= c;
        h[hole] = h[sc];
        hole = sc;
        sc = (hole + 1) * 2;
    }
    if (sc == len) {
        h[hole] = h[sc - 1];
        hole = sc - 1;
    }
    HE8A v = item;
    unsigned lo = *(unsigned *)&v;
    unsigned long hi = ((unsigned *)&v)[1];
    func_002A8A08(h, hole, top, (hi << 32) | lo);
}
#endif
}
