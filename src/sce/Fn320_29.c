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
