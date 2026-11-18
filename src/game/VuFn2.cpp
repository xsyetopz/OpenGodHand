// VU0 macro-mode units, second batch (COP2 sequences in asm blocks, C control flow).
struct Qv { float f[4]; };
struct Sv {
    float v[4] __attribute__((aligned(16)));
    Sv() { __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)v)); }
    Sv &operator=(const float *o)
    {
        if (v != o) { v[0] = o[0]; v[1] = o[1]; v[2] = o[2]; }
        return *this;
    }
};
struct Sv16 { float v[4] __attribute__((aligned(16))); };
struct cVec {
    float v[4] __attribute__((aligned(16)));
    cVec() { __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)v)); }
    cVec(const cVec &o) { __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)v) : "r"(o.v)); }
};
struct cMatrix { float m[16]; };
class cNode { public: void setLocalTranslation(const cVec &); };
extern "C" void sceVu0Normalize(float *, const float *);
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);
extern "C" void func_0030ABA0(float *, const float *, float);
void capVu0AddVectorXYZ(float *, const float *, const float *);
void MtxInitRotY(cMatrix &, float);
float capVu0Atan2(float, float);
extern "C" void func_002B6310(void *, cNode *);

class cCamera { public: cVec calcRotation(const cVec &, const cVec &) const; };

// FUNCTION: GAME 0x138358
cVec cCamera::calcRotation(const cVec &a, const cVec &b) const
{
    float t[4] __attribute__((aligned(16)));
    {
        cVec d;
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)d.v) : "r"(a.v), "r"(b.v));
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)t) : "r"(d.v));
    }
    cVec r;
    if (t[0] == 0.0f && t[2] == 0.0f) { r.v[1] = 0.0f; } else { float zz = t[2]; float xx = t[0]; r.v[1] = capVu0Atan2(xx, zz); }
    cMatrix m;
    MtxInitRotY(m, -r.v[1]);
    sceVu0ApplyMatrix(t, m.m, t);
    if (t[1] == 0.0f && t[2] == 0.0f) r.v[0] = 0.0f;
    else r.v[0] = -capVu0Atan2(t[1], t[2]);
    r.v[2] = 0.0f;
    return r;
}

struct ObjF { char p0[0x11C]; float pos[3]; char p1[0x48]; float rad; float k; float h; };

