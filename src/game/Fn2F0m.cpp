// Unnamed units in 0x2F0000-0x306000.
extern float D_00741DC0;
extern float D_00747A14;

#ifdef NONMATCHING
// DRAFT: GAME 0x2FA350 (29 words off with // DIVNOP: 2 under a FUNCTION tag; original stores *p before an in-place cvt.w.s f0,f0 and reloads *p, we CSE it and use cvt.w.s f1,f0; volatile, temp, *p *= forms, (int)(*p = ...) tried)
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
// DRAFT: GAME 0x2FA3E0 (about 12 words off: target emits in-place cvt.w.s $f0,$f0, build emits cvt.w.s $f1,$f0; barrier/volatile/temp variants tried)
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

// FUNCTION: GAME 0x302E48
extern "C" void func_00302E48(char *self)
{
    float a[4] __attribute__((aligned(16)));
    float b[4] __attribute__((aligned(16)));
    func_002B62F8(a, self);
    char *o;
    float t;
    int n = *(int *)(*(char **)(self + 0x100) + 0x1A0);
    if (n) {
        t = (*(float *)(self + 0x180) - (float)*(short *)(self + 0x186)) / (float)n;
    } else {
        t = 0.0f;
    }
    o = *(char **)(self + 0x100);
    if (*(float *)(o + 0x1C0) <= t) {
        *(float *)(self + 0x128) = *(float *)(self + 0x128) * *(float *)(o + 0x1C4);
        *(float *)(self + 0x12C) = *(float *)(self + 0x12C) * *(float *)(o + 0x1C8);
        *(float *)(self + 0x130) = *(float *)(self + 0x130) * *(float *)(o + 0x1CC);
        Adjust_theta_vec__FPf(a);
    }
    o = *(char **)(self + 0x100);
    if (*(float *)(o + 0x1B0) <= t) {
        b[0] = *(float *)(self + 0x128);
        b[1] = *(float *)(self + 0x12C);
        b[2] = *(float *)(self + 0x130);
        float *v = b;
        v[3] = 1.0f;
        capVu0AddVectorXYZ__FPfPCfT1(a, a, v);
        Adjust_theta_vec__FPf(a);
    }
    func_002B6230(self, a);
}

extern "C" int func_002F3E68(char *);
extern "C" void func_002FBE50(char *);
extern char *pCamWork;

// FUNCTION: GAME 0x2F40C0
extern "C" void func_002F40C0(char *self)
{
    func_002FBED0(self);
    int c = 0;
    if (*(short *)(self + 0x2B0) == -1) {
        if (func_002F3E68(self)) {
            unsigned char o = *(unsigned char *)(pCamWork + 0x278);
            *(unsigned char *)(pCamWork + 0x278) = 2;
            c = o != 1;
        }
    }
    if (*(short *)(self + 0x2B2) == -1) {
        if (func_002F3E68(self)) {
            unsigned char o = *(unsigned char *)(pCamWork + 0x264);
            *(unsigned char *)(pCamWork + 0x264) = 2;
            if (o != 1)
                c = 1;
        }
    }
    if (c) {
        if (*(short *)(self + 0x2B0) == -1) {
            *(float *)(pCamWork + 0x268) = *(float *)(*(char **)(self + 0x110) + 0x13C);
            *(float *)(pCamWork + 0x26C) = *(float *)(*(char **)(self + 0x110) + 0x140);
            *(float *)(pCamWork + 0x270) = *(float *)(*(char **)(self + 0x110) + 0x144);
            *(float *)(pCamWork + 0x274) = *(float *)(*(char **)(self + 0x110) + 0x148);
        }
        if (*(short *)(self + 0x2B2) == -1) {
            *(float *)(pCamWork + 0x254) = *(float *)(*(char **)(self + 0x110) + 0x14C);
            *(float *)(pCamWork + 0x258) = *(float *)(*(char **)(self + 0x110) + 0x150);
            *(float *)(pCamWork + 0x25C) = *(float *)(*(char **)(self + 0x110) + 0x154);
            *(float *)(pCamWork + 0x260) = *(float *)(*(char **)(self + 0x110) + 0x158);
        }
    }
    if (*(short *)(self + 0x2B0) != -1 && *(short *)(self + 0x2B2) != -1)
        func_002FBE50(self);
}

extern "C" void func_002B6160(float *, char *);
extern "C" void func_002FEB18(char *);

// FUNCTION: GAME 0x2F6F48
extern "C" void func_002F6F48(char *self)
{
    float t0 = *(float *)(self + 0x2B8);
    float lim = t0 - *(float *)(self + 0x2BC);
    float g = *(float *)(self + 0x194);
    float pos[4] __attribute__((aligned(16)));
    float d[4] __attribute__((aligned(16)));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(float (*)[4])pos));
    float *c = (float *)(pCamWork + 0x210);
    if (pos != c) {
        pos[0] = c[0];
        pos[1] = c[1];
        pos[2] = c[2];
    }
    func_002B6160(d, self);
    float f = 1.0f;
    float x = __builtin_fabsf(pos[0] - d[0]);
    if (lim < x) {
        if (x < t0)
            f = 1.0f - (x - lim) / *(float *)(self + 0x2BC);
        else
            f = 0.0f;
    }
    float z = __builtin_fabsf(pos[2] - d[2]);
    if (lim < z) {
        if (z < t0)
            f = f * (1.0f - (z - lim) / *(float *)(self + 0x2BC));
        else
            f = 0.0f;
    }
    *(float *)(self + 0x194) = *(float *)(self + 0x194) * f;
    func_002FEB18(self);
    *(float *)(self + 0x194) = g;
}
