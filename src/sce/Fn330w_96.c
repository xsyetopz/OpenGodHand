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

extern void func_00335248();
extern void func_003352D0();
extern volatile int D_003D9F68;
extern char D_003D9F78[];
// FUNCTION: GAME 0x333FA0
char *func_00333FA0()
{
    int v = D_003D9F68;
    func_00335248(0);
    func_003352D0(0);
    return D_003D9F78;
}

extern int strlen();
extern void *memcpy();
extern char D_00756080[];
// FUNCTION: GAME 0x330A68
void *func_00330A68(char *a)
{
    int n = strlen(D_00756080);
    if (D_00756080[0] == 0) {
        *a = 0;
        return;
    }
    return memcpy(a, D_00756080, n + 1);
}

struct S8 { int a; int b; };
extern struct S8 D_00755D40[];
// FUNCTION: GAME 0x3308A8
struct S8 *func_003308A8()
{
    int i;
    for (i = 0; i < 0x28; i++) {
        if (D_00755D40[i].b == 0) break;
    }
    if (i == 0x28) return 0;
    return &D_00755D40[i];
}
