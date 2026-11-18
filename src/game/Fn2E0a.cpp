// Unnamed units in 0x2E0000-0x2EFFFF: ground-probe ChkLine callers, Hermite blend, spline sampling.
#include "game/Fn2E0.h"

// FUNCTION: GAME 0x2E2D40
PROBE(func_002E2D40, func_002E28F0)
// FUNCTION: GAME 0x2E6FD8
PROBE(func_002E6FD8, func_002E6B88)
#define PROBE2(NAME, FO, GO, CB) \
extern "C" void NAME(char *self) \
{ \
    if (!(*(unsigned *)(self + FO) & 2)) { \
        cVec p, a, b, c, d; \
        func_002B6160(&p, self); \
        CP(&a, &p); CP(&b, &p); ZERO(&c); ZERO(&d); \
        a.y += 1.0f; \
        b.y -= 11.0f; \
        if (ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(a, b, &c, &d, 2, 0, 0, 0, 0, 0, 0, 0, 1)) { \
            *(float *)(self + GO) = c.y; \
            *(unsigned *)(self + FO) |= 2; \
        } \
        if (!(*(unsigned *)(self + FO) & 2)) \
            return; \
    } \
    CB(self, *(float *)(self + GO)); \
}
// FUNCTION: GAME 0x2E2C50
PROBE2(func_002E2C50, 0x2CC, 0x2D0, func_002E28F0)
// FUNCTION: GAME 0x2E6EE8
PROBE2(func_002E6EE8, 0x2DC, 0x2E0, func_002E6B88)

extern "C" float ESHermite__5ESLibfffff(float, float, float, float, float);
// FUNCTION: GAME 0x2E1468
extern "C" void *func_002E1468(float *out, float *tmp, float *a, float *b, float t)
{
    tmp[0] = ESHermite__5ESLibfffff(t, a[0], b[0], 0.0f, 0.0f);
    tmp[1] = ESHermite__5ESLibfffff(t, a[1], b[1], 0.0f, 0.0f);
    tmp[2] = ESHermite__5ESLibfffff(t, a[2], b[2], 0.0f, 0.0f);
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)out) : "r"(tmp));
    return out;
}

extern "C" void func_002B6310(cVec *, void *);
extern "C" void getScreenPos__C7cCameraRC4cVec(cVec *, void *, cVec *);
extern "C" void setLocalTranslation__5cNodeRC4cVec(void *, cVec *);
extern "C" void func_002FEB18(void *);
extern void *pCamWork;
// FUNCTION: GAME 0x2EFB68
extern "C" void func_002EFB68(char *self)
{
    cVec a, b, c;
    func_002B6310(&a, self);
    func_002B6160(&b, self);
    getScreenPos__C7cCameraRC4cVec(&c, pCamWork, &b);
    if (c.z > 0.0f) {
        *(unsigned *)(self + 0x11C) &= 0xFEFFFFFF;
        setLocalTranslation__5cNodeRC4cVec(self, &c);
        func_002FEB18(self);
        *(unsigned *)(self + 0x11C) |= 0x1000000;
        setLocalTranslation__5cNodeRC4cVec(self, &a);
    }
}

typedef cVec cVec16;
extern char Spline[];
extern "C" void setBasePoint__7cSplineP4cVec(void *, cVec16 *);
extern "C" void getPoint__7cSplineR4cVecf(void *, void *, float);
// FUNCTION: GAME 0x2EDEA0
extern "C" void func_002EDEA0(char *self, cVec16 *pts, void *out, int idx)
{
    int n = *(int *)(self + 0x2E4);
    float r = (float)(idx % n) / (float)n;
    int q = idx / n;
    if (q == 0) {
        setBasePoint__7cSplineP4cVec(Spline, pts);
        getPoint__7cSplineR4cVecf(Spline, out, r);
    } else {
        setBasePoint__7cSplineP4cVec(Spline, pts + (q - 1));
        getPoint__7cSplineR4cVecf(Spline, out, r + 1.0f);
    }
}

// FUNCTION: GAME 0x2E8210
extern "C" int func_002E8210(char *self)
{
    char *o = *(char **)(self + 0x110);
    *(int *)(self + 0x2B0) = *(int *)(o + 0x16C);
    int n = *(int *)(o + 0x170);
    *(int *)(self + 0x2BC) = n;
    *(float *)(self + 0x2B4) = *(float *)(o + 0x13C);
    *(float *)(self + 0x2B8) = *(float *)(o + 0x140);
    if (n <= 0)
        *(int *)(self + 0x2BC) = 0x19;
    if (*(int *)(self + 0x2BC) > 0x20)
        *(int *)(self + 0x2BC) = 0x20;
    if (*(float *)(self + 0x2B4) != 0.0f)
        func_002E8038(self, *(float *)(self + 0x2B4) * *(float *)(self + 0x2B4));
    else
        func_002E8038(self, 25.0f);
    if (*(float *)(self + 0x2B8) != 0.0f)
        func_002E8168(self, *(float *)(self + 0x2B8));
    else
        func_002E8168(self, 1.0f);
    return 1;
}

