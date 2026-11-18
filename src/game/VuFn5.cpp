// VU0 math units, second half of the VuFn set: node translation helpers, camera-relative checks.
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
float capVu0LengthSq(const float *);
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);

struct cVec { float x, y, z; };
class cNode { public: void setLocalTranslation(const cVec &); };
struct Sv16 { float v[4] __attribute__((aligned(16))); };
extern "C" void func_002B6310(void *, cNode *);
extern "C" void func_002B6160(void *, cNode *);

// Same body twice: the original has one copy per node type.
// FUNCTION: GAME 0x2F6258
extern "C" Sv16 *func_002F6258(Sv16 *ret, cNode *n, const float *delta)
{
    Sv16 a;
    Sv16 tmp;
    Sv16 b;
    func_002B6310(&a, n);
    Sv16 *bp = &b;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)b.v) : "r"(&a));
    __asm__ volatile("lqc2 $vf4,%0\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "+m"(*(Qv *)b.v) : "r"(delta));
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)tmp.v) : "r"(bp));
    n->setLocalTranslation(*(const cVec *)&tmp);
    func_002B6160(bp, n);
    n->setLocalTranslation(*(const cVec *)&a);
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(ret), "r"(bp) : "memory");
    return ret;
}

// FUNCTION: GAME 0x2F71A0
extern "C" Sv16 *func_002F71A0(Sv16 *ret, cNode *n, const float *delta)
{
    Sv16 a;
    Sv16 tmp;
    Sv16 b;
    func_002B6310(&a, n);
    Sv16 *bp = &b;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)b.v) : "r"(&a));
    __asm__ volatile("lqc2 $vf4,%0\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "+m"(*(Qv *)b.v) : "r"(delta));
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)tmp.v) : "r"(bp));
    n->setLocalTranslation(*(const cVec *)&tmp);
    func_002B6160(bp, n);
    n->setLocalTranslation(*(const cVec *)&a);
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(ret), "r"(bp) : "memory");
    return ret;
}

extern "C" void func_002B6370(void *);
extern "C" void *func_002B5E50(void *);
extern "C" void func_002B60D0(void *, void *);
extern "C" void func_002B6230(void *, void *);
// FUNCTION: GAME 0x2B5F28
extern "C" void func_002B5F28(void *self, const float *p)
{
    func_002B6370(self);
    Sv s;
    Sv16 tmp;
    void *r = func_002B5E50(self);
    if (r) {
        func_002B60D0(&tmp, r);
        s = tmp.v;
    }
    Sv d;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)d.v) : "r"(p), "r"(s.v));
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)tmp.v) : "r"(d.v));
    func_002B6230(self, &tmp);
}

extern "C" void func_002F5588(void *, cNode *);
extern "C" void func_002B5FC8(cNode *, void *);
extern "C" void func_002FEB18(cNode *);
// FUNCTION: GAME 0x2F5468
extern "C" void func_002F5468(cNode *self)
{
    Sv16 a;
    Sv16 t;
    Sv16 b;
    Sv16 c;
    Sv16 sum;
    func_002B6160(&a, self);
    func_002F5588(&b, self);
    func_002B6160(&c, self);
    Sv16 *sp = &sum;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)sum.v) : "r"(&b));
    __asm__ volatile("lqc2 $vf4,%0\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "+m"(*(Qv *)sum.v) : "r"(&c));
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)t.v) : "r"(sp));
    func_002B5FC8(self, &t);
    func_002FEB18(self);
    func_002B5FC8(self, &a);
}

struct ObjD { char p0[0xF0]; float *pos; char p1[0x10]; float dir; };
float capVu0Atan2(float, float);
float Adjust_theta(float);
// FUNCTION: GAME 0x14E818
extern "C" void func_0014E818(ObjD *self, float lim, const float *p)
{
    float t[4] __attribute__((aligned(16)));
    const float *pp = self->pos;
    Sv d;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)d.v) : "r"(p), "r"(pp));
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)t) : "r"(d.v));
    float a = Adjust_theta(capVu0Atan2(t[0], t[2]) - self->dir);
    float c;
    if (a < -lim) c = -lim;
    else if (lim < a) c = lim;
    else c = a;
    self->dir += c;
    self->dir = Adjust_theta(self->dir);
}

