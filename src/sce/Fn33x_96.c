// COMPILER: ee-gcc2.96
// SCE library units 0x331570-0x33C458 (framed, 0x60-0x6C bytes), ee-gcc 2.96 -O2 -G0.

extern char D_003D84C0[];
extern char D_003DA5F8[];
extern char D_00454130[];
extern char D_00453EB0[];
extern char D_00453ED0[];
extern void (*D_003E9D28)(int);

int scePrintf(const char *, ...);
int sceOpen(int, int);
void func_003389F8(void);
void func_00338A10(void);
void func_0033B658(void);
void func_0033B670(void);
void func_0033B688(void);
void func_0033B6B8(void);
void func_00332398(void *);
void func_00336218(void *);
void func_00331D40(void);
void func_00331D78(void);
int func_00339360(int, int, int, int);
int func_00339F00(int, int, int, int);
int func_0033ABD0(int, int, int, int);
int func_0033B878(int, int, int, int);
int func_0033BA80(int, int, int, int, int);

// FUNCTION: GAME 0x331570
void func_00331570(int *s) { func_0033B688(); if (!s) scePrintf(D_00453EB0); else if (s[1] == 1) scePrintf(D_00453ED0); else s[1] = 1; func_0033B6B8(); }

// FUNCTION: GAME 0x331EE8
int func_00331EE8(int a, int b) { int r; func_00331D40(); r = sceOpen(a, b); if (r < 0) scePrintf(D_00454130, r); func_00331D78(); return r; }

// FUNCTION: GAME 0x332778
void func_00332778(void) { char *p; int i; func_003389F8(); p = D_003D84C0; for (i = 15; i >= 0; i--, p += 0x44) if (*p == 1) func_00332398(p); func_00338A10(); }

// FUNCTION: GAME 0x3392F8
int func_003392F8(int a, int b, int c, int d) { int r; func_003389F8(); r = func_00339360(a, b, c, d); func_00338A10(); return r; }

// FUNCTION: GAME 0x335A40
void func_00335A40(void) { char *p = D_003DA5F8; int i; for (i = 0x1F; i >= 0; i--, p += 0x238) if (*p == 1) func_00336218(p); }

// FUNCTION: GAME 0x339E98
int func_00339E98(int a, int b, int c, int d) { int r; func_003389F8(); r = func_00339F00(a, b, c, d); func_00338A10(); return r; }

// FUNCTION: GAME 0x33AB68
int func_0033AB68(int a, int b, int c, int d) { int r; func_003389F8(); r = func_0033ABD0(a, b, c, d); func_00338A10(); return r; }

// FUNCTION: GAME 0x33B810
int func_0033B810(int a, int b, int c, int d) { int r; func_0033B658(); r = func_0033B878(a, b, c, d); func_0033B670(); return r; }

// FUNCTION: GAME 0x33BA10
void func_0033BA10(int a, int b, int c, int d, int e) { func_0033B658(); func_0033BA80(a, b, c, d, e); func_0033B670(); }

// FUNCTION: GAME 0x33C458
void func_0033C458(int *s, int b) { if (s[0xB4 / 4]) D_003E9D28(s[0xB4 / 4]); s[0xB8 / 4] = b; s[0xBC / 4] = b / 0x60; }
