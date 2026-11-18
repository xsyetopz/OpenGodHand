// Unnamed units in 0x2E0000-0x2EFFFF: ground-probe ChkLine callers, Hermite blend, spline sampling.
#ifndef GAME_FN2E0_H
#define GAME_FN2E0_H

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

extern "C" void func_002E8038(void *, float);
extern "C" void func_002E8168(void *, float);
extern "C" void func_002D9F68(void *, const char *, ...);
extern char D_0044E808[];

extern "C" void func_002FBED0(void *);
extern unsigned char D_0061B644;
extern int DISPLAY_W, DISPLAY_H;

extern "C" void func_002EC310(void *);
static inline void cpv(cVec *d, const cVec *s)
{
    if (d != s) {
        d->x = s->x;
        d->y = s->y;
        d->z = s->z;
    }
}

#endif
