// COMPILER: ee-gcc2.9-991111
// SCE library small units 0x3B1000-0x3B3000, ee-gcc 2.9-991111 -O2 -G0.

// FUNCTION: GAME 0x3B1DE8
int func_003B1DE8(char **pp, int *pn, int c)
{
    if (*pn == 0)
        return 1;
    if (c < 0x100) {
        if (*pn == 1)
            c = 0;
        *(*pp)++ = c;
        (*pn)--;
        return 1;
    }
    **pp = 0;
    return 0;
}

// FUNCTION: GAME 0x3B2DE8
int *func_003B2DE8(int key, int *obj)
{
    int *a = *(int **)(obj + 10);
    int *v;
    while (a) {
        for (v = *(int **)(a + 2); v; v = *(int **)(v + 14)) {
            if (*v == key)
                return v;
        }
        a = *(int **)(a + 5);
    }
    return 0;
}

extern void func_003B63A0(void);
extern void func_003B63F0(void);

// FUNCTION: GAME 0x3B35F8
int func_003B35F8(int *obj)
{
    int *n;
    func_003B63A0();
    n = *(int **)(obj + 3);
    if (n == 0) {
        obj[1] = 0;
    } else {
        int v = n[15];
        obj[1] = 1;
        obj[3] = v;
    }
    func_003B63F0();
    return (int)n;
}

extern int D_003FAEE4;
extern char D_00460108[];
extern int CreateSema(void *);

// FUNCTION: GAME 0x3B3E70
void func_003B3E70(void)
{
    int sema[8];
    if (D_003FAEE4 == -1) {
        sema[2] = 1;
        sema[5] = (int)D_00460108;
        sema[1] = 1;
        D_003FAEE4 = CreateSema(sema);
    }
}

extern int D_003FAEE8;
extern int D_003FAEEC;
extern char D_00460080[];
extern char D_00460090[];
extern void func_003B59D8(void);

// FUNCTION: GAME 0x3B3858
void func_003B3858(void)
{
    int sema[8];
    if (D_003FAEE8 == -1) {
        sema[2] = 1;
        sema[5] = (int)D_00460080;
        sema[1] = 1;
        D_003FAEE8 = CreateSema(sema);
        sema[5] = (int)D_00460090;
        D_003FAEEC = CreateSema(sema);
    }
}

extern int WaitSema(int);
extern int SignalSema(int);
extern char D_007814C0[];

#ifdef NONMATCHING
// DRAFT: GAME 0x3B3A48 (2 words off: sll into $v1 instead of $s0)
char *func_003B3A48(unsigned n)
{
    func_003B3858();
    WaitSema(D_003FAEE8);
    if (n >= 0x20) {
        SignalSema(D_003FAEE8);
        return 0;
    }
    n <<= 4; n = n + (unsigned)D_007814C0;
    SignalSema(D_003FAEE8);
    return (char *)n;
}
#endif

// FUNCTION: GAME 0x3B38D0
int *func_003B38D0(void)
{
    int *p;
    func_003B3858();
    WaitSema(D_003FAEE8);
    for (p = (int *)D_007814C0; p < (int *)(D_007814C0 + 0x200); p += 4) {
        if (p[1] == 0) {
            p[1] = 0x10000000;
            SignalSema(D_003FAEE8);
            return p;
        }
    }
    SignalSema(D_003FAEE8);
    return 0;
}

extern int D_003FAF18;
extern int D_003FAF1C;
extern char D_00460370[];
extern char D_00460380[];

// FUNCTION: GAME 0x3B6408
void func_003B6408(void)
{
    int s[16];
    s[1] = 1;
    s[2] = 1;
    s[9] = 1;
    s[10] = 1;
    s[5] = (int)D_00460370;
    s[13] = (int)D_00460380;
    D_003FAF18 = CreateSema(s);
    D_003FAF1C = CreateSema(s + 8);
}

extern void func_003B0A40(int);

// FUNCTION: GAME 0x3B3098
void func_003B3098(int *a)
{
    int *b = (int *)a[13];
    int *c = (int *)b[16];
    if (c[3] == 0)
        c[3] = (int)b;
    else
        ((int *)c[4])[15] = (int)b;
    c[4] = (int)b;
    {
        int t1 = a[5], t2 = a[7];
        b[8] = t1;
        b[7] = t2;
    }
    b[9] = a[8];
    b[3] = a[9];
    b[10] = a[10];
    b[11] = a[11];
    b[12] = a[12];
    b[13] = a[4];
    if (c[0] >= 0 && c[1] == 0)
        func_003B0A40(c[0]);
}
