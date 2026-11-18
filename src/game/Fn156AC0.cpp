#include "cvecop.h"
extern "C" void func_001569A0(float *, const float *, const float *, const float *);
extern "C" float func_00101E28(float *);

// FUNCTION: GAME 0x156AC0
// DIVNOP: 2
extern "C" float func_00156AC0(float *a, float *b, float *c)
{
    float v[4], u[4], n[4];
    func_001569A0(v, a, b, c);
    float *up = u;
    cvecop_Zero(n);
    float len = func_00101E28(v);
    if (0.0f < len) {
        float inv = 1.0f / len;
        n[0] = v[0] * inv;
        n[1] = v[1] * inv;
        n[2] = v[2] * inv;
        n[3] = v[3];
    }
    float *np = n;
    cvecop_CopyR(u, np);
    if (v != up) {
        v[0] = u[0];
        v[1] = u[1];
        v[2] = u[2];
    }
    cvecop_Zero(n);
    cvecop_Sub(n, a, c);
    cvecop_CopyR(u, np);
    return v[0] * u[0] + v[1] * u[1] + v[2] * u[2];
}
