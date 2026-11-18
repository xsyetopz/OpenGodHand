// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

extern "C" int func_00377FF8(void);
extern "C" void func_003768B0(void *, void *);
struct Fn376Req {
    unsigned short m_0;
    char _p2[2];
    int m_4;
    unsigned short m_8;
    unsigned short m_A;
};
struct Fn376Par {
    char _p0[8];
    unsigned short m_8;
    char _pA[0x26];
    struct {
        char _p0[6];
        unsigned short m_6;
    } *m_30;
};

// FUNCTION: GAME 0x376510
extern "C" int func_00376510(Fn376Par *x, Fn376Req *r)
{
    unsigned short v = r->m_0;
    if ((v & 1) && !(v & 2))
        return 0;
    r->m_0 = 1;
    r->m_4 = func_00377FF8();
    r->m_8 = x->m_8;
    r->m_A = x->m_30->m_6;
    func_003768B0(x, r);
    return 0;
}

struct Fn376Slot {
    unsigned short m_0;
    char _p2[2];
    int m_4;
    int m_8;
    unsigned char m_C;
    unsigned char m_D;
    short m_E;
    short m_10;
    unsigned short m_12;
    unsigned short m_14;
};
struct Fn376Pair {
    char _p0[2];
    unsigned short m_2;
    int m_4;
};
extern "C" Fn376Slot *func_0037D170(void);
extern "C" void func_00376CF8(Fn376Pair *, Fn376Slot *);

#ifdef NONMATCHING
// DRAFT: GAME 0x376588
// diff: 2 words, sw to +4 and lw of a->m_4 swap
extern "C" int func_00376588(Fn376Pair *a, Fn376Pair *b)
{
    Fn376Slot *e = func_0037D170();
    if (e) {
        e->m_0 = 1;
        int x = b->m_4;
        int y = a->m_4;
        e->m_4 = x;
        e->m_C = 0x10;
        e->m_8 = y;
        e->m_D = 4;
        e->m_10 = -1;
        e->m_E = 0;
        e->m_12 = a->m_2;
        e->m_14 = b->m_2;
        func_00376CF8(a, e);
    }
    return 0;
}
#endif

extern "C" short func_003780B0(short, short);
extern "C" void func_00376D28(void *, int);
struct Fn376Mix {
    char _p0[0x12];
    unsigned short m_12;
    char _p14[4];
    short m_18;
    char _p1A[6];
    short m_20;
    short m_22;
    short m_24;
    short m_26;
};

// FUNCTION: GAME 0x376820
extern "C" void func_00376820(Fn376Mix *p)
{
    if (p->m_12 & 1) {
        p->m_24 = func_003780B0(p->m_20, p->m_18);
        p->m_26 = func_003780B0(p->m_22, p->m_18);
        func_00376D28(p, 1);
    }
    if (p->m_12 & 2)
        func_00376D28(p, 2);
    if (p->m_12 & 4)
        func_00376D28(p, 4);
    p->m_12 = 0;
}
