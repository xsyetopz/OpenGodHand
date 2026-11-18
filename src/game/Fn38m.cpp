// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn38A {
    char _p0[2];
    unsigned char m_2;
    char _p3[0x35];
    int m_38;
    char _p3C[0xC];
    unsigned char m_48[1];
};

// FUNCTION: GAME 0x3827F0
extern "C" int func_003827F0(int, Fn38A *o)
{
    int i;
    for (i = 0; i < o->m_38; i++) {
        if (i != o->m_2 - 1 && o->m_48[i + 1] != o->m_48[o->m_2])
            return 0;
    }
    return 1;
}

struct Fn38B {
    char _p0[4];
    unsigned char m_4;
    char _p5[0xA7];
    int m_AC;
    char _pB0[0xC];
    unsigned char m_BC[1];
};

// FUNCTION: GAME 0x384138
extern "C" int func_00384138(int, Fn38B *o)
{
    int i;
    for (i = 0; i < o->m_AC; i++) {
        if (i != o->m_4 - 1 && o->m_BC[i + 1] != o->m_BC[o->m_4])
            return 0;
    }
    return 1;
}

extern "C" int func_003244C8(int);
extern "C" int func_0037FD28(void *, void *);
struct Fn38C {
    char _p0[2];
    char m_2;
    char _p3[0x36D];
    char m_370[0xF4];
    int m_464;
};

// FUNCTION: GAME 0x3837E8
extern "C" void func_003837E8(Fn38C *p)
{
    char *q = p->m_370;
    if (func_003244C8(*(int *)(q + 0xF4)) == 3) {
        if (func_0037FD28(p, q))
            p->m_2 = 0;
        else
            p->m_2 = 2;
    }
}

extern "C" void func_00383708(Fn38C *);
extern "C" void func_00383848(Fn38C *);

// FUNCTION: GAME 0x383690
extern "C" void func_00383690(Fn38C *p)
{
    switch ((unsigned char)p->m_2) {
    case 0:
        func_00383708(p);
        break;
    case 1:
        func_003837E8(p);
        break;
    case 2:
        func_00383848(p);
        break;
    }
}
