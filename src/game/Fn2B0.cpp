#include "game/cScenario.h"
#include "game/cVec.h"

class cMatrix;

struct cVec16Fn {
    float x, y, z, w;
} __attribute__((aligned(16)));

extern cScenario *g_Sce;
extern char *pCamWork;
extern "C" int func_002DB0D0(int, cVec16Fn *, float);
extern "C" void func_002B6420(void *);
extern "C" void func_00147C60(void *, float *);
extern "C" void func_00147C88(void *, char *, int);
void MtxGetScaleVec(cVec &, const cMatrix &);

// FUNCTION: GAME 0x2B4690
extern "C" int func_002B4690(int, const char *s)
{
    cVec16Fn v;
    int id = g_Sce->getObjIdFromStr(s);
    if (id == 0xFFFF)
        return 0;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(&v), "r"(pCamWork + 0x210) : "memory");
    return func_002DB0D0(id, &v, -1.0f);
}

// FUNCTION: GAME 0x2B6080
extern "C" cVec16Fn *func_002B6080(cVec16Fn *out, char *o)
{
    cVec16Fn v;
    __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(&v) : "memory");
    func_002B6420(o);
    MtxGetScaleVec(*(cVec *)&v, *(const cMatrix *)(o + 0xB0));
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(out), "r"(&v) : "memory");
    return out;
}

// FUNCTION: GAME 0x2B60D0
extern "C" cVec16Fn *func_002B60D0(cVec16Fn *out, char *o)
{
    cVec16Fn v;
    func_002B6420(o);
    __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(&v) : "memory");
    if (*(float *)(o + 0x20) != 0.0f && *(float *)(o + 0x24) != 0.0f && *(float *)(o + 0x28) != 0.0f)
        func_00147C88(&v, o + 0xB0, 0);
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(out), "r"(&v) : "memory");
    return out;
}

// FUNCTION: GAME 0x2B6160
extern "C" cVec16Fn *func_002B6160(cVec16Fn *out, char *o)
{
    cVec16Fn v;
    __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(&v) : "memory");
    func_002B6420(o);
    func_00147C60(&v, (float *)(o + 0xB0));
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(out), "r"(&v) : "memory");
    return out;
}

// FUNCTION: GAME 0x2B62E0
extern "C" void *func_002B62E0(void *d, char *s)
{
    void *r = d;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(r), "r"(s + 0x20) : "memory");
    return r;
}

// FUNCTION: GAME 0x2B62F8
extern "C" void *func_002B62F8(void *d, char *s)
{
    void *r = d;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(r), "r"(s + 0x30) : "memory");
    return r;
}

// FUNCTION: GAME 0x2B6310
extern "C" void *func_002B6310(void *d, char *s)
{
    void *r = d;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(r), "r"(s + 0x40) : "memory");
    return r;
}

// FUNCTION: GAME 0x2BAA90
extern "C" void *func_002BAA90(void *d, char *s)
{
    void *r = d;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(r), "r"(s + 0x110) : "memory");
    return r;
}
