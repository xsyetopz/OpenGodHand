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

// Round 24: 0x60-0x80 byte framed units
void func_00329028(void);
void func_00329040(void);
void func_003298F0(void *);
void func_0032E720(void *);
void func_0033FCA0(void);
void func_0033FCA8(void);
int func_0032D3A8(int, int, int, int);
void func_00329EA8(int);
void func_003298C0(int);
int func_0032F4C8(int);
void func_0032B660(int, int);
int func_00328F30(int);
int func_003277A0(int);
void func_0032A6D0(void *, int, int);
unsigned strlen(const char *);
extern char D_003C7420[];
extern char D_003D1488[];
struct V { int (**vt)(struct V *, int); };

// FUNCTION: GAME 0x328300
void func_00328300(int *s) {
    func_00329028();
    if ((s[0] & 0xFFFF00) == 0x10200) {
        ((char *)s)[0x48] = 1;
        if (((char *)s)[0x47] == 1) ((char *)s)[0x47] = 0;
    } else ((char *)s)[1] = 1;
    func_00329040();
}

// FUNCTION: GAME 0x328E78
void func_00328E78(int *a, struct V *b) {
    int x, y;
    a[1] = (int)b;
    func_00329028();
    x = b->vt[9](b, 0);
    y = b->vt[9](b, 1);
    a[0x10] = x + y;
    func_00329040();
    a[7] = a[6] = a[0x10];
}

// FUNCTION: GAME 0x329AF0
void func_00329AF0(void) { char *p = D_003C7420; int i; for (i = 15; i >= 0; i--, p += 0xC8) if (*p == 1) func_003298F0(p); }

// FUNCTION: GAME 0x32EC00
void func_0032EC00(void) { char *p = D_003D1488; int i; for (i = 3; i >= 0; i--, p += 0x278) if (*p == 1) func_0032E720(p); }

// FUNCTION: GAME 0x32D340
int func_0032D340(int a, int b, int c, int d) { int r; func_0033FCA0(); r = func_0032D3A8(a, b, c, d); func_0033FCA8(); return r; }

// FUNCTION: GAME 0x32EE88
void func_0032EE88(char *s) { int i; int *p; i = 0; if (s[3] > 0) { p = (int *)(s + 0xC); do { if (*p) { int v = *p; *p = 0; func_003298C0(v); } i++; p++; } while (i < s[3]); } }

// FUNCTION: GAME 0x32EF00
void func_0032EF00(char *s) { int i; for (i = 0; i < s[3]; i++) func_00329EA8(((int *)(s + 0xC))[i]); }

// FUNCTION: GAME 0x32F068
void func_0032F068(int *s, int b) { int n = func_0032F4C8(s[1]); int i; for (i = 0; i < n; i++) func_0032B660(s[3 + i], b); }

// FUNCTION: GAME 0x32D0F8
int func_0032D0F8(int sv) { int *s = (int *)sv; if (!s) return 0; if (s[2] == 0) { int *t = (int *)s[0x94 / 4]; if (!t) return 0; if (t[0x28 / 4]) return func_00328F30(t[0x28 / 4]); return 0; } return func_00328F30(s[2]); }

// FUNCTION: GAME 0x32C2A8
void func_0032C2A8(char *s) { if (func_003277A0(*(int *)(s + 4)) == 1) { func_0032A6D0(s, 0, *(short *)(s + 0x42)); return; } func_0032A6D0(s, 0, *(short *)(s + 0x42)); func_0032A6D0(s, 1, *(short *)(s + 0x44)); }

#ifdef NONMATCHING
// DRAFT: GAME 0x330518
// diff: 4 words (copy of n = strlen + 1 into a3 happens before the loop setup in the original)
void func_00330518(char *s) { unsigned n = strlen(s) + 1; unsigned i; for (i = 0; i < n; i++) { int c = (unsigned char)s[i]; if ((unsigned)(c - 0x61) < 0x1A) s[i] = c - 0x20; } }
#endif
