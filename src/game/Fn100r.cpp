// Player-family state functions in 0x100000-0x120000, over raw offsets.
#include "game/Fn110n.h"

extern "C" void func_0012BC00(void *, int, int);
extern "C" int func_0010B2E8(void *, int);
struct SndFlagsR {
    char _pad[0xAC];
    unsigned a;
    unsigned b;
};
extern SndFlagsR SndF __asm__("Snd");
extern "C" void SeStop__4cSnd6eSndId(void *, int);
extern char *CreateObj__F6eObjIdT0(int, int);
struct JtVr {
    char _p[0x40];
    short adj;
    short _pad;
    int (*fn)(void *);
};

// DRAFT: GAME 0x114E28 (5 words: addu s1/s0 vs addiu a2,0x29 / daddu a3,self scheduling around SeCall)
#ifdef NONMATCHING
extern "C" void func_00114E28(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_001268F0(self);
        func_00124E58(self);
        func_00126770(self);
        clearMotionCam__4pl00UiUi(self, 0, 0);
        int t = *(int *)(self + 0x304);
        int a = *(int *)(t + 0x3D8) + t;
        int b = *(int *)(t + 0x3DC) + t;
        Snd.SeCall(0, 0x29, self, 0, 0, 0, 0);
        func_002A8578(self, a, b, 3, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        func_00124E68(self, 0.19634955f);
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (*(unsigned short *)(self + 0x3AC) & 1) {
        if (*(int *)(self + 0x698) == 0) {
            char *o = CreateObj__F6eObjIdT0(0x3AF, 0xFFFF);
            *(char **)(self + 0x698) = o;
            if (o) {
                JtVr *vt = *(JtVr **)(o + 0x214);
                vt->fn(o + vt->adj);
                *(cVec *)*(char **)(*(char **)(self + 0x698) + 0xF0) = **(cVec **)(self + 0xF0);
                *(cVec *)(*(char **)(self + 0x698) + 0x490) = **(cVec **)(self + 0xF0);
                cVec *z = (cVec *)(*(char **)(self + 0x698) + 0x100);
                z->x = 0;
                z->y = 0;
                z->z = 0;
                func_0012A8D8(self);
            }
        }
    }
    func_00123938(self, 1);
}
#endif

// FUNCTION: GAME 0x1127F8
extern "C" void func_001127F8(char *self)
{
    *(float *)(self + 0x54C) = 30.0f;
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    SetPlCatched__9cEmManage(g_EmManage);
    SetBigHitEffWait__9cEmManagei(g_EmManage, 2);
    *(unsigned *)(self + 0x15F4) |= 0x200;
    switch (B(0x2F6)) {
    case 0: {
        func_00124E58(self);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_0010A408(self, 0x8C, 0x1E, 0x25, 0, 0x123);
        func_0010A420(self, 0x8C, 0x1E, 0x25, 0, 0x123);
        B(0x1684) = 1;
        useGodItem__9cCoreSave(&CoreSave);
        func_00129578(self);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x4A4) + (int)t, *(int *)(t + 0x4A8) + (int)t, 3, 0.0f, 0, 0);
        SetSpeedRate__9cEmManagef(g_EmManage, 0.1f);
        *(int *)(self + 0x15B0) = 1;
        B(0x2F6)++;
    }
    case 1:
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self)) {
            func_00129630(self);
            clearMotionCam__4pl00UiUi(self, 1, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    func_0010A438(self);
    if (*(unsigned short *)(self + 0x3AC) & 0x100) SetSpeedRate__9cEmManagef(g_EmManage, 0.1f);
    if (*(unsigned short *)(self + 0x3AC) & 1) {
        if (*(int *)(self + 0x15B0)) {
            *(int *)(self + 0x15B0) = 0;
            func_0012BC00(self, 0x2E, 0);
        }
    }
    if (func_00123938(self, 1)) {
        func_00129630(self);
        clearMotionCam__4pl00UiUi(self, 1, 0);
    } else {
        *(unsigned short *)(self + 0x3AC) |= 0x800;
        *(float *)(self + 0x674) = 0.05f;
    }
}

// FUNCTION: GAME 0x1125A0
extern "C" void func_001125A0(char *self)
{
    *(float *)(self + 0x54C) = 30.0f;
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    SetPlCatched__9cEmManage(g_EmManage);
    SetBigHitEffWait__9cEmManagei(g_EmManage, 2);
    *(unsigned *)(self + 0x15F4) |= 0x200;
    if (B(0x2F6) && !B(0x649) && func_0010B2E8(self, 1)) {
        B(0x649) = 1;
        useGodItem__9cCoreSave(&CoreSave);
        useGodItem__9cCoreSave(&CoreSave);
    }
    switch (B(0x2F6)) {
    case 0: {
        func_00124E58(self);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_0010A408(self, 0x14, 0x1D, 0x23, 0, 0xA);
        func_0010A420(self, 0x50, 0xF, 0x1E, 0, 0x123);
        B(0x1684) = 1;
        func_00129578(self);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x2C0) + (int)t, *(int *)(t + 0x2C4) + (int)t, 3, 0.0f, 0, 0);
        SetSpeedRate__9cEmManagef(g_EmManage, 0.1f);
        B(0x2F6)++;
    }
    case 1:
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self)) {
            func_00129630(self);
            clearMotionCam__4pl00UiUi(self, 1, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    func_0010A438(self);
    if (*(unsigned short *)(self + 0x3AC) & 0x100) SetSpeedRate__9cEmManagef(g_EmManage, 0.1f);
    if (func_00123938(self, 1)) {
        func_00129630(self);
        clearMotionCam__4pl00UiUi(self, 1, 0);
    } else {
        *(unsigned short *)(self + 0x3AC) |= 0x800;
        *(float *)(self + 0x674) = 0.05f;
    }
}

// FUNCTION: GAME 0x1120A8
extern "C" void func_001120A8(char *self)
{
    *(float *)(self + 0x54C) = 30.0f;
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    SetPlCatched__9cEmManage(g_EmManage);
    SetBigHitEffWait__9cEmManagei(g_EmManage, 2);
    *(unsigned *)(self + 0x15F4) |= 0x200;
    switch (B(0x2F6)) {
    case 0: {
        func_00124E58(self);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        B(0x1684) = 1;
        func_00129578(self);
        useGodItem__9cCoreSave(&CoreSave);
        useGodItem__9cCoreSave(&CoreSave);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x870) + (int)t, *(int *)(t + 0x874) + (int)t, 3, 0.0f, 0, 0);
        SetSpeedRate__9cEmManagef(g_EmManage, 0.1f);
        *(int *)(self + 0x15B0) = 1;
        B(0x2F6)++;
    }
    case 1:
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self)) {
            func_00129630(self);
            clearMotionCam__4pl00UiUi(self, 1, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (*(unsigned short *)(self + 0x3AC) & 1) {
        if (*(int *)(self + 0x15B0)) {
            *(int *)(self + 0x15B0) = 0;
            func_0012BC00(self, 0x2F, 0);
        }
    }
    if (*(unsigned short *)(self + 0x3AC) & 0x100) SetSpeedRate__9cEmManagef(g_EmManage, 0.05f);
    if (*(unsigned short *)(self + 0x3AC) & 1) {
        SeStop__4cSnd6eSndId(&SndF, *(int *)(self + 0x161C));
        *(int *)(self + 0x161C) = 0;
        SndF.b &= 0xFFBFFFFF;
        SndF.a &= 0xFFBFFFFF;
    }
    if (func_00123938(self, 1)) {
        func_00129630(self);
        clearMotionCam__4pl00UiUi(self, 1, 0);
    } else {
        *(unsigned short *)(self + 0x3AC) |= 0x800;
        *(float *)(self + 0x674) = 0.05f;
    }
}

// FUNCTION: GAME 0x112A48
extern "C" void func_00112A48(char *self)
{
    *(float *)(self + 0x54C) = 30.0f;
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    SetPlCatched__9cEmManage(g_EmManage);
    SetBigHitEffWait__9cEmManagei(g_EmManage, 2);
    *(unsigned *)(self + 0x15F4) |= 0x200;
    switch (B(0x2F6)) {
    case 0: {
        func_00124E58(self);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        B(0x1684) = 1;
        func_00129578(self);
        useGodItem__9cCoreSave(&CoreSave);
        int a, b;
        if (B(0x2F7)) {
            char *t = *(char **)(self + 0x304);
            a = *(int *)(t + 0x450) + (int)t;
            b = *(int *)(t + 0x458) + (int)t;
        } else {
            char *t = *(char **)(self + 0x304);
            a = *(int *)(t + 0x450) + (int)t;
            b = *(int *)(t + 0x454) + (int)t;
        }
        func_002A8578(self, a, b, 3, 0.0f, 0, 0);
        SetSpeedRate__9cEmManagef(g_EmManage, 0.1f);
        *(int *)(self + 0x15B0) = 1;
        B(0x2F6)++;
    }
    case 1:
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self)) {
            func_00129630(self);
            clearMotionCam__4pl00UiUi(self, 1, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (*(unsigned short *)(self + 0x3AC) & 1) {
        if (*(int *)(self + 0x15B0)) {
            *(int *)(self + 0x15B0) = 0;
            if (B(0x2F7)) {
                func_0012BC00(self, 0x2D, 0);
                func_0012BC00(self, 0x2D, 1);
                func_0012BC00(self, 0x2D, 2);
            } else {
                func_0012BC00(self, 0x2C, 0);
            }
        }
    }
    if (*(unsigned short *)(self + 0x3AC) & 0x100) SetSpeedRate__9cEmManagef(g_EmManage, 0.1f);
    if (func_00123938(self, 1)) {
        func_00129630(self);
        clearMotionCam__4pl00UiUi(self, 1, 0);
    } else {
        *(unsigned short *)(self + 0x3AC) |= 0x800;
        *(float *)(self + 0x674) = 0.05f;
    }
}
