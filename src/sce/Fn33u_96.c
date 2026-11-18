// COMPILER: ee-gcc2.96
void *memset(void *, int, unsigned);
void func_0033B568(int); void func_0033B5C8(int); void func_0033BC48(int);
void func_0033E6B8(int, int, char *, char *); void func_003406D0(int);
// FUNCTION: GAME 0x33B658
void func_0033B658(void) { func_0033B568(1); }
// FUNCTION: GAME 0x33BD18
void func_0033BD18(void) { func_0033BC48(0); }
// FUNCTION: GAME 0x33F9B0
void func_0033F9B0(char *a, unsigned short *b, unsigned short *c) { *(unsigned short *)(a + 0x28) = b[0]; *(unsigned short *)(a + 0x2A) = c[0]; *(unsigned short *)(a + 0x2C) = b[1]; *(unsigned short *)(a + 0x2E) = c[1]; }
// FUNCTION: GAME 0x33F988
void func_0033F988(char *a, int b, int c) { func_0033E6B8(c, b, a + 0x30, a + 0x32); }
// FUNCTION: GAME 0x33FB20
void func_0033FB20(int *a) { a[3] = 0; memset(a + 10, 0, 8); }
// FUNCTION: GAME 0x336E20
void func_00336E20(char *a) { func_003406D0(*(int *)(a + 0xE8)); }
// FUNCTION: GAME 0x33A010
int func_0033A010(int *a, int b, int c) { return a[10 + b * 2 + c]; }
// FUNCTION: GAME 0x33CF70
int func_0033CF70(int *a) { return a ? a[11] : 0; }
