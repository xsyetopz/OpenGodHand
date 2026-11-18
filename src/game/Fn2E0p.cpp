// Small effect-event and bit-set units in 0x2E0000-0x300000.
extern unsigned char EspSys[];
extern char D_0061B7C0[], D_0061B280[];
extern unsigned D_0071B840[];
extern "C" void effDataRegist__6espSys12eEffDataTypePv(void *, int, void *);
extern "C" void effDataRelease__6espSys12eEffDataType(void *, int);
extern "C" void func_002FBED0(void *);
extern "C" void KillEventEsp__Fv();
extern "C" void KillEventEmitter__Fv();
extern "C" void sstClearSetFlag__6espSys(void *);
extern "C" void func_00305C20(void *);
extern "C" void *memset(void *, int, unsigned);
extern unsigned D_0071B7C0[], D_0071B8C0[];
extern char Event[];
extern "C" void *getObjPtr__6cEvent6eObjIdUc(void *, int, unsigned char);
extern "C" void func_00306330(int, int);
extern "C" void SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, void *, void *, int, unsigned);
extern "C" void setLocalTranslation__5cNodeRC4cVec(void *, const void *);
extern "C" void func_002FBE50(void *);
extern "C" int func_002FACA8(int, int);
extern "C" int func_00306030(void *, int, int);

// FUNCTION: GAME 0x2FA0B0
extern "C" void EffEventDataRegist__FPv(void *p)
{
    if (p) {
        EspSys[0x41C] = 1;
        effDataRegist__6espSys12eEffDataTypePv(EspSys, 6, p);
    }
}

// FUNCTION: GAME 0x2FA0E8
extern "C" void EffEventDataRelease__Fv()
{
    if (EspSys[0x41C] == 1) {
        EspSys[0x41C] = 0;
        effDataRelease__6espSys12eEffDataType(EspSys, 6);
    }
}

// FUNCTION: GAME 0x2FA128
extern "C" int EffEventIsCutDataExist__FUi(unsigned a)
{
    return func_00306030(EspSys, 6, a + 1) != 0;
}

// FUNCTION: GAME 0x2FB020
extern "C" void PushEsp__FP7espWork(char *p)
{
    unsigned d = p - D_0061B7C0;
    D_0071B840[d >> 15] |= 0x80000000u >> ((d >> 10) & 0x1F);
}

// FUNCTION: GAME 0x2E13D8
extern "C" void Moji_size_set__FUcUc(unsigned char a, unsigned char b)
{
    if (a && b) {
        D_0061B280[8] = a;
        D_0061B280[9] = b;
    } else {
        D_0061B280[8] = 8;
        D_0061B280[9] = 8;
    }
}

// FUNCTION: GAME 0x2FA310
extern "C" void EffectEventEndProc__Fv()
{
    KillEventEsp__Fv();
    KillEventEmitter__Fv();
    sstClearSetFlag__6espSys(EspSys);
    func_00305C20(EspSys);
}

// FUNCTION: GAME 0x2FAA20
extern "C" void InitEspWork__Fv()
{
    memset(D_0061B7C0, 0, 0x100000);
    memset(D_0071B7C0, 0, 0x80);
    memset(D_0071B840, 0, 0x80);
    memset(D_0071B8C0, 0, 0x80);
}

struct Qp { float v[4] __attribute__((aligned(16))); };
struct Qv { float v[4] __attribute__((aligned(16))); Qv() { asm volatile("sqc2 $vf0,%0" : "=m"(*this)); } };
struct V4a { float x, y, z, w; V4a() { x = 1.0f; y = 1.0f; z = 1.0f; w = 1.0f; } };
struct V4 { float x, y, z, w; V4() { x = 1.0f; y = 1.0f; z = 1.0f; w = 1.0f; } };
struct EP {
    V4a a;
    Qv q1, q2;
    V4 b;
    float c;
    int d, e;
    signed char f; unsigned char g, h, i;
    int j;
    Qp q3;
    short k, l; char m; int n;
    EP() {
        c = 1.0f;
        f = -1; i = 0xFF; d = 0; e = 0; g = 0; h = 0; j = 0;
        asm volatile("sqc2 $vf0,%0" : "=m"(q3));
        e |= 0xE;
        k = 0; l = 0; m = 0; n = 0;
    }
};

// FUNCTION: GAME 0x2FA158
extern "C" void SetEventCutEffect__FUi(unsigned id)
{
    func_00306330(4, 2);
    if (EffEventIsCutDataExist__FUi(id) == 1) {
        EP p;
        SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(6, id + 1, 0, &p, id + 0x2500, 0xFFFFFFFF);
    }
}

