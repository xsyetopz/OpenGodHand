extern "C" void calcParts__6cModel(char *);
static inline char *getM(char *self, const int &n) { return n ? **(char ***)(self + 0x278) : 0; }
// FUNCTION: GAME 0x1CFA20
extern "C" void setThrow__9cOmWeaponRC4cVecP8cGameObj(char *self, float *pos, int a) {
    char *p = *(char **)(self + 0x600);
    if (p) {
        float *d = (float *)(self + 0x490);
        float *s = *(float **)(p + 0xF0);
        if (d != s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
    }
    *(float *)(self + 0x24C) = 1.0f;
    unsigned char n = *(unsigned char *)(self + 0x2B4);
    *(unsigned *)(self + 0x250) &= ~0x10u;
    *(int *)(self + 0x600) = 0;
    *(int *)(self + 0x630) = 0;
    char *m = getM(self, n);
    if (m) {
        *(char **)(m + 0x148) = self;
        *(int *)(m + 0x100) = 0;
        *(int *)(m + 0x104) = 0;
        *(int *)(m + 0x108) = 0;
        calcParts__6cModel(self);
        float *d = (float *)(self + 0x640);
        if (d != pos) { d[0] = pos[0]; d[1] = pos[1]; d[2] = pos[2]; }
        *(int *)(self + 0x670) = a;
        *(char *)(self + 0x2F5) = 3;
        *(char *)(self + 0x2F4) = 0;
        *(char *)(self + 0x2F6) = 0;
        *(char *)(self + 0x2F7) = 0;
    }
}
