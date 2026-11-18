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

// Round 26: framed units of 0xA0-0xB0 bytes
void *memset(void *, int, unsigned);
char *strcpy(char *, const char *);
void func_0033E678(void);
void func_0033E690(void);
void func_00326320(int, int);
void func_00326338(int, int);
void func_00338378(int, int);
void func_00326860(int);
void func_0033C228(int);
int func_0032F4C8(int);
int func_00329F98(int);
int func_0032F468(int);
void func_00330A68(char *);
int func_00330480(char *);
void func_00330F10(char *, char *);
extern char D_003E9970[0x20];
extern char D_007588A0[8], D_007588A8[8], D_007588C0[8], D_007588C8[8];
extern int D_003E9950[5];
extern int D_007588B8;
extern volatile int D_003D1470;
extern int D_003D1474;
extern int D_003D1478;
extern char D_003D1488[];
extern char D_00452980[], D_00452990[];
void func_00324950(void);
void func_0032F230(void);
void func_0032D168(void);
void func_0032D198(void);

// FUNCTION: GAME 0x329E08
void func_00329E08(int *s) {
    func_0033E678();
    func_00326320(s[3], 0); func_00326338(s[3], 0); func_00338378(s[3], 1); func_00326860(s[1]);
    if (((char *)s)[2] == 2) { int *o = (int *)s[5]; if (o) { s[5] = 0; ((void (**)(int *))(*(int **)o))[3](o); } }
    if (s[0x74 / 4]) func_0033C228(s[0x74 / 4]);
    s[5] = 0; ((char *)s)[1] = 0; ((char *)s)[0xAC] = 0;
    func_0033E690();
}

// FUNCTION: GAME 0x32D1A0
void func_0032D1A0(void) {
    int x = D_003D1470;
    if (D_003D1474 == 0) {
        func_00324950(); func_0032F230();
        memset(D_003D1488, 0, 0x9E0);
        func_0033BA10(2, 0, (int)func_0032D168 + 8, 0, (int)D_00452980);
        D_003D1478 = func_0033B810(5, (int)func_0032D198, 0, (int)D_00452990);
    }
    D_003D1474++;
}

// FUNCTION: GAME 0x32F0D0
int func_0032F0D0(int *s) { int i = 0, n, r; int *p = s + 3; n = func_0032F4C8(s[1]); for (; i < n; i++) { r = func_00329F98(*p++); if (r == 6) ((char *)s)[1] = 4; if (r != 3) break; } return i == n; }

// FUNCTION: GAME 0x3306D8
int func_003306D8(char *a, char *b, char *c) { int r; if (*a == 0) func_00330A68(a); if (*a == 0) return 0; func_00330F10(a, b); r = func_00330480(a); if (r == 0) { func_00330A68(a); r = func_00330480(a); if (r == 0) return 0; strcpy(b, c); } return r; }

// FUNCTION: GAME 0x33BDD8
void func_0033BDD8(void) { int i; int *p; memset(D_003E9970, 0, 0x20); memset(D_007588A0, 0, 8); memset(D_007588A8, 0, 8); memset(D_007588C0, 0, 8); memset(D_007588C8, 0, 8); p = D_003E9950; i = 5; do { *p++ = 0; } while (--i >= 0); D_007588B8 = 0; }

#ifdef NONMATCHING
// DRAFT: GAME 0x32F178
// diff: 2 words (original loads the constant 5 into s3 before the pointer into s1)
int func_0032F178(char *s) { int i, r; int *p; if (func_0032F468(*(int *)(s + 4)) == 3) { for (i = 0, p = (int *)(s + 0xC); i < s[3]; i++) { r = func_00329F98(*p++); if (r != 5 && r != 0) break; } if (i == s[3]) return 1; } return 0; }
#endif

// Round 27 declarations
extern char D_00452D78[], D_003D9DE0[], D_004544E0[], D_004544E8[], D_00455308[], D_00455330[], D_004527A0[], D_003E9990[], D_003DA250[], D_003E2B68[];
extern int D_003E8C08[], D_003E0710, D_003E0708;
extern struct { void (*f)(int, char *); int a; } D_007588B0;
char *strcat(char *, const char *);
int strlen(const char *);
int strcmp(const char *, const char *);
int vsprintf(char *, const char *, void *);
void func_0033FCB0(char *);
void func_0033F130(char *);
void func_00340920(int);
int func_0032F570(int);
int func_0032F538(int);
int func_0032A4A8(int);
void func_003329E8(char *);
void func_0032EF00(void);
void func_00329EA8(void);
int func_0032B660(char *, int);
void func_0033F130(char *);
int func_003351C0(int, int *);
void func_00334D68(int, char *);
int func_00331C78(int);
void func_00331F50(int);
void func_00338960(void);
void func_00338978(void);
void func_00340130(void);
void func_00338478(char *);
void func_0033B200(void);

