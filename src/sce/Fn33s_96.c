// COMPILER: ee-gcc2.96
// SCE library units, small framed functions (0x60-0xC0 bytes), ee-gcc 2.96 -O2 -G0.

extern char D_003EAEC8[];

void func_0033E678(void);
void func_0033E690(void);
void func_00324108(char *);
void func_00323AA0(char *);

// FUNCTION: GAME 0x3241F8
void func_003241F8(void) { char *p; int i; func_0033E678(); p = D_003EAEC8; for (i = 15; i >= 0; i--, p += 0x44) if (*p == 1) func_00324108(p); func_0033E690(); }

// FUNCTION: GAME 0x323B80
void func_00323B80(void) { char *p = D_003EAEC8; int i; for (i = 15; i >= 0; i--, p += 0x44) if (*p == 1) func_00323AA0(p); }

extern char D_003DA5F8[];
int strlen(const char *);

// FUNCTION: GAME 0x335360
char *func_00335360(void) { char *r = 0; int i; for (i = 0; i < 0x20; i++) { char *p = D_003DA5F8 + i * 0x238; if (*p == 0) { r = p; break; } } return r; }

// DRAFT: GAME 0x330518
// diff: 4 words; original keeps strlen+1 in $v0 then copies to $a3 (we use $a3 directly, loop head addu/nop order differs)
#ifdef NONMATCHING
void func_00330518(char *s) { unsigned n = strlen(s) + 1; unsigned i; for (i = 0; i < n; i++) { int c = (unsigned char)s[i]; if ((unsigned)(c - 0x61) < 0x1A) s[i] = c - 0x20; } }
#endif

extern char D_00455990[], D_00455920[], D_004559A0[], D_00455950[];
extern char D_00455C48[], D_00455BD8[], D_00455C58[], D_00455C08[];
void func_00338A48(char *, char *);
void func_0033A048(char *, char *);

// FUNCTION: GAME 0x338E38
void func_00338E38(int *a, int b, int c) { if (!a) { func_00338A48(D_00455990, D_00455920); return; } if (!a[1]) { func_00338A48(D_004559A0, D_00455950); return; } a[7] = b; a[8] = c; }

// FUNCTION: GAME 0x33A468
void func_0033A468(char *a, int b, int c) { if (!a) { func_0033A048(D_00455C48, D_00455BD8); return; } if (!a[4]) { func_0033A048(D_00455C58, D_00455C08); return; } *(int *)(a + 0x28) = b; *(int *)(a + 0x2C) = c; }

struct Hook { void (*fn)(int); int arg; };
extern struct Hook D_007588A0;
extern int D_003E9948, D_003E994C;

// DRAFT: GAME 0x33B568
// diff: 14 words; original reloads D_003E9948 after the D_003E994C store and loads both addresses up front; ours folds the increment (88 B)
#ifdef NONMATCHING
void func_0033B568(int a) { if (D_007588A0.fn) { D_007588A0.fn(D_007588A0.arg); if (D_003E9948 == 0) D_003E994C = a; D_003E9948++; } }
#endif
