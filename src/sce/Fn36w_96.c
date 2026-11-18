// COMPILER: ee-gcc2.96
extern int func_0036C5F8();
extern int func_00369F20();
extern int func_0036D688();
extern int func_0036D8E8();
extern int func_00368FB0();
extern int func_00368FC0();
extern int func_00368E90();
extern int D_00766CE8[];
extern int *D_003F1A98;
struct B32 { char c[32]; };

// FUNCTION: GAME 0x0036C568
int func_0036C568(char *o, int i, int *out)
{
    int *p;
    if (o == 0)
        p = D_00766CE8;
    else {
        if (func_0036C5F8(o))
            return func_00369F20(0, 0xFF030210);
        p = (int *)(o + 0x190);
    }
    *out = p[i];
    return 0;
}

// FUNCTION: GAME 0x0036DBE0
void func_0036DBE0(char *o, int *a, int *b, int *c)
{
    int *p = (int *)(o + 0x160);
    if (func_0036D688(o)) {
        func_0036D8E8(0, 0xFF03020F);
        return;
    }
    *a = p[0x2D8 / 4] << 11;
    *b = p[0xE4 / 4];
    *c = -1;
}

// FUNCTION: GAME 0x00368F18
int func_00368F18(char *o, int a, int b)
{
    if (o == 0) {
        func_00368FB0(D_003F1A98);
    } else {
        if (func_00368FC0())
            return func_00368E90(0, 0xFF020101);
        func_00368FB0(o + 4, a, b);
    }
    return 0;
}

// FUNCTION: GAME 0x00368BC8
int func_00368BC8(char *o, struct B32 *out)
{
    if (func_00368FC0(o))
        return func_00368E90(0, 0xFF020202);
    *out = *(struct B32 *)(o + 0x28);
    return 0;
}


