#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")
extern char Snd[];
extern "C" void *func_001B6E90(void *);
extern "C" void *func_001C7D98(void *);
extern "C" void func_0016F640(void *, int);
extern const char D_00422EB8[];
extern const char D_00423E48[];
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" void func_001851C0(void *, int);
extern "C" int checkDamage__7cOmBaseP11cDamageTake(void *self, void *dmg);

// FUNCTION: GAME 0x183510
extern "C" void func_00183510(void *o)
{
    SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 10, o, 0, 0, 0, 0);
}

// FUNCTION: GAME 0x185180
extern "C" void func_00185180(char *self)
{
    if (*(unsigned char *)(self + 0x65B) == 0) {
        func_001851C0(self, 4);
        *(unsigned char *)(self + 0x65B) = 1;
    }
}

// FUNCTION: GAME 0x18F5D0
extern "C" void func_0018F5D0(char *self)
{
    int r = checkDamage__7cOmBaseP11cDamageTake(self, *(void **)(self + 0x654));
    if (r == 1) {
        *(unsigned char *)(self + 0x2F4) = r;
        *(unsigned char *)(self + 0x2F5) = 0;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
}

extern "C" float fRand1_1__Fv();

// FUNCTION: GAME 0x1810A0
extern "C" void func_001810A0(char *self)
{
    if (*(short *)(self + 0x600) > 0) {
        *(short *)(self + 0x600) = *(short *)(self + 0x600) - 1;
        if (*(short *)(self + 0x600) != 0) {
            float v = *(float *)(self + 0x604) + fRand1_1__Fv() * 0.015f;
            (*(float **)(self + 0xF0))[1] = v;
        } else {
            (*(float **)(self + 0xF0))[1] = *(float *)(self + 0x604);
        }
    }
}

// FUNCTION: GAME 0x183848
extern "C" void *func_00183848(char *self)
{
    char *p = self + 0x670;
    func_001B6E90(self);
    *(const void **)(self + 0x214) = D_00422EB8;
    for (int i = 0x13; i != -1; i--) {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    }
    ZQ(self, 0xDF0);
    ZQ(self, 0xE00);
    return self;
}

// FUNCTION: GAME 0x18F110
extern "C" void *func_0018F110(char *self)
{
    func_001C7D98(self);
    *(const void **)(self + 0x214) = D_00423E48;
    ZQ(self, 0x660);
    ZQ(self, 0x670);
    char *p = self + 0x680;
    for (int i = 6; i != -1; i--) {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x20);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        func_0016F640(p, 0);
        p += 0x60;
    }
    return self;
}

struct Qv180 { float v[4] __attribute__((aligned(16))); };
struct SvM180 {
    float v[3];
    SvM180 &operator=(const float *o)
    {
        if (v != o) {
            v[0] = o[0];
            v[1] = o[1];
            v[2] = o[2];
        }
        return *this;
    }
};
struct ObjH180 {
    char p0[0xF0];
    float *tgt;
    char p1[0x2F4 - 0xF4];
    char c4, c5, c6, c7;
    char p2[0x490 - 0x2F8];
    float org[4];
    char p3[0x5B0 - 0x4A0];
    unsigned int fl;
    char p4[0x5C0 - 0x5B4];
    SvM180 out;
};

#define VSUB_FN(name)                                                                                            \
    extern "C" void name(ObjH180 *self)                                                                          \
    {                                                                                                            \
        long f = self->fl;                                                                                       \
        long b = (f >> 1) & 1;                                                                                   \
        if (b == 0) {                                                                                            \
            float *tp = self->tgt;                                                                               \
            float *o = self->org;                                                                                \
            Qv180 t;                                                                                             \
            Qv180 d;                                                                                             \
            __asm__ volatile("sqc2 $vf0,%0" : "=m"(d));                                                          \
            __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" \
                             : "=m"(d)                                                                           \
                             : "r"(tp), "r"(o));                                                                 \
            __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(t) : "r"(d.v));                          \
            self->out = t.v;                                                                                     \
            self->c5 = 0;                                                                                        \
            self->fl |= 1;                                                                                       \
            self->c4 = 2;                                                                                        \
            self->c6 = 0;                                                                                        \
            int g = self->fl;                                                                                    \
            self->c7 = 0;                                                                                        \
            self->fl = g & -5;                                                                                   \
        }                                                                                                        \
    }

// FUNCTION: GAME 0x1824E8
VSUB_FN(func_001824E8)
// FUNCTION: GAME 0x187658
VSUB_FN(func_00187658)
// FUNCTION: GAME 0x18BFA0
VSUB_FN(func_0018BFA0)
