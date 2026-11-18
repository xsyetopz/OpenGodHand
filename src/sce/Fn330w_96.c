// COMPILER: ee-gcc2.96
extern char D_004532D8[], D_004532F8[];
extern void func_003302E0(char *), func_00330910(int *);
// FUNCTION: GAME 0x330AD0
void func_00330AD0(int *o)
{
    void (*f)(int);
    if (!o) {
        func_003302E0(D_004532D8);
        return;
    }
    f = *(void (**)(int))(*(char **)o + 0x14);
    if (f != 0) {
        f(o[1]);
        func_00330910(o);
        return;
    }
    func_003302E0(D_004532F8);
}

extern void func_00333048(void);
extern void func_00332BE0(char *);
// FUNCTION: GAME 0x332D78
void func_00332D78(char *s)
{
    if (s) {
        if ((unsigned char)s[2] >= 2)
            func_00333048();
        s[0] = 0;
        func_00332BE0(s);
    }
}
