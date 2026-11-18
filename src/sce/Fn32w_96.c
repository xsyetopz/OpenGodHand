// COMPILER: ee-gcc2.96
extern char D_00452D10[];
extern char D_00454CD8[];
extern int D_003E0710, D_003E0708, D_003E0738;
extern int D_003E0748[2];
void func_00332670(int, int, int, int *, int);
extern char D_00452038[];
void func_0033F130(char *);
void func_00329ED8(void);
void func_0033E678(void);
void func_0033E690(void);
void func_00329B60(char *, char *);
void func_0032B6A0(char *, int);
void *memset(void *, int, unsigned);
int func_00328098(int);
int func_00335AA0(int);
void func_0032B300(int, int);
void func_0032DC90(char *);
void func_0033FCB0(char *);
void func_0033FC70(void *);
int func_0033FC88(void);
void func_0032D430(void *, int, int);
void func_00335D40(char *);
void func_00328368(char *);
void func_00335848(char *);
int func_0032E3A0(char *);
void func_00328C80(int, int, int);
void func_0032EF68(char *, int);

// FUNCTION: GAME 0x32CEB0
void func_0032CEB0(char *a)
{
    int v = *(int *)(a + 8);
    if (v != 0) {
        if (func_00328098(v) == 4) {
            *(short *)(a + 0x60) = -1;
            a[1] = 6;
        }
    }
    if (*(int *)(a + 0x94) != 0) {
        if (func_00335AA0(*(int *)(a + 0x94)) == 3) {
            *(short *)(a + 0x60) = -1;
            a[1] = 6;
        }
    }
}

// FUNCTION: GAME 0x32DD70
void func_0032DD70(char *a)
{
    float f = *(float *)(a + 0x1E4);
    if (f != 0.0f) {
        int n = func_0032E3A0(a);
        func_00328C80(*(int *)(a + 8), (int)((float)n * *(float *)(a + 0x1E4)), *(int *)(a + 0x118));
    } else {
        int n = *(int *)(a + 0x118);
        func_00328C80(*(int *)(a + 8), n / 2, n);
    }
}

// FUNCTION: GAME 0x32E090
void func_0032E090(char *a, int b)
{
    if (a == 0)
        func_0033FCB0(D_00452D10);
    else {
        func_0032DC90(a);
        *(int *)(a + 0x1A8) = b;
        if (a[1] != 1) func_0032EF68(a, b);
    }
}

// FUNCTION: GAME 0x32EF68
void func_0032EF68(char *a, int b)
{
    int i = 0;
    int *p;
    if (a[3] > 0) {
        p = (int *)(a + 0xC);
        do {
            if (*p) func_0032B300(*p, b);
            p++;
            i++;
        } while (i < a[3]);
    }
}

// FUNCTION: GAME 0x335980
void func_00335980(char *a)
{
    if (a == 0) { func_00335D40(D_00454CD8); return; }
    if (a[1] != 0) {
        a[1] = 0;
        { char *h = *(char **)(a + 0x28); if (h) {
            if (a[2] == 1) { func_00328368(h); a[2] = 0; }
        } }
        *(int *)(a + 0x2C) = 0;
        func_00335848(a);
        *(int *)(a + 0x34) = 0;
    }
}

// FUNCTION: GAME 0x329D78
void func_00329D78(char *a, char *b)
{
    if (a == 0 || b == 0) {
        func_0033F130(D_00452038);
        return;
    }
    func_00329ED8();
    func_0033E678();
    a[2] = 3;
    func_00329B60(a, b);
    func_0032B6A0(a, 1);
    func_0033E690();
}

#ifdef NONMATCHING
// DRAFT: GAME 0x337C88
// diff: 5 words (address register for D_003E0748 stores: $v0/$v1 swapped, original loads $a0/$v0 then address in $v1)
void func_00337C88(void)
{
    int t[2];
    if (D_003E0710 == 1 && D_003E0708 <= 0) return;
    if (D_003E0738 != 0) {
        func_00332670(15, 0, 0, t, 2);
        D_003E0748[0] = t[0];
        D_003E0748[1] = t[1];
        D_003E0738 = 0;
    }
}
#endif
