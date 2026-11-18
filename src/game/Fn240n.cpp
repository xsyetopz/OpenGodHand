// Units in 0x240000-0x260000.
#include "game/cEm00Fn240Decls.h"
#include "game/cVec.h"


#ifdef NONMATCHING
// DRAFT: GAME 0x247218 - 7 words: register allocation of the table base (target v0, mine a0)
extern "C" void func_00247218(char *self)
{
    B(0x617) = 1;
    switch (B(0x2F6)) {
    case 0: {
        unsigned short r = func_00276468(self);
        int o = *(int *)(self + 0x304);
        int a, b;
        if (*(int *)(self + 0x564) == 0x24F) {
            a = *(int *)(o + 0x1F70);
            b = *(int *)(o + 0x1F74);
        } else {
            a = *(int *)(o + 0x1F78);
            b = *(int *)(o + 0x1F7C);
        }
        func_002A8578(self, a + o, b + o, 0xA, 0.0f, r, 0);
        *(short *)(self + 0x568) = 10;
        B(0x623) = 1;
        B(0x2F6)++;
    }
    case 1: {
        if (moveMotion((cObjBase *)self))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        if (*(short *)(self + 0x568) > 0)
            (*(unsigned short *)(self + 0x568))--;
        else
            B(0x623) = 0;
        break;
    }
    }
}
#endif
