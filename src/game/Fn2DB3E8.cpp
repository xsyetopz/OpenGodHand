extern char *scrArray;

// FUNCTION: GAME 0x2DB3E8
extern "C" void setScrollFlagScrollLayer__FUiQ29objScroll11ScrollFlagsb(unsigned layer, unsigned flag, int on)
{
    char **p = *(char ***)(scrArray + 4);
    if (p != *(char ***)(scrArray + 8)) {
        unsigned bit = 0x80000000u >> (flag & 0x1F);
        unsigned off = (flag >> 5) << 2;
        do {
            char *o = *p;
            if (layer == *(unsigned char *)(o + 0x2FD)) {
                o += 0x350;
                unsigned *w;
                if (on == 1) {
                    w = (unsigned *)(off + (int)o);
                    *w = *w | bit;
                } else {
                    w = (unsigned *)(off + (int)o);
                    *w = *w & ~bit;
                }
            }
            p++;
        } while (p != *(char ***)(scrArray + 8));
    }
}
