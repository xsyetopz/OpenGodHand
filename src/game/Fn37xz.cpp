// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn37Slot20 {
    unsigned short m_0;
    char _p2[3];
    unsigned char m_5;
    char _p6[6];
    unsigned int m_C;
    int m_10;
    int m_14;
    char _p18[2];
    short m_1A;
    char _p1C[4];
};
extern Fn37Slot20 D_0076C8C0[];

// FUNCTION: GAME 0x37D060
extern "C" Fn37Slot20 *func_0037D060(int a)
{
    Fn37Slot20 *p = D_0076C8C0;
    int i = 0;
    do {
        i++;
        if (p->m_0 == 0)
            continue;
        if (p->m_10 == a)
            return p;
    } while (p++, i < 0x33);
    return 0;
}

// FUNCTION: GAME 0x37D100
extern "C" Fn37Slot20 *func_0037D100(unsigned short a)
{
    Fn37Slot20 *p = D_0076C8C0;
    int i = 0;
    do {
        i++;
        if (p->m_0 == 0)
            continue;
        if (p->m_1A == a)
            return p;
    } while (p++, i < 0x33);
    return 0;
}


struct Fn37Src {
    unsigned short m_0;
    char _p2[2];
    int m_4;
    int m_8;
    unsigned char m_C;
    unsigned char m_D;
    char _pE[4];
    unsigned short m_12;
    char _p14[0xC];
    unsigned short m_20;
    unsigned short m_22;
    char _p24[4];
    unsigned char m_28;
    char _p29[0x1F];
    unsigned short m_48;
};
struct Fn37Dst2 {
    unsigned short m_0;
    char _p2[2];
    unsigned char m_4;
    unsigned char m_5;
    unsigned short m_6;
    char _p8[4];
    int m_C;
    int m_10;
    int m_14;
    unsigned short m_18;
    unsigned short m_1A;
    unsigned short m_1C;
    unsigned char m_1E;
};

// FUNCTION: GAME 0x37C160
extern "C" void func_0037C160(Fn37Dst2 *d, Fn37Src *s)
{
    d->m_0 = s->m_0;
    d->m_4 = s->m_C;
    d->m_5 = s->m_D;
    d->m_C = 0;
    d->m_10 = s->m_4;
    d->m_14 = s->m_8;
    d->m_18 = s->m_12;
    d->m_1A = s->m_20;
    d->m_1C = s->m_22;
    d->m_1E = s->m_28;
    d->m_6 = s->m_48;
}

extern "C" void func_0037C388(void *);
extern "C" void func_0037C420(void *);
extern "C" void func_0037C4C0(void *);
struct Fn37Sw {
    char _p0[0xE];
    short m_E;
    short m_10;
};

// FUNCTION: GAME 0x37C330
extern "C" int func_0037C330(Fn37Sw *p)
{
    if (p->m_E == 0) {
        if (p->m_10 == 0)
            func_0037C388(p);
        else
            func_0037C420(p);
    } else {
        func_0037C4C0(p);
    }
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x37D0A8
// diff: 2 words, the continue path jumps to a shared slti in the delay slot instead of the original's nop plus duplicated slti.
extern "C" Fn37Slot20 *func_0037D0A8(int a)
{
    Fn37Slot20 *p = D_0076C8C0;
    int i = 0;
    do {
        i++;
        if (p->m_0 != 0 && (p->m_5 & 1) == 0 && p->m_14 == a)
            return p;
    } while (p++, i < 0x33);
    return 0;
}

// DRAFT: GAME 0x37CA98
// diff: 2 words, lui/ori -1 constant and li 0x32 swapped.
extern "C" void func_0037CA98(void)
{
    int n = 0x32;
    Fn37Slot20 *p = D_0076C8C0;
    for (; n >= 0; n--, p++) {
        if (p->m_0 != 0 && p->m_C != 0xFFFFFFFF)
            p->m_C++;
    }
}

struct Fn37Slot50 {
    unsigned short m_0;
    char _p2[0x4E];
};
extern Fn37Slot50 D_0076B9C0[];
extern Fn37Slot50 D_0076CF20[];

// DRAFT: GAME 0x37D2D8
// diff: 10 words, same as 0x37D170.
extern "C" Fn37Slot50 *func_0037D2D8(void)
{
    Fn37Slot50 *p = D_0076CF20;
    Fn37Slot50 *e = D_0076CF20 + 0x33;
    do {
        if (p->m_0 == 0)
            return p;
    } while (p++, (int)p < (int)e);
    return 0;
}

extern int D_0076A7AC;
extern void (*const D_003F2810[])(int);

// DRAFT: GAME 0x37D298
// diff: 8 words, index load vs table address order.
extern "C" void func_0037D298(char a)
{
    D_003F2810[D_0076A7AC](a);
}
#endif
