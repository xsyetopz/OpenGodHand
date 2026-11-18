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

extern int D_00747A78;

// FUNCTION: GAME 0x1027D8
extern "C" void func_001027D8(char *self)
{
    char *pl = (char *)Getplayer();
    switch (B(0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0xC) + (int)t, *(int *)(t + 0x10) + (int)t, 10, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        if (!(D_00747A78 & 0x2000000) && *(unsigned char *)(pl + 0x61F)) {
            float v = *(float *)(pl + 0x608) - 0.5235988f;
            if (v < 0.0f)
                v = 0.0f;
            v *= 0.2f;
            if (v > 0.06544985f)
                v = 0.06544985f;
            if (*(float *)(pl + 0x604) < 0.0f)
                v = -v;
            *(float *)(self + 0x104) += v;
            *(float *)(self + 0x104) = Adjust_theta(*(float *)(self + 0x104));
        }
        moveMotion((cObjBase *)self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    func_001034E0(self);
}

extern "C" void func_00129EB0(void *);

// FUNCTION: GAME 0x10FE18
extern "C" void func_0010FE18(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_00124E58(self);
        func_00126770(self);
        clearMotionCam__4pl00UiUi(self, 0, 0);
        func_0010A408(self, 0x14, 0xB, 10, 0, 10);
        func_0010A420(self, 0x14, 0xB, 10, 0, 10);
        B(0x1684) = 0;
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x100) + (int)t, *(int *)(t + 0x108) + (int)t, 3, 0.0f, 0, 0);
        B(0x2F6)++;
        *(int *)(self + 0x15B0) = 1;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    func_0010A438(self);
    if ((*(unsigned short *)(self + 0x3AC) & 3) && *(int *)(self + 0x15B0)) {
        *(int *)(self + 0x15B0) = 0;
        func_00129EB0(self);
    }
    func_00123938(self, 1);
}

extern "C" void DieDemoStart__4cSnd(void *);
extern "C" void func_001FA1A0(void *);
extern unsigned D_00747A24;

// FUNCTION: GAME 0x103370
extern "C" void func_00103370(char *self)
{
    char *pl = (char *)Getplayer();
    *(float *)(self + 0x54C) = 30.0f;
    switch (B(0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        int a = *(int *)(t + 0x4C) + (int)t;
        int b = *(int *)(t + 0x50) + (int)t;
        DieDemoStart__4cSnd(&Snd);
        func_001FA1A0(&CoreSave);
        func_0012C348(pl, 3);
        func_002A8578(self, a, b, 2, 0.0f, 0, 0);
        SetEffect_o(0, 0x53, self, 0, -1, 0xFFFFFFFFu);
        *(int *)(self + 0x1490) = 0x82;
        B(0x2F6)++;
    }
    case 1:
        if (*(int *)(self + 0x1490))
            (*(int *)(self + 0x1490))--;
        else
            D_00747A24 |= 8;
        if (moveMotion((cObjBase *)self)) {
            D_00747A24 |= 8;
            B(0x2F6)++;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    case 2:
        break;
    }
}

#ifdef NONMATCHING
static inline int InRangeo(const int &n, int i) { return i >= 0 && i < n; }
static inline char *SlotNo(char *o, int i)
{
    if ((unsigned char)InRangeo(*(unsigned char *)(o + 0x2B4), i))
        return ((char **)*(char ***)(o + 0x278))[i];
    return 0;
}
extern "C" void sceVu0ApplyMatrix(float *, void *, float *);

// DRAFT: GAME 0x107C68 (74 differing words, SlotN range test and tbl register)
extern "C" void func_00107C68(char *self, char *ls, char *base)
{
    unsigned i = 0;
    unsigned char *idx = *(unsigned char **)(ls + 4);
    for (; i < *(unsigned *)ls; i++, idx++) {
        char *o;
        char **tbl = *(char ***)(ls + 0x54);
        if (tbl)
            o = tbl[*idx];
        else
            o = SlotNo(self, *idx);
        char *e = base + *idx * 0xA0;
        float w[4] __attribute__((aligned(16)));
        float v[4] __attribute__((aligned(16)));
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Q4o *)v) : "r"(e));
        sceVu0ApplyMatrix(v, o + 0x80, v);
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Q4o *)w) : "r"(v));
        ((V3o *)(e + 0x40))->set(*(V3o *)w);
        ((V3o *)(e + 0x50))->set(*(V3o *)(e + 0x40));
        *(int *)(e + 0x30) = 0;
        *(int *)(e + 0x34) = 0;
        *(int *)(e + 0x38) = 0;
    }
}
#endif

extern "C" void SetMotionStep__FP8cObjBasef(char *, float);
extern "C" void func_0012BFB8(char *);
extern "C" int func_00123938_i(void *, int) __asm__("func_00123938");
extern float D_003BD478;

