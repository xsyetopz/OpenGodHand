#include "game/Fn110n.h"
#include "cvecop.h"
extern "C" float func_00101E28(float *);
float fRand1_1__Fv();
// DRAFT: GAME 0x18F618 (~20 words off: normalize loads hoisted above div.s and the 0x668 add uses $s1 vs $s0; the original reloads v[i] after each n[i] store)
// DIVNOP: 2
#ifdef NONMATCHING
static inline void Normalize(float *d, const float *s)
{
    float len = func_00101E28((float *)s);
    if (0.0f < len) {
        float inv = 1.0f / len;
        d[0] = s[0] * inv;
        d[1] = s[1] * inv;
        d[2] = s[2] * inv;
        d[3] = s[3];
    }
}

extern "C" void func_0018F618(char *self)
{
    switch (*(unsigned char *)(self + 0x2F5)) {
    case 0: {
        float t[4], n[4];
        Snd.SeCall(2, 7, self, 0, 0, 0, 0);
        float *v = (float *)(self + 0x660);
        float *src = (float *)(self + 0x5C0);
        if (v != src) {
            v[0] = src[0];
            v[1] = src[1];
            v[2] = src[2];
        }
        cvecop_Zero(n);
        Normalize(n, v);
        float *np = n;
        cvecop_CopyR(t, np);
        if (v != t) {
            v[0] = t[0];
            v[1] = t[1];
            v[2] = t[2];
        }
        cvecop_Scale(v, 0.04f);
        float r = 0.01f;
        v[0] += fRand1_1__Fv() * r;
        float q = fRand1_1__Fv() * r;
        v[2] += q;
        *(unsigned short *)(self + 0x650) = 2;
        *(float *)(self + 0x670) = 0.02617994f;
        *(unsigned char *)(self + 0x2F5) = 1;
        *(unsigned short *)(self + 0x652) = 0;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
    case 1:
        break;
    default:
        return;
    }
    *(float *)(self + 0x100) = Adjust_theta(*(float *)(self + 0x100) + *(float *)(self + 0x670));
    *(float *)(self + 0x670) = *(float *)(self + 0x670) * 0.9f;
    {
        unsigned c = *(unsigned short *)(self + 0x650) - 1;
        *(unsigned short *)(self + 0x650) = c;
        if ((int)(c << 16) > 0) return;
    }
    if (*(short *)(self + 0x652) < 2) {
        *(float *)(self + 0x670) = -*(float *)(self + 0x670);
        *(unsigned short *)(self + 0x652) = *(unsigned short *)(self + 0x652) + 1;
        *(unsigned short *)(self + 0x650) = 2;
        *(unsigned char *)(self + 0x2F5) = 1;
        *(unsigned char *)(self + 0x2F7) = 0;
    } else {
        *(unsigned char *)(self + 0x2F7) = 0;
        *(unsigned *)(self + 0x100) = 0;
        *(unsigned *)(self + 0x108) = 0;
        *(unsigned char *)(self + 0x2F4) = 0;
        *(unsigned char *)(self + 0x2F5) = 0;
    }
    *(unsigned char *)(self + 0x2F6) = 0;
}
#endif
