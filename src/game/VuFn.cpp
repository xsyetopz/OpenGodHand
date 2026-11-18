// VU0 math units that mix COP2 copies with calls. Memory-operand asm keeps stack-relative addressing.
// libvu0 (sceVu0*) vector and matrix routines: each body is the COP2 sequence in one asm block.
extern "C" {

// FUNCTION: GAME 0x30A4A0
void sceVu0AddVector(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvadd.xyzw $vf6,$vf4,$vf5\n\tsqc2 $vf6,0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}

// FUNCTION: GAME 0x30A4B8
void sceVu0SubVector(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyzw $vf6,$vf4,$vf5\n\tsqc2 $vf6,0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}

// FUNCTION: GAME 0x30A4E8
void sceVu0ScaleVector(float *d, const float *a, float s)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tmfc1 $t0,%2\n\tqmtc2.ni $t0,$vf5\n\tvmulx.xyzw $vf6,$vf4,$vf5x\n\tsqc2 $vf6,0(%0)" : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}

// FUNCTION: GAME 0x30A328
void sceVu0OuterProduct(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvopmula.xyz $ACC,$vf4,$vf5\n\tvopmsub.xyz $vf6,$vf5,$vf4\n\tvsub.w $vf6,$vf6,$vf6\n\tsqc2 $vf6,0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}

// FUNCTION: GAME 0x30A348
float sceVu0InnerProduct(const float *a, const float *b)
{
    float r;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvmul.xyz $vf5,$vf4,$vf5\n\tvaddy.x $vf5,$vf5,$vf5y\n\tvaddz.x $vf5,$vf5,$vf5z\n\tqmfc2.ni %0,$vf5" : "=r"(r) : "r"(a), "r"(b) : "memory");
    return r;
}

// FUNCTION: GAME 0x30A468
void sceVu0DivVector(float *d, const float *a, float s)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tmfc1 $t0,%2\n\tqmtc2.ni $t0,$vf5\n\tvdiv $Q,$vf0w,$vf5x\n\tvwaitq\n\tvmulq.xyzw $vf4,$vf4,$Q\n\tsqc2 $vf4,0(%0)" : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}

// FUNCTION: GAME 0x30A5A0
void sceVu0UnitMatrix(float *m)
{
    __asm__ volatile("vsub.xyzw $vf4,$vf0,$vf0\n\tvadd.w $vf4,$vf4,$vf0\n\tvmr32.xyzw $vf5,$vf4\n\tvmr32.xyzw $vf6,$vf5\n\tvmr32.xyzw $vf7,$vf6\n\tsqc2 $vf4,0x30(%0)\n\tsqc2 $vf5,0x20(%0)\n\tsqc2 $vf6,0x10(%0)\n\tsqc2 $vf7,0(%0)" : : "r"(m) : "memory");
}

// FUNCTION: GAME 0x30A2B0
void sceVu0ApplyMatrix(float *d, const float *m, const float *v)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0x10(%1)\n\tlqc2 $vf6,0x20(%1)\n\tlqc2 $vf7,0x30(%1)\n\tlqc2 $vf8,0(%2)\n\tvmulax.xyzw $ACC,$vf4,$vf8x\n\tvmadday.xyzw $ACC,$vf5,$vf8y\n\tvmaddaz.xyzw $ACC,$vf6,$vf8z\n\tvmaddw.xyzw $vf9,$vf7,$vf8w\n\tsqc2 $vf9,0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory");
}

// FUNCTION: GAME 0x30A370
void sceVu0Normalize(float *d, const float *a)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tvmul.xyz $vf5,$vf4,$vf4\n\tvaddy.x $vf5,$vf5,$vf5y\n\tvaddz.x $vf5,$vf5,$vf5z\n\tvsqrt $Q,$vf5x\n\tvwaitq\n\tvaddq.x $vf5,$vf0,$Q\n\tvnop\n\tvnop\n\tvdiv $Q,$vf0w,$vf5x\n\tvsub.xyzw $vf6,$vf0,$vf0\n\tvwaitq\n\tvmulq.xyz $vf6,$vf4,$Q\n\tsqc2 $vf6,0(%0)" : : "r"(d), "r"(a) : "memory");
}

}

#ifdef NONMATCHING
struct v4f { float f[4]; };
struct V4 {
    float v[4] __attribute__((aligned(16)));
    V4() { __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(v4f *)v)); }
    operator float *() { return v; }
};
struct cMatrix { float m[16]; };
struct VObj {
    char p0[0xF0];
    float *pos;
    char p1[0x10];
    float dir;
    char p2[0x4A0];
    float spd;
};
extern const float D_005850B0[];
static inline void M_Sub(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(v4f *)d) : "r"(a), "r"(b));
}
static inline void M_Add(float *d, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,%1\n\tlqc2 $vf5,0(%2)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(v4f *)d) : "m"(*(const v4f *)a), "r"(b));
}
static inline void M_Copy(float *d, const float *a)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(v4f *)d) : "r"(a));
}
float capVu0Atan2(float, float);
float Adjust_theta(float);
float Turn_dest_dir(float, float, float);
void MtxInitRotY(cMatrix &, float);
extern "C" void sceVu0ApplyMatrix(float *, float *, float *);

// DRAFT: GAME 0x249770
// diff: 9 words, scheduling only (lw/lui/addiu order before the first lqc2, a2 copy vs sw zero order near sceVu0ApplyMatrix)
extern "C" void func_00249770(VObj *self, float ang)
{
    cMatrix m;
    V4 res;
    float tmp[4] __attribute__((aligned(16)));
    V4 rel;
    M_Sub(rel.v, self->pos, D_005850B0);
    M_Copy(tmp, rel.v);
    res.v[0] = tmp[0];
    res.v[1] = tmp[1];
    res.v[2] = tmp[2];
    float a = Adjust_theta(capVu0Atan2(tmp[0], tmp[2]) + ang);
    MtxInitRotY(m, a);
    res.v[0] = 0.0f;
    res.v[2] = 26.0f;
    res.v[1] = 0.0f;
    sceVu0ApplyMatrix(res, (float *)&m, res);
    M_Add(res.v, res.v, D_005850B0);
    self->pos[0] = res.v[0];
    self->pos[2] = res.v[2];
    float t = Adjust_theta(a + 3.1415927f);
    self->dir += Turn_dest_dir(self->dir, t, self->spd * 0.012271847f);
    self->dir = Adjust_theta(self->dir);
}
#endif
