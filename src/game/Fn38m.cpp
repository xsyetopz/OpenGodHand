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

struct Fn38D {
    char _p0[3];
    unsigned char m_3;
    unsigned char m_4;
    char _p5[0x5F];
    int m_64;
    char _p68[0x24];
    int m_8C;
    char _p90[0x14];
    char m_A4[0x20];
    int m_C4;
    char _pC8[4];
    char m_CC[4];
};

extern "C" void func_003849F8(int, Fn38D *, int);

// FUNCTION: GAME 0x384980
extern "C" void func_00384980(int a, Fn38D *p)
{
    if (p->m_3 & 1) {
        if (p->m_C4 != 0) {
            func_003849F8(a, p, p->m_4);
            return;
        }
    } else if (p->m_64 != 0) {
        func_003849F8(a, p, 0);
        return;
    }
    if (p->m_3 & 2)
        func_003849F8(a, p, p->m_4);
    else
        func_003849F8(a, p, 0);
}

extern "C" void func_00384BC8(int, Fn38D *, char *);
extern "C" void func_00384B98(int, int);

// FUNCTION: GAME 0x384B10
extern "C" void func_00384B10(int a, Fn38D *p)
{
    if (p->m_3 & 1) {
        char *q = p->m_A4;
        if (*(int *)(q + 0x20) != 0) {
            func_00384BC8(a, p, q);
            return;
        }
    } else {
        char *v = (char *)p + 0x34;
        if (*(int *)(v + 0x30) != 0) {
            func_00384B98(a, *(int *)(v + 0x20));
            return;
        }
    }
    if (p->m_3 & 2)
        func_00384BC8(a, p, p->m_CC);
    else
        func_00384B98(a, p->m_8C);
}

struct Fn38Ent {
    unsigned short m_0;
    char _p2[2];
    int m_4;
    char m_8;
    char m_9;
    short m_A;
    short m_C;
};
extern "C" unsigned func_00387430(int);
extern "C" Fn38Ent *func_00377998(void);

// FUNCTION: GAME 0x3870E0
extern "C" int func_003870E0(short a)
{
    if (func_00387430(a) & 8)
        return -1;
    Fn38Ent *e = func_00377998();
    if (e == 0)
        return -1;
    e->m_C = a;
    e->m_0 = 1;
    e->m_8 = 0x10;
    e->m_9 = 2;
    e->m_A = 2;
    e->m_4 = 0;
    return 0;
}

extern "C" int func_00329F98(int);
extern "C" int func_0032A4A8(int);
extern "C" int func_0032A530(int);
extern "C" int func_0032A5B8(int);
extern "C" int func_0032A648(int);
extern "C" void func_00380EB0(void *, void *, void *);
struct Fn38E {
    char _p0[2];
    char m_2;
    char _p3[0x46D];
    char m_470[0x4C];
    int m_4BC;
};

// FUNCTION: GAME 0x385138
extern "C" void func_00385138(Fn38E *p)
{
    int *s = (int *)&p->m_4BC;
    if (func_00329F98(s[0x30 / 4]) >= 2) {
        p->m_4BC = func_0032A4A8(s[0x30 / 4]);
        s[1] = func_0032A530(s[0x30 / 4]);
        s[2] = func_0032A5B8(s[0x30 / 4]);
        s[3] = func_0032A648(s[0x30 / 4]);
        func_00380EB0(p, s, p->m_470);
        p->m_2 = 0;
    }
}
