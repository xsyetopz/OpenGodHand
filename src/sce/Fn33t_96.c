// COMPILER: ee-gcc2.96
// SCE library units 0x334000-0x340000 (small framed/leaf units), ee-gcc 2.96 -O2 -G0.

// FUNCTION: GAME 0x33CEF0
int func_0033CEF0(char *a) { int m = *(short *)(a + 0x98); if (m == 0) return 0x10; if (m == 2) { int s = *(short *)(a + 0x9C); if (s == 2) return 4; return s == 1 ? 8 : 0x10; } if (m == 1) { int s = *(short *)(a + 0x9C); return s == 2 ? 4 : 0x10; } return 0x10; }

void *memset(void *, int, unsigned);

// DRAFT: GAME 0x334090
// diff: 7 words; original loads 0x24 into $a0 and 0x1C into $v0 (we swap), and issues dsubu before sltu
#ifdef NONMATCHING
void func_00334090(char *s) { int a = *(int *)(s + 0x24); long b = *(int *)(s + 0x1C); unsigned long cur = *(unsigned long *)(s + 8); unsigned long end = (b + a) << 11; int n = end - cur; if (cur < end) memset((char *)(*(int *)(s + 0x20) + (a << 11) - n), 0, n); }
#endif

extern char D_004559B0[], D_00455920[], D_004559C0[], D_00455950[];
extern char D_00454F10[], D_00454F40[];
void func_00338A48(char *, char *);
void func_00335D40(char *);

// FUNCTION: GAME 0x338EC8
void func_00338EC8(int *a) { if (!a) { func_00338A48(D_004559B0, D_00455920); return; } if (!a[1]) { func_00338A48(D_004559C0, D_00455950); return; } a[3] = a[6]; a[4] = 0; }

// DRAFT: GAME 0x335BC8
// diff: 23 words; original copies $a1 to $v1 on entry and keeps it there; ours uses $a1 (92 vs 100 B)
#ifdef NONMATCHING
void func_00335BC8(int *a, int b) { if (!a) { func_00335D40(D_00454F10); return; } if (b < 0 || a[6] < b) { func_00335D40(D_00454F40); return; } a[5] = b; }
#endif

extern char D_00456918[], D_00456920[];
int memcmp(const void *, const void *, unsigned);
extern int (*D_007588B8)(int *);
void func_0033B658(void);
void func_0033B670(void);
void func_0033D4D8(short *, short *, int);

// FUNCTION: GAME 0x33E558
int func_0033E558(char *a) { if (memcmp(a, D_00456918, 4) == 0) { if (memcmp(a + 8, D_00456920, 4) == 0) return 1; } return 0; }

// FUNCTION: GAME 0x33BF18
int func_0033BF18(int *p) { int r; if (D_007588B8) r = D_007588B8(p); else { int o; func_0033B658(); o = *p; *p = 1; r = o != 1; func_0033B670(); } return r; }

// FUNCTION: GAME 0x33D508
void func_0033D508(short *a, int b, int c, int d) { func_0033D4D8(a, a + b, d); func_0033D4D8(a + c, a + (c + b), d); }

extern char D_00454CA8[];
void func_00335950(char *);
int func_00336510(char *);

// FUNCTION: GAME 0x3358E8
void func_003358E8(char *s) { if (!s) { func_00335D40(D_00454CA8); return; } if (s[1]) func_00335950(s); if (*(int *)(s + 0x24) > 0) { s[1] = 2; return; } s[1] = 1; }

// FUNCTION: GAME 0x3365A8
void func_003365A8(char *s) { int *w = (int *)s; w[1] = 0x800; w[2] = func_00336510(s + 0x1C); w[3] = (w[2] + w[1] - 1) / w[1]; *s = 1; w[6] = 0; w[5] = 0; s[1] = 0; w[4] = 0; }

// DRAFT: GAME 0x33D958
// diff: 4 words; $v0/$v1 swapped for the lb 0xE and lw 0xF4 temporaries (otherwise identical)
#ifdef NONMATCHING
void func_0033D958(char *s) { int m = *(int *)(s + 0x90) * s[0xE]; int n = *(int *)(s + 0x94) - *(int *)(s + 0xF4); if (n < 0) n += 0x7FFFFFFF; (*(void (**)(int, int, int))(s + 0xFC))(*(int *)(s + 0x100), n, m << 1); *(int *)(s + 0xF4) = *(int *)(s + 0x94); }
#endif
