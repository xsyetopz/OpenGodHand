// FUNCTION: GAME 0x3312B0
extern "C" signed char func_003312B0(signed char *p)
{
    return p[2];
}

// FUNCTION: GAME 0x333168
extern "C" int func_00333168()
{
    return 0x800;
}

// FUNCTION: GAME 0x3332A8
extern "C" int func_003332A8()
{
    return 0;
}

// FUNCTION: GAME 0x334AC8
extern "C" int func_00334AC8()
{
    return 0x800;
}

// FUNCTION: GAME 0x3355C0
extern "C" void func_003355C0(int *p, int v)
{
    p[10] = v;
}

// FUNCTION: GAME 0x335CD8
extern "C" void func_00335CD8()
{
}

// FUNCTION: GAME 0x335CE0
extern "C" void func_00335CE0()
{
}

// FUNCTION: GAME 0x335DD0
extern "C" void func_00335DD0()
{
}

// FUNCTION: GAME 0x335DD8
extern "C" void func_00335DD8()
{
}

// FUNCTION: GAME 0x336498
extern "C" void func_00336498()
{
}

struct S20 { char _p[0x20]; int m_20; int m_24; };
struct S0 { int m_0; int m_4; };

// FUNCTION: GAME 0x332378
extern "C" void func_00332378(S20 *s, int a, int b)
{
    s->m_20 = a;
    s->m_24 = b;
}

// FUNCTION: GAME 0x330910
extern "C" void func_00330910(S0 *s)
{
    s->m_4 = 0;
    s->m_0 = 0;
}
