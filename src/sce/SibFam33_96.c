// COMPILER: ee-gcc2.96
// Wrappers sharing the 0x3403F8 skeleton: f1(a); f2(a, b); tail f3() (ee-gcc 2.96, -O2 -G0).

void func_00328488(char *, int);
void func_00328E18(char *, int);
void func_00328E78(char *, int);
void func_00329070(char *);
void func_00329088(void);
void func_00329D78(char *, int);
void func_0032A900(char *, int);
void func_0032AA30(char *, int);
void func_0032ABB0(char *, int);
void func_0032AF80(char *, int);
void func_0032B1C8(char *, int);
void func_0032B340(char *, int);
void func_0032B658(char *, int);
void func_0032B6A0(char *, int);
void func_0032BD90(char *, int);
void func_0032DEC8(char *, int);
void func_0032DF38(char *, int);
void func_003355C0(char *, int);
void func_00335BC8(char *, int);
void func_00335CA8(char *, int);
void func_00335CD8(char *);
void func_00335CE0(void);
void func_0033B658(char *);
void func_0033B670(void);
void func_0033B978(char *, int);
void func_0033E6A8(char *);
void func_0033E6B0(void);
void func_0033FCA0(char *);
void func_0033FCA8(void);

// FUNCTION: GAME 0x328448
void func_00328448(char *a, int b) { func_00329070(a); func_00328488(a, b); func_00329088(); }

// FUNCTION: GAME 0x328DD8
void func_00328DD8(char *a, int b) { func_00329070(a); func_00328E18(a, b); func_00329088(); }

// FUNCTION: GAME 0x328E38
void func_00328E38(char *a, int b) { func_00329070(a); func_00328E78(a, b); func_00329088(); }

// FUNCTION: GAME 0x329D38
void func_00329D38(char *a, int b) { func_0033E6A8(a); func_00329D78(a, b); func_0033E6B0(); }

// FUNCTION: GAME 0x32A8C0
void func_0032A8C0(char *a, int b) { func_0033E6A8(a); func_0032A900(a, b); func_0033E6B0(); }

// FUNCTION: GAME 0x32A9F0
void func_0032A9F0(char *a, int b) { func_0033E6A8(a); func_0032AA30(a, b); func_0033E6B0(); }

// FUNCTION: GAME 0x32AB70
void func_0032AB70(char *a, int b) { func_0033E6A8(a); func_0032ABB0(a, b); func_0033E6B0(); }

// FUNCTION: GAME 0x32AF40
void func_0032AF40(char *a, int b) { func_0033E6A8(a); func_0032AF80(a, b); func_0033E6B0(); }

// FUNCTION: GAME 0x32B188
void func_0032B188(char *a, int b) { func_0033E6A8(a); func_0032B1C8(a, b); func_0033E6B0(); }

// FUNCTION: GAME 0x32B300
void func_0032B300(char *a, int b) { func_0033E6A8(a); func_0032B340(a, b); func_0033E6B0(); }

// FUNCTION: GAME 0x32B618
void func_0032B618(char *a, int b) { func_0033E6A8(a); func_0032B658(a, b); func_0033E6B0(); }

// FUNCTION: GAME 0x32B660
void func_0032B660(char *a, int b) { func_0033E6A8(a); func_0032B6A0(a, b); func_0033E6B0(); }

// FUNCTION: GAME 0x32BD50
void func_0032BD50(char *a, int b) { func_0033E6A8(a); func_0032BD90(a, b); func_0033E6B0(); }

// FUNCTION: GAME 0x32DE88
void func_0032DE88(char *a, int b) { func_0033FCA0(a); func_0032DEC8(a, b); func_0033FCA8(); }

// FUNCTION: GAME 0x32DEF8
void func_0032DEF8(char *a, int b) { func_0033FCA0(a); func_0032DF38(a, b); func_0033FCA8(); }

// FUNCTION: GAME 0x335580
void func_00335580(char *a, int b) { func_00335CD8(a); func_003355C0(a, b); func_00335CE0(); }

// FUNCTION: GAME 0x335B88
void func_00335B88(char *a, int b) { func_00335CD8(a); func_00335BC8(a, b); func_00335CE0(); }

// FUNCTION: GAME 0x335C68
void func_00335C68(char *a, int b) { func_00335CD8(a); func_00335CA8(a, b); func_00335CE0(); }

// FUNCTION: GAME 0x33B938
void func_0033B938(char *a, int b) { func_0033B658(a); func_0033B978(a, b); func_0033B670(); }

// Second and third skeletons: lock / four-argument call / unlock, and guarded callback.
struct SibFP { void (*fn)(int); int arg; };
extern struct SibFP D_00755C20, D_00755C28, D_007588C8;
void func_00324880(void);
void func_00324898(void);
int func_00322A38(int, int, int, int);
int func_00322AD0(int, int, int, int);
int func_00322B60(int, int, int, int);

// FUNCTION: GAME 0x3229D0
int func_003229D0(int a, int b, int c, int d) { int r; func_00324880(); r = func_00322A38(a, b, c, d); func_00324898(); return r; }

// FUNCTION: GAME 0x322A68
int func_00322A68(int a, int b, int c, int d) { int r; func_00324880(); r = func_00322AD0(a, b, c, d); func_00324898(); return r; }

// FUNCTION: GAME 0x322AF8
int func_00322AF8(int a, int b, int c, int d) { int r; func_00324880(); r = func_00322B60(a, b, c, d); func_00324898(); return r; }

// FUNCTION: GAME 0x325FA8
void func_00325FA8(void) { if (D_00755C20.fn) D_00755C20.fn(D_00755C20.arg); }

// FUNCTION: GAME 0x325FD8
void func_00325FD8(void) { if (D_00755C28.fn) D_00755C28.fn(D_00755C28.arg); }

// FUNCTION: GAME 0x33BFE8
void func_0033BFE8(void) { if (D_007588C8.fn) D_007588C8.fn(D_007588C8.arg); }

// Fourth skeleton group: guarded indirect callbacks on a pointer field, tail wrappers, global getters.
extern void (*D_003E9D1C)(int);
extern void (*D_003E9D24)(int);
extern void (*D_003E9D2C)(int);
void func_003282D0(int);
void func_00327FA8(int);
void func_00357490(int);
void func_00359800(int);
int *func_00320360(void);
int *func_00360D18(void);

// FUNCTION: GAME 0x33C290
void func_0033C290(int *a) { int p = a[0xC0 / 4]; if (p) D_003E9D1C(p); }

// FUNCTION: GAME 0x33C428
void func_0033C428(int *a) { int p = a[0xB4 / 4]; if (p) D_003E9D24(p); }

// FUNCTION: GAME 0x33C4E8
void func_0033C4E8(int *a) { int p = a[0xB4 / 4]; if (p) D_003E9D2C(p); }

// FUNCTION: GAME 0x349B60
void func_00349B60(int a) { func_003282D0(a); func_00327FA8(a); }

// FUNCTION: GAME 0x357468
void func_00357468(int a) { func_00357490(a); func_00359800(a); }

// FUNCTION: GAME 0x321268
int func_00321268(void) { return *func_00320360(); }

// FUNCTION: GAME 0x360D50
int func_00360D50(void) { return *func_00360D18(); }
