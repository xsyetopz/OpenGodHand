struct E37B {
    short *p;
    char pad4[5];
    char b9;
    short hA;
    unsigned short hC;
    short hE;
    short h10;
    char pad12[0x78 - 0x12];
};
struct S37B {
    short h0;
    char pad2[0xE];
    int w10;
    char pad14[0xC];
};
struct O37B {
    char pad0[0x27];
    signed char b27, b28, b29;
    char pad2A[2];
    int m2C;
    char pad30[8];
    int m38;
    char pad3C[0x16C - 0x3C];
    S37B sl[8];
};
extern char D_003F26E8[];
extern "C" int func_00374AE0(short);

#ifdef NONMATCHING
// DRAFT: GAME 0x37B808
// 46 differing words: reg allocation (e in a1 not a0, old/p regs swapped) and first clamp uses movz not branch, mult order; tried slot struct, early return vs nested if, old/v decl order
extern "C" int func_0037B808(O37B *o)
{
    int c = o->b27;
    E37B *e = (E37B *)(c * 0x78 + (o->b28 * 0x14 + (int)D_003F26E8));
    int rv = 0;
    if (e->b9 == 0)
        return rv;
    short *p = e->p;
    short old = *p;
    short v = old;
    short step;
    if (o->m2C & 8)
        step = e->h10;
    else
        step = e->hE;
    int k = o->m38;
    if (k & 0x8000)
        v -= step;
    if (k & 0x2000)
        v += step;
    short lo = e->hA;
    unsigned short hi = e->hC;
    if (v < lo)
        v = (short)hi;
    short r = ((short)hi < v) ? lo : v;
    if (r != old) {
        *p = r;
        o->b29 = 1;
        o->sl[c].w10 = func_00374AE0(o->sl[c].h0);
        rv = 1;
        return rv;
    }
    return 0;
}
#endif
