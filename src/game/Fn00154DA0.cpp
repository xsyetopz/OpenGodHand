// Fn00154DA0: free units 0x154DA0, 0x1565A0, 0x1569A0, 0x17F6C0 (VU0 stack vectors and DMA tags).
extern "C" void *func_00154E98(void);
extern int D_00747BB8;
extern char Snd[];
extern "C" int move__6cOmSub(char *);
extern "C" void initMove1_pos__6cOmSubP4cObjiUiRC4cVecff(char *, char *, int, unsigned int, const void *, float, float);
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" void sceVu0ApplyMatrix(float *, const float *, const float *);

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

#ifdef NONMATCHING
static inline void vsub_to(float *dst, const float *a, const float *b)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)dst) : "r"(a), "r"(b));
}
static inline void qcopy(float *dst, const float *src)
{
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)dst) : "r"(src));
}

// DRAFT: GAME 0x1565A0 - 55 words (264 vs 288 bytes); frame matched; guarded u=t copy and cross-product load order differ; tried: void return, out[2]/out[1] order, hoisted temp pointer, load-then-store copy (56, reverted).
extern "C" void *func_001565A0(float *out, const float *a1, const float *a2, const float *a3)
{
    Sv u;
    Sv w;
    float t[4] __attribute__((aligned(16)));
    float *tp = t;
    {
        Sv d;
        vsub_to(d.v, a2, a1);
        qcopy(tp, d.v);
    }
    u = tp;
    {
        Sv d;
        vsub_to(d.v, a3, a1);
        qcopy(tp, d.v);
    }
    float *uv = u.v;
    w.v[0] = t[0];
    w.v[1] = t[1];
    w.v[2] = t[2];
    float rx = uv[1] * t[2] - uv[2] * t[1];
    float ry = uv[2] * t[0] - uv[0] * t[2];
    float rz = uv[0] * t[1] - uv[1] * t[0];
    t[0] = rx;
    t[1] = ry;
    t[2] = rz;
    t[3] = 1.0f;
    out[3] = 1.0f;
    out[0] = uv[1] * rz - uv[2] * ry;
    out[2] = uv[0] * ry - uv[1] * rx;
    out[1] = uv[2] * rx - uv[0] * rz;
    return out;
}

// DRAFT: GAME 0x1569A0 - 55 words expected; instruction words identical to 0x1565A0, so the same body is used.
extern "C" void *func_001569A0(float *out, const float *a1, const float *a2, const float *a3)
{
    Sv u;
    Sv w;
    float t[4] __attribute__((aligned(16)));
    float *tp = t;
    {
        Sv d;
        vsub_to(d.v, a2, a1);
        qcopy(tp, d.v);
    }
    u = tp;
    {
        Sv d;
        vsub_to(d.v, a3, a1);
        qcopy(tp, d.v);
    }
    float *uv = u.v;
    w.v[0] = t[0];
    w.v[1] = t[1];
    w.v[2] = t[2];
    float rx = uv[1] * t[2] - uv[2] * t[1];
    float ry = uv[2] * t[0] - uv[0] * t[2];
    float rz = uv[0] * t[1] - uv[1] * t[0];
    t[0] = rx;
    t[1] = ry;
    t[2] = rz;
    t[3] = 1.0f;
    out[3] = 1.0f;
    out[0] = uv[1] * rz - uv[2] * ry;
    out[2] = uv[0] * ry - uv[1] * rx;
    out[1] = uv[2] * rx - uv[0] * rz;
    return out;
}

// DRAFT: GAME 0x154DA0 - 55 words (240 vs 244 bytes); off hoisted, base/v spilled via volatile locals, por-zeroed sq tail; a2/a3 reused for temps and one word missing before jal; named a3<<6 temp and tail reorder tried, no change (7 attempts).
extern "C" void func_00154DA0(char *a0, char *a1, int a2, int a3)
{
    int off = a2 << 2;
    *(int *)(a0 + (off + (a3 << 6)) + 0x300) = (int)a1;
    unsigned long *d = (unsigned long *)a1;
    d[2] = 0x1000000000008001UL;
    *(unsigned int *)(a1 + 0x18) = 0xE;
    d[0] = 0x10000002UL;
    *(unsigned int *)(a1 + 0x8) = 0x11000000;
    *(unsigned int *)(a1 + 0xC) = 0x50000002;
    *(unsigned int *)(a1 + 0x1C) = 0;
    int base = *(int *)(a0 + 0x388);
    volatile int sb = base;
    int idx = (unsigned char)a0[0x384];
    int tb = base + off;
    int v = *(int *)(tb + 0x20) + base;
    volatile int sv = v;
    idx += *(unsigned char *)(v + 0x16);
    d[5] = 6;
    d[4] = *(unsigned long *)(idx * 0xB0 + (char *)&D_00747BB8);
    unsigned long hi = (unsigned long)((unsigned int)(a1 + 0x40) & 0x0FFFFFFFU);
    d[0] = (hi << 32) | 0x50000002UL;
    char *w = (char *)func_00154E98() - 0x8000;
    unsigned long zq;
    __asm__ volatile("por %0,$zero,$zero\n\tsq %0,0x7FF0(%1)" : "=&r"(zq) : "r"(w) : "memory");
    *(unsigned long *)(w + 0x7FF0) = 0x60000000UL;
    *(unsigned int *)(w + 0x7FFC) = 0;
    *(unsigned int *)(w + 0x7FF8) = 0;
}

// DRAFT: GAME 0x17F6C0 - 89 words (348 vs 356 bytes); state machine on s1[0x2F5] and callee order match; prologue and register allocation differ (original saves s0/s1/s2/ra with sq/sd); float-array locals (94 words, 396 bytes) replaced by Sv locals (2 attempts).
extern "C" void func_0017F6C0(char *s1)
{
    unsigned char st = (unsigned char)s1[0x2F5];
    if (st == 0) {
        if ((unsigned char)s1[0x764] != 1) {
            Sv vec;
            vec.v[0] = -0.6f;
            vec.v[3] = 1.0f;
            sceVu0ApplyMatrix(vec.v, (float *)(s1 + 0x80), vec.v);
            float *src = *(float **)(s1 + 0xF0);
            Sv dif;
            dif.v[0] = src[0] - vec.v[0];
            dif.v[1] = src[1] - vec.v[1];
            dif.v[2] = src[2] - vec.v[2];
            Sv fin;
            fin = dif.v;
            initMove1_pos__6cOmSubP4cObjiUiRC4cVecff(s1 + 0x600, s1, -1, 10, fin.v, 0.1f, 0.1f);
            SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x6B, s1, 0, 0, 0, 0);
            s1[0x2F5] = 1;
            s1[0x765] = 1;
            s1[0x2F6] = 0;
            s1[0x2F7] = 0;
        }
    } else if (st == 1) {
        if (move__6cOmSub(s1 + 0x600) == 0) {
            s1[0x2F7] = 0;
            s1[0x764] = 1;
            s1[0x765] = 0;
            s1[0x2F4] = 0;
            s1[0x2F5] = 0;
            s1[0x2F6] = 0;
        }
    }
}
#endif
