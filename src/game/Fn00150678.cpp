extern "C" void func_00150608(int a, int b);

#ifdef NONMATCHING
// DRAFT: GAME 0x150678
// Non-entry fragment: first insn reads v0 set by the preceding code and nothing references 0x150678; C form keeps the flag store and tail call.
extern "C" void func_00150678(char *a0, int a1)
{
    *(int *)(a0 + 0x154) = a1 != 0;
    func_00150608(1, 0xFFFF);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1552F0 23 differing words: the stack-slot barriers (sw/lw of base and p) and the divide-by-24 scheduling differ; the compiler emits two div ops and movz where the original uses one div and a beqz branch; tried 5 variants (divisor local, barrier on base and p, remainder first).
extern "C" int func_001552F0(char *a0, int a1)
{
    int d = 0x18;
    int base = *(int *)(a0 + 0x388);
    __asm__("" : : "m"(base));
    char *p = (char *)(*(int *)(base + a1 * 4 + 0x20) + base);
    __asm__("" : : "m"(p));
    int n = *(unsigned short *)(p + 0x14);
    int q = n / d;
    if (n % d != 0) {
        q += 1;
    }
    return q * 0x70 + 0x10;
}
#endif
