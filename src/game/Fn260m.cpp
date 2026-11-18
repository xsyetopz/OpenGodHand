#define ZQ(p, o) __asm__ volatile("sqc2 $vf0," #o "(%0)" : : "r"(p) : "memory")
struct SvQ {
    float v[3];
    SvQ &operator=(const float *o)
    {
        if (v != o) {
            v[0] = o[0];
            v[1] = o[1];
            v[2] = o[2];
        }
        return *this;
    }
};

extern unsigned D_00747A78;
extern "C" void *Getplayer__Fv();
extern "C" float capVu0MagnitudeSqXZ__FPCfT0(const float *, const float *);
extern "C" void func_00279FF0(void *);
extern "C" void calcParts__6cModel(void *);
extern "C" void func_0026B1E8(void *);
extern "C" char *getMeshPtr__6cModelPCc(void *, const char *);
extern char D_0042CAB8[];

struct Obj26 {
    char p0[0xF0];
    const float *tgt;
    char p1[0x490 - 0xF4];
    SvQ org;
};

// FUNCTION: GAME 0x279E78
extern "C" void func_00279E78(Obj26 *self)
{
    if ((D_00747A78 & 0x40000000) == 0) {
        float m = capVu0MagnitudeSqXZ__FPCfT0(*(const float **)((char *)Getplayer__Fv() + 0xF0), self->tgt);
        *(float *)((char *)self + 0x618) = m;
        func_00279FF0(self);
        calcParts__6cModel(self);
        self->org = self->tgt;
    }
}

// FUNCTION: GAME 0x269AC0
extern "C" void func_00269AC0(char *self)
{
    if (*(int *)(self + 0x179C) != 0) {
        char *m = getMeshPtr__6cModelPCc(self, D_0042CAB8);
        if (*(unsigned *)(self + 0x16D0) & 0x400000) {
            char *p = *(char **)(self + 0x179C);
            *(unsigned *)(p + 0x380) &= ~1u;
            if (m != 0)
                *(unsigned *)(m + 0x380) &= ~1u;
        } else {
            char *p = *(char **)(self + 0x179C);
            *(unsigned *)(p + 0x380) |= 1;
            if (m != 0)
                *(unsigned *)(m + 0x380) |= 1;
        }
    }
}

extern "C" int func_0028EB00(void *);
extern const char D_004483A8[];
extern const char D_004482B0[];

// FUNCTION: GAME 0x27DD88
extern "C" void *func_0027DD88(char *self)
{
    func_0028EB00(self);
    *(const void **)(self + 0x214) = D_004483A8;
    ZQ(self, 0x1530);
    ZQ(self, 0x1540);
    ZQ(self, 0x1550);
    ZQ(self, 0x1590);
    ZQ(self, 0x15A0);
    ZQ(self, 0x1610);
    char *p = self + 0x1630;
    for (int i = 0x2B; i != -1; i--) {
        ZQ(p, 0x0);
        ZQ(p, 0x10);
        ZQ(p, 0x30);
        ZQ(p, 0x40);
        ZQ(p, 0x50);
        ZQ(p, 0x80);
        p += 0xA0;
    }
    *(const void **)(self + 0x4AC) = D_004482B0;
    return self;
}

extern "C" void setTextureExchange__6cModelPCUiPC(void *, void *, void *, int);
extern char D_0042CAC8[];

// FUNCTION: GAME 0x273F08
extern "C" void func_00273F08(char *self)
{
    if ((*(int *)(self + 0x564) ^ 0x251) == 0) {
        *(unsigned *)(self + 0x16D4) |= 0x10;
        *(unsigned *)(self + 0x254) |= 0x10000000;
        char *t = *(char **)(self + 0x304);
        setTextureExchange__6cModelPCUiPC(self, *(void **)(self + 0x284), *(char **)(t + 0x60) + (long)t, 0);
        char *m = getMeshPtr__6cModelPCc(self, D_0042CAC8);
        if (m != 0)
            *(unsigned *)(m + 0x380) &= ~1u;
    }
}

extern "C" void func_002A8578(void *, void *, void *, float, int, int, int);
extern "C" int moveMotion__FP8cObjBase(void *);

// FUNCTION: GAME 0x27F8D8
extern "C" void func_0027F8D8(unsigned char *self)
{
    switch (self[0x2F6]) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(char **)(t + 0x64) + (long)t, *(char **)(t + 0x68) + (long)t, 0.0f, 5, 0, 0);
        self[0x2F6]++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self) != 0) {
            self[0x2F4] = 0;
            self[0x2F5] = 0;
            self[0x2F6] = 0;
            self[0x2F7] = 0;
        }
        break;
    }
}
