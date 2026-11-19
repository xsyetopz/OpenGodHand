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

// FUNCTION: GAME 0x37D0A8
// The for-loop form duplicates the bound test on the continue path, as the original does.
extern "C" Fn37Slot20 *func_0037D0A8(int a)
{
    Fn37Slot20 *p = D_0076C8C0;
    for (int i = 0; i < 0x33; i++, p++)
        if (p->m_0 != 0 && (p->m_5 & 1) == 0 && p->m_14 == a)
            return p;
    return 0;
}

// FUNCTION: GAME 0x37CA98
// The named -1 constant is loaded before the loop counter, as the original orders them.
extern "C" void func_0037CA98(void)
{
    Fn37Slot20 *p = D_0076C8C0;
    unsigned k = 0xFFFFFFFF;
    int n = 0x32;
    for (; n >= 0; n--, p++) {
        if (p->m_0 != 0 && p->m_C != k)
            p->m_C++;
    }
}

struct Fn37Slot50 {
    unsigned short m_0;
    char _p2[0x4E];
};
extern Fn37Slot50 D_0076B9C0[];
extern Fn37Slot50 D_0076CF20[];

// FUNCTION: GAME 0x37D2D8
extern "C" Fn37Slot50 *func_0037D2D8(void)
{
    int p = (int)D_0076CF20;
    int e = p + 0xFF0;
    do {
        if (*(unsigned short *)p != 0) { p += 0x50; continue; }
        return (Fn37Slot50 *)p;
    } while (p < e);
    return 0;
}

#ifdef NONMATCHING
extern int D_0076A7AC;
extern void (*const D_003F2810[])(int);

// DRAFT: GAME 0x37D298
// diff: 8 words, idx/table reg order (a1/v1/v0); tried int/unsigned idx temp, fnptr temp, ptr-to-table temp, non-const table, int-arith index, raw byte-offset, int-array cast, int temp with pointer cast, pointer temp with t + idx (all 8)
extern "C" void func_0037D298(char a)
{
    D_003F2810[D_0076A7AC](a);
}
#endif

extern "C" void func_00329EA8(int);
extern "C" void func_0032B300(int, int);
extern "C" void func_003298C0(int);
extern "C" void func_0031C900(int);
struct Fn38Obj30 {
    char _p0[0x30];
    int m_30;
    int m_34;
};

// FUNCTION: GAME 0x380EB0
extern "C" void func_00380EB0(int, Fn38Obj30 *o, unsigned char *f)
{
    func_00329EA8(o->m_30);
    if (*f) {
        *f = 0;
        func_0032B300(o->m_30, 0);
    }
    func_003298C0(o->m_30);
    o->m_30 = 0;
    func_0031C900(o->m_34);
}

extern "C" void func_0032DB70(int);
extern "C" void func_0032E040(int, int);
extern "C" void func_0032D6F0(int);
struct Fn38Obj20 {
    char _p0[0x20];
    int m_20;
    int m_24;
};

// FUNCTION: GAME 0x381D60
extern "C" void func_00381D60(int, Fn38Obj20 *o, unsigned char *f)
{
    func_0032DB70(o->m_20);
    if (*f) {
        *f = 0;
        func_0032E040(o->m_20, 0);
    }
    func_0032D6F0(o->m_20);
    o->m_20 = 0;
    func_0031C900(o->m_24);
}

struct Fn38Cur {
    char _p0[4];
    unsigned char m_4;
};
struct Fn38Pad {
    char _p0[0x38];
    unsigned m_38;
};

// FUNCTION: GAME 0x381010
extern "C" void func_00381010(Fn38Cur *c, Fn38Pad *p, unsigned char n)
{
    if (p->m_38 & 0x1000) {
        if (c->m_4)
            c->m_4--;
        else
            c->m_4 = n;
    }
    if (p->m_38 & 0x4000) {
        if (c->m_4 < n)
            c->m_4++;
        else
            c->m_4 = 0;
    }
}

extern "C" void func_0031CB80(short *, int, int);

// FUNCTION: GAME 0x380678
extern "C" void func_00380678(int, short x, short y, int a, int b)
{
    short r[8];
    r[0] = x;
    r[1] = y;
    r[2] = x + 0xC8;
    r[3] = y;
    r[4] = x;
    r[5] = y + 8;
    r[6] = x + 0xC8;
    r[7] = y + 8;
    func_0031CB80(r, a, b);
}