// FUNCTION: GAME 0x304940
extern "C" void func_00304940(ObjF *self)
{
    Sv16 a;
    a.v[0] = self->pos[0]; a.v[1] = self->pos[1]; a.v[2] = self->pos[2]; a.v[3] = 1.0f;
    Sv b;
    {
        Sv16 t;
        func_002B6310(&t, (cNode *)self);
        b.v[0] = t.v[0]; b.v[1] = t.v[1]; b.v[2] = t.v[2];
    }
    if (self->k != 0.0f) func_0030ABA0(a.v, a.v, self->k);
    Sv n;
    sceVu0Normalize(n.v, a.v);
    func_0030ABA0(n.v, n.v, self->rad);
    capVu0AddVectorXYZ(a.v, a.v, n.v);
    a.v[1] -= self->h;
    __asm__ volatile("lqc2 $vf4,%0\n\tlqc2 $vf5,%1\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "+m"(*(Qv *)b.v) : "m"(*(Qv *)a.v));
    self->pos[0] = a.v[0]; self->pos[1] = a.v[1]; self->pos[2] = a.v[2];
    ((cNode *)self)->setLocalTranslation(*(const cVec *)b.v);
}

struct ObjG { char p0[0x11C]; float pos[3]; float pad[3]; float q[3]; char p1[0x30]; float rad; float k; float h; };

// FUNCTION: GAME 0x3033A8
extern "C" void func_003033A8(ObjG *self)
{
    Sv16 a; Sv16 b;
    a.v[0] = self->pos[0]; a.v[1] = self->pos[1]; a.v[2] = self->pos[2]; a.v[3] = 1.0f;
    b.v[0] = self->q[0]; b.v[1] = self->q[1]; b.v[2] = self->q[2]; b.v[3] = 1.0f;
    if (self->k != 0.0f) func_0030ABA0(a.v, a.v, self->k);
    Sv n;
    sceVu0Normalize(n.v, a.v);
    func_0030ABA0(n.v, n.v, self->rad);
    capVu0AddVectorXYZ(a.v, a.v, n.v);
    a.v[1] -= self->h;
    __asm__ volatile("lqc2 $vf4,%0\n\tlqc2 $vf5,%1\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "+m"(*(Qv *)b.v) : "m"(*(Qv *)a.v));
    self->pos[0] = a.v[0]; self->pos[1] = a.v[1]; self->pos[2] = a.v[2];
    self->q[1] = b.v[1]; self->q[0] = b.v[2];
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1BD1A0
// diff: 10 words; original does lwu+dsra for the flag test, loads tgt before the Sv ctor, stores c5,c6,c7 in a different order
struct SvM { float v[3]; SvM &operator=(const float *o){ if (v != o) { v[0]=o[0]; v[1]=o[1]; v[2]=o[2]; } return *this; } };
struct ObjH { char p0[0xF0]; float *tgt; char p1[0x2F4-0xF4]; char c4, c5, c6, c7; char p2[0x490-0x2F8]; float org[4]; char p3[0x5B0-0x4A0]; unsigned int fl; char p4[0x5C0-0x5B4]; SvM out; };
extern "C" void func_001BD1A0(ObjH *a0)
{
    ObjH *self = a0;
    if ((((unsigned long long)self->fl >> 1) & 1)) return;
    {
        float *tp = self->tgt;
        Sv16 t;
        Sv d;
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)d.v) : "r"(tp), "r"(self->org));
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)t.v) : "r"(d.v));
        self->out = t.v;
        self->c4 = 2; self->c5 = 0; self->fl |= 1; self->c6 = self->c7 = 0;
    }
}
// DRAFT: GAME 0x2EA798
// diff: 21 words; original has 2 nops between mtc1 1.0f and div.s, branch to the 1.0f return is one word longer
struct CamWork { char p0[0x210]; float pos[4]; };
extern CamWork *pCamWork;
float capVu0Length(const float *);
extern "C" void func_002B6160(void *, void *);
struct ObjI { char p0[0x2C8]; float k; };
extern "C" float func_002EA798(ObjI *self)
{
    Sv16 a;
    func_002B6160(&a, self);
    Sv16 b;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)b.v) : "r"(pCamWork->pos));
    if (self->k != 0.0f) {
        a.v[0] -= b.v[0]; a.v[1] -= b.v[1]; a.v[2] -= b.v[2];
        float s = 1000.0f;
        __asm__ volatile("lqc2 $vf4,%0\n\tmfc1 $t0,%1\n\tqmtc2.ni $t0,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,%0" : "+m"(*(Qv *)a.v) : "f"(s) : "$8");
        float d = capVu0Length(a.v) / self->k;
        if (d > 1.0f) d = 1.0f;
        if (d < 0.0f) d = 0.0f;
        return 1.0f - d;
    }
    return 1.0f;
}
// DRAFT: GAME 0x138648
// diff: 6 words; ApplyMatrix arg setup order and the &d pointer / ctor scheduling differ
extern "C" void func_0030A8C8(void *, float *, float *, float *);
struct ObjJ { char p0[0x140]; float m140[4]; char p1[0x180-0x150]; float m180[16]; char pm[0x200-0x1C0]; float v200[4]; float v210[3]; char p2[0x240-0x21C]; float v240[3]; };
extern "C" void func_00138648(ObjJ *self)
{
    Sv16 a;
    a.v[0] = self->v210[0]; a.v[1] = self->v210[1]; a.v[2] = self->v210[2]; a.v[3] = 1.0f;
    sceVu0ApplyMatrix(a.v, self->m180, a.v);
    Sv t;
    sceVu0ApplyMatrix(t.v, self->m180, self->v200);
    Sv16 w;
    {
        Sv d;
        float *dp = d.v;
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)d.v) : "r"(t.v), "r"(self->v210));
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)w.v) : "r"(dp));
    }
    Sv16 p, q;
    p.v[0] = w.v[0]; p.v[1] = w.v[1]; p.v[2] = w.v[2]; p.v[3] = 1.0f;
    q.v[0] = self->v240[0]; q.v[1] = self->v240[1]; q.v[2] = self->v240[2]; q.v[3] = 1.0f;
    func_0030A8C8(self->m140, a.v, p.v, q.v);
}
#endif

extern "C" void func_002B6370(void *);
extern "C" void *func_002B5E50(void *);
extern "C" void *func_002B61B0(void *);
void MtxInverse(cMatrix &, const cMatrix &);
struct Mat16 { float m[16] __attribute__((aligned(16))); };
// FUNCTION: GAME 0x2B5FC8
extern "C" void func_002B5FC8(cNode *self, const float *p)
{
    Mat16 m;
    Sv16 c;
    Sv16 t;
    float *tp;
    func_002B6370(self);
    void *r = func_002B5E50(self);
    if (r) {
        MtxInverse(*(cMatrix *)&m, *(const cMatrix *)func_002B61B0(r));
        tp = t.v;
    } else {
        __asm__ volatile("vmove.xyzw $vf4,$vf0\n\tvmr32.xyzw $vf5,$vf4\n\tvmr32.xyzw $vf6,$vf5\n\tvmr32.xyzw $vf7,$vf6\n\t"
                         "sqc2 $vf4,0x30(%0)\n\tsqc2 $vf5,0x20(%0)\n\tsqc2 $vf6,0x10(%0)\n\tsqc2 $vf7,0x0(%0)" : : "r"(&m) : "memory");
        tp = t.v;
    }
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)t.v) : "r"(p));
    sceVu0ApplyMatrix(tp, m.m, tp);
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)c.v) : "r"(tp));
    self->setLocalTranslation(*(const cVec *)&c);
}

