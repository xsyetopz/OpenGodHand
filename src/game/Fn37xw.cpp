// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

extern char SoundHeap[];
extern "C" void func_003298C0(int);
extern "C" void func_0032D6F0(int);
extern "C" void func_0031C928(int, void *);

struct Fn37W {
    char _pad0[0x4C];
    int m_4C;
};
extern "C" int func_00373A50(Fn37W *o);

struct Fn37Pair {
    int m_0;
    int m_4;
};

// FUNCTION: GAME 0x3737C8
extern "C" int func_003737C8(Fn37W *o, int mask)
{
    if (func_00373A50(o) == 0)
        return 0;
    return (o->m_4C & mask) != 0;
}

// FUNCTION: GAME 0x373D48
extern "C" void func_00373D48(Fn37Pair *o)
{
    if (o->m_0 != 0) {
        func_003298C0(o->m_0);
        func_0031C928(o->m_4, SoundHeap);
    }
}

// FUNCTION: GAME 0x374318
extern "C" void func_00374318(Fn37Pair *o)
{
    if (o->m_0 != 0) {
        func_0032D6F0(o->m_0);
        func_0031C928(o->m_4, SoundHeap);
    }
}

struct Fn37Init {
    char _pad0[0x48];
    int m_48;
    int m_4C;
    char _pad50[0x1C];
    int m_6C;
    int m_70;
    int m_74;
    int m_78;
    int m_7C;
};

// FUNCTION: GAME 0x373118
extern "C" int func_00373118(Fn37Init *o, int a, int *p, int flag)
{
    o->m_48 = 1;
    o->m_74 = a;
    o->m_7C = p[2];
    o->m_6C = p[1];
    o->m_4C |= 1;
    if (flag != 0)
        o->m_4C |= 0x10;
    return 1;
}

extern "C" int func_0037D1A8(int, int);
extern "C" int func_0037D060(int);
extern "C" int func_0037D220(int, int);
extern "C" int func_0037D100(int);

// FUNCTION: GAME 0x3750E0
extern "C" int func_003750E0(int a)
{
    return func_0037D1A8(1, a) != 0 ? 1 : (func_0037D060(a) != 0 ? 2 : 0);
}

// FUNCTION: GAME 0x375128
extern "C" int func_00375128(short a)
{
    return func_0037D220(1, a) != 0 ? 1 : (func_0037D100((unsigned short)a) != 0 ? 2 : 0);
}

struct Fn37Vec7 {
    int m_0, m_4, m_8, m_C, m_10, m_14, m_18;
};
extern Fn37Vec7 D_0076B580;
struct Fn37Dst {
    char _pad[0xA8];
    int m_A8, m_AC, m_B0, m_B4, m_B8, m_BC, m_C0;
};

// FUNCTION: GAME 0x3754A8
extern "C" void func_003754A8(Fn37Dst *o)
{
    o->m_A8 = D_0076B580.m_0;
    o->m_AC = D_0076B580.m_4;
    o->m_B0 = D_0076B580.m_8;
    o->m_B4 = D_0076B580.m_C;
    o->m_B8 = D_0076B580.m_10;
    o->m_BC = D_0076B580.m_14;
    o->m_C0 = D_0076B580.m_18;
}

struct Fn37Ent {
    int w[8];
};
extern Fn37Ent D_0076A7D4[];

// FUNCTION: GAME 0x374980
extern "C" void func_00374980(short i, Fn37Ent *out)
{
    *out = D_0076A7D4[i];
}
