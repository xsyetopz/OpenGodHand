// Unnamed accessors of the cCoreSave save-data pointer (first member).
// The save block is viewed by byte offset until its layout is known.
#include "game/cCoreSave.h"

struct SaveSelf {
    char *m_save;
};

#define AT(T, o) (*(T *)(s + (o)))

extern "C" int setGameLevel__9cCoreSavei(SaveSelf *, int);
extern "C" int SdeSystemOutModeGet();
extern "C" void SdeSystemOutModeSet(int);
extern const unsigned char D_005E85F8;
extern unsigned int D_00747A38;
extern int D_00747A0C;

// FUNCTION: GAME 0x1F9AD0
extern "C" void func_001F9AD0(SaveSelf *self)
{
    setGameLevel__9cCoreSavei(self, 1);
}

// FUNCTION: GAME 0x1F9AF0
extern "C" void func_001F9AF0(SaveSelf *self)
{
    setGameLevel__9cCoreSavei(self, 5);
}

// FUNCTION: GAME 0x1F9E90
extern "C" void func_001F9E90(SaveSelf *self)
{
    char *s = self->m_save;
    if (s)
        AT(int, 0x178) = D_00747A0C;
}

// FUNCTION: GAME 0x1F9EB0
extern "C" void func_001F9EB0(SaveSelf *self)
{
    char *s = self->m_save;
    if (s)
        D_00747A0C = AT(int, 0x178);
}

// FUNCTION: GAME 0x1F9FF0
extern "C" char *func_001F9FF0(SaveSelf *self)
{
    if (!self->m_save)
        return 0;
    return self->m_save + 0x180;
}

// FUNCTION: GAME 0x1FA638
extern "C" void func_001FA638(SaveSelf *self, short v)
{
    char *s = self->m_save;
    if (s)
        AT(short, 0x1C) = v;
}

// FUNCTION: GAME 0x1FA858
extern "C" int func_001FA858(SaveSelf *self)
{
    char *s = self->m_save;
    if (!s)
        return 0;
    return AT(int, 0x24);
}

#ifdef NONMATCHING
// 0x1FAD38: addu operand order (a1,v1 vs v1,a1)
extern "C" unsigned char func_001FAD38(SaveSelf *self, int i)
{
    char *s = self->m_save;
    if (!s)
        return 0;
    return *(unsigned char *)(s + 0x134 + i);
}
#endif

// FUNCTION: GAME 0x1FAE28
extern "C" void func_001FAE28(SaveSelf *self, unsigned char v)
{
    char *s = self->m_save;
    if (s)
        AT(unsigned char, 0x156) = v;
}

// FUNCTION: GAME 0x1FC090
extern "C" void func_001FC090(SaveSelf *self)
{
    char *s = self->m_save;
    if (s)
        AT(int, 0xA4) = 0;
}

// FUNCTION: GAME 0x1FC0C0
extern "C" unsigned char func_001FC0C0(SaveSelf *self)
{
    char *s = self->m_save;
    if (!s)
        return 0;
    return AT(unsigned char, 0xAF);
}

// FUNCTION: GAME 0x1FC120
extern "C" void func_001FC120(SaveSelf *self)
{
    char *s = self->m_save;
    if (s)
        AT(unsigned char, 0x157) = 1;
}

// FUNCTION: GAME 0x1FC138
extern "C" void func_001FC138(SaveSelf *self)
{
    char *s = self->m_save;
    if (s)
        AT(unsigned char, 0x157) = 0;
}

// FUNCTION: GAME 0x1FC320
extern "C" void func_001FC320(SaveSelf *self)
{
    char *s = self->m_save;
    if (s)
        AT(int, 0xB90) = 0;
}

// FUNCTION: GAME 0x1FBF78
extern "C" void func_001FBF78(SaveSelf *self, unsigned short v)
{
    char *s = self->m_save;
    if (s)
        AT(unsigned short, 0x12) = v;
}

// FUNCTION: GAME 0x1FA8E0
extern "C" int func_001FA8E0(SaveSelf *self)
{
    char *s = self->m_save;
    if (!s)
        return 0;
    return 999998 < AT(int, 0x20);
}

#ifdef NONMATCHING
// 0x1FA838: addu operand order
extern "C" int func_001FA838(SaveSelf *self, int i)
{
    char *s = self->m_save;
    if (!s)
        return 0;
    return *(int *)(s + i * 4 + 0x28);
}
#endif

// FUNCTION: GAME 0x1FBD00
extern "C" void func_001FBD00(SaveSelf *self, unsigned char v)
{
    char *s = self->m_save;
    if (s && (unsigned char)(v - 1) < 6)
        AT(unsigned char, 0x8A) = v;
}

#ifdef NONMATCHING
// 0x1FC100: reloads m_save for second store, store order 0xAE then 0xAF; compiled CSEs it
extern "C" void func_001FC100(SaveSelf *self, unsigned char v)
{
    char *s = self->m_save;
    if (s) {
        AT(unsigned char, 0xAE) = v;
        AT(unsigned char, 0xAF) = v;
    }
}
#endif

#ifdef NONMATCHING
// 0x1FC170: andi of a2 emitted (original does not mask v, and masks index into a0)
extern "C" void func_001FC170(SaveSelf *self, unsigned char i, unsigned char v)
{
    char *s = self->m_save;
    if (s && i < 10)
        AT(unsigned char, 0x98 + i) = v;
}
#endif

#ifdef NONMATCHING
// 0x1FC198: tail return 0x1F merged into one block, addu operand order
extern "C" unsigned char func_001FC198(SaveSelf *self, unsigned char i)
{
    char *s = self->m_save;
    if (!s)
        return 0x1F;
    if (i < 10)
        return AT(unsigned char, 0x98 + i);
    return 0x1F;
}
#endif

// FUNCTION: GAME 0x1FC338
extern "C" void func_001FC338(SaveSelf *self, int b)
{
    char *s = self->m_save;
    if (s)
        AT(unsigned int, 0xB90) |= 1 << b;
}

#ifdef NONMATCHING
// 0x1FC360: movz selection; compiled uses sltu
extern "C" int func_001FC360(SaveSelf *self, int b)
{
    char *s = self->m_save;
    if (!s)
        return 0;
    return (AT(unsigned int, 0xB90) & (1 << b)) != 0;
}
#endif

