// Small units in 0x140000-0x150000.
struct MtxA { float v[16]; } __attribute__((aligned(16)));
struct Hp { int w[16]; };
extern "C" void MtxInitTransVec__FR7cMatrixRC4cVec(MtxA *, const void *);
extern "C" void MtxMulRotVec__FR7cMatrixRC7cMatrixRC4cVecUc(MtxA *, const MtxA *, const void *, unsigned char);
extern "C" void MtxMulScaleVec__FR7cMatrixRC7cMatrixRC4cVec(MtxA *, const MtxA *, const void *);
extern "C" void func_00147BB0(MtxA *, const MtxA *, const void *);
extern "C" void func_0015EAC8(char *);
extern "C" void func_0014FE78(char *);
extern "C" Hp D_00754200;
extern "C" char *_MemoryAlloc__FUiUiR5cHeap(unsigned, unsigned, Hp &);
extern "C" void *memset(void *, int, unsigned);

// FUNCTION: GAME 0x147A48
extern "C" void MtxInitCoord__FR7cMatrixRC4cVecN21Uc(MtxA *m, const void *t, const void *r, const void *s, unsigned char k)
{
    MtxInitTransVec__FR7cMatrixRC4cVec(m, t);
    MtxMulRotVec__FR7cMatrixRC7cMatrixRC4cVecUc(m, m, r, k);
    MtxMulScaleVec__FR7cMatrixRC7cMatrixRC4cVec(m, m, s);
}

// FUNCTION: GAME 0x147AB8
extern "C" void func_00147AB8(MtxA *m, const void *t, const void *r, const void *s)
{
    MtxInitTransVec__FR7cMatrixRC4cVec(m, t);
    func_00147BB0(m, m, r);
    MtxMulScaleVec__FR7cMatrixRC7cMatrixRC4cVec(m, m, s);
}

// FUNCTION: GAME 0x14FE08
extern "C" void func_0014FE08(char *self, int n)
{
    *(char **)self = _MemoryAlloc__FUiUiR5cHeap(n << 4, 0x80, D_00754200);
    memset(*(char **)self, 0, n << 4);
    *(int *)(self + 0x20) = n;
    func_0014FE78(self);
}

// FUNCTION: GAME 0x14EF50
extern "C" void KageInit__8cObjBaseP12GP_KAGE_WORKP20_COBJBASE_SHADOWDATA(char *self, char *a, char *b)
{
    *(char **)(self + 0x44C) = b;
    *(char **)(self + 0x450) = a;
    int off = 0;
    for (int i = 1; i >= 0; i--) {
        func_0015EAC8(*(char **)(self + 0x450) + off);
        off += 0x750;
    }
}

// FUNCTION: GAME 0x14FF00
extern "C" void func_0014FF00(char *self, unsigned n, unsigned long v, unsigned long *out)
{
    unsigned cnt = *(unsigned *)(self + 0x20);
    unsigned m = cnt < n ? cnt : n;
    char *e = *(char **)self + ((cnt - m) << 4);
    unsigned long hi = (unsigned long)*(unsigned *)(e + 4) << 32;
    *(unsigned long *)e = (v << 32) | 0x20000000;
    unsigned long r = (*out & 0xFFFFFFF) | 0x20000000;
    *out = r | hi;
}
