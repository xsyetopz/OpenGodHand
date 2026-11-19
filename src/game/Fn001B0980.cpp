// Fn001B0980: free units 0x1B0980, 0x1B36E0, 0x1B7EE0, 0x1BD580 (VU0 and MMI paths).
extern "C" void *func_001B6E90(void *self);
extern const char D_00428650[];
extern const char D_00429420[];

#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")

// FUNCTION: GAME 0x1B36E0
extern "C" void *func_001B36E0(char *self)
{
    func_001B6E90(self);
    char *v = self + 0x610;
    *(const char **)(self + 0x214) = D_00428650;
    ZQ(self, 0x660);
    ZQ(self, 0x670);
    ZQ(self, 0x680);
    ZQ(self, 0x690);
    ZQ(self, 0x6A0);
    ZQ(self, 0x6B0);
    ZQ(self, 0x6C0);
    ZQ(self, 0x6D0);
    ZQ(self, 0x6E0);
    ZQ(self, 0x6F0);
    ZQ(self, 0x700);
    ZQ(self, 0x710);
    ZQ(self, 0x720);
    ZQ(self, 0x730);
    *(unsigned char *)(self + 0x610) = 0;
    unsigned i = 0;
    *(int *)(v + 0x13C) = 0;
    char *p = self + 0x61C;
    *(unsigned char *)(v + 1) = 0;
    *(unsigned char *)(v + 2) = 0;
    *(int *)(v + 4) = 0;
    *(int *)(v + 8) = 0;
    *(int *)(v + 0x30) = 0;
    *(int *)(v + 0x34) = 0;
    *(int *)(v + 0x38) = 0;
    *(int *)(v + 0x3C) = 0;
    *(int *)(v + 0x130) = 0;
    *(int *)(v + 0x134) = 0;
    __asm__ volatile("" : : "m"(*(char *)v) : "memory");
    *(int *)(v + 0x138) = 0;
    do {
        *(int *)p = 0;
        i++;
        p += 4;
    } while (i < 8);
    *(int *)(self + 0x600) = 0;
    return self;
}

// FUNCTION: GAME 0x1BD580
extern "C" void *func_001BD580(char *self)
{
    func_001B6E90(self);
    *(const char **)(self + 0x214) = D_00429420;
    ZQ(self, 0x600);
    char *v = self + 0x610;
    ZQ(self, 0x660);
    ZQ(self, 0x670);
    ZQ(self, 0x680);
    ZQ(self, 0x690);
    ZQ(self, 0x6A0);
    ZQ(self, 0x6B0);
    ZQ(self, 0x6C0);
    ZQ(self, 0x6D0);
    ZQ(self, 0x6E0);
    ZQ(self, 0x6F0);
    ZQ(self, 0x700);
    ZQ(self, 0x710);
    ZQ(self, 0x720);
    ZQ(self, 0x730);
    *(unsigned char *)(self + 0x610) = 0;
    unsigned i = 0;
    *(int *)(v + 0x13C) = 0;
    char *p = self + 0x61C;
    *(unsigned char *)(v + 1) = 0;
    *(unsigned char *)(v + 2) = 0;
    *(int *)(v + 4) = 0;
    *(int *)(v + 8) = 0;
    *(int *)(v + 0x30) = 0;
    *(int *)(v + 0x34) = 0;
    *(int *)(v + 0x38) = 0;
    *(int *)(v + 0x3C) = 0;
    *(int *)(v + 0x130) = 0;
    *(int *)(v + 0x134) = 0;
    __asm__ volatile("" : : "m"(*(char *)v) : "memory");
    *(int *)(v + 0x138) = 0;
    for (i = 0; i < 8; i++) {
        *(int *)p = 0;
        p += 4;
    }
    return self;
}

extern "C" void *Getplayer__Fv();
extern "C" float capVu0LengthSq__FPCf(const float *v);
extern "C" int Dest_ck__FPCffT0f(int a, int b, float c, float d);
extern "C" void set__13cActionButton12eScePriority8eActType11eActBtnTypePvT48eActFunc(void *self, int pri, int type, int btn, void *p, void *q, void *f);
extern char g_ActBtn[];
typedef void *(*TblFn)(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x1B0980
extern "C" float capVu0LengthSq__FPCf(const float *v);
extern "C" float sqrtf(float x);
extern "C" void SetDamageCollActive__11cDamageUnitb(void *self, int b);
extern "C" void SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *snd, int blk, void *a2, void *obj, void *parts, unsigned int u, int i, int j);
extern char Snd[];

