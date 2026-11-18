extern "C" void calcParts__6cModel(char *);

#ifdef NONMATCHING
static inline void reset(char *self, float *pos, int v, int a)
{
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
    volatile int sp = n;
    *(int *)(self + 0x630) = 0;
    char *m = n ?**(char ***)(self + 0x278) : 0;
    if (m) {
        *(char **)(m + 0x148) = self;
        *(int *)(m + 0x100) = 0;
        *(int *)(m + 0x104) = 0;
        *(int *)(m + 0x108) = 0;
        calcParts__6cModel(self);
        float *d = (float *)(self + 0x640);
        *(int *)(self + 0x670) = a;
        if (d != pos) { d[0] = pos[0]; d[1] = pos[1]; d[2] = pos[2]; }
        *(char *)(self + 0x2F4) = 0;
        *(char *)(self + 0x2F6) = 0;
        *(char *)(self + 0x2F5) = v;
        *(char *)(self + 0x2F7) = 0;
    }
}

// DRAFT: GAME 0x1D0140
// 2 words differ: spill sw a0,0(sp) lands before sw 0x630 instead of in beqz delay slot; tried volatile spill at 3 positions, (sp = n) in the ternary (worse).
extern "C" void func_001D0140(char *self, float *pos, int a) { reset(self, pos, 0x11, a); }

// DRAFT: GAME 0x1D0240
// 2 words differ: same spill-position issue as 0x1D0140.
extern "C" void func_001D0240(char *self, float *pos, int a) { reset(self, pos, 0x12, a); }
#endif
