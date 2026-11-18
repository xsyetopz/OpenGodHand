// Small free functions of the cOm* object units in 0x190000-0x19FFFF.
#include "game/cVec.h"

extern "C" void *func_001B6E90(void *self);
extern "C" void func_0016F640(void *p, int v);
extern "C" void SetDamageCollActive__11cDamageUnitb(void *u, int on);
extern "C" void setMeshDispFromLayer__7cOmBaseUib(void *self, unsigned layer, int on);
extern "C" void func_001B7300(void *self, int a, int b);
extern const char D_00425820[];

struct cFn190Snd {
    void SeCall(int, int, void *, int, void *, int, int) __asm__("SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii");
};
extern cFn190Snd Snd;

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")

// FUNCTION: GAME 0x195980
struct vtF {
    char _p[0x68];
    short adj;
    short _pad;
    cVec *(*fn)(void *);
};
struct sF {
    char _p[0x214];
    vtF *vt;
};
extern "C" void func_00195980(sF *s)
{
    s->vt->fn((char *)s + s->vt->adj);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x194CB0
// original lays the shared epilogue first and the bgez branches back to it; compiled has bne/b around the early return (5 words)
extern "C" void func_00194CB0(char *self)
{
    unsigned char s = *(unsigned char *)(self + 0x2F6);
    if (s != 0) {
        if (s != 1)
            return;
    } else {
        *(unsigned short *)(self + 0xAF0) = 0;
        *(unsigned char *)(self + 0x2F6) = 1;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
    int t = *(unsigned short *)(self + 0xAF0) - 1;
    *(unsigned short *)(self + 0xAF0) = t;
    if ((short)t < 0) {
        unsigned char b = *(unsigned char *)(self + 0x2F5);
        *(unsigned char *)(self + 0x2F5) = 2;
        *(unsigned char *)(self + 0xAF2) = b;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
}

#endif

// FUNCTION: GAME 0x19C050
extern "C" void func_0019C050(char *self)
{
    short id = *(short *)(self + 0x5F6);
    if (id >= 0)
        Snd.SeCall(2, id, self, 0, 0, 0, 0);
    Snd.SeCall(2, 0x13, self, 0, 0, 0, 0);
}

// FUNCTION: GAME 0x1928D8
extern "C" void func_001928D8(char *self)
{
    void *u = *(void **)(self + 0x604);
    if (u)
        SetDamageCollActive__11cDamageUnitb(u, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x40, 1);
    func_001B7300(self, 0, 0);
    func_001B7300(self, 0x80, 0);
    *(unsigned int *)(self + 0x250) |= 0x10000;
}

// FUNCTION: GAME 0x19AE98
extern "C" void *func_0019AE98(char *self)
{
    char *p = self + 0x610;
    int i = 0xB;
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00425820;
    do {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    } while (--i != -1);
    *(unsigned char *)(self + 0xA92) = 0;
    return self;
}

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

// FUNCTION: GAME 0x1900C8
FN190_STOP(func_001900C8)
// FUNCTION: GAME 0x199CC8
FN190_STOP(func_00199CC8)
// FUNCTION: GAME 0x19D248
FN190_STOP(func_0019D248)
// FUNCTION: GAME 0x19FDB0
FN190_STOP(func_0019FDB0)
