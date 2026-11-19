#include "game/Fn110n.h"

struct HeatF { char pad[0x10]; unsigned char f; };
// FUNCTION: GAME 0x114120
extern "C" void func_00114120(char *self)
{
    *(float *)(self + 0x54C) = 15.0f;
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_00124E58(self);
        char *t = *(char **)(self + 0x304);
        int a = *(int *)(t + 0x10) + (int)t;
        int b = *(int *)(t + 0x14) + (int)t;
        func_0010A408(self, 5, 0x17, 0x2A, 0, 10);
        func_0010A420(self, 5, 0x17, 0x2A, 0, 10);
        B(0x1684) = 1;
        func_002A8578(self, a, b, 3, 0.0f, 0, 0);
        func_0012B928(self);
        func_0012AC28(self);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    if ((*(unsigned short *)(self + 0x3AC) & 1) && !((HeatF *)g_HeatSys)->f) {
        SetHeatMode__8cHeatSysUc(g_HeatSys, 1);
        *(int *)(self + 0x15F4) = (*(int *)(self + 0x15F4) | 0x10) & ~0x20;
        func_0012AC28(self);
        func_0012B928(self);
    }
    func_0010A438(self);
    if (!func_00123938(self, 1)) {
        *(unsigned short *)(self + 0x3AC) |= 0x800;
        *(float *)(self + 0x674) = 0.05f;
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

#ifdef NONMATCHING
// DRAFT: GAME 0x114AC0 - 30 words (fixed 6.25f const, dropped dup 0x338 store); case0 store order; p/q locals (top or case1) put self in s0 not s2 = worse (69-90); original keeps &self[0x1590]/&self[0x490] in s0/s1 (compare + copy), self in s2
extern "C" void func_00114AC0(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_002A8578(self, *(int *)(t + 0x48) + (int)t, *(int *)(t + 0x4C) + (int)t, 3, 0.0f, 0, 0);
        ((cGameObj *)self)->SetTgtTurn(*(cVec *)(self + 0x580), 3.14159274f);
        *(int *)(self + 0x15B4) = 0;
        *(float *)(self + 0x1598) = 99999.8984375f;
        B(0x2F6)++;
        *(float *)(self + 0x1590) = 99999.8984375f;
        *(float *)(self + 0x1594) = 99999.8984375f;
    }
    case 1: {
        *(unsigned short *)(self + 0x434) |= 8;
        moveMotion((cObjBase *)self);
        float m = capVu0MagnitudeSqXZ__FPCfT0((float *)(self + 0x1590), (float *)(self + 0x490));
        float h = *(float *)(self + 0x1588) * 0.5f;
        if (m < h * h) {
            if (++*(int *)(self + 0x15B4) >= 2) {
                B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
            }
        } else {
            *(int *)(self + 0x15B4) = 0;
        }
        if (self + 0x1590 != self + 0x490) {
            *(float *)(self + 0x1590) = *(float *)(self + 0x490);
            *(float *)(self + 0x1594) = *(float *)(self + 0x494);
            *(float *)(self + 0x1598) = *(float *)(self + 0x498);
        }
        float d = capVu0MagnitudeSqXZ__FPCfT0(*(float **)(self + 0xF0), (float *)(self + 0x580));
        if (d < 4.0f) {
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        *(int *)(self + 0x330) = 0;
        float v = 1.0f;
        *(int *)(self + 0x334) = 0;
        if (d > 6.25f) v = 2.0f;
        *(float *)(self + 0x338) = v;
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1156D8 - 9 words: case 2 vec copy has d/src in swapped v0/v1; tried decl order d/src, d!=src vs src!=d, inline exprs, temps (none)
extern "C" void func_001156D8(char *self)
{
    *(float *)(self + 0x54C) = 5.0f;
    switch (B(0x2F6)) {
    case 0: {
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_001268F0(self);
        func_00124E58(self);
        char *t = *(char **)(self + 0x304);
        *(float *)(self + 0x104) = *(float *)(self + 0x670);
        func_002A8578(self, *(int *)(t + 0x4C4) + (int)t, *(int *)(t + 0x4C8) + (int)t, 0, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        func_00124EC0(self);
        *(int *)(self + 0x15F4) |= 0x80;
        g_CollSolidManage.SetActive((cGameObj *)self, false);
        if (moveMotion((cObjBase *)self)) B(0x2F6) = 2;
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        break;
    case 2: {
        float *d = *(float **)(self + 0xF0);
        float *src = (float *)(self + 0x660);
        if (src != d) {
            d[0] = src[0]; d[1] = src[1]; d[2] = src[2];
        }
        d = *(float **)(self + 0xF0);
        float *o = (float *)(self + 0x490);
        if (o != d) {
            o[0] = d[0]; o[1] = d[1]; o[2] = d[2];
        }
        char *t = *(char **)(self + 0x304);
        *(float *)(self + 0x104) = *(float *)(self + 0x670);
        func_002A8578(self, *(int *)(t + 0x4D4) + (int)t, *(int *)(t + 0x4D8) + (int)t, 0, 0.0f, 0, 0);
        B(0x2F6)++;
    }
    case 3:
        func_00124EC0(self);
        if (moveMotion((cObjBase *)self)) {
            clearMotionCam__4pl00UiUi(self, 1, 0);
            B(0x2F4) = 0; B(0x2F5) = 0; B(0x2F6) = 0; B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}
#endif
