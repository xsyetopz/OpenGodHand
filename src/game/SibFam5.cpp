// Sibling families of 0x165e88, 0x12cdf0, 0x12ac28, 0x1492c8 and 0x147bb0.

class cMatrix {
public:
    float m[16] __attribute__((aligned(16)));
};
class Quaternion;
class cVec;
void MtxInitTransVec(cMatrix &, const cVec &);
void MtxInitScaleVec(cMatrix &, const cVec &);
void MtxMultiply(cMatrix &, const cMatrix &, const cMatrix &);

extern "C" {
void func_001FE188(void *);
void func_001FE2B8(void *);
void func_002BE028(void *);
void func_002BE0F0(void *);
void func_002D9C10(void *);
void func_002D9CA8(void *);
void func_0030F5C8(void *);

// FUNCTION: GAME 0x1FDFA8
void func_001FDFA8(void *self)
{
    func_001FE188(self);
    func_001FE2B8(self);
}

// FUNCTION: GAME 0x2BDFF8
void func_002BDFF8(void *self)
{
    func_002BE028(self);
    func_002BE0F0(self);
}

// FUNCTION: GAME 0x2D9BE0
void func_002D9BE0(void *self)
{
    func_002D9C10(self);
    func_002D9CA8(self);
}

// FUNCTION: GAME 0x1FD308
void SetDmgGiveHitVec__11cDamageGiveRC4cVec(char *self, float *v)
{
    float *d = (float *)(self + 0x10);
    if (d != v) {
        d[0] = v[0];
        d[1] = v[1];
        d[2] = v[2];
    }
}

// FUNCTION: GAME 0x26E7A8
void func_0026E7A8(char *self, float *v)
{
    float *d = (float *)(self + 0x1660);
    if (d != v) {
        d[0] = v[0];
        d[1] = v[1];
        d[2] = v[2];
    }
}

// FUNCTION: GAME 0x289038
void SetEscPos__5cEma2RC4cVec(char *self, float *v)
{
    float *d = (float *)(self + 0x1590);
    if (d != v) {
        d[0] = v[0];
        d[1] = v[1];
        d[2] = v[2];
    }
}

// FUNCTION: GAME 0x2714B0
void func_002714B0(char *self)
{
    void *p = *(void **)(self + 0x1860);
    if (p) {
        func_0030F5C8(p);
        *(void **)(self + 0x1860) = 0;
    }
}

// FUNCTION: GAME 0x28CE70
void func_0028CE70(char *self)
{
    void *p = *(void **)(self + 0x1630);
    if (p) {
        func_0030F5C8(p);
        *(void **)(self + 0x1630) = 0;
    }
}

// FUNCTION: GAME 0x147B18
void MtxMulTransVec__FR7cMatrixRC7cMatrixRC4cVec(cMatrix &dst, const cMatrix &src, const cVec &v)
{
    cMatrix m;
    MtxInitTransVec(m, v);
    MtxMultiply(dst, src, m);
}

// FUNCTION: GAME 0x147BF8
void MtxMulScaleVec__FR7cMatrixRC7cMatrixRC4cVec(cMatrix &dst, const cMatrix &src, const cVec &v)
{
    cMatrix m;
    MtxInitScaleVec(m, v);
    MtxMultiply(dst, src, m);
}

// 0x17f4e0 family: object initialisers differing in the base offset and vtable.
struct Qv { float f[4]; };
struct Sv16 { float v[4] __attribute__((aligned(16))); };
void *func_001B6E90(void *);
extern char D_004226A8[];
extern char D_00427E60[];
struct QK {
    char b0, b1, b2, pa;
    int w4, w8;
    int arr[8];
    int w2C;
    int w30, w34, w38, w3C;
    char pb[0x10];
    Sv16 sv[14];
    int w130, w134, w138, w13C;
};
#define SVZ(k) __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)self->q.sv[k].v))
#define OBJK_INIT(ADDR, NAME, B, VT)                                          \
    struct Obj##ADDR {                                                         \
        char p0[0x214];                                                        \
        void *vt;                                                              \
        char p1[B - 0x218];                                                    \
        QK q;                                                                  \
    };                                                                         \
    Obj##ADDR *NAME(Obj##ADDR *self)                                           \
    {                                                                          \
        func_001B6E90(self);                                                   \
        void *vt = VT;                                                         \
        QK *q = &self->q;                                                      \
        self->vt = vt;                                                         \
        SVZ(0); SVZ(1); SVZ(2); SVZ(3); SVZ(4); SVZ(5); SVZ(6);                \
        SVZ(7); SVZ(8); SVZ(9); SVZ(10); SVZ(11); SVZ(12); SVZ(13);            \
        q->b0 = 0;                                                             \
        q->b1 = 0;                                                             \
        q->b2 = 0;                                                             \
        q->w4 = 0;                                                             \
        q->w8 = 0;                                                             \
        q->w30 = 0;                                                            \
        q->w34 = 0;                                                            \
        q->w38 = 0;                                                            \
        q->w3C = 0;                                                            \
        q->w130 = 0;                                                           \
        q->w134 = 0;                                                           \
        q->w138 = 0;                                                           \
        q->w13C = 0;                                                           \
        for (unsigned i = 0; i < 8; i++)                                       \
            q->arr[i] = 0;                                                     \
        return self;                                                           \
    }

// FUNCTION: GAME 0x1808E8
OBJK_INIT(1808E8, func_001808E8, 0x610, D_004226A8)
// FUNCTION: GAME 0x1ABD40
OBJK_INIT(1ABD40, func_001ABD40, 0x630, D_00427E60)
}
