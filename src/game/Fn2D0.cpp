// Small accessors in 0x2D0000-0x2D7FFF.

extern "C" {

// FUNCTION: GAME 0x002D0350
void func_002D0350(int *a, int b) { a[1] |= b; }

// FUNCTION: GAME 0x002D03D0
int func_002D03D0(int *a, int b) { return (~a[1] & b) == 0; }

// FUNCTION: GAME 0x002D2DB0
char *func_002D2DB0(char *a, int b) { return *(char **)(a + 0x38) + b * 0xDC; }

}
