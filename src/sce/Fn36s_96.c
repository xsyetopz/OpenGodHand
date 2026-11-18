// COMPILER: ee-gcc2.96
extern int D_003EEA6C;
extern int *D_00766CD8;
extern int *D_00766D44;
extern int *D_0076A5D8;
extern int D_00766D38;
extern int D_003F1ABC;
extern int *func_00360D18();

// FUNCTION: GAME 0x3607A0
void func_003607A0(void)
{
    if (D_003EEA6C > 0)
        D_003EEA6C = D_003EEA6C - 1;
}

// FUNCTION: GAME 0x368FC0
int func_00368FC0(int *p)
{
    D_00766CD8 = p;
    if (!p)
        return -1;
    return (p[0] ^ 1) ? 0 : -1;
}

// FUNCTION: GAME 0x36C5F8
int func_0036C5F8(int *p)
{
    D_00766D44 = p;
    if (!p)
        return -1;
    return (p[0x188 / 4] ^ 2) ? -1 : 0;
}

// FUNCTION: GAME 0x36D688
int func_0036D688(int *p)
{
    D_0076A5D8 = p;
    if (!p)
        return -1;
    return (p[0] ^ 2) ? -1 : 0;
}

// FUNCTION: GAME 0x36A380
void func_0036A380(char *p, int i, int a, int b, int c)
{
    int *q = (int *)(p + i * 12 + 0x3BC);
    q[0] = a;
    q[1] = b;
    q[2] = c;
}

// FUNCTION: GAME 0x36DDA0
void func_0036DDA0(char *p, int i, int a, int b, int c)
{
    int *q = (int *)(p + i * 12 + 0x11C);
    q[0] = a;
    q[1] = b;
    q[2] = c;
}

// FUNCTION: GAME 0x36C080
void func_0036C080(int *o)
{
    int v;
    o[0x30 / 4] = D_00766D38 + 0x1100;
    v = D_003F1ABC;
    o[0x40 / 4] = v;
    o[0x110 / 4] = v;
}

// FUNCTION: GAME 0x360D28
void func_00360D28(int a)
{
    *func_00360D18() = a;
}

extern int D_003F1EC8;
extern int (*D_003F2004)();
extern int (*D_003F2030)();

// FUNCTION: GAME 0x369130
void func_00369130(int *p)
{
    p[0] = -1;
    p[1] = -1;
    p[2] = -1;
    p[3] = -1;
    p[4] = -1;
    p[5] = -1;
    p[6] = -1;
    p[7] = -1;
}

// FUNCTION: GAME 0x369158
void func_00369158(int *p)
{
    long m = -1;
    *(long *)p = m;
    *(long *)(p + 2) = m;
    p[4] = -1;
    p[5] = -1;
    p[6] = -1;
    p[7] = -1;
    p[8] = -1;
    p[9] = -1;
}

// FUNCTION: GAME 0x36A3C0
void func_0036A3C0(char *o, int *x, int *y)
{
    int *q = (int *)(o + 0x3EC);
    if (x)
        *x = q[0];
    if (y)
        *y = q[2];
}

// FUNCTION: GAME 0x36DDD8
void func_0036DDD8(char *o, int *x, int *y)
{
    int *q = (int *)(o + 0x14C);
    if (x)
        *x = q[0];
    if (y)
        *y = q[2];
}

// FUNCTION: GAME 0x36CD18
int func_0036CD18(void)
{
    int (*f)() = D_003F2004;
    if (f)
        return f();
    return 0;
}

// FUNCTION: GAME 0x36CE38
int func_0036CE38(void)
{
    int (*f)() = D_003F2030;
    if (f)
        return f();
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x36CB98
// diff: orig leaves nop in beqz delay slot and emits lui/addiu(D_003F1EC8) after the sw;
// ours hoists lui into the delay slot (8 words differ)
void func_0036CB98(int *p)
{
    if (p) {
        *p = 0;
        D_003F1EC8--;
    }
}

// DRAFT: GAME 0x368EE0 (same shape at 0x369F70)
// diff: orig copies a1 to v0 before sd ra and stores v0; ours stores a1 (12 words)
struct Cb {
    void (*fn)(int);
    int arg;
    int v;
};
void func_00368EE0(struct Cb *c, int v)
{
    c->v = v;
    if (v && c->fn)
        c->fn(c->arg);
}
#endif
