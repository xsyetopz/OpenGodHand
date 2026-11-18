// Object initialisers in 0x190000-0x1A0000.

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")
extern "C" void *func_001B6E90(void *);
extern "C" void func_0016F640(void *, int);
extern const char D_00424B68[];
struct Q16 { float v[4] __attribute__((aligned(16))); };
struct QK {
    char b0, b1, b2, pa;
    int w4, w8;
    int arr[8];
    int w2C;
    int w30, w34, w38, w3C;
    char pb[0x10];
    Q16 sv[14];
    int w130, w134, w138, w13C;
};
struct Obj {
    char p0[0x214];
    const void *vt;
    char p1[0x990 - 0x218];
    QK q;
};
#define SVZ(k) __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Q16 *)&self->q.sv[k]))
// FUNCTION: GAME 0x193EA8
extern "C" Obj *func_00193EA8(Obj *self)
{
    func_001B6E90(self);
    self->vt = D_00424B68;
    ZQ(self, 0x620);
    char *p = (char *)self + 0x630;
    for (int i = 8; i != -1; i--) {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    }
    QK *q = &self->q;
    SVZ(0); SVZ(1); SVZ(2); SVZ(3); SVZ(4); SVZ(5); SVZ(6);
    SVZ(7); SVZ(8); SVZ(9); SVZ(10); SVZ(11); SVZ(12); SVZ(13);
    q->b0 = 0;
    q->b1 = 0;
    q->b2 = 0;
    q->w4 = 0;
    q->w8 = 0;
    q->w30 = 0;
    q->w34 = 0;
    q->w38 = 0;
    q->w3C = 0;
    q->w130 = 0;
    q->w134 = 0;
    q->w138 = 0;
    q->w13C = 0;
    for (unsigned i = 0; i < 8; i++)
        q->arr[i] = 0;
    ZQ(self, 0xB10);
    *(int *)((char *)self + 0x614) = 0;
    *(int *)((char *)self + 0xB20) = 0;
    return self;
}

struct cPartsF {
    char _p0[0x154];
    int m_flags;
};
extern "C" void func_00149EB8(void *);
extern "C" void func_001B7280(void *, int, int);
class cOm1f {
public:
    enum eSetType { SET0, SET1 };
    void changeSetType(eSetType t);

    static bool inRange(int i, const int &lo, const int &hi)
    {
        bool r = 0;
        if (i >= lo) {
            bool t = i < hi;
            r = t;
        }
        return r;
    }
    cPartsF *getParts(int i)
    {
        if (inRange(i, 0, m_partsNum))
            return m_parts[i];
        return 0;
    }

    char _p0[0x278];
    cPartsF **m_parts;
    char _p27c[0x2B4 - 0x27C];
    unsigned char m_partsNum;
    char _p2b5[0x600 - 0x2B5];
    int m_600;
};

// FUNCTION: GAME 0x1959A8
void cOm1f::changeSetType(eSetType t)
{
    if (getParts(1)) {
        getParts(1)->m_flags &= ~8;
        getParts(1)->m_flags &= ~0x10;
        func_00149EB8(this);
    }
    switch (t) {
    case SET0:
    default:
        func_001B7280(this, 0, 1);
        m_600 = 0;
        if (getParts(1)) {
            getParts(1)->m_flags |= 8;
            getParts(1)->m_flags |= 0x10;
        }
        break;
    case SET1:
        func_001B7280(this, 0, 0);
        m_600 = t;
        break;
    }
}
