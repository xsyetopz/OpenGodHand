// COMPILER: ee-gcc2.9-991111
// SCE library units in 0x328000-0x333FFF built by SCE ee-gcc 2.9x, -O2 -G0.

extern char D_00756080[];
extern int D_003D848C, D_003D8488;
void func_0033E678(void);

typedef struct S28 { char _pad[0x28]; int a; int b; } S28;

// FUNCTION: GAME 0x3306C8
char *func_003306C8(void) { return D_00756080; }

// FUNCTION: GAME 0x332388
void func_00332388(S28 *p, int a, int b) { p->a = a; p->b = b; }

// FUNCTION: GAME 0x32F4D0
int func_0032F4D0(char *p, int i) { return *(int *)(p + i * 16 + 0xB4); }

// FUNCTION: GAME 0x32F4E0
int func_0032F4E0(char *p, int i) { return *(char *)(p + (i << 4) + 0xB0); }

#ifdef NONMATCHING
// DRAFT: GAME 0x3313E0
// 3 words differ: original materialises the address (lui/addiu) and loads through it; gcc folds %lo into the lw
int func_003313E0(void) { return D_003D848C; }

// DRAFT: GAME 0x3313F0
// 3 words differ: same address-folding difference as 0x3313E0
void func_003313F0(int v) { D_003D8488 = v; }

// DRAFT: GAME 0x329028
// original keeps an sd/ld $ra frame around a tail jump (j func_0033E678); gcc 2.9 emits a bare j (5 words differ)
void func_00329028(void) { func_0033E678(); }
#endif
