// Mid-size functions in the ProDG game-code island 0x370000-0x387430 (continued from Fn38i.cpp).

struct Fn38Sl { char _p0[4]; int m_04; int m_08; int m_0C; char _p10[0x20]; int m_30; };
extern "C" int func_00329F98(int);
extern "C" int func_0032A4A8(int);
extern "C" int func_0032A530(int);
extern "C" int func_0032A5B8(int);
extern "C" int func_0032A648(int);
extern "C" void func_00380EB0(void *, void *, void *);

// FUNCTION: GAME 0x37FAC8
extern "C" void func_0037FAC8(unsigned char *o)
{
    unsigned char *b = o + (o[5] * 0x48 + 0x48);
    Fn38Sl *s = (Fn38Sl *)(b + 0x10);
    if (func_00329F98(s->m_30) >= 2) {
        *(int *)(b + 0x10) = func_0032A4A8(s->m_30);
        s->m_04 = func_0032A530(s->m_30);
        s->m_08 = func_0032A5B8(s->m_30);
        s->m_0C = func_0032A648(s->m_30);
        func_00380EB0(o, s, b);
        o[2] = 1;
    }
}

struct Fn38Sm { int m_00; int m_04; int m_08; int m_0C; int m_10; char _p14[0xC]; int m_20; };
extern "C" int func_0032DCD0(int, int);
extern "C" int func_0032E118(int);
extern "C" int func_0032E1F0(int);
extern "C" int func_0032E280(int);
extern "C" int func_0032E310(int);
extern "C" void func_00381D60(void *, void *, void *);

// FUNCTION: GAME 0x37FB70
extern "C" void func_0037FB70(unsigned char *o)
{
    Fn38Sm *s = (Fn38Sm *)(o + 0x348);
    unsigned char *t = o + 0x318;
    int h = func_0032DCD0(s->m_20, 0);
    if (func_00329F98(h) == 2) {
        s->m_00 = func_0032E118(s->m_20);
        s->m_04 = func_0032A530(h);
        s->m_08 = func_0032E1F0(s->m_20);
        s->m_0C = func_0032E280(s->m_20);
        s->m_10 = func_0032E310(s->m_20);
        func_00381D60(o, s, t);
        o[2] = 1;
    }
}

#ifdef NONMATCHING
struct Fn38Mo { char _p0[7]; signed char m_07; char _p08[0x0E]; short m_16[3]; short m_1C[3]; char _p22[3]; };
extern "C" void SdeIssTblGet(int, int, void *);
extern "C" void func_00386DE0(int, int, void *);
extern "C" void func_00375AB0(int, int, void *);

// DRAFT: GAME 0x37A1F0
// diff: 37 words; original copies p into v1 and loads a in the beq delay slots (ours emits nops)
extern "C" void func_0037A1F0(char *o)
{
    int k = o[7];
    char *p = o + k * 2;
    int b = *(short *)(p + 0x1C);
    int a = *(short *)(p + 0x16);
    switch (k) {
    case 0:
        SdeIssTblGet(a, b, o + 0x9C);
        break;
    case 1:
        func_00386DE0(a, b, o + 0xCC);
        break;
    case 2:
        func_00375AB0(a, b, o + 0x12C);
        break;
    }
    o[0x25] = o[o[7] + 0x22];
}
#endif

struct Fn38Pa { char _p0[0x27]; unsigned char m_27; unsigned char m_28; char _p29[0xB]; unsigned m_34; unsigned m_38; };
extern "C" void func_0037B720(Fn38Pa *);
extern "C" void func_0037B768(Fn38Pa *);
extern "C" int func_00379EC0(Fn38Pa *);
extern "C" void func_0037A1F0(char *);
extern "C" int func_0037A4C8(Fn38Pa *);
extern "C" int func_0037B798(Fn38Pa *);
extern "C" void func_0037B808(Fn38Pa *);
extern "C" void func_0037A298(Fn38Pa *);

// FUNCTION: GAME 0x37B660
extern "C" void func_0037B660(Fn38Pa *o)
{
    if (o->m_38 & 4) {
        unsigned t = o->m_27;
        o->m_28 = 0;
        o->m_27 = t ^ 1;
    } else if (o->m_34 & 0x10) {
        func_0037B720(o);
    } else if (o->m_34 & 0x80) {
        func_0037B768(o);
    } else if (func_00379EC0(o) == 0) {
        func_0037A1F0((char *)o);
        if (func_0037A4C8(o) == 0 && func_0037B798(o) == 0)
            func_0037B808(o);
        func_0037A298(o);
    }
}

