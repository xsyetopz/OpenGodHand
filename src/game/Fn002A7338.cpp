// Unnamed and constructor units in 0x2A7000-0x2AC000: __8cGameObj, func_002AB2A0, func_002ABC30.
#include "cvecop.h"

extern "C" void __8cObjBase(void *);
extern "C" void *func_002AED40(int, unsigned short);
extern "C" void func_002AB9A8(int, unsigned char, void *);
extern int Message;
extern int D_0044AE28;
extern int D_0044ADF0;

static inline float AbsF(float a)
{
    float r;
    __asm__("abs.s %0,%1" : "=f"(r) : "f"(a));
    return r;
}

static inline float SqF(float a)
{
    float r;
    __asm__("nop\n\tnop\n\tsqrt.s %0,%1" : "=f"(r) : "f"(a));
    return r;
}

// DRAFT: GAME 0x2A7338 - 22 words (140 bytes); $v0/$v1 and $a0/$v1 constant regs swapped; tried pointer temp (22, 144 bytes), hoisted d and 0xFFFF temps (no drop)
#ifdef NONMATCHING
extern "C" void *__8cGameObj(void *p)
{
    char *self = (char *)p;
    __8cObjBase(self);
    *(int *)(self + 0x214) = (int)&D_0044AE28;
    *(int *)(self + 0x520) = 0;
    *(float *)(self + 0x52C) = 1.0f;
    *(int *)(self + 0x524) = 0;
    *(int *)(self + 0x528) = 0;
    cvecop_Zero((float *)(self + 0x550));
    cvecop_Zero((float *)(self + 0x580));
    cvecop_Zero((float *)(self + 0x590));
    *(int *)(self + 0x4AC) = (int)&D_0044ADF0;
    *(float *)(self + 0x5A8) = 1.0f;
    *(int *)(self + 0x4D0) = 0xFFFF;
    *(signed char *)(self + 0x531) = -1;
    *(int *)(self + 0x510) = 0;
    *(long long *)(self + 0x538) = 0;
    *(long long *)(self + 0x540) = 0;
    *(int *)(self + 0x5A0) = 0;
    return self;
}
#endif

// DRAFT: GAME 0x2AB2A0 - 34 words (192 bytes); original branches for a1 (beqz, not movz); tried if-form a1 and float-first loads (no drop)
#ifdef NONMATCHING
extern "C" void func_002AB2A0(int a0, char *self)
{
    unsigned short t = *(unsigned short *)(self + 0x90);
    unsigned short a1 = t ? t : 0x3000;
    char *p = (char *)func_002AED40(Message, a1);
    if (p == 0) return;
    float fx = *(float *)(self + 0x50);
    float fy = *(float *)(self + 0x54);
    *(short *)(p + 0xA6) = (short)fx;
    *(short *)(p + 0xA8) = (short)fy;
    *(float *)(p + 0x54) = *(float *)(self + 0x58);
    *(float *)(p + 0x58) = *(float *)(self + 0x5C);
    *(short *)(p + 0x5C) = 1;
    *(short *)(p + 0x5E) = (short)(-*(float *)(self + 0x5C) * 24.0f + 4.0f);
    func_002AB9A8(a0, *(unsigned char *)(self + 0x8B), p);
}
#endif

// DRAFT: GAME 0x2ABC30 - 23 words (184 bytes); h/w load order and ok-flag form differ; &= -0x2001 flag, shared n dropped, do-while loop (34 to 23)
#ifdef NONMATCHING
extern "C" void func_002ABC30(void *unused, char *self)
{
    char *s = *(char **)(self + 0x1C);
    short w = *(short *)(s + 0x6C);
    short h = *(short *)(s + 0x6E);
    *(short *)(self + 0xA2) = 0;
    if (s[0x5D] == 0) {
        int ok = 0;
        if (w >= 2) ok = (h >= 2);
        if (ok) *(int *)(self + 0x2C) &= -0x2001;
        else *(int *)(self + 0x2C) |= 0x2000;
    }
    *(int *)(self + 0x9C) = 0;
    int n = h - 3;
    if (n > 0) {
        char *v = *(char **)self;
        do {
            float dx = AbsF(*(float *)(v + 8) - *(float *)(v + 0x10));
            float dy = AbsF(*(float *)(v + 0xC) - *(float *)(v + 0x14));
            *(float *)(self + 0x9C) += SqF(dx * dx + dy * dy);
            v += 8;
        } while (--n);
    }
}
#endif
