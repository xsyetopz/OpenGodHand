#include "game/cEm00StateDecls.h"
#include "game/cVec.h"
extern "C" {
void func_00124540(void *, int);
void func_00124E68(void *, float);
void func_00124E58(void *);
void func_0012B618(void *);
int func_00123938(void *, int);
void func_001268F0(void *);
void func_00126770(void *);
void func_0012A8D8(void *);
void clearMotionCam__4pl00UiUi(void *, unsigned, unsigned);
}
struct cFn110nSnd {
    void SeCall(int, int, void *, int, void *, int, int) __asm__("SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii");
};
extern cFn110nSnd Snd;
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

extern char g_EmManage[];
extern "C" {
void SetSlotWait__9cEmManagei(void *, int);
void SetPlCatched__9cEmManage(void *);
void SetBigHitEffWait__9cEmManagei(void *, int);
void SetPlSorry__9cEmManage(void *);
void func_00124EC0(void *);
void func_00129578(void *);
void func_00129630(void *);
void useGodItem__9cCoreSave(void *);
void setGameLevel__9cCoreSavei(void *, int);
}

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


extern char g_HeatSys[];
extern "C" {
int SetEmAnger__9cEmManageG4cVecfff(void *, void *, float, float, float);
int getGameLevel__9cCoreSave(void *);
void AddHeatGage__8cHeatSysfUi(void *, float, unsigned);
void addGameLevelPoint__9cCoreSavei(void *, int);
}

extern "C" {
void GetPlMotion__5cEm0015EM00_PLMOT_TYPEff(void *, int, float, float);
void func_001299F0(void *, void *, float *, int, float);
void func_0012AC28(void *);
void func_0012B928(void *);
void func_0012C348(void *, int);
}