// FUNCTION: GAME 0x2EA908
extern "C" int func_002EA908(char *self)
{
    *(int *)(self + 0x2B8) = 0;
    *(int *)(self + 0x2BC) = 0;
    char *o = *(char **)(self + 0x110);
    *(float *)(self + 0x2C0) = *(float *)(o + 0x13C) * 0.1f;
    *(float *)(self + 0x2C4) = *(float *)(o + 0x140) * 0.1f;
    int n = o[0x18C] + 2;
    *(int *)(self + 0x2C8) = n;
    *(float *)(self + 0x2B0) = (float)o[0x18D] * 0.1f + 1.0f;
    *(float *)(self + 0x2B4) = (float)o[0x18E] * 0.1f + 1.0f;
    unsigned c = (unsigned char)o[0x18F];
    *(unsigned *)(self + 0x2CC) = c;
    if (c >= 4) {
        func_002D9F68(self, D_0044E808, c);
        *(int *)(self + 0x2CC) = 0;
        return 0;
    }
    if (c && n == 2)
        *(int *)(self + 0x2C8) = 3;
    return 1;
}

#include "vu0.h"
extern "C" float capVu0Length__FPCf(const float *);

// FUNCTION: GAME 0x2EA798
// DIVNOP: 2
extern "C" float func_002EA798(char *self)
{
    float v[4], w[4];
    func_002B6160((cVec *)v, self);
    __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)w) : "r"((char *)pCamWork + 0x210));
    float zero = 0.0f;
    if (*(float *)(self + 0x2C8) != zero) {
        v[0] = v[0] - w[0];
        v[1] = v[1] - w[1];
        v[2] = v[2] - w[2];
        vu0_ScaleXYZ(v, v, 1000.0f);
        float r = capVu0Length__FPCf(v) / *(float *)(self + 0x2C8);
        if (1.0f < r) r = 1.0f;
        if (r < zero) r = zero;
        return 1.0f - r;
    }
    return 1.0f;
}

// FUNCTION: GAME 0x2E9C30
extern "C" void func_002E9C30(char *self)
{
    cVec p, s;
    func_002FBED0(self);
    func_002B6160(&p, self);
    getScreenPos__C7cCameraRC4cVec(&s, pCamWork, &p);
    D_0061B644 = 1;
    if (s.x <= 0.0f) s.x = 1.0f;
    if ((float)DISPLAY_W <= s.x) s.x = (float)(DISPLAY_W - 1);
    if (s.y <= 0.0f) s.y = 1.0f;
    if ((float)DISPLAY_H <= s.y) s.y = (float)(DISPLAY_H - 1);
    *(float *)(self + 0x2C0) = s.x;
    *(float *)(self + 0x2C4) = s.y;
}

// FUNCTION: GAME 0x2EC218
extern "C" void func_002EC218(char *self)
{
    cVec p;
    func_002EC310(self);
    for (int i = self[0x249] - 1; i > 0; i--) {
        cVec *a = (cVec *)((int)i * 16 + *(int *)(self + 0x2BC));
        cpv(a, a - 1);
    }
    func_002B6160(&p, self);
    cpv(*(cVec **)(self + 0x2BC), &p);
    if (!(*(unsigned *)(self + 0x11C) & 0x1000000)) {
        for (int i = 0; i < self[0x249] - 1; i++)
            (*(cVec **)(self + 0x2BC))[i].z = 65520.0f;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2E63C0
// diff: 26 words; original tail layout (msg set in v0 vs a1, branch offsets). func_002D9F68 is variadic here (2-arg call sites).
extern char D_00741DC8[], D_0044E3B0[], D_0044E3D8[], D_0044E3F8[], D_0044E418[];
extern char *CreateObj__F6eObjIdT0(int, int);
extern void ReleaseObj__FP4cObj(void *);
extern int setupModel__6cModelPC10SCR_HEADERUibT3(void *, void *, unsigned, int, int);
extern "C" int func_00306C78(void *, unsigned, void *, void *);
extern "C" int func_002E63C0(char *self)
{
    // NOTE: needs func_002D9F68 declared variadic (2-arg call sites)
    void *hdr; unsigned sz;
    if (!func_00306C78(D_00741DC8, *(unsigned *)(self + 0x2B4), &hdr, &sz)) {
        func_002D9F68(self, D_0044E3B0, *(unsigned *)(self + 0x2B4));
        return 0;
    }
    char *o = CreateObj__F6eObjIdT0(0x500, 0xFFFF);
    *(char **)(self + 0x2B0) = o;
    if (!o) {
        func_002D9F68(self, D_0044E3D8);
        return 0;
    }
    char *vt = *(char **)(o + 0x214);
    const char *msg;
    if (!((int (*)(char *))*(int *)(vt + 0x44))(o + *(short *)(vt + 0x40)))
        msg = D_0044E3F8;
    else if (setupModel__6cModelPC10SCR_HEADERUibT3(*(void **)(self + 0x2B0), hdr, sz, 0, 0))
        return 1;
    else
        msg = D_0044E418;
    func_002D9F68(self, msg, sz);
    ReleaseObj__FP4cObj(*(void **)(self + 0x2B0));
    return 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2E8038
// diff: 43 words; original has 2 nops before each div.s (as in 0x2EA798) and branches bnez i / add.s, ours inverts the test.
extern "C" void func_002E8038(void *s_, float k)
{
    char *self = (char *)s_;
    float sum = 0.0f;
    unsigned i;
    for (i = 0; i < *(unsigned *)(self + 0x2BC); i++) {
        D_0061B5C0[i] = func_003A1C78((float)(i * i) * -0.5f / k);
        sum += i ? D_0061B5C0[i] + D_0061B5C0[i] : D_0061B5C0[0];
    }
    for (i = 0; i < *(unsigned *)(self + 0x2BC); i++)
        D_0061B5C0[i] /= sum;
}
#endif
