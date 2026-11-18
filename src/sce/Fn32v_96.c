// COMPILER: ee-gcc2.96
extern char D_00452918[];
extern char D_00452258[];
extern char D_00452060[];
extern int D_003D04C4;
extern int D_003D1404;
extern int D_003C7410;
extern char D_003C7420[];
extern void (*D_003D1420)(char *);
void func_0033F130(char *);
int func_0032A880(char *, int);
int func_0032A9C0(char *);
void func_0032A720(char *, int, int);
void func_0032A900(char *, int);
void func_00326410(int, int);
int func_00328C80(int, int, int);
void func_00328448(int, int);
void func_003283E8(int, int, int);
void func_003280D8(int, int);
void func_003282D0(int);
void func_00327FA8(int);
void func_00327E18(int, int, int, int, int);
void func_003281C8(int);
void func_00329B60(char *, int);
void func_0032CB90(char *);
void func_0032C5F8(char *);
void func_0032CA10(char *);
void func_0032CC90(char *);
void func_0032CE98(char *);
void func_0032CF30(char *);
void func_0032CEB0(char *);
int func_00327818(int), func_00327830(int), func_00327860(int), func_00327970(int);
void func_00327760(int, int), func_00327758(int, int), func_00327768(int, int), func_00327718(int, int), func_00327748(int, void *, int *);
void func_0032C048(void);
int func_00329058(int *);
void func_003288E0(char *);
int func_0032F468(int);
int func_00329F98(int);
void func_00326860(int);
int func_00335950(int);
void func_00329E08(char *);

// FUNCTION: GAME 0x329C68
void func_00329C68(char *a, int b, int c, int d, int e)
{
    func_00328C80(*(int *)(a + 8), *(short *)(a + 0x3E) << 11, *(short *)(a + 0x3C) << 11);
    func_00328448(*(int *)(a + 8), D_003D1404);
    func_003283E8(*(int *)(a + 8), 0, 0);
    func_003280D8(*(int *)(a + 8), 0);
    func_003282D0(*(int *)(a + 8));
    func_00327FA8(*(int *)(a + 8));
    func_00327E18(*(int *)(a + 8), b, c, d, e);
    func_003281C8(*(int *)(a + 8));
    func_00329B60(a, *(int *)(a + 0x10));
}

// FUNCTION: GAME 0x328FA0
void func_00328FA0(char *a)
{
    if (*(int *)(a + 0x50) != 0 && *(int *)(a + 8) == 0) {
        a[0x45] = 1;
        do {
            if (func_00329058(&D_003D04C4) == 1) {
                func_003288E0(a);
                D_003D04C4 = 0;
            }
        } while (a[0x45] != 0);
    }
}

// FUNCTION: GAME 0x32BA30
void func_0032BA30(int a)
{
    int i, j;
    char *p = D_003C7420;
    D_003C7410 = a;
    for (i = 15; i >= 0; i--) {
        if (p[0] == 1) {
            for (j = 0; j < p[3]; j++)
                func_0032A720(p, j, func_0032A880(p, j));
            func_0032A900(p, func_0032A9C0(p));
        }
        p += 200;
    }
}

// FUNCTION: GAME 0x32BF90
void func_0032BF90(int *a)
{
    int h = a[1];
    int s3, s4, s0;
    s3 = func_00327818(h);
    s4 = func_00327830(h);
    s0 = func_00327860(h);
    func_00327970(h);
    s0 -= s3;
    func_00327760(h, 0);
    a[0x24] = s0;
    func_00327758(h, s0);
    func_00327768(h, s4);
    func_00327718(h, s3);
    func_00327748(h, func_0032C048, a);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x32CFF8
// diff: 4 words (bne vs bnel on each a[1] test)
void func_0032CFF8(char *a)
{
    if (a == 0) { func_0033F130(D_00452918); return; }
    {
        int t = a[1];
        if (t == 3) func_0032CB90(a);
        else if (t == 1) func_0032C5F8(a);
        else if (t == 2) func_0032CA10(a);
        else if (t == 4) func_0032CC90(a);
        else if (t == 5) func_0032CE98(a);
    }
    func_0032CF30(a);
    func_0032CEB0(a);
}

// DRAFT: GAME 0x329ED8
// diff: 8 words (a[0x14] load is hoisted into the bnel delay slot; original loads it in v0 after the a[2]==4 call)
void func_00329ED8(char *a)
{
    if (a == 0) { func_0033F130(D_00452060); return; }
    if (D_003D1420 != 0) {
        func_00326860(*(int *)(a + 4));
        D_003D1420(a);
    }
    if (*(int *)(a + 8) != 0) func_00327FA8(*(int *)(a + 8));
    if (a[2] == 4) func_00335950(*(int *)(a + 0x94));
    {
        int **o = *(int ***)(a + 0x14);
        if (o) (*(void (**)(int **))((char *)*o + 0x14))(o);
    }
    func_00329E08(a);
}

// DRAFT: GAME 0x32A900
// diff: 18 words (clamp branch layout: beql/b/nop vs original beqz/bnel)
void func_0032A900(char *a, int b)
{
    if (a == 0) { func_0033F130(D_00452258); return; }
    if (b < -15) *(short *)(a + 0x46) = -15;
    else if (b < 16) *(short *)(a + 0x46) = b;
    else *(short *)(a + 0x46) = 15;
    if (D_003C7410 == 0)
        func_00326410(*(int *)(a + 0xC), *(short *)(a + 0x46));
    else
        func_00326410(*(int *)(a + 0xC), -0x80);
}
#endif
