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
struct O37B {
    char pad0[0x27];
    signed char b27, b28, b29;
    char pad2A[2];
    int m2C;
    char pad30[8];
    int m38;
};
extern char D_003F26E8[];
extern "C" int func_00374AE0(short);

#ifdef NONMATCHING
// DRAFT: GAME 0x37B808
extern "C" int func_0037B808(O37B *o)
{
    int c = o->b27;
    E37B *e = (E37B *)((char *)D_003F26E8 + o->b28 * 0x14) + c;
    if (e->b9 == 0)
        return 0;
    short *p = e->p;
    short v = *p;
    short old = v;
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
    short hi = e->hC;
    if (v < lo)
        v = hi;
    if (hi < v)
        v = lo;
    if (v == old)
        return 0;
    *p = v;
    o->b29 = 1;
    *(int *)((char *)o + (c << 5) + 0x17C) = func_00374AE0(*(short *)((char *)o + (c << 5) + 0x16C));
    return 1;
}
#endif
