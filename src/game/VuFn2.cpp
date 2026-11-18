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
