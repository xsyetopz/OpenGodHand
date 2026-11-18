struct V { float f[4]; V() { __asm__ volatile("sqc2 $vf0,%0" : "=m"(*this)); } };
extern unsigned D_00747A78;
extern "C" char *Getplayer__Fv();

// FUNCTION: GAME 0x2C1CC8
extern "C" int func_002C1CC8()
{
    char *pl = Getplayer__Fv();
    V v[2];
    int r = 0;
    if (!(D_00747A78 & 0x2000000)) {
        float *src = *(float **)(pl + 0xF0);
        if ((float *)&v[0] != src) {
            v[0].f[0] = src[0];
            v[0].f[1] = src[1];
            v[0].f[2] = src[2];
        }
        r = 1;
        v[0].f[1] = v[0].f[1] + 1.0f;
    }
    return r;
}

extern "C" char *func_002C30C0(char *);
extern "C" char *func_002C30C8(char *, char *);

// FUNCTION: GAME 0x2C1540
extern "C" void func_002C1540(char *self)
{
    char *o = func_002C30C0(self);
    while ((o = func_002C30C8(self, o)) != 0) {
        unsigned *p = (unsigned *)(o + 0x50);
        unsigned v = *p & 0xBFFFFFFF;
        *p = v;
        if (v & 0x80000000)
            *p = v | 0x40000000;
        *p &= 0x7FFFFFFF;
        *p &= 0xF7FFFFFF;
        *p &= 0xFBFFFFFF;
        *p &= 0xFDFFFFFF;
    }
}
