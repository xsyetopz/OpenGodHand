// VU0 math units that mix COP2 copies with calls. Memory-operand asm keeps stack-relative addressing.
// libvu0 (sceVu0*) vector and matrix routines: each body is the COP2 sequence in one asm block.
typedef int Row __attribute__((mode(TI)));

extern "C" {

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
