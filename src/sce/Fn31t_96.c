// COMPILER: ee-gcc2.96
// SCE library units in 0x31C000-0x328098, built with ee-gcc 2.96 (C) at -O2 -G0.

extern int D_003CF9E0;
extern char D_004519F0[];
struct O { int *(**vt)(void); };

void func_0033C428(int);
void func_0033C240(int, int);
void func_0033C458(int);
void func_0033C270(int, int);
void func_0033C4E8(int);
void func_0033C290(int);
void func_00335348(void);
void func_003331C0(int);
void func_0033BFB8(void);
void func_00325DF0(void);
void func_00325FA8(void);
void func_00325EF8(void);
void func_0033BFE8(void);
void func_0033F130(char *);
int **func_00320360(void);
float func_0030F518(void);

// FUNCTION: GAME 0x31D020
float fRand1_1__Fv(void) { float f = func_0030F518(); return (f - 0.5f) * 2.0f; }

// FUNCTION: GAME 0x3217F0
int func_003217F0(struct O *o) { return *o->vt[1](); }

#ifdef NONMATCHING
// DRAFT: GAME 0x321288
// 7 words differ: register allocation (original keeps r in v1, count in a0, flag in a1)
long *func_00321288(void)
{
    long *r = (long *)*func_00320360();
    *(int *)((char *)r + 0x14) = 1;
    r[4]++;
    return r;
}
#endif

// FUNCTION: GAME 0x324500
int adxf_GetStat(char *a) { if (a == 0) { func_0033F130(D_004519F0); return -3; } return a[1]; }

// FUNCTION: GAME 0x325F20
void func_00325F20(void) { func_0033BFB8(); func_00325DF0(); func_00325FA8(); func_00325EF8(); func_0033BFE8(); }

// FUNCTION: GAME 0x326020
void func_00326020(int a) { D_003CF9E0 = a; func_00335348(); func_003331C0(a); }

// FUNCTION: GAME 0x326780
void func_00326780(int *p, int v) { p[2] = v; func_0033C428(p[1]); func_0033C240(p[1], v); }

// FUNCTION: GAME 0x3267C0
void func_003267C0(int *p, int v) { p[14] = v; func_0033C458(p[1]); func_0033C270(p[1], v); }

// FUNCTION: GAME 0x326800
void func_00326800(int *p) { func_0033C4E8(p[1]); func_0033C290(p[1]); }
