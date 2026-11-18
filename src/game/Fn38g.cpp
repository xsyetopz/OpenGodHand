// Mid-size functions in the ProDG game-code island 0x370000-0x387430.

struct Fn38Obj {
    char _pad0[0x30];
    float m_30;
    char _pad34[0x8];
    float m_3C;
    float m_40;
};

extern "C" int func_00373A50(Fn38Obj *o);
extern "C" int func_00373B20(Fn38Obj *o);

// FUNCTION: GAME 0x3739A0
extern "C" void func_003739A0(Fn38Obj *o, int idx, float f)
{
    if (func_00373A50(o)) {
        if (func_00373B20(o) == 1) {
            o->m_40 = f;
            if (idx == 1)
                o->m_3C = f;
        } else {
            o->m_30 = f;
            if (idx == 1)
                *(float *)((char *)o + 0x2C) = f;
        }
    }
}

extern "C" void *memset(void *, int, unsigned);

// FUNCTION: GAME 0x375B90
extern "C" void func_00375B90(short a, short b, short *p)
{
    memset(p, 0, 0x30);
    p[1] = b;
    p[0] = a;
    ((unsigned short *)p)[7] = 0x8000;
}

struct Fn38Msg {
    char _pad0[4];
    int m_04;
    char _pad8[2];
    short m_0A;
};

extern "C" void *func_00376A90(int);
extern "C" void func_00376260(void *, Fn38Msg *);
extern "C" void func_003762D8(void *, Fn38Msg *);

// FUNCTION: GAME 0x376200
extern "C" int func_00376200(Fn38Msg *o)
{
    void *x = func_00376A90(o->m_04);
    if (!x)
        return -1;
    if (o->m_0A == 0)
        func_00376260(x, o);
    else
        func_003762D8(x, o);
    return 0;
}

struct Fn38Ent {
    unsigned short m_00;
    char _pad2[2];
    int m_04;
    unsigned char m_08;
    char _pad9[0x37];
};
extern Fn38Ent D_0076F050[];

// FUNCTION: GAME 0x3769B0
extern "C" Fn38Ent *func_003769B0(int key)
{
    int i;
    Fn38Ent *e = D_0076F050;
    for (i = 0; i < 0x60; i++, e++) {
        if (e->m_00 == 0)
            continue;
        if (e->m_08 & 0x10)
            continue;
        if (key == 0)
            return e;
        if (e->m_04 == key)
            return e;
    }
    return 0;
}

struct Fn38Cmd {
    unsigned short m_00;
    unsigned short m_02;
    int m_04;
    int m_08;
    unsigned char m_0C;
    unsigned char m_0D;
    unsigned short m_0E;
    short m_10;
    unsigned short m_12;
    unsigned short m_14;
    char _pad16[0x14];
    unsigned short m_2A;
    char _pad2C[4];
    unsigned short m_30;
    unsigned short m_32;
    unsigned short m_34;
    char _pad36[6];
    unsigned short m_3C;
};

struct Fn38Src {
    unsigned short m_00;
    unsigned short m_02;
    int m_04;
    unsigned short m_08;
    unsigned short m_0A;
    unsigned short m_0C;
    unsigned short m_0E;
    unsigned short m_10;
};

extern "C" Fn38Cmd *func_0037D170(void);
extern "C" void func_00376CF8(Fn38Src *, Fn38Cmd *);
extern "C" void func_003768B0(Fn38Src *);

// FUNCTION: GAME 0x376588
extern "C" int func_00376588(Fn38Src *a, Fn38Src *b)
{
    Fn38Cmd *c = func_0037D170();
    if (!c)
        return 0;
    {
        c->m_00 = 1;
        c->m_04 = b->m_04;
        c->m_08 = a->m_04;
        c->m_0C = 0x10;
        c->m_0D = 4;
        c->m_10 = -1;
        c->m_0E = 0;
        c->m_12 = a->m_02;
        c->m_14 = b->m_02;
        func_00376CF8(a, c);
    }
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x376618
// diff: 11 words; a/b swapped between s1 and s2 (otherwise identical)
extern "C" int func_00376618(Fn38Src *a, Fn38Src *b)
{
    Fn38Cmd *c;
    func_003768B0(a);
    c = func_0037D170();
    if (!c)
        return 0;
    {
        c->m_00 = 1;
        c->m_04 = b->m_04;
        c->m_08 = a->m_04;
        c->m_0C = 0x10;
        c->m_0D = 4;
        c->m_0E = 1;
        c->m_10 = 0;
        c->m_12 = a->m_02;
        c->m_14 = b->m_02;
        func_00376CF8(a, c);
        c->m_2A = 0xD;
        c->m_30 = b->m_0C;
        c->m_32 = b->m_0C;
        c->m_34 = b->m_0E;
        c->m_3C = b->m_10;
        return 0;
    }
    return 0;
}
#endif

struct Fn38Slot {
    unsigned short m_00;
    char _pad02[0x10];
    short m_12;
};

struct Fn38Mgr {
    char _pad0[0x40];
    Fn38Slot m_40[8];
};

extern "C" void func_00376B80(Fn38Mgr *, Fn38Slot *);

// FUNCTION: GAME 0x376720
extern "C" void func_00376720(Fn38Mgr *o)
{
    Fn38Slot *p = o->m_40;
    int i = 7;
    do {
        unsigned h = p->m_00;
        if (h != 0 && (h & 2) == 0) {
            if (p->m_12 == 0) {
                p->m_00 = h | 2;
                func_00376B80(o, p);
            } else
                p->m_12--;
        }
        p = (Fn38Slot *)((char *)p + 0x14);
    } while (--i >= 0);
}

struct Fn38Evt {
    unsigned short m_00;
    char _pad02[0x10];
    unsigned short m_12;
    char _pad14[4];
    short m_18;
    short m_1A;
    char _pad1C[4];
    short m_20;
    short m_22;
    short m_24;
    short m_26;
};

extern "C" void func_00376AE0(Fn38Evt *, int);
extern "C" void func_00378070(short *);
extern "C" short func_003780B0(int, int);
extern "C" void func_00376D28(Fn38Evt *, int);

// FUNCTION: GAME 0x3767B0
extern "C" void func_003767B0(Fn38Evt *o)
{
    unsigned h = o->m_00;
    if (h & 0x100) {
        short a = o->m_18;
        short b = o->m_1A;
        o->m_00 = h & 0xFEFF;
        if (a == b) {
            if (a == 0)
                func_00376AE0(o, 0);
        } else {
            func_00378070(&o->m_18);
            o->m_12 |= 1;
        }
    }
}

// FUNCTION: GAME 0x376820
extern "C" void func_00376820(Fn38Evt *o)
{
    if (o->m_12 & 1) {
        o->m_24 = func_003780B0(o->m_20, o->m_18);
        o->m_26 = func_003780B0(o->m_22, o->m_18);
        func_00376D28(o, 1);
    }
    if (o->m_12 & 2)
        func_00376D28(o, 2);
    if (o->m_12 & 4)
        func_00376D28(o, 4);
    o->m_12 = 0;
}
