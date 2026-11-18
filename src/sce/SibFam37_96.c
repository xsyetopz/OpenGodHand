// COMPILER: ee-gcc2.96
// Five-argument lock/call/unlock wrappers (0x33BA10 skeleton with the 0x328098 lock pair).

void func_00329070(void);
void func_00329088(void);
void func_00327E88(int, int, int, int, int);
void func_00327F70(int, int, int, int, int);

// FUNCTION: GAME 0x327E18
void func_00327E18(int a, int b, int c, int d, int e) { func_00329070(); func_00327E88(a, b, c, d, e); func_00329088(); }

// FUNCTION: GAME 0x327F00
void func_00327F00(int a, int b, int c, int d, int e) { func_00329070(); func_00327F70(a, b, c, d, e); func_00329088(); }
