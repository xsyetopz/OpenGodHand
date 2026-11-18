// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

extern int D_0076A7A4;
extern "C" void func_0032BA30(int);
extern "C" void func_00375DE0(short, short);
extern "C" void func_00375E78(void);

struct Fn37Ent40 {
    unsigned short m_0;
    char _pad[0x3E];
};
extern Fn37Ent40 D_0076F050[];

struct Fn37Ent70 {
    unsigned short m_0;
    char _pad[0x6E];
};
extern Fn37Ent70 D_0076E590[];

// FUNCTION: GAME 0x375700
extern "C" void SdeSystemOutModeSet(int a)
{
    if (a == 0)
        func_0032BA30(1);
    else
        func_0032BA30(0);
    D_0076A7A4 = a;
}

// FUNCTION: GAME 0x375D98
extern "C" void func_00375D98(int a, short b, short c)
{
    if (a == 0)
        func_00375DE0(b, c);
    else
        func_00375E78();
}

// FUNCTION: GAME 0x376978
extern "C" Fn37Ent40 *func_00376978(void)
{
    for (int i = 0; i < 0x60; i++) {
        if (D_0076F050[i].m_0 == 0)
            return &D_0076F050[i];
    }
    return 0;
}

// FUNCTION: GAME 0x377998
extern "C" Fn37Ent70 *func_00377998(void)
{
    for (int i = 0; i < 8; i++) {
        if (D_0076E590[i].m_0 == 0)
            return &D_0076E590[i];
    }
    return 0;
}
