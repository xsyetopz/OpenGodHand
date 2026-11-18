struct D3C {
    int m0, m4, m8, mC, m10, m14, m18;
    unsigned short h1C, h1E, h20, h22, h24, h26;
    int m28, m2C, m30, m34, m38, m3C, m40;
    float f44, f48, f4C;
    int m50, m54, m58, m5C, m60;
};
struct D3S {
    int s0;
    unsigned short h4, h6, h8, hA, hC, hE;
    int s10, s14, s18, s1C, s20, s24, s28, s2C;
};
extern "C" int SdeSystemOutModeGet(void);
extern "C" int func_002D3D88(void *);
extern "C" void func_00345F48(int, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x2D3C78
extern "C" int func_002D3C78(D3C *d, D3S *s)
{
    d->h1C = s->h4;
    d->h1E = s->h6;
    d->h20 = s->h8;
    d->h22 = s->hA;
    d->h24 = s->hC;
    d->h26 = s->hE;
    d->m28 = s->s14;
    d->m2C = s->s18;
    d->m30 = s->s1C;
    d->m34 = s->s10;
    d->m38 = s->s20;
    float f;
    if (SdeSystemOutModeGet() == 2)
        f = (float)s->s28;
    else
        f = (float)s->s24;
    d->f48 = f;
    d->f44 = f;
    d->m50 = 0;
    d->m3C = s->s2C;
    d->f4C = 1.0f;
    d->m5C = -1;
    d->m58 = -1;
    if (func_002D3D88(d) == 0)
        return 0;
    d->m60 = 0;
    if (!(d->m3C & 2))
        func_00345F48(d->m0, 1);
    return 1;
}
#endif
