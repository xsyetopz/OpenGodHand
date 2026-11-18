// Small unnamed functions in 0x240000-0x267FFF.

#include "game/cEm00State.h"

struct Fn2478B8Obj {
    char _pad0[0x2F4];
    char m_unk2F4;
    unsigned char m_unk2F5;
    char m_unk2F6;
    char m_unk2F7;
};

// FUNCTION: GAME 0x2478B8
extern "C" void func_002478B8(Fn2478B8Obj *self)
{
    self->m_unk2F5 = 0x99;
    self->m_unk2F6 = 2;
    self->m_unk2F4 = 0;
    self->m_unk2F7 = 0;
}

struct Fn2609Obj {
    char _pad0[0x1870];
    int m_unk1870;
    int m_unk1874;
    int m_unk1878;
    int m_unk187C;
    short m_unk1880;
    char _pad1882[2];
    int m_unk1884;
    int m_unk1888;
    int m_unk188C;
    int m_unk1890;
    short m_unk1894;
};

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

// func_00247218 @ 0x247218: near-miss, 7 words differ. The original keeps the
// cEmParam base in v0 and the two offsets in v1/a0 across the branch; every
// source form tried allocates the base in a0 and the sums in a1/a2.
#ifdef NONMATCHING
extern "C" void func_00247218(char *self)
{
    B(0x617) = 1;
    switch (B(0x2F6)) {
    case 0: {
        unsigned short m = func_00276468(self);
        char *t;
        int a, b;
        if (*(int *)(self + 0x564) == 0x24F) {
            t = *(char **)(self + 0x304);
            a = *(int *)(t + 0x1F70); b = *(int *)(t + 0x1F74);
        } else {
            t = *(char **)(self + 0x304);
            a = *(int *)(t + 0x1F78); b = *(int *)(t + 0x1F7C);
        }
        func_002A8578(self, a + (int)t, b + (int)t, 10, 0.0f, m, 0);
        *(short *)(self + 0x568) = 10;
        B(0x623) = 1;
        B(0x2F6)++;
    }
    case 1:
        if (moveMotion((cObjBase *)self))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
        if (*(short *)(self + 0x568) > 0)
            (*(short *)(self + 0x568))--;
        else
            B(0x623) = 0;
    }
}
#endif

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

// func_00246F40 @ 0x246F40: near-miss, 3 words differ (the case-0 state increment
// uses v0 where the original uses v1).
#ifdef NONMATCHING
extern "C" void func_00246F40(char *self)
{
    g_CollSolidManage.SetActive((cGameObj *)self, 0);
    *(unsigned int *)(self + 0x16D0) |= 0x20000;
    *(unsigned int *)(self + 0x16D0) |= 0x10000;
    switch (B(0x2F6)) {
    case 0: {
        unsigned short m = func_00276468(self);
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0xC34) + (int)t, *(int *)(t + 0xC38) + (int)t, 10, 80.0f, m, 0);
        *(int *)(self + 0x5B4) = 0x1869F;
        func_0026F120(self);
        B(0x2F6)++;
    }
    case 1:
        *(unsigned int *)(self + 0x16D0) |= 0x20000;
        if (moveMotion((cObjBase *)self))
            func_00270C78(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}
#endif

// func_002461F0 @ 0x2461F0: near-miss, 16 words differ. Same cause as
// func_00247218: the original keeps the cEmParam base in v0 and the raw offsets
// in v1/a0 across the branch; the pointer-sum forms tried spill the sums to s1/s2
// before the call or use a2 for the base.
#ifdef NONMATCHING
extern "C" void func_002461F0(char *self)
{
    switch (B(0x2F6)) {
    case 0: {
        char *a, *b;
        int c = *(int *)(self + 0x564) == 0x256;
        B(0x1864) = 0;
        char *t = *(char **)(self + 0x304);
        if (c) {
            *(float *)(self + 0x600) = 45.0f;
            a = (char *)*(int *)(t + 0x2B7C) + (int)t;
            b = (char *)*(int *)(t + 0x2B80) + (int)t;
        } else {
            *(float *)(self + 0x600) = 60.0f;
            a = (char *)*(int *)(t + 0x2C30) + (int)t;
            b = (char *)*(int *)(t + 0x2C34) + (int)t;
        }
        unsigned short m = func_00276468(self);
        func_002A8578(self, (int)a, (int)b, 10, 0.0f, m, 0);
        B(0x2F6)++;
    }
    case 1:
        if (*(float *)(self + 0x600) > 0.0f) {
            *(float *)(self + 0x600) -= *(float *)(self + 0x5A8);
            *(unsigned int *)(self + 0x16D0) |= 0x800000;
        }
        ((cGameObj *)self)->SetTgtTurn(*Getplayer()->m_pPos, *(float *)(self + 0x5A8) * 0.19634955f);
        if (moveMotion((cObjBase *)self) || (*(unsigned short *)(self + 0x3AC) & 0x10))
            func_002705D8(self);
        ((cObjBase *)self)->addNullSpeed_Rotation(1.0f);
        ((cObjBase *)self)->addNullSpeed(1.0f);
    }
}
#endif

extern char g_EmManage[];
extern "C" int func_002919C0(void *, int, int);

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

class cVec;
extern cVec ZeroVec;
class cDmgUnitLocal {
public:
    void SetDamageCollRadius(int id, float r);
    void SetDamageCollActive(bool on);
};
class cDamageGive : public cDmgUnitLocal {
public:
    void SetDmgGiveHitVec(const cVec &v);
};

// func_00262980 @ 0x262980: near-miss, 11 words differ (branch layout around the
// 3.0f/2.0f radius select and the 0x46 store).
#ifdef NONMATCHING
extern "C" void func_00262980(char *self)
{
    float r;
    if (*(int *)(self + 0x564) != 0x260) {
        r = 2.0f;
    } else {
        *(short *)(*(char **)(self + 0x680) + 0x46) = 0x49;
        r = 3.0f;
    }
    (*(cDamageGive **)(self + 0x680))->SetDamageCollRadius(*(int *)(self + 0x684), r);
    *(int *)(*(char **)(self + 0x680) + 0x4C) = 0;
    (*(cDamageGive **)(self + 0x680))->SetDamageCollActive(true);
    (*(cDamageGive **)(self + 0x680))->SetDmgGiveHitVec(ZeroVec);
    char *d = *(char **)(self + 0x680);
    *(int *)(d + 0x40) = -1;
    *(short *)(d + 0x44) = 0;
}

#endif

// func_00262A10 @ 0x262A10: near-miss, 30 words differ (the original shares one
// `v0 = 1; sb 0x1864` exit through branch-likely slots; no source form found).
#ifdef NONMATCHING
#define HITP(off) (*(char **)(*(char **)(self + (off)) + 0x34) && *(unsigned short *)(*(char **)(*(char **)(self + (off)) + 0x34) + 0x2FE) == 0x100)

extern "C" int func_00262A10(char *self)
{
    if (HITP(0x670) || HITP(0x678) || HITP(0x680) || HITP(0x688)) {
        B(0x1864) = 1;
        return 1;
    }
    return 0;
}
#endif
