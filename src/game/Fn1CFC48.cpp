extern "C" void calcParts__6cModel(char *);
extern "C" float fRand1_1__Fv();
static inline int IsSet(const int &v) { return v != 0; }

// FUNCTION: GAME 0x1CFC48
extern "C" void setThrowPL__9cOmWeaponRC4cVec(char *self, float *pos)
{
    char *t = *(char **)(self + 0x600);
    if (t) {
        float *s = *(float **)(t + 0xF0);
        float *d = (float *)(self + 0x490);
        if (d != s) {
            d[0] = s[0];
            d[1] = s[1];
            d[2] = s[2];
        }
    }
    *(float *)(self + 0x24C) = 1.0f;
    *(unsigned *)(self + 0x250) &= ~0x10u;
    *(char **)(self + 0x600) = 0;
    *(int *)(self + 0x630) = 0;
    char *m = IsSet(*(unsigned char *)(self + 0x2B4)) ? **(char ***)(self + 0x278) : 0;
    if (m) {
        *(char **)(m + 0x148) = self;
        *(int *)(m + 0x100) = 0;
        *(int *)(m + 0x104) = 0;
        *(float *)(m + 0x108) = fRand1_1__Fv() * 0.5235988f + 0.5235988f;
        calcParts__6cModel(self);
        float *d = (float *)(self + 0x640);
        if (d != pos) {
            d[0] = pos[0];
            d[1] = pos[1];
            d[2] = pos[2];
        }
        *(unsigned char *)(self + 0x2F4) = 0;
        *(unsigned char *)(self + 0x2F5) = 5;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
}
