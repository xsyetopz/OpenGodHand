// Sound-bank selector step (ee-gcc 2.95.3-136, C++).

extern "C" {
int func_00323918(int, int);
int func_00323E80(int, int, int);
void *func_0031C8B8(unsigned, unsigned);
int printf(const char *, ...);
}
extern char D_0045CA58[];

struct Fn383Sub {
    char _p0;
    char m_1;
    char _p2[2];
    char m_4;
    char _p5[0xEF];
    int m_F4;
    void *m_F8;
    char *m_FC;
};
struct Fn383Obj {
    char _p0[2];
    char m_2;
    char _p3[3];
    unsigned char m_6;
    char _p7[0x369];
    Fn383Sub s;
};
struct Fn383In {
    char _p0[0x38];
    int m_38;
};

// FUNCTION: GAME 0x383708
extern "C" void func_00383708(Fn383Obj *o, Fn383In *in)
{
    Fn383Sub *s = &o->s;
    int f = in->m_38;
    char *t = s->m_FC;
    if (f & 0x8000) {
        unsigned char v = o->m_6;
        if (v == 0)
            v = t[8];
        o->m_6 = v - 1;
    } else if (f & 0x2000) {
        unsigned char c = o->m_6;
        if (c < *(int *)(t + 8) - 1)
            o->m_6 = c + 1;
        else
            o->m_6 = 0;
    } else
        return;
    s->m_4 = 0;
    s->m_F4 = func_00323918(0xFF, o->m_6);
    void *r = func_0031C8B8(0x800, 0x40);
    s->m_F8 = r;
    if (r == 0) {
        printf(D_0045CA58);
        s->m_1 = 1;
        return;
    }
    func_00323E80(s->m_F4, 1, (int)r);
    o->m_2 = 1;
}
