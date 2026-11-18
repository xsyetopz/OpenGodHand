#ifdef NONMATCHING
// DRAFT: GAME 0x1B7568 - 68 words: range flag (a>=0x100 && a<0x1FF)==1 compiles to slti+movn and shifts regs (orig branches, a3 flag); tried unsigned short/int a, inline helper, if/else f; same as Fn1BD430 draft
extern "C" void func_001B7568(char *self, char *o)
{
    short t = *(short *)(o + 0x46);
    if (t < 0x30 && t >= 0x2E)
        *(unsigned *)(self + 0x5B4) |= 1;
    if ((unsigned)(t - 7) >= 2) {
        if (t != 0x15 && t != 0x13 && t != 0x18 && t != 0x1C && t != 0x21 && t != 0x22 && t != 0x29 && t != 0x2A && t != 0x2B && t != 0x31) {
            char *p = *(char **)(o + 0x34);
            if (p) {
                int a =*(unsigned short *)(p + 0x2FE);
                int f = 0;
                if (a >= 0x100)
                    f = a < 0x1FF;
                if (f == 1 && *(int *)(o + 0x4C) >= 0xB)
                    *(unsigned *)(self + 0x5B4) |= 2;
            }
        }
    }
    if ((unsigned)(t - 8) < 4 || t == 0x1C || t == 0x30 || t == 0x52)
        *(unsigned *)(self + 0x5B4) |= 4;
}
#endif
