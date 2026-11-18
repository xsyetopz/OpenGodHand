extern char Fade[];
extern "C" void kill__9classFADE(void *);
extern "C" void start__9classFADEUiUiUiUiUiUi(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);

#ifdef NONMATCHING
// DRAFT: GAME 0x1F4428
// 31 words differ: -3 mask built as lui/ori after lw instead of addiu, branch layout of switch (single call tail); tried if/else, switch default/case0, long b temp, call-per-case
extern "C" void func_001F4428(char *self, int mode)
{
    unsigned char m = mode;
    long f = *(unsigned *)(self + 0x54);
    long b = (f >> 1) & 1;
    if (b) {
        kill__9classFADE(Fade);
        *(unsigned *)(self + 0x54) &= ~2;
    }
    unsigned c, d;
    switch (m) {
    case 1:
        c = 0;
        d = 0xFF000000;
        break;
    default:
        c = 0xFF000000;
        d = 0;
        break;
    }
    start__9classFADEUiUiUiUiUiUi(Fade, 0, 10, 0, c, d, 15);
    *(unsigned *)(self + 0x54) |= 2;
}
#endif