// FUNCTION: GAME 0x32E150
int func_0032E150(char *s) {
    if (s == 0) { func_0033FCB0(D_00452D78); return -1; }
    if ((unsigned)((unsigned char)s[1] - 1) < 3) {
        switch (func_0032F570(*(int *)(s + 4))) {
        case 0: return func_0032F538(*(int *)(s + 4));
        case 1: return func_0032A4A8(*(int *)(s + 0xC));
        }
    }
    return 0;
}

// FUNCTION: GAME 0x333390
void func_00333390(char *a, char *b) {
    strcpy(b, D_003D9DE0);
    if (*a != 0x2F && *a != 0x5C) strcat(b, D_004544E0);
    strcat(b, a);
    if (strcmp(b + strlen(b) - 2, D_004544E8) != 0) strcat(b, D_004544E8);
    func_003329E8(b);
}

// FUNCTION: GAME 0x33AD08
int func_0033AD08(char *s) {
    int h = D_003E8C08[s[0]];
    h = (h << 4) + D_003E8C08[s[1]];
    h = (h << 4) + D_003E8C08[s[2]];
    h = (h << 4) + D_003E8C08[s[3]];
    h = (h << 4) + D_003E8C08[s[4]];
    h = (h << 4) + D_003E8C08[s[5]];
    h = (h << 4) + D_003E8C08[s[6]];
    return h;
}

// FUNCTION: GAME 0x336D08
void func_00336D08(char *a, int b, int c) {
    int *q, *o, v;
    if (a == 0) { func_0033F130(D_00455308); return; }
    q = *(int **)(a + 4);
    o = (int *)q[1];
    v = o[0xE8 / 4];
    if (a[3] < 2 || v == 0) { func_0033F130(D_00455330); return; }
    func_00340920(v);
    o[0xEC / 4] = b;
    o[0xF0 / 4] = c;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x33B6E8
// diff: 1 word (va pointer is sp+0x80 from __builtin_next_arg; the original has sp+0x48, the saved a1 slot; the package has no stdarg.h)
void func_0033B6E8(const char *fmt, ...) {
    char *ap = __builtin_next_arg(fmt);
    memset(D_003E9990, 0, 0x80);
    vsprintf(D_003E9990, fmt, ap);
    if (D_007588B0.f) D_007588B0.f(D_007588B0.a, D_003E9990);
}
#endif

// FUNCTION: GAME 0x32BC98
void func_0032BC98(char *s, char *name, int c, int d) {
    if (s == 0 || name == 0) { func_0033F130(D_004527A0); return; }
    func_00329EA8();
    strcpy(*(char **)(s + 0xB0), name);
    *(int *)(s + 0xB4) = *(int *)(s + 0xB0);
    *(int *)(s + 0xBC) = c;
    *(int *)(s + 0xC0) = d;
    *(int *)(s + 0xB8) = 0;
    s[1] = 1;
    s[0xAC] = 1;
    s[2] = 0;
    func_0032B660(s, 0);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x334248
// diff: 3 words (lui of D_003DA250 is scheduled before the jal delay slot, original places it after)
int func_00334248(int a) {
    int t[4]; int s0; char *p;
    if (a == 0) return 0;
    p = D_003DA250;
    func_003351C0(a, t);
    if (t[1] == 0) {
        func_00334D68(a, p);
        func_00331C78(0x4200);
        s0 = func_00331EE8((int)p, 1);
        func_00331C78(0x4201);
        if (s0 < 0) return 0;
        func_00331C78(0x4300);
        func_00331F50(s0);
        func_00331C78(0x4301);
    }
    return 1;
}

// DRAFT: GAME 0x338638
// diff: 2 words (s1 = 15 and s2 = 1 are loaded in swapped order)
void func_00338638(void) {
    int i; char *p;
    if (D_003E0710 == 1 && D_003E0708 <= 0) return;
    func_00338960();
    p = D_003E2B68;
    for (i = 15; i >= 0; i--, p += 0x64)
        if (*p == 1) func_00338478(p);
    func_00338978();
    func_00340130();
    func_0033B200();
}
#endif
