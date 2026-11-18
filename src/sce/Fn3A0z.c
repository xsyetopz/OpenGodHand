// COMPILER: ee-gcc2.9-991111
// SCE kernel interface helpers 0x3B0130-0x3B0398, ee-gcc 2.9-991111 -O2 -G0.

extern int func_003B63A0(void);
extern void func_003B63F0(void);

// FUNCTION: GAME 0x3B0130
void func_003B0130(void)
{
    int i = func_003B63A0();
    *(volatile int *)0x1000F000 = 4;
    __asm__ volatile("sync");
    if (i)
        func_003B63F0();
    while (!(*(volatile int *)0x1000F000 & 4))
        ;
    i = func_003B63A0();
    *(volatile int *)0x1000F000 = 4;
    __asm__ volatile("sync");
    if (i)
        func_003B63F0();
}

extern void func_003B0010(int *, long *);

// FUNCTION: GAME 0x3B01C0
long func_003B01C0(void)
{
    int x = 0;
    long y;
    int i;
    func_003B0010(&x, &y);
    i = func_003B63A0();
    *(volatile int *)0x1000F000 = 4;
    __asm__ volatile("sync");
    if (i)
        func_003B63F0();
    while (!(*(volatile int *)0x1000F000 & 4) && !*(volatile int *)&x)
        ;
    i = func_003B63A0();
    *(volatile int *)0x1000F000 = 4;
    __asm__ volatile("sync");
    if (i)
        func_003B63F0();
    return *(volatile long *)&y;
}
