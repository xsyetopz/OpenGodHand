// Small functions in the ProDG game-code island (ee-gcc2.95.3-136, C++).

struct Fn379F0E {
    short h[16];
};
struct Fn379F0 {
    char _0[7];
    signed char m_7;
    char _8[0xE];
    short m_16[3];
    char _1C[0x10];
    unsigned m_2C;
    char _30[8];
    unsigned m_38;
};
extern Fn379F0E Sde_iss_hed[];
extern Fn379F0E D_0076E510[];
extern Fn379F0E D_0076EA50[];

// FUNCTION: GAME 0x379F00
extern "C" int func_00379F00(Fn379F0 *p)
{
    int cnt = 0;
    int s = p->m_7;
    int idx = *(short *)((int)p + (s << 1) + 0x16);
    switch (s) {
    case 0: cnt = Sde_iss_hed[idx].h[0]; break;
    case 1: cnt = D_0076E510[idx].h[0]; break;
    case 2: cnt = D_0076EA50[idx].h[10]; break;
    }
    short *b = (short *)((char *)p + 0x1C);
    int o = p->m_7;
    short *q = b + o;
    short cur = *q;
    short old = cur;
    unsigned f = p->m_38;
    int step = 1;
    if (p->m_2C & 8)
        step = 10;
    if (f & 0x80000001)
        cur -= step;
    if (f & 0x40000002)
        cur += step;
    if (cur < 0)
        cur = cnt - 1;
    if (cur >= cnt)
        cur = 0;
    if (cur != old) {
        *q = cur;
        return 1;
    }
    return 0;
}