extern "C" void func_001B0980(char *self)
{
    unsigned char mode = *(unsigned char *)(self + 0x2F6);
    if (mode == 0) {
        char *a = self + 0x610;
        char *b = self + 0x5C0;
        if (a != b) {
            *(float *)a = *(float *)b;
            *(float *)(a + 4) = *(float *)(b + 4);
            *(float *)(a + 8) = *(float *)(b + 8);
        }
        unsigned kb = 0x3DA3D70Au;
        float kf = *(float *)&kb;
        __asm__ volatile("lqc2 $vf4,0x610(%0)" : : "r"(self) : "memory");
        unsigned kbi = *(unsigned *)&kf;
        __asm__ volatile("qmtc2.ni %0,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,0x610(%1)" : : "r"(kbi), "r"(self) : "memory");
        long flags = *(unsigned int *)(self + 0x5B4);
        unsigned char f = (flags >> 2) & 1;
        if (f == 1) {
            float len = sqrtf(capVu0LengthSq__FPCf((const float *)a));
            unsigned cb = 0x3DCCCCCDu;
            float c = *(float *)&cb;
            float f3 = len * c;
            float f1 = *(float *)(self + 0x610) * c;
            void *a0 = *(void **)(self + 0x600);
            float f2 = *(float *)(self + 0x618) * c;
            *(char *)(self + 0x624) = f;
            *(float *)(self + 0x614) = f3;
            *(float *)(self + 0x610) = f1;
            *(float *)(self + 0x618) = f2;
            if (a0 != 0) {
                SetDamageCollActive__11cDamageUnitb(a0, 0);
            }
        }
        f = 1;
        *(short *)(self + 0x622) = 0;
        *(char *)(self + 0x625) = f;
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, (void *)0x30, self, 0, 0, 0, 0);
        *(char *)(self + 0x2F6) = f;
        *(char *)(self + 0x2F7) = 0;
        *(char *)(self + 0x2F7) = 0;
        *(char *)(self + 0x2F5) = 0;
        *(char *)(self + 0x2F6) = 0;
        return;
    }
    if (mode == 1) {
        *(char *)(self + 0x2F7) = 0;
        *(char *)(self + 0x2F5) = 0;
        *(char *)(self + 0x2F6) = 0;
    }
}
#endif

// FUNCTION: GAME 0x1B7EE0
extern "C" void func_001B7EE0(char *self, float r)
{
    long flags = *(unsigned int *)(self + 0x5B0);
    if (((flags >> 1) & 1) == 0) {
        char *pl = (char *)Getplayer__Fv();
        char *t1 = *(char **)(pl + 0x214);
        char *s0 = (char *)((TblFn)*(void **)(t1 + 0x84))(pl + *(short *)(t1 + 0x80));
        char *t2 = *(char **)(self + 0x214);
        char *v = (char *)((TblFn)*(void **)(t2 + 0x6C))(self + *(short *)(t2 + 0x68));
        float b[4] __attribute__((aligned(16)));
        float a[4] __attribute__((aligned(16)));
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(a[0]));
        __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(a[0]) : "r"(s0), "r"(v) : "memory");
        __asm__ volatile("lqc2 $vf4,0(%0)\n\tsqc2 $vf4,0(%1)" : : "r"(a), "r"(b) : "memory");
        float len = capVu0LengthSq__FPCf(b);
        if (len < r * r) {
            char *pl2 = (char *)Getplayer__Fv();
            char *t3 = *(char **)(pl2 + 0x214);
            char *s1 = (char *)((TblFn)*(void **)(t3 + 0x84))(pl2 + *(short *)(t3 + 0x80));
            char *pl3 = (char *)Getplayer__Fv();
            char *t4 = *(char **)(pl3 + 0x214);
            char *s0b = (char *)((TblFn)*(void **)(t4 + 0x8C))(pl3 + *(short *)(t4 + 0x88));
            char *t5 = *(char **)(self + 0x214);
            char *vb = (char *)((TblFn)*(void **)(t5 + 0x6C))(self + *(short *)(t5 + 0x68));
            unsigned bits = 0x3FA78D36u;
            float k = *(float *)&bits;
            if (Dest_ck__FPCffT0f((int)s1, (int)vb, *(float *)(s0b + 4), k) != 0) {
                set__13cActionButton12eScePriority8eActType11eActBtnTypePvT48eActFunc(g_ActBtn, 3, 0x1B, 0x12, 0, 0, 0);
            }
        }
    }
}
