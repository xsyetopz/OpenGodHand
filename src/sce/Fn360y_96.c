// COMPILER: ee-gcc2.96
int func_0036C5F8(char *);
int func_00369F20(int, int);
int func_0036CCA8(char *);
void func_0036CDC0(int, int, int, int, int);
void func_0036CDE8(int, int, int);
int func_0036CE38(int, int);
void func_0036CE10(int, int, char *);
void func_0036C790(char *);

// FUNCTION: GAME 0x0036A238
int func_0036A238(char *p, int *a, int *b, int *c)
{
    if (func_0036C5F8(p))
        return func_00369F20(0, 0xFF03020F);
    *a = *(int *)(p + 0x2AC) << 11;
    *b = *(int *)(p + 0x2BC);
    if (*(int *)(p + 0x2A8) == 0x3FFFF)
        *c = -1;
    else
        *c = *(int *)(p + 0x2BC) * *(int *)(p + 0x2A8) / 0x708;
    return 0;
}

// FUNCTION: GAME 0x0036C6C8
int func_0036C6C8(char *p, int x)
{
    int i;
    int *q;
    if (func_0036CCA8(p)) {
        for (i = 0, q = (int *)(p + 0x3BC); i < 4; i++) {
            func_0036CDC0(*(int *)(p + 0x3B4), i, q[0], q[1], q[2]);
            q += 3;
        }
        func_0036CDE8(*(int *)(p + 0x3B4), *(int *)(p + 0x3EC), *(int *)(p + 0x3F0));
        if (func_0036CE38(*(int *)(p + 0x3B4), x))
            return -2;
        func_0036CE10(*(int *)(p + 0x3B4), 0, p + 0x3F4);
        func_0036C790(p);
        return 0;
    }
    return -1;
}
