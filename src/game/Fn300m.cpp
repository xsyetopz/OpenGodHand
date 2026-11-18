// Unnamed units in 0x300000-0x31C000.
#define F(p, o) (*(float *)((p) + (o)))

extern "C" int *func_003058D8(char *);
extern "C" void func_003057D0(char *, int, int);

// FUNCTION: GAME 0x305908
extern "C" int func_00305908(char *self, int a, int b)
{
    int *v = func_003058D8(self);
    if (v) {
        v[3]++;
    } else {
        for (unsigned i = 0; i < 0x40; i++) {
            if (*(int *)(self + i * 0x10) == 5) {
                func_003057D0(self + i * 0x10, a, b);
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

extern "C" void func_003009F8(char *, int);
extern "C" void func_002FBA60(char *, int, int);

// FUNCTION: GAME 0x3063B8
extern "C" void func_003063B8(char *self, int idx, int mode, unsigned char flag)
{
    if (!self && idx == -1)
        return;
    switch (mode) {
    case 0:
        func_003009F8(self, idx);
        break;
    case 1:
        func_002FBA60(self, idx, flag);
        break;
    case 2:
        func_002FBA60(self, idx, flag);
        func_003009F8(self, idx);
        break;
    }
}

extern "C" int irand__Fv(void);
extern "C" int func_0031D098(char *);
extern "C" void func_00300EF8(int, char *, int, char *, int, int, int, int, int, int, int, int, int);

// FUNCTION: GAME 0x300E30
extern "C" void func_00300E30(char *self, int a)
{
    if (*(unsigned char *)(*(char **)(self + 0x100) + 0x28E))
        *(int *)(self + 0x220) = func_0031D098(self + 0x220);
    else
        *(int *)(self + 0x220) = irand__Fv();
    int t = 0;
    unsigned hu = *(unsigned short *)(self + 0x224);
    if (hu) {
        unsigned char one = 1;
        t = (unsigned short)(hu - (int)F(self, 0x228));
        if (!t) t = one;
    }
    char *s = self;
    func_00300EF8(a, s, *(int *)(s + 0x100), s + 0x1A0, *(unsigned short *)(self + 0x18E),
                  *(int *)(s + 0x108), *(int *)(s + 0x10C), *(int *)(s + 0x110),
                  *(int *)(self + 0x118), *(short *)(self + 0x18C), *(int *)(self + 0x114),
                  *(int *)(self + 0x220), t);
}

extern "C" int func_00306A48(int *, unsigned, int *);

#ifdef NONMATCHING
// DRAFT: GAME 0x306AF0 (19 words off: original copies self to a2 and has separate return-1 sites; early-copy, flat returns, base ptr, old local did not help; (int)self casts, d-base slot, nested-if with d hoisted: 21-28 words; d=(int*)self hoisted + d+0x40+idx slot 21, early-return chain 41, nested if 23)
extern "C" int func_00306AF0(char *self, int idx, int *hdr)
{
    if (hdr[0] == 0x444D45 && idx < 0x4E2) {
        int *slot = (int *)(self + 0x100) + idx;
        if (*slot)
            return 0;
        *slot = (int)hdr;
        if (!hdr[1])
            return 1;
        unsigned i = 0;
        int *d = (int *)self;
        int t;
        do {
            if (func_00306A48(hdr, i, &t) && t)
                *d = t;
            i++;
            d++;
        } while (i < (unsigned)hdr[1]);
        return 1;
    }
    return 0;
}
#endif

struct Qv { float f[4]; };
extern "C" void SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, void *, void *, int, unsigned);

// FUNCTION: GAME 0x305E88
extern "C" void func_00305E88(char *self, int idx)
{
    char p[0x80] __attribute__((aligned(16)));
    unsigned m = 1 << idx;
    unsigned old = *(unsigned *)(self + 0x414);
    if (old & m)
        return;
    *(unsigned *)(self + 0x414) = old | m;
    F(p, 0) = 1.0f;
    F(p, 4) = 1.0f;
    F(p, 8) = 1.0f;
    F(p, 0xC) = 1.0f;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)(p + 0x10)));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)(p + 0x20)));
    float *v = (float *)(p + 0x30);
    v[0] = 1.0f;
    v[1] = 1.0f;
    v[2] = 1.0f;
    v[3] = 1.0f;
    F(p, 0x40) = 1.0f;
    *(signed char *)(p + 0x4C) = -1;
    *(unsigned char *)(p + 0x4F) = 0xFF;
    *(int *)(p + 0x44) = 0;
    *(int *)(p + 0x48) = 0;
    *(char *)(p + 0x4D) = 0;
    *(char *)(p + 0x4E) = 0;
    *(int *)(p + 0x50) = 0;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)(p + 0x60)));
    *(unsigned *)(p + 0x48) |= 0x40;
    *(short *)(p + 0x70) = 0;
    *(short *)(p + 0x72) = 0;
    *(char *)(p + 0x74) = 0;
    *(int *)(p + 0x78) = 0;
    SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(3, idx, 0, p, idx + 0x2200, 0xFFFFFFFF);
}

