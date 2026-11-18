// COMPILER: ee-gcc2.9-991111
// SCE runtime helpers in 0x3BA978-end.

extern char D_003FC9B4[];
extern char D_007854B0[];
extern void func_003224D0(char *, char *);

// FUNCTION: GAME 0x3BAFB8
void func_003BAFB8(void)
{
    func_003224D0(D_003FC9B4, D_007854B0);
}

extern int func_003B63A0(void);
extern void func_003B63F0(void);

// FUNCTION: GAME 0x3BAD08
void func_003BAD08(int a)
{
    int r = func_003B63A0();
    volatile unsigned int *src = (volatile unsigned int *)0x1000F520;
    volatile unsigned int *dst = (volatile unsigned int *)0x1000F590;
    *dst = *src | 0x10000;
    *(volatile int *)0x1000B400 = a;
    *dst = *src & 0xFFFEFFFF;
    if (r)
        func_003B63F0();
}
