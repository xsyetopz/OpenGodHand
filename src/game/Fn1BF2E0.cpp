#ifdef NONMATCHING
// DRAFT: GAME 0x1BF2E0
// 3 differing words: original sw v0,0x600(a0); nop; jr; nop (unset v0), register asm gives sw in delay slot.
extern "C" void func_001BF2E0(char *self)
{
    register int v asm("$2");
    *(int *)(self + 0x600) = v;
}
#endif
