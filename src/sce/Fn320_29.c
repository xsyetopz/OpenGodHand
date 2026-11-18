// COMPILER: ee-gcc2.9-991111
// FLAGS: -O2
// SCE pass-through thunks and indirect-call stubs in 0x320000-0x330000 (2.9 emits a framed jal; 2.96 starts at 0x328098).

extern int func_0031EE10();
extern int free();
extern int (*D_003C4908)();
extern int (*D_003C490C)();

// FUNCTION: GAME 0x320010
int func_00320010() { return func_0031EE10(); }

// FUNCTION: GAME 0x320080
int func_00320080() { return func_0031EE10(); }

// FUNCTION: GAME 0x3200F0
int func_003200F0() { return func_0031EE10(); }

// FUNCTION: GAME 0x320160
int func_00320160() { return func_0031EE10(); }

// FUNCTION: GAME 0x3201D0
int func_003201D0() { return func_0031EE10(); }

// FUNCTION: GAME 0x320240
int func_00320240() { return func_0031EE10(); }

// FUNCTION: GAME 0x3212E8
int func_003212E8() { return free(); }

#ifdef NONMATCHING
// DRAFT: GAME 0x320280
int func_00320280() { return D_003C4908(); }
#endif

// FUNCTION: GAME 0x320338
int func_00320338() { return D_003C490C(); }

extern int func_003203B0();
extern int malloc();
extern void func_003211E0() __attribute__((noreturn));
extern int func_00320360();

// FUNCTION: GAME 0x320360
int func_00320360() { return D_003C490C() + 8; }

// FUNCTION: GAME 0x320418
int func_00320418() { return D_003C490C() + 4; }

// FUNCTION: GAME 0x320388
int func_00320388() { return (D_003C490C = func_003203B0)(); }

// FUNCTION: GAME 0x3212C0
int func_003212C0()
{
    int p = malloc();
    if (!p)
        func_003211E0();
    return p;
}

// FUNCTION: GAME 0x3214D0
void func_003214D0()
{
    int *q = *(int **)func_00320360();
    if (!q)
        func_003211E0();
    q[5] = 0;
}

#ifdef NONMATCHING
extern int *D_00755C18;

// DRAFT: GAME 0x3224D0 (9 words off under 2.9, store order is scheduler-dependent)
void func_003224D0(int v, int *n)
{
    n[3] = v;
    n[5] = (int)D_00755C18;
    D_00755C18 = n;
    n[2] = v;
    n[1] = 0;
    n[0] = 0;
    n[4] = 0;
}
#endif

extern struct { char a, b, c, d; short s; } D_00755BC0;

// FUNCTION: GAME 0x31D9F0
void func_0031D9F0(int a, int b)
{
    if (b == 0xFFFF && a) {
        D_00755BC0.c = 0x14;
        D_00755BC0.s = 0x3E8;
    }
}

extern struct S4408 { char *a, *b; } D_003C4408;
extern char D_004510D0[], D_004510D8[], D_00451198[];

#ifdef NONMATCHING
// DRAFT: GAME 0x31FB98 (4 words off, lui order of the two address constants)
struct S4408 *func_0031FB98()
{
    struct S4408 *p = &D_003C4408;
    if (!D_003C4408.a && p) {
        p->b = D_00451198;
        D_003C4408.a = D_004510D0;
    }
    return &D_003C4408;
}
#endif
