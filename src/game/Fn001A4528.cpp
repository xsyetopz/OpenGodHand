// Fn001A4528: free units 0x1A4528, 0x1A4BD0, 0x1A9858, 0x1AE798. The two init units zero VU0 blocks through sqc2 and call the object init at 0x1B6E90.

extern "C" void *func_001B6E90(void *self);
extern "C" void func_0016F640(void *p, int v);
extern const char D_00427CF0[];
extern const char D_00428090[];

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")

// FUNCTION: GAME 0x1AE798
extern "C" void *func_001AE798(char *self)
{
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00428090;
    char *p = self + 0x620;
    int n = 8;
    do {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        n--;
        p += 0x60;
    } while (n != -1);
    char *q = self + 0x990;
    ZQ(self, 0x9E0);
    ZQ(self, 0x9F0);
    ZQ(self, 0xA00);
    ZQ(self, 0xA10);
    ZQ(self, 0xA20);
    ZQ(self, 0xA30);
    ZQ(self, 0xA40);
    ZQ(self, 0xA50);
    ZQ(self, 0xA60);
    ZQ(self, 0xA70);
    ZQ(self, 0xA80);
    ZQ(self, 0xA90);
    ZQ(self, 0xAA0);
    ZQ(self, 0xAB0);
    *(unsigned char *)(self + 0x990) = 0;
    *(unsigned char *)(q + 0x1) = 0;
    *(unsigned char *)(q + 0x2) = 0;
    *(int *)(q + 0x4) = 0;
    *(int *)(q + 0x8) = 0;
    *(int *)(q + 0x30) = 0;
    *(int *)(q + 0x34) = 0;
    *(int *)(q + 0x38) = 0;
    *(int *)(q + 0x3C) = 0;
    *(int *)(q + 0x130) = 0;
    *(int *)(q + 0x134) = 0;
    *(int *)(q + 0x138) = 0;
    *(int *)(q + 0x13C) = 0;
    unsigned i = 0;
    int *v = (int *)(self + 0x99C);
    do {
        *v = 0;
        i++;
        v++;
    } while (i < 8U);
    return self;
}

// FUNCTION: GAME 0x1A9858
extern "C" void *func_001A9858(char *self)
{
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00427CF0;
    ZQ(self, 0x630);
    char *p = self + 0x640;
    int n = 8;
    do {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        n--;
        p += 0x60;
    } while (n != -1);
    ZQ(self, 0x9B0);
    ZQ(self, 0x9C0);
    int a = 0x4E2;
    int b = 0x101;
    *(int *)(self + 0x9D0) = 0;
    *(int *)(self + 0x9D4) = 0;
    *(int *)(self + 0x9EC) = a;
    *(int *)(self + 0x9F0) = b;
    *(int *)(self + 0x9F4) = a;
    *(int *)(self + 0x9F8) = b;
    *(int *)(self + 0x604) = 0;
    *(int *)(self + 0x608) = 0;
    int m = 2;
    int *q = (int *)(self + 0x614);
    do {
        *q = 0;
        m--;
        q--;
    } while (m >= 0);
    return self;
}

#ifdef NONMATCHING

extern "C" int func_001B76B0(void *);
extern "C" void func_001B76D8(void *);
extern "C" void func_002A87E8(void *, int);
extern "C" void sceVu0ApplyMatrix(float *, void *, float *);
extern char D_003BDB78[];

#define VCOPY(dst, src) __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,0(%0)" : : "r"(dst), "r"(src) : "memory")

// DRAFT: GAME 0x1A4528
// 64 differing words (260 vs 292 bytes). Reference re-indexes the table pointer (addiu $a2 / daddu $t0 / second addiu $v1 per branch); compiled form lacks those 8 instructions. Tried: struct-typed table, offset via short load, unsigned long pair load.
extern "C" void func_001A4528(char *self)
{
    if (func_001B76B0(self) == 0) return;
    unsigned int idx = (unsigned char)self[0x2F4];
    char *e = D_003BDB78 + (idx << 3);
    short a1 = *(short *)(e + 2);
    unsigned int fn;
    int off;
    if (a1 >= 0) {
        char *base = *(char **)(self + *(short *)(e + 4));
        unsigned long s0 = *(unsigned long *)(base + (a1 << 3) - 8);
        fn = (unsigned int)(s0 >> 32);
        off = (short)(s0 & 0xFFFF) + *(short *)e;
    } else {
        fn = *(unsigned int *)(e + 4);
        off = *(short *)e;
    }
    ((void (*)(char *))fn)(self + off);
    float v[4];
    float tmp[4];
    VCOPY(tmp, self + 0x770);
    sceVu0ApplyMatrix(tmp, self + 0x80, tmp);
    VCOPY(v, tmp);
    float *d = (float *)(self + 0x780);
    if (d != v) {
        d[0] = v[0];
        d[1] = v[1];
        d[2] = v[2];
    }
    float *f = (float *)(self + 0x784);
    *f = *f - 1.0f;
    func_002A87E8(self, 0);
    func_001B76D8(self);
}

// DRAFT: GAME 0x1A4BD0
// 75 differing words (304 vs 292 bytes). Reference keeps self in $s0 under a 0x70 frame; compiled form needs a third saved register and a 0x80 frame, so the s0/s1/s2 allocation differs. Tried: unsigned reads, declaration order, b-init ordering, direct call, float init array (86 words).
extern "C" void startSoftEvent__9cScenario14eSoftEventType(void *self, int ev);
extern "C" void setSubScrCamera__11cCamManagerUc(void *self, int v);
extern "C" char *g_Sce;
extern "C" unsigned int D_00747A78;
extern "C" char CamManager[];

extern "C" void func_001A4BD0(char *self)
{
    if ((unsigned char)self[0x763] != 0) {
        startSoftEvent__9cScenario14eSoftEventType(g_Sce, 0);
        D_00747A78 |= 0x10000;
        char *vt = *(char **)(self + 0x214);
        float *(*fn)(char *) = *(float *(**)(char *))(vt + 0x84);
        float *r = fn(self + *(short *)(vt + 0x80));
        float a[4];
        float b[4];
        float c[4];
        float d[4];
        VCOPY(a, r);
        b[0] = 1.0f;
        b[1] = 1.0f;
        b[2] = 4.0f;
        b[3] = 1.0f;
        VCOPY(d, b);
        sceVu0ApplyMatrix(d, self + 0x80, d);
        VCOPY(c, d);
        b[0] = c[0];
        b[1] = c[1];
        b[2] = c[2];
        setSubScrCamera__11cCamManagerUc(CamManager, 0);
        float *p = (float *)(CamManager + 0xE90);
        if ((float *)a != p) {
            p[0] = a[0];
            p[2] = a[2];
            p[1] = a[1];
        }
        float *q = (float *)(CamManager + 0xEA0);
        if (b != q) {
            q[0] = b[0];
            q[2] = b[2];
            q[1] = b[1];
        }
    }
}

#endif
