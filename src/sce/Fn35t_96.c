// COMPILER: ee-gcc2.96
// CRI middleware (SFD) small units 0x350000-0x358000, ee-gcc 2.96 -O2 -G0.

void func_0034C390(char *, int, int);
void func_0035C2D0(int, int, int, int, int);
void func_0036A070(int);

// FUNCTION: GAME 0x3545D8
void func_003545D8(char *a, int b) { func_0034C390(a, *(int *)(a + 0x1FC8), b); }

// FUNCTION: GAME 0x350B38
void func_00350B38(char *a) { a += 0xE48; if (*(int *)(a + 0x24) != 0x7FFFFFFF) *(int *)a = 1; }

// FUNCTION: GAME 0x357258
int func_00357258(int *a) { int r = 1; if ((unsigned)(a[0x12] - 1) < 4) r = a[0x11] == 0; return r; }

// FUNCTION: GAME 0x3520B0
void func_003520B0(int *a) { int *b; a[2] = 0; a[0] = 0; a[1] = 0; b = a + 4; *(long *)b = -1; b[3] = -1; b[2] = 0; }

// FUNCTION: GAME 0x3570D0
void func_003570D0(int a, int b) { func_0035C2D0(a, 7, 8, b, 0); }

// FUNCTION: GAME 0x355670
void func_00355670(int *a) { if (a) { if (*a == 4) *a = 3; else *a = 0; a[0x58 / 4] = -1; } }

// FUNCTION: GAME 0x354D80
int func_00354D80(char *a) { int v = **(int **)(a + 0x1FC0); if (v) func_0036A070(v); return 0; }
