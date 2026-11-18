// Small units in 0x270000-0x280000 over raw offsets.
#include "game/cEm00StateDecls.h"

// FUNCTION: GAME 0x273630
extern "C" void func_00273630()
{
    char b[32];
    asm volatile("" : "=m"(b));
}

#ifdef NONMATCHING
// DRAFT: GAME 0x27DBF8 - 19 words, compare/tail layout differs
extern "C" void func_0027DBF8(char *self, int a1)
{
    int y;
    switch (a1) {
    case 1: y = 2; break;
    case 2: y = 4; break;
    default:
        B(0x2F7) = 0;
        B(0x2F5) = 7;
        B(0x2F4) = 0;
        B(0x2F6) = 0;
        return;
    }
    B(0x2F5) = 7;
    B(0x2F6) = y;
    B(0x2F7) = 0;
    B(0x2F4) = 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x27E3F8 - 6 words, ld ra/delay slot and shared jal layout
extern "C" void func_0027E3F8(char *self)
{
    unsigned char v = B(0x2F6);
    if (v == 0) B(0x2F6) = 1;
    else if (v != 1) return;
    moveMotion((cObjBase *)self);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x27A0F0 - 5 words, zero-fill/branch layout
extern "C" int func_0027A0F0(char *self)
{
    volatile int t;
    t = B(0x2B4);
    int v = B(0x2B4) ? **(int **)(self + 0x278) : 0;
    if (v) return *(int *)(v + 0xF0);
    return *(int *)(self + 0xF0);
}
#endif
