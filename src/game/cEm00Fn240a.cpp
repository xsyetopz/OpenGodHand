#include "game/cEm00Fn240Decls.h"

// FUNCTION: GAME 0x2478B8
extern "C" void func_002478B8(Fn2478B8Obj *self)
{
    self->m_unk2F5 = 0x99;
    self->m_unk2F6 = 2;
    self->m_unk2F4 = 0;
    self->m_unk2F7 = 0;
}

// FUNCTION: GAME 0x2609A8
extern "C" void func_002609A8(Fn2609Obj *self, int a, int b, int c, int d, short e)
{
    self->m_unk1874 = a;
    self->m_unk1870 = b;
    self->m_unk1878 = c;
    self->m_unk187C = d;
    self->m_unk1880 = e;
    self->m_unk1888 = a;
    self->m_unk1884 = b;
    self->m_unk188C = c;
    self->m_unk1890 = d;
    self->m_unk1894 = e;
}

// FUNCTION: GAME 0x2609E0
extern "C" void func_002609E0(Fn2609Obj *self, int a, int b, int c, int d, short e)
{
    self->m_unk1874 = a;
    self->m_unk1870 = b;
    self->m_unk1878 = c;
    self->m_unk187C = d;
    self->m_unk1880 = e;
}

// FUNCTION: GAME 0x2609F8
extern "C" void func_002609F8(Fn2609Obj *self, int a, int b, int c, int d, short e)
{
    self->m_unk1888 = a;
    self->m_unk1884 = b;
    self->m_unk188C = c;
    self->m_unk1890 = d;
    self->m_unk1894 = e;
}

// FUNCTION: GAME 0x2477F0
extern "C" void func_002477F0(char *self)
{
    *(float *)(self + 0x54C) = 3.0f;
    *(unsigned int *)(self + 0x16D0) |= 0x20000;
    switch (B(0x2F6)) {
    case 0: {
        int m = func_00276468(self);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x23F8) + (int)t, *(int *)(t + 0x23FC) + (int)t, 0, 0.0f, m & 0xFFFF, 0);
        B(0x2F6)++;
    }
    case 1:
        moveMotion((cObjBase *)self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x247708
extern "C" void func_00247708(char *self)
{
    *(unsigned int *)(self + 0x16D0) |= 0x30000;
    *(float *)(self + 0x54C) = 3.0f;
    *(unsigned int *)(self + 0x250) |= 0x10000;
    switch (B(0x2F6)) {
    case 0: {
        int m = func_00276468(self);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x2148) + (int)t, *(int *)(t + 0x214C) + (int)t, 0, 0.0f, m & 0xFFFF, 0);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x244610
extern "C" void func_00244610(char *self)
{
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    *(unsigned int *)(self + 0x16D0) |= 0x10000;
    switch (B(0x2F6)) {
    case 0: {
        unsigned short m = func_00276468(self);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x2494) + (int)t, *(int *)(t + 0x2498) + (int)t, 3, 0.0f, m, 0);
        func_002606E8(self, 0x200);
        func_002606E8(self, 0x203);
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}

// FUNCTION: GAME 0x260650
extern "C" int func_00260650(char *self)
{
    if ((*(int *)(self + 0x564) ^ 0x211) != 0)
        return 0;
    {
        int n = func_002919C0(g_EmManage, *(unsigned short *)(self + 0x2FE), 0x200);
        n += func_002919C0(g_EmManage, *(unsigned short *)(self + 0x2FE), 0x203);
        n += func_002919C0(g_EmManage, *(unsigned short *)(self + 0x2FE), 0x227);
        n += func_002919C0(g_EmManage, *(unsigned short *)(self + 0x2FE), 0x22A);
        return n;
    }
}
