#ifdef NONMATCHING
// DRAFT: GAME 0x2B12A0
// 7 differing words: original jumps b over delay-slot dead lw to shared return-1; tried volatile, asm sink, goto, r-flag, volatile-then-return-1 join (16), else-form r flag (7).
extern int D_0044B110[];
extern "C" int func_002B12A0(unsigned short *p) {
    unsigned short i = *p;
    if (i >= 0xE)
        return 0;
    int v = D_0044B110[i];
    asm("" : : "r"(v));
    return 1;
}
#endif
