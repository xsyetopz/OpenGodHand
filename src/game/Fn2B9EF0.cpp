// Fn2B9EF0: allocate slot type 2, init embedded sub-object (two float args) or notify owner on failure.
struct Fn2B9EVt {
    char _pad0[0x18];
    short adj18;
    short _pad1A;
    void (*fn1C)(char *, float);
    char _pad20[8];
    short adj28;
    short _pad2A;
    void (*fn2C)(char *, float);
    short adj30;
    short _pad32;
    void (*fn34)(char *, char *);
};

struct Fn2B9EObj {
    char _pad0[0x18];
    Fn2B9EVt *vt;
};

extern char D_0044BCA0[];
extern char ZeroVec[];
extern "C" char *func_002BA300(void *, int);
extern "C" void func_002B8A70(char *, int);
extern "C" void func_002BB160(char *, int, int, char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x2B9EF0
// 5 words off: vtable lui/addiu in v0 (orig v1), 2 in v1 (orig a0); second vt as separate local vt2 fixed fn ptr reg; tried store order swap, *(int*)q, two/vv temps; sibling Fn2B9DF0 same
extern "C" char *func_002B9EF0(char *self, int a, int b, int c, char *d, float f, float g)
{
    char *p = func_002BA300(self, 2);
    if (p) {
        if (((*(unsigned *)p & 0x201) ^ 1) == 0) {
            func_002B8A70(p, a);
            char *q = p + 0xE0;
            func_002BB160(q, b, c, d);
            *(char **)(q + 0x100) = D_0044BCA0;
            *(int *)(p + 0xE0) = 2;
            Fn2B9EVt *vt = *(Fn2B9EVt **)(q + 0x100);
            vt->fn1C(q + vt->adj18, g);
            Fn2B9EVt *vt2 = *(Fn2B9EVt **)(q + 0x100);
            vt2->fn2C(q + vt2->adj28, f);
            *(char **)(p + 0x34) = q;
            return p;
        }
        Fn2B9EVt *vt = ((Fn2B9EObj *)self)->vt;
        vt->fn34(self + vt->adj30, p);
        return 0;
    }
    return 0;
}
#endif
