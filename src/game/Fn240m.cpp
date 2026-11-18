// Mid-size units in 0x240000-0x260000.
#include "game/cEm00Fn240Decls.h"

extern "C" float fRand1_1__Fv();
extern "C" void func_001D05A0(void *, int);

// FUNCTION: GAME 0x247050
extern "C" void func_00247050(char *self)
{
    B(0x617) = 1;
    switch (B(0x2F6)) {
    case 0: {
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0x10A8) + (int)o, *(int *)(o + 0x10AC) + (int)o, 0xA, 0.0f, r, 0);
        *(float *)(self + 0x600) = fRand1_1__Fv() * 150.0f + 150.0f;
        B(0x2F6)++;
    }
    case 1: {
        moveMotion((cObjBase *)self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        float t = *(float *)(self + 0x600) - *(float *)(self + 0x5A8);
        *(float *)(self + 0x600) = t;
        if (t <= 0.0f)
            B(0x2F6) = 2;
        if (*(float *)(self + 0x16C0) > 0.0f)
            func_002705D8(self);
        break;
    }
    case 2: {
        unsigned short r = func_00276468(self);
        char *o = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(o + 0x11A8) + (int)o, *(int *)(o + 0x11B4) + (int)o, 0xA, 0.0f, r, 0);
        if (*(void **)(self + 0x6F0))
            func_001D05A0(*(void **)(self + 0x6F0), 0);
        B(0x2F6)++;
    }
    case 3:
        if (moveMotion((cObjBase *)self)) {
            B(0x2F6) = 0;
        } else {
            ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
            ((cObjBase *)self)->addNullSpeed(1.0f);
        }
    }
}
