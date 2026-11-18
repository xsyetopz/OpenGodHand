// Mid-size units in 0x100000-0x110000.
#include "game/cEm00StateDecls.h"
#include "game/cVec.h"

extern "C" void calcParts__6cModel(void *);

struct sPos100 {
    char pad0[0xF0];
    cVec *m_pPos;
    char pad1[0xC];
    cVec m_100;
    char pad2[0x490 - 0x10C];
    cVec m_490;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x103760 - 4 words, a1/v0 swap of constants 7 and 0x12C
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
    case 1:
        *(int *)(s + 0x14B4) = 0x12C;
        *(unsigned *)(s + 0x250) &= 0xFFFFFFFD;
        *(unsigned *)(s + 0x14B0) |= 1;
        B(0x2F5) = 7;
        break;
    }
    B(0x2F6) = 0;
    B(0x2F7) = 0;
    B(0x2F4) = 0;
}
#endif

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
