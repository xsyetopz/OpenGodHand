#ifdef NONMATCHING
#include "cvecop.h"
extern "C" int func_00291FD8(char *);
extern "C" float capVu0MagnitudeSqXZ__FPCfT0(const float *, const float *);
extern "C" void setGoto__5cEm00RC4cVec14EM00_GOTO_TYPEUif(void *, const void *, int, unsigned, float);
extern char g_EmManage[];

// DRAFT: GAME 0x26E258 - 102 words off (one shifted): mag compares via mov.s f2 plus extra nop; orig loads 25.0f first and keeps mag in f3
extern "C" int func_0026E258(char *self)
{
    if (!func_00291FD8(g_EmManage))
        return 0;
    if (0.0f < *(float *)(self + 0x16C0))
        return 0;
    float P[4];
    float *ps = (float *)(g_EmManage + 0x520);
    cvecop_CopyR(P, ps);
    float mag = capVu0MagnitudeSqXZ__FPCfT0(P, *(float **)(self + 0xF0));
    if (25.0f < mag)
        return 0;
    switch (*(int *)(self + 0x564)) {
    case 0x20A: case 0x20B: case 0x20C: case 0x20D: case 0x20E: case 0x218:
    case 0x245: case 0x246: case 0x247: case 0x24F: case 0x250: case 0x251:
    case 0x278: case 0x279:
        *(unsigned char *)(self + 0x2F5) = 0x6D;
        *(unsigned char *)(self + 0x2F7) = 0;
        break;
    case 0x220: case 0x221: case 0x222: case 0x223: case 0x26A:
        return 0;
    default: {
        float V[4], D[4], T[4], W[4];
        cvecop_Zero(V);
        cvecop_Zero(D);
        float len;
        if (mag == 0.0f) {
            V[0] = 0.0f;
            V[1] = 0.0f;
            V[2] = 1.0f;
            len = 1.0f;
        } else {
            cvecop_Zero(W);
            cvecop_Sub(W, *(float **)(self + 0xF0), P);
            float *Wp = W;
            cvecop_CopyR(T, Wp);
            V[0] = T[0];
            V[2] = T[2];
            V[1] = 0.0f;
            __asm__("nop\n\tnop\n\tsqrt.s %0,%1" : "=f"(len) : "f"(mag));
        }
        float k = 10.0f / len;
        V[2] = V[2] * k;
        V[0] = V[0] * k;
        float *Vp = V;
        cvecop_CopyR(W, Vp);
        cvecop_Add(W, W, *(float **)(self + 0xF0));
        float *Wq = W;
        cvecop_CopyR(T, Wq);
        D[0] = T[0];
        D[1] = T[1];
        D[2] = T[2];
        setGoto__5cEm00RC4cVec14EM00_GOTO_TYPEUif(self, D, 7, 0, 60.0f);
        *(unsigned char *)(self + 0x2F7) = 1;
        *(unsigned char *)(self + 0x2F5) = 0x13;
        break;
    }
    }
    *(unsigned char *)(self + 0x2F4) = 0;
    *(unsigned char *)(self + 0x2F6) = 0;
    return 1;
}
#endif
