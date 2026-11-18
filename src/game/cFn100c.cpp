extern "C" void *initialize__7cIDBase7eIdData5eIdNo(void *, int, int);

// FUNCTION: GAME 0x133408
extern "C" int func_00133408(void *, float *a, float *b, float *c, float *d)
{
    if (b[0] < c[0] || a[0] > d[0])
        return 0;
    if (b[2] < c[2] || a[2] > d[2])
        return 0;
    if (b[1] < c[1] || a[1] > d[1])
        return 0;
    return 1;
}

// FUNCTION: GAME 0x135250
extern "C" int func_00135250(void *, float *a, float *b, float *c, float *d)
{
    if (b[0] < c[0] || a[0] > d[0])
        return 0;
    if (b[2] < c[2] || a[2] > d[2])
        return 0;
    if (b[1] < c[1] || a[1] > d[1])
        return 0;
    return 1;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x139910
// diff: load/store scheduling of the two vec temps differs (21 words)
extern "C" void func_00139910(char *self)
{
    char *p = *(char **)(self + 0x364);
    if (p && *(char **)(self + 0x368)) {
        float t[4];
        float *d = (float *)(self + 0x210);
        t[2] = *(float *)(p + 0xB8);
        t[0] = *(float *)(p + 0xB0);
        t[1] = *(float *)(p + 0xB4);
        t[3] = 1.0f;
        if (d != t) {
            d[0] = t[0];
            d[1] = t[1];
            d[2] = t[2];
        }
        p = *(char **)(self + 0x368);
        d = (float *)(self + 0x200);
        t[2] = *(float *)(p + 0xB8);
        t[0] = *(float *)(p + 0xB0);
        t[1] = *(float *)(p + 0xB4);
        t[3] = 1.0f;
        if (d != t) {
            d[0] = t[0];
            d[1] = t[1];
            d[2] = t[2];
        }
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x13DF70
// diff: original keeps off+self in v0 then moves to s0 (17 words)
extern "C" void func_0013DF70(char *self)
{
    unsigned short i = 0;
    do {
        int off = i * 0x50;
        char *e;
        initialize__7cIDBase7eIdData5eIdNo(self + (off + 0x90), 1, 0x12);
        e = self + off;
        *(short *)(e + 0xD4) = 1;
        *(float *)(e + 0xD0) = 0.00724635f;
        i++;
    } while (i < 8);
}
#endif

extern "C" void func_001331B8(void *, long);

#ifdef NONMATCHING
// DRAFT: GAME 0x1332D0
// diff: char->long widening emits lbu+dsll32/dsra32; original shifts the lb result directly with dsllv (22 words)
extern "C" void SetCollEnable__16cCollisionScrollPCcb(void *self, const signed char *s, int)
{
    long m = 0;
    if (*s) {
        int i = 0;
        do {
            m |= (long)*s << (i * 8);
            i++;
            s++;
        } while (i < 8 && *s);
    }
    func_001331B8(self, m);
}
#endif

extern "C" void SetEffectParts__F12eEffDataType6eEffIdP4cObjiffffi(int, int, void *, int, float, float, float, float, int);
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(void *, int, int);

// FUNCTION: GAME 0x12BB38
extern "C" void func_0012BB38(char *self)
{
    long k = *(long *)(self + 0x2F0) & ((long)0xFFFF << 32);
    int f;
    if (k == ((long)0xC020 << 27)) {
        f = *(int *)(self + 0x15F4);
        if ((f & 0x40) == 0) {
            *(int *)(self + 0x15F4) = f | 0x40;
            SetEffectParts__F12eEffDataType6eEffIdP4cObjiffffi(0, 4, self, 4, 0.0f, 0.0f, 0.0f, 1.0f, 4);
        }
    } else if ((f = *(int *)(self + 0x15F4)) & 0x40) {
        *(int *)(self + 0x15F4) = f & -0x41;
        KillEffect__FPC4cObji13eEspEraseMode(self, 4, 2);
    }
}

class cPlSt {
public:
    virtual void vf();
    char _pad[0x2F5];
    unsigned char st;
};
typedef void (cPlSt::*PlStFn)();
extern "C" PlStFn D_003BC770[];

// FUNCTION: GAME 0x102728
extern "C" void func_00102728(cPlSt *self)
{
    if (self->st >= 8)
        self->st = 0;
    (self->*D_003BC770[self->st])();
}
extern "C" PlStFn D_003BC7B0[];
extern "C" PlStFn D_003BC7B8[];
extern "C" PlStFn D_003BD0F0[];

// FUNCTION: GAME 0x10B6B0
extern "C" void func_0010B6B0(cPlSt *self)
{
    if (self->st >= 0x47)
        self->st = 0;
    (self->*D_003BD0F0[self->st])();
}

// FUNCTION: GAME 0x1030C8
extern "C" void func_001030C8(cPlSt *self)
{
    if (self->st != 0)
        self->st = 0;
    (self->*D_003BC7B0[self->st])();
}

// FUNCTION: GAME 0x1032C8
extern "C" void func_001032C8(cPlSt *self)
{
    if (self->st != 0)
        self->st = 0;
    (self->*D_003BC7B8[self->st])();
}
