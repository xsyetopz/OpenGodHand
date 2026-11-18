// Small units in 0x140000-0x150000.
// FUNCTION: GAME 0x1471A8
extern "C" void TutorialON__13cCockTutorialUs(char *self, unsigned short v)
{
    if (*(int *)(self + 0xB0)) {
        *(unsigned short *)(self + 0xAC) = v;
        *(unsigned char *)(self + 0xB8) = 1;
        *(unsigned *)(*(char **)(self + 0xA4) + 0x2C) |= 0x8000000;
        *(unsigned *)(*(char **)(self + 0xA8) + 0x2C) |= 0x8000000;
    }
}


// FUNCTION: GAME 0x1476D0
extern "C" void MtxInitTransVec__FR7cMatrixRC4cVec(float *m, const float *p)
{
    m[1] = 0;
    m[0] = 1.0f;
    m[2] = 0;
    m[3] = 0;
    m[4] = 0;
    m[5] = 1.0f;
    m[6] = 0;
    m[7] = 0;
    m[8] = 0;
    m[9] = 0;
    m[10] = 1.0f;
    m[11] = 0;
    m[12] = p[0];
    m[13] = p[1];
    m[14] = p[2];
    m[15] = 1.0f;
}

struct MtxA { float v[16]; } __attribute__((aligned(16)));
extern "C" void MtxInitRotVec__FR7cMatrixRC4cVecUc(MtxA *, const void *, unsigned char);
extern "C" void MtxMultiply__FR7cMatrixRC7cMatrixT1(MtxA *, const MtxA *, const MtxA *);

// FUNCTION: GAME 0x147B60
extern "C" void MtxMulRotVec__FR7cMatrixRC7cMatrixRC4cVecUc(MtxA *d, const MtxA *a, const void *v, unsigned char k)
{
    MtxA t;
    MtxInitRotVec__FR7cMatrixRC4cVecUc(&t, v, k);
    MtxMultiply__FR7cMatrixRC7cMatrixT1(d, a, &t);
}


extern "C" char *getMeshPtr__6cModeli(void *, int);
extern "C" void func_00149220(void *, float);
// FUNCTION: GAME 0x14E4D0
extern "C" void ScrollTexture__6cModelf(void *self, float f)
{
    char *m = getMeshPtr__6cModeli(self, 0);
    if (m) {
        do {
            func_00149220(m, f);
            m = *(char **)(m + 0x404);
        } while (m);
    }
}

extern int D_00747AA8;
extern "C" void func_00148BD8(void *, int, int, int);
extern "C" void func_00148D30(void *, int);
// FUNCTION: GAME 0x14B5D8
extern "C" void func_0014B5D8(char *self, char *o)
{
    if (*(unsigned *)(*(char **)(o + 0x414) + 0x34) & 0x200000) {
        if (D_00747AA8) {
            func_00148BD8(o, *(int *)(self + 0x2C4), D_00747AA8, 0);
            return;
        }
    }
    func_00148D30(o, *(int *)(self + 0x2C4));
}

// DRAFT: GAME 0x14FD98 (loop/range-test codegen differs after 3 tries)
#ifdef NONMATCHING
extern "C" char *SearchOM__13cObjBaseArrayUl(char *self, unsigned long key)
{
    char *arr = *(char **)self;
    char **e = *(char ***)(arr + 8);
    char **a = *(char ***)(arr + 4);
    for (; a < e; a++) {
        char *o = *a;
        int v = *(unsigned short *)(o + 0x2FE);
        bool ok = v >= 0x300 && v < 0x500;
        if (ok && *(unsigned long *)(o + 0x538) == key)
            return o;
    }
    return 0;
}
#endif
