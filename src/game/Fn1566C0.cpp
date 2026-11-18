#include "cvecop.h"
struct cVec { float v[4] __attribute__((aligned(16))); };
struct LenPosLineReslt;
float capVu0Length(const float *);
float capVu0LengthSq(const float *);
extern "C" void func_001565A0(float *, const float *, const float *, const float *);
extern "C" float func_00101E28(float *);
extern "C" float sqrtf_(float) __asm__("sqrtf");

// FUNCTION: GAME 0x1566C0
// DIVNOP: 2
float LengthPositionToGivenLine(const cVec &p, const cVec &a, const cVec &b, LenPosLineReslt *res)
{
    float v[4] __attribute__((aligned(16)));
    float u[4] __attribute__((aligned(16)));
    float n[4] __attribute__((aligned(16)));
    cvecop_Zero(u);
    cvecop_Sub(u, a.v, p.v);
    float *up = u;
    cvecop_CopyR(v, up);
    float l1 = capVu0Length(v);
    cvecop_Zero(u);
    cvecop_Sub(u, b.v, p.v);
    cvecop_CopyR(v, up);
    float l2 = capVu0Length(v);
    float *wp = u;
    __asm__("" : "+r"(wp));
    float m = l1 < l2 ? l1 : l2;
    cvecop_Zero(u);
    cvecop_Sub(u, b.v, a.v);
    cvecop_CopyR(v, wp);
    float x = capVu0LengthSq(v) + m * m;
    float h;
    __asm__("sqrt.s %0,%1" : "=f"(h) : "f"(x));
    if (h != h) h = sqrtf_(x);
    func_001565A0(v, a.v, b.v, p.v);
    cvecop_Zero(n);
    float len = func_00101E28(v);
    if (0.0f < len) {
        float inv = 1.0f / len;
        n[0] = v[0] * inv; n[1] = v[1] * inv; n[2] = v[2] * inv; n[3] = v[3];
    }
    float *np = n;
    cvecop_CopyR(u, np);
    if (v != up) { v[0] = u[0]; v[1] = u[1]; v[2] = u[2]; }
    cvecop_Zero(n);
    cvecop_Sub(n, a.v, p.v);
    cvecop_CopyR(u, np);
    float dot = v[0] * u[0] + v[1] * u[1] + v[2] * u[2];
    if (h <= l1 || h <= l2) {
        if (res) *(int *)res = l1 < l2 ? 0 : 1;
        return m;
    }
    if (res) *(int *)res = 2;
    return dot;
}
