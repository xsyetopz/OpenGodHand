// COMPILER: ee-gcc2.96
// FLAGS: -fno-optimize-sibling-calls
// SCE library wrappers that keep a frame around the call, built with ee-gcc 2.96 (C).

void func_003B02E8(int, int, int);
void func_0038EB28(int, int);

// FUNCTION: GAME 0x393230
void func_00393230(int *o, int b, long c)
{
    func_003B02E8(o[0x38 / 4], b, (int)c);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x38BA10
// diff: 2 words, addiu $sp and daddu $a0 swapped (scheduling)
void func_0038BA10(int a, int b)
{
    func_0038EB28(b, a);
}
#endif
