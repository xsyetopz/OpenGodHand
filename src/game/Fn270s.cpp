// Small units in 0x270000-0x280000 over raw offsets.
#include "game/cEm00StateDecls.h"

// FUNCTION: GAME 0x273630
extern "C" void func_00273630()
{
    char b[32];
    asm volatile("" : "=m"(b));
}

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
