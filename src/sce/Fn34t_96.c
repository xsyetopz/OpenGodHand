// COMPILER: ee-gcc2.96
// CRI middleware (SFD) small units 0x348000-0x350000, ee-gcc 2.96 -O2 -G0.

struct E { int a; int b; };
extern struct E D_003EE088[];

void func_0033BEC0();
void func_003466C0();
void func_003466D8();
void func_0033BF18();
void func_00349308();
void func_00349480();

// FUNCTION: GAME 0x348920
struct E *func_00348920(int i) { return &D_003EE088[i]; }

// DRAFT: GAME 0x348938
// diff: 3 words; original folds %lo(D_003EE088) into the lw offset, ours emits a separate addiu (24 vs 20 B)
#ifdef NONMATCHING
int func_00348938(int i) { return *(int *)((char *)D_003EE088 + (i << 3)); }
#endif

// DRAFT: GAME 0x348950
// diff: 3 words; same %lo folding miss as 0x348938
#ifdef NONMATCHING
void func_00348950(int v, int i) { *(int *)((char *)D_003EE088 + (i << 3)) = v; }
#endif

// FUNCTION: GAME 0x3489F0
void func_003489F0(void) { func_0033BEC0(); }

// FUNCTION: GAME 0x348B78
void func_00348B78(void) { func_003466C0(); }

// FUNCTION: GAME 0x348B90
void func_00348B90(void) { func_003466D8(); }

// FUNCTION: GAME 0x348BC8
void func_00348BC8(void) { func_0033BF18(); }

// FUNCTION: GAME 0x349238
void func_00349238(void) { func_00349308(); }

// FUNCTION: GAME 0x349468
void func_00349468(void) { func_00349480(); }
