// COMPILER: ee-gcc2.96

extern int func_0036D410();
extern int func_0036D460();
extern int func_00369F20();
extern int D_003F1EC8[];
struct E3 { int f; char pad[0x20]; };

extern int func_0036C5F8();
struct E4 { char pad[0x188]; int f; char pad2[0x2B4]; };
struct T4 { char pad[0x54]; int n; struct E4 *e; };
extern struct T4 D_00766CE8;

// FUNCTION: GAME 0x36A1D8
int func_0036A1D8(char *a, int *b)
{
    if (func_0036C5F8()) return func_00369F20(0, 0xFF03020D);
    *b = *(int *)(a + 0x2A8);
}

// FUNCTION: GAME 0x36CBC0
void func_0036CBC0(char *a, int b, int c)
{
    int *p = (int *)(a + 8);
    void (*fn)(int, int, int, int) = *(void (**)(int, int, int, int))(a + 0x18);
    int x = p[0], y = p[1], z = p[2];
    if (fn) fn(x, y, z, c);
    *(int *)(a + 4) = 0;
}

// FUNCTION: GAME 0x36C2A0
struct E4 *func_0036C2A0(void)
{
    int i;
    int n = D_00766CE8.n;
    struct E4 *e = D_00766CE8.e;
    for (i = 0; i < n; i++, e++)
        if (e->f == 1) return e;
    return 0;
}

extern void func_0036C438();
extern char *func_0036C2F0();

// FUNCTION: GAME 0x36C248
char *func_0036C248(void)
{
    char *s = (char *)func_0036C2A0();
    if (s) {
        func_0036C438(s, 0x40C);
        s = func_0036C2F0(s);
        *(int *)(s + 0x3B4) = ((int (*)(char *))func_0036C670)(s);
        return s;
    }
    return s;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x36CB08
// diff: 10 words, original loop keeps the table base in v0 and tests with bnez+nop where ours uses bnel (3 probes)
struct E3 *func_0036CB08(void)
{
    int i;
    int n = D_003F1EC8[1];
    struct E3 *e = (struct E3 *)(D_003F1EC8 + 2);
    for (i = 0; i < n; i++, e++)
        if (e->f == 0) return e;
    return 0;
}

// DRAFT: GAME 0x369F70
// diff: 12 words off: orig copies a1 to v0 before the frame save and tests v0 (4 probes)
void func_00369F70(int *p, int b)
{
    void (*fn)(int);
    int v = b;
    p[2] = v;
    if (v) {
        fn = (void (*)(int))p[0];
        if (fn) fn(p[1]);
    }
}

// DRAFT: GAME 0x36D938
// diff: same as 0x369F70 (12 words)
void func_0036D938(int *p, int b)
{
    void (*fn)(int);
    int v = b;
    p[2] = v;
    if (v) {
        fn = (void (*)(int))p[0];
        if (fn) fn(p[1]);
    }
}

// DRAFT: GAME 0x36D3D8
// diff: 6 words off: orig keeps the result in v1 and tests v1; ours uses v0
int func_0036D3D8(void)
{
    int v = func_0036D410();
    if (v) return func_0036D460(v);
}

// DRAFT: GAME 0x36CC08
// diff: 3 words off: lbu load order a3,a1,a2 vs orig a1,a2,a3 (4 probes)
void func_0036CC08(unsigned char *a, int b, int c)
{
    void (*fn)(int, int, int, int) = *(void (**)(int, int, int, int))(a + 0x1C);
    int x = a[0x14], y = a[0x15], z = a[0x16];
    if (fn) fn(c, x, y, z);
}

// DRAFT: GAME 0x36CC40
// diff: 3 words off: same as 0x36CC08 with offset 0x20
void func_0036CC40(unsigned char *a, int b, int c)
{
    void (*fn)(int, int, int, int) = *(void (**)(int, int, int, int))(a + 0x20);
    int x = a[0x14], y = a[0x15], z = a[0x16];
    if (fn) fn(c, x, y, z);
}

// DRAFT: GAME 0x36CB58
// diff: 10 words off: constant materialization order and registers differ (2 probes)
void func_0036CB58(char *a)
{
    int *p = (int *)(a + 8);
    char *q = a + 0x14;
    p[1] = 0x1F;
    p[2] = 100;
    p[0] = 0;
    *(int *)(a + 4) = 1;
    q[1] = 0x40;
    q[2] = -0x80;
    q[0] = 0;
}
#endif
