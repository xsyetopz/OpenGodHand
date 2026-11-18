// COMPILER: ee-gcc2.96
// SCE library tail-call thunks (framed sd ra/ld ra then j); ee-gcc 2.9 emits a bare j, 3.2 and 2.96 match.

void func_00332778(void);
void func_00334310(void);
void func_0033B658(void);
void func_0033B670(void);
void func_003A9228(void);

// FUNCTION: GAME 0x334B20
void func_00334B20(void) { func_00334310(); }

// FUNCTION: GAME 0x335CE8
void func_00335CE8(void) { func_0033B658(); }

// FUNCTION: GAME 0x335D00
void func_00335D00(void) { func_0033B670(); }

// FUNCTION: GAME 0x3362E8
void func_003362E8(void) { func_0033B658(); }

// FUNCTION: GAME 0x336300
void func_00336300(void) { func_0033B670(); }

// FUNCTION: GAME 0x336360
void func_00336360(void) { func_003A9228(); }

// FUNCTION: GAME 0x3389F8
void func_003389F8(void) { func_0033B658(); }

// FUNCTION: GAME 0x338A10
void func_00338A10(void) { func_0033B670(); }

// FUNCTION: GAME 0x33B200
void func_0033B200(void) { func_00332778(); }

// FUNCTION: GAME 0x33E678
void func_0033E678(void) { func_0033B658(); }

// FUNCTION: GAME 0x33E690
void func_0033E690(void) { func_0033B670(); }

// FUNCTION: GAME 0x33FC70
void func_0033FC70(void) { func_0033B658(); }
