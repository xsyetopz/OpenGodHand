// VU0 math units that mix COP2 copies with calls. Memory-operand asm keeps stack-relative addressing.
// libvu0 (sceVu0*) vector and matrix routines: each body is the COP2 sequence in one asm block.
typedef int Row __attribute__((mode(TI)));

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


// The three row loads precede the vadd, so the rows sit in registers across the asm; the clobbers and
// the declaration order reproduce the original register choice (a3/t0/t1).
// FUNCTION: GAME 0x30A508
void sceVu0TransMatrix(Row *d, const Row *m, const float *t)
{
    __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0x30(%1)" : : "r"(t), "r"(m) : "memory");
    Row b = m[1], c = m[2], a = m[0];
    __asm__ volatile("vadd.xyz $vf5,$vf5,$vf4" : : : "$2", "$3", "$6", "memory");
    d[0] = a;
    d[1] = b;
    d[2] = c;
    __asm__ volatile("sqc2 $vf5,0x30(%0)" : : "r"(d) : "memory");
}

// FUNCTION: GAME 0x30AB48
void func_0030AB48(float *d, const float *m, const float *v, int zw)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0x10(%1)\n\tlqc2 $vf6,0x20(%1)\n\tlqc2 $vf7,0x30(%1)\n\tlqc2 $vf8,0(%2)\n\tvmulax.xyzw $ACC,$vf4,$vf8x\n\tvmadday.xyzw $ACC,$vf5,$vf8y\n\tvmaddaz.xyzw $ACC,$vf6,$vf8z\n\tvmaddw.xyzw $vf9,$vf7,$vf8w\n\tvdiv $Q,$vf0w,$vf9w\n\tvwaitq\n\tvmulq.xyz $vf9,$vf9,$Q\n\tvftoi4.xyzw $vf10,$vf9" : : "r"(d), "r"(m), "r"(v) : "memory");
    if (zw)
        __asm__ volatile("vftoi0.zw $vf10,$vf9");
    __asm__ volatile("sqc2 $vf10,0(%0)" : : "r"(d) : "memory");
}

// FUNCTION: GAME 0x2A38E8
int func_002A38E8(float *d, const float *m, const float *v)
{
    int clip;
    __asm__ volatile("lqc2 $vf4,0(%2)\n\tlqc2 $vf5,0x10(%2)\n\tlqc2 $vf6,0x20(%2)\n\tlqc2 $vf7,0x30(%2)\n\tlqc2 $vf8,0(%3)\n\tvmulax.xyzw $ACC,$vf4,$vf8x\n\tvmadday.xyzw $ACC,$vf5,$vf8y\n\tvmaddaz.xyzw $ACC,$vf6,$vf8z\n\tvmaddw.xyzw $vf12,$vf7,$vf0w\n\tvclipw.xyz $vf12,$vf12w\n\tvnop\n\tvnop\n\tvnop\n\tsqc2 $vf12,0(%1)\n\tvnop\n\tcfc2.ni %0,$vi18" : "=r"(clip) : "r"(d), "r"(m), "r"(v) : "memory");
    return clip;
}

// Uses the matrix rows already in $vf4-$vf7.
// FUNCTION: GAME 0x2A3930
int func_002A3930(float *d, const float *v)
{
    int clip;
    __asm__ volatile("lqc2 $vf8,0(%2)\n\tvmulax.xyzw $ACC,$vf4,$vf8x\n\tvmadday.xyzw $ACC,$vf5,$vf8y\n\tvmaddaz.xyzw $ACC,$vf6,$vf8z\n\tvmaddw.xyzw $vf12,$vf7,$vf0w\n\tvclipw.xyz $vf12,$vf12w\n\tvnop\n\tvnop\n\tvnop\n\tsqc2 $vf12,0(%1)\n\tvnop\n\tcfc2.ni %0,$vi18" : "=r"(clip) : "r"(d), "r"(v) : "memory");
    return clip;
}
}

