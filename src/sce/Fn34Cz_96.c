// COMPILER: ee-gcc2.96
int *func_0034E988(char *);
// FUNCTION: GAME 0x0034E928
int func_0034E928(char *p, int a)
{
    int *q = func_0034E988(p);
    if (q[0] == 0 && (q[4] != 0 || q[5] != 0))
        return 0;
    return a == q[2] + q[3];
}

int func_00350138();
// FUNCTION: GAME 0x0034D450
int func_0034D450(char *p)
{
    int v = *(int *)(p + 0x36B0);
    if (!v)
        return 0;
    if (func_00350138() > 0)
        return 0;
    return *(int *)(p + 0x36B0) + 0xC;
}

int func_0034F0E0(int, int, int);
// FUNCTION: GAME 0x0034EB28
int func_0034EB28(int a, void (*fn)(int, int), int ctx, int x, int t0, int t1)
{
    int r = func_0034F0E0(a, t0, t1);
    if (r == 1 && fn)
        fn(ctx, x);
    return r;
}

int func_0035A1C8(char *, int);
int func_0034C7F0(char *, int);
int func_0035C338(char *, int);
void func_0035A000(char *, int, int);
// FUNCTION: GAME 0x0034F930
void func_0034F930(char *p)
{
    int *s = *(int **)(p + 0x1F7C);
    if (func_0035A1C8(p, 6) && func_0035A1C8(p, 0x50) && !func_0034C7F0(p, 2) && !s[2] && func_0035C338(p, 6))
        func_0035A000(p, 6, 0);
    if (func_0035A1C8(p, 5) && func_0035A1C8(p, 0x4F) && !func_0034C7F0(p, 1) && !s[1] && func_0035C338(p, 7))
        func_0035A000(p, 5, 0);
}