// FUNCTION: GAME 0x2DB008
extern "C" int func_002DB008(const float *a, const float *b, float r1, float r2, float r3, float *dist, float *out)
{
    float t[4] __attribute__((aligned(16)));
    Sv d;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)d.v) : "r"(a), "r"(b));
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)t) : "r"(d.v));
    float h = r2 + r3;
    if (t[1] < -h) return 0;
    if (h < t[1]) return 0;
    register float l __asm__("$f0") = t[0] * t[0];
    l += t[2] * t[2];
    __asm__ volatile("nop\n\tnop\n\tsqrt.s %0,%0" : "+f"(l));
    if (l < r1 + r3) {
        if (dist) *dist = l;
        if (out) { if (out != a) { out[0] = a[0]; out[1] = a[1]; out[2] = a[2]; } }
        return 1;
    }
    return 0;
}

struct NodeK { char p0[0x2B8]; float rad; };
extern char *pCamWork;
float capVu0Length(const float *);
// FUNCTION: GAME 0x2F3E68
extern "C" int func_002F3E68(NodeK *self)
{
    Sv16 a;
    Sv16 b;
    func_002B6160(&a, (cNode *)self);
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)b.v) : "r"(pCamWork + 0x210));
    if (self->rad == 0.0f) return 1;
    a.v[0] -= b.v[0];
    a.v[1] -= b.v[1];
    a.v[2] -= b.v[2];
    float s = 1000.0f;
    __asm__ volatile("lqc2 $vf4,%0\n\tmfc1 $t0,%1\n\tqmtc2.ni $t0,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,%0" : "+m"(*(Qv *)a.v) : "f"(s) : "$8");
    if (self->rad < capVu0Length(a.v)) return 0;
    return 1;
}

struct cMatrix { float m[16]; };
struct ObjE { char p0[0xF0]; float *pos; char p1[0x10]; float dir; };
extern const float D_005850B0[];
void MtxInitRotY(cMatrix &, float);
// FUNCTION: GAME 0x2498A8
extern "C" void func_002498A8(ObjE *self, float ang)
{
    cMatrix m;
    Sv res;
    self->dir = ang + 3.1415927f;
    self->dir = Adjust_theta(self->dir);
    MtxInitRotY(m, ang);
    res.v[0] = 0.0f;
    res.v[2] = 26.0f;
    res.v[1] = 0.0f;
    sceVu0ApplyMatrix(res.v, m.m, res.v);
    __asm__ volatile("lqc2 $vf4,%0\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "+m"(*(Qv *)res.v) : "r"(D_005850B0));
    self->pos[0] = res.v[0];
    self->pos[2] = res.v[2];
}

#ifdef NONMATCHING
struct v4f { float f[4]; };
struct V4 {
    float v[4] __attribute__((aligned(16)));
    V4() { __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(v4f *)v)); }
    operator float *() { return v; }
};
struct VObj {
    char p0[0xF0];
    float *pos;
    char p1[0x10];
    float dir;
    char p2[0x4A0];
    float spd;
};
extern const float D_005850B0[];
static inline void M_Sub(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(v4f *)d) : "r"(a), "r"(b));
}
static inline void M_Add(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,%1\n\tlqc2 $vf5,0(%2)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(v4f *)d) : "m"(*(const v4f *)a), "r"(b));
}
static inline void M_Copy(float *d, const float *a)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(v4f *)d) : "r"(a));
}
float capVu0Atan2(float, float);
float Adjust_theta(float);
float Turn_dest_dir(float, float, float);
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);

// DRAFT: GAME 0x249770
// diff: 9 words, scheduling only (lw/lui/addiu order before the first lqc2, a2 copy vs sw zero order near sceVu0ApplyMatrix)
extern "C" void func_00249770(VObj *self, float ang)
{
    cMatrix m;
    V4 res;
    float tmp[4] __attribute__((aligned(16)));
    V4 rel;
    M_Sub(rel.v, self->pos, D_005850B0);
    M_Copy(tmp, rel.v);
    res.v[0] = tmp[0];
    res.v[1] = tmp[1];
    res.v[2] = tmp[2];
    float a = Adjust_theta(capVu0Atan2(tmp[0], tmp[2]) + ang);
    MtxInitRotY(m, a);
    res.v[0] = 0.0f;
    res.v[2] = 26.0f;
    res.v[1] = 0.0f;
    sceVu0ApplyMatrix(res, (float *)&m, res);
    M_Add(res.v, res.v, D_005850B0);
    self->pos[0] = res.v[0];
    self->pos[2] = res.v[2];
    float t = Adjust_theta(a + 3.1415927f);
    self->dir += Turn_dest_dir(self->dir, t, self->spd * 0.012271847f);
    self->dir = Adjust_theta(self->dir);
}
#endif