// Adjust_theta_vec: wrap the xyz angles into range through a COP2/MMI sequence.
// FUNCTION: GAME 0x1F7DA0
void Adjust_theta_vec(float *v)
{
    __asm__ volatile(
        "lqc2 $vf4,0(%0)\n\t"
        "lui $t1,%%hi(D_003BF110)\n\taddiu $t1,$t1,%%lo(D_003BF110)\n\t"
        "lqc2 $vf6,0($t1)\n\tlq $t5,0x10($t1)\n\tvmulx.xyz $vf7,$vf4,$vf6x\n\tqmfc2.ni $t0,$vf4\n\t"
        "lq $t2,0x20($t1)\n\tpcgtw $t0,$t0,$zero\n\tvftoi0.xyz $vf7,$vf7\n\tpand $t0,$t5,$t0\n\t"
        "qmfc2.ni $t3,$vf7\n\tpaddw $t3,$t3,$t0\n\tpand $t3,$t3,$t2\n\tqmtc2.ni $t3,$vf7\n\t"
        "vitof0.xyz $vf7,$vf7\n\tvmuly.xyz $vf7,$vf7,$vf6y\n\tvsub.xyz $vf4,$vf4,$vf7\n\tsqc2 $vf4,0(%0)"
        : : "r"(v) : "$8", "$9", "$10", "$11", "$13", "memory");
}

// 4x4 matrix inverse for a rotation + translation matrix: transposes the 3x3 part with MMI, negates the translation.
// FUNCTION: GAME 0x30A3F8
extern "C" void func_0030A3F8(float *d, const float *m)
{
    __asm__ volatile(
        "lq $t0,0(%1)\n\tlq $t1,0x10(%1)\n\tlq $t2,0x20(%1)\n\tlqc2 $vf4,0x30(%1)\n\t"
        "vmove.xyzw $vf5,$vf4\n\tvsub.xyz $vf4,$vf4,$vf4\n\tvmove.xyzw $vf9,$vf4\n\tqmfc2.ni $t3,$vf4\n\t"
        "pextlw $t4,$t1,$t0\n\tpextuw $t5,$t1,$t0\n\tpextlw $t6,$t3,$t2\n\tpextuw $t7,$t3,$t2\n\t"
        "pcpyld $t0,$t6,$t4\n\tpcpyud $t1,$t4,$t6\n\tpcpyld $t2,$t7,$t5\n\t"
        "qmtc2.ni $t0,$vf6\n\tqmtc2.ni $t1,$vf7\n\tqmtc2.ni $t2,$vf8\n\t"
        "vmulax.xyz $ACC,$vf6,$vf5x\n\tvmadday.xyz $ACC,$vf7,$vf5y\n\tvmaddz.xyz $vf4,$vf8,$vf5z\n\tvsub.xyz $vf4,$vf9,$vf4\n\t"
        "sq $t0,0(%0)\n\tsq $t1,0x10(%0)\n\tsq $t2,0x20(%0)\n\tsqc2 $vf4,0x30(%0)"
        : : "r"(d), "r"(m) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}

// Continues from $vf6 (set by the caller); the result stays in $vf4.
// FUNCTION: GAME 0x30A5D0
extern "C" void func_0030A5D0(int, int, int, int neg)
{
    __asm__ volatile("lui $t0,%%hi(D_003C3C90)\n\taddiu $t0,$t0,%%lo(D_003C3C90)\n\tlqc2 $vf5,0($t0)\n\tvmr32.w $vf6,$vf6\n\tvaddx.x $vf4,$vf0,$vf6x\n\tvmul.x $vf6,$vf6,$vf6\n\tvmulx.yzw $vf4,$vf4,$vf0x\n\tvmulw.xyzw $vf8,$vf5,$vf6w\n\tvsub.xyzw $vf5,$vf0,$vf0\n\tvmulx.xyzw $vf8,$vf8,$vf6x\n\tvmulx.xyz $vf8,$vf8,$vf6x\n\tvaddw.x $vf4,$vf4,$vf8w\n\tvmulx.xy $vf8,$vf8,$vf6x\n\tvaddz.x $vf4,$vf4,$vf8z\n\tvmulx.x $vf8,$vf8,$vf6x\n\tvaddy.x $vf4,$vf4,$vf8y\n\tvaddx.x $vf4,$vf4,$vf8x\n\tvaddx.xy $vf4,$vf5,$vf4x\n\tvmul.x $vf7,$vf4,$vf4\n\tvsubx.w $vf7,$vf0,$vf7x\n\tvsqrt $Q,$vf7w\n\tvwaitq\n\tvaddq.x $vf7,$vf0,$Q" : : : "$8", "memory");
    if (!neg)
        __asm__ volatile("vaddx.x $vf4,$vf5,$vf7x");
    else
        __asm__ volatile("vsubx.x $vf4,$vf5,$vf7x");
    __asm__ volatile("");
}

struct Ent { float *dst; char pad[0xC]; float off[4]; };
struct Set {
    char p0[0xC];
    int n;
    char p1[0x10];
    Ent e[1];
};
// FUNCTION: GAME 0x2AE1C8
extern "C" void func_002AE1C8(Set *s)
{
    for (int i = 0; i < s->n; i++) {
        float *d = s->e[i].dst;
        __asm__ volatile("lqc2 $vf4,0(%0)\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,0(%0)" : : "r"(d), "r"(s->e[i].off) : "memory");
    }
    s->n = 0;
}


// Stack vectors with a zeroed-w constructor and the guarded 3-float assignment of the cVec family.
struct Qv { float f[4]; };
struct Sv {
    float v[4] __attribute__((aligned(16)));
    Sv() { __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)v)); }
    Sv &operator=(const float *o)
    {
        if (v != o) { v[0] = o[0]; v[1] = o[1]; v[2] = o[2]; }
        return *this;
    }
};
float capVu0LengthSq(const float *);

