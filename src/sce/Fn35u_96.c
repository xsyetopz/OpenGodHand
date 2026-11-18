// COMPILER: ee-gcc2.96
// FLAGS: -fno-optimize-sibling-calls
// CRI middleware (SFD) wrappers that keep jal + frame around the final call.

void func_0034C390(char *, int, int);
void func_0035C2D0(int, int, int, int, int);

// FUNCTION: GAME 0x3545D8
void func_003545D8(char *a, int b) { func_0034C390(a, *(int *)(a + 0x1FC8), b); }

// FUNCTION: GAME 0x3570D0
void func_003570D0(int a, int b) { func_0035C2D0(a, 7, 8, b, 0); }
