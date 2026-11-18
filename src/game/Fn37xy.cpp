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

struct Fn37Ramp {
    unsigned short m_0;
    unsigned short m_2;
    short m_4;
    short m_6;
};

// FUNCTION: GAME 0x378020
extern "C" void func_00378020(Fn37Ramp *p)
{
    int d = (short)(p->m_2 - p->m_0);
    int q = d / p->m_6;
    p->m_4 = q;
    if ((q << 16) == 0)
        p->m_4 = d > 0 ? 1 : -1;
    p->m_6 = 0;
}

struct Fn37Clamp {
    short m_0;
    short m_2;
    short m_4;
    unsigned short m_6;
};

// FUNCTION: GAME 0x378070
extern "C" void func_00378070(Fn37Clamp *p)
{
    int s = p->m_0 + p->m_4;
    if (p->m_4 > 0) {
        if (p->m_2 < s)
            s = p->m_2;
    } else {
        if (s < p->m_2)
            s = p->m_2;
    }
    p->m_0 = s;
    p->m_6++;
}

// FUNCTION: GAME 0x3780B0
extern "C" short func_003780B0(short a, short b)
{
    int v = a << 8;
    if ((a ^ 0x80) == 0)
        v = 0x7FFF;
    return v * b / 0x7F00;
}

extern "C" void func_00378C48(void *);
extern "C" void func_0037B0E0(void *);
extern "C" void func_00379190(void *);
extern "C" void func_00379BC0(void *);
struct Fn37Sel {
    char _pad[6];
    signed char m_6;
};

// FUNCTION: GAME 0x378BF8
extern "C" void func_00378BF8(Fn37Sel *p)
{
    func_00378C48(p);
    func_0037B0E0(p);
    if (p->m_6 == 0)
        func_00379190(p);
    else
        func_00379BC0(p);
}

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


// FUNCTION: GAME 0x37C160
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

extern "C" void func_0037C160(Fn37Dst2 *d, Fn37Src *s)
{
    d->m_0 = s->m_0;
    d->m_4 = s->m_C;
    d->m_C = 0;
    d->m_5 = s->m_D;
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

#ifdef NONMATCHING
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

// DRAFT: GAME 0x37D170
// diff: 10 words, original is bnel-rotated (p++ in the delay slot, slt after); mine tests slt first.
extern "C" Fn37Slot50 *func_0037D170(void)
{
    Fn37Slot50 *p = D_0076B9C0;
    Fn37Slot50 *e = D_0076B9C0 + 0x30;
    do {
        if (p->m_0 == 0)
            return p;
    } while (p++, (int)p < (int)e);
    return 0;
}

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

struct Fn37Pos {
    char _p0[5];
    unsigned char m_5;
    char _p6[0x28];
    unsigned short m_2E;
    char _p30[0x16];
    unsigned short m_46;
    unsigned short m_48;
    unsigned short m_4A;
};

// DRAFT: GAME 0x37D728
// diff: 1 word, addu operand order (v0,a0,v0 vs v0,v0,a0).
extern "C" void func_0037D728(Fn37Pos *p)
{
    int s = p->m_46 + p->m_48;
    p->m_4A = s;
    if ((p->m_5 & 1) == 0)
        p->m_4A = p->m_2E + s;
}

extern "C" int func_0037E8D8(void *);
struct Fn37B2 {
    char _p0[2];
    char m_2;
};

// DRAFT: GAME 0x37E488
// diff: 4 words, result held in v1 with beqz instead of v0 with bnez.
extern "C" void func_0037E488(Fn37B2 *p)
{
    p->m_2 = func_0037E8D8(p) ? 0xC : 1;
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
