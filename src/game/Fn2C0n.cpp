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

struct Quad2C {
    float x0, z0, x1, z1, x2, z2, x3, z3, ymin, ymax;
};
struct Pt2C {
    float x, y, z;
};

// DRAFT: GAME 0x2C0B38
// diff: 31 words, float register allocation and tail branch layout of the quad containment test
#ifdef NONMATCHING
int func_002C0B38(Quad2C *q, Pt2C *p)
{
    float y = p->y;
    if (y < q->ymin)
        return 0;
    if (q->ymax < y)
        return 0;
    float px = p->x - q->x0;
    float pz = p->z - q->z0;
    float e1x = q->x1 - q->x0;
    float e1z = q->z1 - q->z0;
    float e3x = q->x3 - q->x0;
    float e3z = q->z3 - q->z0;
    if (e1z * px < e1x * pz)
        return 0;
    if (e3x * pz < e3z * px)
        return 0;
    float dz = q->z2 - q->z0;
    float dx = q->x2 - q->x0;
    pz = pz - dz;
    e1x = e1x - dx;
    px = px - dx;
    e1z = e1z - dz;
    e3x = e3x - dx;
    e3z = e3z - dz;
    if (e1x * pz < e1z * px)
        return 0;
    return !(e3z * px < e3x * pz);
}
#endif

struct Rec2C {
    char _p[0x14];
    short m_14;
    char _p1[0x24 - 0x16];
};
struct Sort2C {
    Rec2C *m_0;
    char _p[0xC];
    unsigned m_10;
    signed char m_14[1];
};

// DRAFT: GAME 0x2C9950
// diff: 14 words, register allocation only (a0/v1 vs v0/a0 in compare; a3/t0 swapped in backward pass)
#ifdef NONMATCHING
void func_002C9950(Sort2C *self)
{
    if (self->m_0 == 0 || self->m_10 == 0)
        return;
    int swapped;
    do {
        unsigned i = 0;
        swapped = 0;
        while (i < self->m_10 - 1) {
            signed char a = self->m_14[i];
            signed char b = self->m_14[i + 1];
            if (self->m_0[b].m_14 < self->m_0[a].m_14) {
                self->m_14[i] = self->m_14[i + 1];
                self->m_14[i + 1] = a;
                swapped = 1;
            }
            i++;
        }
        if (swapped) {
            while (i >= 2) {
                unsigned j = i - 1;
                signed char a = self->m_14[i];
                signed char b = self->m_14[j];
                if (self->m_0[a].m_14 < self->m_0[b].m_14) {
                    self->m_14[i] = self->m_14[j];
                    self->m_14[j] = a;
                    swapped = 1;
                }
                i = j;
            }
        }
    } while (swapped);
}
#endif
}
