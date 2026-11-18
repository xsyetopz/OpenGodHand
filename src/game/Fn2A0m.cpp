// Free units in 0x2A0000-0x2AFFFF, 0x80-0x200 bytes.
extern "C" {
struct Ent2A {
    char _p[0xA0];
    unsigned short m_a0, m_a2, m_a4, m_a6, m_a8;
    char _p1[0xAC - 0xAA];
};
struct Pool2A {
    char _p[4];
    char *m_4;
    char _p1[4];
    int m_c;
    char _p2[0x1C - 0x10];
    unsigned char m_1c;
};

// FUNCTION: GAME 0x2AABA0
void func_002AABA0(Pool2A *self)
{
    if (self->m_1c != 0) {
        for (int i = 0; i < self->m_c; i++) {
            Ent2A *e = (Ent2A *)(self->m_4 + i * 0xAC);
            if (e != 0) {
                e->m_a0++;
                e->m_a2++;
                e->m_a6++;
                e->m_a8++;
                e->m_a4++;
            }
        }
    }
}

struct FL2A {
    char *m_0;
    int m_4;
    int m_8;
    int m_c;
    int *m_10;
    int m_14;
};

// FUNCTION: GAME 0x2A9708
void func_002A9708(FL2A *self)
{
    int t = self->m_c + 7;
    int stride = (self->m_4 + t) & -self->m_c;
    char *base = self->m_0;
    int n = self->m_8;
    while (n != 0) {
        char *p = base + self->m_4;
        *(int *)p = (int)(p - stride);
        *(int *)(p + 4) = (int)(p + stride);
        base += stride;
        n--;
    }
    int *first = (int *)(self->m_0 + self->m_4);
    *first = 0;
    *(int *)(self->m_0 + stride * (self->m_8 - 1) + self->m_4 + 4) = 0;
    self->m_10 = first;
    self->m_14 = 0;
}

struct HE2A {
    int m_0;
    float m_4;
};

// FUNCTION: GAME 0x2A8A08
void func_002A8A08(HE2A *h, int i, int lim, HE2A item)
{
    int parent = (i - 1) / 2;
    int c;
    while (lim < i && (c = (h[parent].m_4 < item.m_4), c)) {
        h[i] = h[parent];
        i = parent;
        parent = (i - 1) / 2;
    }
    h[i] = item;
}
}
