// Small functions in the ProDG game-code island 0x370000-0x383FFF.
#include "game/Fn37x.h"

// FUNCTION: GAME 0x373A50
extern "C" int func_00373A50(Fn37Obj *o) { return o->m_48; }

// FUNCTION: GAME 0x376508
extern "C" int func_00376508(void) { return 0; }

// FUNCTION: GAME 0x3775E8
extern "C" void func_003775E8(void) {}

// FUNCTION: GAME 0x37A810
extern "C" void func_0037A810(void) {}

// FUNCTION: GAME 0x3756F0
extern "C" int SdeSystemOutModeGet(void) { return D_0076A7A4; }

// FUNCTION: GAME 0x377520
extern "C" void func_00377520(short *o) { o[10] = 1; }

// FUNCTION: GAME 0x373A58
extern "C" int func_00373A58(Fn37Obj *o)
{
    unsigned t = o->m_4C & 2;
    return t != 0;
}

// FUNCTION: GAME 0x373A68
extern "C" int func_00373A68(Fn37Obj *o)
{
    unsigned t = o->m_4C & 0x10;
    return t != 0;
}

// FUNCTION: GAME 0x373B20 (if/return form keeps `slt` instead of slti+xori)
extern "C" int func_00373B20(Fn37Obj *o)
{
    if (o->m_58 > 1)
        return 1;
    return 0;
}

// FUNCTION: GAME 0x3754F0
extern "C" void func_003754F0(Fn37Obj *o) { D_0076B080 = *(int *)((char *)o + 0xA4); }

// FUNCTION: GAME 0x3766F8
extern "C" int func_003766F8(Fn37Obj *o)
{
    o->m_30 = o->m_34;
    return 1;
}

// FUNCTION: GAME 0x3766E0
extern "C" int func_003766E0(Fn37Obj *o)
{
    int v = o->m_30 + 0x10;
    o->m_30 = v;
    o->m_34 = v;
    return 1;
}

// FUNCTION: GAME 0x376708
extern "C" int func_00376708(Fn37Flags *o)
{
    o->m_0 |= 0x1000;
    return 1;
}

// FUNCTION: GAME 0x37D3B0
extern "C" void func_0037D3B0(char *o)
{
    *(short *)o = 0;
    *(int *)(o + 0x10) = 0;
    *(int *)(o + 0x14) = 0;
    *(int *)(o + 8) = 0;
}

// FUNCTION: GAME 0x37C618
extern "C" void func_0037C618(char *a, char *b)
{
    unsigned short f = *(unsigned short *)(a + 6) | 4;
    unsigned short g = *(unsigned short *)(b + 0x3C);
    *(unsigned short *)(a + 0x48) = g;
    *(unsigned short *)(a + 6) = f;
}

// FUNCTION: GAME 0x375840
extern "C" void func_00375840(void) { func_003757A0(1, 0xFFFF); }

// FUNCTION: GAME 0x386D48
extern "C" void func_00386D48(void)
{
    func_00386D70();
    func_0037BE98();
}

// FUNCTION: GAME 0x37C5F8
extern "C" void func_0037C5F8(char *a, char *b)
{
    unsigned short x = *(unsigned short *)(b + 0x34);
    unsigned short f = *(unsigned short *)(a + 6) | 0xA;
    *(unsigned short *)(a + 0x40) = x;
    unsigned short y = *(unsigned short *)(b + 0x36);
    *(unsigned short *)(a + 6) = f;
    *(unsigned short *)(a + 0x42) = y;
}

// FUNCTION: GAME 0x37CEE0
extern "C" void *func_0037CEE0(char *a)
{
    char *e = D_0076C8C0 + (a[6] << 5);
    return *(unsigned short *)e ? 0 : e;
}

// FUNCTION: GAME 0x37D148
extern "C" void func_0037D148(char *a)
{
    char *p = *(char **)(a + 8);
    if (p) {
        *(short *)p = 0;
        *(int *)(p + 0x10) = 0;
        *(int *)(p + 0x14) = 0;
        *(int *)(p + 8) = 0;
    }
}

// FUNCTION: GAME 0x373F78
extern "C" void func_00373F78(void **o)
{
    if (*o)
        func_00329EA8(*o);
}

// FUNCTION: GAME 0x373FA0
extern "C" void func_00373FA0(void **o)
{
    if (*o)
        func_0032B300(*o, 1);
}

// FUNCTION: GAME 0x373FC8
extern "C" void func_00373FC8(void **o)
{
    if (*o)
        func_0032B300(*o, 0);
}

// FUNCTION: GAME 0x374120
extern "C" void func_00374120(void **o, int, int)
{
    if (*o)
        func_0032A6D0(*o);
}

// FUNCTION: GAME 0x374148
extern "C" void func_00374148(void **o, int, int)
{
    if (*o)
        func_00336D08(*o);
}

// FUNCTION: GAME 0x373810
extern "C" void func_00373810(Fn37Obj *o, int m)
{
    if (func_00373A50(o))
        o->m_4C |= m;
}

// FUNCTION: GAME 0x373858
extern "C" void func_00373858(Fn37Obj *o, int m)
{
    if (func_00373A50(o))
        o->m_4C &= ~m;
}

// FUNCTION: GAME 0x373430
extern "C" void func_00373430(Fn37Obj *o)
{
    if (func_00373A50(o)) {
        if (func_00373B20(o) == 1)
            func_00374548(o);
        else
            func_00373F78((void **)o);
    }
}

// FUNCTION: GAME 0x3733C8
extern "C" void func_003733C8(Fn37Obj *o)
{
    if (func_00373A50(o)) {
        if (func_00373B20(o) == 1)
            func_00374318(o);
        else
            func_00373D48(o);
        memset(o, 0, 0x84);
    }
}

// FUNCTION: GAME 0x373488
extern "C" void func_00373488(Fn37Obj *o)
{
    if (func_00373A50(o)) {
        if (func_00373B20(o) == 1)
            func_00374570(o);
        else
            func_00373FA0((void **)o);
        o->m_4C |= 2;
    }
}

// FUNCTION: GAME 0x3734F0
extern "C" void func_003734F0(Fn37Obj *o)
{
    if (func_00373A50(o)) {
        if (func_00373B20(o) == 1)
            func_00374598(o);
        else
            func_00373FC8((void **)o);
        o->m_4C &= 0xFFFFFFFDu;
    }
}

// FUNCTION: GAME 0x373560
extern "C" void func_00373560(Fn37Obj4 *o, float f, int a)
{
    if (func_00373A50((Fn37Obj *)o)) {
        if (func_00373B20((Fn37Obj *)o) == 1)
            func_003745C0(f, o, o->m_54, a);
        else
            func_00373FF0(f, o, o->m_54);
    }
}

// FUNCTION: GAME 0x373690
extern "C" void func_00373690(Fn37Obj *o, int a, int b)
{
    if (func_00373A50(o)) {
        if (o->m_58 >= 2)
            func_00374820(o, b, a);
        else
            func_00374120((void **)o, b, a);
    }
}

// FUNCTION: GAME 0x373708
extern "C" void func_00373708(Fn37Obj *o, int a, int b)
{
    if (func_00373A50(o)) {
        if (func_00373B20(o) != 1)
            func_00374148((void **)o, a, b);
    }
}

// FUNCTION: GAME 0x373770
extern "C" int func_00373770(Fn37Obj *o)
{
    if (func_00373A50(o) == 0)
        return 0;
    if (func_00373B20(o) != 1)
        return func_00374170(o);
    return func_003748A8(o);
}
