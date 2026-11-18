// Resets the zero matrix and zero vector once the sentinel id 0xFFFF arrives (COP2 quad copies in asm).
extern char Sys[];
extern char ZeroMat[];
extern char D_003C3C40[];
extern float ZeroVec[4];

static inline void Set4(float *v, float x, float y, float z, float w)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = w;
}

// FUNCTION: GAME 0x3079C8
extern "C" void func_003079C8(int a, int b)
{
    if (b == 0xFFFF && a) {
        __asm__ volatile("sqc2 $vf0,0x5C0(%0)" : : "r"(Sys) : "memory");
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0x10(%1)\n\tlqc2 $vf6,0x20(%1)\n\tlqc2 $vf7,0x30(%1)\n\tsqc2 $vf4,0(%0)\n\tsqc2 $vf5,0x10(%0)\n\tsqc2 $vf6,0x20(%0)\n\tsqc2 $vf7,0x30(%0)" : : "r"(ZeroMat), "r"(D_003C3C40) : "memory");
        Set4(ZeroVec, 0.0f, 0.0f, 0.0f, 1.0f);
    }
}
