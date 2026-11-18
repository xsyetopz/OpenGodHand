// Player-family state functions in 0x110000-0x120000, over raw offsets.
#include "game/cEm00StateDecls.h"
#include "game/cVec.h"

extern "C" {
int func_002C2638(void *, int, float *, float *);
void func_00124E58(void *);
void func_0012B928(void *);
void func_001268F0(void *);
void func_00124EC0(void *);
void clearMotionCam__4pl00UiUi(void *, unsigned, unsigned);
void func_0012C348(void *, int);
void func_0012AC28(void *);
int func_00123938(void *, int);
void func_0010A408(void *, int, int, int, int, int);
void func_0010A420(void *, int, int, int, int, int);
void func_0010A438(void *);
}

struct cFn110Snd {
    void SeCall(int, int, void *, int, void *, int, int) __asm__("SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii");
};
extern cFn110Snd Snd;
extern unsigned Sys;
extern unsigned short D_00747A50;
extern char g_SceAt[];
extern unsigned char D_005CB010;

// FUNCTION: GAME 0x1161E0
extern "C" void func_001161E0(char *self)
{
    *(float *)(self + 0x54C) = 5.0f;
    unsigned f = *(unsigned *)(self + 0x15F4) | 0x2080;
    *(unsigned *)(self + 0x15F4) = f;
    switch (B(0x2F6)) {
    case 0:
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_001268F0(self);
        func_00124E58(self);
        {
            char *t = *(char **)(self + 0x304);
            func_002A8578(self, *(int *)(t + 0x8D8) + (int)t, *(int *)(t + 0x8DC) + (int)t, 0, 0.0f, 0, 0);
        }
        B(0x2F6)++;
    case 1:
        func_00124EC0(self);
        moveMotion((cObjBase *)self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

class cFn110Obj {
public:
    typedef void (cFn110Obj::*Act)();
    virtual void vf();
};
extern cFn110Obj::Act D_003BD328[];

// FUNCTION: GAME 0x11A820
extern "C" void func_0011A820(cFn110Obj *self)
{
    char *p = (char *)self;
    func_00124E58(self);
    *(short *)(p + 0x5E0) = 0;
    *(short *)(p + 0x5E2) = 0;
    *(char *)(p + 0x1603) = 0;
    *(short *)(p + 0x1618) = 0;
    func_0012B928(self);
    if (*(unsigned char *)(p + 0x2F5) > 0x25)
        *(unsigned char *)(p + 0x2F5) = 0;
    (self->*D_003BD328[*(unsigned char *)(p + 0x2F5)])();
}

// FUNCTION: GAME 0x1169D8
extern "C" int func_001169D8(char *self)
{
    cVec pos __attribute__((aligned(16)));
    float y;
    __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(&pos) : "memory");
    if (D_00747A50 != 0x700)
        return 0;
    if (!func_002C2638(g_SceAt, *(int *)(self + 0xF0), (float *)&pos, &y))
        return 0;
    if (D_005CB010)
        return 0;
    *(cVec *)(self + 0x580) = pos;
    *(float *)(self + 0x598) = y;
    B(0x2F5) = 0x37;
    B(0x2F4) = 0;
    B(0x2F6) = 0;
    B(0x2F7) = 0;
    return 1;
}

// FUNCTION: GAME 0x115F60
extern "C" void func_00115F60(char *self)
{
    *(float *)(self + 0x54C) = 5.0f;
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_001268F0(self);
        func_00124E58(self);
        cVec *v = *(cVec **)(self + 0xF0);
        v->x = *(float *)(self + 0x660);
        (*(cVec **)(self + 0xF0))->z = *(float *)(self + 0x668);
        *(cVec *)(self + 0x490) = **(cVec **)(self + 0xF0);
        *(float *)(self + 0x104) = *(float *)(self + 0x670);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x8B8) + (int)t, *(int *)(t + 0x8BC) + (int)t, 0, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self)) {
            clearMotionCam__4pl00UiUi(self, 1, 0);
            B(0x2F4) = 0;
            B(0x2F5) = 0;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x11A530
extern "C" void func_0011A530(char *self)
{
    *(unsigned *)(self + 0x15F4) |= 0x80;
    switch (B(0x2F6)) {
    case 0: {
        int t = *(int *)(self + 0x304);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        void *p = *(void **)(self + 0x6A0);
        int a = *(int *)(t + 0x28) + t;
        int b = *(int *)(t + 0x2C) + t;
        if (p) {
            func_002A8578(p, *(int *)(t + 0x36C) + t, *(int *)(t + 0x388) + t, 10, 0.0f, 0, 0);
            int u = *(int *)(self + 0x304);
            a = *(int *)(u + 0x344) + u;
            b = *(int *)(u + 0x348) + u;
            B(0x2F7) = 3;
        }
        if (*(int *)(self + 0x698)) {
            int u = *(int *)(self + 0x304);
            a = *(int *)(u + 0x3AC) + u;
            b = *(int *)(u + 0x3B0) + u;
            B(0x2F7) = 3;
        }
        func_002A8578(self, a, b, 3, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        moveMotion((cObjBase *)self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x1160A0
extern "C" void func_001160A0(char *self)
{
    *(float *)(self + 0x54C) = 5.0f;
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_001268F0(self);
        func_00124E58(self);
        cVec *v = *(cVec **)(self + 0xF0);
        v->x = *(float *)(self + 0x660);
        (*(cVec **)(self + 0xF0))->z = *(float *)(self + 0x668);
        *(cVec *)(self + 0x490) = **(cVec **)(self + 0xF0);
        *(float *)(self + 0x104) = *(float *)(self + 0x670);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x954) + (int)t, *(int *)(t + 0x958) + (int)t, 0, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self)) {
            clearMotionCam__4pl00UiUi(self, 1, 0);
            B(0x2F4) = 0;
            B(0x2F5) = 0;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x11AC80
extern "C" void func_0011AC80(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        int a = *(int *)(t + 0x878) + (int)t;
        int b = *(int *)(t + 0x87C) + (int)t;
        Snd.SeCall(0, 0xCF, self, 0, 0, 0, 0);
        *(float *)(self + 0x54C) = 10.0f;
        func_002A8578(self, a, b, 1, 0.0f, 0, 0);
        clearMotionCam__4pl00UiUi(self, 0, 0);
        func_0012C348(self, 0);
        if (irand() & 1) {
            func_0012AC28(self);
            func_0012B928(self);
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
    func_00123938(self, 1);
}

// FUNCTION: GAME 0x11B280
extern "C" void func_0011B280(char *self)
{
    *(float *)(self + 0x54C) = 15.0f;
    switch (B(0x2F6)) {
    case 0: {
        int a;
        int b;
        if (B(0x2F7) || (Sys & 0xF0)) {
            int t = *(int *)(self + 0x304);
            a = *(int *)(t + 0x51C) + t;
            b = *(int *)(t + 0x520) + t;
            func_0010A408(self, 10, 0x17, 0x2A, 0, 10);
            func_0010A420(self, 10, 0x17, 0x2A, 0, 10);
            *(char *)(self + 0x1684) = 0;
        } else {
            int t = *(int *)(self + 0x304);
            a = *(int *)(t + 0x174) + t;
            b = *(int *)(t + 0x178) + t;
        }
        func_002A8578(self, a, b, 10, 0.0f, 0, 0);
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
        if (!func_00123938(self, 1))
            func_0010A438(self);
    }
}
