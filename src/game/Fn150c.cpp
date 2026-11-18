// Fn150c: 0x150000-0x160000 free units, round 31.

// DRAFT: GAME 0x155C68
// diff: param copy order and sd scheduling (59 words); logic ok
#ifdef NONMATCHING
struct TabEnt155C68 { unsigned w0, w1; };
extern TabEnt155C68 D_004A5D80[];
extern "C" void func_00155C68(long *a, long *b, int idx)
{
    if (idx >= 0) {
        int i = idx & 0xFF;
        *a = (unsigned long)(D_004A5D80[i].w1 | 0x30000000) | ((long)(D_004A5D80[i].w0 & 0xFFFFFFF) << 32);
        *b = (unsigned long)(D_004A5D80[i + 1].w1 | 0x30000000) | ((long)(D_004A5D80[i + 1].w0 & 0xFFFFFFF) << 32);
    } else {
        int i = idx & 0xFF;
        *a = 0x10000000;
        *b = (unsigned long)(D_004A5D80[i + 1].w1 | 0x30000000) | ((long)(D_004A5D80[i + 1].w0 & 0xFFFFFFF) << 32);
    }
}
#endif

struct V3F { float x, y, z; };
// DRAFT: GAME 0x158198
// diff: stack slot reproduced via volatile member only; reg alloc (n/idx regs, mtc1 order) still differs
#ifdef NONMATCHING

// diff: original keeps iterator pointer in a stack slot (sw/lw 0($sp)); mine registers it (60 words)
struct Lst158198 {
    char *volatile p;
    V3F *at(int idx) { return (V3F *)(*(int *)(p + 4) + (int)p + idx * 16); }
};
extern "C" void func_00158198(char *self)
{
    char *n = *(char **)(self + 0x144);
    if (n) {
        char *a = *(char **)(self + 0x280);
        char *b = a + *(int *)(a + 0x10);
        Lst158198 base;
        base.p = b + *(int *)b;
        int idx = 0;
        do {
            unsigned fl = *(unsigned *)(n + 0x154);
            if (!(fl & 1)) {
                V3F *p = base.at(idx);
                if (!(fl & 0x200)) {
                    V3F *d = (V3F *)(n + 0xE0);
                    d->x = p->x;
                    d->y = p->y;
                    d->z = p->z;
                    V3F *e = *(V3F **)(n + 0xD0);
                    if (e != d) {
                        e->x = d->x;
                        e->y = d->y;
                        e->z = d->z;
                    }
                }
                if (!(*(unsigned char *)(n + 0x155) & 1)) {
                    *(float *)(n + 0x108) = 0.0f;
                    *(float *)(n + 0x104) = 0.0f;
                    *(float *)(n + 0x100) = 0.0f;
                }
                if (!(*(unsigned *)(n + 0x154) & 0x400)) {
                    *(float *)(n + 0x118) = 1.0f;
                    *(float *)(n + 0x114) = 1.0f;
                    *(float *)(n + 0x110) = 1.0f;
                }
            }
            n = *(char **)(n + 0x144);
            idx++;
        } while (n);
    }
}
#endif

// DRAFT: GAME 0x159200
// diff: original moves flags a1->t0 and idx into a1; mine keeps flags in a1 (reg alloc, ~50 words)
#ifdef NONMATCHING
extern "C" float func_002DA8D8(float, float, float);
extern "C" float func_00159200(float f, char *data, char *flags)
{
    char *fl = flags;
    int idx = (int)f;
    char *c = data + *(int *)(fl + 8);
    unsigned short n = *(unsigned short *)(data + 4);
    unsigned short *arr = (unsigned short *)(c + 8);
    float off = *(float *)c;
    float scale = *(float *)(c + 4);
    if (idx >= n - 1)
        return (float)arr[n - 1] * scale + off;
    float t = f - (float)idx;
    float a = (float)arr[idx] * scale + off;
    float b = (float)arr[idx + 1] * scale + off;
    unsigned mode = *(unsigned *)fl & 0xF00;
    if (mode == 0x300 || mode == 0x400 || mode == 0x500)
        return func_002DA8D8(b, a, t);
    return a * (1.0f - t) + b * t;
}
#endif

// DRAFT: GAME 0x15A590
// diff: FP mul/reg order only (16 words); formula and calls identical
#ifdef NONMATCHING
extern "C" float func_003A19F8(float);
extern "C" float func_003A18F0(float);
class cVec;
struct cVecQ15A590 { float x, y, z, w; };
class Quaternion {
public:
    float q[4];
    void SetEulerXYZ(const cVec &v);
};
void Quaternion::SetEulerXYZ(const cVec &v)
{
    const cVecQ15A590 &e = (const cVecQ15A590 &)v;
    float ax = e.x * 0.5f;
    float ay = e.y * 0.5f;
    float az = e.z * 0.5f;
    float sx = func_003A19F8(ax);
    float cx = func_003A18F0(ax);
    float sy = func_003A19F8(ay);
    float cy = func_003A18F0(ay);
    float sz = func_003A19F8(az);
    float cz = func_003A18F0(az);
    q[2] = cx * cy * sz - sx * sy * cz;
    q[0] = sx * cy * cz - cx * sy * sz;
    q[1] = cx * cz * sy + sx * sz * cy;
    q[3] = cx * cz * cy + sx * sz * sy;
}
#endif

// FUNCTION: GAME 0x1632E8
extern "C" int func_001FA710(char *);
extern "C" void func_001633A0(char *);
extern "C" void func_001634E0(char *);
extern "C" void func_00163F00(char *);
extern "C" void func_002AAA40(char *);
extern char D_00569B70[];
extern "C" void func_001632E8(char *self)
{
    *(int *)(*(char **)(self + 0xE0) + 0x84) = func_001FA710(D_00569B70);
    *(unsigned *)(*(char **)(self + 0xE4) + 0x2C) &= 0xF7FFFFFF;
    switch (*(unsigned char *)(self + 0x64)) {
    case 0:
        func_001633A0(self);
        break;
    case 1:
        func_001634E0(self);
        break;
    case 2:
    case 3:
        func_00163F00(self);
        break;
    }
    func_002AAA40(self);
}

// DRAFT: GAME 0x160F38
// diff: bit-6 test compiles to dsll32/dsra32 instead of dsrl 6; branch layout (46 words)
#ifdef NONMATCHING
extern int D_00747A2C[];
extern unsigned D_00747A24;
extern unsigned D_00747A88;
extern int D_003C2648;
extern "C" void func_002BF268(int);
extern "C" int func_00160F38(char *self)
{
    if (D_00747A2C[2] & 0x800)
        return 1;
    unsigned long w = D_00747A2C[3];
    if ((long)w < 0 || (w >> 6 & 1))
        return 1;
    switch (*(short *)(self + 0x52)) {
    case 0:
        func_002BF268(D_003C2648);
        (*(unsigned short *)(self + 0x52))++;
    case 1:
        if (D_00747A88 & 0x40000000)
            return 0;
    }
    D_00747A24 &= ~3;
    *(short *)(self + 0x52) = 0;
    return 1;
}
#endif
