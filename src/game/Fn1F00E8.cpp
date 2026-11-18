#include "cvecop.h"
#ifdef NONMATCHING
// DRAFT: GAME 0x1F00E8
// diff: 25/157 words; w/f address addiu and 0.1f lui/ori scheduled later than original
// DIVNOP: 2
extern "C" int ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(const float *, const float *, float *, float *, unsigned, unsigned, void **, unsigned, unsigned *, void **, unsigned, void **, bool);
float capVu0LengthSq(const float *);
extern "C" float func_00101E28(float *);
extern "C" void func_001EFED0(char *, float *, float *);
static inline void SubR(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(CvQ *)d) : "r"(a), "r"(b));
}
static inline void AddR(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,%1\n\tlqc2 $vf5,0(%2)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(CvQ *)d) : "m"(*(const CvQ *)a), "r"(b));
}
struct VT { char _p[0x80]; short adj; short _a; float *(*fn)(void *); };

extern "C" void func_001F00E8(char *self, char *obj, float t)
{
    float pos[4] __attribute__((aligned(16)));
    float q[4] __attribute__((aligned(16)));
    float v[4] __attribute__((aligned(16)));
    float u[4] __attribute__((aligned(16)));
    float n[4] __attribute__((aligned(16)));
    float w[4] __attribute__((aligned(16)));
    float e[4] __attribute__((aligned(16)));
    float f[4] __attribute__((aligned(16)));
    float *posp = pos;
    pos[0] = 0.0f; posp[1] = 0.0f; posp[2] = 0.0f; posp[3] = 1.0f;
    VT *vt = *(VT **)(obj + 0x214);
    float *r = vt->fn(obj + vt->adj);
    cvecop_CopyR(q, r);
    q[1] = q[1] + 1.0f;
    pos[1] = pos[1] + 1.0f;
    float *up = u;
    float *qp = q;
    float *vp = v;
    cvecop_Zero(u);
    SubR(u, qp, posp);
    cvecop_CopyR(v, up);
    cvecop_Zero(n);
    float len = func_00101E28(vp);
    if (0.0f < len) {
        float inv = 1.0f / len;
        n[0] = v[0] * inv; n[1] = v[1] * inv; n[2] = v[2] * inv; n[3] = v[3];
    }
    float *np = n;
    cvecop_CopyR(u, np);
    v[0] = u[0]; v[1] = u[1]; v[2] = u[2];
    cvecop_Scale(v, 15.0f);
    cvecop_CopyR(n, posp);
    AddR(n, n, vp);
    cvecop_CopyR(u, np);
    cvecop_Zero(n);
    if (ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(posp, up, np, 0, 1, 0x24, 0, 0, 0, 0, 0, 0, true)) {
        float *ep = e;
        cvecop_Zero(e);
        SubR(e, np, qp);
        cvecop_CopyR(w, ep);
        w[1] = 0.0f;
        float d = t + 0.1f;
        if (capVu0LengthSq(w) <= d * d) {
            cvecop_Zero(f);
            SubR(f, posp, qp);
            float *fp = f;
            cvecop_CopyR(e, fp);
            if (!(0.0f < *(float *)(obj + 0x54C)))
                func_001EFED0(self, np, ep);
        }
    }
}
#endif
