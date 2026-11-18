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
        if (r == 1) { t = *(char **)(self + 0x304); a = *(int *)(t + 0x4DC); b = *(int *)(t + 0x4E0); }
        else if (r == 0) { t = *(char **)(self + 0x304); a = *(int *)(t + 0x140); b = *(int *)(t + 0x144); }
        else if (r == 2) { t = *(char **)(self + 0x304); a = *(int *)(t + 0x4E4); b = *(int *)(t + 0x4E8); }
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
