// COMPILER: ee-gcc2.9-991111
// SCE library units in 0x328000-0x333FFF built by SCE ee-gcc 2.9x, -O2 -G0.

extern char D_00756080[];
extern int D_003D848C, D_003D8488;
void func_0033E678(void);
void func_0033E690(void);
void func_0033BF18(void);
void func_0033E6A8(void);

typedef struct S28 { char _pad[0x28]; int a; int b; } S28;
typedef struct Slot16 { char _pad[0xB0]; char c; char _p1[3]; int v; char _p2[8]; } Slot16;

// FUNCTION: GAME 0x3306C8
char *func_003306C8(void) { return D_00756080; }

// FUNCTION: GAME 0x332388
void func_00332388(S28 *p, int a, int b) { p->a = a; p->b = b; }

// FUNCTION: GAME 0x3313E0
int func_003313E0(void) { return D_003D848C; }

// FUNCTION: GAME 0x3313F0
void func_003313F0(int v) { D_003D8488 = v; }

// FUNCTION: GAME 0x32F4D0
int func_0032F4D0(Slot16 *p, int i) { return p[i].v; }

// FUNCTION: GAME 0x32F4E0
int func_0032F4E0(Slot16 *p, int i) { return p[i].c; }

// FUNCTION: GAME 0x329028
void func_00329028(void) { func_0033E678(); }

// FUNCTION: GAME 0x329040
void func_00329040(void) { func_0033E690(); }

// FUNCTION: GAME 0x329058
void func_00329058(void) { func_0033BF18(); }

// FUNCTION: GAME 0x329070
void func_00329070(void) { func_0033E6A8(); }
