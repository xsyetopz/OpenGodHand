extern "C" void setMeshDispFromLayer__7cOmBaseUib(void *, unsigned, int);

#define B(o) (*(unsigned char *)(self + (o)))

struct Ch {
    unsigned n;
    char *p;
};

static inline bool Ok(int i, int n)
{
    return i >= 0 && i < n;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1BBF68
// 66 words off: gcc emits movz for the (i>=0&&i<n) bool where original branches (slt a3,t0; bnez) and keeps loop var in a1/a3 pair; tried raw && expr, bool helper, Ch struct spill.
extern "C" int func_001BBF68(char *self)
{
    setMeshDispFromLayer__7cOmBaseUib(self, 0, 1);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x40, 0);
    for (int i = 1; i < *(signed char *)(self + 0x624) && B(0x2B4) != i; i++) {
        Ch a;
        char *c;
        a.n = B(0x2B4);
        if (Ok(i, a.n))
            c = *(char **)(*(char **)(self + 0x278) + i * 4);
        else
            c = 0;
        *(unsigned *)(c + 0x154) |= 8;
        Ch b;
        char *d;
        b.n = B(0x2B4);
        if (Ok(i, b.n))
            d = *(char **)(*(char **)(self + 0x278) + i * 4);
        else
            d = 0;
        *(unsigned *)(d + 0x154) |= 0x10;
    }
    *(unsigned *)(self + 0x5B8) |= 4;
    if (*(unsigned **)(self + 0x600))
        **(unsigned **)(self + 0x600) |= 1;
    return 1;
}
#endif
