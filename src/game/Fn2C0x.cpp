// Small helpers in 0x2C0000-0x2D0000.

// FUNCTION: GAME 0x2C30C8
extern "C" unsigned func_002C30C8(void *self, unsigned *p)
{
    unsigned v = *p;
    if (v != 0xFFFFFFFF) {
        while (1) {
            unsigned m = v & 0x7FFFFFFF;
            if (v & 0x80000000)
                return m;
            v = *(unsigned *)m;
            if (v == 0xFFFFFFFF)
                break;
        }
    }
    return 0;
}

struct Tbl2C9008 {
    char *base;
    int p4, p8;
    unsigned max;
    int cnt;
    signed char idx[1];
};

// FUNCTION: GAME 0x2C9008
extern "C" char *func_002C9008(Tbl2C9008 *t, unsigned i)
{
    char *base = t->base;
    if (base == 0)
        return 0;
    if (t->cnt == 0 || t->cnt < (int)i)
        return 0;
    if (t->max == 0)
        return 0;
    if (i >= t->max)
        return 0;
    return base + t->idx[i] * 0x24;
}
