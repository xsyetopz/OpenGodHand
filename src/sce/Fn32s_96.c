// COMPILER: ee-gcc2.96
// Tiny SCE accessors in 0x328098-0x340000.

extern int D_003EB850;
extern int D_003D1410, D_003D1414;
extern int D_003D90D4, D_003D90D8;
extern int D_003D9F6C, D_003D9F70;
extern int D_003DECFC, D_003DED00;
extern int D_007588A0[2];
extern int D_007588A8[2];
extern int D_007588C0[2];
extern int D_007588C8[2];
extern int D_003D04CC;
extern int D_003D1428;
extern int D_003D84B0;
extern int D_003E3A80;

// FUNCTION: GAME 0x333278
int func_00333278(int *a) { return (int)(((long)a[5] << 11) >> 32); }

// FUNCTION: GAME 0x33CFA8
int func_0033CFA8(char *a, int i) { return *(short *)(a + i * 2 + 0xE2); }

// FUNCTION: GAME 0x33FA00
void func_0033FA00(short *p, int a, int b, int c) { p[0x34/2] = a; p[0x36/2] = b; p[0x38/2] = c; }

// FUNCTION: GAME 0x33FB68
void func_0033FB68(void) { D_003EB850 = 1; }

// FUNCTION: GAME 0x32AB58
void func_0032AB58(int a) { D_003D1410 = a; D_003D1414 = a; }

// FUNCTION: GAME 0x3329D0
void func_003329D0(int a, int b) { D_003D90D4 = a; D_003D90D8 = b; }

// FUNCTION: GAME 0x334230
void func_00334230(int a, int b) { D_003D9F6C = a; D_003D9F70 = b; }

// FUNCTION: GAME 0x3364F8
void func_003364F8(int a, int b) { D_003DECFC = a; D_003DED00 = b; }

// FUNCTION: GAME 0x33BC18
void func_0033BC18(int a, int b) { D_007588A0[0] = a; D_007588A0[1] = b; }

// FUNCTION: GAME 0x33BC30
void func_0033BC30(int a, int b) { D_007588A8[0] = a; D_007588A8[1] = b; }

// FUNCTION: GAME 0x33BF88
void func_0033BF88(int a, int b) { D_007588C0[0] = a; D_007588C0[1] = b; }

// FUNCTION: GAME 0x33BFA0
void func_0033BFA0(int a, int b) { D_007588C8[0] = a; D_007588C8[1] = b; }

// FUNCTION: GAME 0x3284A0
void func_003284A0(void) { D_003D04CC ++; }

// FUNCTION: GAME 0x32A148
void func_0032A148(void) { D_003D1428 ++; }

// FUNCTION: GAME 0x3320E0
void func_003320E0(void) { D_003D84B0 ++; }

// FUNCTION: GAME 0x338960
void func_00338960(void) { D_003E3A80 ++; }

// FUNCTION: GAME 0x338978
void func_00338978(void) { D_003E3A80--; }

// tail-call wrappers
void func_00330C88(void);
void func_003313F0(void);
void func_003313E0(void);

// FUNCTION: GAME 0x328C58
void func_00328C58(void) { func_00330C88(); }

// FUNCTION: GAME 0x329278
void func_00329278(void) { func_003313F0(); }

// FUNCTION: GAME 0x329298
void func_00329298(void) { func_003313E0(); }