extern "C" void *func_001B6E90(void *);
extern "C" char D_00422498[];
struct QK { char b0, b1, b2, pa; int w4, w8; int arr[8]; int w2C; int w30, w34, w38, w3C; char pb[0x10]; Sv16 sv[14]; int w130, w134, w138, w13C; };
struct ObjK {
    char p0[0x214]; void *vt; char p1[0x600 - 0x218];
    QK q;
};
#define SVZ(k) __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)self->q.sv[k].v))
// FUNCTION: GAME 0x17F4E0
extern "C" ObjK *func_0017F4E0(ObjK *self)
{
    func_001B6E90(self);
    void *vt = D_00422498;
    QK *q = &self->q;
    self->vt = vt;
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
    for (unsigned i = 0; i < 8; i++) q->arr[i] = 0;
    return self;
}

extern "C" void func_002B5D58(void *, void *);
extern "C" char D_0044B310[];
struct ObjL {
    void *w0; int w4, w8, wC, w10; char b14, b15, b16, p0; char p1[8];
    float one[4]; Sv16 s30, s40; char p2[0x90 - 0x50]; int w90; char p3[0xA0 - 0x94]; Sv16 sA0;
    char p4[0xF0 - 0xB0]; void *vtF0;
};
#define IDENT(o) __asm__ volatile("vmove.xyzw $vf4,$vf0\n\tvmr32.xyzw $vf5,$vf4\n\tvmr32.xyzw $vf6,$vf5\n\tvmr32.xyzw $vf7,$vf6\n\t" \
                                  "sqc2 $vf4,0x30(%0)\n\tsqc2 $vf5,0x20(%0)\n\tsqc2 $vf6,0x10(%0)\n\tsqc2 $vf7,0x0(%0)" : : "r"((char *)self + (o)) : "memory")
// FUNCTION: GAME 0x2B5C20
extern "C" ObjL *func_002B5C20(ObjL *self, void *a1, void *a2)
{
    self->w0 = a1;
    self->vtF0 = D_0044B310;
    float *o = self->one;
    self->one[0] = 1.0f;
    self->w4 = 0; self->w8 = 0; self->wC = 0; self->w10 = 0;
    self->b14 = 0; self->b15 = 0; self->b16 = 0;
    o[1] = 1.0f; o[2] = 1.0f; o[3] = 1.0f;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)self->s30.v));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)self->s40.v));
    self->w90 = 0;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)self->sA0.v));
    func_002B5D58(self, a2);
    IDENT(0x50);
    IDENT(0xB0);
    return self;
}

#ifdef NONMATCHING
struct LenPosLineReslt;
float LengthPositionToGivenLine(const cVec &, const cVec &, const cVec &, LenPosLineReslt *);
extern "C" void func_00147C60(void *, float *);
// DRAFT: GAME 0x2BBCE0
// diff: 4 words; original computes &t (s0) before &c (s2); here the two addiu are swapped
extern "C" int func_002BBCE0(void *a0, float *m, const float *p, float r)
{
    cVec z;
    cVec c(*(const cVec *)p);
    Sv16 u;
    Sv16 t;
    func_00147C60(&z, m);
    float *cp = c.v;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)t.v) : "r"(cp));
    sceVu0ApplyMatrix(t.v, m, t.v);
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)u.v) : "r"(t.v));
    c.v[0] = u.v[0]; c.v[1] = u.v[1]; c.v[2] = u.v[2];
    return LengthPositionToGivenLine(*(const cVec *)a0, z, c, 0) <= r;
}
#endif

struct VtJ { char p[0x30]; short off; short pad; void (*fn)(float *, void *); };
struct ObjM { char p0[0x70]; float *mtx; char p1[0x100 - 0x74]; VtJ *vt; char p2[0x120 - 0x104]; Sv v120; };
// FUNCTION: GAME 0x2BABD0
extern "C" void func_002BABD0(ObjM *self)
{
    Sv16 b;
    Sv16 a;
    Sv16 t;
    self->vt->fn(a.v, (char *)self + self->vt->off);
    float *tp = t.v;
    float *mt = self->mtx;
    b.v[0] = 0.0f;
    b.v[1] = a.v[1] * 0.5f;
    b.v[2] = 0.0f;
    b.v[3] = 1.0f;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)t.v) : "r"(b.v));
    sceVu0ApplyMatrix(tp, mt, tp);
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)a.v) : "r"(tp));
    self->v120 = a.v;
}

extern "C" int func_001573C8(float *, float *, float *, float *, float *);
// FUNCTION: GAME 0x1F8488
extern "C" int func_001F8488(float *o, float *p)
{
    Sv m0, m1, m2, m3;
    float y = o[1];
    float py = p[1];
    float top = y + o[2];
    if (!(py < y)) {
        if (!(top < py)) {
            m0.v[0] = o[4]; m0.v[1] = 0.0f; m0.v[2] = o[5];
            m1.v[0] = o[6]; m1.v[1] = 0.0f; m1.v[2] = o[7];
            m2.v[0] = o[8]; m2.v[1] = 0.0f; m2.v[2] = o[9];
            m3.v[0] = o[10]; m3.v[1] = 0.0f; m3.v[2] = o[11];
            return func_001573C8(p, m0.v, m1.v, m2.v, m3.v) != 0;
        }
    }
    return 0;
}
