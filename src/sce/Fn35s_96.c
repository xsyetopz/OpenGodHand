// COMPILER: ee-gcc2.96
// SCE library units in 0x350000-0x358000, built with ee-gcc 2.96 (C) at -O2 -G0.

extern int D_003EE304;
extern char D_00766C28[];

void func_00355E88(int);
void func_00355F88(int);
void func_003571F8(void);
void func_003669B0(void *, void *, int);
void func_00357678(int);
void func_00357720(int);
void func_003577A8(int);

// FUNCTION: GAME 0x3556A0
void func_003556A0(int *p) { if (p) { if (*p == 4) *p = 2; else *p = 0; } }

// FUNCTION: GAME 0x3558E8
void func_003558E8(unsigned long *d, unsigned long a, unsigned long b, unsigned long c) { *d = (a << 32) | ((b << 32) >> 4) | ((c << 32) >> 32); }

// FUNCTION: GAME 0x356790
int func_00356790(int a, int b, char *c) { func_00355E88(*(int *)(c + 0x1FC0) + 0x1198); return 1; }

// FUNCTION: GAME 0x3567B8
int func_003567B8(int a, int b, char *c) { func_00355F88(*(int *)(c + 0x1FC0) + 0x1198); return 1; }

// FUNCTION: GAME 0x356868
void func_00356868(char *a) { func_003669B0(D_00766C28, (void *)(*(int *)(a + 0x1FC0) + 0x1150), 0x48); }

// FUNCTION: GAME 0x356890
void func_00356890(char *a) { func_003669B0((void *)(*(int *)(a + 0x1FC0) + 0x1150), D_00766C28, 0x48); }

// FUNCTION: GAME 0x3571D0
void func_003571D0(void) { func_003571F8(); D_003EE304 = 0; }

// FUNCTION: GAME 0x357648
void func_00357648(int a) { func_00357678(a); func_00357720(a); func_003577A8(a); }
