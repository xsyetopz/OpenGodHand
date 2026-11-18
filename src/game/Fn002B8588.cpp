static inline char *Child002B8588(char *base, int i)
{
    char *r = 0;
    const int &n = *(unsigned char *)(base + 0x2B4);
    unsigned char ok = i >= 0 && i < n;
    if (ok)
        r = *(char **)(*(int *)(base + 0x278) + i * 4);
    return r;
}

// DRAFT: GAME 0x2B8588 (36 differing words: reg alloc of ok/zero (v0/v1) and one-insn shift; tried stack ref temp, ok=0 init, Valid() helper)
#ifdef NONMATCHING
extern "C" void SetParentInfo__10cObjSimpleP8cObjBaseiG4cVecT3(char *self, char *base, int idx, float *v0, float *v1)
{
    if (base) {
        if (idx != -1 && !Child002B8588(base, idx))
            return;
        *(char **)(self + 0x30B0) = base;
        *(int *)(self + 0x30B4) = idx;
        float *d = (float *)(self + 0x30C0);
        if (d != v0) {
            d[0] = v0[0];
            d[1] = v0[1];
            d[2] = v0[2];
        }
        float *e = (float *)(self + 0x30D0);
        if (e != v1) {
            e[0] = v1[0];
            e[1] = v1[1];
            e[2] = v1[2];
        }
        *(char *)(self + 0x4E0) = 1;
    }
}
#endif
