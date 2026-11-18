// Player-family state functions in 0x100000-0x110000, over raw offsets.
#include "game/Fn110n.h"

extern float D_003BD488;

static inline int IsSet(const int &v) { return v != 0; }
static inline char *Slot0(char *o)
{
    if (IsSet(*(unsigned char *)(o + 0x2B4)))
        return **(char ***)(o + 0x278);
    return 0;
}
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
extern char *D_00747A98;
extern "C" int setupModel__6cModelPC10SCR_HEADERUibT3(char *, char *, unsigned, int, int);
extern "C" void calcParts__6cModel(char *);
extern "C" void func_00100870(char *);
float Adjust_theta(float);
extern "C" void func_001034E0(char *);

// FUNCTION: GAME 0x10CB10
extern "C" void func_0010CB10(char *self)
{
    if (*(short *)(self + 0x54A) <= 0)
        *(short *)(self + 0x54A) = 1;
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_00124E58(self);
        void *o = *(void **)(self + 0x6A0);
        char *t = *(char **)(self + 0x304);
        int a = *(int *)(t + 0x7C) + (int)t;
        int b = *(int *)(t + 0x80) + (int)t;
        if (o) {
            func_002A8578(o, *(int *)(t + 0x39C) + (int)t, *(int *)(t + 0x3A0) + (int)t, 5, 0.0f, 0, 0);
            char *u = *(char **)(self + 0x304);
            int c = *(int *)(u + 0x3A4);
            int d = *(int *)(u + 0x3A8);
            a = c + (int)u;
            b = d + (int)u;
        }
        func_002A8578(self, a, b, 5, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        *(float *)(self + 0x15F0) = D_003BD488;
        if (moveMotion((cObjBase *)self)) {
            clearMotionCam__4pl00UiUi(self, 1, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        func_00123938(self, 1);
    }
}

// FUNCTION: GAME 0x100378
extern "C" int func_00100378(char *self)
{
    int ok = 0;
    char *h = *(char **)(self + 0x304);
    if (setupModel__6cModelPC10SCR_HEADERUibT3(self, (char *)(*(int *)(h + 4) + (int)h), *(int *)(h + 8) + (int)h, 0, 0)) {
        *(unsigned *)(self + 0x2F0) |= 0x80;
        ok = 1;
        *(unsigned *)(self + 0x250) |= 0x10000;
        *(int *)(self + 0x20D0) = 0;
        if (Slot0(self)) {
            char *o = Slot0(self);
            V3o *d = (V3o *)(o + 0xE0);
            d->x = V0001.x;
            d->y = V0001.y;
            d->z = V0001.z;
            V3o *e = *(V3o **)(Slot0(self) + 0xD0);
            e->x = V0001.x;
            e->y = V0001.y;
            e->z = V0001.z;
        }
        calcParts__6cModel(self);
        func_00100870(self);
        D_00747A98 = self;
    }
    *(unsigned *)(self + 0x254) |= 0x8000000;
    *(unsigned *)(self + 0x2F0) |= 1;
    return ok;
}

// FUNCTION: GAME 0x102A80
extern "C" void func_00102A80(char *self)
{
    char *pl = (char *)Getplayer();
    switch (B(0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x1C) + (int)t, *(int *)(t + 0x20) + (int)t, 10, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        if (*(unsigned char *)(pl + 0x61F)) {
            float v = (3.1415927f - *(float *)(pl + 0x608)) - 0.5235988f;
            if (v < 0.0f)
                v = 0.0f;
            v *= 0.4f;
            if (v > 0.04188790f)
                v = 0.04188790f;
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

struct Q4o { float v[4]; } __attribute__((aligned(16)));
float capVu0Atan2(float, float);
extern "C" void *SetEffect_o(int, int, void *, void *, int, unsigned) __asm__("SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2");
extern "C" void func_0012C348(void *, int);
extern "C" void clearMotionCam__4pl00UiUi(void *, unsigned, unsigned);

// FUNCTION: GAME 0x103170
extern "C" void func_00103170(char *self)
{
    char *pl = (char *)Getplayer();
    *(float *)(self + 0x54C) = 5.0f;
    switch (B(0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x2C) + (int)t, *(int *)(t + 0x30) + (int)t, 1, 0.0f, 0, 0);
        SetEffect_o(0, 0x52, self, 0, -1, 0xFFFFFFFFu);
        func_0012C348(pl, 0);
        clearMotionCam__4pl00UiUi(pl, 0, 0);
        char *p = *(char **)(self + 0x5B0);
        if (p) {
            float t4[4] __attribute__((aligned(16)));
            __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Q4o *)t4) : "r"(p + 0x10));
            float a = capVu0Atan2(t4[0], t4[2]) + 3.1415927f;
            *(float *)(self + 0x104) = a;
            *(float *)(self + 0x104) = Adjust_theta(a);
        }
        B(0x2F6)++;
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
}
