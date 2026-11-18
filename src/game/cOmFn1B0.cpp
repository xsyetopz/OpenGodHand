#include "game/cOmBase.h"

// Small stubs of the 0x1B0000-0x1BFFFF map-object classes (dieCommon wrappers,
// vtable-reset destructors, empty virtuals and field accessors), as free functions.
extern "C" void func_001B6FB8(void *self);
extern "C" void func_001BD6B0(cOmBase *self);
extern "C" void func_001C29D0(cOmBase *self);

extern "C" void func_001B6F38(void *self);
extern "C" void func_001BD650(void *self);
extern "C" void func_001C2820(void *self);
extern const char D_00428228[];
extern const char D_004284A0[];
extern const char D_00428588[];
extern const char D_00428650[];
extern const char D_00429190[];
extern const char D_00429620[];
extern const char D_004296F0[];
extern const char D_004297D8[];

// FUNCTION: GAME 0x1B0BA8
extern "C" void func_001B0BA8(cOmBase *self)
{
    *(const void **)((char *)self + 0x214) = D_00428228;
    func_001BD650(self);
}

// FUNCTION: GAME 0x1B22A8
extern "C" void func_001B22A8(cOmBase *self)
{
    *(const void **)((char *)self + 0x214) = D_004284A0;
    func_001C2820(self);
}

// FUNCTION: GAME 0x1B2520
extern "C" void func_001B2520(cOmBase *self)
{
    *(const void **)((char *)self + 0x214) = D_00428588;
    func_001B6F38(self);
}

// FUNCTION: GAME 0x1B37A8
extern "C" void func_001B37A8(cOmBase *self)
{
    *(const void **)((char *)self + 0x214) = D_00428650;
    func_001B6F38(self);
}

// FUNCTION: GAME 0x1BBB00
extern "C" void func_001BBB00(cOmBase *self)
{
    *(const void **)((char *)self + 0x214) = D_00429190;
    func_001B6F38(self);
}

// FUNCTION: GAME 0x1BE8F0
extern "C" void func_001BE8F0(cOmBase *self)
{
    *(const void **)((char *)self + 0x214) = D_00429620;
    func_001B6F38(self);
}

// FUNCTION: GAME 0x1BF4B8
extern "C" void func_001BF4B8(cOmBase *self)
{
    *(const void **)((char *)self + 0x214) = D_004296F0;
    func_001B6F38(self);
}

// FUNCTION: GAME 0x1BFB00
extern "C" void func_001BFB00(cOmBase *self)
{
    *(const void **)((char *)self + 0x214) = D_004297D8;
    func_001B6F38(self);
}

// FUNCTION: GAME 0x1B2478
extern "C" void func_001B2478(cOmBase *self)
{
    func_001C29D0(self);
}

// Singleton accessors: construct on first use and register the destructor.
extern "C" void func_0031EEA8(void *obj, const void *a, const void *b);
extern "C" void func_001B8058();
extern "C" void func_001C3BE8();
extern const char D_00428140[];
extern const char D_00428210[];
extern const char D_004283A0[];
extern const char D_00428488[];
extern const char D_00428570[];
extern const char D_00428700[];
extern const char D_004288F0[];
extern const char D_004289D8[];
extern const char D_00428C08[];
extern const char D_00428CD0[];
extern const char D_00429178[];
extern const char D_00429240[];
extern const char D_004293A0[];
extern const char D_004294D0[];
extern const char D_004295A0[];
extern const char D_004296D0[];
extern const char D_004297A0[];
extern const char D_00785798[];
extern const char D_00785878[];
extern int D_00785858;
extern int D_007859B8;
extern int D_00786038;
extern int D_00786048;
extern int D_00786068;
extern int D_00786078;
extern int D_00786088;
extern int D_007860A8;
extern int D_007860C8;
extern int D_007860D8;
extern int D_007860E8;
extern int D_007860F8;
extern int D_00786108;
extern int D_00786118;
extern int D_00786128;
extern int D_00786138;
extern int D_00786148;

// FUNCTION: GAME 0x1B0240
extern "C" void *func_001B0240()
{
    if (D_00786038 == 0) {
        func_001B8058();
        func_0031EEA8(&D_00786038, D_00428140, D_00785878);
    }
    return &D_00786038;
}

// FUNCTION: GAME 0x1B0B20
extern "C" void *func_001B0B20()
{
    if (D_00786048 == 0) {
        func_001B8058();
        func_0031EEA8(&D_00786048, D_00428210, D_00785878);
    }
    return &D_00786048;
}

// FUNCTION: GAME 0x1B1AE8
extern "C" void *func_001B1AE8()
{
    if (D_00786068 == 0) {
        func_001B8058();
        func_0031EEA8(&D_00786068, D_004283A0, D_00785878);
    }
    return &D_00786068;
}

// FUNCTION: GAME 0x1B21B0
extern "C" void *func_001B21B0()
{
    if (D_00786078 == 0) {
        func_001B8058();
        func_0031EEA8(&D_00786078, D_00428488, D_00785878);
    }
    return &D_00786078;
}

// FUNCTION: GAME 0x1B2498
extern "C" void *func_001B2498()
{
    if (D_00786088 == 0) {
        func_001C3BE8();
        func_0031EEA8(&D_00786088, D_00428570, D_00785798);
    }
    return &D_00786088;
}

// FUNCTION: GAME 0x1B3978
extern "C" void *func_001B3978()
{
    if (D_007860A8 == 0) {
        func_001B8058();
        func_0031EEA8(&D_007860A8, D_00428700, D_00785878);
    }
    return &D_007860A8;
}

// FUNCTION: GAME 0x1B66C0
extern "C" void *func_001B66C0()
{
    if (D_007860C8 == 0) {
        func_001B8058();
        func_0031EEA8(&D_007860C8, D_004288F0, D_00785878);
    }
    return &D_007860C8;
}

// FUNCTION: GAME 0x1B6E30
extern "C" void *func_001B6E30()
{
    if (D_007860D8 == 0) {
        func_001B8058();
        func_0031EEA8(&D_007860D8, D_004289D8, D_00785878);
    }
    return &D_007860D8;
}

// FUNCTION: GAME 0x1B8758
extern "C" void *func_001B8758()
{
    if (D_007860E8 == 0) {
        func_001B8058();
        func_0031EEA8(&D_007860E8, D_00428C08, D_00785878);
    }
    return &D_007860E8;
}

// FUNCTION: GAME 0x1B8FA8
extern "C" void *func_001B8FA8()
{
    if (D_007860F8 == 0) {
        func_001B8058();
        func_0031EEA8(&D_007860F8, D_00428CD0, D_00785878);
    }
    return &D_007860F8;
}
