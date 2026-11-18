// COMPILER: ee-gcc2.96
// Tiny SCE accessors (<= 0x20 bytes).

extern int D_003EC7E0;
extern int D_003EE078;
extern int D_003EE2C0;
extern int D_003EE2F4;
extern int D_003EE2BC;
extern int D_00459BF0;

// FUNCTION: GAME 0x3452B0
int *func_003452B0(void) { return &D_003EC7E0; }

// FUNCTION: GAME 0x345D10
void func_00345D10(int *p) { p[0x7C/4] = 0; p[0x80/4] = 0; }

// FUNCTION: GAME 0x3463F8
int func_003463F8(void) { return D_003EE078; }

// FUNCTION: GAME 0x346FA0
void func_00346FA0(int *a, int *b) { b[0x4C/4] = a[0x34/4]; }

// FUNCTION: GAME 0x34AFE0
int func_0034AFE0(void) { return D_003EE2C0; }

// FUNCTION: GAME 0x34C1F8
void func_0034C1F8(int *p) { p[0] = 0; p[1] = 0; }

// FUNCTION: GAME 0x34DB50
int func_0034DB50(int a, int b) { return b == 0x37B0; }

// FUNCTION: GAME 0x34DEB8
void func_0034DEB8(int *p, int a, int b) { p[0] = a; p[1] = b; }

// FUNCTION: GAME 0x350138
int func_00350138(char *a) { return *(int *)(*(char **)(a + 0x1F7C) + 0x20); }

// FUNCTION: GAME 0x3554E8
int func_003554E8(char *a) { return *(int *)(*(char **)(a + 0x1FC0) + 0x7C); }

// FUNCTION: GAME 0x356348
void func_00356348(int a) { D_003EE2F4 = a; }

// FUNCTION: GAME 0x3565D0
int func_003565D0(char *a) { return *(int *)(*(char **)(a + 0x1FC0) + 0x11FC); }

// FUNCTION: GAME 0x356C58
int func_00356C58(char *a) { return *(int *)(*(char **)(a + 0x1FC0) + 0x1158); }

// FUNCTION: GAME 0x358A28
void func_00358A28(int a) { D_003EE2BC = a; }

// FUNCTION: GAME 0x358A38
int func_00358A38(void) { return D_003EE2BC; }

// FUNCTION: GAME 0x35AA40
void func_0035AA40(int *p, int a, int b) { p[0x144/4] = a; p[0x148/4] = b; }

// FUNCTION: GAME 0x35D520
int *func_0035D520(void) { return &D_00459BF0; }

// FUNCTION: GAME 0x35D7A8
int func_0035D7A8(int *a) { return *a == 0; }

// FUNCTION: GAME 0x35EF40
void func_0035EF40(char *a, int v) { *(int *)(*(char **)(a + 0x30) + 0x18) = v; }

// FUNCTION: GAME 0x35EF50
void func_0035EF50(char *a, int v) { *(int *)(*(char **)(a + 0x30) + 0x20) = v; }
