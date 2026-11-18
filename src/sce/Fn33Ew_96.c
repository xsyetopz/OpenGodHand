// COMPILER: ee-gcc2.96
int func_0033FCD0();
extern int D_007588FC;
void func_00347450();
int strncpy();
extern char D_003EADC0[];
extern int (*D_003EADB8)();
extern int D_003EADBC;
extern char D_00456930[];
int func_0033B6E8();
void func_003497A0();
int func_00358968();
void func_00345750();
void func_00348498();
void func_00349B60();
void func_00335950();
extern char D_00458068[];
int func_00348BE0();
int func_00345598();
int func_003504A0();
extern char D_00457308[];
extern char D_00457340[];
extern char D_00457890[];
extern int D_003EC660;
int func_003424A8(int, int, int, int, int, int, short, short, int, short, short);
int func_003420E0(int, int, int, int, int, int, short, short, int, short, short);

// FUNCTION: GAME 0x33FD70
int func_0033FD70(int a, int *b)
{
    int *p;
    if (D_007588FC == 0) return -1;
    p = (int *)func_0033FCD0();
    if (p == 0) return -3;
    *b = p[3];
    return 0;
}

// FUNCTION: GAME 0x3448F8
void func_003448F8(char *a, char *b)
{
    int v = *(int *)(b + 0x30);
    if (*(int *)(a + 0x190) < v) func_00347450(a);
    *(int *)(a + 0x190) = *(int *)(b + 0x30);
}

// FUNCTION: GAME 0x33F130
void func_0033F130(char *a)
{
    char *s;
    if (a == 0) {
        func_0033B6E8(D_00456930);
        return;
    }
    s = D_003EADC0;
    strncpy(s, a, 0xFF);
    if (D_003EADB8) D_003EADB8(D_003EADBC, s);
    func_0033B6E8(s);
}

// FUNCTION: GAME 0x345DF0
void func_00345DF0(char *a)
{
    int s = *(int *)(a + 0x3C);
    if (s == 0) return;
    func_003497A0();
    *(int *)(a + 4) = 0;
    *(int *)(a + 0x3C) = 0;
    if (func_00358968(s) != 0) {
        func_00345750(-0x134);
        func_00348BE0(D_00458068);
    }
    *(int *)(a + 0x3C) = s;
    func_00348498(a + 0x284);
    func_00348498(a + 0x2A4);
    *(int *)(a + 0x2CC) = 0;
    if (*(int *)(a + 0x40) != 0) func_00349B60(*(int *)(a + 0x40));
    if (*(int *)(a + 0x48) != 0) func_00335950(*(int *)(a + 0x48));
    if (*(int *)(a + 0x2E0) == 0) {
        *(int *)(a + 0x2E4) = 0;
        *(int *)(a + 0x2DC) = 0;
        *(int *)(a + 0x300) = 0;
        *(int *)(a + 0x2FC) = -1;
        *(int *)(a + 0x2E8) = 0;
    } else {
        *(int *)(a + 0x2E8) = 2;
    }
}

// FUNCTION: GAME 0x343AE8
int func_00343AE8(char *a)
{
    int *p = *(int **)(a + 0x178);
    int s1, s2, s3;
    if (p == 0) {
        return func_00348BE0(D_00457308);
    }
    s3 = p[2];
    s2 = *(int *)(a + 0x18) + 4;
    s1 = p[0];
    if (p[1] < s2 * s3) {
        return func_00348BE0(D_00457340);
    }
    if (func_00345598() == 1) return func_003504A0(*(int *)(a + 0x3C), s1, s2, s3);
}

// FUNCTION: GAME 0x344C30
int func_00344C30(unsigned a)
{
    int r;
    switch (a) {
    case 1: r = 1; break;
    case 2: r = 2; break;
    case 3: r = 3; break;
    case 4: r = 4; break;
    default:
        func_00348BE0(D_00457890);
        r = 1;
    }
    return r;
}

// FUNCTION: GAME 0x3427F0
int func_003427F0(int a, int b, int c, int d, int e, int f, short g, short h, int i, short j, short k)
{
    if (D_003EC660 == 0)
        return func_003424A8(a, b, c, d, e, f, g, h, i, j, k);
    return func_003420E0(a, b, c, d, e, f, g, h, i, j, k);
}
