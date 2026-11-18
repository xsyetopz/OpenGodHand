// COMPILER: ee-gcc2.96
int func_00356358(char *);
int func_00356648(char *, int, int);
void func_0034DF68(int *);
void func_0034DF80(int *);
typedef struct { int w[11]; } S;
struct O { int (**vt)(struct O *, int); };

// FUNCTION: GAME 0x3568B8
int func_003568B8(char *a, int b, int c)
{
    if (func_00356358(a) == 0) return c;
    return func_00356648(*(char **)(a + 0x1FC0) + 0x1198, b, c);
}

// FUNCTION: GAME 0x34C7F0
int func_0034C7F0(char *a, int b)
{
    int buf[4];
    char *s = a + b * 116 + 0x1320;
    int s1, s2;
    func_0034DF68(buf);
    s1 = *(int *)(s + 0x20);
    s2 = *(int *)(s + 0x24);
    if (s1 == 0 && s2 != 0) {
        struct O *o = *(struct O **)(s + 4);
        s1 = s2 + o->vt[9](o, 1);
    }
    if (s1 < 0) s1 = 0x7FFFFFFF;
    func_0034DF80(buf);
    return s1;
}

// FUNCTION: GAME 0x3538B0
void func_003538B0(char *a)
{
    S *src = (S *)(a + 0xDF0);
    S *dst = (S *)(a + 0xE1C);
    if (src->w[9] < *(int *)(a + 0xE6C))
        *dst = *src;
}
