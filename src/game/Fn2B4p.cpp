// Unnamed units in 0x2B4000-0x2C0000 (continuation of Fn2B0p.cpp).
float capVu0LengthSq(const float *);
extern "C" float sqrtf_(float) __asm__("sqrtf");
static inline float Sq(float a)
{
    float r;
    __asm__("nop\n\tnop\n\tsqrt.s %0,%1" : "=f"(r) : "f"(a));
    if (r != r) r = sqrtf_(a);
    return r;
}

// FUNCTION: GAME 0x2BAB30
extern "C" void func_002BAB30(char *self)
{
    float t[4];
    char *vt = *(char **)(self + 0x100);
    ((void (*)(float *, char *))(*(void **)(vt + 0x34)))(t, self + *(short *)(vt + 0x30));
    t[0] *= 0.5f;
    t[1] *= 0.5f;
    t[2] *= 0.5f;
    *(float *)(self + 0xE4) = Sq(capVu0LengthSq(t));
}

extern unsigned D_00747A78;
extern char *pCamWork;
extern "C" void func_001582A0(char *, int, int, int, int, float, float);
extern "C" void setRotationOrder__6cPartsUc(char *, int);
extern "C" void calcParts__6cModel(char *);

// FUNCTION: GAME 0x2B8850
extern "C" void func_002B8850(char *self)
{
    if (D_00747A78 & 0x10000000) return;
    int a = *(int *)(self + 0x4D0);
    if (a && !*(unsigned char *)(self + 0x4D4))
        func_001582A0(self, a, 0, 0, 0, 1.0f, 0.0f);
    if (*(unsigned *)(self + 0x2F8) & 1) {
        float *d = (float *)(self + 0x100);
        float *s = (float *)(pCamWork + 0x220);
        if (d != s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
        setRotationOrder__6cPartsUc(self, 4);
    }
    calcParts__6cModel(self);
}
