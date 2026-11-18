// COMPILER: ee-gcc2.96
// Tiny SCE wrappers in 0x31C000-0x328098.

void func_00324880(void);
void func_00324898(void);
void func_0033E6A8(void);
void func_0033E6B0(void);
void func_0033F130(int);
extern long D_003C8100;
extern int D_003EB308[];
void func_00322F80(void);
void func_00323B80(void);
void func_003241F8(void);
void func_00324C78(void);

// FUNCTION: GAME 0x322F58
void func_00322F58(void) { func_00324880(); func_00322F80(); func_00324898(); }

// FUNCTION: GAME 0x323B58
void func_00323B58(void) { func_00324880(); func_00323B80(); func_00324898(); }

// FUNCTION: GAME 0x3241D0
void func_003241D0(void) { func_00324880(); func_003241F8(); func_00324898(); }

// FUNCTION: GAME 0x324C50
void func_00324C50(void) { func_0033E6A8(); func_00324C78(); func_0033E6B0(); }

// FUNCTION: GAME 0x3248C0
void func_003248C0(int a, int b) { func_0033F130(b); }

// FUNCTION: GAME 0x3248D8
void func_003248D8(int a, int b) { func_0033F130(b); }

// FUNCTION: GAME 0x324E98
void func_00324E98(void) { D_003C8100++; }

// FUNCTION: GAME 0x324808
int func_00324808(int i) { return D_003EB308[i] + 0x10; }

// batch 2
int func_0031EE40(int, int, int);
void func_00324D88(int, int);
extern int D_003C814C, D_003C80C8;
extern int D_003C490C;
void func_00326568(char *);
void func_0033D230(int);

// FUNCTION: GAME 0x326830
void func_00326830(char *p) { func_00326568(p); p[1] = 1; }

// FUNCTION: GAME 0x326860
void func_00326860(char *p) { func_0033D230(*(int *)(p + 4)); p[1] = 0; }

// FUNCTION: GAME 0x324858
int func_00324858(int a) { int q = a / 2048; return q + (a % 2048 > 0); }

