#include "game/cEvCmd.h"

extern unsigned char D_003C2554;
extern unsigned char D_003C2555;

// FUNCTION: GAME 0x2B6598
extern "C" void func_002B6598()
{
    D_003C2555 = 0;
    D_003C2554 = 0;
}

extern unsigned int D_00747A80;

// FUNCTION: GAME 0x2B8978
extern "C" int func_002B8978()
{
    unsigned t = D_00747A80 & 0x10000000;
    return t != 0;
}

extern "C" {
void func_002B4850(int a, unsigned short b);
void func_002B5028(int a, unsigned short b);
void func_002B5AF8(void *movie, int a, int b);
void func_002B5BB8(void *movie, int a, int b);
}
extern int Movie;

// FUNCTION: GAME 0x2B4880
extern "C" void func_002B4880()
{
    func_002B4850(1, 0xFFFF);
}

// FUNCTION: GAME 0x2B5C00
extern "C" void func_002B5C00()
{
    func_002B5028(1, 0xFFFF);
}

// FUNCTION: GAME 0x2B48C8
extern "C" void func_002B48C8(int a, int b)
{
    func_002B5BB8(&Movie, a, b);
}

// FUNCTION: GAME 0x2B45C8
extern "C" void func_002B45C8(cEvCmd *) { }

// FUNCTION: GAME 0x2B45D0
extern "C" void func_002B45D0() { }

// FUNCTION: GAME 0x2B45E8
extern "C" void func_002B45E8() { }

// FUNCTION: GAME 0x2B45F0
extern "C" void func_002B45F0(cEvCmd *) { }

// FUNCTION: GAME 0x2B5F18
extern "C" void func_002B5F18() { }

struct cMsgView {
    char _pad[0xBEE];
    unsigned short m_bee;
};
extern cMsgView *Message;

// FUNCTION: GAME 0x2B1290
extern "C" unsigned short func_002B1290()
{
    return Message->m_bee;
}

extern int D_00747A0C;

// FUNCTION: GAME 0x2B12D8
extern "C" float func_002B12D8()
{
    float r = 26.0f;
    if (D_00747A0C != 0)
        r = 32.0f;
    return r;
}

extern "C" void func_003466A8();

// FUNCTION: GAME 0x2B4BC0
extern "C" void func_002B4BC0(cEvCmd *self)
{
    if (*(unsigned char *)((char *)self + 0x14))
        func_003466A8();
}

// FUNCTION: GAME 0x2B65F0
extern "C" void exitTask__11cNowLoading()
{
    D_003C2555 = 1;
}

// FUNCTION: GAME 0x2B3B40
extern "C" int func_002B3B40(cEvCmd *self)
{
    short v = self->m_data->m_arg + 1;
    if (self->m_96 < v)
        self->m_96 = v;
    return 0;
}
