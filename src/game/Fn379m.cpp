// Small functions in the ProDG game-code island (ee-gcc2.95.3-136, C++).

extern "C" int func_00379F00(void *);
extern "C" int func_0037A020(void *);

// FUNCTION: GAME 0x379EC0
extern "C" int func_00379EC0(void *p)
{
    if (func_00379F00(p))
        return 1;
    return func_0037A020(p);
}

extern "C" void func_0037B660(void *);
extern "C" void func_0037B0E0(void *);
extern "C" void func_0037B918(void *);
extern "C" void func_0037BC90(void *);

// FUNCTION: GAME 0x37B620
extern "C" void func_0037B620(void *p)
{
    func_0037B660(p);
    func_0037B0E0(p);
    func_0037B918(p);
    func_0037BC90(p);
}

struct Fn379A {
    char _p0[0xC];
    int m_C;
    char _p10[0x11C];
    char m_12C[8];
};
struct Fn379S {
    char _p0[7];
    char m_7;
    int low() { return m_7 < 0x29; }
};
extern "C" int func_00375BF0(void);

#ifdef NONMATCHING
// DRAFT: GAME 0x37A668
// diff: ~2 words; the original keeps a0 = this+0x12C and loads 7(a0), ours folds to lb 0x133(s0)
extern "C" void func_0037A668(Fn379A *p)
{
    Fn379S *q = (Fn379S *)p->m_12C;
    if (q->low())
        p->m_C = func_00375BF0();
}
#endif

struct Fn379B {
    char _p0[0x28];
    char m_28;
    char m_29;
    char _p2A[0x142];
    char m_16C[0x20];
    char m_18C[0x20];
};
extern "C" void func_00374980(int, void *);

// FUNCTION: GAME 0x37B5E0
extern "C" void func_0037B5E0(Fn379B *p)
{
    func_00374980(0, p->m_16C);
    func_00374980(1, p->m_18C);
    p->m_28 = 0;
    p->m_29 = 0;
}

struct Fn379C {
    char _p0[0x80];
    char *m_80;
};
extern char D_003BAFE0[];

// FUNCTION: GAME 0x372C68
extern "C" Fn379C *func_00372C68(Fn379C *p)
{
    p->m_80 = D_003BAFE0;
    return p;
}

extern int D_003F2160[];

// FUNCTION: GAME 0x374AE0
extern "C" int func_00374AE0(short i)
{
    return D_003F2160[i];
}

struct Fn379D {
    char _p0[0x27];
    char m_27;
    char _p28;
    char m_29;
};
extern "C" void func_003749D8(int, void *);

// FUNCTION: GAME 0x37B720
extern "C" void func_0037B720(Fn379D *p)
{
    if (p->m_29) {
        func_003749D8(p->m_27, (char *)p + 0x16C + p->m_27 * 0x20);
        p->m_29 = 0;
    }
}

struct Fn379E {
    unsigned short m_0;
    char _p2[0x12];
    short m_14;
};
extern "C" void func_003775F0(Fn379E *);
extern "C" void func_00377700(Fn379E *);

// FUNCTION: GAME 0x377598
extern "C" void func_00377598(Fn379E *p)
{
    unsigned short f = p->m_0;
    if (!(f & 0x8000)) {
        if (f & 8) {
            p->m_14 = 3;
            return;
        }
        func_003775F0(p);
    }
    func_00377700(p);
}

struct Fn379F {
    unsigned short m_0;
    char _p2[2];
    int m_4;
    char _p8[0xD8];
};
extern Fn379F D_00770850[];

// FUNCTION: GAME 0x376A90
extern "C" Fn379F *func_00376A90(int id)
{
    Fn379F *e = D_00770850;
    Fn379F *end = D_00770850 + 0x2A00 / 0xE0;
    do {
        if (e->m_0) {
            if (id == 0)
                return e;
            if (e->m_4 == id)
                return e;
        }
        e++;
    } while ((int)e < (int)end);
    return 0;
}

struct Fn379G {
    char _p0[0x10];
    int m_10;
};
extern "C" int func_00373A50(Fn379G *);
extern "C" void func_00373B20(Fn379G *);

#ifdef NONMATCHING
// DRAFT: GAME 0x373B68
// diff: 1 word (2 probes: int r=1 ternary, r=1 then r=p->m_10 both no help); the original has a dead `addiu v1, zero, 1` before the lw
extern "C" int func_00373B68(Fn379G *p)
{
    if (!func_00373A50(p))
        return 0;
    func_00373B20(p);
    return p->m_10;
}
#endif
