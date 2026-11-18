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

// DRAFT: GAME 0x2A8A08
// diff: 1 word, addu operand order for &h[parent] (a3=t0+v0 vs v0+t0); tried &h[parent], h+parent, (char*)h+parent*8 forms: all 1 word off
#ifdef NONMATCHING
void func_002A8A08(HE2A *h, int i, int lim, HE2A item)
{
    int parent = (i - 1) / 2;
    int c;
    HE2A *pp;
    while (lim < i && (pp = &h[parent], c = (pp->m_4 < item.m_4), c)) {
        h[i] = *pp;
        i = parent;
        parent = (i - 1) / 2;
    }
    h[i] = item;
}
#endif
}

enum eFontKind { FONT_KIND_0 };
struct FSlot2A {
    void *m_0;
    void *m_4;
    unsigned short m_8, m_a, m_c, m_e;
};
struct FSrc2A {
    int m_0;
    unsigned short m_4, m_6;
    int m_8, m_c;
    unsigned short m_10, m_12;
};
struct FDesc2A {
    unsigned short m_0, m_2, m_4;
    unsigned char m_6, m_7;
};
class cFont {
public:
    FSlot2A m_slot[1];
    void setTextureAddr(eFontKind, unsigned *, unsigned *);
};

// DRAFT: GAME 0x2A4CB0
// diff: 21 words, slot pointer lives in a0 with a v0 copy and this stays in v1 in the original
#ifdef NONMATCHING
void cFont::setTextureAddr(eFontKind kind, unsigned *a, unsigned *b)
{
    FSrc2A *src = (FSrc2A *)a;
    FDesc2A *d = (FDesc2A *)b;
    if (src && d && d->m_0 && d->m_2 && d->m_4 && d->m_6 && d->m_7 && src->m_0 && src->m_4 && src->m_6 && src->m_8 && src->m_c) {
        FSlot2A *e = &m_slot[kind];
        e->m_0 = src;
        e->m_4 = d;
        e->m_8 = d->m_2;
        e->m_a = d->m_4;
        e->m_c = d->m_6;
        e->m_e = d->m_7;
        if (src->m_0 >= 0) {
            unsigned i;
            char *base = (char *)src + src->m_8;
            unsigned *q;
            for (i = 0, q = (unsigned *)base; i < src->m_10; i++, q += 4)
                q[1] += (unsigned)base;
            q = (unsigned *)((char *)src + src->m_c);
            base = (char *)q;
            for (i = 0; i < src->m_12; i++, q += 4)
                q[1] += (unsigned)base;
            src->m_0 |= 0x80000000;
        }
    }
}
#endif
