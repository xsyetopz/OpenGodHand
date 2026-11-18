// COMPILER: ee-gcc2.96
extern int func_00350138(), func_00366918();

// FUNCTION: GAME 0x003500E8
int func_003500E8(char *a)
{
    int v = *(int *)(a + 0x36B0);
    if (v == 0)
        return 0;
    if (func_00350138() > 0)
        return 0;
    return *(int *)(a + 0x36B0) + 0x8A0;
}

// FUNCTION: GAME 0x003534B0
int func_003534B0(char *a)
{
    int *q = (int *)(a + 0x36B4);
    int *t = (int *)(a + 0xDF0);
    int *x = (int *)(a + 0xE48);
    if (q[1] < 0)
        return 0;
    if (*x != 0)
        return 0;
    return func_00366918(q[1], q[2], t[9], t[10]) == 0;
}
