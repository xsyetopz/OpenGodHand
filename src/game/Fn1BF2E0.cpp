#ifdef NONMATCHING
// DRAFT: GAME 0x1BF2E0
// 2 words differ: original is sw v0,0x600(a0); nop; jr; nop, plain C emits sw; jr; nop (nop needs inline asm); volatile store 3->2, empty barrier also 2.
extern "C" void func_001BF2E0(char *self)
{
    register int v asm("$2");
    *(volatile int *)(self + 0x600) = v;
}
#endif
