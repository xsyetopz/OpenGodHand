// COMPILER: ee-gcc2.96

extern int func_0034C890();
extern int func_0034CAF8();
extern int func_0034CCB0();
extern int WaitSema();
extern int SignalSema();
#ifdef NONMATCHING
extern int func_0034C2B8();
extern int func_003518D8();
extern int func_00351AB0();
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x351780 3 words: branch sense (bnez vs beqz) and zero-store order
void func_00351780(char *a, int *b)
{
    int v[8];
    if (!func_0034C2B8(a, *(int *)(a + 0x1FC8), v)) {
        b[1] = 0;
        b[0] = 0;
    } else {
        b[0] = v[0];
        b[1] = v[1];
    }
}

// DRAFT: GAME 0x351888 3 words: epilogue order (return value set before s0 reload)
int func_00351888(int a, int b)
{
    int r = func_003518D8(a, b);
    if (r != -1)
        func_00351AB0(a, b);
    return 0;
}
#endif

// FUNCTION: GAME 0x352DC0
void func_00352DC0(char *a, int *b)
{
    int x;
    b[0] = *(int *)(a + 0x10);
    b[1] = *(int *)(a + 0x1C);
    b[2] = *(int *)(a + 0x20);
    b[3] = *(int *)(a + 0x24);
    b[4] = *(int *)(a + 0x28);
    b[5] = *(int *)(a + 0x2C);
    x = *(int *)(a + 0x14);
    b[6] = x;
    *(short *)(b + 7) = *(char *)(a + 0x54);
    *((short *)b + 15) = 0;
}

// FUNCTION: GAME 0x3545F8
void func_003545F8(char *a)
{
    int v[4];
    func_0034C890(a, *(int *)(a + 0x1FC8), v);
    if (v[0]) {
        func_0034CAF8(v[0], v + 1, v + 2);
        *(long *)(a + 0x9A0) = func_0034CCB0(*(long *)(a + 0x9A0), v[1]);
    }
}

// FUNCTION: GAME 0x355BB8
void func_00355BB8(int *a, int b)
{
    WaitSema(a[0x10]);
    a[5] += b;
    *(long *)(a + 0x12) += b;
    SignalSema(a[0x10]);
}
