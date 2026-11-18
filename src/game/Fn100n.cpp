// Mid-size units in 0x100000-0x110000.
#include "game/cEm00StateDecls.h"
#include "game/cVec.h"

extern "C" void calcParts__6cModel(void *);
extern "C" void SetMotionStep__FP8cObjBasef(char *, float);

struct sPos100 {
    char pad0[0xF0];
    cVec *m_pPos;
    char pad1[0xC];
    cVec m_100;
    char pad2[0x490 - 0x10C];
    cVec m_490;
};

// FUNCTION: GAME 0x103760
extern "C" void func_00103760(sPos100 *self, int mode)
{
    char *pl = (char *)Getplayer();
    *self->m_pPos = **(cVec **)(pl + 0xF0);
    self->m_490 = *self->m_pPos;
    self->m_100 = *(cVec *)((char *)Getplayer() + 0x100);
    calcParts__6cModel(self);
    char *s = (char *)self;
    switch (mode) {
    case 0:
    default:
        *(int *)(s + 0x14B0) &= -2;
        *(int *)(s + 0x14B4) = 0;
        B(0x2F5) = 6;
        break;
    case 1: {
        int k = 7;
        *(int *)(s + 0x14B4) = 0x12C;
        *(unsigned *)(s + 0x250) &= 0xFFFFFFFD;
        *(unsigned *)(s + 0x14B0) |= 1;
        B(0x2F5) = k;
        break;
    }
    }
    B(0x2F6) = 0;
    B(0x2F7) = 0;
    B(0x2F4) = 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x102CB0 - case 2/3 layout; target keeps li t0,2 after case 2's b, ours emits it before (24 words)
extern "C" void func_00102CB0(char *self)
{
    int f = 0;
    switch (B(0x2F6)) {
    case 0: {
        int a, b;
        switch (B(0x2F7)) {
        case 0:
        default:
            a = *(int *)(*(int *)(self + 0x304) + 0x6C) + *(int *)(self + 0x304);
            b = *(int *)(*(int *)(self + 0x304) + 0x70) + *(int *)(self + 0x304);
            f = (irand__Fv() & 1) << 1;
            break;
        case 1:
            a = *(int *)(*(int *)(self + 0x304) + 0x64) + *(int *)(self + 0x304);
            b = *(int *)(*(int *)(self + 0x304) + 0x68) + *(int *)(self + 0x304);
            break;
        case 2:
            goto L23;
        case 3:
            f = 2;
        L23:
            a = *(int *)(*(int *)(self + 0x304) + 0x5C) + *(int *)(self + 0x304);
            b = *(int *)(*(int *)(self + 0x304) + 0x60) + *(int *)(self + 0x304);
            break;
        }
        func_002A8578(self, a, b, 5, 0.0f, f, 0);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self)) {
            B(0x2F4) = 0;
            B(0x2F5) = 0;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}
#endif


extern "C" void func_001034E0(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);

// FUNCTION: GAME 0x102938
extern "C" void func_00102938(char *self)
{
    char *pl = (char *)Getplayer();
    switch (B(0x2F6)) {
    case 0:
        func_002A8578(self, *(int *)(*(int *)(self + 0x304) + 0x14) + *(int *)(self + 0x304),
                      *(int *)(*(int *)(self + 0x304) + 0x18) + *(int *)(self + 0x304), 10, 0.0f, 0, 0);
        B(0x2F6)++;
    case 1:
        if (*(unsigned char *)(pl + 0x61F)) {
            float f = *(float *)(pl + 0x608) - 0.5235988f;
            if (f < 0.0f)
                f = 0.0f;
            f *= 0.4f;
            if (f > 0.04188790172338486f)
                f = 0.04188790172338486f;
            if (*(float *)(pl + 0x604) < 0.0f)
                f = -f;
            *(float *)(self + 0x104) += f;
            *(float *)(self + 0x104) = Adjust_theta(*(float *)(self + 0x104));
        }
        moveMotion((cObjBase *)self);
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
    }
    func_001034E0(self);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x10B780 - 1 word, case 2 stores v1 instead of const-2 register v0
extern "C" void func_0010B780(char *self)
{
    *(float *)(self + 0x54C) = 5.0f;
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    *(unsigned *)(self + 0x15F4) |= 0x2000;
    *(float *)(self + 0x5A8) = 1.0f;
    SetMotionStep__FP8cObjBasef(self, 1.0f);
    switch (B(0x2F6)) {
    case 0:
        func_002A8578(self, *(int *)(*(int *)(self + 0x304) + 0x28) + *(int *)(self + 0x304),
                      *(int *)(*(int *)(self + 0x304) + 0x2C) + *(int *)(self + 0x304), 10, 0.0f, 0, 0);
        B(0x2F6)++;
    case 1:
        moveMotion((cObjBase *)self);
        break;
    case 2:
        B(0x2F6) = 2;
    case 3:
        if (moveMotion((cObjBase *)self))
            B(0x2F6) = 0;
        break;
    }
    *(unsigned short *)(self + 0x3AC) |= 0x404;
}
#endif