// FUNCTION: GAME 0x10C930
extern "C" void func_0010C930(char *self)
{
    if (*(short *)(self + 0x54A) <= 0)
        *(short *)(self + 0x54A) = 1;
    *(float *)(self + 0x5A8) = 1.5f;
    SetMotionStep__FP8cObjBasef(self, 1.5f);
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        if (*(signed char *)(self + 0x648) > 10)
            *(signed char *)(self + 0x648) = 10;
        char *t = *(char **)(self + 0x304);
        void *o = *(void **)(self + 0x6A0);
        int a = *(int *)(t + 0x60) + (int)t;
        int b = *(int *)(t + 0x64) + (int)t;
        if (o) {
            func_002A8578(o, *(int *)(t + 0x374) + (int)t, *(int *)(t + 0x390) + (int)t, 10, 0.0f, 0, 0);
            char *u = *(char **)(self + 0x304);
            int c = *(int *)(u + 0x354);
            int d = *(int *)(u + 0x358);
            a = c + (int)u;
            b = d + (int)u;
        }
        func_002A8578(self, a, b, 10, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        if (*(unsigned char *)(self + 0x61F)) {
            float v = (3.1415927f - *(float *)(self + 0x608)) - 0.5235988f;
            if (v < 0.0f)
                v = 0.0f;
            v *= 0.4f;
            if (D_003BD478 < v)
                v = D_003BD478;
            if (*(float *)(self + 0x604) < 0.0f)
                v = -v;
            *(float *)(self + 0x104) += v;
            *(float *)(self + 0x104) = Adjust_theta(*(float *)(self + 0x104));
        }
        moveMotion((cObjBase *)self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (!func_00123938_i(self, 0))
        func_0012BFB8(self);
}

#ifdef NONMATCHING
struct cMatrixo { float m[16] __attribute__((aligned(16))); };
struct Svo {
    float v[4] __attribute__((aligned(16)));
    Svo() { __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Q4o *)v)); }
    operator float *() { return v; }
};
extern "C" void MtxInitRotY__FR7cMatrixf(cMatrixo &, float) ;
extern "C" float func_00101E28(float *);
extern "C" float capVu0Sin__Ff(float);
extern "C" void func_00104010(void *, void *, void *);
extern float D_003BC730, D_003BC734, D_003BC738, D_003BC73C, D_003BC740, D_003BC744;

// DRAFT: GAME 0x100CE0 (113 differing words, s2 caching of the &a address shifts the frame)
extern "C" void func_00100CE0(char *self)
{
    if (*(unsigned short *)(self + 0x2FE) == 0x101) {
        *(unsigned *)(self + 0x20AC) &= 0xFFFFFBFF;
        char *o = *(char **)(self + 0x20D0);
        if (o) {
            if (*(unsigned short *)(o + 0x2FE) == 0x100) {
                char *pl = (char *)Getplayer();
                if (*(unsigned short *)(pl + 0x3AC) & 0x800) {
                    cMatrixo m;
                    Svo a;
                    float t[4] __attribute__((aligned(16)));
                    float r = *(float *)(pl + 0x104);
                    MtxInitRotY__FR7cMatrixf(m, r);
                    a.v[0] = D_003BC730;
                    a.v[1] = D_003BC734;
                    a.v[2] = D_003BC738;
                    sceVu0ApplyMatrix(a, m.m, a);
                    Svo n;
                    float len = func_00101E28(a);
                    if (len > 0.0f) {
                        float s = 1.0f / len;
                        n.v[0] = a.v[0] * s;
                        n.v[1] = a.v[1] * s;
                        n.v[2] = a.v[2] * s;
                        n.v[3] = a.v[3];
                    }
                    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Q4o *)t) : "r"(n.v));
                    a.v[1] = t[1];
                    a.v[2] = t[2];
                    a.v[0] = t[0];
                    float f = capVu0Sin__Ff(D_003BC740) + 1.0f;
                    D_003BC740 = D_003BC740 + D_003BC744;
                    f = f * 0.5f * D_003BC73C;
                    D_003BC740 = Adjust_theta(D_003BC740);
                    __asm__ volatile("lqc2 $vf4,%0\n\tmfc1 $t0,%1\n\tqmtc2.ni $t0,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,%0" : "+m"(*(Q4o *)a.v) : "f"(f) : "$8");
                    ((V3o *)(self + 0x20B0))->set(*(V3o *)a.v);
                    *(unsigned *)(self + 0x20AC) |= 0x400;
                }
            }
        }
    }
    func_00104010(self, self + 0x2050, self + 0x4D0);
}
#endif

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
        Svp d;
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(Q4o *)d.v) : "r"(pos), "r"(q));
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
