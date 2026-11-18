extern "C" void func_00302918(void *);
extern "C" void func_003029C0(void *);

static inline unsigned char Eq(volatile unsigned char *v, int n) { return *v == n; }

#ifdef NONMATCHING
// DRAFT: GAME 0x304C48
// 55 differing words: orig reloads mode byte per test, bools via bne/daddu+andi; tried plain, volatile (kept), Eq()==1, local flags (62)
extern "C" void func_00304C48(unsigned char *self)
{
    int ok = 1;
    if (Eq(*(unsigned char **)(self + 0x108) + 0x2F4, 0) & 1)
        ok = ((int)(*(unsigned char **)(self + 0x108))[0x2F4] ^ *(int *)(self + 0x240)) == 0;
    unsigned char *p = *(unsigned char **)(self + 0x108);
    if (Eq(p + 0x2F4, 1) & 1)
        ok = ((int)p[0x2F5] ^ *(int *)(self + 0x244)) == 0 ? ok : 0;
    if (Eq(p + 0x2F4, 2) & 1)
        ok = ((int)p[0x2F6] ^ *(int *)(self + 0x248)) == 0 ? ok : 0;
    if (Eq(p + 0x2F4, 3) & 1)
        ok = ((int)p[0x2F7] ^ *(int *)(self + 0x24C)) == 0 ? ok : 0;
    if (ok == 0)
        func_00302918(self);
    func_003029C0(self);
}
#endif
