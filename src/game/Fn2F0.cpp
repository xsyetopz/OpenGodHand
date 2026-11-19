// Unnamed units in 0x2F0000-0x2FFFFF: small constructors and helpers.
struct espWork;
extern "C" void *func_002B5E50();
extern "C" void func_002B5CF0(void *, void *);
extern "C" void *func_002B5C20(void *, int, int);
extern "C" void *func_002FBCC8(void *);
extern "C" void PushEsp__FP7espWork(espWork *);
extern char D_0044FB60[], D_0044E090[];

// FUNCTION: GAME 0x2FBE50
extern "C" void func_002FBE50(void *self)
{
    func_002B5CF0(self, func_002B5E50());
    PushEsp__FP7espWork((espWork *)self);
}

// FUNCTION: GAME 0x2FBD98
extern "C" void *func_002FBD98(void *self)
{
    func_002B5C20(self, 0, 0);
    *(char **)((char *)self + 0xF0) = D_0044FB60;
    return self;
}

// FUNCTION: GAME 0x2FFA90
extern "C" void *func_002FFA90(void *self)
{
    if (self) {
        func_002FBCC8(self);
        *(char **)((char *)self + 0xF0) = D_0044E090;
    }
    return self;
}

extern "C" void func_002FBE28(void *, int);
extern void ReleaseObj__FP4cObj(void *);
extern char D_0044EE38[], D_0044F4F8[], D_0044F6D8[], D_0044F448[];
#define CTOR(NAME, VT) \
extern "C" void *NAME(char *self) \
{ \
    func_002FBCC8(self); \
    *(void **)(self + 0x2B0) = 0; \
    *(float *)(self + 0x2D4) = 1.0f; \
    *(char **)(self + 0xF0) = VT; \
    *(void **)(self + 0x2B4) = 0; \
    *(void **)(self + 0x2B8) = 0; \
    *(void **)(self + 0x2BC) = 0; \
    *(void **)(self + 0x2C0) = 0; \
    *(void **)(self + 0x2C4) = 0; \
    *(void **)(self + 0x2C8) = 0; \
    *(void **)(self + 0x2D8) = 0; \
    *(void **)(self + 0x2DC) = 0; \
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)(self + 0x2F0))); \
    return self; \
}
struct Qv { float f[4]; };

// FUNCTION: GAME 0x2F27E8
extern "C" void func_002F27E8(char *self, int a)
{
    *(char **)(self + 0xF0) = D_0044EE38;
    char *o = *(char **)(self + 0x2B0);
    if (o) {
        *(unsigned *)(o + 0x250) |= 2;
        ReleaseObj__FP4cObj(*(void **)(self + 0x2B0));
    }
    func_002FBE28(self, a);
}

// FUNCTION: GAME 0x2F61C8
CTOR(func_002F61C8, D_0044F4F8)

// FUNCTION: GAME 0x2F7110
CTOR(func_002F7110, D_0044F6D8)


// FUNCTION: GAME 0x2F56C0
extern "C" void *func_002F56C0(char *self)
{
    func_002FBCC8(self);
    *(void **)(self + 0x2B0) = 0;
    *(float *)(self + 0x2D4) = 1.0f;
    *(char **)(self + 0xF0) = D_0044F448;
    *(void **)(self + 0x2B4) = 0;
    *(void **)(self + 0x2B8) = 0;
    *(void **)(self + 0x2BC) = 0;
    *(void **)(self + 0x2C0) = 0;
    *(void **)(self + 0x2C4) = 0;
    *(void **)(self + 0x2C8) = 0;
    *(void **)(self + 0x2D8) = 0;
    *(void **)(self + 0x2DC) = 0;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)(self + 0x300)));
    *(void **)(self + 0x2F0) = 0;
    return self;
}

struct cVec { float x, y, z, w; };
extern "C" void func_002B6160(cVec *, void *);

// FUNCTION: GAME 0x2F2758
extern "C" void func_002F2758(char *self)
{
    char *a = *(char **)(self + 0x2B0);
    if (a && *(char **)(self + 0x114)) {
        if (*(unsigned *)(*(char **)(self + 0x114) + 0x250) & 2)
            *(unsigned *)(a + 0x250) |= 2;
        else
            *(unsigned *)(a + 0x250) &= ~2u;
        if (*(unsigned *)(*(char **)(self + 0x114) + 0x250) & 0x8000)
            *(unsigned *)(*(char **)(self + 0x2B0) + 0x250) |= 0x8000;
        else
            *(unsigned *)(*(char **)(self + 0x2B0) + 0x250) &= ~0x8000u;
    }
}

static inline void cpv2(cVec *d, const cVec *q)
{
    if (d != q) {
        d->x = q->x;
        d->y = q->y;
        d->z = q->z;
    }
}

