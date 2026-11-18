// Small units in 0x1F8000-0x200000.

struct Fn1V { float x, y, z; void set(const Fn1V *s) { x = s->x; y = s->y; z = s->z; } };
struct Fn1P { char _p0[0xC0]; Fn1V *m_C0; };
struct Fn1Q { char _p0[0x34]; Fn1P *m_34; };
struct Fn1N {
    Fn1V m_0;
    float _pc;
    Fn1V m_10;
    float _p1c;
    char _p20[4];
    Fn1N *m_24;
    Fn1Q *m_28;
};
struct Fn1O { char _p0[0x34]; int m_34; Fn1N *m_38; Fn1N *m_3C; };
// FUNCTION: GAME 0x1FCEB0
extern "C" void func_001FCEB0(Fn1O *o)
{
    Fn1N *n = o->m_3C;
    o->m_34 = 0;
    while (n) {
        Fn1V *src = n->m_28->m_34->m_C0;
        if ((Fn1V *)n != src)
            n->m_0.set(src);
        Fn1V *d = &n->m_10;
        if (d != (Fn1V *)n)
            d->set(&n->m_0);
        n = n->m_24;
    }
}

struct Fn1A { char _p0[0x70]; int m_70[5]; };
struct Fn1B { Fn1A *m_0; };
// FUNCTION: GAME 0x1FAAB0
extern "C" void func_001FAAB0(Fn1B *o, unsigned i, int v)
{
    if (o->m_0 != 0) {
        if (i >= 5)
            i = 0;
        o->m_0->m_70[i] += v;
        if (o->m_0->m_70[i] >= 10)
            o->m_0->m_70[i] = 9;
        if (o->m_0->m_70[i] < 0)
            o->m_0->m_70[i] = 0;
    }
}

struct Fn1D { char _p0[0x98]; char m_98[10]; };
struct Fn1C { Fn1D *m_0; };
extern "C" void func_001FC170(Fn1C *, int, int);
// FUNCTION: GAME 0x1FC278
extern "C" void func_001FC278(Fn1C *o)
{
    if (o->m_0 != 0) {
        for (unsigned i = 0; i < 10; i++)
            o->m_0->m_98[i] = 0x1F;
        func_001FC170(o, 0, 1);
        func_001FC170(o, 1, 2);
        func_001FC170(o, 2, 3);
        func_001FC170(o, 3, 7);
        func_001FC170(o, 4, 0xE);
        func_001FC170(o, 5, 0x17);
    }
}

struct Fn1E { int m_0; };
extern "C" void func_001FF238(Fn1E *);
extern "C" void func_001FF338(Fn1E *);
// FUNCTION: GAME 0x1FF110
extern "C" void func_001FF110(Fn1E *o)
{
    switch (o->m_0) {
    case 0:
    case 2:
    case 3:
    case 4:
    case 8:
        break;
    case 1: func_001FF238(o); break;
    case 5: o->m_0 = 6; break;
    case 6: o->m_0 = 7; break;
    case 7: func_001FF338(o); break;
    }
}

extern "C" void func_001FCE20(char *);
extern "C" void func_001FD3B8(char *);
// FUNCTION: GAME 0x1FDE00
extern "C" char *func_001FDE00(char *o)
{
    char *p = o;
    int i = 0x9F;
    do {
        func_001FCE20(p);
        i--;
        p += 0x60;
    } while (i != -1);
    p = o + 0x3C00;
    i = 0xFF;
    do {
        func_001FD3B8(p);
        i--;
        p += 0x70;
    } while (i != -1);
    func_001FCE20(o + 0xAC00);
    func_001FD3B8(o + 0xAC60);
    return o;
}
