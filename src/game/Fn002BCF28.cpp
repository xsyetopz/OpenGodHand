// VU0 units for slice F170 (COP2 copies in asm blocks, C control flow).
struct Qv { float f[4]; };
struct cVec { float v[4] __attribute__((aligned(16))); };
struct LenPosLineReslt;

extern "C" {
void func_00147C60(void *, float *);
void sceVu0ApplyMatrix(float *, void *, float *);
void func_002BC0F8(float *, float *, float *, float *, float, float, float, float);
void func_002BD078(void *, void *, float *);
void func_002BD4B0(void *, void *, void *, float *);
}
float LengthPositionToGivenLine(const cVec &p, const cVec &a, const cVec &b, LenPosLineReslt *res);

static inline void vcopy(float *dst, const float *src)
{
    __asm__ volatile("lqc2 $vf4,%1\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)dst) : "m"(*(const Qv *)src));
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2BD3D8 - 53 words; frame 0x90 vs 0xA0, saves s0-s2 vs s0-s3 (&s10 not kept in a saved reg); variants: store order, float* aliases p10/p30, s10 via struct pointer
extern "C" int func_002BD3D8(void *arg0, void *arg1, float fparg0, float fparg1)
{
    cVec sp;
    cVec s10;
    cVec s20;
    cVec s30;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)sp.v));
    cVec *ps10 = &s10;
    ps10->v[1] = fparg1;
    ps10->v[0] = 0.0f;
    ps10->v[2] = 0.0f;
    func_00147C60(sp.v, (float *)arg0);
    ps10->v[3] = 1.0f;
    float *p30 = s30.v;
    vcopy(p30, ps10->v);
    sceVu0ApplyMatrix(p30, arg0, p30);
    vcopy(s20.v, p30);
    ps10->v[0] = s20.v[0];
    ps10->v[1] = s20.v[1];
    ps10->v[2] = s20.v[2];
    if (LengthPositionToGivenLine(*(const cVec *)arg1, sp, s10, 0) <= fparg0) {
        return 1;
    }
    return 0;
}

// DRAFT: GAME 0x2BD200 - 77 words; frame 0x90 vs 0xA0, scale done with scalar mul.s instead of VU0 vmulx.xyz; variants: scalar form only
extern "C" void func_002BD200(void *arg0, void *arg1, float *arg2)
{
    cVec sp[8];
    float *p = sp[0].v;
    int n = 7;
    do {
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)p));
        p += 4;
        n--;
    } while (n != -1);
    float x = arg2[0] * 0.5f;
    float y = arg2[1];
    float z = arg2[2] * 0.5f;
    sp[0].v[0] = -x; sp[0].v[1] = 0.0f; sp[0].v[2] = -z;
    sp[1].v[0] = x;  sp[1].v[1] = 0.0f; sp[1].v[2] = -z;
    sp[2].v[0] = -x; sp[2].v[1] = 0.0f; sp[2].v[2] = z;
    sp[3].v[0] = x;  sp[3].v[1] = 0.0f; sp[3].v[2] = z;
    sp[4].v[0] = -x; sp[4].v[1] = y; sp[4].v[2] = -z;
    sp[5].v[0] = x;  sp[5].v[1] = y; sp[5].v[2] = -z;
    sp[6].v[0] = -x; sp[6].v[1] = y; sp[6].v[2] = z;
    sp[7].v[0] = x;  sp[7].v[1] = y; sp[7].v[2] = z;
    func_002BD078(arg0, arg1, sp[0].v);
}

// DRAFT: GAME 0x2BD6A8 - 76 words; frame 0x90 vs 0xA0, scale done with scalar mul.s instead of VU0 vmulx.xyz; variants: scalar form only
extern "C" void func_002BD6A8(void *arg0, void *arg1, void *arg2, float *arg3)
{
    cVec sp[8];
    float *p = sp[0].v;
    int n = 7;
    do {
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)p));
        p += 4;
        n--;
    } while (n != -1);
    float x = arg3[0] * 0.5f;
    float y = arg3[1];
    float z = arg3[2] * 0.5f;
    sp[0].v[0] = -x; sp[0].v[1] = 0.0f; sp[0].v[2] = -z;
    sp[1].v[0] = x;  sp[1].v[1] = 0.0f; sp[1].v[2] = -z;
    sp[2].v[0] = -x; sp[2].v[1] = 0.0f; sp[2].v[2] = z;
    sp[3].v[0] = x;  sp[3].v[1] = 0.0f; sp[3].v[2] = z;
    sp[4].v[0] = -x; sp[4].v[1] = y; sp[4].v[2] = -z;
    sp[5].v[0] = x;  sp[5].v[1] = y; sp[5].v[2] = -z;
    sp[6].v[0] = -x; sp[6].v[1] = y; sp[6].v[2] = z;
    sp[7].v[0] = x;  sp[7].v[1] = y; sp[7].v[2] = z;
    func_002BD4B0(arg0, arg1, arg2, sp[0].v);
}

// DRAFT: GAME 0x2BCF28 - 77 words; frame 0xC0 vs 0xE0, saves s0-s2 vs s0-s4 (no s3/s4 pointer keeps), 2 VU0 copies differ; variants: first form only
extern "C" void func_002BCF28(void *arg0, void *arg1, float fparg0, float fparg1, float fparg2, float fparg3)
{
    cVec sp;
    cVec s10;
    cVec s20;
    cVec s30;
    cVec s40;
    cVec s50;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)sp.v));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)s10.v));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)s20.v));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)s30.v));
    func_00147C60(sp.v, (float *)arg0);
    s10.v[1] = fparg1;
    vcopy(s50.v, s10.v);
    sceVu0ApplyMatrix(s50.v, arg0, s50.v);
    vcopy(s40.v, s50.v);
    s10.v[0] = s40.v[0];
    s10.v[1] = s40.v[1];
    s10.v[2] = s40.v[2];
    func_00147C60(s20.v, (float *)arg1);
    s30.v[1] = fparg3;
    vcopy(s50.v, s30.v);
    sceVu0ApplyMatrix(s50.v, arg1, s50.v);
    vcopy(s40.v, s50.v);
    s30.v[0] = s40.v[0];
    s30.v[1] = s40.v[1];
    s30.v[2] = s40.v[2];
    func_002BC0F8(sp.v, s10.v, s20.v, s30.v, fparg0, fparg1, fparg2, fparg3);
}
#endif
