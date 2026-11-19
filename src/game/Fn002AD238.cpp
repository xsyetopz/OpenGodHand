// Fn002AD238: three small free units: VU0 zeroing init (0x2AD238), table alloc (0x2B5AF8), collision shape init (0x2BB160).
extern char D_0044BED0[];
extern char ZeroMat[];
extern char D_0044B288[];
extern "C" void setOffsetPos__15cCollisionShapeRC4cVec(char *self, float *v);
extern "C" void func_002BB298(char *self, float *v);
extern "C" char *func_002B4FE8(char *self, int id);
extern "C" void *_MemoryAlloc__FUiUiR5cHeap(unsigned size, unsigned align, void *heap);
extern "C" void *memcpy(void *, const void *, unsigned);

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")

// FUNCTION: GAME 0x2AD238
extern "C" void *func_002AD238(char *self, int a1, int a2, int a3, int t0, int t1)
{
    *(int *)(self + 0xC) = 0;
    *(int *)(self + 0x10) = 0;
    *(int *)(self + 0x14) = 0;
    char *p = self + 0x20;
    int n = 0x7F;
    do {
        ZQ(p, 0x10);
        n--;
        p += 0x20;
    } while (n != -1);
    *(int *)self = a1;
    *(int *)(self + 4) = a2;
    *(int *)(self + 8) = t1;
    *(int *)(self + 0x10) = a3;
    *(int *)(self + 0x14) = t0;
    return self;
}

// FUNCTION: GAME 0x2B5AF8
extern "C" void *func_002B5AF8(char *self, int a1, unsigned size)
{
    char tbl[8];
    memcpy(tbl, D_0044B288, 8);
    char *n = func_002B4FE8(self, 0);
    if (n == 0) return 0;
    for (int i = 0; i < 2; i++) {
        void *r = _MemoryAlloc__FUiUiR5cHeap(size, 0x80, *(void **)(tbl + i * 4));
        if (r) {
            *(void **)n = r;
            *(void **)(n + 4) = *(void **)(tbl + i * 4);
            return r;
        }
    }
    return 0;
}

// FUNCTION: GAME 0x2BB160
extern "C" void *func_002BB160(char *self, char *shape, float *ofs, float *v)
{
    *(char **)(self + 0x100) = D_0044BED0;
    *(unsigned char *)(self + 4) = 0;
    ZQ(self, 0x50);
    ZQ(self, 0x60);
    ZQ(self, 0xD0);
    ZQ(self, 0xF0);
    *(char **)(self + 8) = shape;
    if (shape != ZeroMat) *(unsigned char *)(self + 4) |= 2;
    else *(unsigned char *)(self + 4) &= 0xFD;
    setOffsetPos__15cCollisionShapeRC4cVec(self, ofs);
    func_002BB298(self, v);
    return self;
}