// FUNCTION: GAME 0x2FA240
extern "C" void *getEventObjPtr__FUi(unsigned a)
{
    unsigned id = a >> 16;
    void *r;
    if (!id)
        return 0;
    if (id == 0x605) {
        r = getObjPtr__6cEvent6eObjIdUc(Event, 0x605, a);
        if (!r) r = getObjPtr__6cEvent6eObjIdUc(Event, 0x600, a);
    } else if (id == 0x3D6) {
        r = getObjPtr__6cEvent6eObjIdUc(Event, 0x3D6, a);
        if (!r) r = getObjPtr__6cEvent6eObjIdUc(Event, 0x668, a);
    } else
        r = getObjPtr__6cEvent6eObjIdUc(Event, id, a);
    return r;
}

struct V16F { float x, y, z, w; } __attribute__((aligned(16)));
extern char *pCamWork;
#define CP(d, s) __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(d) : "r"(&(s)))
#ifdef NONMATCHING
// DRAFT: GAME 0x2F6BB8 - 18 words, address-register materialization order
extern "C" void func_002F6BB8(char *self)
{
    V16F c, t, u, v, w;
    CP(c, *(V16F *)(pCamWork + 0x210));
    const float *p = (const float *)(self + 0x2B0);
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(u));
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvsub.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(u) : "r"(&c), "r"(p));
    CP(t, u);
    float f = *(float *)(self + 0x2C0);
    CP(w, t);
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tmfc1 $8,%2\n\tqmtc2.ni $8,$vf5\n\tvmulx.xyz $vf4,$vf4,$vf5x\n\tsqc2 $vf4,%0" : "=m"(w) : "r"(&w), "f"(f) : "$8");
    CP(v, w);
    CP(w, *(V16F *)p);
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,0(%2)\n\tvadd.xyz $vf4,$vf4,$vf5\n\tsqc2 $vf4,%0" : "=m"(w) : "r"(&w), "r"(&v));
    CP(u, w);
    u.y = *(float *)(self + 0x2B4);
    setLocalTranslation__5cNodeRC4cVec(self, &u);
    func_002FBED0(self);
}
#endif

// FUNCTION: GAME 0x2FB998
extern "C" void EspAllKill__Fv()
{
    unsigned *a = D_0071B7C0;
    unsigned *b = D_0071B840;
    unsigned *c = D_0071B8C0;
    char *p = D_0061B7C0;
    for (int i = 0; i < 0x400; i++, p += 0x400) {
        unsigned bit = 0x80000000u >> (i & 0x1F);
        unsigned w = (unsigned)i >> 5;
        if ((a[w] & bit) && !(b[w] & bit) && !(c[w] & bit))
            func_002FBE50(p);
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2FAA88 - 25 words, loop/register layout
extern "C" int PullEsp__F6eEspId(int id)
{
    char *p = D_0061B7C0;
    for (unsigned i = 0; i < 0x400; i++, p += 0x400) {
        unsigned bit = 0x80000000u >> (i & 0x1F);
        unsigned w = i >> 5;
        if (!(D_0071B7C0[w] & bit)) {
            memset(p, 0, 0x400);
            if (!func_002FACA8(i, id))
                return 0;
            D_0071B7C0[w] |= bit;
            D_0071B840[w] &= ~bit;
            D_0071B8C0[w] &= ~bit;
            return 1;
        }
    }
    return 0;
}
#endif
struct V3 {
    float x, y, z;
    V3 &operator=(const V3 &o) { if (this != &o) { x = o.x; y = o.y; z = o.z; } return *this; }
};
extern "C" void func_002B6160(float *, char *);
extern "C" void func_002B5FC8(char *, float *);
#define R (*(float *)(self + 0x2B8))
#define AX(i) { if (p.v[i] < c.v[i] - R) p.v[i] = c.v[i] + R; else if (c.v[i] + R < p.v[i]) p.v[i] = c.v[i] - R; }
// FUNCTION: GAME 0x2F6E20
extern "C" void func_002F6E20(char *self)
{
    Qv c;
    Qp p;
    *(V3 *)&c = *(V3 *)(pCamWork + 0x210);
    func_002B6160(p.v, self);
    AX(0) AX(1) AX(2)
    Qp q;
    float *qp = q.v;
    asm volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qp *)qp) : "r"(&p));
    func_002B5FC8(self, qp);
    func_002FBED0(self);
}

#define T(x) (0x8000000000L | (x))
// FUNCTION: GAME 0x2FA4F0
extern "C" void func_002FA4F0(long **pp, unsigned char k)
{
    switch (k) {
    case 0: *(*pp)++ = T(0x44); break;
    case 1: *(*pp)++ = T(0x48); break;
    case 2: *(*pp)++ = T(0xA9); break;
    case 3: *(*pp)++ = T(0x41); break;
    case 4: *(*pp)++ = T(0x49); break;
    case 5: *(*pp)++ = T(0x68); break;
    case 6: *(*pp)++ = T(0x9); break;
    case 7: *(*pp)++ = T(0x46); break;
    case 8: *(*pp)++ = T(0xA4); break;
    case 9: *(*pp)++ = T(0x42); break;
    case 10: *(*pp)++ = T(0x6); break;
    }
    *(*pp)++ = 0x42;
}
