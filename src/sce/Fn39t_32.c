// COMPILER: ee-gcc3.2-030926
// FLAGS: -fno-optimize-sibling-calls
// SCE wrappers in 0x394F20-0x3A53A8 that keep a frame around the call.

extern void FlushCache(int);
extern int func_003AFFC0(void);
extern int func_00398890(int, int, int);

// FUNCTION: GAME 0x395180
void func_00395180(void)
{
    FlushCache(0);
    FlushCache(2);
}

// FUNCTION: GAME 0x3964A0
int func_003964A0(void)
{
    return func_003AFFC0();
}

// FUNCTION: GAME 0x398B90
int func_00398B90(int a, int b)
{
    return func_00398890(a, b, 0);
}
