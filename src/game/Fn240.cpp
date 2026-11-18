// Enemy state functions in 0x240000-0x260000, over raw offsets.
#include "game/cEm00StateDecls.h"

extern "C" {
void func_00281338(void *);
void func_00283170(void *);
void func_002813C0(void *, int);
void func_00283270(void *, int);
void func_00281290(void *, int);
void func_002831B0(void *, int);
void func_0026DB00(void *, int, int);
void func_00260438(void *);
}

extern unsigned short D_00747A50;

// FUNCTION: GAME 0x24AA68
extern "C" void func_0024AA68(char *self)
{
    *(unsigned int *)(self + 0x16D0) |= 0x30400;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        unsigned m = func_00276468(self) & 0xFFFF;
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x3D94) + (int)t, *(int *)(t + 0x3D98) + (int)t, 10, 0.0f, m, 0);
        void *p = *(void **)(self + 0x748);
        if (p)
            func_00281338(p);
        p = *(void **)(self + 0x74C);
        if (p)
            func_00283170(p);
        p = *(void **)(self + 0x750);
        if (p)
            func_00283170(p);
        *(float *)(self + 0x600) = 30.0f;
        B(0x2F6)++;
    }
    case 1: {
        float f = *(float *)(self + 0x600);
        if (0.0f < f) {
            *(unsigned int *)(self + 0x16D0) |= 0x800000;
            *(float *)(self + 0x600) = f - *(float *)(self + 0x5A8);
        }
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0xA1;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    }
}

// FUNCTION: GAME 0x246088
extern "C" void func_00246088(char *self)
{
    int flag = 1;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        if (D_00747A50 == 0x303 && !(*(unsigned int *)(self + 0x16D4) & 0x2000000)) {
            *(unsigned int *)(self + 0x16D4) |= 0x2000000;
            *(float *)(self + 0x54C) = 10.0f;
            flag = 0;
        }
        if (flag)
            func_00260438(self);
        char *t = *(char **)(self + 0x304);
        int a1 = *(int *)(t + 0xBCC) + (int)t;
        int a2 = *(int *)(t + 0xBD4) + (int)t;
        unsigned m = func_00276468(self) & 0xFFFF;
        func_002A8578(self, a1, a2, 10, 0.0f, m, 0);
        *(short *)(self + 0x568) = 3;
        B(0x2F6)++;
    }
    case 1: {
        cGameObj *pl = Getplayer();
        ((cGameObj *)self)->SetTgtTurn(*pl->m_pPos, *(float *)(self + 0x5A8) * 0.19634955f);
        if (moveMotion((cObjBase *)self)) {
            int c = *(unsigned short *)(self + 0x568) - 1;
            *(unsigned short *)(self + 0x568) = c;
            if ((int)(c << 16) <= 0)
                func_002705D8(self);
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    }
}

// DRAFT: GAME 0x246370 - many words differ: orig keeps self in s0 with t/o1/o2 in v0/v1/a0 and a1/a2 in s2/s1 before the call; here the a1/a2 adds sink into the call delay slot and regs shift.
#ifdef NONMATCHING
extern "C" void func_00246370(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        char *t;
        int o1;
        int o2;
        if (*(int *)(self + 0x564) == 0x256) {
            t = *(char **)(self + 0x304);
            o1 = *(int *)(t + 0x2B84);
            o2 = *(int *)(t + 0x2B88);
        } else {
            t = *(char **)(self + 0x304);
            o1 = *(int *)(t + 0x2C38);
            o2 = *(int *)(t + 0x2C3C);
        }
        int a1 = o1 + (int)t;
        int a2 = o2 + (int)t;
        unsigned m = func_00276468(self) & 0xFFFF;
        func_002A8578(self, a1, a2, 10, 0.0f, m, 0);
        *(float *)(self + 0x600) = 30.0f;
        B(0x2F6)++;
    }
    case 1: {
        float f = *(float *)(self + 0x600);
        if (0.0f < f) {
            *(unsigned int *)(self + 0x16D0) |= 0x800000;
            *(float *)(self + 0x600) = f - *(float *)(self + 0x5A8);
        }
        cGameObj *pl = Getplayer();
        ((cGameObj *)self)->SetTgtTurn(*pl->m_pPos, *(float *)(self + 0x5A8) * 0.19634955f);
        if (moveMotion((cObjBase *)self) || (*(unsigned short *)(self + 0x3AC) & 0x10))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    }
}
#endif

// FUNCTION: GAME 0x24B218
extern "C" void func_0024B218(char *self)
{
    *(unsigned int *)(self + 0x16D0) |= 0x30400;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        unsigned m = func_00276468(self) & 0xFFFF;
        char *t = *(char **)(self + 0x304);
        int a = *(int *)(t + 0x3DA4) + (int)t;
        int b = *(int *)(t + 0x3DA8) + (int)t;
        if (CoreSave.getGameLevel() == 5) {
            char *u = *(char **)(self + 0x304);
            b = *(int *)(u + 0x3DAC) + (int)u;
            if (*(void **)(self + 0x748))
                func_002813C0(*(void **)(self + 0x748), 1);
            if (*(void **)(self + 0x74C))
                func_00283270(*(void **)(self + 0x74C), 1);
            if (*(void **)(self + 0x750))
                func_00283170(*(void **)(self + 0x750));
        } else {
            if (*(void **)(self + 0x748))
                func_002813C0(*(void **)(self + 0x748), 0);
            if (*(void **)(self + 0x74C))
                func_00283270(*(void **)(self + 0x74C), 0);
            if (*(void **)(self + 0x750))
                func_00283170(*(void **)(self + 0x750));
        }
        func_002A8578(self, a, b, 10, 0.0f, m, 0);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0xA1;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (*(unsigned short *)(self + 0x3AC) & 1)
        func_0026DB00(self, 4, 0);
}

// FUNCTION: GAME 0x249EF8
extern "C" void func_00249EF8(char *self)
{
    *(unsigned int *)(self + 0x16D0) |= 0x30400;
    switch (B(0x2F6)) {
    case 0: {
        B(0x1864) = 0;
        unsigned m = func_00276468(self) & 0xFFFF;
        char *t = *(char **)(self + 0x304);
        int a = *(int *)(t + 0x3D64) + (int)t;
        int b = *(int *)(t + 0x3D68) + (int)t;
        if (CoreSave.getGameLevel() == 5) {
            char *u = *(char **)(self + 0x304);
            b = *(int *)(u + 0x3D6C) + (int)u;
            if (*(void **)(self + 0x748))
                func_00281290(*(void **)(self + 0x748), 1);
            if (*(void **)(self + 0x74C))
                func_002831B0(*(void **)(self + 0x74C), 1);
            if (*(void **)(self + 0x750))
                func_00283170(*(void **)(self + 0x750));
        } else {
            if (*(void **)(self + 0x748))
                func_00281290(*(void **)(self + 0x748), 0);
            if (*(void **)(self + 0x74C))
                func_002831B0(*(void **)(self + 0x74C), 0);
            if (*(void **)(self + 0x750))
                func_00283170(*(void **)(self + 0x750));
        }
        func_002A8578(self, a, b, 10, 0.0f, m, 0);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0xA1;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (*(unsigned short *)(self + 0x3AC) & 1)
        func_0026DB00(self, 2, 0);
}
