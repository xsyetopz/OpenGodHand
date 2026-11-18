#ifdef NONMATCHING
// DRAFT: GAME 0x2AD108
// 27 words differ: reg alloc (p copied to t1, lb into a0), movn instead of branch for flags|=2; tried raw offsets, struct, indexed, early-return forms.
extern "C" int func_002AD108(char *p)
{
    unsigned n, i = 0, last = 0;
    int flags = 0, sum = 0;
    if (*(int *)(p + 0x1B544) != 0) {
        n = *(unsigned *)(p + 0x740);
        if (n != 0) {
            char *q = p;
            do {
                if (*(int *)(q + 0x100) == 1) {
                    last = i;
                    sum += *(signed char *)(q + 0x10C);
                    if (flags & 1) flags |= 2;
                } else {
                    flags |= 1;
                }
                i++;
                q += 0x10;
            } while (i < n);
        }
        if ((flags & 3) != 3) {
            *(unsigned *)(p + 0x740) = last + 1;
            *(int *)(p + 0x1B544) = sum;
            return 1;
        }
    }
    return 0;
}
#endif
