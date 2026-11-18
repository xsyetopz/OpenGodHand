// COMPILER: ee-gcc2.96
// SCE library code (sd s0 prologues), built with ee-gcc 2.96 (C) at -O2 -G0.

extern int D_00760DB0;
void *memset(void *, int, unsigned int);
void func_0034DF68(void *);
void func_0034DF80(void *);
void func_00366C50(int *, int, int);

extern int D_00766CE8[];
extern char D_0045A420[];
extern int D_0076A590[];
void func_0033ACA0();
int func_0036B888();
void func_0036BB78(int **);
void func_0036C438(int *, int);
void func_0036D6B0(int *, char *, int);
int func_00368B18(int, int *, int);
int func_00366E18();
void func_0034DD70(int, int);

// FUNCTION: GAME 0x36B6D8
int func_0036B6D8(char *a, int **b)
{
    int buf[4];
    int *s = (int *)(a + 0x38C);
    int v, x;
    ((void (*)(int **, int, int, int *))(*b)[6])(b, 1, 0x7FFFFFFF, s);
    v = *s;
    x = v & -4;
    {
        int c = x + (((v - x) << 3) >> 3);
        c += 4;
        func_0033ACA0(s, c - v, s, buf);
    }
    ((void (*)(int **, int, int *))(*b)[8])(b, 0, s);
    ((void (*)(int **, int, int *))(*b)[7])(b, 1, buf);
    func_0036BB78(b);
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x36B798
// diff: 22 words: s-reg and arg-order scheduling around func_0036B888
int func_0036B798(char *a, int **b)
{
    int buf[4];
    int *s = (int *)(a + 0x38C);
    int v, x, r, c;
    ((void (*)(int **, int, int, int *))(*b)[6])(b, 1, 0x7FFFFFFF, s);
    v = *s;
    x = v & -4;
    r = func_0036B888(a, v, *(int *)(a + 0x390));
    c = x + 8 + (((v - x) << 3) >> 3) - 4;
    func_0033ACA0(s, c - *s, s, buf);
    ((void (*)(int **, int, int *))(*b)[8])(b, 0, s);
    ((void (*)(int **, int, int *))(*b)[7])(b, 1, buf);
    func_0036BB78(b);
    return r;
}
#endif

// FUNCTION: GAME 0x34CE80
int func_0034CE80(char *a, int b, int c)
{
    char lk[16];
    int *s = (int *)(a + 0xD30);
    int r = 0;
    func_0034DF68(lk);
    if (s[0x1F4 / 4] - s[0x1F8 / 4] < 0x20) {
        s[0x1EC / 4] = c;
        ((int *)a)[0xF2C / 4 + s[0x1F4 / 4] % 32] = b;
        r = 1;
        s[0x1F4 / 4] = s[0x1F4 / 4] + 1;
    }
    func_0034DF80(lk);
    return r;
}

// FUNCTION: GAME 0x34FA28
void func_0034FA28(char *a, int *b, int *c)
{
    int buf[8];
    int s2 = 0, s1 = 0, i = 0;
    int *p = *(int **)(a + 0x1F7C);
    int q = p[0];
    do {
        func_00368B18(q, buf, i);
        i++;
        if (buf[2] >= s2)
            s2 = buf[2];
        if (buf[3] >= s1)
            s1 = buf[3];
    } while (i < 3);
    p[1] = s1;
    p[2] = s2;
    *b = s2;
    *c = p[1];
}

#ifdef NONMATCHING
// DRAFT: GAME 0x36C0B0
// diff: 5 words: memset size add after a0 move, and tail store order 54/58/50
void func_0036C0B0(int a, int b)
{
    int s3 = (b + 0x3F) & -0x40;
    int s1 = s3 + a * 0x440;
    int s4 = s1 + 0x420;
    func_00366C50((int *)s3, 0, a * 0x118 + 0x800);
    func_0036C438((int *)s4, 0x1BE0);
    func_0036D6B0(D_00766CE8, D_0045A420, 0x10);
    D_00766CE8[0x4C / 4] = s1;
    D_00766CE8[0x58 / 4] = s3;
    D_00766CE8[0x50 / 4] = s4;
    D_00766CE8[0x54 / 4] = a;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x36D280
// diff: 38 words: loop strength reduction differs (152 vs 160 bytes)
void func_0036D280(int a, int b, unsigned int c)
{
    int p;
    while (c < (unsigned int)(a * 0x700 + 0x40))
        a--;
    p = (b + 0x3F) & -0x40;
    memset((void *)p, 0, a * 0x700);
    D_0076A590[0x44 / 4] = p;
    D_0076A590[0x40 / 4] = a;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x350048
// diff: 37 words: compiler CSEs sp+4 into s2, frame 0x50 vs 0x40
void func_00350048(int a, int *b, char *c)
{
    int buf[2];
    int *s0 = (int *)(c + 0x30);
    int s1 = *b;
    int r1 = func_00366E18(s1, s0, s0[0x160 / 4], buf, buf + 1);
    int r2 = func_00366E18(s1, c + 0xE0, s0[0x164 / 4], buf, buf + 1);
    if (r1 || r2)
        func_0034DD70(a, 0xFF000D0D);
}
#endif
