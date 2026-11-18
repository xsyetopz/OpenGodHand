// Small functions in the ProDG game-code island 0x370000-0x383FFF.

struct Fn37Obj {
    char _pad0[0x30];
    int m_30;
    int m_34;
    char _pad38[0x10];
    int m_48;
    int m_4C;
    char _pad50[8];
    int m_58;
};

extern int D_0076A7A4;
extern int D_0076B080;

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

#ifdef NONMATCHING
// DRAFT: GAME 0x373B20
// diff: 3 words; original emits `slt v0, 1, v1` directly, ours slt + xori
extern "C" int func_00373B20(Fn37Obj *o) { return o->m_58 > 1; }
#endif

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

struct Fn37Flags {
    unsigned short m_0;
};

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

extern "C" void func_003757A0(int, int);
extern "C" void func_00386D70(void);
extern "C" void func_0037BE98(void);
extern "C" void func_00329EA8(void *);
extern "C" void func_0032B300(void *, int);
extern "C" void func_0032A6D0(void *);
extern "C" void func_00336D08(void *);
extern char D_0076C8C0[];

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
        *(int *)(p + 8) = 0;
        *(short *)p = 0;
        *(int *)(p + 0x10) = 0;
        *(int *)(p + 0x14) = 0;
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
extern "C" void func_00374120(void **o)
{
    if (*o)
        func_0032A6D0(*o);
}

// FUNCTION: GAME 0x374148
extern "C" void func_00374148(void **o)
{
    if (*o)
        func_00336D08(*o);
}
