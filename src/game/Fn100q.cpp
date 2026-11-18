// Player-family state functions in 0x100000-0x110000, over raw offsets.
#include "game/Fn110n.h"


struct V3o {
    float x, y, z;
    void set(const V3o &o)
    {
        if (this != &o) {
            x = o.x;
            y = o.y;
            z = o.z;
        }
    }
};
extern V3o V0001;
struct Q4o { float v[4]; } __attribute__((aligned(16)));
float capVu0Atan2(float, float);
extern "C" void *SetEffect_o(int, int, void *, void *, int, unsigned) __asm__("SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2");
extern "C" void func_0012C348(void *, int);
extern "C" void clearMotionCam__4pl00UiUi(void *, unsigned, unsigned);
extern "C" void func_001034E0(char *);

struct Svp {
    float v[4] __attribute__((aligned(16)));
    Svp() { __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Q4o *)v)); }
};
extern "C" V3o *func_0012A2E0(void *);
extern "C" void func_0012A3C0(void *);

// FUNCTION: GAME 0x10FF80
extern "C" void func_0010FF80(char *self)
{
    Svp acc;
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        V3o *pos = (V3o *)(self + 0x580);
        func_00124E58(self);
        func_00126770(self);
        clearMotionCam__4pl00UiUi(self, 0, 0);
        pos->set(*func_0012A2E0(self));
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x20C) + (int)t, *(int *)(t + 0x6DC) + (int)t, 3, 15.0f, 0, 0);
        float t1[4] __attribute__((aligned(16)));
        char *q = *(char **)(self + 0xF0);
        V3o *src = (V3o *)t1;
        Svp d;
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(Q4o *)d.v) : "r"(pos), "r"(q), "r"(src));
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Q4o *)t1) : "r"(d.v));
        ((V3o *)(self + 0x590))->set(*(V3o *)t1);
        B(0x2F6)++;
    }
    case 1: {
        float k = 0.1f;
        float t1[4] __attribute__((aligned(16)));
        float d_[4] __attribute__((aligned(16)));
        float *d = d_;
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Q4o *)d) : "r"(self + 0x590));
        __asm__ volatile("lqc2 $vf4,%0\n\tmfc1 $t0,%1\n\tqmtc2.ni $t0,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,%0" : "+m"(*(Q4o *)d) : "f"(k) : "$8");
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Q4o *)t1) : "r"(d));
        ((V3o *)acc.v)->set(*(V3o *)t1);
        char *p = *(char **)(self + 0xF0);
        __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(p), "r"(acc.v) : "memory");
        __asm__ volatile("lqc2 $vf4,%0\n\tlqc2 $vf5,0(%1)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "+m"(*(Q4o *)(self + 0x590)) : "r"(acc.v));
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        if (!(*(unsigned short *)(self + 0x3AC) & 4))
            ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    }
    if (*(unsigned short *)(self + 0x3AC) & 1)
        func_0012A3C0(self);
    *(unsigned short *)(self + 0x3AC) |= 0x200;
    func_00123938(self, 1);
}

#ifdef NONMATCHING
struct Vq {
    float x, y, z, w;
    Vq(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};
static inline int Ltp(const int &v, int n) { return n < v; }
extern char g_DmgManage_p[] __asm__("g_DmgManage");
extern char D_003C3F58[];
extern int D_00586A88;
extern "C" int setupModel_p(char *, int, int, int, int) __asm__("setupModel__6cModelPC10SCR_HEADERUibT3");
extern "C" void setRotationOrder__6cPartsUc(char *, int);
extern "C" void KageInit_p(char *, char *, char *) __asm__("KageInit__8cObjBaseP12GP_KAGE_WORKP20_COBJBASE_SHADOWDATA");
extern "C" void CreateUnit_p(void *, char *, int, float) __asm__("CreateUnit__21cCollisionSolidManageP8cGameObjQ225cCollisionSolidManageUnit9ePRIORITYf");
extern "C" void CreateSphere_p(void *, char *, char *, const Vq &, float) __asm__("CreateSphere__21cCollisionSolidManageP8cGameObjRC7cMatrixRC4cVecf");
extern "C" short getVitalMax_p(void *) __asm__("getVitalMax__9cCoreSave");
extern "C" short getVital_p(void *) __asm__("getVital__9cCoreSave");
extern "C" void *CreateDamageTake_p(void *, char *, int) __asm__("CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND");
extern "C" void *AddDamageCollSphere_p(void *, char *, const Vq &, float) __asm__("AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf");

// DRAFT: GAME 0x101EB8 (90 differing words after 3 variants; frame 0x60 vs 0x50, constant register choice)
extern "C" int func_00101EB8(char *self)
{
    char *h = *(char **)(self + 0x304);
    if (!setupModel_p(self, *(int *)(h + 8) + (int)h, *(int *)(h + 4) + (int)h, 0, 0))
        return 0;
    *(unsigned *)(self + 0x254) |= 0x8000000;
    setRotationOrder__6cPartsUc(self, 4);
    KageInit_p(self, self + 0x5C0, D_003C3F58);
    CreateUnit_p(&g_CollSolidManage, self, 5, 0.2f);
    CreateSphere_p(&g_CollSolidManage, self, self + 0x80, Vq(0.0f, 0.5f, 0.0f, 1.0f), 0.5f);
    *(short *)(self + 0x548) = getVitalMax_p(&CoreSave);
    short vit = getVital_p(&CoreSave);
    *(short *)(self + 0x54A) = (vit < *(short *)(self + 0x548)) ? vit : *(unsigned short *)(self + 0x548);
    if ((*(void **)(self + 0x5B0) = CreateDamageTake_p(g_DmgManage_p, self, 0))) {
        char *m = 0;
        if (Ltp(*(unsigned char *)(self + 0x2B4), 1))
            m = ((char **)*(char ***)(self + 0x278))[1];
        *(void **)(self + 0x5B4) = AddDamageCollSphere_p(*(void **)(self + 0x5B0), m + 0x80, Vq(0.0f, 0.0f, 0.0f, 1.0f), 0.25f);
    }
    char *t = *(char **)(self + 0x304);
    B(0x2F5) = 6;
    B(0x2F4) = 0;
    B(0x2F6) = 0;
    B(0x2F7) = 0;
    float z = 0.0f;
    func_002A8578(self, *(int *)(t + 0xC) + (int)t, *(int *)(t + 0x10) + (int)t, 0, z, 0, 0);
    moveMotion((cObjBase *)self);
    *(unsigned *)(self + 0x250) |= 2;
    *(float *)(self + 0x5BC) = z;
    *(float *)(self + 0x5B8) = 0.02f;
    ((V3o *)(self + 0x490))->set(**(V3o **)(self + 0xF0));
    D_00586A88 = (int)self;
    return 1;
}
#endif