// FUNCTION: GAME 0x2BB3F0
extern "C" int func_002BB3F0(const float *a, const float *b, float r1, float r2)
{
    Sv s;
    float t[4] __attribute__((aligned(16)));
    float *tp = t;
    Sv d;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)d.v) : "r"(b), "r"(a));
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)tp) : "r"(d.v));
    s = t;
    return capVu0LengthSq(s.v) < (r1 + r2) * (r1 + r2);
}

struct ObjA { char p0[0xF0]; float *pos; char p1[0x53C]; float org[4]; };
// FUNCTION: GAME 0x12A578
extern "C" Sv *func_0012A578(Sv *out, ObjA *self, float k)
{
    Sv s;
    float t[4] __attribute__((aligned(16)));
    const float *pp = self->pos;
    const float *oo = self->org;
    float *tp = t;
    Sv d;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)d.v) : "r"(pp), "r"(oo));
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)tp) : "r"(d.v));
    s = t;
    __asm__ volatile("lqc2 $vf4,%0\n\tmfc1 $t0,%1\n\tqmtc2.ni $t0,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,%0" : "+m"(*(Qv *)s.v) : "f"(k) : "$8");
    __asm__ volatile("lqc2 $vf4,%0\n\tlqc2 $vf5,0(%1)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "+m"(*(Qv *)s.v) : "r"(self->pos));
    __asm__ volatile("lqc2 $vf4,%1\n\tsqc2 $vf4,0(%0)" : : "r"(out), "m"(*(Qv *)s.v) : "memory");
    return out;
}

struct ObjB {
    char p0[0x110]; int *fl; char p1[9]; unsigned char b11D; char p2[6];
    float pos[3]; float k; char p3[0xFA]; short h22E; short h230;
};
// FUNCTION: GAME 0x2FDD10
extern "C" void func_002FDD10(ObjB *self)
{
    float v[4] __attribute__((aligned(16)));
    v[0] = self->pos[0]; v[1] = self->pos[1]; v[2] = self->pos[2]; v[3] = 1.0f;
    if ((self->fl[1] & 0x2000) || (self->b11D & 1) == 0 || self->h230 != self->h22E) {
        __asm__ volatile("lqc2 $vf4,%0\n\tmfc1 $t0,%1\n\tqmtc2.ni $t0,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,%0" : "+m"(*(Qv *)v) : "f"(self->k) : "$8");
    }
    self->pos[0] = v[0]; self->pos[1] = v[1]; self->pos[2] = v[2];
}

// FUNCTION: GAME 0x2DAF68
extern "C" int func_002DAF68(const float *a, const float *b, float r1, float r2, float *dist, float *out)
{
    float t[4] __attribute__((aligned(16)));
    Sv d;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)d.v) : "r"(a), "r"(b));
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)t) : "r"(d.v));
    register float l __asm__("$f0") = t[0] * t[0];
    l += t[1] * t[1];
    l += t[2] * t[2];
    // The two nops ahead of sqrt.s are hazard padding of the original inline template.
    __asm__ volatile("nop\n\tnop\n\tsqrt.s %0,%0" : "+f"(l));
    if (l < r1 + r2) {
        if (dist) *dist = l;
        if (out) { if (out != a) { out[0] = a[0]; out[1] = a[1]; out[2] = a[2]; } }
        return 1;
    }
    return 0;
}
