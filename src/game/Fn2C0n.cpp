// Free units in 0x2C0000-0x2DFFFF, 0x80-0x200 bytes.
extern char Snd[];
extern "C" {
struct Link2C {
    int m_0;
    int m_4;
};
struct Snd2C {
    char _p[0x8C];
    int m_8c, m_90;
    char _p1[4];
    unsigned m_98;
    char _p2[0xA4 - 0x9C];
    Link2C *m_a4;
    char _p3[0xBC - 0xA8];
    int m_bc, m_c0;
};
// FUNCTION: GAME 0x2C31D0
float func_002C31D0(float x)
{
    if (x >= 3.1415927f) {
        do
            x -= 6.2831855f;
        while (x >= 3.1415927f);
    } else if (x < -3.1415927f) {
        do
            x += 6.2831855f;
        while (x < -3.1415927f);
    }
    return x;
}

// DRAFT: GAME 0x2CCB58
// diff: 40 words, original keeps 1 in a1 and uses movz for the (f & 8) result; ours folds to sra/andi
#ifdef NONMATCHING
int func_002CCB58(Snd2C *self)
{
    self->m_c0 = self->m_bc;
    int r = 0;
    if (self->m_8c - 0x80 == *(int *)(Snd + 0x118))
        r = (self->m_90 == *(int *)(Snd + 0x11C));
    int ok = 1;
    if (r == ok) {
        self->m_98 |= 8;
        self->m_bc = *(int *)(Snd + 0x120);
        return ok;
    }
    unsigned f = self->m_98;
    self->m_98 = f & ~8;
    r = ok;
    if (!(f & 8))
        r = 0;
    if (self->m_a4 != 0)
        self->m_bc = self->m_a4->m_4;
    return r;
}
#endif

extern int D_00747A84;
struct Node2C {
    Node2C *m_0;
    char _p[0xE - 4];
    unsigned char m_e;
    char _p1[3];
    unsigned char m_12, m_13;
    int m_14;
};
struct Hdr2C {
    char _p[4];
    float m_4;
    int m_8;
    int m_c;
};
struct Pool2C {
    char _p[0x2C];
    Node2C *m_2c;
};

// FUNCTION: GAME 0x2CB080
void func_002CB080(Pool2C *self, Hdr2C *h)
{
    D_00747A84 &= ~0x800;
    self->m_2c = 0;
    if (h != 0) {
        float v = h->m_4;
        Node2C *p = (Node2C *)((char *)h + h->m_8);
        if (v == 0.0f)
            return;
        if (v == 1.1f && h->m_c == 0)
            return;
        do {
            Node2C *next = p->m_0;
            p->m_0 = 0;
            Node2C *old = self->m_2c;
            self->m_2c = p;
            p->m_0 = old;
            p->m_12 = 0;
            p->m_13 = 0;
            p->m_14 = 0;
            if (next == 0)
                break;
            p = (Node2C *)((char *)p + p->m_e * 16 + 0x30);
        } while (p != 0);
    }
}
}
