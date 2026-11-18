// Mid-size units in 0x200000-0x230000.
extern "C" void func_002011B0(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x2017A8 - self/b saved-register swap (s0/s1), loop 2 otherwise equal
extern "C" char *func_002017A8(char *self)
{
    char *b = self + 4;
    char *e = b;
    char *p = b;
    int i;
    for (i = 0; i < 0x20; i++, e += 0x88, p += 0x88) {
        if (*(int *)p == 0)
            return e;
    }
    func_002011B0(self);
    e = self + 4;
    p = b;
    int end = (int)b + 0x1100;
    for (; (int)p < end; p += 0x88, e += 0x88) {
        if (*(int *)p == 0)
            return e;
    }
    return 0;
}
#endif

extern "C" void func_00201290(void *);
extern "C" void func_00201228(void *, void *);

class cHeap;
void *_MemoryAlloc(unsigned int, unsigned int, cHeap &);
extern int D_00580D40;
struct DvdSlot {
    int used;
    int id;
    int ret;
    int fC;
    char pad0[0x5C];
    int f6C;
    int f70;
    int f74;
    unsigned f78;
    int f7C;
    void *f80;
};
struct DvdQ {
    int cur;
};
extern "C" DvdSlot *func_002017A8(void *);
extern "C" int func_001FF9C0(int *, const char *, unsigned *, int *);
extern "C" int func_00201788(void *);

// FUNCTION: GAME 0x200CB0
extern "C" int ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(DvdQ *self, const char *name, void **out, cHeap &heap, int id, unsigned a, unsigned b, unsigned c)
{
    *out = 0;
    DvdSlot *s = func_002017A8(self);
    if (s == 0)
        return 0;
    int r = func_001FF9C0(&D_00580D40, name, &s->f78, &s->fC);
    s->ret = r;
    s->f7C = (int)&heap;
    s->f74 = (s->f78 + 0x7FF) >> 11;
    if (r < 0)
        return 0;
    s->used = 1;
    if (id == 0)
        s->id = func_00201788(self);
    else
        s->id = id;
    s->f6C = c;
    s->f70 = b;
    s->f80 = 0;
    if (a != 0)
        s->f74 = (a + 0x7FF) >> 11;
    void *p = _MemoryAlloc(s->f74 << 11, 0x80, heap);
    s->f80 = p;
    if (p == 0) {
        func_00201228(self, s);
        return 0;
    }
    *out = p;
    if (self->cur == 0)
        func_00201290(self);
    return s->id;
}

extern unsigned D_00747A84;
extern "C" void KeyStop__Fv();
extern "C" char *Getplayer__Fv();

#ifdef NONMATCHING
// DRAFT: GAME 0x201E80 - gcc folds the -0xC/-0x60 accesses into hi/lo-0x8000 base instead of keeping s0=&D_00747A84
extern "C" void setEnding__3cE3b(char *self, int v)
{
    unsigned *g = &D_00747A84;
    D_00747A84 |= 0x40000040;
    g[-3] |= 0x2000;
    KeyStop__Fv();
    g[-3] |= 0x400000;
    g[-3] |= 0x100000;
    g[-24] |= 8;
    *(float *)(Getplayer__Fv() + 0x54C) = 100.0f;
    self[3] = v;
    self[0] = 1;
}
#endif

extern unsigned D_00747A2C[];
extern char D_0042C7A0[];
extern char D_0042C7B8[];
extern char Sys[];
extern "C" void printf__FiiiiiiPCce(int, int, int, int, int, int, const char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x201AE0 - ~25 words: original keeps self[2] in t3 at the first test and shares the clamp store via v1; ours uses v0 and a split clamp
extern "C" void menu__3cE3(char *self)
{
    if (!(D_00747A2C[2] & 0x800))
        return;
    if (*((unsigned char *)D_00747A2C - 0x4FC) == 0)
        return;
    int t = self[2];
    if (t > 0)
        printf__FiiiiiiPCce(10, 16, 50, 50, 0, 0, D_0042C7A0);
    else
        printf__FiiiiiiPCce(10, 16, 50, 50, 0, 0, D_0042C7B8);
    if (*(unsigned *)(Sys + 0x98) & 0x2000)
        self[2]++;
    if (*(unsigned *)(Sys + 0x98) & 0x8000)
        self[2]--;
    int v = self[2];
    self[2] = v < 0 ? 0 : (v < 0x79 ? self[2] : 0x78);
}
#endif
