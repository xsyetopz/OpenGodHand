#include "PlStDispatch.h"

extern "C" PlStFn D_003BFE18[];

// FUNCTION: GAME 0x27BEF8
extern "C" void func_0027BEF8(cPlSt *self)
{
    if (self->st >= 0xb)
        self->st = 0;
    (self->*D_003BFE18[self->st])();
}

extern "C" PlStFn D_003BFEB0[];

// FUNCTION: GAME 0x27F4C0
extern "C" void func_0027F4C0(cPlSt *self)
{
    if (self->st >= 0x12)
        self->st = 0;
    (self->*D_003BFEB0[self->st])();
}

extern "C" PlStFn D_003BFF58[];

// FUNCTION: GAME 0x281C60
extern "C" void func_00281C60(cPlSt *self)
{
    if (self->st >= 0xf)
        self->st = 0;
    (self->*D_003BFF58[self->st])();
}

extern "C" PlStFn D_003BFAD8[];

// FUNCTION: GAME 0x2777A8
extern "C" void func_002777A8(cPlSt *self)
{
    if (self->st >= 0x5)
        self->st = 0;
    (self->*D_003BFAD8[self->st])();
}

extern "C" PlStFn D_003BFB18[];

// FUNCTION: GAME 0x2785E0
extern "C" void func_002785E0(cPlSt *self)
{
    if (self->st >= 0x6)
        self->st = 0;
    (self->*D_003BFB18[self->st])();
}

extern "C" PlStFn D_003BFE88[];

// FUNCTION: GAME 0x27E348
extern "C" void func_0027E348(cPlSt *self)
{
    if (self->st >= 0x2)
        self->st = 0;
    (self->*D_003BFE88[self->st])();
}

extern "C" PlStFn D_003BDD08[];

// FUNCTION: GAME 0x1B2708
extern "C" void func_001B2708(cPlSt *self)
{
    (self->*D_003BDD08[self->st])();
}

extern "C" PlStFn D_003BDE98[];

// FUNCTION: GAME 0x1C9A50
extern "C" void func_001C9A50(cPlSt *self)
{
    (self->*D_003BDE98[self->st])();
}

extern "C" PlStFn D_003BDE50[];

// FUNCTION: GAME 0x1C7F80
extern "C" void func_001C7F80(cPlSt *self)
{
    (self->*D_003BDE50[self->st])();
}

struct sPlTab1 {
    PlStFn f[1];
};
struct sPlTab2 {
    PlStFn f[2];
};
extern "C" sPlTab1 D_00448DF8;
extern "C" sPlTab2 D_004275A0;

// FUNCTION: GAME 0x28A6B8
extern "C" void func_0028A6B8(cPlSt *self)
{
    sPlTab1 t = D_00448DF8;
    if (self->st >= 1)
        self->st = 0;
    (self->*t.f[self->st])();
}

// FUNCTION: GAME 0x1A7940
extern "C" void func_001A7940(cPlSt *self)
{
    sPlTab2 t = D_004275A0;
    (self->*t.f[self->st])();
}
