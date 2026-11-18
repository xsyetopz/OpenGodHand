#include "game/cObj.h"

// Const-ref temporaries reproduce the lbu/sw-to-stack then register-branch pattern.
static inline int IsSet(const int &v) { return v != 0; }
static inline char *Slot0(char *o)
{
    if (IsSet(*(unsigned char *)(o + 0x2B4)))
        return **(char ***)(o + 0x278);
    return 0;
}

extern char g_DmgManage[];
extern char V0001[];
extern "C" void func_001B6FB8(void *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(void *, void *, void *, float);
extern "C" void setLayerDisplay__6cModelib(void *, int, int);

// FUNCTION: GAME 0x1B2548
extern "C" int func_001B2548(char *self)
{
    func_001B6FB8(self);
    *(void **)(self + 0x600) = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 1);
    if (*(void **)(self + 0x600)) {
        char *o = Slot0(self);
        cVec16 v;
        char *m = o + 0x80;
        cVec16 *pv = &v;
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(v) : "r"(V0001));
        AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(*(void **)(self + 0x600), m, pv, 2.25f);
        **(unsigned **)(self + 0x600) |= 1;
    }
    *(int *)(self + 0x624) = 0;
    *(char *)(self + 0x62C) = 0;
    *(char *)(self + 0x2F5) = 0;
    *(short *)(self + 0x548) = 0x3E8;
    *(short *)(self + 0x54A) = 0x3E8;
    *(unsigned *)(self + 0x5B8) |= 8;
    *(float *)(self + 0x620) = 1.8f;
    *(float *)(self + 0x628) = 0.036f;
    setLayerDisplay__6cModelib(self, 0, 1);
    setLayerDisplay__6cModelib(self, 0x40, 0);
    *(char *)(self + 0x62D) = 0;
    return 1;
}
