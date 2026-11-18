#include "game/cEm00Fn240Decls.h"

// FUNCTION: GAME 0x25FCF8
extern "C" void func_0025FCF8(char *self)
{
    cDmgFwd25F *d = ((cDmgFwd25F * (*)(char *)) * (void **)(*(char **)(self + 0x214) + 0xB4))(
        self + *(short *)(*(char **)(self + 0x214) + 0xB0));
    unsigned char s = B(0x2F6);
    switch (s) {
    case 0: {
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        int off = *(int *)(o + 0x108C) + (int)o;
        func_002A8578(self, off, off, 3, 0.0f, r, 0);
        d->SetDamageCollActive(false);
        Snd.SeCall(1, GetSeqSEBase__FP8cObjBase(self) + 8, self, 0, 0, 0, 0);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            B(0x2F6) = 0;
            B(0x2F4) = 2;
            B(0x2F5) = 2;
            B(0x2F7) = 0;
        } else {
            ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
            ((cObjBase *)self)->addNullSpeed(1.0f);
        }
    }
    *(unsigned short *)(self + 0x3AC) |= 0x400;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x25B5A8
// diff: original keeps base pointer in v0 and raw offsets in v1/a0 across the branch (we add before merging)
extern "C" void func_0025B5A8(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        unsigned short r = func_00276468(self);
        int k = irand__Fv() & 1;
        B(0x2F7) = k;
        char *o;
        int a, b;
        if (k) {
            o = *(char **)(self + 0x304);
            a = *(int *)(o + 0x3DF4);
            b = *(int *)(o + 0x3DF8);
        } else {
            o = *(char **)(self + 0x304);
            a = *(int *)(o + 0x3DEC);
            b = *(int *)(o + 0x3DF0);
        }
        *(unsigned *)(self + 0x16D0) &= 0xFEFFFFFF;
        func_002A8578(self, a + (int)o, b + (int)o, 2, 0.0f, r, 0);
        if (*(void **)(self + 0x748))
            func_002814E8(*(void **)(self + 0x748), B(0x2F7));
        if (*(void **)(self + 0x74C))
            func_002833C0(*(void **)(self + 0x74C), B(0x2F7));
        if (*(void **)(self + 0x750))
            func_002833C0(*(void **)(self + 0x750), B(0x2F7));
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            func_0026F120(self);
            if (func_0026F1D8(self))
                func_00270C78(self);
            else
                func_002705D8(self);
        }
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x249960
// diff: 2 words; g_HeatSys flag lbu lands in v0 instead of v1
extern "C" void func_00249960(char *self)
{
    capVu0MagnitudeSqXZ__FPCfT0(*(const float **)((char *)Getplayer() + 0xF0), D_005850B0);
    *(unsigned *)(self + 0x16D0) |= 0x30400;
    char *h;
    switch (B(0x2F6)) {
    case 0:
        B(0x1864) = 0;
        {
            unsigned short r = func_00276468(self);
            char *o = *(char **)(self + 0x304);
            func_002A8578(self, *(int *)(o + 0x3D34) + (int)o, *(int *)(o + 0x3D38) + (int)o, 0xA, 0.0f, r, 0);
        }
        if (*(void **)(self + 0x748))
            func_00281260(*(void **)(self + 0x748));
        if (*(void **)(self + 0x74C))
            func_00283170(*(void **)(self + 0x74C));
        if (*(void **)(self + 0x750))
            func_00283170(*(void **)(self + 0x750));
        *(unsigned *)(self + 0x16D0) &= 0xFCFFFFFF;
        B(0x2F6)++;
    case 1:
        func_002495E0(self, 0.0f);
        moveMotion((cObjBase *)self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        h = g_HeatSys;
        break;
    default:
        h = g_HeatSys;
    }
    if (*(unsigned char *)(h + 0x10) == 0)
        func_00262AA8(self);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x24AA68
// diff: 17 words; original fills the shared `b` with the 2F7 store (344 bytes vs our 348)
extern "C" void func_0024AA68(char *self)
{
    *(unsigned *)(self + 0x16D0) |= 0x30400;
    switch (B(0x2F6)) {
    case 0:
        B(0x1864) = 0;
        {
            unsigned short r = func_00276468(self);
            char *o = *(char **)(self + 0x304);
            func_002A8578(self, *(int *)(o + 0x3D94) + (int)o, *(int *)(o + 0x3D98) + (int)o, 0xA, 0.0f, r, 0);
        }
        if (*(void **)(self + 0x748))
            func_00281338(*(void **)(self + 0x748));
        if (*(void **)(self + 0x74C))
            func_00283170(*(void **)(self + 0x74C));
        if (*(void **)(self + 0x750))
            func_00283170(*(void **)(self + 0x750));
        *(float *)(self + 0x600) = 30.0f;
        B(0x2F6)++;
    case 1:
        if (*(float *)(self + 0x600) > 0.0f) {
            *(unsigned *)(self + 0x16D0) |= 0x800000;
            *(float *)(self + 0x600) = *(float *)(self + 0x600) - *(float *)(self + 0x5A8);
        }
        if (moveMotion((cObjBase *)self)) {
            B(0x2F5) = 0xA1;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
            B(0x2F4) = 0;
        } else {
            ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
            ((cObjBase *)self)->addNullSpeed(1.0f);
        }
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x247588
// diff: 81 words; original keeps self in s1, player in s2, CamManager in s0 (ours: 0x50 frame, self in s0)
extern "C" void func_00247588(char *self)
{
    pl00Fwd247 *pl = (pl00Fwd247 *)Getplayer();
    *(unsigned *)(self + 0x16D0) |= 0x30000;
    *(float *)(self + 0x54C) = 3.0f;
    *(unsigned *)(self + 0x250) |= 0x10000;
    switch (B(0x2F6)) {
    case 0: {
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0x2FB4) + (int)o, *(int *)(o + 0x2FB8) + (int)o, 0, 0.0f, r, 0);
        func_001D0778(*(void **)(self + 0x708));
        B(0x2F6)++;
        cCamMgr247 *cm = &CamManager;
        cm->setPartsCamera(0);
        {
            unsigned char t = B(0x2B4);
            void *a = 0, *b = 0;
            if (t > 0x1B)
                a = *(void **)(*(char **)(self + 0x278) + 0x6C);
            t = B(0x2B4);
            if (t > 0x1C)
                b = *(void **)(*(char **)(self + 0x278) + 0x70);
            ((cPartsCam247 *)((char *)cm + 0x920))->SetParts(self, a, b, 0);
        }
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            pl->clearMotionCam(0, 1);
            func_002705D8(self);
        } else {
            ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
            ((cObjBase *)self)->addNullSpeed(1.0f);
        }
    }
}
#endif