extern "C" {
void EmitterAllKill__Fv();
void EspAllKill__Fv();
void func_003057A0(char *);
void func_00305BC0(char *);
void func_00306A88(char *);
void func_00305C10(char *, void *);
void func_00305C18(char *, void *);
void func_00306D18(char *);
void effDataRegist__6espSys12eEffDataTypePv(char *, int, void *);
void *SearchData__FPUiPCcUi(void *, const char *, unsigned);
extern char Sys[], D_00741DC8[], D_00743250[], D_00450068[], D_00450070[], D_00450078[];
}

// FUNCTION: GAME 0x305A68
extern "C" void func_00305A68(char *self)
{
    *(char *)(self + 0x41C) = 0;
    EmitterAllKill__Fv();
    EspAllKill__Fv();
    func_003057A0(self);
    func_00305BC0(self);
    func_00306A88(D_00741DC8);
    char *s = Sys;
    char *p = *(char **)(s + 0x550);
    effDataRegist__6espSys12eEffDataTypePv(self, 0, (void *)(*(int *)(p + 0x14) + (int)p));
    p = *(char **)(s + 0x550);
    effDataRegist__6espSys12eEffDataTypePv(self, 0x58, (void *)(*(int *)(p + 0x1C) + (int)p));
    p = *(char **)(s + 0x550);
    effDataRegist__6espSys12eEffDataTypePv(self, 4, (void *)(*(int *)(p + 0x14) + (int)p));
    void *r = SearchData__FPUiPCcUi(*(void **)(s + 0x5AC), D_00450068, 0);
    if (r)
        effDataRegist__6espSys12eEffDataTypePv(self, 1, r);
    r = SearchData__FPUiPCcUi(*(void **)(s + 0x5AC), D_00450070, 0);
    if (r)
        func_00305C10(self, r);
    r = SearchData__FPUiPCcUi(*(void **)(s + 0x5AC), D_00450078, 0);
    if (r)
        func_00305C18(self, r);
    func_00306D18(D_00743250);
}

extern "C" char *func_00306F88(char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x306D18 - 19 words: original stores c[0..2] as sw $zero outside loop, reloads c[0] (lwc1) in loop and stores hoisted float 0.0 ($f1) via swc1; mine folds to sw $zero. Tried init outside loop, int-cast c stores (hoists load, 26), mixed int/float (19), c[] copies (25-71)
extern "C" void func_00306D18(char *self)
{
    float c[4];
    float *v = (float *)(self + 0x380);
    float fz = 0.0f;
    for (unsigned i = 0; i < 1000; i++, v += 4) {
        c[0] = 0.0f;
        c[1] = 0.0f;
        c[2] = 0.0f;
        c[3] = 1.0f;
        if (v != c) {
            v[0] = fz;
            v[2] = c[0];
            v[1] = fz;
        }
    }
    char *e = self;
    char *z = self + 0x300;
    char *vv = self + 0x380;
    char *t = self + 0x4200;
    for (e = self; e < z; e += 0x18) {
        *(int *)e = 0;
        *(int *)(e + 4) = 0;
        e[8] = 0;
        e[9] = 0;
        *(short *)(e + 10) = 0;
        *(short *)(e + 0x10) = 0;
        *(int *)(e + 0xC) = 0;
        *(short *)(e + 0x12) = 0;
    }
    int *w = (int *)z;
    for (unsigned i = 0; i < 0x20; i++)
        *w++ = 0;
    char *r = func_00306F88(self);
    *(char **)(r + 0xC) = vv;
    *(short *)(r + 0x10) = 0x3E8;
    *(int *)(self + 0x4200) = 0;
    t[8] = 0;
    t[9] = 0;
    *(short *)(t + 10) = 0;
    *(short *)(t + 0x10) = 0;
    *(int *)(t + 0xC) = 0;
    *(short *)(t + 0x12) = 0;
    *(char **)(t + 4) = r;
    *(char **)r = t;
}
#endif

extern char g_CollScr[];
extern "C" int func_0012ED60(void *, int, int, int, int, int, int, int **, int, unsigned *, int, int, int, int);
extern "C" char *func_001333B8(void *, unsigned short);
extern "C" int func_00308D68(char *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x308DA8 (18 words off; nested ifs, early returns, result-var goto tried (worse): original tests the hit count once before the loop and keeps the entry base in a0)
extern "C" int func_00308DA8(char *self, int a1, int a2)
{
    int *hit[8];
    unsigned n;
    if (func_0012ED60(g_CollScr, a1, a2, 0, 0, 7, 300, hit, 8, &n, 0, 0, 0, 0) && n) {
        for (unsigned i = 0; i < n; i++) {
            char *d = func_001333B8(g_CollScr, *(unsigned short *)((char *)hit[i] + 8));
            if (!*((unsigned char *)hit[i] + 10))
                return 1;
            for (int j = 0; j < *((unsigned char *)hit[i] + 10); j++, d += 8) {
                if (!*(int *)d && *(int *)(d + 4) && !func_00308D68(self, *(int *)(d + 4)))
                    return 1;
            }
        }
    }
    return 0;
}
#endif
