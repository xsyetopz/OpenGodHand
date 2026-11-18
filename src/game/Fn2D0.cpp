// Small unnamed units in 0x2D0000-0x2E0000.
extern char D_0044D1C8[];
extern "C" void func_002D0748(int *, int);
extern "C" void func_002D0758(int *, int);
extern "C" void func_002D2F78(void *, int, int, int, int);

// FUNCTION: GAME 0x2D50C0
extern "C" char *func_002D50C0(char *self)
{
    *(int *)self = 0;
    *(char **)(self + 0x30) = D_0044D1C8;
    *(int *)(self + 4) = 0;
    *(short *)(self + 0xC) = 0;
    *(short *)(self + 0xE) = 0;
    *(int *)(self + 0x2C) = 0;
    return self;
}

// FUNCTION: GAME 0x2D07A8
extern "C" void func_002D07A8(int *self, int m)
{
    self[0x16] |= m;
    func_002D0748(self, m);
}

// FUNCTION: GAME 0x2D07D8
extern "C" void func_002D07D8(int *self, int m)
{
    self[0x16] &= ~m;
    func_002D0758(self, m);
}

// FUNCTION: GAME 0x2D0820
extern "C" void func_002D0820(char *self, float f)
{
    char *p = *(char **)(self + 0x18);
    while (p) {
        *(float *)(p + 0xC4) = f;
        *(unsigned *)(p + 0x98) |= 4;
        p = *(char **)(p + 0x88);
    }
}

// FUNCTION: GAME 0x2D3020
extern "C" void func_002D3020(void *a, int b, int c, int d)
{
    func_002D2F78(a, 0, b, c, d);
}

struct cHeap;
extern cHeap D_00754200;
void *_MemoryAlloc(unsigned, unsigned, cHeap &);
extern "C" int func_00346848(int);

// FUNCTION: GAME 0x2D5790
extern "C" void func_002D5790(char *self)
{
    *(void **)(self + 0x10) = _MemoryAlloc(*(unsigned *)(self + 8), 0x10, D_00754200);
}

// FUNCTION: GAME 0x2D4210
extern "C" int func_002D4210(char *self)
{
    int r = 0;
    if (*(int *)self) {
        r = func_00346848(*(int *)self);
        *(int *)(self + 0xA4) = r;
    }
    return r;
}

// FUNCTION: GAME 0x2D3240
extern "C" void func_002D3240(int *self, int b, int c, int d, int e, int f)
{
    self[2] = c;
    self[0] = 1;
    self[1] = b;
    if (!b) {
        self[3] = d;
        self[0x1B] = 0;
    } else {
        self[0x1B] = d;
        self[3] = 0;
    }
    self[0x20] = f;
    self[0x1D] = e;
    self[0x1C] = 0;
}
