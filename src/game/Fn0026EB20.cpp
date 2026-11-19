extern "C" void sceVu0ApplyMatrix(float *, void *, float *);
extern "C" int ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(float *, float *, float *, float *, int, int, int, int, int, int, int, int, int);
extern char Snd[];
extern "C" void SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(int, int, void *, float *, float, int);
extern "C" void SeCall__4cSnd6eSeBlksPfUii(void *, int, int, void *, int, int);
extern "C" void *Getplayer__Fv();
extern "C" float func_002DB6D0(char *self);
extern "C" float capVu0MagnitudeXZ__FPCfT0(const float *, const float *);
extern "C" float capVu0Atan2__Fff(float, float);

struct Qv { float f[4] __attribute__((aligned(16))); };

// DRAFT: GAME 0x273C38 - 45 words (244 vs 236 bytes); nested range check best, pointer locals (61) and compound range check (48) tried
#ifdef NONMATCHING
extern "C" int func_00273C38(char *self)
{
    Qv a;
    Qv b;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(a));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(b));
    int v = *(int *)(self + 0x564);
    if (v < 0x223) {
        if (v >= 0x220) {
            return 0;
        }
    }
    float h = 0.5f;
    float *pa = a.f;
    float *pb = b.f;
    pa[0] = 0.0f;
    pa[1] = h;
    pa[2] = 0.0f;
    sceVu0ApplyMatrix(pa, self + 0x80, pa);
    int res = 1;
    pb[1] = h;
    pb[2] = -6.0f;
    pb[0] = 0.0f;
    sceVu0ApplyMatrix(pb, self + 0x80, pb);
    if (ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(pa, pb, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, res) == 1) {
        res = 0;
    }
    return res;
}
#endif

// DRAFT: GAME 0x2751F0 - 47 words (284 vs 280 bytes); SeCall arg from a fresh self+0xF0 load gave 69 and was discarded
#ifdef NONMATCHING
extern "C" void func_002751F0(char *self)
{
    if (*(unsigned char *)(self + 0x17C2) != 0) {
        return;
    }
    char *pos = *(char **)(self + 0xF0);
    if (*(float *)(self + 0x494) <= *(float *)(pos + 4)) {
        return;
    }
    if (!(*(unsigned short *)(self + 0x3AC) & 4) && !(*(float *)(self + 0x1710) < 0.0f)) {
        return;
    }
    Qv a;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(a));
    void *hit;
    int ok = ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b((float *)(self + 0x490), (float *)pos, a.f, 0, 7, 0, (int)&hit, 1, 0, 0, 0, 0, 1);
    if (ok) {
        if (*(unsigned int *)((char *)hit + 4) & 0x400) {
            SetEffectPos__F12eEffDataType6eEffIdP4cObjRC4cVecfi(0, 0x55, 0, a.f, 1.0f, -1);
            SeCall__4cSnd6eSeBlksPfUii(Snd, 2, 0x50, pos, 0, 0);
            *(unsigned char *)(self + 0x17C2) = 1;
        }
    }
}
#endif

// DRAFT: GAME 0x26F328 - 90 words (360 vs 332 bytes); first draft, skip-flag form and pointer-inequality guards suspected
#ifdef NONMATCHING
extern "C" int func_0026F328(char *self)
{
    int v = *(int *)(self + 0x564);
    int skip = 0;
    if (v < 0x266) {
        if (v >= 0x264 || v == 0x260) {
            skip = 1;
        }
    } else if (v == 0x26A) {
        skip = 1;
    }
    if (!skip) {
        Qv a;
        Qv b;
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(a));
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(b));
        float *pa = a.f;
        float *pb = b.f;
        float *p = *(float **)(self + 0xF0);
        if (p != pa) {
            pa[0] = p[0];
            pa[1] = p[1];
            pa[2] = p[2];
        }
        pa[1] = pa[1] + 1.0f;
        char *g = (char *)Getplayer__Fv();
        float *q = *(float **)(g + 0xF0);
        if (q != pb) {
            pb[0] = q[0];
            pb[1] = q[1];
            pb[2] = q[2];
        }
        pb[1] = pb[1] + 1.0f;
        if (ChkLine__FRC4cVecT0P4cVecT2UiUiPP11AK_HIT_INFOUiPUiPP8cGameObjUiT8b(pa, pb, 0, 0, 1, 0x10, 0, 0, 0, 0, 0, 0, 1) == 1) {
            *(unsigned int *)(self + 0x16D0) &= 0xFFDFFFFFu;
            return 0;
        }
    }
    *(unsigned int *)(self + 0x16D0) |= 0x200000u;
    return 1;
}
#endif

// DRAFT: GAME 0x26EB20 - 63 words (324 vs 320 bytes); early g=0 init best, g in else branch gave 81, self-in-s2 tried
#ifdef NONMATCHING
extern "C" void func_0026EB20(char *self)
{
    float g = 0.0f;
    if (*(unsigned short *)(self + 0x3AC) & 8) {
        Qv a;
        Qv b;
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(a));
        __asm__ volatile("sqc2 $vf0,%0" : "=m"(b));
        a.f[0] = 0.0f;
        a.f[1] = 0.0f;
        a.f[2] = 0.25f;
        sceVu0ApplyMatrix(a.f, self + 0x80, a.f);
        a.f[1] = func_002DB6D0((char *)a.f);
        b.f[0] = 0.0f;
        b.f[1] = 0.0f;
        b.f[2] = -0.25f;
        sceVu0ApplyMatrix(b.f, self + 0x80, b.f);
        float r2 = func_002DB6D0((char *)b.f);
        b.f[1] = r2;
        float d = a.f[1] - r2;
        float m = capVu0MagnitudeXZ__FPCfT0(a.f, b.f);
        g = -capVu0Atan2__Fff(d, m);
    }
    float t = *(float *)(self + 0x1708) * 0.6f * (g * 0.1f);
    *(float *)(self + 0x1708) = t;
    float ab = t < 0.0f ? -t : t;
    if (ab < 0.01f) {
        *(float *)(self + 0x1708) = 0.0f;
    } else {
        *(float *)(self + 0x100) = t;
    }
}
#endif