// FUNCTION: GAME 0x2F6B40
extern "C" int func_002F6B40(char *self)
{
    cVec p;
    func_002B6160(&p, self);
    cpv2((cVec *)(self + 0x2B0), &p);
    *(float *)(self + 0x2C0) = (float)*(unsigned char *)(*(char **)(self + 0x110) + 0x18C) * 0.01f;
    return 1;
}

// FUNCTION: GAME 0x2F9D30
extern "C" int func_002F9D30(char *self)
{
    float v = *(float *)(*(char **)(self + 0x110) + 0x13C);
    if (v == 0.0f)
        *(float *)(self + 0x2B0) = 30.0f;
    else
        *(float *)(self + 0x2B0) = v;
    v = *(float *)(*(char **)(self + 0x110) + 0x148);
    if (v == 0.0f)
        *(float *)(self + 0x2B8) = 3.0f;
    else
        *(float *)(self + 0x2B8) = v;
    char *o = *(char **)(self + 0x110);
    if (*(float *)(o + 0x14C) == 0.0f)
        *(float *)(self + 0x2BC) = 40.0f;
    else
        *(float *)(self + 0x2BC) = *(float *)(o + 0x148);
    *(int *)(self + 0x2B4) = *(signed char *)(*(char **)(self + 0x110) + 0x18C);
    return 1;
}

#ifdef NONMATCHING
static inline int Lt(const int &v, int i) { return i < v; }
static inline int slotAt(char *p, int i)
{
    if (i >= 0 && Lt(*(unsigned char *)(p + 0x2B4), i))
        return (*(int **)(p + 0x278))[i];
    return 0;
}

static inline int Lt2(const int &v, int i) { unsigned char ok = i < v; return ok; }
static inline int slotAt2(char *p, int i)
{
    if (i >= 0 && Lt2(*(unsigned char *)(p + 0x2B4), i))
        return (*(int **)(p + 0x278))[i];
    return 0;
}

// DRAFT: GAME 0x2F53A8 (20 words: Lt(const int&) spill fixed 1st call; 2nd call needs andi 0xFF on slt + lbu/spill before bltz + 0x2B0 loaded before 0x114; tried uchar-returning Lt2, n local+&n, inline r)
extern "C" int func_002F53A8(char *self)
{
    char *h = *(char **)(self + 0x110);
    char *p = *(char **)(self + 0x114);
    *(int *)(self + 0x2B0) = *(signed char *)(h + 0x18C);
    if (!p)
        return 0;
    int i = *(signed char *)(h + 0xBE);
    if (i < 0)
        return 0;
    if (!slotAt(p, i))
        return 0;
    return slotAt2(*(char **)(self + 0x114), *(int *)(self + 0x2B0)) != 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2FEBE8
// diff: 7 words; reg alloc only (original cur in v0, const 1 in v1; ours cur in v1); tried cur as int/ushort local, reordered branches, hoisted b
extern "C" void func_002FEBE8(char *self, unsigned short a, int mode)
{
    unsigned short *p = (unsigned short *)(self + 0x22C);
    int cur = *p;
    if (cur == 0) {
        *p = a;
        return;
    }
    int b = *(unsigned short *)(self + 0x224);
    if (mode == 1 || (mode == 0 && cur - b < a))
        *p = a + b;
}
#endif

// FUNCTION: GAME 0x2FEB18
// "% 2" on the unsigned long shift avoids the dsll32/dsra32 sign-extension that "& 1" and an int cast produce
extern "C" void func_002FEB18(char *self)
{
    long f = *(int *)(self + 0x11C);
    if (!(f & 0x800000)) {
        char *o = *(char **)(self + 0x114);
        if (!o || !(*(unsigned *)(o + 0x250) & 2) || ((unsigned long)f >> 7) % 2) {
            char *vt = *(char **)(self + 0xF0);
            ((void (*)(char *))*(int *)(vt + 0x84))(self + *(short *)(vt + 0x80));
        }
    }
}

#ifdef NONMATCHING
static inline unsigned char isEsp(int id)
{
    if (id < 0x500)
        return 0;
    return id < 0x600;
}
struct ObjVec { int pad; char **b; char **e; };
extern ObjVec *objArray;

// DRAFT: GAME 0x2FA470
// diff: ~10 words; original keeps the range test in a3 (slti/bnez/daddu pattern) and reloads objArray via t1; ours uses movn or a different phi (3 probes).
extern "C" void func_002FA470(int on)
{
    for (char **i = objArray->b; i != objArray->e; i++) {
        char *o = *i;
        int id = *(unsigned short *)(o + 0x2FE);
        if (isEsp(id)) {
            if (on)
                *(unsigned *)(o + 0x250) |= 0x8000;
            else
                *(unsigned *)(o + 0x250) &= 0xFFFF7FFF;
        }
    }
}
#endif
