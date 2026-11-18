extern "C" void func_003079C8(int, int);
extern "C" void func_00308EE8(int, int);
extern "C" void func_0030E568(int, int);
extern "C" void func_0030EE68(int, int);
void EmitterAllKill();
void EspAllKill();
extern int D_00747A10;

enum eEffDataType { eEffDataType_0 = 0 };

class espSys {
public:
    void effDataRegist(eEffDataType, void *);
    void effDataRelease(eEffDataType);
};
extern "C" void func_00305908(espSys *, eEffDataType, void *);
extern "C" void func_003059A8(espSys *, eEffDataType, int);

// FUNCTION: GAME 0x307A40
extern "C" void func_00307A40() { func_003079C8(1, 0xFFFF); }

// FUNCTION: GAME 0x308EF8
extern "C" void func_00308EF8() { func_00308EE8(1, 0xFFFF); }

// FUNCTION: GAME 0x30E598
extern "C" void func_0030E598() { func_0030E568(1, 0xFFFF); }

// FUNCTION: GAME 0x30EEC8
extern "C" void func_0030EEC8() { func_0030EE68(1, 0xFFFF); }

// FUNCTION: GAME 0x305B90
extern "C" void func_00305B90()
{
    EmitterAllKill();
    EspAllKill();
}

#ifdef NONMATCHING
// DRAFT: GAME 0x307118
// 8 words differ: gcc folds the compare to xor/sltiu; the original uses bne with a delay-slot clear
extern "C" int func_00307118(unsigned int *p)
{
    if (*p == 0xCDCDCDCD)
        return 1;
    return 0;
}
#endif

// FUNCTION: GAME 0x30D168
void SetEventFrame(int a)
{
    if (a < 2)
        D_00747A10 = 2;
    else
        D_00747A10 = a;
}

// FUNCTION: GAME 0x305758
void espSys::effDataRegist(eEffDataType t, void *p)
{
    func_00305908(this, t, p);
}

// FUNCTION: GAME 0x305778
void espSys::effDataRelease(eEffDataType t)
{
    func_003059A8(this, t, 0);
}

struct EmWork {
    char _pad0[0xF0];
    void *m_vt;
};
extern "C" void *func_00302790(void *);
extern "C" void func_003028E8(EmWork *, int);
extern "C" void func_002FBE28(EmWork *, int);
extern char D_0044FC38[];
extern char D_0044FDF8[];

// FUNCTION: GAME 0x304DF0
extern "C" void *func_00304DF0(EmWork *p)
{
    if (p) {
        func_00302790(p);
        p->m_vt = D_0044FC38;
    }
    return p;
}

// FUNCTION: GAME 0x305290
extern "C" void func_00305290(EmWork *p, int a)
{
    p->m_vt = D_0044FC38;
    func_003028E8(p, a);
}

// FUNCTION: GAME 0x3052C0
extern "C" void func_003052C0(EmWork *p, int a)
{
    p->m_vt = D_0044FDF8;
    func_002FBE28(p, a);
}

class cIDParam {
public:
    cIDParam();
    void initialize();
};

// FUNCTION: GAME 0x308F18
cIDParam::cIDParam()
{
    initialize();
}

extern "C" void func_00309028(void *);

// FUNCTION: GAME 0x309000
extern "C" void *func_00309000(void *p)
{
    func_00309028(p);
    return p;
}

class cHeap {
public:
    void free(void *);
};

// FUNCTION: GAME 0x30F5A0
extern "C" void func_0030F5A0(void *p)
{
    if (p)
        (*(cHeap **)((char *)p - 0x20))->free(p);
}

// FUNCTION: GAME 0x30F5C8
extern "C" void func_0030F5C8(void *p)
{
    if (p)
        (*(cHeap **)((char *)p - 0x20))->free(p);
}

struct Slot306 {
    char _pad0[0xA];
    unsigned short m_cnt;
};
struct Tbl306 {
    char _pad0[0x300];
    Slot306 *m_slot[32];
};

// FUNCTION: GAME 0x306ED8
extern "C" short func_00306ED8(Tbl306 *t, int i)
{
    Slot306 *s;
    if (i >= 32 || (s = t->m_slot[i]) == 0)
        return -1;
    s->m_cnt++;
    return s->m_cnt;
}

#ifdef NONMATCHING
extern "C" unsigned int func_0030F348();

// DRAFT: GAME 0x30F518
// 9 words differ: original loads the 2^-31 constant after the cvt.s.w, ours before the mtc1
extern "C" float func_0030F518()
{
    float r = (float)(int)(func_0030F348() >> 1);
    return r * 4.656613e-10f;
}

// DRAFT: GAME 0x309D40
// 17 words differ: ceil-log2 loop; original shares the v0=1 exit, ours duplicates it
extern "C" int func_00309D40(int a)
{
    int i = 31;
    if (a >= 0) {
        i--;
        while (i > 0 && !((a >> i) & 1))
            i--;
    }
    return i + ((1 << i) < a);
}
#endif
