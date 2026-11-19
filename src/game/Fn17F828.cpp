extern char Snd[];
extern "C" void sceVu0ApplyMatrix(float *, const float *, const float *);
extern "C" int move__6cOmSub(char *);
extern "C" void initMove1_pos__6cOmSubP4cObjiUiRC4cVecff(char *, char *, int, unsigned int, void *, float, float);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" float fRand0_1__Fv();
extern "C" void setMeshDispFromLayer__7cOmBaseUib(char *, unsigned int, int);
extern "C" void func_001B7300(char *, unsigned int, int);
extern "C" void func_0018A130(char *, int, float *, float *);
extern const unsigned char D_004236C0[];

struct Qf17 {
    float v[4] __attribute__((aligned(16)));
};
struct Cv17 {
    float v[3];
    Cv17 &operator=(const float *o)
    {
        if (v != o) {
            v[0] = o[0];
            v[1] = o[1];
            v[2] = o[2];
        }
        return *this;
    }
};

#ifdef NONMATCHING
// DRAFT: GAME 0x17F828 - 73 words; VU0 zero/vsub via inline asm. Tried: declaration swap (73), goto clear tail (80), inverted st if/else (80), goto move_call past body (76). Remaining: st branch and 0x764 layout, constant load order, 1.0f store placement
extern "C" void func_0017F828(char *self)
{
    unsigned char st = *(unsigned char *)(self + 0x2F5);
    if (st == 0) {
        if (*(unsigned char *)(self + 0x764) == 0) {
            *(unsigned char *)(self + 0x2F7) = 0;
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            return;
        }
        Cv17 dst;
        Qf17 in;
        Qf17 sub;
        Qf17 res;
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(dst));
        in.v[0] = 0.7f;
        in.v[1] = 0.0f;
        in.v[2] = 0.0f;
        in.v[3] = 1.0f;
        sceVu0ApplyMatrix(in.v, (float *)(self + 0x80), in.v);
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(sub));
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0"
                         : "=m"(sub)
                         : "r"(*(float **)(self + 0xF0)), "r"(in.v));
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(res) : "r"(sub.v));
        dst = res.v;
        initMove1_pos__6cOmSubP4cObjiUiRC4cVecff(self + 0x600, self, -1, 10, &dst, 0.1f, 0.1f);
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x6B, self, 0, 0, 0, 0);
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F5) = 1;
        *(unsigned char *)(self + 0x765) = 1;
        *(unsigned char *)(self + 0x2F7) = 0;
    } else if (st != 1) {
        return;
    }
    if (move__6cOmSub(self + 0x600) == 0) {
        *(unsigned char *)(self + 0x2F7) = 0;
        *(unsigned char *)(self + 0x764) = 0;
        *(unsigned char *)(self + 0x765) = 0;
        *(unsigned char *)(self + 0x2F4) = 0;
        *(unsigned char *)(self + 0x2F5) = 0;
        *(unsigned char *)(self + 0x2F6) = 0;
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x192588 - 11 words; $v0/$v1 reload choice and store order in bit-3 blocks differ. Tried: plain shifts (52), != 0 (52), long b flags (15), local q reload (11), fl temp (11), volatile stores (27, 11)
extern "C" void func_00192588(char *self)
{
    Qf17 tmp;
    char *p = *(char **)(self + 0x604);
    if (p == 0) {
        return;
    }
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(tmp) : "r"(p + 0x10));
    *(Cv17 *)(self + 0x5C0) = tmp.v;
    char *q = *(char **)(self + 0x604);
    long f = *(unsigned int *)(q + 0x60);
    long b = (f >> 2) & 1;
    if (b) {
        b = (f >> 6) & 1;
        if (b) {
            *(unsigned char *)(self + 0x2F4) = 2;
            *(unsigned int *)(self + 0x5B0) |= 1;
            *(unsigned char *)(self + 0x2F5) = 0;
        } else {
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F4) = 1;
        }
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
    q = *(char **)(self + 0x604);
    f = *(unsigned int *)(q + 0x60);
    b = (f >> 3) & 1;
    if (b) {
        float r = fRand0_1__Fv();
        if (r < 0.8f) {
            unsigned int fl = *(unsigned int *)(self + 0x5B0);
            *(unsigned char *)(self + 0x2F4) = 2;
            fl |= 1;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned int *)(self + 0x5B0) = fl;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        } else {
            *(unsigned char *)(self + 0x2F7) = 0;
            *(unsigned char *)(self + 0x2F4) = 1;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
        }
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x18A3E8 - 80 words (312 vs 328 bytes), first draft; scale via VU0 vmulx with constant 0x3CA3D70A (0.02f) in inline asm. Mirrors another unit that differs only in callee and data symbol
extern "C" void func_0018A3E8(char *self, unsigned int arg1, int arg2)
{
    setMeshDispFromLayer__7cOmBaseUib(self, arg1, 0);
    setMeshDispFromLayer__7cOmBaseUib(self, arg1 | 0x40, 1);
    func_001B7300(self, arg1, 0);
    func_001B7300(self, arg1 | 0x40, 0);
    *(unsigned int *)(self + 0x250) |= 0x10000;
    Qf17 p;
    Qf17 q;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(p) : "r"(self + 0x5C0));
    q.v[0] = 0.0f;
    q.v[1] = 0.0f;
    q.v[2] = 0.0f;
    q.v[3] = 1.0f;
    unsigned int kbits = 0x3CA3D70Au;
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tqmtc2.ni %2,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,%0"
                     : "=m"(p)
                     : "r"(p.v), "r"(kbits));
    int var = D_004236C0[arg2 * 2];
    while (var < D_004236C0[arg2 * 2] + D_004236C0[arg2 * 2 + 1] && *(unsigned char *)(self + 0x2B4) != var) {
        func_0018A130(self, var, p.v, q.v);
        var++;
    }
}
#endif
