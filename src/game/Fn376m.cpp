// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

extern "C" void *memset(void *, int, unsigned);
struct Fn38Hdr {
    short m_0;
    short m_2;
    char _p4[0xA];
    unsigned short m_E;
    char _p10[0x20];
};

// FUNCTION: GAME 0x375B90
extern "C" void func_00375B90(short a, short b, Fn38Hdr *p)
{
    memset(p, 0, 0x30);
    p->m_2 = b;
    p->m_0 = a;
    p->m_E = 0x8000;
}

extern "C" void *func_00376A90(int);
struct Fn376Obj;
struct Fn376Src;
extern "C" void func_00376260(Fn376Obj *, Fn376Src *);
extern "C" void func_003762D8(Fn376Obj *, Fn376Src *);
struct Fn38Req {
    char _p0[4];
    int m_4;
    char _p8[2];
    short m_A;
};

// FUNCTION: GAME 0x376200
extern "C" int func_00376200(Fn38Req *r)
{
    void *q = func_00376A90(r->m_4);
    if (q == 0)
        return -1;
    if (r->m_A == 0)
        func_00376260((Fn376Obj *)q, (Fn376Src *)r);
    else
        func_003762D8((Fn376Obj *)q, (Fn376Src *)r);
    return 0;
}

struct Fn38Flags {
    char _p0[0x22];
    unsigned short m_22;
};
extern Fn38Flags D_0076A790;
extern "C" void func_0037D9B0(int, int);

// FUNCTION: GAME 0x375FA0
extern "C" void func_00375FA0(void)
{
    Fn38Flags *f = &D_0076A790;
    if (f->m_22 & 0x10) {
        f->m_22 &= ~0x10;
        func_0037D9B0(4, 1);
    }
    if (f->m_22 & 0x20) {
        f->m_22 &= ~0x20;
        func_0037D9B0(4, 2);
    }
}

struct Fn38Sif {
    int m_0;
    void *m_4;
    void *m_8;
};
extern Fn38Sif D_0076A880;
extern char D_0076A9C0[], D_0076B1C0[];
extern "C" void sceSifInitRpc(int);
extern "C" void func_00377BC8(void);
extern "C" void func_00375860(void);
extern "C" int func_003758E8(int);


// FUNCTION: GAME 0x376E38
extern "C" void func_00376E38(void)
{
    Fn38Flags *f = &D_0076A790;
    if (f->m_22 & 4) {
        f->m_22 &= ~4;
        func_0037D9B0(2, 1);
    }
    if (f->m_22 & 8) {
        f->m_22 &= ~8;
        func_0037D9B0(2, 2);
    }
}

// FUNCTION: GAME 0x375318
// func_003758E8 is declared int-returning (its definition returns int); a void declaration swaps the v0/v1 order of the +4/+8 stores.
extern "C" void func_00375318(void)
{
    Fn38Sif *s = &D_0076A880;
    sceSifInitRpc(0);
    func_00377BC8();
    func_00375860();
    s->m_4 = D_0076A9C0;
    s->m_8 = D_0076B1C0;
    func_003758E8(0);
    func_003758E8(1);
}

#ifdef NONMATCHING
struct Fn38Obj {
    int m_0;
    char _p4[8];
    int m_C;
    int m_10;
};
extern "C" void func_0032ABE8(float, int, int, int);

// DRAFT: GAME 0x3741B0
// diff: original copies the argument into v0 and loads m_0 into a0; mine keeps the argument in a0 (about 10 words).
extern "C" void func_003741B0(Fn38Obj *o, float f)
{
    if (o->m_0 == 0)
        return;
    if (f == 0.0f)
        f = 2.0f;
    func_0032ABE8(f, o->m_0, o->m_10, o->m_C);
}
#endif

struct Fn376Ent {
    unsigned short m_0;
    char _p2[6];
    unsigned char m_8;
    char _p9[0x37];
};
extern Fn376Ent D_0076F050[];
extern "C" int func_00376080(Fn376Ent *);

// FUNCTION: GAME 0x376008
extern "C" void func_00376008(void)
{
    Fn376Ent *p = D_0076F050;
    for (int i = 0x5F; i >= 0; i--, p++) {
        if (p->m_0 != 0) {
            if (p->m_8 & 0x10)
                func_00376200((Fn38Req *)p);
            else
                func_00376080(p);
            p->m_0 = 0;
        }
    }
}

struct Fn376Obj {
    unsigned short m_0;
    char _p2[0x10];
    unsigned short m_12;
    char _p14[4];
    short m_18;
    short m_1A;
    char _p1C[2];
    unsigned short m_1E;
    unsigned short m_20;
    unsigned short m_22;
    char _p24[4];
    unsigned short m_28;
    unsigned short m_2A;
};
struct Fn376Src {
    char _p0[2];
    unsigned short m_2;
    char _p4[2];
    short m_6;
    char _p8[0x12];
    unsigned short m_1A;
    char _p1C[0xC];
    unsigned short m_28;
    unsigned short m_2A;
    unsigned short m_2C;
    char _p2E[6];
    unsigned short m_34;
};
extern "C" void func_00376AE0(Fn376Obj *, short);
extern "C" void func_00378020(void *);
extern "C" void func_00378070(void *);

// FUNCTION: GAME 0x376260
extern "C" void func_00376260(Fn376Obj *o, Fn376Src *s)
{
    s = (Fn376Src *)((char *)s + 0x20);
    if ((unsigned short)(s->m_6 + 1) < 2) {
        func_00376AE0(o, s->m_6);
    } else {
        o->m_1A = s->m_2 << 8;
        o->m_1E = s->m_6;
        func_00378020(&o->m_18);
        o->m_0 |= 0x100;
    }
}

// FUNCTION: GAME 0x3762D8
extern "C" void func_003762D8(Fn376Obj *d, Fn376Src *s)
{
    if (s->m_1A & 1) {
        d->m_20 = s->m_28;
        d->m_12 |= 1;
    }
    if (s->m_1A & 2) {
        d->m_22 = s->m_2A;
        d->m_12 |= 1;
    }
    if (s->m_1A & 4) {
        d->m_28 = s->m_2C;
        d->m_12 |= 2;
    }
    if (s->m_1A & 8) {
        unsigned short t = s->m_34;
        d->m_2A = t;
        d->m_12 |= 4;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3767B0
// diff: a0 vs v1 register allocation and beql/beqz layout
extern "C" void func_003767B0(Fn376Obj *p)
{
    unsigned short a = p->m_0;
    if (a & 0x100) {
        p->m_0 = a & 0xFEFF;
        if (p->m_18 == p->m_1A) {
            if (p->m_18 == 0)
                func_00376AE0(p, 0);
        } else {
            func_00378070(&p->m_18);
            p->m_12 |= 1;
        }
    }
}
#endif
