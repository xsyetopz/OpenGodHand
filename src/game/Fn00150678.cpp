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
// DRAFT: GAME 0x1552F0 22 differing words (88 vs 100 bytes): the barrier on p forces a stack reload the original does not make, the compiler emits movz where the original has a beqz/addiu branch, the mult operands are swapped (original loads 0x70 into v0 and mults v1 by v0), and the original's second divide-by-zero check (beql v0,0) after the if body is missing. Tried: no barriers, barrier on base only, barrier on p only (best), barrier on q in the if body (asm +r), 0x70 operand order, d declared above or below base/p, hoisted a1*4 index, separate remainder local r.
extern "C" int func_001552F0(char *a0, int a1)
{
    int base = *(int *)(a0 + 0x388);
    char *p = (char *)(*(int *)(base + a1 * 4 + 0x20) + base);
    int d = 0x18;
    __asm__("" : : "m"(p));
    int n = *(unsigned short *)(p + 0x14);
    int q = n / d;
    if (n % d != 0) {
        q += 1;
    }
    return q * 0x70 + 0x10;
}
#endif
