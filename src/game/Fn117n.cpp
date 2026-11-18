#include "game/Fn110n.h"

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
