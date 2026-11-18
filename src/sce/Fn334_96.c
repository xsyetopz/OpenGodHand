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

// Framed non-thunk units, 0x328098-0x33C240 (ee-gcc 2.96 matches; 2.9 misses all but 0x334BA8)
void func_00329070(void);
void func_00329088(void);
void func_0033E6A8(void);
void func_0033E6B0(void);
int func_003280D0(int);
int func_00328200(int);
int func_00329FD0(int);
int func_0032A4E0(int);
int func_0032D0F8(int);
long func_00334B20_l(void) __asm__("func_00334B20");
int func_0033AD08(int);
void func_00327720(int);
struct FP { void (*fn)(int); int arg; };
extern struct FP D_007588C0;
extern void (*D_003E9D18)(int);

// FUNCTION: GAME 0x328098
int func_00328098(int a) { int r; func_00329070(); r = func_003280D0(a); func_00329088(); return r; }

// FUNCTION: GAME 0x3281C8
int func_003281C8(int a) { int r; func_00329070(); r = func_00328200(a); func_00329088(); return r; }

// FUNCTION: GAME 0x329F98
int func_00329F98(int a) { int r; func_0033E6A8(); r = func_00329FD0(a); func_0033E6B0(); return r; }

// FUNCTION: GAME 0x32A4A8
int func_0032A4A8(int a) { int r; func_0033E6A8(); r = func_0032A4E0(a); func_0033E6B0(); return r; }

// FUNCTION: GAME 0x32B6A0
void func_0032B6A0(char *a, char c) { a[0x98] = c; if (*(int *)(a + 4)) func_00327720(*(int *)(a + 4)); }

// FUNCTION: GAME 0x32D0C0
int func_0032D0C0(int a) { int r; func_0033E6A8(); r = func_0032D0F8(a); func_0033E6B0(); return r; }

// FUNCTION: GAME 0x33ADC0
void func_0033ADC0(int a, int *b) { b[0] = a + 0x10; b[1] = func_0033AD08(a + 8); }

// FUNCTION: GAME 0x33BFB8
void func_0033BFB8(void) { if (D_007588C0.fn) D_007588C0.fn(D_007588C0.arg); }

// FUNCTION: GAME 0x33C240
void func_0033C240(int *a) { int p = a[0xC0 / 4]; if (p) D_003E9D18(p); }

// FUNCTION: GAME 0x334BA8
int func_00334BA8(void) { return (int)(func_00334B20_l() & 0xFFFFFFFFUL); }
