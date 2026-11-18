// COMPILER: ee-gcc2.96
// CRI middleware (SFD) small units 0x350000-0x358000, ee-gcc 2.96 -O2 -G0.

void func_0034C390(char *, int, int);
void func_0035C2D0(int, int, int, int, int);
void func_0036A070(int);

// DRAFT: GAME 0x3545D8
// diff: 5 words; original calls with jal (lw a1 in the delay slot) and returns normally, ours folds to a tail j
#ifdef NONMATCHING
void func_003545D8(char *a, int b) { func_0034C390(a, *(int *)(a + 0x1FC8), b); }
#endif

// FUNCTION: GAME 0x350B38
void func_00350B38(char *a) { a += 0xE48; if (*(int *)(a + 0x24) != 0x7FFFFFFF) *(int *)a = 1; }

// DRAFT: GAME 0x357258
// diff: 7 words; original keeps the 1 in the beqz delay slot ($v0), ours uses $v1 plus a move
#ifdef NONMATCHING
int func_00357258(int *a) { int r = 1; if ((unsigned)(a[0x12] - 1) < 4) r = a[0x11] == 0; return r; }
#endif

// FUNCTION: GAME 0x3520B0
void func_003520B0(int *a) { int *b; a[2] = 0; a[0] = 0; a[1] = 0; b = a + 4; *(long *)b = -1; b[3] = -1; b[2] = 0; }

// DRAFT: GAME 0x3570D0
// diff: 8 words; original uses jal with li a1,7 in the delay slot, ours folds to a tail j
#ifdef NONMATCHING
void func_003570D0(int a, int b) { func_0035C2D0(a, 7, 8, b, 0); }
#endif

// FUNCTION: GAME 0x355670
void func_00355670(int *a) { if (a) { if (*a == 4) *a = 3; else *a = 0; a[0x58 / 4] = -1; } }

// DRAFT: GAME 0x354D80
// diff: 6 words; original loads *p straight into $a0, ours goes through $v1 and a move
#ifdef NONMATCHING
int func_00354D80(char *a) { int v = **(int **)(a + 0x1FC0); if (v) func_0036A070(v); return 0; }
#endif

// DRAFT: GAME 0x353060
// diff: 6 words; load/store interleave differs (original loads s[0] and s[4] first)
#ifdef NONMATCHING
void func_00353060(int *d, int a, int *s, int b) { int t = s[4]; d[0] = s[0]; d[1] = s[1]; d[2] = s[2]; d[8] = b; d[3] = s[3]; d[5] = t; d[4] = a; }
#endif

// FUNCTION: GAME 0x355450
char *func_00355450(char *a, int b) { char *p = *(char **)(a + 0x1FC0) + 0x180; int i; for (i = 0; i < 16; i++, p += 0xF0) if (*(int *)(p + 0x58) == b) return p; return 0; }

// DRAFT: GAME 0x3574A8
// diff: 11 words; original tests v<2 then v<5 as separate branches, ours merges
#ifdef NONMATCHING
int func_003574A8(int *a) { int v = a[0x13]; int w = a[0x12]; switch (v) { case 0: case 1: case 2: case 3: case 4: case 6: w = 2; } return w; }
#endif

// DRAFT: GAME 0x3553C8
// diff: 11 words; register allocation ($v1/$a1) and branch layout differ
#ifdef NONMATCHING
int func_003553C8(char *a) { int p = *(int *)(a + 0x36B0); char *b; int r = 0; b = *(char **)(a + 0x1FC0); if (p) { int x = *(int *)(b + 0x88); r = 0; if (!(x > 0)) r = p + 0xAD0; } return r; }
#endif

extern void func_0034C8F0(char *, int, int);

// FUNCTION: GAME 0x351B70
void func_00351B70(char *a, int b) { func_0034C8F0(a, *(int *)(a + 0x1FC8), b); *(long *)(a + 0x9A8) += b; }
