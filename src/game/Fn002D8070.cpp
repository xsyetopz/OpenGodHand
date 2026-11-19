struct D8070 {
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
// DRAFT: GAME 0x2D8070
// 6 differing words: cvt.w.s target f0 vs in-place f1 in three clamps; tried local ints/ulong temps, ternary and if-assign clamp (worse)
extern "C" void func_002D8070(D8070 *self, float *out, unsigned long *col, float f)
{
    *col = (unsigned long)(unsigned int)Cl(self->c) | ((unsigned long)(unsigned int)Cl(self->d) << 8) | ((unsigned long)(unsigned int)Cl(self->e) << 16);
    float v;
    if (f > 0.0f) {
        float n = self->a;
        float d = self->b - n;
        v = (n / d + 1.0f - f / d) * 255.0f;
    } else {
        v = 255.0f;
    }
    if (v < 0.0f) v = 0.0f;
    if (v > 255.0f) v = 255.0f;
    out[7] = v;
}
#endif
