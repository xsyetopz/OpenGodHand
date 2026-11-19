extern "C" void calcParts__6cModel(char *);

#ifdef NONMATCHING
static inline void reset(char *self, int v)
{
    char *p = *(char **)(self + 0x600);
    if (p) {
        float *d = (float *)(self + 0x490);
        float *s = *(float **)(p + 0xF0);
        if (d != s) { d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; }
    }
    *(float *)(self + 0x24C) = 1.0f;
    unsigned char n = *(unsigned char *)(self + 0x2B4);
    volatile int sp = n;
    *(unsigned *)(self + 0x250) &= ~0x10u;
    *(int *)(self + 0x600) = 0;
    *(int *)(self + 0x630) = 0;
    char *m = n ? **(char ***)(self + 0x278) : 0;
    if (m) {
        *(int *)(m + 0x108) = 0;
        *(char **)(m + 0x148) = self;
        *(int *)(m + 0x100) = 0;
        *(int *)(m + 0x104) = 0;
        calcParts__6cModel(self);
        *(char *)(self + 0x2F7) = 0;
        *(char *)(self + 0x2F5) = v;
        *(int *)(self + 0x670) = 0;
        *(char *)(self + 0x2F4) = 0;
        *(char *)(self + 0x2F6) = 0;
    }
}

// DRAFT: GAME 0x1D0340
// 11 words differ: target puts the volatile n spill in beqz's delay slot after the 0x600/0x630 stores; tried volatile spill before/after 0x600, all m-block stores volatile, if(n) form (21-26 words).
extern "C" void func_001D0340(char *self) { reset(self, 0x14); }

// DRAFT: GAME 0x1D0408
// 11 words differ, same body as 0x1D0340 (only the 0x15 constant differs); no variant tried separately.
extern "C" void func_001D0408(char *self) { reset(self, 0x15); }
#endif
