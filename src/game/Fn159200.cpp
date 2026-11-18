struct Ctl159 {
    unsigned flags;
    int pad4;
    int off;
};
struct Hdr159 {
    int pad0;
    unsigned short n;
};
struct Trk159 {
    float base;
    float scale;
    unsigned short v[1];
};

extern "C" float Ang_mult_late__Ffff(float a, float b, float t);

#ifdef NONMATCHING
// DRAFT: GAME 0x159200
// 5 words: only f1/f2 swap (base/scale vs y); tried x/y decl+assign order, switch (worse), shared-tail forms
extern "C" float func_00159200(Hdr159 *h, Ctl159 *c, float t)
{
    int i = (int)t;
    unsigned n = h->n;
    Trk159 *k = (Trk159 *)((char *)h + c->off);
    unsigned short *v = k->v;
    float y, x;
    if (i >= (int)(n - 1)) {
        x = (float)v[n - 1] * k->scale;
        y = k->base;
    } else {
        float f14 = t - (float)i;
        float f13 = (float)v[i] * k->scale + k->base;
        float f12 = (float)v[i + 1] * k->scale + k->base;
        unsigned m = c->flags & 0xF00;
        if (m == 0x300 || m == 0x400 || m == 0x500)
            return Ang_mult_late__Ffff(f12, f13, f14);
        y = f12 * f14;
        x = f13 * (1.0f - f14);
    }
    return x + y;
}
#endif
