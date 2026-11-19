// Fn00147568: VU0 units in 0x147568-0x153808: MtxInverse, a cVec-style object init (0x14FF80), and the VU0 units 0x14FA60 and 0x153808.
extern const char D_0041ECA0[];

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")

// FUNCTION: GAME 0x14FF80
extern "C" char *func_0014FF80(char *self)
{
    *(const void **)(self + 0x214) = D_0041ECA0;
    ZQ(self, 0xC0);
    *(char **)(self + 0xD0) = self + 0x30;
    ZQ(self, 0xE0);
    *(char **)(self + 0xF0) = self + 0xB0;
    ZQ(self, 0x100);
    float *v = (float *)(self + 0x110);
    float *a = (float *)(self + 0x120);
    *(float *)(self + 0x110) = 1.0f;
    v[1] = 1.0f;
    v[2] = 1.0f;
    v[3] = 1.0f;
    *(float *)(self + 0x120) = 1.0f;
    a[1] = 1.0f;
    a[2] = 1.0f;
    a[3] = 1.0f;
    ZQ(self, 0x130);
    *(char *)(self + 0x140) = 0;
    *(int *)(self + 0x144) = 0;
    *(int *)(self + 0x148) = 0;
    *(int *)(self + 0x14C) = 0;
    *(int *)(self + 0x158) = 0;
    ZQ(self, 0x1A0);
    __asm__ volatile("vmove.xyzw $vf4,$vf0\n\tvmr32.xyzw $vf5,$vf4\n\tvmr32.xyzw $vf6,$vf5\n\tvmr32.xyzw $vf7,$vf6\n\tsqc2 $vf4,0x30(%0)\n\tsqc2 $vf5,0x20(%0)\n\tsqc2 $vf6,0x10(%0)\n\tsqc2 $vf7,0x0(%0)" : : "r"(self) : "memory");
    __asm__ volatile("vmove.xyzw $vf4,$vf0\n\tvmr32.xyzw $vf5,$vf4\n\tvmr32.xyzw $vf6,$vf5\n\tvmr32.xyzw $vf7,$vf6\n\tsqc2 $vf4,0x30(%0)\n\tsqc2 $vf5,0x20(%0)\n\tsqc2 $vf6,0x10(%0)\n\tsqc2 $vf7,0x0(%0)" : : "r"(self + 0x80) : "memory");
    return self;
}

extern unsigned int D_00747A84;
extern "C" void VecRotVec__FR4cVecRC4cVecT1Uc(void *, void *, void *, unsigned char);

// DRAFT: GAME 0x14FA60 13 words; the lwc1 register assignment and the 1.0f constant load differ from the original (tried product operand order, fa store placement, hoisted 1.0f)
#ifdef NONMATCHING
extern "C" void func_0014FA60(char *self, float fa, float fb)
{
    if (!(D_00747A84 & 0x20000000)) {
        float buf[8];
        ZQ(buf, 0);
        float one = 1.0f;
        float x = *(float *)(self + 0x330) * *(float *)(self + 0x110) * fb;
        float y = *(float *)(self + 0x334) * *(float *)(self + 0x114) * fb;
        float z = *(float *)(self + 0x338) * *(float *)(self + 0x118) * fb;
        int *b = (int *)(buf + 4);
        *(float *)&b[1] = fa;
        b[0] = 0;
        buf[0] = x;
        b[2] = 0;
        buf[1] = y;
        buf[2] = z;
        *(float *)&b[3] = one;
        VecRotVec__FR4cVecRC4cVecT1Uc(buf, buf, b, 4);
        *(float *)(*(char **)(self + 0xF0) + 0x0) += buf[0];
        *(float *)(*(char **)(self + 0xF0) + 0x4) += buf[1];
        *(float *)(*(char **)(self + 0xF0) + 0x8) += buf[2];
    }
}
#endif

extern "C" void sceVu0MulMatrix(void *, void *, void *);
extern "C" void capVu0ApplyMatrixXYZ__FPfPA3_CfPCf(void *, void *, void *);
extern "C" void func_0030A3F8(void *, int);
extern "C" void func_001501D0(void *, unsigned int);

// DRAFT: GAME 0x153808 5 words; the s3/s4 pair and the sp+0x40/sp+0x50 vector addressing differ (tried memory operands, r/t order, hoisted r address)
#ifdef NONMATCHING
extern "C" void func_00153808(char *self, char *arg1, char *arg2)
{
    float m[16];
    float r[4];
    float t[4];
    char *s4 = *(char **)(arg1 + 0x144);
    char *s2 = arg1 + 0x80;
    sceVu0MulMatrix(s2, self + 0x80, arg1);
    capVu0ApplyMatrixXYZ__FPfPA3_CfPCf(*(void **)(arg1 + 0xF0), s2, *(void **)(s4 + 0xD0));
    char *p = *(char **)(arg1 + 0xF0);
    ZQ(t, 0);
    __asm__ volatile("lqc2 $vf4,0x0(%0)\n\tlqc2 $vf5,0x0(%1)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0x0(%2)" : : "r"(arg2), "r"(p), "r"(t) : "memory");
    __asm__ volatile("lqc2 $vf4,0x0(%0)\n\tsqc2 $vf4,0x0(%1)" : : "r"(t), "r"(r) : "memory");
    if (p != (char *)r) {
        ((float *)p)[0] = r[0];
        ((float *)p)[1] = r[1];
        ((float *)p)[2] = r[2];
    }
    func_0030A3F8(m, *(int *)(arg1 + 0x148) + 0x80);
    sceVu0MulMatrix(arg1, m, s2);
    func_001501D0(s4, *(unsigned int *)(self + 0x250));
}
#endif

