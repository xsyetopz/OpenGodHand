// Player-family state functions in 0x100000-0x110000, over raw offsets.
#include "game/cEm00StateDecls.h"

extern const float D_003BC7C0;
extern const float D_003BD48C;
extern "C" void func_00124E68(void *, float);
extern "C" void *__7cPlBase(void *);
extern const char D_0041D220[];
extern const char D_0041B800[];
struct Qa { float f[4] __attribute__((aligned(16))); };
#define QZ(f) __asm__ volatile("sqc2 $vf0,%0" : "=m"(f))
extern "C" void clearMotionCam__4pl00UiUi(void *, unsigned, unsigned);
extern "C" void func_00126770(void *);
extern "C" void calcParts__6cModel(void *);
extern "C" void InverseKinematics__2IKP8cObjBase(void *, void *);
extern "C" void calcWorldParts__6cModel(void *);
extern "C" void func_001CF3A8(void *);
extern "C" void func_00123938(void *, int);
extern "C" int SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, void *, void *, int, unsigned);


// FUNCTION: GAME 0x102BD8
extern "C" void func_00102BD8(char *self)
{
    char *pl = (char *)Getplayer();
    switch (B(0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        int a = *(int *)(t + 0x24) + (int)t;
        func_002A8578(self, a, a, 5, 0.0f, 0, 0);
        B(0x2F6) = B(0x2F6) + 1;
    }
    case 1:
        *(float *)(pl + 0x15F0) = D_003BC7C0;
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        float one = 1.0f;
        ((cObjBase *)self)->addNullSpeed_Rotation(one);
        ((cObjBase *)self)->addNullSpeed(one);
    }
}

// FUNCTION: GAME 0x102FE8
extern "C" void func_00102FE8(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x54) + (int)t, *(int *)(t + 0x58) + (int)t, 0, 0.0f, 0, 0);
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0, 0x51, self, 0, -1, 0xFFFFFFFF);
        unsigned char n = B(0x2F6) + 1;
        B(0x2F6) = n;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        float one = 1.0f;
        ((cObjBase *)self)->addNullSpeed_Rotation(one);
        ((cObjBase *)self)->addNullSpeed(one);
    }
}

// FUNCTION: GAME 0x10CC58
extern "C" void func_0010CC58(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x220) + (int)t, *(int *)(t + 0x278) + (int)t, 3, 0.0f, 0, 0);
        *(int *)(self + 0x15B0) = 0x10;
        B(0x2F6) = B(0x2F6) + 1;
    }
    case 1:
        *(float *)(self + 0x15F0) = D_003BD48C;
        if (*(int *)(self + 0x15B0)) {
            *(int *)(self + 0x15B0) = *(int *)(self + 0x15B0) - 1;
            func_00124E68(self, 0.19634954f);
        }
        if (moveMotion((cObjBase *)self)) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
            func_00123938(self, 1);
        }
    }
}

// FUNCTION: GAME 0x107E40
extern "C" char *func_00107E40(char *self)
{
    __7cPlBase(self);
    *(const void **)(self + 0x214) = D_0041D220;
    QZ(*(Qa *)(self + 0x630));
    QZ(*(Qa *)(self + 0x650));
    QZ(*(Qa *)(self + 0x660));
    Qa *p = (Qa *)(self + 0x1580);
    int i = 1;
    do {
        QZ(*p);
        p++;
    } while (--i != -1);
    QZ(*(Qa *)(self + 0x15E0));
    *(int *)(self + 0x698) = 0;
    *(const void **)(self + 0x4AC) = D_0041B800;
    *(int *)(self + 0x6A0) = 0;
    *(int *)(self + 0x69C) = 0;
    *(int *)(self + 0x6A4) = 0;
    *(int *)(self + 0x6A8) = 0;
    return self;
}

// FUNCTION: GAME 0x10B888
extern "C" void SubscreenMode__4pl00Ui(char *self, int on)
{
    if (on) {
        B(0x420) |= 1;
        B(0x2F4) = 5;
        *(float *)(self + 0x54C) = 5.0f;
        B(0x2F5) = 0;
        B(0x2F6) = 0;
        B(0x2F7) = 0;
    } else {
        B(0x420) &= 0xFE;
        clearMotionCam__4pl00UiUi(self, 0, 0);
        func_00126770(self);
        char *t = *(char **)(self + 0x304);
        B(0x2F4) = 0;
        B(0x2F5) = 0;
        B(0x2F6) = 0;
        B(0x2F7) = 0;
        func_002A8578(self, *(int *)(t + 0x28) + (int)t, *(int *)(t + 0x2C) + (int)t, 0, 0.0f, 0, 0);
        moveMotion((cObjBase *)self);
        calcParts__6cModel(self);
        InverseKinematics__2IKP8cObjBase(self + 0x448, self);
        calcWorldParts__6cModel(self);
        void *m = *(void **)(self + 0x6A8);
        if (m) {
            func_001CF3A8(m);
            calcParts__6cModel(*(void **)(self + 0x6A8));
        }
    }
}
// FUNCTION: GAME 0x102DE8
extern "C" void func_00102DE8(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        int a, b;
        char *t;
        unsigned char c = B(0x2F7);
        if (c == 1) {
            t = *(char **)(self + 0x304);
            a = *(int *)(t + 0x3C);
            b = *(int *)(t + 0x40);
        } else if (c < 2) {
            t = *(char **)(self + 0x304);
            a = *(int *)(t + 0x34);
            b = *(int *)(t + 0x38);
        } else if (c == 2) {
            t = *(char **)(self + 0x304);
            a = *(int *)(t + 0x44);
            b = *(int *)(t + 0x48);
        } else {
            t = *(char **)(self + 0x304);
            a = *(int *)(t + 0x34);
            b = *(int *)(t + 0x38);
        }
        func_002A8578(self, a + (int)t, b + (int)t, 5, 0.0f, 0, 0);
        B(0x2F6) = B(0x2F6) + 1;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        float one = 1.0f;
        ((cObjBase *)self)->addNullSpeed_Rotation(one);
        ((cObjBase *)self)->addNullSpeed(one);
    }
}
