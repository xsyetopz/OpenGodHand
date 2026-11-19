extern "C" int func_00140C58(char *self);
extern "C" void Adjust_theta_vec__FPf(float *);
extern int D_00747A84;

// FUNCTION: GAME 0x0013E2F8
extern "C" void setData__13cCockGetPointG4cVecUss(void) {}

struct W1E { int a, b, c; };
struct W1S { char pad[0x22F0]; W1E e[1]; };

#ifdef NONMATCHING
// DRAFT: GAME 0x00140BF0
// 4 words differ (104 bytes each): addiu/addu folds 0x22F0 into index, original keeps addu a0 + imm 0x22F4/0x22F0; tried early return, store swap, base-pointer forms (14-16 words)
extern "C" int func_00140BF0(W1S *self, int a, int b)
{
    int i = func_00140C58((char *)self);
    if (i < 0) return 0;
    W1E *e = &self->e[i];
    e->a = b;
    e->b = a;
    return 1;
}
#endif

// FUNCTION: GAME 0x00148358
// volatile stores keep source order (gcc otherwise hoists the 0x294 float store); last store stays plain so it fills the jr delay slot
extern "C" char *func_00148358(char *p)
{
    *(volatile int *)(p + 0x38C) = 0;
    *(volatile float *)(p + 0x2A8) = 1.0f;
    *(volatile int *)(p + 0x390) = 0;
    *(volatile float *)(p + 0x1B0) = 1.0f;
    *(volatile int *)(p + 0x1B4) = 0;
    *(volatile int *)(p + 0x1B8) = 0;
    *(volatile int *)(p + 0x1C0) = 0;
    *(volatile float *)(p + 0x1C4) = 1.0f;
    *(volatile int *)(p + 0x1C8) = 0;
    *(volatile int *)(p + 0x1D0) = 0;
    *(volatile int *)(p + 0x1D4) = 0;
    *(volatile float *)(p + 0x1D8) = 1.0f;
    *(volatile float *)(p + 0x280) = 1.0f;
    *(volatile int *)(p + 0x284) = 0;
    *(volatile int *)(p + 0x288) = 0;
    *(volatile int *)(p + 0x290) = 0;
    *(volatile float *)(p + 0x294) = 1.0f;
    *(volatile int *)(p + 0x298) = 0;
    *(volatile int *)(p + 0x2A0) = 0;
    *(volatile int *)(p + 0x2A4) = 0;
    *(volatile int *)(p + 0x404) = 0;
    *(volatile int *)(p + 0x408) = 0;
    *(int *)(p + 0x410) = 0;
    return p;
}

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
// 7 words differ (112 vs 108 bytes): lui/mtc1 lands after the f[0] store and a nop follows jr; tried plain leading stores (20 words), hoisted 1.0f local (14), plain zero stores (16), raw offsets (13)
extern "C" void func_00148250(W1M *p, float a, float b)
{
    __asm__ volatile("vmove.xyzw $vf4,$vf0\n\tvmr32.xyzw $vf5,$vf4\n\tvmr32.xyzw $vf6,$vf5\n\tvmr32.xyzw $vf7,$vf6\n\tsqc2 $vf4,0x30(%0)\n\tsqc2 $vf5,0x20(%0)\n\tsqc2 $vf6,0x10(%0)\n\tsqc2 $vf7,0(%0)" : : "r"(p) : "memory");
    *(volatile float *)&p->f[0] = a;
    *(volatile float *)&p->f[5] = b;
    *(volatile float *)&p->f[10] = 1.0f;
    *(volatile int *)&p->f[15] = 0;
    *(volatile int *)&p->f[1] = 0;
    *(volatile int *)&p->f[2] = 0;
    *(volatile int *)&p->f[3] = 0;
    *(volatile int *)&p->f[4] = 0;
    *(volatile int *)&p->f[6] = 0;
    *(volatile int *)&p->f[7] = 0;
    *(volatile int *)&p->f[8] = 0;
    *(volatile int *)&p->f[9] = 0;
    *(volatile int *)&p->f[11] = 0;
    *(volatile int *)&p->f[12] = 0;
    *(volatile int *)&p->f[13] = 0;
    p->f[14] = 0;
}
#endif
