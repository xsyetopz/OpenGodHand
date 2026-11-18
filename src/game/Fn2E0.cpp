// Unnamed units in 0x2E0000-0x2EFFFF: ground-probe ChkLine callers, Hermite blend, spline sampling.
struct Qv { float f[4]; };
struct cVec { float x, y, z, w; };
class cGameObj; struct AK_HIT_INFO;
int ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(const cVec &, const cVec &, cVec *, cVec *, unsigned, unsigned, AK_HIT_INFO **, unsigned, unsigned *, cGameObj **, unsigned, unsigned, bool);
extern "C" void func_002B6160(cVec *, void *);
extern "C" void func_002E28F0(void *, float);
extern "C" void func_002E6B88(void *, float);
#define CP(d, s) __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Qv *)(d)) : "r"(s))
#define ZERO(d) __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)(d)))
#define PROBE(NAME, CB) \
extern "C" void NAME(void *self) \
{ \
    cVec p, a, b, c, d; \
    func_002B6160(&p, self); \
    CP(&a, &p); CP(&b, &p); ZERO(&c); ZERO(&d); \
    a.y += 1.0f; \
    b.y -= 11.0f; \
    if (ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(a, b, &c, &d, 2, 0, 0, 0, 0, 0, 0, 0, 1)) \
        CB(self, c.y); \
}
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
