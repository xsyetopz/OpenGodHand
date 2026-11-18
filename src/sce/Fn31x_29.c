// COMPILER: ee-gcc2.9-991111
// SCE library units in 0x31C000-0x31FFFF built by SCE ee-gcc 2.9x, -O2 -G0.

extern int D_00755BC8;
extern char D_00450FC0[], D_004511A8[];
void func_0031DAA0(void);

typedef struct Quad { void *a; void *b; void *c; void *d; } Quad;

// FUNCTION: GAME 0x31DB50
void func_0031DB50(void)
{
    if (D_00755BC8)
        return;
    D_00755BC8 = 1;
    func_0031DAA0();
}

// FUNCTION: GAME 0x31EE80
void func_0031EE80(Quad *p, void *a, void *c, void *d)
{
    if (p) { p->a = a; p->b = D_00450FC0; p->c = c; p->d = d; }
}

// FUNCTION: GAME 0x31FA40
void func_0031FA40(Quad *p, void *a, void *c, void *d)
{
    if (p) { p->a = a; p->b = D_004511A8; p->c = d; p->d = c; }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x31D098
// 8 words differ: register allocation (original keeps *p in v0, constants in a1/v1); same under 2.9
void func_0031D098(unsigned *p)
{
    *p = *p * 0x19660D + 0x3C6EF35F;
}
#endif
