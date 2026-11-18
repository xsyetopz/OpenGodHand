extern "C" int func_00140C58(char *self);
extern "C" void Adjust_theta_vec__FPf(float *);
extern int D_00747A84;

// FUNCTION: GAME 0x0013E2F8
extern "C" void setData__13cCockGetPointG4cVecUss(void) {}

struct W1E { int a, b, c; };
struct W1S { char pad[0x22F0]; W1E e[1]; };

#ifdef NONMATCHING
// DRAFT: GAME 0x00140BF0
// 11 words as written (struct-array form); a lost p/q pointer-copy form reached 4 (mult dest a1 vs a0, addiu/addu fold); tried early returns
extern "C" int func_00140BF0(W1S *self, int a, int b)
{
    int i = func_00140C58((char *)self);
    if (i >= 0) {
        W1E *e = &self->e[i];
        e->b = a;
        e->a = b;
        return 1;
    }
    return 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x00148358
// 16 words differ: gcc hoists the 0x294 float store to slot 3; tried source reorder (sorted, reversed, hoisted const)
extern "C" char *func_00148358(char *p)
{
    *(int *)(p + 0x38C) = 0;
    *(float *)(p + 0x2A8) = 1.0f;
    *(int *)(p + 0x390) = 0;
    *(float *)(p + 0x1B0) = 1.0f;
    *(int *)(p + 0x1B4) = 0;
    *(int *)(p + 0x1B8) = 0;
    *(int *)(p + 0x1C0) = 0;
    *(float *)(p + 0x1C4) = 1.0f;
    *(int *)(p + 0x1C8) = 0;
    *(int *)(p + 0x1D0) = 0;
    *(int *)(p + 0x1D4) = 0;
    *(float *)(p + 0x1D8) = 1.0f;
    *(float *)(p + 0x280) = 1.0f;
    *(int *)(p + 0x284) = 0;
    *(int *)(p + 0x288) = 0;
    *(int *)(p + 0x290) = 0;
    *(float *)(p + 0x294) = 1.0f;
    *(int *)(p + 0x298) = 0;
    *(int *)(p + 0x2A0) = 0;
    *(int *)(p + 0x2A4) = 0;
    *(int *)(p + 0x404) = 0;
    *(int *)(p + 0x408) = 0;
    *(int *)(p + 0x410) = 0;
    return p;
}
#endif

// FUNCTION: GAME 0x0014F9F0
extern "C" void addNullSpeed_Rotation__8cObjBasef(char *p, float f)
{
    if (!(D_00747A84 & 0x20000000)) {
        *(float *)(p + 0x100) += *(float *)(p + 0x360) * f;
        *(float *)(p + 0x104) += *(float *)(p + 0x364) * f;
        *(float *)(p + 0x108) += *(float *)(p + 0x368) * f;
        Adjust_theta_vec__FPf((float *)(p + 0x100));
    }
}

struct W1M { float f[16]; };

#ifdef NONMATCHING
// DRAFT: GAME 0x00148250
// 13 words differ: 0x38 zero store hoisted before 0x3C; tried raw offsets and float[16] struct
extern "C" void func_00148250(W1M *p, float a, float b)
{
    __asm__ volatile("vmove.xyzw $vf4,$vf0\n\tvmr32.xyzw $vf5,$vf4\n\tvmr32.xyzw $vf6,$vf5\n\tvmr32.xyzw $vf7,$vf6\n\tsqc2 $vf4,0x30(%0)\n\tsqc2 $vf5,0x20(%0)\n\tsqc2 $vf6,0x10(%0)\n\tsqc2 $vf7,0(%0)" : : "r"(p) : "memory");
    p->f[0] = a;
    p->f[5] = b;
    p->f[10] = 1.0f;
    p->f[15] = 0;
    p->f[1] = 0;
    p->f[2] = 0;
    p->f[3] = 0;
    p->f[4] = 0;
    p->f[6] = 0;
    p->f[7] = 0;
    p->f[8] = 0;
    p->f[9] = 0;
    p->f[11] = 0;
    p->f[12] = 0;
    p->f[13] = 0;
    p->f[14] = 0;
}
#endif
