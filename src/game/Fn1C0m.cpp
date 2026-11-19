extern "C" void func_001DEE60(void *, int, int);

#define MODE_FN(name, a, b)                                  \
    extern "C" void name(char *self, unsigned char m)        \
    {                                                        \
        switch (m) {                                         \
        case 0:                                              \
            func_001DEE60(self, a, 0);                       \
            func_001DEE60(self, b, 1);                       \
            break;                                           \
        case 1:                                              \
            func_001DEE60(self, a, 1);                       \
            func_001DEE60(self, b, 1);                       \
            break;                                           \
        }                                                    \
    }

// FUNCTION: GAME 0x1DEF48
MODE_FN(func_001DEF48, 2, 3)
// FUNCTION: GAME 0x1DEFC8
MODE_FN(func_001DEFC8, 4, 5)

extern "C" void func_001C0450(void *);
struct SvP {
    float v[3];
    SvP &operator=(const float *o)
    {
        if (v != o) {
            v[0] = o[0];
            v[1] = o[1];
            v[2] = o[2];
        }
        return *this;
    }
};
struct Obj1C2 {
    char p0[0xF0];
    SvP *tgt;
    char p1[0x490 - 0xF4];
    SvP org;
    char p2[0x5B8 - 0x49C];
    unsigned int fl;
};

// FUNCTION: GAME 0x1C2630
extern "C" void func_001C2630(Obj1C2 *self, const float *v)
{
    *self->tgt = v;
    func_001C0450(self);
    self->org = v;
    self->fl |= 0x10;
}

extern "C" void func_001DBF18(void *, unsigned short *, unsigned short *, unsigned short *, unsigned short *);

// FUNCTION: GAME 0x1DC710
extern "C" int func_001DC710(char *self)
{
    unsigned short a[4];
    func_001DBF18(self, &a[0], &a[1], &a[2], &a[3]);
    if (a[0] == 5 || a[1] == 5 || a[2] == 5 || a[3] == 5) {
        int **pp = (int **)(self + 0x3004);
        int i;
        for (i = 4; i >= 0; i--) {
            (*pp)[1] |= 4;
            pp++;
        }
        return 1;
    }
    return 0;
}

struct Obj1C23;
extern "C" void func_001C2378(Obj1C23 *);
extern "C" void calcParts__6cModel(void *);
struct Obj1C22 {
    char p0[0x2F6];
    char c6;
    char p1[0x630 - 0x2F7];
    int a;
    int b;
    int pad0[2];
    SvP v1;
    float pad1;
    SvP v2;
};

// FUNCTION: GAME 0x1C2280
extern "C" void func_001C2280(Obj1C22 *self, int a, int b, const float *v1, const float *v2)
{
    self->a = a;
    self->b = b;
    self->v1 = v1;
    self->v2 = v2;
    self->c6 = 2;
    func_001C2378((Obj1C23 *)self);
    calcParts__6cModel(self);
}

extern "C" void sceVu0ApplyMatrix(void *, void *, void *);
struct Mdl1C23 {
    char p0[0x278];
    char **tbl;
    char p1[0x2B4 - 0x27C];
    unsigned char n;
};
struct Obj1C23 {
    char p0[0xF0];
    SvP *tgt;
    char p1[0x630 - 0xF4];
    Mdl1C23 *m;
    int idx;
    int pad0[2];
    SvP v1;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x1C2378 - 7 words: n spill is sb/andi instead of sw/slt on the loaded byte; target shares epilogue via beqz, ours duplicates. tried: int n (34), goto shared exit (34), int+goto (34), if-assign e (34), tbl local (35), tgt local (33), unsigned n (34), direct m->n compare (33)
extern "C" void func_001C2378(Obj1C23 *self)
{
    Mdl1C23 *m = self->m;
    if (m != 0) {
        int i = self->idx;
        unsigned char n = m->n;
        const unsigned char &r = n;
        char *e = (i >= 0 && i < r) ? m->tbl[i] : 0;
        *self->tgt = (const float *)&self->v1;
        sceVu0ApplyMatrix(self->tgt, e + 0x80, self->tgt);
    }
}
#endif
