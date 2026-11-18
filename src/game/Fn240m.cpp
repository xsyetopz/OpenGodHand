// Mid-size units in 0x240000-0x260000.
#include "game/cEm00Fn240Decls.h"
#include "game/cVec.h"

extern "C" float fRand1_1__Fv();
extern "C" void func_001D05A0(void *, int);

// FUNCTION: GAME 0x247050
extern "C" void func_00247050(char *self)
{
    B(0x617) = 1;
    switch (B(0x2F6)) {
    case 0: {
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0x10A8) + (int)o, *(int *)(o + 0x10AC) + (int)o, 0xA, 0.0f, r, 0);
        *(float *)(self + 0x600) = fRand1_1__Fv() * 150.0f + 150.0f;
        B(0x2F6)++;
    }
    case 1: {
        moveMotion((cObjBase *)self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        float t = *(float *)(self + 0x600) - *(float *)(self + 0x5A8);
        *(float *)(self + 0x600) = t;
        if (t <= 0.0f)
            B(0x2F6) = 2;
        if (*(float *)(self + 0x16C0) > 0.0f)
            func_002705D8(self);
        break;
    }
    case 2: {
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0x11A8) + (int)o, *(int *)(o + 0x11B4) + (int)o, 0xA, 0.0f, r, 0);
        if (*(void **)(self + 0x6F0))
            func_001D05A0(*(void **)(self + 0x6F0), 0);
        B(0x2F6)++;
    }
    case 3:
        if (moveMotion((cObjBase *)self))
            B(0x2F6) = 0;
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x2464E0
extern "C" void func_002464E0(char *self)
{
    *(float *)(self + 0x54C) = 3.0f;
    B(0x617) = 1;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        char *o = *(char **)(self + 0x304);
        int a = *(int *)(o + 0x2504) + (int)o;
        int b = *(int *)(o + 0x2508) + (int)o;
        unsigned short r = func_00276468(self);
        *(unsigned *)(self + 0x16D0) &= 0xDFFFFFFF;
        func_002A8578(self, a, b, 0xA, 0.0f, r, 0);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self))
            B(0x2F6)++;
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        break;
    case 2: {
        B(0x1864) = 0;
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0x24EC) + (int)o, *(int *)(o + 0x24F0) + (int)o, 0xA, 0.0f, r, 0);
        B(0x2F6)++;
    }
    case 3:
        moveMotion((cObjBase *)self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        if (*(unsigned *)(self + 0x16D0) & 0x20000000)
            func_002705D8(self);
    }
}

extern "C" void func_0026B1E8(void *);
extern "C" void AddHeatGage__8cHeatSysfUi(void *, float, unsigned);

// FUNCTION: GAME 0x25C010
extern "C" void func_0025C010(char *self)
{
    char *pl = (char *)Getplayer();
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    *(float *)(self + 0x54C) = 3.0f;
    switch (B(0x2F6)) {
    case 0: {
        func_0026B1E8(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0x1074) + (int)o, *(int *)(o + 0x1078) + (int)o, 0, 0.0f, 0, 0);
        *(int *)(self + 0x5F0) = 0x2A;
        B(0x2F6)++;
        *(short *)(self + 0x56E) = 0xF;
        *(int *)(self + 0x16EC) = 0;
    }
    case 1: {
        if (*(short *)(self + 0x56E)) {
            *(unsigned short *)(self + 0x56E) = *(unsigned short *)(self + 0x56E) - 1;
            char *p = *(char **)(self + 0xF0);
            char *q = pl + 0x550;
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(p), "r"(q) : "memory");
        }
        int c = *(int *)(self + 0x5F0);
        if (c) {
            c--;
            *(int *)(self + 0x5F0) = c;
            if (c <= 0) {
                char *vt = *(char **)(self + 0x214);
                ((void (*)(char *, int, char *, int, int)) * (void **)(vt + 0xAC))(self + *(short *)(vt + 0xA8), 0x32, pl, 1, 0);
                AddHeatGage__8cHeatSysfUi(g_HeatSys, 10.0f, 0);
            }
        }
        if (moveMotion((cObjBase *)self)) {
            if (*(short *)(self + 0x54A) <= 0) {
                B(0x2F4) = 2;
                B(0x2F5) = 4;
                B(0x2F6) = 0;
            } else {
                B(0x2F4) = 1;
                B(0x2F5) = 0x16;
                B(0x2F6) = 2;
            }
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    }
    *(unsigned short *)(self + 0x3AC) |= 0x400;
}

extern "C" int func_002948C8(void *, int);
extern "C" cVec *func_001B8720(void *);
extern "C" unsigned char func_001B8640(void *);
extern "C" void setFire__5cOmbb(void *);

// FUNCTION: GAME 0x244708
extern "C" void func_00244708(char *self)
{
    int s1 = func_002948C8(g_EmManage, B(0x17B1));
    cVec v;
    __asm__ volatile("sqc2 $vf0, 0(%0)" : : "r"(&v) : "memory");
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    *(unsigned *)(self + 0x16D0) |= 0x10000;
    switch (B(0x2F6)) {
    case 0: {
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0x4FC) + (int)o, *(int *)(o + 0x500) + (int)o, 3, 0.0f, r, 0);
        Snd.SeCall(2, 0x64, self, 0, 0, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        v = *Getplayer()->m_pPos;
        if (s1) {
            cVec *p = func_001B8720((void *)s1);
            v = *p;
        }
        ((cGameObj *)self)->SetTgtTurn(v, *(float *)(self + 0x5A8) * 0.39269909f);
        if (moveMotion((cObjBase *)self))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (*(unsigned short *)(self + 0x3AC) & 1) {
        if (s1 && !func_001B8640((void *)s1))
            setFire__5cOmbb((void *)s1);
    }
}

// FUNCTION: GAME 0x2426A0
extern "C" void func_002426A0(char *self)
{
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    unsigned f = *(unsigned *)(self + 0x16D0) | 0x11000;
    *(unsigned *)(self + 0x16D0) = f | 0x20000;
    switch (B(0x2F6)) {
    case 0: {
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        int a = *(int *)(o + 0x3F4) + (int)o;
        int b = *(int *)(o + 0x3F8) + (int)o;
        float sp = 0.0f;
        if (*(int *)(self + 0x564) == 0x215)
            sp = 25.0f;
        func_002A8578(self, a, b, 0xA, sp, r, 0);
        *(unsigned *)(self + 0x16D0) &= 0xDFFFFFFF;
        B(0x2F6)++;
    }
    case 1:
        moveMotion((cObjBase *)self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        if (*(float *)(self + 0x16C0) > 0.0f)
            func_002705D8(self);
        if (*(unsigned *)(self + 0x16D0) & 0x20000000)
            B(0x2F6) = 2;
        break;
    case 2: {
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0x1B58) + (int)o, *(int *)(o + 0x1B5C) + (int)o, 3, 0.0f, r, 0);
        B(0x2F6)++;
    }
    case 3:
        if (moveMotion((cObjBase *)self))
            B(0x2F6) = 0;
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}
