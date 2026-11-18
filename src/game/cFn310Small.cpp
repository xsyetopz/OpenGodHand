// Small unnamed functions in 0x310000-0x31FFFF.
class cHeap {
public:
    void free(void *);
};
void *_MemoryAlloc(unsigned int size, unsigned int align, cHeap &heap);
extern "C" int func_0030F348();
extern "C" float func_0030F518();
extern "C" void func_0031D9F0(int, int);
extern "C" void func_0031DAA0();
extern cHeap *MemDefalutHeapPtr;
extern int D_00755BC8;

struct SlotPair {
    char _pad[0xB00];
    struct {
        int m_a;
        int m_b;
    } m_s[1];
};
struct Quad {
    int _0;
    int _4;
    int m_8;
    int _C;
    int m_10;
    int _14;
    int m_18;
};

// FUNCTION: GAME 0x31A300
extern "C" void func_0031A300(SlotPair *self, int i, int v)
{
    self->m_s[i].m_a = v;
    self->m_s[i].m_b = v + 0x80;
}

// FUNCTION: GAME 0x31BE78
extern "C" void func_0031BE78(Quad *self)
{
    self->m_8 = 0;
    self->m_10 = 0;
    self->m_18 = 0;
}

// FUNCTION: GAME 0x31CFE0
int irand()
{
    return func_0030F348();
}

// FUNCTION: GAME 0x31D000
float fRand0_1()
{
    return func_0030F518();
}

// FUNCTION: GAME 0x31C8E0
extern "C" void *func_0031C8E0(unsigned a, unsigned b, cHeap &h)
{
    return _MemoryAlloc(a, b, h);
}

// FUNCTION: GAME 0x31C8B8
extern "C" void *func_0031C8B8(unsigned a, unsigned b)
{
    return _MemoryAlloc(a, b, *MemDefalutHeapPtr);
}

// FUNCTION: GAME 0x31C900
extern "C" void func_0031C900(char *p)
{
    if (p)
        (*(cHeap **)(p - 0x20))->free(p);
}

// FUNCTION: GAME 0x31DA28
extern "C" void func_0031DA28()
{
    func_0031D9F0(1, 0xFFFF);
}


#ifdef NONMATCHING
// DRAFT: GAME 0x31D098
// diff: register allocation (seed in a1 vs v0, constants in different regs)
extern "C" void func_0031D098(int *seed)
{
    int v = *seed;
    *seed = v * 0x19660D + 0x3C6EF35F;
}
#endif
