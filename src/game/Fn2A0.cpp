// Small units in 0x2A0000-0x2AFFFF (round 24).
extern "C" void ObjTrans__Fv();
extern "C" void func_002AF028(char *);
extern "C" void *__11PathFinding(void *);
extern "C" void func_002A9708(void *);
extern char *Message;

// FUNCTION: GAME 0x2AF1F8
extern "C" unsigned getCodeSize__11cMessCommonUs(unsigned short a)
{
    if ((a >> 15) != 0)
        return a & 0xF;
    return 1;
}

struct S2A {
    char _pad[0x1B2];
    short m_1b2;
};

// FUNCTION: GAME 0x2A6C50
extern "C" int isReleaseActiveHeap__5cGame(S2A *s)
{
    if (s->m_1b2 > 0) {
        s->m_1b2--;
        return 0;
    }
    return 1;
}

struct Lk {
    int m_0;
    Lk *m_4;
    Lk *m_8;
};

// FUNCTION: GAME 0x2A9620
extern "C" void func_002A9620(int v, Lk *n, Lk *h)
{
    Lk *t = h->m_8;
    n->m_0 = v;
    n->m_8 = t;
    n->m_4 = h;
    if (h->m_8)
        h->m_8->m_4 = n;
    h->m_8 = n;
}

// FUNCTION: GAME 0x2AE718
extern "C" void Trans__3cMc(void)
{
    ObjTrans__Fv();
    func_002AF028(Message);
}

// FUNCTION: GAME 0x2A5AD0
extern "C" char *func_002A5AD0(char *self)
{
    __11PathFinding(self + 0x18C);
    return self;
}

struct Slot {
    int m_a;
    int m_b;
    int m_c;
};
struct Slots {
    char _pad[0xC];
    Slot m_s[32];
};

// FUNCTION: GAME 0x2A6C78
extern "C" void func_002A6C78(Slots *s)
{
    for (int i = 0; i < 32; i++) {
        s->m_s[i].m_a = 0xFFFF;
        s->m_s[i].m_b = -1;
        s->m_s[i].m_c = 0;
    }
}

// FUNCTION: GAME 0x2A96D8
extern "C" void func_002A96D8(int *s, int a, int b, int c, int d)
{
    s[0] = a;
    s[1] = b;
    s[2] = c;
    s[3] = d;
    func_002A9708(s);
}

struct Cmp {
    char _pad[4];
    float m_4;
    char _pad2[4];
    float m_c;
    char _pad3[4];
    int m_14;
};

// FUNCTION: GAME 0x2A9BC0
extern "C" int GetHeatLv__8cHeatSys(Cmp *s)
{
    if (s->m_4 < s->m_c)
        s->m_14 = 0;
    else
        s->m_14 = 1;
    return s->m_14;
}
