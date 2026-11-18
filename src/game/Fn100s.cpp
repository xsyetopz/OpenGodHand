// Player-family state functions in 0x100000-0x120000, over raw offsets.
#include "game/Fn110n.h"

extern "C" void func_0012BC00(void *, int, int);
extern "C" int func_0010B2E8(void *, int);
extern "C" void func_00129BA0(void *);
extern "C" int strcmp(const char *, const char *);
extern char D_0041C208[];
extern "C" void *func_0027A128(void *);
#define B2(p, o) (*(unsigned char *)((p) + (o)))
struct JtV68 {
    char _p[0x68];
    short adj;
    short _pad;
    const float *(*fn)(void *);
};
struct SndFlagsR {
    char _pad[0xAC];
    unsigned a;
    unsigned b;
};
extern SndFlagsR SndF __asm__("Snd");
extern "C" void SeStop__4cSnd6eSndId(void *, int);

// FUNCTION: GAME 0x112318
extern "C" void func_00112318(char *self)
{
    *(float *)(self + 0x54C) = 30.0f;
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    SetBigHitEffWait__9cEmManagei(g_EmManage, 2);
    *(unsigned *)(self + 0x15F4) |= 0x200;
    if (B(0x2F6) && !B(0x649) && func_0010B2E8(self, 1)) {
        B(0x649) = 1;
        useGodItem__9cCoreSave(&CoreSave);
    }
    switch (B(0x2F6)) {
    case 0: {
        func_00124E58(self);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_0010A408(self, 0x32, 0x16, 0x22, 0, 0xA);
        func_0010A420(self, 0x32, 0x16, 0x22, 0, 0xA);
        B(0x1684) = 1;
        func_00129578(self);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x218) + (int)t, *(int *)(t + 0x21C) + (int)t, 3, 0.0f, 0, 0);
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

// FUNCTION: GAME 0x113CF8
extern "C" void func_00113CF8(char *self)
{
    *(float *)(self + 0x54C) = 30.0f;
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    SetPlCatched__9cEmManage(g_EmManage);
    SetBigHitEffWait__9cEmManagei(g_EmManage, 2);
    *(unsigned *)(self + 0x15F4) |= 0x200;
    switch (B(0x2F6)) {
    case 0: {
        func_00129BA0(self);
        clearMotionCam__4pl00UiUi(self, 0, 0);
        func_00124E58(self);
        char *t = *(char **)(self + 0x304);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_002A8578(self, *(int *)(t + 0x220) + (int)t, *(int *)(t + 0x224) + (int)t, 3, 21.0f, 0, 0);
        *(int *)(self + 0x15B0) = 13;
        B(0x2F6)++;
    }
    case 1:
        moveMotion((cObjBase *)self);
        if (*(int *)(self + 0x15B0))
            *(int *)(self + 0x15B0) = *(int *)(self + 0x15B0) - 1;
        else
            B(0x2F6) = 2;
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        SetSpeedRate__9cEmManagef(g_EmManage, 0.1f);
        return;
    case 2: {
        func_00124E58(self);
        char *t = *(char **)(self + 0x304);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_002A8578(self, *(int *)(t + 0x380) + (int)t, *(int *)(t + 0x384) + (int)t, 0, 0.0f, 0, 0);
        int v = *(unsigned short *)(self + 0x54A) - 10;
        *(short *)(self + 0x54A) = v;
        if ((short)v < 2)
            *(short *)(self + 0x54A) = 1;
        B(0x2F6)++;
    }
    case 3:
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self)) {
            clearMotionCam__4pl00UiUi(self, 0, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        if (func_00123938(self, 1))
            clearMotionCam__4pl00UiUi(self, 0, 0);
    }
}

// FUNCTION: GAME 0x113228
extern "C" void func_00113228(char *self)
{
    *(float *)(self + 0x54C) = 30.0f;
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    SetPlCatched__9cEmManage(g_EmManage);
    SetBigHitEffWait__9cEmManagei(g_EmManage, 2);
    *(unsigned *)(self + 0x15F4) |= 0x200;
    if (B(0x2F6) && !B(0x649) && func_0010B2E8(self, 1)) {
        B(0x649) = 1;
        useGodItem__9cCoreSave(&CoreSave);
    }
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_0010A408(self, 0xC8, 0x14, 0x26, 0, 0x123);
        func_0010A420(self, 0xC8, 0x14, 0x26, 0, 0x123);
        B(0x1684) = 1;
        func_00129578(self);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x60C) + (int)t, *(int *)(t + 0x610) + (int)t, 3, 0.0f, 0, 0);
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
        if (*(char **)(self + 0x640)) {
            char *o = *(char **)(self + 0x640);
            JtV68 *vt = *(JtV68 **)(o + 0x214);
            const float *p = *(const float **)(self + 0xF0);
            if (capVu0MagnitudeSqXZ__FPCfT0(p, vt->fn(o + vt->adj)) < 1.21f) {
                *(int *)(self + 0x330) = 0;
                *(int *)(self + 0x338) = 0;
            }
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

// DRAFT: GAME 0x1134C8 (14 words: original keeps o and the result of func_0027A128 both in s0; gcc uses v0/a0)
#ifdef NONMATCHING
extern "C" void func_001134C8(char *self)
{
    *(float *)(self + 0x54C) = 30.0f;
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    SetPlCatched__9cEmManage(g_EmManage);
    SetBigHitEffWait__9cEmManagei(g_EmManage, 2);
    *(unsigned *)(self + 0x15F4) |= 0x200;
    if (B(0x2F6) && !B(0x649) && func_0010B2E8(self, 1)) {
        B(0x649) = 1;
        useGodItem__9cCoreSave(&CoreSave);
    }
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_0010A408(self, 0x50, 0x6, 0x28, 0, 0x123);
        func_0010A420(self, 0x50, 0x6, 0x28, 0, 0x123);
        B(0x1684) = 1;
        func_00129578(self);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x8A8) + (int)t, *(int *)(t + 0x8AC) + (int)t, 3, 0.0f, 0, 0);
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
        if (*(unsigned short *)(self + 0x3AC) & 0x200) {
            char *o = *(char **)(self + 0x640);
            if (o) {
                if (!strcmp(D_0041C208, *(const char **)(o + 0x4AC))) {
                    o = (char *)func_0027A128(*(void **)(self + 0x640));
                    B2(o, 0x2F4) = 1;
                    B2(o, 0x2F5) = 6;
                    B2(o, 0x2F7) = 0;
                    B2(o, 0x2F6) = 0;
                }
            }
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
#endif
