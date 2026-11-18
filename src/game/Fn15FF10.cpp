struct V15 {
    char _p[0x18];
    short adj;
    short _pad;
    void (*fn)(void *);
};
extern int D_00747A84;
extern "C" char *func_00161288(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x15FF10
// 28 words differ: D-4 accessed as 0x7FFC(s1-0x8000) not -4(s1), EE0 load order; tried &D-0x5E4 constant-folded (46), p var (43)
extern "C" void func_0015FF10(char *self)
{
    int *p = &D_00747A84;
    if (!(D_00747A84 & 0x08000000))
        return;
    char *o = func_00161288(self);
    if (o) {
        V15 *v = *(V15 **)(o + 0x70);
        v->fn(o + v->adj);
    }
    *(int *)(self + 0x48) = -1;
    int e0 = *(int *)(self + 0xEE0);
    int e4 = *(int *)(self + 0xEE4);
    char *q = (char *)p - 0x5E4;
    *(int *)(q + 0x5D8) = e0;
    int f = p[-1];
    *(int *)(q + 0x5E0) = e4;
    if (f & 0x40000)
        p[-1] |= 0x40000;
    else
        p[-1] &= 0xFFFBFFFF;
    D_00747A84 &= 0xF7FFFFFF;
    int i = 8;
    int *a = (int *)(self + 0xF08);
    *(char *)(self + 0xED4) = 0;
    *(short *)(self + 0x50) = 0;
    do {
        *a = -1;
        i--;
        a--;
    } while (i >= 0);
    *(char *)(self + 0xF15) = 0;
}
#endif
