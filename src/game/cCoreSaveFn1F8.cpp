#include "game/cCoreSave.h"

// Small unnamed functions in 0x1F8000-0x1FFFFF.

extern "C" {
void func_001FC758(int, int);
void func_001FDEA8();
void func_001FE428(int, int);
void func_001FF780(int, int);
void func_001FFDB0(int, int);
}

// FUNCTION: GAME 0x1FD528
extern "C" void func_001FD528()
{
}

// FUNCTION: GAME 0x1FFE00
extern "C" void func_001FFE00()
{
}

// FUNCTION: GAME 0x1FFE08
extern "C" void func_001FFE08(short *p)
{
    *p = 0;
}

// FUNCTION: GAME 0x1FE348
extern "C" void func_001FE348(char *p, int v)
{
    *(int *)(p + 0x8000 + 0x2CD0) = v;
}

// FUNCTION: GAME 0x1FE6B8
extern "C" int *func_001FE6B8(int *p, int a, int b)
{
    p[1] = b;
    p[2] = a;
    return p;
}

// FUNCTION: GAME 0x1FC7F8
extern "C" void func_001FC7F8(int *p)
{
    p[10] = 0;
    *(short *)((char *)p + 0x30) = 0;
    p[8] = 0;
    p[9] = 0;
}

// FUNCTION: GAME 0x1FFD98
extern "C" int func_001FFD98(int, unsigned char *p)
{
    return (*(unsigned short *)(p + 2) + (p[1] << 16)) << 4;
}

// FUNCTION: GAME 0x1FDF88
extern "C" void func_001FDF88()
{
    func_001FDEA8();
}

// FUNCTION: GAME 0x1FF090
extern "C" void func_001FF090(int *p)
{
    int v = p[1];
    if (v >= 0)
        p[1] = v + 1;
    p[0] = 3;
}

// FUNCTION: GAME 0x1FC100
extern "C" void func_001FC100(cCoreSave *self, unsigned char v)
{
    if (self->m_save) {
        *((unsigned char *)self->m_save + 0xAE) = v;
        *((unsigned char *)self->m_save + 0xAF) = v;
    }
}

// FUNCTION: GAME 0x1FC7A8
extern "C" void func_001FC7A8()
{
    func_001FC758(1, 0xFFFF);
}

// FUNCTION: GAME 0x1FE698
extern "C" void func_001FE698()
{
    func_001FE428(1, 0xFFFF);
}

// FUNCTION: GAME 0x1FF7E0
extern "C" void func_001FF7E0()
{
    func_001FF780(1, 0xFFFF);
}

// FUNCTION: GAME 0x1FFDE0
extern "C" void func_001FFDE0()
{
    func_001FFDB0(1, 0xFFFF);
}
