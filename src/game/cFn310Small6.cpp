// Small named functions in 0x310000-0x31FFFF, part 6.
extern "C" void *func_00312AB0(void *a, void *b);
extern "C" void *func_0030FB20(void *a, void *b);
extern union { unsigned w; unsigned short h; unsigned char b; } D_00747B10;

// FUNCTION: GAME 0x312A80
extern "C" void *CreateEventObj__F6eObjIdT0(void *a, void *b)
{
    return func_0030FB20(a, func_00312AB0(a, b));
}

// FUNCTION: GAME 0x31BD88
extern "C" void Pad_act_all_stop__13classPAD_WORK(char *p)
{
    int i;
    p += 0x160;
    for (i = 31; i != -1; i--) {
        *p = 0;
        p += 0x10;
    }
}

// FUNCTION: GAME 0x31CEF8
extern "C" unsigned char Rnd__Fv()
{
    unsigned x = D_00747B10.h * 5;
    D_00747B10.w = ((x & 0xFF) << 8) + ((x & 0xFF00) >> 8);
    return D_00747B10.b;
}

struct VT { char p0[8]; short adj3; void (*fn3)(void *, int); char p1[0x38]; short adj9; void (*fn9)(void *); };
struct cObj { char p0[0x214]; VT *vt; char p1[0x38]; int flags; };
extern "C" void func_0031B410(void *, void *);
extern "C" void free__5cHeapPv(void *, void *);
extern char g_ps2[];
extern int D_00747A78;

// FUNCTION: GAME 0x312778
extern "C" void delObj__FP4cObj(cObj *o)
{
    if (o)
        o->vt->fn3((char *)o + o->vt->adj3, 3);
}

// FUNCTION: GAME 0x31AFA0
extern "C" void KeyStop__Fv()
{
    int *p = &D_00747A78;
    *p |= 0x2000000;
    func_0031B410(g_ps2, (char *)p - 0x460);
}

// FUNCTION: GAME 0x31C928
extern "C" void func_0031C928(void *p, void *heap)
{
    if (p)
        free__5cHeapPv(heap, p);
}


extern "C" int func_0014FF00(int, int, int, ...);
extern int D_007476B0;

static inline int *slot(char *self, int idx) { return (int *)(self + ((D_007476B0 & 1) * 4 + idx * 8) + 0xB00); }

// FUNCTION: GAME 0x31A600
extern "C" int func_0031A600(char *self, int idx, int a, int b)
{
    if (idx < 10)
        return func_0014FF00(*slot(self, idx), a, b, b);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x31A650 (2 words differ: a1/a3 arg moves swapped)
extern "C" int func_0031A650(char *self, int idx, int a, int b, int c)
{
    if (idx < 10) {
        if (!c)
            c = b;
        return func_0014FF00(*slot(self, idx), a, b, c);
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x312708 (18 words differ: original hoists lui 0x8000, o in s0)
struct RObj { char p0[0x214]; VT *vt; char p1[0x38]; int flags; };
extern "C" void func_002CBE18(void *, void *);
extern char Snd[];
extern "C" void ReleaseObj__FP4cObj(RObj *o)
{
    if (o && o->flags >= 0) {
        func_002CBE18(Snd, o);
        o->vt->fn9((char *)o + o->vt->adj9);
        int f = 0x80000002;
        o->flags |= f;
    }
}
#endif
