// Unnamed accessors of the cCoreSave save-data pointer (first member).
#include "game/cCoreSaveFn.h"

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

// FUNCTION: GAME 0x1FAD38
extern "C" unsigned char func_001FAD38(SaveSelf *self, int i)
{
    char *s = self->m_save;
    if (!s)
        return 0;
    return *(unsigned char *)(i + s + 0x134);
}

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

// FUNCTION: GAME 0x1FA838
extern "C" int func_001FA838(SaveSelf *self, int i)
{
    char *s = self->m_save;
    if (!s)
        return 0;
    int o = i * 4;
    return *(int *)(s + o + 0x28);
}

// FUNCTION: GAME 0x1FBD00
extern "C" void func_001FBD00(SaveSelf *self, unsigned char v)
{
    char *s = self->m_save;
    if (s && (unsigned char)(v - 1) < 6)
        AT(unsigned char, 0x8A) = v;
}

// FUNCTION: GAME 0x1FC338
extern "C" void func_001FC338(SaveSelf *self, int b)
{
    char *s = self->m_save;
    if (s)
        AT(unsigned int, 0xB90) |= 1 << b;
}

// FUNCTION: GAME 0x1F9C58
extern "C" void func_001F9C58(SaveSelf *self)
{
    char *s = self->m_save;
    int v = AT(int, 8) + 1;
    AT(int, 8) = v;
    if ((unsigned)v >= 0x3E8) {
        s = self->m_save;
        AT(int, 8) = 0x3E7;
    }
}

// FUNCTION: GAME 0x1F9C88
extern "C" void func_001F9C88(SaveSelf *self)
{
    *(unsigned short *)(self->m_save + 0xC) = Sys.m_5B0;
    *(unsigned short *)(self->m_save + 0xE) = Sys.m_5B6;
}

// FUNCTION: GAME 0x1F9DD0
extern "C" void func_001F9DD0(SaveSelf *self)
{
    char *s = self->m_save;
    if (s) {
        if (D_005E85F8)
            AT(int, 0x174) = 1;
        else
            AT(int, 0x174) = 0;
    }
}

// FUNCTION: GAME 0x1F9E00
extern "C" void func_001F9E00(SaveSelf *self)
{
    if (*(int *)(self->m_save + 0x174))
        D_005E85F8 = 1;
    else
        D_005E85F8 = 0;
}

// FUNCTION: GAME 0x1FAD58
extern "C" void func_001FAD58(SaveSelf *self, unsigned char v)
{
    char *s = self->m_save;
    if (s) {
        AT(unsigned char, 0x154) = v;
        char *u = self->m_save;
        if (*(unsigned char *)(u + 0x154) >= 0xE)
            *(unsigned char *)(u + 0x154) = 0xD;
    }
}

// FUNCTION: GAME 0x1FADC0
extern "C" void func_001FADC0(SaveSelf *self, unsigned char v)
{
    char *s = self->m_save;
    if (s) {
        AT(unsigned char, 0x155) = v;
        char *u = self->m_save;
        if (*(unsigned char *)(u + 0x155) >= 6)
            *(unsigned char *)(u + 0x155) = 5;
    }
}

// FUNCTION: GAME 0x1FBDA0
extern "C" void func_001FBDA0(SaveSelf *self, short v)
{
    if ((unsigned short)v < 1000)
        *(short *)(self->m_save + 0x88) = v;
}

// FUNCTION: GAME 0x1FBF18
extern "C" void func_001FBF18(SaveSelf *self)
{
    char *s = self->m_save;
    if (s) {
        AT(unsigned short, 0x12)++;
        char *u = self->m_save;
        *(unsigned short *)(u + 0xBB8) += 1;
    }
}
