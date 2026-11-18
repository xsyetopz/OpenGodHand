#include "game/cEm00.h"

// Small unnamed functions between 0x268000 and 0x27FFFF. Their owners are the
// cEm* classes; field access goes through byte offsets until those classes exist.
#define AT(T, p, off) (*(T *)((char *)(p) + (off)))

#define EMPTY(addr) \
    extern "C" void func_00##addr() {}

// FUNCTION: GAME 0x268500
EMPTY(268500)
// FUNCTION: GAME 0x277F08
EMPTY(277F08)
// FUNCTION: GAME 0x277F10
EMPTY(277F10)
// FUNCTION: GAME 0x277F78
EMPTY(277F78)
// FUNCTION: GAME 0x279670
EMPTY(279670)
// FUNCTION: GAME 0x279930
EMPTY(279930)
// FUNCTION: GAME 0x279E70
EMPTY(279E70)
// FUNCTION: GAME 0x279F60
EMPTY(279F60)
// FUNCTION: GAME 0x27CFF8
EMPTY(27CFF8)
// FUNCTION: GAME 0x27D0D8
EMPTY(27D0D8)
// FUNCTION: GAME 0x27D0E0
EMPTY(27D0E0)
// FUNCTION: GAME 0x27D148
EMPTY(27D148)
// FUNCTION: GAME 0x27E4E0
EMPTY(27E4E0)
// FUNCTION: GAME 0x27E5C0
EMPTY(27E5C0)
// FUNCTION: GAME 0x27E5C8
EMPTY(27E5C8)
// FUNCTION: GAME 0x27E630
EMPTY(27E630)

// FUNCTION: GAME 0x26E7A0
extern "C" void func_0026E7A0(void *self, float f)
{
    AT(float, self, 0x16C8) = f;
}

// FUNCTION: GAME 0x26ECC0
extern "C" bool func_0026ECC0(void *self)
{
    unsigned int m = 2;
    return (AT(unsigned int, self, 0x16D0) & m) != 0;
}

// FUNCTION: GAME 0x26F2F0
extern "C" bool func_0026F2F0(void *self)
{
    unsigned int m = 0x100000;
    return (AT(unsigned int, self, 0x16D0) & m) != 0;
}

// FUNCTION: GAME 0x26F308
extern "C" bool func_0026F308(void *self)
{
    unsigned int m = 4;
    return (AT(unsigned int, self, 0x16D4) & m) != 0;
}

// FUNCTION: GAME 0x26F318
extern "C" bool func_0026F318(void *self)
{
    unsigned int m = 4;
    return (AT(unsigned short, self, 0x3AC) & m) != 0;
}

// FUNCTION: GAME 0x272570
extern "C" void func_00272570(void *self)
{
    AT(unsigned int, self, 0x16D0) |= 0x20000000;
}

// FUNCTION: GAME 0x276468
extern "C" int func_00276468(void *self)
{
    return AT(unsigned char, self, 0x17C3) ? 2 : 0;
}

// FUNCTION: GAME 0x2767E0
extern "C" int func_002767E0(void *self)
{
    return AT(int, self, 0x698);
}

// FUNCTION: GAME 0x27A128
extern "C" int func_0027A128(void *self)
{
    return AT(int, self, 0x1580);
}

// FUNCTION: GAME 0x27DD00
extern "C" int func_0027DD00(void *self)
{
    return AT(unsigned int, self, 0x1560) & 1;
}

// FUNCTION: GAME 0x279C88
extern "C" void func_00279C88(void *self)
{
    AT(unsigned int, self, 0x1560) |= 4;
}

// FUNCTION: GAME 0x26EB00
extern "C" void func_0026EB00(void *self)
{
    AT(int, self, 0x24C) = 0;
    AT(unsigned int, self, 0x250) |= 0x10;
    AT(float, self, 0x1704) = 1.0f;
}

// FUNCTION: GAME 0x26F1D8
extern "C" int func_0026F1D8(void *self)
{
    return AT(float, self, 0x17CC) > 0.0f;
}

// FUNCTION: GAME 0x273EB8
extern "C" int func_00273EB8(void *self)
{
    if (AT(float, self, 0x1720) > 0.0f)
        return 0;
    return 1;
}

// FUNCTION: GAME 0x273EE0
extern "C" int func_00273EE0(void *self)
{
    if (AT(float, self, 0x1724) > 0.0f)
        return 0;
    return 1;
}

// 0x2744B8: near-miss, 9 words differ (original 40 bytes, ours 36).
#ifdef NONMATCHING
extern "C" bool func_002744B8(void *self)
{
    if (AT(int, self, 0x564) == 0x211)
        return AT(unsigned int, self, 0x16D4) & 0x20;
    return false;
}

#endif

// FUNCTION: GAME 0x276090
extern "C" void func_00276090(void *self, bool b)
{
    if (b)
        AT(unsigned int, self, 0x16D4) |= 0x200000;
    else
        AT(unsigned int, self, 0x16D4) &= ~0x200000;
}

extern "C" void func_00276618(int, int);
extern "C" void func_00276F18(int, int);
extern "C" void func_0027A7F0(int, int);
extern "C" void func_0027B2E8(int, int);
extern "C" void func_00104010(void *, void *, void *);
extern "C" void func_0030F5C8(void *);

// FUNCTION: GAME 0x2767E8
extern "C" void func_002767E8()
{
    func_00276618(1, 0xFFFF);
}

// FUNCTION: GAME 0x277288
extern "C" void func_00277288()
{
    func_00276F18(1, 0xFFFF);
}

// FUNCTION: GAME 0x27AC50
extern "C" void func_0027AC50()
{
    func_0027A7F0(1, 0xFFFF);
}

// FUNCTION: GAME 0x27B748
extern "C" void func_0027B748()
{
    func_0027B2E8(1, 0xFFFF);
}

// FUNCTION: GAME 0x27A748
extern "C" void func_0027A748(void *self)
{
    func_00104010(self, (char *)self + 0x2130, (char *)self + 0x5B0);
}

// FUNCTION: GAME 0x27B240
extern "C" void func_0027B240(void *self)
{
    func_00104010(self, (char *)self + 0x2130, (char *)self + 0x5B0);
}

// 0x2714B0: near-miss, guessed body is wrong (original 56 bytes, ours 44); wrapper around func_0030F5C8.
#ifdef NONMATCHING
extern "C" void func_002714B0(void *self)
{
    void *p = AT(void *, self, 0x1860);
    if (p) {
        AT(void *, self, 0x1860) = 0;
        func_0030F5C8(p);
    }
}
#endif