#ifdef NONMATCHING
struct Fn38In { unsigned short m_00; char _p02[2]; unsigned char m_04; unsigned char m_05; char _p06[0xA]; int m_10; int m_14; unsigned short m_18, m_1A, m_1C, m_1E, m_20, m_22; char _p24[0x26]; unsigned short m_4A, m_4C, m_4E; };
struct Fn38Ou { unsigned short m_00; unsigned char m_02; unsigned char m_03; int m_04; int m_08; unsigned short m_0C, m_0E, m_10, m_12, m_14, m_16, m_18, m_1A, m_1C; char _p1E[2]; };
extern Fn38In D_0076CF20[];
extern Fn38Ou D_0076A9C0[];

// DRAFT: GAME 0x37CE20
// diff: 33 words; swapping s/o decl order gives 35; lui order of the two table bases and bnel delay-slot fill differ (original puts else-path lbu in the delay slot, ours the i-- ; while-loop form did not change it)
extern "C" void func_0037CE20(void)
{
    Fn38Ou *o = D_0076A9C0;
    Fn38In *s = D_0076CF20;
    int i;
    for (i = 0x2F; i >= 0; i--) {
        if (s->m_00 == 0) {
            o->m_00 = 0;
            o->m_04 = 0;
            o->m_08 = 0;
        } else {
            o->m_00 = s->m_00;
            o->m_02 = s->m_04;
            o->m_03 = s->m_05;
            o->m_04 = s->m_10;
            o->m_08 = s->m_14;
            o->m_0C = s->m_1C;
            o->m_0E = s->m_1E;
            o->m_10 = s->m_20;
            o->m_12 = s->m_18;
            o->m_14 = s->m_1A;
            o->m_16 = s->m_22;
            o->m_18 = s->m_4A;
            o->m_1A = s->m_4C;
            o->m_1C = s->m_4E;
        }
        o++;
        s++;
    }
}
#endif

extern "C" void *memset(void *, int, unsigned);

// FUNCTION: GAME 0x374D98
extern "C" void func_00374D98(short a, short b, short *p)
{
    memset(p, 0, 0x30);
    p[1] = b;
    p[0] = a;
    ((unsigned short *)p)[7] = 0x8000;
}

// FUNCTION: GAME 0x386F38
extern "C" void func_00386F38(short a, short b, short *p)
{
    memset(p, 0, 0x60);
    p[1] = b;
    p[0] = a;
    ((unsigned short *)p)[7] = 0x8000;
}

struct Fn38Hd { int m_00; };
extern "C" int func_00373A50(void *);
extern "C" int func_0032DCD0(int, int);

// FUNCTION: GAME 0x373B30
extern "C" int func_00373B30(char *o)
{
    if (func_00373A50(o) == 0)
        return 0;
    return *(int *)(o + 0x58);
}

// FUNCTION: GAME 0x374170
extern "C" int func_00374170(Fn38Hd *o)
{
    if (o->m_00 == 0)
        return 0;
    return func_00329F98(o->m_00);
}

// FUNCTION: GAME 0x374928
extern "C" int func_00374928(Fn38Hd *o)
{
    if (o->m_00 == 0)
        return 0;
    return ((int (*)(int))func_0032DCD0)(o->m_00);
}

struct Fn38Sx { unsigned short m_00; short m_02; int m_04; char _p08[0xA]; short m_12; };
// FUNCTION: GAME 0x3761D0
extern "C" void func_003761D0(char *o)
{
    Fn38Sx *p = (Fn38Sx *)(o + 0x40);
    int i;
    for (i = 0; i < 8; i++) {
        p->m_02 = i;
        p->m_00 = 0;
        p->m_04 = 0;
        p->m_12 = 0;
        p++;
    }
}

struct Fn38Cp { char b[16]; } __attribute__((packed));
extern Fn38Cp D_0076A7B8;

// FUNCTION: GAME 0x375600
extern "C" void SdeSystemVolGet(Fn38Cp *d)
{
    *d = D_0076A7B8;
}
