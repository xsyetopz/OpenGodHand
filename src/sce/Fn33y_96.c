// COMPILER: ee-gcc2.96
// SCE library units in 0x328098-0x33FFFF built by SCE ee-gcc 2.96, -O2 -G0.

extern int D_003D848C, D_003D8488;
void func_0033E678(void);
void func_0033E690(void);
void func_0033BF18(void);
void func_0033E6A8(void);
void func_0033E6B0(void);

// FUNCTION: GAME 0x329028
void func_00329028(void) { func_0033E678(); }

// FUNCTION: GAME 0x329040
void func_00329040(void) { func_0033E690(); }

// FUNCTION: GAME 0x329058
void func_00329058(void) { func_0033BF18(); }

// FUNCTION: GAME 0x329070
void func_00329070(void) { func_0033E6A8(); }

// FUNCTION: GAME 0x329088
void func_00329088(void) { func_0033E6B0(); }

#ifdef NONMATCHING
// DRAFT: GAME 0x3313E0
// 3 words differ: original materialises the address (lui/addiu) and loads through it; compiler folds %lo into the lw (same under 2.96)
int func_003313E0(void) { return D_003D848C; }

// DRAFT: GAME 0x3313F0
// 3 words differ: same address-folding difference as 0x3313E0
void func_003313F0(int v) { D_003D8488 = v; }
#endif
