// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// scanf %[ class-table builder (0x3A79F8): fills a 256-byte table from a set spec, returns the pointer past ']'.

#ifdef NONMATCHING
// DRAFT: GAME 0x3A79F8
// diff: 54 words, c/hi register swap (a2/a3) and different loop layout
char *func_003A79F8(char *tab, char *p)
{
    int c, hi, i, neg;

    c = *p++;
    if (c == '^') {
        c = *p++;
        neg = 1;
    } else {
        neg = 0;
    }
    for (i = 255; i >= 0; i--)
        tab[i] = neg;
    if (c == 0)
        return p - 1;
    neg = 1 - neg;
    for (;;) {
        tab[c] = neg;
    next:
        hi = *p++;
        if (hi == '-') {
            hi = *p;
            if (hi == ']' || hi < c) {
                c = '-';
                continue;
            }
            p++;
            do {
                c++;
                tab[c] = neg;
            } while (c < hi);
            goto next;
        }
        if (hi == 0)
            return p - 1;
        if (hi == ']')
            return p;
        c = hi;
    }
}

#endif
