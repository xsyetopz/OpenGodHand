// COMPILER: ee-gcc2.96
extern int D_003EE34C;
extern char D_00459FA8[];
// FUNCTION: GAME 0x0035EF60
void func_0035EF60(char *p, int a) { *(int *)(*(char **)(p + 0x30) + 0x1C) = a; }
// FUNCTION: GAME 0x0035F8A8
char *func_0035F8A8(void) { return D_00459FA8; }
// FUNCTION: GAME 0x0035FC18
void func_0035FC18(int a) { D_003EE34C = a; }
// FUNCTION: GAME 0x0035FC28
int func_0035FC28(void) { return D_003EE34C; }
// FUNCTION: GAME 0x0035FC60
void func_0035FC60(int *p, int a, int b) { p[2] = a; p[3] = b; }
