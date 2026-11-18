// Units in .text 0x150000-0x15FFFF (continued).
extern "C" void Gp_draw_poly4__FPA3_CfUiUiPC7GP_INFO7eOtTypeUi(float *, unsigned, unsigned, void *, int, unsigned);

// FUNCTION: GAME 0x15F2B0
extern "C" void Draw_Poly_sc__FPA3_CfUi(float *v, unsigned c)
{
    Gp_draw_poly4__FPA3_CfUiUiPC7GP_INFO7eOtTypeUi(v, c, 1, 0, 8, 2);
}

struct MPE {
    unsigned w;
    unsigned x[2];
};
struct MPH {
    char _p[6];
    unsigned char n;
    char _q;
    MPE e[1];
};

// FUNCTION: GAME 0x1594A0
extern "C" int MotionIsHaveParam__FPvii(void *p, int a, int b)
{
    MPH *h = (MPH *)p;
    unsigned i;
    MPE *e;
    if (h == 0) {
        return 0;
    }
    for (i = 0, e = h->e; i < h->n; i++, e++) {
        if ((char)e->w == a) {
            if (b == -1 || ((e->w >> 8) & 0xF) == b) {
                return 1;
            }
        }
    }
    return 0;
}

union FU {
    float f;
    unsigned u;
};

// FUNCTION: GAME 0x156488
extern "C" float F16toF32__FUs(unsigned short h)
{
    unsigned v = h;
    unsigned m = v & 0x3FF;
    unsigned e;
    unsigned s;
    FU r;
    if ((v & 0x7C00) != 0) {
        s = v & 0x8000;
        e = (v >> 10) & 0x1F;
    } else if (m != 0) {
        e = 1;
        s = v & 0x8000;
        do {
            m <<= 1;
            e--;
        } while ((m & 0x400) == 0);
        m &= 0x3FF;
    } else {
        e = 0xFFFFFF90u;
        s = v & 0x8000;
    }
    r.u = (s << 16) | ((e + 0x70) << 23) | (m << 13);
    return r.f;
}
