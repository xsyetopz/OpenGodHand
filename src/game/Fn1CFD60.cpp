static inline int IsSet(const int &v) { return v != 0; }
extern "C" void calcParts__6cModel(char *);
extern "C" float fRand0_1__Fv();
extern "C" float fRand1_1__Fv();

// FUNCTION: GAME 0x1CFD60
extern "C" void func_001CFD60(char *self, int a)
{
    char *p = *(char **)(self + 0x600);
    if (p) {
        float *d = (float *)(self + 0x490);
        float *s = *(float **)(p + 0xF0);
        if (d != s) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
    }
    *(float *)(self + 0x24C) = 1.0f;
    *(unsigned *)(self + 0x250) &= ~0x10u;
    *(int *)(self + 0x600) = 0;
    *(int *)(self + 0x630) = 0;
    char *m = IsSet(*(unsigned char *)(self + 0x2B4)) ? **(char ***)(self + 0x278) : 0;
    if (m) {
        *(char **)(m + 0x148) = self;
        *(int *)(m + 0x100) = 0;
        *(int *)(m + 0x104) = 0;
        *(int *)(m + 0x108) = 0;
        calcParts__6cModel(self);
        *(int *)(self + 0x690) = a;
        *(int *)(self + 0x6A0) = 0;
        *(float *)(self + 0x6A4) = 2.0f * fRand0_1__Fv() + 2.0f;
        *(float *)(self + 0x6A8) = 2.0f * fRand0_1__Fv() + 7.0f;
        float r = fRand1_1__Fv();
        *(char *)(self + 0x2F5) = 12;
        *(char *)(self + 0x2F7) = 0;
        *(char *)(self + 0x2F4) = 0;
        *(char *)(self + 0x2F6) = 0;
        *(float *)(self + 0x694) = r * 3.1415927f;
    }
}
