#include "game/Fn110n.h"

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
            v[2] = 0.99630004f;
            sceVu0ApplyMatrix(v, em + 0x80, v);
            **(float **)(self + 0xF0) = v[0];
            (*(float **)(self + 0xF0))[2] = v[2];
            *(float *)(self + 0x104) = *(float *)(em + 0x104) + 3.1415927f;
            *(float *)(self + 0x104) = Adjust_theta(*(float *)(self + 0x104));
        }
        GetPlMotion__5cEm0015EM00_PLMOT_TYPEff(em, 0x52, 0.0f, 0.0f);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_00124E58(self);
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

// FUNCTION: GAME 0x11B3E8
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
            void *po = *(void **)(o + 0xF0);
            Qv110 *pc = &c;
            void *ps = *(void **)(self + 0xF0);
            __asm__ volatile("sqc2 $vf0,%0" : "=m"(d));
            __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(d) : "r"(po), "r"(ps));
            __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(c) : "r"(d.v));
            if (&t != pc) { t.v[0] = c.v[0]; t.v[1] = c.v[1]; t.v[2] = c.v[2]; }
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

#ifdef NONMATCHING
// DRAFT: GAME 0x11B900 - 102 words differ (496 vs 500 bytes); original keeps a/b in v1/a0 and sums into a1/a2 in a shared tail, mine coalesces a/b into a1/a2 and hoists the 0x304 load above the compare chain. Tried: explicit case 3 no default (134, a/b spilled to s-regs); cases 1/2/3 + default (115); init decl with default (102); if-chain on r=irand()&3 (109); sum as (int)t + a (104)
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
