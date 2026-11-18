// Small game functions at 0x300000-0x310000 (2.95.3-136 C++).
extern "C" void func_002FBE88(void);
extern "C" void func_00306AA8(void);
extern "C" void func_003028E8(void *);
extern "C" void func_002FB7B0(int);
extern "C" void func_00300C00(int, int);
extern "C" void func_002F7110(void *);
extern "C" int D_00450080;
extern "C" int D_0044FCF8;

struct S4 { char pad[0xF0]; void *p; };
struct S5A { char pad[0x420]; float f; void *p; };
struct S5B { int pad[0x100]; unsigned a, b, c, d, e, f; };

// FUNCTION: GAME 0x3052E8
extern "C" void func_003052E8(void) { func_002FBE88(); }

// FUNCTION: GAME 0x306A88
extern "C" void func_00306A88(void) { func_00306AA8(); }

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

#ifdef NONMATCHING
// DRAFT: GAME 0x300060 (8 words off: original copies a0 to v0 and tests v0)
extern "C" void func_00300060(void *a) { if (a) func_002F7110(a); }
#endif
