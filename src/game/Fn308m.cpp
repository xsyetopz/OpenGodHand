// Unnamed units in 0x306000-0x31C000.
extern "C" void func_00306FC0(char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x307060 (23 words off: only a1/a2 register roles swapped)
extern "C" void func_00307060(char *self)
{
    char *a1 = self + 0x4200;
    char *a2 = a1;
    if (*(char **)(a2 + 4)) {
        do {
            a1 = *(char **)(a2 + 4);
            unsigned a3 = *(unsigned short *)(a2 + 0x10);
            if (*(char **)(a2 + 0xC) + (a3 << 4) == *(char **)(a1 + 0xC)) {
                *(unsigned short *)(a2 + 0x10) = a3 + *(unsigned short *)(a1 + 0x10);
                char *n = *(char **)(a1 + 4);
                if (n)
                    *(int *)n = *(int *)a1;
                *(char **)(a2 + 4) = *(char **)(a1 + 4);
                func_00306FC0(self);
                a2 = self + 0x4200;
            }
            a2 = *(char **)(a2 + 4);
        } while (a2 && *(char **)(a2 + 4));
    }
}
#endif

extern char g_CollScr[], scrArray[];
extern "C" char *func_001333B8(void *, unsigned short);
extern "C" int SearchScroll__9cScrArrayUl(void *, long);
extern "C" void ClearHiddenModelList__12HideModelMgr(void *);

// FUNCTION: GAME 0x307A60
extern "C" void func_00307A60(void *self)
{
    char *c = *(char **)g_CollScr;
    if (c && *(unsigned short *)(c + 0x2A)) {
        int i = 0;
        do {
            int *e = (int *)func_001333B8(g_CollScr, i);
            if (e && *e) {
                int r = SearchScroll__9cScrArrayUl(scrArray, *(long *)e);
                if (r) {
                    e[1] = r;
                    *e = 0;
                }
            }
            i++;
        } while (i < *(unsigned short *)(c + 0x2A));
    }
    ClearHiddenModelList__12HideModelMgr(self);
}

extern "C" int func_00306A48(int *, unsigned, int *);

#ifdef NONMATCHING
// DRAFT: GAME 0x306BB0 (about 40 words off: original keeps self+0x100 and idx*4 in separate callee-saved regs)
extern "C" int func_00306BB0(char *self, int idx)
{
    if (idx < 0x4E2) {
        int *tab = (int *)(self + 0x100);
        int *hdr = (int *)tab[idx];
        if (!hdr)
            return 0;
        if (hdr[1]) {
            unsigned i = 0;
            int *d = (int *)self;
            int t;
            do {
                if (func_00306A48(hdr, i, &t) && t)
                    *d = 0;
                i++;
                d++;
            } while (i < (unsigned)hdr[1]);
        }
        tab[idx] = 0;
        return 1;
    }
    return 0;
}
#endif

extern "C" void sceVu0UnitMatrix(float *);
extern "C" void sceVu0OuterProduct(float *, float *, float *);
extern "C" void sceVu0Normalize(float *, float *);
extern "C" void sceVu0TransMatrix(float *, float *, float *);
extern "C" void func_0030A3F8(void *, float *);

// FUNCTION: GAME 0x30A8C8
extern "C" void func_0030A8C8(void *out, float *pos, float *a, float *b)
{
    float m[16] __attribute__((aligned(16)));
    float t[4] __attribute__((aligned(16)));
    sceVu0UnitMatrix(m);
    sceVu0OuterProduct(t, b, a);
    sceVu0Normalize(m, t);
    sceVu0Normalize(m + 8, a);
    sceVu0OuterProduct(m + 4, m + 8, m);
    sceVu0TransMatrix(m, m, pos);
    func_0030A3F8(out, m);
}

extern "C" void sceVu0ScaleVector(float *, float *, float);
extern "C" void func_0030A3B0(float *, float *);

// FUNCTION: GAME 0x30A978
extern "C" void func_0030A978(float *m, float *x, float *y, float *z)
{
    float t[4] __attribute__((aligned(16)));
    sceVu0ScaleVector(t, x, -1.0f);
    sceVu0Normalize(m, t);
    sceVu0ScaleVector(t, y, -1.0f);
    sceVu0Normalize(m + 4, t);
    sceVu0ScaleVector(t, z, -1.0f);
    sceVu0Normalize(m + 8, t);
    float zero = 0.0f;
    m[15] = 1.0f;
    m[14] = zero;
    m[13] = zero;
    m[12] = zero;
    func_0030A3B0(m, m);
}

extern char D_00747A2C[];

#ifdef NONMATCHING
// DRAFT: GAME 0x30B090 (about 30 words off: original keeps one base reg and reloads flags; gcc splits base/offset and reuses the flag load)
extern "C" void func_0030B090(void)
{
    unsigned *b = (unsigned *)D_00747A2C;
    if (!(b[4] & 0x100000))
        return;
    if (b[-2] & 0x8000)
        return;
    unsigned *c = b - 0x58C / 4;
    if (b[-2] & 0x4000)
        c[0x5A0 / 4] = 0;
    if ((c[0] & 0x90F) != 0x90F) {
        b[-2] &= ~0x1000u;
        c[0x5A0 / 4] = 0;
        return;
    }
    int n = c[0x5A0 / 4] + 1;
    c[0x5A0 / 4] = n;
    if ((float)n >= 15.0f) {
        if (b[-2] & 0x1000)
            return;
        b[-2] |= 0x8000;
        c[0x5A0 / 4] = 0;
        b[-2] |= 0x1000;
    }
}
#endif
