// VU0 macro-mode units for slice F165 (COP2 copies in asm blocks, C control flow).
struct Qv { float f[4]; };
struct cVec { float v[4] __attribute__((aligned(16))); };
struct LenPosLineReslt;

extern "C" {
void func_00147C60(void *, float *);
void sceVu0ApplyMatrix(float *, void *, float *);
void func_002BC6C8(void *, float *, float *, float, float);
}
float LengthPositionToGivenLine(const cVec &p, const cVec &a, const cVec &b, LenPosLineReslt *res);

static inline void vcopy(float *dst, const float *src)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)dst) : "r"(src));
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2BB670 - 8 words; 1.0f store lands before the jal (original stores it in the delay slot via s1). Tried: "m" operands (56), register COP2 operands (38), store after call (41, 11), pointer store after call (23), hoisted constant (52).
extern "C" int func_002BB670(void *arg0, float *arg1, float fparg0, float fparg1, float fparg2)
{
    float lim = fparg0;
    float ext = fparg1;
    cVec sp;
    cVec s10;
    cVec s20;
    cVec s30;
    __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(sp.v) : "memory");
    s10.v[0] = 0.0f;
    s10.v[1] = fparg2;
    s10.v[2] = 0.0f;
    s10.v[3] = 1.0f;
    func_00147C60(sp.v, arg1);
    vcopy(s30.v, s10.v);
    sceVu0ApplyMatrix(s30.v, arg1, s30.v);
    vcopy(s20.v, s30.v);
    s10.v[0] = s20.v[0];
    s10.v[1] = s20.v[1];
    s10.v[2] = s20.v[2];
    float d = LengthPositionToGivenLine(*(const cVec *)arg0, sp, s10, 0);
    if (d <= lim + ext) { return 1; }
    return 0;
}

// DRAFT: GAME 0x2BB760 - 37 words; zero-loop counter and main-loop counter merge into one countdown s3 (addiu 7, bgez), original keeps v1 countdown and s3 ascending. Tried: do-while main loop (37), q/w/d decl orders (37, 37), w=arg0 with w+=4 (24, wrong data flow, dropped), q-first (28 with do-while zero loop).
extern "C" void func_002BB868(void *, void *, float);

extern "C" void func_002BB760(void *arg0, float *arg1, float *arg2, float fparg0)
{
    cVec sp[10];
    float *p = sp[0].v;
    int i = 7;
    do {
        __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(p) : "memory");
        i -= 1;
        p += 4;
    } while (i != -1);
    float *d = sp[0].v;
    float *w = sp[9].v;
    float *q = arg2;
    for (int s3 = 0; s3 < 8; s3++) {
        vcopy(sp[9].v, q);
        sceVu0ApplyMatrix(w, arg1, w);
        vcopy(sp[8].v, w);
        if (d != sp[8].v) {
            d[0] = sp[8].v[0];
            d[1] = sp[8].v[1];
            d[2] = sp[8].v[2];
        }
        d += 4;
        q += 4;
    }
    func_002BB868(arg0, sp, fparg0);
}

// DRAFT: GAME 0x2BBBA0 - 73 words; cached x/z/qy, 0x3F000000 constant, direct sp[k] stores. Tried: this recipe (73, twice), hoisted e-pointers with per-element t reads (79), bit-cast 0.5 with cached values (75), hoisted e-pointers reversed (75), per-element constant to $v0 (74).
extern "C" void func_002BBBA0(void *arg0, float *arg1, float *arg2, float fparg0)
{
    cVec sp[8];
    cVec t;
    float *p = sp[0].v;
    int i = 7;
    do {
        __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(p) : "memory");
        i -= 1;
        p += 4;
    } while (i != -1);
    vcopy(t.v, arg2);
    unsigned int hb = 0x3F000000u;
    __asm__ volatile("lqc2 $vf4,0(%0)\n\tqmtc2.ni %1,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,0(%0)"
                     : : "r"(t.v), "r"(hb) : "memory");
    float x = t.v[0];
    float z = t.v[2];
    float qy = arg2[1];
    sp[0].v[0] = -x; sp[0].v[1] = 0.0f; sp[0].v[2] = -z;
    sp[1].v[0] = x;  sp[1].v[1] = 0.0f; sp[1].v[2] = -z;
    sp[2].v[0] = -x; sp[2].v[1] = 0.0f; sp[2].v[2] = z;
    sp[3].v[0] = x;  sp[3].v[1] = 0.0f; sp[3].v[2] = z;
    sp[4].v[0] = -x; sp[4].v[1] = qy; sp[4].v[2] = -z;
    sp[5].v[0] = x;  sp[5].v[1] = qy; sp[5].v[2] = -z;
    sp[6].v[0] = -x; sp[6].v[1] = qy; sp[6].v[2] = z;
    sp[7].v[0] = x;  sp[7].v[1] = qy; sp[7].v[2] = z;
    func_002BB760(arg0, arg1, sp[0].v, fparg0);
}

// DRAFT: GAME 0x2BCB80 - 73 words; cached x/z/qy, 0x3F000000 constant, direct sp[k] stores. Tried: this recipe (73, twice), per-element t reads without hoisting (73).
extern "C" void func_002BCB80(void *arg0, float *arg1, float *arg2, float fparg0, float fparg1)
{
    cVec sp[8];
    cVec t;
    float *p = sp[0].v;
    int i = 7;
    do {
        __asm__ volatile("sqc2 $vf0,0(%0)" : : "r"(p) : "memory");
        i -= 1;
        p += 4;
    } while (i != -1);
    vcopy(t.v, arg2);
    unsigned int hb = 0x3F000000u;
    __asm__ volatile("lqc2 $vf4,0(%0)\n\tqmtc2.ni %1,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,0(%0)"
                     : : "r"(t.v), "r"(hb) : "memory");
    float x = t.v[0];
    float z = t.v[2];
    float qy = arg2[1];
    sp[0].v[0] = -x; sp[0].v[1] = 0.0f; sp[0].v[2] = -z;
    sp[1].v[0] = x;  sp[1].v[1] = 0.0f; sp[1].v[2] = -z;
    sp[2].v[0] = -x; sp[2].v[1] = 0.0f; sp[2].v[2] = z;
    sp[3].v[0] = x;  sp[3].v[1] = 0.0f; sp[3].v[2] = z;
    sp[4].v[0] = -x; sp[4].v[1] = qy; sp[4].v[2] = -z;
    sp[5].v[0] = x;  sp[5].v[1] = qy; sp[5].v[2] = -z;
    sp[6].v[0] = -x; sp[6].v[1] = qy; sp[6].v[2] = z;
    sp[7].v[0] = x;  sp[7].v[1] = qy; sp[7].v[2] = z;
    func_002BC6C8(arg0, arg1, sp[0].v, fparg0, fparg1);
}
#endif
