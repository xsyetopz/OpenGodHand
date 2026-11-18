// COMPILER: ee-gcc2.96
extern char D_00458928[];
void func_00348BE0();
int func_003403C8(void);
int func_003403E0(void);
void func_00340970(int, int, int);
void func_003446D0(char *);
void func_003446D8(int);
void func_00344780(char *);
void func_00359EC0(int, int, void *);
int func_00345090();
int func_00346DD0(int, int);
int func_00360808(int, int);
int func_00349840(int);
int func_003492E8(int);
int func_00349468(int, int);
int func_0034B030();
void func_0035B0D8(int, int (*)(), int);
void func_0035A000(int, int, int);
void func_0032B300(int, int);
void func_0035C538(int, int);
void func_0035B5B8(int, int *, int *);
int func_0036C920(int, int, int);
void func_0034BD98(int, int);
void func_0034BFA8(char *, int, int);
void func_0034BFC8(char *);
int func_0034FEE0(int);
int func_0034DD70(char *, int);
extern char D_00458088[], D_004573D8[], D_00457410[], D_00458168[], D_00458628[], D_00458FD8[], D_00458C68[];
int func_00346828(int *);
void func_00345DF0(int *);
void func_00347E58(int *, int);
void func_00335950(int);
int func_00329438(int, int, int);
void func_003B9998(int, int, int);
int func_00358968(int);
int func_0034DE20(int, void *, int *);
int func_00345848();
void func_00345750(int);
void func_00343AE8(int *);
int func_003245B0(int, int, int, int *, int *, int *);
void func_0036CA38(char *, int);
void func_003485B0(char *, int);
void func_00347908(int *, int);
void func_00347AA8(int *);
void func_00349738(int, int);
void func_00325F20(void);
int func_003472E8(int *);
int func_003395A0(int, int, int);
void func_003443C8(int *);
int func_0035C338(char *, int);
int func_0034CA30(char *, int);
void func_0035C320(char *, int, int);
int func_0035C368(char *, int);
int func_0034CA98(char *, int);
void func_0035C350(char *, int, int);
int func_0035A1C8(char *, int);
void func_0032AB70(int, int);
int func_00358A38(int *);
int func_0034AFE0(void);
void func_0032AF40(int, int);

// FUNCTION: GAME 0x340920
void func_00340920(int a, int b, int c)
{
    func_003403C8();
    func_00340970(a, b, c);
    func_003403E0();
}

// FUNCTION: GAME 0x342CB0
void func_00342CB0(int *a, int *b, int *c, int *d, int *e)
{
    int t2 = a[2];
    int t3 = a[3];
    *d = (t2 / 2 + 31) / 32 * 32;
    *e = t3 / 2;
    *b = t2;
    *c = t3;
}

// FUNCTION: GAME 0x346D80
int func_00346D80(int a, int *b)
{
    int r = func_00346DD0(a, b[0x30 / 4]) == 1;
    if (b[0x88 / 4]) r = func_00360808(b[0x88 / 4], b[0x8C / 4]) == 1;
    return r;
}

// FUNCTION: GAME 0x34AFF0
void func_0034AFF0(int a)
{
    func_0035B0D8(a, func_0034B030, 2);
    func_0035A000(a, 0xF, 2);
}

// FUNCTION: GAME 0x34B478
void func_0034B478(int a, int b, int c)
{
    func_0032B300(a, c);
    func_0035C538(b, c);
}

// FUNCTION: GAME 0x34B4B8
void func_0034B4B8(int a, int *b, int c)
{
    int x[2];
    func_0035B5B8(a, &x[0], &x[1]);
    *b = func_0036C920(c, x[0], x[1]);
}

// FUNCTION: GAME 0x34BD58
void func_0034BD58(int a)
{
    func_0034BD98(a, 0);
    func_0034BD98(a, 1);
    func_0034BD98(a, 2);
}

// FUNCTION: GAME 0x34FE90
void func_0034FE90(char *a)
{
    int *p = *(int **)(a + 0x1F7C);
    if (func_0034FEE0(*p)) func_0034DD70(a, 0xFF000D0A);
}

// FUNCTION: GAME 0x345040
void func_00345040(char *a)
{
    int s = *(int *)(a + 0x3C);
    func_00359EC0(s, 0x4B, func_00345090);
    func_00359EC0(s, 0x4C, a);
}

// Diff: 2 words, a1 is copied to v1 early in the original (b held across the branch).
#ifdef NONMATCHING
// DRAFT: GAME 0x344680
void func_00344680(char *a, int b)
{
    if (*(int *)(a + 0x1EC)) func_003446D0(a);
    else func_003446D8(b);
    func_00344780(a);
}
#endif
// FUNCTION: GAME 0x345EE0
void func_00345EE0(int *a)
{
    if (func_00346828(a) != 1) {
        func_00348BE0(D_00458088);
        return;
    }
    func_00345DF0(a);
    func_00347E58(a, 0);
    a[0x74 / 4] = 0;
    func_00335950(a[0x48 / 4]);
}

// FUNCTION: GAME 0x343D68
int func_00343D68(int *a)
{
    int s = a[0x3C / 4];
    a[0x3C / 4] = 0;
    if (func_00358968(s)) {
        func_00348BE0(D_004573D8);
        return -1;
    }
    a[0x3C / 4] = s;
    if (func_0034DE20(s, func_00345848, a)) {
        func_00345750(-0x12F);
        func_00348BE0(D_00457410);
        return -1;
    }
    func_00343AE8(a);
    return 0;
}

// FUNCTION: GAME 0x346A48
void func_00346A48(char *a, int b)
{
    if (func_00346828((int *)a) != 1) {
        func_00348BE0(D_00458628);
        return;
    }
    func_0036CA38(a, b);
    func_003485B0(a + 0x284, b);
    func_003485B0(a + 0x2A4, b);
}

// FUNCTION: GAME 0x347A40
void func_00347A40(int *a)
{
    if (func_00346828(a) != 1) {
        func_00348BE0(D_00458FD8);
        return;
    }
    func_00347908(a, 0);
    func_00347AA8(a);
    a[0x2E8 / 4] = 4;
}

// FUNCTION: GAME 0x348CE0
void func_00348CE0(int a)
{
    int i = 0;
    while (i < 10) {
        i++;
        func_00349738(a, 1);
        func_00325F20();
        func_00349738(a, 0);
        if (*(int *)(a + 0x60) != 1) break;
    }
}

// FUNCTION: GAME 0x347310
int func_00347310(int *a)
{
    if (func_003472E8(a + 2) == 1) {
        int r = func_003395A0(a[0x180 / 4], a[0x184 / 4], 0);
        if (r) return r;
        func_00348BE0(D_00458C68);
        func_003443C8(a);
    }
    return 0;
}

// FUNCTION: GAME 0x34B7A8
void func_0034B7A8(char *a)
{
    if (func_0035C338(a, 7) != 1)
        if (func_0034CA30(a, *(int *)(a + 0x211C)) == 1) func_0035C320(a, 7, 1);
}

// FUNCTION: GAME 0x34B818
void func_0034B818(char *a)
{
    if (func_0035C368(a, 7) != 1)
        if (func_0034CA98(a, *(int *)(a + 0x211C)) == 1) func_0035C350(a, 7, 1);
}

// FUNCTION: GAME 0x34ABF8
void func_0034ABF8(char *a)
{
    int *p = *(int **)(a + 0x2004);
    int h = *p;
    int v = func_0035A1C8(a, 0x1B);
    if (p[0x44 / 4] != v) {
        p[0x44 / 4] = v;
        func_0032AB70(h, v);
    }
}
