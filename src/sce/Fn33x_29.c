// COMPILER: ee-gcc2.9-991111
// SCE library units in 0x328000-0x333FFF built by SCE ee-gcc 2.9x, -O2 -G0.

extern char D_00756080[];
extern int D_003D848C, D_003D8488;

typedef struct S28 { char _pad[0x28]; int a; int b; } S28;

// FUNCTION: GAME 0x3306C8
char *func_003306C8(void) { return D_00756080; }

// FUNCTION: GAME 0x332388
void func_00332388(S28 *p, int a, int b) { p->a = a; p->b = b; }

// FUNCTION: GAME 0x32F4D0
int func_0032F4D0(char *p, int i) { return *(int *)(p + i * 16 + 0xB4); }

// FUNCTION: GAME 0x32F4E0
int func_0032F4E0(char *p, int i) { return *(char *)(p + (i << 4) + 0xB0); }
