#include "game/Fn110n.h"

// FUNCTION: GAME 0x110E98
extern "C" void func_00110E98(char *self)
{
    *(unsigned *)(self + 0x15F4) |= 0x100000;
    switch (B(0x2F6)) {
    case 0:
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_00124540(self, 4);
        if (*(void **)(self + 0x6A0)) {
            char *t = *(char **)(self + 0x304);
            func_002A8578(*(void **)(self + 0x6A0), *(int *)(t + 0x37C) + (int)t, *(int *)(t + 0x398) + (int)t, 3, 0.0f, 0, 0);
        }
        {
            char *t = *(char **)(self + 0x304);
            func_002A8578(self, *(int *)(t + 0x364) + (int)t, *(int *)(t + 0x368) + (int)t, 3, 0.0f, 0, 0);
        }
        *(int *)(self + 0x15B0) = 1;
        B(0x2F6)++;
    case 1:
        if (*(int *)(self + 0x640)) B(0x648) = 0x14;
        func_00124E68(self, 0.19634955f);
        if (moveMotion((cObjBase *)self)) {
            func_00124E58(self);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (*(unsigned short *)(self + 0x3AC) & 1) func_0012B618(self);
    if (func_00123938(self, 1)) func_00124E58(self);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x111010 - 10 words: base t lands in t2 with loads v0/v1 (offset-pair-in-branch regalloc idiom)
extern "C" void func_00111010(char *self)
{
    *(float *)(self + 0x54C) = 3.0f;
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_00124E58(self);
        char *t;
        int a, b;
        if (B(0x2F7)) {
            t = *(char **)(self + 0x304);
            a = *(int *)(t + 0x4BC) + (int)t;
            b = *(int *)(t + 0x4C0) + (int)t;
            func_0010A408(self, 0x32, 0x26, 0x1D, 0, 0x123);
            func_0010A420(self, 0x32, 0x26, 0x1D, 0, 0x123);
        } else {
            t = *(char **)(self + 0x304);
            a = *(int *)(t + 0x494) + (int)t;
            b = *(int *)(t + 0x498) + (int)t;
            func_0010A408(self, 0x32, 0x25, 0x1D, 0, 0x123);
            func_0010A420(self, 0x32, 0x25, 0x1D, 0, 0x123);
        }
        B(0x1684) = 0;
        func_002A8578(self, a, b, 0, 0.0f, 0, 0);
        addGameLevelPoint__9cCoreSavei(&CoreSave, 100);
        *(float *)(self + 0x54C) = 15.0f;
        B(0x2F6)++;
    }
    case 1:
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self)) {
            clearMotionCam__4pl00UiUi(self, 1, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    func_0010A438(self);
    if (*(unsigned short *)(self + 0x3AC) & 0x100) SetSpeedRate__9cEmManagef(g_EmManage, 0.05f);
    if (func_00123938(self, 1)) clearMotionCam__4pl00UiUi(self, 1, 0);
}
#endif

// FUNCTION: GAME 0x113F68
extern "C" void func_00113F68(char *self)
{
    *(float *)(self + 0x54C) = 30.0f;
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    SetPlCatched__9cEmManage(g_EmManage);
    SetBigHitEffWait__9cEmManagei(g_EmManage, 2);
    switch (B(0x2F6)) {
    case 0: {
        func_00124E58(self);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_00129578(self);
        useGodItem__9cCoreSave(&CoreSave);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x604) + (int)t, *(int *)(t + 0x608) + (int)t, 3, 0.0f, 0, 0);
        *(int *)(self + 0x15B0) = 1;
        B(0x2F6)++;
    }
    case 1:
        func_00124EC0(self);
        if (*(unsigned short *)(self + 0x3AC) & 0x200) SetPlSorry__9cEmManage(g_EmManage);
        if (moveMotion((cObjBase *)self)) {
            clearMotionCam__4pl00UiUi(self, 0, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (*(unsigned short *)(self + 0x3AC) & 1) {
        if (*(int *)(self + 0x15B0)) {
            *(int *)(self + 0x15B0) = 0;
            setGameLevel__9cCoreSavei(&CoreSave, 0);
        }
    }
    if (func_00123938(self, 1)) {
        func_00129630(self);
        clearMotionCam__4pl00UiUi(self, 0, 0);
    }
}
