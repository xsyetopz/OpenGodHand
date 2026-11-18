// Small ctor-like unnamed functions in 0x310000-0x31FFFF.
extern char D_00451008[], D_00451020[], D_00450FF0[], D_00451038[], D_00451188[], D_00451178[], D_00451168[], D_00451158[], D_00450FD8[];

struct VtObj { void *vt; };
struct PairObj { void *a; void *b; };
struct TriObj { void *a; void *b; void *c; };

// FUNCTION: GAME 0x31F360
extern "C" VtObj *func_0031F360(VtObj *p) { p->vt = D_00451008; return p; }
// FUNCTION: GAME 0x31F3F8
extern "C" VtObj *func_0031F3F8(VtObj *p) { p->vt = D_00451020; return p; }
// FUNCTION: GAME 0x31F2A8
extern "C" PairObj *func_0031F2A8(PairObj *p, void *a) { p->a = a; p->b = D_00450FF0; return p; }
// FUNCTION: GAME 0x31F488
extern "C" PairObj *func_0031F488(PairObj *p, void *a) { p->a = a; p->b = D_00451038; return p; }
// FUNCTION: GAME 0x31EEC8
extern "C" void func_0031EEC8(PairObj *p, void *a) { if (p) { p->a = a; p->b = D_00450FF0; } }
// FUNCTION: GAME 0x31FA68
extern "C" void func_0031FA68(PairObj *p, void *a) { if (p) { p->a = a; p->b = D_00451188; } }
// FUNCTION: GAME 0x31FA88
extern "C" void func_0031FA88(PairObj *p, void *a) { if (p) { p->a = a; p->b = D_00451178; } }
// FUNCTION: GAME 0x31FAA8
extern "C" void func_0031FAA8(PairObj *p, void *a) { if (p) { p->a = a; p->b = D_00451168; } }
// FUNCTION: GAME 0x31FAC8
extern "C" void func_0031FAC8(PairObj *p, void *a) { if (p) { p->a = a; p->b = D_00451158; } }
// FUNCTION: GAME 0x31F218
extern "C" TriObj *func_0031F218(TriObj *p, void *a, void *c) { p->b = D_00450FD8; p->a = a; p->c = c; return p; }
