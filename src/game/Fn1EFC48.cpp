extern "C" void kill__9classFADE(void *);
extern "C" void start__9classFADEUiUiUiUiUiUi(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
extern char Fade[];

#ifdef NONMATCHING
// DRAFT: GAME 0x1EFC48
// 26 words differ: original keeps mode in s1/Fade hi in s2 and tests s1==0 / s1==1 with one shared jal; ours reorders regs. Variants: if/else, switch with duplicated calls, switch picking x/y, init+switch, if-chain (best)
extern "C" void func_001EFC48(char *self, unsigned char mode)
{
    long l = *(unsigned *)(self + 0x54);
    long b = (l >> 1) & 1;
    if (b) {
        kill__9classFADE(Fade);
        *(int *)(self + 0x54) &= ~2;
    }
    unsigned x, y;
    if (mode == 0) {
        x = 0xFF000000; y = 0;
    } else if (mode == 1) {
        x = 0; y = 0xFF000000;
    } else {
        x = 0xFF000000; y = 0;
    }
    start__9classFADEUiUiUiUiUiUi(Fade, 0, 10, 0, x, y, 15);
    *(int *)(self + 0x54) |= 2;
}
#endif