// FUNCTION: GAME 0x1177F8
extern "C" void func_001177F8(char *self)
{
    *(float *)(self + 0x54C) = 5.0f;
    *(unsigned *)(self + 0x250) |= 0x10000;
    char *em = *(char **)(self + 0x694);
    g_CollSolidManage.SetActive((cGameObj *)self, false);
    SetPlCatched__9cEmManage(g_EmManage);
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    *(int *)(self + 0x15F4) |= 0x80000;
    switch (B(0x2F6)) {
    case 0: {
        func_0012AC28(self);
        func_0012B928(self);
        float v[4] __attribute__((aligned(16)));
        v[0] = -0.3293f;
        *(int *)&v[1] = 0;
        v[2] = 1.6646f;
        v[3] = 1.0f;
        float y = v[1];
        func_001299F0(self, em, v, 0, y);
        GetPlMotion__5cEm0015EM00_PLMOT_TYPEff(em, 0x39, y, y);
        addGameLevelPoint__9cCoreSavei(&CoreSave, 100);
        *(short *)(self + 0x56E) = 0xF;
        B(0x2F6)++;
    }
    case 1:
        if (*(short *)(self + 0x56E) && em) {
            *(unsigned short *)(self + 0x56E) -= 1;
            void *dst = *(void **)(self + 0xF0);
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(dst), "r"(em + 0x550) : "memory");
        }
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self)) {
            clearMotionCam__4pl00UiUi(self, 0, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x117F78
extern "C" void func_00117F78(char *self)
{
    *(float *)(self + 0x54C) = 5.0f;
    *(unsigned *)(self + 0x250) |= 0x10000;
    char *em = *(char **)(self + 0x694);
    g_CollSolidManage.SetActive((cGameObj *)self, false);
    SetPlCatched__9cEmManage(g_EmManage);
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    *(int *)(self + 0x15F4) |= 0x80000;
    switch (B(0x2F6)) {
    case 0: {
        func_0012AC28(self);
        func_0012B928(self);
        float v[4] __attribute__((aligned(16)));
        v[0] = -0.5191f;
        *(int *)&v[1] = 0;
        v[2] = 0.0427f;
        v[3] = 1.0f;
        float y = v[1];
        func_001299F0(self, em, v, 0, y);
        GetPlMotion__5cEm0015EM00_PLMOT_TYPEff(em, 0x3D, y, y);
        addGameLevelPoint__9cCoreSavei(&CoreSave, 100);
        if (*(short *)(self + 0x54A) <= 0) *(short *)(self + 0x54A) = 1;
        *(short *)(self + 0x56E) = 0x1E;
        B(0x2F6)++;
    }
    case 1:
        func_00124EC0(self);
        if (*(short *)(self + 0x56E) && em) {
            *(unsigned short *)(self + 0x56E) -= 1;
            void *dst = *(void **)(self + 0xF0);
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(dst), "r"(em + 0x550) : "memory");
        }
        if (moveMotion((cObjBase *)self)) {
            clearMotionCam__4pl00UiUi(self, 0, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x117600
extern "C" void func_00117600(char *self)
{
    *(float *)(self + 0x54C) = 5.0f;
    *(unsigned *)(self + 0x250) |= 0x10000;
    char *em = *(char **)(self + 0x694);
    g_CollSolidManage.SetActive((cGameObj *)self, false);
    SetPlCatched__9cEmManage(g_EmManage);
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    *(int *)(self + 0x15F4) |= 0x80000;
    switch (B(0x2F6)) {
    case 0: {
        func_0012AC28(self);
        func_0012B928(self);
        float v[4] __attribute__((aligned(16)));
        float *ep = (float *)em;
        float dx = ep[0x110 / 4], dz = ep[0x118 / 4];
        float ax = 1.0f / dx, az = 1.0f / dz;
        *(int *)&v[1] = 0;
        v[3] = 1.0f;
        v[0] = ax * -0.5842f;
        v[2] = az * 0.1376f;
        float y = v[1];
        func_001299F0(self, em, v, 0, y);
        GetPlMotion__5cEm0015EM00_PLMOT_TYPEff(em, 0x38, y, y);
        addGameLevelPoint__9cCoreSavei(&CoreSave, 100);
        if (*(short *)(self + 0x54A) <= 0) *(short *)(self + 0x54A) = 1;
        *(short *)(self + 0x56E) = 0x1E;
        B(0x2F6)++;
    }
    case 1:
        func_00124EC0(self);
        if (*(short *)(self + 0x56E) && em) {
            *(unsigned short *)(self + 0x56E) -= 1;
            void *dst = *(void **)(self + 0xF0);
            __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(dst), "r"(em + 0x550) : "memory");
        }
        if (moveMotion((cObjBase *)self)) {
            clearMotionCam__4pl00UiUi(self, 0, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x11AAA0 - irand()&3 selection: original loads offsets into v1/a0 in each branch then addu into a1/a2; mine allocates a1/a2 directly and (with t hoisted) spills to s1
extern "C" void func_0011AAA0(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        int a, b;
        char *t = *(char **)(self + 0x304);
        switch (irand() & 3) {
        case 0: a = *(int *)(t + 0x148); b = *(int *)(t + 0x14C); break;
        case 1: a = *(int *)(t + 0x150); b = *(int *)(t + 0x154); break;
        case 2: a = *(int *)(t + 0x4EC); b = *(int *)(t + 0x4F0); break;
        default: a = *(int *)(t + 0x4F4); b = *(int *)(t + 0x4F8); break;
        }
        func_002A8578(self, a + (int)t, b + (int)t, 1, 0.0f, 0, 0);
        if (irand() & 1) Snd.SeCall(0, 0xCF, self, 0, 0, 0, 0);
        else Snd.SeCall(0, 0xD0, self, 0, 0, 0, 0);
        func_0012C348(self, 1);
        clearMotionCam__4pl00UiUi(self, 0, 0);
        func_0012AC28(self);
        func_0012B928(self);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (*(float *)(self + 0x54C) <= 1.0f) *(unsigned short *)(self + 0x3AC) |= 0x40;
    func_00123938(self, 1);
}

#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x11B3E8 - 12 words differ: scheduling of &c (addiu a1,sp,0x10), d zero-store and the second null-check delay slot
float capVu0Atan2(float, float);

extern "C" void func_0011B3E8(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        char *tb = *(char **)(self + 0x304);
        int a = *(int *)(tb + 0x270) + (int)tb;
        int b = *(int *)(tb + 0x274) + (int)tb;
        Snd.SeCall(0, 0xCF, self, 0, 0, 0, 0);
        Snd.SeCall(0, 0x2D, self, 0, 0, 0, 0);
        Snd.SeCall(0, 0x32, self, 0, 0, 0, 0);
        *(float *)(self + 0x54C) = 5.0f;
        func_0012C348(self, 2);
        func_0012AC28(self);
        func_0012B928(self);
        func_002A8578(self, a, b, 2, 15.0f, 0, 0);
        char *o = *(char **)(self + 0x678);
        if (o && (o = *(char **)(o + 0x34))) {
            Qv110 t, c, d;
            __asm__ volatile("sqc2 $vf0,%0" : "=m"(t));
            __asm__ volatile("sqc2 $vf0,%0" : "=m"(d));
            __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(d) : "r"(*(void **)(o + 0xF0)), "r"(*(void **)(self + 0xF0)));
            __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(c) : "r"(d.v));
            if (&t != &c) { t.v[0] = c.v[0]; t.v[1] = c.v[1]; t.v[2] = c.v[2]; }
            *(float *)(self + 0x104) = capVu0Atan2(t.v[0], t.v[2]);
        }
        *(int *)(self + 0x15B0) = 0x1E;
        B(0x2F6)++;
    }
    case 1:
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self)) {
            clearMotionCam__4pl00UiUi(self, 0, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

#endif

extern "C" {
void sceVu0ApplyMatrix(float *, void *, float *);
}
struct Qv110 { float v[4] __attribute__((aligned(16))); };
extern "C" {
void SetSpeedRate__9cEmManagef(void *, float);
void func_0010A408(void *, int, int, int, int, int);
void func_0010A420(void *, int, int, int, int, int);
}

// FUNCTION: GAME 0x11A060
extern "C" void func_0011A060(char *self)
{
    *(float *)(self + 0x54C) = 5.0f;
    *(unsigned *)(self + 0x250) |= 0x10000;
    char *em = *(char **)(self + 0x694);
    g_CollSolidManage.SetActive((cGameObj *)self, false);
    SetPlCatched__9cEmManage(g_EmManage);
    SetSlotWait__9cEmManagei(g_EmManage, 2);
    *(int *)(self + 0x15F4) |= 0x200;
    switch (B(0x2F6)) {
    case 0: {
        func_0012AC28(self);
        func_0012B928(self);
        if (em) {
            float v[4] __attribute__((aligned(16)));
            __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv110 *)v));
            v[0] = 0.0f;
            v[1] = 0.0f;
            v[2] = 0.99737f;
            sceVu0ApplyMatrix(v, em + 0x80, v);
            **(float **)(self + 0xF0) = v[0];
            (*(float **)(self + 0xF0))[2] = v[2];
            *(float *)(self + 0x104) = *(float *)(em + 0x104) + 3.1415927f;
            *(float *)(self + 0x104) = Adjust_theta(*(float *)(self + 0x104));
        }
        GetPlMotion__5cEm0015EM00_PLMOT_TYPEff(em, 0x52, 0.0f, 0.0f);
        *(short *)(self + 0x5E0) = 0;
        func_00124E58(self);
        *(short *)(self + 0x5E2) = 0;
        func_0010A408(self, 5, 0, 0x2A, 0, 10);
        func_0010A420(self, 5, 0, 0x2A, 0, 10);
        B(0x1684) = 1;
        addGameLevelPoint__9cCoreSavei(&CoreSave, 100);
        B(0x2F6)++;
    }
    case 1:
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self)) {
            clearMotionCam__4pl00UiUi(self, 0, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (func_00123938(self, 1)) {
        clearMotionCam__4pl00UiUi(self, 0, 0);
    } else if (*(unsigned short *)(self + 0x3AC) & 0x100) {
        SetSpeedRate__9cEmManagef(g_EmManage, 0.1f);
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x114460 - 8 words differ: case 0 table-offset loads use v1/a0 temps then addu into a1/a2 in the original

extern "C" void func_00114460(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        int a, b;
        unsigned r = irand() & 1;
        char *t = *(char **)(self + 0x304);
        if (r) {
            a = *(int *)(t + 0x230); b = *(int *)(t + 0x234);
        } else {
            a = *(int *)(t + 0x8A0); b = *(int *)(t + 0x8A4);
        }
        int x = a + (int)t, y = b + (int)t;
        func_002A8578(self, x, y, 3, 0.0f, 0, 0);
        *(short *)(self + 0x568) = 1;
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        if ((*(unsigned short *)(self + 0x3AC) & 1) && *(short *)(self + 0x568)) {
            *(short *)(self + 0x568) = 0;
            cVec v __attribute__((aligned(16)));
            __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(v) : "r"(*(void **)(self + 0xF0)));
            if (SetEmAnger__9cEmManageG4cVecfff(g_EmManage, &v, *(float *)(self + 0x104), 15.0f, 0.5235988f)) {
                if (getGameLevel__9cCoreSave(&CoreSave) != 5) {
                    AddHeatGage__8cHeatSysfUi(g_HeatSys, 12.0f, 0);
                    addGameLevelPoint__9cCoreSavei(&CoreSave, 250);
                } else {
                    AddHeatGage__8cHeatSysfUi(g_HeatSys, 6.0f, 0);
                }
            }
        }
    }
    func_00123938(self, 1);
}
#endif


extern "C" void func_0012C348(void *, int);
extern "C" void func_0012AC28(void *);
extern "C" void func_0012B928(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x11A8F8 - irand()%3 three-way selection: original uses v1/a0 temps and no extra callee-saved regs; mine spills a,b,t into s1-s3 (frame 0x60 vs 0x30)
extern "C" void func_0011A8F8(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        int a = 0, b = 0;
        char *t = 0;
        unsigned r = irand() % 3;
        if (r == 1) { a = *(int *)(t + 0x4DC); b = *(int *)(t + 0x4E0); }
        else if (r == 0) { a = *(int *)(t + 0x140); b = *(int *)(t + 0x144); }
        else if (r == 2) { a = *(int *)(t + 0x4E4); b = *(int *)(t + 0x4E8); }
        func_002A8578(self, a + (int)t, b + (int)t, 1, 0.0f, 0, 0);
        Snd.SeCall(0, 0xCE, self, 0, 0, 0, 0);
        func_0012C348(self, 0);
        clearMotionCam__4pl00UiUi(self, 0, 0);
        func_0012AC28(self);
        func_0012B928(self);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            if (func_00123938(self, 1)) return;
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (*(float *)(self + 0x54C) <= 1.0f) *(unsigned short *)(self + 0x3AC) |= 0x40;
    func_00123938(self, 1);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x11B900 - same irand()&3 offset selection as 0x11AAA0 (v1/a0 temps in original); tail untested beyond that
extern "C" void func_0011B900(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        int a, b;
        char *t;
        switch (irand() & 3) {
        case 0: t = *(char **)(self + 0x304); a = *(int *)(t + 0x148); b = *(int *)(t + 0x14C); break;
        case 1: t = *(char **)(self + 0x304); a = *(int *)(t + 0x150); b = *(int *)(t + 0x154); break;
        case 2: t = *(char **)(self + 0x304); a = *(int *)(t + 0x4EC); b = *(int *)(t + 0x4F0); break;
        default: t = *(char **)(self + 0x304); a = *(int *)(t + 0x4F4); b = *(int *)(t + 0x4F8); break;
        }
        func_002A8578(self, a + (int)t, b + (int)t, 1, 0.0f, 0, 0);
        if (irand() & 1) Snd.SeCall(0, 0xCF, self, 0, 0, 0, 0);
        else Snd.SeCall(0, 0xD0, self, 0, 0, 0, 0);
        func_0012C348(self, 1);
        clearMotionCam__4pl00UiUi(self, 0, 0);
        func_00126770(self);
        func_0012AC28(self);
        func_0012B928(self);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            if (*(short *)(self + 0x54A) <= 0) goto fin;
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if (*(short *)(self + 0x54A) > 0) {
        func_00123938(self, 1);
    } else if (*(unsigned short *)(self + 0x3AC) & 0x10) {
    fin:
        B(0x2F7) = 0; B(0x2F4) = 2; B(0x2F5) = 0; B(0x2F6) = 0;
    }
}
#endif

