// COMPILER: ee-gcc2.96
extern int D_00758900;
extern char *D_007588FC;
extern int D_003EB848;
extern char D_00457748[];
unsigned strncmp(const char *, const char *, unsigned);
int func_0033F850(int);
void func_0033BD18(void);
void func_0033BD30(void);
void func_0033BD48(void);
void func_0033BD60(void);
void func_0033BD90(void);
void func_00348BE0(char *);
int func_00344610(void);
int func_00344648(int);
void func_00344770(int *);
int func_00345598(int);

// FUNCTION: GAME 0x33FCD0
char *func_0033FCD0(char *a)
{
    int i;
    char *p;
    if (a[0] == 0) return 0;
    p = D_007588FC;
    for (i = 0; i < D_00758900; ) {
        if (strncmp(p, a, 12) == 0) return p;
        i++;
        p += 16;
    }
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x344568
// diff: 7 words, original copies arg b into $a2 up front where the compile keeps $a1/$a0
int func_00344568(int *a, int b)
{
    int r; int *q = &a[0x1EC / 4];
    if (a[0x200 / 4] >= 0x20) { func_00348BE0(D_00457748); return 0; }
    if (b < 0) return 0;
    if (*q != 0) r = func_00344610();
    else r = func_00344648(b);
    if (r != 0) {
        a[0x204 / 4 + a[0x200 / 4]] = r;
        func_00344770(a);
    }
    return r;
}

// DRAFT: GAME 0x33F720
// diff: 25 words, switch layout differs (case 1 / case 2 branch order, 144 vs 152 bytes)
int func_0033F720(void)
{
    switch (func_0033F850(D_003EB848)) {
    case 1: break;
    case 2: func_0033BD18(); break;
    case 3:
        func_0033BD18();
        func_0033BD30();
        func_0033BD48();
        func_0033BD60();
        func_0033BD90();
        break;
    }
    return 0;
}

// DRAFT: GAME 0x33E9A0
// diff: 26 words, byte-swap code order differs and the original hoists the 0xFF00 mask into $t0
int func_0033E9A0(unsigned char *p, int n, unsigned short *out)
{
    unsigned short h;
    if (n < 0x12) return -1;
    h = *(unsigned short *)p;
    if ((unsigned short)((h << 8) | (h >> 8)) != 0x8000) return -2;
    if ((short)((p[2] << 8) | p[3]) < 0xE) return -1;
    h = *(unsigned short *)(p + 16);
    *out = ((h << 8) & 0xFF00) | (h >> 8);
    return 0;
}

// DRAFT: GAME 0x344B28
// diff: 29 words, register allocation and store order differ (160 vs 152 bytes)
void func_00344B28(char *a, char *b, int *c)
{
    char *e = a + 0x160;
    int *p = *(int **)(b + 0x38);
    char *s4 = *(char **)(a + 0x178);
    int s1 = p[1];
    int s0 = p[0];
    if (func_00345598(s0) != 1 || s4 == e) { c[0x48 / 4] = 0; c[0x44 / 4] = 0; return; }
    if (s0 != 0) {
        if (s1 >= 5) { s0 += 4; s1 -= 4; }
    }
    c[0x48 / 4] = s1;
    c[0x44 / 4] = s0;
}
#endif
