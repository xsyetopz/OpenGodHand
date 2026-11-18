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

// FUNCTION: GAME 0x1BBA78
extern "C" void *func_001BBA78()
{
    if (D_00786108 == 0) {
        func_001B8058();
        func_0031EEA8(&D_00786108, D_00429178, D_00785878);
    }
    return &D_00786108;
}

// FUNCTION: GAME 0x1BBE68
extern "C" void *func_001BBE68()
{
    if (D_00786118 == 0) {
        func_001B8058();
        func_0031EEA8(&D_00786118, D_00429240, D_00785878);
    }
    return &D_00786118;
}

// FUNCTION: GAME 0x1BD528
extern "C" void *func_001BD528()
{
    if (D_007859B8 == 0) {
        func_001B8058();
        func_0031EEA8(&D_007859B8, D_004293A0, D_00785878);
    }
    return &D_007859B8;
}

// FUNCTION: GAME 0x1BDE00
extern "C" void *func_001BDE00()
{
    if (D_00785858 == 0) {
        func_001B8058();
        func_0031EEA8(&D_00785858, D_004294D0, D_00785878);
    }
    return &D_00785858;
}

// FUNCTION: GAME 0x1BE860
extern "C" void *func_001BE860()
{
    if (D_00786128 == 0) {
        func_001B8058();
        func_0031EEA8(&D_00786128, D_004295A0, D_00785878);
    }
    return &D_00786128;
}

// FUNCTION: GAME 0x1BF428
extern "C" void *func_001BF428()
{
    if (D_00786138 == 0) {
        func_001B8058();
        func_0031EEA8(&D_00786138, D_004296D0, D_00785878);
    }
    return &D_00786138;
}

// FUNCTION: GAME 0x1BFA78
extern "C" void *func_001BFA78()
{
    if (D_00786148 == 0) {
        func_001B8058();
        func_0031EEA8(&D_00786148, D_004297A0, D_00785878);
    }
    return &D_00786148;
}

// Constructor-style stubs: base ctor func_001B6E90, vtable store at +0x214, field init.
extern "C" void func_001B6E90(void *self);
extern const char D_00428160[];
extern const char D_004282F0[];
extern const char D_004283D8[];
extern const char D_00428928[];
extern const char D_00428B58[];
extern const char D_00428C20[];
extern const char D_004290C8[];
extern const char D_004292F0[];

// FUNCTION: GAME 0x1B1B38
extern "C" void *func_001B1B38(char *self)
{
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_004283D8;
    *(int *)(self + 0x600) = 0;
    *(short *)(self + 0x604) = 0;
    return self;
}

// FUNCTION: GAME 0x1B8108
extern "C" void *func_001B8108(char *self)
{
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00428B58;
    return self;
}

// FUNCTION: GAME 0x1B8FF8
extern "C" void *func_001B8FF8(char *self)
{
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_004290C8;
    return self;
}

// FUNCTION: GAME 0x1BBAC8
extern "C" void *func_001BBAC8(char *self)
{
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00429190;
    return self;
}

// FUNCTION: GAME 0x1BFAC8
extern "C" void *func_001BFAC8(char *self)
{
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_004297D8;
    return self;
}

#ifdef NONMATCHING
// Near-misses: sqc2 variants differ only by vtable temp register (v1 vs v0); 1BE8B0/1BF478 differ in temp register order.
extern "C" void *func_001B0290(char *self)
{
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00428160;
    __asm__ volatile("sqc2 $vf0,0x610(%0)" : : "r"(self) : "memory");
    return self;
}

extern "C" void *func_001B0CE8(char *self)
{
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_004282F0;
    __asm__ volatile("sqc2 $vf0,0x610(%0)" : : "r"(self) : "memory");
    __asm__ volatile("sqc2 $vf0,0x620(%0)" : : "r"(self) : "memory");
    __asm__ volatile("sqc2 $vf0,0x640(%0)" : : "r"(self) : "memory");
    __asm__ volatile("sqc2 $vf0,0x650(%0)" : : "r"(self) : "memory");
    return self;
}

extern "C" void *func_001B24E8(char *self)
{
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00428588;
    __asm__ volatile("sqc2 $vf0,0x610(%0)" : : "r"(self) : "memory");
    return self;
}

extern "C" void *func_001B6710(char *self)
{
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00428928;
    __asm__ volatile("sqc2 $vf0,0x600(%0)" : : "r"(self) : "memory");
    __asm__ volatile("sqc2 $vf0,0x610(%0)" : : "r"(self) : "memory");
    *(int *)(self + 0x620) = 0;
    *(int *)(self + 0x624) = 0;
    return self;
}

extern "C" void *func_001B87A8(char *self)
{
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00428C20;
    __asm__ volatile("sqc2 $vf0,0x600(%0)" : : "r"(self) : "memory");
    __asm__ volatile("sqc2 $vf0,0x610(%0)" : : "r"(self) : "memory");
    *(char *)(self + 0x630) = 0;
    *(int *)(self + 0x620) = 0;
    return self;
}

extern "C" void *func_001BBEB8(char *self)
{
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_004292F0;
    __asm__ volatile("sqc2 $vf0,0x610(%0)" : : "r"(self) : "memory");
    *(int *)(self + 0x620) = 0;
    *(int *)(self + 0x634) = 0;
    *(short *)(self + 0x630) = 0;
    *(int *)(self + 0x644) = 0;
    return self;
}

extern "C" void *func_001BE8B0(char *self)
{
    func_001B6E90(self);
    *(int *)(self + 0x604) = 0x3E9;
    *(const void **)(self + 0x214) = D_00429620;
    *(int *)(self + 0x600) = 0;
    return self;
}

extern "C" void *func_001BF478(char *self)
{
    func_001B6E90(self);
    *(char *)(self + 0x600) = -1;
    *(const void **)(self + 0x214) = D_004296F0;
    return self;
}

#endif
