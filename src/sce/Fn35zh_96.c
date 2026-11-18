// COMPILER: ee-gcc2.96
extern int func_003AFCE0();
extern int func_003AFCC0();
extern int func_003554E8();
extern int func_003509E8();
extern int func_00350A50();
extern int func_00356358();
extern int func_00355C08();

// FUNCTION: GAME 0x350988
int func_00350988(int a)
{
    if (func_003554E8(a))
        return 1;
    if (func_003509E8(a) && func_00350A50(a))
        return 1;
    return 0;
}

// FUNCTION: GAME 0x353500
int func_00353500(char *a, unsigned k)
{
    int *p = (int *)(a + 0xA0C);
    int v;
    switch (k) {
    case 1: v = p[8 / 4]; break;
    case 2: v = p[0xC / 4]; break;
    case 3: v = p[0x10 / 4]; break;
    default: return 1;
    }
    return v == 0;
}

// FUNCTION: GAME 0x3562F8
int func_003562F8(int *a)
{
    func_003AFCE0(a[0x40 / 4]);
    a[0x14 / 4] = (a[0x14 / 4] + 0x803) / 0x800 * 0x800;
    return func_003AFCC0(a[0x40 / 4]);
}

// FUNCTION: GAME 0x356928
int func_00356928(int *a, int b)
{
    if (!func_00356358(a, b))
        return b;
    return func_00355C08(a[0x1FC0 / 4] + 0x1198, b);
}
