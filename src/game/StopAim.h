// Shared stop-and-aim handler body used by the cOm* units.
#pragma once
#include "game/cVec.h"

struct V16F {
    float x, y, z, w;
} __attribute__((aligned(16)));

#define FN190_STOP(NAME)                                                        \
    extern "C" void NAME(char *self)                                            \
    {                                                                           \
        long f = *(unsigned *)(self + 0x5B0);                                   \
        long x = (f >> 1) & 1;                                                  \
        if (x)                                                                  \
            return;                                                             \
        V16F b;                                                                 \
        V16F a;                                                                 \
        const float *tgt = *(const float **)(self + 0xF0);                      \
        const float *p = (const float *)(self + 0x490);                         \
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(a));                             \
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(a) : "r"(tgt), "r"(p)); \
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(b) : "r"(&a)); \
        *(cVec *)(self + 0x5C0) = *(cVec *)&b;                                  \
        *(int *)(self + 0x5B0) = (*(int *)(self + 0x5B0) | 1) & -5;            \
        *(unsigned char *)(self + 0x2F4) = 2;                                   \
        *(unsigned char *)(self + 0x2F6) = 0;                                   \
        *(unsigned char *)(self + 0x2F7) = 0;                                   \
        *(unsigned char *)(self + 0x2F5) = 0;                                   \
    }
