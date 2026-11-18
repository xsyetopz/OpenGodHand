// COMPILER: ee-gcc2.9-991111
// Leaf and tail-call code in a separate SCE object (no frame around tail calls).

extern char D_003FC9B4[];
extern int D_003EC454;
extern int D_003EC458;
void func_003224F8(char *);

// FUNCTION: GAME 0x3BAFD0
void func_003BAFD0()
{
    func_003224F8(D_003FC9B4);
}

// FUNCTION: GAME 0x340438
void func_00340438(int a, int b)
{
    D_003EC454 = a;
    D_003EC458 = b;
}
