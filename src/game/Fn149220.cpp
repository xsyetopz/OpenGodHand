extern "C" float F16toF32__FUs(unsigned short h);

#define TRUNCF(r, x) asm volatile("cvt.w.s $f0,%1\n\tcvt.s.w %0,$f0" : "=f"(r) : "f"(x) : "$f0", "memory")

// FUNCTION: GAME 0x149220
extern "C" void func_00149220(char *self, float s)
{
    if (*(int *)(self + 0x410) >= 0) {
        float a = F16toF32__FUs(*(unsigned short *)(*(char **)(self + 0x414) + 0x3E)) * s;
        float b = F16toF32__FUs(*(unsigned short *)(*(char **)(self + 0x414) + 0x40)) * s;
        float *p = (float *)(self + 0x38C);
        float *q = (float *)(self + 0x390);
        *p += a;
        *q += b;
        float t, u;
        TRUNCF(t, *p);
        *p -= t;
        TRUNCF(u, *q);
        *q -= u;
    }
}
