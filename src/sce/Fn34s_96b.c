// COMPILER: ee-gcc2.96
// SCE library units 0x341000-0x348000 (small), ee-gcc 2.96 -O2 -G0.

extern int D_003EE078, D_003EE07C, D_003EE080, D_003EE084;
void func_003395A0(int, int, int);
void func_00359EC0(int);
void func_0035A128(int);
int func_00335AA0(void);
void func_003412D8(char *);
void func_00341120(char *);

// FUNCTION: GAME 0x342B78
int *func_00342B78(int *a, unsigned b) { if (b < 0x8C) return 0; *a = 1; return a; }

// FUNCTION: GAME 0x343E00
void func_00343E00(char *a) { func_003395A0(*(int *)(a + 0x1C4), *(int *)(a + 0x1C8), *(int *)(a + 0x1CC)); }

// FUNCTION: GAME 0x346798
void func_00346798(char *a) { func_00359EC0(a ? *(int *)(a + 0x3C) : 0); }

// FUNCTION: GAME 0x3467C0
void func_003467C0(char *a) { func_0035A128(a ? *(int *)(a + 0x3C) : 0); }

// DRAFT: GAME 0x3472E8
// diff: 3 words; original returns via $a0 (delay-slot li 1) with a different branch layout
#ifdef NONMATCHING
int func_003472E8(int *a) { int v = a[8]; return v == 0 || v == 0x101; }
#endif

// FUNCTION: GAME 0x347DF8
int func_00347DF8(void) { return func_00335AA0() == 3; }

// FUNCTION: GAME 0x341458
void func_00341458(char *a) { if (*(short *)(a + 0x9C) == 1) func_003412D8(a); else func_00341120(a); }

// FUNCTION: GAME 0x346450
void func_00346450(void) { D_003EE078 = 1; D_003EE07C = 0; D_003EE080 = 0; D_003EE084 = 0; }

void func_0035F838(void);
void func_0035F958(void (*)(void), int);
void func_00346BE0(void);
void func_0036C920(int, int, int);
int *func_003452B0(void);
int func_00346C48(int);
void func_0035FC58(int, int);
void func_00335B88(int);

// FUNCTION: GAME 0x346BB8
void func_00346BB8(void) { func_0035F838(); func_0035F958(func_00346BE0, 0); }

// DRAFT: GAME 0x342E50
// diff: 4 words; li $a0,0x600 is scheduled after the first sw in the original, before it in ours
#ifdef NONMATCHING
int func_00342E50(int a, int *b, int *c, int *d) { *b = 0x4000; *c = 0x100; *d = 0x600; return *b + *c + *d; }
#endif

// FUNCTION: GAME 0x344BC0
void func_00344BC0(int a, int b, int c) { func_0036C920(a, b, c * 1000); }

// FUNCTION: GAME 0x345750
int func_00345750(int a) { func_003452B0()[0x68 / 4] = a; return a; }

// FUNCTION: GAME 0x3471B8
void func_003471B8(int a, int b) { func_0035FC58(func_00346C48(a), b); }

// FUNCTION: GAME 0x347E20
void func_00347E20(int *a) { int v = a[0x48 / 4]; if (v) func_00335B88(v); }