typedef int Row __attribute__((mode(TI)));

// DRAFT: GAME 0x147568 22 words; zero-path dst copy (daddu $a2) and output register allocation differ from the original's $t0-$t3 (tried Row indexed stores, fixed $12-$15 temporaries)
#ifdef NONMATCHING
extern "C" void MtxInverse__FR7cMatrixRC7cMatrix(void *dst, void *src)
{
    const float *s = (const float *)src;
    float det = s[0] * s[5] * s[10] + s[4] * s[9] * s[2] + s[8] * s[1] * s[6]
              - s[2] * s[5] * s[8] - s[1] * s[4] * s[10] - s[0] * s[6] * s[9];
    if (det == 0.0f) {
        __asm__ volatile("vmove.xyzw $vf4,$vf0\n\tvmr32.xyzw $vf5,$vf4\n\tvmr32.xyzw $vf6,$vf5\n\tvmr32.xyzw $vf7,$vf6\n\tsqc2 $vf4,0x30(%0)\n\tsqc2 $vf5,0x20(%0)\n\tsqc2 $vf6,0x10(%0)\n\tsqc2 $vf7,0x0(%0)" : : "r"(dst) : "memory");
        return;
    }
    int bits = *(int *)&det;
    Row o0, o1, o2, o3, t4, t5, t6, t7;
    __asm__ volatile(
        "qmtc2.ni %4,$vf10\n\t"
        "vdiv $Q,$vf0w,$vf10x\n\t"
        "lqc2 $vf4,0x0(%5)\n\t"
        "lqc2 $vf5,0x10(%5)\n\t"
        "lqc2 $vf6,0x20(%5)\n\t"
        "vopmula.xyz $ACC,$vf5,$vf6\n\t"
        "vopmsub.xyz $vf7,$vf6,$vf5\n\t"
        "vopmula.xyz $ACC,$vf6,$vf4\n\t"
        "vopmsub.xyz $vf8,$vf4,$vf6\n\t"
        "vopmula.xyz $ACC,$vf4,$vf5\n\t"
        "vopmsub.xyz $vf9,$vf5,$vf4\n\t"
        "vwaitq\n\t"
        "lqc2 $vf10,0x30(%5)\n\t"
        "vmulq.xyz $vf4,$vf7,$Q\n\t"
        "vmulq.xyz $vf5,$vf8,$Q\n\t"
        "vmulq.xyz $vf6,$vf9,$Q\n\t"
        "vmul.xyz $vf7,$vf4,$vf10\n\t"
        "vmul.xyz $vf8,$vf5,$vf10\n\t"
        "vmul.xyz $vf9,$vf6,$vf10\n\t"
        "vaddz.x $vf7,$vf7,$vf7z\n\t"
        "vaddz.x $vf8,$vf8,$vf8z\n\t"
        "vaddz.x $vf9,$vf9,$vf9z\n\t"
        "vsubw.w $vf10,$vf0,$vf0w\n\t"
        "vaddy.x $vf7,$vf7,$vf7y\n\t"
        "vaddy.x $vf8,$vf8,$vf8y\n\t"
        "vaddy.x $vf9,$vf9,$vf9y\n\t"
        "vsubx.w $vf4,$vf10,$vf7x\n\t"
        "vsubx.w $vf5,$vf10,$vf8x\n\t"
        "vsubx.w $vf6,$vf10,$vf9x\n\t"
        "qmfc2.ni %0,$vf4\n\t"
        "qmfc2.ni %1,$vf5\n\t"
        "qmfc2.ni %2,$vf6\n\t"
        "qmfc2.ni %3,$vf0\n\t"
        "pextlw $12,%1,%0\n\t"
        "pextuw $13,%1,%0\n\t"
        "pextlw $14,%3,%2\n\t"
        "pextuw $15,%3,%2\n\t"
        "pcpyld %0,$14,$12\n\t"
        "pcpyud %1,$12,$14\n\t"
        "pcpyld %2,$15,$13\n\t"
        "pcpyud %3,$13,$15"
        : "=&r"(o0), "=&r"(o1), "=&r"(o2), "=&r"(o3)
        : "r"(bits), "r"(src)
        : "memory", "$12", "$13", "$14", "$15");
    Row *d = (Row *)dst;
    d[0] = o0;
    d[1] = o1;
    d[2] = o2;
    d[3] = o3;
}
#endif
