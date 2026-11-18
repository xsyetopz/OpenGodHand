// Small units in 0x290000-0x29FFFF (round 24).
#include "game/cDvd.h"

extern char Dvd[];
extern char RelSys;
extern char D_Ev297AA8[];
extern float D_Ev297B88[];
extern "C" void func_0(char *);
extern "C" void func_0b(char *, unsigned short, unsigned char);
extern "C" void unlinkNoFree__7cRelSysQ27cRelSys8eRelType(void *, int);
extern "C" int Check__4cDvd6eDvdId(void *, int);

// FUNCTION: GAME 0x297B88
extern "C" float getCutFrame__C6cEvent()
{
    return D_Ev297B88[5];
}

struct EvRst {
    char _pad0[4];
    unsigned char m_4, m_5, m_6, m_7;
    int m_8;
    char _pad1[0x14 - 0xC];
    int m_14;
    int m_18;
};

// FUNCTION: GAME 0x297660
extern "C" void func_00297660(EvRst *s)
{
    s->m_4 = 0;
    s->m_5 = 0;
    s->m_6 = 0;
    s->m_7 = 0;
    s->m_8 = 0;
    s->m_18 = 0;
    s->m_14 = 0;
}

// FUNCTION: GAME 0x297A68
extern "C" void isEndCreateWork__C6cEvent()
{
    func_0(D_Ev297AA8);
}

// FUNCTION: GAME 0x297A88
extern "C" void startReleaseObj__6cEvent()
{
    func_0(D_Ev297AA8);
}

// FUNCTION: GAME 0x297428
extern "C" int func_00297428(char *self)
{
    return Check__4cDvd6eDvdId(Dvd, *(int *)(self + 0xC)) == 0;
}

// FUNCTION: GAME 0x2975D0
extern "C" int func_002975D0(char *self)
{
    return Check__4cDvd6eDvdId(Dvd, *(int *)(self + 0xC)) == 0;
}

// FUNCTION: GAME 0x297C50
extern "C" void getObjPtr__6cEvent6eObjIdUc(int, unsigned short a, unsigned char b)
{
    func_0b(D_Ev297AA8, a, b);
}
