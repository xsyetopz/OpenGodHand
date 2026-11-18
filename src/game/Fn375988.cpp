struct Fn3759Src {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
};
struct Fn3759Ent {
    int m0;
    char *m4;
    int m8;
    int mC;
    char *m10;
    int m14;
    char *m18;
    char *m1C;
};
struct Fn3759Out {
    int m0;
    int m4;
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    int m20;
    int m24;
};
extern Fn3759Ent D_0076EA50[];
extern Fn3759Out D_0076A880;
extern "C" int func_003758E8(int);

// FUNCTION: GAME 0x375988
extern "C" void func_00375988(short n, Fn3759Src *s, int a, int b)
{
    Fn3759Out *o = &D_0076A880;
    Fn3759Ent *e = &D_0076EA50[n];
    char *src = (char *)s;
    e->m0 = s->m0;
    e->m4 = src + s->m4;
    e->m8 = a;
    e->mC = b;
    if (s->m10 == 0)
        e->m10 = 0;
    else
        e->m10 = src + s->m10;
    e->m14 = s->m14;
    if (s->m18 == 0)
        e->m18 = 0;
    else
        e->m18 = src + s->m18;
    if (s->m1C == 0)
        e->m1C = 0;
    else
        e->m1C = src + s->m1C;
    o->m4 = n;
    o->m8 = e->m0;
    o->mC = (int)e->m4;
    o->m10 = e->m8;
    o->m14 = e->mC;
    o->m18 = (int)e->m10;
    o->m1C = e->m14;
    o->m20 = (int)e->m18;
    o->m24 = (int)e->m1C;
    func_003758E8(6);
}
