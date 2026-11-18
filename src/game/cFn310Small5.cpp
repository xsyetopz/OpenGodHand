// Small unnamed functions in 0x310000-0x31FFFF, part 5.
extern "C" int strcmp(const char *, const char *);
extern unsigned int D_00747A2C;
extern char D_00450FC0[], D_004511A8[];

struct Quad { void *a; void *b; void *c; void *d; };
struct PP { int *p; };
struct StrP { const char *s; };

// FUNCTION: GAME 0x31F480
extern "C" int func_0031F480(int *p) { return *p; }
#ifdef NONMATCHING
// DRAFT: GAME 0x31D098
// 8 words differ: register allocation (original keeps *p in v0, constants in a1/v1)
extern "C" void func_0031D098(unsigned *p) { *p = *p * 0x19660D + 0x3C6EF35F; }
#endif
#ifdef NONMATCHING
// DRAFT: GAME 0x31EE80
// 4 words differ: original stores d first, then a, b, c; gcc emits c first
extern "C" void func_0031EE80(Quad *p, void *a, void *c, void *d) { if (p) { p->d = d; p->a = a; p->b = D_00450FC0; p->c = c; } }
#endif
#ifdef NONMATCHING
// DRAFT: GAME 0x31FA40
// 4 words differ: store order (same as 0x31EE80)
extern "C" void func_0031FA40(Quad *p, void *a, void *c, void *d) { if (p) { p->d = c; p->a = a; p->b = D_004511A8; p->c = d; } }
#endif
// FUNCTION: GAME 0x31F4E0
extern "C" unsigned func_0031F4E0(StrP *a, StrP *b) { return (unsigned)strcmp(a->s, b->s) >> 31; }
// FUNCTION: GAME 0x31CA58
extern "C" unsigned func_0031CA58(unsigned v) { return (v & 0xFF000000) | ((v >> 16) & 0xFF) | (v & 0xFF00) | ((v & 0xFF) << 16); }
// FUNCTION: GAME 0x31A088
extern "C" void func_0031A088(char *o, unsigned bit) { unsigned *w = (unsigned *)(o + 0x350); w[bit >> 5] |= 0x80000000u >> (bit & 0x1F); }
// FUNCTION: GAME 0x3186D0
extern "C" int func_003186D0(char *o) { if (*(unsigned *)(o + 0x250) & 2) return 1; unsigned m = 0x400000; return (D_00747A2C & m) > 0; }
