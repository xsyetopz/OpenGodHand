// COMPILER: ee-gcc2.96
int func_0034DEC8(char *);
int func_0034DD70(int, int);
void func_0035D1B0(int, int, int, int, int);
void func_0034C208(char *, int, int, int);
// FUNCTION: GAME 0x0035CE60
int func_0035CE60(char *p, int a, int b, int c)
{
    int *s = (int *)(p + 0x2150);
    int k;
    int t, base;
    if (func_0034DEC8(p))
        return func_0034DD70(0, 0xFF000191);
    k = s[4];
    base = s[2];
    if (k == 8)
        return func_0034DD70((int)p, 0xFF000602);
    t = base + a * 16 + 4;
    func_0035D1B0(t, b, c, 0, 0);
    func_0034C208(p, k, a, t);
    return 0;
}
