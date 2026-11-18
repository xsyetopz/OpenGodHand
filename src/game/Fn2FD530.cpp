// Object position update with optional scaled offset (ee-gcc 2.95.3-136, C++).

extern "C" {
void func_002B62F8(float *, void *);
void func_002B6230(void *, float *);
void sceVu0ScaleVector(float *, float *, float);
void capVu0AddVectorXYZ__FPfPCfT1(float *, const float *, const float *);
void Adjust_theta_vec__FPf(float *);
}
extern float D_00741DC0;
extern float D_00747A14;
extern unsigned D_00747A84;

struct Fn2FDObj {
    char _p0[0x110];
    int *m_110;
    char _p114[9];
    unsigned char m_11D;
    char _p11E[0x5A];
    float m_178, m_17C, m_180;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x2FD530
// 46 differing words (216 vs 220 bytes): original takes &d in v0 and copies to s1, loads f3,f2,f0; control flow matches; tried d before/after call, struct/array/V-struct locals, w store order.
extern "C" void func_002FD530(Fn2FDObj *o)
{
    struct { float r[4]; float d[4]; } v;
    func_002B62F8(v.r, o);
    float *d = v.d;
    d[0] = o->m_178;
    d[1] = o->m_17C;
    d[2] = o->m_180;
    d[3] = 1.0f;
    if (((o->m_110[1] & 0x2000) == 0 && (o->m_11D & 1)) || (D_00747A84 & 0x20000))
        sceVu0ScaleVector(d, d, D_00741DC0 * D_00747A14);
    capVu0AddVectorXYZ__FPfPCfT1(v.r, v.r, d);
    Adjust_theta_vec__FPf(v.r);
    func_002B6230(o, v.r);
}
#endif
