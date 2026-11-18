// Small game functions at 0x300000-0x310000 (2.95.3-136 C++).
extern "C" void func_002FBE88(void);
extern "C" void func_00306AA8(int *);
extern "C" void func_003028E8(void *);
extern "C" void func_002FB7B0(int);
extern "C" void func_00300C00(int, int);
extern "C" void func_002F7110(void *);
extern "C" int func_003069A8(char *, unsigned, char **);
extern "C" int func_00306A08(char *, unsigned, char **);
extern "C" void func_003128B0(void *);
extern "C" void func_002A9528(void *);
extern "C" int func_00303A20(void *);
extern "C" int func_003AF980(int, void *, int);
extern "C" void func_003B0740(int);
extern "C" void func_0030D190(void);
extern "C" void KillEffect__FPC4cObji13eEspEraseMode(int, int, int);
extern "C" char objArray[], scrArray[], D_00754C50[], objbaseArray[], D_00754C20[], D_00754C10[];
extern "C" int D_00450080;
extern "C" int D_0044FCF8;

struct E16 { int a, b, c, d; };
struct T4 { char pad[0x108]; char *s; char pad2[0x240 - 0x10C]; int a, b, c, d; };
struct U5 { char pad[0x414]; unsigned m; };
struct S4 { char pad[0xF0]; void *p; };
struct S5A { char pad[0x420]; float f; void *p; };
struct S5B { int pad[0x100]; unsigned a, b, c, d, e, f; };

// FUNCTION: GAME 0x3052E8
extern "C" void func_003052E8(void) { func_002FBE88(); }

// FUNCTION: GAME 0x306A88
extern "C" void func_00306A88(int *a) { func_00306AA8(a); }

// FUNCTION: GAME 0x304F58
extern "C" void func_00304F58(S4 *s) { s->p = &D_0044FCF8; func_003028E8(s); }

// FUNCTION: GAME 0x306140
extern "C" void func_00306140(void) { func_002FB7B0(0x20); func_00300C00(0x20, 1); }

// FUNCTION: GAME 0x3069E8
extern "C" int func_003069E8(char *a, int u, char **o1, char **o2) {
    *o1 = a + *(int *)(a + 4);
    *o2 = a + *(int *)(a + 8);
    return 1;
}

// FUNCTION: GAME 0x305A18
extern "C" S5A *func_00305A18(S5A *s) { s->p = &D_00450080; s->f = 1.0f; return s; }

// FUNCTION: GAME 0x305BC0
extern "C" void func_00305BC0(S5B *s) {
    s->f = 0; s->a = 0; s->b = 0; s->c = 0xFFFFFFFFu; s->d = 0xFFFFFFFFu;
}

// FUNCTION: GAME 0x3057A0
extern "C" void func_003057A0(E16 *p) {
    for (unsigned i = 0; i < 0x40; i++) { p[i].a = 5; p[i].b = 0; p[i].c = 0; p[i].d = 0; }
}

// FUNCTION: GAME 0x3058D8
extern "C" E16 *func_003058D8(E16 *p, int k) {
    for (unsigned i = 0; i < 0x40; i++) { if (p[i].a == k) return &p[i]; }
    return 0;
}

// FUNCTION: GAME 0x306A48
extern "C" int func_00306A48(char *a, unsigned i, char **o) {
    *o = 0;
    if (i >= *(unsigned *)(a + 4)) return 0;
    char *q = (char *)((int *)a + i);
    int off = *(int *)(q + 0x10);
    if (!off) return 0;
    *o = a + off;
    return 1;
}

// FUNCTION: GAME 0x306C78
extern "C" int func_00306C78(char **a, unsigned i, char **o, char **p) {
    *o = 0; *p = 0;
    if (i < 0x40) {
        char *z = (char *)a + (i << 2); char *q = *(char **)z;
        if (q) return func_003069E8(q, i, o, p) != 0;
    }
    return 0;
}

// FUNCTION: GAME 0x306CC8
extern "C" int func_00306CC8(char **a, unsigned i, char **o, char **p) {
    *p = 0;
    if (i < 0x40) {
        char *z = (char *)a + (i << 2); char *q = *(char **)z;
        if (q) return func_00306A08(q, (unsigned)o, p) != 0;
    }
    return 0;
}

// FUNCTION: GAME 0x3078E0
extern "C" int func_003078E0(unsigned a) {
    if (!a) return -1;
    unsigned v = a & 0xFF00;
    if (v == 0x500) return -1;
    if (!((int)v < 0x601)) return -1;
    return a | 0x40000000;
}

// FUNCTION: GAME 0x3089F0
extern "C" int func_003089F0(int *a, int k) {
    for (int i = 0; i < 0x20; i++) { if (a[i] == k) return 1; if (!a[i]) { a[i] = k; return 1; } }
    return 0;
}

// FUNCTION: GAME 0x308D68
extern "C" int func_00308D68(int *a, int k) {
    for (int i = 0; i < 0x20; i++) { if (!a[i]) return 0; if (a[i] == k) return 1; }
    return 0;
}

// FUNCTION: GAME 0x304BF8
extern "C" int func_00304BF8(T4 *t) {
    char *s = t->s;
    if (s) {
        t->a = (unsigned char)s[0x2F4]; t->b = (unsigned char)s[0x2F5];
        t->c = (unsigned char)s[0x2F6]; t->d = (unsigned char)s[0x2F7];
        return func_00303A20(t);
    }
    return 0;
}

// FUNCTION: GAME 0x305F58
extern "C" void func_00305F58(U5 *u, int n) {
    unsigned b = 1u << n;
    if (u->m & b) { u->m &= ~b; KillEffect__FPC4cObji13eEspEraseMode(0, n + 0x2200, 2); }
}

// FUNCTION: GAME 0x306A08
extern "C" int func_00306A08(char *a, unsigned i, char **o) {
    *o = 0;
    char *b = a + *(int *)(a + 0xC);
    if (i >= *(unsigned *)(b + 4)) return 0;
    return func_003069A8(b, i, o);
}

// FUNCTION: GAME 0x306AA8
extern "C" void func_00306AA8(int *a) {
    for (unsigned i = 0; i < 0x4E2; i++) a[0x40 + i] = 0;
    for (unsigned i = 0; i < 0x40; i++) a[i] = 0;
}

// FUNCTION: GAME 0x30D1F8
extern "C" void func_0030D1F8(void) {
    *(volatile int *)0x10000000 = 0;
    *(volatile int *)0x10000020 = 0x2589;
    *(volatile int *)0x10000010 |= 0x1C2;
    func_003AF980(9, (void *)func_0030D190, 0);
    func_003B0740(9);
}

// FUNCTION: GAME 0x30F5F0
extern "C" void func_0030F5F0(void) {
    func_003128B0(objArray); func_003128B0(scrArray); func_003128B0(D_00754C50); func_003128B0(objbaseArray);
    func_002A9528(D_00754C20); func_002A9528(D_00754C10);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x300060 (8 words off with -O2 -G0: original copies a0 to v0 and tests v0)
extern "C" void func_00300060(void *a) { if (a) func_002F7110(a); }
#endif
