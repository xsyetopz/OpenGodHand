struct Qv2 { float f[4]; };
struct Mtx { float m[16]; };
extern "C" void MtxInitCoord__FR7cMatrixRC4cVecN21Uc(Mtx *, char *, Qv2 *, char *, unsigned char);
extern "C" void sceVu0ApplyMatrix(char *, Mtx *, char *);
extern Qv2 D_005FEB00;
extern char D_0044D1A8[];
extern "C" int func_002D50C0(char *);

// FUNCTION: GAME 0x2DA9E0
extern "C" void Add_nullspeedDir__FP8cObjBasef(char *self, float f)
{
    Mtx m;
    Qv2 v;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(v));
    v.f[0] = 0.0f;
    v.f[1] = f;
    v.f[2] = 0.0f;
    MtxInitCoord__FR7cMatrixRC4cVecN21Uc(&m, *(char **)(self + 0xF0), &v, self + 0x110, *(unsigned char *)(self + 0x140));
    sceVu0ApplyMatrix(*(char **)(self + 0xF0), &m, self + 0x330);
}

// FUNCTION: GAME 0x2C5338
extern "C" void func_002C5338(int a, int b)
{
    if (b == 0xFFFF && a) {
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(D_005FEB00));
        char *p = (char *)&D_005FEB00 + 0x1C;
        func_002D50C0(p);
        *(int *)(p + 0x30) = (int)D_0044D1A8;
    }
}
