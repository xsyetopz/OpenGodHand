// Unnamed units in 0x2F0000-0x306000.
extern float D_00741DC0;
extern float D_00747A14;

#ifdef NONMATCHING
// DRAFT: GAME 0x2FA350 (30 words off: original reuses f0 for cvt.w.s and reloads *p; volatile reload and temp variants tried)
extern "C" void func_002FA350(float *p)
{
    float v = *p * 100.0f;
    *p = v;
    int i = (int)v;
    float r = *p - (float)i;
    if (r != 0.0f)
        i++;
    int d = (int)(D_00741DC0 * D_00747A14 * 100.0f);
    *p = (float)(i + d) / 100.0f;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2FA3E0 (30 words off: original reuses f0 for cvt.w.s and reloads *p; volatile reload and temp variants tried)
extern "C" void func_002FA3E0(float *p)
{
    float v = *p * 100.0f;
    *p = v;
    int i = (int)v;
    float r = *p - (float)i;
    if (r != 0.0f)
        i++;
    int d = (int)(D_00741DC0 * D_00747A14 * 100.0f);
    *p = (float)(i - d) / 100.0f;
}
#endif

extern "C" void func_002FBED0(char *);
extern "C" float capVu0Sin__Ff(float);
extern "C" float capVu0Cos__Ff(float);
extern "C" float Adjust_theta__Ff(float);

// FUNCTION: GAME 0x2F01B8
extern "C" void func_002F01B8(char *self)
{
    func_002FBED0(self);
    float zero = 0.0f;
    if (*(float *)(self + 0x2C8) != zero) {
        float s = capVu0Sin__Ff(*(float *)(self + 0x2C0));
        *(float *)(self + 0x2B8) = *(float *)(self + 0x2B0) * s;
        float a = *(float *)(self + 0x2C0) + *(float *)(self + 0x2C8);
        *(float *)(self + 0x2C0) = a;
        *(float *)(self + 0x2C0) = Adjust_theta__Ff(a);
    }
    if (*(float *)(self + 0x2CC) != zero) {
        float c = capVu0Cos__Ff(*(float *)(self + 0x2C4));
        *(float *)(self + 0x2BC) = *(float *)(self + 0x2B4) * c;
        float a = *(float *)(self + 0x2C4) + *(float *)(self + 0x2CC);
        *(float *)(self + 0x2C4) = a;
        *(float *)(self + 0x2C4) = Adjust_theta__Ff(a);
    }
    if (*(float *)(self + 0x2DC) != zero) {
        float c = capVu0Cos__Ff(*(float *)(self + 0x2D8));
        *(float *)(self + 0x2D4) = *(float *)(self + 0x2D0) * c;
        float a = *(float *)(self + 0x2D8) + *(float *)(self + 0x2DC);
        *(float *)(self + 0x2D8) = a;
        *(float *)(self + 0x2D8) = Adjust_theta__Ff(a);
    }
}

extern "C" void func_002B62F8(float *, void *);
extern "C" void func_002B6230(void *, float *);
extern "C" void capVu0AddVectorXYZ__FPfPCfT1(float *, const float *, const float *);
extern "C" void Adjust_theta_vec__FPf(float *);

// FUNCTION: GAME 0x304830
extern "C" void func_00304830(char *self)
{
    float a[4] __attribute__((aligned(16)));
    float b[4] __attribute__((aligned(16)));
    float k = 0.001f;
    func_002B62F8(a, self);
    char *o = *(char **)(self + 0x100);
    *(float *)(self + 0x128) = *(float *)(self + 0x128) * *(float *)(o + 0x1C0);
    *(float *)(self + 0x12C) = *(float *)(self + 0x12C) * *(float *)(o + 0x1C0);
    *(float *)(self + 0x130) = *(float *)(self + 0x130) * *(float *)(o + 0x1C0);
    *(float *)(self + 0x128) = Adjust_theta__Ff(*(float *)(self + 0x128) + *(float *)(o + 0x1C4) * k);
    o = *(char **)(self + 0x100);
    *(float *)(self + 0x12C) = Adjust_theta__Ff(*(float *)(self + 0x12C) + *(float *)(o + 0x1C8) * k);
    o = *(char **)(self + 0x100);
    *(float *)(self + 0x130) = Adjust_theta__Ff(*(float *)(self + 0x130) + *(float *)(o + 0x1CC) * k);
    b[0] = *(float *)(self + 0x128);
    b[1] = *(float *)(self + 0x12C);
    b[2] = *(float *)(self + 0x130);
    float *v = b;
    v[3] = 1.0f;
    capVu0AddVectorXYZ__FPfPCfT1(a, a, v);
    Adjust_theta_vec__FPf(a);
    func_002B6230(self, a);
}

extern "C" unsigned irand__Fv();

// FUNCTION: GAME 0x2F4EB8
extern "C" int func_002F4EB8(char *self, char *src)
{
    char *d = *(char **)(self + 0x110);
    int s = (signed char)d[0x18D];
    *(short *)(self + 0x2BC) = (signed char)d[0x18C];
    unsigned m = s;
    if (s) {
        *(short *)(self + 0x2BC) -= irand__Fv() % m;
        if (*(short *)(self + 0x2BC) <= 0)
            *(short *)(self + 0x2BC) = 0;
    }
    char *d1 = *(char **)(self + 0x110);
    d = d1;
    *(unsigned char *)(self + 0x2BE) = d[0x18E];
    *(float *)(self + 0x2B4) = (float)(signed char)d[0x18F] * 0.025f;
    *(float *)(self + 0x2B8) = (float)(signed char)d[0x190] * 0.5f;
    *(unsigned char *)(self + 0x2E0) = d[0x197];
    if (*(int *)(src + 0x50)) {
        *(int *)(self + 0x2C0) = *(int *)(src + 0x50);
        float *dst = (float *)(self + 0x2D0);
        float *v = (float *)(src + 0x60);
        *(unsigned char *)(self + 0x2BF) = *(unsigned char *)(src + 0x4E);
        if (dst != v) {
            dst[0] = v[0];
            dst[1] = v[1];
            dst[2] = v[2];
        }
    } else {
        int p = *(int *)(self + 0x114);
        if (p && (signed char)d[0xBE] >= 0) {
            *(int *)(self + 0x2C0) = p;
            *(unsigned char *)(self + 0x2BF) = d[0xBE];
        }
        char *e = *(char **)(self + 0x110);
        *(float *)(self + 0x2D0) = *(float *)(e + 0x13C);
        *(float *)(self + 0x2D4) = *(float *)(e + 0x140);
        *(float *)(self + 0x2D8) = *(float *)(e + 0x144);
    }
    return 1;
}
