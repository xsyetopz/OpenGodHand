// Mid-size units in 0x140000-0x160000.
extern int D_007476B0;
extern char D_00754C80[];
extern "C" float cosf(float);
extern "C" float sinf(float);
extern "C" void func_0031A650(void *, int, int, char *, char *);
extern "C" void func_00144C90(void *);
extern "C" void resetAnim__7cIDBase(void *);
extern unsigned short D_003BD70C;
class cHeap;
void *_MemoryAlloc(unsigned int, unsigned int, cHeap &);
extern cHeap *MemDefalutHeapPtr;
extern "C" void *func_002A96C0(int, int, int);
extern "C" void func_00150418(void *);
extern "C" void func_002A96D8(void *, void *, int, int, int);
extern "C" void *func_002A9860(void *, void *);
extern "C" void func_001483C8(void *, int);
extern "C" void func_002A9790(void *);
extern "C" void free__5cHeapPv(void *, void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x14B918 - ~30 words differ: original keeps self in a0 until the lh and loads D_00754C80 after it; ours moves self to a2 and hoists the lui
extern "C" void func_0014B918(char *self, char *o)
{
    int f = D_007476B0 & 1;
    if (*(unsigned *)(o + 0x380) & 1)
        return;
    int s = *(int *)(self + 0x2C0);
    if (s == 10)
        func_0031A650(D_00754C80, 6, 4, o + f * 0xB0, o + f * 0xB0 + 0xA0);
    else {
        int h = *(short *)(self + 0x2AC);
        func_0031A650(D_00754C80, s, h, o + f * 0xB0, o + f * 0xB0 + 0xA0);
    }
}
#endif

// FUNCTION: GAME 0x14BDB0
extern "C" void func_0014BDB0(char *self, char *o)
{
    int f = D_007476B0 & 1;
    if (*(unsigned *)(o + 0x380) & 1)
        return;
    int s = *(int *)(self + 0x2C0);
    if (s == 10)
        func_0031A650(D_00754C80, 4, 5, o + f * 0xB0, o + f * 0xB0 + 0xA0);
    else {
        int h = *(short *)(self + 0x2AC);
        func_0031A650(D_00754C80, s, h, o + f * 0xB0, o + f * 0xB0 + 0xA0);
    }
}

// FUNCTION: GAME 0x144C08
extern "C" void func_00144C08(char *self)
{
    unsigned short i = 0;
    func_00144C90(self);
    do {
        resetAnim__7cIDBase(self + 0x100 + i * 0x50);
        i++;
    } while (i < 5);
    resetAnim__7cIDBase(self + 0x430);
    resetAnim__7cIDBase(self + 0x480);
    *(short *)(self + 0x41E) = 0;
    *(short *)(self + 0x420) = 0;
    *(int *)(self + 0x90) = 0;
    *(unsigned short *)(self + 0x4D0) = D_003BD70C;
}

// FUNCTION: GAME 0x149378
extern "C" void func_00149378(char *self)
{
    void *o = func_002A9860(self, 0);
    if (o) {
        do {
            void *n = func_002A9860(self, o);
            func_001483C8(o, 2);
            o = n;
        } while (o);
    }
    char *h = *(char **)self;
    func_002A9790(self);
    if (h)
        free__5cHeapPv(*(void **)(h - 0x20), h);
}

// FUNCTION: GAME 0x149400
extern "C" void func_00149400(char *self, int n)
{
    func_00149378(self);
    void *a = func_002A96C0(0x480, n, 0x80);
    void *b = _MemoryAlloc((unsigned)a, 0x80, *MemDefalutHeapPtr);
    func_002A96D8(self, b, 0x480, n, 0x80);
    *(int *)(self + 0x18) = n;
    *(int *)(self + 0x1C) = n;
    *(int *)(self + 0x24) = n;
    *(void **)(self + 0x20) = a;
}

// FUNCTION: GAME 0x1504B0
extern "C" void func_001504B0(char *self, int n)
{
    func_00150418(self);
    void *a = func_002A96C0(0x220, n, 0x10);
    void *b = _MemoryAlloc((unsigned)a, 0x10, *MemDefalutHeapPtr);
    func_002A96D8(self, b, 0x220, n, 0x10);
    *(int *)(self + 0x18) = n;
    *(int *)(self + 0x1C) = n;
    *(int *)(self + 0x24) = n;
    *(void **)(self + 0x20) = a;
}

// FUNCTION: GAME 0x1482C0
extern "C" void func_001482C0(float *p, float a)
{
    p[0] = cosf(a);
    p[1] = -sinf(a);
    p[2] = 0;
    p[3] = 0;
    p[4] = sinf(a);
    p[5] = cosf(a);
    p[10] = 1.0f;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[11] = 0;
    p[12] = 0;
    p[13] = 0;
    p[14] = 0;
    p[15] = 0;
}
