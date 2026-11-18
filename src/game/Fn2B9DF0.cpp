// Fn2B9DF0: allocate a slot, init its embedded sub-object or notify the owner on failure.
struct Fn2B9Vt {
    char _pad0[0x18];
    short adj18;
    short _pad1A;
    void (*fn1C)(char *, float);
    char _pad20[0x10];
    short adj30;
    short _pad32;
    void (*fn34)(char *, char *);
};

struct Fn2B9Obj {
    char _pad0[0x18];
    Fn2B9Vt *vt;
};

extern char D_0044BD60[];
extern char ZeroVec[];
extern "C" char *func_002BA300(void *, int);
extern "C" void func_002B8A70(char *, int);
extern "C" void func_002BB160(char *, int, int, char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x2B9DF0
// 3 words differ: vtable constant lui/addiu in v0 (orig v1); tried temp local, &D_ extern form, q reassign, store order, int-returning callee
extern "C" char *func_002B9DF0(char *self, int a, int b, int c, float f)
{
    char *p = func_002BA300(self, 0);
    if (p) {
        if (((*(unsigned *)p & 0x201) ^ 1) == 0) {
            func_002B8A70(p, a);
            char *q = p + 0xE0;
            func_002BB160(q, b, c, ZeroVec);
            *(char **)(q + 0x100) = D_0044BD60;
            *(int *)(p + 0xE0) = 0;
            Fn2B9Vt *vt = *(Fn2B9Vt **)(q + 0x100);
            vt->fn1C(q + vt->adj18, f);
            *(char **)(p + 0x34) = q;
            return p;
        }
        Fn2B9Vt *vt = ((Fn2B9Obj *)self)->vt;
        vt->fn34(self + vt->adj30, p);
        return 0;
    }
    return 0;
}
#endif
