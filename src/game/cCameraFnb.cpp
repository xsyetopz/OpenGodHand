#include "game/cIDBase.h"

class cCamera {
public:
    void move();
    void reset();
};
class cParts;
class cCamManager {
public:
    unsigned isCk_CamClass(unsigned m);
    char _pad0[0x1028];
    unsigned m_flags;
};
class cPartsCamera {
public:
    void SetParts(cParts *a, cParts *b, cParts *c);
    char _pad0[0x360];
    cParts *m_a;
    cParts *m_b;
    cParts *m_c;
};
extern "C" void func_00138BE8(void *);
extern char CamManager[];
extern cCamera *pCamWork;

extern char D_0041DCC8[];
extern "C" void func_0030F5A0(void *);

// FUNCTION: GAME 0x13E300
extern "C" void func_0013E300(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x13E750
extern "C" void func_0013E750(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x13EC50
extern "C" void func_0013EC50(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x13F270
extern "C" void func_0013F270(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x140B58
extern "C" void func_00140B58(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x1434D0
extern "C" void func_001434D0(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x143AF0
extern "C" void func_00143AF0(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x144AD0
extern "C" void func_00144AD0(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x146748
extern "C" void func_00146748(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x146E70
extern "C" void func_00146E70(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x146F98
extern "C" void func_00146F98(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x1474A0
extern "C" void func_001474A0(char *p, int f)
{
    *(char **)(p + 0x80) = D_0041DCC8;
    if (f & 1)
        func_0030F5A0(p);
}

extern char D_0041D5A8[];

// FUNCTION: GAME 0x12D178
extern "C" void func_0012D178(char *p, int f)
{
    *(char **)(p + 0x5C) = D_0041D5A8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x12DC88
extern "C" void func_0012DC88(char *p, int f)
{
    *(char **)(p + 0x5C) = D_0041D5A8;
    if (f & 1)
        func_0030F5A0(p);
}
extern char D_0041ECA0[];

extern char D_0041D540[];

// FUNCTION: GAME 0x12E640
extern "C" void func_0012E640(char *p, int f)
{
    *(char **)(p + 0x198) = D_0041D540;
    if (f & 1)
        func_0030F5A0(p);
}

extern char D_0041D8F8[];

// FUNCTION: GAME 0x139878
extern "C" void func_00139878(char *p, int f)
{
    *(char **)(p + 0x35C) = D_0041D8F8;
    if (f & 1)
        func_0030F5A0(p);
}


// FUNCTION: GAME 0x150048
extern "C" void func_00150048(char *p, int f)
{
    *(char **)(p + 0x214) = D_0041ECA0;
    if (f & 1)
        func_0030F5A0(p);
}

extern char D_0042C4D8[];

// FUNCTION: GAME 0x1FCE80
extern "C" void func_001FCE80(char *p, int f)
{
    *(char **)(p + 0x50) = D_0042C4D8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x1FD418
extern "C" void func_001FD418(char *p, int f)
{
    *(char **)(p + 0x50) = D_0042C4D8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x1FE500
extern "C" void func_001FE500(char *p, int f)
{
    *(char **)(p + 0x50) = D_0042C4D8;
    if (f & 1)
        func_0030F5A0(p);
}

extern char D_0044B310[];

// FUNCTION: GAME 0x2B6568
extern "C" void func_002B6568(char *p, int f)
{
    *(char **)(p + 0xF0) = D_0044B310;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x2FBDD8
extern "C" void func_002FBDD8(char *p, int f)
{
    *(char **)(p + 0xF0) = D_0044B310;
    if (f & 1)
        func_0030F5A0(p);
}

extern char D_0044BAB0[];

// FUNCTION: GAME 0x2B8B20
extern "C" void func_002B8B20(char *p, int f)
{
    *(char **)(p + 0x18) = D_0044BAB0;
    if (f & 1)
        func_0030F5A0(p);
}


extern char D_0044D1C8[];
extern char D_00451038[];
extern char D_003BAFE0[];

// FUNCTION: GAME 0x139C58
extern "C" void _$_9cPlCamera(char *p, int f)
{
    *(char **)(p + 0x35C) = D_0041D8F8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x2D5CA8
extern "C" void func_002D5CA8(char *p, int f)
{
    *(char **)(p + 0x30) = D_0044D1C8;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x31EE10
extern "C" void func_0031EE10(char *p, int f)
{
    *(char **)(p + 0x4) = D_00451038;
    if (f & 1)
        func_0030F5A0(p);
}

// FUNCTION: GAME 0x372C80
extern "C" void func_00372C80(char *p, int f)
{
    *(char **)(p + 0x80) = D_003BAFE0;
    if (f & 1)
        func_0030F5A0(p);
}
