struct D81A0 {
    char pad[0x16150];
    float a, b, c, d, e;
};

static inline int Cl(float v)
{
    if (v < 0.0f)
        return 0;
    return (int)v;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2D81A0
// 55 differing words: out ptr swapped into t0/a1, final lui/addu hoisted; tried struct offsets, early-return/ternary/if-assign clamp helper
extern "C" void func_002D81A0(D81A0 *self, float *out, unsigned long *col)
{
    int r = Cl(self->c);
    int g = Cl(self->d);
    int b = Cl(self->e);
    unsigned long R = (unsigned int)r;
    unsigned long G = (unsigned int)g;
    unsigned long B = (unsigned int)b;
    *col = R | (G << 8) | (B << 16);
    float n = self->a;
    out[3] = (n / (self->b - n) + 1.0f) * 255.0f;
    out[7] = -255.0f / (self->b - self->a);
}
#endif
